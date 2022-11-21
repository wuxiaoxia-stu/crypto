#include <stdio.h>
#include <stdlib.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_CertReq.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

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
	NETCA_PKI_DEVICE_HANDLE hDevice;
	const char *label;
	int keypairType;
	int signAlgo;
	const char *p10FileName;
	int retryNumber;
	int genKeypairAlgo;
	int keybits;
	NETCA_PKI_KEYPAIR_HANDLE hKeypair;
	NETCA_PKI_CERTREQ_HANDLE hCertReq;
	const char *subject;
	char *utf8Subject;
	unsigned char *p10;
	int p10Len;

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

	rv=NetcaPKICryptoFindDevice(deviceType,deviceSn,NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN,&hDevice);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoFindDevice fail,return %d\n",rv);
		return -1;
	}
	
	rv=NetcaPKICryptoVerifyPwd(hDevice,NETCA_PKI_USER_PWD,devicePwd,&retryNumber);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeDevice(hDevice);
		printf("NetcaPKICryptoVerifyPwd fail,return %d\n",rv);
		return -1;
	}
	if(signAlgo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		struct NETCA_PKI_GenECC_PARAM_st param;
		param.m_curve=NETCA_PKI_ECC_CURVE_SM2;
		param.m_reserve=0;
		param.m_temp=0;
		genKeypairAlgo=NETCA_PKI_ALGORITHM_GENKEYPAIR_ECC;

		rv=NetcaPKICryptoGenerateKeypair(hDevice,genKeypairAlgo,keybits,&param,
			keypairType,label,&hKeypair);
	}
	else
	{
		genKeypairAlgo=NETCA_PKI_ALGORITHM_GENKEYPAIR_RSA;
		rv=NetcaPKICryptoGenerateKeypair(hDevice,genKeypairAlgo,keybits,0,
			keypairType,label,&hKeypair);
	}
	NetcaPKICryptoFreeDevice(hDevice);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoGenerateKeypair fail\n");
		return -1;
	}

	hCertReq=NetcaPKICertReqNew();
	if(hCertReq==0)
	{
		NetcaPKICertReqFree(hCertReq);
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("NetcaPKICertReqNew fail\n");
		return -1;
	}
	utf8Subject=ansiToutf8(subject);
	if(utf8Subject==0)
	{
		NetcaPKICertReqFree(hCertReq);
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("ansiToutf8 fail\n");
		return -1;
	}
	rv=NetcaPKICertReqSetStringAttribute(hCertReq,NETCA_PKI_CERTREQ_SUBJECT,utf8Subject);
	NETCA_FREE(utf8Subject);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(hCertReq);
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("set subject fail\n");
		return -1;
	}

	rv=NetcaPKICertReqSign(hCertReq,hKeypair,signAlgo,0,&p10,&p10Len);
	NetcaPKICryptoFreeKeypair(hKeypair);
	NetcaPKICertReqFree(hCertReq);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICertReqSign fail\n");
		return -1;
	}

	rv=SaveFile(p10FileName,p10,p10Len);
	NetcaPKICryptoFreeMemory(p10);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}

	printf("Success\n");
	return 0;
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

