#include <stdio.h>
#include "Device.hpp"
#include "PKIException.hpp"

using Netca::CDevice;
using Netca::CPKIException;

static void usage(const char *procName);

int main(int argc,char **argv)
{
	int rv;
	int deviceType;
	const char *deviceSn;
	const char *devicePwd;

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
	try
	{
		CDevice device=CDevice::FindDevice(deviceType,deviceSn,NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN);
		if(device.isNull())
		{
			printf("NetcaPKICryptoFindDevice fail\n");
			return -1;
		}
		printf("find device success\n");

		if(devicePwd)
		{
			int retryNumber;
			rv=device.verifyPwd(NETCA_PKI_USER_PWD,devicePwd,retryNumber);
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
			
		return 0;
	}
	catch(CPKIException& e)
	{
		printf("find device fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *procName)
{
	printf("Usage: %s type sn [pwd]",procName);
}
