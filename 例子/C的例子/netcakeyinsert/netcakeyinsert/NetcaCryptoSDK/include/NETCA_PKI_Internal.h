#ifndef _NETCA_PKI_INTERNAL_INLCUDE_H_
#define _NETCA_PKI_INTERNAL_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif


/*
 *	NetcaPKICertSetTrustAnchor
 *		设置当前进程使用的TrustAnchor
 *	参数：
 *		flag：输入参数，标志
 *		store：TrustAnchor集合组成的证书库
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetTrustAnchor(int flag,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertSetCACert
 *		设置当前进程使用的CA证书
 *	参数：
 *		flag：输入参数，标志
 *		store：CA证书集合组成的证书库
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetCACert(int flag,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertGetTrustAnchor
 *		获取TrustAnchor
 *	参数：
 *		无
 *	返回值：
 *		成功返回TrustAnchor集合组成的证书库，失败返回NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertGetTrustAnchor(void);

/*
 *	NetcaPKICertGetCACert
 *		获取CA证书
 *	参数：
 *		无
 *	返回值：
 *		成功返回CA证书集合组成的证书库，失败返回NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertGetCACert(void);

/*
 *	NetcaPKICryptoSetDeviceFlag
 *		设置当前进程使用的加密设备的标志
 *	参数：
 *		flag：输入参数，标志
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeviceFlag(int flag);

/*
 *	NetcaPKICryptoGetDeviceFlag
 *		获取当前进程使用的加密设备的标志
 *	参数：
 *		无
 *	返回值：
 *		成功返回加密设备的标志
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDeviceFlag(void);


/*
 *	NetcaPKICertSetSelectCertConfig
 *		设置当前进程使用的选择证书的配置
 *	参数：
 *		config：输入参数，配置字符串
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetSelectCertConfig(const char *config);


/*
 *	NetcaPKICertGetSelectCertConfig
 *		获取当前进程使用的选择证书的配置
 *	参数：
 *		无
 *	返回值：
 *		成功返回配置字符串，如果没有或者失败返回NULL
 *
 */
char* NETCADLLAPI NetcaPKICertGetSelectCertConfig(void);


/*
 *	NetcaPKISetSM2SignParamConfig
 *		设置SM2签名的参数编码
 *	参数：
 *		useNull：输入参数，如果为真，表示使用NULL，为假则不编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS,失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKISetSM2SignParamConfig(int useNull);


/*
 *	NetcaPKIGetSM2SignParamConfig
 *		获取SM2签名的参数编码
 *	参数：
 *		无
 *	返回值：
 *		成功返回SM2签名的参数编码
 *
 */
int NETCADLLAPI NetcaPKIGetSM2SignParamConfig(void);


/*
 *	NetcaPKICryptoSetDefaultDeviceConfig
 *		设置当前进程使用的默认加密设备
 *	参数：
 *		config：输入参数，配置字符串
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDefaultDeviceConfig(const char *config);

/*
 *	NetcaPKICryptoGetDefaultDevice
 *		获取默认的加密设备
 *	参数：
 *		algo：输入参数，加密算法
 *		usage：输入参数，用途
 *	返回值：
 *		成功返回默认的加密设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDefaultDevice(int algo,int usage);

/*
 *	NetcaPKICryptoAddHttpAuthInfo
 *		设置HTTP的认证信息
 *	参数：
 *		url：输入参数，HTTP的URL
 *		authFlag:输入参数，认证的方式
 *		cert:输入参数，SSL双向认证的客户端证书，必须要有关联的密钥对
 *		userName：输入参数，用户名
 *		pwd:输入参数，密码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoAddHttpAuthInfo(const char *url,int authFlag,NETCA_PKI_CERTIFICATE_HANDLE cert,const char *userName,const char *pwd);

/*
 *	NetcaPKICryptoClearHttpAuthInfo
 *		清除HTTP的认证信息
 *	参数：
 *		url：输入参数，HTTP的URL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoClearHttpAuthInfo(const char *url);

/*
 *	NetcaPKICryptoGetHttpAuthInfo
 *		获取设置的HTTP的认证信息
 *	参数：
 *		url：输入参数，HTTP的URL
 *		authFlag:输出参数，认证的方式
 *		cert:输出参数，SSL双向认证的客户端证书，必须要有关联的密钥对
 *		userName：输出参数，用户名
 *		pwd:输出参数，密码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，不存在返回NETCA_PKI_NOTEXISIT，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHttpAuthInfo(const char *url,int *authFlag,NETCA_PKI_CERTIFICATE_HANDLE *cert,char **userName,char **pwd);


/*
 *	NetcaPKICryptoHttpGet
 *		通过HTTP的Get方法获取数据
 *	参数：
 *		url：输入参数，HTTP的URL
 *		reqHeads:输入参数，附加的HTTP头域，可以为NULL
 *		reqHeadCount：输入参数，附加的HTTP头的个数
 *		status:输出参数，返回HTTP状态码
 *		contentType:输出参数，输出返回的ContentType,如果输入为NULL，则不输出
 *		data:输出参数，返回获取的数据
 *		dataLen：输出参数，返回获取的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoHttpGet(const char *url,const char *reqHeads[],int reqHeadCount,int *status,char **contentType,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICryptoHttpPost
 *		通过HTTP的Post方法获取数据
 *	参数：
 *		url：输入参数，HTTP的URL
 *		reqHeads:输入参数，附加的HTTP头域，可以为NULL
 *		reqHeadCount：输入参数，附加的HTTP头的个数
 *		data:输入参数，请求数据
 *		dataLen：输入参数，请求数据的长度
 *		status:输出参数，返回HTTP状态码
 *		contentType:输出参数，输出返回的ContentType,如果输入为NULL，则不输出
 *		resp:输出参数，返回获取的数据
 *		respLen：输出参数，返回获取的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoHttpPost(const char *url,const char *reqHeads[],int reqHeadCount,const unsigned char *data,int dataLen,int *status,char **contentType,unsigned char **resp,int *respLen);

/*
 *	NetcaPKICryptoSetHttpImplement
 *		设置HTTP的实现
 *	参数：
 *		name：输入参数，HTTP实现的名称,UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpImplement(const char *name);

/*
 *	NetcaPKICryptoSetHttpsVerifyFlag
 *		设置HTTPS的验证标志
 *	参数：
 *		name：输入参数，HTTPS的验证标志
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpsVerifyFlag(int flag);

/*
 *	NetcaPKICryptoLdapGetAttributes
 *		通过Ldap获取属性
 *	参数：
 *		url：输入参数，LDAP的URL
 *		names:输出参数，返回获取的属性名数组
 *		values:输出参数，返回获取的属性值数组
 *		valueLens：输出参数，返回获取的属性长度数组
 *		count：输出参数，返回获取的属性数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoLdapGetAttributes(const char *url,char ***names,unsigned char ***values,int **valueLens,int* count);

/*
 *	NetcaPKICryptoLdapSearch
 *		通过Ldap进行搜索
 *	参数：
 *		host：输入参数，LDAP的主机名，ASCII编码
 *		port：输入参数，LDAP的端口号，-1为默认端口号
 *		flag：输入参数，标志
 *		baseDN：输入参数，搜索开始的DN，UTF-8编码
 *		scope:输入参数，搜索的范围
 *		filter：输入参数，过滤表达式，UTF-8编码
 *		sizeLimit:输入参数，返回的条目的最大数量
 *		attrNames:输入参数，要获取的所有属性名,属性名为UTF-8编码
 *		attrNameCount：输入参数，属性个数
 *		names:输出参数，返回获取的属性名数组
 *		values:输出参数，返回获取的属性值数组
 *		valueLens：输出参数，返回获取的属性长度数组
 *		count：输出参数，返回获取的属性数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoLdapSearch(const char *host,int port,int flag,const char *baseDN,int scope,const char *filter,int sizeLimit,const char **attrNames,int attrNameCount,char ***names,unsigned char ***values,int **valueLens,int* count);


/*
 *	NetcaPKICryptoAddTSACert
 *		添加信任的TSA证书
 *	参数：
 *		cert：输入参数，信任的TSA证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoAddTSACert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoGetTSACerts
 *		获取信任的TSA证书
 *	参数：
 *		certs：输出参数，信任的TSA证书
 *		count：输出参数，信任的TSA证书的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetTSACerts(NETCA_PKI_CERTIFICATE_HANDLE **certs,int *count);

/*
 *	NetcaPKICertGetAllowCertType
 *		获取允许的证书类型
 *	参数：
 *		allowCertType：输出参数，成功返回允许的证书类型
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetAllowCertType(char **allowCertType);
/*
 *	NetcaPKICertSetAllowCertType
 *		设置允许的证书类型
 *	参数：
 *		allowCertType：输入参数，允许的证书类型，NULL为允许所有的证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKICertSetAllowCertType(const char *allowCertType);


#ifdef __cplusplus
	}	
#endif
#endif
