#ifndef NETCA_HTTP_INCLUDE_H
#define NETCA_HTTP_INCLUDE_H

#include "NETCA_Uri.h"
#include "NETCA_Socket.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_HTTP_st;
typedef struct NETCA_HTTP_st* NETCA_HTTP;

enum
{
	NETCA_HTTP_METHOD_GET			=0,		
	NETCA_HTTP_METHOD_POST			=1,		
};

/*
 *		netca_http_new
 *			创建一个HTTP句柄
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的HTTP句柄，失败返回NULL
 */
NETCA_HTTP NETCAAPI netca_http_new(void);

/*
 *		netca_http_free
 *			释放HTTP句柄
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_http_free(NETCA_HTTP http);


/*
 *		netca_http_newfromurl
 *			根据URL创建一个HTTP句柄
 *		参数：
 *			url：HTTP的URL句柄
 *		返回值：
 *			成功返回有效的HTTP句柄，失败返回NULL
 */
NETCA_HTTP NETCAAPI netca_http_newfromurl(NETCA_URI url);


/*
 *		netca_http_sethost
 *			设置HTTP的域名或IP
 *		参数：
 *			http：HTTP句柄
 *			host：域名或IP
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_sethost(NETCA_HTTP http,NETCA_UString host);

/*
 *		netca_http_gethost
 *			获得HTTP的域名或IP
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回HTTP的域名或IP，失败返回NULL
 */
NETCA_UString NETCAAPI netca_http_gethost(NETCA_HTTP http);


/*
 *		 
 *			设置HTTP的端口号
 *		参数：
 *			http：HTTP句柄
 *			port：输入参数，端口号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setport(NETCA_HTTP http,int port);


/*
 *		netca_http_getport
 *			获取HTTP的端口号
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回端口号，失败返回-1
 */
int NETCAAPI netca_http_getport(NETCA_HTTP http);


/*
 *		netca_http_connect
 *			连接HTTP服务器
 *		参数：
 *			http：HTTP句柄
 *			timeout：输入参数，连接超时的秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_connect(NETCA_HTTP http,int timeout);

/*
 *		netca_ldap_disconnect
 *			断开与HTTP服务器的连接
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_disconnect(NETCA_HTTP http);

/*
 *		netca_http_setmethod
 *			设置HTTP请求的方法
 *		参数：
 *			http：HTTP句柄
 *			method：输入参数，请求的方法
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setmethod(NETCA_HTTP http,int method);


/*
 *		netca_http_setrequestcharset
 *			设置HTTP请求的字符集
 *		参数：
 *			http：HTTP句柄
 *			charset：输入参数，请求的字符集
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setrequestcharset(NETCA_HTTP http,const char *charset);


/*
 *		netca_http_setrequestcharset
 *			设置HTTP请求头部
 *		参数：
 *			http：HTTP句柄
 *			name：输入参数，名称
 *			value：输入参数，值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setrequestheader(NETCA_HTTP http,const char *name,const char *value);

/*
 *		netca_http_setpath
 *			设置HTTP请求资源的路径
 *		参数：
 *			http：HTTP句柄
 *			path：请求资源的路径
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setpath(NETCA_HTTP http,NETCA_UString path);

/*
 *		netca_http_setformrequest
 *			设置HTTP表单请求
 *		参数：
 *			http：HTTP句柄
 *			name：表单项名称
 *			value：表单项值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setformrequest(NETCA_HTTP http,NETCA_UString name,NETCA_UString value);

/*
 *		netca_http_clearrequest
 *			清除HTTP请求
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_clearrequest(NETCA_HTTP http);


/*
 *		netca_http_setrequestlength
 *			设置HTTP的Content-Length的值
 *		参数：
 *			http：HTTP句柄
 *			length：输入参数，请求数据的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setrequestlength(NETCA_HTTP http,int length);

/*
 *		netca_http_requestdata_init
 *			发送HTTP头
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_requestdata_init(NETCA_HTTP http);
/*
 *		netca_http_requestdata_update
 *			添加HTTP的请求内容，可多次调用
 *		参数：
 *			http：HTTP句柄
 *			data：输入参数，请求内容
 *			length：输入参数，请求内容的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_requestdata_update(NETCA_HTTP http,const unsigned char *data,int length);

/*
 *		netca_http_requestdata_finish
 *			结束HTTP的请求内容
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_requestdata_finish(NETCA_HTTP http);


/*
 *		netca_http_getresponsestatus
 *			获取HTTP响应
 *		参数：
 *			http：HTTP句柄
 *			status：输出参数，HTTP响应状态
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_getresponsestatus(NETCA_HTTP http,int *status);

/*
 *		netca_http_getresponse
 *			获取HTTP响应的Content-Length
 *		参数：
 *			http：HTTP句柄
 *			length：输出参数，HTTP响应的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_getresponselength(NETCA_HTTP http,int *length);

/*
 *		netca_http_getresponseheadercount
 *			获取HTTP响应头的名值对个数
 *		参数：
 *			http：HTTP句柄
 *		返回值：
 *			成功返回响应头的名值对个数，失败返回-1
 */
int NETCAAPI netca_http_getresponseheadercount(NETCA_HTTP http);

/*
 *		netca_http_getresponseheadername
 *			获取HTTP响应头的名称,返回值使用NETCA_FREE来释放
 *		参数：
 *			http：HTTP句柄
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回响应头的第index个名称，失败返回NULL
 */
char* NETCAAPI netca_http_getresponseheadername(NETCA_HTTP http,int index);


/*
 *		netca_http_getresponseheadervalue
 *			获取HTTP响应头的值,返回值使用NETCA_FREE来释放
 *		参数：
 *			http：HTTP句柄
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回响应头的第index个值，失败返回NULL
 */
char* NETCAAPI netca_http_getresponseheadervalue(NETCA_HTTP http,int index);

/*
 *		netca_http_findresponseheadervalue
 *			获取HTTP响应头的值,返回值使用NETCA_FREE来释放
 *		参数：
 *			http：HTTP句柄
 *			name：输入参数，响应头的名
 *		返回值：
 *			成功返回响应头的名称对应的值，失败返回NULL
 */
char* NETCAAPI netca_http_findresponseheadervalue(NETCA_HTTP http,const char *name);

/*
 *		netca_http_setresponsecharset
 *			设置HTTP响应的字符集
 *		参数：
 *			http：HTTP句柄
 *			charset：输入参数，响应的字符集
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setresponsecharset(NETCA_HTTP http,const char *charset);



/*
 *		netca_http_getresponse
 *			获取HTTP响应的数据，可多次调用
 *		参数：
 *			http：HTTP句柄
 *			buf：输出参数，返回HTTP响应的数据
 *			buflen：输入参数，buf的长度
 *			readlen：输出参数，返回读到的数据长度。
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_getresponse(NETCA_HTTP http,unsigned char *buf,int buflen,int *readlen);





/*
 *		netca_http_settimeout
 *			设置超时值
 *		参数：
 *			http：HTTP句柄
 *			timeout：输入参数，超时的秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_settimeout(NETCA_HTTP http,int timeout);

/*
 *		netca_http_setpersistentconnection
 *			设置持久连接
 *		参数：
 *			http：HTTP句柄
 *			value：输入参数，为真则使用持久连接，为假则不用
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setpersistentconnection(NETCA_HTTP http,int value);

/*
 *		netca_http_setabsoluteURI
 *			设置是否使用绝对URI
 *		参数：
 *			http：HTTP句柄
 *			value：输入参数，为真则使用使用绝对URI，为假则不用
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setabsoluteURI(NETCA_HTTP http,int value);

#define NETCA_HTTP_AUTH_IMMEDIATE_BASIC	1
/*
 *		netca_http_setauthinfo
 *			设置HTTP认证信息，这个函数并不真正去验证用户名密码是否正确，要根据响应的状态的来判断用户名密码是否正确。
 *		参数：
 *			http：HTTP句柄
 *			flag：输入参数，如果设置了NETCA_HTTP_AUTH_IMMEDIATE_BASIC位则一开始就发生HTTP Basic认证的头
 *			username：输入参数，用户名
 *			pwd：输入参数，密码
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setauthinfo(NETCA_HTTP http,int flag,const char *username,const char *pwd);


#define NETCA_HTTP_PROXY_TYPE_GLOBAL	1
#define NETCA_HTTP_PROXY_TYPE_LOCAL		2
/*
 *		netca_http_setproxy
 *			设置HTTP代理信息。
 *		参数：
 *			http：HTTP句柄
 *			flag：输入参数，如果为NETCA_HTTP_PROXY_TYPE_GLOBAL则进程有效，如果为NETCA_HTTP_PROXY_TYPE_LOCAL则本句柄有效
 *			host：输入参数，代理的主机名，为NULL则表示不使用代理
 *			port：输入参数，代理的端口号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_http_setproxy(NETCA_HTTP http,int flag,NETCA_UString host,int port);

#ifdef __cplusplus
	}	
#endif

#endif

