#include "Hash.hpp"
#include "PKIException.hpp"
#include <string.h>

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

namespace Netca
{
	
	CHash::CHash(int algo):m_algo(algo)
	{
		m_hash=NetcaPKICryptoGetHashHandle(algo);
		if(m_hash==0)
		{
			throw CPKIException("create hash handle fail");
		}
	}

	CHash::CHash(const CDevice& device,int algo):m_algo(algo)
	{
		if(device.isNull())
		{
			throw CPKIException("null device handle");
		}
		m_hash=NetcaPKICryptoNewHash(device.handle(),algo);
		if(m_hash==0)
		{
			throw CPKIException("create hash handle fail");
		}
	}

	CHash::~CHash()
	{
		NetcaPKICryptoFreeHash(m_hash);
	}

	CHash::CHash(NETCA_PKI_HASH_HANDLE hash,int algo):m_hash(hash),m_algo(algo)
	{
	
	}

	CHash CHash::dup()
	{
		NETCA_PKI_HASH_HANDLE hHash;
		int rv=NetcaPKICryptoDuplicateHash(m_hash,&hHash);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"duplicate hash handle fail");
		}
		try
		{
			return CHash(hHash,m_algo);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeHash(hHash);
			throw;
		}
	}

	void CHash::update(const unsigned char *data,int dataLen)
	{
		int rv;

		rv=NetcaPKICryptoHashUpdate(m_hash,data,dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"hash update fail");
		}
	}

	int CHash::length()const
	{
		return NetcaPKICryptoGetHashLength(m_hash);
	}

	void CHash::final(CBlob& hash)
	{
		int rv;
		unsigned char *hashValue;
		int hashLen;
		rv=NetcaPKICryptoHashFinal(m_hash,&hashValue,&hashLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"hash finish fail");
		}

		hash.attach(hashValue,hashLen);
		
	}

	CDevice CHash::device()
	{
		NETCA_PKI_DEVICE_HANDLE deviceHandle=NetcaPKICryptoGetDeviceHandleFromHash(m_hash);
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

	void CHash::Hash(int algo,const unsigned char *data,int dataLen,CBlob& hash)
	{
		CHash hashObj(algo);
		hashObj.update(data,dataLen);
		hashObj.final(hash);
	}

	int CHash::GetHashAlgorithm(const char *name)
	{
		if(STRINGCASECMP(name,"md5")==0)
		{
			return NETCA_PKI_ALGORITHM_MD5;
		}
		else if(STRINGCASECMP(name,"sha1")==0
			|| STRINGCASECMP(name,"sha-1")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA1;
		}
		else if(STRINGCASECMP(name,"sha256")==0
			|| STRINGCASECMP(name,"sha-256")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA256;
		}
		else if(STRINGCASECMP(name,"sha512")==0
			|| STRINGCASECMP(name,"sha-512")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA512;
		}
		else if(STRINGCASECMP(name,"sm3")==0)
		{
			return NETCA_PKI_ALGORITHM_SM3;
		}
		else if(STRINGCASECMP(name,"sha224")==0
			|| STRINGCASECMP(name,"sha-224")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA224;
		}
		else if(STRINGCASECMP(name,"sha384")==0
			|| STRINGCASECMP(name,"sha-384")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA384;
		}
		else if(STRINGCASECMP(name,"sha-512/224")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA512_224;
		}
		else if(STRINGCASECMP(name,"sha-512/256")==0)
		{
			return NETCA_PKI_ALGORITHM_SHA512_256;
		}
		else
		{
			return INVALID_HASH_ALGORITHM;
		}
	}

	int CHash::GetHashAlgorithm(const std::string &name)
	{
		return GetHashAlgorithm(name.c_str());
	}
};
