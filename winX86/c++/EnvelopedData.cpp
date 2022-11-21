#include "EnvelopedData.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "Device.hpp"
#include "Store.hpp"

namespace Netca
{
	CEnvelopedData::CEnvelopedData(bool encrypt)
	{
		m_hEnvelopedData = NetcaPKIMsgNewEnvelopedData(encrypt);
		if (m_hEnvelopedData == 0)
		{
			throw CPKIException("new enveloped data handle fail");
		}
	}

	CEnvelopedData::~CEnvelopedData()
	{
		NetcaPKIMsgFreeEnvelopedData(m_hEnvelopedData);
	}

	void CEnvelopedData::setEncAlgorithm(int encAlgo)
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataSetEncAlgorithm(m_hEnvelopedData, encAlgo);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set encrypt algorithm fail");
		}
	}

	void CEnvelopedData::addCert(const CCertificate &cert, int flag )
	{
		int rv;
		if (cert.isNull())
		{
			throw CPKIException("cert is null");
		}
		rv = NetcaPKIMsgEnvelopedDataAddCert(m_hEnvelopedData, cert.handle(), flag);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data add cert fail");
		}

	}

	void CEnvelopedData::setDevice(const CDevice &device)
	{
		if (device.isNull())
		{
			throw CPKIException("device is null");
		}
		int rv = NetcaPKIMsgEnvelopedDataSetCryptoHandle(m_hEnvelopedData, device.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set device fail");
		}
	}

	void CEnvelopedData::setUseContentInfo(bool value)
	{
		int rv = NetcaPKIMsgEnvelopedDataSetIntegerAttribute(m_hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_HAS_CONTENT_INFO,value?1:0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set use contentinfo fail");
		}
	}

	void CEnvelopedData::setUseQ7(bool useQ7,bool useV1)
	{
		int rv = NetcaPKIMsgEnvelopedDataSetIntegerAttribute(m_hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_USE_SM2_Q7,useQ7?1:0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set use q7 fail");
		}

		if(useQ7)
		{
			rv = NetcaPKIMsgEnvelopedDataSetIntegerAttribute(m_hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_USE_SM2_Q7_VERSION1,useV1?1:0);
			if (rv != NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"enveloped data set use q7 version 1 fail");
			}
		}
	}

	void CEnvelopedData::setUseRfc3278(bool value)
	{
		int rv = NetcaPKIMsgEnvelopedDataSetIntegerAttribute(m_hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_USE_RFC3278,value?1:0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set use rfc3278 fail");
		}
	}

	void CEnvelopedData::setUseUkm(bool value)
	{
		int rv = NetcaPKIMsgEnvelopedDataSetIntegerAttribute(m_hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_USE_UKM,value?1:0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set use ukm fail");
		}
	}

	void CEnvelopedData::encryptInit(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataEncryptInit(m_hEnvelopedData,&data,&dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data encrypt init fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::encryptUpdate(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataEncryptUpdate(m_hEnvelopedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data encrypt update fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::encryptFinal(CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataEncryptFinal(m_hEnvelopedData, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data encrypt final fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::encrypt(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataEncrypt(m_hEnvelopedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data encrypt fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::addStore(const CStore& store)
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataAddStore(m_hEnvelopedData, store.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data add store fail");
		}
	}

	void CEnvelopedData::decrypt(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataDecrypt(m_hEnvelopedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data decrypt fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::decryptInit()
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataDecryptInit(m_hEnvelopedData);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data decrypt init fail");
		}
	}

	void CEnvelopedData::decryptUpdate(const unsigned char *inData, int inDataLen, CBlob& outData)
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgEnvelopedDataDecryptUpdate(m_hEnvelopedData, inData, inDataLen, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data decrypt update fail");
		}
		outData.attach(data, dataLen);
	}

	void CEnvelopedData::decryptFinal()
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataDecryptFinal(m_hEnvelopedData);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data decrypt final fail");
		}
	}

	void CEnvelopedData::setPwd(const char *pwd)
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataSetPwd(m_hEnvelopedData, pwd);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set pwd fail");
		}
	}

	void CEnvelopedData::setKey(const unsigned char *key, int keyLen)
	{
		int rv;
		rv = NetcaPKIMsgEnvelopedDataSetKey(m_hEnvelopedData, key, keyLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"enveloped data set key fail");
		}
	}

	int CEnvelopedData::getEncAlgorithm()
	{
		int algo;
		algo=NetcaPKIMsgEnvelopedDataGetEncAlgorithm(m_hEnvelopedData);
		if (algo < 0)
		{
			throw CPKIException("enveloped data get encrypt algorithm fail");
		}
		return algo;
	}

	CCertificate CEnvelopedData::getCert()
	{
		CCertificate certObj;
		NETCA_PKI_CERTIFICATE_HANDLE cert= NetcaPKIMsgEnvelopedDataGetCert(m_hEnvelopedData);
		if (cert == 0)
		{
			return certObj;
		}
		certObj.attach(cert);
		return certObj;
	}

	bool CEnvelopedData::isContentInfo()
	{
		return NetcaPKIMsgEnvelopedDataIsContentInfo(m_hEnvelopedData) != 0;
	}


}
