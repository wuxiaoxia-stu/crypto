#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>

static void Usage(const char *progName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
static PCCERT_CONTEXT GetCert(const char *fileName);
static int SaveFile(const char *fileName, const unsigned char *buf, int bufLen);
static void ToLittleEncode(unsigned char *data, int dataLen);
static LPCWSTR GetHashAlgoNameFromSignAlgo(const char *signAlgo);
static int Hash(LPCWSTR hashAlgo, const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen);

void Usage(const char *progName)
{
	printf("Usage: %s ecdsawithsha1|ecdsawithsha256 certFileName tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* tbs;
	const char* signFileName;
	PCCERT_CONTEXT cert;
	BOOL b;
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey;
	DWORD lastError;
	SECURITY_STATUS rv;
	DWORD length;
	BYTE* sign;
	DWORD dwKeySpec;
	BOOL fCallerFreeProvOrNCryptKey;
	unsigned char *hashValue;
	int hashLen;
	CERT_ECC_SIGNATURE eccSign;
	unsigned char *eccSignEncode;
	DWORD eccSignEncodeLen;
	const char* signAlgo;
	LPCWSTR hashAlgo;

	if (argc != 5)
	{
		Usage(argv[0]);
		return -1;
	}
	signAlgo = argv[1];
	certFileName = argv[2];
	tbs = argv[3];
	signFileName = argv[4];

	cert = GetCert(certFileName);
	if (cert == NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}

	b = CryptAcquireCertificatePrivateKey(cert, CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG, NULL, &hKey,
		&dwKeySpec, &fCallerFreeProvOrNCryptKey);
	lastError = GetLastError();
	CertFreeCertificateContext(cert);
	if (b == FALSE)
	{
		printf("CryptAcquireCertificatePrivateKey fail,error code=0X%X\n", lastError);
		return -1;
	}
	hashAlgo = GetHashAlgoNameFromSignAlgo(signAlgo);
	if (hashAlgo == 0)
	{
		printf("unsupport sign algo\n");
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		return -1;
	}
	if (Hash(hashAlgo, (const unsigned char*)tbs, (int)strlen(tbs), &hashValue, &hashLen) == 0)
	{
		printf("Hash fail\n");
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		return -1;
	}
	rv = NCryptSignHash(hKey, 0, hashValue, (DWORD)hashLen,
		0, 0, &length, 0);
	if (rv != ERROR_SUCCESS)
	{
		printf("NCryptSignHash fail,error code=0X%X\n", rv);
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		free(hashValue);
		return -1;
	}

	sign = (BYTE *)malloc(length);
	if (sign == 0)
	{
		printf("malloc fail\n");
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		free(hashValue);
		return -1;
	}
	rv = NCryptSignHash(hKey, 0, hashValue, (DWORD)hashLen,
		sign, length, &length, 0);
	if (fCallerFreeProvOrNCryptKey)
	{
		NCryptFreeObject(hKey);
	}
	free(hashValue);
	if (rv != ERROR_SUCCESS)
	{
		printf("NCryptSignHash fail,error code=0X%X\n", rv);
		free(sign);
		return -1;
	}
	eccSign.r.cbData = (int)(length / 2);
	eccSign.r.pbData = sign;
	ToLittleEncode(eccSign.r.pbData, (int)eccSign.r.cbData);

	eccSign.s.cbData = (int)(length - eccSign.r.cbData);
	eccSign.s.pbData = &sign[eccSign.r.cbData];
	ToLittleEncode(eccSign.s.pbData, (int)eccSign.s.cbData);


	b = CryptEncodeObjectEx(
		PKCS_7_ASN_ENCODING | X509_ASN_ENCODING,
		X509_ECC_SIGNATURE, &eccSign,
		0, 0, 0, &eccSignEncodeLen);
	if (b == FALSE)
	{
		printf("CryptEncodeObjectEx fail,error code=0X%X\n", GetLastError());
		free(sign);
		return -1;
	}
	eccSignEncode = (unsigned char*)malloc(eccSignEncodeLen);
	if (eccSignEncode == 0)
	{
		printf("malloc fail\n");
		free(sign);
		return -1;
	}
	b = CryptEncodeObjectEx(
		PKCS_7_ASN_ENCODING | X509_ASN_ENCODING,
		X509_ECC_SIGNATURE, &eccSign,
		0, 0, eccSignEncode, &eccSignEncodeLen);
	if (b == FALSE)
	{
		printf("CryptEncodeObjectEx fail,error code=0X%X\n", GetLastError());
		free(sign);
		free(eccSignEncode);
		return -1;
	}
	free(sign);
	if (SaveFile(signFileName, eccSignEncode, (int)eccSignEncodeLen) == 0)
	{
		printf("SaveFile fail\n");
		free(eccSignEncode);
		return -1;
	}
	free(eccSignEncode);
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

void ToLittleEncode(unsigned char *data, int dataLen)
{
	int i;
	unsigned char temp;

	for (i = 0; i < dataLen / 2; i++)
	{
		temp = data[i];
		data[i] = data[dataLen - 1 - i];
		data[dataLen - 1 - i] = temp;
	}
}

int Hash(LPCWSTR hashAlgo, const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen)
{
	NTSTATUS rv;
	BCRYPT_ALG_HANDLE hAlgorithm;
	UCHAR *hashObj;
	DWORD hashObjLen;
	ULONG len;
	UCHAR *hashValue;
	DWORD hashLen;
	BCRYPT_HASH_HANDLE  hSm3;

	rv = BCryptOpenAlgorithmProvider(&hAlgorithm, hashAlgo, 0, 0);
	if (rv != STATUS_SUCCESS)
	{
		return 0;
	}
	rv = BCryptGetProperty(hAlgorithm, BCRYPT_OBJECT_LENGTH,
		(PBYTE)&hashObjLen, sizeof(DWORD), &len, 0);
	if (rv != STATUS_SUCCESS)
	{
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}

	rv = BCryptGetProperty(hAlgorithm, BCRYPT_HASH_LENGTH,
		(PBYTE)&hashLen, sizeof(DWORD), &len, 0);
	if (rv != STATUS_SUCCESS)
	{
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}

	hashObj = (UCHAR*)malloc(hashObjLen);
	if (hashObj == 0)
	{
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}
	rv = BCryptCreateHash(hAlgorithm, &hSm3, hashObj, hashObjLen, 0, 0, 0);
	if (rv != STATUS_SUCCESS)
	{
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}

	rv = BCryptHashData(hSm3, (PUCHAR)data, (ULONG)dataLen, 0);
	if (rv != STATUS_SUCCESS)
	{
		BCryptDestroyHash(hSm3);
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}
	hashValue = (UCHAR*)malloc(hashLen);
	if (hashValue == 0)
	{
		BCryptDestroyHash(hSm3);
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return 0;
	}
	rv = BCryptFinishHash(hSm3, hashValue, hashLen, 0);
	BCryptDestroyHash(hSm3);
	free(hashObj);
	BCryptCloseAlgorithmProvider(hAlgorithm, 0);
	if (rv != STATUS_SUCCESS)
	{
		free(hashValue);
		return 0;
	}

	*pHashValue = hashValue;
	*pHashLen = (int)hashLen;
	return 1;
}

LPCWSTR GetHashAlgoNameFromSignAlgo(const char *signAlgo)
{
	if (stricmp(signAlgo, "ecdsawithsha1") == 0)
	{
		return BCRYPT_SHA1_ALGORITHM;
	}
	else if (stricmp(signAlgo, "ecdsawithsha256") == 0)
	{
		return BCRYPT_SHA256_ALGORITHM;
	}
	else if (stricmp(signAlgo, "ecdsawithsha384") == 0)
	{
		return BCRYPT_SHA384_ALGORITHM;
	}
	else if (stricmp(signAlgo, "ecdsawithsha512") == 0)
	{
		return BCRYPT_SHA512_ALGORITHM;
	}
	else
	{
		return 0;
	}
}
