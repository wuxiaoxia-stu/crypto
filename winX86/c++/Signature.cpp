#include "Signature.hpp"
#include "Keypair.hpp"
#include "PKIException.hpp"
#include "PublicKey.hpp"


namespace Netca
{
	CSignature::CSignature(const CPublicKey& pubkey,int algo)
	{
		m_forSign=false;
		m_hVerify=NetcaPKICryptoNewVerify(pubkey.handle(),algo,0);
		if(m_hVerify==0)
		{
			throw CPKIException("create signature object for verify fail");
		}
	}
	
	CSignature::CSignature(const CKeypair& keypair,int algo)
	{
		m_forSign=true;
		m_hSign=NetcaPKICryptoNewSign(keypair.handle(),algo,0);
		if(m_hSign==0)
		{
			throw CPKIException("create signature object for sign fail");
		}
	}

	CSignature::~CSignature()
	{
		if(m_forSign)
		{
			NetcaPKICryptoFreeSign(m_hSign);
		}
		else
		{
			NetcaPKICryptoFreeVerify(m_hVerify);
		}

	}

	void CSignature::update(const unsigned char *data,int dataLen)
	{
		int rv;

		if(m_forSign)
		{
			rv=NetcaPKICryptoSignUpdate(m_hSign,data,dataLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"sign update fail");
			}
		}
		else
		{
			rv=NetcaPKICryptoVerifyUpdate(m_hVerify,data,dataLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"verify update fail");
			}
		}
	}


	void CSignature::sign(CBlob& blob)
	{
		if(m_forSign==false)
		{
			throw CPKIException("not for sign");
		}

		int rv;
		unsigned char *data;
		int dataLen;
		
		rv=NetcaPKICryptoSignFinal(m_hSign,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"NetcaPKICryptoSignFinal fail");
		}
		blob.attach(data,dataLen);
		return ;
	}

	bool CSignature::verify(const unsigned char *signature,int signatureLen)
	{
		if(m_forSign)
		{
			throw CPKIException("not for verify");
		}

		int rv;
		rv=NetcaPKICryptoVerifyFinal(m_hVerify,signature,signatureLen);
		return rv==NETCA_PKI_SUCCESS;
	}

	void CSignature::Sign(const CKeypair& keypair,int algo,const unsigned char *data,int dataLen,CBlob& outData)
	{
		CSignature signObj(keypair,algo);
		signObj.update(data,dataLen);
		signObj.sign(outData);
	}

	bool CSignature::Verify(const CPublicKey& pubkey,int algo,const unsigned char *data,int dataLen,const unsigned char *signature,int signatureLen)
	{
		CSignature signObj(pubkey,algo);
		signObj.update(data,dataLen);
		return signObj.verify(signature,signatureLen);
	}
};

