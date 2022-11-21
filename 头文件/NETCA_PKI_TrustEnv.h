#ifndef NETCA_PKI_TRUSTENV_H
#define NETCA_PKI_TRUSTENV_H

#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


/*
 *		NetcaPKIEnvLoad
 *			装载安全环境
 *		参数：
 *			data：输入参数，安全环境编码数据
  *			datalen：输入参数，data的字节数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvLoad(const unsigned char *data,int datalen);

/*
 *		NetcaPKIEnvLoadFromFile
 *			装载安全环境
 *		参数：
 *			filename：输入参数，安全环境文件名，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvLoadFromFile(const char *filename);

/*
 *		NetcaPKIEnvLoadDefaultEnv
 *			装载缺省的安全环境
 *		参数：
 *			无。
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvLoadDefaultEnv(void);

/*
 *		NetcaPKIEnvSave
 *			保存安全环境
 *		参数：
 *			filename：输入参数，安全环境文件名，UTF-8编码，如果为NULL，则为缺省的安全环境名
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvSave(const char *filename);

/*
 *		NetcaPKIEnvGetAllRootCerts
 *			获取所有的根证书
 *		参数：
 *			pCerts：输出参数，返回的证书
 *			count：输出参数，返回的证书个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvGetAllRootCerts(NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

/*
 *		NetcaPKIEnvGetAllCACerts
 *			获取所有的CA证书
 *		参数：
 *			pCerts：输出参数，返回的证书
  *			count：输出参数，返回的证书个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvGetAllCACerts(NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

/*
 *		NetcaPKIEnvAddRootCert
 *			添加根证书到信任环境
 *		参数：
 *			name：输入参数，根CA的名称，UTF-8编码
 *			cert：输入参数，根证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddRootCert(const char *name,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvAddCACert
 *			添加CA证书到信任环境
 *		参数：
 *			name：输入参数， CA的名称，UTF-8编码
 *			cert：输入参数，CA证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddCACert(const char *name,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvGetCACert
 *			根据名称获取CA证书或者根证书
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回证书句柄，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetCACert(const char *name);


/*
 *		NetcaPKIEnvUpdateRootCert
 *			更新根证书
 *		参数：
 *			name：输入参数，根CA的名称，UTF-8编码
 *			cert：输入参数，根证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateRootCert(const char *name, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvUpdateCACert
 *			更新CA证书
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			cert：输入参数，CA证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateCACert(const char *name, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteRootCA
 *			删掉根CA
 *		参数：
 *			name：输入参数，根CA的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteRootCA(const char *name);

/*
 *		NetcaPKIEnvDeleteCA
 *			删掉CA
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteCA(const char *name);

/*
 *		NetcaPKIEnvGetCRL
 *			获取CA颁发的CRL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			crl：输出参数，返回CRL的编码
 *			crllen：输出参数，返回CRL的编码的长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvGetCRL(const char *name, unsigned char** crl,int *crllen);

/*
 *		NetcaPKIEnvGetDeltaCRL
 *			获取CA颁发的Delta CRL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			crl：输出参数，返回Delta CRL的编码
 *			crllen：输出参数，返回Delta CRL的编码的长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvGetDeltaCRL(const char *name, unsigned char** crl,int *crllen);

/*
 *		NetcaPKIEnvUpdateCRL
 *			设置CA颁发的CRL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			crl：输入参数，CRL的编码
 *			crllen：输入参数，CRL的编码的长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateCRL(const char *name, const unsigned char* crl,int crllen);

/*
 *		NetcaPKIEnvUpdateDeltaCRL
 *			设置CA颁发的Delta CRL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			crl：输入参数，Delta CRL的编码
 *			crllen：输入参数，Delta CRL的编码的长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateDeltaCRL(const char *name, const unsigned char* crl,int crllen);

/*
 *		NetcaPKIEnvGetCRLURL
 *			获取CA颁发的CRL的URL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回获取CA颁发的CRL的URL，UTF-8编码，失败返回NULL
 */
char*  NETCADLLAPI NetcaPKIEnvGetCRLURL(const char *name);

/*
 *		NetcaPKIEnvGetDeltaCRLURL
 *			获取CA颁发的Delta CRL的URL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回获取CA颁发的Delta CRL的URL，UTF-8编码，失败返回NULL
 */
char*  NETCADLLAPI NetcaPKIEnvGetDeltaCRLURL(const char *name);

/*
 *		NetcaPKIEnvUpdateCRLURL
 *			设置获取CA颁发的CRL的URL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码，UTF-8编码
 *			url：输入参数，获取CA颁发的CRL的URL
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateCRLURL(const char *name, const char *url);

/*
 *		NetcaPKIEnvUpdateDeltaCRLURL
 *			设置获取CA颁发的Delta CRL的URL
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			url：输入参数，获取CA颁发的Delta CRL的URL，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateDeltaCRLURL(const char *name, const char *url);

/*
 *		NetcaPKIEnvGetVerifyParam
 *			获取验证证书使用的参数
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回验证证书使用的参数，UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetVerifyParam(const char *name);

/*
 *		NetcaPKIEnvUpdateVerifyParam
 *			设置获取验证证书使用的参数
 *		参数：
 *			name：输入参数，CA的名称，UTF-8编码
 *			param：输入参数，验证证书使用的参数，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateVerifyParam(const char *name,const char *param);

/*
 *		NetcaAddressBookClose
 *			添加OCSP
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *			url：输入参数，OCSP的URL，UTF-8编码
 *			hashalgo：输入参数，支持的OCSP请求的Hash算法
 *			usenonce：输入参数，为真表示支持Nonce，为假表示不支持
 *			cert：输入参数，OCSP服务器证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddOCSP(const char *name,const char *url,int hashalgo,int usenonce, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteOCSP
 *			删除OCSP
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteOCSP(const char *name);

/*
 *		NetcaPKIEnvUpdateOCSP
 *			更新OCSP信息
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *			url：输入参数，OCSP的URL，UTF-8编码
 *			hashalgo：输入参数，支持的OCSP请求的Hash算法
 *			usenonce：输入参数，为真表示支持Nonce，为假表示不支持
 *			cert：输入参数，OCSP服务器证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateOCSP(const char *name,const char *url,int hashalgo,int usenonce, NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *		NetcaPKIEnvGetOCSPURL
 *			获取OCSP的URL
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			成功返回OCSP的URL，UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPURL(const char *name);

/*
 *		NetcaPKIEnvGetOCSPHashAlgo
 *			获取OCSP的Hash算法
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			成功返回OCSP的Hash算法，失败返回-1
 */
int NETCADLLAPI NetcaPKIEnvGetOCSPHashAlgo(const char *name);

/*
 *		NetcaPKIEnvIsOCSPUseNonce
 *			获取OCSP是否支持Nonce
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			如果OCSP支持Nonce返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsOCSPUseNonce(const char *name);

/*
 *		NetcaPKIEnvGetOCSPCert
 *			获取OCSP证书
 *		参数：
 *			name：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			成功返回OCSP证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetOCSPCert(const char *name);

/*
 *		NetcaPKIEnvGetAllOCSPCount
 *			获取Ocsp的个数
 *		参数：
 *			无。
 *		返回值：
 *			成功返回Ocsp的个数，失败返回-1
 */
int NETCADLLAPI NetcaPKIEnvGetAllOCSPCount();

/*
 *		NetcaPKIEnvGetOCSPNameByIndex
 *			获取第index个Ocsp名称
 *		参数：
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回第index个Ocsp名称，UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPNameByIndex(int index);

/*
 *		NetcaPKIEnvAddOCSPToCA
 *			给CA添加OCSP信息
 *		参数：
 *			caname：输入参数，CA的名称，UTF-8编码
 *			ocspname：输入参数，OCSP的名称，UTF-8编码
 *			isdefault：输入参数，为真表示这是CA的缺省OCSP，为假则不是
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddOCSPToCA(const char *caname, const char *ocspname,int isdefault);

/*
 *		NetcaPKIEnvDeleteOCSPFromCA
 *			从CA中删掉OCSP信息
 *		参数：
 *			caname：输入参数，CA的名称，UTF-8编码
 *			ocspname：输入参数，OCSP的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteOCSPFromCA(const char *caname, const char *ocspname);

/*
 *		NetcaPKIEnvGetDefaultOCSP
 *			获取CA的缺省OCSP名
 *		参数：
 *			caname：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回CA缺省的OCSP，失败返回NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetDefaultOCSP(const char *caname);

/*
 *		NetcaPKIEnvGetOCSPCount
 *			获取CA的OCSP个数
 *		参数：
 *			caname：输入参数，CA的名称，UTF-8编码
 *		返回值：
 *			成功返回CA的OCSP个数，失败返回-1
 */
int NETCADLLAPI NetcaPKIEnvGetOCSPCount(const char *caname);

/*
 *		NetcaPKIEnvGetOCSPName 
 *			获取CA的第index个OCSP名
 *		参数：
 *			caname：输入参数，CA的名称，UTF-8编码
 *			index：输入参数，索引值，从0算起
 *			isdefault：输出参数，为缺省OCSP则返回1，否则返回0
 *		返回值：
 *			成功返回CA的第index个OCSP名，UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPName(const char *caname,int index,int * isdefault);

/*
 *		NetcaPKIEnvAddTSA
 *			添加TSA
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *			url：输入参数，TSA的URL，UTF-8编码
 *			hashalgo：输入参数，支持的TSA请求的Hash算法
 *			policy：输入参数，支持的TSA请求的策略OID
 *			cert：输入参数，TSA证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddTSA(const char *name,const char *url,int hashalgo,const char *policy, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteTSA
 *			删除TSA
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteTSA(const char *name);

/*
 *		NetcaPKIEnvUpdateTSA
 *			更新TSA
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *			url：输入参数，TSA的URL，UTF-8编码
 *			hashalgo：输入参数，支持的TSA请求的Hash算法
 *			policy：输入参数，支持的TSA请求的策略OID
 *			cert：输入参数，TSA证书
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvUpdateTSA(const char *name,const char *url,int hashalgo,const char *policy, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvSetDefaultTSA
 *			设置缺省的TSA
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvSetDefaultTSA(const char *name);

/*
 *		NetcaPKIEnvGetDefaultTSA
 *			获取缺省的TSA
 *		参数：
 *			无。
 *		返回值：
 *			成功返回缺省的TSA名，失败返回NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetDefaultTSA(void);

/*
 *		NetcaPKIEnvGetTSAURL 
 *			获取TSA的URL
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回TSA的URL，失败返回NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetTSAURL(const char *name);

/*
 *		NetcaPKIEnvGetTSAHashAlgorithm
 *			获取TSA的Hash算法
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回TSA的Hash算法，失败返回-1
 */
int NETCADLLAPI NetcaPKIEnvGetTSAHashAlgorithm(const char *name);

/*
 *		NetcaPKIEnvGetTSAPolicy
 *			获取TSA的支持的策略
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回TSA的支持的策略，失败返回NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetTSAPolicy(const char *name);

/*
 *		NetcaPKIEnvGetTSACert
 *			获取TSA证书
 *		参数：
 *			name：输入参数，TSA的名称，UTF-8编码
 *		返回值：
 *			成功返回TSA证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetTSACert(const char *name);

/*
 *		NetcaPKIEnvGetTSACount
 *			获取TSA的个数
 *		参数：
 *			无。
 *		返回值：
 *			成功返回TSA的个数，失败返回-1
 */
int NETCADLLAPI NetcaPKIEnvGetTSACount();

/*
 *		NetcaPKIEnvGetTSAName
 *			获取第index个TSA名称
 *		参数：
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回第index个TSA名称，UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetTSAName(int index);

/*
 *		NetcaPKIEnvIsAcceptableHashAlgorithm
 *			判断是否支持Hash算法
 *		参数：
 *			algo：输入参数，Hash算法
 *		返回值：
 *			如果支持该Hash算法，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableHashAlgorithm(int algo);

/*
 *		NetcaPKIEnvAddAcceptableHashAlgorithm
 *			添加支持的Hash算法
 *		参数：
 *			algo：输入参数，Hash算法
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableHashAlgorithm(int algo);

/*
 *		NetcaPKIEnvDeleteAcceptableHashAlgorithm
 *			删除Hash算法
 *		参数：
 *			algo：输入参数，Hash算法
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableHashAlgorithm (int algo);

/*
 *		NetcaPKIEnvIsAcceptableMacAlgorithm
 *			判断是否支持Mac算法
 *		参数：
 *			algo：输入参数，Mac算法
 *		返回值：
 *			如果支持该Mac算法，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvAddAcceptableMacAlgorithm
 *			添加支持的Mac算法
 *		参数：
 *			algo：输入参数，Mac算法
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvDeleteAcceptableMacAlgorithm  
 *			删除MAC算法
 *		参数：
 *			algo：输入参数，Hash算法
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvIsAcceptableSymmetricAlgorithm
 *			判断是否支持对称加密算法
 *		参数：
 *			algo：输入参数，对称加密算法
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			keybits：输入参数，密钥长度
 *		返回值：
 *			如果支持该对称加密算法，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableSymmetricAlgorithm(int algo,int enc,int keybits);

/*
 *		NetcaPKIEnvAddAcceptableSymmetricAlgorithm
 *			添加支持的加密算法
 *		参数：
 *			algo：输入参数，对称加密算法
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableSymmetricAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptableSymmetricAlgorithm 
 *			删除加密算法
 *		参数：
 *			algo：输入参数，对称加密算法
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableSymmetricAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptablePublickeyAlgorithm
 *			判断是否支持非对称加密算法
 *		参数：
 *			algo：输入参数，非对称加密算法，如果为产生密钥对算法，忽略enc
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			keybits：输入参数，密钥长度
 *		返回值：
 *			如果支持该非对称加密算法，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptablePublicKeyAlgorithm(int algo,int enc,int keybits);

/*
 *		NetcaPKIEnvAddAcceptablePublicKeyAlgorithm
 *			添加支持的非对称加密算法
 *		参数：
 *			algo：输入参数，非对称加密算法，如果为产生密钥对算法，忽略enc
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptablePublicKeyAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptablePublicKeyAlgorithm
 *			删除非对称加密算法
 *		参数：
 *			algo：输入参数，非对称加密算法，如果为产生密钥对算法，忽略enc
 *			enc：输入参数，为真表示，用来加密，为假表示用来解密
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptablePublicKeyAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptableSignAlgorithm
 *			判断是否支持签名算法
 *		参数：
 *			algo：输入参数，签名算法
 *			sign：输入参数，为真表示，用来签名，为假表示用来验证
 *			keybits：输入参数，密钥长度
 *		返回值：
 *			如果支持该签名算法，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableSignAlgorithm(int algo,int sign,int keybits);

/*
 *		NetcaPKIEnvAddAcceptableSignAlgorithm
 *			添加支持的签名算法
 *		参数：
 *			algo：输入参数，签名算法
 *			enc：输入参数，为真表示，用来签名，为假表示用来验证
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableSignAlgorithm(int algo,int sign,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptableSignAlgorithm
 *			删除签名算法
 *		参数：
 *			algo：输入参数，签名算法
 *			enc：输入参数，为真表示，用来签名，为假表示用来验证
 *			minkeybits：输入参数，支持的最小密钥长度
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableSignAlgorithm(int algo,int sign,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptableDevice
 *			判断是否支持设备
 *		参数：
 *			type：输入参数，设备类型
 *		返回值：
 *			如果支持设备，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableDevice(int type);

/*
 *		NetcaPKIEnvAddAcceptableDevice
 *			添加支持的设备
 *		参数：
 *			type：输入参数，设备类型
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableDevice(int type);

/*
 *		NetcaPKIEnvDeleteAcceptableDevice
 *			删除支持的设备
 *		参数：
 *			type：输入参数，设备类型
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableDevice(int type);

/*
 *		NetcaPKIEnvIsAcceptableCSP
 *			判断是否支持CSP
 *		参数：
 *			cspname：输入参数，CSP名称，UTF-8编码
 *		返回值：
 *			如果支持该CSP，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvAddAcceptableCSP
 *			添加支持的CSP
 *		参数：
 *			cspname：输入参数，CSP名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvDeleteAcceptableCSP
 *			删除支持的CSP
 *		参数：
 *			cspname：输入参数，CSP名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvIsAcceptablePKCS11
 *			判断是否支持PKCS#11
 *		参数：
 *			name：输入参数，PKCS#11名称，UTF-8编码
 *		返回值：
 *			如果支持该PKCS#11，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvAddAcceptablePKCS11
 *			添加支持的PKCS#11
 *		参数：
 *			name：输入参数，PKCS#11名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvDeleteAcceptablePKCS11
 *			删除支持的PKCS#11
 *		参数：
 *			name：输入参数，PKCS#11名称，UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvIsAcceptableTSAPolicy
 *			判断是否支持TSA的策略OID
 *		参数：
 *			policy：输入参数，TSA的策略OID
 *		返回值：
 *			如果支持该TSA的策略OID，返回1，否则返回0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableTSAPolicy(const char *policy);

/*
 *		NetcaPKIEnvAddAcceptableTSAPolicy
 *			添加支持的TSA的策略OID
 *		参数：
 *			policy：输入参数，TSA的策略OID
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableTSAPolicy(const char *policy);

/*
 *		NetcaPKIEnvDeleteAcceptableTSAPolicy
 *			删除支持的TSA的策略OID
 *		参数：
 *			policy：输入参数，TSA的策略OID
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableTSAPolicy(const char *policy);


#ifdef __cplusplus
	}
#endif
#endif
