#define CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <bcrypt.h>
#include <ntstatus.h>

#define SM2ENC_OID			"1.2.156.10197.1.301.3"

static int GetFileLength(FILE *fp);
static void Usage(const char *progName);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
static PCCERT_CONTEXT GetCert(const char *fileName);
static int SaveFile(const char *fileName, const unsigned char *buf, int bufLen);
static int Encrypt(PCCERT_CONTEXT cert, const unsigned char *clear, int clearLen, unsigned char **env, int *envLen);
static int ChangePublicKeyEncryptAlgorithm(const unsigned char *in, int inLen, unsigned char **out, int *outLen);

void Usage(const char *progName)
{
	printf("Usage: %s certFileName clear encFileName\n", progName);
}


int main(int argc, char **argv)
{
	const char* certFileName;
	const char* clear;
	const char* encFileName;
	PCCERT_CONTEXT cert;
	unsigned char* env;
	int envLen;
	int rv;

	if (argc != 4)
	{
		Usage(argv[0]);
		return -1;
	}

	certFileName = argv[1];
	clear = argv[2];
	encFileName = argv[3];

	cert = GetCert(certFileName);
	if (cert == NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}
	rv = Encrypt(cert, (const unsigned char*)clear, (int)strlen(clear),
		&env, &envLen);
	CertFreeCertificateContext(cert);
	if (rv == 0)
	{
		printf("Encrypt fail\n");
		return -1;
	}
	rv = SaveFile(encFileName, env, envLen);
	free(env);
	if (rv == 0)
	{
		printf("SaveFile fail\n");
		return -1;
	}
	printf("Encrypt success\n");
	return 0;
}

int GetFileLength(FILE *fp)
{
	int  len;
	if (fseek(fp, 0, SEEK_END) != 0)
	{
		return -1;
	}
	len = ftell(fp);
	if (fseek(fp, 0, SEEK_SET) != 0)
	{
		return -1;
	}

	return len;
}

int ReadFileData(const char *fileName, unsigned char **data, int *dataLen)
{
	FILE *fp;
	int len;
	unsigned char *buf;

	fp = fopen(fileName, "rb");
	if (fp == 0)
	{
		return 0;
	}

	len = GetFileLength(fp);
	if (len<0)
	{
		fclose(fp);
		return 0;
	}

	buf = (unsigned char *)malloc(len);
	if (buf == 0)
	{
		fclose(fp);
		return 0;
	}
	if ((int)fread(buf, 1, len, fp) != len)
	{
		free(buf);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	*data = buf;
	*dataLen = len;
	return 1;
}
PCCERT_CONTEXT GetCert(const char *fileName)
{
	PCCERT_CONTEXT cert;
	unsigned char *data;
	int dataLen;
	int rv;

	rv = ReadFileData(fileName, &data, &dataLen);
	if (rv == 0)
	{
		return NULL;
	}
	cert = CertCreateCertificateContext(X509_ASN_ENCODING, data, dataLen);
	free(data);
	return cert;
}

int SaveFile(const char *fileName, const unsigned char *buf, int bufLen)
{
	FILE *fp;
	int len;
	fp = fopen(fileName, "wb");
	if (fp == 0)
	{
		return 0;
	}

	len = (int)fwrite(buf, 1, bufLen, fp);
	fclose(fp);
	return len == bufLen;
}

int Encrypt(PCCERT_CONTEXT cert, const unsigned char *clear, int clearLen, unsigned char **env, int *envLen)
{
	NTSTATUS status;
	BOOL b;
	CMSG_ENVELOPED_ENCODE_INFO encodeInfo;
	unsigned char *out;
	DWORD outLen;
	HCRYPTMSG hMsg;
	DWORD dwFlags = 0;
	unsigned char iv[18];
	unsigned char* publicKey = 0;
	int rv;
	PCERT_INFO certs[1];

	memset(&encodeInfo, 0, sizeof(encodeInfo));
	encodeInfo.cbSize = sizeof(encodeInfo);
	encodeInfo.hCryptProv = 0;

	encodeInfo.ContentEncryptionAlgorithm.pszObjId = szOID_NIST_AES128_CBC;
	encodeInfo.ContentEncryptionAlgorithm.Parameters.cbData = 18;
	memset(iv, 0, sizeof(iv));
	iv[0] = 4;
	iv[1] = 16;
	status = BCryptGenRandom(NULL, &iv[2], 16, BCRYPT_USE_SYSTEM_PREFERRED_RNG);
	if (status != STATUS_SUCCESS)
	{
		return 0;
	}
	encodeInfo.ContentEncryptionAlgorithm.Parameters.pbData = iv;
	encodeInfo.pvEncryptionAuxInfo = 0;

	encodeInfo.cRecipients = 1;
	certs[0] = cert->pCertInfo;
	encodeInfo.rgpRecipients = certs;
	encodeInfo.rgCmsRecipients = 0;


	outLen = CryptMsgCalculateEncodedLength(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		dwFlags,
		CMSG_ENVELOPED,
		&encodeInfo,
		0,
		(DWORD)clearLen);
	if (outLen == 0)
	{
		free(publicKey);
		return 0;
	}


	hMsg = CryptMsgOpenToEncode(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		dwFlags,
		CMSG_ENVELOPED,
		&encodeInfo,
		0,
		0);
	if (hMsg == 0)
	{
		free(publicKey);
		return 0;
	}

	b = CryptMsgUpdate(hMsg, clear, (DWORD)clearLen, TRUE);
	if (b == FALSE)
	{
		free(publicKey);
		CryptMsgClose(hMsg);
		return 0;
	}
	outLen += 100;
	out = (unsigned char*)malloc(outLen);
	if (out == 0)
	{
		free(publicKey);
		CryptMsgClose(hMsg);
		return 0;
	}
	b = CryptMsgGetParam(hMsg,
		CMSG_CONTENT_PARAM,
		0, out, &outLen);
	free(publicKey);
	CryptMsgClose(hMsg);
	if (b == FALSE)
	{
		free(out);
		return 0;
	}

	rv = ChangePublicKeyEncryptAlgorithm(out, (int)outLen, env, envLen);
	free(out);

	return rv;
}

int ChangePublicKeyEncryptAlgorithm(const unsigned char *in, int inLen, unsigned char **out, int *outLen)
{
	BOOL b;
	DWORD length;
	CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *envelopedData;
	CRYPT_SEQUENCE_OF_ANY *recipientInfos;
	CRYPT_SEQUENCE_OF_ANY *ktri;
	CRYPT_ALGORITHM_IDENTIFIER *algo;
	unsigned char* algoEncode;
	unsigned char* ktriEncode;
	unsigned char* recipientInfosEncode;

	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		return 0;
	}
	envelopedData = (CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *)malloc(length);
	if (envelopedData == 0)
	{
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, NULL,
		envelopedData, &length
		);
	if (b == FALSE)
	{
		free(envelopedData);
		return 0;
	}

	if (envelopedData->cValue < 3)
	{
		free(envelopedData);
		return 0;
	}

	/* 把SET OF 转换为SEQUECE OF */
	envelopedData->rgValue[1].pbData[0] -= 1;
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		envelopedData->rgValue[1].pbData,
		envelopedData->rgValue[1].cbData,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		free(envelopedData);
		return 0;
	}
	recipientInfos = (CRYPT_SEQUENCE_OF_ANY*)malloc(length);
	if (recipientInfos == 0)
	{
		free(envelopedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		envelopedData->rgValue[1].pbData,
		envelopedData->rgValue[1].cbData,
		0, NULL,
		recipientInfos, &length
		);
	if (b == FALSE)
	{
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}


	/* 只处理一个接收者的情况 */
	if (recipientInfos->cValue != 1)
	{
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}

	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		recipientInfos->rgValue[0].pbData,
		recipientInfos->rgValue[0].cbData,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}

	ktri = (CRYPT_SEQUENCE_OF_ANY*)malloc(length);
	if (recipientInfos == 0)
	{
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		recipientInfos->rgValue[0].pbData,
		recipientInfos->rgValue[0].cbData,
		0, NULL,
		ktri, &length
		);
	if (b == FALSE)
	{
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}

	if (ktri->cValue < 3)
	{
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}

	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ALGORITHM_IDENTIFIER,
		ktri->rgValue[2].pbData,
		ktri->rgValue[2].cbData,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	algo = (CRYPT_ALGORITHM_IDENTIFIER *)malloc(length);
	if (algo == 0)
	{
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ALGORITHM_IDENTIFIER,
		ktri->rgValue[2].pbData,
		ktri->rgValue[2].cbData,
		0, NULL,
		algo, &length
		);
	if (b == FALSE)
	{
		free(algo);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	algo->pszObjId = SM2ENC_OID;
	algo->Parameters.cbData = 2;
	algo->Parameters.pbData = "\x05\x00";

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ALGORITHM_IDENTIFIER,
		algo,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(algo);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	algoEncode = (unsigned char*)malloc(length);
	if (algoEncode == 0)
	{
		free(algo);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ALGORITHM_IDENTIFIER,
		algo,
		0, 0,
		algoEncode, &length);
	free(algo);
	if (b == FALSE)
	{
		free(algoEncode);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	ktri->rgValue[2].pbData = algoEncode;
	ktri->rgValue[2].cbData = length;

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		ktri,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(algoEncode);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	ktriEncode = (unsigned char*)malloc(length);
	if (ktriEncode == 0)
	{
		free(algoEncode);
		free(ktri);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		ktri,
		0, 0,
		ktriEncode, &length);
	free(algoEncode);
	free(ktri);
	if (b == FALSE)
	{
		free(ktriEncode);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	recipientInfos->rgValue[0].pbData = ktriEncode;
	recipientInfos->rgValue[0].cbData = length;

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		recipientInfos,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(ktriEncode);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	recipientInfosEncode = (unsigned char*)malloc(length);
	if (recipientInfosEncode == 0)
	{
		free(ktriEncode);
		free(recipientInfos);
		free(envelopedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		recipientInfos,
		0, 0,
		recipientInfosEncode, &length);
	free(ktriEncode);
	free(recipientInfos);
	if (b == FALSE)
	{
		free(recipientInfosEncode);
		free(envelopedData);
		return 0;
	}
	envelopedData->rgValue[1].pbData = recipientInfosEncode;
	envelopedData->rgValue[1].cbData = length;

	envelopedData->rgValue[1].pbData[0] += 1;

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		envelopedData,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(recipientInfosEncode);
		free(envelopedData);
		return 0;
	}
	*out = (unsigned char*)malloc(length);
	if (*out == 0)
	{
		free(recipientInfosEncode);
		free(envelopedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		envelopedData,
		0, 0,
		*out, &length);
	free(recipientInfosEncode);
	free(envelopedData);
	if (b == FALSE)
	{
		free(*out);
		return 0;
	}
	*outLen = (int)length;
	return 1;
}
