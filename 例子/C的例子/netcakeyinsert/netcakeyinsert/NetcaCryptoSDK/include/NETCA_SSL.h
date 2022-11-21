#ifndef NETCA_SSL_INCLUDE_H
#define NETCA_SSL_INCLUDE_H

#include "NETCA_Socket.h"
#include "NETCA_Http.h"
#include "NETCA_Cert.h"

#ifdef __cplusplus
extern "C"
	{
#endif


struct NETCA_SSLContext_st;
typedef struct NETCA_SSLContext_st* NETCA_SSLContext;

struct NETCA_SSLSession_st;
typedef struct NETCA_SSLSession_st* NETCA_SSLSession;


enum
{
	NETCA_SSL_VERIFY_LEVEL_NONE	=0,					/* 对服务器证书不进行任何验证 */
	NETCA_SSL_VERIFY_LEVEL_CERT	=1,					/* 对服务器证书进行证书路径的验证，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_HTTP_NO_WILDCARD=2,		/* 对服务器证书进行证书路径的验证和名称验证，不支持通配符，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_HTTP	=3,					/* 对服务器证书进行证书路径的验证和名称验证，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_NO_REVOCATION =3,		/* 对服务器证书进行证书路径的验证和名称验证，但是不验证作废状态 */
	NETCA_SSL_VERIFY_LEVEL_SERVER_REVOCATION =4,		/* 对服务器证书进行证书路径的验证和名称验证，并且验证服务器证书的作废状态，但不验证CA证书的作废状态 */
	NETCA_SSL_VERIFY_LEVEL_CA_REVOCATION =5,		/* 对服务器证书进行证书路径的验证和名称验证，并且验证整个证书路径的作废状态 */
};

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
 *		netca_socket_sslctx_new
 *			创建一个SSL上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的SSL上下文，失败返回NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_sslctx_new(void);


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
int NETCAAPI netca_socket_sslctx_setverifyparam(NETCA_SSLContext ssl,int verifylevel,NETCA_CERT* cacerts,int cacount,NETCA_CERT* rootcerts,int rootcount);


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
int NETCAAPI netca_socket_sslctx_setclientcert(NETCA_SSLContext ssl,NETCA_CERT cert,const char *pwd);

/*
 *		netca_socket_getsslservercert
 *			获取SSL服务器证书
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回SSL服务器证书，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_socket_getsslservercert(NETCA_SOCKET sock);


/*
 *		netca_http_getsslservercert
 *			获取SSL服务器证书
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回SSL服务器证书，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_http_getsslservercert(NETCA_HTTP http);


/*
 *		netca_http_getsslctx
 *			获取SSL上下文句柄
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回SSL上下文句柄
 */
NETCA_SSLContext NETCAAPI netca_http_getsslctx(NETCA_HTTP http);

#ifdef __cplusplus
	}	
#endif

#endif
