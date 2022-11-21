#ifndef NETCA_CERTVERIFY_INCLUDE_HPP
#define NETCA_CERTVERIFY_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"
#include "RevokeInfo.hpp"
#include <string>
#include <vector>

namespace Netca
{
	class CCertificate;
	class CPublicKey;
	
	class CCertVerify
	{
	public:
		CCertVerify();
		~CCertVerify();
		
		void setOption(int option);
		void setParam(const char *param);
		void setParam(const std::string& param);
		void addRootCert(const CCertificate &cert);
		void addCACert(const CCertificate &cert);
		void setVerifyTime(const char *verifyTime);
		void setVerifyTime(const std::string& verifyTime);
		void addIgnoreExtension(const char *ext);
		void addIgnoreExtension(const std::string& ext);

		void CCertVerify::addCRL(const unsigned char *crl,int crlLen);
		void addOCSP(const unsigned char *ocsp,int ocspLen,const CCertificate &vaCert);
		void addOCSP(const unsigned char *ocsp,int ocspLen);

		int verify(const CCertificate& cert,int &status,CRevokeInfo &info);
		std::vector<CCertificate> getCertPath();
		CPublicKey getPublicKey(int purpose);
		std::vector<std::string> getAuthPolicySet();
		std::vector<std::string> getUserPolicySet();
	private:
		friend class CSignedData;
		CCertVerify(const CCertVerify& verify);
		CCertVerify(NETCA_PKI_CERT_VERIFY_HANDLE hVerify);
		CCertVerify& operator =(const CCertVerify& );
		NETCA_PKI_CERT_VERIFY_HANDLE m_hVerify;
	};

};

#endif

