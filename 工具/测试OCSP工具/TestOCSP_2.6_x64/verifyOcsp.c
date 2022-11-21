
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"


int ReadFileData(const char *filename,unsigned char **data,int *datalen)
{
	FILE *fp;
	long len;
	unsigned char *buf;

	fp=fopen(filename,"rb");
	if(fp==0)
	{
		printf("fopen %s, fail.\n",filename);
		return 0;
	}

	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	fseek(fp,0,SEEK_SET);

	buf=(unsigned char*)NetcaPKICryptoAllocMemory(len);
	if(buf==0)
	{
		fclose(fp);
		printf("alloc memory, fail.\n");
		return 0;
	}

	fread(buf,1,len,fp);
	fclose(fp);
	*data=buf;
	*datalen=(int)len;
	return 1;
}

char* GetOcspUrl()
{
	int rv;
	unsigned char *data;
	int datalen;
	char *res;

	rv=ReadFileData("ocspurl.txt",&data,&datalen);
	if(rv!=1)
	{
		return 0;
	}

	res=(char*)NetcaPKICryptoAllocMemory(datalen+1);
	if(res==0)
	{
		NetcaPKICryptoFreeMemory(data);
		return 0;
	}
	memcpy(res,data,datalen);
	res[datalen]=0;

	NetcaPKICryptoFreeMemory(data);
	return res;
}



int main()
{
	int rv;
	NETCA_PKI_CERTIFICATE_HANDLE hCert;
	unsigned char *certblob;
	int certbloblen;
	char *ocspurl;
	int status;
	NETCA_PKI_REVOKEDCERT_HANDLE info;

	ocspurl=GetOcspUrl();
	if(ocspurl==0)
	{
		printf("read ocsp url, fail.\n");
		return -1;
	}

	rv=ReadFileData("cert.cer",&certblob,&certbloblen);
	if(rv!=1)
	{
		NetcaPKICryptoFreeMemory(ocspurl);
		printf("read certificate data, fail.\n");
		return -1;
	}


	hCert = NetcaPKICertNewCert(certblob, certbloblen);
	NetcaPKICryptoFreeMemory(certblob);
	if(hCert == 0)
	{
		printf("NetcaPKICertNewCert Fail\n");
		return -1;
	}

	rv = NetcaPKICertOCSPVerifyCert(hCert, ocspurl, NULL, &status, &info);
	NetcaPKICryptoFreeMemory(ocspurl);
	NetcaPKICertFreeCert(hCert);
	if(rv != 1)
	{
		printf("NetcaPKICertOCSPVerifyCert Fail\n");
		return -1;
	}

	printf("status = %d\n", status);
	return 0;
}
