#ifndef NETCA_MAC_INCLUDE_HPP
#define NETCA_MAC_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"

#include "Device.hpp"
#include "Blob.hpp"

namespace Netca
{

	class CMac
	{
	public:
		CMac(int algo,const unsigned char *key,int keyLen);
		CMac(const CDevice& device,int algo,const unsigned char *key,int keyLen);
		~CMac();
		

		int algorithm() const { return m_algo; }
		int length()const;
		void update(const unsigned char *data,int dataLen);
		void final(CBlob& mac);

		CDevice device();

		static void Mac(int algo,const unsigned char *key,int keyLen,const unsigned char *data,int dataLen,CBlob& mac);
		
		static CMac NewZucMac(int count,int bearer,bool direction,int unusedBits,const unsigned char *key,int keyLen);
		static CMac NewZucMac(const CDevice& device,int count,int bearer,bool direction,int unusedBits,const unsigned char *key,int keyLen);

	private:
		CMac(const CMac&);
		CMac& operator =(const CMac&);
		CMac(NETCA_PKI_MAC_HANDLE mac,int algo);

		NETCA_PKI_MAC_HANDLE m_mac;
		int m_algo;
	};

};

#endif

