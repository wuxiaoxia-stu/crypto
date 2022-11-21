#define CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SM3_OID			"1.2.156.10197.1.401"
#define SM3WITHSM2_OID "1.2.156.10197.1.501"

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
static int Sign(PCCERT_CONTEXT cert, int detached, const char* hashAlgoOid, const char* signAlgoOid, const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen);

void Usage(const char *progName)
{
	printf("Usage: %s [-detached] sm3withsm2|sha1withrsa certFileName tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* tbs;
	const char* signFileName;
	const char* signAlgoName;
	PCCERT_CONTEXT cert;
	int pos;
	int detached;
	const char* hashAlgoOid;
	const char* signAlgoOid;
	unsigned char* sign;
	int signLen;
	int rv;


	if (argc != 5 && argc != 6)
	{
		Usage(argv[0]);
		return -1;
	}

	pos = 1;
	detached = 0;
	if (argc == 6)
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
	signAlgoName = argv[pos];
	pos++;
	certFileName = argv[pos];
	pos++;
	tbs = argv[pos];
	pos++;
	signFileName = argv[pos];
	
	hashAlgoOid = GetHashAlgorithmOidFromSignAlgoName(signAlgoName);
	if (hashAlgoOid == 0)
	{
		printf("unsupport sign algo\n");
		return -1;
	}
	signAlgoOid = GetSignAlgorithmOidFromSignAlgoName(signAlgoName);
	if (signAlgoOid == 0)
	{
		printf("unsupport sign algo\n");
		return -1;
	}
	

	cert = GetCert(certFileName);
	if (cert == NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}

	rv = Sign(cert, detached, hashAlgoOid, signAlgoOid,
		(const unsigned char*)tbs, (int)strlen(tbs),
		&sign,&signLen);
	CertFreeCertificateContext(cert);
	if (rv == 0)
	{
		printf("Sign fail\n");
		return -1;
	}
	rv = SaveFile(signFileName, sign, signLen);
	free(sign);
	if(rv== 0)
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

const char* GetHashAlgorithmOidFromSignAlgoName(const char *signAlgoName)
{
	if (_stricmp(signAlgoName, "sm3withsm2")==0)
	{
		return SM3_OID;
	}
	else if (_stricmp(signAlgoName, "sha1withrsa") == 0
		|| _stricmp(signAlgoName, "ecdsawithsha1") == 0)
	{
		return szOID_OIWSEC_sha1;
	}
	else if (_stricmp(signAlgoName, "sha256withrsa") == 0
		|| _stricmp(signAlgoName, "ecdsawithsha256") == 0)
	{
		return szOID_NIST_sha256;
	}
	else if (_stricmp(signAlgoName, "sha384withrsa") == 0
		|| _stricmp(signAlgoName, "ecdsawithsha384") == 0)
	{
		return szOID_NIST_sha384;
	}
	else if (_stricmp(signAlgoName, "sha512withrsa") == 0
		|| _stricmp(signAlgoName, "ecdsawithsha512") == 0)
	{
		return szOID_NIST_sha512;
	}
	else
	{
		return 0;
	}
}
const char* GetSignAlgorithmOidFromSignAlgoName(const char *signAlgoName)
{
	if (_stricmp(signAlgoName, "sm3withsm2") == 0)
	{
		return SM3WITHSM2_OID;
	}
	else if (_stricmp(signAlgoName, "sha1withrsa") == 0)
	{
		return szOID_RSA_RSA;
	}
	else if (_stricmp(signAlgoName, "sha256withrsa") == 0)
	{
		return szOID_RSA_SHA256RSA;
	}
	else if (_stricmp(signAlgoName, "sha384withrsa") == 0)
	{
		return szOID_RSA_SHA384RSA;
	}
	else if (_stricmp(signAlgoName, "sha512withrsa") == 0)
	{
		return szOID_RSA_SHA512RSA;
	}
	else if (_stricmp(signAlgoName, "ecdsawithsha1") == 0)
	{
		return szOID_ECDSA_SHA1;
	}
	else if (_stricmp(signAlgoName, "ecdsawithsha256") == 0)
	{
		return szOID_ECDSA_SHA256;
	}
	else if (_stricmp(signAlgoName, "ecdsawithsha384") == 0)
	{
		return szOID_ECDSA_SHA384;
	}
	else if (_stricmp(signAlgoName, "ecdsawithsha512") == 0)
	{
		return szOID_ECDSA_SHA512;
	}
	else
	{
		return 0;
	}
}

int Sign(PCCERT_CONTEXT cert, int detached, const char* hashAlgoOid, const char* signAlgoOid,const unsigned char *tbs, int tbsLen, unsigned char **sign, int *signLen)
{
	BOOL b;
	CRYPT_SIGN_MESSAGE_PARA param;
	const unsigned char *tbsArray[1];
	DWORD tbsLenArray[1];
	unsigned char *out;
	DWORD outLen;
	PCCERT_CONTEXT certs[1];
	PCRYPT_ATTRIBUTE attr=0;
	CRYPT_ATTRIBUTE attrs[1];

	memset(&param, 0, sizeof(param));
	param.cbSize = sizeof(param);
	param.dwMsgEncodingType = X509_ASN_ENCODING | PKCS_7_ASN_ENCODING;
	param.pSigningCert = cert;
	param.HashAlgorithm.pszObjId = (LPSTR)hashAlgoOid;
	param.pvHashAuxInfo = 0;

	tbsArray[0] = tbs;
	tbsLenArray[0] = tbsLen;

	
	certs[0] = cert;

	param.cMsgCert = 1;
	param.rgpMsgCert = certs;
	param.cMsgCrl = 0;
	param.rgpMsgCrl = 0;

	attr = CreatSigningTimeAttribute();
	if (attr == 0)
	{
		return 0;
	}
	
	attrs[0] = *attr;
	param.cAuthAttr = 1;
	param.rgAuthAttr = attrs;
	
	param.cUnauthAttr = 0;
	param.rgUnauthAttr = 0;
	param.dwFlags = 0;
	param.dwInnerContentType = 0;
	param.HashEncryptionAlgorithm.pszObjId = (LPSTR)signAlgoOid;
	param.pvHashEncryptionAuxInfo = 0;

	b = CryptSignMessage(
		&param,
		detached?TRUE:FALSE,
		1,
		tbsArray,
		tbsLenArray,
		0,
		&outLen
		);
	if (b == 0)
	{
		FreeAttribute(attr);
		return 0;
	}
	out = (unsigned char *)malloc(outLen);
	if (out == 0)
	{
		FreeAttribute(attr);
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
	FreeAttribute(attr);
	if (b == 0)
	{
		free(out);
		return 0;
	}

	*sign = out;
	*signLen = (int)outLen;
	return 1;
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

