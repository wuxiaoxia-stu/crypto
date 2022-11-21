#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"


static void usage(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE hCert;
	NETCA_PKI_KEYPAIR_HANDLE hKeyPair;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;
	int rv;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	
	rv= NetcaPKISelectCert("Decrypt","Algorithm='RSA' && CertType='Encrypt'",&hCert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}
	
	hKeyPair=NetcaPKICertGetCertKeyPair(hCert,0,NETCA_PKI_CERT_PURPOSE_ENCRYPT,0);
	NetcaPKICertFreeCert(hCert);
	if(hKeyPair==0)
	{
		printf("NetcaPKICertGetCertKeyPair fail\n");
		return -1;
	}
	
	rv=ReadFileData(argv[1],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKICryptoFreeKeypair(hKeyPair);
		printf("read %s fail\n",argv[1]);
		return -1;
	}
	
	rv=NetcaPKICryptoPrivateKeyDecrypt(hKeyPair,NETCA_PKI_ALGORITHM_RSA_PKCS1_V1_5_ENC,
		0,buf,bufLen,&out,&outLen);
	NetcaPKICryptoFreeKeypair(hKeyPair);
	NetcaPKICryptoFreeMemory(buf);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoPrivateKeyDecrypt fail\n");
		return -1;
	}
	rv=SaveFile(argv[2],out,outLen);
	NetcaPKICryptoFreeMemory(out);
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
