#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_CertReq.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static char *utf8Toansi(const char *str);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);
static void printsignalgo(int algo);
static void printpublickeyalgo(int algo);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *p10;
	int p10Len;
	NETCA_PKI_CERTREQ_HANLDE hCertReq;
	char *ansistr;
	char *subject;
	int signAlgo;
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;

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
	hCertReq=NetcaPKICertReqDecode(p10,p10Len);
	NetcaPKICryptoFreeMemory(p10);
	if(hCertReq==0)
	{
		printf("bad p10 file\n");
		return -1;
	}
	
	rv=NetcaPKICertReqVerify(hCertReq);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(hCertReq);
		printf("NetcaPKICertReqVerify fail\n");
		return -1;
	}
	printf("verify success\n");

	rv=NetcaPKICertReqGetStringAttribute(hCertReq,NETCA_PKI_CERTREQ_SUBJECT,&subject);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(hCertReq);
		printf("get subject fail\n");
		return -1;
	}
	ansistr=utf8Toansi(subject);
	NetcaPKICryptoFreeMemory(subject);
	if(ansistr==0)
	{
		NetcaPKICertReqFree(hCertReq);
		printf("utf8Toansi fail\n");
		return -1;
	}
	printf("subject:%s\n",ansistr);
	NETCA_FREE(ansistr);
	
	rv=NetcaPKICertReqGetIntegerAttribute(hCertReq,NETCA_PKI_CERTREQ_SIGN_ALGO,&signAlgo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(hCertReq);
		printf("get sign algo fail\n");
		return -1;
	}
	printsignalgo(signAlgo);

	hPublicKey=NetcaPKICertReqGetPublicKey(hCertReq);
	NetcaPKICertReqFree(hCertReq);
	if(hPublicKey==0)
	{
		printf("NetcaPKICertReqGetPublicKey fail\n");
		return -1;
	}
	printpublickeyalgo(NetcaPKICryptoGetPublicKeyAlgorithm(hPublicKey));
	printf("public key bits:%d\n",NetcaPKICryptoGetPublicKeyBits(hPublicKey));
	NetcaPKICryptoFreePublicKey(hPublicKey);
	return 0;
	
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
