#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Application.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"

static void usage(const char *fileName);
static int Hash(int algo,const char *fileName,unsigned char **md,int *mdLen);
static char *utf8Toansi(const char *str);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName,unsigned char **data,int *dataLen);

int main(int argc,char **argv)
{
	int rv;
	unsigned char *token;
	int tokenLen;
	NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp;
	int algo;
	unsigned char *md;
	int mdLen;
	unsigned char *md2;
	int md2Len;
	char *time;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	char *ansistr;
	char *subject;

	if(argc!=3)
	{
		usage(argv[0]);
		return -1;
	}
	rv=ReadFileData(argv[2],&token,&tokenLen);
	if(rv==0)
	{
		printf("read %s fail\n",argv[2]);
		return -1;
	}
	hTimeStamp=NetcaPKIMsgVerifyTimeStampToken(token,tokenLen,0);
	NetcaPKICryptoFreeMemory(token);
	if(hTimeStamp==0)
	{
		printf("NetcaPKIMsgVerifyTimeStampToken fail\n");
		return -1;
	}

	algo=NetcaPKIMsgTimeStampGetHashAlgorithm(hTimeStamp);
	rv=Hash(algo,argv[1],&md,&mdLen);
	if(rv==0)
	{
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("Hash fail\n");
		return -1;
	}

	rv=NetcaPKIMsgTimeStampGetMessageImprint(hTimeStamp,&md2,&md2Len);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeMemory(md);
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("NetcaPKIMsgTimeStampGetMessageImprint fail\n");
		return -1;
	}
	if(mdLen!=md2Len)
	{
		NetcaPKICryptoFreeMemory(md);
		NetcaPKICryptoFreeMemory(md2);
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("hash value mismatch\n");
		return -1;
	}

	if(memcmp(md,md2,mdLen)!=0)
	{
		NetcaPKICryptoFreeMemory(md);
		NetcaPKICryptoFreeMemory(md2);
		NetcaPKIMsgFreeTimeStamp(hTimeStamp);
		printf("hash value mismatch\n");
		return -1;
	}
	NetcaPKICryptoFreeMemory(md);
	NetcaPKICryptoFreeMemory(md2);


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

	NetcaPKIMsgFreeTimeStamp(hTimeStamp);
	return 0;
}


void usage(const char *fileName)
{
	printf("Usage: %s infile token\n",fileName);
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


int GetFileLength(FILE *fp)
{
	int  len;
	if(fseek(fp,0,SEEK_END)!=0)
	{
		return -1;
	}
	len=ftell(fp);
	if(fseek(fp,0,SEEK_SET)!=0)
	{
		return -1;
	}
	
	return len;
}

int ReadFileData(const char *fileName,unsigned char **data,int *dataLen)
{
	FILE *fp;
	int len;
	unsigned char *buf;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		return 0;
	}

	len=GetFileLength(fp);
	if(len<0)
	{
		fclose(fp);
		return 0;
	}
	
	buf=(unsigned char *)NetcaPKICryptoAllocMemory(len);
	if(buf==0)
	{
		fclose(fp);
		return 0;
	}
	if((int)fread(buf,1,len,fp)!=len)
	{
		NetcaPKICryptoFreeMemory(buf);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	*data=buf;
	*dataLen=len;
	return 1;
}

