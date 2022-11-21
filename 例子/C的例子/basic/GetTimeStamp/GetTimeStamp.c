#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"


static void Usage(const char *progName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

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
	NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
	char *t;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}

	data=argv[1];
	tokenFileName=argv[2];
	
	
	rv=NetcaPKIAppTimeStampGetToken((const unsigned char *)data,(int)strlen(data),
		&token,&tokenLen,&hTimeStamp);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppTimeStampGetToken fail,return %d\n",rv);
		return -1;
	}
	
	t=NetcaPKIMsgTimeStampGetTime(hTimeStamp);
	NetcaPKIMsgFreeTimeStamp(hTimeStamp);
	if(t==0)
	{
		NetcaPKICryptoFreeMemory(token);
		printf("NetcaPKIMsgTimeStampGetTime fail\n");
		return -1;
	}
	rv=SaveFile(tokenFileName,token,tokenLen);
	NetcaPKICryptoFreeMemory(token);
	if(rv==0)
	{
		NetcaPKICryptoFreeMemory(t);
		printf("Save file fail\n");
		return -1;
	}
	printf("TimeStamp:%s\n",t);
	NetcaPKICryptoFreeMemory(t);
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

