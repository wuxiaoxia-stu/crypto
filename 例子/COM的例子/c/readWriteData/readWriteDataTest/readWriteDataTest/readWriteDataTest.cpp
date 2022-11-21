// readWriteDataTest.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//��ȡ�豸
	IDeviceSet *deviceSet = NULL;
	HRESULT hr = CoCreateInstance(__uuidof(DeviceSet), NULL, CLSCTX_ALL, __uuidof(IDeviceSet), (void **)&deviceSet);
	if(hr != S_OK){

		MessageBox(NULL,_T("Failed to create DeviceSet Instance"),_T("error"),0);
		::CoUninitialize();
		return 0;
	}
	//��ȡ���е��豸���豸��
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
		MessageBox(NULL,_T("����ʱֻ�������һ��USBKey"),_T("warning"),0);
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

	//�Լ��趨����
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
    
	//����δ��¼�û����ж�Ȩ�ޣ���ͨPIN��¼�û�������ԱPIN��¼�û�����д��ɾKey��Ȩ�ޡ�

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




//�����ݹ��찲ȫ����
STDMETHODIMP encodeDataSaftArray(const char* pAData, SAFEARRAY** pparray)
{
	*pparray = NULL;
	int nADataLen = strlen(pAData);//����pADataΪNULL���򳤶�Ϊ0
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