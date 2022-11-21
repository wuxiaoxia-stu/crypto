#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_JSON.h"
#include "NETCA_Alloc.h"

typedef int (NETCADLLAPI* NetcaSignCallback_Ptr)(void *context,int algo,const void *param,const unsigned char *data,int dataLen,unsigned char **signature,int *signatureLen);
int NETCADLLAPI NetcaPKICertSignCRL(NETCA_PKI_CERTIFICATE_HANDLE issuerCert,const char *templateInfo,void *context,NetcaSignCallback_Ptr signCallback,unsigned char** pCrl,int *pCrlLen);


static int ReadWholeFile(const char *fileName,unsigned char **data,int *dataLen);
static NETCA_JSON ReadJsonFile(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE ReadCertFile(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE ReadIssuerCert(NETCA_JSON json);
static NETCA_PKI_KEYPAIR_HANDLE GetKeypair(NETCA_JSON json);
static int SignCRL(NETCA_JSON templateJson);
static int SaveFile(const char *fileName,const unsigned char *data,int dataLen);
static int SaveCRL(NETCA_JSON json,const unsigned char *crl,int crlLen);

int main(int argc, char**argv)
{
	int rv;
	const char *templateJsonFileName;
	
	NETCA_JSON templateJson;
	
	if(argc!=2)
	{
		printf("Usage:%s templateFileName\n",argv[0]);
		return -1;
	}
	templateJsonFileName=argv[1];
	templateJson=ReadJsonFile(templateJsonFileName);
	if(templateJson==0)
	{
		printf("Bad templateFile(%s),not json\n",templateJsonFileName);
		return -1;
	}
	if(netca_json_gettype(templateJson)!=NETCA_JSON_TYPE_OBJECT)
	{
		netca_json_free(templateJson);
		printf("Bad templateFile(%s),not json\n",templateJsonFileName);
		return -1;
	}

	rv=SignCRL(templateJson);
	netca_json_free(templateJson);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("Sign CRL Fail\n");
		return -1;
	}
	printf("Sign CRL Success\n");
	return 0;
}

int ReadWholeFile(const char *fileName,unsigned char **data,int *dataLen)
{
	FILE *fp;
	int len;
	unsigned char *buf;

	fp=fopen(fileName,"rb");
	if(fp==0)
	{
		return NETCA_PKI_FAIL;
	}
	fseek(fp,0L,SEEK_END);
	len=(int)ftell(fp);
	if(len<=0)
	{
		fclose(fp);
		return NETCA_PKI_FAIL;
	}
	fseek(fp,0L,SEEK_SET);
	
	buf=(unsigned char *)NetcaPKICryptoAllocMemory(len);
	if(buf==0)
	{
		fclose(fp);
		return NETCA_PKI_FAIL;
	}
	if(len!=fread(buf,1,len,fp))
	{
		NetcaPKICryptoFreeMemory(buf);
		fclose(fp);
		return NETCA_PKI_FAIL;
	}
	fclose(fp);

	*data=buf;
	*dataLen=len;
	return NETCA_PKI_SUCCESS;
}

NETCA_JSON ReadJsonFile(const char *fileName)
{
	int rv;
	unsigned char *data;
	int dataLen;
	NETCA_JSON json;

	rv=ReadWholeFile(fileName,&data,&dataLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}

	if(dataLen>=3 && data[0]==(unsigned char)'\xEF' && data[1]==(unsigned char)'\xBB' && data[2]==(unsigned char)'\xBF')
	{
		memmove(data,&data[3],dataLen-3);
		dataLen-=3;
	}

	json=netca_json_decode(data,dataLen);
	NetcaPKICryptoFreeMemory(data);
	return json;
}


int SignCRL(NETCA_JSON templateJson)
{
	NETCA_PKI_CERTIFICATE_HANDLE issuerCert;
	NETCA_PKI_KEYPAIR_HANDLE hKeypair;
	int rv;
	unsigned char *templateJsonData;
	int templateJsonDataLen;
	int flag=NETCA_JSON_ENCODE_FLAG_NORMAL;
	unsigned char *crl;
	int crlLen;

	issuerCert=ReadIssuerCert(templateJson);
	if(issuerCert==0)
	{
		printf("read issuer cert fail\n");
		return NETCA_PKI_FAIL;
	}

	hKeypair=GetKeypair(templateJson);
	if(hKeypair==0)
	{
		NetcaPKICertFreeCert(issuerCert);
		printf("get keypair fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICertSetCertKeyPair(issuerCert,hKeypair);
	NetcaPKICryptoFreeKeypair(hKeypair);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertFreeCert(issuerCert);
		printf("set keypair fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=netca_json_encode(templateJson,flag,&templateJsonData,&templateJsonDataLen);
	if(rv!=NETCA_OK)
	{
		NetcaPKICertFreeCert(issuerCert);
		printf("encode template json fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICertSignCRL(issuerCert,(const char *)templateJsonData,
		0,0,&crl,&crlLen);
	NetcaPKICertFreeCert(issuerCert);
	NETCA_FREE(templateJsonData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("sign fail\n");
		return rv;
	}
	rv=SaveCRL(templateJson,crl,crlLen);
	NetcaPKICryptoFreeMemory(crl);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("save crl fail fail\n");
		return rv;
	}
	return rv;
}



NETCA_PKI_CERTIFICATE_HANDLE ReadCertFile(const char *fileName)
{
	int rv;
	unsigned char *data;
	int dataLen;
	NETCA_PKI_CERTIFICATE_HANDLE cert;

	rv=ReadWholeFile(fileName,&data,&dataLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}

	cert=NetcaPKICertNewCert(data,dataLen);
	NetcaPKICryptoFreeMemory(data);
	return cert;
}

NETCA_PKI_CERTIFICATE_HANDLE ReadIssuerCert(NETCA_JSON json)
{
	NETCA_JSON item;
	const char *fileName;

	item=netca_json_getobjectvalue(json,(const unsigned char *)"_issuerCertFileName",19);
	fileName=netca_json_getstring(item);
	if(fileName==0)
	{
		return 0;
	}
	return ReadCertFile(fileName);
}

NETCA_PKI_KEYPAIR_HANDLE GetKeypair(NETCA_JSON json)
{
	int deviceType;
	const char *deviceSn;
	const char *pwd;
	NETCA_JSON item;
	NETCA_JSON keypairItem;
	int keypairType;
	const char *label;
	int flag=NETCA_PKI_DEVICE_FLAG_SILENT;
	NETCA_PKI_KEYPAIR_HANDLE hKeypair;
	int rv;

	keypairItem=netca_json_getobjectvalue(json,(const unsigned char *)"_keypair",8);
	
	item=netca_json_getobjectvalue(keypairItem,(const unsigned char *)"deviceType",10);
	if(netca_json_gettype(item)!=NETCA_JSON_TYPE_NUMBER)
	{
		return 0;
	}
	deviceType=(int)netca_json_getnumber(item);

	item=netca_json_getobjectvalue(keypairItem,(const unsigned char *)"deviceSn",8);
	deviceSn=netca_json_getstring(item);
	if(deviceSn==0)
	{
		return 0;
	}

	item=netca_json_getobjectvalue(keypairItem,(const unsigned char *)"pwd",3);
	pwd=netca_json_getstring(item);
	if(pwd==0)
	{
		return 0;
	}

	item=netca_json_getobjectvalue(keypairItem,(const unsigned char *)"keypairType",11);
	if(netca_json_gettype(item)!=NETCA_JSON_TYPE_NUMBER)
	{
		return 0;
	}
	keypairType=(int)netca_json_getnumber(item);

	item=netca_json_getobjectvalue(keypairItem,(const unsigned char *)"keypairLabel",12);
	label=netca_json_getstring(item);
	if(label==0)
	{
		return 0;
	}

	rv=NetcaPKICryptoFindKeypairEx(deviceType,deviceSn,flag,
		pwd,keypairType,label,&hKeypair);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}
	return hKeypair;
}

int SaveFile(const char *fileName,const unsigned char *data,int dataLen)
{
	FILE *fp;

	fp=fopen(fileName,"wb");
	if(fp==0)
	{
		return NETCA_PKI_FAIL;
	}
	if(fwrite(data,1,dataLen,fp)!=dataLen)
	{
		fclose(fp);
		return NETCA_PKI_FAIL;
	}
	fclose(fp);
	return NETCA_PKI_SUCCESS;
}

int SaveCRL(NETCA_JSON json,const unsigned char *crl,int crlLen)
{
	NETCA_JSON item;
	const char *fileName;

	item=netca_json_getobjectvalue(json,(const unsigned char *)"_crlFileName",12);
	fileName=netca_json_getstring(item);
	if(fileName==0)
	{
		return NETCA_PKI_FAIL;
	}
	return SaveFile(fileName,crl,crlLen);
}
