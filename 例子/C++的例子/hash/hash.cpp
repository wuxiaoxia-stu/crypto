#include <stdio.h>
#include "Hash.hpp"
#include "PKIException.hpp"

static void usage(const char *filename);

using Netca::CHash;
using Netca::CBlob;
using Netca::CPKIException;

void usage(const char *filename)
{
	printf("Usage: %s sha-1|sha-256|sm3 FileName",filename);
}

int main(int argc,char **argv)
{
	const char *algoName;
	const char *fileName;
	int algo;
	FILE *fp;
	unsigned char buf[8192];
	int len;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}

	algoName=argv[1];
	algo=CHash::GetHashAlgorithm(algoName);
	if(algo==CHash::INVALID_HASH_ALGORITHM)
	{
		usage(argv[0]);
		return -1;
	}

	fileName=argv[2];
	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		printf("open %s fail\n",fileName);
		return -1;
	}
	
	CBlob hashValue;
	try
	{
		CHash hashObj(algo);
		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fp);
			if(ferror(fp)!=0)
			{
				fclose(fp);
				printf("fread fail\n");
				return -1;
			}
			
			hashObj.update(buf,len);
			if(feof(fp))
			{
				break;
			}

		}
		hashObj.final(hashValue);
		fclose(fp);
		fp=0;
		puts(hashValue.encodeHexString().c_str());
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fp)
		{
			fclose(fp);
		}
		printf("hash fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
		
}

