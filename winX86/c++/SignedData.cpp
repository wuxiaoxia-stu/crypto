#include "SignedData.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "Device.hpp"
#include "TimeStamp.hpp"
#include "CertVerify.hpp"

extern "C" NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataDup(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);

namespace Netca
{
	CSignedData::CSignedData(bool sign)
	{
		m_hSignedData = NetcaPKIMsgNewSignedData(sign);
		if (m_hSignedData == 0)
		{
			throw CPKIException("new signeddata handle fail");
		}
	}
	CSignedData::CSignedData(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData)
	{
		m_hSignedData=NetcaPKIMsgSignedDataDup(hSignedData);
		if(m_hSignedData==0)
		{
			throw CPKIException("dup signeddata handle fail");
		}
	}

	CSignedData::CSignedData(const CSignedData& signedData)
	{
		m_hSignedData=NetcaPKIMsgSignedDataDup(signedData.m_hSignedData);
		if(m_hSignedData==0)
		{
			throw CPKIException("dup signeddata handle fail");
		}
	}

	CSignedData::~CSignedData()
	{
		NetcaPKIMsgFreeSignedData(m_hSignedData);
	}

	void CSignedData::setIntegerAttribute(int atrrId, int index, int value)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataSetIntegerAttribute(m_hSignedData, atrrId, index,value);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata set integer attribute fail");
		}
	}

	void CSignedData::setStringAttribute(int atrrId, int index, const char* value)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataSetStringAttribute(m_hSignedData, atrrId, index, value);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata set string attribute fail");
		}
	}

	void CSignedData::setStringAttribute(int atrrId, int index, const std::string& value)
	{
		setStringAttribute(atrrId, index, value.c_str());
	}

	void CSignedData::setSignCert(const CCertificate& cert,const char *pwd)
	{
		if (cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv = NetcaPKIMsgSignedDataSetSignCert(m_hSignedData, cert.handle(),pwd);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata set sign cert fail");
		}
	}

	void CSignedData::setEncCert(int index, int flag, const CCertificate& cert)
	{
		if (cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv = NetcaPKIMsgSignedDataSetEncCert(m_hSignedData, index,flag, cert.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata set enc cert fail");
		}
	}

	void CSignedData::addCert(const CCertificate& cert)
	{
		if (cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		int rv;
		rv = NetcaPKIMsgSignedDataAddCert(m_hSignedData, cert.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add cert fail");
		}
	}

	void CSignedData::addCRL(const unsigned char *crl, int crlLen)
	{
		int rv;
		
		rv = NetcaPKIMsgSignedDataAddCRL(m_hSignedData,crl,crlLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add crl fail");
		}
	}

	void CSignedData::setDevice(const CDevice& device)
	{
		if (device.isNull())
		{
			throw CPKIException("device is null");
		}
		int rv;
		rv = NetcaPKIMsgSignedDataSetCryptoHandle(m_hSignedData, device.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata set device fail");
		}
	}

	void CSignedData::addSignedAttribute(int index, const char *attrType, const unsigned char *attrValue, int attrValueLen)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataAddSignedAttribute(m_hSignedData, index, attrType,attrValue,attrValueLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add signed attribute fail");
		}
	}

	void CSignedData::addSignedAttribute(int index, const std::string& attrType, const unsigned char *attrValue, int attrValueLen)
	{
		addSignedAttribute(index, attrType.c_str(), attrValue, attrValueLen);
	}

	void CSignedData::addUnsignedAttribute(int index, const char *attrType, const unsigned char *attrValue, int attrValueLen)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataAddUnsignedAttribute(m_hSignedData, index, attrType, attrValue, attrValueLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add unsigned attribute fail");
		}
	}

	void CSignedData::addUnsignedAttribute(int index, const std::string& attrType, const unsigned char *attrValue, int attrValueLen)
	{
		addUnsignedAttribute(index, attrType.c_str(), attrValue, attrValueLen);
	}

	void CSignedData::encode(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataEncode(m_hSignedData, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata encode fail");
		}
		outData.attach(data,dataLen);
	}

	void CSignedData::sign(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSign(m_hSignedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign fail");
		}
		outData.attach(data, dataLen);
	}
	void CSignedData::coSign(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSign(m_hSignedData, 0, 0, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::countersign(int index, int algo, const CCertificate& cert, const char *pwd, CBlob& outData)
	{
		if (cert.isNull())
		{
			throw CPKIException("cert is null");
		}

		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataCountersign(m_hSignedData, index,algo,cert.handle(),pwd,&data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata countersign fail");
		}
		outData.attach(data, dataLen);

	}

	void CSignedData::countersign(int index, int algo, const CCertificate& cert, CBlob& outData)
	{
		countersign(index, algo, cert, 0, outData);
	}

	void CSignedData::signWithTimeStamp(const char *tsaName, const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSignWithTimeStamp(m_hSignedData, tsaName, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign with timestamp fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::signWithTimeStamp(const std::string& tsaName, const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		signWithTimeStamp(tsaName.c_str(), inData, inDataLen, outData);
	}

	void CSignedData::signInit(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSignInit(m_hSignedData, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign init fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::signUpdate(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSignUpdate(m_hSignedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign update fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::signFinal(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSignFinal(m_hSignedData, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign final fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::signWithTimeStampFinal(const char *tsaName, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataSignWithTimeStampFinal(m_hSignedData, tsaName,&data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata sign with timestamp final fail");
		}
		outData.attach(data, dataLen);
	}

	void CSignedData::signWithTimeStampFinal(const std::string& tsaName, CBlob& outData)
	{
		signWithTimeStampFinal(tsaName.c_str(), outData);
	}

	std::vector<CCertificate> CSignedData::getCerts()
	{
		std::vector<CCertificate> v;
		CCertificate cert;
		int rv;
		NETCA_PKI_CERTIFICATE_HANDLE *certs;
		int count;

		rv = NetcaPKIMsgSignedDataGetCertificates(m_hSignedData, &certs, &count);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get certs fail");
		}
		for (int i = 0; i < count; i++)
		{
			cert.attach(certs[i]);
			try
			{
				v.push_back(cert);
			}
			catch (std::exception&)
			{
				for (int j = i + 1; j < count; j++)
				{
					NetcaPKICertFreeCert(certs[j]);
				}
				NetcaPKICryptoFreeMemory(certs);
				throw;
			}
		}
		NetcaPKICryptoFreeMemory(certs);
		return v;
	}

	int CSignedData::verify(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataVerify(m_hSignedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS && rv != NETCA_PKI_VERIFY_SIGNEDDATA_PARTLY_FAIL
			&& rv != NETCA_PKI_VERIFY_SIGNEDDATA_CERT_FAIL)
		{
			return rv;
		}
		outData.attach(data, dataLen);
		return rv;
	}

	bool CSignedData::verifySignatureTimeStamp(int index, const CCertificate &tsaCert)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataVerifyTimeStamp(m_hSignedData, index, tsaCert.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			return false;
		}
		return true;
	}

	bool CSignedData::verifySignatureTimeStamp(int index)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataVerifyTimeStamp(m_hSignedData, index, 0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			return false;
		}
		return true;
	}

	bool CSignedData::verifyCountersignature(int index, int countersignIndex, const CCertificate& cert)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataVerifyCountersignature(m_hSignedData, index, countersignIndex,cert.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			return false;
		}
		return true;
	}

	bool CSignedData::verifyCountersignature(int index, int countersignIndex)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataVerifyCountersignature(m_hSignedData, index, countersignIndex, 0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			return false;
		}
		return true;
	}

	void CSignedData::verifyInit()
	{
		int rv;
		rv = NetcaPKIMsgSignedDataVerifyInit(m_hSignedData);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata verify init fail");
		}
	}

	void CSignedData::verifyUpdate(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgSignedDataVerifyUpdate(m_hSignedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata verify update fail");
		}
		outData.attach(data, dataLen);
		
	}

	int CSignedData::verifyFinal()
	{
		return NetcaPKIMsgSignedDataVerifyFinal(m_hSignedData);
	}

	void CSignedData::detachedVerifyInit(const unsigned char *sign, int signLen)
	{
		int rv = NetcaPKIMsgSignedDataDetachedVerifyInit(m_hSignedData, sign, signLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata detached verify init fail");
		}
	}

	void CSignedData::detachedVerifyUpdate(const unsigned char *inData, int inDataLen)
	{
		int rv;
		
		rv = NetcaPKIMsgSignedDataDetachedVerifyUpdate(m_hSignedData, inData, inDataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata detached verify update fail");
		}
		
	}

	int CSignedData::detachedVerifyFinal()
	{
		return NetcaPKIMsgSignedDataDetachedVerifyFinal(m_hSignedData);
	}

	int CSignedData::detachedVerifyHash(int index, const unsigned char *hash, int hashLen)
	{
		return NetcaPKIMsgSignedDataDetachedVerifyHash(m_hSignedData,index,hash,hashLen);
	}

	int CSignedData::detachedVerify(const unsigned char *tbs, int tbsLen, const unsigned char *sign, int signLen)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataDetachedVerify(m_hSignedData, tbs, tbsLen, sign, signLen);
		return rv;
	}

	int CSignedData::getIntegerAttribute(int atrrId, int index)
	{
		int rv;
		int value;

		rv = NetcaPKIMsgSignedDataGetIntegerAttribute(m_hSignedData, atrrId, index, &value);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get integer attribute fail");
		}

		return value;
	}

	std::string CSignedData::getStringAttribute(int atrrId, int index)
	{
		int rv;
		char * value;
		std::string str;
		rv = NetcaPKIMsgSignedDataGetStringAttribute(m_hSignedData, atrrId, index, &value);
		if(rv==NETCA_PKI_NOTEXISIT)
		{
			return std::string();
		}
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get string attribute fail");
		}

		try
		{
			str = value;
		}
		catch (std::exception&)
		{
			NetcaPKICryptoFreeMemory(value);
			throw;
		}
		NetcaPKICryptoFreeMemory(value);
		
		return str;
	}

	void CSignedData::getSignedAttribute(int index, int attrIndex, std::string& attrType, CBlob& attrValue)
	{
		int rv;
		char *type;
		unsigned char *data;
		int dataLen;
		rv = NetcaPKIMsgSignedDataGetSignedAttribute(m_hSignedData, index, attrIndex, &type, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get signed attribute fail");
		}
		attrValue.attach(data, dataLen);
		try
		{
			attrType = type;
		}
		catch (std::exception&)
		{
			NetcaPKICryptoFreeMemory(type);
			throw;
		}
		NetcaPKICryptoFreeMemory(type);
	}

	void CSignedData::getUnsignedAttribute(int index, int attrIndex, std::string& attrType, CBlob& attrValue)
	{
		int rv;
		char *type;
		unsigned char *data;
		int dataLen;
		rv = NetcaPKIMsgSignedDataGetUnsignedAttribute(m_hSignedData, index, attrIndex, &type, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get unsigned attribute fail");
		}
		attrValue.attach(data, dataLen);
		try
		{
			attrType = type;
		}
		catch (std::exception&)
		{
			NetcaPKICryptoFreeMemory(type);
			throw;
		}
		NetcaPKICryptoFreeMemory(type);
	}

	CCertificate CSignedData::getSignCert(int index)
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert = NetcaPKIMsgSignedDataGetSignCert(m_hSignedData,index);
		if (cert == 0)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	CCertificate CSignedData::getEncCert(int index)
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert;
		int rv= NetcaPKIMsgSignedDataGetEncCert(m_hSignedData, index,&cert);
		if (rv != NETCA_PKI_SUCCESS)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	CCertificate CSignedData::getSignatureTimeStampCert(int index)
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert = NetcaPKIMsgSignedDataGetTSACert(m_hSignedData, index);
		if (cert == 0)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	CCertificate CSignedData::getCountersignatureCert(int index, int countersignIndex)
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert = NetcaPKIMsgSignedDataGetCountersignatureCert(m_hSignedData, index, countersignIndex);
		if (cert == 0)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	void CSignedData::addOCSP(const CCertificate& vaCert,const unsigned char *ocsp,int ocspLen)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataAddOCSP(m_hSignedData,0,vaCert.handle(),ocsp,ocspLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add ocsp fail");
		}
	}

	void CSignedData::addOCSP(const unsigned char *ocsp,int ocspLen)
	{
		int rv;
		rv = NetcaPKIMsgSignedDataAddOCSP(m_hSignedData,0,0,ocsp,ocspLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add ocsp fail");
		}
	}

	void CSignedData::setCompleteCertificateRefs(int index,int hashAlgo,bool hasIssuerSN,const std::vector<CCertificate>& certs)
	{
		NETCA_PKI_CERTIFICATE_HANDLE *certArray;
		int certCount=(int)certs.size();
		certArray=(NETCA_PKI_CERTIFICATE_HANDLE *)NetcaPKICryptoAllocMemory(sizeof(NETCA_PKI_CERTIFICATE_HANDLE)*certCount);
		if(certArray==0)
		{
			throw CPKIException("alloc fail");
		}
		for(int i=0;i<certCount;i++)
		{
			certArray[i]=certs[i].handle();
		}
		int rv;
		rv=NetcaPKIMsgSignedDataSetCompleteCertificateRefs(m_hSignedData,index,hashAlgo,
			hasIssuerSN?1:0,certArray,certCount);
		NetcaPKICryptoFreeMemory(certArray);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set CompleteCertificateRefs fail");
		}
	}

	void CSignedData::addCompleteRevocationRef(int index,bool last,int flag,int hashAlgo,const unsigned char *crlData,int crlDataLen,const unsigned char *ocsp,int ocspLen)
	{
		if(last)
		{
			flag|=NETCA_PKI_CRLOCSPREF_FLAG_FINISH;
		}
		else
		{
			flag&=~NETCA_PKI_CRLOCSPREF_FLAG_FINISH;
		}
		int rv;
		rv=NetcaPKIMsgSignedDataAddCompleteRevocationRef(m_hSignedData,index,flag,
			hashAlgo,crlData,crlDataLen,ocsp,ocspLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add CompleteRevocationRef fail");
		}
	}

	void CSignedData::addCRLRef(int index,bool last,bool useCrlId,int hashAlgo,const unsigned char *crlData,int crlDataLen)
	{
		int flag=NETCA_PKI_CRLOCSPREF_FLAG_USE_CRL;
		if(last)
		{
			flag|=NETCA_PKI_CRLOCSPREF_FLAG_FINISH;
		}
		if(useCrlId)
		{
			flag|=NETCA_PKI_CRLOCSPREF_FLAG_HAS_CRLIDENTIFIER;
		}
		int rv;
		rv=NetcaPKIMsgSignedDataAddCompleteRevocationRef(m_hSignedData,index,flag,
			hashAlgo,crlData,crlDataLen,0,0);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add CompleteRevocationRef fail");
		}
	}

	void CSignedData::addOCSPRef(int index,bool last,bool useOcspRespHash,int hashAlgo,const unsigned char *ocsp,int ocspLen)
	{
		int flag=NETCA_PKI_CRLOCSPREF_FLAG_USE_OCSP;
		if(last)
		{
			flag|=NETCA_PKI_CRLOCSPREF_FLAG_FINISH;
		}
		if(useOcspRespHash)
		{
			flag|=NETCA_PKI_CRLOCSPREF_FLAG_HAS_OCSPRESPHASH;
		}
		int rv;
		rv=NetcaPKIMsgSignedDataAddCompleteRevocationRef(m_hSignedData,index,flag,
			hashAlgo,0,0,ocsp,ocspLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add CompleteRevocationRef fail");
		}
	}

	void CSignedData::setCertificateValues(int index,const std::vector<CCertificate>& certs)
	{
		NETCA_PKI_CERTIFICATE_HANDLE *certArray;
		int certCount=(int)certs.size();
		certArray=(NETCA_PKI_CERTIFICATE_HANDLE *)NetcaPKICryptoAllocMemory(sizeof(NETCA_PKI_CERTIFICATE_HANDLE)*certCount);
		if(certArray==0)
		{
			throw CPKIException("alloc fail");
		}
		for(int i=0;i<certCount;i++)
		{
			certArray[i]=certs[i].handle();
		}
		int rv;
		rv=NetcaPKIMsgSignedDataSetCertificateValues(m_hSignedData,index,certArray,certCount);
		NetcaPKICryptoFreeMemory(certArray);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set CertificateValues fail");
		}
	}

	void CSignedData::setRevocationValues(int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataSetRevocationValues(m_hSignedData,index,crls,crlsLen,crlCount,ocsps,ocspsLen,ocspCount);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set RevocationValues fail");
		}
	}
	void CSignedData::setContentTimeStamp(int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataSetContentTimeStamp(m_hSignedData,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set ContentTimeStamp fail");
		}
	}

	void CSignedData::setContentTimeStamp(int index,int hashAlgo,const std::string& tsaName)
	{
		setContentTimeStamp(index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::attachSignatureTimeStamp(int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAttachSignatureTimeStamp(m_hSignedData,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"attach SignatureTimeStamp fail");
		}
	}

	void CSignedData::attachSignatureTimeStamp(int index,int hashAlgo,const std::string& tsaName)
	{
		attachSignatureTimeStamp(index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::addEscTimeStamp(int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAddEscTimeStamp(m_hSignedData,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"Add EscTimeStamp fail");
		}
	}

	void CSignedData::addEscTimeStamp(int index,int hashAlgo,const std::string& tsaName)
	{
		addEscTimeStamp(index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::addCertCRLTimeStamp(int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAddCertCRLTimeStamp(m_hSignedData,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"Add CertCRLTimeStamp fail");
		}
	}

	void CSignedData::addCertCRLTimeStamp(int index,int hashAlgo,const std::string& tsaName)
	{
		addCertCRLTimeStamp(index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::addArchiveTimeStampV2(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAddArchiveTimeStampV2(m_hSignedData,tbs,tbsLen,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"Add ArchiveTimeStampV2 fail");
		}
	}

	void CSignedData::addArchiveTimeStampV2(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const std::string& tsaName)
	{
		addArchiveTimeStampV2(tbs,tbsLen,index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::addArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAddArchiveTimeStampV3(m_hSignedData,tbs,tbsLen,index,hashAlgo,tsaName);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"Add ArchiveTimeStampV3 fail");
		}
	}

	void CSignedData::addArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const std::string& tsaName)
	{
		addArchiveTimeStampV3(tbs,tbsLen,index,hashAlgo,tsaName.c_str());
	}

	void CSignedData::attachATSHashIndex(int index,int hashAlgo)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAttachATSHashIndex(m_hSignedData,index,hashAlgo);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"attach ATSHashIndex fail");
		}
	}

	void CSignedData::GetCRLs(unsigned char ***crls, int **crlLen,int* count)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataGetCRLs(m_hSignedData,crls,crlLen,count);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get crls fail");
		}
	}

	void CSignedData::addRootCert(const CCertificate& cert)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataAddRootCert(m_hSignedData,cert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata add root cert for verify fail");
		}
	}

	void CSignedData::setSigningCertificateAttribute(int index,int hashAlgo,bool includeIssuerSerial,const std::vector<CCertificate>certs,const unsigned char *policies,int policiesLen)
	{
		NETCA_PKI_CERTIFICATE_HANDLE *certArray;
		int certCount=(int)certs.size();
		certArray=(NETCA_PKI_CERTIFICATE_HANDLE *)NetcaPKICryptoAllocMemory(sizeof(NETCA_PKI_CERTIFICATE_HANDLE)*certCount);
		if(certArray==0)
		{
			throw CPKIException("alloc fail");
		}
		for(int i=0;i<certCount;i++)
		{
			certArray[i]=certs[i].handle();
		}
		int rv;
		rv=NetcaPKIMsgSignedDataSetSigningCertificateAttribute(m_hSignedData,index,hashAlgo,
			includeIssuerSerial?1:0,certArray,certCount,policies,policiesLen);
		NetcaPKICryptoFreeMemory(certArray);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set SigningCertificateAttribute fail");
		}
	}

	void CSignedData::setSigningCertificateAttribute(int index,int hashAlgo,bool includeIssuerSerial,const std::vector<CCertificate>certs)
	{
		setSigningCertificateAttribute(index,hashAlgo,includeIssuerSerial,certs,0,0);
	}

	void CSignedData::getUnsignedAttributeInATSHashIndex(int index,int **attrIndex,char ***attrType,unsigned char ***attrValue,int **attrValueLen,int *attrCount)
	{
		int rv;
		rv=NetcaPKIMsgSignedDataGetUnsignedAttributeInATSHashIndex(m_hSignedData,index,attrIndex,attrType,attrValue,attrValueLen,attrCount);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"signeddata get UnsignedAttributeInATSHashIndex fail");
		}
	}

	bool CSignedData::MaybeSignedData(const unsigned char *data,int dataLen,bool &detached)
	{
		int rv;
		int value;
		rv=NetcaPKIMsgSignedDataMaybe(data,dataLen,&value);
		if(rv)
		{
			detached=(value!=0);
			return true;
		}
		else
		{
			return false;
		}

	}
	CTimeStamp CSignedData::verifyTimestampToken(const unsigned char *token,int tokenLen)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgVerifyTimeStampTokenBySignedDataHandle(token,tokenLen,
			m_hSignedData,&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify timestamp token fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}
	
	CCertVerify CSignedData::getCertVerify(int index)
	{
		NETCA_PKI_CERT_VERIFY_HANDLE hVerify= NetcaPKIMsgSignedDataGetVerifyHandle(m_hSignedData,index);
		if(hVerify==0)
		{
			throw CPKIException("get cert verify handle fail");
		}

		try
		{
			CCertVerify verify(hVerify);
			NetcaPKICertFreeVerify(hVerify);
			hVerify=0;
			return verify;
		}
		catch(std::exception&)
		{
			NetcaPKICertFreeVerify(hVerify);
			throw;
		}
	}

	void CSignedData::setGetCertCallback(NetcaSignedDataGetCertCallback_Ptr callback,void *context)
	{
		int rv=NetcaPKIMsgSignedDataSetGetCertCallback(m_hSignedData,callback,context);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set GetCertCallback fail");
		}
	}

	CTimeStamp CSignedData::verifyArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int tsIndex,const CCertificate &tsaCert)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3(m_hSignedData,
			tbs,tbsLen,index,tsIndex,tsaCert.handle(),&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify ArchiveTimeStampV3 fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	CTimeStamp CSignedData::verifyArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int tsIndex)
	{
		return verifyArchiveTimeStampV3(tbs,tbsLen,index,tsIndex,CCertificate());
	}

	CTimeStamp CSignedData::verifyArchiveTimeStampV2(const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,const CCertificate &tsaCert)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgSignedDataVerifyArchiveTimeStampV2(m_hSignedData,
			signedData,signedDataLen,tbs,tbsLen,index,tsIndex,tsaCert.handle(),&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify ArchiveTimeStampV2 fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	CTimeStamp CSignedData::verifyArchiveTimeStampV2(const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex)
	{
		return verifyArchiveTimeStampV2(signedData,signedDataLen,tbs,tbsLen,index,tsIndex,CCertificate());
	}

	CTimeStamp CSignedData::verifyCertCRLTimeStamp(int index,int tsIndex,const CCertificate &tsaCert)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgSignedDataVerifyCertCRLTimeStamp(m_hSignedData,
			index,tsIndex,tsaCert.handle(),&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify CertCRLTimeStamp fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	CTimeStamp CSignedData::verifyCertCRLTimeStamp(int index,int tsIndex)
	{
		return verifyCertCRLTimeStamp(index,tsIndex,CCertificate());
	}

	CTimeStamp CSignedData::verifyEscTimeStamp(int index,int tsIndex,const CCertificate &tsaCert)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgSignedDataVerifyEscTimeStamp(m_hSignedData,
			index,tsIndex,tsaCert.handle(),&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify EscTimeStamp fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	CTimeStamp CSignedData::verifyEscTimeStamp(int index,int tsIndex)
	{
		return verifyEscTimeStamp(index,tsIndex,CCertificate());
	}

	CTimeStamp CSignedData::verifyContentTimeStamp(int index,const CCertificate &tsaCert)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		int rv=NetcaPKIMsgSignedDataVerifyContentTimeStamp(m_hSignedData,
			index,tsaCert.handle(),&hTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"verify ContentTimeStamp fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	CTimeStamp CSignedData::verifyContentTimeStamp(int index)
	{
		return verifyContentTimeStamp(index,CCertificate());
	}

	CTimeStamp CSignedData::getSignatureTimeStamp(int index)
	{
		NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
		hTimeStamp=NetcaPKIMsgSignedDataGetTimeStampHandle(m_hSignedData,index);
		if(hTimeStamp==0)
		{
			throw CPKIException("get SignatureTimeStamp handle fail");
		}
		try
		{
			CTimeStamp timestamp(hTimeStamp);
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			hTimeStamp=0;
			return timestamp;
		}
		catch(std::exception&)
		{
			NetcaPKIMsgFreeTimeStamp(hTimeStamp);
			throw;
		}
	}

	void CSignedData::getSignatureValue(int index,CBlob& data)
	{
		int rv;
		
		char* value;
		rv = NetcaPKIMsgSignedDataGetStringAttribute(m_hSignedData, NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNATURE_VALUE, index, &value);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get signature value fail");
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

	void CSignedData::setUseQ7(bool value,int index)
	{
		setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SM2_Q7, -1, value?1:0);
		setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SM2SIGN_OID,index, value?1:0);
	}


}
