#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"


static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);

void Usage(const char *progName)
{
	printf("Usage: %s data tokenFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	const char* data;
	const char* tokenFileName;
	unsigned char *token;
	int tokenLen;
	char *t;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}

	data=argv[1];
	tokenFileName=argv[2];
	
	rv=ReadFileData(tokenFileName,&token,&tokenLen);
	if(rv==0)
	{
		printf("Read token file fail\n");
		return -1;
	}
	
	t=NetcaPKIAppTimeStampVerifyToken((const unsigned char *)data,(int)strlen(data),
		token,tokenLen,NULL);
	NetcaPKICryptoFreeMemory(token);
	if(t==0)
	{
		printf("NetcaPKIAppTimeStampVerifyToken fail,return %d\n",rv);
		return -1;
	}
	
	printf("Verify TimeStamp Success\n");
	printf("TimeStamp:%s\n",t);
	NetcaPKICryptoFreeMemory(t);
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


