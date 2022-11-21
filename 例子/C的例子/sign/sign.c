#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);
static int GetSignAlgoFromName(const char *algoName);

int main(int argc,char **argv)
{
	int algo;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_KEYPAIR_HANDLE hKeyPair;
	FILE *fp;
	unsigned char buf[8192];
	int len;
	NETCA_PKI_SIGN_HANDLE hSign;
	int rv;
	unsigned char *sign;
	int signLen;
	const char *filter;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	algo=GetSignAlgoFromName(argv[1]);
	if(algo==-1)
	{
		usage(argv[0]);
		return -1;
	}

	if(algo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		filter="Algorithm='SM2'";
	}
	else
	{
		filter="Algorithm='RSA'";
	}

	rv= NetcaPKISelectCert("Signature",filter,&cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}
	hKeyPair=NetcaPKICertGetCertKeyPair(cert,0,NETCA_PKI_CERT_PURPOSE_SIGN,0);
	NetcaPKICertFreeCert(cert);
	if(hKeyPair==0)
	{
		printf("NetcaPKICertGetCertKeyPair fail\n");
		return -1;
	}

	hSign=NetcaPKICryptoNewSign(hKeyPair,algo,0);
	NetcaPKICryptoFreeKeypair(hKeyPair);
	if(hSign==0)
	{
		printf("NetcaPKICryptoNewSign fail\n");
		return -1;
	}
	

	fp=fopen(argv[2],"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeSign(hSign);
		printf("open %s fail\n",argv[2]);
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fp);
		if(ferror(fp)!=0)
		{
			fclose(fp);
			printf("fread fail\n");
			NetcaPKICryptoFreeSign(hSign);
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKICryptoSignUpdate(hSign,buf,len);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fp);
				NetcaPKICryptoFreeSign(hSign);
				printf("NetcaPKICryptoSignUpdate fail\n");
				return -1;
			}
		}

		if(feof(fp))
		{
			break;
		}
	}
	fclose(fp);
	
	rv=NetcaPKICryptoSignFinal(hSign,&sign,&signLen);
	NetcaPKICryptoFreeSign(hSign);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoSignFinal fail\n");
		return -1;
	}

	rv=SaveFile(argv[3],sign,signLen);
	NetcaPKICryptoFreeMemory(sign);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}

	printf("Success\n");
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s sha1withRSA|sha256withRSA tbsFileName signatureFileName",fileName);
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
