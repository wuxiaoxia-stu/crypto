#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "NETCA_PKI_Crypto.h"


static void usage(const char *filename);
static int HexDecode(const char *hex,unsigned char **data,int *dataLen);
static int DecodeHexByte(const char *hex,unsigned char *data);
static int DecodeHexHalfByte(char ch);
static long GetFileLength(FILE *fp);
static int SaveFile(const char *fileName,const unsigned char *buf,size_t bufLen);

int main(int argc,char **argv)
{
	int enc;
	unsigned char *key;
	int keyLen;
	unsigned char *iv;
	int ivLen;
	int rv;
	NETCA_PKI_CIPHER_HANDLE hCipher;
	FILE *fIn;
	unsigned char *buf;
	long len;
	unsigned char *out;
	long long outLen;
	struct NETCA_PKI_GCMParam_st param;
	const char *aad;
	int aadLen;
	int pos;

	if(argc!=6 && argc!=7)
	{
		usage(argv[0]);
		return -1;
	}
	
	if(strcmp(argv[1],"/e")==0 || strcmp(argv[1],"-e")==0)
	{
		enc=1;
	}
	else if(strcmp(argv[1],"/d")==0 || strcmp(argv[1],"-d")==0)
	{
		enc=0;
	}
	else
	{
		usage(argv[0]);
		return -1;
	}
	

	rv=HexDecode(argv[2],&key,&keyLen);
	if(rv==0)
	{
		printf("bad hex key\n");
		return -1;
	}

	rv=HexDecode(argv[3],&iv,&ivLen);
	if(rv==0)
	{
		NetcaPKICryptoFreeMemory(key);
		printf("bad hex iv\n");
		return -1;
	}

	
	if(argc==6)
	{
		aad=0;
		aadLen=0;
		pos=4;	
	}
	else
	{
		aad=argv[4];
		aadLen=(int)strlen(aad);
		pos=5;
	}

	param.m_tLen=16;
	param.m_iv=iv;
	param.m_ivLen=ivLen;
	param.m_aad=(unsigned char *)aad;
	param.m_aadLen=aadLen;

	hCipher=NetcaPKICryptoGetCipherHandle(enc,NETCA_PKI_ALGORITHM_AES_GCM,
		key,keyLen,&param);
	NetcaPKICryptoFreeMemory(key);
	NetcaPKICryptoFreeMemory(iv);
	
	if(hCipher==0)
	{
		printf("NetcaPKICryptoGetCipherHandle fail\n");
		return -1;
	}

	fIn=fopen(argv[pos],"rb");
	if(fIn==0)
	{
		NetcaPKICryptoFreeCipher(hCipher);
		printf("open %s fail\n",argv[pos]);
		return -1;
	}
	pos++;
	
	len=GetFileLength(fIn);
	if(len<0)
	{
		NetcaPKICryptoFreeCipher(hCipher);
		fclose(fIn);
		printf("GetFileLength fail\n");
		return -1;
	}

	buf=(unsigned char *)NetcaPKICryptoAllocMemory(len);
	if(buf==0)
	{
		NetcaPKICryptoFreeCipher(hCipher);
		fclose(fIn);
		printf("NetcaPKICryptoAllocMemory fail\n");
		return -1;
	}
	fread(buf,1,len,fIn);
	if(ferror(fIn)!=0)
	{
		NetcaPKICryptoFreeMemory(buf);
		NetcaPKICryptoFreeCipher(hCipher);
		fclose(fIn);
		printf("fread fail\n");
		return -1;
	}
	fclose(fIn);
	
	rv=NetcaPKICryptoCipher(hCipher,buf,len,0,0,&outLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeMemory(buf);
		NetcaPKICryptoFreeCipher(hCipher);
		printf("NetcaPKICryptoCipher fail\n");
		return -1;
	}
	if(outLen>LONG_MAX)
	{
		NetcaPKICryptoFreeMemory(buf);
		NetcaPKICryptoFreeCipher(hCipher);
		printf("return outLen too long\n");
		return -1;
	}

	out=(unsigned char *)NetcaPKICryptoAllocMemory((long)outLen);
	if(out==0)
	{
		NetcaPKICryptoFreeMemory(buf);
		NetcaPKICryptoFreeCipher(hCipher);
		printf("NetcaPKICryptoAllocMemory fail\n");
		return -1;
	}
	
	rv=NetcaPKICryptoCipher(hCipher,buf,len,out,outLen,&outLen);
	NetcaPKICryptoFreeMemory(buf);
	NetcaPKICryptoFreeCipher(hCipher);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeMemory(out);
		printf("NetcaPKICryptoCipher fail\n");
		return -1;
	}
	
	rv=SaveFile(argv[pos],out,(size_t)outLen);
	NetcaPKICryptoFreeMemory(out);
	if(rv==0)
	{
		printf("save %s fail\n",argv[pos]);
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
	printf("Usage: %s /e|/d key iv [aad] inFileName outFileName",filename);
}


int HexDecode(const char *hex,unsigned char **data,int *dataLen)
{
	int len;
	unsigned char *buf;
	int bufLen;
	int i;
	int j;

	len=(int)strlen(hex);

	if(len%2!=0)
	{
		return 0;
	}

	bufLen=len/2;
	buf=(unsigned char *)NetcaPKICryptoAllocMemory(bufLen);
	if(buf==0)
	{
		return 0;
	}
	
	for(i=0,j=0;i<len;i+=2,j++)
	{
		if(DecodeHexByte(&hex[i],&buf[j])==0)
		{
			NetcaPKICryptoFreeMemory(buf);
			return 0;
		}
	}

	*data=buf;
	*dataLen=bufLen;
	return 1;
}

int DecodeHexByte(const char *hex,unsigned char *data)
{
	int high;
	int low;

	high=DecodeHexHalfByte(hex[0]);
	if(high==-1)
	{
		return 0;
	}
	
	low=DecodeHexHalfByte(hex[1]);
	if(low==-1)
	{
		return 0;
	}

	*data=(unsigned char)(high<<4|low);
	return 1;
}

int DecodeHexHalfByte(char ch)
{
	if(ch>='0' && ch<='9')
	{
		return ch-'0';
	}
	else if(ch>='a' && ch<='f')
	{
		return ch-'a'+10;
	}
	else if(ch>='A' && ch<='F')
	{
		return ch-'A'+10;
	}
	else
	{
		return -1;
	}
}

long GetFileLength(FILE *fp)
{
	long  len;
	if(fseek(fp,0,SEEK_END)!=0)
	{
		return -1L;
	}
	len=ftell(fp);
	if(fseek(fp,0,SEEK_SET)!=0)
	{
		return -1L;
	}
	
	return len;
}


int SaveFile(const char *fileName,const unsigned char *buf,size_t bufLen)
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
	return len==(int)bufLen;
}
