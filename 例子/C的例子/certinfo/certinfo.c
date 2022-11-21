#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *fileName);
static void printversion(long version);
static void printsignalgo(long algo);
static char *utf8Toansi(const char *str);
static void printpublickeyalgo(long algo);
static void printkeyusage(long keyusage);

int main(int argc,char **argv)
{
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	int rv;
	long version;
	char *sn;
	long signAlgo;
	char *issuer;
	char *ansistr;
	char *notbefore;
	char *notafter;
	char *subject;
	long publickeyAlgo;
	long publickeyLen;
	long keyusage;

	if(argc!=2)
	{
		usage(argv[0]);
		return -1;
	}

	cert=getcert(argv[1]);
	if(cert==0)
	{
		printf("bad cert file\n");
		return -1;
	}
	
	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_VERSION,&version);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get version fail\n");
		return -1;
	}
	printversion(version);
	

	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SN_HEX,&sn);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get sn fail\n");
		return -1;
	}
	printf("SerialNumber: %s\n",sn);
	NetcaPKICryptoFreeMemory(sn);

	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SIGNALGO,&signAlgo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get sign algorithm fail\n");
		return -1;
	}
	printsignalgo(signAlgo);


	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_ISSUER,&issuer);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get issuer fail\n");
		return -1;
	}
	ansistr=utf8Toansi(issuer);
	NetcaPKICryptoFreeMemory(issuer);
	if(ansistr==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("issuer utf8Toansi fail\n");
		return -1;
	}
	printf("Issuer: %s\n",ansistr);
	NETCA_FREE(ansistr);

	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_VALIDITY_START,&notbefore);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get notbefore fail\n");
		return -1;
	}
	printf("NotBefore: %s\n",notbefore);
	NetcaPKICryptoFreeMemory(notbefore);

	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_VALIDITY_END,&notafter);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get notafter fail\n");
		return -1;
	}
	printf("NotAfter: %s\n",notafter);
	NetcaPKICryptoFreeMemory(notafter);

	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT,&subject);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get issuer fail\n");
		return -1;
	}
	ansistr=utf8Toansi(subject);
	NetcaPKICryptoFreeMemory(subject);
	if(ansistr==0)
	{
		NetcaPKICertFreeCert(cert);
		printf("subject utf8Toansi fail\n");
		return -1;
	}
	printf("Subject: %s\n",ansistr);
	NETCA_FREE(ansistr);


	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_PUBKEYALGO,&publickeyAlgo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get public key algoritm fail\n");
		return -1;
	}
	printpublickeyalgo(publickeyAlgo);

	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_PUBKEYBITS,&publickeyLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get public key bit fail\n");
		return -1;
	}
	printf("PublicKey Bits: %ld\n",publickeyLen);


	rv=NetcaPKICertGetCertIntegerAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_KEYUSAGE,&keyusage);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(cert);
		printf("get keyusage fail\n");
		return -1;
	}
	printkeyusage(keyusage);

	NetcaPKICertFreeCert(cert);
	return 0;
}


void usage(const char *fileName)
{
	printf("Usage: %s certFileName",fileName);
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


char *utf8Toansi(const char *str)
{
	NETCA_UString ustr;
	char *charset;
	int rv;
	unsigned char *mbs;
	long mbsLen;

	ustr=netca_ustring_newutf8((const unsigned char *)str,(long)strlen(str));
	if(ustr==0)
	{
		return 0;
	}

	charset=netca_ustring_getdefaultcharset();
	if(charset==0)
	{
		netca_ustring_free(ustr);
		return 0;
	}

	rv=netca_ustring_tombs(ustr,charset,&mbs,&mbsLen);
	NETCA_FREE(charset);
	netca_ustring_free(ustr);
	if(rv!=NETCA_OK)
	{
		return 0;
	}

	return (char *)mbs;
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
