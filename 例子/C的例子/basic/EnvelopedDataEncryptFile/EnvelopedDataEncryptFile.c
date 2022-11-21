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
	printf("Usage: %s certFileName clearTextFileName cipherTextFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	const char* certFileName;
	const char* clearTextFileName;
	const char* cipherTextFileName;
	unsigned char *cipherText;
	int cipherTextLen;
	int isUseSubjectKeyId;
	NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData;
	int flag;
	FILE *fIn;
	FILE *fOut;
	unsigned char buf[8192];
	int len;

	if(argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName=argv[1];
	clearTextFileName=argv[2];
	cipherTextFileName=argv[3];


	hEnvelopedData=NetcaPKIAppNewEnvelopedDataEncryptHandle();
	if(hEnvelopedData==0)
	{
		printf("NetcaPKIAppNewEnvelopedDataEncryptHandle fail\n");
		return -1;
	}
	isUseSubjectKeyId=NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier();
	flag= isUseSubjectKeyId? NETCA_PKI_ENVELOPEDDATA_FLAG_USEKEYID:0;
	
	cert=GetCert(certFileName);
	if(cert==NULL)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("Bad cert file\n");
		return -1;
	}
	
	rv=NetcaPKIMsgEnvelopedDataAddCert(hEnvelopedData,cert,flag);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataAddCert fail\n");
		return -1;
	}

	fIn=fopen(clearTextFileName,"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("open %s fail\n",clearTextFileName);
		return -1;
	}

	fOut=fopen(cipherTextFileName,"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		printf("open %s fail\n",cipherTextFileName);
		return -1;
	}
	
	rv=NetcaPKIMsgEnvelopedDataEncryptInit(hEnvelopedData,&cipherText,&cipherTextLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataEncryptInit fail\n");
		return -1;
	}

	if((int)fwrite(cipherText,1,cipherTextLen,fOut)!=cipherTextLen)
	{
		fclose(fIn);
		fclose(fOut);
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		NetcaPKICryptoFreeMemory(cipherText);
		printf("fwrite fail\n");
		return -1;
	}
	NetcaPKICryptoFreeMemory(cipherText);

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fIn);
		if(ferror(fIn)!=0)
		{
			fclose(fIn);
			fclose(fOut);
			NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKIMsgEnvelopedDataEncryptUpdate(hEnvelopedData,buf,len,&cipherText,&cipherTextLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
				printf("NetcaPKIMsgEnvelopedDataEncryptUpdate fail\n");
				return -1;
			}

			if(cipherTextLen>0)
			{
				if((int)fwrite(cipherText,1,cipherTextLen,fOut)!=cipherTextLen)
				{
					fclose(fIn);
					fclose(fOut);
					NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
					NetcaPKICryptoFreeMemory(cipherText);
					printf("fwrite fail\n");
					return -1;
				}

			}
			NetcaPKICryptoFreeMemory(cipherText);
		}

		if(feof(fIn))
		{
			break;
		}
	}
	fclose(fIn);

	rv=NetcaPKIMsgEnvelopedDataEncryptFinal(hEnvelopedData,&cipherText,&cipherTextLen);
	NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataEncryptFinal fail\n");
		return -1;
	}

	if(cipherTextLen>0)
	{
		if((int)fwrite(cipherText,1,cipherTextLen,fOut)!=cipherTextLen)
		{
			fclose(fOut);
			NetcaPKICryptoFreeMemory(cipherText);
			printf("fwrite fail\n");
			return -1;
		}

	}
	NetcaPKICryptoFreeMemory(cipherText);
	fclose(fOut);

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

