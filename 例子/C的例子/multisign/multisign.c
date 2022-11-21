#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif


static void usage(const char *fileName);
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
	int count;
	unsigned char *tbs;
	int tbsLen;
	int algo;
	const char *filter;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}

	hSignedData=NetcaPKIMsgNewSignedData(0);
	if(hSignedData==0)
	{
		printf("NetcaPKIMsgNewSignedData fail\n");
		return -1;
	}

	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,
		NETCA_PKI_SIGNEDDATA_ATTRIBUTE_KEEP_TBS,-1,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set keep tbs fail\n");
		return -1;
	}

	
	rv=ReadFileData(argv[2],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("read %s fail\n",argv[2]);
		return -1;
	}

	rv=NetcaPKIMsgSignedDataVerify(hSignedData,buf,bufLen,&tbs,&tbsLen);
	NetcaPKICryptoFreeMemory(buf);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataVerify fail\n");
		return -1;
	}
	NetcaPKICryptoFreeMemory(tbs);

	algo=GetSignAlgoFromName(argv[1]);
	if(algo==-1)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		usage(argv[0]);
		return -1;
	}

	if(algo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		filter="Algorithm='SM2'";
	}
	else
	{
		filter="Algorithm='RSA'";
	}

	rv= NetcaPKISelectCert("Signature",filter,&cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}



	rv=NetcaPKIMsgSignedDataGetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGNER_COUNT,
		0,&count);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("get signer count fail\n");
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
		count,algo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set sign algo fail\n");
		return -1;
	}
	
	rv=NetcaPKIMsgSignedDataSign(hSignedData,0,0,&out,&outLen);
	NetcaPKIMsgFreeSignedData(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgSignedDataSign fail\n");
		return -1;
	}

	rv=SaveFile(argv[3],out,outLen);
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
	printf("Usage: %s sha1withRSA|sha256withRSA oldsign newFile\n",fileName);
}


int GetSignAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha1withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha256withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha512withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sm3withsm2")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3WITHSM2;
	}
	else
	{
		return -1;
	}
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
