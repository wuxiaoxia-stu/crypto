#include "NETCA_PKI_Crypto.h"
#include "NETCA_Log.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int T_SJJ0929(const char *sn, const char *pwd);
int main(int argc, char* argv[])
{
	int rv;
	if(argc!=3)
	{
		printf("Usage : %s SerialNumber UsrPin \n", argv[0]);
		return 1;
	}
	
	rv=NetcaLogSetConfigParam(NETCA_LOG_LEVEL_DEBUG,NETCA_LOG_MODE_FILE,"log.txt");
	if(rv!=1)
	{
		return ;
	}
	
	if(T_SJJ0929(argv[1], argv[2])==1)
	{
		printf("SJJ0929 simple test, OK \n");
	}

	NetcaLogClose();
	return 0;
}

int T_SJJ0929(const char *sn, const char *pwd)
{
	int rv;
	NETCA_PKI_DEVICE_HANDLE hDevice=0;
	
	rv=NetcaPKICryptoFindDevice(102, sn, NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS, &hDevice);
	if(rv!=1)
	{
		printf("NetcaPKICryptoFindDevice, SerialNumber : %s, fail\n", sn);
		return 0;
	}

	rv=NetcaPKICryptoVerifyPwd(hDevice, NETCA_PKI_USER_PWD, pwd, 0);
	NetcaPKICryptoFreeDevice(hDevice);
	if(rv!=1)
	{
		printf("NetcaPKICryptoVerifyPwd, UsrPin : %s, fail\n", pwd);
		hDevice=0;
		return 0;
	}

	return 1;
}
