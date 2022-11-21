#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"


static void usage(const char *filename);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE hCert;
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;
	int rv;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}

	hCert=GetCert(argv[1]);
	if(hCert==0)
	{
		printf("bad cert file\n");
		return -1;
	}
	hPublicKey=NetcaPKICertGetCertPublicKey(hCert,NETCA_PKI_CERT_PURPOSE_ENCRYPT);
	NetcaPKICertFreeCert(hCert);

	if(hPublicKey==0)
	{
		printf("NetcaPKICertGetCertKeyPair fail,cert not in validity,or not encrypt cert\n");
		return -1;
	}
	

	rv=ReadFileData(argv[2],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKICryptoFreePublicKey(hPublicKey);
		printf("read %s fail\n",argv[2]);
		return -1;
	}
	
	rv=NetcaPKICryptoPublicKeyEncrypt(hPublicKey,NETCA_PKI_ALGORITHM_RSA_PKCS1_V1_5_ENC,
		0,buf,bufLen,&out,&outLen);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	NetcaPKICryptoFreeMemory(buf);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoPublicKeyEncrypt fail\n");
		return -1;
	}
	rv=SaveFile(argv[3],out,outLen);
	NetcaPKICryptoFreeMemory(out);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}

	printf("Success\n");
	return 0;
}


void usage(const char *filename)
{
	printf("Usage: %s certFileName clearFileName cipherFileName",filename);
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


