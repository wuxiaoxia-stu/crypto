#ifndef NETCA_CERT_INLCUDE_H
#define NETCA_CERT_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"
#include "NETCA_UString.h"
#include "NETCA_Error.h"
#include "NETCA_Time.h"
#include "NETCA_Crypto.h"

#ifdef __cplusplus
extern "C"
	{
#endif

enum{
	NETCA_CERT_V1=0,
	NETCA_CERT_V2=1,
	NETCA_CERT_V3=2,
};

#define NETCA_ATTRIBUTE_STRING_TYPE_PRINTABLESTRING		1
#define NETCA_ATTRIBUTE_STRING_TYPE_IA5STRING			2
#define NETCA_ATTRIBUTE_STRING_TYPE_BMPSTRING			4
#define NETCA_ATTRIBUTE_STRING_TYPE_UTF8STRING			8


#define NETCA_DN_LDAP_FLAG_XMLSIG			1

/*
 *		netca_cert_new
 *			创建一个证书对象
 *		参数：
 *			data：输入参数，证书的编码值
 *			datalen：输入参数，data的长度
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的证书对象，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_cert_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);

/*
 *		netca_cert_free
 *			释放证书对象
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_free(NETCA_CERT cert);

/*
 *		netca_cert_dup
 *			复制证书对象
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回复制的证书对象，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_cert_dup(NETCA_CERT cert);

/*
 *		netca_cert_encode
 *			获取证书对象的DER编码
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的DER编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_encode(NETCA_CERT cert);

/*
 *		netca_cert_cmp
 *			比较证书
 *		参数：
 *			cert1：证书对象1
 *			cert2：证书对象2
 *		返回值：
 *			如果cert1>cert2返回1，否则cert1<cert2返回-1，如果两者编码相等返回0
 */
int NETCAAPI netca_cert_cmp(NETCA_CERT cert1,NETCA_CERT cert2);

/*
 *		netca_cert_getversion
 *			获取证书的版本号
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的版本号，失败返回-1
 */
int NETCAAPI netca_cert_getversion(NETCA_CERT cert);

/*
 *		netca_cert_getserialnumber
 *			获取证书的序列号
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的序列号，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_getserialnumber(NETCA_CERT cert);

/*
 *		netca_cert_getsignalgorithm
 *			获取证书的签名算法
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getsignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getinnersignalgorithm
 *			获取证书的内层的签名算法
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的内层的签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getinnersignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getoutersignalgorithm
 *			获取证书的外层的签名算法
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的外层的签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getoutersignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getissuer
 *			获取证书的颁发者
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的颁发者，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_getissuer(NETCA_CERT cert);

/*
 *		netca_cert_getsubject
 *			获取证书的主体
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的主体，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_getsubject(NETCA_CERT cert);

/*
 *		netca_cert_getvaliditystart
 *			获取证书的有效期开始时间
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的有效期开始时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_cert_getvaliditystart(NETCA_CERT cert);

/*
 *		netca_cert_getvalidityend
 *			获取证书的有效期结束时间
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的有效期结束时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_cert_getvalidityend(NETCA_CERT cert);

/*
 *		netca_cert_getpubkeyalgorithm
 *			获取证书的公钥算法
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的公钥算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getpubkeyalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getpubkey
 *			获取证书的公钥
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的公钥，失败返回NULL
 */
NETCA_CERT_PubKey NETCAAPI netca_cert_getpubkey(NETCA_CERT cert);

/*
 *		netca_cert_hasissueruid
 *			判断证书的是否有颁发者唯一ID
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			如果证书有颁发者唯一ID返回1，否则返回0
 */
int NETCAAPI netca_cert_hasissueruid(NETCA_CERT cert);

/*
 *		netca_cert_getissueruid
 *			获取证书的颁发者唯一ID
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的颁发者唯一ID，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_cert_getissueruid(NETCA_CERT cert);

/*
 *		netca_cert_hassubjectuid
 *			判断证书的是否有主体唯一ID
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			如果证书有主体唯一ID返回1，否则返回0
 */
int NETCAAPI netca_cert_hassubjectuid(NETCA_CERT cert);

/*
 *		netca_cert_getsubjectuid
 *			获取证书的主体唯一ID
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的主体唯一ID，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_cert_getsubjectuid(NETCA_CERT cert);

/*
 *		netca_cert_hasexts
 *			判断证书的是否有扩展
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			如果证书有扩展返回1，否则返回0
 */
int NETCAAPI netca_cert_hasexts(NETCA_CERT cert);

/*
 *		netca_cert_getexts
 *			获取证书的扩展
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的扩展，失败返回NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_cert_getexts(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalue
 *			获取证书的签名值
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的签名值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_getsignvalue(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalueunusedbits
 *			获取证书的签名值的未使用位数
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的签名值的未使用位数，失败返回-1
 */
int NETCAAPI netca_cert_getsignvalueunusedbits(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalue
 *			获取证书的要签名部分的编码
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的要签名部分的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_gettbs(NETCA_CERT cert);

/*
 *		netca_cert_isinvalidity
 *			判断证书是否在有效期内
 *		参数：
 *			cert：证书对象
 *			t：时间
 *		返回值：
 *			如果在时间点t，证书在有效期内返回1，否则返回0
 */
int NETCAAPI netca_cert_isinvalidity(NETCA_CERT cert,NETCA_Time t);

/*
 *		netca_cert_getsubjectdisplayname
 *			获取证书的主体的显示名
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的主体的显示名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_getsubjectdisplayname(NETCA_CERT cert);

/*
 *		netca_cert_getissuerdisplayname
 *			获取证书的颁发者的显示名
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			成功返回证书的颁发者的显示名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_getissuerdisplayname(NETCA_CERT cert);

/*
 *		netca_cert_algorithmid_free
 *			释放算法
 *		参数：
 *			cert：证书对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_algorithmid_free(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_dup
 *			复制算法
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回复制的算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_algorithmid_dup(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getoid
 *			获取算法的OID，使用NETCA_FREE来释放
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回算法的OID，失败返回NULL
 */
char *NETCAAPI netca_cert_algorithmid_getoid(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_hasparams
 *			判断算法是否有参数
 *		参数：
 *			algo：算法
 *		返回值：
 *			如果算法有参数返回1，否则返回0
 */
int NETCAAPI netca_cert_algorithmid_hasparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_hasnullparam
 *			判断算法是否有NULL参数
 *		参数：
 *			algo：算法
 *		返回值：
 *			如果算法有NULL参数返回1，否则返回0
 */
int NETCAAPI netca_cert_algorithmid_hasnullparam(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getparamsencode
 *			获取算法的参数编码
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回算法的参数编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_algorithmid_getparamsencode(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getdssparams
 *			获取算法的的DSS参数，要算法参数是DSS参数才能成功
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回算法的DSS参数，失败返回NULL
 */
NETCA_CERT_DssParms NETCAAPI netca_cert_algorithmid_getdssparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getoaepparams
 *			获取算法的的OAEP参数，要算法参数是OAEP参数才能成功
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回算法的OAEP参数，失败返回NULL
 */
struct NETCA_RSA_PARAM_PKCS1_OAEP_st* NETCAAPI netca_cert_algorithmid_getoaepparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getpssparams
 *			获取算法的的PSS参数，要算法参数是PSS参数才能成功
 *		参数：
 *			algo：算法
 *		返回值：
 *			成功返回算法的PSS参数，失败返回NULL
 */
struct NETCA_RSA_PARAM_PKCS1_PSS_st* NETCAAPI netca_cert_algorithmid_getpssparams(NETCA_CERT_AlgorithmIdentifier algo);


/*
 *		netca_cert_dn_dup
 *			复制DN
 *		参数：
 *			dn：DN
 *		返回值：
 *			成功返回复制的DN，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_dup(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_free
 *			释放DN
 *		参数：
 *			dn：DN
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_dn_free(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getitemcount
 *			获取DN的RDN个数
 *		参数：
 *			dn：DN
 *		返回值：
 *			成功返回DN的RDN个数，失败返回-1
 */
int NETCAAPI netca_cert_dn_getitemcount(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getitem
 *			获取DN的RDN
 *		参数：
 *			dn：DN
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回DN的第index个RDN，失败返回NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_dn_getitem(NETCA_CERT_X500_DN dn,int index);

/*
 *		netca_cert_dn_equals
 *			判断两个DN是否相等
 *		参数：
 *			dn1：DN1
 *			dn2：DN2
 *		返回值：
 *			如果DN相等返回1，否则返回0
 */
int NETCAAPI netca_cert_dn_equals(NETCA_CERT_X500_DN dn1,NETCA_CERT_X500_DN dn2);

/*
 *		netca_cert_dn_getdisplayname
 *			获取DN的显示名
 *		参数：
 *			dn：DN
 *		返回值：
 *			成功返回DN的显示名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_dn_getdisplayname(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getldapstring
 *			获取DN的LDAP字符串表示
 *		参数：
 *			dn：DN
 *		返回值：
 *			成功返回DN的LDAP字符串表示，失败返回NULL
 */
char *NETCAAPI netca_cert_dn_getldapstring(int flag,NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_matchldapstring
 *			判断DN和LDAP字符串表示是否匹配
 *		参数：
 *			dn：DN
 *			str：输入参数，LDAP字符串表示
 *		返回值：
 *			如果匹配返回1，否则返回0
 */
int NETCAAPI netca_cert_dn_matchldapstring(NETCA_CERT_X500_DN dn,const char *str);


/*
 *		netca_cert_dn_empty
 *			创建一个空的DN
 *		参数：
 *			dn：DN
 *		返回值：
 *			成功返回空的DN，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_empty(void);

/*
 *		netca_cert_dn_add
 *			在DN的末尾插入一个RDN
 *		参数：
 *			dn：DN
 *			rdn：RDN
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_cert_dn_add(NETCA_CERT_X500_DN dn,NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_dup
 *			复制RDN
 *		参数：
 *			rdn：RDN
 *		返回值：
 *			成功返回复制的RDN，失败返回NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_rdn_dup(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_free
 *			释放RDN
 *		参数：
 *			rdn：RDN
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_rdn_free(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_getitemcount
 *			获取RDN的属性数
 *		参数：
 *			rdn：RDN
 *		返回值：
 *			成功返回RDN的属性数，失败返回-1
 */
int NETCAAPI netca_cert_rdn_getitemcount(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_getitem
 *			获取RDN的属性
 *		参数：
 *			rdn：RDN
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回RDN的第index个属性，失败返回NULL
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_rdn_getitem(NETCA_CERT_X500_RDN rdn,int index);

/*
 *		netca_cert_rdn_new
 *			创建一个只包含一个属性的RDN
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回RDN，失败返回NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_rdn_new(NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_rdn_add
 *			在RDN中添加一个属性
 *		参数：
 *			rdn：RDN
 *			attr：属性
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_cert_rdn_add(NETCA_CERT_X500_RDN rdn,NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_attrtypeandvalue_dup
 *			复制属性
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回复制的属性，失败返回NULL
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_attrtypeandvalue_dup(NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_attrtypeandvalue_free
 *			释放属性
 *		参数：
 *			attr_value：属性
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_attrtypeandvalue_free(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_gettype
 *			获取属性的OID，使用NETCA_FREE来释放
 *		参数：
 *			attr_value：属性
 *		返回值：
 *			成功返回属性的OID，失败返回NULL
 */
char * NETCAAPI netca_cert_attrtypeandvalue_gettype(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getstring
 *			获取属性值的字符串表示
 *		参数：
 *			attr_value：属性
 *		返回值：
 *			成功返回属性值的字符串表示，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_attrtypeandvalue_getstring(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getvalencode
 *			获取属性值的编码
 *		参数：
 *			attr_value：属性
 *		返回值：
 *			成功返回属性值的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_attrtypeandvalue_getvalencode(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getstrtype
 *			获取属性值的字符串类型
 *		参数：
 *			attr_value：属性
 *			strtype：输出参数，返回属性值的字符串类型
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_cert_attrtypeandvalue_getstrtype(NETCA_CERT_AttributeTypeAndValue attr_value,int *strtype);

/*
 *		netca_cert_attrtypeandvalue_newstring
 *			创建一个属性
 *		参数：
 *			type：属性类型OID
 *			strmask：输入参数，属性值的字符串类型
 *			value：属性值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_attrtypeandvalue_newstring(const char *type,int strmask,NETCA_UString value);

/*
 *		netca_cert_pubkey_dup
 *			复制公钥
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			成功返回复制的公钥，失败返回NULL
 */
NETCA_CERT_PubKey NETCAAPI netca_cert_pubkey_dup(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_free
 *			释放公钥
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_pubkey_free(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_toeccpubkey
 *			公钥转换为ECC公钥
 *		参数：
 *			algo：公钥算法
 *			pubkey：公钥
 *		返回值：
 *			成功返回ECC公钥，失败返回NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_cert_pubkey_toeccpubkey(NETCA_CERT_AlgorithmIdentifier algo,NETCA_CERT_PubKey pubkey);
/*
 *		netca_cert_pubkey_torsapubkey
 *			公钥转换为RSA公钥
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			成功返回RSA公钥，失败返回NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_cert_pubkey_torsapubkey(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_getencode
 *			获取公钥编码
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			成功返回公钥编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_pubkey_getencode(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_getunusedbits
 *			获取公钥的未使用位数
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			成功返回公钥的未使用位数，失败返回-1
 */
int NETCAAPI netca_cert_pubkey_getunusedbits(NETCA_CERT_PubKey pubkey);


/*
 *		netca_cert_pubkey_todsapubkey
 *			公钥转换为DSA公钥
 *		参数：
 *			pubkey：公钥
 *		返回值：
 *			成功返回DSA公钥，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_pubkey_todsapubkey(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_dssparams_free
 *			释放DSS参数
 *		参数：
 *			params：DSS参数
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_dssparams_free(NETCA_CERT_DssParms params);

/*
 *		netca_cert_dssparams_getp
 *			获取DSS参数的p
 *		参数：
 *			params：DSS参数
 *		返回值：
 *			成功返回DSS参数的p，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getp(NETCA_CERT_DssParms params);

/*
 *		netca_cert_dssparams_getq
 *			获取DSS参数的q
 *		参数：
 *			params：DSS参数
 *		返回值：
 *			成功返回DSS参数的q，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getq(NETCA_CERT_DssParms params);
/*
 *		netca_cert_dssparams_getg
 *			获取DSS参数的g
 *		参数：
 *			params：DSS参数
 *		返回值：
 *			成功返回DSS参数的g，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getg(NETCA_CERT_DssParms params);

/*
 *		netca_cert_exts_dup
 *			复制扩展集
 *		参数：
 *			exts：扩展集
 *		返回值：
 *			成功返回复制的扩展集，失败返回NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_cert_exts_dup(NETCA_CERT_Extensions exts);
/*
 *		netca_cert_exts_free
 *			释放扩展集
 *		参数：
 *			exts：扩展集
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_exts_free(NETCA_CERT_Extensions exts);

/*
 *		netca_cert_exts_getitemcount
 *			获取扩展集的扩展个数
 *		参数：
 *			exts：扩展集
 *		返回值：
 *			成功返回扩展集的扩展个数，失败返回-1
 */
int NETCAAPI netca_cert_exts_getitemcount(NETCA_CERT_Extensions exts);
/*
 *		netca_cert_exts_getitem
 *			获取扩展集的扩展
 *		参数：
 *			exts：扩展集
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回扩展集的第index个扩展，失败返回NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_exts_getitem(NETCA_CERT_Extensions exts,int index);
/*
 *		netca_cert_exts_find
 *			根据扩展OID，寻找扩展值
 *		参数：
 *			exts：扩展集
 *			oid：输入参数，索引值，扩展OID
 *		返回值：
 *			成功返回OID为oid的扩展，失败返回NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_exts_find(NETCA_CERT_Extensions exts,const char *oid);

/*
 *		netca_cert_ext_free
 *			释放扩展
 *		参数：
 *			ext：扩展
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_ext_free(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_dup
 *			复制扩展
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回复制的扩展，失败返回NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_ext_dup(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_getextid
 *			获取扩展的OID
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的OID，失败返回NULL
 */
char * NETCAAPI netca_cert_ext_getextid(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_iscrical
 *			判断扩展是否关键扩展
 *		参数：
 *			ext：扩展
 *		返回值：
 *			如果扩展是否关键扩展返回1，否则返回0
 */
int NETCAAPI netca_cert_ext_iscrical(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_getvalue
 *			获取扩展的编码值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的编码值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_ext_getvalue(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tooctetstring
 *			获取扩展的OCTET STRING的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的OCTET STRING的值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI  netca_cert_ext_tooctetstring(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tobitstring
 *			获取扩展的BIT STRING的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的BIT STRING的值，失败返回NULL
 */
NETCA_BitSet NETCAAPI  netca_cert_ext_tobitstring(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_togeneralnames
 *			获取扩展的GeneralNames的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的GeneralNames的值，失败返回NULL
 */
NETCA_CERT_GeneralNames  NETCAAPI netca_cert_ext_togeneralnames(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_toakid
 *			获取扩展的AKID的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的AKID的值，失败返回NULL
 */
NETCA_CERT_AKID  NETCAAPI netca_cert_ext_toakid(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tointeger
 *			获取扩展的整数的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回扩展的整数的值，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_ext_tointeger(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tonull
 *			获取扩展的NULL的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回非NULL，不用释放，失败返回NULL
 */
void * NETCAAPI netca_cert_ext_tonull(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toenum
 *			获取扩展的枚举的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回枚举的值，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_ext_toenum(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_topolicymappings
 *			获取扩展的PolicyMappings的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回PolicyMappings的值，失败返回NULL
 */
NETCA_CERT_PolicyMappings NETCAAPI netca_cert_ext_topolicymappings(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toattrs
 *			获取扩展的Attributes的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回Attributes的值，失败返回NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_ext_toattrs(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tobasicconstraints
 *			获取扩展的BasicConstraints的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回BasicConstraints的值，失败返回NULL
 */
NETCA_CERT_BasicConstraints NETCAAPI netca_cert_ext_tobasicconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tonameconstraints
 *			获取扩展的NameConstraints的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回NameConstraints的值，失败返回NULL
 */
NETCA_CERT_NameConstraints NETCAAPI netca_cert_ext_tonameconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_topolicyconstraints
 *			获取扩展的PolicyConstraints的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回PolicyConstraints的值，失败返回NULL
 */
NETCA_CERT_PolicyConstraints NETCAAPI netca_cert_ext_topolicyconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toextkeyusage
 *			获取扩展的ExtKeyUsage的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回ExtKeyUsage的值，失败返回NULL
 */
NETCA_CERT_ExtKeyUsage NETCAAPI netca_cert_ext_toextkeyusage(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tocrldp
 *			获取扩展的CRLDistributionPoints的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回CRLDistributionPoints的值，失败返回NULL
 */
NETCA_CERT_CRLDistributionPoints NETCAAPI netca_cert_ext_tocrldp(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toaccessdescs
 *			获取扩展的AccessDescriptions的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回AccessDescriptions的值，失败返回NULL
 */
NETCA_CERT_AccessDescriptions NETCAAPI netca_cert_ext_toaccessdescs(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_togeneralizedtime
 *			获取扩展的GeneralizationTime的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回GeneralizationTime的值，失败返回NULL
 */
NETCA_Time NETCAAPI netca_cert_ext_togeneralizedtime(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toidp
 *			获取扩展的IssuingDistributionPoint的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回IssuingDistributionPoint的值，失败返回NULL
 */
NETCA_CERT_IssuingDistributionPoint NETCAAPI netca_cert_ext_toidp(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tooid
 *			获取扩展值的OID的值，扩展值必须是OID编码
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回OID的值，失败返回NULL
 */
char *netca_cert_ext_tooid(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toprivkeyusageperiod
 *			获取扩展值的PrivateKeyUsagePeriod的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回PrivateKeyUsagePeriod的值，失败返回NULL
 */
NETCA_CERT_PrivateKeyUsagePeriod NETCAAPI netca_cert_ext_toprivkeyusageperiod(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tocertpolicies
 *			获取扩展值的CertificatePolicies的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回CertificatePolicies的值，失败返回NULL
 */
NETCA_CERT_CertificatePolicies NETCAAPI netca_cert_ext_tocertpolicies(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_todigestinfolist
 *			获取扩展值的DigestInfoList的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回DigestInfoList的值，失败返回NULL
 */
NETCA_CERT_DigestInfoList NETCAAPI netca_cert_ext_todigestinfolist(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toutf8string
 *			获取扩展值的UTF8String的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回UTF8String的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toutf8string(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toia5string
 *			获取扩展值的IA5String的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回IA5String的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toia5string(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toprintablestring
 *			获取扩展值的PrintableString的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回PrintableString的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toprintablestring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tovisiblestring
 *			获取扩展值的VisibleString的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回VisibleString的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_tovisiblestring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tobmpstring
 *			获取扩展值的BMPString的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回BMPString的值，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_tobmpstring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toidentificationitems
 *			获取扩展值的IdentificationItems的值
 *		参数：
 *			ext：扩展
 *		返回值：
 *			成功返回IdentificationItems的值，失败返回NULL
 */
NETCA_CERT_IdentificationItems NETCAAPI netca_cert_ext_toidentificationitems(NETCA_CERT_Extension ext);

/*
 *		netca_cert_generalnames_free
 *			释放GeneralNames
 *		参数：
 *			gns：GeneralNames
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_generalnames_free(NETCA_CERT_GeneralNames gns);

/*
 *		netca_cert_generalnames_getitemcount
 *			获取GeneralNames的项数
 *		参数：
 *			gns：GeneralNames
 *		返回值：
 *			成功返回GeneralNames的项数，失败返回-1
 */
int NETCAAPI netca_cert_generalnames_getitemcount(NETCA_CERT_GeneralNames gns);
/*
 *		netca_cert_generalnames_getitem
 *			获取GeneralNames的项
 *		参数：
 *			gns：GeneralNames
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回GeneralNames的第index项，失败返回NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalnames_getitem(NETCA_CERT_GeneralNames gns,int index);
/*
 *		netca_cert_generalnames_dup
 *			复制GeneralNames
 *		参数：
 *			gns：GeneralNames
 *		返回值：
 *			成功返回复制的GeneralNames，失败返回NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_generalnames_dup(NETCA_CERT_GeneralNames gns);

/*
 *		netca_cert_generalname_free
 *			释放GeneralName
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_generalname_free(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_gettype
 *			获取GeneralName的类型
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的类型，失败返回-1
 */
int NETCAAPI netca_cert_generalname_gettype(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_dup
 *			复制GeneralName
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回复制的GeneralName，失败返回NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalname_dup(NETCA_CERT_GeneralName gn);

/*
 *		netca_cert_generalname_getothername
 *			获得GeneralName的OtherName
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的OtherName，失败返回NULL
 */
NETCA_CERT_OtherName NETCAAPI netca_cert_generalname_getothername(NETCA_CERT_GeneralName gn);

/*
 *		netca_cert_generalname_getrfc822name
 *			获得GeneralName的email
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的email，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_getrfc822name(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getdnsname
 *			获得GeneralName的域名
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的域名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_getdnsname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getdirname
 *			获得GeneralName的目录名
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的目录名，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_generalname_getdirname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getediname
 *			获得GeneralName的EDIPartyName
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的EDIPartyName，失败返回NULL
 */
NETCA_CERT_EDIPartyName NETCAAPI netca_cert_generalname_getediname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			获得GeneralName的URI
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的URI，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_geturi(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			获得GeneralName的IP
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的IP，失败返回NULL
 */
char *NETCAAPI netca_cert_generalname_getip(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			获得GeneralName的注册ID
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的注册ID，失败返回NULL
 */
char *NETCAAPI netca_cert_generalname_getregid(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getencode
 *			获取GeneralName的编码
 *		参数：
 *			gn：GeneralName
 *		返回值：
 *			成功返回GeneralName的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_generalname_getencode(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_equals
 *			判断两个GeneralName的是否相等
 *		参数：
 *			gn1：GeneralName1
 *			gn2：GeneralName2
 *		返回值：
 *			如果两个GeneralName相等返回1，否则返回0
 */
int NETCAAPI netca_cert_generalname_equals(NETCA_CERT_GeneralName gn1,NETCA_CERT_GeneralName gn2);

/*
 *		netca_cert_ediparyname_free
 *			释放EDIPartyName
 *		参数：
 *			edi：EDIPartyName
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_ediparyname_free(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_dup
 *			复制EDIPartyName
 *		参数：
 *			edi：EDIPartyName
 *		返回值：
 *			成功返回复制的EDIPartyName，失败返回NULL
 */
NETCA_CERT_EDIPartyName NETCAAPI netca_cert_ediparyname_dup(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_getnameassigner
 *			获取EDIPartyName的Assigner
 *		参数：
 *			edi：EDIPartyName
 *		返回值：
 *			成功返回EDIPartyName的Assigner，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ediparyname_getnameassigner(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_getpartyname
 *			获取EDIPartyName的partyname
 *		参数：
 *			edi：EDIPartyName
 *		返回值：
 *			成功返回EDIPartyName的partyname，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_ediparyname_getpartyname(NETCA_CERT_EDIPartyName edi);

/*
 *		netca_cert_othername_free
 *			释放OtherName
 *		参数：
 *			othername：OtherName
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_othername_free(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_dup
 *			复制OtherName
 *		参数：
 *			othername：OtherName
 *		返回值：
 *			成功返回复制的OtherName，失败返回NULL
 */
NETCA_CERT_OtherName NETCAAPI netca_cert_othername_dup(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_gettype
 *			获取OtherName的OID
 *		参数：
 *			othername：OtherName
 *		返回值：
 *			成功返回OtherName的OID，失败返回NULL
 */
char * NETCAAPI netca_cert_othername_gettype(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_getvalue
 *			获取OtherName的值的编码值
 *		参数：
 *			othername：OtherName
 *		返回值：
 *			成功返回OtherName的值的编码值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_othername_getvalue(NETCA_CERT_OtherName othername);

/*
 *		netca_cert_akid_free
 *			释放AKID
 *		参数：
 *			akid：AKID
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_akid_free(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getkeyid
 *			获取AKID的密钥标识
 *		参数：
 *			akid：AKID
 *		返回值：
 *			成功返回AKID的密钥标识，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_akid_getkeyid(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getissuerissuername
 *			获取AKID的颁发者的颁发者名
 *		参数：
 *			akid：AKID
 *		返回值：
 *			成功返回AKID的颁发者的颁发者名，失败返回NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_akid_getissuerissuername(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getissuercertsn
 *			获取AKID的颁发者证书的序列号
 *		参数：
 *			akid：AKID
 *		返回值：
 *			成功返回AKID的颁发者证书的序列号，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_akid_getissuercertsn(NETCA_CERT_AKID akid);

/*
 *		netca_cert_policymaps_getitemcount
 *			获取PolicyMappings的项数
 *		参数：
 *			policymaps：PolicyMappings
 *		返回值：
 *			成功返回PolicyMappings的项数，失败返回-1
 */
int NETCAAPI netca_cert_policymaps_getitemcount(NETCA_CERT_PolicyMappings policymaps);
/*
 *		netca_cert_policymaps_getitem
 *			获取PolicyMappings的项
 *		参数：
 *			policymaps：PolicyMappings
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回PolicyMappings的第index项，失败返回-1
 */
NETCA_CERT_PolicyMapping NETCAAPI netca_cert_policymaps_getitem(NETCA_CERT_PolicyMappings policymaps,int index);
/*
 *		netca_cert_policymaps_free
 *			释放PolicyMappings
 *		参数：
 *			policymaps：PolicyMappings
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_policymaps_free(NETCA_CERT_PolicyMappings policymaps);

/*
 *		netca_cert_policymap_free
 *			释放PolicyMapping
 *		参数：
 *			policymap：PolicyMapping
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_policymap_free(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_dup
 *			复制PolicyMapping
 *		参数：
 *			policymap：PolicyMapping
 *		返回值：
 *			成功返回复制的PolicyMapping，失败返回NULL
 */
NETCA_CERT_PolicyMapping NETCAAPI netca_cert_policymap_dup(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_getissuerpolicy
 *			获取PolicyMapping的颁发者域的策略
 *		参数：
 *			policymap：PolicyMapping
 *		返回值：
 *			成功PolicyMapping的颁发者域的策略，失败返回NULL
 */
char * NETCAAPI netca_cert_policymap_getissuerpolicy(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_getsubjectpolicy
 *			获取PolicyMapping的主体域的策略
 *		参数：
 *			policymap：PolicyMapping
 *		返回值：
 *			成功PolicyMapping的主体域的策略，失败返回NULL
 */
char * NETCAAPI netca_cert_policymap_getsubjectpolicy(NETCA_CERT_PolicyMapping policymap);

/*
 *		netca_cert_basicconstraints_free
 *			释放BasicConstraints
 *		参数：
 *			bc：BasicConstraints
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_basicconstraints_free(NETCA_CERT_BasicConstraints bc);
/*
 *		netca_cert_basicconstraints_isca
 *			判断BasicConstraints是否CA
 *		参数：
 *			bc：BasicConstraints
 *		返回值：
 *			如果BasicConstraints的isca为真，则返回1，否则返回0
 */
int NETCAAPI netca_cert_basicconstraints_isca(NETCA_CERT_BasicConstraints bc);
/*
 *		netca_cert_basicconstraints_getpathlen
 *			获取BasicConstraints的路径限制
 *		参数：
 *			bc：BasicConstraints
 *		返回值：
 *			成功返回BasicConstraints的路径限制，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_basicconstraints_getpathlen(NETCA_CERT_BasicConstraints bc);

/*
 *		netca_cert_polqualifierinfo_free
 *			释放PolicyQualifierInfo
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_polqualifierinfo_free(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_dup
 *			复制PolicyQualifierInfo
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			成功返回复制的PolicyQualifierInfo，失败返回NULL
 */
NETCA_CERT_PolicyQualifierInfo NETCAAPI netca_cert_polqualifierinfo_dup(NETCA_CERT_PolicyQualifierInfo pqinfo);

/*
 *		netca_cert_polqualifierinfo_getid
 *			获得PolicyQualifierInfo的类型的OID
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			成功返回PolicyQualifierInfo的类型的OID，失败返回NULL
 */
char * NETCAAPI netca_cert_polqualifierinfo_getid(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getqualifierencode
 *			获得PolicyQualifierInfo的值的编码
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			成功返回PolicyQualifierInfo的值的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_polqualifierinfo_getqualifierencode(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getcpsuri
 *			获得PolicyQualifierInfo的CPS URI
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			成功返回PolicyQualifierInfo的CPS URI，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_polqualifierinfo_getcpsuri(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getusernotice
 *			获得PolicyQualifierInfo的用户通告
 *		参数：
 *			pqinfo：PolicyQualifierInfo
 *		返回值：
 *			成功返回PolicyQualifierInfo的用户通告，失败返回NULL
 */
NETCA_CERT_UserNotice NETCAAPI netca_cert_polqualifierinfo_getusernotice(NETCA_CERT_PolicyQualifierInfo pqinfo);

/*
 *		netca_cert_policyinfo_free
 *			释放PolicyInformation
 *		参数：
 *			polinfo：PolicyInformation
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_policyinfo_free(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_dup
 *			复制PolicyInformation
 *		参数：
 *			polinfo：PolicyInformation
 *		返回值：
 *			成功返回复制的PolicyInformation，失败返回NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_cert_policyinfo_dup(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getid
 *			获取PolicyInformation的类型的OID
 *		参数：
 *			polinfo：PolicyInformation
 *		返回值：
 *			成功返回PolicyInformation的类型的OID，失败返回NULL
 */
char * NETCAAPI netca_cert_policyinfo_getid(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_hasqualifier
 *			判断PolicyInformation是否有qualifier
 *		参数：
 *			polinfo：PolicyInformation
 *		返回值：
 *			如果PolicyInformation有qualifier，返回1，否则返回0
 */
int NETCAAPI netca_cert_policyinfo_hasqualifier(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getqualifiercount
 *			获取PolicyInformation的qualifier个数
 *		参数：
 *			polinfo：PolicyInformation
 *		返回值：
 *			成功返回PolicyInformation的qualifier个数，失败返回-1
 */
int NETCAAPI netca_cert_policyinfo_getqualifiercount(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getqualifier
 *			获取PolicyInformation的qualifier
 *		参数：
 *			polinfo：PolicyInformation
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回PolicyInformation的第index个qualifier，失败返回NULL
 */
NETCA_CERT_PolicyQualifierInfo NETCAAPI netca_cert_policyinfo_getqualifier(NETCA_CERT_PolicyInformation polinfo,int index);

/*
 *		netca_cert_certpolicies_free
 *			释放CertificatePolicies
 *		参数：
 *			certpols：CertificatePolicies
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_certpolicies_free(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_dup
 *			复制CertificatePolicies
 *		参数：
 *			certpols：CertificatePolicies
 *		返回值：
 *			成功返回复制的CertificatePolicies，失败返回NULL
 */
NETCA_CERT_CertificatePolicies NETCAAPI netca_cert_certpolicies_dup(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_getitemcount
 *			获取CertificatePolicies的项数
 *		参数：
 *			certpols：CertificatePolicies
 *		返回值：
 *			成功返回CertificatePolicies的项数，失败返回-1
 */
int NETCAAPI netca_cert_certpolicies_getitemcount(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_getitem
 *			获取CertificatePolicies的项
 *		参数：
 *			certpols：CertificatePolicies
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回CertificatePolicies的第index项，失败返回NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_cert_certpolicies_getitem(NETCA_CERT_CertificatePolicies certpols,int index);


/*
 *		netca_cert_usernotice_free
 *			释放UserNotice
 *		参数：
 *			usernotice：UserNotice
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_usernotice_free(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getexplicittext
 *			获取UserNotice的explicittext
 *		参数：
 *			usernotice：UserNotice
 *		返回值：
 *			成功返回UserNotice的explicittext，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_usernotice_getexplicittext(NETCA_CERT_UserNotice usernotice);

/*
 *		netca_cert_usernotice_getreforg
 *			获取UserNotice的reforg
 *		参数：
 *			usernotice：UserNotice
 *		返回值：
 *			成功返回UserNotice的reforg，失败返回NULL
 */
NETCA_UString NETCAAPI netca_cert_usernotice_getreforg(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getrefnumberscount
 *			获取UserNotice的refnumber的个数
 *		参数：
 *			usernotice：UserNotice
 *		返回值：
 *			成功返回UserNotice的refnumber的个数，失败返回-1
 */
int NETCAAPI netca_cert_usernotice_getrefnumberscount(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getrefnumber
 *			获取UserNotice的refnumber
 *		参数：
 *			usernotice：UserNotice
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回UserNotice的第index个refnumber，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_usernotice_getrefnumber(NETCA_CERT_UserNotice usernotice,int index);

/*
 *		netca_cert_attributes_free
 *			释放Attributes
 *		参数：
 *			attrs：Attributes
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_attributes_free(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_dup
 *			复制Attributes
 *		参数：
 *			attrs：Attributes
 *		返回值：
 *			成功返回复制的Attributes，失败返回NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_attributes_dup(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_getitemcount
 *			获取Attributes的属性个数
 *		参数：
 *			attrs：Attributes
 *		返回值：
 *			成功返回Attributes的属性个数，失败返回-1
 */
int NETCAAPI netca_cert_attributes_getitemcount(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_getitem
 *			获取Attributes的属性
 *		参数：
 *			attrs：Attributes
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回Attributes的第index个属性，失败返回NULL
 */
NETCA_CERT_Attribute NETCAAPI netca_cert_attributes_getitem(NETCA_CERT_Attributes attrs,int index);

/*
 *		netca_cert_attribute_free
 *			释放属性
 *		参数：
 *			attr：属性
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_attribute_free(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_dup
 *			复制属性
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回复制的属性，失败返回NULL
 */
NETCA_CERT_Attribute NETCAAPI  netca_cert_attribute_dup(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_gettype
 *			获取属性的类型OID
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回属性的类型OID，失败返回NULL
 */
char *NETCAAPI  netca_cert_attribute_gettype(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_getvaluescount
 *			获取属性的值的个数
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回属性的值的个数，失败返回-1
 */
int NETCAAPI  netca_cert_attribute_getvaluescount(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_getvaluescount
 *			获取属性的值的编码
 *		参数：
 *			attr：属性
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回属性的第index个值的编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI  netca_cert_attribute_getvalue(NETCA_CERT_Attribute attr,int index);

/*
 *		netca_cert_generalsubtree_free
 *			释放GeneralSubtree
 *		参数：
 *			subtree：GeneralSubtree
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_generalsubtree_free(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_dup
 *			复制GeneralSubtree
 *		参数：
 *			subtree：GeneralSubtree
 *		返回值：
 *			成功返回复制的GeneralSubtree，失败返回NULL
 */
NETCA_CERT_GeneralSubtree NETCAAPI  netca_cert_generalsubtree_dup(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getbase
 *			获取GeneralSubtree的base
 *		参数：
 *			subtree：GeneralSubtree
 *		返回值：
 *			成功返回GeneralSubtree的base，失败返回NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalsubtree_getbase(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getmin
 *			获取GeneralSubtree的min
 *		参数：
 *			subtree：GeneralSubtree
 *		返回值：
 *			成功返回GeneralSubtree的min，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_generalsubtree_getmin(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getmax
 *			获取GeneralSubtree的max
 *		参数：
 *			subtree：GeneralSubtree
 *		返回值：
 *			成功返回GeneralSubtree的max，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_generalsubtree_getmax(NETCA_CERT_GeneralSubtree subtree);

/*
 *		netca_cert_generalsubtrees_free
 *			释放GeneralSubtrees
 *		参数：
 *			subtrees：GeneralSubtrees
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_generalsubtrees_free(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_dup
 *			复制GeneralSubtrees
 *		参数：
 *			subtrees：GeneralSubtrees
 *		返回值：
 *			成功返回复制的GeneralSubtrees，失败返回NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_generalsubtrees_dup(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_getitemcount
 *			获取GeneralSubtrees的项数
 *		参数：
 *			subtrees：GeneralSubtrees
 *		返回值：
 *			成功返回GeneralSubtrees的项数，失败返回-1
 */
int NETCAAPI netca_cert_generalsubtrees_getitemcount(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_getitemcount
 *			获取GeneralSubtrees的项
 *		参数：
 *			subtrees：GeneralSubtrees
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回GeneralSubtrees的第index项，失败返回NULL
 */
NETCA_CERT_GeneralSubtree NETCAAPI netca_cert_generalsubtrees_getitem(NETCA_CERT_GeneralSubtrees subtrees,int index);

/*
 *		netca_cert_nameconstraints_free
 *			释放名字约束
 *		参数：
 *			nameconstraints：名字约束
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_nameconstraints_free(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_dup
 *			复制名字约束
 *		参数：
 *			nameconstraints：名字约束
 *		返回值：
 *			成功返回复制的名字约束，失败返回NULL
 */
NETCA_CERT_NameConstraints NETCAAPI netca_cert_nameconstraints_dup(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_getpremit
 *			获取名字约束的允许项
 *		参数：
 *			nameconstraints：名字约束
 *		返回值：
 *			成功返回名字约束的允许项，失败返回NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_nameconstraints_getpremit(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_getexclude
 *			获取名字约束的禁止项
 *		参数：
 *			nameconstraints：名字约束
 *		返回值：
 *			成功返回名字约束的禁止项，失败返回NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_nameconstraints_getexclude(NETCA_CERT_NameConstraints nameconstraints);

/*
 *		netca_cert_policyconstraints_free
 *			释放策略约束
 *		参数：
 *			policyconstraints：策略约束
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_policyconstraints_free(NETCA_CERT_PolicyConstraints policyconstraints);
/*
 *		netca_cert_policyconstraints_getreqexppolicy
 *			获取策略约束的reqexppolicy
 *		参数：
 *			policyconstraints：策略约束
 *		返回值：
 *			成功返回名字约束的reqexppolicy，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_policyconstraints_getreqexppolicy(NETCA_CERT_PolicyConstraints policyconstraints);
/*
 *		netca_cert_policyconstraints_getinhibtpolicymapping
 *			获取策略约束的inhibtpolicymapping
 *		参数：
 *			policyconstraints：策略约束
 *		返回值：
 *			成功返回名字约束的inhibtpolicymapping，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_policyconstraints_getinhibtpolicymapping(NETCA_CERT_PolicyConstraints policyconstraints);

/*
 *		netca_cert_extkeyusage_free
 *			释放扩展密钥用法
 *		参数：
 *			extkeyusage：扩展密钥用法
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_extkeyusage_free(NETCA_CERT_ExtKeyUsage extkeyusage);
/*
 *		netca_cert_extkeyusage_getitemcount
 *			获取扩展密钥用法的项数
 *		参数：
 *			extkeyusage：扩展密钥用法
 *		返回值：
 *			成功返回扩展密钥用法的项数，失败返回-1
 */
int NETCAAPI netca_cert_extkeyusage_getitemcount(NETCA_CERT_ExtKeyUsage extkeyusage);
/*
 *		netca_cert_extkeyusage_getitemcount
 *			获取扩展密钥用法的项
 *		参数：
 *			extkeyusage：扩展密钥用法
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回扩展密钥用法的第index项数，失败返回NULL
 */
char *NETCAAPI netca_cert_extkeyusage_getitem(NETCA_CERT_ExtKeyUsage extkeyusage,int index);

/*
 *		netca_cert_dpname_free
 *			释放分布点名
 *		参数：
 *			dpname：分布点名
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_dpname_free(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_gettype
 *			获取分布点名的类型
 *		参数：
 *			dpname：分布点名
 *		返回值：
 *			成功返回分布点名的类型，失败返回-1
 */
int NETCAAPI netca_cert_dpname_gettype(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_dup
 *			复制分布点名
 *		参数：
 *			dpname：分布点名
 *		返回值：
 *			成功返回复制的分布点名，失败返回NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_dpname_dup(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_getfullname
 *			获取分布点名的全名
 *		参数：
 *			dpname：分布点名
 *		返回值：
 *			成功返回分布点名的全名，失败返回NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_dpname_getfullname(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_getrelname
 *			获取分布点名的相对名
 *		参数：
 *			dpname：分布点名
 *		返回值：
 *			成功返回分布点名的相对名，失败返回NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_dpname_getrelname(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_equals
 *			判断分布点名是否相等
 *		参数：
 *			dpname1：分布点名1
 *			dpname2：分布点名2
 *		返回值：
 *			如果两个分布点名相等，返回1，否则返回0
 */
int NETCAAPI netca_cert_dpname_equals(NETCA_CERT_DistributionPointName dpname1,NETCA_CERT_DistributionPointName dpname2);

/*
 *		netca_cert_distpoint_free
 *			释放分布点名
 *		参数：
 *			dp：分布点
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_distpoint_free(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_dup
 *			复制分布点
 *		参数：
 *			dp：分布点
 *		返回值：
 *			成功返回复制的分布点，失败返回NULL
 */
NETCA_CERT_DistributionPoint NETCAAPI netca_cert_distpoint_dup(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getdpname
 *			获取分布点的分布点名
 *		参数：
 *			dp：分布点
 *		返回值：
 *			成功返回分布点的分布点名，失败返回NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_distpoint_getdpname(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getreasons
 *			获取分布点的reasons
 *		参数：
 *			dp：分布点
 *		返回值：
 *			成功返回分布点的reasons，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_cert_distpoint_getreasons(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getcrlissuer
 *			获取分布点的CRL颁发者
 *		参数：
 *			dp：分布点
 *		返回值：
 *			成功返回分布点的CRL颁发者，失败返回NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_distpoint_getcrlissuer(NETCA_CERT_DistributionPoint dp);

/*
 *		netca_cert_crldps_free
 *			释放CRLDistributionPoints
 *		参数：
 *			crldps：CRLDistributionPoints
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_crldps_free(NETCA_CERT_CRLDistributionPoints crldps);
/*
 *		netca_cert_crldps_getitemcount
 *			获取CRLDistributionPoints的项数
 *		参数：
 *			crldps：CRLDistributionPoints
 *		返回值：
 *			成功返回CRLDistributionPoints的项数，失败返回-1
 */
int NETCAAPI netca_cert_crldps_getitemcount(NETCA_CERT_CRLDistributionPoints crldps);
/*
 *		netca_cert_crldps_getitem
 *			获取CRLDistributionPoints的项
 *		参数：
 *			crldps：CRLDistributionPoints
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回CRLDistributionPoints的第index项，失败返回NULL
 */
NETCA_CERT_DistributionPoint NETCAAPI netca_cert_crldps_getitem(NETCA_CERT_CRLDistributionPoints crldps,int index);

/*
 *		netca_cert_accessdescs_free
 *			释放AccessDescriptions
 *		参数：
 *			accessdescs：AccessDescriptions
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_accessdescs_free(NETCA_CERT_AccessDescriptions accessdescs);
/*
 *		netca_cert_accessdescs_getitemcount
 *			获取AccessDescriptions的项数
 *		参数：
 *			accessdescs：AccessDescriptions
 *		返回值：
 *			成功返回AccessDescriptions的项数，失败返回-1
 */
int NETCAAPI netca_cert_accessdescs_getitemcount(NETCA_CERT_AccessDescriptions accessdescs);
/*
 *		netca_cert_accessdescs_getitem
 *			获取AccessDescriptions的项
 *		参数：
 *			accessdescs：AccessDescriptions
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回AccessDescriptions的第index项，失败返回NULL
 */
NETCA_CERT_AccessDescription NETCAAPI netca_cert_accessdescs_getitem(NETCA_CERT_AccessDescriptions accessdescs,int index);

/*
 *		netca_cert_accessdesc_free
 *			释放AccessDescription
 *		参数：
 *			accessdesc：AccessDescription
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_accessdesc_free(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_dup
 *			复制AccessDescription
 *		参数：
 *			accessdesc：AccessDescription
 *		返回值：
 *			成功返回复制的AccessDescription，失败返回NULL
 */
NETCA_CERT_AccessDescription NETCAAPI netca_cert_accessdesc_dup(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_getmethod
 *			获取AccessDescription的method
 *		参数：
 *			accessdesc：AccessDescription
 *		返回值：
 *			成功返回AccessDescription的method，失败返回NULL
 */
char * NETCAAPI netca_cert_accessdesc_getmethod(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_getlocation
 *			获取AccessDescription的location
 *		参数：
 *			accessdesc：AccessDescription
 *		返回值：
 *			成功返回AccessDescription的location，失败返回NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_accessdesc_getlocation(NETCA_CERT_AccessDescription accessdesc);

/*
 *		netca_cert_idp_free
 *			释放IssuingDistributionPoint
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_idp_free(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_getdpname
 *			获取IssuingDistributionPoint的分布点名
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			成功返回IssuingDistributionPoint的分布点名，失败返回NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_idp_getdpname(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainsusercerts
 *			判断IssuingDistributionPoint的是否只包含用户证书
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			如果IssuingDistributionPoint的只包含用户证书，返回1，否则返回0
 */
int NETCAAPI netca_cert_idp_isonlycontainsusercerts(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainscacerts
 *			判断IssuingDistributionPoint的是否只包含CA证书
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			如果IssuingDistributionPoint的只包含CA证书，返回1，否则返回0
 */
int NETCAAPI netca_cert_idp_isonlycontainscacerts(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_getconverreasons
 *			获取IssuingDistributionPoint的覆盖的作废原因
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			成功返回IssuingDistributionPoint的覆盖的作废原因，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_cert_idp_getconverreasons(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isindirectcrl
 *			获取IssuingDistributionPoint的是否是间接CRL
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			如果IssuingDistributionPoint是间接CRL，返回1，否则返回0
 */
int NETCAAPI netca_cert_idp_isindirectcrl(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainsattrcerts
 *			获取IssuingDistributionPoint的是否只包含属性证书
 *		参数：
 *			idp：IssuingDistributionPoint
 *		返回值：
 *			如果IssuingDistributionPoint只包含属性证书，返回1，否则返回0
 */
int NETCAAPI netca_cert_idp_isonlycontainsattrcerts(NETCA_CERT_IssuingDistributionPoint idp);

/*
 *		netca_cert_privkeyusageperiod_free
 *			释放私钥有效期
 *		参数：
 *			privkeyusageperiod：私钥有效期
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_privkeyusageperiod_free(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);
/*
 *		netca_cert_privkeyusageperiod_getnotbefore
 *			获取私钥有效期的notbefore
 *		参数：
 *			privkeyusageperiod：私钥有效期
 *		返回值：
 *			成功返回私钥有效期的notbefore，失败返回NULL
 */
NETCA_Time NETCAAPI netca_cert_privkeyusageperiod_getnotbefore(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);
/*
 *		netca_cert_privkeyusageperiod_getnotafter
 *			获取私钥有效期的notafter
 *		参数：
 *			privkeyusageperiod：私钥有效期
 *		返回值：
 *			成功返回私钥有效期的notafter，失败返回NULL
 */
NETCA_Time NETCAAPI netca_cert_privkeyusageperiod_getnotafter(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);


/*
 *		netca_cert_identificationitems_free
 *			释放IdentificationItems
 *		参数：
 *			items：IdentificationItems
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_identificationitems_free(NETCA_CERT_IdentificationItems items);

/*
 *		netca_cert_identificationitems_getitemcount
 *			获取IdentificationItem的项数
 *		参数：
 *			items：IdentificationItems
 *		返回值：
 *			成功返回IdentificationItems的项数，失败返回-1
 */
int NETCAAPI netca_cert_identificationitems_getitemcount(NETCA_CERT_IdentificationItems items);
/*
 *		netca_cert_identificationitems_getitem
 *			获取IdentificationItems的项
 *		参数：
 *			items：IdentificationItems
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回IdentificationItems的第index项，失败返回NULL
 */
NETCA_CERT_IdentificationItem NETCAAPI netca_cert_identificationitems_getitem(NETCA_CERT_IdentificationItems items,int index);

/*
 *		netca_cert_identificationitem_free
 *			释放IdentificationItem
 *		参数：
 *			item：IdentificationItem
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_identificationitem_free(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_gettype
 *			获取IdentificationItem的类型
 *		参数：
 *			item：IdentificationItem
 *		返回值：
 *			成功返回IdentificationItem的类型，失败返回-1
 */
int NETCAAPI netca_cert_identificationitem_gettype(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_getencode
 *			获取IdentificationItem的编码方式
 *		参数：
 *			item：IdentificationItem
 *		返回值：
 *			成功返回IdentificationItem的编码方式，失败返回-1
 */
int NETCAAPI netca_cert_identificationitem_getencode(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_getencode
 *			获取IdentificationItem的值
 *		参数：
 *			item：IdentificationItem
 *		返回值：
 *			成功返回IdentificationItem的值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_identificationitem_getvalue(NETCA_CERT_IdentificationItem item);

enum{
	NETCA_CRL_V1=0,
	NETCA_CRL_V2=1,
};

enum{
	NETCA_CRL_VERIFY_UNDETERMINED			=-1,
	NETCA_CRL_VERIFY_UNREVOKED			=0,
	NETCA_CRL_VERIFY_REVOKED			=1,
	NETCA_CRL_VERIFY_BADCERT			=2,
	NETCA_CRL_VERIFY_BADCRL				=3,
	NETCA_CRL_VERIFY_CRLDISMATCH			=4,
	NETCA_CRL_VERIFY_UNKNOWN_CRITICAL_CRL_EXT	=5,
	NETCA_CRL_VERIFY_UNKNOWN_CRITICAL_CRLENTRY_EXT	=6,
	NETCA_CRL_VERIFY_TWOCRLDISMATCH			=7,
	NETCA_CRL_VERIFY_BADCRLENTRY			=8,
};

enum{
	NETCA_CRLREASON_UNSPECIFIED			=0,
	NETCA_CRLREASON_KEYCOMPROMISE			=1,
	NETCA_CRLREASON_CACOMPROMISE			=2,
	NETCA_CRLREASON_AFFILIATIONCHANGED		=3,
	NETCA_CRLREASON_SUPERSEDED			=4,
	NETCA_CRLREASON_CESSATIONOFOPERTION		=5,
	NETCA_CRLREASON_CERTIFICATEHOLD			=6,
	NETCA_CRLREASON_REMOVEFROMCRL			=8,
	NETCA_CRLREASON_PRIVILEGEWITHDRAWN		=9,
	NETCA_CRLREASON_AACOMPROMISE			=10,
};

/*
 *		netca_crl_new
 *			创建CRL
 *		参数：
 *			data：输入参数，CRL的编码
 *			datalen:输入参数，CRL的编码的长度
 *			errctx:错误上下文
 *		返回值：
 *			成功返回CRL，失败返回NULL
 */
NETCA_CRL NETCAAPI netca_crl_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);
/*
 *		netca_crl_free
 *			释放CRL
 *		参数：
 *			crl：CRL
 *		返回值：
 *			无
 */
void NETCAAPI netca_crl_free(NETCA_CRL crl);
/*
 *		netca_crl_dup
 *			复制CRL
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回复制的CRL，失败返回NULL
 */
NETCA_CRL NETCAAPI netca_crl_dup(NETCA_CRL crl);
/*
 *		netca_crl_getversion
 *			获取CRL的版本号
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的版本号，失败返回-1
 */
int NETCAAPI netca_crl_getversion(NETCA_CRL crl);
/*
 *		netca_crl_getsignalgorithm
 *			获取CRL的签名算法
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getsignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getinnersignalgorithm
 *			获取CRL的内部签名算法
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的内部签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getinnersignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getoutersignalgorithm
 *			获取CRL的外部签名算法
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的外部签名算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getoutersignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getissuer
 *			获取CRL的颁发者
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的颁发者，失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_crl_getissuer(NETCA_CRL crl);
/*
 *		netca_crl_getthisupdate
 *			获取CRL的thisupdate
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的thisupdate，失败返回NULL
 */
NETCA_Time NETCAAPI netca_crl_getthisupdate(NETCA_CRL crl);
/*
 *		netca_crl_getnextupdate
 *			获取CRL的nextupdate
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的nextupdate，失败返回NULL
 */
NETCA_Time NETCAAPI netca_crl_getnextupdate(NETCA_CRL crl);
/*
 *		netca_crl_hasnextupdate
 *			判断CRL是否有nextupdate
 *		参数：
 *			crl：CRL
 *		返回值：
 *			如果CRL有nextupdate返回1，否则返回0
 */
int NETCAAPI netca_crl_hasnextupdate(NETCA_CRL crl);
/*
 *		netca_crl_hasexts
 *			判断CRL是否有扩展
 *		参数：
 *			crl：CRL
 *		返回值：
 *			如果CRL有扩展返回1，否则返回0
 */
int NETCAAPI netca_crl_hasexts(NETCA_CRL crl);
/*
 *		netca_crl_getexts
 *			获取CRL的扩展
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的扩展，失败返回NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_crl_getexts(NETCA_CRL crl);
/*
 *		netca_crl_getsignvalue
 *			获取CRL的签名值
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的签名值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_getsignvalue(NETCA_CRL crl);

/*
 *		netca_crl_getsignvalueunusedbits
 *			获取CRL的签名值的未使用位数
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的签名值的未使用位数，失败返回-1
 */
int NETCAAPI netca_crl_getsignvalueunusedbits(NETCA_CRL crl);

/*
 *		netca_crl_hasrevokedcertlist
 *			判断CRL是否有作废证书列表
 *		参数：
 *			crl：CRL
 *		返回值：
 *			如果CRL有作废证书列表返回1，否则返回0
 */
int NETCAAPI netca_crl_hasrevokedcertlist(NETCA_CRL crl);
/*
 *		netca_crl_getrevokedcertlist
 *			获取CRL的作废证书列表
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的作废证书列表，失败返回NULL
 */
NETCA_CRL_RevokedCertList NETCAAPI netca_crl_getrevokedcertlist(NETCA_CRL crl);
/*
 *		netca_crl_ismatchdcrl
 *			判断CRL和delta CRL是否匹配
 *		参数：
 *			crl：CRL
 *			dcrl：delta CRL
 *		返回值：
 *			如果CRL和delta CRL匹配返回1，否则返回0
 */
int NETCAAPI netca_crl_ismatchdcrl(NETCA_CRL crl,NETCA_CRL dcrl);
/*
 *		netca_crl_isdcrl
 *			判断CRL是否delta CRL
 *		参数：
 *			dcrl：delta CRL
 *		返回值：
 *			如果dcrl是delta CRL返回1，否则返回0
 */
int NETCAAPI netca_crl_isdcrl(NETCA_CRL dcrl);
/*
 *		netca_crl_encode
 *			获取CRL的DER编码
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的DER编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_encode(NETCA_CRL crl);
/*
 *		netca_crl_gettbs
 *			获取CRL的要签名部分的编码值
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的要签名部分的编码值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_gettbs(NETCA_CRL crl);
/*
 *		netca_crl_verifycert
 *			使用CRL来验证证书是否作废
 *		参数：
 *			crl：CRL
 *			dcrl：delta CRL可以为NULL
 *			cert:证书
 *			revtime：输出参数，返回的作废时间
 *			revreason：输出参数，返回的作废原因
 *			reasonscope：输出参数，返回的CRL覆盖的作废原因范围
 *		返回值：
 *			未作废返回NETCA_CRL_VERIFY_UNREVOKED，作废返回NETCA_CRL_VERIFY_REVOKED，不能确定返回NETCA_CRL_VERIFY_UNDETERMINED
 */
int NETCAAPI netca_crl_verifycert(NETCA_CRL crl,NETCA_CRL dcrl,NETCA_CERT cert,NETCA_Time *revtime,int *revreason,long *reasonscope);
/*
 *		netca_crl_isinvalidity
 *			判断CRL是否在有效期内
 *		参数：
 *			crl：CRL
 *			t：时间
 *		返回值：
 *			如果在时间t，CRL在有效期内，返回1，否则返回0
 */
int NETCAAPI netca_crl_isinvalidity(NETCA_CRL crl,NETCA_Time t);
/*
 *		netca_crl_getissuerdisplayname
 *			获取CRL的颁发者的显示名
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的颁发者的显示名，失败返回NULL
 */
NETCA_UString NETCAAPI netca_crl_getissuerdisplayname(NETCA_CRL crl);

/*
 *		netca_crl_revokedcert_dup
 *			复制CRL的作废证书条目
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			成功返回复制的CRL的作废证书条目，失败返回NULL
 */
NETCA_CRL_RevokedCert NETCAAPI netca_crl_revokedcert_dup(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_free
 *			释放CRL的作废证书条目
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			无
 */
void NETCAAPI netca_crl_revokedcert_free(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getserialnumber
 *			获取CRL的作废证书条目的序列号
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			成功返回CRL的作废证书条目的序列号，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crl_revokedcert_getserialnumber(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getrevdate
 *			获取CRL的作废证书条目的作废时间
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			成功返回CRL的作废证书条目的作废时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_crl_revokedcert_getrevdate(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_hasexts
 *			判断CRL的作废证书条目是否有扩展
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			如果CRL的作废证书条目有扩展返回1，否则返回0
 */
int NETCAAPI netca_crl_revokedcert_hasexts(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getexts
 *			获取CRL的作废证书条目的扩展
 *		参数：
 *			cert：CRL的作废证书条目
 *		返回值：
 *			成功返回CRL的作废证书条目的扩展，失败返回NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_crl_revokedcert_getexts(NETCA_CRL_RevokedCert cert);

/*
 *		netca_crl_revokedcertlist_free
 *			释放CRL的作废证书列表
 *		参数：
 *			certlist：CRL的作废证书列表
 *		返回值：
 *			无
 */
void NETCAAPI netca_crl_revokedcertlist_free(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_dup
 *			复制CRL的作废证书列表
 *		参数：
 *			certlist：CRL的作废证书列表
 *		返回值：
 *			成功返回复制的CRL的作废证书列表，失败返回NULL
 */
NETCA_CRL_RevokedCertList NETCAAPI netca_crl_revokedcertlist_dup(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_getitemcount
 *			获取CRL的作废证书列表的项数
 *		参数：
 *			certlist：CRL的作废证书列表
 *		返回值：
 *			成功返回CRL的作废证书列表的项数，失败返回-1
 */
int NETCAAPI netca_crl_revokedcertlist_getitemcount(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_getitem
 *			获取CRL的作废证书列表的项
 *		参数：
 *			certlist：CRL的作废证书列表
 *			index:输入参数，索引值，从0算起
 *		返回值：
 *			成功返回CRL的作废证书列表的第index项，失败返回NULL
 */
NETCA_CRL_RevokedCert NETCAAPI netca_crl_revokedcertlist_getitem(NETCA_CRL_RevokedCertList certlist,int index);

/*
 *		netca_cert_digestinfo_free
 *			释放DigestInfo
 *		参数：
 *			hash：DigestInfo
 *		返回值：
 *			无
 */
void NETCAAPI  netca_cert_digestinfo_free(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_dup
 *			复制DigestInfo
 *		参数：
 *			hash：DigestInfo
 *		返回值：
 *			成功返回复制的DigestInfo，失败返回NULL
 */
NETCA_CERT_DigestInfo NETCAAPI  netca_cert_digestinfo_dup(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_getalgorithm
 *			获取DigestInfo的摘要算法
 *		参数：
 *			hash：DigestInfo
 *		返回值：
 *			成功返回DigestInfo的摘要算法，失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_digestinfo_getalgorithm(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_gethashvalue
 *			获取DigestInfo的摘要值
 *		参数：
 *			hash：DigestInfo
 *		返回值：
 *			成功返回DigestInfo的摘要值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_digestinfo_gethashvalue(NETCA_CERT_DigestInfo hash);

/*
 *		netca_cert_digestinfolist_free
 *			释放DigestInfo列表
 *		参数：
 *			list：DigestInfo列表
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_digestinfolist_free(NETCA_CERT_DigestInfoList list);
/*
 *		netca_cert_digestinfolist_getitemcount
 *			获取DigestInfo列表的项数
 *		参数：
 *			list：DigestInfo列表
 *		返回值：
 *			成功返回DigestInfo列表的项数，失败返回-1
 */
int NETCAAPI netca_cert_digestinfolist_getitemcount(NETCA_CERT_DigestInfoList list);
/*
 *		netca_cert_digestinfolist_getitem
 *			获取DigestInfo列表的项
 *		参数：
 *			list：DigestInfo列表
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回DigestInfo列表的第index项，失败返回-1
 */
NETCA_CERT_DigestInfo NETCAAPI netca_cert_digestinfolist_getitem(NETCA_CERT_DigestInfoList list,int index);


/*
 *		netca_cert_setattribute
 *			设置证书属性
 *		参数：
 *			cert：证书
 *			type：输入参数，属性类型
 *			value：输入参数，属性值
 *		返回值：
 *			成功返回NETCA_OK,失败返回NETCA_FAIL
 */
int NETCAAPI netca_cert_setattribute(NETCA_CERT cert,int type,void *value);
/*
 *		netca_cert_getattribute
 *			获取证书属性
 *		参数：
 *			cert：证书
 *			type：输入参数，属性类型
 *			value：输出参数，返回的属性值
 *		返回值：
 *			成功返回NETCA_OK,失败返回NETCA_FAIL
 */
int NETCAAPI netca_cert_getattribute(NETCA_CERT cert,int type,void **value);


enum{
	NETCA_CERT_STORE_TYPE_CURRENTUSER=0,
	NETCA_CERT_STORE_TYPE_LOCALMACHINE=1,
};

#define NETCA_CERT_STORE_NAME_MY	"my"
#define NETCA_CERT_STORE_NAME_OTHERS	"others"
#define NETCA_CERT_STORE_NAME_CA	"ca"
#define NETCA_CERT_STORE_NAME_ROOT	"root"
#define NETCA_CERT_STORE_NAME_DEVICE	"device"



/*
 *		netca_cert_store_open
 *			打开证书库
 *		参数：
 *			type：输入参数，证书库的类型
 *			name：输入参数，证书库的名称
 *		返回值：
 *			成功返回证书库,失败返回NULL
 */
NETCA_CERT_Store NETCAAPI netca_cert_store_open(int type,const char *name);
/*
 *		netca_cert_store_getcertcount
 *			获取证书库中证书个数
 *		参数：
 *			store：证书库
 *		返回值：
 *			成功返回证书库中证书个数,失败返回-1
 */
int NETCAAPI netca_cert_store_getcertcount(NETCA_CERT_Store store);
/*
 *		netca_cert_store_getcert
 *			获取证书库中证书
 *		参数：
 *			store：证书库
 *			index:输入参数，索引值，从0算起
 *		返回值：
 *			成功返回证书库中第index个证书,失败返回NULL
 */
NETCA_CERT NETCAAPI netca_cert_store_getcert(NETCA_CERT_Store store,int index);
/*
 *		netca_cert_store_close
 *			关闭证书库
 *		参数：
 *			store：证书库
 *		返回值：
 *			无
 */
void NETCAAPI netca_cert_store_close(NETCA_CERT_Store store);
/*
 *		netca_cert_store_save
 *			保存证书库
 *		参数：
 *			store：证书库
 *		返回值：
 *			成功返回NETCA_OK,失败返回NETCA_FAIL
 */
int NETCAAPI netca_cert_store_save(NETCA_CERT_Store store);
/*
 *		netca_cert_store_addcert
 *			添加证书到证书库
 *		参数：
 *			store：证书库
 *			cert：证书
 *		返回值：
 *			成功返回NETCA_OK,失败返回NETCA_FAIL
 */
int NETCAAPI netca_cert_store_addcert(NETCA_CERT_Store store,NETCA_CERT cert);
/*
 *		netca_cert_store_delete
 *			在证书库里删除证书
 *		参数：
 *			store：证书库
 *			cert：证书
 *		返回值：
 *			成功返回NETCA_OK,失败返回NETCA_FAIL
 */
int NETCAAPI netca_cert_store_delete(NETCA_CERT_Store store,NETCA_CERT cert);

/*
 *		netca_cert_store_loadpfx
 *			把PFX格式的数据装载到证书库
 *		参数：
 *			data：输入参数，PFX格式的数据
 *			datalen：输入参数，data的长度
 *			pwd：输入数，PFX的密码
 *		返回值：
 *			成功返回证书库,失败返回NULL
 */
NETCA_CERT_Store NETCAAPI netca_cert_store_loadpfx(const unsigned char *data,long datalen,NETCA_UString pwd);


#ifdef __cplusplus
	}	
#endif
#endif

