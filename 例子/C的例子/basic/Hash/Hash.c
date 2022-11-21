#include <stdio.h>
#include <string.h>
#include "NETCA_PKI.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void Usage(const char *progName);
static char *HexEncode(const unsigned char *data,int dataLen);
static int GetHashAlgoFromName(const char *algoName);

void Usage(const char *progName)
{
	printf("Usage: %s sha-1|sha-256|sm3 data\n",progName);
}

int main(int argc,char **argv)
{
	int rv;
	int algo;
	const char *algoName;
	const char *data;
	unsigned char* hashValue;
	int hashValueLen;
	char *hex;
	int hexLen;

	if(argc!=3)
	{
		Usage(argv[0]);
		return -1;
	}
	algoName=argv[1];
	data=argv[2];

	algo=GetHashAlgoFromName(algoName);
	if(algo==-1)
	{
		Usage(argv[0]);
		return -1;
	}

	rv=NetcaPKICryptoHash(algo,(const unsigned char*)data,(int)strlen(data),
		&hashValue,&hashValueLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoHash fail\n");
		return -1;
	}

	rv=NetcaPKICryptoHexEncode(1,hashValue,hashValueLen,&hex,&hexLen);
	NetcaPKICryptoFreeMemory(hashValue);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoHexEncode fail,return %d\n",rv);
		return -1;
	}
	printf("%s\n",hex);
	NetcaPKICryptoFreeMemory(hex);

	return 0;
}

int GetHashAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5;
	}
	else if(STRINGCASECMP(algoName,"sha1")==0
		|| STRINGCASECMP(algoName,"sha-1")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1;
	}
	else if(STRINGCASECMP(algoName,"sha256")==0
		|| STRINGCASECMP(algoName,"sha-256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256;
	}
	else if(STRINGCASECMP(algoName,"sha512")==0
		|| STRINGCASECMP(algoName,"sha-512")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512;
	}
	else if(STRINGCASECMP(algoName,"sm3")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3;
	}
	else if(STRINGCASECMP(algoName,"sha224")==0
		|| STRINGCASECMP(algoName,"sha-224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA224;
	}
	else if(STRINGCASECMP(algoName,"sha384")==0
		|| STRINGCASECMP(algoName,"sha-384")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA384;
	}
	else if(STRINGCASECMP(algoName,"sha-512/224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_224;
	}
	else if(STRINGCASECMP(algoName,"sha-512/256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_256;
	}
	else if(STRINGCASECMP(algoName,"sha3-224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA3_224;
	}
	else if(STRINGCASECMP(algoName,"sha3-256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA3_256;
	}
	else if(STRINGCASECMP(algoName,"sha3-384")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA3_384;
	}
	else if(STRINGCASECMP(algoName,"sha3-512")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA3_512;
	}
	else
	{
		return -1;
	}
}
