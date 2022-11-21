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
	printf("Usage: %s tbsData oldSignedDataFileName newSignedDataFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	const char* tbs;
	const char* oldSignedDataFileName;
	const char* newSignedDataFileName;
	unsigned char *signedData;
	int signedDataLen;
	NETCA_PKI_SIGNEDDATA_HANDLE hSignedData;
	

	if(argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}

	tbs=argv[1];
	oldSignedDataFileName=argv[2];
	newSignedDataFileName=argv[3];

	rv=ReadFileData(oldSignedDataFileName,&signedData,&signedDataLen);
	if(rv==0)
	{
		printf("Read old signedData file fail\n");
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
	rv=NetcaPKIAppSignedDataAttachTimeStamp(hSignedData,&signedData,&signedDataLen);
	NetcaPKIMsgFreeSignedData(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppSignedDataAttachTimeStamp fail,return %d\n",rv);
		return -1;
	}
	rv=SaveFile(newSignedDataFileName,signedData,signedDataLen);
	NetcaPKICryptoFreeMemory(signedData);
	if(rv==0)
	{
		printf("Save file fail\n");
		return -1;
	}
	printf("Attach TimeStamp Success\n");
	return 0;
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

