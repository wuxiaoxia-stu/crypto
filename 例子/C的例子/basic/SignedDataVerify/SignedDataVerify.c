#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"


static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);


void Usage(const char *progName)
{
	printf("Usage: %s tbsData signedDataFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	const char* tbs;
	const char* signedDataFileName;
	unsigned char *signedData;
	int signedDataLen;
	NETCA_PKI_SIGNEDDATA_HANDLE hSignedData;
	int count;
	int i;
	int hasTimeStamp;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}

	tbs=argv[1];
	signedDataFileName=argv[2];
	
	rv=ReadFileData(signedDataFileName,&signedData,&signedDataLen);
	if(rv==0)
	{
		printf("Read signedData file fail\n");
		return -1;
	}


	rv=NetcaPKIAppSignedDataVerify(NULL,(const unsigned char *)tbs,(int)strlen(tbs),
		signedData,signedDataLen,&hSignedData);
	NetcaPKICryptoFreeMemory(signedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppSignedDataVerify fail,return %d\n",rv);
		return -1;
	}
	
	printf("Verify Success\n");
	rv=NetcaPKIMsgSignedDataGetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_COUNT,-1,&count);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("Get signer count fail,return %d\n",rv);
		return -1;
	}
	printf("Signer Count:%d\n",count);
	for(i=0;i<count;i++)
	{
		rv=NetcaPKIMsgSignedDataGetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_HAS_TSATIME,i,&hasTimeStamp);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKIMsgFreeSignedData(hSignedData);
			printf("Get hasTimeStamp fail,return %d\n",rv);
			return -1;
		}
		if(hasTimeStamp)
		{
			rv=NetcaPKIMsgSignedDataVerifyTimeStamp(hSignedData,i,NULL);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				printf("Signer(%d) verify timestamp fail,return %d\n",i,rv);
			}
			else
			{
				char *t;
				rv=NetcaPKIMsgSignedDataGetStringAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_TSATIME,i,&t);
				if(rv!=NETCA_PKI_SUCCESS)
				{
					printf("Signer(%d) get timestamp fail,return %d\n",i,rv);
				}
				else
				{
					printf("Signer(%d) timestamp %s\n",i,t);
					NetcaPKICryptoFreeMemory(t);
				}


			}
		}
		else
		{
			printf("Signer(%d) has not timestamp\n",i);
		}
	}
	NetcaPKIMsgFreeSignedData(hSignedData);
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

