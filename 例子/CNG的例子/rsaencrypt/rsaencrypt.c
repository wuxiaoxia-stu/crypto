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
	printf("Usage: %s certFileName clearText cipherTextFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* certFileName;
	const char* clearText;
	const char* cipherTextFileName;
	PCCERT_CONTEXT cert;
	BOOL b;
	BCRYPT_KEY_HANDLE hKey;
	DWORD lastError;
	NTSTATUS rv;
	ULONG length;
	UCHAR *cipher;

	if (argc != 4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName = argv[1];
	clearText = argv[2];
	cipherTextFileName = argv[3];

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

	rv = BCryptEncrypt(hKey, (PUCHAR)clearText, (ULONG)strlen(clearText),
		0, 0, 0,
		0, 0, &length, BCRYPT_PAD_PKCS1);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptEncrypt fail,return 0X%X\n", rv);
		BCryptDestroyKey(hKey);
		return -1;
	}
	cipher = (UCHAR *)malloc(length);
	if (cipher == 0)
	{
		printf("malloc fail\n");
		BCryptDestroyKey(hKey);
		return -1;
	}
	rv = BCryptEncrypt(hKey, (PUCHAR)clearText, (ULONG)strlen(clearText),
		0, 0, 0,
		cipher, length, &length, BCRYPT_PAD_PKCS1);
	BCryptDestroyKey(hKey);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptEncrypt fail,return 0X%X\n", rv);
		free(cipher);
		return -1;
	}

	if (SaveFile(cipherTextFileName, (const unsigned char *)cipher, (int)length) == 0)
	{
		printf("SaveFile fail\n");
		free(cipher);
		return -1;
	}
	free(cipher);

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
