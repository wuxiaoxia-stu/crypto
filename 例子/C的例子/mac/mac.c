#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

static void usage(const char *filename);
static char *HexEncode(const unsigned char *data,int dataLen);
static int HexDecode(const char *hex,unsigned char **data,int *dataLen);
static int DecodeHexByte(const char *hex,unsigned char *data);
static int DecodeHexHalfByte(char ch);
static int GetMacAlgoFromName(const char *algoName);

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

void usage(const char *filename)
{
	printf("Usage: %s hmac-sha1|hmac-sha256|hmac-sm3 key FileName",filename);
}

int main(int argc,char **argv)
{
	int algo;
	int rv;
	unsigned char *key;
	int keyLen;
	unsigned char buf[8192];
	NETCA_PKI_MAC_HANDLE hMac;
	int len;
	FILE *fp;
	unsigned char *mac;
	int macLen;
	char *hex;
	const char *algoName;
	const char *fileName;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	algoName=argv[1];
	algo=GetMacAlgoFromName(algoName);
	if(algo==-1)
	{
		usage(argv[0]);
		return -1;
	}


	rv=HexDecode(argv[2],&key,&keyLen);
	if(rv==0)
	{
		printf("bad hex key\n");
		return -1;
	}

	hMac=NetcaPKICryptoGetMacHandle(algo,key,keyLen,0);
	NetcaPKICryptoFreeMemory(key);
	if(hMac==0)
	{
		printf("NetcaPKICryptoGetMacHandle fail\n");
		return -1;
	}

	fileName=argv[3];
	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeMac(hMac);
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
			NetcaPKICryptoFreeMac(hMac);
			return -1;
		}

		rv=NetcaPKICryptoMacUpdate(hMac,buf,len);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			fclose(fp);
			NetcaPKICryptoFreeMac(hMac);
			printf("NetcaPKICryptoMacUpdate fail\n");
			return -1;
		}

		if(feof(fp))
		{
			break;
		}
	}
	fclose(fp);

	rv=NetcaPKICryptoMacFinal(hMac,&mac,&macLen);
	NetcaPKICryptoFreeMac(hMac);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICryptoMacFinal fail\n");
		return -1;
	}
	
	hex=HexEncode(mac,macLen);
	NetcaPKICryptoFreeMemory(mac);
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

int HexDecode(const char *hex,unsigned char **data,int *dataLen)
{
	int len;
	unsigned char *buf;
	int bufLen;
	int i;
	int j;

	len=(int)strlen(hex);

	if(len%2!=0)
	{
		return 0;
	}

	bufLen=len/2;
	buf=(unsigned char *)NetcaPKICryptoAllocMemory(bufLen);
	if(buf==0)
	{
		return 0;
	}
	
	for(i=0,j=0;i<len;i+=2,j++)
	{
		if(DecodeHexByte(&hex[i],&buf[j])==0)
		{
			NetcaPKICryptoFreeMemory(buf);
			return 0;
		}
	}

	*data=buf;
	*dataLen=bufLen;
	return 1;
}

int DecodeHexByte(const char *hex,unsigned char *data)
{
	int high;
	int low;

	high=DecodeHexHalfByte(hex[0]);
	if(high==-1)
	{
		return 0;
	}
	
	low=DecodeHexHalfByte(hex[1]);
	if(low==-1)
	{
		return 0;
	}

	*data=(unsigned char)(high<<4|low);
	return 1;
}

int DecodeHexHalfByte(char ch)
{
	if(ch>='0' && ch<='9')
	{
		return ch-'0';
	}
	else if(ch>='a' && ch<='f')
	{
		return ch-'a'+10;
	}
	else if(ch>='A' && ch<='F')
	{
		return ch-'A'+10;
	}
	else
	{
		return -1;
	}
}

int GetMacAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"hmac-md5")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_MD5;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha1")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA1;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha256")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA256;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha512")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA512;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha224")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA224;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha384")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA384;
	}
	else if(STRINGCASECMP(algoName,"hmac-sm3")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SM3;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha512/224")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA512_224;
	}
	else if(STRINGCASECMP(algoName,"hmac-sha512/256")==0)
	{
		return NETCA_PKI_ALGORITHM_HMAC_SHA512_256;
	}
	else if(STRINGCASECMP(algoName,"aes-cmac")==0)
	{
		return NETCA_PKI_ALGORITHM_AES_CMAC;
	}
	else if(STRINGCASECMP(algoName,"sm4-cmac")==0)
	{
		return NETCA_PKI_ALGORITHM_SM4_CMAC;
	}
	else if(STRINGCASECMP(algoName,"3des-cmac")==0
		|| STRINGCASECMP(algoName,"tdes-cmac")==0)
	{
		return NETCA_PKI_ALGORITHM_3DES_CMAC;
	}
	else
	{
		return -1;
	}
}
