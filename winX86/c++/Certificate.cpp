#include "Certificate.hpp"
#include "PKIException.hpp"
#include "PublicKey.hpp"
#include "Keypair.hpp"
#include "RevokeInfo.hpp"

namespace
{
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

	int getStringExtensionType(unsigned char ch)
	{
		switch(ch)
		{
		case 4:
			return NETCA_PKI_EXTENSION_TYPE_OCTETSTRING;
		case 6:
			return NETCA_PKI_EXTENSION_TYPE_OID;
		case 0x0C:
			return NETCA_PKI_EXTENSION_TYPE_UTF8STRING;
		case 0x12:
			return NETCA_PKI_EXTENSION_TYPE_NUMERICSTRING;
		case 0x13:
			return NETCA_PKI_EXTENSION_TYPE_PRINTABLESTRING;
		case 0x14:
			return NETCA_PKI_EXTENSION_TYPE_TELETEXSTRING;
		case 0x15:
			return NETCA_PKI_EXTENSION_TYPE_VIDEOTEXSTRING;
		case 0x16:
			return NETCA_PKI_EXTENSION_TYPE_IA5STRING;
		case 0x19:
			return NETCA_PKI_EXTENSION_TYPE_GRAPHICSTRING;
		case 0x1A:
			return NETCA_PKI_EXTENSION_TYPE_VISIBLESTRING;
		case 0x1B:
			return NETCA_PKI_EXTENSION_TYPE_GENERALSTRING;
		case 0x1C:
			return NETCA_PKI_EXTENSION_TYPE_UNIVERSALSTRING;
		case 0x1E:
			return NETCA_PKI_EXTENSION_TYPE_BMPSTRING;
		}
		return -1;
	}
}

namespace Netca
{
	CCertificate::CCertificate()
	{
		m_cert=0;
	}

	CCertificate::CCertificate(const unsigned char *data,int dataLen)
	{
		NETCA_PKI_CERTIFICATE_HANDLE cert=NetcaPKICertNewCert(data,dataLen);
		if(cert==0)
		{
			throw CPKIException("not certificate");
		}
		m_cert=cert;
		return;
		
	}

	CCertificate::CCertificate(NETCA_PKI_CERTIFICATE_HANDLE cert)
	{
		if(cert==0)
		{
			m_cert=0;
			return;
		}
		m_cert=NetcaPKICertDupCert(cert);
		if(m_cert==0)
		{
			throw CPKIException("dup certificate fail");
		}
	}

	CCertificate::~CCertificate()
	{
		NetcaPKICertFreeCert(m_cert);
	}
	
	void CCertificate::attach(NETCA_PKI_CERTIFICATE_HANDLE cert)
	{
		if(m_cert)
		{
			NetcaPKICertFreeCert(m_cert);
		}
		m_cert=cert;
	}

	CCertificate::CCertificate(const CCertificate& cert)
	{
		if(cert.isNull())
		{
			m_cert=0;
			return;
		}
		m_cert=NetcaPKICertDupCert(cert.m_cert);
		if(m_cert==0)
		{
			throw CPKIException("dup certificate fail");
		}
	}

	CCertificate& CCertificate::operator =(const CCertificate& cert)
	{
		if(this!=&cert)
		{
			NETCA_PKI_CERTIFICATE_HANDLE dupHandle=0;
			if(cert.isNull()==false)
			{
				dupHandle=NetcaPKICertDupCert(cert.m_cert);
				if(dupHandle==0)
				{
					throw CPKIException("dup certificate fail");
				}
			}
			NetcaPKICertFreeCert(m_cert);
			m_cert=dupHandle;
			
		}

		return *this;
	}

	void CCertificate::encode(int flag,CBlob& outData)const
	{
		int rv;
		unsigned char *data;
		int dataLen;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		rv=NetcaPKICertGetCertEncode(m_cert,flag,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"cert encode fail");
		}
		outData.attach(data,dataLen);
	}

	bool operator==(const CCertificate& cert1,const CCertificate& cert2)
	{
		if(cert1.isNull() && cert2.isNull())
		{
			return true;
		}

		return NetcaPKICertEqual(cert1.handle(),cert2.handle())!=0;
	}

	bool CCertificate::match(const char *expr)const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		rv=NetcaPKICertMatch(m_cert,expr);
		if(rv==1)
		{
			return true;
		}
		else if(rv==0)
		{
			return false;
		}
		else if(rv==-1)
		{
			throw CPKIException("bad expr");
		}
		else
		{
			throw CPKIException("match cert fail");
		}
	}

	bool CCertificate::match(const std::string& expr)const
	{
		return match(expr.c_str());
	}

	CCertificate CCertificate::SelectCert(const char *type,const char *expr)
	{
		int rv;
		NETCA_PKI_CERTIFICATE_HANDLE cert;
		CCertificate certObj;
		rv=NetcaPKISelectCert(type,expr,&cert);
		
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return certObj;
		}
		else
		{
			certObj.attach(cert);
			return certObj;
		}
	}

	CCertificate CCertificate::SelectCert(const char *type)
	{
		return SelectCert(type,0);
	}

	CCertificate CCertificate::SelectCert(const std::string& type,const std::string& expr)
	{
		return SelectCert(type.c_str(),expr.c_str());
	}

	CCertificate CCertificate::SelectCert(const std::string& type)
	{
		return SelectCert(type.c_str(),0);
	}

	long CCertificate::getIntegerAttribute(int attrId)const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		long value;
		rv=NetcaPKICertGetCertIntegerAttribute(m_cert,attrId,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get cert integer attribute fail");
		}
		return value;
	}

	std::string CCertificate::getStringAttriubte(int attrId)const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		char* value;
		rv=NetcaPKICertGetCertStringAttribute(m_cert,attrId,&value);
		if(rv==NETCA_PKI_NOTEXISIT)
		{
			NetcaPKISetLastError(NETCA_PKI_NOTEXISIT);
			return std::string();
		}
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get cert string attribute fail");
		}
		try
		{
			std::string str(value);
			NetcaPKICryptoFreeMemory(value);
			value=0;
			NetcaPKISetLastError(NETCA_PKI_SUCCESS);
			return str;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		
	}

	std::vector<std::string> CCertificate::getStringArrayAttriubte(int attrId)const
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		int rv;
		rv=NetcaPKICertIsMultiValueStringAttribute(attrId);
		if(rv==0)
		{
			throw CPKIException(rv,"not string array attribute");
		}
		char* value;
		rv=NetcaPKICertGetCertStringAttribute(m_cert,attrId,&value);
		if(rv==NETCA_PKI_NOTEXISIT)
		{
			NetcaPKISetLastError(NETCA_PKI_NOTEXISIT);
			return std::vector<std::string>();
		}
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException("get cert string array attribute fail");
		}
		try
		{
			std::vector<std::string> v=ToStringArray(value);
			NetcaPKICryptoFreeMemory(value);
			value=0;
			NetcaPKISetLastError(NETCA_PKI_SUCCESS);
			return v;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
	}


	bool CCertificate::IsMultiValueStringAttribute(int attrId)
	{
		return NetcaPKICertIsMultiValueStringAttribute(attrId)!=0;
	}

	void CCertificate::getHashAttribute(int attrId,int hashAlgo,CBlob& hashValue)const
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		int rv;
		unsigned char* value;
		int valueLen;
		rv=NetcaPKICertGetCertHashAttribute(m_cert,attrId,hashAlgo,&value,&valueLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get cert hash attribute fail");
		}
		hashValue.attach(value,valueLen);
	}

	void CCertificate::setIntegerAttribute(int attrId,long value)
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv=NetcaPKICertSetCertIntegerAttribute(m_cert,attrId,value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set cert integer attribute fail");
		}
	}

	void CCertificate::setStringAttribute(int attrId,const char *value)
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv=NetcaPKICertSetCertStringAttribute(m_cert,attrId,value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set cert string attribute fail");
		}
	}

	void CCertificate::setStringAttribute(int attrId,const std::string& value)
	{
		setStringAttribute(attrId,value.c_str());
	}

	bool CCertificate::findExtension(const char *oid,bool& crical,CBlob& value) const
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		int rv;
		int isCrical;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKICertFindExtension(m_cert,oid,&isCrical,&data,&dataLen);
		if(rv==NETCA_PKI_SUCCESS)
		{
			crical=(isCrical!=0);
			value.attach(data,dataLen);
			return true;
		}
		else if(rv==NETCA_PKI_NOTEXISIT)
		{
			return false;
		}
		else
		{
			throw CPKIException(rv,"find cert extension fail");
		}
	}

	bool CCertificate::findExtension(const std::string& oid,bool& crical,CBlob& value)const
	{
		return findExtension(oid.c_str(),crical,value);
	}

	CPublicKey CCertificate::getPublicKey(int purpose)const
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=NetcaPKICertGetCertPublicKey(m_cert,purpose);
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

	CPublicKey CCertificate::getPublicKey() const
	{
		int purpose=0;
		int ku=getKeyUsage();
		if((ku&(NETCA_PKI_KEYUSAGE_DIGITALSIGNATURE
			|NETCA_PKI_KEYUSAGE_NONREPUDIATION
			|NETCA_PKI_KEYUSAGE_KEYCERTSIGN
			|NETCA_PKI_KEYUSAGE_CRLSIGN)) !=0)
		{
			purpose|=NETCA_PKI_CERT_PURPOSE_SIGN;
		}

		if((ku&NETCA_PKI_KEYUSAGE_KEYAGREEMENT) !=0)
		{
			purpose|=NETCA_PKI_CERT_PURPOSE_KEYAGREEMENT;
		}

		if((ku&(NETCA_PKI_KEYUSAGE_KEYENCIPHERMENT
			|NETCA_PKI_KEYUSAGE_DATAENCIPHERMENT)) !=0)
		{
			purpose|=NETCA_PKI_CERT_PURPOSE_ENCRYPT;
		}
		return getPublicKey(purpose);
	}

	CKeypair CCertificate::getKeypair(int flag,int purpose,const char *pwd)
	{
		NETCA_PKI_KEYPAIR_HANDLE hKeypair=NetcaPKICertGetCertKeyPair(m_cert,flag,purpose,pwd);
		if(hKeypair==0)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypairObj(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypairObj;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
	}

	CKeypair CCertificate::getKeypair(int flag,int purpose)
	{
		return getKeypair(flag,purpose,0);
	}

	CKeypair CCertificate::getKeypair(int purpose)
	{
		return getKeypair(0,purpose,0);
	}

	void CCertificate::setKeypair(const CKeypair& keypair)
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		if(keypair.isNull())
		{
			throw CPKIException("keypair is null");
		}

		int rv;
		rv=NetcaPKICertSetCertKeyPair(m_cert,keypair.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set keypair  fail");
		}
	}

	CCertificate CCertificate::getDefaultCert(int purpose)
	{
		NETCA_PKI_CERTIFICATE_HANDLE hCert=NetcaPKICertGetDefaultCert(purpose);
		if(hCert==0)
		{
			return CCertificate();
		}
		try
		{
			CCertificate certObj(hCert);
			NetcaPKICertFreeCert(hCert);
			hCert=0;
			return certObj;
		}
		catch(std::exception&)
		{
			NetcaPKICertFreeCert(hCert);
			throw;
		}
	}

	void CCertificate::setDefaultCert(int purpose)
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		int rv;
		rv=NetcaPKICertSetDefaultCert(purpose,m_cert);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set default cert fail");
		}
	}

	int CCertificate::verifyUserPIN(const char *pwd,int &retryNumber)
	{
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}

		int rv;
		retryNumber=NETCA_PKI_UNSUPPORTED_RETRY_NUMBER;
		rv=NetcaPKICertVerifyUserPIN(m_cert,pwd,&retryNumber);
		return rv;
	}

	bool CCertificate::verifyUserPIN(const char *pwd)
	{
		int retryNumber;
		return verifyUserPIN(pwd,retryNumber)==NETCA_PKI_SUCCESS;
	}

	int CCertificate::verify(const char *checkTime,int flag,int &status,CRevokeInfo& info)
	{
		int rv;
		NETCA_PKI_REVOKEDCERT_HANDLE revokeInfo;

		rv=NetcaPKICertVerifyCert(m_cert,checkTime,flag,&status,&revokeInfo);
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

	int CCertificate::verify(const std::string& checkTime,int flag,int &status,CRevokeInfo& info)
	{
		return verify(checkTime.c_str(),flag,status,info);
	}

	int CCertificate::verify(int flag,int &status,CRevokeInfo& info)
	{
		return verify(0,flag,status,info);
	}

	std::vector<CCertificate> CCertificate::buildCertPath()
	{
		std::vector<CCertificate> v;
		CCertificate certObj;
		int rv;
		NETCA_PKI_CERTIFICATE_HANDLE *certPath;
		int count;
		rv=NetcaPKICertGetCertPath(m_cert, &certPath,&count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"build cert path fail");
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

	int CCertificate::verifyByCRL(const unsigned char* crl,int crlLen,const char *checkTime,int &status,CRevokeInfo& info)
	{
		int rv;
		NETCA_PKI_REVOKEDCERT_HANDLE revokeInfo;

		rv=NetcaPKICertCRLVerifyCert(m_cert,crl,crlLen,checkTime,&status,&revokeInfo);
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

	int CCertificate::verifyByCRL(const unsigned char* crl,int crlLen,const std::string& checkTime,int &status,CRevokeInfo& info)
	{
		return verifyByCRL(crl,crlLen,checkTime.c_str(),status,info);
	}

	int CCertificate::verifyByCRL(const unsigned char* crl,int crlLen,int &status,CRevokeInfo& info)
	{
		return verifyByCRL(crl,crlLen,0,status,info);
	}

	int CCertificate::verifyByOCSP(const char* ocspUrl,const CCertificate& vaCert,int &status,CRevokeInfo& info)
	{
		int rv;
		NETCA_PKI_REVOKEDCERT_HANDLE revokeInfo;

		rv=NetcaPKICertOCSPVerifyCert(m_cert,ocspUrl,vaCert.handle(),&status,&revokeInfo);
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

	int CCertificate::verifyByOCSP(const char* ocspUrl,int &status,CRevokeInfo& info)
	{
		int rv;
		NETCA_PKI_REVOKEDCERT_HANDLE revokeInfo;

		rv=NetcaPKICertOCSPVerifyCert(m_cert,ocspUrl,0,&status,&revokeInfo);
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

	int CCertificate::verifyByOCSP(const std::string& ocspUrl,const CCertificate& vaCert,int &status,CRevokeInfo& info)
	{
		return verifyByOCSP(ocspUrl.c_str(),vaCert,status,info);
	}

	int CCertificate::verifyByOCSP(const std::string& ocspUrl,int &status,CRevokeInfo& info)
	{
		return verifyByOCSP(ocspUrl.c_str(),status,info);
	}

	void CCertificate::getIssuer(CBlob& data) const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		char* value;
		rv=NetcaPKICertGetCertStringAttribute(m_cert,NETCA_PKI_CERT_ATTRIBUTE_ISSUER_HEX_ENCODE,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get issuer fail");
		}
		try
		{
			data.decodeHexString(value);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		NetcaPKICryptoFreeMemory(value);
	}

	void CCertificate::getSubject(CBlob& data) const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		char* value;
		rv=NetcaPKICertGetCertStringAttribute(m_cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_HEX_ENCODE,&value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get subject fail");
		}
		try
		{
			data.decodeHexString(value);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		NetcaPKICryptoFreeMemory(value);
	}

	void CCertificate::getSubjectKeyId(CBlob& data) const
	{
		int rv;
		if(m_cert==0)
		{
			throw CPKIException("cert is null");
		}
		char* value;
		rv=NetcaPKICertGetCertStringAttribute(m_cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_KEYID,&value);
		if(rv==NETCA_PKI_NOTEXISIT)
		{
			data.clear();
			return;
		}
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get subject fail");
		}
		try
		{
			data.decodeHexString(value);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		NetcaPKICryptoFreeMemory(value);
	}

	bool CCertificate::isSelfSign()const
	{
		CBlob issuer;
		CBlob subject;

		getIssuer(issuer);
		getSubject(subject);

		if(issuer.length()!=subject.length())
		{
			return false;
		}

		if(memcmp(issuer.data(),subject.data(),issuer.length())!=0)
		{
			return false;
		}

		return NetcaPKICertVerifySelfSignCertSignature(m_cert)==NETCA_PKI_SUCCESS;
	}

	std::string CCertificate::DecodeStringExtension(int type,const unsigned char *ext,int extLen)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIDecodeStringExtension(type,ext,extLen,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"decode string extension fail");
		}
		std::string str;
		try
		{
			str.assign((const char *)data,dataLen);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(data);
			throw;
		}
		NetcaPKICryptoFreeMemory(data);
		return str;
	}

	std::string CCertificate::DecodeStringExtension(int type,const CBlob& ext)
	{
		return DecodeStringExtension(type,ext.data(),ext.length());
	}
	
	std::string CCertificate::DecodeStringExtension(const unsigned char *ext,int extLen)
	{
		if(ext==0 || extLen<1)
		{
			throw CPKIException("bad string extension");
		}
		int type=getStringExtensionType(ext[0]);
		if(type==-1)
		{
			throw CPKIException("bad string extension,unknown tag");
		}
		return DecodeStringExtension(type,ext,extLen);
	}

	std::string CCertificate::DecodeStringExtension(const CBlob& ext)
	{
		return DecodeStringExtension(ext.data(),ext.length());
	}

	std::string CCertificate::getSubject(bool reverse) const
	{
		return getStringAttriubte(reverse?NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_REVERSE:NETCA_PKI_CERT_ATTRIBUTE_SUBJECT);
	}

	std::string CCertificate::getIssuer(bool reverse) const
	{
		return getStringAttriubte(reverse?NETCA_PKI_CERT_ATTRIBUTE_ISSUER_REVERSE:NETCA_PKI_CERT_ATTRIBUTE_ISSUER);
	}

	void CCertificate::exportPFX(const char *pwd,const char *friendlyName,CBlob& value)
	{
		int rv;
		unsigned char *pfx;
		int pfxLen;
		rv=NetcaPKICertExportPFX(m_cert,pwd,0,0,friendlyName,&pfx,&pfxLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"export pfx fail");
		}
		value.attach(pfx,pfxLen);
	}

	void CCertificate::exportPFX(const char *pwd,const std::string &friendlyName,CBlob& value)
	{
		if(friendlyName.length()==0)
		{
			exportPFX(pwd,0,value);
		}
		else
		{
			exportPFX(pwd,friendlyName.c_str(),value);
		}
	}

	void CCertificate::exportPFX(const char *pwd,std::vector<CCertificate>& otherCerts,const char *friendlyName,CBlob& value)
	{
		if(otherCerts.size()==0)
		{
			exportPFX(pwd,friendlyName,value);
			return;
		}
		NETCA_PKI_CERTIFICATE_HANDLE *otherCertArray;
		int otherCertCount=(int)otherCerts.size();
		otherCertArray=(NETCA_PKI_CERTIFICATE_HANDLE *)NetcaPKICryptoAllocMemory(sizeof(NETCA_PKI_CERTIFICATE_HANDLE)*otherCertCount);
		if(otherCertArray==0)
		{
			throw CPKIException("alloc fail");
		}
		for(int i=0;i<otherCertCount;i++)
		{
			otherCertArray[i]=otherCerts[i].handle();
		}
		int rv;
		unsigned char *pfx;
		int pfxLen;
		rv=NetcaPKICertExportPFX(m_cert,pwd,otherCertArray,otherCertCount,friendlyName,&pfx,&pfxLen);
		NetcaPKICryptoFreeMemory(otherCertArray);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"export pfx fail");
		}
		value.attach(pfx,pfxLen);
	}

	void CCertificate::exportPFX(const char *pwd,std::vector<CCertificate>& otherCerts,const std::string &friendlyName,CBlob& value)
	{
		if(friendlyName.length()==0)
		{
			exportPFX(pwd,otherCerts,0,value);
		}
		else
		{
			exportPFX(pwd,otherCerts,friendlyName.c_str(),value);
		}
	}

	bool CCertificate::hasSubjectKeyId() const
	{
		bool crical;
		CBlob value;
		return findExtension("2.5.29.14",crical,value);
	}
};
