#ifndef NETCA_SIGNEDDATA_INCLUDE_HPP
#define NETCA_SIGNEDDATA_INCLUDE_HPP

#include "NETCA_PKI_Application.h"
#include "Blob.hpp"
#include <string>
#include <vector>

namespace Netca
{
	class CCertificate;
	class CDevice;
	class CTimeStamp;
	class CCertVerify;
	
	class CSignedData
	{
	public:
		explicit CSignedData(bool sign);
		CSignedData(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);
		~CSignedData();

		void setIntegerAttribute(int atrrId, int index, int value);
		void setStringAttribute(int atrrId, int index, const char* value);
		void setStringAttribute(int atrrId, int index, const std::string& value);
		void setSignCert(const CCertificate& cert, const char *pwd=0);
		void setEncCert(int index, int flag, const CCertificate& cert);
		void addCert(const CCertificate& cert);
		void addCRL(const unsigned char *crl, int crlLen);
		void addOCSP(const CCertificate& vaCert,const unsigned char *ocsp,int ocspLen);
		void addOCSP(const unsigned char *ocsp,int ocspLen);
		void setDevice(const CDevice& device);
		void addSignedAttribute(int index, const char *attrType, const unsigned char *attrValue, int attrValueLen);
		void addSignedAttribute(int index, const std::string& attrType, const unsigned char *attrValue, int attrValueLen);
		void addUnsignedAttribute(int index, const char *attrType, const unsigned char *attrValue, int attrValueLen);
		void addUnsignedAttribute(int index, const std::string& attrType, const unsigned char *attrValue, int attrValueLen);
		
		void setCompleteCertificateRefs(int index,int hashAlgo,bool hasIssuerSN,const std::vector<CCertificate>& certs);
		void addCompleteRevocationRef(int index,bool last,int flag,int hashAlgo,const unsigned char *crlData,int crlDataLen,const unsigned char *ocsp,int ocspLen);
		void addCRLRef(int index,bool last,bool useCrlId,int hashAlgo,const unsigned char *crlData,int crlDataLen);
		void addOCSPRef(int index,bool last,bool useOcspRespHash,int hashAlgo,const unsigned char *ocsp,int ocspLen);
		void setCertificateValues(int index,const std::vector<CCertificate>& certs);
		void setRevocationValues(int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount);

		void encode(CBlob& outData);
		void sign(const unsigned char *inData, int inDataLen, CBlob& outData);
		void coSign(CBlob& outData);
		void countersign(int index, int algo, const CCertificate& cert, const char *pwd, CBlob& outData);
		void countersign(int index, int algo, const CCertificate& cert, CBlob& outData);
		void signWithTimeStamp(const char *tsaName, const unsigned char *inData, int inDataLen, CBlob& outData);
		void signWithTimeStamp(const std::string& tsaName, const unsigned char *inData, int inDataLen, CBlob& outData);
		void signInit(CBlob& outData);
		void signUpdate(const unsigned char *inData, int inDataLen, CBlob& outData);
		void signFinal(CBlob& outData);
		void signWithTimeStampFinal(const char *tsaName, CBlob& outData);
		void signWithTimeStampFinal(const std::string& tsaName, CBlob& outData);
		
		std::vector<CCertificate> getCerts();
		int verify(const unsigned char *inData, int inDataLen, CBlob& outData);
		bool verifySignatureTimeStamp(int index, const CCertificate &tsaCert);
		bool verifySignatureTimeStamp(int index);
		bool verifyCountersignature(int index, int countersignIndex, const CCertificate& cert);
		bool verifyCountersignature(int index, int countersignIndex);
		void verifyInit();
		void verifyUpdate(const unsigned char *inData, int inDataLen, CBlob& outData);
		int verifyFinal();
		void detachedVerifyInit(const unsigned char *sign, int signLen);
		void detachedVerifyUpdate(const unsigned char *inData, int inDataLen);
		int detachedVerifyFinal();
		int detachedVerifyHash(int index, const unsigned char *hash, int hashLen);
		int detachedVerify(const unsigned char *tbs, int tbsLen, const unsigned char *sign, int signLen);


		int getIntegerAttribute(int atrrId, int index);
		std::string getStringAttribute(int atrrId, int index);
		void getSignedAttribute(int index, int attrIndex, std::string& attrType, CBlob& attrValue);
		void getUnsignedAttribute(int index, int attrIndex, std::string& attrType, CBlob& attrValue);
		CCertificate getSignCert(int index=0);
		CCertificate getEncCert(int index = 0);
		CCertificate getSignatureTimeStampCert(int index = 0);
		CCertificate getCountersignatureCert(int index, int countersignIndex);

		int getSignerCount() { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_COUNT,-1); }

		bool isDetached() { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_DETACHED,-1)!=0; }
		void setDetached(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_DETACHED, -1, value?1:0); }
		
		int getSignAlgo(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGN_ALGO,index); }
		void setSignAlgo(int algo,int index=0) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGN_ALGO, index, algo); }
		
		bool hasSigningTime(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGTIME,index)!=0; }
		void setUseSigningTime(bool value,int index=0) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGTIME, index, value?1:0); }
		
		bool isContentInfo() { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_CONTENT_INFO,-1)!=0; }
		
		void setUseContentInfo(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_CONTENT_INFO, -1, value?1:0); }
		
		bool useSubjectKeyId(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_KEYID,index)!=0; }
		void setUseSubjectKeyId(bool value,int index=0) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_KEYID, index, value?1:0); }
		
		void setIncludeCertOption(int option) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_INCLUDE_CERT_OPTION, -1, option); }
		
		void setKeepTbs(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_KEEP_TBS, -1, value?1:0); }
		
		bool hasSigningCertAttribute(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGCERT,index)!=0; }
		void setUseSigningCertAttribute(bool value,int index=0) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGCERT, index, value?1:0); }

		int getSigningCertV2HashAlgo(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNINGCERTV2_HASH_ALGO,index); }
		int setSigningCertV2HashAlgo(int algo,int index=0) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNINGCERTV2_HASH_ALGO, index, algo); }

		std::string getSigningTimeString(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNINGTIME,index); }
			
		std::string getContentInfoOid() { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_OID,-1); }
		void setContentInfoOid(const char *oid) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_OID, -1,oid); }
		void setContentInfoOid(const std::string& oid) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_OID, -1,oid); }
		
		void setVerifyValidity(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_VALIDITY, -1, value?1:0); }
		
		bool hasSignatureTimeStamp(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_TSATIME,index)!=0; }
		std::string getSignatureTimeStampTimeString(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_TSATIME,index); }
		std::string getSignatureTimeStampSerialNumber(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_TIMESTAMP_SERIAL_NUMBER,index); }
		int getSignatureTimeStampHashAlgo(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_TIMESTAMP_HASH_ALGO,index); }
		std::string getSignatureTimeStampPolicy(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_TIMESTAMP_POLICY,index); }

		int getCounterSignatureCount(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COUNTERSIGNATURE_COUNT,index); }

		int getSignedAttributeCount(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNEDATTRS_COUNT,index); }
		int getUnsignedAttributeCount(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_UNSIGNEDATTRS_COUNT,index); }

		void getSignatureValue(int index,CBlob& value);

		void setUseQ7(bool value,int index=0);

		void setUsePkcs7(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_PKCS7, -1, value?1:0); }

		void setVerifyRSANoHashIdSignature(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_NOHASHID_SIGNATURE, -1, value?1:0); }

		std::string getSmimeCapabilities(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SMIMECAPABILITIES,index); }
		void setSmimeCapabilities(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SMIMECAPABILITIES, index,value); }
		void setSmimeCapabilities(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SMIMECAPABILITIES, index,value); }
		
		std::string getContentHints(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_HINTS,index); }
		void setContentHints(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_HINTS, index,value); }
		void setContentHints(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_HINTS, index,value); }
		
		std::string getContentId(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_IDENTIFIER,index); }
		void setContentId(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_IDENTIFIER, index,value); }
		void setContentId(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_IDENTIFIER, index,value); }

		std::string getContentReference(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_REFERENCE,index); }
		void setContentReference(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_REFERENCE, index,value); }
		void setContentReference(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CONTENT_REFERENCE, index,value); }

		std::string getCommitmentTypeIndication(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COMMITMENT_TYPE_INDICATION,index); }
		void setCommitmentTypeIndication(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COMMITMENT_TYPE_INDICATION, index,value); }
		void setCommitmentTypeIndication(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COMMITMENT_TYPE_INDICATION, index,value); }

		std::string getSignerLocation(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_LOCATION,index); }
		void setSignerLocation(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_LOCATION, index,value); }
		void setSignerLocation(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_LOCATION, index,value); }

		std::string getMimeType(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_MIME_TYPE,index); }
		void setMimeType(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_MIME_TYPE, index,value); }
		void setMimeType(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_MIME_TYPE, index,value); }

		std::string getSignaturePolicyId(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNATURE_POLICYID,index); }
		void setSignaturePolicyId(const char *value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNATURE_POLICYID, index,value); }
		void setSignaturePolicyId(const std::string& value,int index=0) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNATURE_POLICYID, index,value); }

		
		bool hasCompleteCertificateRefs(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_COMPLETE_CERTIFICATE_REFS,index)!=0; }
		int verifyCompleteCertificateRefs(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CHECK_COMPLETE_CERT_REFS,index); }
		std::string getCompleteCertificateRefs(int index) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COMPLETE_CERTIFICATE_REFS,index); }

		bool hasCompleteRevocationRefs(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_COMPLETE_REVOCATION_REFS,index)!=0; }
		int verifyCompleteRevocationRefs(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CHECK_COMPLETE_REVOCATION_REFS,index); }
		std::string getCompleteRevocationRefs(int index) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_COMPLETE_REVOCATION_REFS,index); }

		bool hasCertificateValues(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_CERT_VALUES,index)!=0; }
		int verifyCertificateValues(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CHECK_CERT_VALUES,index); }
		

		bool hasRevocationValues(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_REVOCATION_VALUES,index)!=0; }
		int verifyRevocationValues(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CHECK_REVOCATION_VALUES,index); }

		void setUseSystemCertStoreForVerify(bool value) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SYSTEM_CERTSTORE_VERIFY, -1, value?1:0); }
		void setVerifyLevel(int level) { setIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_LEVEL, -1, level); }
		void setVerifyParam(const char *value) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_PARAM, -1,value); }
		void setVerifyParam(const std::string& value) { setStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_PARAM, -1,value); }

		int getVerifyResult(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFY_RESULT,index); }
		int getVerifyCertResult(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFYCERT_RESULT,index); }
		int getVerifyCertStatus(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFYCERT_STATUS,index); }
		int getVerifyCertRevokeReason(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFYCERT_REVOKE_REASON,index); }
		std::string getVerifyCertRevokeTimeString(int index) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_VERIFYCERT_REVOKE_TIME,index); }


		std::string getSigningCertAttribute(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNINGCERT_ATTRIBUTE,index); }
		std::string getSigningCertV2Attribute(int index=0) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNINGCERTV2_ATTRIBUTE,index); }

		int getEscTimeStampCount(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_ESC_TIMESTAMP_COUNT,index); }

		int getCertCRLTimeStampCount(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_CERTCRL_TIMESTAMP_COUNT,index); }

		int getArchiveTimeStampV2Count(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_ARCHIVE_TIMESTAMP_V2_COUNT,index); }

		int getArchiveTimeStampV3Count(int index) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_ARCHIVE_TIMESTAMP_V3_COUNT,index); }
		
		bool hasATSHashIndex(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_ATS_HASH_INDEX,index)!=0; }
		std::string getATSHashIndex(int index) { return getStringAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_ATS_HASH_INDEX,index); }

		void setContentTimeStamp(int index,int hashAlgo,const char *tsaName);
		void setContentTimeStamp(int index,int hashAlgo,const std::string& tsaName);
		void attachSignatureTimeStamp(int index,int hashAlgo,const char *tsaName);
		void attachSignatureTimeStamp(int index,int hashAlgo,const std::string& tsaName);
		void addEscTimeStamp(int index,int hashAlgo,const char *tsaName);
		void addEscTimeStamp(int index,int hashAlgo,const std::string& tsaName);
		void addCertCRLTimeStamp(int index,int hashAlgo,const char *tsaName);
		void addCertCRLTimeStamp(int index,int hashAlgo,const std::string& tsaName);
		void addArchiveTimeStampV2(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);
		void addArchiveTimeStampV2(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const std::string& tsaName);
		void addArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);
		void addArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const std::string& tsaName);
		void attachATSHashIndex(int index,int hashAlgo);


		void GetCRLs(unsigned char ***crls, int **crlLen,int* count);

		void addRootCert(const CCertificate& cert);

		void setSigningCertificateAttribute(int index,int hashAlgo,bool includeIssuerSerial,const std::vector<CCertificate>certs,const unsigned char *policies,int policiesLen);
		void setSigningCertificateAttribute(int index,int hashAlgo,bool includeIssuerSerial,const std::vector<CCertificate>certs);

		void getUnsignedAttributeInATSHashIndex(int index,int **attrIndex,char ***attrType,unsigned char ***attrValue,int **attrValueLen,int *attrCount);

		CTimeStamp verifyTimestampToken(const unsigned char *token,int tokenLen);

		CCertVerify getCertVerify(int index=0);

		static bool MaybeSignedData(const unsigned char *data,int dataLen,bool &detached);

		void setGetCertCallback(NetcaSignedDataGetCertCallback_Ptr callback,void *context);

		CTimeStamp verifyArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int tsIndex,const CCertificate &tsaCert);
		CTimeStamp verifyArchiveTimeStampV3(const unsigned char *tbs,long long tbsLen,int index,int tsIndex);

		CTimeStamp verifyArchiveTimeStampV2(const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,const CCertificate &tsaCert);
		CTimeStamp verifyArchiveTimeStampV2(const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex);
		
		CTimeStamp verifyCertCRLTimeStamp(int index,int tsIndex,const CCertificate &tsaCert);
		CTimeStamp verifyCertCRLTimeStamp(int index,int tsIndex);

		CTimeStamp verifyEscTimeStamp(int index,int tsIndex,const CCertificate &tsaCert);
		CTimeStamp verifyEscTimeStamp(int index,int tsIndex);

		bool hasContentTimeStamp(int index=0) { return getIntegerAttribute(NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_CONTENT_TIMESTAMP,index)!=0; }
		CTimeStamp verifyContentTimeStamp(int index,const CCertificate &tsaCert);
		CTimeStamp verifyContentTimeStamp(int index);

		CTimeStamp getSignatureTimeStamp(int index=0);


	private:
		CSignedData(const CSignedData& signedData);
		CSignedData& operator =(const CSignedData&);

		friend class CMime;
		friend class CTimeStamp;
		NETCA_PKI_SIGNEDDATA_HANDLE handle() const  { return m_hSignedData;}

		NETCA_PKI_SIGNEDDATA_HANDLE m_hSignedData;
	};

};

#endif

