#ifndef NETCA_PKI_ATTRIBUTE_CERT_INCLUDE_H
#define NETCA_PKI_ATTRIBUTE_CERT_INCLUDE_H

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIAttributeCertNew
 *		创建属性证书句柄
 *	参数：
 *		data：输入参数，属性证书的编码
 *		len：输入参数，属性证书的编码的长度
 *	返回值：
 *		成功返回有效的属性证书句柄，失败返回NULL
 *
 */
NETCA_PKI_ATTRIBUTE_CERT_HANDLE NETCADLLAPI NetcaPKIAttributeCertNew(const unsigned char *data,int len);


/*
 *	NetcaPKIAttributeCertFree
 *		释放属性证书句柄
 *	参数：
 *		hCert：属性证书句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertFree(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetEncode
 *		获取属性证书的DER编码
 *	参数：
 *		hCert：属性证书句柄
 *		data：输出参数，主体的编码
 *		dataLen：输出参数，主体的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetEncode(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,unsigned char **data,int *dataLen);

/*
 *	NetcaPKIAttributeCertGetSerialNumber
 *		获取属性证书的序列号
 *	参数：
 *		hCert：属性证书句柄
 *	返回值：
 *		成功返回序列号的HEX编码，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetSerialNumber(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetNotBefore
 *		获取属性证书的有效期开始时间
 *	参数：
 *		hCert：属性证书句柄
 *	返回值：
 *		成功返回有效期开始时间，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetNotBefore(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetNotAfter
 *		获取属性证书的有效期结束时间
 *	参数：
 *		hCert：属性证书句柄
 *	返回值：
 *		成功返回有效期结束时间，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetNotAfter(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetAttributeCount
 *		获取属性证书的属性个数
 *	参数：
 *		hCert：属性证书句柄
 *	返回值：
 *		成功返回属性个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetAttributeCount(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetAttribute
 *		获取属性证书的属性
 *	参数：
 *		hCert：属性证书句柄
 *		index：输入参数，属性索引值，从0算起。
 *		attrType：输出参数，属性类型
 *		attrValue：输出参数，属性值的DER编码
 *		attrValueLen：输出参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetAttribute(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,int index,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIAttributeCertFindExtension
 *		获取属性证书的扩展
 *	参数：
 *		hCert：属性证书句柄
 *		oid：输入参数，扩展的OID
 *		pcritical：输出参数，如果扩展是关键的返回1，否则返回0
 *		pvalue：输出参数，返回扩展的编码值
 *		pvaluelen：输出参数，返回扩展的编码值的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值，如果扩展不存在返回NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertFindExtension(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,const char *oid,int *pcritical,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKIAttributeCertVerify
 *		验证属性证书
 *	参数：
 *		hAttrCert：属性证书句柄
 *		hIssuerCert：属性证书的颁发者公钥证书
 *		verifyTime：输入参数，验证时间，为NULL则为当前时间
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertVerify(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hAttrCert,NETCA_PKI_CERTIFICATE_HANDLE hIssuerCert,const char* verifyTime);

/*
 *	NetcaPKIAttributeCertMatchPublicKeyCert
 *		判断属性证书是否和公钥证书匹配
 *	参数：
 *		hAttrCert：属性证书句柄
 *		hPublicKeyCert：公钥证书句柄
 *	返回值：
 *		匹配返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertMatchPublicKeyCert(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hAttrCert,NETCA_PKI_CERTIFICATE_HANDLE hPublicKeyCert);


#ifdef __cplusplus
	}	
#endif
#endif
