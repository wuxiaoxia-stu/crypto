#ifndef NETCA_SIGNATURE_INCLUDE_HPP
#define NETCA_SIGNATURE_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"

#include "Blob.hpp"

namespace Netca
{
	class CPublicKey;
	class CKeypair;

	class CSignature
	{
	public:
		CSignature(const CPublicKey& pubkey,int algo);
		CSignature(const CKeypair& keypair,int algo);
		~CSignature();
		
		void update(const unsigned char *data,int dataLen);
		void sign(CBlob& blob);
		bool verify(const unsigned char *signature,int signatureLen);

		static void Sign(const CKeypair& keypair,int algo,const unsigned char *data,int dataLen,CBlob& outData);
		static bool Verify(const CPublicKey& pubkey,int algo,const unsigned char *data,int dataLen,const unsigned char *signature,int signatureLen);

	private:

		CSignature(const CSignature&);
		CSignature& operator =(const CSignature&);

		NETCA_PKI_SIGN_HANDLE m_hSign;
		NETCA_PKI_DEVICE_VERIFY_HANDLE m_hVerify;
		bool m_forSign;

	};

};

#endif

