#ifndef NETCA_DEVICE_INCLUDE_HPP
#define NETCA_DEVICE_INCLUDE_HPP

#include <string>
#include <vector>

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"

namespace Netca
{
	class CKeypair;
	class CPublicKey;
	class CCertificate;

	class CDevice
	{
	public:
		CDevice();
		CDevice(NETCA_PKI_DEVICE_HANDLE hDevice);
		~CDevice();
		CDevice(const CDevice& device);
		CDevice& operator =(const CDevice& device);

		static CDevice BuiltinSoftwareDevice();
		static CDevice FindDevice(int type,const char *sn,int flag);
		static CDevice FindDevice(int type,const std::string &sn,int flag);

		bool isNull() const { return m_hDevice==0; }
		int type()const { return m_type;}
		std::string serialNumber()const { return m_sn;}
		
		std::string label()const;
		bool mustLogin()const;

		int deviceClass()const;

		bool isImportOnlyEncryptKeyPair()const;

		bool isSamePhysicalDevice(const CDevice& device)const;
		
		void usbInfo(int &vid,int &pid);
		
		bool isSupportPwdAuth()const;
		
		void setCachePwdSecond(int second);

		void clearPwdCache(void);

		bool reVerifyUserPwd(const char *msg);
		bool reVerifyUserPwd(const std::string& msg);

		void lock();
		void unlock();

		int verifyPwd(int type,const char *pwd,int &retryNumber);
		bool verifyPwd(int type,const char *pwd);
		int retryNumber(int type);
		int changePwd(int type, const char *oldPwd, const char *newPwd,int &retryNumber);
		bool changePwd(int type, const char *oldPwd, const char *newPwd);
		int unlockPwd(int type, const char *soPwd, const char *newPwd,int &retryNumber);
		bool unlockPwd(int type, const char *soPwd, const char *newPwd);

		std::vector<CKeypair> keypairs()const;
		CKeypair findKeypair(int type,const char* label) const;
		CKeypair findKeypair(int type,const std::string &label) const;

		void generateRandom(int length,CBlob& blob);

		CPublicKey importPublicKey(const unsigned char *data,int dataLen);
		CPublicKey importSubjectPublicKeyInfo(const unsigned char *data,int dataLen);

		CKeypair importKeyPair(int type,const char *label,const unsigned char *data,int dataLen);
		CKeypair importKeyPair(int type,const std::string& label,const unsigned char *data,int dataLen);

		CKeypair generateRSAKeypair(int keyBits,int type, const char *label);
		CKeypair generateTemporaryRSAKeypair(int keyBits,int type, const char *label);
		CKeypair generateECCKeypair(int curve,int type, const char *label);
		CKeypair generateTemporaryECCKeypair(int curve,int type, const char *label);
		CKeypair generateSM2Keypair(int type, const char *label);
		CKeypair generateTemporarySM2Keypair(int type, const char *label);

		void generateKey(int algo,int keyLen,unsigned char *key);


		int createData(int dataId, const char *mode,int length);
		int getDataLength(int dataId);
		int readData(int dataId, int offset,unsigned char *data,int dataLen,int& retDataLen);
		int readData(int dataId, unsigned char *data,int dataLen,int& retDataLen);
		int writeData(int dataId,int offset,const unsigned char *data,int dataLen);
		int writeData(int dataId,const unsigned char *data,int dataLen);
		int deleteData(int dataId);

		void installCert(int type,const unsigned char *encKeypair,int encKeypairLen,const CCertificate &encCert,const CCertificate &signCert);
		void installCert(const CCertificate &encCert,const CCertificate &signCert);
		void installCert(const CCertificate &encCert);

	private:
		void init(NETCA_PKI_DEVICE_HANDLE hDevice);

		friend class CSignedData;
		friend class CMac;
		friend class CHash;
		friend class CEnvelopedData;
		friend class CCipher;

		NETCA_PKI_DEVICE_HANDLE handle() const { return m_hDevice;}

		NETCA_PKI_DEVICE_HANDLE m_hDevice;
		int m_type;
		std::string m_sn;
	};

	void AddRandomSeed(const unsigned char *seed,int seedLen);
	void SetCachePwdSecond(int second);
	void ClearPwdCache(void);
};

#endif

