#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static int PrintClearText(const unsigned char *data,int dataLen);

void Usage(const char *progName)
{
	printf("Usage: %s cipherTextFileName clearTextFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	unsigned char* clearText;
	int clearTextLen;
	const char* clearTextFileName;
	const char* cipherTextFileName;
	NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData;
	FILE *fIn;
	FILE *fOut;
	unsigned char buf[8192];
	int len;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}
	cipherTextFileName=argv[1];
	clearTextFileName=argv[2];

	hEnvelopedData= NetcaPKIAppNewEnvelopedDataDecryptHandle();
	if(hEnvelopedData==0)
	{
		printf("NetcaPKIAppNewEnvelopedDataDecryptHandle fail\n");
		return -1;
	}

	fIn=fopen(cipherTextFileName,"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("open %s fail\n",cipherTextFileName);
		return -1;
	}

	fOut=fopen(clearTextFileName,"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		printf("open %s fail\n",clearTextFileName);
		return -1;
	}

	rv=NetcaPKIMsgEnvelopedDataDecryptInit(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataDecryptInit fail\n");
		return -1;
	}

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
			rv=NetcaPKIMsgEnvelopedDataDecryptUpdate(hEnvelopedData,buf,len,&clearText,&clearTextLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
				printf("NetcaPKIMsgEnvelopedDataDecryptUpdate fail\n");
				return -1;
			}

			if(clearTextLen>0)
			{
				if((int)fwrite(clearText,1,clearTextLen,fOut)!=clearTextLen)
				{
					fclose(fIn);
					fclose(fOut);
					NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
					NetcaPKICryptoFreeMemory(clearText);
					printf("fwrite fail\n");
					return -1;
				}

			}
			NetcaPKICryptoFreeMemory(clearText);
		}

		if(feof(fIn))
		{
			break;
		}
	}
	fclose(fIn);
	fclose(fOut);

	rv=NetcaPKIMsgEnvelopedDataDecryptFinal(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataDecryptFinal fail\n");
		return -1;
	}
	rv=NetcaPKIAppEnvelopedDataDecryptPostCheck(hEnvelopedData);
	NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppEnvelopedDataDecryptPostCheck fail,return %d\n",rv);
		return -1;
	}
	
	printf("Decrypt Success\n");
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
