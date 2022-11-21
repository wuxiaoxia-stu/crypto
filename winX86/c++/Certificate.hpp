#ifndef NETCA_CERTIFICATE_INCLUDE_HPP
#define NETCA_CERTIFICATE_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"
#include <string>
#include <vector>

namespace Netca
{
	class CPublicKey;
	class CKeypair;
	class CRevokeInfo;

	class CCertificate
	{
	public:
		CCertificate();
		CCertificate(const unsigned char *data,int dataLen);
		~CCertificate();
		CCertificate(const CCertificate& cert);
		CCertificate& operator =(const CCertificate& cert);
		CCertificate(NETCA_PKI_CERTIFICATE_HANDLE cert);

		void attach(NETCA_PKI_CERTIFICATE_HANDLE cert);

		bool isNull() const { return m_cert==0; }
		
		void encode(int flag,CBlob& outData)const;
		
		bool match(const char *expr)const;
		bool match(const std::string& expr)const;
		
		static CCertificate SelectCert(const char *type,const char *expr);
		static CCertificate SelectCert(const char *type);
		static CCertificate SelectCert(const std::string& type,const std::string& expr);
		static CCertificate SelectCert(const std::string& type);

		long getIntegerAttribute(int attrId) const;
		std::string getStringAttriubte(int attrId)const;
		std::vector<std::string> getStringArrayAttriubte(int attrId) const;
		static bool IsMultiValueStringAttribute(int attrId) ;
		void getHashAttribute(int attrId,int hashAlgo,CBlob& hashValue) const;

		int getVersion() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_VERSION); } 
		int getSignAlgo() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_SIGNALGO); } 
		int getPublicKeyAlgo() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_PUBKEYALGO); } 
		int getPublicKeyBits() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_PUBKEYBITS); } 
		int getEccCurve() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_PUBKEY_ECC_CURVE); } 
		int getKeyUsage() const{ return (int)getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_KEYUSAGE); } 
		
		std::string getIssuer(bool reverse=false) const;
		void getIssuer(CBlob& data) const;
		std::string getIssuerDisplayName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_DISPLAY_NAME); }
		std::string getIssuerLadpName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_LDAP_NAME); }
		std::string getIssuerXmlSigName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_XMLSIG_NAME); }
		std::vector<std::string> getIssuerC() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_C); }
		std::vector<std::string> getIssuerO() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_O); }
		std::vector<std::string> getIssuerOU() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_OU); }
		std::vector<std::string> getIssuerCN() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_CN); }
		std::vector<std::string> getIssuerEmail() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_EMAIL); }
		std::vector<std::string> getIssuerST() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_ST); }
		std::vector<std::string> getIssuerL() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_L); }
		std::vector<std::string> getIssuerDNQualifier() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_DN_QUALIFIER); }
		std::vector<std::string> getIssuerSN() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_SN); }
		std::vector<std::string> getIssuerTitle() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_TITLE); }
		std::vector<std::string> getIssuerSurname() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_SURNAME); }
		std::vector<std::string> getIssuerGivenName() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_GIVEN_NAME); }
		std::vector<std::string> getIssuerInitials() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_INITIALS); }
		std::vector<std::string> getIssuerPseudonym() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_PSEUDONYM); }
		std::vector<std::string> getIssuerGenerationQualifier() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_GENERATION_QUALIFIER); }
		std::vector<std::string> getIssuerDC() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_DC); }
		std::vector<std::string> getIssuerUID() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_UID); }
		std::vector<std::string> getIssuerStreet() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_ISSUER_STREET); }

		
		std::string getSubject(bool reverse=false) const;
		void getSubject(CBlob& data) const;
		std::string getSubjectDisplayName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_DISPLAY_NAME); }
		std::string getSubjectLadpName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_LDAP_NAME); }
		std::string getSubjectXmlSigName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_XMLSIG_NAME); }
		std::vector<std::string> getC() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_C); }
		std::vector<std::string> getO() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_O); }
		std::vector<std::string> getOU() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_OU); }
		std::vector<std::string> getCN() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_CN); }
		std::vector<std::string> getEmail() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_EMAIL); }
		std::vector<std::string> getST() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_ST); }
		std::vector<std::string> getL() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_L); }
		std::vector<std::string> getDNQualifier() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_DN_QUALIFIER); }
		std::vector<std::string> getSubjectSN() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_SN); }
		std::vector<std::string> getTitle() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_TITLE); }
		std::vector<std::string> getSurname() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_SURNAME); }
		std::vector<std::string> getGivenName() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_GIVEN_NAME); }
		std::vector<std::string> getInitials() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_INITIALS); }
		std::vector<std::string> getPseudonym() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_PSEUDONYM); }
		std::vector<std::string> getGenerationQualifier() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_GENERATION_QUALIFIER); }
		std::vector<std::string> getDC() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_DC); }
		std::vector<std::string> getSubjectUID() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_UID); }
		std::vector<std::string> getStreet() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_STREET); }
		std::vector<std::string> getJurisdictionL() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_JURISDICTION_L); }
		std::vector<std::string> getJurisdictionST() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_JURISDICTION_ST); }
		std::vector<std::string> getJurisdictionC() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_JURISDICTION_C); }
		std::vector<std::string> getBusinessCategory() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SUBJECT_BUSINESS_CATEGORY); }

		std::string getSerialNumber() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SN_HEX); }
		std::string getDecimalSerialNumber() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_SN_DEC); }
		std::string getNotBefore() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_VALIDITY_START); }
		std::string getNotAfter() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_VALIDITY_END); }
		std::string getUPN() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_UPN); }
		std::vector<std::string> getCRLUrl() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_CRL_URL); }
		std::vector<std::string> getDeltaCRLUrl() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_DELTA_CRL_URL); }
		std::vector<std::string> getOCSPUrl() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_OCSP_URL); }
		std::vector<std::string> getIP() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_IP); }
		std::vector<std::string> getDNSName() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_DNS_NAME); }
		std::vector<std::string> getCertPolicyOid() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_CERT_POLICY_OID); }
		std::vector<std::string> getExtendedKeyUsage() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_EXTENDED_KEY_USAGE); }
		std::vector<std::string> getCAIssuerURL() const{ return getStringArrayAttriubte(NETCA_PKI_CERT_ATTRIBUTE_CAISSUERS_URL); }
		void getSubjectKeyId(CBlob& data) const;
		bool hasSubjectKeyId() const;

		void getThumbprint(int hashAlgo,CBlob& value) const
		{
			getHashAttribute(NETCA_PKI_CERT_ATTRIBUTE_THUMBPRINT,hashAlgo,value);
		}
		
		std::string getFriendlyName() const{ return getStringAttriubte(NETCA_PKI_CERT_ATTRIBUTE_EX_FRIENDLY_NAME); }

		bool isInValidity()const { return getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_IN_VALIDITY)!=0; }
		bool hasPrivateKey() const {return getIntegerAttribute(NETCA_PKI_CERT_ATTRIBUTE_HAS_PRIVKEY_ATTRIBUTE)!=0; }

		void setIntegerAttribute(int attrId,long value);
		void setStringAttribute(int attrId,const char *value);
		void setStringAttribute(int attrId,const std::string& value);

		bool findExtension(const char *oid,bool& crical,CBlob& value) const;
		bool findExtension(const std::string& oid,bool& crical,CBlob& value) const;

		CPublicKey getPublicKey(int purpose) const;
		CPublicKey getPublicKey() const;
		CKeypair getKeypair(int flag,int purpose,const char *pwd);
		CKeypair getKeypair(int flag,int purpose);
		CKeypair getKeypair(int purpose);
		void setKeypair(const CKeypair& keypair);

		static CCertificate getDefaultCert(int purpose);
		void setDefaultCert(int purpose);

		bool isSelfSign()const;

		int verifyUserPIN(const char *pwd,int &retryNumber);
		bool verifyUserPIN(const char *pwd);

		int verify(const char *checkTime,int flag,int &status,CRevokeInfo& info);
		int verify(const std::string& checkTime,int flag,int &status,CRevokeInfo& info);
		int verify(int flag,int &status,CRevokeInfo& info);

		std::vector<CCertificate> buildCertPath();

		int verifyByCRL(const unsigned char* crl,int crlLen,const char *checkTime,int &status,CRevokeInfo& info);
		int verifyByCRL(const unsigned char* crl,int crlLen,const std::string& checkTime,int &status,CRevokeInfo& info);
		int verifyByCRL(const unsigned char* crl,int crlLen,int &status,CRevokeInfo& info);
		int verifyByOCSP(const char* ocspUrl,const CCertificate& vaCert,int &status,CRevokeInfo& info);
		int verifyByOCSP(const char* ocspUrl,int &status,CRevokeInfo& info);
		int verifyByOCSP(const std::string& ocspUrl,const CCertificate& vaCert,int &status,CRevokeInfo& info);
		int verifyByOCSP(const std::string& ocspUrl,int &status,CRevokeInfo& info);

		void exportPFX(const char *pwd,const char *friendlyName,CBlob& value);
		void exportPFX(const char *pwd,const std::string &friendlyName,CBlob& value);
		void exportPFX(const char *pwd,std::vector<CCertificate>& otherCerts,const char *friendlyName,CBlob& value);
		void exportPFX(const char *pwd,std::vector<CCertificate>& otherCerts,const std::string &friendlyName,CBlob& value);

		static std::string DecodeStringExtension(int type,const unsigned char *ext,int extLen);
		static std::string DecodeStringExtension(int type,const CBlob& ext);
		static std::string DecodeStringExtension(const unsigned char *ext,int extLen);
		static std::string DecodeStringExtension(const CBlob& ext);

	private:
		friend class CTimeStamp;
		friend class CStore;
		friend class CSignedData;
		friend class CKeypair;
		friend class CEnvelopedData;
		friend class CDevice;
		friend class CCertVerify;
		friend bool operator==(const CCertificate& cert1,const CCertificate& cert2);

		NETCA_PKI_CERTIFICATE_HANDLE handle()const { return m_cert;}

		NETCA_PKI_CERTIFICATE_HANDLE m_cert;
	};

	bool operator==(const CCertificate& cert1,const CCertificate& cert2);
};

#endif

