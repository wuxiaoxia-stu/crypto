#include <stdio.h>
#include "Store.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CStore;
using Netca::CPKIException;
using Netca::CCertificate;


static std::string utf8Toansi(const std::string &str);
int main()
{
	try
	{
		CStore store(NETCA_PKI_CERT_STORE_TYPE_CURRENT_USER,NETCA_PKI_CERT_STORE_NAME_MY);
		std::vector<CCertificate> certs=store.getCerts();
		for(size_t i=0;i<certs.size();i++)
		{
			printf("Cert %d: %s\n",i+1,(utf8Toansi(certs[i].getSubject())).c_str());
		}
		
		return 0;
	}
	catch(CPKIException& e)
	{
		printf("get my store fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
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

