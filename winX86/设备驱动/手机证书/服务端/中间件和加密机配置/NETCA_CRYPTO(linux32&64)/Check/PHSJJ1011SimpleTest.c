#include "NETCA_PKI_Crypto.h"
#include "NETCA_Log.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int T_PHSJJ1011(const char *pwd);
int main(int argc, char* argv[])
{
	int rv;
	if(argc!=2)
	{
		printf("Usage : %s UsrPin \n", argv[0]);
		return 0;
	}
	
	rv=NetcaLogSetConfigParam(NETCA_LOG_LEVEL_DEBUG,NETCA_LOG_MODE_FILE,"log.txt");
	if(rv!=1)
	{
		return rv;
	}
	
	if(T_PHSJJ1011(argv[1])==1)
	{
		printf("PHSJJ1011 simple test, OK\n");
	}
	
	NetcaLogClose();
	return 1;
}


int T_PHSJJ1011(const char *pwd)
{
	int rv;
	char sn[]="SJJ1011::1";
	NETCA_PKI_DEVICE_HANDLE hDevice=0;
	
	rv=NetcaPKICryptoFindDevice(103, sn, NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS, &hDevice);
	if(rv==0)
	{
		printf("NetcaPKICryptoFindDevice, SerialNumber : SJJ1011::1, fail\n");
		return 0;
	}

	rv=NetcaPKICryptoVerifyPwd(hDevice, NETCA_PKI_USER_PWD, pwd, 0);
	NetcaPKICryptoFreeDevice(hDevice);
	hDevice=0;
	if(rv!=1)
	{
		printf("NetcaPKICryptoVerifyPwd, fail\n");
		return 0;
	}

	return 1;
}
