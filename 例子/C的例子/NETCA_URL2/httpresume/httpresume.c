#include <stdio.h>
#include <string.h>
#include "NETCA_Http.h"
#include "NETCA_Alloc.h"
#include "NETCA_UString.h"
#include "NETCA_FileUrl.h"

#ifndef _WIN32
#define _atoi64(value) strtoll(value, NULL, 10)	
#endif


static int GetFileLength(const char* fileName,integer64* length);
static int WriteFileFromHttp(FILE* fp,NETCA_HTTP http,integer64 length);
int main(int argc,char** argv)
{
	const char* url;
	const char* fileName;
	const char* eTag;
	NETCA_HTTP http;
	NETCA_URI uri;
	integer64 offset;
	integer64 totalLength;
	int rv;
	int status;
	integer64 length;
	FILE* fp;

	if(argc!=5)
	{
		printf("Usage:%s url fileName totalLength eTag\n",argv[0]);
		return -1;
	}

	url=argv[1];
	fileName=argv[2];
	totalLength=_atoi64(argv[3]);
	eTag=argv[4];
	if(eTag[0]=='\0')
	{
		eTag=NULL;
	}

	rv=GetFileLength(fileName,&offset);
	if(rv!=NETCA_OK)
	{
		printf("GetFileLength fail\n");
		return -1;
	}

	uri=netca_uri_new(url);
	if(uri==NULL)
	{
		printf("bad url\n");
		return -1;
	}
	
	http=netca_http_newfromurl(uri);
	netca_uri_free(uri);
	if(http==NULL)
	{
		printf("netca_http_newfromurl fail\n");
		return -1;
	}
	
	rv=netca_http_addresumeheader(http,eTag,NULL,offset,totalLength-1);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("netca_http_addresumeheader fail,return %d\n",rv);
		return -1;
	}

	rv=netca_http_connect(http,0);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("netca_http_connect fail,return %d\n",rv);
		return -1;
	}
	
	rv=netca_http_requestdata_init(http);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("netca_http_requestdata_init fail,return %d\n",rv);
		return -1;
	}

	rv=netca_http_requestdata_finish(http);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("netca_http_requestdata_init fail,return %d\n",rv);
		return -1;
	}
	
	rv=netca_http_getresponsestatus(http,&status);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("netca_http_getresponsestatus fail,return %d\n",rv);
		return -1;
	}

	printf("Http Status:%d\n",status);
	if(status!=206)
	{
		netca_http_free(http);
		printf("bad http status\n");
		return -1;
	}
	
	rv=netca_http_getresponselength_ex(http,&length);
	if(rv!=NETCA_OK)
	{
		netca_http_free(http);
		printf("get Content-Length fail\n");
		return -1;
	}

	fp=fopen(fileName,"ab");
	if(fp==NULL)
	{
		netca_http_free(http);
		printf("open file fail\n");
		return -1;
	}
	rv=WriteFileFromHttp(fp,http,length);
	fclose(fp);
	fclose(fp);
	netca_http_disconnect(http);
	netca_http_free(http);
	if(rv!=NETCA_OK)
	{
		printf("WriteFileFromHttp fail\n");
		return -1;
	}

	printf("Success\n");
	return 0;
}

int GetFileLength(const char* fileName,integer64* length)
{
	char* charset;
	NETCA_UString ustr;
	NETCA_FileURL file;
	int rv;

	charset=netca_ustring_getdefaultcharset();
	if(charset==NULL)
	{
		return NETCA_FAIL;
	}
	ustr=netca_ustring_newmbs(charset,(const unsigned char *)fileName,(long)strlen(fileName));
	NETCA_FREE(charset);
	if(ustr==NULL)
	{
		return NETCA_FAIL;
	}
	file=netca_fileurl_new(ustr);
	netca_ustring_free(ustr);
	if(file==NULL)
	{
		return NETCA_FAIL;
	}
	rv=netca_fileurl_getlength(file,length);
	netca_fileurl_free(file);
	if(rv!=NETCA_OK)
	{
		return rv;
	}

	return NETCA_OK;
}

int WriteFileFromHttp(FILE* fp,NETCA_HTTP http,integer64 length)
{
	char buf[8192];
	int readLen;
	integer64 pos;
	int rv;

	if(length==0)
	{
		return NETCA_OK;
	}

	pos=0;
	while(pos<length)
	{
		rv=netca_http_getresponse(http,buf,sizeof(buf),&readLen);
		if(rv!=NETCA_OK)
		{
			return rv;
		}
		if(readLen==0)
		{
			return NETCA_FAIL;
		}
		if((int)fwrite(buf,1,readLen,fp)!=readLen)
		{
			return NETCA_FAIL;
		}
		pos+=readLen;
	}
	if(pos!=length)
	{
		return NETCA_FAIL;
	}

	return NETCA_OK;
}
