#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName);
static void printreason(int reason);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	int flag=NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_REVOKE
		|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_CRL
		|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_ONLINE;
	int status;
	NETCA_PKI_REVOKEDCERT_HANDLE revInfo;

	if(argc!=2)
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

	rv=NetcaPKICertVerifyCert(cert,0,flag,&status,&revInfo);
	NetcaPKICertFreeCert(cert);
	if(rv==NETCA_PKI_NOT_IN_VALIDITY)
	{
		printf("cert not in validity\n");
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
		printreason(reason);
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


void usage(const char *fileName)
{
	printf("Usage: %s cert",fileName);
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

void printreason(int reason)
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
