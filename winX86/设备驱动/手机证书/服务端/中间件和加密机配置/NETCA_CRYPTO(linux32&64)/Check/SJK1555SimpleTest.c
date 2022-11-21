#include "NETCA_PKI_Crypto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int rv;
	NETCA_PKI_DEVICE_HANDLE hDevice=0;

	printf("SJK1555 simple test, Begin\n");
	rv=NetcaPKICryptoFindDevice(109, "SJK1555", NETCA_PKI_DEVICE_FLAG_SILENT, &hDevice);
	if(rv!=1)
	{
		printf("NetcaPKICryptoFindDevice, Fail\n");
		printf("SJK1555 simple test, Fail\n");
		return 0;
	}
	NetcaPKICryptoFreeDevice(hDevice);
	hDevice=0;
	printf("SJK1555 simple test, Success\n");
	return 0;
}