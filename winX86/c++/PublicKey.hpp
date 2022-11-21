#ifndef NETCA_PUBLICKEY_INCLUDE_HPP
#define NETCA_PUBLICKEY_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"

namespace Netca
{
	class CPublicKey
	{
	public:
		CPublicKey();
		CPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);
		~CPublicKey();
		CPublicKey(const CPublicKey& pubkey);
		CPublicKey& operator =(const CPublicKey& pubkey);
		
		bool isNull() const { return m_hPublicKey==0; }
		int algorithm() const;
		int bits() const;
		int eccCurve() const;

		void getEncoded(CBlob& blob)const;
		void getSubjectPublicKeyInfoEncoded(CBlob& blob)const;

		void encrypt(int algo,const unsigned char *clear,int clearLen,CBlob& cipher);

		bool verifyHash(int algo,const unsigned char *hash,int hashLen,const unsigned char *signature,int signatureLen);
		bool verifyHash(int algo,const CBlob &hash,const unsigned char *signature,int signatureLen);

		void computeSM2Z(int hashAlgo,const unsigned char *id,int idLen,CBlob& z);
		void computeSM2Z(CBlob& z);
	private:
		void init(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);
	
		friend class CSignature;
		friend bool operator==(const CPublicKey& pubkey1,const CPublicKey& pubkey2);
		NETCA_PKI_PUBLICKEY_HANDLE handle()const { return m_hPublicKey;}

		NETCA_PKI_PUBLICKEY_HANDLE m_hPublicKey;
	};

	bool operator==(const CPublicKey& pubkey1,const CPublicKey& pubkey2);
};

#endif
