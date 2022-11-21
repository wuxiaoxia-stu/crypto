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
static int SM3(const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen);
static void ToLittleEncode(unsigned char *data, int dataLen);

void Usage(const char *progName)
{
	printf("Usage: %s certFileName tbs signFileName\n", progName);
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
	CERT_ECC_SIGNATURE sm2Sign;
	unsigned char *sm2SignEncode;
	DWORD sm2SignEncodeLen;

	if (argc != 4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName = argv[1];
	tbs = argv[2];
	signFileName = argv[3];

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
	if (SM3((const unsigned char*)tbs, (int)strlen(tbs), &hashValue, &hashLen) == 0)
	{
		printf("SM3 fail\n");
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		return -1;
	}
	rv = NCryptSignHash(hKey,0,hashValue,(DWORD)hashLen,
		0, 0, &length,0);
	if (rv != ERROR_SUCCESS)
	{
		printf("NCryptSignHash fail,error code=0X%X\n",rv);
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
	sm2Sign.r.cbData = (int)(length / 2);
	sm2Sign.r.pbData = sign;
	ToLittleEncode(sm2Sign.r.pbData, (int)sm2Sign.r.cbData);

	sm2Sign.s.cbData = (int)(length - sm2Sign.r.cbData);
	sm2Sign.s.pbData = &sign[sm2Sign.r.cbData];
	ToLittleEncode(sm2Sign.s.pbData, (int)sm2Sign.s.cbData);


	b = CryptEncodeObjectEx(
		PKCS_7_ASN_ENCODING | X509_ASN_ENCODING,
		X509_ECC_SIGNATURE, &sm2Sign,
		0, 0, 0, &sm2SignEncodeLen);
	if (b == FALSE)
	{
		printf("CryptEncodeObjectEx fail,error code=0X%X\n", GetLastError());
		free(sign);
		return -1;
	}
	sm2SignEncode = (unsigned char*)malloc(sm2SignEncodeLen);
	if (sm2SignEncode == 0)
	{
		printf("malloc fail\n");
		free(sign);
		return -1;
	}
	b = CryptEncodeObjectEx(
		PKCS_7_ASN_ENCODING | X509_ASN_ENCODING,
		X509_ECC_SIGNATURE, &sm2Sign,
		0, 0, sm2SignEncode, &sm2SignEncodeLen);
	if (b == FALSE)
	{
		printf("CryptEncodeObjectEx fail,error code=0X%X\n", GetLastError());
		free(sign);
		free(sm2SignEncode);
		return -1;
	}
	free(sign);
	if (SaveFile(signFileName, sm2SignEncode, (int)sm2SignEncodeLen) == 0)
	{
		printf("SaveFile fail\n");
		free(sm2SignEncode);
		return -1;
	}
	free(sm2SignEncode);
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

int SM3(const unsigned char *data,int dataLen,unsigned char **pHashValue,int *pHashLen)
{
	NTSTATUS rv;
	BCRYPT_ALG_HANDLE hAlgorithm;
	UCHAR *hashObj;
	DWORD hashObjLen;
	ULONG len;
	UCHAR *hashValue;
	DWORD hashLen;
	BCRYPT_HASH_HANDLE  hSm3;

	rv = BCryptOpenAlgorithmProvider(&hAlgorithm, L"SM3", L"NETCA SM2 CNG Provider", 0);
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

void ToLittleEncode(unsigned char *data,int dataLen)
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
