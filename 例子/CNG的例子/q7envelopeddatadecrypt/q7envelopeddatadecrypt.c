#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static int GetFileLength(FILE *fp);
static void Usage(const char *progName);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
static int SaveFile(const char *fileName, const unsigned char *buf, int bufLen);
static int ToCMSEnvelopedData(const unsigned char* in, int inLen, unsigned char** out, int *outLen);

void Usage(const char *progName)
{
	printf("Usage: %s encFileName clearFileName\n", progName);
}
int main(int argc, char **argv)
{
	const char* clearFileName;
	const char* encFileName;
	unsigned char* env;
	int envLen;
	unsigned char* cmsEnv;
	int cmsEnvLen;
	int rv;
	BOOL b;
	CRYPT_DECRYPT_MESSAGE_PARA param;
	unsigned char *clear;
	DWORD clearLen;
	HCERTSTORE hStore;
	if (argc != 3)
	{
		Usage(argv[0]);
		return -1;
	}

	encFileName = argv[1];
	clearFileName = argv[2];

	rv = ReadFileData(encFileName, &env, &envLen);
	if (rv == 0)
	{
		printf("read encrypt file fail\n");
		return 0;
	}

	rv = ToCMSEnvelopedData(env, envLen, &cmsEnv, &cmsEnvLen);
	free(env);
	if (rv == 0)
	{
		printf("ToCMSEnvelopedData fail\n");
		return 0;
	}
	env = cmsEnv;
	envLen = cmsEnvLen;

	memset(&param, 0, sizeof(param));
	param.cbSize = sizeof(param);
	param.dwMsgAndCertEncodingType = X509_ASN_ENCODING | PKCS_7_ASN_ENCODING;

	hStore = CertOpenSystemStore(0, L"my");
	if (hStore == 0)
	{
		printf("CertOpenSystemStore fail,error code=0X%X\n", GetLastError());
		free(env);
		return 0;
	}
	param.cCertStore = 1;
	param.rghCertStore = &hStore;

	b = CryptDecryptMessage(
		&param,
		env, (DWORD)envLen,
		0, &clearLen, 0);
	if (b == FALSE)
	{
		printf("CryptDecryptMessage fail,error code=0X%X\n", GetLastError());
		free(env);
		CertCloseStore(hStore, 0);
		return -1;
	}
	clear = (unsigned char*)malloc(clearLen);
	if (clear == 0)
	{
		free(env);
		CertCloseStore(hStore, 0);
		printf("malloc fail\n");
		return -1;
	}
	b = CryptDecryptMessage(
		&param,
		env, (DWORD)envLen,
		clear, &clearLen, 0);
	if (b == FALSE)
	{
		printf("CryptDecryptMessage fail,error code=0X%X\n", GetLastError());
		free(clear);
		free(env);
		CertCloseStore(hStore, 0);
		return -1;
	}
	free(env);
	CertCloseStore(hStore, 0);
	rv = SaveFile(clearFileName, clear, (int)clearLen);
	free(clear);
	if (rv == 0)
	{
		printf("SaveFile fail\n");
		return -1;
	}
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

int ToCMSEnvelopedData(const unsigned char* in, int inLen, unsigned char** out, int *outLen)
{
	BOOL b;
	DWORD length;
	CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *envelopedData;


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
	envelopedData->pszObjId = szOID_RSA_envelopedData;
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		envelopedData,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(envelopedData);
		return 0;
	}
	*out = (unsigned char*)malloc(length);
	if (*out == 0)
	{
		free(envelopedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		envelopedData,
		0, 0,
		*out, &length);
	free(envelopedData);
	if (b == FALSE)
	{
		free(*out);
		return 0;
	}
	*outLen = (int)length;
	return 1;
}
