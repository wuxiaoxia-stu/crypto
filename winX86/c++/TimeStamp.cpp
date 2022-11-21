#include "TimeStamp.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "SignedData.hpp"
#include "NETCA_PKI_Internal.h"

extern "C" NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgTimeStampDup(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

namespace Netca
{
	CTimeStamp::CTimeStamp()
	{
		m_hTimeStamp=NetcaPKIMsgNewTimeStamp();
		if(m_hTimeStamp==0)
		{
			throw CPKIException("create timestamp handle fail");
		}
	}

	CTimeStamp::CTimeStamp(const unsigned char *token,int tokenLen)
	{
		m_hTimeStamp=NetcaPKIMsgVerifyTimeStampToken(token,tokenLen,0);
		if(m_hTimeStamp==0)
		{
			throw CPKIException("verify timestamp token fail");
		}
	}

	CTimeStamp::CTimeStamp(const unsigned char *token,int tokenLen,const CCertificate& cert)
	{
		m_hTimeStamp=NetcaPKIMsgVerifyTimeStampToken(token,tokenLen,cert.handle());
		if(m_hTimeStamp==0)
		{
			throw CPKIException("verify timestamp token fail");
		}
	}

	CTimeStamp::CTimeStamp(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp)
	{
		m_hTimeStamp=NetcaPKIMsgTimeStampDup(hTimeStamp);
		if(m_hTimeStamp==0)
		{
			throw CPKIException("dup timestamp handle fail");
		}
	}

	CTimeStamp::CTimeStamp(const CTimeStamp& timestamp)
	{
		m_hTimeStamp=NetcaPKIMsgTimeStampDup(timestamp.m_hTimeStamp);
		if(m_hTimeStamp==0)
		{
			throw CPKIException("dup timestamp handle fail");
		}
	}

	CTimeStamp::~CTimeStamp()
	{
		NetcaPKIMsgFreeTimeStamp(m_hTimeStamp);
	}

	

	void CTimeStamp::setTSA(const char *tsaUrl)
	{
		int rv;

		rv=NetcaPKIMsgTimeStampSetTSA(m_hTimeStamp,tsaUrl);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set tsa url fail");
		}
	}

	void CTimeStamp::setTSA(const std::string& tsaUrl)
	{
		setTSA(tsaUrl.c_str());
	}

	void CTimeStamp::setHashAlgorithm(int algo)
	{
		int rv;

		rv=NetcaPKIMsgTimeStampSetHashAlgorithm(m_hTimeStamp,algo);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set hash algorithm fail");
		}
	}

	void CTimeStamp::setMessageImprint(const unsigned char *hash,int hashLen)
	{
		int rv;

		rv=NetcaPKIMsgTimeStampSetMessageImprint(m_hTimeStamp,hash,hashLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set message imprint fail");
		}
	}
	
	void CTimeStamp::setMessageImprint(const CBlob &hash)
	{
		int rv;

		rv=NetcaPKIMsgTimeStampSetMessageImprint(m_hTimeStamp,hash.data(),hash.length());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set message imprint fail");
		}
	}
	void CTimeStamp::getReqEncode(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIMsgTimeStampGetReqEncode(m_hTimeStamp,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp get request encode fail");
		}
		outData.attach(data,dataLen);
	}

	int CTimeStamp::getResponse(int &status)
	{
		return NetcaPKIMsgTimeStampGetResponse(m_hTimeStamp,&status);
	}

	void CTimeStamp::getTimeStampToken(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIMsgTimeStampGetTimeStampToken(m_hTimeStamp,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp get token fail");
		}
		outData.attach(data,dataLen);
	}

	CCertificate CTimeStamp::getTSACert()
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert=NetcaPKIMsgTimeStampGetTSACert(m_hTimeStamp);
		if(cert==0)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	int CTimeStamp::getHashAlgorithm()
	{
		
		int algo;
		algo=NetcaPKIMsgTimeStampGetHashAlgorithm(m_hTimeStamp);
		if(algo<0)
		{
			throw CPKIException("timestamp get hash algorithm fail");
		}
		return algo;
	}

	void CTimeStamp::getMessageImprint(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIMsgTimeStampGetMessageImprint(m_hTimeStamp,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp get message imprint fail");
		}
		outData.attach(data,dataLen);
	}

	std::string CTimeStamp::getTimeString()
	{
		char *time;
		std::string str;

		time=NetcaPKIMsgTimeStampGetTime(m_hTimeStamp);
		if(time==0)
		{
			throw CPKIException("timestamp get time fail");
		}

		try
		{
			str=time;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(time);
			throw;
		}
		NetcaPKICryptoFreeMemory(time);
		return str;
	}

	std::string CTimeStamp::getPolicy()
	{
		char *policy;
		std::string str;

		policy=NetcaPKIMsgTimeStampGetTime(m_hTimeStamp);
		if(policy==0)
		{
			throw CPKIException("timestamp get policy fail");
		}

		try
		{
			str=policy;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(policy);
			throw;
		}
		NetcaPKICryptoFreeMemory(policy);
		return str;
	}

	void CTimeStamp::setPolicy(const char *policy)
	{
		int rv;
		rv=NetcaPKIMsgTimeStampSetPolicy(m_hTimeStamp,policy);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set policy fail");
		}
	}

	void CTimeStamp::setPolicy(const std::string& policy)
	{
		setPolicy(policy.c_str());
	}

	std::string CTimeStamp::getSerialNumber()
	{
		char *sn;
		std::string str;

		sn=NetcaPKIMsgTimeStampGetSerialNumber(m_hTimeStamp);
		if(sn==0)
		{
			throw CPKIException("timestamp get serial number fail");
		}

		try
		{
			str=sn;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(sn);
			throw;
		}
		NetcaPKICryptoFreeMemory(sn);
		return str;
	}

	void CTimeStamp::getNonce(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv=NetcaPKIMsgTimeStampGetNonce(m_hTimeStamp,&data,&dataLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp get nonce fail");
		}
		outData.attach(data,dataLen);
	}

	void CTimeStamp::setCertReq(bool certReq)
	{
		int rv;
		rv=NetcaPKIMsgTimeStampSetCertReq(m_hTimeStamp,certReq);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set certreq fail");
		}
	}

	bool CTimeStamp::getCertReq()
	{
		int rv;
		int certReq;
		rv=NetcaPKIMsgTimeStampGetCertReq(m_hTimeStamp,&certReq);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp get certreq fail");
		}
		return certReq!=0;
	}

	void CTimeStamp::setTSACert(const CCertificate& cert)
	{
		if(cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv=NetcaPKIMsgTimeStampSetTSACert(m_hTimeStamp,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"timestamp set tsa cert fail");
		}

	}

	int CTimeStamp::GetTimeStampTokenFromResponse(const unsigned char *resp,int respLen,CBlob& outData)
	{
		int rv;
		unsigned char *token;
		int tokenLen;
		int status;
		rv=NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse(resp,respLen,&status,&token,&tokenLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get timestamp form response fail");
		}

		if(status==NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTED
			|| status==NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
		{
			outData.attach(token,tokenLen);
		}
		else
		{
			outData.clear();
		}
		return status;
	}

	int CTimeStamp::getAccuracy(int &seconds,int &millis,int &micros)
	{
		return NetcaPKIMsgTimeStampGetAccuracy(m_hTimeStamp,&seconds,&millis,&micros);
	}

	CSignedData CTimeStamp::getSignedData()
	{
		NETCA_PKI_SIGNEDDATA_HANDLE hSignedData=NetcaPKIMsgTimeStampGetSignedData(m_hTimeStamp);
		if(hSignedData==0)
		{
			throw CPKIException("get signedata fail");
		}
		try
		{
			CSignedData signedData(hSignedData);
			NetcaPKIMsgFreeSignedData(hSignedData);
			hSignedData=0;
			return signedData;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeSignedData(hSignedData);
			throw;
		}
	}

	void CTimeStamp::AddTSACert(const CCertificate& cert)
	{
		int rv;

		rv=NetcaPKICryptoAddTSACert(cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add tsa cert fail");
		}
	}

	std::vector<CCertificate> CTimeStamp::GetTSACerts()
	{
		std::vector<CCertificate> v;
		CCertificate certObj;
		int rv;
		NETCA_PKI_CERTIFICATE_HANDLE *certs;
		int count;
		rv=NetcaPKICryptoGetTSACerts(&certs,&count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get tsa certs fail");
		}
		try
		{
			for(int i=0;i<count;i++)
			{
				v.push_back(certs[i]);
			}
		}
		catch(std::exception&)
		{
			NetcaPKICertFreeCertPath(certs,count);
			throw;
		}
		NetcaPKICertFreeCertPath(certs,count);
		return v;
	}
}
