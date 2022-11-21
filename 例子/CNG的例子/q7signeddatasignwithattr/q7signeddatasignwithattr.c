#define CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SM3_OID			"1.2.156.10197.1.401"
#define SM2SIGN_OID		"1.2.156.10197.1.301.1"
#define SM2DATA_OID		"1.2.156.10197.6.1.4.2.1"
#define SM2SIGNEDDATA_OID		"1.2.156.10197.6.1.4.2.2"

static int GetFileLength(FILE *fp);
static void Usage(const char *progName);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
static PCCERT_CONTEXT GetCert(const char *fileName);
static int SaveFile(const char *fileName, const unsigned char *buf, int bufLen);
static const char* GetHashAlgorithmOidFromSignAlgoName(const char *signAlgoName);
static const char* GetSignAlgorithmOidFromSignAlgoName(const char *signAlgoName);
static PCRYPT_ATTRIBUTE CreatSigningTimeAttribute();
static void FreeAttribute(PCRYPT_ATTRIBUTE attr);
static int EncodeNow(unsigned char **data, DWORD *dataLen);
static int Sign(PCCERT_CONTEXT cert, int detached, NCRYPT_KEY_HANDLE hNCryptKey, const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen);
static int EncodeOuterContentInfo(const unsigned char *in, int inLen, unsigned char **out, int *outLen);

void Usage(const char *progName)
{
	printf("Usage: %s [-detached] certFileName tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* tbs;
	const char* signFileName;
	PCCERT_CONTEXT cert;
	int pos;
	int detached;
	unsigned char* sign;
	int signLen;
	int rv;
	DWORD dwKeySpec;
	BOOL fCallerFreeProvOrNCryptKey;
	BOOL b;
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey;
	DWORD lastError;

	if (argc != 5 && argc != 4)
	{
		Usage(argv[0]);
		return -1;
	}

	pos = 1;
	detached = 0;
	if (argc == 5)
	{
		if (_stricmp(argv[1], "-detached") != 0
			&& _stricmp(argv[1], "/detached") != 0)
		{
			Usage(argv[0]);
			return -1;
		}
		pos = 2;
		detached = 1;
	}
	certFileName = argv[pos];
	pos++;
	tbs = argv[pos];
	pos++;
	signFileName = argv[pos];

	cert = GetCert(certFileName);
	if (cert == NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}
	b = CryptAcquireCertificatePrivateKey(cert, CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG, NULL, &hKey,
		&dwKeySpec, &fCallerFreeProvOrNCryptKey);
	lastError = GetLastError();
	if (b == FALSE)
	{
		printf("CryptAcquireCertificatePrivateKey fail,error code=0X%X\n", lastError);
		CertFreeCertificateContext(cert);
		return -1;
	}
	rv = Sign(cert, detached, hKey,
		(const unsigned char*)tbs, (int)strlen(tbs),
		&sign, &signLen);
	CertFreeCertificateContext(cert);
	if (fCallerFreeProvOrNCryptKey)
	{
		NCryptFreeObject(hKey);
	}
	if (rv == 0)
	{
		printf("Sign fail\n");
		return -1;
	}
	rv = SaveFile(signFileName, sign, signLen);
	free(sign);
	if (rv == 0)
	{
		printf("SaveFile fail\n");
		return -1;
	}
	printf("Sign success\n");
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


int Sign(PCCERT_CONTEXT cert, int detached, NCRYPT_KEY_HANDLE hNCryptKey, const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen)
{
	BOOL b;
	CMSG_SIGNED_ENCODE_INFO encodeInfo;
	unsigned char *out;
	DWORD outLen;
	PCRYPT_ATTRIBUTE attr = 0;
	CRYPT_ATTRIBUTE attrs[1];
	HCRYPTMSG hMsg;
	DWORD dwFlags;
	CMSG_SIGNER_ENCODE_INFO signerInfo;
	CERT_BLOB certEncoded[1];
	int rv;

	dwFlags = CMSG_BARE_CONTENT_FLAG | CMSG_CMS_ENCAPSULATED_CONTENT_FLAG;
	if (detached)
	{
		dwFlags |= CMSG_DETACHED_FLAG;
	}

	memset(&encodeInfo, 0, sizeof(encodeInfo));
	encodeInfo.cbSize = sizeof(encodeInfo);
	encodeInfo.cSigners = 1;
	encodeInfo.rgSigners = &signerInfo;


	memset(&signerInfo, 0, sizeof(signerInfo));
	signerInfo.cbSize = sizeof(signerInfo);
	signerInfo.pCertInfo = cert->pCertInfo;
	signerInfo.hNCryptKey = hNCryptKey;
	signerInfo.HashAlgorithm.pszObjId = SM3_OID;
	signerInfo.HashEncryptionAlgorithm.pszObjId = SM2SIGN_OID;
	
	signerInfo.cAuthAttr = 1;
	signerInfo.rgAuthAttr = attrs;
	attr = CreatSigningTimeAttribute();
	if (attr == 0)
	{
		return 0;
	}
	attrs[0] = *attr;

	encodeInfo.cCertEncoded = 1;
	encodeInfo.rgCertEncoded = certEncoded;
	certEncoded[0].cbData = cert->cbCertEncoded;
	certEncoded[0].pbData = cert->pbCertEncoded;


	outLen = CryptMsgCalculateEncodedLength(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		dwFlags,
		CMSG_SIGNED,
		&encodeInfo,
		SM2DATA_OID,
		(DWORD)tbsLen);
	if (outLen == 0)
	{
		FreeAttribute(attr);
		return 0;
	}


	hMsg = CryptMsgOpenToEncode(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		dwFlags,
		CMSG_SIGNED,
		&encodeInfo,
		SM2DATA_OID,
		0);
	if (hMsg == 0)
	{
		FreeAttribute(attr);
		return 0;
	}
	b = CryptMsgUpdate(hMsg, tbs, (DWORD)tbsLen, TRUE);
	if (b == FALSE)
	{
		FreeAttribute(attr);
		CryptMsgClose(hMsg);
		return 0;
	}
	out = (unsigned char*)malloc(outLen);
	if (out == 0)
	{
		FreeAttribute(attr);
		CryptMsgClose(hMsg);
		return 0;
	}
	b = CryptMsgGetParam(hMsg,
		CMSG_BARE_CONTENT_PARAM,
		0, out, &outLen);
	CryptMsgClose(hMsg);
	FreeAttribute(attr);
	if (b == FALSE)
	{
		free(out);
		return 0;
	}
	rv = EncodeOuterContentInfo(out, outLen, sign, signLen);
	free(out);
	return rv;
}

PCRYPT_ATTRIBUTE CreatSigningTimeAttribute()
{
	PCRYPT_ATTRIBUTE attr;
	int b;
	attr = (PCRYPT_ATTRIBUTE)malloc(sizeof(*attr));
	if (attr == 0)
	{
		return 0;
	}

	attr->pszObjId = szOID_RSA_signingTime;
	attr->cValue = 1;
	attr->rgValue = (PCRYPT_ATTR_BLOB)malloc(sizeof(CRYPT_ATTR_BLOB));
	if (attr->rgValue == 0)
	{
		free(attr);
		return 0;
	}
	attr->rgValue[0].cbData = 0;
	attr->rgValue[0].pbData = 0;

	b = EncodeNow(&attr->rgValue[0].pbData, &attr->rgValue[0].cbData);
	if (b == 0)
	{
		free(attr->rgValue);
		free(attr);
		return 0;
	}

	return attr;
}

int EncodeNow(unsigned char **data, DWORD *dataLen)
{
	BOOL b;
	FILETIME now;
	GetSystemTimeAsFileTime(&now);
	DWORD len;
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_CHOICE_OF_TIME,
		&now,
		0,
		NULL,
		NULL,
		&len
		);
	if (b == 0)
	{
		return 0;
	}
	unsigned char *out;
	out = (unsigned char *)malloc(len);
	if (out == 0)
	{
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_CHOICE_OF_TIME,
		&now,
		0,
		NULL,
		out,
		&len
		);
	if (b == 0)
	{
		free(out);
		return 0;
	}
	*data = out;
	*dataLen = len;
	return 1;
}

void FreeAttribute(PCRYPT_ATTRIBUTE attr)
{
	if (attr)
	{
		if (attr->rgValue)
		{
			for (DWORD i = 0; i < attr->cValue; i++)
			{
				free(attr->rgValue[i].pbData);
			}
			free(attr->rgValue);
		}
		free(attr);
	}
}

int EncodeOuterContentInfo(const unsigned char *in, int inLen, unsigned char **out, int *outLen)
{
	CRYPT_CONTENT_INFO contentInfo;
	BOOL b;
	DWORD length;

	contentInfo.pszObjId = SM2SIGNEDDATA_OID;
	contentInfo.Content.cbData = (DWORD)inLen;
	contentInfo.Content.pbData = (unsigned char*)in;

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		&contentInfo,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		return 0;
	}

	*out = (unsigned char *)malloc(length);
	if (*out == 0)
	{
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		&contentInfo,
		0, 0,
		*out, &length);
	if (b == FALSE)
	{
		free(*out);
		return 0;
	}
	*outLen = (int)length;
	return 1;
}

