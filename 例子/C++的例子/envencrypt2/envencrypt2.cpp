#include <stdio.h>
#include <string.h>
#include "EnvelopedData.hpp"
#include "Certificate.hpp"
#include "PKIException.hpp"

using Netca::CEnvelopedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static CCertificate GetCert(const char *fileName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *buf=0;
	int bufLen;
	CBlob out;
	
	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	
	try
	{
		CCertificate cert=GetCert(argv[1]);
		
		CEnvelopedData env(true);
		env.setEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_ALGORITHM_AES128CBC);
		env.addCert(cert);
		
		rv=ReadFileData(argv[2],&buf,&bufLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[2]);
			return -1;
		}
		
		env.encrypt(buf,bufLen,out);
		NetcaPKICryptoFreeMemory(buf);
		buf=0;
		
		rv=SaveFile(argv[3],out.data(),out.length());
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
		if(buf)
		{
			NetcaPKICryptoFreeMemory(buf);
		}

		printf("encrypt  fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s cert infile outfile",fileName);
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
		throw CPKIException("open cert file fail");
	}

	cert= NetcaPKICertNewCert(buf,bufLen);
	NetcaPKICryptoFreeMemory(buf);
	certObj.attach(cert);
	return certObj;
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
