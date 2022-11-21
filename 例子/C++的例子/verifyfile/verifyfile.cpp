#include <stdio.h>
#include <string.h>
#include "PKIException.hpp"
#include "Certificate.hpp"
#include "SignedData.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CSignedData;
using Netca::CPKIException;
using Netca::CCertificate;
using Netca::CBlob;

static void usage(const char *fileName);
static std::string utf8Toansi(const std::string &str);

int main(int argc,char **argv)
{
	int rv;
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	CBlob out;
	
	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CSignedData signedData(false);
		
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
		
		signedData.verifyInit();
		
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
				signedData.verifyUpdate(buf,len,out);
				
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
		fclose(fOut);
		fOut=0;

		rv=signedData.verifyFinal();
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("NetcaPKIMsgSignedDataVerifyFinal fail\n");
			return -1;
		}
		

		CCertificate cert=signedData.getSignCert();
		printf("Verify Success\nThe subject of sign cert is %s\n",utf8Toansi(cert.getSubject()).c_str());
		
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
		printf("verify fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}

void usage(const char *fileName)
{
	printf("Usage: %s signFile tbsFile\n",fileName);
}

std::string utf8Toansi(const std::string &str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *mbs;
	long mbsLen;

	ustr=netca_ustring_newutf8((const unsigned char *)str.data(),(long)str.length());
	if(ustr==0)
	{
		throw CPKIException("netca_ustring_newutf8 fail");
	}

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		netca_ustring_free(ustr);
		throw CPKIException("netca_ustring_getdefaultcharset fail");
	}

	rv=netca_ustring_tombs(ustr,charset,&mbs,&mbsLen);
	NETCA_FREE(charset);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		throw CPKIException("netca_ustring_tombs fail");
	}
	
	try
	{
		std::string retStr((char *)mbs,(int)mbsLen);
		NETCA_FREE(mbs);
		mbs=0;
		return retStr;
	}
	catch(...)
	{
		if(mbs)
		{
			NETCA_FREE(mbs);
		}
		throw;
	}
}
