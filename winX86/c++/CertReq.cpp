#include "CertReq.hpp"

#include "PKIException.hpp"
#include "Keypair.hpp"
#include "PublicKey.hpp"
namespace
{
	/*
	std::vector<std::string> ToStringArray(const char *str)
	{
		std::vector<std::string> v;
		const char *p=str;
		while(*p)
		{
			v.push_back(p);
			p+=strlen(p)+1;
		}
		return v;
	}
	*/

	int StringArrayToStringLength(const std::vector<std::string>&v)
	{
		int sum=0;
		for(size_t i=0;i<v.size();i++)
		{
			sum+=(int)v[i].length()+1;
		}
		sum++;
		if(v.size()==0)
		{
			sum++;
		}
		return sum;
	}

	char *StringArrayToString(const std::vector<std::string>&v)
	{
		int len=StringArrayToStringLength(v);
		char *str;
		str=(char *)NetcaPKICryptoAllocMemory(len);
		if(str==0)
		{
			throw Netca::CPKIException("alloc fail");
		}
		if(v.size()==0)
		{
			str[0]=str[1]='\0';
			return str;
		}
		int pos=0;
		for(size_t i=0;i<v.size();i++)
		{
			memcpy(&str[pos],v[i].c_str(),v[i].length());
			pos+=(int)v[i].length();
		}
		str[pos]='\0';
		return str;
	}


}
namespace Netca
{
	CCertReq::CCertReq()
	{
		m_hReq=NetcaPKICertReqNew();
		if(m_hReq==0)
		{
			throw CPKIException("new certreq handle fail");
		}
	}
	CCertReq::CCertReq(const unsigned char*data,int dataLen)
	{
		m_hReq=NetcaPKICertReqDecode(data,dataLen);
		if(m_hReq==0)
		{
			throw CPKIException("bad certreq encode");
		}
	}

	CCertReq::~CCertReq()
	{
		NetcaPKICertReqFree(m_hReq);
	}

	void CCertReq::setIntegerAttribute(int atrrId,int value)
	{
		int rv;

		rv=NetcaPKICertReqSetIntegerAttribute(m_hReq,atrrId,value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq set integer attribute fail");
		}
	}

	void CCertReq::setStringAttribute(int atrrId,const char *value)
	{
		int rv;

		rv=NetcaPKICertReqSetStringAttribute(m_hReq,atrrId,value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq set string attribute fail");
		}
	}

	void CCertReq::setStringAttribute(int atrrId,const std::string& value)
	{
		setStringAttribute(atrrId,value.c_str());
	}

	void CCertReq::sign(const CKeypair& keypair,int signAlgo,CBlob& certReq)
	{
		if(keypair.isNull())
		{
			throw CPKIException("keypair is null");
		}
		int rv;
		unsigned char *data;
		int dataLen;

		rv=NetcaPKICertReqSign(m_hReq,keypair.handle(),signAlgo,0,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"sign certreq fail");
		}
		certReq.attach(data,dataLen);
	}

	int CCertReq::getIntegerAttribute(int atrrId)const
	{
		int value;
		int rv;
		rv=NetcaPKICertReqGetIntegerAttribute(m_hReq,atrrId,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get certreq integer attribute fail");
		}
		return value;
	}

	std::string CCertReq::getStringAttribute(int atrrId)const
	{
		char *value;
		int rv;
		std::string str;
		rv=NetcaPKICertReqGetStringAttribute(m_hReq,atrrId,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get certreq string attribute fail");
		}

		try
		{
			str=value;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		NetcaPKICryptoFreeMemory(value);
		return str;

	}
	/*
	std::vector<std::string> CCertReq::getStringArrayAttribute(int atrrId)const
	{
		char *value;
		int rv;
		rv=NetcaPKICertReqGetStringAttribute(m_hReq,atrrId,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get certreq string array attribute fail");
		}

		try
		{
			std::vector<std::string> v=ToStringArray(value);
			NetcaPKICryptoFreeMemory(value);
			value=0;
			return v;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
	}
	*/

	bool CCertReq::verify()
	{
		int rv;
		rv=NetcaPKICertReqVerify(m_hReq);
		return rv==NETCA_PKI_SUCCESS;
	}

	void CCertReq::setSubject(const unsigned char *data,int dataLen)
	{
		int rv;
		rv=NetcaPKICertReqSetSubject(m_hReq,data,dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq set subject encode fail");
		}
	}

	void CCertReq::getSubject(CBlob& subject)const
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv=NetcaPKICertReqGetSubject(m_hReq,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get certreq subject encode fail");
		}
		subject.attach(data,dataLen);
	}

	CPublicKey CCertReq::getPublicKey()const
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=NetcaPKICertReqGetPublicKey(m_hReq);
		if(hPublicKey==0)
		{
			return CPublicKey();
		}

		try
		{
			CPublicKey pubkeyObj(hPublicKey);
			NetcaPKICryptoFreePublicKey(hPublicKey);
			hPublicKey=0;
			return pubkeyObj;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreePublicKey(hPublicKey);
			throw;
		}
	}
	void CCertReq::encode(CBlob& subject)const
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv=NetcaPKICertReqGetEncode(m_hReq,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq encode fail");
		}
		subject.attach(data,dataLen);
	}

	void CCertReq::addAttribute(const char *attrType,const unsigned char *attrValue,int attrValueLen)
	{
		int rv;
		rv=NetcaPKICertReqAddAttribute(m_hReq,attrType,attrValue,attrValueLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq add attribute fail");
		}

	}

	void CCertReq::addAttribute(const std::string& attrType,const unsigned char *attrValue,int attrValueLen)
	{
		addAttribute(attrType.c_str(),attrValue,attrValueLen);
	}

	void CCertReq::getAttribute(int index,std::string& attrType,CBlob& attrValue)const
	{
		int rv;
		char *type;
		unsigned char *value;
		int valueLen;
		
		rv=NetcaPKICertReqGetAttribute(m_hReq,index,&type,&value,&valueLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get certreq attribute fail");
		}
		attrValue.attach(value,valueLen);
		try
		{
			attrType=type;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(type);
			throw;
		}
		NetcaPKICryptoFreeMemory(type);
	}

	std::string CCertReq::getSubject(bool reverse)const
	{
		return getStringAttribute(reverse?NETCA_PKI_CERTREQ_SUBJECT_REVERSE:NETCA_PKI_CERTREQ_SUBJECT);
	}

	void CCertReq::setSubject(const char *value,bool reverse)
	{
		setStringAttribute(reverse?NETCA_PKI_CERTREQ_SUBJECT_REVERSE:NETCA_PKI_CERTREQ_SUBJECT,value);
	}

	void CCertReq::setSubject(const std::string& value,bool reverse)
	{
		setStringAttribute(reverse?NETCA_PKI_CERTREQ_SUBJECT_REVERSE:NETCA_PKI_CERTREQ_SUBJECT,value);
	}

	void CCertReq::setStringArrayAttribute(int atrrId,const std::vector<std::string>& value)
	{
		char *str=StringArrayToString(value);
		int rv;

		rv=NetcaPKICertReqSetStringAttribute(m_hReq,atrrId,str);
		NetcaPKICryptoFreeMemory(str);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certreq set string array attribute fail");
		}
	}
}
