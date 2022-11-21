#include <stdio.h>
#include <string.h>
#include "Hash.hpp"
#include "TimeStamp.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"


using Netca::CTimeStamp;
using Netca::CPKIException;
using Netca::CHash;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static int Hash(int algo,const char *fileName,CBlob &hashValue);
static std::string utf8Toansi(const std::string &str);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *token=0;
	int tokenLen;
	int algo;
	CBlob md;
	CBlob md2;
	
	
	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	rv=ReadFileData(argv[2],&token,&tokenLen);
	if(rv==0)
	{
		printf("read %s fail\n",argv[2]);
		return -1;
	}
	try
	{
		CTimeStamp timestamp(token,tokenLen);
		NetcaPKICryptoFreeMemory(token);
		token=0;
		algo=timestamp.getHashAlgorithm();
		rv=Hash(algo,argv[1],md);
		if(rv==0)
		{
			printf("Hash fail\n");
			return -1;
		}

		timestamp.getMessageImprint(md2);
		if(md2.length()!=md.length())
		{
			printf("hash value mismatch\n");
			return -1;
		}

		if(memcmp(md.data(),md2.data(),md.length())!=0)
		{
			printf("hash value mismatch\n");
			return -1;
		}
		
		printf("timestamp time:%s\n",timestamp.getTimeString().c_str());
		CCertificate cert=timestamp.getTSACert();
		
		printf("subject:%s\n",utf8Toansi(cert.getSubject()).c_str());
		
		return 0;
	}
	catch(CPKIException& e)
	{
		if(token)
		{
			NetcaPKICryptoFreeMemory(token);
		}

		printf("verify timestamp fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}


void usage(const char *fileName)
{
	printf("Usage: %s infile token\n",fileName);
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

int Hash(int algo,const char *fileName,CBlob &hashValue)
{
	unsigned char buf[8192];
	int len;
	FILE *fp=0;

	try
	{
		CHash hashObj(algo);

		fp=fopen(fileName,"rb");
		if(fp==0)
		{
			return 0;
		}

		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fp);
			if(ferror(fp)!=0)
			{
				fclose(fp);
				return 0;
			}
			if(len>0)
			{
				hashObj.update(buf,len);
			}
			if(feof(fp))
			{
				break;
			}
		}
		fclose(fp);
		fp=0;
		hashObj.final(hashValue);
		return 1;
	
	}
	catch(CPKIException& )
	{
		if(fp)
		{
			fclose(fp);
		}
		return 0;
	}
}

std::string utf8Toansi(const std::string &str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *mbs;
	long mbsLen;

	ustr=netca_ustring_newutf8((const unsigned char *)str.data(),(long)str.length());
	if(ustr==0)
	{
		throw CPKIException("netca_ustring_newutf8 fail");
	}

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		netca_ustring_free(ustr);
		throw CPKIException("netca_ustring_getdefaultcharset fail");
	}

	rv=netca_ustring_tombs(ustr,charset,&mbs,&mbsLen);
	NETCA_FREE(charset);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		throw CPKIException("netca_ustring_tombs fail");
	}
	
	try
	{
		std::string retStr((char *)mbs,(int)mbsLen);
		NETCA_FREE(mbs);
		mbs=0;
		return retStr;
	}
	catch(...)
	{
		if(mbs)
		{
			NETCA_FREE(mbs);
		}
		throw;
	}
}
