#include <stdio.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "PublicKey.hpp"

using Netca::CPublicKey;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *filename);
static CCertificate GetCert(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	unsigned char *buf=0;
	int bufLen;
	CBlob out;
	int rv;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CCertificate cert=GetCert(argv[1]);
		CPublicKey publicKey=cert.getPublicKey(NETCA_PKI_CERT_PURPOSE_ENCRYPT);
		if(publicKey.isNull())
		{
			printf("get public key fail,cert not in validity,or not encrypt cert\n");
			return -1;
		}
		
		rv=ReadFileData(argv[2],&buf,&bufLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[2]);
			return -1;
		}
		
		publicKey.encrypt(NETCA_PKI_ALGORITHM_RSA_PKCS1_V1_5_ENC,buf,bufLen,out);
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

		printf("encrypt fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}


void usage(const char *filename)
{
	printf("Usage: %s certFileName clearFileName cipherFileName",filename);
}

CCertificate GetCert(const char *fileName)
{
	unsigned char *buf;
	int bufLen;
	int rv;
	CCertificate certObj;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	rv=ReadFileData(fileName,&buf,&bufLen);
	if(rv==0)
	{
		throw CPKIException("read cert fail fail");
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


