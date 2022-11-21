#include <stdio.h>
#include <string.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "SignedData.hpp"


#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif


using Netca::CSignedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;


static void usage(const char *fileName);

int main(int argc,char **argv)
{
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	CBlob out;
	int algo;
	const char *filter;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}

	algo=NETCA_PKI_ALGORITHM_SM3WITHSM2;
	
	try
	{
		filter="Algorithm='SM2'";
		
		CCertificate cert=CCertificate::SelectCert("Signature",filter);
		if(cert.isNull())
		{
			printf("select cert fail\n");
			return -1;
		}

		CSignedData signedData(true);
		
		signedData.setSignCert(cert);
		signedData.setSignAlgo(algo);
		signedData.setUseSigningTime(true);
		signedData.setUseQ7(true);

		fIn=fopen(argv[1],"rb");
		if(fIn==0)
		{
			printf("open %s fail\n",argv[1]);
			return -1;
		}

		fOut=fopen(argv[2],"wb");
		if(fOut==0)
		{
			fclose(fIn);
			fIn=0;
			printf("open %s fail\n",argv[2]);
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

		signedData.signFinal(out);
		
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
		printf("sign fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s inFileName outFileName\n",fileName);
}

