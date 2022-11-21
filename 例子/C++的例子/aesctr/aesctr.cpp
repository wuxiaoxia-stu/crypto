#include <stdio.h>
#include "Cipher.hpp"
#include "PKIException.hpp"

static void usage(const char *filename);

using Netca::CBlob;
using Netca::CPKIException;
using Netca::CCipher;

int main(int argc,char **argv)
{
	bool enc;
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	
	if(argc!=6)
	{
		usage(argv[0]);
		return -1;
	}
	
	if(strcmp(argv[1],"/e")==0 || strcmp(argv[1],"-e")==0)
	{
		enc=true;
	}
	else if(strcmp(argv[1],"/d")==0 || strcmp(argv[1],"-d")==0)
	{
		enc=false;
	}
	else
	{
		usage(argv[0]);
		return -1;
	}
	try
	{
		CCipher cipher(enc,NETCA_PKI_ALGORITHM_AES_CTR);

		CBlob key;
		key.decodeHexString(argv[2]);
		cipher.setKey(key.data(),key.length());
		
		CBlob iv;
		iv.decodeHexString(argv[3]);
		cipher.setCtrParam(128,iv.data(),iv.length());

		cipher.init();

		fIn=fopen(argv[4],"rb");
		if(fIn==0)
		{
			printf("open %s fail\n",argv[4]);
			return -1;
		}

		fOut=fopen(argv[5],"wb");
		if(fOut==0)
		{
			fclose(fIn);
			fIn=0;
			printf("open %s fail\n",argv[5]);
			return -1;
		}

		CBlob out;
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
				cipher.update(buf,len,out);
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
		cipher.final(out);
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
		
		printf("cipher fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
	if(enc)
	{
		printf("encrypt success\n");
	}
	else
	{
		printf("decrypt success\n");
	}

	return 0;
}


void usage(const char *filename)
{
	printf("Usage: %s /e|/d key iv inFileName outFileName",filename);
}
