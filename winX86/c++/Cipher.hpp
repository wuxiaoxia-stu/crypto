#ifndef NETCA_CIPHER_INCLUDE_HPP
#define NETCA_CIPHER_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"

namespace Netca
{
	class CDevice;

	class CCipher
	{
	public:
		CCipher(bool enc,int algo);
		~CCipher();
		
		int algorithm() const  { return m_algo; }
		int padding() const  { return m_padding; }
		void padding(int value) { m_padding=value;}

		void getKey(CBlob& key)const;
		void setKey(const unsigned char *key,int keyLen);

		void getIV(CBlob& iv)const;
		void setIV(const unsigned char *iv,int ivLen);

		void setCtrParam(int bitCount,const unsigned char *iv,int ivLen);

		void setCcmParam(int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen, long long p);
		void setCcmParam(int tLen, const unsigned char *nonce,int nonceLen,long long p);

		void setGcmParam(int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen);
		void setGcmParam(int tLen, const unsigned char *iv,int ivLen);

		void setZucParam(int count, int bearer, bool direction);

		void setTweak(const unsigned char *tweak,int tweakLen);

		void setEffectiveKeyBits(int length);

		void init(const CDevice &device);
		void init();
		void update(const unsigned char *inData,int inDataLen,CBlob& outData);
		void final(CBlob& outData);
		void cipher(const unsigned char *inData,int inDataLen,CBlob& outData);


		static void RC4(bool enc,const unsigned char *key,int keyLen,const unsigned char *in,int inLen,CBlob& outData);
		static void RC2Ecb(bool enc,const unsigned char *key,int keyLen,int effectiveKeyBits,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void RC2Cbc(bool enc,const unsigned char *key,int keyLen,int effectiveKeyBits,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void Ecb(bool enc,int algo,const unsigned char *key,int keyLen,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void Ecb(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void Cbc(bool enc,int algo,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void Cbc(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData);
		static void Ctr(bool enc,int algo,const unsigned char *key,int keyLen,int bitCount,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Ctr(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int bitCount,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Ccm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Ccm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Ccm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Ccm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Gcm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Gcm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Gcm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Gcm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData);
		static void AesXts(bool enc,const unsigned char *key,int keyLen,const unsigned char *tweak,int tweakLen,const unsigned char *in,int inLen,CBlob& outData);
		static void Zuc(bool enc,const unsigned char *key,int keyLen,int count, int bearer, bool direction,const unsigned char *in,int inLen,CBlob& outData);
		static void Zuc(bool enc,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData);

	private:
		CCipher(const CCipher&);
		CCipher& operator =(const CCipher&);


		void init(const CDevice *device);

		NETCA_PKI_CIPHER_HANDLE m_hCipher;
		int m_algo;
        int m_padding;
        bool m_enc;
        CBlob m_key;
        CBlob m_iv;
		CBlob m_tweak;
        int m_effectiveKeyLength;
        struct NETCA_PKI_CTRParam_st m_ctrParam;
        bool m_hasCtrParam;
		struct NETCA_PKI_CCMParam_st m_ccmParam;
		bool m_hasCcmParam;
		struct NETCA_PKI_GCMParam_st m_gcmParam;
		bool m_hasGcmParam;
		struct NETCA_PKI_ZUCParam_st m_zucParam;
		bool m_hasZucParam;


	};
};

#endif
