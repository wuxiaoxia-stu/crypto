#define CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
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
static int Sign(PCCERT_CONTEXT cert, int detached, const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen);
static int ToQ7SignedData(const unsigned char *in, int inLen, unsigned char** out, int *outLen);

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
	rv = Sign(cert, detached, (const unsigned char*)tbs, (int)strlen(tbs),
		&sign, &signLen);
	CertFreeCertificateContext(cert);
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


int Sign(PCCERT_CONTEXT cert, int detached, const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen)
{
	BOOL b;
	CRYPT_SIGN_MESSAGE_PARA param;
	const unsigned char *tbsArray[1];
	DWORD tbsLenArray[1];
	unsigned char *out;
	DWORD outLen;
	PCCERT_CONTEXT certs[1];
	int rv;

	memset(&param, 0, sizeof(param));
	param.cbSize = sizeof(param);
	param.dwMsgEncodingType = X509_ASN_ENCODING | PKCS_7_ASN_ENCODING;
	param.pSigningCert = cert;
	param.HashAlgorithm.pszObjId = (LPSTR)SM3_OID;
	param.pvHashAuxInfo = 0;

	tbsArray[0] = tbs;
	tbsLenArray[0] = tbsLen;


	certs[0] = cert;

	param.cMsgCert = 1;
	param.rgpMsgCert = certs;
	param.cMsgCrl = 0;
	param.rgpMsgCrl = 0;

	param.cAuthAttr = 0;
	param.rgAuthAttr = 0;

	param.cUnauthAttr = 0;
	param.rgUnauthAttr = 0;
	param.dwFlags = 0;
	param.dwInnerContentType = 0;
	param.HashEncryptionAlgorithm.pszObjId = (LPSTR)SM2SIGN_OID;
	param.pvHashEncryptionAuxInfo = 0;

	b = CryptSignMessage(
		&param,
		detached ? TRUE : FALSE,
		1,
		tbsArray,
		tbsLenArray,
		0,
		&outLen
		);
	if (b == 0)
	{
		return 0;
	}
	out = (unsigned char *)malloc(outLen);
	if (out == 0)
	{
		return 0;
	}
	b = CryptSignMessage(
		&param,
		detached ? TRUE : FALSE,
		1,
		tbsArray,
		tbsLenArray,
		out,
		&outLen
		);
	if (b == 0)
	{
		free(out);
		return 0;
	}
	rv = ToQ7SignedData(out, (int)outLen, sign, signLen);
	free(out);
	
	return rv;
}

int ToQ7SignedData(const unsigned char *in,int inLen,unsigned char** out,int *outLen)
{
	BOOL b;
	DWORD length;
	CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *oldSignedData;
	CRYPT_CONTENT_INFO *oldInnerContentInfo;
	unsigned char *innerContentInfoEncode;
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, 0,
		0, &length);
	if (b == 0)
	{
		return 0;
	}
	oldSignedData = (CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *)malloc(length);
	if (oldSignedData == 0)
	{
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, 0,
		oldSignedData, &length);
	if (b == FALSE)
	{
		free(oldSignedData);
		return 0;
	}
	oldSignedData->pszObjId = SM2SIGNEDDATA_OID;
	if (oldSignedData->cValue < 3)
	{
		free(oldSignedData);
		return 0;
	}

	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		oldSignedData->rgValue[2].pbData, 
		oldSignedData->rgValue[2].cbData,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(oldSignedData);
		return 0;
	}
	oldInnerContentInfo = (CRYPT_CONTENT_INFO*)malloc(length);
	if (oldInnerContentInfo == 0)
	{
		free(oldSignedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		oldSignedData->rgValue[2].pbData,
		oldSignedData->rgValue[2].cbData,
		0, 0,
		oldInnerContentInfo, &length);
	if (b == FALSE)
	{
		free(oldInnerContentInfo);
		free(oldSignedData);
		return 0;
	}
	oldInnerContentInfo->pszObjId = SM2DATA_OID;

	b=CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		oldInnerContentInfo,
		0,0,
		0,&length);
	if (b == FALSE)
	{
		free(oldInnerContentInfo);
		free(oldSignedData);
		return 0;
	}
	innerContentInfoEncode = (unsigned char*)malloc(length);
	if (innerContentInfoEncode == 0)
	{
		free(oldInnerContentInfo);
		free(oldSignedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO,
		oldInnerContentInfo,
		0, 0,
		innerContentInfoEncode, &length);
	free(oldInnerContentInfo);
	if (b == FALSE)
	{
		free(innerContentInfoEncode);
		free(oldSignedData);
		return 0;
	}
	oldSignedData->rgValue[2].pbData = innerContentInfoEncode;
	oldSignedData->rgValue[2].cbData = length;
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		oldSignedData,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(innerContentInfoEncode);
		free(oldSignedData);
		return 0;
	}
	*out = (unsigned char*)malloc(length);
	if (*out == 0)
	{
		free(innerContentInfoEncode);
		free(oldSignedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		oldSignedData,
		0, 0,
		*out, &length);
	free(innerContentInfoEncode);
	free(oldSignedData);
	if (b == FALSE)
	{
		free(*out);
		return 0;
	}
	*outLen = (int)length;
	return 1;
}
