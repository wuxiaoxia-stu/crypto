
#include <windows.h>
#include<iostream>
#include <string.h>
#include "NETCA_XML.h"
#include "NETCA_JSON.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_ArrayList.h"
#include "NETCA_Alloc.h"
#include "NETCA_Cert.h"
using namespace std;


static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *filename);
int main()
{
	
	int rv;
	int reason;
	NETCA_PKI_CERTIFICATE_HANDLE signCert;
	NETCA_XML_Signature_VerifyCtx ctx=NULL;
	rv=netca_xml_init();
	NETCA_XML_DocPtr doc=netca_xml_parsefile("..//..//signatureResult.xml");
	if(doc==NULL)
	{
		printf("xml parse fail.\n");
		netca_xml_end();
		return -1;
	}
	rv=netca_xml_signature_setid(doc);
	if(rv !=NETCA_OK)
	{		
		printf("xml set id fail\n");
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;	
	}

	NETCA_XML_NodePtr root =  netca_xml_doc_getrootelement(doc);
    NETCA_ArrayList signlist =netca_arraylist_new(NULL,(netca_arraylist_freeitem_func)netca_xml_node_free);
	rv =netca_xml_node_findsignature(root,&signlist);
	if(rv !=NETCA_OK)
	{
		printf("xml get signaturelist fail\n");
		netca_arraylist_free(signlist);
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	
	}
	int count =netca_arraylist_count(signlist);
	if (count==0)
	{
		printf("no signaturenode.\n");
		netca_arraylist_free(signlist);
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;	
	}	
	NETCA_XML_NodePtr signNode =(NETCA_XML_NodePtr)netca_arraylist_getitemref(signlist,0);
	netca_arraylist_free(signlist);
	if(rv!=NETCA_OK)
	{
		printf("xml get signnode fail\n");
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	}

	ctx=netca_xml_decode_signature(signNode);
	if(ctx==0)
	{
		printf("xml decode_signature fail\n");
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	}

	signCert=getcert("..//..//test.cer");
	if(signCert==NULL)
	{
		printf("get cert fail\n");
		netca_xml_free_signature(ctx);
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;		
	}
	rv =netca_xml_signature_addcert(ctx,signCert);
	if(rv!=NETCA_OK)
	{
		printf("xml add cert fail\n");
		netca_xml_free_signature(ctx);
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	}
	NetcaPKICertFreeCert(signCert);	
	NETCA_XML_Signature_Key verifykey;
	rv=netca_xml_signature_signaturevalidation(ctx,&verifykey,&reason);
	if(rv!=NETCA_OK)
	{
		netca_xml_free_signature(ctx);
		printf("xml signaturevalidation fail,reason=%d\n",reason);
		netca_xml_end();
		netca_xml_doc_free(doc);
		return -1;
	}
	NETCA_PKI_CERTIFICATE_HANDLE certHandle=netca_xml_signature_key_getcert(verifykey);
	netca_xml_signature_key_free(verifykey);
	if(certHandle==0)
	{
		netca_xml_free_signature(ctx);
		printf("netca_xml_signature_key_getcert fail,reason=%d\n");
		netca_xml_end();
		netca_xml_doc_free(doc);
		return -1;
	}

	rv=netca_xml_signature_referencevalidation_ex(ctx,0,0,0,&reason);
	if(rv!=NETCA_OK)
	{
		NetcaPKICertFreeCert(certHandle);
		certHandle=0;
		netca_xml_free_signature(ctx);
		printf("netca_xml_signature_referencevalidation_ex fail,reason=%d\n");
		netca_xml_end();
		netca_xml_doc_free(doc);
		return -1;
	}
	netca_xml_free_signature(ctx);
	printf("xml verify ok\n");
	netca_xml_doc_free(doc);
	netca_xml_end();

	return 0;
}



#define MAX_BUFFER_LENGTH (32*1024)
NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *filename)
{
	unsigned char buf[MAX_BUFFER_LENGTH];
	int buflen;
	FILE *fp;
	
	fp=fopen(filename,"rb");
	if(fp==NULL){
		return NULL;
	}
	buflen=(int)fread(buf,1,MAX_BUFFER_LENGTH,fp);
	fclose(fp);

	if(buflen==MAX_BUFFER_LENGTH){
		return NULL;
	}
	
	return NetcaPKICertNewCert(buf,buflen);
}