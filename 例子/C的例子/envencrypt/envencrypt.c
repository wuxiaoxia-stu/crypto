#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_Application.h"


static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName);

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

	if(argc!=4)
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

	hEnvelopedData=NetcaPKIMsgNewEnvelopedData(1);
	if(hEnvelopedData==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("NetcaPKIMsgNewEnvelopedData fail\n");
		return -1;
	}

	rv=NetcaPKIMsgEnvelopedDataSetEncAlgorithm(hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ALGORITHM_AES128CBC);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataSetEncAlgorithm fail\n");
		return -1;
	}

	rv=NetcaPKIMsgEnvelopedDataAddCert(hEnvelopedData,cert,0);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataAddCert fail\n");
		return -1;
	}

	fIn=fopen(argv[2],"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("open %s fail\n",argv[2]);
		return -1;
	}

	fOut=fopen(argv[3],"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		printf("open %s fail\n",argv[3]);
		return -1;
	}
	
	rv=NetcaPKIMsgEnvelopedDataEncryptInit(hEnvelopedData,&out,&outLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataEncryptInit fail\n");
		return -1;
	}

	if((int)fwrite(out,1,outLen,fOut)!=outLen)
	{
		fclose(fIn);
		fclose(fOut);
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		NetcaPKICryptoFreeMemory(out);
		printf("fwrite fail\n");
		return -1;
	}
	NetcaPKICryptoFreeMemory(out);

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
			rv=NetcaPKIMsgEnvelopedDataEncryptUpdate(hEnvelopedData,buf,len,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
				printf("NetcaPKIMsgEnvelopedDataEncryptUpdate fail\n");
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

	rv=NetcaPKIMsgEnvelopedDataEncryptFinal(hEnvelopedData,&out,&outLen);
	NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		fclose(fOut);
		printf("NetcaPKIMsgEnvelopedDataEncryptFinal fail\n");
		return -1;
	}

	if(outLen>0)
	{
		if((int)fwrite(out,1,outLen,fOut)!=outLen)
		{
			fclose(fOut);
			NetcaPKICryptoFreeMemory(out);
			printf("fwrite fail\n");
			return -1;
		}

	}
	NetcaPKICryptoFreeMemory(out);
	fclose(fOut);

	printf("Success\n");
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s cert infile outfile",fileName);
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
