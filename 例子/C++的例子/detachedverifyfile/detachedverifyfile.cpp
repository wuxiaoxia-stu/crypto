#include <stdio.h>
#include <string.h>
#include "SignedData.hpp"
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CSignedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static std::string utf8Toansi(const std::string &str);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);

int main(int argc,char **argv)
{
	int rv;
	FILE *fIn=0;
	unsigned char buf[8192];
	int len;
	unsigned char *sign=0;
	int signLen;


	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	
	rv=ReadFileData(argv[2],&sign,&signLen);
	if(rv==0)
	{
		printf("read %s fail\n",argv[2]);
		return -1;
	}

	try
	{
		CSignedData signedData(false);
			
		fIn=fopen(argv[1],"rb");
		if(fIn==0)
		{
			NetcaPKICryptoFreeMemory(sign);
			sign=0;
			printf("open %s fail\n",argv[1]);
			return -1;
		}

		signedData.detachedVerifyInit	(sign,signLen);
		NetcaPKICryptoFreeMemory(sign);
		sign=0;
		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fIn);
			if(ferror(fIn)!=0)
			{
				fclose(fIn);
				fIn=0;
				printf("fread fail\n");
				return -1;
			}

			if(len>0)
			{
				signedData.detachedVerifyUpdate(buf,len);
			}
			if(feof(fIn))
			{
				break;
			}
		}
		fclose(fIn);
		fIn=0;

		rv=signedData.detachedVerifyFinal();
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("NetcaPKIMsgSignedDataDetachedVerifyFinal fail\n");
			return -1;
		}
		

		CCertificate cert=signedData.getSignCert(0);
		
		printf("Verify Success\nThe subject of sign cert is %s\n",(utf8Toansi(cert.getSubject())).c_str());
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fIn)
		{
			fclose(fIn);
		}

		if(sign)
		{
			NetcaPKICryptoFreeMemory(sign);
		}
		printf("detached verify fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s tbsFile signFile\n",fileName);
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

