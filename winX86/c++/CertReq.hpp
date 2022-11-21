#ifndef NETCA_CERTREQ_INCLUDE_HPP
#define NETCA_CERTREQ_INCLUDE_HPP

#include "NETCA_PKI_CertReq.h"
#include "Blob.hpp"
#include <string>
#include <vector>

namespace Netca
{
	class CKeypair;
	class CPublicKey;

	class CCertReq
	{
	public:
		CCertReq();
		CCertReq(const unsigned char*data,int dataLen);
		~CCertReq();

		
		void setIntegerAttribute(int atrrId,int value);
		int getIntegerAttribute(int atrrId)const;
		void setStringAttribute(int atrrId,const char *value);
		void setStringAttribute(int atrrId,const std::string& value);
		std::string getStringAttribute(int atrrId)const;
		

		int getVersion()const { return getIntegerAttribute(NETCA_PKI_CERTREQ_VERSION); }
		int getSignAlgo()const { return getIntegerAttribute(NETCA_PKI_CERTREQ_SIGN_ALGO); }
		
		void setVersion(int version) { setIntegerAttribute(NETCA_PKI_CERTREQ_VERSION,version); }
		void setSignAlgo(int algo) { setIntegerAttribute(NETCA_PKI_CERTREQ_SIGN_ALGO,algo); }
		
		void sign(const CKeypair& keypair,int signAlgo,CBlob& certReq);
		bool verify();
		
		void setSubject(const unsigned char *data,int dataLen);
		void setSubject(const char *value,bool reverse=false);
		void setSubject(const std::string& value,bool reverse=false);
		void getSubject(CBlob& subject)const;
		std::string getSubject(bool reverse=false)const;
		

		std::string getC()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_C); }
		std::string getST()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_ST); }
		std::string getL()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_L); }
		std::string getO()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_O); }
		std::string getOU()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_OU); }
		std::string getCN()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_CN); }
		std::string getEmail()const { return getStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_EMAIL); }

		void setC(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_C,value); }
		void setC(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_C,value); }
		void setST(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_ST,value); }
		void setST(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_ST,value); }
		void setL(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_L,value); }
		void setL(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_L,value); }
		void setO(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_O,value); }
		void setO(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_O,value); }
		void setOU(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_OU,value); }
		void setOU(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_OU,value); }
		void setOU(const std::vector<std::string>& value) { setStringArrayAttribute(NETCA_PKI_CERTREQ_SUBJECT_OU,value); }
		void setCN(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_CN,value); }
		void setCN(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_CN,value); }
		void setCN(const std::vector<std::string>& value) { setStringArrayAttribute(NETCA_PKI_CERTREQ_SUBJECT_CN,value); }
		void setEmail(const char * value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_EMAIL,value); }
		void setEmail(const std::string& value) { setStringAttribute(NETCA_PKI_CERTREQ_SUBJECT_EMAIL,value); }

		CPublicKey getPublicKey()const;
		void encode(CBlob& subject)const;

		void addAttribute(const char *attrType,const unsigned char *attrValue,int attrValueLen);
		void addAttribute(const std::string& attrType,const unsigned char *attrValue,int attrValueLen);
		int getAttributeCount()const { return getIntegerAttribute(NETCA_PKI_CERTREQ_ATTRIBUTE_COUNT); }
		void getAttribute(int index,std::string& attrType,CBlob& attrValue)const;

	private:
		CCertReq(const CCertReq& );
		CCertReq& operator =(const CCertReq& );
		NETCA_PKI_CERTREQ_HANDLE m_hReq;
		void setStringArrayAttribute(int atrrId,const std::vector<std::string>& value);
	};
};
#endif
