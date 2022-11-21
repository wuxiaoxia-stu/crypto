#include <stdio.h>
#include "EnvelopedData.hpp"
#include "Certificate.hpp"
#include "PKIException.hpp"

using Netca::CEnvelopedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static CCertificate getcert(const char *fileName);

int main(int argc,char **argv)
{
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	CBlob out;
	
	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	
	try
	{
		CCertificate cert=getcert(argv[1]);
		
		CEnvelopedData env(true);
		
		env.setEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_ALGORITHM_AES128CBC);
		env.addCert(cert);
		
		fIn=fopen(argv[2],"rb");
		if(fIn==0)
		{
			printf("open %s fail\n",argv[2]);
			return -1;
		}

		fOut=fopen(argv[3],"wb");
		if(fOut==0)
		{
			fclose(fIn);
			fIn=0;
			printf("open %s fail\n",argv[3]);
			return -1;
		}
		
		env.encryptInit(out);
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
				env.encryptUpdate(buf,len,out);
				
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
		env.encryptFinal(out);
		
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
		printf("encrypt  fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s cert infile outfile",fileName);
}

CCertificate getcert(const char *fileName)
{
	FILE *fp;
	unsigned char buf[8192];
	int len;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		throw CPKIException("open cert file fail");
	}
	len=(int)fread(buf,1,sizeof(buf),fp);
	fclose(fp);

	return CCertificate(buf,len);
}
