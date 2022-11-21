#include <stdio.h>
#include <string.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "Keypair.hpp"

using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;
using Netca::CKeypair;

static void usage(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	
	unsigned char *buf=0;
	int bufLen;
	CBlob out;
	int rv;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	
	try
	{

		CCertificate cert=CCertificate::SelectCert("Decrypt","Algorithm='RSA' && CertType='Encrypt'");
		if(cert.isNull())
		{
			printf("select cert fail\n");
			return -1;
		}
		CKeypair keypair=cert.getKeypair(0,NETCA_PKI_CERT_PURPOSE_ENCRYPT);
		if(keypair.isNull())
		{
			printf("get keypair fail\n");
			return -1;
		}
		rv=ReadFileData(argv[1],&buf,&bufLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[1]);
			return -1;
		}
		
		keypair.decrypt(NETCA_PKI_ALGORITHM_RSA_PKCS1_V1_5_ENC,buf,bufLen,out);
		NetcaPKICryptoFreeMemory(buf);
		buf=0;
		rv=SaveFile(argv[2],out.data(),out.length());
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

		printf("rsa decrypt fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}


void usage(const char *fileName)
{
	printf("Usage: %s cipherFileName clearFileName",fileName);
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
