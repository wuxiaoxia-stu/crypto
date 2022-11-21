#include "CertVerify.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "PublicKey.hpp"

extern "C" NETCA_PKI_CERT_VERIFY_HANDLE NETCADLLAPI NetcaPKICertVerifyDup(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify);

namespace
{
	void FreePolicySet(char **polictSet,int count)
	{
		if(polictSet)
		{
			for(int i=0;i<count;i++)
			{
				NetcaPKICryptoFreeMemory(polictSet[i]);
			}
			NetcaPKICryptoFreeMemory(polictSet);
		}
	}
}

namespace Netca
{

	CCertVerify::CCertVerify()
	{
		m_hVerify=NetcaPKICertNewVerify();
		if(m_hVerify==0)
		{
			throw CPKIException("new certverify handle fail");
		}
	}

	CCertVerify::CCertVerify(NETCA_PKI_CERT_VERIFY_HANDLE hVerify)
	{
		m_hVerify=NetcaPKICertVerifyDup(hVerify);
		if(m_hVerify==0)
		{
			throw CPKIException("dup certverify handle fail");
		}
	}

	CCertVerify::CCertVerify(const CCertVerify& verify)
	{
		m_hVerify=NetcaPKICertVerifyDup(verify.m_hVerify);
		if(m_hVerify==0)
		{
			throw CPKIException("dup certverify handle fail");
		}
	}

	CCertVerify::~CCertVerify()
	{
		NetcaPKICertFreeVerify(m_hVerify);
	}

	void CCertVerify::setOption(int option)
	{
		int rv;
		rv=NetcaPKICertVerifySetOption(m_hVerify,option);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify set option fail");
		}
	}

	void CCertVerify::setParam(const char *param)
	{
		int rv;
		rv=NetcaPKICertVerifySetParam(m_hVerify,param);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify set param fail");
		}
	}

	void CCertVerify::setParam(const std::string& param)
	{
		setParam(param.c_str());
	}

	void CCertVerify::addRootCert(const CCertificate &cert)
	{
		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv=NetcaPKICertVerifyAddRootCert(m_hVerify,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add root cert fail");
		}
	}

	void CCertVerify::addCACert(const CCertificate &cert)
	{
		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv=NetcaPKICertVerifyAddCACert(m_hVerify,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add ca cert fail");
		}
	}

	void CCertVerify::setVerifyTime(const char *verifyTime)
	{
		int rv;
		rv=NetcaPKICertVerifySetVerifyTime(m_hVerify,verifyTime);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify set verify time fail");
		}
	}

	void CCertVerify::setVerifyTime(const std::string& verifyTime)
	{
		setVerifyTime(verifyTime.c_str());
	}

	void CCertVerify::addIgnoreExtension(const char *ext)
	{
		int rv;
		rv=NetcaPKICertVerifyAddIgnoreExtension(m_hVerify,ext);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add ignore extension fail");
		}
	}

	void CCertVerify::addIgnoreExtension(const std::string& ext)
	{
		addIgnoreExtension(ext.c_str());
	}

	void CCertVerify::addCRL(const unsigned char *crl,int crlLen)
	{
		int rv;
		rv=NetcaPKICertVerifyAddCRL(m_hVerify,crl,crlLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add crl fail");
		}
	}

	void CCertVerify::addOCSP(const unsigned char *ocsp,int ocspLen,const CCertificate &vaCert)
	{
		if(vaCert.isNull())
		{
			throw CPKIException("vacert is null");
		}

		int rv;
		rv=NetcaPKICertVerifyAddOCSP(m_hVerify,vaCert.handle(),ocsp,ocspLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add ocsp fail");
		}
	}

	void CCertVerify::addOCSP(const unsigned char *ocsp,int ocspLen)
	{
		int rv;
		rv=NetcaPKICertVerifyAddOCSP(m_hVerify,0,ocsp,ocspLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"certverify add ocsp fail");
		}
	}

	int CCertVerify::verify(const CCertificate& cert,int &status,CRevokeInfo &info)
	{
		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		NETCA_PKI_REVOKEDCERT_HANDLE revokeInfo;
		rv=NetcaPKICertVerify(m_hVerify,cert.handle(),&status,&revokeInfo);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return rv;
		}

		if(status==NETCA_PKI_CERTIFICATE_STATUS_REVOKED
			|| status==NETCA_PKI_CERTIFICATE_STATUS_CA_REVOKED)
		{
			try
			{
				info=CRevokeInfo(revokeInfo);
				NetcaPKICertFreeRevokedCert(revokeInfo);
				revokeInfo=0;
			}
			catch(std::exception&)
			{
				NetcaPKICertFreeRevokedCert(revokeInfo);
				throw;
			}
		
		}

		return rv;
	}

	std::vector<CCertificate> CCertVerify::getCertPath()
	{
		int rv;
		NETCA_PKI_CERTIFICATE_HANDLE *certPath;
		int count;
		std::vector<CCertificate> v;
		rv=NetcaPKICertVerifyGetCertPath(m_hVerify, &certPath,&count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get cert path fail");
		}

		try
		{
			for(int i=0;i<count;i++)
			{
				v.push_back(certPath[i]);
			}
		}
		catch(std::exception&)
		{
			NetcaPKICertFreeCertPath(certPath,count);
			throw;
		}
		NetcaPKICertFreeCertPath(certPath,count);
		return v;
	}

	CPublicKey CCertVerify::getPublicKey(int purpose)
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=NetcaPKICertVerifyGetPublicKey(m_hVerify,purpose);
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

	std::vector<std::string> CCertVerify::getAuthPolicySet()
	{
		int rv;
		char **policySet;
		int count;
		std::vector<std::string> v;
		int i;
		rv=NetcaPKICertVerifyGetAuthPolicySet(m_hVerify, &policySet,&count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get auth policy set fail");
		}

		try
		{
			for(i=0;i<count;i++)
			{
				v.push_back(policySet[i]);
			}
		}
		catch(std::exception&)
		{
			FreePolicySet(policySet,count);
			throw;
		}
		FreePolicySet(policySet,count);
		return v;
	}

	std::vector<std::string> CCertVerify::getUserPolicySet()
	{
		int rv;
		char **policySet;
		int count;
		std::vector<std::string> v;
		int i;
		rv=NetcaPKICertVerifyGetUserPolicySet(m_hVerify, &policySet,&count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get user policy set fail");
		}

		try
		{
			for(i=0;i<count;i++)
			{
				v.push_back(policySet[i]);
			}
		}
		catch(std::exception&)
		{
			FreePolicySet(policySet,count);
			throw;
		}
		FreePolicySet(policySet,count);
		return v;
	}
}
