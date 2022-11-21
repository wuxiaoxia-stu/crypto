// netcakeyinsert.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_Application.h"

bool IsNetcaKeyInserted()
{
	NETCA_PKI_DEVICE_HANDLE_SET hDevSet = NetcaPKICryptoGetAllDevices(NETCA_PKI_DEVICE_TYPE_ANY,NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN);

	if(hDevSet==NULL)
	{
	   return false;
	}

	int devSetCount = NetcaPKICryptoGetDeviceCount(hDevSet);
	NetcaPKICryptoFreeDevices(hDevSet);

	if(devSetCount<=0)
	{
		return false;
	}
	else
	{
		return true;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	if(IsNetcaKeyInserted())
	{
		printf("NetcaKeyInserted");
	}
	else
	{
		printf("NetcaKeyNoInserted");
	}

	getchar();
	return 0;
}

