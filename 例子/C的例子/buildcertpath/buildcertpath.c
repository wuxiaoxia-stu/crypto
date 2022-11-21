#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName);
static char *utf8Toansi(const char *str);
static void freecerpath(NETCA_PKI_CERTIFICATE_HANDLE *certpath,int count);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE *certpath;
	int count;
	int i;
	char *subject;
	char *ansistr;

	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	cert=getcert(argv[1]);
	if(cert==0)
	{
		printf("bad cert file\n");
		return -1;
	}

	rv=NetcaPKICertGetCertPath(cert, &certpath,&count);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICertGetCertPath fail\n");
		return -1;
	}

	for(i=0;i<count;i++)
	{
		rv=NetcaPKICertGetCertStringAttribute(certpath[i],NETCA_PKI_CERT_ATTRIBUTE_SUBJECT,&subject);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			freecerpath(certpath,count);
			printf("get subject fail\n");
			return -1;
		}
		ansistr=utf8Toansi(subject);
		NetcaPKICryptoFreeMemory(subject);
		if(ansistr==0)
		{
			freecerpath(certpath,count);
			printf("utf8Toansi fail\n");
			return -1;
		}
		printf("Cert %d: %s\n",i+1,ansistr);
		NETCA_FREE(ansistr);
	}
	freecerpath(certpath,count);
	return 0;
}


void usage(const char *fileName)
{
	printf("Usage: %s cert",fileName);
}

NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName)
{
	FILE *fp;
	unsigned char buf[8192];
	int len;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		return 0;
	}
	len=(int)fread(buf,1,sizeof(buf),fp);
	fclose(fp);

	return NetcaPKICertNewCert(buf,len);
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

void freecerpath(NETCA_PKI_CERTIFICATE_HANDLE *certpath,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		NetcaPKICertFreeCert(certpath[i]);		
	}
	NetcaPKICryptoFreeMemory(certpath);
}
