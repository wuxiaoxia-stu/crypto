#include "DeviceSet.hpp"

#include "PKIException.hpp"

namespace Netca
{

	CDeviceSet::CDeviceSet(int type,int flag)
	{
		NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet=NetcaPKICryptoGetAllDevices(type,flag);
		if(hDeviceSet==0)
		{
			throw CPKIException("get device set fail");
		}

		try
		{
			init(hDeviceSet);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevices(hDeviceSet);
			throw;
		}
		NetcaPKICryptoFreeDevices(hDeviceSet);
		
	}

	CDeviceSet::CDeviceSet(int vid,int pid,int flag)
	{
		NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet=NetcaPKICryptoGetUSBDevices(vid,pid,flag);
		if(hDeviceSet==0)
		{
			throw CPKIException("get device set fail");
		}

		try
		{
			init(hDeviceSet);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevices(hDeviceSet);
			throw;
		}
		NetcaPKICryptoFreeDevices(hDeviceSet);
	}

	CDeviceSet::CDeviceSet(const std::vector<int> &types,int flag)
	{
		NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet=NetcaPKICryptoGetAllDevicesEx(&types[0],(int)types.size(),flag);
		if(hDeviceSet==0)
		{
			throw CPKIException("get device set fail");
		}

		try
		{
			init(hDeviceSet);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevices(hDeviceSet);
			throw;
		}
		NetcaPKICryptoFreeDevices(hDeviceSet);
	}

	CDeviceSet::CDeviceSet(const int *types,int count,int flag)
	{
		NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet=NetcaPKICryptoGetAllDevicesEx(types,count,flag);
		if(hDeviceSet==0)
		{
			throw CPKIException("get device set fail");
		}

		try
		{
			init(hDeviceSet);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevices(hDeviceSet);
			throw;
		}
		NetcaPKICryptoFreeDevices(hDeviceSet);
	}

	void CDeviceSet::init(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet)
	{
		m_devices.clear();
		int count=NetcaPKICryptoGetDeviceCount(hDeviceSet);
		NETCA_PKI_DEVICE_HANDLE hDevice=0;
		for(int i=0;i<count;i++)
		{
			hDevice=NetcaPKICryptoGetDevice(hDeviceSet,i);
			if(hDevice)
			{
				try
				{
					m_devices.push_back(CDevice(hDevice));
				}
				catch(std::exception&)
				{
					NetcaPKICryptoFreeDevice(hDevice);
					throw;
				}
				NetcaPKICryptoFreeDevice(hDevice);
			}
		}

	}


};
