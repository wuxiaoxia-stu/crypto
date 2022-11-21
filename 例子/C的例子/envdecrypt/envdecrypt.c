#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_Application.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static char *utf8Toansi(const char *str);

static void usage(const char *fileName);

int main(int argc,char **argv)
{
	NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	FILE *fIn;
	FILE *fOut;
	unsigned char buf[8192];
	int len;
	unsigned char *out;
	int outLen;
	char *subject;
	char *ansistr;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}

	hEnvelopedData=NetcaPKIMsgNewEnvelopedData(0);
	if(hEnvelopedData==0)
	{
		printf("NetcaPKIMsgNewEnvelopedData fail\n");
		return -1;
	}

	fIn=fopen(argv[1],"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("open %s fail\n",argv[1]);
		return -1;
	}

	fOut=fopen(argv[2],"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		printf("open %s fail\n",argv[2]);
		return -1;
	}

	rv=NetcaPKIMsgEnvelopedDataDecryptInit(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataDecryptInit fail\n");
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fIn);

		if(ferror(fIn)!=0)
		{
			fclose(fIn);
			fclose(fOut);
			NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKIMsgEnvelopedDataDecryptUpdate(hEnvelopedData,buf,len,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
				printf("NetcaPKIMsgEnvelopedDataDecryptUpdate fail\n");
				return -1;
			}

			if(outLen>0)
			{
				if((int)fwrite(out,1,outLen,fOut)!=outLen)
				{
					fclose(fIn);
					fclose(fOut);
					NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
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

	rv=NetcaPKIMsgEnvelopedDataDecryptFinal(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataDecryptFinal fail\n");
		return -1;
	}

	cert=NetcaPKIMsgEnvelopedDataGetCert(hEnvelopedData);
	NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);

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
	printf("Decrypt Success\nThe subject of decrypt cert is %s\n",ansistr);
	NETCA_FREE(ansistr);
	
	return 0;
}
void usage(const char *fileName)
{
	printf("Usage: %s infile outfile",fileName);
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

