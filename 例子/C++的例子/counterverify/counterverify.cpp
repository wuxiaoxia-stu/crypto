#include <stdio.h>
#include <string.h>
#include "SignedData.hpp"
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CSignedData;
using Netca::CPKIException;
using Netca::CBlob;
using Netca::CCertificate;

static void usage(const char *fileName);
static std::string utf8Toansi(const std::string &str);
static int printsubject(const char *name,const CCertificate &cert);

int main(int argc,char **argv)
{
	CCertificate cert;
	int rv;
	FILE *fIn=0;
	FILE *fOut=0;
	unsigned char buf[8192];
	int len;
	CBlob out;
	int count;
	char info[64];
	int i;
	int j;
	int counterSignCount;

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
		
		printf("verify signature ok\n");
		count=signedData.getSignerCount();
		printf("signer count :%d\n",count);
		for(i=0;i<count;i++)
		{
			cert=signedData.getSignCert(i);
			sprintf(info,"Sign Cert %d",i+1);
			printsubject(info,cert);
		}

		for(i=0;i<count;i++)
		{
			counterSignCount=signedData.getCounterSignatureCount();
			for(j=0;j<counterSignCount;j++)
			{
				if(signedData.verifyCountersignature(i,j)==false)
				{
					printf("verify countersign %d of sign %d fail\n",j+1,i+1);
				}
				else
				{
					cert=signedData.getCountersignatureCert(i,j);
					sprintf(info,"countersign cert %d of sign %d",j+1,i+1);
					printsubject(info,cert);
				}
			}
				
		}
		
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
		printf("verify countsign fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
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

int printsubject(const char *name,const CCertificate &cert)
{
	printf("%s: %s\n",name,(utf8Toansi(cert.getSubject())).c_str());
	return 1;
}
