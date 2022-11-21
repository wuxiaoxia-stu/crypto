#ifndef _NETCA_PKI_CONFIG_INLCUDE_H_
#define _NETCA_PKI_CONFIG_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIConfigSetSelectCertPolicy 
 *		设置证书的选择策略
 *	参数：
 *		policy：输入参数，选择证书的策略
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetSelectCertPolicy(const char* policy);


/*
 *	NetcaPKIConfigGetSelectCertPolicy 
 *		获取证书的选择策略
 *	参数：
 *		无
 *	返回值：
 *		成功返回证书的选择策略，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetSelectCertPolicy(void);


/*
 *	NetcaPKIConfigSetFilterCertCondition 
 *		设置证书的选择策略
 *	参数：
 *		condition：输入参数，过滤证书的条件
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetFilterCertCondition(const char* condition);


/*
 *	NetcaPKIConfigGetFilterCertCondition 
 *		获取过滤证书的条件
 *	参数：
 *		无
 *	返回值：
 *		成功返回过滤证书的条件，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetFilterCertCondition(void);


/*
 *	NetcaPKIConfigReset 
 *		重新获取默认的配置
 *	参数：
 *		无
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigReset(void);

/*
 *	NetcaPKIConfigGetSignAlgo 
 *		获取签名算法
 *	参数：
 *		cert：输入参数，签名证书
 *		param：输出参数，签名算法参数，可以为NULL
 *	返回值：
 *		成功返回签名算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIConfigGetSignAlgo(NETCA_PKI_CERTIFICATE_HANDLE cert,void **param);

/*
 *	NetcaPKIConfigSetSignAlgo 
 *		设置签名算法
 *	参数：
 *		publicKeyType：输入参数，公钥类型，RSA、SM2等
 *		algo：输入参数，签名算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetSignAlgo(const char* publicKeyType,int algo);


/*
 *	NetcaPKIConfigGetPublicKeyEncryptAlgo 
 *		获取公钥加密算法
 *	参数：
 *		cert：输入参数，加密证书
 *		param：输出参数，公钥加密算法参数，可以为NULL
 *	返回值：
 *		成功返回公钥加密算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIConfigGetPublicKeyEncryptAlgo(NETCA_PKI_CERTIFICATE_HANDLE cert,void **param);

/*
 *	NetcaPKIConfigSetPublicKeyEncryptAlgo 
 *		设置公钥加密算法
 *	参数：
 *		publicKeyType：输入参数，公钥类型，RSA、SM2等
 *		algo：输入参数，公钥加密算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetPublicKeyEncryptAlgo(const char* publicKeyType,int algo);


/*
 *	NetcaPKIConfigEnvelopedDataGetEncryptAlgo 
 *		获取数字信封的对称加密算法
 *	参数：
 *		无
 *	返回值：
 *		成功返回数字信封的对称加密算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataGetEncryptAlgo(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetEncryptAlgo 
 *		设置数字信封对称加密算法
 *	参数：
 *		algo：输入参数，数字信封对称加密算法
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetEncryptAlgo(int algo);


/*
 *	NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier 
 *		获取数字信封的是否使用主体密钥标识表标识加密证书
 *	参数：
 *		无
 *	返回值：
 *		返回数字信封的是否使用主体密钥标识表标识加密证书
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier 
 *		设置数字信封的是否使用主体密钥标识表标识加密证书
 *	参数：
 *		value：输入参数，为真表示使用，为假表示不使用
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier(int value);

/*
 *	NetcaPKIConfigSetPwdCacheOption 
 *		设置是否进行密码缓存
 *	参数：
 *		option：输入参数，1为不缓存，0为缓存，-1为不缓存且清掉以前的缓存
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetPwdCacheOption(int option);

/*
 *	NetcaPKIConfigGetPwdCacheOption 
 *		获取是否进行密码缓存
 *	参数：
 *		无
 *	返回值：
 *		成功返回是否进行密码缓存，失败返回-2
 *
 */
int NETCADLLAPI NetcaPKIConfigGetPwdCacheOption(void);

/*
 *	NetcaPKIConfigSignedDataGetIncludeCertOption 
 *		获取SignedData的包含证书选项
 *	参数：
 *		无
 *	返回值：
 *		成功返回SignedData的包含证书选项，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIConfigSignedDataGetIncludeCertOption(void);


/*
 *	NetcaPKIConfigSignedDataSetIncludeCertOption 
 *		设置SignedData的包含证书选项
 *	参数：
 *		option:输入参数，SignedData的包含证书选项
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSignedDataSetIncludeCertOption(int option);


/*
 *	NetcaPKIConfigSetConfig 
 *		设置配置
 *	参数：
 *		config:输入参数，配置的JSON编码，UTF-8格式
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigSetConfig(const char* config);

/*
 *	NetcaPKIConfigGetConfig 
 *		获取配置
 *	参数：
 *		无
 *	返回值：
 *		成功返回配置的JSON编码，UTF-8格式，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetConfig(void);

/*
 *	NetcaPKIAppCertEncrypt 
 *		使用证书进行非对称加密
 *	参数：
 *		cert:输入参数，加密证书
 *		clearText:输入参数，明文
 *		clearTextLen:输入参数，明文长度
 *		cipherText:输出参数，成功返回密文
 *		cipherTextLen:输出参数，成功返回密文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppCertEncrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* clearText,int clearTextLen,unsigned char** cipherText,int* cipherTextLen);

/*
 *	NetcaPKIAppCertDecrypt 
 *		使用证书对应的私钥进行非对称加密
 *	参数：
 *		cert:输入参数，加密证书
 *		cipherText:输入参数，密文
 *		cipherTextLen:输入参数，密文长度
 *		clearText:输出参数，成功返回明文
 *		clearTextLen:输出参数，成功返回明文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppCertDecrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* cipherText,int cipherTextLen,unsigned char** clearText,int* clearTextLen);

/*
 *	NetcaPKIAppSign 
 *		使用证书对应的私钥进行签名
 *	参数：
 *		cert:输入参数，签名证书
 *		tbs:输入参数，原文
 *		tbsLen:输入参数，原文长度
 *		signature:输出参数，成功返回签名值
 *		signatureLen:输出参数，成功返回签名值长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSign(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* tbs,int tbsLen,unsigned char** signature,int* signatureLen);

/*
 *	NetcaPKIAppVerify 
 *		使用证书进行验证
 *	参数：
 *		cert:输入参数，签名证书
 *		tbs:输入参数，原文
 *		tbsLen:输入参数，原文长度
 *		signature:输入参数，签名值
 *		signatureLen:输入参数，签名值长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppVerify(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* tbs,int tbsLen,const unsigned char* signature,int signatureLen);

/*
 *	NetcaPKIAppEnvelopedDataEncrypt 
 *		使用数字信封进行加密
 *	参数：
 *		cert:输入参数，签名证书
 *		clearText:输入参数，明文
 *		clearTextLen:输入参数，明文长度
 *		cipherText:输出参数，成功返回数字信封
 *		cipherTextLen:输出参数，成功返回数字信封长度
 *		hEnvelopedData:输出参数，成功返回数字信封句柄，可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataEncrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* clearText,int clearTextLen,unsigned char** cipherText,int* cipherTextLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);

/*
 *	NetcaPKIAppNewEnvelopedDataEncryptHandle 
 *		创建数字信封加密句柄
 *	参数：
 *		无
 *	返回值：
 *		成功返回有效的数字信封句柄，失败返回NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewEnvelopedDataEncryptHandle(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetDecryptCert 
 *		设置数字信封解密证书，证书必须有对应的密钥对
 *	参数：
 *		cert:输入参数，解密证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetDecryptCert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIAppEnvelopedDataDecrypt 
 *		解密数字信封
 *	参数：
 *		cipherText:输入参数，数字信封
 *		cipherTextLen：输入参数，数字信封的长度
 *		clearText：输出参数，成功返回明文
 *		clearTextLen：输出参数，成功返回明文的长度
 *		hEnvelopedData：输出参数，成功返回数字信封句柄，可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataDecrypt(const unsigned char* cipherText,int cipherTextLen,unsigned char** clearText,int* clearTextLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);


/*
 *	NetcaPKIAppNewEnvelopedDataDecryptHandle 
 *		创建数字信封解密句柄
 *	参数：
 *		无
 *	返回值：
 *		成功返回有效的数字信封句柄，失败返回NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewEnvelopedDataDecryptHandle(void);

/*
 *	NetcaPKIAppEnvelopedDataDecryptPostCheck 
 *		解密数字信封后检查是否符合配置
 *	参数：
 *		hEnvelopedData：输入参数，数字信封句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataDecryptPostCheck(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIAppSignedDataSign 
 *		进行SignedData签名
 *	参数：
 *		cert：输入参数，签名证书
 *		detached：输入参数，为真表示不带原文，否则带原文
 *		tbs：输入参数，要签名的数据
 *		tbsLen：输入参数，要签名的数据长度
 *		signature：输出参数，成功返回SignedData
 *		signatureLen：输出参数，成功返回SignedData长度
 *		hSignedData：输出参数，成功返回SignedData句柄，可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataSign(NETCA_PKI_CERTIFICATE_HANDLE cert,int detached,const unsigned char* tbs,int tbsLen,unsigned char** signature,int* signatureLen,NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIAppSignedDataApplySignConfig 
 *		使用配置信息进行设置SignedData签名
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataApplySignConfig(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIAppSignedDataVerify 
 *		验证SignedData签名
 *	参数：
 *		cert：输入参数，签名证书，可以为NULL，如果不为NULL，则必须为其中的一个签名证书
 *		tbs：输入参数，要签名的数据
 *		tbsLen：输入参数，要签名的数据长度
 *		signature：输入参数，SignedData
 *		signatureLen：输入参数，SignedData长度
 *		hSignedData：输出参数，成功返回SignedData句柄，可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataVerify(NETCA_PKI_CERTIFICATE_HANDLE cert, const unsigned char* tbs,int tbsLen, const unsigned char* signature,int signatureLen, NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIAppNewSignedDataVerifyHandle 
 *		根据配置创建验证SignedData签名的句柄
 *	参数：
 *		无
 *	返回值：
 *		成功返回有效的SignedData句柄，失败返回NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewSignedDataVerifyHandle(void);

/*
 *	NetcaPKIAppSignedDataVerifyPostCheck 
 *		验证SignedData后检查是否符合配置
 *	参数：
 *		hSignedData：SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataVerifyPostCheck(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);

/*
 *	NetcaPKIAppTimeStampGetToken 
 *		向时间戳服务器，获取时间戳Token
 *	参数：
 *		data：输入参数，要提交的数据
 *		dataLen：输入参数，要提交的数据的长度
 *		token：输出参数，成功返回时间戳Token
 *		tokenLen：输出参数，成功返回时间戳Token的长度
 *		hTimeStamp：输出参数，成功返回时间戳句柄,可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int  NETCADLLAPI NetcaPKIAppTimeStampGetToken(const unsigned char* data,int dataLen, unsigned char** token,int* tokenLen,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);

/*
 *	NetcaPKIAppTimeStampVerifyToken 
 *		验证时间戳Token
 *	参数：
 *		data：输入参数，要提交的数据
 *		dataLen：输入参数，要提交的数据的长度
 *		token：输入参数，时间戳Token
 *		tokenLen：输入参数，回时间戳Token的长度
 *		hTimeStamp：输出参数，成功返回时间戳句柄,可以为NULL
 *	返回值：
 *		成功返回时间戳时间，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppTimeStampVerifyToken(const unsigned char* data,int dataLen,const unsigned char* token,int tokenLen,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);

/*
 *	NetcaPKIAppSignedDataAttachTimeStamp 
 *		在签名中添加时间戳，如果已经存在时间戳，则用新的替代它。如果有多个签名值，只处理最后一个
 *	参数：
 *		hSignedData：SignedData句柄
 *		signature：输出参数，成功返回添加时间戳后的SignedData
 *		signatureLen：输出参数，成功返回添加时间戳后的SignedData的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataAttachTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char** signature,int* signatureLen);


/*
 *	NetcaPKIAppGetUserCert 
 *		获取用户证书
 *	参数：
 *		type：输入参数，证书类型
 *		condition：输入参数，选择证书的条件
 *	返回值：
 *		成功返回获取到的证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIAppGetUserCert(int type,const char* condition);

/*
 *	NetcaPKIAppCertGetKeypair 
 *		获取证书对应的密钥对句柄
 *	参数：
 *		cert：输入参数，证书
 *		pwd：输入参数，使用私钥需要的密码，通常不能为NULL
 *		hKeypair:输出参数，成功返回密钥对句柄，可以为NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppCertGetKeypair(NETCA_PKI_CERTIFICATE_HANDLE cert, const char *pwd,NETCA_PKI_KEYPAIR_HANDLE* hKeypair);

/*
 *	NetcaPKIAppCertGetStringExtension 
 *		获取证书的字符串类型的扩展的值
 *	参数：
 *		cert：输入参数，证书
 *		extOid：输入参数，扩展的OID
 *	返回值：
 *		成功返回UTF-8编码的扩展值，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppCertGetStringExtension(NETCA_PKI_CERTIFICATE_HANDLE cert,const char* extOid);

/*
 *	NetcaPKIAppDeviceGetDeviceId 
 *		获取当前连接的所有设备的ID，格式为设备类型#设备序列号
 *	参数：
 *		ids：输出参数，成功返回所有的设备的ID
 *		idCount：输出参数，成功返回设备的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceGetDeviceId(char*** ids,int* idCount);

/*
 *	NetcaPKIAppDeviceVerifyPwd 
 *		验证设备的密码
 *	参数：
 *		id：输入参数，设备的ID
 *		pwd：输入参数，设备的密码
 *		retryNum：输出参数，密码出错时，返回重试次数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceVerifyPwd(const char* id,const char *pwd,int *retryNum);


/*
 *	NetcaPKIAppDeviceIsDeviceConnent 
 *		判断是否有设备连接
 *	参数：
 *		无
 *	返回值：
 *		有返回1，无返回0
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceIsDeviceConnent(void);

/*
 *	NetcaPKIAppGetVersionInfo 
 *		获取版本信息
 *	参数：
 *		无
 *	返回值：
 *		成功返回版本信息，失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppGetVersionInfo(void);


#ifdef __cplusplus
	}	
#endif
#endif
