#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"


static void usage(const char *filename);
static int HexDecode(const char *hex,unsigned char **data,int *dataLen);
static int DecodeHexByte(const char *hex,unsigned char *data);
static int DecodeHexHalfByte(char ch);

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
	FILE *fOut;
	unsigned char buf[8192];
	int len;
	unsigned char *out;
	int outLen;
	struct NETCA_PKI_CTRParam_st param;

	if(argc!=6)
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

	if(ivLen!=16)
	{
		NetcaPKICryptoFreeMemory(key);
		NetcaPKICryptoFreeMemory(iv);
		printf("bad iv length\n");
		return -1;
	}
	param.m_count_bits=128;
	memcpy(&param.m_iv,iv,16);
	NetcaPKICryptoFreeMemory(iv);

	hCipher=NetcaPKICryptoGetCipherHandle(enc,NETCA_PKI_ALGORITHM_AES_CTR,
		key,keyLen,&param);
	NetcaPKICryptoFreeMemory(key);
	
	
	if(hCipher==0)
	{
		printf("NetcaPKICryptoGetCipherHandle fail\n");
		return -1;
	}

	fIn=fopen(argv[4],"rb");
	if(fIn==0)
	{
		NetcaPKICryptoFreeCipher(hCipher);
		printf("open %s fail\n",argv[4]);
		return -1;
	}

	fOut=fopen(argv[5],"wb");
	if(fOut==0)
	{
		NetcaPKICryptoFreeCipher(hCipher);
		fclose(fIn);
		printf("open %s fail\n",argv[5]);
		return -1;
	}


	for(;;)
	{
		len=(int)fread(buf,1,sizeof(buf),fIn);
		if(ferror(fIn)!=0)
		{
			fclose(fIn);
			fclose(fOut);
			NetcaPKICryptoFreeCipher(hCipher);
			printf("fread fail\n");
			return -1;
		}

		if(len>0)
		{
			rv=NetcaPKICryptoCipherUpdate(hCipher,buf,len,&out,&outLen);
			if(rv!=NETCA_PKI_SUCCESS)
			{
				fclose(fIn);
				fclose(fOut);
				NetcaPKICryptoFreeCipher(hCipher);
				if(enc)
				{
					printf("NetcaPKICryptoCipherUpdate encrypt fail\n");
				}
				else
				{
					printf("NetcaPKICryptoCipherUpdate decrypt fail\n");
				}
				return -1;
			}

			if(outLen>0)
			{
				if((int)fwrite(out,1,outLen,fOut)!=outLen)
				{
					fclose(fIn);
					fclose(fOut);
					NetcaPKICryptoFreeCipher(hCipher);
					NetcaPKICryptoFreeMemory(out);
					printf("fwrite fail\n");
					return -1;
				}

			}
			NetcaPKICryptoFreeMemory(out);
		}
		

		if(feof(fIn))
		{
			break;
		}
	}
	fclose(fIn);

	rv=NetcaPKICryptoCipherFinal(hCipher,&out,&outLen);
	NetcaPKICryptoFreeCipher(hCipher);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		fclose(fOut);
		if(enc)
		{
			printf("NetcaPKICryptoCipherFinal encrypt fail\n");
		}
		else
		{
			printf("NetcaPKICryptoCipherFinal decrypt fail\n");
		}
		return -1;
	}

	if(outLen>0)
	{
		if((int)fwrite(out,1,outLen,fOut)!=outLen)
		{
			fclose(fOut);
			NetcaPKICryptoFreeMemory(out);
			printf("fwrite fail\n");
			return -1;
		}

	}
	NetcaPKICryptoFreeMemory(out);
	fclose(fOut);

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

