#ifndef NETCA_XML_INCLUDE_H
#define NETCA_XML_INCLUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_XML_Type.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#define NETCA_XML_VERIFY_SUCCESS		0
#define NETCA_XML_VERIFY_SIGNATURE_FAIL		1
#define NETCA_XML_VERIFY_REF_FAIL		2
#define NETCA_XML_VERIFY_OUTOFMEMORY		3
#define NETCA_XML_VERIFY_URI_UNSUPPORT		4
#define NETCA_XML_VERIFY_URI_DEFER_FAIL		5
#define NETCA_XML_VERIFY_PARAM_ERROR		6
#define NETCA_XML_VERIFY_TRANSFORM_UNSUPPORT	7
#define NETCA_XML_VERIFY_C14N_UNSUPPORT		8
#define NETCA_XML_VERIFY_NOKEY			9
#define NETCA_XML_VERIFY_HMAC_UNSUPPORT		10
#define NETCA_XML_VERIFY_SIGNATURE_UNSUPPORT	11
#define NETCA_XML_VERIFY_HASH_UNSUPPORT		12
#define NETCA_XML_VERIFY_TRANSFORM_FAIL		13
#define NETCA_XML_VERIFY_MORE_URI_ABSENCE	14
#define NETCA_XML_VERIFY_IDCONFLICT		15
#define NETCA_XML_VERIFY_NO_SIGNATURE		16
#define NETCA_XML_VERIFY_SIGNATURE_BAD_FORMAT	17
#define NETCA_XML_VERIFY_BAD_C14N_PARAM		18
#define NETCA_XML_VERIFY_NOT_REF		19
#define NETCA_XML_VERIFY_REF_NOTIN_SIGNATURE	20
#define NETCA_XML_VERIFY_OFFLINE_DEFER_FAIL		21
#define NETCA_XML_VERIFY_BADMANIFEST			22
#define NETCA_XML_VERIFY_MISMATCH_SIGNINGCERT	23
#define NETCA_XML_VERIFY_BAD_XPATH				24


#define NETCA_XML_SIGN_SUCCESS			0
#define NETCA_XML_SIGN_FAIL			1
#define NETCA_XML_SIGN_REF_FAIL			2
#define NETCA_XML_SIGN_OUTOFMEMORY		3
#define NETCA_XML_SIGN_URI_UNSUPPORT		4
#define NETCA_XML_SIGN_URI_DEFER_FAIL		5
#define NETCA_XML_SIGN_PARAM_ERROR		6
#define NETCA_XML_SIGN_TRANSFORM_UNSUPPORT	7
#define NETCA_XML_SIGN_C14N_UNSUPPORT		8
#define NETCA_XML_SIGN_NOKEY			9
#define NETCA_XML_SIGN_HMAC_UNSUPPORT		10
#define NETCA_XML_SIGN_SIGNATURE_UNSUPPORT	11
#define NETCA_XML_SIGN_HASH_UNSUPPORT		12
#define NETCA_XML_SIGN_TRANSFORM_FAIL		13
#define NETCA_XML_SIGN_MORE_URI_ABSENCE		14
#define NETCA_XML_SIGN_IDCONFLICT		15
#define NETCA_XML_SIGN_BADPOS			16
#define NETCA_XML_SIGN_KEYMISMATCH		17
#define NETCA_XML_SIGN_NOTSIGNCERT		18
#define NETCA_XML_SIGN_HASH_FAIL		19
#define NETCA_XML_SIGN_UNEXPECT			20
#define NETCA_XML_SIGN_NOT_SIGNATURE		21
#define NETCA_XML_SIGN_C14N_FAIL			22
#define NETCA_XML_SIGN_GETTIMESTAMP_FAIL	23
#define NETCA_XML_SIGN_BADCERT_NOPRIVKEY	24
#define NETCA_XML_SIGN_BAD_JSON				25
#define NETCA_XML_SIGN_SIGNVALUE_NO_ID		26
#define NETCA_XML_SIGN_NOT_REF				27
#define NETCA_XML_SIGN_OFFLINE_DEFER_FAIL	28
#define NETCA_XML_SIGN_BUILD_CERT_PATH_FAIL	29

#define NETCA_XML_VERISON_1_0			0
#define NETCA_XML_VERISON_1_1			1

#define NETCA_XML_NOXMLDESC			1

/*
 *		netca_xml_init
 *			��ʼ��NETCA_XML�⣬�����ڳ���ʼʱ������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_init(void);

/*
 *		netca_xml_end
 *			�ͷ�NETCA_XML���ȫ�ֵ�������Ϣ��ֻӦ���ڳ��������ʱ��ŵ���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_end(void);

/*
 *		netca_xml_parse
 *			����XML�ĵ�
 *		������
 *			data�����������XML�ı���ֵ
 *			dataLen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ�����XML�ĵ��ĸ�Ԫ�أ�ʧ�ܷ���NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_parse(const unsigned char *data,long dataLen);

/*
 *		netca_xml_parsefile
 *			���ļ��н���XML�ĵ�
 *		������
 *			fileName������������ļ���
 *		����ֵ��
 *			�ɹ�����XML�ĵ��ĸ�Ԫ�أ�ʧ�ܷ���NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_parsefile(const char *fileName);

/*
 *		netca_xml_doc_free
 *			�ͷ�����XML�ĵ����������еĽڵ㶼�ᱻ�ͷ�
 *		������
 *			doc: XML�ĵ��ĸ��ڵ�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_doc_free(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_doc_getrootelement
 *			��ȡXML�ĵ��ĸ�Ԫ�أ���Ҫ�ͷ���
 *		������
 *			doc: XML�ĵ��ĸ��ڵ�
 *		����ֵ��
 *			�ɹ�����XML�ĵ��ĸ�Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_doc_getrootelement(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_node_gettype
 *			��ȡ�ڵ������
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			���ؽڵ����ͣ�nodeΪNULL��δ֪�ڵ㷵��-1
 */
int NETCAAPI netca_xml_node_gettype(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getname
 *			��ȡ�ڵ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ������ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getname(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getprefixedname
 *			��ȡ�ڵ�������ռ�ǰ׺
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ�������ռ�ǰ׺��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getprefixedname(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnsuri
 *			��ȡ�ڵ�������ռ�URI
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ�������ռ�URI��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getnsuri(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getvalue
 *			��ȡ�ڵ��ֵ
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getvalue(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getpcdata
 *			��ȡ�ı��ڵ��PCDATA���������
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ������ı��ڵ��PCDATA��������ݣ�ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getpcdata(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getdoc
 *			��ȡXML���ڵ�
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ�����ڵ�XML���ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_node_getdoc(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getchildren
 *			��ȡԪ�ؽڵ�ĵ�һ����Ԫ�ؽڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ�����Ԫ�ؽڵ�ĵ�һ����Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getchildren(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getparent
 *			��ȡ�ڵ�ĸ��ڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ�ĸ��ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getparent(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnextsibling
 *			��ȡ�ڵ����һ���ֵܽڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ����һ���ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getnextsibling(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getprevsibling
 *			��ȡ�ڵ��ǰһ���ֵܽڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ��ǰһ���ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getprevsibling(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getattributevalue
 *			��ȡԪ�ؽڵ������ֵ
 *		������
 *			node���ڵ�
 *			name������
 *			nsUri:���ֿռ�URI
 *		����ֵ��
 *			�ɹ���������ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getattributevalue(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsUri);

/*
 *		netca_xml_node_findattribute
 *			��ȡԪ�ؽڵ������
 *		������
 *			node���ڵ�
 *			name������
 *			nsUri:���ֿռ�URI
 *		����ֵ��
 *			�ɹ��������ԣ�ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_findattribute(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsUri);

/*
 *		netca_xml_node_getattribute
 *			��ȡԪ�ؽڵ�ĵ�һ�����Խڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ�����Ԫ�ؽڵ�ĵ�һ�����Խڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getattribute(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnsnode
 *			��ȡԪ�ؽڵ㶨��������ռ�ڵ㣬��Ҫ�ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ�����Ԫ�ؽڵ㶨��ĵ�һ�������ռ�ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getnsnode(NETCA_XML_NodePtr node);


/*
 *		netca_xml_node_getassociatednsnode
 *			��ȡ�ڵ�����������ռ�ڵ�
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ����ؽڵ�����������ռ�ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getassociatednsnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_newtext
 *			�������ı��ڵ�
 *		������
 *			doc�����ڵ�
 *			text������������ı�ֵ
 *		����ֵ��
 *			�ɹ����ش������ı��ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newtext(NETCA_XML_DocPtr doc,NETCA_UString  text);

/*
 *		netca_xml_node_newns
 *			�����������ռ�ڵ�
 *		������
 *			node��Ԫ�ؽڵ�
 *			href����������������ռ�URI
 *			prefix: ��������������ռ�ǰ׺������ΪNULL
 *		����ֵ��
 *			�ɹ����ش����������ռ�ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newns(NETCA_XML_NodePtr node,NETCA_UString href,NETCA_UString prefix);

/*
 *		netca_xml_node_setvalue
 *			���ýڵ�node��ֵΪdata
 *		������
 *			node���ڵ�
 *			data�������������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setvalue(NETCA_XML_NodePtr node,NETCA_UString  data);

/*
 *		netca_xml_node_setns
 *			���ýڵ�node����ص������ռ�ڵ�Ϊns
 *		������
 *			node���ڵ�
 *			ns�������ռ�ڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setns(NETCA_XML_NodePtr node,NETCA_XML_NodePtr ns);

/*
 *		netca_xml_doc_new
 *			����һ���յ�XML�ĵ��ĸ��ڵ㣬������ڵ���Ϊû�а�����Ԫ�ؽڵ�������ǲ��Ϸ���XML�ĵ���
 *		������
 *			version: ���������NETCA_XML_VERISON_1_0 ��ʾ1.0�汾��NETCA_XML_VERISON_1_1 ��ʾ1.1�汾��
 *		����ֵ��
 *			�ɹ����ؿյ�XML�ĵ��ĸ��ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_DocPtr  NETCAAPI netca_xml_doc_new(int version);

/*
 *		netca_xml_node_newattr
 *			�������Խڵ�
 *		������
 *			node��Ԫ�ؽڵ�
 *			ns�������ռ�ڵ㣬�������û�������ռ���ΪNULL
 *			name�����������������
 *			value���������������ֵ
 *		����ֵ��
 *			�ɹ����ش��������Խڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newattr(NETCA_XML_NodePtr node,NETCA_XML_NodePtr ns,NETCA_UString name,NETCA_UString value);

/*
 *		netca_xml_node_newpi
 *			��������ָ��ڵ�
 *		������
 *			doc�����ڵ�
 *			name���������������ָ����
 *			content: �������������ָ������
 *		����ֵ��
 *			�ɹ����ش����Ĵ���ָ��ڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newpi(NETCA_XML_DocPtr doc,NETCA_UString name,NETCA_UString content);


/*
 *		netca_xml_node_newcomment
 *			����ע�ͽڵ�
 *		������
 *			doc��XML�ĵ��ĸ��ڵ�
 *			content�����������ע�͵�����
 *		����ֵ��
 *			�ɹ����ش�����ע�ͽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newcomment(NETCA_XML_DocPtr doc,NETCA_UString content);

/*
 *		netca_xml_node_remove
 *			�ѽڵ㼰���ӽڵ������ժ����������û���ͷ���
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_node_remove(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_free
 *			�ͷŽڵ�node��������
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_node_free(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_newelem
 *			�����յ�Ԫ�ؽڵ�
 *		������
 *			ns�������ռ�ڵ㣬���Ԫ��û�������ռ���ΪNULL
 *			name�����������Ԫ����
 *		����ֵ��
 *			�ɹ����ش�����Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newelem(NETCA_XML_NodePtr ns,NETCA_UString name);

/*
 *		netca_xml_node_setdoc
 *			���ýڵ�node�ĸ��ڵ�Ϊdoc
 *		������
 *			node���ڵ�
 *			doc�����ڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setdoc(NETCA_XML_NodePtr node,NETCA_XML_DocPtr doc);

/*
 *		netca_xml_node_addchild
 *			��node�ڵ����parent�ڵ���ӽڵ��б����󣬲�Ҫ�ͷ��ӽڵ�
 *		������
 *			parent����Ԫ�ؽڵ�
 *			node��Ԫ�ؽڵ㡢PI�ڵ㡢ע�ͽڵ���ı��ڵ�
 *		����ֵ��
 *			�ɹ������ӽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addchild(NETCA_XML_NodePtr parent,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addnextsibling
 *			��node�ڵ����Ϊnode�ڵ����һ���ֵܽڵ㡣ע��nodeֻ��Ϊһ���ڵ�
 *		������
 *			cur��Ԫ�ؽڵ�����Խڵ�
 *			node��Ԫ�ؽڵ�����Խڵ�
 *		����ֵ��
 *			�ɹ��������ҵ��ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addnextsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addprevsibling
 *			��node�ڵ����Ϊnode�ڵ����һ���ֵܽڵ㡣ע��nodeֻ��Ϊһ���ڵ�
 *		������
 *			cur��Ԫ�ؽڵ�����Խڵ�
 *			node��Ԫ�ؽڵ�����Խڵ�
 *		����ֵ��
 *			�ɹ�����������ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addprevsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addsibling
 *			��node�ڵ����Ϊnode�ڵ����һ���ֵܽڵ㡣node�����Ƕ���ڵ�
 *		������
 *			cur��Ԫ�ؽڵ�����Խڵ�
 *			node��Ԫ�ؽڵ�����Խڵ�
 *		����ֵ��
 *			�ɹ��������ҵ��ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_dup
 *			����һ���ڵ�
 *		������
 *			node��Ԫ�ؽڵ�����Խڵ�
 *		����ֵ��
 *			�ɹ����ظ��ƺ�Ľڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_dup(NETCA_XML_NodePtr node);

/*
 *		netca_xml_doc_setrootelement
 *			����XML�ĵ��ĸ�Ԫ�ؽڵ�Ϊroot���ɹ���Ҫ�ͷŸ�Ԫ�ؽڵ�
 *		������
 *			doc: ���������XML�ĵ��ĸ��ڵ�
 *			root��Ҫ���õĸ�Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ����ظ�Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_doc_setrootelement(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr root);

/*
 *		netca_xml_doc_save
 *			��XML�ĵ�����Ϊ�ļ�
 *		������
 *			doc: ���������XML�ĵ��ĸ��ڵ�
 *			filename������������ļ���
 *			flag����������������NETCA_XML_NOXMLDESCλ�����ʱ��������XML�������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_doc_save(NETCA_XML_DocPtr doc,const char *filename,int flag);

/*
 *		netca_xml_doc_save_ex
 *			��XML�ĵ�����Ϊ�ļ�
 *		������
 *			doc: ���������XML�ĵ��ĸ��ڵ�
 *			encoding������������ַ�����
 *			filename������������ļ���
 *			flag����������������NETCA_XML_NOXMLDESCλ�����ʱ��������XML�������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_doc_save_ex(NETCA_XML_DocPtr doc,const char *encoding,const char *filename,int flag);

/*
 *		netca_xml_doc_dump
 *			��XML�ĵ����л����ڴ���
 *		������
 *			doc: ���������XML�ĵ��ĸ��ڵ�
 *			flag����������������NETCA_XML_NOXMLDESCλ�����ʱ��������XML�������������
 *		����ֵ��
 *			�ɹ�����XML�ĵ��ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_doc_dump(NETCA_XML_DocPtr doc,int flag);

/*
 *		netca_xml_doc_dump_ex
 *			��XML�ĵ����л����ڴ���
 *		������
 *			doc: ���������XML�ĵ��ĸ��ڵ�
 *			encoding������������ַ�����
 *			flag����������������NETCA_XML_NOXMLDESCλ�����ʱ��������XML�������������
 *		����ֵ��
 *			�ɹ�����XML�ĵ��ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_doc_dump_ex(NETCA_XML_DocPtr doc,const char *encoding,int flag);

/*
 *		netca_xml_element_dump
 *			��XMLԪ�����л����ڴ���
 *		������
 *			elem: ���������Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ����ظ�Ԫ�صı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_element_dump(NETCA_XML_NodePtr elem);

/*
 *		netca_xml_element_dump_ex
 *			��XMLԪ�����л����ڴ���
 *		������
 *			elem: ���������Ԫ�ؽڵ�
 *			encoding������������ַ�����
 *		����ֵ��
 *			�ɹ����ظ�Ԫ�صı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_element_dump_ex(NETCA_XML_NodePtr elem,const char *encoding);

/*
 *		netca_xml_node_findelemnode
 *			��parent��������������Ԫ����Ϊname�������ռ��URI��ֵΪnsuri��Ԫ�ؽڵ�
 *		������
 *			parent�����������Ԫ�ؽڵ�
 *			name�����������Ԫ����
 *			nsuri�����������Ԫ�ص������ռ��URI��ֵ��û�������ռ�ȡNULL
 *		����ֵ��
 *			�ɹ����ط��ط��������ĵ�һ��Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_findelemnode(NETCA_XML_NodePtr parent,NETCA_UString name,NETCA_UString nsuri);	

/*
 *		netca_xml_node_match
 *			�������ƺ������ռ��URI�жϽڵ��Ƿ�ƥ��
 *		������
 *			node��Ԫ�ؽڵ�
 *			name���������������
 *			nsuri����������������ռ��URI�����û�������ռ�����NULL
 *		����ֵ��
 *			������ƺ������ռ��URI�ͽڵ��ƥ�䣬����1�����򷵻�0
 */
int NETCAAPI netca_xml_node_match(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsuri);

/*
 *		netca_xml_node_skipignorenode
 *			��ȡ��һ���ֵܽڵ㣬���ǻ�����ע�ͺͿհס�
 *		������
 *			node���ڵ�
 *		����ֵ��
 *			�ɹ�������һ���ֵܽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_skipignorenode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getelemchildren
 *			��ȡ��Ԫ�ؽڵ㣬������ǰ��Ŀհ׺�ע�͡�
 *		������
 *			node����Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ�������Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getelemchildren(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_setidattr
 *			�������Խڵ�attr������ΪID����
 *		������
 *			doc�����ڵ�
 *			attr�����Խڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setidattr(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr attr);

/*
 *		netca_xml_node_findallelemnode
 *			��parent��������������Ԫ����Ϊname�������ռ��URI��ֵΪnsuri��Ԫ�ؽڵ㣬�ҵ������list��
 *		������
 *			parent�����������Ԫ�ؽڵ�
 *			name�����������Ԫ����
 *			nsuri�����������Ԫ�ص������ռ��URI��ֵ��û�������ռ�ȡNULL
 *			list��������������ط���������Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_findallelemnode(NETCA_XML_NodePtr parent,NETCA_UString name,NETCA_UString nsuri,NETCA_ArrayList *list);

/*
 *		netca_xml_c14nnode
 *			��XMLԪ�ؽڵ����C14N�淶��
 *		������
 *			node: ���������XML�ĵ���Ԫ�ؽڵ�
 *			c14nAlgo�����������C14N�㷨
 *			param�����������C14N�㷨�Ĳ���
 *		����ֵ��
 *			�ɹ����ع淶���ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_c14nnode(NETCA_XML_NodePtr node,int c14nAlgo,void *param);

/*
 *		netca_xml_decode_signature
 *			����SignatureԪ�ؽڵ㣬ת��ΪXMLǩ����֤������
 *		������
 *			node: ���������SignatureԪ�ؽڵ�
 *		����ֵ��
 *			�ɹ�������Ч��XMLǩ����֤�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_VerifyCtx netca_xml_decode_signature(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_findsignature
 *			��parent��������������Ԫ����ΪSignature�������ռ��URI��ֵΪhttp://www.w3.org/2000/09/xmldsig#��Ԫ�ؽڵ㣨Ҳ����XMLǩ���ڵ㣩���ҵ������list��
 *		������
 *			parent�����������Ԫ�ؽڵ�
 *			list������������������е�Signature��Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_node_findsignature(NETCA_XML_NodePtr parent,NETCA_ArrayList *list);

/*
 *		netca_xml_signature_getsignalgothrim
 *			��ȡǩ���㷨
 *		������
 *			ctx�����������XMLǩ����֤������
 *			algo�����������ǩ���㷨
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_getsignalgothrim(NETCA_XML_Signature_VerifyCtx ctx,int *algo);

/*
 *		netca_xml_free_signature
 *			�ͷ�XMLǩ����֤������
 *		������
 *			ctx�����������XMLǩ����֤������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_free_signature(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_dup
 *			����XMLǩ����֤������
 *		������
 *			ctx�����������XMLǩ����֤������
 *		����ֵ��
 *			�ɹ����ظ��ƺ��XMLǩ����֤������
 */
NETCA_XML_Signature_VerifyCtx netca_xml_signature_dup(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_key_free
 *			�ͷ�XMLǩ������Կ
 *		������
 *			key�� XMLǩ������Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_key_free(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_sethmackey
 *			����HMAC����Կ
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			key�������������Կ
 *			keylen�����������key���ֽ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sethmackey(NETCA_XML_Signature_VerifyCtx ctx,const unsigned char *key,long keylen);

/*
 *		netca_xml_signature_sethdomainparam
 *			�������������֤DSAʱ����Ҫ��
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			p�����������p
 *			q�����������q
 *			g�����������g
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sethdomainparam(NETCA_XML_Signature_VerifyCtx ctx,NETCA_BigInteger p,NETCA_BigInteger q,NETCA_BigInteger g);

/*
 *		netca_xml_signature_addcert
 *			���֤�鵽XMLǩ����֤�����ģ��԰�����֤ǩ����cert�����XMLǩ�����õ�����֤��
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			cert�����������֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_addcert(NETCA_XML_Signature_VerifyCtx ctx,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_setbasepath
 *			���û�׼·��
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			basepath�������������׼·��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_setbasepath(NETCA_XML_Signature_VerifyCtx ctx,NETCA_UString basepath);

/*
 *		netca_xml_signature_key_dup
 *			����XMLǩ������Կ
 *		������
 *			key�� XMLǩ������Կ
 *		����ֵ��
 *			�ɹ����ظ��Ƶõ���XMLǩ������Կ��ʧ�ܷ���NULL
 */
NETCA_XML_Signature_Key NETCAAPI netca_xml_signature_key_dup(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_key_newcert
 *			����֤�鴴��XMLǩ������Կ
 *		������
 *			cert�� ֤��
 *		����ֵ��
 *			�ɹ����ذ���֤���XMLǩ������Կ�����򷵻�NULL
 */
NETCA_XML_Signature_Key NETCAAPI netca_xml_signature_key_newcert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_key_getcert
 *			��ȡXMLǩ������Կ�е�֤��
 *		������
 *			key�� XMLǩ������Կ
 *		����ֵ��
 *			���XMLǩ������Կʹ�õ���֤�飬����֤�飬���򷵻�NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_key_getcert(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_signaturevalidation
 *			��֤XMLǩ���������ǲ���֤����
 *		������
 *			ctx�� XMLǩ����֤������
 *			verifykey���������������ǩ������Կ
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_signaturevalidation(NETCA_XML_Signature_VerifyCtx ctx,NETCA_XML_Signature_Key *verifykey,int *reason);

/*
 *		netca_xml_signature_getid
 *			��ȡXMLǩ����Id
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����XMLǩ����Id��û�л���ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_getid(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_getsignaturevalueid
 *			��ȡXMLǩ����ǩ��ֵ��Id
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����XMLǩ����ǩ��ֵ��Id��û�л���ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_getsignaturevalueid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getqualifyingpropertiesid
 *			��ȡQualifyingProperties��ID���ԡ�
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����Idֵ��û�л���ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getqualifyingpropertiesid(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_xades_getsignedpropertiesid
 *			��ȡSignedProperties��ID���ԡ�
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����Idֵ��û�л���ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getsignedpropertiesid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getsignedsignaturepropertiesid
 *			��ȡSignedSignatureProperties��ID���ԡ�
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����Idֵ��û�л���ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getsignedsignaturepropertiesid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getsignaturetimestampcount
 *			��ȡXMLǩ����ǩ��ʱ�������
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����ǩ��ʱ���������ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_xades_getsignaturetimestampcount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_verifysignaturetimestamp
 *			��֤XMLǩ����ǩ��ʱ���
 *		������
 *			ctx�� XMLǩ����֤������
 *			index:���������������
 *			cert:���������ʱ���֤�飬����ΪNULL
 *			phTimeStamp��������������ص�ʱ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_verifysignaturetimestamp(NETCA_XML_Signature_VerifyCtx ctx,int index,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);


/*
 *		netca_xml_signature_xades_getcountersignaturecount
 *			��ȡXMLǩ��������ǩ������
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ���������ǩ��������ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_xades_getcountersignaturecount(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_xades_verifycountersignature
 *			��֤XMLǩ��������ǩ��
 *		������
 *			ctx�� XMLǩ����֤������
 *			index:���������������
 *			cert:������������ܵ�ǩ��֤�飬����ΪNULL
 *			signCert:���������ǩ��֤��
 *			signNode�������������������ǩ����ǩ���ڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_verifycountersignature(NETCA_XML_Signature_VerifyCtx ctx,int index,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_CERTIFICATE_HANDLE *signCert,NETCA_XML_NodePtr* signNode);


/*
 *		netca_xml_signature_xades_getcompleterevocationrefscount
 *			��ȡXMLǩ����CompleteRevocationRefs��֤�����
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����CompleteRevocationRefs��֤�������ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_xades_getcompleterevocationrefscount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getcompleterevocationref
 *			��ȡXMLǩ����CompleteRevocationRefs�ĵ�index��CertID
 *		������
 *			ctx�� XMLǩ����֤������
 *			index���������������ֵ
 *		����ֵ��
 *			�ɹ�������Ӧ��CertID��ʧ�ܷ���NULL
 */
NETCA_XAdES_CertID NETCAAPI netca_xml_signature_xades_getcompleterevocationref(NETCA_XML_Signature_VerifyCtx ctx,int index);

/*
 *		netca_xml_signature_xades_getcertificatevaluescount
 *			��ȡXMLǩ����CertificateValues��֤�����
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����CertificateValues��֤�������ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_xades_getcertificatevaluescount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getcertificatevalues
 *			��ȡXMLǩ����CertificateValues�ĵ�index��֤��
 *		������
 *			ctx�� XMLǩ����֤������
 *			index���������������ֵ
 *		����ֵ��
 *			�ɹ�����֤������ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_xades_getcertificatevalue(NETCA_XML_Signature_VerifyCtx ctx,int index);

/*
 *		netca_xml_signature_xades_getsigningtime
 *			��ȡXMLǩ����ǩ��ʱ�����ԣ��������ʱ���ʱ��
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����ǩ��ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_xml_signature_xades_getsigningtime(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_hassigningcertificate
 *			�ж�XMLǩ���Ƿ�ǩ��֤������
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�����ǩ��֤�����Է��أ����򷵻�0
 */
int NETCAAPI netca_xml_signature_xades_hassigningcertificate(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_getsigncert
 *			��ȡǩ��֤��
 *		������
 *			ctx�� XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_getsigncert(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_setid
 *			����XMLǩ����ID���ԣ��Ա�URI���ÿ����ҵ�
 *		������
 *			doc�� XML�ĵ��ĸ��ڵ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_setid(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_getidelemnode
 *			��ȡID�������ڵ�Ԫ�ؽڵ㣬��Ҫ�ͷ���
 *		������
 *			doc�� XML�ĵ��ĸ��ڵ�
 *			id�����������ID���Ե�ֵ
 *		����ֵ��
 *			�ɹ����ذ���ID�������ڵ�Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_getidelemnode(NETCA_XML_DocPtr doc,NETCA_UString id);

/*
 *		netca_xml_getidattribute
 *			��ȡID���Խڵ㣬��Ҫ�ͷ���
 *		������
 *			doc�� XML�ĵ��ĸ��ڵ�
 *			id�����������ID���Ե�ֵ
 *		����ֵ��
 *			�ɹ�����ID���Խڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_getidattribute(NETCA_XML_DocPtr doc,NETCA_UString id);

/*
 *		netca_xml_signature_issignaturenode
 *			�ж�Ԫ�ؽڵ��Ƿ�XMLǩ���ڵ�
 *		������
 *			node�� Ԫ�ؽڵ�
 *		����ֵ��
 *			��XMLǩ���ڵ㷵��1�����Ƿ���0
 */
int NETCAAPI netca_xml_signature_issignaturenode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_gethmaclength
 *			��ȡHMAC�ĳ���
 *		������
 *			ctx�� XMLǩ����֤������
 *			len������������ɹ�����HMAC�ĳ��ȣ����ֽ�Ϊ��λ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_gethmaclength(NETCA_XML_Signature_VerifyCtx ctx,int *len);

/*
 *		netca_xml_signature_referencevalidation
 *			��֤SignedInfo����������ã�������֤Manifest�������
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			data��������������õ�URIΪ�յ�ʱ�����õ�ֵ������ΪNULL
 *			datalen�����������data���ֽ���
 *			reason�����������ʧ�ܷ��ص�ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_referencevalidation(NETCA_XML_Signature_VerifyCtx ctx,const unsigned char *data,long datalen,int *reason);
/*
 *		netca_xml_signature_referencevalidation_ex
 *			��֤SignedInfo�����������
 *		������
 *			ctx�� ���������XMLǩ����֤������
 *			verifyflag�������������֤��ʶ
 *			data��������������õ�URIΪ�յ�ʱ�����õ�ֵ������ΪNULL
 *			datalen�����������data���ֽ���
 *			reason�����������ʧ�ܷ��ص�ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_referencevalidation_ex(NETCA_XML_Signature_VerifyCtx ctx,int verifyflag,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verifyref
 *			��֤XML����
 *		������
 *			refnode��������������ýڵ�
 *			data�������������URI�����õ����ݣ�����ΪNULL
 *			datalen�����������data���ֽ���
 *		reason�����������ʧ�ܷ���ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verifyref(NETCA_XML_NodePtr refnode,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verifyref_ex
 *			��֤XML����
 *		������
 *			refnode��������������ýڵ�
 *			verifyflag�������������֤��־
 *			basepath�������������׼·��
 *			data�������������URI�����õ����ݣ�����ΪNULL
 *			datalen�����������data���ֽ���
 *		reason�����������ʧ�ܷ���ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verifyref_ex(NETCA_XML_NodePtr refnode,int verifyflag,NETCA_UString basepath,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verify
 *			��֤XML�ĵ�������ǩ��������ǩ��ֵ��SignedInfo������ã������ǲ���֤Manifest������
 *		������
 *			doc�����������XML�ĵ��ĸ��ڵ�
 *			data�������������URI�����õ����ݣ�����ΪNULL
 *			datalen�����������data���ֽ���
 *			verifykeys�����������ǩ����Կ�б������Ԫ����NETCA_XML_Signature_Key
 *			reason�����������ʧ�ܷ���ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verify(NETCA_XML_DocPtr doc,const unsigned char *data,long datalen,NETCA_ArrayList *verifykeys,int *reason);

/*
 *		netca_xml_signature_verify_ex
 *			��֤XML�ĵ�������ǩ��������ǩ��ֵ��SignedInfo������ã������ǲ���֤Manifest������
 *		������
 *			doc�����������XML�ĵ��ĸ��ڵ�
 *			basepath�������������׼·��
 *			data�������������URI�����õ����ݣ�����ΪNULL
 *			datalen�����������data���ֽ���
 *			verifykeys�����������ǩ����Կ�б������Ԫ����NETCA_XML_Signature_Key
 *			reason�����������ʧ�ܷ���ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verify_ex(NETCA_XML_DocPtr doc,NETCA_UString basepath,const unsigned char *data,long datalen,NETCA_ArrayList *verifykeys,int *reason);

/*
 *		netca_xml_signature_getnode
 *			��ȡXMLǩ����֤�����Ķ�Ӧ��Ԫ�ؽڵ㣬Ҳ����XMLǩ��Ԫ�ؽڵ�
 *		������
 *			ctx�����������XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����XMLǩ����֤�����Ķ�Ӧ��Ԫ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_signature_getnode(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_getsignedinfo
 *			XMLǩ����֤������ת��Ϊǩ��ǩ����Ϣ������
 *		������
 *			ctx�����������XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����ǩ����Ϣ�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_getsignedinfo(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_transformctx_new
 *			����ת��������
 *		������
 *			algoid�����������ת���㷨
 *			param�����������ת���㷨����������ΪNULL
 *		����ֵ��
 *			�ɹ����ش�����ת�������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_TransformCtx NETCAAPI netca_xml_signature_transformctx_new(int algoid,void *param);

/*
 *		netca_xml_signature_transformctx_free
 *			�ͷ�ת��������
 *		������
 *			ctx�� ת��������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_transformctx_free(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_transformctx_dup
 *			����ת��������
 *		������
 *			ctx�� ת��������
 *		����ֵ��
 *			�ɹ����ظ��Ƶĵõ���ת�������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_TransformCtx NETCAAPI netca_xml_signature_transformctx_dup(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_transformctx_getalgoid
 *			���ת���㷨
 *		������
 *			ctx�� ת��������
 *		����ֵ��
 *			�ɹ�����ת���㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_transformctx_getalgoid(NETCA_XML_Signature_TransformCtx ctx);


/*
 *		netca_xml_signature_transformctx_getparam
 *			���ת���㷨��صĲ���
 *		������
 *			ctx�� ת��������
 *		����ֵ��
 *			�ɹ�����ת���㷨��صĲ�����û�л���ʧ�ܷ���NULL
 */
void* NETCAAPI netca_xml_signature_transformctx_getparam(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_referencectx_new
 *			��������������
 *		������
 *			hashalgoid�� ���������Hash�㷨
 *			id��������������õ�ID���Ե�ֵ��ΪNULL��ʾû��ID����
 *			uri��������������õ�URI��ΪNULLʱ��data������ֵ
 *			type��������������õ�type���Ե�ֵ��ΪNULL��ʾû��type����
 *			data�������������uriΪNULLʱ��Ч�����ǰ������õ�����
 *			transforms�����������ת���б������Ԫ����NETCA_XML_Signature_TransformCtx������ΪNULL
 *		����ֵ��
 *			�ɹ����ش��������������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_new(int hashalgoid,NETCA_UString id,NETCA_UString uri,NETCA_UString type,
								     NETCA_Data_Blob data,NETCA_ArrayList transforms);

/*
 *		netca_xml_signature_referencectx_newwithhash
 *			��������������
 *		������
 *			hashalgoid�� ���������Hash�㷨
 *			hash�����������Hashֵ
 *			id��������������õ�ID���Ե�ֵ��ΪNULL��ʾû��ID����
 *			uri��������������õ�URI��ΪNULLʱ��data������ֵ
 *			type��������������õ�type���Ե�ֵ��ΪNULL��ʾû��type����
 *			data�������������uriΪNULLʱ��Ч�����ǰ������õ�����
 *			transforms�����������ת���б������Ԫ����NETCA_XML_Signature_TransformCtx������ΪNULL
 *		����ֵ��
 *			�ɹ����ش��������������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_newwithhash(int hashalgoid,NETCA_Data_Blob hash,NETCA_UString id,NETCA_UString uri,
									NETCA_UString type,NETCA_ArrayList transforms);

/*
 *		netca_xml_signature_referencectx_free
 *			�ͷ�����������
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_referencectx_free(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_dup
 *			��������������
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ����ظ��Ƶõ������������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_dup(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gethashalgoid
 *			�������ʹ�õ�Hash�㷨
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ���������ʹ�õ�Hash�㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_referencectx_gethashalgoid(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gethashvalue
 *			������õ�Hashֵ
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ���������ʹ�õ�Hashֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_signature_referencectx_gethashvalue(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_getid
 *			������õ�ID����
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ��������õ�ID���Ե�ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_getid(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_geturi
 *			������õ�URI
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ��������õ�URI��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_geturi(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gettype
 *			������õ�Type
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ��������õ�Type��û�л�ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_gettype(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gettransforms
 *			������õ�ת���б�
 *		������
 *			ctx�� �������������������
 *		����ֵ��
 *			�ɹ��������õ�ת���б�û�з���NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_referencectx_gettransforms(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_uri_encode
 *			URI����
 *		������
 *			path�� ���������URI
 *		����ֵ��
 *			�ɹ�����URI���룬ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_uri_encode(NETCA_UString path);

/*
 *		netca_xml_signature_ismanifestnode
 *			�ж�Ԫ�ؽڵ��Ƿ�Manifest�ڵ�
 *		������
 *			node�� ���������Ԫ�ؽڵ�
 *		����ֵ��
 *			���Ԫ�ؽڵ���Manifest�ڵ㷵��1�����򷵻�0
 */
int NETCAAPI netca_xml_signature_ismanifestnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_decodemanifestnode
 *			����Manifest�ڵ�
 *		������
 *			node��ManifestԪ�ؽڵ�
 *		����ֵ��
 *			�ɹ�����ManifestԪ�ؽڵ��µ��������ýڵ��б�ʧ�ܷ���NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_decodemanifestnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_referencectx_decode
 *			�������ýڵ㹹������������
 *		������
 *			node�� ������������ýڵ�
 *		����ֵ��
 *			�ɹ��������������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_decode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_getreflist
 *			��ȡSignedInfoԪ��������ýڵ��б�������ManifestԪ�ص���Щ��
 *		������
 *			ctx�����������XMLǩ����֤������
 *		����ֵ��
 *			�ɹ�����XMLǩ����֤�����ĵ����ýڵ��б�ʧ�ܷ���NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_getreflist(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_signedinfoctx_new
 *			����ǩ����Ϣ�����ġ�
 *		������
 *			id�� ���������SignedInfo��ID���Ե�ֵ������ΪNULL
 *			c14nalgoid������������淶������
 *			c14nparam������������淶�������Ĳ���������ΪNULL
 *			signalgoid�����������ǩ���㷨
 *			refs����������������б������Ԫ����NETCA_XML_Signature_ReferenceCtx
 *		����ֵ��
 *			�ɹ����ش�����ǩ����Ϣ�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_signedinfoctx_new(NETCA_UString id,int c14nalgoid,void *c14nparam,
										 int signalgoid,NETCA_ArrayList refs);



/*
 *		netca_xml_signature_signedinfoctx_setsignaturevalueid
 *			����ǩ��ֵ��Id���ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			id�����������IDֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_setsignaturevalueid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);

/*
 *		netca_xml_signature_signedinfoctx_xades_setusesigningtime
 *			�����Ƿ�ʹ��ǩ��ʱ�����ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			value�����������Ϊ�����ʾʹ��ǩ��ʱ�����ԣ�Ϊ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setusesigningtime(NETCA_XML_Signature_SignedInfoCtx ctx,int value);

/*
 *		netca_xml_signature_signedinfoctx_xades_setqualifyingpropertiesid
 *			����QualifyingProperties��ID���ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			id�� ���������QualifyingProperties��ID���Ե�ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setqualifyingpropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignedpropertiesid
 *			����SignedProperties��ID���ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			id�� ���������SignedProperties��ID���Ե�ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignedpropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);

/*
 *		netca_xml_signature_signedinfoctx_xades_setsignedsignaturepropertiesid
 *			����SignedSignatureProperties��ID���ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			id�� ���������SignedSignatureProperties��ID���Ե�ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignedsignaturepropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsigningcertificateinfo
 *			����ǩ��֤�����ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			hashalgoid:���������Hash�㷨
 *			flag:�������������֤���ѡ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsigningcertificateinfo(NETCA_XML_Signature_SignedInfoCtx ctx,int hashalgoid,int flag);

/*
 *		netca_xml_signature_signedinfoctx_setincludecertflag
 *			���ð���֤���ѡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			flag:�������������֤���ѡ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_setincludecertflag(NETCA_XML_Signature_SignedInfoCtx ctx,int flag);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignaturepolicyimplied
 *			����ʹ����ʽ��ǩ�����ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignaturepolicyimplied(NETCA_XML_Signature_SignedInfoCtx ctx);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignatureproductionplace
 *			����ʹ�ò���ǩ�����ԡ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *			city:�������������
 *			province:���������ʡ��
 *			postalcode:�����������������
 *			countryname:�������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignatureproductionplace(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString city,NETCA_UString province,NETCA_UString postalcode,NETCA_UString countryname);

/*
 *		netca_xml_signature_signedinfoctx_free
 *			�ͷ�ǩ����Ϣ�����ġ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_signedinfoctx_free(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_dup
 *			����ǩ����Ϣ�����ġ�
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ����ظ��Ƶõ���ǩ����Ϣ�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_signedinfoctx_dup(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getid
 *			��ȡ�淶���㷨��
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ�����SignedInfo�ڵ��Id��ʧ�ܻ���û�з���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_signedinfoctx_getid(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getc14nmethon
 *			��ȡ�淶���㷨��
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ����ع淶���㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_signedinfoctx_getc14nmethon(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getc14nparam
 *			��ȡ�淶���㷨�Ĳ�����
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ����ع淶���㷨������ʧ�ܻ�û�з���NULL
 */
void* NETCAAPI netca_xml_signature_signedinfoctx_getc14nparam(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getsignalgoid
 *			��ȡǩ���㷨��
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ�����ǩ���㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_signedinfoctx_getsignalgoid(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getrefs
 *			��������б�
 *		������
 *			ctx�� ǩ����Ϣ������
 *		����ֵ��
 *			�ɹ����ط��������б�ʧ�ܷ���NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_signedinfoctx_getrefs(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_objectctx_newdata
 *			����һ��PCDATA��ObjectԪ�ء�
 *		������
 *			id�� ���������ObjectԪ�ص�ID���Ե�ֵ������ΪNULL����ʾû�и�����
 *			mimetype�����������ObjectԪ�ص�mimetype���Ե�ֵ������ΪNULL����ʾû�и�����
 *			encoding�����������ObjectԪ�ص�encoding���Ե�ֵ������ΪNULL����ʾû�и�����
 *			data�����������ObjectԪ�ص����ı��ڵ��ֵ
 *		����ֵ��
 *			�ɹ����ش�����XMLǩ����Object�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newdata(NETCA_UString id,NETCA_UString mimetype,NETCA_UString encoding,NETCA_UString data);

/*
 *		netca_xml_signature_objectctx_free
 *			�ͷ�XMLǩ����Object�����ġ�
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_objectctx_free(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_dup
 *			����XMLǩ����Object�����ġ�
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			�ɹ����ظ��Ƶõ���XMLǩ����Object�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_dup(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_newmanifest
 *			����һ������Manifest��ObjectԪ��
 *		������
 *			id�� ���������ManifestԪ�ص�ID���Ե�ֵ������ΪNULL����ʾû�и�����
 *			refs����������������б�
 *		����ֵ��
 *			�ɹ����ش�����XMLǩ����Object�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newmanifest(NETCA_UString id,NETCA_ArrayList refs);

/*
 *		netca_xml_signature_objectctx_getmanifest
 *			��ȡManifest�е������б��б�
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			XMLǩ����Object�����Manifest�б����������б����򷵻�NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_objectctx_getmanifest(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_getnode
 *			��ȡXMLǩ����ObjectԪ�ؽڵ�
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			�ɹ�XMLǩ����ObjectԪ�ؽڵ㣬ʧ�ܷ���NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_signature_objectctx_getnode(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_gettype
 *			��ȡXMLǩ����Object������
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			�ɹ�XMLǩ����Object�����ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_objectctx_gettype(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_newnode
 *			���ݽڵ㴴��XMLǩ����Object������
 *		������
 *			id�����������ID
 *			node:���������Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ����ش�����XMLǩ����Object�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newnode(NETCA_UString id,NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_signaturepropctx_new
 *			����XMLǩ����ǩ������������
 *		������
 *			id�����������ID
 *			target�����������Ŀ��
 *			node:���������Ԫ�ؽڵ�
 *		����ֵ��
 *			�ɹ����ش�����XMLǩ����ǩ�����������ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_SignaturePropertyCtx NETCAAPI netca_xml_signature_signaturepropctx_new(NETCA_UString id,NETCA_UString target,NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_signaturepropctx_free
 *			�ͷ�XMLǩ����ǩ������������
 *		������
 *			ctx�����������XMLǩ����ǩ������������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_signaturepropctx_free(NETCA_XML_Signature_SignaturePropertyCtx ctx);

/*
 *		netca_xml_signature_objectctx_newsignprops
 *			����XMLǩ����ǩ�������б��Object������
 *		������
 *			id�����������ID
 *			signprops�����������һ��XMLǩ����ǩ������������
 *		����ֵ��
 *			�ɹ����ش�����XMLǩ����ǩ�������б��Object�����ģ�ʧ�ܷ���NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newsignprops(NETCA_UString id,NETCA_ArrayList signprops);

/*
 *		netca_xml_signature_objectctx_getsignatureprops
 *			��ȡXMLǩ����ǩ�������������б�
 *		������
 *			ctx�� XMLǩ����Object������
 *		����ֵ��
 *			�ɹ�����XMLǩ����ǩ�������������б�ʧ�ܷ���NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_objectctx_getsignatureprops(NETCA_XML_Signature_ObjectCtx ctx);


/*
 *		netca_xml_signature_sign
 *			����XMLǩ����doc��parent��leftsibing������XMLǩ��Ԫ�ز����λ��
 *		������
 *			doc�� XML�ĵ��ĸ��ڵ㣬����ΪNULL����ʱ��ʾXMLǩ��Ԫ�ؾ���XML�ĵ��ĸ�Ԫ��
 *			parent��XMLǩ��Ԫ�صĸ�Ԫ�ؽڵ�
 *			leftsibing��XMLǩ��Ԫ����ߵ��ֵܽڵ㣬���ΪNULL�����ʾXMLǩ��Ԫ����parentԪ�صĵ�һ���ӽڵ�
 *			id�����������XMLǩ��Ԫ�ص�ID���Ե�ֵ�����ΪNULL�����ʾû��ID����
 *			signedinfo�����������Ҫǩ����ǩ����Ϣ������
 *			objs�����������XMLǩ����Object�������б�����ΪNULL,�����Ԫ��ΪNETCA_XML_Signature_ObjectCtx
 *			cert�����������ǩ��˽Կ��Ӧ��֤��
 *			pwd�����������ʹ��ǩ��˽Կ��Ҫ�����룬����ΪNULL
 *			signnode�����������������XMLǩ��Ԫ��
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sign(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent,NETCA_XML_NodePtr leftsibing,
					NETCA_UString id,NETCA_XML_Signature_SignedInfoCtx signedinfo,NETCA_ArrayList objs,
					NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,
					NETCA_XML_NodePtr *signnode,int *reason);

/*
 *		netca_xml_signature_signex
 *			����XMLǩ����doc��parent��leftsibing������XMLǩ��Ԫ�ز����λ��
 *		������
 *			doc�� XML�ĵ��ĸ��ڵ㣬����ΪNULL����ʱ��ʾXMLǩ��Ԫ�ؾ���XML�ĵ��ĸ�Ԫ��
 *			parent��XMLǩ��Ԫ�صĸ�Ԫ�ؽڵ�
 *			leftsibing��XMLǩ��Ԫ����ߵ��ֵܽڵ㣬���ΪNULL�����ʾXMLǩ��Ԫ����parentԪ�صĵ�һ���ӽڵ�
 *			id�����������XMLǩ��Ԫ�ص�ID���Ե�ֵ�����ΪNULL�����ʾû��ID����
 *			signedinfo�����������Ҫǩ����ǩ����Ϣ������
 *			objs�����������XMLǩ����Object�������б�����ΪNULL,�����Ԫ��ΪNETCA_XML_Signature_ObjectCtx
 *			key�����������ǩ������Կ��Ϣ��ͨ������ǩ��֤��
 *			privkey�����������ǩ��˽Կ
 *			checkkey�����������Ϊ���ʾУ��˽Կ��Ϊ�ٲ�У��
 *			certs�����������������ص�֤��
 *			basepath�������������׼·��
 *			signnode�����������������XMLǩ��Ԫ��
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_signex(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent,NETCA_XML_NodePtr leftsibing,
					NETCA_UString id,NETCA_XML_Signature_SignedInfoCtx signedinfo,NETCA_ArrayList objs,
					NETCA_XML_Signature_Key key,NETCA_PKI_KEYPAIR_HANDLE privkey,int checkkey,NETCA_ArrayList certs,
					NETCA_UString basepath,NETCA_XML_NodePtr *signnode,int *reason);


/*
 *		netca_xml_signature_xades_addsignaturetimestamp
 *			��XMLǩ��׷��ʱ�������ΪSignatureTimeStamp����
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			id�����������SignatureTimeStamp���Ե�ID���Ե�ֵ�����ΪNULL�����ʾû��ID����
 *			c14nAlgoid������������淶���㷨��-1��ʾ�����в����淶���㷨
 *			param������������淶���㷨����
 *			tsaurl�����������ʱ�����������URL
 *			hashAlgo�����������ʹ�õ�ǩ���㷨
 *			phTimeStamp������������ɹ�����ʱ�����������ΪNULL���򲻷���
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addsignaturetimestamp(NETCA_XML_NodePtr signNode,NETCA_UString id,int c14nAlgoid,void *param,const char *tsaurl,int hashAlgo,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp,int *reason);


/*
 *		netca_xml_signature_xades_addcompletecertificaterefs
 *			��XMLǩ��׷��CompleteCertificateRefs����
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			id�����������CompleteCertificateRefs���Ե�ID���Ե�ֵ�����ΪNULL�����ʾû��ID����
 *			hashAlgo:���������Hash�㷨
 *			cert:���������ǩ��֤��
 *			reserve���������������������ΪNULL
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addcompletecertificaterefs(NETCA_XML_NodePtr signNode,NETCA_UString id,int hashAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert,void *reserve);

/*
 *		netca_xml_signature_xades_add_completerevocationrefs_crl
 *			��XMLǩ��׷��CompleteRevocationRefs���ԣ�����CRL
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			hashAlgo:���������Hash�㷨
 *			flag�����������ʹ��CRLIdentifier�ı�ʶ
 *			crl:���������CRL�ı���
 *			crlLen:���������CRL�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_add_completerevocationrefs_crl(NETCA_XML_NodePtr signNode,int hashAlgo,int flag,const unsigned char *crl,int crlLen);

/*
 *		netca_xml_signature_xades_set_completerevocationrefs_id
 *			��XMLǩ����CompleteRevocationRefs���ԣ�����ID����
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			id:���������IDֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_completerevocationrefs_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_xades_addcertificatevalues
 *			��XMLǩ��׷��CertificateValues���ԣ�����֤��
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			cert:֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addcertificatevalues(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_xades_set_certificatevalues_id
 *			��XMLǩ����CertificateValues���ԣ�����ID����
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			id:���������IDֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_certificatevalues_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_xades_add_revocationvalues_crl
 *			��XMLǩ��׷��RevocationValues���ԣ�����CRL
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			crl:���������CRL����
 *			crlLen:���������CRL����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_add_revocationvalues_crl(NETCA_XML_NodePtr signNode,const unsigned char *crl,int crlLen);

/*
 *		netca_xml_signature_xades_set_revocationvalues_id
 *			��XMLǩ����RevocationValues���ԣ�����ID����
 *		������
 *			signNode��ǩ��Ԫ�ؽڵ�
 *			id:���������IDֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_revocationvalues_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_sign_ex
 *			����XMLǩ��
 *		������
 *			signNode�� XMLǩ���Ľڵ㣬�����Ҫ�����ǩ���ڵ�
 *			signCert�����������ǩ��֤��
 *			param�����������ǩ������ز���
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sign_ex(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE signCert,NETCA_JSON param,int *reason);

/*
 *		netca_xml_signature_countersign
 *			����XMLǩ��������ǩ��
 *		������
 *			signNode�� XMLǩ���Ľڵ㣬�����Ҫ��������ǩ����ǩ���ڵ�
 *			signCert�����������ǩ��֤��
 *			hashAlgo���������������ʹ�õ�Hash�㷨
 *			counterSignId�����������CountSign��ds:Signature�ڵ��Id������ΪNULL
 *			param�����������ǩ������ز���
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_countersign(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE signCert,int hashAlgo,NETCA_UString counterSignId,NETCA_JSON param,NETCA_XML_NodePtr* counterSignNode,int *reason);

/*
 *		netca_xml_signature_calref
 *			�������ýڵ������ֵ
 *		������
 *			refnode�� ���ýڵ�
 *			flag����������������ñ�־
 *			basepath�������������׼·��
 *			reason�����������ʧ�ܷ��ص�ʧ��ԭ��
 *		����ֵ��
 *			�ɹ��������õ�Hashֵ��Base64���룬ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_calref(NETCA_XML_NodePtr refnode,int flag,NETCA_UString basepath,int *reason);

/*
 *		netca_xml_signature_xades_certid_free
 *			�ͷ�CertID
 *		������
 *			certId�� CertID���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_xml_signature_xades_certid_free(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_matchcert
 *			�ж�CertID��֤���Ƿ�ƥ��
 *		������
 *			certId�� CertID���
 *			cert��֤����
 *		����ֵ��
 *			ƥ�䷵��1����ƥ�䷵��0
 */
int NETCAAPI netca_xml_signature_xades_certid_matchcert(NETCA_XAdES_CertID certId,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_xades_certid_getcerthashalgo
 *			��ȡCertID��Hash�㷨
 *		������
 *			certId�� CertID���
 *		����ֵ��
 *			�ɹ�����֤���Hash�㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_xml_signature_xades_certid_getcerthashalgo(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_getcerthashvalue
 *			��ȡCertID��֤���Hashֵ
 *		������
 *			certId�� CertID���
 *			hash������������ɹ�����Hashֵ
 *			hashLen:����������ɹ�����Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_certid_getcerthashvalue(NETCA_XAdES_CertID certId,unsigned char **hash,int *hashLen);

/*
 *		netca_xml_signature_xades_certid_getissuer
 *			��ȡCertID��֤��İ䷢��
 *		������
 *			certId�� CertID���
 *		����ֵ��
 *			�ɹ�����֤��İ䷢�ߣ�ʧ�ܷ���NULL
 */
char* NETCAAPI netca_xml_signature_xades_certid_getissuer(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_getsn
 *			��ȡCertID��֤������к�
 *		������
 *			certId�� CertID���
 *		����ֵ��
 *			�ɹ�����֤������кţ�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_xml_signature_xades_certid_getsn(NETCA_XAdES_CertID certId);

#ifdef __cplusplus
}
#endif
#endif
