#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

void Usage(const char *progName)
{
	printf("Usage: %s certFileName clearText cipherTextFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	const char* certFileName;
	const char* clearText;
	const char* cipherTextFileName;
	unsigned char *cipherText;
	int cipherTextLen;

	if(argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName=argv[1];
	clearText=argv[2];
	cipherTextFileName=argv[3];

	cert=GetCert(certFileName);
	if(cert==NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}
	rv=NetcaPKIAppCertEncrypt(cert,(const unsigned char *)clearText,(int)strlen(clearText),
		&cipherText,&cipherTextLen);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppCertEncrypt fail,return %d\n",rv);
		return -1;
	}
	rv=SaveFile(cipherTextFileName,cipherText,cipherTextLen);
	NetcaPKICryptoFreeMemory(cipherText);
	if(rv==0)
	{
		printf("Save file fail\n");
		return -1;
	}
	printf("Encrypt Success\n");
	return 0;
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

NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	unsigned char *data;
	int dataLen;
	int rv;

	rv=ReadFileData(fileName,&data,&dataLen);
	if(rv==0)
	{
		return NULL;
	}
	cert=NetcaPKICertNewCert(data,dataLen);
	NetcaPKICryptoFreeMemory(data);
	return cert;
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

