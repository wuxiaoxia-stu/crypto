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

void Usage(const char *progName)
{
	printf("Usage: %s certFileName cipherTextFileName clearTextFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* cipherTextFileName;
	const char* clearTextFileName;
	unsigned char *cipher;
	int cipherLen;
	PCCERT_CONTEXT cert;
	BOOL b;
	HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey;
	DWORD lastError;
	NTSTATUS rv;
	ULONG length;
	UCHAR* clear;
	DWORD dwKeySpec;
	BOOL fCallerFreeProvOrNCryptKey;

	if (argc != 4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName = argv[1];
	cipherTextFileName = argv[2];
	clearTextFileName = argv[3];

	cert = GetCert(certFileName);
	if (cert == NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}

	if (ReadFileData(cipherTextFileName, &cipher, &cipherLen) == 0)
	{
		printf("Read CipherText file fail\n");
		CertFreeCertificateContext(cert);
		return -1;
	}
	
	b = CryptAcquireCertificatePrivateKey(cert,CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG, NULL, &hKey,
		&dwKeySpec, &fCallerFreeProvOrNCryptKey);
	lastError = GetLastError();
	CertFreeCertificateContext(cert);
	if (b == FALSE)
	{
		printf("CryptAcquireCertificatePrivateKey fail,error code=0X%X\n", lastError);
		free(cipher);
		return -1;
	}
	

	if (dwKeySpec == CERT_NCRYPT_KEY_SPEC)
	{
		rv = NCryptDecrypt(hKey, (PUCHAR)cipher, (ULONG)cipherLen,
			0, 0, 0, &length, NCRYPT_PAD_PKCS1_FLAG);
		if (rv != STATUS_SUCCESS)
		{
			printf("NCryptDecrypt fail,return 0X%X\n", rv);
			if (fCallerFreeProvOrNCryptKey)
			{
				NCryptFreeObject(hKey);
			}
			free(cipher);
			return -1;
		}
		clear = (UCHAR *)malloc(length);
		if (clear == 0)
		{
			printf("malloc fail\n");
			if (fCallerFreeProvOrNCryptKey)
			{
				NCryptFreeObject(hKey);
			}
			free(cipher);
			return -1;
		}
		rv = NCryptDecrypt(hKey, (PUCHAR)cipher, (ULONG)cipherLen,
			0, clear, length, &length, NCRYPT_PAD_PKCS1_FLAG);
		if (fCallerFreeProvOrNCryptKey)
		{
			NCryptFreeObject(hKey);
		}
		free(cipher);
		if (rv != STATUS_SUCCESS)
		{
			printf("NCryptDecrypt fail,return 0X%X\n", rv);
			free(clear);
			return -1;
		}
	}
	else
	{
		int i;
		unsigned char temp;
		HCRYPTKEY hUserKey;
		DWORD tempLen;

		b = CryptGetUserKey(hKey,dwKeySpec,&hUserKey);
		lastError = GetLastError();
		if (b == FALSE)
		{
			printf("CryptGetUserKey fail,error code=0X%X\n", lastError);
			free(cipher);
			if (fCallerFreeProvOrNCryptKey)
			{
				CryptReleaseContext(hKey, 0);
			}
			return -1;
		}

		for (i = 0; i < cipherLen / 2; i++)
		{
			temp = cipher[i];
			cipher[i] = cipher[cipherLen - 1 - i];
			cipher[cipherLen - 1 - i] = temp;
		}
		tempLen = cipherLen;
		b = CryptDecrypt(hUserKey, 0, TRUE, 0, cipher, &tempLen);
		lastError = GetLastError();
		CryptDestroyKey(hUserKey);
		if (fCallerFreeProvOrNCryptKey)
		{
			CryptReleaseContext(hKey, 0);
		}
		if (b == FALSE)
		{
			printf("CryptGetUserKey fail,error code=0X%X\n", lastError);
			free(cipher);
			return -1;
		}
		clear = cipher;
		length = tempLen;
	}
	if (SaveFile(clearTextFileName, (const unsigned char *)clear, (int)length) == 0)
	{
		printf("SaveFile fail\n");
		free(clear);
		return -1;
	}
	free(clear);
	printf("Decrypt success\n");

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
