#include <stdio.h>
#include <stdlib.h>
#include "NETCA_PKI.h"

static void Usage(const char *progName)
{
	printf("Usage: %s randLength\n",progName);
}

int main(int argc,char **argv)
{
	int randLength;
	unsigned char *rand;
	int rv;
	char *hex;
	int hexLen;

	if(argc!=2)
	{
		Usage(argv[0]);
		return -1;
	}
	randLength=atoi(argv[1]);
	
	rand=(unsigned char *)NetcaPKICryptoAllocMemory(randLength);
	if(rand==0)
	{
		printf("NetcaPKICryptoAllocMemory fail\n");
		return -1;
	}
	rv=NetcaPKICryptoGenerateRandom(NULL,randLength,rand);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeMemory(rand);
		printf("NetcaPKICryptoGenerateRandom fail,return %d\n",rv);
		return -1;
	}
	rv=NetcaPKICryptoHexEncode(1,rand,randLength,&hex,&hexLen);
	NetcaPKICryptoFreeMemory(rand);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoHexEncode fail,return %d\n",rv);
		return -1;
	}
	printf("%s\n",hex);
	NetcaPKICryptoFreeMemory(hex);
	return 0;
}
