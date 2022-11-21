#include <stdio.h>
#include <stdlib.h>
#include "NETCA_PKI_Crypto.h"

static void usage(const char *procName);

int main(int argc,char **argv)
{
	int rv;
	int deviceType;
	const char *deviceSn;
	const char *devicePwd;
	NETCA_PKI_DEVICE_HANDLE hDevice;

	if(argc!=3 && argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	deviceType=atoi(argv[1]);
	deviceSn=argv[2];
	if(argc==3)
	{
		devicePwd=0;
	}
	else
	{
		devicePwd=argv[3];
	}

	rv=NetcaPKICryptoFindDevice(deviceType,deviceSn,NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN,&hDevice);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoFindDevice fail,return %d\n",rv);
		return -1;
	}
	printf("find device success\n");

	if(devicePwd)
	{
		int retryNumber;
		rv=NetcaPKICryptoVerifyPwd(hDevice,NETCA_PKI_USER_PWD,devicePwd,&retryNumber);
		NetcaPKICryptoFreeDevice(hDevice);
		if(rv==NETCA_PKI_PWD_ERROR)
		{
			if(retryNumber==0)
			{
				printf("the user pin is locked\n");
			}
			else if(retryNumber==-1)
			{
				printf("incorrect user pin\n");
			}
			else
			{
				printf("incorrect user pin,retry number %d\n",retryNumber);				
			}
			return -1;
		}
		else if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("verify user pin fail,return %d\n",rv);
			return -1;
		}
		else
		{
			printf("verify user pin success\n");
		}
		
	}
	else
	{
		NetcaPKICryptoFreeDevice(hDevice);
	}
	
	return 0;
}

void usage(const char *procName)
{
	printf("Usage: %s type sn [pwd]",procName);
}
