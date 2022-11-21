#include "Device.hpp"
#include "PKIException.hpp"
#include "Keypair.hpp"
#include "PublicKey.hpp"
#include "Certificate.hpp"

namespace
{
	int GetKeyBitsFromCurve(int curve)
	{
		switch(curve)
		{
		case NETCA_PKI_ECC_CURVE_P192:
		case NETCA_PKI_ECC_CURVE_WAPI:
			return 192;
		case NETCA_PKI_ECC_CURVE_P224:
			return 224;
		case NETCA_PKI_ECC_CURVE_P256:
		case NETCA_PKI_ECC_CURVE_SM2:
			return 256;
		case NETCA_PKI_ECC_CURVE_P384:
			return 384;
		case NETCA_PKI_ECC_CURVE_P521:
			return 521;
		default:
			return -1;
		}
	}
};
namespace Netca
{


	CDevice::CDevice()
	{
		init(0);
	}

	CDevice::CDevice(NETCA_PKI_DEVICE_HANDLE hDevice)
	{
		init(hDevice);
	}

	void CDevice::init(NETCA_PKI_DEVICE_HANDLE hDevice)
	{
		if(hDevice==0)
		{
			m_hDevice=0;
			m_type=-1;
			m_sn="";
			return;
		}
		m_hDevice=NetcaPKICryptoDupDevice(hDevice);
		if(m_hDevice==0)
		{
			throw CPKIException("dup device fail");
		}
		m_type=NetcaPKICryptoGetType(m_hDevice);
		if(m_type<0)
		{
			NetcaPKICryptoFreeDevice(m_hDevice);
			throw CPKIException("get device type fail");
		}

		int rv;
		char *sn;

		rv=NetcaPKICryptoGetSerialNumber(m_hDevice,&sn);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICryptoFreeDevice(m_hDevice);
			throw CPKIException(rv,"get device sn fail");
		}
		
		try
		{
			m_sn=sn;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevice(m_hDevice);
			NetcaPKICryptoFreeMemory(sn);
			throw;
		}

		NetcaPKICryptoFreeMemory(sn);
	}

	CDevice::~CDevice()
	{
		NetcaPKICryptoFreeDevice(m_hDevice);
	}

	CDevice::CDevice(const CDevice& device)
	{
		init(device.m_hDevice);
	}

	CDevice& CDevice::operator =(const CDevice& device)
	{
		if(this!=&device)
		{
			NetcaPKICryptoFreeDevice(m_hDevice);
			m_hDevice=0;
			init(device.m_hDevice);
		}

		return *this;
	}

	std::string CDevice::label()const
	{
		char *labelString=0;
		int rv=NetcaPKICryptoGetLabel(m_hDevice,&labelString);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return std::string();
		}
		
		try
		{
			std::string str(labelString);
			NetcaPKICryptoFreeMemory(labelString);
			labelString=0;
			return str;
		}
		catch(std::exception&)
		{
			if(labelString)
			{
				NetcaPKICryptoFreeMemory(labelString);
			}
			throw;
		}
	}

	bool CDevice::mustLogin()const
	{
		return NetcaPKICryptoDeviceMustLogin(m_hDevice)!=0;
	}

	int CDevice::deviceClass()const
	{
		return NetcaPKICryptoGetClass(m_hDevice);
	}

	bool CDevice::isImportOnlyEncryptKeyPair()const
	{
		return NetcaPKICryptoIsImportOnlyEncryptKeyPair(m_hDevice)!=0;
	}

	bool CDevice::isSamePhysicalDevice(const CDevice& device)const
	{
		return NetcaPKICryptoIsSamePhysicalDevice(m_hDevice,device.m_hDevice)!=0;
	}

	void CDevice::usbInfo(int &vid,int &pid)
	{
		int rv;
		rv=NetcaPKICryptoGetUsbInfo(m_hDevice,&vid,&pid);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException("get usb info fail");
		}
	}

	bool CDevice::isSupportPwdAuth()const
	{
		return NetcaPKICryptoDeviceIsSupportPwdAuth(m_hDevice)!=0;
	}

	void CDevice::setCachePwdSecond(int second)
	{
		int rv;
		rv=NetcaPKICryptoSetCachePwdSecond(m_hDevice,second);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set cahce pwd timeout fail");
		}
	}

	void CDevice::clearPwdCache(void)
	{
		int rv;
		rv=NetcaPKICryptoClearPwdCache(m_hDevice);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"clear cahce pwd fail");
		}
	}

	bool CDevice::reVerifyUserPwd(const char *msg)
	{
		int rv;
		rv=NetcaPKICryptoReVerifyUserPwd(m_hDevice,msg);
		return rv==NETCA_PKI_SUCCESS;
	}

	bool CDevice::reVerifyUserPwd(const std::string& msg)
	{
		return reVerifyUserPwd(msg.c_str());
	}

	CDevice CDevice::BuiltinSoftwareDevice()
	{
		NETCA_PKI_DEVICE_HANDLE hDevice;
		hDevice=NetcaPKICryptoGetPseudoDevice();
		try
		{
			CDevice device(hDevice);
			NetcaPKICryptoFreeDevice(hDevice);
			hDevice=0;
			return device;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevice(hDevice);
			throw;
		}
	}

	CDevice CDevice::FindDevice(int type,const char *sn,int flag)
	{
		int rv;
		NETCA_PKI_DEVICE_HANDLE hDevice;
		rv=NetcaPKICryptoFindDevice(type,sn,flag,&hDevice);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CDevice();
		}

		try
		{
			CDevice device(hDevice);
			NetcaPKICryptoFreeDevice(hDevice);
			hDevice=0;
			return device;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeDevice(hDevice);
			throw;
		}
	}

	CDevice CDevice::FindDevice(int type,const std::string &sn,int flag)
	{
		return FindDevice(type,sn.c_str(),flag);
	}

	void CDevice::lock()
	{
		int rv=NetcaPKICryptoLockDevice(m_hDevice);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"lock device fail");
		}
	}

	void CDevice::unlock()
	{
		int rv=NetcaPKICryptoUnlockDevice(m_hDevice);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"unlock device fail");
		}
	}


	int CDevice::verifyPwd(int type,const char *pwd,int &retryNumber)
	{
		int rv;
		retryNumber=NETCA_PKI_UNSUPPORTED_RETRY_NUMBER;
		rv=NetcaPKICryptoVerifyPwd(m_hDevice,type,pwd,&retryNumber);
		return rv;
	}

	bool CDevice::verifyPwd(int type,const char *pwd)
	{
		int retryNumber;
		return verifyPwd(type,pwd,retryNumber)==NETCA_PKI_SUCCESS;
	}

	int CDevice::retryNumber(int type)
	{
		int retryNumber;
		int rv=NetcaPKICryptoGetPwdRetryNum(m_hDevice,type, &retryNumber);
		if(rv==NETCA_PKI_SUCCESS)
		{
			return retryNumber;
		}
		else
		{
			return NETCA_PKI_UNSUPPORTED_RETRY_NUMBER;
		}
	}

	int CDevice::changePwd(int type, const char *oldPwd, const char *newPwd,int &retryNumber)
	{
		int rv;
		retryNumber=NETCA_PKI_UNSUPPORTED_RETRY_NUMBER;
		rv=NetcaPKICryptoChangePwd(m_hDevice,type,oldPwd,newPwd,&retryNumber);
		return rv;
	}

	bool CDevice::changePwd(int type, const char *oldPwd, const char *newPwd)
	{
		int retryNumber;
		return changePwd(type,oldPwd,newPwd,retryNumber)==NETCA_PKI_SUCCESS;
	}

	int CDevice::unlockPwd(int type, const char * soPwd, const char * newPwd,int &retryNumber)
	{
		int rv;
		retryNumber=NETCA_PKI_UNSUPPORTED_RETRY_NUMBER;
		rv=NetcaPKICryptoUnlockPwd(m_hDevice,type,soPwd,newPwd,&retryNumber);
		return rv;
	}

	bool CDevice::unlockPwd(int type, const char * soPwd, const char * newPwd)
	{
		int retryNumber;
		return unlockPwd(type,soPwd,newPwd,retryNumber)==NETCA_PKI_SUCCESS;
	}

	std::vector<CKeypair> CDevice::keypairs()const
	{
		std::vector<CKeypair> v;
		int count;
		int i;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair=0;

		count=NetcaPKICryptoGetKeypairCount(m_hDevice);
		for(i=0;i<count;i++)
		{
			hKeypair=NetcaPKICryptoGetKeypair(m_hDevice,i);
			if(hKeypair)
			{
				try
				{
					v.push_back(CKeypair(hKeypair));
				}
				catch(std::exception&)
				{
					NetcaPKICryptoFreeKeypair(hKeypair);
					throw;
				}
				NetcaPKICryptoFreeKeypair(hKeypair);
			}
		}
		return v;
	}
	
	CKeypair CDevice::findKeypair(int type,const char* label)const
	{
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;
		int rv=NetcaPKICryptoFindKeypair(m_hDevice,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		CKeypair keypair;
		try
		{
			keypair=CKeypair(hKeypair);
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
		NetcaPKICryptoFreeKeypair(hKeypair);
		return keypair;
	}
	CKeypair CDevice::findKeypair(int type,const std::string& label)const
	{
		return findKeypair(type,label.c_str());
	}


	void CDevice::generateRandom(int length,CBlob& blob)
	{
		unsigned char *rand;

		rand=(unsigned char *)NetcaPKICryptoAllocMemory(length);
		if(rand==0)
		{
			throw CPKIException("alloc fail");
		}
		int rv=NetcaPKICryptoGenerateRandom(m_hDevice,length,rand);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICryptoFreeMemory(rand);
			throw CPKIException(rv,"generate random fail");
		}

		blob.attach(rand,length);
		
	}

	CPublicKey CDevice::importPublicKey(const unsigned char *data,int dataLen)
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
		int rv;

		rv=NetcaPKICryptoImportPublicKey(m_hDevice,data,dataLen,&hPublicKey);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CPublicKey();
		}

		try
		{
			CPublicKey pubkey(hPublicKey);
			NetcaPKICryptoFreePublicKey(hPublicKey);
			hPublicKey=0;
			return pubkey;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreePublicKey(hPublicKey);
			throw;
		}
	}
	
	CPublicKey CDevice::importSubjectPublicKeyInfo(const unsigned char *data,int dataLen)
	{
		NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
		int rv;

		rv=NetcaPKICryptoImportPublicKeyFromSubjectPublicKeyInfo(m_hDevice,data,dataLen,&hPublicKey);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CPublicKey();
		}

		try
		{
			CPublicKey pubkey(hPublicKey);
			NetcaPKICryptoFreePublicKey(hPublicKey);
			hPublicKey=0;
			return pubkey;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreePublicKey(hPublicKey);
			throw;
		}
	}

	CKeypair CDevice::generateRSAKeypair(int keyBits,int type, const char *label)
	{
		int rv;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;

		rv=NetcaPKICryptoGenerateKeypair(m_hDevice,NETCA_PKI_ALGORITHM_GENKEYPAIR_RSA,keyBits,0,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
		
	}

	CKeypair CDevice::generateTemporaryRSAKeypair(int keyBits,int type, const char *label)
	{
		int rv;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;
		struct NETCA_PKI_GenRSA_PARAM_st param;

		param.m_e=0;
		param.m_elen=0;
		param.m_temp=1;
		param.m_reserve=0;

		rv=NetcaPKICryptoGenerateKeypair(m_hDevice,NETCA_PKI_ALGORITHM_GENKEYPAIR_RSA,keyBits,&param,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
		
	}

	CKeypair CDevice::generateECCKeypair(int curve,int type, const char *label)
	{
		int keyBits=GetKeyBitsFromCurve(curve);
		int rv;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;
		struct NETCA_PKI_GenECC_PARAM_st param;

		param.m_curve=curve;
		param.m_temp=0;
		param.m_reserve=0;

		rv=NetcaPKICryptoGenerateKeypair(m_hDevice,NETCA_PKI_ALGORITHM_GENKEYPAIR_ECC,keyBits,&param,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
	}

	CKeypair CDevice::generateTemporaryECCKeypair(int curve,int type, const char *label)
	{
		int keyBits=GetKeyBitsFromCurve(curve);
		int rv;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;
		struct NETCA_PKI_GenECC_PARAM_st param;

		param.m_curve=curve;
		param.m_temp=1;
		param.m_reserve=0;

		rv=NetcaPKICryptoGenerateKeypair(m_hDevice,NETCA_PKI_ALGORITHM_GENKEYPAIR_ECC,keyBits,&param,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
	}

	CKeypair CDevice::generateSM2Keypair(int type, const char *label)
	{
		return generateECCKeypair(NETCA_PKI_ECC_CURVE_SM2,type,label);
	}

	CKeypair CDevice::generateTemporarySM2Keypair(int type, const char *label)
	{
		return generateTemporaryECCKeypair(NETCA_PKI_ECC_CURVE_SM2,type,label);
	}

	int CDevice::createData(int dataId, const char *mode,int length)
	{
		return NetcaPKICryptoCreateData(m_hDevice,dataId,mode,length);;
	}

	int CDevice::getDataLength(int dataId)
	{
		int rv;
		int length;
		
		rv=NetcaPKICryptoGetDataLength(m_hDevice,dataId,&length);
		if(rv==NETCA_PKI_SUCCESS)
		{
			return length;
		}
		else
		{
			return -1;
		}

	}

	int CDevice::readData(int dataId, int offset,unsigned char *data,int dataLen,int& retDataLen)
	{
		return NetcaPKICryptoReadDataEx(m_hDevice,dataId,offset,data,dataLen,&retDataLen);
	}

	int CDevice::readData(int dataId, unsigned char *data,int dataLen,int& retDataLen)
	{
		return NetcaPKICryptoReadDataEx(m_hDevice,dataId,0,data,dataLen,&retDataLen);
	}

	int CDevice::writeData(int dataId,int offset,const unsigned char *data,int dataLen)
	{
		return NetcaPKICryptoWriteDataEx(m_hDevice,dataId,offset,data,dataLen);
	}

	int CDevice::writeData(int dataId,const unsigned char *data,int dataLen)
	{
		return NetcaPKICryptoWriteDataEx(m_hDevice,dataId,0,data,dataLen);
	}

	int CDevice::deleteData(int dataId)
	{
		return NetcaPKICryptoDeleteData(m_hDevice,dataId);
	}

	CKeypair CDevice::importKeyPair(int type,const char *label,const unsigned char *data,int dataLen)
	{
		int rv;
		NETCA_PKI_KEYPAIR_HANDLE hKeypair;
		rv=NetcaPKICryptoImportKeypair(m_hDevice,data,dataLen,type,label,&hKeypair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			return CKeypair();
		}

		try
		{
			CKeypair keypair(hKeypair);
			NetcaPKICryptoFreeKeypair(hKeypair);
			hKeypair=0;
			return keypair;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeKeypair(hKeypair);
			throw;
		}
	}

	CKeypair CDevice::importKeyPair(int type,const std::string& label,const unsigned char *data,int dataLen)
	{
		return importKeyPair(type,label.c_str(),data,dataLen);
	}

	void CDevice::generateKey(int algo,int keyLen,unsigned char *key)
	{
		int rv=NetcaPKICryptoGenerateKey(m_hDevice,algo,keyLen,key);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"generate key fail");
		}
	}

	void AddRandomSeed(const unsigned char *seed,int seedLen)
	{
		int rv=NetcaPKICryptoAddRandomSeed(seed,seedLen);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add random seed fail");
		}
	}
	void SetCachePwdSecond(int second)
	{
		int rv;

		rv=NetcaPKICryptoSetCachePwdSecond(0,second);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"set cache pwd time fail");
		}
	}

	void ClearPwdCache(void)
	{
		int rv;

		rv=NetcaPKICryptoClearPwdCache(0);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"clear cache pwd fail");
		}
		
	}

	void CDevice::installCert(int type,const unsigned char *encKeypair,int encKeypairLen,const CCertificate &encCert,const CCertificate &signCert)
	{
		int rv;
		rv=NetcaPKICryptoInstallCertificate(m_hDevice,type,encKeypair,encKeypairLen,encCert.handle(),signCert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"install cert fail");
		}
	}

	void CDevice::installCert(const CCertificate &encCert,const CCertificate &signCert)
	{
		int rv;
		rv=NetcaPKICryptoInstallCertificate(m_hDevice,NETCA_PKI_ENCKEYPAIR_TYPE_NONE,0,0,encCert.handle(),signCert.handle());
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"install cert fail");
		}
	}

	void CDevice::installCert(const CCertificate &encCert)
	{
		int rv;
		rv=NetcaPKICryptoInstallCertificate(m_hDevice,NETCA_PKI_ENCKEYPAIR_TYPE_NONE,0,0,encCert.handle(),0);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"install cert fail");
		}
	}
}
