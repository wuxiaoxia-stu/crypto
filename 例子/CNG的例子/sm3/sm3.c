#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <bcrypt.h>
#include <ntstatus.h>

int main(int argc, char **argv)
{
	NTSTATUS rv;
	BCRYPT_ALG_HANDLE hAlgorithm;
	const char *data;
	UCHAR *hashObj;
	DWORD hashObjLen;
	ULONG len;
	UCHAR *hashValue;
	DWORD hashLen;
	BCRYPT_HASH_HANDLE  hSm3;
	DWORD i;

	if (argc != 2)
	{
		printf("Usage:%s data\n", argv[0]);
		return -1;
	}
	data = argv[1];

	rv=BCryptOpenAlgorithmProvider(&hAlgorithm, L"SM3", L"NETCA SM2 CNG Provider",0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptOpenAlgorithmProvider fail,return 0X%X\n", rv);
		return -1;
	}
	rv = BCryptGetProperty(hAlgorithm, BCRYPT_OBJECT_LENGTH,
		(PBYTE)&hashObjLen, sizeof(DWORD), &len, 0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptGetProperty BCRYPT_OBJECT_LENGTH fail,return 0X%X\n", rv);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}

	rv = BCryptGetProperty(hAlgorithm, BCRYPT_HASH_LENGTH,
		(PBYTE)&hashLen, sizeof(DWORD), &len, 0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptGetProperty BCRYPT_HASH_LENGTH fail,return 0X%X\n", rv);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}
		
	hashObj = (UCHAR*)malloc(hashObjLen);
	if (hashObj == 0)
	{
		printf("malloc fail\n", rv);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}
	rv = BCryptCreateHash(hAlgorithm, &hSm3, hashObj, hashObjLen, 0, 0, 0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptCreateHash fail,return 0X%X\n", rv);
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}

	rv = BCryptHashData(hSm3, (PUCHAR)data, (ULONG)(strlen(data)), 0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptHashData fail,return 0X%X\n", rv);
		BCryptDestroyHash(hSm3);
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}
	hashValue = (UCHAR*)malloc(hashLen);
	if (hashValue == 0)
	{
		printf("malloc fail\n");
		BCryptDestroyHash(hSm3);
		free(hashObj);
		BCryptCloseAlgorithmProvider(hAlgorithm, 0);
		return -1;
	}
	rv = BCryptFinishHash(hSm3, hashValue,hashLen,0);
	BCryptDestroyHash(hSm3);
	free(hashObj);
	BCryptCloseAlgorithmProvider(hAlgorithm, 0);
	if (rv != STATUS_SUCCESS)
	{
		printf("BCryptFinishHash fail,return 0X%X\n", rv);
		free(hashValue);
		return -1;
	}

	for (i = 0; i < hashLen; i++)
	{
		printf("%02X", hashValue[i]);
	}
	printf("\n");
	free(hashValue);
	return 0;
}
