#ifndef _NETCA_PKI_APPLICATION_INLCUDE_H_
#define _NETCA_PKI_APPLICATION_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif




/* 数字信封相关函数 */

/*
 *	NetcaPKIMsgNewEnvelopedData
 *		创建数字信封句柄
 *	参数：
 *		enc：输入参数，为真表示在创建数字信封，为假表示在解开数字信封
 *	返回值：
 *		成功返回数字信封句柄，失败返回NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgNewEnvelopedData(int enc);

/*
 *	NetcaPKIMsgFreeEnvelopedData
 *		释放数字信封句柄
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeEnvelopedData(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataSetEncAlgorithm
 *		设置数字信封的对称加密算法
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		encAlgo：输入参数，对称加密算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int encAlgo);


/*
 *	NetcaPKIMsgEnvelopedDataAddCert
 *		在数字信封里添加加密证书
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		cert：输入参数，加密证书
 *		flag：输入参数，标志
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataAddCert(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_CERTIFICATE_HANDLE cert,int flag);


/*
 *	NetcaPKIMsgEnvelopedDataSetCryptoHandle
 *		设置数字信封句柄对称加解密使用的设备句柄
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetCryptoHandle(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKIMsgEnvelopedDataSetUseSM2Q7
 *		设置使用GM/T 0010-2012的数字信封格式
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetUseSM2Q7(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataSetNoContentInfo
 *		设置数字信封句柄不输出ContentInfo的封装，仅仅是EnvelopedData
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetNoContentInfo(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataSetIntegerAttribute
 *		设置数字信封的整数类型的属性
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		atrrId：输入参数，属性ID
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetIntegerAttribute(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int atrrId,int value);

/*
 *	NetcaPKIMsgEnvelopedDataSetStringAttribute
 *		设置数字信封的字符串类型的属性
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		atrrId：输入参数，属性ID
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetStringAttribute(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int atrrId,const char* value);

/*
 *	NetcaPKIMsgEnvelopedDataEncryptInit
 *		开始构造数字信封
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		cipher：输出参数，密文
 *		cipherlen：输出参数，返回的密文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptInit(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,unsigned char **cipher,int *cipherlen);

/*
 *	NetcaPKIMsgEnvelopedDataEncryptUpdate
 *		添加明文，进行加密
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		clear：输入参数，明文
 *		clearlen：输入参数，明文长度
 *		cipher：输出参数，密文
 *		cipherlen：输出参数，返回的密文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptUpdate(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *clear,int clearlen,unsigned char **cipher,int *cipherlen);


/*
 *	NetcaPKIMsgEnvelopedDataEncryptFinal
 *		结束加密
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		cipher：输出参数，密文
 *		cipherlen：输出参数，返回的密文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptFinal(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, unsigned char **cipher,int *cipherlen);


/*
 *	NetcaPKIMsgEnvelopedDataEncrypt
 *		进行加密，构造完成数字信封
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		clear：输入参数，明文
 *		clearlen：输入参数，明文长度
 *		cipher：输出参数，密文
 *		cipherlen：输出参数，返回的密文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncrypt(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const unsigned char *clear,int clearlen,unsigned char **cipher,int *cipherlen);

/*
 *	NetcaPKIMsgEnvelopedDataAddStore
 *		添加解密的证书所在的证书库
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		store：证书库
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataAddStore(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKIMsgEnvelopedDataSetDecryptKeyCallback
 *		设置解密对称密钥的回调函数
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		callback：回调函数
 *		context：回调函数的参数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetDecryptKeyCallback(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NetcaEnvelopedDataDecryptKeyCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgEnvelopedDataDecrypt
 *		解密数字信封
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		cipher：输入参数，密文
 *		cipherlen：输入参数，密文长度
 *		clear：输出参数，明文
 *		clearlen：输出参数，返回的明文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecrypt(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *cipher,int cipherlen,unsigned char **clear,int *clearlen);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptInit
 *		开始解密数字信封
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptInit(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptUpdate
 *		解密数字信封，可以调用多次。
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		cipher：输入参数，密文
 *		cipherlen：输入参数，密文长度
 *		clear：输出参数，明文
 *		clearlen：输出参数，返回的明文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptUpdate(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *cipher,int cipherlen,unsigned char **clear,int *clearlen);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptFinal
 *		结束解密数字信封。
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptFinal(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataSetPwd
 *		设置密码。不建议使用
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		pwd：输入参数，密码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetPwd(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const char *pwd);

/*
 *	NetcaPKIMsgEnvelopedDataSetKey
 *		设置解密的对称密钥
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		key：输入参数，解密使用的对称密钥
 *		keyLen:输入参数，解密使用的对称密钥长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetKey(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const unsigned char *key,int keyLen);

/*
 *	NetcaPKIMsgEnvelopedDataGetEncAlgorithm
 *		获取数字信封的对称加密算法。
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回对称加密算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataGetEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataGetCert
 *		获取数字信封的解密证书。
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		成功返回解密证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgEnvelopedDataGetCert(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataIsContentInfo
 *		判断数字信封的是否为ContentInfo封装
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *	返回值：
 *		是返回1，不是返回0
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataIsContentInfo(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode
 *		获取数字信封的接收者信息的编码
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		recipientInfos：输出参数，接收者信息的编码
 *		recipientInfosLen：输出参数，返回的接收者信息的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，NETCA_PKI_NEED_MORE_DATA表示还无法判断，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, unsigned char **recipientInfos ,int *recipientInfosLen);


/*
 *	NetcaPKIMsgEnvelopedDataMaybe
 *		判断是否可能是数字信封
 *	参数：
 *		data：输入参数，数字信封编码的前面部分
 *		dataLen：输入参数，data的长度
 *	返回值：
 *		可能是返回1，不是返回0
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataMaybe(const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgEnvelopedDataSetPromptMsg
 *		设置解密时的提示信息。
 *	参数：
 *		hEnvelopedData：数字信封句柄
 *		flag：输入参数，NETCA_PKI_PROMTMSG_FLAG_NO_ARGUMENT表示没有参数，直接显示msg。
 *		msg：输入参数，提示信息。UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetPromptMsg(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int flag,const char *msg);

/*
 *	NetcaPKIMsgNewSignedData
 *		创建SignedData句柄
 *	参数：
 *		sign：输入参数，为真表示先用于签名，为假表示先用于验证。
 *	返回值：
 *		成功返回有效的SignedData句柄，失败返回NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgNewSignedData(int sign);


/*
 *	NetcaPKIMsgFreeSignedData
 *		释放SignedData句柄
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeSignedData(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataSetIntegerAttribute
 *		设置SignedData的整数属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		atrrId：输入参数，属性ID
 *		index：输入参数，索引值，从0算起。某些属性会忽略这个值
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetIntegerAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,int value);


/*
 *	NetcaPKIMsgSignedDataSetStringAttribute
 *		设置SignedData的字符串属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		atrrId：输入参数，属性ID
 *		index：输入参数，索引值，从0算起。某些属性会忽略这个值
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetStringAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,const char *value);

/*
 *	NetcaPKIMsgSignedDataSetSignCert
 *		设置SignedData的签名证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		cert：签名证书
 *		pwd：输入参数，密码。可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSignCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd);

/*
 *	NetcaPKIMsgSignedDataSetEncCert
 *		设置SignedData的签名者对应的加密证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名索引值
 *		flag:输入参数，加密证书的标志参数
 *		cert：加密证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetEncCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, int index,int flag,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedDataAddCert
 *		为SignedData的添加证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		cert：证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedDataAddCRL
 *		为SignedData的添加CRL
 *	参数：
 *		hSignedData：SignedData句柄
 *		crl：输入参数，CRL的编码
 *		crlLen:输入参数，CRL的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCRL(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *crl,int crlLen);

/*
 *	NetcaPKIMsgSignedDataAddOCSP
 *		为SignedData的添加OCSP
 *	参数：
 *		hSignedData：SignedData句柄
 *		flag：输入参数，标志，当前为0
 *		vaCert：输入参数，OCSP的证书
 *		ocsp：输入参数，OCSP的编码
 *		ocspLen:输入参数，OCSP的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddOCSP(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int flag,NETCA_PKI_CERTIFICATE_HANDLE vaCert,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKIMsgSignedDataSetCryptoHandle
 *		设置SignedData句柄Hash使用的设备句柄
 *	参数：
 *		hSignedData：SignedData句柄
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCryptoHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKIMsgSignedDataAddSignedAttribute
 *		添加签名属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		attrType：输入参数，属性类型
 *		attrValue：输入参数，属性值的DER编码
 *		attrValueLen：输入参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddSignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKIMsgSignedDataAddUnsSignedAttribute
 *		添加未签名属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		attrType：输入参数，属性类型
 *		attrValue：输入参数，属性值的DER编码
 *		attrValueLen：输入参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKIMsgSignedDataDeleteUnsignedAttribute
 *		删除未签名属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		attrType：输入参数，属性类型
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDeleteUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType);

/*
 *	NetcaPKIMsgSignedDataSetCompleteCertificateRefs
 *		设置CompleteCertificateRefs属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		hashAlgo：输入参数，Hash算法
 *		hasIssuerSN：输入参数，是否使用颁发者名和序列号
 *		certs：输入参数，CA证书
 *		certCount：输入参数，CA证书的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCompleteCertificateRefs(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,int hasIssuerSN,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount);

/*
 *	NetcaPKIMsgSignedDataAddCompleteRevocationRef
 *		添加CompleteRevocationRefs属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		flag：输入参数，标志
 *		hashAlgo：输入参数，Hash算法
 *		crlData：输入参数，CRL的编码
 *		crlDataLen：输入参数，CRL的编码长度
 *		ocsp：输入参数，OCSP响应的编码
 *		ocspLen：输入参数，OCSP响应的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCompleteRevocationRef(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int flag,int hashAlgo,const unsigned char *crlData,int crlDataLen,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKIMsgSignedDataSetCertificateValues
 *		设置CertificateValues属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		certs：输入参数，CA证书
 *		certCount：输入参数，CA证书的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCertificateValues(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount);

/*
 *	NetcaPKIMsgSignedDataSetRevocationValues
 *		设置RevocationValues属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		crls：输入参数，CRL编码的数组
 *		crlsLen：输入参数，CRL编码长度的数组
 *		crlCount：输入参数，CRL的个数
 *		ocsps：输入参数，OCSP编码的数组
 *		ocspsLen：输入参数，OCSP编码长度的数组
 *		ocspCount：输入参数，OCSP个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetRevocationValues(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount);

/*
 *	NetcaPKIMsgSignedDataSetAdbeRevocationInfoArchival
 *		设置Adbe RevocationInfoArchival属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		crls：输入参数，CRL编码的数组
 *		crlsLen：输入参数，CRL编码长度的数组
 *		crlCount：输入参数，CRL的个数
 *		ocsps：输入参数，OCSP编码的数组
 *		ocspsLen：输入参数，OCSP编码长度的数组
 *		ocspCount：输入参数，OCSP个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetAdbeRevocationInfoArchival(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount);

/*
 *	NetcaPKIMsgSignedDataEncode
 *		对SignedData再次进行编码，通常用于添加完未签名属性后
 *	参数：
 *		hSignedData：SignedData句柄
 *		sign：输出参数，签名值
 *		signLen：输出参数，返回的sign长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataEncode(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char **sign,int *signLen);

/*
 *	NetcaPKIMsgSignedDataSetSignCallback
 *		设置签名的回调函数
 *	参数：
 *		hSignedData：SignedData句柄
 *		callback：回调函数
 *		context：回调函数的参数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSignCallback(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NetcaSignedDataSignHashCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgSignedDataSign
 *		进行签名。这个函数一次返回签名的结果
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文
 *		tbslen：输入参数，tbs的长度
 *		sign：输出参数，签名值
 *		signlen：输出参数，返回的sign长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSign(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *tbs,int tbslen, unsigned char **sign,int *signlen);


/*
 *	NetcaPKIMsgSignedDataCountersign
 *		连署签名
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引号
 *		algo：输入参数，签名算法 
 *		cert：输入参数，签名证书
 *		pwd：输出参数，密码
 *		sign：输出参数，签名值
 *		signlen：输出参数，返回的sign长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataCountersign(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int algo,NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,unsigned char **sign,int *signlen);

/*
 *	NetcaPKIMsgSignedDataSignWithTimeStamp
 *		进行带时间戳签名。这个函数一次返回签名的结果
 *	参数：
 *		hSignedData：SignedData句柄
 *		tsaName：输入参数，时间戳服务器的名称
 *		tbs：输入参数，原文
 *		tbslen：输入参数，tbs的长度
 *		sign：输出参数，签名值
 *		signlen：输出参数，返回的sign长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignWithTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const char *tsaName, const unsigned char *tbs,int tbslen, unsigned char **sign,int *signlen);

/*
 *	NetcaPKIMsgSignedDataSetContentTimeStamp
 *		添加content-time-stamp。必须在原文输入之前调用
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetContentTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAttachSignatureTimeStamp
 *		添加Signature-time-stamp。如果原来存在Signature-time-stamp，则用新的替换掉旧的
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachSignatureTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddEscTimeStamp
 *		添加ES-C Timestamp Attribute。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddEscTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddCertCRLTimeStamp
 *		添加Time-Stamped Certificates and CRLs。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCertCRLTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV2
 *		添加archive-time-stamp V2 Attribute。
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文。如果SignedData句柄中保留有原文，则忽略该参数
 *		tbsLen：输入参数，原文长度
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV2(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV3
 *		添加archive-time-stamp V3 Attribute。
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文。如果SignedData句柄中保留有原文，则忽略该参数
 *		tbsLen：输入参数，原文长度
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV3ByHashValue
 *		添加archive-time-stamp V3 Attribute。
 *	参数：
 *		hSignedData：SignedData句柄
 *		hashAlgo：输入参数，Hash算法
 *		hashValue：输入参数，原文的Hash值
 *		hashLen：输入参数，原文的Hash长度
 *		tsaName：输入参数，时间戳服务器的名称
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV3ByHashValue(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const unsigned char *hashValue,int hashLen,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAttachATSHashIndex
 *		添加ats-hash-index。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachATSHashIndex(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo);

/*
 *	NetcaPKIMsgSignedDataAttachATSHashIndexV3
 *		添加ats-hash-index-v3。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引值
 *		hashAlgo：输入参数，Hash算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachATSHashIndexV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo);

/*
 *	NetcaPKIMsgSignedDataSignInit
 *		进行多步签名的初始化
 *	参数：
 *		hSignedData：SignedData句柄
 *		out：输出参数，输出的结果
 *		outlen：输出参数，返回的out长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignUpdate
 *		进行多步签名的原文输入，可以调用多次
 *	参数：
 *		hSignedData：SignedData句柄
 *		in：输入参数，输入的数据
 *		inlen：输入参数，in的长度
 *		out：输出参数，输出的结果
 *		outlen：输出参数，返回的out长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *in,int inlen ,unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignFinal
 *		进行签名，结束多步签名
 *	参数：
 *		hSignedData：SignedData句柄
 *		out：输出参数，输出的结果
 *		outlen：输出参数，返回的out长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignWithTimeStampFinal
 *		进行带时间戳的签名，结束多步签名
 *	参数：
 *		hSignedData：SignedData句柄
 *		tsaName：输入参数，时间戳服务器的名称
 *		out：输出参数，输出的结果
 *		outlen：输出参数，返回的out长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignWithTimeStampFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const char *tsaName,unsigned char **out,int *outlen);


/*
 *	NetcaPKIMsgSignedDataGetCert
 *		获取SignedData的证书
 *	参数：
 *		sign：输入参数，SignedData的编码值
 *		signlen：输入参数，sign的长度
 *		certs：输出参数，返回的证书数组
 *		count：输出参数，返回的证书数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCert(const unsigned char *sign,int signlen, NETCA_PKI_CERTIFICATE_HANDLE **certs,int* count);

/*
 *	NetcaPKIMsgSignedDataGetCertificates
 *		获取SignedData的证书
 *	参数：
 *		hSignedData：输入参数，SignedData句柄
 *		certs：输出参数，返回的证书数组
 *		count：输出参数，返回的证书数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCertificates(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_CERTIFICATE_HANDLE **certs,int* count);

/*
 *	NetcaPKIMsgSignedDataGetCertificateSet
 *		获取SignedData的证书编码，也就是SignedData.certificates
 *	参数：
 *		hSignedData：输入参数，SignedData句柄
 *		certs：输出参数，返回的证书编码的数组
 *		certLen：输出参数，返回的证书编码的长度数组
 *		count：输出参数，返回的证书的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCertificateSet(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***certs, int **certLen,int* count);


/*
 *	NetcaPKIMsgSignedDataGetCRLs
 *		获取SignedData的CRL
 *	参数：
 *		hSignedData：输入参数，SignedData句柄
 *		crls：输出参数，返回的CRL编码的数组
 *		crlLen：输出参数，返回的CRL编码的长度数组
 *		count：输出参数，返回的CRL个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCRLs(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***crls, int **crlLen,int* count);

/*
 *	NetcaPKIMsgSignedDataGetRevocationInfoChoices
 *		获取SignedData的作废信息编码，也就是SignedData.crls
 *	参数：
 *		hSignedData：输入参数，SignedData句柄
 *		crls：输出参数，返回的作废信息编码的数组
 *		crlLen：输出参数，返回的作废信息编码的长度数组
 *		count：输出参数，返回的作废信息的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetRevocationInfoChoices(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***crls, int **crlLen,int* count);

/*
 *	NetcaPKIMsgSignedDataAddRootCert
 *		添加根证书，为验证做准备
 *	参数：
 *		hSignedData：SignedData句柄
 *		rootCert：根证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddRootCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_CERTIFICATE_HANDLE rootCert);

/*
 *	NetcaPKIMsgSignedDataSetSigningCertificateAttribute
 *		设置SigningCertificate或者SigningCertificateV2属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值
 *		hashAlgo：输入参数，Hash算法，如果为SHA-1则设置SigningCertificate属性，否则设置SigningCertificateV2属性
 *		includeIssuerSerial：输入参数，为真则包括颁发者序列号，为加则不包括
 *		certs:输入参数，证书
 *		certCount：输入参数，证书个数
 *		policies：输入参数，证书策略的编码
 *		policiesLen：输入参数，证书策略的编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSigningCertificateAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,int includeIssuerSerial,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount,const unsigned char *policies,int policiesLen);


/*
 *	NetcaPKIMsgSignedDataVerify
 *		验证带原文的签名。这是一步完成的操作
 *	参数：
 *		hSignedData：SignedData句柄
 *		sign：输入参数，SignedData的编码值
 *		signlen：输入参数，sign的长度
 *		tbs：输出参数，返回的原文
 *		tbslen：输出参数，原文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerify(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *sign,int signlen,unsigned char **tbs,int *tbslen);

/*
 *	NetcaPKIMsgSignedDataVerifyTimeStamp
 *		验证时间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值
 *		tsaCert：输入参数，时间戳证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE tsaCert);

/*
 *	NetcaPKIMsgSignedDataGetTimeStampHandle
 *		获取时间戳句柄。必须验证时间戳成功后，才能调用成功
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值
 *	返回值：
 *		成功返回时间戳句柄，失败返回NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetTimeStampHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataVerifyContentTimeStamp
 *		验证Content时间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyContentTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyEscTimeStamp
 *		验证ES-C时间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyEscTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyCertCRLTimeStamp
 *		验证CertCRL时间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyCertCRLTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV2
 *		验证archive-time-stamp V2间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		signedData：输入参数，SignedData编码
 *		signedDataLen：输入参数，SignedData编码的长度
 *		tbs：输入参数，原文，仅对不带原文的签名，且SignedData句柄中不保留有原文有效
 *		tbsLen：输入参数，原文长度
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV2(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3
 *		验证archive-time-stamp V3间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文，仅对SignedData句柄中不保留有原文有效
 *		tbsLen：输入参数，原文长度
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3ByHashValue
 *		验证archive-time-stamp V3间戳。
 *	参数：
 *		hSignedData：SignedData句柄
 *		hashValue：输入参数，原文的Hash值
 *		hashLen：输入参数，Hash长度
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *		tsaCert：输入参数，时间戳证书
 *		phTimeStamp：输出参数，时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3ByHashValue(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *hashValue,int hashLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataGetArchiveTimeStampV3HashAlgo
 *		验证archive-time-stamp V3间戳的Hash算法。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名值索引
 *		tsIndex：输入参数，时间戳索引
 *	返回值：
 *		成功返回archive-time-stamp V3间戳的Hash算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetArchiveTimeStampV3HashAlgo(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex);

/*
 *	NetcaPKIMsgSignedDataDecodeAttributeForATSHashIndexV3
 *		把属性编码转换为ATSHashIndexV3需要的各项编码
 *	参数：
 *		attrEncode：输入参数，属性的编码
 *		attrLen：输入参数，属性编码的长度
 *		data：输出参数，返回的数据项编码的数组
 *		dataLen：输出参数，返回的数据项的长度数组
 *		count：输出参数，返回的数据项的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDecodeAttributeForATSHashIndexV3(const unsigned char *attrEncode,int attrLen,unsigned char ***data, int **dataLen,int* count);

/*
 *	NetcaPKIMsgSignedDataVerifyCountersignature
 *		验证连署签名。
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值
 *		countersignIndex：输入参数，连署签名索引值，从0算起。
 *		cert：输入参数，签名证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyCountersignature(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int countersignIndex,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKIMsgSignedDataVerifyInit
 *		初始化验证带原文的签名
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataVerifyUpdate
 *		多次输入SignedData的编码值进行带原文的签名验证
 *	参数：
 *		hSignedData：SignedData句柄
 *		sign：输入参数，SignedData的编码值
 *		signlen：输入参数，sign的长度
 *		tbs：输出参数，返回的原文
 *		tbslen：输出参数，原文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char * sign,int signlen, unsigned char **tbs,int *tbslen);

/*
 *	NetcaPKIMsgSignedDataVerifyFinal
 *		结束带原文的签名验证
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataDetachedVerifyInit
 *		初始化验证不带原文的签名
 *	参数：
 *		hSignedData：SignedData句柄
 *		sign：输入参数，签名值
 *		signlen：输入参数,sign的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *sign,int signlen);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyUpdate
 *		输入不带原文的签名对应的原文
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文
 *		tbslen：输入参数，tbs的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,int tbslen);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyFinal
 *		结束不带原文的签名的验证。
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyHash
 *		输入Hash值进行不带原文的签名的验证
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名者索引
 *		hash：输入参数，Hash值
 *		hashlen：输入参数,Hash值的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyHash(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *hash,int hashlen);


/*
 *	NetcaPKIMsgSignedDataDetachedVerify
 *		验证不带原文的签名
 *	参数：
 *		hSignedData：SignedData句柄
 *		tbs：输入参数，原文
 *		tbslen：输入参数，tbs的长度
 *		sign：输入参数，签名值
 *		signlen：输入参数,sign的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerify(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,int tbslen,const unsigned char *sign,int signlen);

/*
 *	NetcaPKIMsgSignedDataSetGetCertCallback
 *		设置获取签名证书的回调函数
 *	参数：
 *		hSignedData：SignedData句柄
 *		callback：回调函数
 *		context：回调函数的参数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetGetCertCallback(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NetcaSignedDataGetCertCallback_Ptr callback,void *context);


/*
 *	NetcaPKIMsgSignedDataGetIntegerAttribute
 *		获取SignedData的整数属性。
 *	参数：
 *		hSignedData：SignedData句柄
 *		atrrId：输入参数，属性ID
 *		index：输入参数，索引值，从0算起。某些属性会忽略这个值
 *		value：输出参数，返回属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetIntegerAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,int *value);


/*
 *	NetcaPKIMsgSignedDataGetStringAttribute
 *		获取SignedData的字符串属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		atrrId：输入参数，属性ID
 *		index：输入参数，索引值，从0算起。某些属性会忽略这个值
 *		value：输出参数，返回属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetStringAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,char **value);


/*
 *	NetcaPKIMsgSignedDataGetSignedAttribute
 *		获取签名属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名索引值，从0算起。
 *		attrIndex：输入参数，属性索引值，从0算起。
 *		attrType：输出参数，属性类型
 *		attrValue：输出参数，属性值的DER编码
 *		attrValueLen：输出参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetSignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIMsgSignedDataGetUnsignedAttribute
 *		获取不签名属性
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名索引值，从0算起。
 *		attrIndex：输入参数，属性索引值，从0算起。
 *		attrType：输出参数，属性类型
 *		attrValue：输出参数，属性值的DER编码
 *		attrValueLen：输出参数，属性值的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIMsgSignedDataGetUnsignedAttributeEncode
 *		获取不签名属性的编码
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，签名索引值，从0算起。
 *		attrIndex：输入参数，属性索引值，从0算起。
 *		attrEncode：输出参数，属性的编码
 *		attrEncodeLen：输出参数，属性的编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetUnsignedAttributeEncode(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,unsigned char **attrEncode,int *attrEncodeLen);

/*
 *	NetcaPKIMsgSignedDataGetSignCert
 *		获取SignedData的第index个签名证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *	返回值：
 *		成功返回签名证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetSignCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataGetVerifyHandle
 *		获取SignedData的第index个签名的证书验证句柄
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *	返回值：
 *		成功返回第index个签名的证书验证句柄，失败返回NULL
 *
 */
NETCA_PKI_CERT_VERIFY_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetVerifyHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataGetEncCert
 *		获取SignedData的第index个签名者对应的加密证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		cert:输出参数，成功返回加密证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetEncCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE *cert);

/*
 *	NetcaPKIMsgSignedDataGetTSACert
 *		获取SignedData的第index个签名中的时间戳签名的证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *	返回值：
 *		成功返回时间戳签名的证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetTSACert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);


/*
 *	NetcaPKIMsgSignedDataGetCountersignatureCert
 *		获取SignedData的第index个签名的第countersignIndex个连署签名的证书
 *	参数：
 *		hSignedData：SignedData句柄
 *		index：输入参数，索引值，从0算起。
 *		countersignIndex：输入参数，连署签名索引值，从0算起。
 *	返回值：
 *		成功返回签名证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetCountersignatureCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int countersignIndex);

/*
 *	NetcaPKIMsgSignedDataMaybe
 *		判断是否可能是SignedData
 *	参数：
 *		data：输入参数，SignedData的前面部分
 *		dataLen：输入参数，data的长度
 *		detached：输出参数，如果带原文返回0，不带返回1
 *	返回值：
 *		可能是返回1，不是返回0
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataMaybe(const unsigned char *data,int dataLen,int *detached);

/*
 *	NetcaPKIMsgSignedDataSetPromptMsg
 *		设置签名时的提示信息。
 *	参数：
 *		hSignedData：SignedData句柄
 *		flag：输入参数，NETCA_PKI_PROMTMSG_FLAG_NO_ARGUMENT表示没有参数，直接显示msg。
 *		msg：输入参数，提示信息。UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetPromptMsg(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int flag,const char *msg);


/* 时间戳相关函数 */
/*
 *	NetcaPKIMsgNewTimeStamp
 *		创建时间戳句柄。
 *	参数：
 *		无
 *	返回值：
 *		成功返回时间戳句柄，失败返回NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgNewTimeStamp(void);


/*
 *	NetcaPKIMsgFreeTimeStamp
 *		释放时间戳句柄。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeTimeStamp(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);


/*
 *	NetcaPKIMsgTimeStampSetTSA
 *		设置时间戳服务器。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		tsaurl：输入参数，TSA的URL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetTSA(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *tsaurl);

/*
 *	NetcaPKIMsgTimeStampSetHashAlgorithm
 *		设置时间戳请求的Hash算法。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		algo：输入参数，时间戳Hash算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetHashAlgorithm(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int algo);


/*
 *	NetcaPKIMsgTimeStampSetMessageImprint
 *		设置要发送给时间戳服务器的Hash值。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		hash：输入参数，Hash值
 *		hashlen：输入参数，Hash长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetMessageImprint(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const unsigned char *hash,int hashlen);

/*
 *	NetcaPKIMsgTimeStampGetReqEncode
 *		获取时间戳请求的DER编码。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		encode：输出参数，返回时间戳请求的DER编码
 *		encodeLen：输出参数，返回时间戳请求的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetReqEncode(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **encode,int *encodeLen);

/*
 *	NetcaPKIMsgTimeStampGetResponse
 *		向时间戳服务器发送响应，并验证和获取时间值。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		status：输出参数，返回时间戳响应状态
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetResponse(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *status);

/*
 *	NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse
 *		从时间戳响应编码获取时间戳Token的编码。
 *	参数：
 *		resp：输入参数，时间戳响应的DER编码
 *		respLen：输入参数，时间戳响应的DER编码的长度
 *		status：输出参数，返回时间戳响应状态
 *		token：输出参数，返回的时间戳token编码值
 *		tokenLen：输出参数，返回token的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse(const unsigned char *resp,int respLen,int *status,unsigned char **token,int *tokenLen);

/*
 *	NetcaPKIMsgTimeStampGetTimeStampToken
 *		获取时间戳编码。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		token：输出参数，返回的时间戳编码值
 *		ptokenlen：输出参数，返回token的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTimeStampToken(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **token,int *ptokenlen);

/*
 *	NetcaPKIMsgTimeStampGetTSACert
 *		获取时间戳证书
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间戳证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgTimeStampGetTSACert(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);


/*
 *	NetcaPKIMsgVerifyTimeStampToken
 *		验证时间戳的编码
 *	参数：
 *		token：输入参数，时间戳编码
 *		tokenlen：输入参数，token的长度
 *		cert：时间戳证书，可以为NULL
 *	返回值：
 *		成功返回时间戳句柄，失败返回NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgVerifyTimeStampToken(const unsigned char *token,int tokenlen,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKIMsgVerifyTimeStampTokenBySignedDataHandle
 *		验证时间戳的编码
 *	参数：
 *		token：输入参数，时间戳编码
 *		tokenlen：输入参数，token的长度
 *		hSignedData：SignedData验证句柄
 *		hTimeStamp：输出参数，成功返回时间戳句柄
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgVerifyTimeStampTokenBySignedDataHandle(const unsigned char *token,int tokenlen,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);


/*
 *	NetcaPKIMsgTimeStampGetHashAlgorithm
 *		获得时间戳的Hash算法
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间戳使用的Hash算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetHashAlgorithm(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetMessageImprint 
 *		获得发送给时间戳的Hash值
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		hash：输出参数，返回Hash值
 *		phashlen：输出参数，返回Hash长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetMessageImprint(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **hash,int *phashlen);

/*
 *	NetcaPKIMsgTimeStampGetTime 
 *		获取时间戳
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间值，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetTime(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetPolicy 
 *		获取时间戳策略
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间戳策略OID，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetPolicy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampSetPolicy 
 *		设置时间戳策略
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		policy：时间戳策略OID
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetPolicy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *policy);

/*
 *	NetcaPKIMsgTimeStampGetSerialNumber 
 *		获取时间戳的序列号
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间戳的序列号，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetSerialNumber(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetNonce 
 *		获取时间戳的Nonce值
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		nonce：输出参数，返回Nonce值
 *		nonceLen：输出参数，返回Nonce长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetNonce(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **nonce,int *nonceLen);

/*
 *	NetcaPKIMsgTimeStampSetNonce 
 *		设置时间戳的Nonce值
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		flag：输入参数，NETCA_PKI_TIMESTAMP_NONCE_FLAG_NONE表示不要Nonce，NETCA_PKI_TIMESTAMP_NONCE_FLAG_RANDOM表示使用随机产生的nonceLen字节的Nonce，NETCA_PKI_TIMESTAMP_NONCE_FLAG_FIX表示使用nonce作为Nonce
 *		nonce：输入参数，Nonce值，NETCA_PKI_TIMESTAMP_NONCE_FLAG_FIX有效
 *		nonceLen：输入参数，Nonce长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetNonce(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int flag,const unsigned char *nonce,int nonceLen);


/*
 *	NetcaPKIMsgTimeStampSetCertReq
 *		设置时间戳请求的是否要求响应带证书。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		certReq：输入参数，为真表示要求响应带证书，为假表示要求响应不带证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetCertReq(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int certReq);

/*
 *	NetcaPKIMsgTimeStampGetCertReq
 *		判断时间戳请求的是否要求响应带证书。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		pCertReq：输出参数，为真表示要求响应带证书，为假表示要求响应不带证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetCertReq(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *pCertReq);

/*
 *	NetcaPKIMsgTimeStampSetTSACert
 *		设置时间戳证书，用于验证响应。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		cert：输入参数，时间戳证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetTSACert(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgTimeStampGetSignedData
 *		获得时间戳的SignedData句柄
 *	参数：
 *		hTimeStamp：时间戳句柄
 *	返回值：
 *		成功返回时间戳的SignedData句柄，失败返回NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgTimeStampGetSignedData(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetAccuracy
 *		获得时间戳的时间精度
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		seconds：输出参数，秒
 *		millis：输出参数，毫秒
 *		micros：输出参数，微秒
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，响应中没有精度返回NETCA_PKI_NOTEXISIT，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetAccuracy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *seconds,int *millis,int *micros);


/*
 *	NetcaPKIMsgTimeStampAddReqExt 
 *		添加时间戳请求的扩展
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		oid：输入参数，扩展OID
 *		critical：输入参数，扩展是否关键
 *		value：输入参数，扩展值的编码
 *		valueLen：输入参数，扩展值的编码长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampAddReqExt(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *oid,int critical,const unsigned char *value,int valueLen);

/*
 *	NetcaPKIMsgTimeStampGetTSTInfo
 *		获取时间戳的TSTInfo编码。
 *	参数：
 *		hTimeStamp：时间戳句柄
 *		tstInfo：输出参数，返回的时间戳TSTInfo编码值
 *		pTstInfoLen：输出参数，返回TSTInfo编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTSTInfo(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **tstInfo,int *pTstInfoLen);

/*
 *	NetcaPKIMsgAuthenticodeSign 
 *		对文件进行Authenticode方式的代码签名。
 *	参数：
 *		fileName：输入参数，文件名。文件必须可读可写。使用前请保留文件副本，因为失败可能也会改写文件
 *		flag：输入参数，标志
 *		hashAlgo:输入参数，对文件进行Hash的Hash算法
 *		signAlgo:输入参数，签名算法
 *		cert：签名证书，必须有私钥
 *		otherCerts:输入参数，其他证书数组，在flag的NETCA_PKI_AUTHENTICODE_FLAG_DONTBUILDCERTPATH置位是有效，表示使用这些证书代替构造的证书路径，otherCerts不应该包含签名证书，因为签名中总是包含签名证书的
 *		otherCertCount:输入参数，其他证书个数
 *		description:输入参数，描述，可以为NULL。UTF-8编码
 *		publisherUrl:输入参数，开发商的URL,可以为NULL。
 *		tsaUrl：输入参数，时间戳服务器地址，可以为NULL。
 *		reserve:保留参数，当前未使用
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgAuthenticodeSign(const char *fileName,int flag,int hashAlgo,int signAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_CERTIFICATE_HANDLE* otherCerts,int otherCertCount,const char *description,const char *publisherUrl,const char *tsaUrl,void *reserve);

#ifdef __cplusplus
	}	
#endif
#endif

