#ifndef NETCA_KEYPAIR_INCLUDE_HPP
#define NETCA_KEYPAIR_INCLUDE_HPP

#include <string>
#include <vector>

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"

namespace Netca
{
	class CPublicKey;
	class CCertificate;
	class CDevice;

	class CKeypair
	{
	public:
		CKeypair();
		CKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);
		~CKeypair();
		CKeypair(const CKeypair& keypair);
		CKeypair& operator =(const CKeypair& keypair);
		
		
		static CKeypair FindKeyPair(int deviceType, const char *deviceSn, int flag,const char * pwd,int keypairType, const char * label);
		static CKeypair FindKeyPair(int deviceType, const std::string &deviceSn, int flag,const char * pwd,int keypairType, const std::string &label);

		bool isNull() const { return m_hKeypair==0; }
		int type() const;
		std::string label()const;
		int algorithm() const;
		int bits() const;
		int eccCurve() const;
		bool isTemporaryKeypair()const;

		bool exportKeypair(CBlob& data)const;
		void deleteKeypair();

		CDevice device()const;

		CPublicKey getPublicKey() const;
		
		void decrypt(int algo,const unsigned char *cipher,int cipherLen,CBlob& clear);

		void signHash(int algo,const unsigned char *hash,int hashLen,CBlob& signature);
		void signHash(int algo,const CBlob &hash,CBlob& signature);

		std::vector<CCertificate> certs()const;
		
		int certCount()const;
		void deleteCert(int index);

		void updateCert(const CCertificate& cert);
		void addCert(const CCertificate& cert);
#ifdef _WIN32
		bool getMSProvInfo(PCRYPT_KEY_PROV_INFO pinfo);
#endif
	private:
		void init(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

		friend class CSignature;
		friend class CCertReq;
		friend class CCertificate;
		NETCA_PKI_KEYPAIR_HANDLE handle() const { return m_hKeypair;}

		NETCA_PKI_KEYPAIR_HANDLE m_hKeypair;
	};

};


#endif
