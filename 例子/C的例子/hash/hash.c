#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *filename);
static char *HexEncode(const unsigned char *data,int dataLen);
static int GetHashAlgoFromName(const char *algoName);

void usage(const char *filename)
{
	printf("Usage: %s sha-1|sha-256|sm3 FileName",filename);
}

int main(int argc,char **argv)
{
	int rv;
	int algo;
	FILE *fp;
	unsigned char buf[8192];
	NETCA_PKI_HASH_HANDLE hHash;
	int len;
	unsigned char *md;
	int mdLen;
	char *hex;
	const char *algoName;
	const char *fileName;
	
	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	algoName=argv[1];
	algo=GetHashAlgoFromName(algoName);
	if(algo==-1)
	{
		usage(argv[0]);
		return -1;
	}

	hHash=NetcaPKICryptoGetHashHandle(algo);
	if(hHash==0)
	{
		printf("NetcaPKICryptoGetHashHandle fail\n");
		return -1;
	}
	
	fileName=argv[2];
	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeHash(hHash);
		printf("open %s fail\n",fileName);
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fp);
		if(ferror(fp)!=0)
		{
			fclose(fp);
			printf("fread fail\n");
			NetcaPKICryptoFreeHash(hHash);
			return -1;
		}
		
		rv=NetcaPKICryptoHashUpdate(hHash,buf,len);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			fclose(fp);
			printf("NetcaPKICryptoHashUpdate fail\n");
			NetcaPKICryptoFreeHash(hHash);
			return -1;
		}
		
		if(feof(fp))
		{
			break;
		}

	}
	fclose(fp);

	rv=NetcaPKICryptoHashFinal(hHash,&md,&mdLen);
	NetcaPKICryptoFreeHash(hHash);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoHashFinal fail\n");
		return -1;
	}

	hex=HexEncode(md,mdLen);
	NetcaPKICryptoFreeMemory(md);
	if(hex==0)
	{
		printf("HexEncode fail\n");
		return -1;
	}
	puts(hex);
	NetcaPKICryptoFreeMemory(hex);
	return 0;
}

char *HexEncode(const unsigned char *data,int dataLen)
{
	char *hex;
	int i;

	hex=(char *)NetcaPKICryptoAllocMemory(dataLen*2+1);
	if(hex==0)
	{
		return 0;
	}

	for(i=0;i<dataLen;i++)
	{
		sprintf(&hex[2*i],"%02X",data[i]);
	}

	return hex;
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
	else
	{
		return -1;
	}
}
