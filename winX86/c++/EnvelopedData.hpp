#ifndef NETCA_ENVELOPEDDATA_INCLUDE_HPP
#define NETCA_ENVELOPEDDATA_INCLUDE_HPP

#include "NETCA_PKI_Application.h"
#include "Blob.hpp"
#include <vector>
namespace Netca
{
	class CCertificate;
	class CDevice;
	class CStore;

	class CEnvelopedData
	{
	public:
		explicit CEnvelopedData(bool encrypt);
		~CEnvelopedData();

		void setEncAlgorithm(int encAlgo);
		void addCert(const CCertificate &cert, int flag=0);
		void setDevice(const CDevice &device);
		void setUseContentInfo(bool value);
		void setUseQ7(bool useQ7,bool useV1=false);
		void setUseRfc3278(bool value);
		void setUseUkm(bool value);

		void encryptInit(CBlob& outData);
		void encryptUpdate(const unsigned char *inData, int inDataLen, CBlob& outData);
		void encryptFinal(CBlob& outData);
		void encrypt(const unsigned char *inData, int inDataLen, CBlob& outData);

		void addStore(const CStore& store);
		void decrypt(const unsigned char *inData, int inDataLen, CBlob& outData);
		void decryptInit();
		void decryptUpdate(const unsigned char *inData, int inDataLen, CBlob& outData);
		void decryptFinal();
		void setPwd(const char *pwd);
		void setKey(const unsigned char *key, int keyLen);

		int getEncAlgorithm();
		CCertificate getCert();
		bool isContentInfo();

		
	private:
		CEnvelopedData(const CEnvelopedData& );
		CEnvelopedData& operator =(const CEnvelopedData& );

		friend class CMime;
		NETCA_PKI_ENVELOPEDDATA_HANDLE handle() const { return m_hEnvelopedData;}

		NETCA_PKI_ENVELOPEDDATA_HANDLE m_hEnvelopedData;
	};

};

#endif

