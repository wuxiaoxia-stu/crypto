#include "Store.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "NETCA_PKI_Internal.h"

namespace Netca
{

	CStore::CStore()
	{
		m_store=NetcaPKICertOpenStore(NETCA_PKI_CERT_STORE_TYPE_MEMORY,0);
		if(m_store==0)
		{
			throw CPKIException("open memory store fail");
		}
	}
	CStore::CStore(int type,const char *name)
	{
		m_store=NetcaPKICertOpenStore(type,name);
		if(m_store==0)
		{
			throw CPKIException("open store fail");
		}
	}

	CStore::CStore(int type,const std::string& name)
	{
		m_store=NetcaPKICertOpenStore(type,name.c_str());
		if(m_store==0)
		{
			throw CPKIException("open store fail");
		}
	}

	CStore::~CStore()
	{
		close();
	}

	void CStore::close()
	{
		NetcaPKICertCloseStore(m_store);
		m_store=0;
	}

	std::vector<CCertificate> CStore::getCerts()const
	{
		if(m_store==0)
		{
			throw CPKIException("store is close");
		}
		std::vector<CCertificate> v;
		int i;
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert;
		int count=NetcaPKICertGetStoreCertCount(m_store);
		for(i=0;i<count;i++)
		{
			cert=NetcaPKICertGetStoreCert(m_store,i);
			if(cert)
			{
				certObj.attach(cert);
				v.push_back(cert);
			}
		}
		return v;
	}

	void CStore::addCert(const CCertificate& cert)
	{
		if(m_store==0)
		{
			throw CPKIException("store is close");
		}

		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;

		rv=NetcaPKICertAddStoreCert(m_store,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add cert in store fail");
		}
	}

	void CStore::deleteCert(const CCertificate& cert)
	{
		if(m_store==0)
		{
			throw CPKIException("store is close");
		}

		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;

		rv=NetcaPKICertDeleteStoreCert(m_store,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"delete cert from store fail");
		}
	}

	CStore::CStore(StoreEncodeType type,const CBlob& encode,const char *pwd)
	{
		if(type!=STORE_ENCODE_TYPE_PFX && type!=STORE_ENCODE_TYPE_P7C)
		{
			throw CPKIException("bad store encode type");
		}

		if(type==STORE_ENCODE_TYPE_PFX)
		{
			m_store=NetcaPKICertLoadPFX(encode.data(),encode.length(),pwd);
		}
		else
		{
			m_store=NetcaPKICertLoadP7c(encode.data(),encode.length());
		}
		if(m_store==0)
		{
			throw CPKIException("bad store encode,or bad pwd");
		}
	}

	CStore::CStore(StoreEncodeType type,const CBlob& encode)
	{
		if(type!=STORE_ENCODE_TYPE_PFX && type!=STORE_ENCODE_TYPE_P7C)
		{
			throw CPKIException("bad store encode type");
		}

		if(type==STORE_ENCODE_TYPE_PFX)
		{
			m_store=NetcaPKICertLoadPFX(encode.data(),encode.length(),0);
		}
		else
		{
			m_store=NetcaPKICertLoadP7c(encode.data(),encode.length());
		}
		if(m_store==0)
		{
			throw CPKIException("bad store encode");
		}
	}

	void CStore::exportP7c(CBlob& encode)const
	{
		if(m_store==0)
		{
			throw CPKIException("store is close");
		}
		int rv;
		unsigned char *data;
		int dataLen;

		rv=NetcaPKICertExportP7c(m_store,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"export p7c fail");
		}
		encode.attach(data,dataLen);
	}

	CStore::CStore(NETCA_PKI_CERT_STORE store)
	{
		m_store=store;
	}

	CStore CStore::LoadPfx(const unsigned char *data,int len,const char *pwd)
	{
		NETCA_PKI_CERT_STORE hStore;
		hStore=NetcaPKICertLoadPFX(data,len,pwd);
		if(hStore==0)
		{
			throw CPKIException("bad pfx or bad pwd");
		}
		try
		{
			return CStore(hStore);
		}
		catch(std::exception&)
		{
			NetcaPKICertCloseStore(hStore);
			throw;
		}
		
	}

	CStore CStore::LoadP7c(const unsigned char *data,int len)
	{
		NETCA_PKI_CERT_STORE hStore;
		hStore=NetcaPKICertLoadP7c(data,len);
		if(hStore==0)
		{
			throw CPKIException("bad signeddata");
		}
		try
		{
			return CStore(hStore);
		}
		catch(std::exception&)
		{
			NetcaPKICertCloseStore(hStore);
			throw;
		}
		
	}

	void SetRootCert(int flag,const CStore& store)
	{
		int rv;
		rv=NetcaPKICertSetTrustAnchor(flag,store.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set root cert fail");
		}
	}

	void SetCACert(int flag,const CStore& store)
	{
		int rv;
		rv=NetcaPKICertSetCACert(flag,store.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set ca cert fail");
		}
	}

	CStore CStore::GetRootCerts()
	{
		NETCA_PKI_CERT_STORE hStore;
		hStore=NetcaPKICertGetTrustAnchor();
		if(hStore==0)
		{
			throw CPKIException("get root certs fail");
		}
		try
		{
			return CStore(hStore);
		}
		catch(std::exception&)
		{
			NetcaPKICertCloseStore(hStore);
			throw;
		}
	}

	CStore CStore::GetCACerts()
	{
		NETCA_PKI_CERT_STORE hStore;
		hStore=NetcaPKICertGetCACert();
		if(hStore==0)
		{
			throw CPKIException("get ca certs fail");
		}
		try
		{
			return CStore(hStore);
		}
		catch(std::exception&)
		{
			NetcaPKICertCloseStore(hStore);
			throw;
		}
	}
}

