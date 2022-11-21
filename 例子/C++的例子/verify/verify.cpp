#include <stdio.h>
#include <string.h>
#include "Signature.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "PublicKey.hpp"

using Netca::CSignature;
using Netca::CBlob;
using Netca::CPKIException;
using Netca::CCertificate;
using Netca::CPublicKey;

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static CCertificate GetCert(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);

int main(int argc,char **argv)
{
	int algo;
	FILE *fp=0;
	unsigned char buf[8192];
	int len;
	int rv;
	unsigned char *signValue=0;
	int signLen;
	
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

	try
	{
		CCertificate cert=GetCert(argv[2]);
		CPublicKey publicKey=cert.getPublicKey(NETCA_PKI_CERT_PURPOSE_SIGN);
		if(publicKey.isNull())
		{
			printf("get public key fail,cert not in validity,or not signature cert\n");
			return -1;
		}

		CSignature sign(publicKey,algo);
		
		fp=fopen(argv[3],"rb");
		if(fp==0)
		{
			printf("open %s fail\n",argv[3]);
			return -1;
		}

		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fp);

			if(ferror(fp)!=0)
			{
				fclose(fp);
				fp=0;
				printf("fread fail\n");
				return -1;
			}

			if(len>0)
			{
				sign.update(buf,len);
			}

			if(feof(fp))
			{
				break;
			}
		}
		fclose(fp);
		fp=0;

		rv=ReadFileData(argv[4],&signValue,&signLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[4]);
			return -1;
		}
		
		bool b=sign.verify(signValue,signLen);
		NetcaPKICryptoFreeMemory(signValue);
		signValue=0;
		if(b==false)
		{
			printf("Verify Fail\n");
		}
		else
		{
			printf("Verify OK\n");
		}
		
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fp)
		{
			fclose(fp);
		}

		if(signValue)
		{
			NetcaPKICryptoFreeMemory(signValue);
		}
		printf("verify fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s sha1withRSA|sha256withRSA cert tbs signature",fileName);
}

CCertificate GetCert(const char *fileName)
{
	unsigned char *buf;
	int bufLen;
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	CCertificate certObj;
	rv=ReadFileData(fileName,&buf,&bufLen);
	if(rv==0)
	{
		throw CPKIException("read cert file fail");
	}

	cert= NetcaPKICertNewCert(buf,bufLen);
	NetcaPKICryptoFreeMemory(buf);
	certObj.attach(cert);
	return certObj;
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
