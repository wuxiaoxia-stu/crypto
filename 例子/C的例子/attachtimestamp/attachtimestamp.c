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
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);
static int GetHashAlgoFromName(const char *algoName);

int main(int argc,char **argv)
{
	NETCA_PKI_SIGNEDDATA_HANLDE hSignedData;
	int rv;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;
	const char *url;
	int hashAlgo;

	if(argc!=5)
	{
		usage(argv[0]);
		return -1;
	}

	url=argv[1];
	hashAlgo=GetHashAlgoFromName(argv[2]);
	if(hashAlgo==-1)
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

	rv=ReadFileData(argv[3],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("read %s fail\n",argv[3]);
		return -1;
	}


	rv=NetcaPKIMsgSignedDataVerify(hSignedData,buf,bufLen,&out,&outLen);
	NetcaPKICryptoFreeMemory(buf);
	
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataVerify fail\n");
		return -1;
	}
	NetcaPKICryptoFreeMemory(out);
	rv=NetcaPKIMsgSignedDataAttachSignatureTimeStamp(hSignedData,0,hashAlgo,url);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataAttachSignatureTimeStamp fail\n");
		return -1;
	}

	rv=NetcaPKIMsgSignedDataEncode(hSignedData,&out,&outLen);
	NetcaPKIMsgFreeSignedData(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgFreeSignedData fail\n");
		return -1;
	}
	rv=SaveFile(argv[4],out,outLen);
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
	printf("Usage: %s url sha-1|sha-256|sm3 oldSignFile newSignFile\n",fileName);
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

int GetHashAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5;
	}
	else if(STRINGCASECMP(algoName,"sha1")==0
		|| STRINGCASECMP(algoName,"sha-1")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1;
	}
	else if(STRINGCASECMP(algoName,"sha256")==0
		|| STRINGCASECMP(algoName,"sha-256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256;
	}
	else if(STRINGCASECMP(algoName,"sha512")==0
		|| STRINGCASECMP(algoName,"sha-512")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512;
	}
	else if(STRINGCASECMP(algoName,"sm3")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3;
	}
	else if(STRINGCASECMP(algoName,"sha224")==0
		|| STRINGCASECMP(algoName,"sha-224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA224;
	}
	else if(STRINGCASECMP(algoName,"sha384")==0
		|| STRINGCASECMP(algoName,"sha-384")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA384;
	}
	else if(STRINGCASECMP(algoName,"sha-512/224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_224;
	}
	else if(STRINGCASECMP(algoName,"sha-512/256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_256;
	}
	else
	{
		return -1;
	}
}
