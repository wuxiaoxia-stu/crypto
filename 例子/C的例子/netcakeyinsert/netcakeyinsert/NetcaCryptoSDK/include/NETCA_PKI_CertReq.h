#ifndef _NETCA_PKI_CERTREQ_INLCUDE_H_
#define _NETCA_PKI_CERTREQ_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKICertReqNew
 *		创建证书请求句柄
 *	参数：
 *		无。
 *	返回值：
 *		成功返回有效的证书请求句柄，失败返回NULL
 *
 */
NETCA_PKI_CERTREQ_HANDLE NETCADLLAPI NetcaPKICertReqNew(void);


/*
 *	NetcaPKICertReqFree
 *		释放证书请求句柄
 *	参数：
 *		hCertReq：证书请求句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqFree(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqSetIntegerAttribute
 *		设置证书请求的整数属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		atrrId：输入参数，属性ID
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqSetIntegerAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,int value);


/*
 *	NetcaPKICertReqSetStringAttribute
 *		设置证书请求的字符串属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		atrrId：输入参数，属性ID
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqSetStringAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,const char *value);

/*
 *	NetcaPKICertReqSign
 *		签名产生证书请求
 *	参数：
 *		hCertReq：证书请求句柄
 *		hKeypair：签名私钥
 *		signAlgo：输入参数，签名算法
 *		param：输入参数，签名参数
 *		certReq：输出参数，返回的证书请求
 *		certReqLen：输出参数，返回的证书请求的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqSign(NETCA_PKI_CERTREQ_HANDLE hCertReq,NETCA_PKI_KEYPAIR_HANDLE hKeypair,int signAlgo,const void *param,unsigned char **certReq,int *certReqLen);

/*
 *	NetcaPKICertReqSignWithCallback
 *		签名产生证书请求
 *	参数：
 *		hCertReq：证书请求句柄
 *		spki：输入参数，主体公钥的DER编码
 *		spkiLen：输入参数，主体公钥的DER编码的长度
 *		signAlgo：输入参数，签名算法
 *		param：输入参数，签名参数
 *		signCallback：输入参数，签名回调函数
 *		context：回调函数的参数
 *		certReq：输出参数，返回的证书请求
 *		certReqLen：输出参数，返回的证书请求的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqSignWithCallback(NETCA_PKI_CERTREQ_HANDLE hCertReq,const unsigned char *spki,int spkiLen,int signAlgo,const void *param,NetcaCertReqSignHashCallback_Ptr signCallback,void *context,unsigned char **certReq,int *certReqLen);


/*
 *	NetcaPKICertReqDecode
 *		创建证书请求句柄
 *	参数：
 *		data：证书请求的编码。
 *		dataLen：证书请求的编码长度。
 *	返回值：
 *		成功返回有效的证书请求句柄，失败返回NULL
 *
 */
NETCA_PKI_CERTREQ_HANDLE NETCADLLAPI NetcaPKICertReqDecode(const unsigned char *data,int dataLen);


/*
 *	NetcaPKICertReqGetIntegerAttribute
 *		获取证书请求的整数属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		atrrId：输入参数，属性ID
 *		value：输出参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqGetIntegerAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,int *value);


/*
 *	NetcaPKICertReqGetStringAttribute
 *		获取证书请求的字符串属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		atrrId：输入参数，属性ID
 *		value：输出参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqGetStringAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,char **value);


/*
 *	NetcaPKICertReqVerify
 *		验证证书请求的签名
 *	参数：
 *		hCertReq：证书请求句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqVerify(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqSetSubject
 *		设置证书请求的主体
 *	参数：
 *		hCertReq：证书请求句柄
 *		data：输入参数，主体的编码
 *		dataLen：输入参数，主体的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqSetSubject(NETCA_PKI_CERTREQ_HANDLE hCertReq,const unsigned char *data,int dataLen);

/*
 *	NetcaPKICertReqGetSubject
 *		获取证书请求的主体
 *	参数：
 *		hCertReq：证书请求句柄
 *		data：输出参数，主体的编码
 *		dataLen：输出参数，主体的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqGetSubject(NETCA_PKI_CERTREQ_HANDLE hCertReq,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICertReqGetSubject
 *		获取证书请求的主体
 *	参数：
 *		hCertReq：证书请求句柄
 *		data：输出参数，主体的编码
 *		dataLen：输出参数，主体的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertReqGetPublicKey(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqGetEncode
 *		获取证书请求的DER编码
 *	参数：
 *		hCertReq：证书请求句柄
 *		data：输出参数，主体的编码
 *		dataLen：输出参数，主体的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqGetEncode(NETCA_PKI_CERTREQ_HANDLE hCertReq,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICertReqAddAttribute
 *		添加证书请求属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		attrType：输入参数，属性类型
 *		attrValue：输入参数，属性值的DER编码
 *		attrValueLen：输入参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqAddAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKICertReqGetAttribute
 *		获取证书请求的属性
 *	参数：
 *		hCertReq：证书请求句柄
 *		index：输入参数，属性索引值，从0算起。
 *		attrType：输出参数，属性类型
 *		attrValue：输出参数，属性值的DER编码
 *		attrValueLen：输出参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertReqGetAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int index,char **attrType,unsigned char **attrValue,int *attrValueLen);

#ifdef __cplusplus
	}	
#endif
#endif
