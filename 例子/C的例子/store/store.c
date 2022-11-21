#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static char *utf8Toansi(const char *str);
int main()
{
	NETCA_PKI_CERT_STORE hStore;
	int count;
	int i;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	char *subject;
	int rv;
	char *ansistr;

	hStore=NetcaPKICertOpenStore(NETCA_PKI_CERT_STORE_TYPE_CURRENT_USER,NETCA_PKI_CERT_STORE_NAME_MY);
	if(hStore==0)
	{
		printf("NetcaPKICertOpenStore fail\n");
		return -1;
	}

	count=NetcaPKICertGetStoreCertCount(hStore);
	for(i=0;i<count;i++)
	{
		cert=NetcaPKICertGetStoreCert(hStore,i);
		rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT,&subject);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICertFreeCert(cert);
			NetcaPKICertCloseStore(hStore);
			printf("get subject fail\n");
			return -1;
		}
		ansistr=utf8Toansi(subject);
		NetcaPKICryptoFreeMemory(subject);
		if(ansistr==0)
		{
			NetcaPKICertFreeCert(cert);
			NetcaPKICertCloseStore(hStore);
			printf("utf8Toansi fail\n");
			return -1;
		}
		printf("Cert %d: %s\n",i+1,ansistr);
		NETCA_FREE(ansistr);
		NetcaPKICertFreeCert(cert);
	}
	NetcaPKICertCloseStore(hStore);

	return 0;
}

char *utf8Toansi(const char *str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *mbs;
	long mbsLen;

	ustr=netca_ustring_newutf8((const unsigned char *)str,(long)strlen(str));
	if(ustr==0)
	{
		return 0;
	}

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		netca_ustring_free(ustr);
		return 0;
	}

	rv=netca_ustring_tombs(ustr,charset,&mbs,&mbsLen);
	NETCA_FREE(charset);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		return 0;
	}

	return (char *)mbs;
}

