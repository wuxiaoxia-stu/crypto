#include <stdio.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CCertificate;
using Netca::CPKIException;

static void usage(const char *fileName);
static CCertificate getcert(const char *fileName);
static std::string utf8Toansi(const std::string &str);

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CCertificate cert=getcert(argv[1]);
		std::vector<CCertificate> certs=cert.buildCertPath();
		for(size_t i=0;i<certs.size();i++)
		{
			printf("Cert %d: %s\n",i+1,(utf8Toansi(certs[i].getSubject())).c_str());
		}
	}
	catch(CPKIException& e)
	{
		printf("build cert path fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
	return 0;
}


void usage(const char *fileName)
{
	printf("Usage: %s cert",fileName);
}

CCertificate getcert(const char *fileName)
{
	FILE *fp;
	unsigned char buf[8192];
	int len;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		throw CPKIException("open cert file fail");
	}
	len=(int)fread(buf,1,sizeof(buf),fp);
	fclose(fp);

	return CCertificate(buf,len);
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


