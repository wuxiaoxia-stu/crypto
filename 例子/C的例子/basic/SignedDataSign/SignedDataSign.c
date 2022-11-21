#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"


static void Usage(const char *progName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

void Usage(const char *progName)
{
	printf("Usage: %s [-detached] tbsData signedDataFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	const char* tbs;
	const char* signedDataFileName;
	unsigned char *signedData;
	int signedDataLen;
	int detached;
	int pos;

	if(argc!=3 && argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}

	if(argc==4)
	{
		if(strcmp(argv[1],"-detached")==0 ||
			strcmp(argv[1],"/detached")==0)
		{
			detached=1;
		}
		else
		{
			Usage(argv[0]);
			return -1;
		}
		pos=2;
	}
	else
	{
		pos=1;
		detached=0;
	}
	
	tbs=argv[pos];
	pos++;
	signedDataFileName=argv[pos];
	
	cert=NetcaPKIAppGetUserCert(NETCA_PKI_GET_USER_CERT_TYPE_SIGN,NULL);
	if(cert==NULL)
	{
		printf("Get sign cert fail\n");
		return -1;
	}
	rv=NetcaPKIAppSignedDataSign(cert,detached,(const unsigned char*)tbs,(int)strlen(tbs),
		&signedData,&signedDataLen,NULL);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIAppSignedDataSign fail,return %d\n",rv);
		return -1;
	}
	rv=SaveFile(signedDataFileName,signedData,signedDataLen);
	NetcaPKICryptoFreeMemory(signedData);
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

