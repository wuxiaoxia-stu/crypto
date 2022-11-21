#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static char *utf8Toansi(const char *str);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_SIGNEDDATA_HANLDE hSignedData;
	int rv;
	FILE *fIn;
	FILE *fOut;
	unsigned char buf[8192];
	int len;
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
	
	fIn=fopen(argv[1],"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("open %s fail\n",argv[1]);
		return -1;
	}

	fOut=fopen(argv[2],"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		fclose(fIn);
		printf("open %s fail\n",argv[2]);
		return -1;
	}
	
	rv=NetcaPKIMsgSignedDataVerifyInit(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgSignedDataVerifyInit fail\n");
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fIn);

		if(ferror(fIn)!=0)
		{
			fclose(fIn);
			fclose(fOut);
			NetcaPKIMsgFreeSignedData(hSignedData);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKIMsgSignedDataVerifyUpdate(hSignedData,buf,len,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeSignedData(hSignedData);
				printf("NetcaPKIMsgSignedDataVerifyUpdate fail\n");
				return -1;
			}

			if(outLen>0)
			{
				if((int)fwrite(out,1,outLen,fOut)!=outLen)
				{
					fclose(fIn);
					fclose(fOut);
					NetcaPKIMsgFreeSignedData(hSignedData);
					NetcaPKICryptoFreeMemory(out);
					printf("fwrite fail\n");
					return -1;
				}

			}
			NetcaPKICryptoFreeMemory(out);
		}
		
		if(feof(fIn))
		{
			break;
		}
	}
	fclose(fIn);
	fclose(fOut);

	rv=NetcaPKIMsgSignedDataVerifyFinal(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataVerifyFinal fail\n");
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
