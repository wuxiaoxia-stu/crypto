#include "PublicKey.hpp"
#include "PKIException.hpp"

namespace Netca
{
	CPublicKey::CPublicKey()
	{
		init(0);
	}

	CPublicKey::CPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey)
	{
		init(hPublicKey);
	}

	void CPublicKey::init(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey)
	{
		if(hPublicKey==0)
		{
			m_hPublicKey=0;
			return;
		}
		m_hPublicKey=NetcaPKICryptoDupPublicKey(hPublicKey);
		if(m_hPublicKey==0)
		{
			throw CPKIException("new public key fail");
		}
	}

	CPublicKey::~CPublicKey()
	{
		NetcaPKICryptoFreePublicKey(m_hPublicKey);
	}

	CPublicKey::CPublicKey(const CPublicKey& pubkey)
	{
		init(pubkey.m_hPublicKey);
	}

	CPublicKey& CPublicKey::operator =(const CPublicKey& pubkey)
	{
		if(this!=&pubkey)
		{
			NetcaPKICryptoFreePublicKey(m_hPublicKey);
			m_hPublicKey=0;
			init(pubkey.m_hPublicKey);
		}

		return *this;
	}

	int CPublicKey::algorithm() const
	{
		return NetcaPKICryptoGetPublicKeyAlgorithm(m_hPublicKey);
	}

	int CPublicKey::bits() const
	{
		return NetcaPKICryptoGetPublicKeyBits(m_hPublicKey);
	}

	int CPublicKey::eccCurve() const
	{
		int algo=NetcaPKICryptoGetPublicKeyAlgorithm(m_hPublicKey);
		if(algo!=NETCA_PKI_ALGORITHM_ECC
			&& algo!=NETCA_PKI_ALGORITHM_ECC_ONLY_ECDH
			&& algo!=NETCA_PKI_ALGORITHM_ECC_ONLY_ECMQV)
		{
			throw CPKIException("not ecc public key");
		}

		return NetcaPKICryptoGetPublicKeyECCCurve(m_hPublicKey);
	}

	void CPublicKey::getEncoded(CBlob& blob)const
	{
		unsigned char *buf;
		int bufLen;
		int rv;

		rv=NetcaPKICryptoExportPublicKey(m_hPublicKey,&buf,&bufLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException("export public key fail");
		}
		blob.attach(buf,bufLen);
	}
	
	void CPublicKey::getSubjectPublicKeyInfoEncoded(CBlob& blob)const
	{
		unsigned char *buf;
		int bufLen;
		int rv;

		rv=NetcaPKICryptoGetSubjectPublicKeyInfoEncode(m_hPublicKey,&buf,&bufLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"export subject public key info fail");
		}
		blob.attach(buf,bufLen);
	}

	

	void CPublicKey::encrypt(int algo,const unsigned char *clear,int clearLen,CBlob& cipher)
	{
		int rv;
		unsigned char *out;
		int outLen;
		
		rv=NetcaPKICryptoPublicKeyEncrypt(m_hPublicKey,algo,0,clear,clearLen,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"NetcaPKICryptoPublicKeyEncrypt fail");
		}
		if(algo==NETCA_PKI_ALGORITHM_SM2_ENC)
		{
			unsigned char *der;
			int derLen;

			rv=NetcaPKICryptoSM2CipherToDER(NETCA_PKI_ECC_CURVE_SM2,NETCA_PKI_ALGORITHM_SM3,
				out,outLen,&der,&derLen);
			NetcaPKICryptoFreeMemory(out);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"NetcaPKICryptoSM2CipherToDER fail");
			}
			cipher.attach(der,derLen);
		}
		else
		{
			cipher.attach(out,outLen);
		}
		
	}


	bool CPublicKey::verifyHash(int algo,const unsigned char *hash,int hashLen,const unsigned char *signature,int signatureLen)
	{
		int rv;
		rv=NetcaPKICryptoVerifyHash(m_hPublicKey,algo,0,hash,hashLen,signature,signatureLen);
		return rv==NETCA_PKI_SUCCESS;
	}

	bool CPublicKey::verifyHash(int algo,const CBlob &hash,const unsigned char *signature,int signatureLen)
	{
		int rv;
		rv=NetcaPKICryptoVerifyHash(m_hPublicKey,algo,0,hash.data(),hash.length(),signature,signatureLen);
		return rv==NETCA_PKI_SUCCESS;
	}

	bool operator==(const CPublicKey& pubkey1,const CPublicKey& pubkey2)
	{
		if(pubkey1.isNull() && pubkey2.isNull())
		{
			return true;
		}

		return NetcaPKICryptoPublicKeyEqual(pubkey1.handle(),pubkey2.handle())!=0;
	}

	void CPublicKey::computeSM2Z(int hashAlgo,const unsigned char *id,int idLen,CBlob& z)
	{
		struct NETCA_PKI_SM2Sign_PARAM_st param;
		param.m_id=(unsigned char *)id;
		param.m_idbits=idLen*8;
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIComputeSM2Z(m_hPublicKey,hashAlgo,&param,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"compute sm2 z fail");
		}
		z.attach(data,dataLen);
	}

	void CPublicKey::computeSM2Z(CBlob& z)
	{
		computeSM2Z(NETCA_PKI_ALGORITHM_SM3,(const unsigned char *)"1234567812345678",16,z);
	}
};
