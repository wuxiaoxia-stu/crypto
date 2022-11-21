#include <stdio.h>
#include <string.h>
#include "NETCA_PKI_Crypto.h"
#include "NETCA_PKI_CertReq.h"
#include "NETCA_JSON.h"
#include "NETCA_Alloc.h"

typedef int (NETCADLLAPI* NetcaSignCallback_Ptr)(void *context,int algo,const void *param,const unsigned char *data,int dataLen,unsigned char **signature,int *signatureLen);
int NETCADLLAPI NetcaPKICertSignCert(NETCA_PKI_CERTIFICATE_HANDLE issuerCert,const char *templateInfo,const char *dataInfo,void *context,NetcaSignCallback_Ptr signCallback,NETCA_PKI_CERTIFICATE_HANDLE *pCert);

static int ReadWholeFile(const char *fileName,unsigned char **data,int *dataLen);
static NETCA_JSON ReadJsonFile(const char *fileName);
static NETCA_PKI_CERTIFICATE_HANDLE ReadCertFile(const char *fileName);
static int SignCert(NETCA_JSON templateJson,NETCA_JSON dataJson);
static int SelfSignCert(NETCA_JSON templateJson,NETCA_JSON dataJson);
static NETCA_PKI_KEYPAIR_HANDLE GetKeypair(NETCA_JSON dataJson);
static int AddSubjectPublicKeyInfoFromPublicKey(NETCA_JSON dataJson,NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);
static int AddSubjectPublicKeyInfoFromKeypair(NETCA_JSON dataJson,NETCA_PKI_KEYPAIR_HANDLE hKeypair);
static int NETCADLLAPI SignCallback(void *context,int algo,const void *param,const unsigned char *data,int dataLen,unsigned char **signature,int *signatureLen);
static int SaveFile(const char *fileName,const unsigned char *data,int dataLen);
static int SaveCertFile(const char *fileName,NETCA_PKI_CERTIFICATE_HANDLE cert);
static int SaveCert(NETCA_JSON dataJson,NETCA_PKI_CERTIFICATE_HANDLE cert);
static NETCA_PKI_CERTIFICATE_HANDLE ReadIssuerCert(NETCA_JSON dataJson);
static NETCA_PKI_CERTREQ_HANDLE GetCertReq(NETCA_JSON dataJson);
static int AddSubjectPublicKeyInfoFromCertReq(NETCA_JSON dataJson,NETCA_PKI_CERTREQ_HANDLE p10);
static int AddSubjectFromCertReq(NETCA_JSON dataJson,NETCA_PKI_CERTREQ_HANDLE p10);
static int IsUseCertReqSubject(NETCA_JSON dataJson);
static int IsSelfIssue(NETCA_JSON json);

int main(int argc, char**argv)
{
	int rv;
	const char *templateJsonFileName;
	const char *dataJsonFileName;

	NETCA_JSON templateJson;
	NETCA_JSON dataJson;

	if(argc!=3)
	{
		printf("Usage:%s templateFileName dataFileName\n",argv[0]);
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

	dataJsonFileName=argv[2];
	dataJson=ReadJsonFile(dataJsonFileName);
	if(dataJson==0)
	{
		netca_json_free(templateJson);
		printf("Bad dataFile(%s),not json\n",dataJsonFileName);
		return -1;
	}
	if(netca_json_gettype(dataJson)!=NETCA_JSON_TYPE_OBJECT)
	{
		netca_json_free(templateJson);
		netca_json_free(dataJson);
		printf("Bad dataFile(%s),not json\n",dataJsonFileName);
		return -1;
	}
	if(IsSelfIssue(templateJson)==0)
	{
		rv=SignCert(templateJson,dataJson);
		netca_json_free(templateJson);
		netca_json_free(dataJson);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("Sign Cert Fail\n");
			return -1;
		}
		printf("Sign Cert Success\n");
	}
	else
	{
		rv=SelfSignCert(templateJson,dataJson);
		netca_json_free(templateJson);
		netca_json_free(dataJson);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			printf("Self Sign Cert Fail\n");
			return -1;
		}
		printf("Self Sign Cert Success\n");
	}
	
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

int IsSelfIssue(NETCA_JSON json)
{
	NETCA_JSON item;
	item=netca_json_getobjectvalue(json,(const unsigned char *)"selfsign",8);
	if(item==0)
	{
		return 0;
	}
	if(netca_json_gettype(item)!=NETCA_JSON_TYPE_BOOLEAN)
	{
		return 0;
	}
	return netca_json_istrue(item);
}

int SelfSignCert(NETCA_JSON templateJson,NETCA_JSON dataJson)
{
	NETCA_PKI_KEYPAIR_HANDLE hKeypair;
	int rv;
	unsigned char *templateJsonData;
	int templateJsonDataLen;
	unsigned char *dataJsonData;
	int dataJsonDataLen;
	int flag=NETCA_JSON_ENCODE_FLAG_NORMAL;
	NETCA_PKI_CERTIFICATE_HANDLE cert;

	hKeypair=GetKeypair(dataJson);
	if(hKeypair==0)
	{
		printf("get keypair fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=AddSubjectPublicKeyInfoFromKeypair(dataJson,hKeypair);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("add subject publickey info fail\n");
		return rv;
	}
	rv=netca_json_encode(templateJson,flag,&templateJsonData,&templateJsonDataLen);
	if(rv!=NETCA_OK)
	{
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("encode template json fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=netca_json_encode(dataJson,flag,&dataJsonData,&dataJsonDataLen);
	if(rv!=NETCA_OK)
	{
		NETCA_FREE(templateJsonData);
		NetcaPKICryptoFreeKeypair(hKeypair);
		printf("encode template json fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICertSignCert(0,(const char *)templateJsonData,(const char *)dataJsonData,
		hKeypair,SignCallback,&cert);
	NetcaPKICryptoFreeKeypair(hKeypair);
	NETCA_FREE(templateJsonData);
	NETCA_FREE(dataJsonData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("sign fail\n");
		return rv;
	}
	rv=SaveCert(dataJson,cert);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("save cert fail\n");
		return rv;
	}
	return rv;
}

NETCA_PKI_KEYPAIR_HANDLE GetKeypair(NETCA_JSON dataJson)
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

	keypairItem=netca_json_getobjectvalue(dataJson,(const unsigned char *)"_keypair",8);
	
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

int AddSubjectPublicKeyInfoFromPublicKey(NETCA_JSON dataJson,NETCA_PKI_PUBLICKEY_HANDLE hPublicKey)
{
	int rv;
	unsigned char *spkiEncode;
	int spkiEncodeLen;
	char *hex;
	int hexLen;
	NETCA_JSON item;
	rv=NetcaPKICryptoGetSubjectPublicKeyInfoEncode(hPublicKey,&spkiEncode,&spkiEncodeLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return rv;
	}
	rv=NetcaPKICryptoHexEncode(1,spkiEncode,spkiEncodeLen,&hex,&hexLen);
	NetcaPKICryptoFreeMemory(spkiEncode);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return rv;
	}

	item=netca_json_newstring((const unsigned char *)hex,hexLen);
	NetcaPKICryptoFreeMemory(hex);
	if(item==0)
	{
		return NETCA_PKI_FAIL;
	}
	rv=netca_json_updateobjectitem(dataJson,(const unsigned char *)"subjectPublicKeyInfo",20,item);
	netca_json_free(item);
	if(rv!=NETCA_OK)
	{
		return NETCA_PKI_FAIL;
	}
	return NETCA_PKI_SUCCESS;
}

int AddSubjectPublicKeyInfoFromKeypair(NETCA_JSON dataJson,NETCA_PKI_KEYPAIR_HANDLE hKeypair)
{
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
	int rv;
	hPublicKey=NetcaPKICryptoGetPublicKeyFromKeypair(hKeypair);
	rv=AddSubjectPublicKeyInfoFromPublicKey(dataJson,hPublicKey);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	return rv;
}


int NETCADLLAPI SignCallback(void *context,int algo,const void *param,const unsigned char *data,int dataLen,unsigned char **signature,int *signatureLen)
{
	NETCA_PKI_KEYPAIR_HANDLE hKeypair=(NETCA_PKI_KEYPAIR_HANDLE)context;
	int rv;
	NETCA_PKI_SIGN_HANDLE hSign;
	
	hSign=NetcaPKICryptoNewSign(hKeypair,algo,param);
	if(hSign==0)
	{
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICryptoSignUpdate(hSign,data,dataLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICryptoFreeSign(hSign);
		return rv;
	}

	rv=NetcaPKICryptoSignFinal(hSign,signature,signatureLen);
	NetcaPKICryptoFreeSign(hSign);
	return rv;
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

int SaveCertFile(const char *fileName,NETCA_PKI_CERTIFICATE_HANDLE cert)
{
	int rv;
	unsigned char *data;
	int dataLen;

	rv=NetcaPKICertGetCertEncode(cert,NETCA_PKI_CERT_ENCODE_DER,&data,&dataLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return rv;
	}
	rv=SaveFile(fileName,data,dataLen);
	NetcaPKICryptoFreeMemory(data);
	return rv;
}

int SaveCert(NETCA_JSON dataJson,NETCA_PKI_CERTIFICATE_HANDLE cert)
{
	NETCA_JSON item;
	const char *fileName;

	item=netca_json_getobjectvalue(dataJson,(const unsigned char *)"_certFileName",13);
	fileName=netca_json_getstring(item);
	if(fileName==0)
	{
		return NETCA_PKI_FAIL;
	}
	return SaveCertFile(fileName,cert);
}

int SignCert(NETCA_JSON templateJson,NETCA_JSON dataJson)
{
	NETCA_PKI_CERTIFICATE_HANDLE issuerCert;
	NETCA_PKI_KEYPAIR_HANDLE hKeypair;
	int rv;
	unsigned char *templateJsonData;
	int templateJsonDataLen;
	unsigned char *dataJsonData;
	int dataJsonDataLen;
	int flag=NETCA_JSON_ENCODE_FLAG_NORMAL;
	NETCA_PKI_CERTIFICATE_HANDLE cert;
	NETCA_PKI_CERTREQ_HANDLE p10;

	issuerCert=ReadIssuerCert(dataJson);
	if(issuerCert==0)
	{
		printf("read issuer cert fail\n");
		return NETCA_PKI_FAIL;
	}

	hKeypair=GetKeypair(dataJson);
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

	p10=GetCertReq(dataJson);
	if(p10==0)
	{
		NetcaPKICertFreeCert(issuerCert);
		printf("get p10 fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICertReqVerify(p10);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(p10);
		NetcaPKICertFreeCert(issuerCert);
		printf("verify p10 fail\n");
		return rv;
	}

	rv=AddSubjectPublicKeyInfoFromCertReq(dataJson,p10);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		NetcaPKICertReqFree(p10);
		NetcaPKICertFreeCert(issuerCert);
		printf("add subject publickey info fail\n");
		return rv;
	}

	if(IsUseCertReqSubject(dataJson))
	{
		rv=AddSubjectFromCertReq(dataJson,p10);
		if(rv!=NETCA_PKI_SUCCESS)
		{
			NetcaPKICertReqFree(p10);
			NetcaPKICertFreeCert(issuerCert);
			printf("add subject fail\n");
			return rv;
		}
	}

	NetcaPKICertReqFree(p10);
	rv=netca_json_encode(templateJson,flag,&templateJsonData,&templateJsonDataLen);
	if(rv!=NETCA_OK)
	{
		NetcaPKICertFreeCert(issuerCert);
		printf("encode template json fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=netca_json_encode(dataJson,flag,&dataJsonData,&dataJsonDataLen);
	if(rv!=NETCA_OK)
	{
		NETCA_FREE(templateJsonData);
		NetcaPKICertFreeCert(issuerCert);
		printf("encode template json fail\n");
		return NETCA_PKI_FAIL;
	}

	rv=NetcaPKICertSignCert(issuerCert,(const char *)templateJsonData,(const char *)dataJsonData,
		0,0,&cert);
	NetcaPKICertFreeCert(issuerCert);
	NETCA_FREE(templateJsonData);
	NETCA_FREE(dataJsonData);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("sign fail\n");
		return rv;
	}
	rv=SaveCert(dataJson,cert);
	NetcaPKICertFreeCert(cert);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		printf("save cert fail\n");
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

NETCA_PKI_CERTIFICATE_HANDLE ReadIssuerCert(NETCA_JSON dataJson)
{
	NETCA_JSON item;
	const char *fileName;

	item=netca_json_getobjectvalue(dataJson,(const unsigned char *)"_issuerCertFileName",19);
	fileName=netca_json_getstring(item);
	if(fileName==0)
	{
		return 0;
	}
	return ReadCertFile(fileName);
}

NETCA_PKI_CERTREQ_HANDLE GetCertReq(NETCA_JSON dataJson)
{
	NETCA_JSON item;
	const char *fileName;
	int rv;
	unsigned char *data;
	int dataLen;
	NETCA_PKI_CERTREQ_HANDLE p10;

	item=netca_json_getobjectvalue(dataJson,(const unsigned char *)"_p10FileName",12);
	fileName=netca_json_getstring(item);
	if(fileName==0)
	{
		return 0;
	}
	
	rv=ReadWholeFile(fileName,&data,&dataLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return 0;
	}

	p10=NetcaPKICertReqDecode(data,dataLen);
	NetcaPKICryptoFreeMemory(data);
	return p10;
}

int AddSubjectPublicKeyInfoFromCertReq(NETCA_JSON dataJson,NETCA_PKI_CERTREQ_HANDLE p10)
{
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey;
	int rv;
	hPublicKey=NetcaPKICertReqGetPublicKey(p10);
	rv=AddSubjectPublicKeyInfoFromPublicKey(dataJson,hPublicKey);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	return rv;
}

int IsUseCertReqSubject(NETCA_JSON dataJson)
{
	NETCA_JSON item;
	item=netca_json_getobjectvalue(dataJson,(const unsigned char *)"_useP10Subject",14);
	if(netca_json_gettype(item)!=NETCA_JSON_TYPE_BOOLEAN)
	{
		return 0;
	}
	return netca_json_istrue(dataJson);
}

int AddSubjectFromCertReq(NETCA_JSON dataJson,NETCA_PKI_CERTREQ_HANDLE p10)
{
	int rv;
	unsigned char *subject;
	int subjectLen;
	char *hex;
	int hexLen;
	NETCA_JSON item;

	rv=NetcaPKICertReqGetEncode(p10,&subject,&subjectLen);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return rv;
	}
	
	rv=NetcaPKICryptoHexEncode(1,subject,subjectLen,&hex,&hexLen);
	NetcaPKICryptoFreeMemory(subject);
	if(rv!=NETCA_PKI_SUCCESS)
	{
		return rv;
	}

	item=netca_json_newstring((const unsigned char *)hex,hexLen);
	NetcaPKICryptoFreeMemory(hex);
	if(item==0)
	{
		return NETCA_PKI_FAIL;
	}
	rv=netca_json_updateobjectitem(dataJson,(const unsigned char *)"subject",7,item);
	netca_json_free(item);
	if(rv!=NETCA_OK)
	{
		return NETCA_PKI_FAIL;
	}
	return NETCA_PKI_SUCCESS;
}

