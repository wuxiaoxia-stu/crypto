#ifndef NETCA_STORE_INCLUDE_HPP
#define NETCA_STORE_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"
#include <string>
#include <vector>

namespace Netca
{
	class CCertificate;
	
	class CStore
	{
	public:
		CStore();
		CStore(int type,const char *name);
		CStore(int type,const std::string& name);
		~CStore();
		
		enum StoreEncodeType
		{
			STORE_ENCODE_TYPE_PFX=1,
			STORE_ENCODE_TYPE_P7C=2,
		};
		CStore(StoreEncodeType type,const CBlob& encode,const char *pwd);
		CStore(StoreEncodeType type,const CBlob& encode);

		void close();
			
		std::vector<CCertificate> getCerts()const;

		void addCert(const CCertificate& cert);
		void deleteCert(const CCertificate& cert);

		void exportP7c(CBlob& encode)const;

		static CStore LoadPfx(const unsigned char *data,int len,const char *pwd);
		static CStore LoadP7c(const unsigned char *data,int len);
		static CStore GetRootCerts();
		static CStore GetCACerts();

	private:
		CStore(const CStore& );
		CStore& operator =(const CStore& );
		CStore(NETCA_PKI_CERT_STORE store);

		friend void SetRootCert(int flag,const CStore& store);
		friend void SetCACert(int flag,const CStore& store);
		friend class CEnvelopedData;

		NETCA_PKI_CERT_STORE handle() const { return m_store;}
		NETCA_PKI_CERT_STORE m_store;
	};

	void SetRootCert(int flag,const CStore& store);
	void SetCACert(int flag,const CStore& store);
};

#endif

