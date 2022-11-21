#include <stdio.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"

//static int verifyCert(NETCA_PKI_CERTIFICATE_HANDLE hCert);
static int getHashValue(int algo,const unsigned char *data,int datalen,unsigned char **hashvalue,int *hashvaluelen);


static int getTimeStamp(const char *tspUrl,int hashAlgo,const unsigned char *data,int datalen,unsigned char **token,int *tokenlen);
static int verifyTimeStamp(const unsigned char *data,int datalen,const unsigned char *token,int tokenlen);



int main()
{
	int rv;
	int hashAlgo=NETCA_PKI_ALGORITHM_SHA256;

	unsigned char data[1024];
	int datalen=sizeof(data);


	char tspUrl[]="http://tsa.cnca.net/SM2/NETCATimeStampServer/TSAServer.jsp";

	

	unsigned char *token;
	int tokenlen;

	rv=getTimeStamp(tspUrl,hashAlgo,data,datalen,&token,&tokenlen);

	rv=verifyTimeStamp(data,datalen,token,tokenlen);
}

static int getTimeStamp(const char *tspUrl,int hashAlgo,const unsigned char *data,int datalen,unsigned char **token,int *tokenlen)
{
	int rv;
	unsigned char *hashvalue;
	int hashvaluelen;
	NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
	int status;

	hTimeStamp=NetcaPKIMsgNewTimeStamp();
	if(hTimeStamp==0)
	{
		printf("NetcaPKIMsgNewTimeStamp, Fail.\n");
		return 0;
	}

	rv=NetcaPKIMsgTimeStampSetTSA(hTimeStamp,tspUrl);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampSetTSA, Fail.\n");
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=getHashValue(hashAlgo,data,datalen,&hashvalue,&hashvaluelen);
	if(rv!=1)
	{
		printf("get hash fail.\n");
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=NetcaPKIMsgTimeStampSetHashAlgorithm(hTimeStamp,hashAlgo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampSetTSA, Fail.\n");
		NetcaPKICryptoFreeMemory(hashvalue);
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=NetcaPKIMsgTimeStampSetMessageImprint(hTimeStamp,hashvalue,hashvaluelen);
	NetcaPKICryptoFreeMemory(hashvalue);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampSetTSA, Fail.\n");
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=NetcaPKIMsgTimeStampGetResponse(hTimeStamp,&status);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampSetTSA, Fail.\n");
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	if(status!=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTED && 
		status!=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
	{
		printf("timestap status error.\n");
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=NetcaPKIMsgTimeStampGetTimeStampToken(hTimeStamp,token,tokenlen);
	NetcaPKIMsgFreeTimeStamp(hTimeStamp);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampGetTimeStampToken, Fail.\n");
		return 0;
	}

	return 1;
}

/*
static int verifyCert(NETCA_PKI_CERTIFICATE_HANDLE hCert)
{
	int rv;
	int status;
	NETCA_PKI_REVOKEDCERT_HANDLE info;
	int flag=NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_REVOKE | 
		NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_OCSP | 
		NETCA_PKI_CERTIFICATE_VERIFY_FLAG_VERIFY_CRL;
	
	rv=NetcaPKICertVerifyCert(hCert,NULL,flag,&status,&info);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKICertVerifyCert, Fail.\n");
		return 0;
	}
	if(status!=NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED)
	{
		printf("certificate status error.\n");
		return 0;
	}
	
	return 1;
}*/



static int getHashValue(int algo,const unsigned char *data,int datalen,unsigned char **hashvalue,int *hashvaluelen)
{
	int rv;
	NETCA_PKI_HASH_HANDLE hHash;

	hHash=NetcaPKICryptoGetHashHandle(algo);
	if(hHash==0)
	{
		return 0;
	}

	rv=NetcaPKICryptoHashUpdate(hHash,data,datalen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeHash(hHash);
		return 0;
	}

	rv=NetcaPKICryptoHashFinal(hHash,hashvalue,hashvaluelen);
	NetcaPKICryptoFreeHash(hHash);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}
	return 1;
}


static int verifyTimeStamp(const unsigned char *data,int datalen,const unsigned char *token,int tokenlen)
{
	int rv;
	int hashAlgo;
	unsigned char *hash1;
	int hash1len;
	unsigned char *hash2;
	int hash2len;
	NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;

	hTimeStamp=NetcaPKIMsgVerifyTimeStampToken(token,tokenlen,0);
	if(hTimeStamp==0)
	{
		return 0;
	}

	hashAlgo=NetcaPKIMsgTimeStampGetHashAlgorithm(hTimeStamp);
	if(hashAlgo==-1)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		return 0;
	}

	rv=NetcaPKIMsgTimeStampGetMessageImprint(hTimeStamp,&hash1,&hash1len);
	NetcaPKIMsgFreeTimeStamp(hTimeStamp);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}

	rv=getHashValue(hashAlgo,data,datalen,&hash2,&hash2len);
	if(rv!=1)
	{
		NetcaPKICryptoFreeMemory(hash1);
		return 0;
	}

	if(hash1len!=hash2len || memcmp(hash1,hash2,hash1len))
	{
		NetcaPKICryptoFreeMemory(hash1);
		NetcaPKICryptoFreeMemory(hash2);
		return 0;
	}

	NetcaPKICryptoFreeMemory(hash1);
	NetcaPKICryptoFreeMemory(hash2);
	return 1;
}