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
static int SM3(const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen);
static void ToBigEncode(unsigned char *data, int dataLen);
static int DecodeSM2Signature(const unsigned char *der, int derLen, unsigned char *data);

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
	DWORD lastError;
	BCRYPT_KEY_HANDLE hKey;
	NTSTATUS rv;
	int signLen;
	BYTE* sign;
	unsigned char *hashValue;
	int hashLen;
	unsigned char sm2Sign[64];

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

	b = CryptImportPublicKeyInfoEx2(X509_ASN_ENCODING, &cert->pCertInfo->SubjectPublicKeyInfo, 0, NULL, &hKey);
	lastError = GetLastError();
	CertFreeCertificateContext(cert);
	if (b == FALSE)
	{
		printf("CryptImportPublicKeyInfoEx2 fail,error code=0X%X\n", lastError);
		return -1;
	}
	if (SM3((const unsigned char*)tbs, (int)strlen(tbs), &hashValue, &hashLen) == 0)
	{
		printf("SM3 fail\n");
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
	if (DecodeSM2Signature(sign, signLen, sm2Sign) == 0)
	{
		printf("Bad Sm2 signature fail\n");
		BCryptDestroyKey(hKey);
		free(hashValue);
		free(sign);
		return -1;
	}
	free(sign);

	rv = BCryptVerifySignature(hKey, 0, hashValue, (ULONG)hashLen,
		sm2Sign, 64, 0);
	BCryptDestroyKey(hKey);
	free(hashValue);
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

int SM3(const unsigned char *data, int dataLen, unsigned char **pHashValue, int *pHashLen)
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

void ToBigEncode(unsigned char *data, int dataLen)
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

int DecodeSM2Signature(const unsigned char *der, int derLen,unsigned char *data)
{
	CERT_ECC_SIGNATURE *sm2Sign;
	BOOL b;
	DWORD length;
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ECC_SIGNATURE, der, derLen,
		0, 0, 0, &length);
	if (b == FALSE)
	{
		return 0;
	}
	sm2Sign = (CERT_ECC_SIGNATURE *)malloc(length);
	if (sm2Sign == 0)
	{
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_ECC_SIGNATURE, der, derLen,
		0, 0, sm2Sign, &length);
	if (b == FALSE)
	{
		free(sm2Sign);
		return 0;
	}
	if (sm2Sign->r.cbData > 33 || sm2Sign->s.cbData > 33)
	{
		free(sm2Sign);
		return 0;
	}
	ToBigEncode(sm2Sign->r.pbData, (int)sm2Sign->r.cbData);
	ToBigEncode(sm2Sign->s.pbData, (int)sm2Sign->s.cbData);
	memset(data, 0, 64);
	if (sm2Sign->r.cbData == 33)
	{
		if (sm2Sign->r.pbData[0] != 0 && (sm2Sign->r.pbData[1] & 0x80) == 0)
		{
			free(sm2Sign);
			return 0;
		}
		memcpy(data, &sm2Sign->r.pbData[1], 32);
	}
	else
	{
		memcpy(&data[32 - sm2Sign->r.cbData], sm2Sign->r.pbData, sm2Sign->r.cbData);
	}
	if (sm2Sign->s.cbData == 33)
	{
		if (sm2Sign->s.pbData[0] != 0 && (sm2Sign->s.pbData[1] & 0x80) == 0)
		{
			free(sm2Sign);
			return 0;
		}
		memcpy(&data[32], &sm2Sign->s.pbData[1], 32);
	}
	else
	{
		memcpy(&data[64- sm2Sign->s.cbData], sm2Sign->s.pbData, sm2Sign->s.cbData);
	}
	free(sm2Sign);
	return 1;
}
