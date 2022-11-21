#include "Cipher.hpp"
#include "PKIException.hpp"
#include "Device.hpp"
#include <limits.h>

namespace Netca
{
	CCipher::CCipher(bool enc,int algo)
	{
		m_enc=enc;
		m_algo=algo;
		m_hCipher=0;
		m_padding=NETCA_PKI_PADDING_NONE;
		m_effectiveKeyLength=-1;
		m_hasCtrParam=false;
		m_hCipher=0;
		m_hasCcmParam=false;
		m_hasGcmParam=false;
		m_hasZucParam=false;
	}

	CCipher::~CCipher()
	{
		m_key.clear();
		NetcaPKICryptoFreeCipher(m_hCipher);

		if(m_hasCcmParam)
		{
			NetcaPKICryptoFreeMemory(m_ccmParam.m_adata);
		}

		if(m_hasGcmParam)
		{
			NetcaPKICryptoFreeMemory(m_gcmParam.m_iv);
			NetcaPKICryptoFreeMemory(m_gcmParam.m_aad);
		}
	}

	void CCipher::getKey(CBlob& key)const
	{
		key.assign(m_key);
	}
	void CCipher::setKey(const unsigned char *key,int keyLen)
	{
		if(key==0)
		{
			throw CPKIException("key is null");
		}

		if (m_algo == NETCA_PKI_ALGORITHM_DES_ECB || m_algo == NETCA_PKI_ALGORITHM_DES_CBC)
        {
			if (keyLen != 8)
            {
				throw CPKIException("the key length of des is not 8");
            }
		}
        else if (m_algo == NETCA_PKI_ALGORITHM_3DES_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_3DES_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_3DES_CTR)
		{
			if (keyLen != 16 && keyLen != 24)
            {
				throw CPKIException("the key length of 3des is not 16,24");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_AES_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_AES_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_AES_CCM
			|| m_algo == NETCA_PKI_ALGORITHM_AES_GCM
			)
		{
			if (keyLen != 16 && keyLen != 24 && keyLen != 32)
            {
				throw CPKIException("the key length of aes is not 16,24,32");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SSF33_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SSF33_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SSF33_CTR)
		{
			if (keyLen != 16)
            {
				throw CPKIException("the key length of ssf33 is not 16");
            }
		}
        else if (m_algo == NETCA_PKI_ALGORITHM_SM1_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SM1_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SM1_CTR)
		{
			if (keyLen != 16 && keyLen != 32)
            {
				throw CPKIException("the key length of sm1 is not 16,32");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SM4_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CCM)
		{
			if (keyLen != 16)
            {
				throw CPKIException("the key length of sm4 is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_ZUC
			|| m_algo == NETCA_PKI_ALGORITHM_ZUC_BASE
			)
		{
			if (keyLen != 16)
            {
				throw CPKIException("the key length of zuc is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_XTS)
		{
			if (keyLen != 32 && keyLen != 64)
            {
				throw CPKIException("the key length of aes-xts is not 32,64");
            }
		}
		unsigned char *newKey=(unsigned char*)NetcaPKICryptoAllocMemory(keyLen);
		if(newKey==0)
		{
			throw CPKIException("alloc fail");
		}
		memcpy(newKey,key,keyLen);
		m_key.clear();
		m_key.attach(newKey,keyLen);
	}

	void CCipher::getIV(CBlob& iv)const
	{
		iv.assign(m_iv);
	}

	void CCipher::setIV(const unsigned char *iv,int ivLen)
	{
		if(iv==0)
		{
			throw CPKIException("iv is null");
		}

		if (m_algo == NETCA_PKI_ALGORITHM_DES_CBC)
        {
			if (ivLen != 8)
            {
				throw CPKIException("the iv length of des is not 8");
            }
		}
        else if (m_algo == NETCA_PKI_ALGORITHM_3DES_CBC)
		{
			if (ivLen != 8)
            {
				throw CPKIException("the iv length of 3des is not 8");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_CBC)
		{
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of aes is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SSF33_CBC)
		{
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of ssf33 is not 16");
            }
		}
        else if (m_algo == NETCA_PKI_ALGORITHM_SM1_CBC)
		{
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of sm1 is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SM4_CBC)
		{
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of sm4 is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_ZUC_BASE)
		{
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of zuc is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_RC2_CBC)
		{
			if (ivLen != 8)
            {
				throw CPKIException("the iv length of rc2 is not 8");
            }
		}
		else
		{
			throw CPKIException("not cbc mode");
		}
		m_iv.assign(iv,ivLen);
	}


	void CCipher::setCtrParam(int bitCount,const unsigned char *iv,int ivLen)
	{
		if(iv==0)
		{
			throw CPKIException("iv is null");
		}
		if(bitCount<=0)
		{
			throw CPKIException("bitCount<=0");
		}

		if(bitCount>ivLen*8)
		{
			throw CPKIException("bitCount >iv bits");
		}

		if (m_algo == NETCA_PKI_ALGORITHM_3DES_CTR)
        {
			if (ivLen != 8)
            {
				throw CPKIException("the iv length of 3des is not 8");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_CTR)
        {
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of aes is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SSF33_CTR)
        {
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of ssf33 is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SM1_CTR)
        {
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of sm1 is not 16");
            }
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_SM4_CTR)
        {
			if (ivLen != 16)
            {
				throw CPKIException("the iv length of sm4 is not 16");
            }
		}
		else
		{
			throw CPKIException("not ctr mode");
		}
		m_ctrParam.m_count_bits=bitCount;
		memcpy(m_ctrParam.m_iv,iv,ivLen);
		m_hasCtrParam=true;
	}

	void CCipher::setCcmParam(int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen, long long p)
	{
		if(nonce==0)
		{
			throw CPKIException("nonce is null");
		}

		if(nonceLen>NETCA_PKI_CRYPT_BLOCK_MAXLEN)
		{
			throw CPKIException("nonce too long");
		}

		if(aData==0 && aDataLen!=0)
		{
			throw CPKIException("bad aData");
		}
		if (m_algo != NETCA_PKI_ALGORITHM_AES_CCM
                && m_algo != NETCA_PKI_ALGORITHM_SM4_CCM)
		{
			throw CPKIException("not ccm mode");
		}
        
		m_ccmParam.m_tLen=tLen;
		m_ccmParam.m_nonceLen=nonceLen;
		memcpy(m_ccmParam.m_nonce,nonce,nonceLen);
		if(m_hasCcmParam)
		{
			NetcaPKICryptoFreeMemory(m_ccmParam.m_adata);
			m_ccmParam.m_adata=0;
		}
		if(aData)
		{
			
			m_ccmParam.m_adata=(unsigned char *)NetcaPKICryptoAllocMemory(aDataLen);
			if(m_ccmParam.m_adata==0)
			{
				throw CPKIException("alloc fail");
			}
			
			memcpy(m_ccmParam.m_adata,aData,aDataLen);
			m_ccmParam.m_adataLen=aDataLen;
		}
		else
		{
			m_ccmParam.m_adata=0;
			m_ccmParam.m_adataLen=0;
		}
		m_ccmParam.m_p=p;
		m_ccmParam.m_reserve=0;
		m_hasCcmParam=true;
	}

	void CCipher::setCcmParam(int tLen, const unsigned char *nonce,int nonceLen,long long p)
	{
		setCcmParam(tLen,nonce,nonceLen,0,0,p);
	}

	void CCipher::setGcmParam(int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen)
	{
		if(iv==0)
		{
			throw CPKIException("iv is null");
		}

		if(aad==0 && aadLen!=0)
		{
			throw CPKIException("bad aad");
		}

		if(m_algo != NETCA_PKI_ALGORITHM_AES_GCM)
		{
			throw CPKIException("not gcm mode");
		}

		m_gcmParam.m_tLen=tLen;
		if(m_hasGcmParam)
		{
			NetcaPKICryptoFreeMemory(m_gcmParam.m_iv);
			m_gcmParam.m_iv=0;
		}
		m_gcmParam.m_iv=(unsigned char *)NetcaPKICryptoAllocMemory(ivLen);
		if(m_gcmParam.m_iv==0)
		{
			throw CPKIException("alloc fail");
		}
			
		memcpy(m_gcmParam.m_iv,iv,ivLen);
		m_gcmParam.m_ivLen=ivLen;

		if(m_hasGcmParam)
		{
			NetcaPKICryptoFreeMemory(m_gcmParam.m_aad);
			m_gcmParam.m_aad=0;
		}

		if(aad)
		{
			m_gcmParam.m_aad=(unsigned char *)NetcaPKICryptoAllocMemory(aadLen);
			if(m_gcmParam.m_aad==0)
			{
				throw CPKIException("alloc fail");
			}
			memcpy(m_gcmParam.m_aad,aad,aadLen);
			m_gcmParam.m_aadLen=aadLen;
		}
		else
		{
			m_gcmParam.m_aad=0;
			m_gcmParam.m_aadLen=0;
		}
		m_hasGcmParam=true;
	}

	void CCipher::setGcmParam(int tLen, const unsigned char *iv,int ivLen)
	{
		setGcmParam(tLen,iv,ivLen,0,0);
	}

	void CCipher::setZucParam(int count, int bearer, bool direction)
	{
		if(m_algo != NETCA_PKI_ALGORITHM_ZUC)
		{
			throw CPKIException("not zuc");
		}
		m_zucParam.m_bearer=bearer;
		m_zucParam.m_count=count;
		m_zucParam.m_direction=direction?1:0;
		m_zucParam.m_unusedBits=0;
		m_hasZucParam=true;
	}

	void CCipher::setTweak(const unsigned char *tweak,int tweakLen)
	{
		if(tweak==0)
		{
			throw CPKIException("tweak is null");
		}
		if(m_algo != NETCA_PKI_ALGORITHM_AES_XTS)
		{
			throw CPKIException("not xts mode");
		}

		if(tweakLen!=16)
		{
			throw CPKIException("bad tweakLen");
		}
		m_tweak.assign(tweak,tweakLen);
	}

	void CCipher::setEffectiveKeyBits(int length)
	{
		if(m_algo != NETCA_PKI_ALGORITHM_RC2_ECB
			&& m_algo != NETCA_PKI_ALGORITHM_RC2_CBC)
		{
			throw CPKIException("not rc2");
		}
		m_effectiveKeyLength=length;
	}

	void CCipher::init(const CDevice *device)
	{
		if (m_hCipher != 0)
		{
			NetcaPKICryptoFreeCipher(m_hCipher);
			m_hCipher=0;
		}
        if (m_algo == NETCA_PKI_ALGORITHM_DES_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_3DES_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_ARC4
			|| m_algo == NETCA_PKI_ALGORITHM_AES_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SSF33_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SM1_ECB
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_ECB)
		{
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),0);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),0);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_DES_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_3DES_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_AES_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SSF33_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SM1_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CBC
			|| m_algo == NETCA_PKI_ALGORITHM_ZUC_BASE)
		{
			if(m_iv.length()<=0)
			{
				throw CPKIException("not iv");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),m_iv.data());
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),m_iv.data());
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_RC2_CBC)
		{
			if(m_effectiveKeyLength<=0)
			{
				throw CPKIException("not effective key length");
			}
			if(m_iv.length()<=0)
			{
				throw CPKIException("not iv");
			}
			struct NETCA_PKI_RC2CBCParam_st rc2Param;
			rc2Param.m_effective_keybits=m_effectiveKeyLength;
			memcpy(rc2Param.m_iv,m_iv.data(),8);
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&rc2Param);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&rc2Param);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_RC2_ECB)
		{
			if(m_effectiveKeyLength<=0)
			{
				throw CPKIException("not effective key length");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&m_effectiveKeyLength);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&m_effectiveKeyLength);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_3DES_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_AES_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_SSF33_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_SM1_CTR
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CTR)
		{
			if(m_hasCtrParam==false)
			{
				throw CPKIException("not ctr param");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&m_ctrParam);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&m_ctrParam);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_ZUC)
		{
			if(m_hasZucParam==false)
			{
				throw CPKIException("not zuc param");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&m_zucParam);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&m_zucParam);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_CCM
			|| m_algo == NETCA_PKI_ALGORITHM_SM4_CCM)
		{
			if(m_hasCcmParam==false)
			{
				throw CPKIException("not ccm param");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&m_ccmParam);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&m_ccmParam);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_GCM)
		{
			if(m_hasGcmParam==false)
			{
				throw CPKIException("not gcm param");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),&m_gcmParam);
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),&m_gcmParam);
			}
		}
		else if (m_algo == NETCA_PKI_ALGORITHM_AES_XTS)
		{
			if(m_tweak.length()<=0)
			{
				throw CPKIException("not tweak");
			}
			if(device)
			{
				m_hCipher=NetcaPKICryptoNewCipher(device->handle(),m_enc,m_algo,m_key.data(),m_key.length(),m_tweak.data());
			}
			else
			{
				m_hCipher=NetcaPKICryptoGetCipherHandle(m_enc,m_algo,m_key.data(),m_key.length(),m_tweak.data());
			}
		}

		if(m_hCipher==0)
		{
			throw CPKIException("create cipher handle fail");
		}

		if(m_algo==NETCA_PKI_ALGORITHM_DES_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_DES_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_3DES_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_3DES_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_RC2_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_RC2_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_AES_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_AES_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_SSF33_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_SSF33_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_SM1_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_SM1_CBC
			|| m_algo==NETCA_PKI_ALGORITHM_SM4_ECB
			|| m_algo==NETCA_PKI_ALGORITHM_SM4_CBC)
		{
			int rv;
			rv=NetcaPKICryptoCipherSetPadding(m_hCipher,m_padding);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				throw CPKIException(rv,"set padding fail");
			}
		}

	}

	void CCipher::init(const CDevice &device)
	{
		init(&device);
	}
	void CCipher::init()
	{
		init(0);
	}

	void CCipher::update(const unsigned char *inData,int inDataLen,CBlob& outData)
	{
		if(m_hCipher==0)
		{
			throw CPKIException("not init");
		}
		int rv;
		unsigned char *out;
		int outLen;
		rv=NetcaPKICryptoCipherUpdate(m_hCipher,inData,inDataLen,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"cipher update fail");
		}
		outData.attach(out,outLen);
	}

	void CCipher::final(CBlob& outData)
	{
		if(m_hCipher==0)
		{
			throw CPKIException("not init");
		}
		int rv;
		unsigned char *out;
		int outLen;
		rv=NetcaPKICryptoCipherFinal(m_hCipher,&out,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"cipher final fail");
		}
		outData.attach(out,outLen);
	}
	
	void CCipher::cipher(const unsigned char *inData,int inDataLen,CBlob& outData)
	{
		if(m_hCipher==0)
		{
			throw CPKIException("not init");
		}
		long long outLen;

		int rv=NetcaPKICryptoCipher(m_hCipher,inData,inDataLen,0,0,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"cipher fail");
		}
		if(outLen>INT_MAX)
		{
			throw CPKIException("cipher length too long");
		}
		unsigned char *out=(unsigned char *)NetcaPKICryptoAllocMemory((int)outLen);
		if(out==0)
		{
			throw CPKIException("alloc fail");
		}
		rv=NetcaPKICryptoCipher(m_hCipher,inData,inDataLen,out,outLen,&outLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICryptoFreeMemory(out);
			throw CPKIException(rv,"cipher fail");
		}
		outData.attach(out,(int)outLen);
	}

	void CCipher::RC4(bool enc,const unsigned char *key,int keyLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_ARC4);
		cipherObj.setKey(key,keyLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::RC2Ecb(bool enc,const unsigned char *key,int keyLen,int effectiveKeyBits,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_RC2_ECB);
		cipherObj.setKey(key,keyLen);
		cipherObj.setEffectiveKeyBits(effectiveKeyBits);
		cipherObj.padding(padding);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::RC2Cbc(bool enc,const unsigned char *key,int keyLen,int effectiveKeyBits,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_RC2_CBC);
		cipherObj.setKey(key,keyLen);
		cipherObj.setEffectiveKeyBits(effectiveKeyBits);
		cipherObj.setIV(iv,ivLen);
		cipherObj.padding(padding);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ecb(bool enc,int algo,const unsigned char *key,int keyLen,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.padding(padding);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ecb(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.padding(padding);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Cbc(bool enc,int algo,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setIV(iv,ivLen);
		cipherObj.padding(padding);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Cbc(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,int padding,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setIV(iv,ivLen);
		cipherObj.padding(padding);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ctr(bool enc,int algo,const unsigned char *key,int keyLen,int bitCount,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCtrParam(bitCount,iv,ivLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ctr(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int bitCount,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCtrParam(bitCount,iv,ivLen);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ccm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCcmParam(tLen,nonce,nonceLen,aData,aDataLen,inLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ccm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *aData,int aDataLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCcmParam(tLen,nonce,nonceLen,aData,aDataLen,inLen);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ccm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCcmParam(tLen,nonce,nonceLen,inLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Ccm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *nonce,int nonceLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setCcmParam(tLen,nonce,nonceLen,inLen);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Gcm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setGcmParam(tLen,iv,ivLen,aad,aadLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Gcm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char * aad,int aadLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setGcmParam(tLen,iv,ivLen,aad,aadLen);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Gcm(bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setGcmParam(tLen,iv,ivLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Gcm(const CDevice &device,bool enc,int algo,const unsigned char *key,int keyLen,int tLen, const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,algo);
		cipherObj.setKey(key,keyLen);
		cipherObj.setGcmParam(tLen,iv,ivLen);
		cipherObj.init(device);
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::AesXts(bool enc,const unsigned char *key,int keyLen,const unsigned char *tweak,int tweakLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_AES_XTS);
		cipherObj.setKey(key,keyLen);
		cipherObj.setTweak(tweak,tweakLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Zuc(bool enc,const unsigned char *key,int keyLen,int count, int bearer, bool direction,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_ZUC);
		cipherObj.setKey(key,keyLen);
		cipherObj.setZucParam(count, bearer, direction);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}

	void CCipher::Zuc(bool enc,const unsigned char *key,int keyLen,const unsigned char *iv,int ivLen,const unsigned char *in,int inLen,CBlob& outData)
	{
		CCipher cipherObj(enc,NETCA_PKI_ALGORITHM_ZUC_BASE);
		cipherObj.setKey(key,keyLen);
		cipherObj.setIV(iv,ivLen);
		cipherObj.init();
		cipherObj.cipher(in,inLen,outData);
	}
};
