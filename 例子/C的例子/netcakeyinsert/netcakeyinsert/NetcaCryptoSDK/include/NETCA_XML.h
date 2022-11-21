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
 *			初始化NETCA_XML库，必须在程序开始时调用它
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_init(void);

/*
 *		netca_xml_end
 *			释放NETCA_XML库的全局的配置信息，只应该在程序结束的时候才调用
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_end(void);

/*
 *		netca_xml_parse
 *			解析XML文档
 *		参数：
 *			data：输入参数，XML的编码值
 *			dataLen：输入参数，data的字节数
 *		返回值：
 *			成功返回XML文档的根元素，失败返回NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_parse(const unsigned char *data,long dataLen);

/*
 *		netca_xml_parsefile
 *			从文件中解析XML文档
 *		参数：
 *			fileName：输入参数，文件名
 *		返回值：
 *			成功返回XML文档的根元素，失败返回NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_parsefile(const char *fileName);

/*
 *		netca_xml_doc_free
 *			释放整个XML文档，下面所有的节点都会被释放
 *		参数：
 *			doc: XML文档的根节点
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_doc_free(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_doc_getrootelement
 *			获取XML文档的根元素，不要释放它
 *		参数：
 *			doc: XML文档的根节点
 *		返回值：
 *			成功返回XML文档的根元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_doc_getrootelement(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_node_gettype
 *			获取节点的类型
 *		参数：
 *			node：节点
 *		返回值：
 *			返回节点类型，node为NULL或未知节点返回-1
 */
int NETCAAPI netca_xml_node_gettype(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getname
 *			获取节点名
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getname(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getprefixedname
 *			获取节点的命名空间前缀
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的命名空间前缀，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getprefixedname(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnsuri
 *			获取节点的命名空间URI
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的命名空间URI，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getnsuri(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getvalue
 *			获取节点的值
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getvalue(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getpcdata
 *			获取文本节点的PCDATA定义的内容
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回文本节点的PCDATA定义的内容，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getpcdata(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getdoc
 *			获取XML根节点
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的所在的XML根节点，失败返回NULL
 */
NETCA_XML_DocPtr NETCAAPI netca_xml_node_getdoc(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getchildren
 *			获取元素节点的第一个子元素节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回元素节点的第一个子元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getchildren(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getparent
 *			获取节点的父节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的父节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getparent(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnextsibling
 *			获取节点的下一个兄弟节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的下一个兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getnextsibling(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getprevsibling
 *			获取节点的前一个兄弟节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点的前一个兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getprevsibling(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getattributevalue
 *			获取元素节点的属性值
 *		参数：
 *			node：节点
 *			name：名称
 *			nsUri:名字空间URI
 *		返回值：
 *			成功返回属性值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_node_getattributevalue(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsUri);

/*
 *		netca_xml_node_findattribute
 *			获取元素节点的属性
 *		参数：
 *			node：节点
 *			name：名称
 *			nsUri:名字空间URI
 *		返回值：
 *			成功返回属性，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_findattribute(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsUri);

/*
 *		netca_xml_node_getattribute
 *			获取元素节点的第一个属性节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回元素节点的第一个属性节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getattribute(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getnsnode
 *			获取元素节点定义的命名空间节点，不要释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回元素节点定义的第一个命名空间节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getnsnode(NETCA_XML_NodePtr node);


/*
 *		netca_xml_node_getassociatednsnode
 *			获取节点关联的命名空间节点
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回节点关联的命名空间节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getassociatednsnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_newtext
 *			创建的文本节点
 *		参数：
 *			doc：根节点
 *			text：输入参数，文本值
 *		返回值：
 *			成功返回创建的文本节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newtext(NETCA_XML_DocPtr doc,NETCA_UString  text);

/*
 *		netca_xml_node_newns
 *			创建的命名空间节点
 *		参数：
 *			node：元素节点
 *			href：输入参数，命名空间URI
 *			prefix: 输入参数，命名空间前缀，可以为NULL
 *		返回值：
 *			成功返回创建的命名空间节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newns(NETCA_XML_NodePtr node,NETCA_UString href,NETCA_UString prefix);

/*
 *		netca_xml_node_setvalue
 *			设置节点node的值为data
 *		参数：
 *			node：节点
 *			data：输入参数，新值
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setvalue(NETCA_XML_NodePtr node,NETCA_UString  data);

/*
 *		netca_xml_node_setns
 *			设置节点node的相关的命名空间节点为ns
 *		参数：
 *			node：节点
 *			ns：命名空间节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setns(NETCA_XML_NodePtr node,NETCA_XML_NodePtr ns);

/*
 *		netca_xml_doc_new
 *			生成一个空的XML文档的根节点，这个根节点因为没有包括根元素节点因而还是不合法的XML文档。
 *		参数：
 *			version: 输入参数，NETCA_XML_VERISON_1_0 表示1.0版本，NETCA_XML_VERISON_1_1 表示1.1版本。
 *		返回值：
 *			成功返回空的XML文档的根节点，失败返回NULL
 */
NETCA_XML_DocPtr  NETCAAPI netca_xml_doc_new(int version);

/*
 *		netca_xml_node_newattr
 *			创建属性节点
 *		参数：
 *			node：元素节点
 *			ns：命名空间节点，如果属性没有命名空间则为NULL
 *			name：输入参数，属性名
 *			value：输入参数，属性值
 *		返回值：
 *			成功返回创建的属性节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newattr(NETCA_XML_NodePtr node,NETCA_XML_NodePtr ns,NETCA_UString name,NETCA_UString value);

/*
 *		netca_xml_node_newpi
 *			创建处理指令节点
 *		参数：
 *			doc：根节点
 *			name：输入参数，处理指令名
 *			content: 输入参数，处理指令内容
 *		返回值：
 *			成功返回创建的处理指令节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newpi(NETCA_XML_DocPtr doc,NETCA_UString name,NETCA_UString content);


/*
 *		netca_xml_node_newcomment
 *			创建注释节点
 *		参数：
 *			doc：XML文档的根节点
 *			content：输入参数，注释的内容
 *		返回值：
 *			成功返回创建的注释节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newcomment(NETCA_XML_DocPtr doc,NETCA_UString content);

/*
 *		netca_xml_node_remove
 *			把节点及其子节点从树中摘下来，但是没有释放它
 *		参数：
 *			node：节点
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_node_remove(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_free
 *			释放节点node及其子树
 *		参数：
 *			node：节点
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_node_free(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_newelem
 *			创建空的元素节点
 *		参数：
 *			ns：命名空间节点，如果元素没有命名空间则为NULL
 *			name：输入参数，元素名
 *		返回值：
 *			成功返回创建的元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_newelem(NETCA_XML_NodePtr ns,NETCA_UString name);

/*
 *		netca_xml_node_setdoc
 *			设置节点node的根节点为doc
 *		参数：
 *			node：节点
 *			doc：根节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setdoc(NETCA_XML_NodePtr node,NETCA_XML_DocPtr doc);

/*
 *		netca_xml_node_addchild
 *			把node节点加入parent节点的子节点列表的最后，不要释放子节点
 *		参数：
 *			parent：父元素节点
 *			node：元素节点、PI节点、注释节点或文本节点
 *		返回值：
 *			成功返回子节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addchild(NETCA_XML_NodePtr parent,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addnextsibling
 *			把node节点加入为node节点的下一个兄弟节点。注意node只能为一个节点
 *		参数：
 *			cur：元素节点或属性节点
 *			node：元素节点或属性节点
 *		返回值：
 *			成功返回最右的兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addnextsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addprevsibling
 *			把node节点加入为node节点的上一个兄弟节点。注意node只能为一个节点
 *		参数：
 *			cur：元素节点或属性节点
 *			node：元素节点或属性节点
 *		返回值：
 *			成功返回最左的兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addprevsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_addsibling
 *			把node节点加入为node节点的下一个兄弟节点。node可以是多个节点
 *		参数：
 *			cur：元素节点或属性节点
 *			node：元素节点或属性节点
 *		返回值：
 *			成功返回最右的兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_addsibling(NETCA_XML_NodePtr cur,NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_dup
 *			复制一个节点
 *		参数：
 *			node：元素节点或属性节点
 *		返回值：
 *			成功返回复制后的节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_dup(NETCA_XML_NodePtr node);

/*
 *		netca_xml_doc_setrootelement
 *			设置XML文档的根元素节点为root。成功后不要释放根元素节点
 *		参数：
 *			doc: 输入参数，XML文档的根节点
 *			root：要设置的根元素节点
 *		返回值：
 *			成功返回根元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_doc_setrootelement(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr root);

/*
 *		netca_xml_doc_save
 *			把XML文档保存为文件
 *		参数：
 *			doc: 输入参数，XML文档的根节点
 *			filename：输入参数，文件名
 *			flag：输入参数，如果置NETCA_XML_NOXMLDESC位则输出时，不包括XML声明，否则包括
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_doc_save(NETCA_XML_DocPtr doc,const char *filename,int flag);

/*
 *		netca_xml_doc_save_ex
 *			把XML文档保存为文件
 *		参数：
 *			doc: 输入参数，XML文档的根节点
 *			encoding：输入参数，字符编码
 *			filename：输入参数，文件名
 *			flag：输入参数，如果置NETCA_XML_NOXMLDESC位则输出时，不包括XML声明，否则包括
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_doc_save_ex(NETCA_XML_DocPtr doc,const char *encoding,const char *filename,int flag);

/*
 *		netca_xml_doc_dump
 *			把XML文档序列化到内存中
 *		参数：
 *			doc: 输入参数，XML文档的根节点
 *			flag：输入参数，如果置NETCA_XML_NOXMLDESC位则输出时，不包括XML声明，否则包括
 *		返回值：
 *			成功返回XML文档的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_doc_dump(NETCA_XML_DocPtr doc,int flag);

/*
 *		netca_xml_doc_dump_ex
 *			把XML文档序列化到内存中
 *		参数：
 *			doc: 输入参数，XML文档的根节点
 *			encoding：输入参数，字符编码
 *			flag：输入参数，如果置NETCA_XML_NOXMLDESC位则输出时，不包括XML声明，否则包括
 *		返回值：
 *			成功返回XML文档的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_doc_dump_ex(NETCA_XML_DocPtr doc,const char *encoding,int flag);

/*
 *		netca_xml_element_dump
 *			把XML元素序列化到内存中
 *		参数：
 *			elem: 输入参数，元素节点
 *		返回值：
 *			成功返回该元素的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_element_dump(NETCA_XML_NodePtr elem);

/*
 *		netca_xml_element_dump_ex
 *			把XML元素序列化到内存中
 *		参数：
 *			elem: 输入参数，元素节点
 *			encoding：输入参数，字符编码
 *		返回值：
 *			成功返回该元素的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_element_dump_ex(NETCA_XML_NodePtr elem,const char *encoding);

/*
 *		netca_xml_node_findelemnode
 *			在parent及其子树下搜索元素名为name，命名空间的URI的值为nsuri的元素节点
 *		参数：
 *			parent：输入参数，元素节点
 *			name：输入参数，元素名
 *			nsuri：输入参数，元素的命名空间的URI的值，没有命名空间取NULL
 *		返回值：
 *			成功返回返回符合条件的第一个元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_findelemnode(NETCA_XML_NodePtr parent,NETCA_UString name,NETCA_UString nsuri);	

/*
 *		netca_xml_node_match
 *			根据名称和命名空间的URI判断节点是否匹配
 *		参数：
 *			node：元素节点
 *			name：输入参数，名称
 *			nsuri：输入参数，命名空间的URI，如果没有命名空间输入NULL
 *		返回值：
 *			如果名称和命名空间的URI和节点的匹配，返回1，否则返回0
 */
int NETCAAPI netca_xml_node_match(NETCA_XML_NodePtr node,NETCA_UString name,NETCA_UString nsuri);

/*
 *		netca_xml_node_skipignorenode
 *			获取下一个兄弟节点，但是会跳过注释和空白。
 *		参数：
 *			node：节点
 *		返回值：
 *			成功返回下一个兄弟节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_skipignorenode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_getelemchildren
 *			获取子元素节点，会跳过前面的空白和注释。
 *		参数：
 *			node：父元素节点
 *		返回值：
 *			成功返回子元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_node_getelemchildren(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_setidattr
 *			设置属性节点attr的属性为ID属性
 *		参数：
 *			doc：根节点
 *			attr：属性节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_setidattr(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr attr);

/*
 *		netca_xml_node_findallelemnode
 *			在parent及其子树下搜索元素名为name，命名空间的URI的值为nsuri的元素节点，找到后加入list中
 *		参数：
 *			parent：输入参数，元素节点
 *			name：输入参数，元素名
 *			nsuri：输入参数，元素的命名空间的URI的值，没有命名空间取NULL
 *			list：输出参数，返回符合条件的元素节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_findallelemnode(NETCA_XML_NodePtr parent,NETCA_UString name,NETCA_UString nsuri,NETCA_ArrayList *list);

/*
 *		netca_xml_c14nnode
 *			对XML元素节点进行C14N规范化
 *		参数：
 *			node: 输入参数，XML文档的元素节点
 *			c14nAlgo：输入参数，C14N算法
 *			param：输入参数，C14N算法的参数
 *		返回值：
 *			成功返回规范化的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_c14nnode(NETCA_XML_NodePtr node,int c14nAlgo,void *param);

/*
 *		netca_xml_decode_signature
 *			解码Signature元素节点，转换为XML签名验证上下文
 *		参数：
 *			node: 输入参数，Signature元素节点
 *		返回值：
 *			成功返回有效的XML签名验证上下文，失败返回NULL
 */
NETCA_XML_Signature_VerifyCtx netca_xml_decode_signature(NETCA_XML_NodePtr node);

/*
 *		netca_xml_node_findsignature
 *			在parent及其子树下搜索元素名为Signature，命名空间的URI的值为http://www.w3.org/2000/09/xmldsig#的元素节点（也就是XML签名节点），找到后加入list中
 *		参数：
 *			parent：输入参数，元素节点
 *			list：输出参数，返回所有的Signature的元素节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_node_findsignature(NETCA_XML_NodePtr parent,NETCA_ArrayList *list);

/*
 *		netca_xml_signature_getsignalgothrim
 *			获取签名算法
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *			algo：输出参数，签名算法
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_getsignalgothrim(NETCA_XML_Signature_VerifyCtx ctx,int *algo);

/*
 *		netca_xml_free_signature
 *			释放XML签名验证上下文
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_free_signature(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_dup
 *			复制XML签名验证上下文
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *		返回值：
 *			成功返回复制后的XML签名验证上下文
 */
NETCA_XML_Signature_VerifyCtx netca_xml_signature_dup(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_key_free
 *			释放XML签名的密钥
 *		参数：
 *			key： XML签名的密钥
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_key_free(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_sethmackey
 *			设置HMAC的密钥
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			key：输入参数，密钥
 *			keylen：输入参数，key的字节数
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sethmackey(NETCA_XML_Signature_VerifyCtx ctx,const unsigned char *key,long keylen);

/*
 *		netca_xml_signature_sethdomainparam
 *			设置域参数，验证DSA时可能要用
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			p：输入参数，p
 *			q：输入参数，q
 *			g：输入参数，g
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sethdomainparam(NETCA_XML_Signature_VerifyCtx ctx,NETCA_BigInteger p,NETCA_BigInteger q,NETCA_BigInteger g);

/*
 *		netca_xml_signature_addcert
 *			添加证书到XML签名验证上下文，以帮助验证签名，cert最好是XML签名所用的那张证书
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			cert：输入参数，证书
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_addcert(NETCA_XML_Signature_VerifyCtx ctx,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_setbasepath
 *			设置基准路径
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			basepath：输入参数，基准路径
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_setbasepath(NETCA_XML_Signature_VerifyCtx ctx,NETCA_UString basepath);

/*
 *		netca_xml_signature_key_dup
 *			复制XML签名的密钥
 *		参数：
 *			key： XML签名的密钥
 *		返回值：
 *			成功返回复制得到的XML签名的密钥，失败返回NULL
 */
NETCA_XML_Signature_Key NETCAAPI netca_xml_signature_key_dup(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_key_newcert
 *			根据证书创建XML签名的密钥
 *		参数：
 *			cert： 证书
 *		返回值：
 *			成功返回包含证书的XML签名的密钥，否则返回NULL
 */
NETCA_XML_Signature_Key NETCAAPI netca_xml_signature_key_newcert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_key_getcert
 *			获取XML签名的密钥中的证书
 *		参数：
 *			key： XML签名的密钥
 *		返回值：
 *			如果XML签名的密钥使用的是证书，返回证书，否则返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_key_getcert(NETCA_XML_Signature_Key key);

/*
 *		netca_xml_signature_signaturevalidation
 *			验证XML签名本身，但是不验证引用
 *		参数：
 *			ctx： XML签名验证上下文
 *			verifykey：输出参数，返回签名的密钥
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_signaturevalidation(NETCA_XML_Signature_VerifyCtx ctx,NETCA_XML_Signature_Key *verifykey,int *reason);

/*
 *		netca_xml_signature_getid
 *			获取XML签名的Id
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回XML签名的Id，没有或者失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_getid(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_getsignaturevalueid
 *			获取XML签名的签名值的Id
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回XML签名的签名值的Id，没有或者失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_getsignaturevalueid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getqualifyingpropertiesid
 *			获取QualifyingProperties的ID属性。
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回Id值，没有或者失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getqualifyingpropertiesid(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_xades_getsignedpropertiesid
 *			获取SignedProperties的ID属性。
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回Id值，没有或者失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getsignedpropertiesid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getsignedsignaturepropertiesid
 *			获取SignedSignatureProperties的ID属性。
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回Id值，没有或者失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_xades_getsignedsignaturepropertiesid(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getsignaturetimestampcount
 *			获取XML签名的签名时间戳个数
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回签名时间戳个数，失败返回-1
 */
int NETCAAPI netca_xml_signature_xades_getsignaturetimestampcount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_verifysignaturetimestamp
 *			验证XML签名的签名时间戳
 *		参数：
 *			ctx： XML签名验证上下文
 *			index:输入参数，索引号
 *			cert:输入参数，时间戳证书，可以为NULL
 *			phTimeStamp：输出参数，返回的时间戳句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_verifysignaturetimestamp(NETCA_XML_Signature_VerifyCtx ctx,int index,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);


/*
 *		netca_xml_signature_xades_getcountersignaturecount
 *			获取XML签名的联署签名个数
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回联署签名个数，失败返回-1
 */
int NETCAAPI netca_xml_signature_xades_getcountersignaturecount(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_xades_verifycountersignature
 *			验证XML签名的联署签名
 *		参数：
 *			ctx： XML签名验证上下文
 *			index:输入参数，索引号
 *			cert:输入参数，可能的签名证书，可以为NULL
 *			signCert:输出参数，签名证书
 *			signNode：输出参数，返回联署签名的签名节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_verifycountersignature(NETCA_XML_Signature_VerifyCtx ctx,int index,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_CERTIFICATE_HANDLE *signCert,NETCA_XML_NodePtr* signNode);


/*
 *		netca_xml_signature_xades_getcompleterevocationrefscount
 *			获取XML签名的CompleteRevocationRefs的证书个数
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回CompleteRevocationRefs的证书个数，失败返回-1
 */
int NETCAAPI netca_xml_signature_xades_getcompleterevocationrefscount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getcompleterevocationref
 *			获取XML签名的CompleteRevocationRefs的第index个CertID
 *		参数：
 *			ctx： XML签名验证上下文
 *			index：输入参数，索引值
 *		返回值：
 *			成功返回相应的CertID，失败返回NULL
 */
NETCA_XAdES_CertID NETCAAPI netca_xml_signature_xades_getcompleterevocationref(NETCA_XML_Signature_VerifyCtx ctx,int index);

/*
 *		netca_xml_signature_xades_getcertificatevaluescount
 *			获取XML签名的CertificateValues的证书个数
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回CertificateValues的证书个数，失败返回-1
 */
int NETCAAPI netca_xml_signature_xades_getcertificatevaluescount(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_getcertificatevalues
 *			获取XML签名的CertificateValues的第index个证书
 *		参数：
 *			ctx： XML签名验证上下文
 *			index：输入参数，索引值
 *		返回值：
 *			成功返回证书句柄，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_xades_getcertificatevalue(NETCA_XML_Signature_VerifyCtx ctx,int index);

/*
 *		netca_xml_signature_xades_getsigningtime
 *			获取XML签名的签名时间属性，这个不是时间戳时间
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回签名时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_xml_signature_xades_getsigningtime(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_xades_hassigningcertificate
 *			判断XML签名是否签名证书属性
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			如果有签名证书属性返回，否则返回0
 */
int NETCAAPI netca_xml_signature_xades_hassigningcertificate(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_getsigncert
 *			获取签名证书
 *		参数：
 *			ctx： XML签名验证上下文
 *		返回值：
 *			成功返回签名证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_xml_signature_getsigncert(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_setid
 *			设置XML签名的ID属性，以便URI引用可以找到
 *		参数：
 *			doc： XML文档的根节点
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_setid(NETCA_XML_DocPtr doc);

/*
 *		netca_xml_getidelemnode
 *			获取ID属性所在的元素节点，不要释放它
 *		参数：
 *			doc： XML文档的根节点
 *			id：输入参数，ID属性的值
 *		返回值：
 *			成功返回包含ID属性所在的元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_getidelemnode(NETCA_XML_DocPtr doc,NETCA_UString id);

/*
 *		netca_xml_getidattribute
 *			获取ID属性节点，不要释放它
 *		参数：
 *			doc： XML文档的根节点
 *			id：输入参数，ID属性的值
 *		返回值：
 *			成功返回ID属性节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_getidattribute(NETCA_XML_DocPtr doc,NETCA_UString id);

/*
 *		netca_xml_signature_issignaturenode
 *			判断元素节点是否XML签名节点
 *		参数：
 *			node： 元素节点
 *		返回值：
 *			是XML签名节点返回1，不是返回0
 */
int NETCAAPI netca_xml_signature_issignaturenode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_gethmaclength
 *			获取HMAC的长度
 *		参数：
 *			ctx： XML签名验证上下文
 *			len：输出参数，成功返回HMAC的长度，以字节为单位
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_gethmaclength(NETCA_XML_Signature_VerifyCtx ctx,int *len);

/*
 *		netca_xml_signature_referencevalidation
 *			验证SignedInfo里的所有引用，但不验证Manifest里的引用
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			data：输入参数，引用的URI为空的时候引用的值，可以为NULL
 *			datalen：输入参数，data的字节数
 *			reason：输出参数，失败返回的原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_referencevalidation(NETCA_XML_Signature_VerifyCtx ctx,const unsigned char *data,long datalen,int *reason);
/*
 *		netca_xml_signature_referencevalidation_ex
 *			验证SignedInfo里的所有引用
 *		参数：
 *			ctx： 输入参数，XML签名验证上下文
 *			verifyflag：输入参数，验证标识
 *			data：输入参数，引用的URI为空的时候引用的值，可以为NULL
 *			datalen：输入参数，data的字节数
 *			reason：输出参数，失败返回的原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_referencevalidation_ex(NETCA_XML_Signature_VerifyCtx ctx,int verifyflag,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verifyref
 *			验证XML引用
 *		参数：
 *			refnode：输入参数，引用节点
 *			data：输入参数，无URI的引用的数据，可以为NULL
 *			datalen：输入参数，data的字节数
 *		reason：输出参数，失败返回失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verifyref(NETCA_XML_NodePtr refnode,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verifyref_ex
 *			验证XML引用
 *		参数：
 *			refnode：输入参数，引用节点
 *			verifyflag：输入参数，验证标志
 *			basepath：输入参数，基准路径
 *			data：输入参数，无URI的引用的数据，可以为NULL
 *			datalen：输入参数，data的字节数
 *		reason：输出参数，失败返回失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verifyref_ex(NETCA_XML_NodePtr refnode,int verifyflag,NETCA_UString basepath,const unsigned char *data,long datalen,int *reason);

/*
 *		netca_xml_signature_verify
 *			验证XML文档的所有签名（包括签名值和SignedInfo里的引用），但是不验证Manifest的引用
 *		参数：
 *			doc：输入参数，XML文档的根节点
 *			data：输入参数，无URI的引用的数据，可以为NULL
 *			datalen：输入参数，data的字节数
 *			verifykeys：输出参数，签名密钥列表，里面的元素是NETCA_XML_Signature_Key
 *			reason：输出参数，失败返回失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verify(NETCA_XML_DocPtr doc,const unsigned char *data,long datalen,NETCA_ArrayList *verifykeys,int *reason);

/*
 *		netca_xml_signature_verify_ex
 *			验证XML文档的所有签名（包括签名值和SignedInfo里的引用），但是不验证Manifest的引用
 *		参数：
 *			doc：输入参数，XML文档的根节点
 *			basepath：输入参数，基准路径
 *			data：输入参数，无URI的引用的数据，可以为NULL
 *			datalen：输入参数，data的字节数
 *			verifykeys：输出参数，签名密钥列表，里面的元素是NETCA_XML_Signature_Key
 *			reason：输出参数，失败返回失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_verify_ex(NETCA_XML_DocPtr doc,NETCA_UString basepath,const unsigned char *data,long datalen,NETCA_ArrayList *verifykeys,int *reason);

/*
 *		netca_xml_signature_getnode
 *			获取XML签名验证上下文对应的元素节点，也就是XML签名元素节点
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *		返回值：
 *			成功返回XML签名验证上下文对应的元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_signature_getnode(NETCA_XML_Signature_VerifyCtx ctx);

/*
 *		netca_xml_signature_getsignedinfo
 *			XML签名验证上下文转换为签名签名信息上下文
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *		返回值：
 *			成功返回签名信息上下文，失败返回NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_getsignedinfo(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_transformctx_new
 *			创建转换上下文
 *		参数：
 *			algoid：输入参数，转换算法
 *			param：输入参数，转换算法参数，可以为NULL
 *		返回值：
 *			成功返回创建的转换上下文，失败返回NULL
 */
NETCA_XML_Signature_TransformCtx NETCAAPI netca_xml_signature_transformctx_new(int algoid,void *param);

/*
 *		netca_xml_signature_transformctx_free
 *			释放转换上下文
 *		参数：
 *			ctx： 转换上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_transformctx_free(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_transformctx_dup
 *			复制转换上下文
 *		参数：
 *			ctx： 转换上下文
 *		返回值：
 *			成功返回复制的得到的转换上下文，失败返回NULL
 */
NETCA_XML_Signature_TransformCtx NETCAAPI netca_xml_signature_transformctx_dup(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_transformctx_getalgoid
 *			获得转换算法
 *		参数：
 *			ctx： 转换上下文
 *		返回值：
 *			成功返回转换算法，失败返回-1
 */
int NETCAAPI netca_xml_signature_transformctx_getalgoid(NETCA_XML_Signature_TransformCtx ctx);


/*
 *		netca_xml_signature_transformctx_getparam
 *			获得转换算法相关的参数
 *		参数：
 *			ctx： 转换上下文
 *		返回值：
 *			成功返回转换算法相关的参数，没有或者失败返回NULL
 */
void* NETCAAPI netca_xml_signature_transformctx_getparam(NETCA_XML_Signature_TransformCtx ctx);

/*
 *		netca_xml_signature_referencectx_new
 *			创建引用上下文
 *		参数：
 *			hashalgoid： 输入参数，Hash算法
 *			id：输入参数，引用的ID属性的值，为NULL表示没有ID属性
 *			uri：输入参数，引用的URI，为NULL时，data必须有值
 *			type：输入参数，引用的type属性的值，为NULL表示没有type属性
 *			data：输入参数，当uri为NULL时有效，这是包含引用的数据
 *			transforms：输入参数，转换列表，里面的元素是NETCA_XML_Signature_TransformCtx，可以为NULL
 *		返回值：
 *			成功返回创建的引用上下文，失败返回NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_new(int hashalgoid,NETCA_UString id,NETCA_UString uri,NETCA_UString type,
								     NETCA_Data_Blob data,NETCA_ArrayList transforms);

/*
 *		netca_xml_signature_referencectx_newwithhash
 *			创建引用上下文
 *		参数：
 *			hashalgoid： 输入参数，Hash算法
 *			hash：输入参数，Hash值
 *			id：输入参数，引用的ID属性的值，为NULL表示没有ID属性
 *			uri：输入参数，引用的URI，为NULL时，data必须有值
 *			type：输入参数，引用的type属性的值，为NULL表示没有type属性
 *			data：输入参数，当uri为NULL时有效，这是包含引用的数据
 *			transforms：输入参数，转换列表，里面的元素是NETCA_XML_Signature_TransformCtx，可以为NULL
 *		返回值：
 *			成功返回创建的引用上下文，失败返回NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_newwithhash(int hashalgoid,NETCA_Data_Blob hash,NETCA_UString id,NETCA_UString uri,
									NETCA_UString type,NETCA_ArrayList transforms);

/*
 *		netca_xml_signature_referencectx_free
 *			释放引用上下文
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_referencectx_free(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_dup
 *			复制引用上下文
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回复制得到的引用上下文，失败返回NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_dup(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gethashalgoid
 *			获得引用使用的Hash算法
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用使用的Hash算法，失败返回-1
 */
int NETCAAPI netca_xml_signature_referencectx_gethashalgoid(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gethashvalue
 *			获得引用的Hash值
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用使用的Hash值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_xml_signature_referencectx_gethashvalue(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_getid
 *			获得引用的ID属性
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用的ID属性的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_getid(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_geturi
 *			获得引用的URI
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用的URI，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_geturi(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gettype
 *			获得引用的Type
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用的Type，没有或失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_referencectx_gettype(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_signature_referencectx_gettransforms
 *			获得引用的转换列表
 *		参数：
 *			ctx： 输入参数，引用上下文
 *		返回值：
 *			成功返回引用的转换列表，没有返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_referencectx_gettransforms(NETCA_XML_Signature_ReferenceCtx ctx);

/*
 *		netca_xml_uri_encode
 *			URI编码
 *		参数：
 *			path： 输入参数，URI
 *		返回值：
 *			成功返回URI编码，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_uri_encode(NETCA_UString path);

/*
 *		netca_xml_signature_ismanifestnode
 *			判断元素节点是否Manifest节点
 *		参数：
 *			node： 输入参数，元素节点
 *		返回值：
 *			如果元素节点是Manifest节点返回1，否则返回0
 */
int NETCAAPI netca_xml_signature_ismanifestnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_decodemanifestnode
 *			解码Manifest节点
 *		参数：
 *			node：Manifest元素节点
 *		返回值：
 *			成功返回Manifest元素节点下的所有引用节点列表，失败返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_decodemanifestnode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_referencectx_decode
 *			根据引用节点构造引用上下文
 *		参数：
 *			node： 输入参数，引用节点
 *		返回值：
 *			成功返回引用上下文，失败返回NULL
 */
NETCA_XML_Signature_ReferenceCtx NETCAAPI netca_xml_signature_referencectx_decode(NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_getreflist
 *			获取SignedInfo元素里的引用节点列表，不包括Manifest元素的那些。
 *		参数：
 *			ctx：输入参数，XML签名验证上下文
 *		返回值：
 *			成功返回XML签名验证上下文的引用节点列表，失败返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_getreflist(NETCA_XML_Signature_VerifyCtx ctx);


/*
 *		netca_xml_signature_signedinfoctx_new
 *			创建签名信息上下文。
 *		参数：
 *			id： 输入参数，SignedInfo的ID属性的值，可以为NULL
 *			c14nalgoid：输入参数，规范化方法
 *			c14nparam：输入参数，规范化方法的参数，可以为NULL
 *			signalgoid：输入参数，签名算法
 *			refs：输入参数，引用列表，里面的元素是NETCA_XML_Signature_ReferenceCtx
 *		返回值：
 *			成功返回创建的签名信息上下文，失败返回NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_signedinfoctx_new(NETCA_UString id,int c14nalgoid,void *c14nparam,
										 int signalgoid,NETCA_ArrayList refs);



/*
 *		netca_xml_signature_signedinfoctx_setsignaturevalueid
 *			设置签名值的Id属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			id：输入参数，ID值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_setsignaturevalueid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);

/*
 *		netca_xml_signature_signedinfoctx_xades_setusesigningtime
 *			设置是否使用签名时间属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			value：输入参数，为真则表示使用签名时间属性，为假则不用
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setusesigningtime(NETCA_XML_Signature_SignedInfoCtx ctx,int value);

/*
 *		netca_xml_signature_signedinfoctx_xades_setqualifyingpropertiesid
 *			设置QualifyingProperties的ID属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			id： 输入参数，QualifyingProperties的ID属性的值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setqualifyingpropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignedpropertiesid
 *			设置SignedProperties的ID属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			id： 输入参数，SignedProperties的ID属性的值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignedpropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);

/*
 *		netca_xml_signature_signedinfoctx_xades_setsignedsignaturepropertiesid
 *			设置SignedSignatureProperties的ID属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			id： 输入参数，SignedSignatureProperties的ID属性的值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignedsignaturepropertiesid(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString id);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsigningcertificateinfo
 *			设置签名证书属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			hashalgoid:输入参数，Hash算法
 *			flag:输入参数，包含证书的选项
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsigningcertificateinfo(NETCA_XML_Signature_SignedInfoCtx ctx,int hashalgoid,int flag);

/*
 *		netca_xml_signature_signedinfoctx_setincludecertflag
 *			设置包含证书的选项。
 *		参数：
 *			ctx： 签名信息上下文
 *			flag:输入参数，包含证书的选项
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_setincludecertflag(NETCA_XML_Signature_SignedInfoCtx ctx,int flag);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignaturepolicyimplied
 *			设置使用隐式的签名策略。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignaturepolicyimplied(NETCA_XML_Signature_SignedInfoCtx ctx);


/*
 *		netca_xml_signature_signedinfoctx_xades_setsignatureproductionplace
 *			设置使用产地签名属性。
 *		参数：
 *			ctx： 签名信息上下文
 *			city:输入参数，城市
 *			province:输入参数，省份
 *			postalcode:输入参数，邮政编码
 *			countryname:输入参数，国家
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_xml_signature_signedinfoctx_xades_setsignatureproductionplace(NETCA_XML_Signature_SignedInfoCtx ctx,NETCA_UString city,NETCA_UString province,NETCA_UString postalcode,NETCA_UString countryname);

/*
 *		netca_xml_signature_signedinfoctx_free
 *			释放签名信息上下文。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_signedinfoctx_free(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_dup
 *			复制签名信息上下文。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回复制得到的签名信息上下文，失败返回NULL
 */
NETCA_XML_Signature_SignedInfoCtx NETCAAPI netca_xml_signature_signedinfoctx_dup(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getid
 *			获取规范化算法。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回SignedInfo节点的Id，失败或者没有返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_signedinfoctx_getid(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getc14nmethon
 *			获取规范化算法。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回规范化算法，失败返回-1
 */
int NETCAAPI netca_xml_signature_signedinfoctx_getc14nmethon(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getc14nparam
 *			获取规范化算法的参数。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回规范化算法参数，失败或没有返回NULL
 */
void* NETCAAPI netca_xml_signature_signedinfoctx_getc14nparam(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getsignalgoid
 *			获取签名算法。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回签名算法，失败返回-1
 */
int NETCAAPI netca_xml_signature_signedinfoctx_getsignalgoid(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_signedinfoctx_getrefs
 *			获得引用列表。
 *		参数：
 *			ctx： 签名信息上下文
 *		返回值：
 *			成功返回返回引用列表，失败返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_signedinfoctx_getrefs(NETCA_XML_Signature_SignedInfoCtx ctx);

/*
 *		netca_xml_signature_objectctx_newdata
 *			创建一个PCDATA的Object元素。
 *		参数：
 *			id： 输入参数，Object元素的ID属性的值，可以为NULL，表示没有该属性
 *			mimetype：输入参数，Object元素的mimetype属性的值，可以为NULL，表示没有该属性
 *			encoding：输入参数，Object元素的encoding属性的值，可以为NULL，表示没有该属性
 *			data：输入参数，Object元素的子文本节点的值
 *		返回值：
 *			成功返回创建的XML签名的Object上下文，失败返回NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newdata(NETCA_UString id,NETCA_UString mimetype,NETCA_UString encoding,NETCA_UString data);

/*
 *		netca_xml_signature_objectctx_free
 *			释放XML签名的Object上下文。
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_objectctx_free(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_dup
 *			复制XML签名的Object上下文。
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			成功返回复制得到的XML签名的Object上下文，失败返回NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_dup(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_newmanifest
 *			创建一个包含Manifest的Object元素
 *		参数：
 *			id： 输入参数，Manifest元素的ID属性的值，可以为NULL，表示没有该属性
 *			refs：输入参数，引用列表
 *		返回值：
 *			成功返回创建的XML签名的Object上下文，失败返回NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newmanifest(NETCA_UString id,NETCA_ArrayList refs);

/*
 *		netca_xml_signature_objectctx_getmanifest
 *			获取Manifest中的引用列表列表
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			XML签名的Object如果是Manifest列表，返回引用列表，否则返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_objectctx_getmanifest(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_getnode
 *			获取XML签名的Object元素节点
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			成功XML签名的Object元素节点，失败返回NULL
 */
NETCA_XML_NodePtr NETCAAPI netca_xml_signature_objectctx_getnode(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_gettype
 *			获取XML签名的Object的类型
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			成功XML签名的Object的类型，失败返回-1
 */
int NETCAAPI netca_xml_signature_objectctx_gettype(NETCA_XML_Signature_ObjectCtx ctx);

/*
 *		netca_xml_signature_objectctx_newnode
 *			根据节点创建XML签名的Object上下文
 *		参数：
 *			id：输入参数，ID
 *			node:输入参数，元素节点
 *		返回值：
 *			成功返回创建的XML签名的Object上下文，失败返回NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newnode(NETCA_UString id,NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_signaturepropctx_new
 *			创建XML签名的签名属性上下文
 *		参数：
 *			id：输入参数，ID
 *			target：输入参数，目标
 *			node:输入参数，元素节点
 *		返回值：
 *			成功返回创建的XML签名的签名属性上下文，失败返回NULL
 */
NETCA_XML_Signature_SignaturePropertyCtx NETCAAPI netca_xml_signature_signaturepropctx_new(NETCA_UString id,NETCA_UString target,NETCA_XML_NodePtr node);

/*
 *		netca_xml_signature_signaturepropctx_free
 *			释放XML签名的签名属性上下文
 *		参数：
 *			ctx：输入参数，XML签名的签名属性上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_signaturepropctx_free(NETCA_XML_Signature_SignaturePropertyCtx ctx);

/*
 *		netca_xml_signature_objectctx_newsignprops
 *			创建XML签名的签名属性列表的Object上下文
 *		参数：
 *			id：输入参数，ID
 *			signprops：输入参数，一组XML签名的签名属性上下文
 *		返回值：
 *			成功返回创建的XML签名的签名属性列表的Object上下文，失败返回NULL
 */
NETCA_XML_Signature_ObjectCtx NETCAAPI netca_xml_signature_objectctx_newsignprops(NETCA_UString id,NETCA_ArrayList signprops);

/*
 *		netca_xml_signature_objectctx_getsignatureprops
 *			获取XML签名的签名属性上下文列表
 *		参数：
 *			ctx： XML签名的Object上下文
 *		返回值：
 *			成功返回XML签名的签名属性上下文列表，失败返回NULL
 */
NETCA_ArrayList NETCAAPI netca_xml_signature_objectctx_getsignatureprops(NETCA_XML_Signature_ObjectCtx ctx);


/*
 *		netca_xml_signature_sign
 *			进行XML签名，doc、parent和leftsibing决定了XML签名元素插入的位置
 *		参数：
 *			doc： XML文档的根节点，可以为NULL，这时表示XML签名元素就是XML文档的根元素
 *			parent：XML签名元素的父元素节点
 *			leftsibing：XML签名元素左边的兄弟节点，如果为NULL，则表示XML签名元素是parent元素的第一个子节点
 *			id：输入参数，XML签名元素的ID属性的值，如果为NULL，则表示没有ID属性
 *			signedinfo：输入参数，要签名的签名信息上下文
 *			objs：输入参数，XML签名的Object上下文列表，可以为NULL,里面的元素为NETCA_XML_Signature_ObjectCtx
 *			cert：输入参数，签名私钥对应的证书
 *			pwd：输入参数，使用签名私钥需要的密码，可以为NULL
 *			signnode：输出参数，产生的XML签名元素
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sign(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent,NETCA_XML_NodePtr leftsibing,
					NETCA_UString id,NETCA_XML_Signature_SignedInfoCtx signedinfo,NETCA_ArrayList objs,
					NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,
					NETCA_XML_NodePtr *signnode,int *reason);

/*
 *		netca_xml_signature_signex
 *			进行XML签名，doc、parent和leftsibing决定了XML签名元素插入的位置
 *		参数：
 *			doc： XML文档的根节点，可以为NULL，这时表示XML签名元素就是XML文档的根元素
 *			parent：XML签名元素的父元素节点
 *			leftsibing：XML签名元素左边的兄弟节点，如果为NULL，则表示XML签名元素是parent元素的第一个子节点
 *			id：输入参数，XML签名元素的ID属性的值，如果为NULL，则表示没有ID属性
 *			signedinfo：输入参数，要签名的签名信息上下文
 *			objs：输入参数，XML签名的Object上下文列表，可以为NULL,里面的元素为NETCA_XML_Signature_ObjectCtx
 *			key：输入参数，签名的密钥信息，通常包含签名证书
 *			privkey：输入参数，签名私钥
 *			checkkey：输入参数，为真表示校验私钥，为假不校验
 *			certs：输入参数，其他相关的证书
 *			basepath：输入参数，基准路径
 *			signnode：输出参数，产生的XML签名元素
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_signex(NETCA_XML_DocPtr doc,NETCA_XML_NodePtr parent,NETCA_XML_NodePtr leftsibing,
					NETCA_UString id,NETCA_XML_Signature_SignedInfoCtx signedinfo,NETCA_ArrayList objs,
					NETCA_XML_Signature_Key key,NETCA_PKI_KEYPAIR_HANDLE privkey,int checkkey,NETCA_ArrayList certs,
					NETCA_UString basepath,NETCA_XML_NodePtr *signnode,int *reason);


/*
 *		netca_xml_signature_xades_addsignaturetimestamp
 *			对XML签名追加时间戳，作为SignatureTimeStamp属性
 *		参数：
 *			signNode：签名元素节点
 *			id：输入参数，SignatureTimeStamp属性的ID属性的值，如果为NULL，则表示没有ID属性
 *			c14nAlgoid：输入参数，规范化算法。-1表示编码中不带规范化算法
 *			param：输入参数，规范化算法参数
 *			tsaurl：输入参数，时间戳服务器的URL
 *			hashAlgo：输入参数，使用的签名算法
 *			phTimeStamp：输出参数，成功返回时间戳句柄。如果为NULL，则不返回
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addsignaturetimestamp(NETCA_XML_NodePtr signNode,NETCA_UString id,int c14nAlgoid,void *param,const char *tsaurl,int hashAlgo,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp,int *reason);


/*
 *		netca_xml_signature_xades_addcompletecertificaterefs
 *			对XML签名追加CompleteCertificateRefs属性
 *		参数：
 *			signNode：签名元素节点
 *			id：输入参数，CompleteCertificateRefs属性的ID属性的值，如果为NULL，则表示没有ID属性
 *			hashAlgo:输入参数，Hash算法
 *			cert:输入参数，签名证书
 *			reserve：输入参数，保留参数，为NULL
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addcompletecertificaterefs(NETCA_XML_NodePtr signNode,NETCA_UString id,int hashAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert,void *reserve);

/*
 *		netca_xml_signature_xades_add_completerevocationrefs_crl
 *			对XML签名追加CompleteRevocationRefs属性，加入CRL
 *		参数：
 *			signNode：签名元素节点
 *			hashAlgo:输入参数，Hash算法
 *			flag：输入参数，使用CRLIdentifier的标识
 *			crl:输入参数，CRL的编码
 *			crlLen:输入参数，CRL的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_add_completerevocationrefs_crl(NETCA_XML_NodePtr signNode,int hashAlgo,int flag,const unsigned char *crl,int crlLen);

/*
 *		netca_xml_signature_xades_set_completerevocationrefs_id
 *			对XML签名的CompleteRevocationRefs属性，设置ID属性
 *		参数：
 *			signNode：签名元素节点
 *			id:输入参数，ID值
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_completerevocationrefs_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_xades_addcertificatevalues
 *			对XML签名追加CertificateValues属性，加入证书
 *		参数：
 *			signNode：签名元素节点
 *			cert:证书
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_addcertificatevalues(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_xades_set_certificatevalues_id
 *			对XML签名的CertificateValues属性，设置ID属性
 *		参数：
 *			signNode：签名元素节点
 *			id:输入参数，ID值
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_certificatevalues_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_xades_add_revocationvalues_crl
 *			对XML签名追加RevocationValues属性，加入CRL
 *		参数：
 *			signNode：签名元素节点
 *			crl:输入参数，CRL编码
 *			crlLen:输入参数，CRL长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_add_revocationvalues_crl(NETCA_XML_NodePtr signNode,const unsigned char *crl,int crlLen);

/*
 *		netca_xml_signature_xades_set_revocationvalues_id
 *			对XML签名的RevocationValues属性，设置ID属性
 *		参数：
 *			signNode：签名元素节点
 *			id:输入参数，ID值
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_set_revocationvalues_id(NETCA_XML_NodePtr signNode,NETCA_UString id);


/*
 *		netca_xml_signature_sign_ex
 *			进行XML签名
 *		参数：
 *			signNode： XML签名的节点，这个是要代替的签名节点
 *			signCert：输入参数，签名证书
 *			param：输入参数，签名的相关参数
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_sign_ex(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE signCert,NETCA_JSON param,int *reason);

/*
 *		netca_xml_signature_countersign
 *			进行XML签名的联署签名
 *		参数：
 *			signNode： XML签名的节点，这个是要进行联署签名的签名节点
 *			signCert：输入参数，签名证书
 *			hashAlgo：输入参数，引用使用的Hash算法
 *			counterSignId：输入参数，CountSign的ds:Signature节点的Id，可以为NULL
 *			param：输入参数，签名的相关参数
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_countersign(NETCA_XML_NodePtr signNode,NETCA_PKI_CERTIFICATE_HANDLE signCert,int hashAlgo,NETCA_UString counterSignId,NETCA_JSON param,NETCA_XML_NodePtr* counterSignNode,int *reason);

/*
 *		netca_xml_signature_calref
 *			计算引用节点的引用值
 *		参数：
 *			refnode： 引用节点
 *			flag：输入参数，解引用标志
 *			basepath：输入参数，基准路径
 *			reason：输出参数，失败返回的失败原因
 *		返回值：
 *			成功返回引用的Hash值的Base64编码，失败返回NULL
 */
NETCA_UString NETCAAPI netca_xml_signature_calref(NETCA_XML_NodePtr refnode,int flag,NETCA_UString basepath,int *reason);

/*
 *		netca_xml_signature_xades_certid_free
 *			释放CertID
 *		参数：
 *			certId： CertID句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_xml_signature_xades_certid_free(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_matchcert
 *			判断CertID和证书是否匹配
 *		参数：
 *			certId： CertID句柄
 *			cert：证书句柄
 *		返回值：
 *			匹配返回1，不匹配返回0
 */
int NETCAAPI netca_xml_signature_xades_certid_matchcert(NETCA_XAdES_CertID certId,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		netca_xml_signature_xades_certid_getcerthashalgo
 *			获取CertID的Hash算法
 *		参数：
 *			certId： CertID句柄
 *		返回值：
 *			成功返回证书的Hash算法，失败返回-1
 */
int NETCAAPI netca_xml_signature_xades_certid_getcerthashalgo(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_getcerthashvalue
 *			获取CertID的证书的Hash值
 *		参数：
 *			certId： CertID句柄
 *			hash：输出参数，成功返回Hash值
 *			hashLen:输出参数，成功返回Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_xml_signature_xades_certid_getcerthashvalue(NETCA_XAdES_CertID certId,unsigned char **hash,int *hashLen);

/*
 *		netca_xml_signature_xades_certid_getissuer
 *			获取CertID的证书的颁发者
 *		参数：
 *			certId： CertID句柄
 *		返回值：
 *			成功返回证书的颁发者，失败返回NULL
 */
char* NETCAAPI netca_xml_signature_xades_certid_getissuer(NETCA_XAdES_CertID certId);

/*
 *		netca_xml_signature_xades_certid_getsn
 *			获取CertID的证书的序列号
 *		参数：
 *			certId： CertID句柄
 *		返回值：
 *			成功返回证书的序列号，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_xml_signature_xades_certid_getsn(NETCA_XAdES_CertID certId);

#ifdef __cplusplus
}
#endif
#endif
