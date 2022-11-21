#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif


static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_SIGNEDDATA_HANLDE hSignedData;
	int rv;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;
	int algo;
	const char *filter;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}

	algo=NETCA_PKI_ALGORITHM_SM3WITHSM2;
	filter="Algorithm='SM2'";
	
	rv= NetcaPKISelectCert("Signature",filter,&cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}

	hSignedData=NetcaPKIMsgNewSignedData(1);
	if(hSignedData==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("NetcaPKIMsgNewSignedData fail\n");
		return -1;
	}
	rv=NetcaPKIMsgSignedDataSetSignCert(hSignedData,cert,0);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataSetSignCert fail\n");
		return -1;
	}
	
	
	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGN_ALGO,
		0,algo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set sign algorithm fail\n");
		return -1;
	}
	

	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGTIME,
		0,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set signing time fail\n");
		return -1;
	}

	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SM2_Q7,
		-1,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set use q7 fail\n");
		return -1;
	}

	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SM2SIGN_OID,
		0,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set use sm2 sign oid fail\n");
		return -1;
	}
	

	rv=ReadFileData(argv[1],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("read %s fail\n",argv[1]);
		return -1;
	}

	rv=NetcaPKIMsgSignedDataSign(hSignedData,buf,bufLen,&out,&outLen);
	NetcaPKICryptoFreeMemory(buf);
	NetcaPKIMsgFreeSignedData(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgSignedDataSign fail\n");
		return -1;
	}

	rv=SaveFile(argv[2],out,outLen);
	NetcaPKICryptoFreeMemory(out);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}
	
	printf("Success\n");
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s inFileName outFileName\n",fileName);
}

NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName)
{
	unsigned char *buf;
	int bufLen;
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	rv=ReadFileData(fileName,&buf,&bufLen);
	if(rv==0)
	{
		return 0;
	}

	cert= NetcaPKICertNewCert(buf,bufLen);
	NetcaPKICryptoFreeMemory(buf);
	return cert;
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
