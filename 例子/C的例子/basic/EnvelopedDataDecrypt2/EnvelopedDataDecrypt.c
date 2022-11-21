#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static int PrintClearText(const unsigned char *data,int dataLen);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);

void Usage(const char *progName)
{
	printf("Usage: %s certFileName pwd cipherTextFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	unsigned char* clearText;
	int clearTextLen;
	const char* cipherTextFileName;
	unsigned char *cipherText;
	int cipherTextLen;
	const char *certFileName;
	const char *pwd;
	NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData;
	NETCA_PKI_CERTIFICATE_HANDLE cert;

	if(argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName=argv[1];
	pwd=argv[2];
	cipherTextFileName=argv[3];

	cert=GetCert(certFileName);
	if(cert==NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}

	rv=NetcaPKIAppCertGetKeypair(cert,pwd,NULL);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("NetcaPKIAppCertGetKeypair fail,return %d\n",rv);
		return -1;
	}

	rv=NetcaPKIConfigEnvelopedDataSetDecryptCert(cert);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIConfigEnvelopedDataSetDecryptCert fail,return %d\n",rv);
		return -1;
	}

	rv=ReadFileData(cipherTextFileName,&cipherText,&cipherTextLen);
	if(rv==0)
	{
		printf("Read cipherText file fail\n");
		return -1;
	}

	rv=NetcaPKIAppEnvelopedDataDecrypt(cipherText,cipherTextLen,&clearText,&clearTextLen,NULL);
	NetcaPKICryptoFreeMemory(cipherText);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppEnvelopedDataDecrypt fail,return %d\n",rv);
		return -1;
	}
	
	/* 假定密文是使用EnvelopedDataEncrypt加密得到的，这时明文是可显示的*/
	rv=PrintClearText(clearText,clearTextLen);
	NetcaPKICryptoFreeMemory(clearText);
	if(rv==0)
	{
		printf("Print clearText fail\n");
		return -1;
	}
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

int PrintClearText(const unsigned char *data,int dataLen)
{
	char *buf;

	buf=(char *)NetcaPKICryptoAllocMemory(dataLen+1);
	if(buf==0)
	{
		return 0;
	}
	memcpy(buf,data,dataLen);
	buf[dataLen]='\0';
	printf("%s\n",buf);
	NetcaPKICryptoFreeMemory(buf);
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


