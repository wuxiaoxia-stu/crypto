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
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	int rv;
	int hashAlgo;
	int status;
	CBlob token;
	CBlob hashValue;

	if(argc!=5)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CTimeStamp timestamp;
		timestamp.setTSA(argv[1]);
		
		hashAlgo=CHash::GetHashAlgorithm(argv[2]);
		if(hashAlgo==CHash::INVALID_HASH_ALGORITHM)
		{
			printf("NetcaPKIMsgTimeStampSetTSA fail\n");
			return -1;
		}

		timestamp.setHashAlgorithm(hashAlgo);
		rv=Hash(hashAlgo,argv[3],hashValue);
		if(rv==0)
		{
			printf("Hash fail\n");
			return -1;
		}

		timestamp.setMessageImprint(hashValue);
		
		rv=timestamp.getResponse(status);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("NetcaPKIMsgTimeStampGetResponse fail\n");
			return -1;
		}

		if(status!=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTED
			&& status !=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
		{
			printf("get timestamp resp fail,return status %d\n",status);
			return -1;
		}

		printf("timestamp time:%s\n",timestamp.getTimeString().c_str());
		
		CCertificate cert=timestamp.getTSACert();
		printf("subject:%s\n",(utf8Toansi(cert.getSubject())).c_str());
		
		timestamp.getTimeStampToken(token);
		rv=SaveFile(argv[4],token.data(),token.length());
		if(rv==0)
		{
			printf("SaveFile fail\n");
			return -1;
		}

		return 0;
	}
	catch(CPKIException& e)
	{
		printf("get timestamp fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s url sha-1|sha-256|sm3 infile token\n",fileName);
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

