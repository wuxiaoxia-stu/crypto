#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"

#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);
static int GetSignAlgoFromName(const char *algoName);
static int GetHashAlgoFromSignAlgo(int signAlgo);
static int HashZ(NETCA_PKI_HASH_HANDLE hHash,int hashAlgo,NETCA_PKI_KEYPAIR_HANDLE hKeyPair);

int main(int argc,char **argv)
{
	int signAlgo;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_KEYPAIR_HANDLE hKeyPair;
	FILE *fp;
	unsigned char buf[8192];
	int len;
	int rv;
	unsigned char *sign;
	int signLen;
	const char *filter;
	int hashAlgo;
	NETCA_PKI_HASH_HANDLE hHash;
	unsigned char *md;
	int mdLen;

	if(argc!=4)
	{
		usage(argv[0]);
		return -1;
	}
	signAlgo=GetSignAlgoFromName(argv[1]);
	if(signAlgo==-1)
	{
		usage(argv[0]);
		return -1;
	}

	if(signAlgo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		filter="Algorithm='SM2'";
	}
	else
	{
		filter="Algorithm='RSA'";
	}

	rv= NetcaPKISelectCert("Signature",filter,&cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKISelectCert fail\n");
		return -1;
	}
	hKeyPair=NetcaPKICertGetCertKeyPair(cert,0,NETCA_PKI_CERT_PURPOSE_SIGN,0);
	NetcaPKICertFreeCert(cert);
	if(hKeyPair==0)
	{
		printf("NetcaPKICertGetCertKeyPair fail\n");
		return -1;
	}
	hashAlgo=GetHashAlgoFromSignAlgo(signAlgo);
	
	hHash=NetcaPKICryptoGetHashHandle(hashAlgo);
	if(hHash==0)
	{
		NetcaPKICryptoFreeKeypair(hKeyPair);
		printf("NetcaPKICryptoGetHashHandle fail\n");
		return -1;
	}

	if(signAlgo==NETCA_PKI_ALGORITHM_SM3WITHSM2)
	{
		rv=HashZ(hHash,hashAlgo,hKeyPair);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICryptoFreeHash(hHash);
			NetcaPKICryptoFreeKeypair(hKeyPair);
			printf("HashZ fail\n");
			return -1;
		}
	}
	
	fp=fopen(argv[2],"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeHash(hHash);
		NetcaPKICryptoFreeKeypair(hKeyPair);
		printf("open %s fail\n",argv[2]);
		return -1;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fp);
		if(ferror(fp)!=0)
		{
			NetcaPKICryptoFreeHash(hHash);
			NetcaPKICryptoFreeKeypair(hKeyPair);
			fclose(fp);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKICryptoHashUpdate(hHash,buf,len);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fp);
				NetcaPKICryptoFreeHash(hHash);
				NetcaPKICryptoFreeKeypair(hKeyPair);
				printf("NetcaPKICryptoHashUpdate fail\n");
				return -1;
			}
		}

		if(feof(fp))
		{
			break;
		}
	}
	fclose(fp);
	
	rv=NetcaPKICryptoHashFinal(hHash,&md,&mdLen);
	NetcaPKICryptoFreeHash(hHash);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeKeypair(hKeyPair);
		printf("NetcaPKICryptoHashFinal fail\n");
		return -1;
	}

	rv=NetcaPKICryptoSignHash(hKeyPair,signAlgo,0,md,mdLen,&sign,&signLen);
	NetcaPKICryptoFreeKeypair(hKeyPair);
	NetcaPKICryptoFreeMemory(md);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeKeypair(hKeyPair);
		printf("NetcaPKICryptoSignHash fail\n");
		return -1;
	}

	rv=SaveFile(argv[3],sign,signLen);
	NetcaPKICryptoFreeMemory(sign);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}

	printf("Success\n");
	return 0;
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

int GetHashAlgoFromSignAlgo(int signAlgo)
{
	switch(signAlgo)
	{
	case NETCA_PKI_ALGORITHM_MD5WITHRSA:
		return NETCA_PKI_ALGORITHM_MD5;
	case NETCA_PKI_ALGORITHM_SHA1WITHRSA:
		return NETCA_PKI_ALGORITHM_SHA1;
	case NETCA_PKI_ALGORITHM_SHA256WITHRSA:
		return NETCA_PKI_ALGORITHM_SHA256;
	case NETCA_PKI_ALGORITHM_SHA512WITHRSA:
		return NETCA_PKI_ALGORITHM_SHA512;
	case NETCA_PKI_ALGORITHM_SM3WITHSM2:
		return NETCA_PKI_ALGORITHM_SM3;
	default:
		return -1;
	}
}

int HashZ(NETCA_PKI_HASH_HANDLE hHash,int hashAlgo,NETCA_PKI_KEYPAIR_HANDLE hKeyPair)
{
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
	struct NETCA_PKI_SM2Sign_PARAM_st param;
	unsigned char id[16];
	unsigned char *Z;
	int ZLen;
	int rv;

	hPublicKey=NetcaPKICryptoGetPublicKeyFromKeypair(hKeyPair);
	if(hPublicKey==0)
	{
		return NETCA_PKI_FAIL;
	}

	param.m_idbits=128;
	param.m_id=id;
	memcpy(id,"1234567812345678",16);

	rv=NetcaPKIComputeSM2Z(hPublicKey,hashAlgo,&param,&Z,&ZLen);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICryptoHashUpdate(hHash,Z,ZLen);
	NetcaPKICryptoFreeMemory(Z);
	return rv;
}
