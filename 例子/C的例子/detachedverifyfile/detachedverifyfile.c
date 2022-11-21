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

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_SIGNEDDATA_HANLDE hSignedData;
	int rv;
	FILE *fIn;
	unsigned char buf[8192];
	int len;
	char *ansistr;
	char *subject;
	unsigned char *sign;
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

	hSignedData=NetcaPKIMsgNewSignedData(0);
	if(hSignedData==0)
	{
		NetcaPKICryptoFreeMemory(sign);
		printf("NetcaPKIMsgNewSignedData fail\n");
		return -1;
	}

	
	fIn=fopen(argv[1],"rb");
	if(fIn==0)
	{
		NetcaPKICryptoFreeMemory(sign);
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("open %s fail\n",argv[1]);
		return -1;
	}

		
	rv=NetcaPKIMsgSignedDataDetachedVerifyInit(hSignedData,sign,signLen);
	NetcaPKICryptoFreeMemory(sign);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		fclose(fIn);
		printf("NetcaPKIMsgSignedDataDetachedVerifyInit fail\n");
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fIn);
		if(ferror(fIn)!=0)
		{
			fclose(fIn);
			NetcaPKIMsgFreeSignedData(hSignedData);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKIMsgSignedDataDetachedVerifyUpdate(hSignedData,buf,len);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				NetcaPKIMsgFreeSignedData(hSignedData);
				printf("NetcaPKIMsgSignedDataDetachedVerifyUpdate fail\n");
				return -1;
			}

			
		}
		if(feof(fIn))
		{
			break;
		}
	}
	fclose(fIn);
	
	rv=NetcaPKIMsgSignedDataDetachedVerifyFinal(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataDetachedVerifyFinal fail\n");
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
	printf("Usage: %s tbsFile signFile\n",fileName);
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

