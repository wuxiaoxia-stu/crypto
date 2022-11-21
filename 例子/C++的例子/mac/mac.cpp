#include <stdio.h>
#include <string.h>
#include "PKIException.hpp"
#include "Mac.hpp"

using Netca::CMac;
using Netca::CPKIException;
using Netca::CBlob;

static void usage(const char *filename);
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
	CBlob key;
	unsigned char buf[8192];
	int len;
	FILE *fp=0;
	CBlob macValue;
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

	try
	{

		key.decodeHexString(argv[2]);
		CMac mac(algo,key.data(),key.length());
		
		fileName=argv[3];
		fp=fopen(fileName,"rb");
		if(fp==0)
		{
			printf("open %s fail\n",fileName);
			return -1;
		}

		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fp);
			if(ferror(fp)!=0)
			{
				fclose(fp);
				fp=0;
				printf("fread fail\n");
				return -1;
			}
			mac.update(buf,len);
			
			if(feof(fp))
			{
				break;
			}
		}
		fclose(fp);
		fp=0;
		mac.final(macValue);
		
		puts(macValue.encodeHexString().c_str());
		
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fp)
		{
			fclose(fp);
		}
		printf("mac fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
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
