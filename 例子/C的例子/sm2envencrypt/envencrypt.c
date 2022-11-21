#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_Application.h"


static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);

int main(int argc,char **argv)
{
	NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	unsigned char *buf;
	int bufLen;
	unsigned char *out;
	int outLen;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	
	cert=GetCert(argv[1]);
	if(cert==0)
	{
		printf("bad cert file\n");
		return -1;
	}

	if(NetcaPKICertMatch(cert,"Algorithm='SM2' && CertType='Encrypt' && InValidity='True'")==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("not sm2 encrypt cert,not in validity\n");
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

	rv=NetcaPKIMsgEnvelopedDataSetIntegerAttribute(hEnvelopedData,NETCA_PKI_ENVELOPEDDATA_ATTRIBUTE_USE_SM2_Q7,1);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("NetcaPKIMsgEnvelopedDataSetIntegerAttribute use sm2 q7 fail\n");
		return -1;
	}

	rv=ReadFileData(argv[2],&buf,&bufLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
		printf("read %s fail\n",argv[2]);
		return -1;
	}
	
	rv=NetcaPKIMsgEnvelopedDataEncrypt(hEnvelopedData,buf,bufLen,&out,&outLen);
	NetcaPKIMsgFreeEnvelopedData(hEnvelopedData);
	NetcaPKICryptoFreeMemory(buf);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgEnvelopedDataEncrypt fail\n");
		return -1;
	}

	rv=SaveFile(argv[3],out,outLen);
	NetcaPKICryptoFreeMemory(out);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}


	printf("Success\n");
	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s cert infile outfile",fileName);
}

NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName)
{
	unsigned char *buf;
	int bufLen;
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	rv=ReadFileData(fileName,&buf,&bufLen);
	if(rv==0)
	{
		return 0;
	}

	cert= NetcaPKICertNewCert(buf,bufLen);
	NetcaPKICryptoFreeMemory(buf);
	return cert;
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
