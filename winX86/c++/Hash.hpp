#ifndef NETCA_HASH_INCLUDE_HPP
#define NETCA_HASH_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"

#include "Device.hpp"
#include "Blob.hpp"
#include <string>

namespace Netca
{

	class CHash
	{
	public:
		explicit CHash(int algo);
		CHash(const CDevice& device,int algo);
		~CHash();
		
		enum
		{
			INVALID_HASH_ALGORITHM=-1,
		};

		int algorithm() const { return m_algo; }
		int length()const;
		CHash dup();
		void update(const unsigned char *data,int dataLen);
		void final(CBlob& hash);

		CDevice device();

		static void Hash(int algo,const unsigned char *data,int dataLen,CBlob& hash);

		static int GetHashAlgorithm(const char *name);

		static int GetHashAlgorithm(const std::string &name);
	private:
		CHash(NETCA_PKI_HASH_HANDLE hash,int algo);
		CHash(const CHash&);
		CHash& operator =(const CHash&);

		NETCA_PKI_HASH_HANDLE m_hash;
		int m_algo;
	};

};

#endif

