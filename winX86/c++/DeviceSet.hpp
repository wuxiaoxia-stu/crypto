#ifndef NETCA_DEVICESET_INCLUDE_HPP
#define NETCA_DEVICESET_INCLUDE_HPP

#include <vector>

#include "NETCA_PKI_Crypto.h"
#include "Device.hpp"

namespace Netca
{

	class CDeviceSet
	{
	public:
		CDeviceSet(int type,int flag);
		CDeviceSet(int vid,int pid,int flag);
		CDeviceSet(const std::vector<int> &types,int flag);
		CDeviceSet(const int *types,int count,int flag);
		~CDeviceSet() {}
		
		int size() const { return (int)m_devices.size(); }
		CDevice& operator[](int index) { return m_devices[index]; }
		const CDevice& operator[](int index)const { return m_devices[index]; }

		std::vector<CDevice> devices()const { return m_devices;}
	private:
		CDeviceSet(const CDeviceSet& device);
		CDeviceSet& operator =(const CDeviceSet& device);

		void init(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet);

		std::vector<CDevice> m_devices;
	};

};
#endif

