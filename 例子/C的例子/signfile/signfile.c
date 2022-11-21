#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif


static void usage(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);

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
	int algo;
	const char *filter;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}

	algo=GetSignAlgoFromName(argv[1]);
	if(algo==-1)
	{
		usage(argv[0]);
		return -1;
	}

	if(algo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		filter="Algorithm='SM2'";
	}
	else
	{
		filter="Algorithm='RSA'";
	}

	rv= NetcaPKISelectCert("Signature",filter,&cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}

	hSignedData=NetcaPKIMsgNewSignedData(1);
	if(hSignedData==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("NetcaPKIMsgNewSignedData fail\n");
		return -1;
	}
	rv=NetcaPKIMsgSignedDataSetSignCert(hSignedData,cert,0);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("NetcaPKIMsgSignedDataSetSignCert fail\n");
		return -1;
	}
	
	
	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_SIGN_ALGO,
		0,algo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set sign algorithm fail\n");
		return -1;
	}
	

	rv=NetcaPKIMsgSignedDataSetIntegerAttribute(hSignedData,NETCA_PKI_SIGNEDDATA_ATTRIBUTE_USE_SIGNINGTIME,
		0,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("set signing time fail\n");
		return -1;
	}
	
	
	fIn=fopen(argv[2],"rb");
	if(fIn==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		printf("open %s fail\n",argv[2]);
		return -1;
	}

	fOut=fopen(argv[3],"wb");
	if(fOut==0)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		fclose(fIn);
		printf("open %s fail\n",argv[3]);
		return -1;
	}
	
	rv=NetcaPKIMsgSignedDataSignInit(hSignedData,&out,&outLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeSignedData(hSignedData);
		fclose(fIn);
		fclose(fOut);
		printf("NetcaPKIMsgSignedDataSignInit fail\n");
		return -1;
	}

	if((int)fwrite(out,1,outLen,fOut)!=outLen)
	{
		fclose(fIn);
		fclose(fOut);
		NetcaPKIMsgFreeSignedData(hSignedData);
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
			NetcaPKIMsgFreeSignedData(hSignedData);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKIMsgSignedDataSignUpdate(hSignedData,buf,len,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKIMsgFreeSignedData(hSignedData);
				printf("NetcaPKIMsgSignedDataSignUpdate fail\n");
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

	rv=NetcaPKIMsgSignedDataSignFinal(hSignedData,&out,&outLen);
	NetcaPKIMsgFreeSignedData(hSignedData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		fclose(fOut);
		printf("NetcaPKIMsgSignedDataSignFinal fail\n");
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
	printf("Usage: %s sha1withRSA|sha256withRSA inFileName outFileName\n",fileName);
}

int GetSignAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha1withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha256withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha512withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sm3withsm2")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3WITHSM2;
	}
	else
	{
		return -1;
	}
}


