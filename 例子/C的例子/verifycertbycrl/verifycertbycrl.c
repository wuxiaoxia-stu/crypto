#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static void PrintReason(int reason);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	int status;
	NETCA_PKI_REVOKEDCERT_HANDLE revInfo;
	unsigned char *crl;
	int crlLen;
	long inValidty;

	if(argc!=3)
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
	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_IN_VALIDITY,&inValidty);
	if(rv==NETCA_PKI_SUCCESS && inValidty==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("cert not in validity\n");
		return -1;
	}
	rv=ReadFileData(argv[2],&crl,&crlLen);
	if(rv==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("read %s fail\n",argv[2]);
		return -1;
	}
	
	rv=NetcaPKICertCRLVerifyCert(cert,crl,crlLen,0,&status,&revInfo);
	NetcaPKICertFreeCert(cert);
	NetcaPKICryptoFreeMemory(crl);
	if(rv==NETCA_PKI_REVOKEINFO_NOT_IN_VALIDITY)
	{
		printf("CRL not in validity\n");
		return -1;
	}
	else if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("verify cert fail\n");
		return -1;
	}

	if(status==NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED)
	{
		printf("cert unrevoked\n");
	}
	else if(status==NETCA_PKI_CERTIFICATE_STATUS_REVOKED)
	{
		int reason;
		char *t;
		printf("cert revoked\n");
		reason=NetcaPKICertGetRevokedCertRevokedReason(revInfo);
		PrintReason(reason);
		t=NetcaPKICertGetRevokedCertRevokedTime(revInfo);
		NetcaPKICertFreeRevokedCert(revInfo);
		if(t==0)
		{
			printf("get revoked time fail\n");
			return -1;
		}
		printf("RevokedTime: %s\n",t);
		NetcaPKICryptoFreeMemory(t);
	}
	else
	{
		printf("cert undetermined\n");
	}
	return 0;
}


void usage(const char *fileName)
{
	printf("Usage: %s cert crl",fileName);
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

void PrintReason(int reason)
{
	switch(reason)
	{
	case -1:
		printf("RevokedReason: no  CRLReason extension\n");
		break;
	case NETCA_PKI_CRL_REASON_UNSPECIFIED:
		printf("RevokedReason: unspecified\n");
		break;
	case NETCA_PKI_CRL_REASON_KEYCOMPROMISE:
		printf("RevokedReason: keyCompromise\n");
		break;
	case NETCA_PKI_CRL_REASON_CACOMPROMISE:
		printf("RevokedReason: cACompromise\n");
		break;
	case NETCA_PKI_CRL_REASON_AFFILIATION_CHANGED:
		printf("RevokedReason: affiliationChanged\n");
		break;
	case NETCA_PKI_CRL_REASON_SUPERSEDED:
		printf("RevokedReason: superseded\n");
		break;
	case NETCA_PKI_CRL_REASON_CESSATION_OF_OPERATION:
		printf("RevokedReason: cessationOfOperation\n");
		break;
	case NETCA_PKI_CRL_REASON_CERTIFATE_HOLD:
		printf("RevokedReason: certificateHold\n");
		break;
	default:
		printf("RevokedReason: unkown reason(%d)\n",reason);
		break;
	}
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
