#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);

int main(int argc,char **argv)
{
	int algo;
	NETCA_PKI_CERTIFICATE_HANDLE hCert;
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
	FILE *fp;
	unsigned char buf[8192];
	int len;
	int rv;
	unsigned char *sign;
	int signLen;
	NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify;

	if(argc!=5)
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

	hCert=GetCert(argv[2]);
	if(hCert==0)
	{
		printf("bad cert file\n");
		return -1;
	}
	hPublicKey=NetcaPKICertGetCertPublicKey(hCert,NETCA_PKI_CERT_PURPOSE_SIGN);
	NetcaPKICertFreeCert(hCert);
	if(hPublicKey==0)
	{
		printf("NetcaPKICertGetCertKeyPair fail,cert not in validity,or not signature cert\n");
		return -1;
	}

	hVerify=NetcaPKICryptoNewVerify(hPublicKey,algo,0);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	if(hVerify==0)
	{
		printf("NetcaPKICryptoNewVerify fail\n");
		return -1;
	}
	

	fp=fopen(argv[3],"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeVerify(hVerify);
		printf("open %s fail\n",argv[3]);
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fp);

		if(ferror(fp)!=0)
		{
			fclose(fp);
			printf("fread fail\n");
			NetcaPKICryptoFreeVerify(hVerify);
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKICryptoVerifyUpdate(hVerify,buf,len);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fp);
				NetcaPKICryptoFreeVerify(hVerify);
				printf("NetcaPKICryptoVerifyUpdate fail\n");
				return -1;
			}
		}

		if(feof(fp))
		{
			break;
		}
	}
	fclose(fp);

	rv=ReadFileData(argv[4],&sign,&signLen);
	if(rv==0)
	{
		NetcaPKICryptoFreeVerify(hVerify);
		printf("read %s fail\n",argv[4]);
		return -1;
	}
	
	rv=NetcaPKICryptoVerifyFinal(hVerify,sign,signLen);
	NetcaPKICryptoFreeVerify(hVerify);
	NetcaPKICryptoFreeMemory(sign);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("Verify Fail\n");
	}
	else
	{
		printf("Verify OK\n");
	}
	
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s sha1withRSA|sha256withRSA cert tbs signature",fileName);
}

NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName)
{
	unsigned char *buf;
	int bufLen;
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	rv=ReadFileData(fileName,&buf,&bufLen);
	if(rv==0)
	{
		return 0;
	}

	cert= NetcaPKICertNewCert(buf,bufLen);
	NetcaPKICryptoFreeMemory(buf);
	return cert;
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


int GetFileLength(FILE *fp)
{
	int  len;
	if(fseek(fp,0,SEEK_END)!=0)
	{
		return -1;
	}
	len=ftell(fp);
	if(fseek(fp,0,SEEK_SET)!=0)
	{
		return -1;
	}
	
	return len;
}

int ReadFileData(const char *fileName,unsigned char **data,int *dataLen)
{
	FILE *fp;
	int len;
	unsigned char *buf;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		return 0;
	}

	len=GetFileLength(fp);
	if(len<0)
	{
		fclose(fp);
		return 0;
	}
	
	buf=(unsigned char *)NetcaPKICryptoAllocMemory(len);
	if(buf==0)
	{
		fclose(fp);
		return 0;
	}
	if((int)fread(buf,1,len,fp)!=len)
	{
		NetcaPKICryptoFreeMemory(buf);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	*data=buf;
	*dataLen=len;
	return 1;
}
