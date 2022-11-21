#include "Base64.hpp"
#include "PKIException.hpp"
#include <string.h>

namespace Netca
{
	CBase64::CBase64(bool encode,int flag)
	{
		m_hBase64=NetcaPKICryptoNewBase64(encode,flag);
		if(m_hBase64==0)
		{
			throw CPKIException("create base64 fail");
		}
	}

	CBase64::~CBase64()
	{
		NetcaPKICryptoFreeBase64(m_hBase64);
	}

	void CBase64::update(const unsigned char *inData,int inDataLen,CBlob& outData)
	{
		int rv;
		unsigned char *out;
		int outLen;
		rv=NetcaPKICryptoBase64Update(m_hBase64,inData,inDataLen,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"base64 update fail");
		}
		outData.attach(out,outLen);
	}

	void CBase64::final(CBlob& outData)
	{
		int rv;
		unsigned char *out;
		int outLen;
		rv=NetcaPKICryptoBase64Final(m_hBase64,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"base64 final fail");
		}
		outData.attach(out,outLen);
	}

	std::string CBase64::Encode(int flag,const unsigned char *inData,int inDataLen)
	{
		int rv;
		unsigned char *out;
		int outLen;

		rv=NetcaPKICryptoBase64(0,flag,inData,inDataLen,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"base64 encode fail");
		}
		
		
		try
		{
			std::string str((char *)out,outLen);
			NetcaPKICryptoFreeMemory(out);
			out=0;

			return str;
		}
		catch(...)
		{
			if(out)
			{
				NetcaPKICryptoFreeMemory(out);
			}
			throw;
		}
	}

	void CBase64::Decode(int flag,const unsigned char *inData,int inDataLen,CBlob& outData)
	{
		int rv;
		unsigned char *out;
		int outLen;

		rv=NetcaPKICryptoBase64(1,flag,inData,inDataLen,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"base64 decode fail");
		}
		outData.attach(out,outLen);
	}

	void CBase64::Decode(int flag,const std::string &b64String,CBlob& outData)
	{
		Decode(flag,(const unsigned char *)b64String.c_str(),(int)b64String.length(),outData);
	}

	void CBase64::Decode(int flag,const char *b64String,CBlob& outData)
	{
		if(b64String==0)
		{
			throw CPKIException("b64String is null");
		}
		Decode(flag,(const unsigned char *)b64String,(int)strlen(b64String),outData);
	}
}
