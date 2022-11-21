#ifndef NETCA_TIMESTAMP_INCLUDE_HPP
#define NETCA_TIMESTAMP_INCLUDE_HPP

#include "NETCA_PKI_Application.h"
#include "Blob.hpp"
#include <string>
#include <vector>

namespace Netca
{

	class CCertificate;
	class CSignedData;

	class CTimeStamp
	{
	public:
		CTimeStamp();
		CTimeStamp(const unsigned char *token,int tokenLen);
		CTimeStamp(const unsigned char *token,int tokenLen,const CCertificate& cert);
		
		~CTimeStamp();
		
		void setTSA(const char *tsaUrl);
		void setTSA(const std::string& tsaUrl);
		void setHashAlgorithm(int algo);
		void setMessageImprint(const unsigned char *hash,int hashLen);
		void setMessageImprint(const CBlob &hash);
		void getReqEncode(CBlob& outData);
		int getResponse(int &status);
		void getTimeStampToken(CBlob& outData);
		void setPolicy(const char *policy);
		void setPolicy(const std::string& policy);
		void setCertReq(bool certReq);
		void setTSACert(const CCertificate& cert);

		CCertificate getTSACert();
		int getHashAlgorithm();
		void getMessageImprint(CBlob& outData);
		std::string getTimeString();
		std::string getPolicy();
		std::string getSerialNumber();
		void getNonce(CBlob& outData);
		bool getCertReq();

		int getAccuracy(int &seconds,int &millis,int &micros);

		CSignedData getSignedData();

		static int GetTimeStampTokenFromResponse(const unsigned char *resp,int respLen,CBlob& outData);
		
		static void AddTSACert(const CCertificate& cert);
		static std::vector<CCertificate> GetTSACerts();
	private:
		friend class CSignedData;
		CTimeStamp(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);
		CTimeStamp(const CTimeStamp&);
		CTimeStamp& operator =(const CTimeStamp& );
		NETCA_PKI_TIMESTAMP_HANDLE m_hTimeStamp;
	};

};

#endif

