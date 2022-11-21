#include "Mac.hpp"
#include "PKIException.hpp"

namespace Netca
{
	
	CMac::CMac(int algo,const unsigned char *key,int keyLen):m_algo(algo)
	{
		m_mac=NetcaPKICryptoGetMacHandle(algo,key,keyLen,0);
		if(m_mac==0)
		{
			throw CPKIException("create mac handle fail");
		}
	}

	CMac::CMac(const CDevice& device,int algo,const unsigned char *key,int keyLen):m_algo(algo)
	{
		m_mac=NetcaPKICryptoNewMac(device.handle(),algo,key,keyLen,0);
		if(m_mac==0)
		{
			throw CPKIException("create mac handle fail");
		}
	}

	CMac::~CMac()
	{
		NetcaPKICryptoFreeMac(m_mac);
	}

	int CMac::length()const
	{
		return NetcaPKICryptoGetMacLength(m_mac);
	}

	void CMac::update(const unsigned char *data,int dataLen)
	{
		int rv;

		rv=NetcaPKICryptoMacUpdate(m_mac,data,dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"mac update fail");
		}
	}

	void CMac::final(CBlob& mac)
	{
		int rv;
		unsigned char *macValue;
		int macLen;
		rv=NetcaPKICryptoMacFinal(m_mac,&macValue,&macLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"mac finish fail");
		}

		mac.attach(macValue,macLen);
	}

	CDevice CMac::device()
	{
		NETCA_PKI_DEVICE_HANDLE deviceHandle=NetcaPKICryptoGetDeviceHandleFromMac(m_mac);
		try
		{
			CDevice device(deviceHandle);
			NetcaPKICryptoFreeDevice(deviceHandle);
			deviceHandle=0;
			return device;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevice(deviceHandle);
			throw;
		}
	}

	void CMac::Mac(int algo,const unsigned char *key,int keyLen,const unsigned char *data,int dataLen,CBlob& mac)
	{
		CMac macObj(algo,key,keyLen);
		macObj.update(data,dataLen);
		macObj.final(mac);
	}

	CMac::CMac(NETCA_PKI_MAC_HANDLE mac,int algo)
	{
		m_mac=mac;
		m_algo=algo;
	}

	CMac CMac::NewZucMac(int count,int bearer,bool direction,int unusedBits,const unsigned char *key,int keyLen)
	{
		struct NETCA_PKI_ZUCParam_st param;
		param.m_count=count;
		param.m_bearer=bearer;
		param.m_direction=direction?1:0;
		param.m_unusedBits=unusedBits;

		NETCA_PKI_MAC_HANDLE mac=NetcaPKICryptoGetMacHandle(NETCA_PKI_ALGORITHM_ZUC_MAC,key,keyLen,&param);
		if(mac==0)
		{
			throw CPKIException("create zuc mac handle fail");
		}
		try
		{
			return CMac(mac,NETCA_PKI_ALGORITHM_ZUC_MAC);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMac(mac);
			throw;
		}
	}

	CMac CMac::NewZucMac(const CDevice& device,int count,int bearer,bool direction,int unusedBits,const unsigned char *key,int keyLen)
	{
		struct NETCA_PKI_ZUCParam_st param;
		param.m_count=count;
		param.m_bearer=bearer;
		param.m_direction=direction?1:0;
		param.m_unusedBits=unusedBits;

		NETCA_PKI_MAC_HANDLE mac=NetcaPKICryptoNewMac(device.handle(),NETCA_PKI_ALGORITHM_ZUC_MAC,key,keyLen,&param);
		if(mac==0)
		{
			throw CPKIException("create zuc mac handle fail");
		}
		try
		{
			return CMac(mac,NETCA_PKI_ALGORITHM_ZUC_MAC);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMac(mac);
			throw;
		}
	}
};
