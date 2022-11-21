#include <stdio.h>
#include "Cipher.hpp"
#include "PKIException.hpp"



using Netca::CBlob;
using Netca::CPKIException;
using Netca::CCipher;

static void usage(const char *filename);
static bool SaveFile(const char *fileName,const CBlob &blob);
static int GetFileLength(FILE *fp);

int main(int argc,char **argv)
{
	bool enc;
	FILE *fIn=0;
	unsigned char *buf=0;
	int len;
	int pos;
	CBlob out;

	if(argc!=6 && argc!=7)
	{
		usage(argv[0]);
		return -1;
	}
	
	if(strcmp(argv[1],"/e")==0 || strcmp(argv[1],"-e")==0)
	{
		enc=true;
	}
	else if(strcmp(argv[1],"/d")==0 || strcmp(argv[1],"-d")==0)
	{
		enc=false;
	}
	else
	{
		usage(argv[0]);
		return -1;
	}
	try
	{
		CCipher cipher(enc,NETCA_PKI_ALGORITHM_AES_GCM);

		CBlob key;
		key.decodeHexString(argv[2]);
		cipher.setKey(key.data(),key.length());
		
		CBlob iv;
		iv.decodeHexString(argv[3]);
		
		if(argc==6)
		{
			cipher.setGcmParam(16,iv.data(),iv.length());
			pos=4;	
		}
		else
		{
			cipher.setGcmParam(16,iv.data(),iv.length(),(const unsigned char *)argv[4],(int)strlen(argv[4]));
			pos=5;
		}
		

		cipher.init();

		fIn=fopen(argv[pos],"rb");
		if(fIn==0)
		{
			printf("open %s fail\n",argv[pos]);
			return -1;
		}
		pos++;

		len=GetFileLength(fIn);
		if(len<0)
		{
			fclose(fIn);
			fIn=0;
			printf("GetFileLength fail\n");
			return -1;
		}

		buf=(unsigned char *)NetcaPKICryptoAllocMemory(len);
		if(buf==0)
		{
			fclose(fIn);
			fIn=0;
			printf("NetcaPKICryptoAllocMemory fail\n");
			return -1;
		}
		fread(buf,1,len,fIn);
		if(ferror(fIn)!=0)
		{
			NetcaPKICryptoFreeMemory(buf);
			fclose(fIn);
			fIn=0;
			printf("fread fail\n");
			return -1;
		}
		fclose(fIn);
		fIn=0;
		
		cipher.cipher(buf,len,out);

		bool b=SaveFile(argv[pos],out);
		NetcaPKICryptoFreeMemory(buf);
		buf=0;
		if(b==false)
		{
			printf("save %s fail\n",argv[pos]);
			return -1;
		}
	
	}
	catch(CPKIException& e)
	{
		if(fIn)
		{
			fclose(fIn);
		}

		if(buf)
		{
			NetcaPKICryptoFreeMemory(buf);
		}
		
		printf("cipher fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
	if(enc)
	{
		printf("encrypt success\n");
	}
	else
	{
		printf("decrypt success\n");
	}

	return 0;
}


void usage(const char *filename)
{
	printf("Usage: %s /e|/d key iv inFileName outFileName",filename);
}

bool SaveFile(const char *fileName,const CBlob &blob)
{
	FILE *fp;
	int len;
	fp=fopen(fileName,"wb");
	if(fp==0)
	{
		return false;
	}

	len=(int)fwrite(blob.data(),1,blob.length(),fp);
	fclose(fp);
	return len==(int)blob.length();
}

int GetFileLength(FILE *fp)
{
	long  len;
	if(fseek(fp,0,SEEK_END)!=0)
	{
		return -1L;
	}
	len=ftell(fp);
	if(fseek(fp,0,SEEK_SET)!=0)
	{
		return -1L;
	}
	
	return len;
}
