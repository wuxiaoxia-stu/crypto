#include <stdio.h>
#include "Certificate.hpp"
#include "PKIException.hpp"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

using Netca::CCertificate;
using Netca::CPKIException;

static void usage(const char *fileName);
static CCertificate getcert(const char *fileName);
static std::string utf8Toansi(const std::string &str);
static void printversion(long version);
static void printsignalgo(long algo);
static void printpublickeyalgo(long algo);
static void printkeyusage(long keyusage);

int main(int argc,char **argv)
{
	int version;
	int signAlgo;
	int publickeyAlgo;
	int publickeyLen;
	int keyusage;

	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	try
	{
		CCertificate cert=getcert(argv[1]);
		version=cert.getVersion();
		printversion(version);
		
		printf("SerialNumber: %s\n",cert.getSerialNumber().c_str());
		
		signAlgo=cert.getSignAlgo();
		printsignalgo(signAlgo);
		printf("Issuer: %s\n",(utf8Toansi(cert.getIssuer())).c_str());
		
		printf("NotBefore: %s\n",cert.getNotBefore().c_str());
		printf("NotAfter: %s\n",cert.getNotAfter().c_str());
		
		printf("Subject: %s\n",(utf8Toansi(cert.getSubject())).c_str());
		
		publickeyAlgo=cert.getPublicKeyAlgo();
		printpublickeyalgo(publickeyAlgo);

		publickeyLen=cert.getPublicKeyBits();
		printf("PublicKey Bits: %ldÎ»\n",publickeyLen);

		keyusage=cert.getKeyUsage();
		printkeyusage(keyusage);
		return 0;
	}
	catch(CPKIException& e)
	{
		printf("get cert info fail,error code£º%d£¬error msg£º%s\n",e.errorCode(),e.what());
		return -1;
	}
}


void usage(const char *fileName)
{
	printf("Usage: %s certFileName",fileName);
}

void printversion(long version)
{
	switch(version)
	{
	case NETCA_PKI_CERT_VERSION_V1:
		printf("Version: V1\n");
		break;
	case NETCA_PKI_CERT_VERSION_V2:
		printf("Version: V2\n");
		break;
	case NETCA_PKI_CERT_VERSION_V3:
		printf("Version: V3\n");
		break;
	default:
		printf("Version: unknown version(%ld)\n",version);
		break;
	}
}


void printsignalgo(long algo)
{
	switch(algo)
	{
	case NETCA_PKI_ALGORITHM_MD5WITHRSA:
		printf("Sign Algorithm: MD5WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA1WITHRSA:
		printf("Sign Algorithm: SHA1WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA224WITHRSA:
		printf("Sign Algorithm: SHA224WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA256WITHRSA:
		printf("Sign Algorithm: SHA256WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA384WITHRSA:
		printf("Sign Algorithm: SHA384WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_SHA512WITHRSA:
		printf("Sign Algorithm: SHA512WithRSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA1:
		printf("Sign Algorithm: DSAWithSHA1\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA224:
		printf("Sign Algorithm: DSAWithSHA224\n");
		break;
	case NETCA_PKI_ALGORITHM_DSAWITHSHA256:
		printf("Sign Algorithm: DSAWithSHA256\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA1:
		printf("Sign Algorithm: ECDSAWithSHA1\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA224:
		printf("Sign Algorithm: ECDSAWithSHA224\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA256:
		printf("Sign Algorithm: ECDSAWithSHA256\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA384:
		printf("Sign Algorithm: ECDSAWithSHA384\n");
		break;
	case NETCA_PKI_ALGORITHM_ECDSAWITHSHA512:
		printf("Sign Algorithm: ECDSAWithSHA512\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_PSS:
		printf("Sign Algorithm: RSA PSS\n");
		break;
	case NETCA_PKI_ALGORITHM_SM3WITHSM2:
		printf("Sign Algorithm: SM3WithSM2\n");
		break;
	case NETCA_PKI_ALGORITHM_SM3WITHRSA:
		printf("Sign Algorithm: SM3WithRSA\n");
		break;
	default:
		printf("Sign Algorithm: unknown sign algorithm(%ld)\n",algo);
		break;
	}
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


void printpublickeyalgo(long algo)
{
	switch(algo)
	{
	case NETCA_PKI_ALGORITHM_RSA:
		printf("PublicKey Algorithm: RSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DSA:
		printf("PublicKey Algorithm: DSA\n");
		break;
	case NETCA_PKI_ALGORITHM_DH:
		printf("PublicKey Algorithm: DH\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC:
		printf("PublicKey Algorithm: ECC\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_ONLY_OAEP:
		printf("PublicKey Algorithm: RSA OAEP\n");
		break;
	case NETCA_PKI_ALGORITHM_RSA_ONLY_PSS:
		printf("PublicKey Algorithm: RSA PSS\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC_ONLY_ECDH:
		printf("PublicKey Algorithm: ECC ECDH\n");
		break;
	case NETCA_PKI_ALGORITHM_ECC_ONLY_ECMQV:
		printf("PublicKey Algorithm: ECC ECMQV\n");
		break;
	default:
		printf("PublicKey Algorithm: unkown publickey algorithm(%ld)\n",algo);
		break;

	}
}

void printkeyusage(long keyusage)
{
	int first=1;
	if(keyusage==-1)
	{
		printf("KeyUsage: no keyusage extension\n");
		return;
	}
	
	printf("KeyUsage: ");

	if(keyusage&NETCA_PKI_KEYUSAGE_DIGITALSIGNATURE)
	{
		if (first)
        {
			printf("digitalSignature");
			first=0;
        }
        else
        {
            printf(",digitalSignature");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_NONREPUDIATION)
	{
		if (first)
        {
			printf("nonRepudiation/contentCommitment");
			first=0;
        }
        else
        {
            printf(",nonRepudiation/contentCommitment");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_KEYENCIPHERMENT)
	{
		if (first)
        {
			printf("keyEncipherment");
			first=0;
        }
        else
        {
            printf(",keyEncipherment");
		}
	}


	if(keyusage&NETCA_PKI_KEYUSAGE_DATAENCIPHERMENT)
	{
		if (first)
        {
			printf("dataEncipherment");
			first=0;
        }
        else
        {
            printf(",dataEncipherment");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_KEYAGREEMENT)
	{
		if (first)
        {
			printf("keyAgreement");
			first=0;
        }
        else
        {
            printf(",keyAgreement");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_KEYCERTSIGN)
	{
		if (first)
        {
			printf("keyCertSign");
			first=0;
        }
        else
        {
            printf(",keyCertSign");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_CRLSIGN)
	{
		if (first)
        {
			printf("cRLSign");
			first=0;
        }
        else
        {
            printf(",cRLSign");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_ENCIPHERONLY)
	{
		if (first)
        {
			printf("encipherOnly");
			first=0;
        }
        else
        {
            printf(",encipherOnly");
		}
	}

	if(keyusage&NETCA_PKI_KEYUSAGE_DECIPHERONLY)
	{
		if (first)
        {
			printf("decipherOnly");
			first=0;
        }
        else
        {
            printf(",decipherOnly");
		}
	}

	printf("\n");

}
