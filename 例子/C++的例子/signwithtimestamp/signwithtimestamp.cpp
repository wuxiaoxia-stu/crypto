#include <stdio.h>
#include <string.h>
#include "SignedData.hpp"
#include "PKIException.hpp"
#include "Certificate.hpp"

using Netca::CSignedData;
using Netca::CBlob;
using Netca::CPKIException;
using Netca::CCertificate;

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif


static void usage(const char *fileName);
static int GetSignAlgoFromName(const char *algoName);

int main(int argc,char **argv)
{
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	CBlob out;
	int algo;
	const char *filter;

	if(argc!=5)
	{
		usage(argv[0]);
		return -1;
	}

	algo=GetSignAlgoFromName(argv[2]);
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

		CSignedData signedData(true);
		signedData.setSignCert(cert);
		signedData.setSignAlgo(algo);
		
		fIn=fopen(argv[3],"rb");
		if(fIn==0)
		{
			printf("open %s fail\n",argv[3]);
			return -1;
		}

		fOut=fopen(argv[4],"wb");
		if(fOut==0)
		{
			fclose(fIn);
			fIn=0;
			printf("open %s fail\n",argv[4]);
			return -1;
		}
		
		signedData.signInit(out);
		
		if((int)fwrite(out.data(),1,out.length(),fOut)!=out.length())
		{
			fclose(fIn);
			fIn=0;
			fclose(fOut);
			fOut=0;
			printf("fwrite fail\n");
			return -1;
		}
		
		for(;;)
		{
			len=(int)fread(buf,1,sizeof(buf),fIn);
			if(ferror(fIn)!=0)
			{
				fclose(fIn);
				fIn=0;
				fclose(fOut);
				fOut=0;
				printf("fread fail\n");
				return -1;
			}

			if(len>0)
			{
				signedData.signUpdate(buf,len,out);
				
				if(out.length()>0)
				{
					if((int)fwrite(out.data(),1,out.length(),fOut)!=out.length())
					{
						fclose(fIn);
						fIn=0;
						fclose(fOut);
						fOut=0;
						printf("fwrite fail\n");
						return -1;
					}

				}
				
			}
			if(feof(fIn))
			{
				break;
			}
		}
		fclose(fIn);
		fIn=0;

		signedData.signWithTimeStampFinal(argv[1],out);
		if(out.length()>0)
		{
			if((int)fwrite(out.data(),1,out.length(),fOut)!=out.length())
			{
				fclose(fOut);
				fOut=0;
				printf("fwrite fail\n");
				return -1;
			}

		}
		fclose(fOut);
		fOut=0;

		printf("Success\n");
		return 0;
	}
	catch(CPKIException& e)
	{
		if(fIn)
		{
			fclose(fIn);
		}

		if(fOut)
		{
			fclose(fOut);
		}
		printf("sign with timestamp fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
	
}


void usage(const char *fileName)
{
	printf("Usage: %s url sha1withRSA|sha256withRSA inFile outFile\n",fileName);
}

NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName)
{
	FILE *fp;
	unsigned char buf[8192];
	int len;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		return 0;
	}
	len=(int)fread(buf,1,sizeof(buf),fp);
	fclose(fp);

	return NetcaPKICertNewCert(buf,len);
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
