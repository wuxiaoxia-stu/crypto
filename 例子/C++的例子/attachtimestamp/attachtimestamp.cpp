#include <stdio.h>
#include "SignedData.hpp"
#include "Hash.hpp"
#include "PKIException.hpp"


using Netca::CBlob;
using Netca::CPKIException;
using Netca::CHash;
using Netca::CSignedData;


static void usage(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *buf=0;
	int bufLen;
	const char *url;
	int hashAlgo;

	if(argc!=5)
	{
		usage(argv[0]);
		return -1;
	}

	url=argv[1];
	hashAlgo=CHash::GetHashAlgorithm(argv[2]);
	if(hashAlgo==CHash::INVALID_HASH_ALGORITHM)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CSignedData signedData(false);
		signedData.setKeepTbs(true);
		
		rv=ReadFileData(argv[3],&buf,&bufLen);
		if(rv==0)
		{
			printf("read %s fail\n",argv[3]);
			return -1;
		}

		CBlob out;
		rv=signedData.verify(buf,bufLen,out);
		NetcaPKICryptoFreeMemory(buf);
		buf=0;
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("NetcaPKIMsgSignedDataVerify fail\n");
			return -1;
		}
		
		signedData.attachSignatureTimeStamp(0,hashAlgo,url);
		signedData.encode(out);
		rv=SaveFile(argv[4],out.data(),out.length());
		if(rv==0)
		{
			printf("SaveFile fail\n");
			return -1;
		}
	}
	catch(CPKIException& e)
	{
		if(buf)
		{
			NetcaPKICryptoFreeMemory(buf);
		}
		printf("attch timestamp fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
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
