#include <stdio.h>
#include <string.h>
#include "SignedData.hpp"
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

using Netca::CSignedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *buf=0;
	int bufLen;
	CBlob out;
	int algo;
	const char *filter;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	
	try
	{
		CSignedData signedData(false);
		signedData.setKeepTbs(true);
		
		rv=ReadFileData(argv[2],&buf,&bufLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[2]);
			return -1;
		}
		rv=signedData.verify(buf,bufLen,out);
		NetcaPKICryptoFreeMemory(buf);
		buf=0;
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("NetcaPKIMsgSignedDataVerify fail\n");
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
		CCertificate cert=CCertificate::SelectCert("Signature",filter);
		if(cert.isNull())
		{
			printf("select cert fail\n");
			return -1;
		}
		signedData.countersign(0,algo,cert,out);
		rv=SaveFile(argv[3],out.data(),out.length());
		if(rv==0)
		{
			printf("SaveFile fail\n");
			return -1;
		}
	}
	catch(CPKIException& e)
	{
		if(buf)
		{
			NetcaPKICryptoFreeMemory(buf);
		}
		printf("countsign fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
	printf("Success\n");
	return 0;

}

void usage(const char *fileName)
{
	printf("Usage: %s sha1withRSA|sha256withRSA oldsign newFile\n",fileName);
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

