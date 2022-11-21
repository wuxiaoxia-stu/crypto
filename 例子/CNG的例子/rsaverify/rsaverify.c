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
static int Hash(LPCWSTR hashAlgo, const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen);
static LPCWSTR GetHashAlgoNameFromSignAlgo(const char *signAlgo);

void Usage(const char *progName)
{
	printf("Usage: %s sha1withrsa|sha256withrsa certFileName tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* tbs;
	const char* signFileName;
	PCCERT_CONTEXT cert;
	BOOL b;
	DWORD lastError;
	BCRYPT_KEY_HANDLE hKey;
	NTSTATUS rv;
	int signLen;
	BYTE* sign;
	unsigned char *hashValue;
	int hashLen;
	const char* signAlgo;
	LPCWSTR hashAlgo;
	BCRYPT_PKCS1_PADDING_INFO paddingInfo;

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

	b = CryptImportPublicKeyInfoEx2(X509_ASN_ENCODING, &cert->pCertInfo->SubjectPublicKeyInfo, 0, NULL, &hKey);
	lastError = GetLastError();
	CertFreeCertificateContext(cert);
	if (b == FALSE)
	{
		printf("CryptImportPublicKeyInfoEx2 fail,error code=0X%X\n", lastError);
		return -1;
	}
	hashAlgo = GetHashAlgoNameFromSignAlgo(signAlgo);
	if (hashAlgo == 0)
	{
		printf("unsupport sign algo\n");
		BCryptDestroyKey(hKey);
		return -1;
	}
	if (Hash(hashAlgo, (const unsigned char*)tbs, (int)strlen(tbs), &hashValue, &hashLen) == 0)
	{
		printf("Hash fail\n");
		BCryptDestroyKey(hKey);
		return -1;
	}

	if (ReadFileData(signFileName, &sign, &signLen) == 0)
	{
		printf("Read sign file fail\n");
		BCryptDestroyKey(hKey);
		free(hashValue);
		return -1;
	}
	paddingInfo.pszAlgId = hashAlgo;
	rv = BCryptVerifySignature(hKey, &paddingInfo, hashValue, (ULONG)hashLen,
		sign, signLen, BCRYPT_PAD_PKCS1);
	BCryptDestroyKey(hKey);
	free(hashValue);
	free(sign);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptVerifySignature fail,error code=0X%X\n", rv);
		return -1;
	}

	printf("Verify success\n");

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
	if (stricmp(signAlgo, "sha1withrsa") == 0)
	{
		return BCRYPT_SHA1_ALGORITHM;
	}
	else if (stricmp(signAlgo, "sha256withrsa") == 0)
	{
		return BCRYPT_SHA256_ALGORITHM;
	}
	else if (stricmp(signAlgo, "sha384withrsa") == 0)
	{
		return BCRYPT_SHA384_ALGORITHM;
	}
	else if (stricmp(signAlgo, "sha512withrsa") == 0)
	{
		return BCRYPT_SHA512_ALGORITHM;
	}
	else
	{
		return 0;
	}
}

