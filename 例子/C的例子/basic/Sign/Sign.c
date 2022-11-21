#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

void Usage(const char *progName)
{
	printf("Usage: %s tbsData signatureFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	const char* tbs;
	const char* signatureFileName;
	unsigned char *signature;
	int signatureLen;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}
	tbs=argv[1];
	signatureFileName=argv[2];

	cert=NetcaPKIAppGetUserCert(NETCA_PKI_GET_USER_CERT_TYPE_SIGN,NULL);
	if(cert==NULL)
	{
		printf("Get sign cert fail\n");
		return -1;
	}
	rv=NetcaPKIAppSign(cert,(const unsigned char*)tbs,(int)strlen(tbs),
		&signature,&signatureLen);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppSign fail,return %d\n",rv);
		return -1;
	}
	rv=SaveFile(signatureFileName,signature,signatureLen);
	NetcaPKICryptoFreeMemory(signature);
	if(rv==0)
	{
		printf("Save file fail\n");
		return -1;
	}
	printf("Sign Success\n");
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
