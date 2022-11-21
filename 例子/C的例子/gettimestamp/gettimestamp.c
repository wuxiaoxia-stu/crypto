#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"


#ifdef _WIN32
#define STRINGCASECMP _stricmp
#else
#define STRINGCASECMP strcasecmp
#endif

static void usage(const char *fileName);
static int Hash(int algo,const char *fileName,unsigned char **md,int *mdLen);
static char *utf8Toansi(const char *str);
static int SaveFile(const char *fileName,const unsigned char *buf,int bufLen);
static int GetHashAlgoFromName(const char *algoName);

int main(int argc,char **argv)
{
	NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
	int rv;
	int hashAlgo;
	unsigned char *md;
	int mdLen;
	int status;
	char *time;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	char *ansistr;
	char *subject;
	unsigned char *token;
	int tokenLen;

	if(argc!=5)
	{
		usage(argv[0]);
		return -1;
	}

	hTimeStamp=NetcaPKIMsgNewTimeStamp();
	if(hTimeStamp==0)
	{
		printf("NetcaPKIMsgNewTimeStamp fail\n");
		return -1;
	}

	rv=NetcaPKIMsgTimeStampSetTSA(hTimeStamp,argv[1]);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("NetcaPKIMsgTimeStampSetTSA fail\n");
		return -1;
	}

	hashAlgo=GetHashAlgoFromName(argv[2]);
	if(hashAlgo==-1)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("NetcaPKIMsgTimeStampSetTSA fail\n");
		return -1;
	}

	rv=NetcaPKIMsgTimeStampSetHashAlgorithm(hTimeStamp,hashAlgo);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		usage(argv[0]);
		return -1;
	}

	rv=Hash(hashAlgo,argv[3],&md,&mdLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("Hash fail\n");
		return -1;
	}

	rv=NetcaPKIMsgTimeStampSetMessageImprint(hTimeStamp,md,mdLen);
	NetcaPKICryptoFreeMemory(md);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("NetcaPKIMsgTimeStampSetMessageImprint fail\n");
		return -1;
	}

	rv=NetcaPKIMsgTimeStampGetResponse(hTimeStamp,&status);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("NetcaPKIMsgTimeStampGetResponse fail\n");
		return -1;
	}

	if(status!=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTED
		&& status !=NETCA_PKI_TIMESTAMP_RESP_STATUS_GRANTEDWITHMODS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("get timestamp resp fail,return status %d\n",status);
		return -1;
	}

	time=NetcaPKIMsgTimeStampGetTime(hTimeStamp);
	printf("timestamp time:%s\n",time);
	NetcaPKICryptoFreeMemory(time);

	cert=NetcaPKIMsgTimeStampGetTSACert(hTimeStamp);
	
	rv=NetcaPKICertGetCertStringAttribute(cert,NETCA_PKI_CERT_ATTRIBUTE_SUBJECT,&subject);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("get subject fail\n");
		return -1;
	}
	ansistr=utf8Toansi(subject);
	NetcaPKICryptoFreeMemory(subject);
	if(ansistr==0)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("utf8Toansi fail\n");
		return -1;
	}
	printf("subject:%s\n",ansistr);
	NETCA_FREE(ansistr);

	rv=NetcaPKIMsgTimeStampGetTimeStampToken(hTimeStamp,&token,&tokenLen);
	NetcaPKIMsgFreeTimeStamp(hTimeStamp);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("NetcaPKIMsgTimeStampGetTimeStampToken fail\n");
		return -1;
	}

	rv=SaveFile(argv[4],token,tokenLen);
	NetcaPKICryptoFreeMemory(token);
	if(rv==0)
	{
		printf("SaveFile fail\n");
		return -1;
	}

	return 0;
}

void usage(const char *fileName)
{
	printf("Usage: %s url sha-1|sha-256|sm3 infile token\n",fileName);
}

int Hash(int algo,const char *fileName,unsigned char **md,int *mdLen)
{
	unsigned char buf[8192];
	NETCA_PKI_HASH_HANDLE hHash;
	int len;
	FILE *fp;
	int rv;

	hHash=NetcaPKICryptoGetHashHandle(algo);
	if(hHash==0)
	{
		return 0;
	}
	
	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		NetcaPKICryptoFreeHash(hHash);
		return 0;
	}

	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fp);
		if(ferror(fp)!=0)
		{
			fclose(fp);
			NetcaPKICryptoFreeHash(hHash);
			return 0;
		}
		if(len>0)
		{
			rv=NetcaPKICryptoHashUpdate(hHash,buf,len);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fp);
				NetcaPKICryptoFreeHash(hHash);
				return 0;
			}
		}
		if(feof(fp))
		{
			break;
		}
	}
	fclose(fp);

	rv=NetcaPKICryptoHashFinal(hHash,md,mdLen);
	NetcaPKICryptoFreeHash(hHash);
	return rv==NETCA_PKI_SUCCESS;
	
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

int GetHashAlgoFromName(const char *algoName)
{
	if(STRINGCASECMP(algoName,"md5")==0)
	{
		return NETCA_PKI_ALGORITHM_MD5;
	}
	else if(STRINGCASECMP(algoName,"sha1")==0
		|| STRINGCASECMP(algoName,"sha-1")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA1;
	}
	else if(STRINGCASECMP(algoName,"sha256")==0
		|| STRINGCASECMP(algoName,"sha-256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA256;
	}
	else if(STRINGCASECMP(algoName,"sha512")==0
		|| STRINGCASECMP(algoName,"sha-512")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512;
	}
	else if(STRINGCASECMP(algoName,"sm3")==0)
	{
		return NETCA_PKI_ALGORITHM_SM3;
	}
	else if(STRINGCASECMP(algoName,"sha224")==0
		|| STRINGCASECMP(algoName,"sha-224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA224;
	}
	else if(STRINGCASECMP(algoName,"sha384")==0
		|| STRINGCASECMP(algoName,"sha-384")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA384;
	}
	else if(STRINGCASECMP(algoName,"sha-512/224")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_224;
	}
	else if(STRINGCASECMP(algoName,"sha-512/256")==0)
	{
		return NETCA_PKI_ALGORITHM_SHA512_256;
	}
	else
	{
		return -1;
	}
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

