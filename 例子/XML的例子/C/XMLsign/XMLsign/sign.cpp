
#include <windows.h>
#include<iostream>
#include <string.h>
#include "NETCA_XML.h"
#include "NETCA_JSON.h"
#include "NETCA_PKI_Crypto.h"
#include "NETCA_Alloc.h"
#include "NETCA_Cert.h"
using namespace std;

static NETCA_XML_NodePtr createSignature(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent);
static NETCA_PKI_CERTIFICATE_HANDLE getcert(const char *filename);

int main()
{
	const char *str;
	NETCA_JSON json;
	int rv;
	NETCA_XML_NodePtr signNode;
	NETCA_PKI_CERTIFICATE_HANDLE signCert;
	int reason;	
	NETCA_XML_NodePtr parent;
	NETCA_XML_DocPtr doc;
	NETCA_PKI_KEYPAIR_HANDLE hKeyPair;

	rv=netca_xml_init();

	doc=netca_xml_parsefile("..//..//example.xml");
	if(doc==NULL)
	{
		printf("xml parse fail.\n");
		netca_xml_end();
		return -1;
	}
	parent=netca_xml_doc_getrootelement(doc);
//在要签名的xml文档里添加Signature节点
	signNode =createSignature(doc,parent);
	if(signNode==0)
	{		
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	}	
	str="{"
			"\"C14NAlgo\":\"C14N\","
			"\"SignAlgo\":\"Sha1WithRSA\","
			"\"References\":"
				"["
					"{"
						"\"HashAlgo\":\"Sha1\","
						"\"URI\":\"\","
						"\"Transforms\":"
							"["
								"{"
									"\"TransformAlgo\":\"EnvelopedSignature\""									
								"}"
							"]"
					"}"
					
				"],"
			"\"IncludeCertOption\":\"None\""			
	"}";
	json=netca_json_decode((const unsigned char *)str,(int)strlen(str));	
	if(json==0)
	{
		printf("bad json string\n");
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;
	}
	signCert=getcert("..//..//test.cer");
	if(signCert==NULL)
	{
		printf("get cert fail\n");
		netca_json_free(json);
		netca_xml_doc_free(doc);
		netca_xml_end();
		return -1;		
	}
	//检测是否存在证书相关的私钥
	char* pwd="12345678";//证书密码，也可以设置为空，在签名时会弹出密码对话框
	hKeyPair=NetcaPKICertGetCertKeyPair(signCert,NETCA_PKI_SEARCH_KEYPAIR_FLAG_CURRENT_USER,
		NETCA_PKI_CERT_PURPOSE_SIGN,pwd);
	if(hKeyPair==0)
	{
		NetcaPKICertFreeCert(signCert);
		netca_xml_doc_free(doc);
		netca_json_free(json);
		printf("no keypair\n");
		netca_xml_end();
		return -1;
	}
	NetcaPKICryptoFreeKeypair(hKeyPair);
	
	rv=netca_xml_signature_sign_ex(signNode,signCert,json,&reason);	
	netca_json_free(json);
	if(rv!=NETCA_OK)
	{
		printf("xml sign fail,reason=%d\n",reason);
		netca_xml_end();
		return -1;
	}
	printf("xml sign ok\n");
	NetcaPKICertFreeCert(signCert);
	rv=netca_xml_doc_save_ex(doc,"GBK","..//..//signatureResult.xml",0);
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

//签名元素
NETCA_XML_NodePtr createSignature(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent)
{
	
	NETCA_XML_NodePtr signaturenode;
	NETCA_XML_NodePtr elemnode;
	NETCA_XML_NodePtr textnode;		
	NETCA_XML_NodePtr returnnode;
	NETCA_XML_NodePtr cur;	
	NETCA_XML_NodePtr ns;
	NETCA_UString indent;
	NETCA_UString signaturename;
	NETCA_UString signatureuri;	
	
	indent=netca_ustring_newutf8((const unsigned char *)"\n    ",5);
	if(indent==0)
	{
		return 0;
	}
	/* 创建一个缩进节点 */
	textnode=netca_xml_node_newtext(doc,indent);
	netca_ustring_free(indent);	
	if(textnode==0)
	{		
		return 0;
	}
	cur=netca_xml_node_addchild(parent,textnode);

	/* 建立Signature元素 */	
	signaturename=netca_ustring_newutf8((const unsigned char *)"Signature",9);
	elemnode=netca_xml_node_newelem(0,signaturename);
	netca_ustring_free(signaturename);
	if(elemnode==0)
	{		
		return 0;
	}
	signaturenode =netca_xml_node_addsibling(cur,elemnode);
	returnnode =signaturenode;
	
	/* 设定名字空间 */
	signatureuri=netca_ustring_newutf8((const unsigned char *)"http://www.w3.org/2000/09/xmldsig#",34);	
	ns=netca_xml_node_newns(elemnode,signatureuri,NULL);
	netca_ustring_free(signatureuri);	
	if(ns==0)
	{		
		return 0;
	}
	netca_xml_node_setns(signaturenode,ns);	
	return returnnode;
}