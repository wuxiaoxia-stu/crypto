#include <stdio.h>
#include <string.h>
#include "PublicKey.hpp"
#include "PKIException.hpp"
#include "CertReq.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CCertReq;
using Netca::CPKIException;
using Netca::CPublicKey;

static void usage(const char *fileName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static void printsignalgo(int algo);
static void printpublickeyalgo(int algo);
static std::string utf8Toansi(const std::string &str);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *p10=0;
	int p10Len;

	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	rv=ReadFileData(argv[1],&p10,&p10Len);
	if(rv==0)
	{
		printf("read %s fail\n",argv[1]);
		return -1;
	}

	try
	{
		CCertReq cerReq(p10,p10Len);
		NetcaPKICryptoFreeMemory(p10);
		p10=0;
		
		
		if(cerReq.verify()==false)
		{
			printf("NetcaPKICertReqVerify fail\n");
			return -1;
		}
		printf("verify success\n");

		printf("subject:%s\n",utf8Toansi(cerReq.getSubject()).c_str());
		printsignalgo(cerReq.getSignAlgo());

		CPublicKey publicKey=cerReq.getPublicKey();
		printpublickeyalgo(publicKey.algorithm());
		printf("public key bits:%d\n",publicKey.bits());
		return 0;
	}
	catch(CPKIException& e)
	{
		if(p10)
		{
			NetcaPKICryptoFreeMemory(p10);
		}

		printf("verify p10 fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s p10file\n",fileName);
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




void printsignalgo(int algo)
{
	switch(algo)
	{
	case NETCA_PKI_ALGORITHM_MD5WITHRSA:
		printf("Sign Algorithm: MD5WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA1WITHRSA:
		printf("Sign Algorithm: SHA1WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA224WITHRSA:
		printf("Sign Algorithm: SHA224WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA256WITHRSA:
		printf("Sign Algorithm: SHA256WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA384WITHRSA:
		printf("Sign Algorithm: SHA384WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA512WITHRSA:
		printf("Sign Algorithm: SHA512WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA1:
		printf("Sign Algorithm: DSAWithSHA1\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA224:
		printf("Sign Algorithm: DSAWithSHA224\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA256:
		printf("Sign Algorithm: DSAWithSHA256\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA1:
		printf("Sign Algorithm: ECDSAWithSHA1\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA224:
		printf("Sign Algorithm: ECDSAWithSHA224\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA256:
		printf("Sign Algorithm: ECDSAWithSHA256\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA384:
		printf("Sign Algorithm: ECDSAWithSHA384\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA512:
		printf("Sign Algorithm: ECDSAWithSHA512\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_PSS:
		printf("Sign Algorithm: RSA PSS\n");
		break;
	case NETCA_PKI_ALGORITHM_SM3WITHSM2:
		printf("Sign Algorithm: SM3WithSM2\n");
		break;
	case NETCA_PKI_ALGORITHM_SM3WITHRSA:
		printf("Sign Algorithm: SM3WithRSA\n");
		break;
	default:
		printf("Sign Algorithm: unknown sign algorithm(%ld)\n",algo);
		break;
	}
}


void printpublickeyalgo(int algo)
{
	switch(algo)
	{
	case NETCA_PKI_ALGORITHM_RSA:
		printf("PublicKey Algorithm: RSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DSA:
		printf("PublicKey Algorithm: DSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DH:
		printf("PublicKey Algorithm: DH\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC:
		printf("PublicKey Algorithm: ECC\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_ONLY_OAEP:
		printf("PublicKey Algorithm: RSA OAEP\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_ONLY_PSS:
		printf("PublicKey Algorithm: RSA PSS\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC_ONLY_ECDH:
		printf("PublicKey Algorithm: ECC ECDH\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC_ONLY_ECMQV:
		printf("PublicKey Algorithm: ECC ECMQV\n");
		break;
	default:
		printf("PublicKey Algorithm: unkown publickey algorithm(%ld)\n",algo);
		break;

	}
}

std::string utf8Toansi(const std::string &str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *mbs;
	long mbsLen;

	ustr=netca_ustring_newutf8((const unsigned char *)str.data(),(long)str.length());
	if(ustr==0)
	{
		throw CPKIException("netca_ustring_newutf8 fail");
	}

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		netca_ustring_free(ustr);
		throw CPKIException("netca_ustring_getdefaultcharset fail");
	}

	rv=netca_ustring_tombs(ustr,charset,&mbs,&mbsLen);
	NETCA_FREE(charset);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		throw CPKIException("netca_ustring_tombs fail");
	}
	
	try
	{
		std::string retStr((char *)mbs,(int)mbsLen);
		NETCA_FREE(mbs);
		mbs=0;
		return retStr;
	}
	catch(...)
	{
		if(mbs)
		{
			NETCA_FREE(mbs);
		}
		throw;
	}
}

