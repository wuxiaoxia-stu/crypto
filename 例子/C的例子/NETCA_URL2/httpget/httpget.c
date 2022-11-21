#include <stdio.h>
#include "NETCA_Http.h"
#include "NETCA_Alloc.h"

#ifndef _WIN32
#define _atoi64(value) strtoll(value, NULL, 10)	
#endif

static int WriteFileFromHttp(FILE* fp,NETCA_HTTP http,integer64 length);
static int WriteFileFromHttpNoContentLength(FILE* fp,NETCA_HTTP http);

int main(int argc,char** argv)
{
	NETCA_HTTP http;
	NETCA_URI uri;
	const char* url;
	int rv;
	int status;
	char* contentType;
	char* eTag;
	integer64 length=0;
	FILE* fp;
	const char* fileName;
	integer64 partlyLength; 

	if(argc!=3 && argc!=4)
	{
		printf("Usage:%s url fileName [length]\n",argv[0]);
		return -1;
	}

	url=argv[1];
	fileName=argv[2];

	if(argc==4)
	{
		partlyLength=_atoi64(argv[3]);
	}
	else
	{
		partlyLength=-1;
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
	if(status<200 || status>299)
	{
		netca_http_free(http);
		printf("bad http status\n");
		return -1;
	}

	contentType=netca_http_findresponseheadervalue(http,"Content-Type");
	if(contentType==NULL)
	{
		printf("No Content-Type\n");
	}
	else
	{
		printf("Content-Type:%s\n",contentType);
		NETCA_FREE(contentType);
	}

	if(netca_http_canresume(http))
	{
		printf("Can Resume\n");
	}
	eTag=netca_http_findresponseheadervalue(http,"ETag");
	if(eTag==NULL)
	{
		printf("No ETag\n");
	}
	else
	{
		printf("ETag:%s\n",eTag);
		NETCA_FREE(eTag);
	}
	
	rv=netca_http_getresponselength_ex(http,&length);
	if(rv==NETCA_OK)
	{
#ifdef _WIN32
		printf("Content-Length:%I64d\n",length);
#else
		printf("Content-Length:%lld\n",length);
#endif
		if(partlyLength>=0)
		{
			length=partlyLength;
		}
	}
	else if(rv==NETCA_ERROR_NOTEXISIT)
	{
		printf("No Content-Length\n");
		if(partlyLength<0)
		{
			length=-1;
		}
		else
		{
			length=partlyLength;
		}
	}
	else
	{
		netca_http_free(http);
		printf("netca_http_getresponselength_ex fail,return %d\n",rv);
		return -1;
	}

	fp=fopen(fileName,"wb");
	if(fp==NULL)
	{
		netca_http_free(http);
		printf("open file fail\n");
		return -1;
	}
	rv=WriteFileFromHttp(fp,http,length);
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

	if(length<0)
	{
		return WriteFileFromHttpNoContentLength(fp,http);
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

int WriteFileFromHttpNoContentLength(FILE* fp,NETCA_HTTP http)
{
	char buf[8192];
	int readLen;
	int rv;

	for(;;)
	{
		rv=netca_http_getresponse(http,buf,sizeof(buf),&readLen);
		if(rv!=NETCA_OK)
		{
			return rv;
		}
		if(readLen==0)
		{
			break;
		}
		if((int)fwrite(buf,1,readLen,fp)!=readLen)
		{
			return NETCA_FAIL;
		}
		
	}

	return NETCA_OK;
}
