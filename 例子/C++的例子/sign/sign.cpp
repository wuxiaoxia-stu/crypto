#include <stdio.h>
#include <string.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "Signature.hpp"
#include "Keypair.hpp"

using Netca::CKeypair;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;
using Netca::CSignature;

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);
static int GetSignAlgoFromName(const char *algoName);

int main(int argc,char **argv)
{
	int algo;
	FILE *fp=0;
	unsigned char buf[8192];
	int len;
	int rv;
	CBlob signValue;
	const char *filter;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	algo=GetSignAlgoFromName(argv[1]);
	if(algo==-1)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		if(algo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
		{
			filter="Algorithm='SM2'";
		}
		else
		{
			filter="Algorithm='RSA'";
		}
		
		CCertificate cert=CCertificate::SelectCert("Signature",filter);
		if(cert.isNull())
		{
			printf("select cert fail\n");
			return -1;
		}
		CKeypair keypair=cert.getKeypair(0,NETCA_PKI_CERT_PURPOSE_SIGN);
		if(keypair.isNull())
		{
			printf("get keypair fail\n");
			return -1;
		}

		CSignature sign(keypair,algo);
		
		fp=fopen(argv[2],"rb");
		if(fp==0)
		{
			printf("open %s fail\n",argv[2]);
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

			if(len>0)
			{
				sign.update(buf,len);
			}

			if(feof(fp))
			{
				break;
			}
		}
		fclose(fp);
		fp=0;

		sign.sign(signValue);
		
		rv=SaveFile(argv[3],signValue.data(),signValue.length());
		if(rv==0)
		{
			printf("SaveFile fail\n");
			return -1;
		}

		printf("Success\n");
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fp)
		{
			fclose(fp);
		}

		printf("sign fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s sha1withRSA|sha256withRSA tbsFileName signatureFileName",fileName);
}

int SaveFile(const char *fileName,const unsigned char *buf,int bufLen)
{
	FILE *fp;
	int len;
	fp=fopen(fileName,"wb");
	if(fp==0)
	{
		return 0;
	}

	len=(int)fwrite(buf,1,bufLen,fp);
	fclose(fp);
	return len==bufLen;
}

int GetSignAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha1withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha256withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sha512withRSA")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512WITHRSA;
	}
	else if(STRINGCASECMP(algoName,"sm3withsm2")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3WITHSM2;
	}
	else
	{
		return -1;
	}
}
