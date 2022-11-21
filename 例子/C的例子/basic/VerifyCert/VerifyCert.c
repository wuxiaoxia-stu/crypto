#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static int GetFileLength(FILE *fp);
static NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName);
static void PrintReason(int reason);

void Usage(const char *progName)
{
	printf("Usage: %s certFileName\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	const char *certFileName;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int flag;
	int status;
	NETCA_PKI_REVOKEDCERT_HANDLE revInfo;

	if(argc!=2)
	{
		Usage(argv[0]);
		return -1;
	}
	certFileName=argv[1];
	
	flag=0;
	/* 
	用CRL验证证书的状态
	flag=NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_REVOKE|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_ONLINE|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_CRL| NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_CACERT_REVOKE;
	*/

	cert=GetCert(certFileName);
	if(cert==NULL)
	{
		printf("Bad cert file\n");
		return -1;
	}
	rv=NetcaPKICertVerifyCert(cert,NULL,flag,&status,&revInfo);
	NetcaPKICertFreeCert(cert);
	if(rv==NETCA_PKI_NOT_IN_VALIDITY)
	{
		printf("cert not in validity\n");
		return -1;
	}
	else if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICertVerifyCert file,return %d\n",rv);
		return -1;
	}
	
	if(status==NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED)
	{
		printf("cert unrevoked\n");
		
	}
	else if(status==NETCA_PKI_CERTIFICATE_STATUS_REVOKED
		|| status==NETCA_PKI_CERTIFICATE_STATUS_CA_REVOKED)
	{
		int reason;
		char *t;
		if(status==NETCA_PKI_CERTIFICATE_STATUS_REVOKED)
		{
			printf("cert revoked\n");
		}
		else
		{
			printf("ca cert revoked\n");
		}
		
		reason=NetcaPKICertGetRevokedCertRevokedReason(revInfo);
		PrintReason(reason);
		t=NetcaPKICertGetRevokedCertRevokedTime(revInfo);
		NetcaPKICertFreeRevokedCert(revInfo);
		if(t==0)
		{
			printf("get revoke time fail\n");
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

NETCA_PKI_CERTIFICATE_HANDLE GetCert(const char *fileName)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	unsigned char *data;
	int dataLen;
	int rv;

	rv=ReadFileData(fileName,&data,&dataLen);
	if(rv==0)
	{
		return NULL;
	}
	cert=NetcaPKICertNewCert(data,dataLen);
	NetcaPKICryptoFreeMemory(data);
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
