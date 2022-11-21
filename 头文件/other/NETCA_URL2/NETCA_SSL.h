#ifndef NETCA_SSL_INCLUDE_H
#define NETCA_SSL_INCLUDE_H

#include "NETCA_Socket.h"
#include "NETCA_Http.h"
#include "NETCA_Ldap.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


struct NETCA_SSLContext_st;
typedef struct NETCA_SSLContext_st* NETCA_SSLContext;

enum
{
	NETCA_SSL_VERIFY_LEVEL_NONE	=0,					/* 对服务器证书不进行任何验证 */
	NETCA_SSL_VERIFY_LEVEL_CERT	=1,					/* 对服务器证书进行证书路径的验证，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_HTTP_NO_WILDCARD=2,		/* 对服务器证书进行证书路径的验证和名称验证，不支持通配符，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_HTTP	=3,					/* 对服务器证书进行证书路径的验证和名称验证，但是不验证作废状态 */
    NETCA_SSL_VERIFY_LEVEL_HTTPS = 3,
    NETCA_SSL_VERIFY_LEVEL_NO_REVOCATION =3,		/* 对服务器证书进行证书路径的验证和名称验证，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_SERVER_REVOCATION =4,	/* 对服务器证书进行证书路径的验证和名称验证，并且验证服务器证书的作废状态，但不验证CA证书的作废状态 */
	NETCA_SSL_VERIFY_LEVEL_CA_REVOCATION =5,		/* 对服务器证书进行证书路径的验证和名称验证，并且验证整个证书路径的作废状态 */
};



#define NETCA_TLS_TYPE_GMSSL			0
#define NETCA_TLS_TYPE_LEGACY_TLS1_0	1
#define NETCA_TLS_TYPE_TLS1_3			3
/*
 *		netca_ssl_init
 *			初始化SSL库
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ssl_init(void);

/*
 *		netca_ssl_end
 *			结束SSL库
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ssl_end(void);

/*
 *		netca_ssl_set_special_host
 *			设置特殊的域名
 *		参数：
 *			type：输入参数，类型
 *			host：输入参数，域名或IP地址
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ssl_set_special_host(int type,const char* host);

/*
 *		netca_socket_sslctx_new
 *			创建一个SSL上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_sslctx_new(void);

/*
 *		netca_socket_legacy_tls1_0ctx_new
 *			创建一个TLS V1.0上下文，用于访问windows2003的IIS
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_legacy_tls1_0ctx_new(void);

/*
 *		netca_socket_islegacy_tls1_0
 *			判断是否使用TLS V1.0上下文
 *		参数：
 *			host：主机名，或者IP地址
 *		返回值：
 *			如果使用TLS V1.0上下文返回1，否则返回0
 */
int NETCAAPI netca_socket_islegacy_tls1_0(NETCA_UString host);

/*
 *		netca_socket_tls1_3ctx_new
 *			创建一个TLS V1.3上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_tls1_3ctx_new(void);

/*
 *		netca_socket_istls1_3
 *			判断是否使用TLS 1.3上下文
 *		参数：
 *			host：主机名，或者IP地址
 *		返回值：
 *			如果使用TLS 1.3上下文返回1，否则返回0
 */
int NETCAAPI netca_socket_istls1_3(NETCA_UString host);

/*
 *		netca_socket_https2ctx_new
 *			创建一个HTTP 2.0的TLS上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_https2ctx_new(void);

/*
 *		netca_socket_ishttps2_host
 *			判断是否使用HTTP 2.0的TLS上下文
 *		参数：
 *			host：主机名，或者IP地址
 *		返回值：
 *			如果使用HTTP 2.0的TLS上下文返回1，否则返回0
 */
int NETCAAPI netca_socket_ishttps2_host(NETCA_UString host);

/*
 *		netca_socket_ishttps2_connect
 *			判断是否使用HTTP 2.0
 *		参数：
 *			ssl：主机名，或者IP地址
 *		返回值：
 *			如果使用HTTP 2.0返回1，否则返回0
 */
int NETCAAPI netca_socket_ishttps2_connect(NETCA_SSLContext ssl);

/*
 *		netca_socket_gmsslctx_new
 *			创建一个国密SSL上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的国密SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_gmsslctx_new(void);

/*
 *		netca_socket_gmssl_https2ctx_new
 *			创建一个国密SSL的HTTPS 2上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的国密SSL的HTTPS 2上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_gmssl_https2ctx_new(void);

/*
 *		netca_socket_isgmssl
 *			判断是否使用国密SSL
 *		参数：
 *			host：主机名，或者IP地址
 *		返回值：
 *			如果使用国密SSL返回1，否则返回0
 */
int NETCAAPI netca_socket_isgmssl(NETCA_UString host);
/*
 *		netca_socket_sslctx_new
 *			释放SSL上下文
 *		参数：
 *			ssl：SSL上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_socket_sslctx_free(NETCA_SSLContext ssl);

/*
 *		netca_socket_setssl
 *			设置使用SSL
 *		参数：
 *			sock：SOCKET句柄
 *			ssl：SSL上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_setssl(NETCA_SOCKET sock,NETCA_SSLContext ssl);

/*
 *		netca_socket_sslctx_dup
 *			复制一个SSL上下文
 *		参数：
 *			ssl：SSL上下文
 *		返回值：
 *			成功返回SSL上下文，失败返回0
 */
NETCA_SSLContext NETCAAPI netca_socket_sslctx_dup(NETCA_SSLContext ssl);

/*
 *		netca_http_setssl
 *			设置使用SSL
 *		参数：
 *			http：HTTP句柄
 *			ssl：SSL上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setssl(NETCA_HTTP http,NETCA_SSLContext ssl);


/*
 *		netca_http_setssl
 *			设置使用SSL
 *		参数：
 *			ldap：LDAP句柄
 *			ssl：SSL上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_setssl(NETCA_LDAP ldap,NETCA_SSLContext ssl);

/*
 *		netca_socket_sslctx_setverifyparam
 *			设置SSL验证参数
 *		参数：
 *			ssl：SSL上下文
 *			verifylevel：输入参数，验证的级别
 *			cacerts：输入参数，一组CA证书
 *			cacount：输入参数，CA证书个数
 *			rootcerts：输入参数，一组根证书
 *			rootcount：输入参数，根证书个数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_sslctx_setverifyparam(NETCA_SSLContext ssl,int verifylevel, NETCA_PKI_CERTIFICATE_HANDLE* cacerts,int cacount, NETCA_PKI_CERTIFICATE_HANDLE* rootcerts,int rootcount);


/*
 *		netca_socket_sslctx_setverifytime
 *			设置SSL验证时间
 *		参数：
 *			ssl：SSL上下文
 *			date：输入参数，验证的时间，如果为NULL，则为当前时间
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_sslctx_setverifytime(NETCA_SSLContext ssl,NETCA_Time date);

/*
 *		netca_socket_sslctx_setclientcert
 *			设置SSL双向验证的SSL的客户端证书
 *		参数：
 *			ssl：SSL上下文
 *			cert：客户端证书
 *			pwd：输入参数，密码
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_sslctx_setclientcert(NETCA_SSLContext ssl, NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd);

/*
 *		netca_socket_getsslservercert
 *			获取SSL服务器证书
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回SSL服务器证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_socket_getsslservercert(NETCA_SOCKET sock);


/*
 *		netca_http_getsslservercert
 *			获取SSL服务器证书
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回SSL服务器证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_http_getsslservercert(NETCA_HTTP http);


/*
 *		netca_ldap_getsslservercert
 *			获取SSL服务器证书
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			成功返回SSL服务器证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_ldap_getsslservercert(NETCA_LDAP ldap);
/*
 *		netca_http_getsslctx
 *			获取SSL上下文句柄
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回SSL上下文句柄
 */
NETCA_SSLContext NETCAAPI netca_http_getsslctx(NETCA_HTTP http);


/*
 *		netca_ldap_getsslctx
 *			获取SSL上下文句柄
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			成功返回SSL上下文句柄
 */
NETCA_SSLContext NETCAAPI netca_ldap_getsslctx(NETCA_LDAP ldap);

/*
 *		netca_socket_getsslctx
 *			获取SSL上下文句柄
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回SSL上下文句柄
 */
NETCA_SSLContext NETCAAPI netca_socket_getsslctx(NETCA_SOCKET sock);

/*
 *		netca_socket_write_ssl_alert_close_notify
 *			发送SSL的关闭告警信息
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_write_ssl_alert_close_notify(NETCA_SOCKET sock);

#ifdef __cplusplus
	}	
#endif

#endif
