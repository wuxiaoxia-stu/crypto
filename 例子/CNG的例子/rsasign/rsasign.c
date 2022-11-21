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
static int RSACNGSignHash(LPCWSTR hashAlgo, NCRYPT_KEY_HANDLE hKey, const unsigned char *hashValue, int hashLen, unsigned char **signature, int *signatureLen);
static int RSACSPSignHash(LPCWSTR hashAlgo, HCRYPTPROV hProv, DWORD dwKeySpec, const unsigned char *hashValue, unsigned char **signature, int *signatureLen);
static ALG_ID GetHashAlgoIdFromName(LPCWSTR hashAlgo);
static HCRYPTHASH CreateHashHandle(LPCWSTR hashAlgo, HCRYPTPROV hProv, const unsigned char *hashValue);

void Usage(const char *progName)
{
	printf("Usage: %s sha1withrsa|sha256withrsa certFileName tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* tbs;
	const char* signFileName;
	const char* signAlgo;
	LPCWSTR hashAlgo;
	PCCERT_CONTEXT cert;
	BOOL b;
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey;
	DWORD lastError;
	DWORD dwKeySpec;
	BOOL fCallerFreeProvOrNCryptKey;
	unsigned char *hashValue;
	int hashLen;
	unsigned char *sign;
	int signLen;
	

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

	b = CryptAcquireCertificatePrivateKey(cert, CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG, NULL, &hKey,
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
			if (dwKeySpec == CERT_NCRYPT_KEY_SPEC)
			{
				NCryptFreeObject(hKey);
			}
			else
			{
				CryptReleaseContext(hKey, 0);
			}
		}
		return -1;
	}
	if (Hash(hashAlgo,(const unsigned char*)tbs, (int)strlen(tbs), &hashValue, &hashLen) == 0)
	{
		printf("Hash fail\n");
		if (fCallerFreeProvOrNCryptKey)
		{
			if (dwKeySpec == CERT_NCRYPT_KEY_SPEC)
			{
				NCryptFreeObject(hKey);
			}
			else
			{
				CryptReleaseContext(hKey, 0);
			}
		}
		return -1;
	}
	if (dwKeySpec == CERT_NCRYPT_KEY_SPEC)
	{
		if (RSACNGSignHash(hashAlgo, hKey, hashValue, hashLen, &sign, &signLen) == 0)
		{
			printf("Sign fail\n");
			if (fCallerFreeProvOrNCryptKey)
			{
				NCryptFreeObject(hKey);
			}
			return -1;
		}
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
	}
	else
	{
		if (RSACSPSignHash(hashAlgo, hKey, dwKeySpec, hashValue,  &sign, &signLen) == 0)
		{
			printf("Sign fail\n");
			if (fCallerFreeProvOrNCryptKey)
			{
				CryptReleaseContext(hKey, 0);
			}
			return -1;
		}
		if (fCallerFreeProvOrNCryptKey)
		{
			CryptReleaseContext(hKey, 0);
		}

	}
	if (SaveFile(signFileName, sign, signLen) == 0)
	{
		printf("SaveFile fail\n");
		free(sign);
		return -1;
	}
	free(sign);
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

int Hash(LPCWSTR hashAlgo,const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen)
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

int RSACNGSignHash(LPCWSTR hashAlgo, NCRYPT_KEY_HANDLE hKey,const unsigned char *hashValue, int hashLen, unsigned char **signature, int *signatureLen)
{
	SECURITY_STATUS rv;
	BCRYPT_PKCS1_PADDING_INFO paddingInfo;
	DWORD length;
	BYTE *sign;

	paddingInfo.pszAlgId = hashAlgo;

	rv = NCryptSignHash(hKey, &paddingInfo,(PBYTE)hashValue, (DWORD)hashLen,
		0, 0, &length, BCRYPT_PAD_PKCS1);
	if (rv != ERROR_SUCCESS)
	{
		return 0;
	}

	sign = (BYTE *)malloc(length);
	if (sign == 0)
	{
		return 0;
	}
	rv = NCryptSignHash(hKey, &paddingInfo,(PBYTE) hashValue, (DWORD)hashLen,
		sign, length, &length, BCRYPT_PAD_PKCS1);
	if (rv != ERROR_SUCCESS)
	{
		free(sign);
		return 0;
	}

	*signature = sign;
	*signatureLen = (int)length;
	return 1;
}

int RSACSPSignHash(LPCWSTR hashAlgo, HCRYPTPROV hProv, DWORD dwKeySpec, const unsigned char *hashValue, unsigned char **signature, int *signatureLen)
{
	HCRYPTHASH hHash;
	BOOL b;
	unsigned char *sign;
	DWORD length;

	hHash = CreateHashHandle(hashAlgo, hProv, hashValue);
	if (hHash == 0)
	{
		return 0;
	}
	b = CryptSignHash(hHash, dwKeySpec,0, 0, 0, &length);
	if (b == FALSE)
	{
		CryptDestroyHash(hHash);
		return 0;
	}
	sign = (unsigned char*)malloc(length);
	if (sign == 0)
	{
		CryptDestroyHash(hHash);
		return 0;
	}
	b = CryptSignHash(hHash, dwKeySpec, 0, 0, sign, &length);
	CryptDestroyHash(hHash);
	if (b == FALSE)
	{
		free(sign);
		return 0;
	}
	
	ToLittleEncode(sign, (int)length);
	*signature = sign;
	*signatureLen = (int)length;

	return 1;
}

HCRYPTHASH CreateHashHandle(LPCWSTR hashAlgo, HCRYPTPROV hProv, const unsigned char *hashValue)
{
	ALG_ID hashAlgoId = GetHashAlgoIdFromName(hashAlgo);
	BOOL b;
	HCRYPTHASH hHash;
	b = CryptCreateHash(hProv, hashAlgoId,
		0, 0, &hHash);
	if (b == FALSE)
	{
		return 0;
	}
	b = CryptSetHashParam(hHash, HP_HASHVAL,
		hashValue, 0);
	if (b == FALSE)
	{
		CryptDestroyHash(hHash);
		return 0;
	}
	return hHash;
}

ALG_ID GetHashAlgoIdFromName(LPCWSTR hashAlgo)
{
	if (wcscmp(hashAlgo,BCRYPT_SHA1_ALGORITHM)==0)
	{
		return CALG_SHA1;
	}
	else if (wcscmp(hashAlgo, BCRYPT_SHA256_ALGORITHM) == 0)
	{
		return CALG_SHA_256;
	}
	else if (wcscmp(hashAlgo, BCRYPT_SHA384_ALGORITHM) == 0)
	{
		return CALG_SHA_384;
	}
	else if (wcscmp(hashAlgo, BCRYPT_SHA512_ALGORITHM) == 0)
	{
		return CALG_SHA_512;
	}
	else
	{
		return (ALG_ID)- 1;
	}
}
