#include "Keypair.hpp"
#include "PKIException.hpp"
#include "PublicKey.hpp"
#include "Certificate.hpp"
#include "Device.hpp"

namespace Netca
{
	CKeypair::CKeypair()
	{
		init(0);
	}

	CKeypair::CKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair)
	{
		init(hKeypair);
	}

	CKeypair::~CKeypair()
	{
		NetcaPKICryptoFreeKeypair(m_hKeypair);
	}

	CKeypair::CKeypair(const CKeypair& keypair)
	{
		init(keypair.m_hKeypair);
	}

	CKeypair& CKeypair::operator =(const CKeypair& keypair)
	{
		if(this!=&keypair)
		{
			NetcaPKICryptoFreeKeypair(m_hKeypair);
			m_hKeypair=0;
			init(keypair.m_hKeypair);
		}

		return *this;
	}

	void CKeypair::init(NETCA_PKI_KEYPAIR_HANDLE hKeypair)
	{
		if(hKeypair==0)
		{
			m_hKeypair=0;
			return;
		}
		NETCA_PKI_KEYPAIR_HANDLE hNewKeypair=NetcaPKICryptoDupKeypair(hKeypair);
		if(hNewKeypair==0)
		{
			throw CPKIException("new keypair fail");
		}
		m_hKeypair=hNewKeypair;
	}

	int CKeypair::type() const
	{
		return NetcaPKICryptoGetKeypairType(m_hKeypair);
	}

	std::string CKeypair::label()const
	{
		int rv;
		char *label;
		rv=NetcaPKICryptoGetKeypairLabel(m_hKeypair,&label);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return std::string();
		}
		try
		{
			std::string str(label);
			NetcaPKICryptoFreeMemory(label);
			label=0;
			return str;
		}
		catch(std::exception&)
		{
			if(label)
			{
				NetcaPKICryptoFreeMemory(label);
			}
			throw;
		}
		
	}

	int CKeypair::algorithm() const
	{
		return NetcaPKICryptoGetKeypairAlgorithm(m_hKeypair);
	}

	int CKeypair::bits() const
	{
		return NetcaPKICryptoGetKeypairBits(m_hKeypair);
	}

	CKeypair CKeypair::FindKeyPair(int deviceType, const char *deviceSn, int flag,const char * pwd,int keypairType, const char * label)
	{
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;

		int rv=NetcaPKICryptoFindKeypairEx(deviceType,deviceSn,flag,pwd,keypairType,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}
		
		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
	}

	CKeypair CKeypair::FindKeyPair(int deviceType, const std::string &deviceSn, int flag,const char * pwd,int keypairType, const std::string &label)
	{
		return FindKeyPair(deviceType,deviceSn.c_str(),flag,pwd,keypairType,label.c_str());
	}

	int CKeypair::eccCurve() const
	{
		int algo=NetcaPKICryptoGetKeypairAlgorithm(m_hKeypair);
		if(algo!=NETCA_PKI_ALGORITHM_ECC
			&& algo!=NETCA_PKI_ALGORITHM_ECC_ONLY_ECDH
			&& algo!=NETCA_PKI_ALGORITHM_ECC_ONLY_ECMQV)
		{
			throw CPKIException("not ecc keypair");
		}

		return NetcaPKICryptoGetKeypairECCCurve(m_hKeypair);
	}

	CPublicKey CKeypair::getPublicKey() const
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=NetcaPKICryptoGetPublicKeyFromKeypair(m_hKeypair);
		try
		{
			CPublicKey pubkey(hPublicKey);
			NetcaPKICryptoFreePublicKey(hPublicKey);
			hPublicKey=0;
			return pubkey;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreePublicKey(hPublicKey);
			throw;
		}
	}

	void CKeypair::decrypt(int algo,const unsigned char *cipher,int cipherLen,CBlob& clear)
	{
		int rv;
		unsigned char *out;
		int outLen;

		if(algo==NETCA_PKI_ALGORITHM_SM2_ENC)
		{
			unsigned char *sm2Cipher;
			int sm2CipherLen;

			rv=NetcaPKICryptoSM2CipherFromDER(NETCA_PKI_ECC_CURVE_SM2,cipher,cipherLen,&sm2Cipher,&sm2CipherLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"NetcaPKICryptoSM2CipherFromDER fail");
			}
			rv=NetcaPKICryptoPrivateKeyDecrypt(m_hKeypair,algo,0,sm2Cipher,sm2CipherLen,&out,&outLen);
			NetcaPKICryptoFreeMemory(sm2Cipher);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"NetcaPKICryptoPrivateKeyDecrypt fail");
			}
		}
		else
		{
			rv=NetcaPKICryptoPrivateKeyDecrypt(m_hKeypair,algo,0,cipher,cipherLen,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"NetcaPKICryptoPrivateKeyDecrypt fail");
			}
		}
		clear.attach(out,outLen);
	
	}


	void CKeypair::signHash(int algo,const unsigned char *hash,int hashLen,CBlob& signature)
	{
		unsigned char *sign;
		int signLen;
		int rv;
		rv=NetcaPKICryptoSignHash(m_hKeypair,algo,0,hash,hashLen,&sign,&signLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"NetcaPKICryptoSignHash fail");
		}
		signature.attach(sign,signLen);
		
	}

	void CKeypair::signHash(int algo,const CBlob &hash,CBlob& signature)
	{
		unsigned char *sign;
		int signLen;
		int rv;
		rv=NetcaPKICryptoSignHash(m_hKeypair,algo,0,hash.data(),hash.length(),&sign,&signLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"NetcaPKICryptoSignHash fail");
		}
		signature.attach(sign,signLen);
		
	}

	std::vector<CCertificate> CKeypair::certs()const
	{
		std::vector<CCertificate> v;
		NETCA_PKI_CERTIFICATE_HANDLE hCert;
		int rv;
		int count=NetcaPKICryptoGetCertificateCount(m_hKeypair);
		for(int i=0;i<count;i++)
		{
			rv=NetcaPKICryptoGetCertificate(m_hKeypair,i,&hCert);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				CCertificate cert;
				try
				{
					cert.attach(hCert);
				}
				catch(std::exception&)
				{
					NetcaPKICertFreeCert(hCert);
					throw;
				}
				v.push_back(cert);
			}
		}
		return v;
	}

	bool CKeypair::isTemporaryKeypair()const
	{
		return NetcaPKICryptoIsTemporaryKeypair(m_hKeypair)!=0;
	}

	bool CKeypair::exportKeypair(CBlob& blob)const
	{
		int rv;
		unsigned char *data=0;
		int dataLen;
		rv=NetcaPKICryptoExportKeypair(m_hKeypair,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return false;
		}
		
		blob.attach(data,dataLen);
		return true;
	}

	void CKeypair::deleteKeypair()
	{
		int rv;
		rv=NetcaPKICryptoDeleteKeypair(m_hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"delete keypair fail");
		}
	}

	CDevice CKeypair::device() const
	{
		NETCA_PKI_DEVICE_HANDLE deviceHandle=NetcaPKICryptoGetDeviceHandleFromKeypair(m_hKeypair);
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

	int CKeypair::certCount()const
	{
		return NetcaPKICryptoGetCertificateCount(m_hKeypair);
	}

	void CKeypair::deleteCert(int index)
	{
		int rv;
		rv=NetcaPKICryptoDeleteCertificate(m_hKeypair,index);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"delete cert fail");
		}
	}

	void CKeypair::updateCert(const CCertificate& cert)
	{
		int rv;
		rv=NetcaPKICryptoUpdateCertificate(m_hKeypair,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"update cert fail");
		}
	}

	void CKeypair::addCert(const CCertificate& cert)
	{
		int rv;
		rv=NetcaPKICryptoAddCertificate(m_hKeypair,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add cert fail");
		}
	}

#ifdef _WIN32
	bool CKeypair::getMSProvInfo(PCRYPT_KEY_PROV_INFO pinfo)
	{
		int rv;
		rv=NetcaPKIGetKeypairMSProvInfo(m_hKeypair,pinfo);
		return rv==NETCA_PKI_SUCCESS;
	}
#endif
};
