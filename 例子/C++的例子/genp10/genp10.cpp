#include <stdio.h>
#include "Device.hpp"
#include "PKIException.hpp"
#include "CertReq.hpp"
#include "Keypair.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

using Netca::CDevice;
using Netca::CPKIException;
using Netca::CCertReq;
using Netca::CKeypair;
using Netca::CBlob;

static void usage(const char *procName);
static int GetSignAlgoFromName(const char *algoName);
static int GetKeypairTypeFromName(const char *name);
static char *ansiToutf8(const char *str);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	int rv;
	int deviceType;
	const char *deviceSn;
	const char *devicePwd;
	const char *label;
	int keypairType;
	int signAlgo;
	const char *p10FileName;
	int keybits;
	const char *subject;
	char *utf8Subject=0;
	CBlob p10;


	if(argc!=10)
	{
		usage(argv[0]);
		return -1;
	}
	deviceType=atoi(argv[1]);
	deviceSn=argv[2];
	devicePwd=argv[3];
	keybits=atoi(argv[4]);
	label=argv[5];
	subject=argv[8];

	keypairType=GetKeypairTypeFromName(argv[6]);
	if(keypairType==-1)
	{
		usage(argv[0]);
		return -1;
	}

	signAlgo=GetSignAlgoFromName(argv[7]);
	if(signAlgo==-1)
	{
		usage(argv[0]);
		return -1;
	}
	

	p10FileName=argv[9];

	try
	{
		CDevice device=CDevice::FindDevice(deviceType,deviceSn,NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN);
		if(device.isNull())
		{
			printf("NetcaPKICryptoFindDevice fail\n");
			return -1;
		}
		
		if(device.verifyPwd(NETCA_PKI_USER_PWD,devicePwd)==false)
		{
			printf("NetcaPKICryptoVerifyPwd fail\n");
			return -1;
		}
		CKeypair keypair;
		if(signAlgo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
		{
			keypair=device.generateSM2Keypair(keypairType,label);
		}
		else
		{
			keypair=device.generateRSAKeypair(keybits,keypairType,label);
		}
		
		if(keypair.isNull())
		{
			printf("Generate Keypair fail\n");
			return -1;
		}

		CCertReq req;
		
		utf8Subject=ansiToutf8(subject);
		if(utf8Subject==0)
		{
			printf("ansiToutf8 fail\n");
			return -1;
		}
		req.setSubject(utf8Subject);
		NETCA_FREE(utf8Subject);
		utf8Subject=0;

		req.sign(keypair,signAlgo,p10);
		
		rv=SaveFile(p10FileName,p10.data(),p10.length());
		if(rv==0)
		{
			printf("SaveFile fail\n");
			return -1;
		}

		printf("Success\n");
		return 0;
	}
	catch(CPKIException& e)
	{
		if(utf8Subject)
		{
			NETCA_FREE(utf8Subject);
		}
		printf("gen p10 fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *procName)
{
	printf("Usage: %s type sn pwd bits label enc|sign sha1withRSA|sha256withRSA subject p10FileName",procName);
}

int GetSignAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha1withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha256withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha512withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sm3withsm2")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3WITHSM2;
	}
	else
	{
		return -1;
	}
}

int GetKeypairTypeFromName(const char *name)
{
	if(STRINGCASECMP(name,"enc")==0
		|| STRINGCASECMP(name,"encrypt")==0)
	{
		return NETCA_PKI_KEYPAIRTYPE_ENCRYPT;
	}
	else if(STRINGCASECMP(name,"sign")==0
		|| STRINGCASECMP(name,"signature")==0)
	{
		return NETCA_PKI_KEYPAIRTYPE_SIGNATURE;
	}
	else if(STRINGCASECMP(name,"keyagreement")==0)
	{
		return NETCA_PKI_KEYPAIRTYPE_KEYAGREEMENT;
	}
	else
	{
		return -1;
	}
}

char *ansiToutf8(const char *str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *utf8;
	long utf8Len;

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		return 0;
	}

	ustr=netca_ustring_newmbs(charset,(const unsigned char *)str,(long)strlen(str));
	NETCA_FREE(charset);
	if(ustr==0)
	{
		return 0;
	}

	rv=netca_ustring_toutf8(ustr,&utf8,&utf8Len);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		return 0;
	}

	return (char *)utf8;
}

int SaveFile(const char *fileName,const unsigned char *buf,int bufLen)
{
	FILE *fp;
	int len;
	fp=fopen(fileName,"wb");
	if(fp==0)
	{
		return 0;
	}

	len=(int)fwrite(buf,1,bufLen,fp);
	fclose(fp);
	return len==bufLen;
}

