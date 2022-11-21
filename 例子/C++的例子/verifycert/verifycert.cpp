#include <stdio.h>
#include <string.h>
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "RevokeInfo.hpp"

using Netca::CRevokeInfo;
using Netca::CPKIException;
using Netca::CCertificate;

static void usage(const char *fileName);
static CCertificate getcert(const char *fileName);
static void printreason(int reason);

int main(int argc,char **argv)
{
	int rv;
	int flag=NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_REVOKE
		|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_CRL
		|NETCA_PKI_CERTIFICATE_VERIFY_FLAG_ONLINE;
	int status;
	
	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CCertificate cert=getcert(argv[1]);
		CRevokeInfo revInfo;
		rv=cert.verify(flag,status,revInfo);
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
			if(status==NETCA_PKI_CERTIFICATE_STATUS_REVOKED)
			{
				printf("cert revoked\n");
			}
			else
			{
				printf("ca cert revoked\n");
			}
			
			reason=revInfo.reason();
			printreason(reason);
			printf("RevokedTime: %s\n",revInfo.revokeTime().c_str());
			
		}
		else
		{
			printf("cert undetermined\n");
		}
		return 0;
	}
	catch(CPKIException& e)
	{
		printf("verify cert fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}


void usage(const char *fileName)
{
	printf("Usage: %s cert",fileName);
}


CCertificate getcert(const char *fileName)
{
	FILE *fp;
	unsigned char buf[8192];
	int len;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		throw CPKIException("read cert file fail");
	}
	len=(int)fread(buf,1,sizeof(buf),fp);
	fclose(fp);

	return CCertificate(buf,len);
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
