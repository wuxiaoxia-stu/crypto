#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static char *utf8Toansi(const char *str);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_SIGNEDDATA_HANLDE hSignedData;
	int rv;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;
	char *ansistr;
	char *subject;

	if(argc!=3)
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
	
	rv=ReadFileData(argv[1],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("read %s fail\n",argv[1]);
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

	rv=SaveFile(argv[2],out,outLen);
	NetcaPKICryptoFreeMemory(out);
	if(rv==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("SaveFile fail\n");
		return -1;
	}
	
	cert=NetcaPKIMsgSignedDataGetSignCert(hSignedData,0);
	NetcaPKIMsgFreeSignedData(hSignedData);

	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT,&subject);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("get subject fail\n");
		return -1;
	}
	ansistr=utf8Toansi(subject);
	NetcaPKICryptoFreeMemory(subject);
	if(ansistr==0)
	{
		printf("utf8Toansi fail\n");
		return -1;
	}
	printf("Verify Success\nThe subject of sign cert is %s\n",ansistr);
	NETCA_FREE(ansistr);
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s signFile tbsFile\n",fileName);
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
