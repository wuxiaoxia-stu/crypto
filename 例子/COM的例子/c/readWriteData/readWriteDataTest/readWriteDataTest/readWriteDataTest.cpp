// readWriteDataTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#import "NETCAPKICOM.dll" no_smart_pointers raw_interfaces_only raw_native_types
using NetcaPkiLib::DeviceSet;
using NetcaPkiLib::IDeviceSet;

using NetcaPkiLib::Device;
using NetcaPkiLib::IDevice;

STDMETHODIMP encodeDataSaftArray(const char* pAData, SAFEARRAY** pparray);

int _tmain(int argc, _TCHAR* argv[])
{
	::CoInitialize(NULL);

	//获取设备
	IDeviceSet *deviceSet = NULL;
	HRESULT hr = CoCreateInstance(__uuidof(DeviceSet), NULL, CLSCTX_ALL, __uuidof(IDeviceSet), (void **)&deviceSet);
	if(hr != S_OK){

		MessageBox(NULL,_T("Failed to create DeviceSet Instance"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}
	//获取所有的设备的设备集
	//hr = deviceSet->GetAllDevice(NetcaPkiLib::NETCAPKI_DEVICETYPE_ANY, NetcaPkiLib::NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_HANDLE);
	hr = deviceSet->GetAllDevice(NetcaPkiLib::NETCAPKI_DEVICETYPE_ANY, NetcaPkiLib::NETCAPKI_DEVICEFLAG_SILENT | NetcaPkiLib::NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_HANDLE);
	if(hr != S_OK){
		deviceSet->Release();
		deviceSet = NULL;
		MessageBox(NULL,_T("Failed to get all deviceSet"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}


	LONG lCount = 0;
	hr = deviceSet->get_Count(&lCount);
	if( FAILED(hr))
	{
		MessageBox(NULL,_T("Failed to get device count"),_T("error"),0);
		deviceSet->Release();
		::CoUninitialize();
		return 0;
	}
	if(lCount <= 0 || lCount >=2 ){
		deviceSet->Release();
		MessageBox(NULL,_T("测试时只容许插入一个USBKey"),_T("warning"),0);
		::CoUninitialize();
		return 0;
		
	}

	IDevice * device = NULL;
	hr = deviceSet->get_Item(1,&device);
	if(FAILED(hr))
	{
		deviceSet->Release();
		MessageBox(NULL,_T("Failed to get device"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}

	//自己设定密码
	VARIANT_BOOL  bRes;
	BSTR psw = SysAllocString(L"12345678");
	hr = device->VerifyPwd(psw,1,&bRes);
	if( FAILED(hr))
	{
		deviceSet->Release();
		device->Release();
		::CoUninitialize();
		return 0;
	}

	if( !bRes )
	{
		deviceSet->Release();
		device->Release();
		MessageBox(NULL,_T("Error password"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}

	int fileId = 9000;
	device->DeleteData(fileId);
    
	//允许未登录用户具有读权限；普通PIN登录用户、管理员PIN登录用户读、写、删Key的权限。

	BSTR mode = SysAllocString(L"04010707");
	hr = device->CreateData(fileId,mode,30);
	SysFreeString(mode);
	if( FAILED(hr))
	{
		deviceSet->Release();
		device->Release();
		MessageBox(NULL,_T("Failed to create data"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}

	char * pAData = "123456789axcvbnm";
	SAFEARRAY *parrData = NULL;
	hr = encodeDataSaftArray(pAData, &parrData);

	VARIANT varData;
	VariantInit(&varData);
	V_VT(&varData) = VT_ARRAY|VT_UI1;
	V_ARRAY(&varData) = parrData;
	hr = device->WriteData(fileId,varData);
	VariantClear(&varData);

	if( FAILED(hr))
	{
		device->DeleteData(fileId);
		deviceSet->Release();
		device->Release();
		MessageBox(NULL,_T("Failed to write data"),_T("error"),0);
		::CoUninitialize();
		return 0;

	}
	else
		MessageBox(NULL,_T("Writing data, Success"),_T("error"),0);

	//Reading testing
	VARIANT varData2;
	hr = device->ReadData(fileId,&varData2);
	if( FAILED(hr))
	{
		//deviceSet->Release();
		//device->Release();
		MessageBox(NULL,_T("Failed to read data"),_T("error"),0);     
	}
	else
	{
		VariantClear(&varData);
		MessageBox(NULL,_T("Reading data,Success"),_T("error"),0); 
	}

	hr = device->DeleteData(fileId);

	deviceSet->Release();
	device->Release();

	if(FAILED(hr))
	{
		MessageBox(NULL,_T("Failed to write data"),_T("error"),0);
	}
	else
		MessageBox(NULL,_T("Testing, Success"),_T("error"),0);

	::CoUninitialize();

	return 0;
}




//用数据构造安全数组
STDMETHODIMP encodeDataSaftArray(const char* pAData, SAFEARRAY** pparray)
{
	*pparray = NULL;
	int nADataLen = strlen(pAData);//假如pAData为NULL，则长度为0
	*pparray = SafeArrayCreateVector(VT_UI1, 0, nADataLen);
	if(*pparray == NULL){
		return S_FALSE;
	}
	SafeArrayLock(*pparray);
	if(nADataLen > 0){
		memcpy((*pparray)->pvData, pAData, nADataLen);
	}
	SafeArrayUnlock(*pparray);
	return S_OK;
}