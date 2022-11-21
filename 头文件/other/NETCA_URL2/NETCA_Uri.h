#ifndef NETCA_URI_INCLUDE_H
#define NETCA_URI_INCLUDE_H

#include "NETCA_UString.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_URI_st;
typedef struct NETCA_URI_st* NETCA_URI;

/*
 *		netca_uri_new
 *			创建一个URI句柄
 *		参数：
 *			uri：输入参数，URI引用，ASCII编码
 *		返回值：
 *			成功返回有效的URI句柄，失败返回NULL
 */
NETCA_URI NETCAAPI netca_uri_new(const char *uri);


/*
 *		netca_uri_free
 *			释放URI句柄
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_uri_free(NETCA_URI uri);

/*
 *		netca_uri_getscheme
 *			获取URI的scheme
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			成功返回有效的URI的scheme，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_getscheme(NETCA_URI uri);


/*
 *		netca_uri_gethost
 *			获取URI的域名或IP
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			成功返回有效的URI的域名或IP，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_gethost(NETCA_URI uri);


/*
 *		netca_url_getport
 *			获取URI的端口号
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			成功返回URI的端口号，失败返回-1
 */
int NETCAAPI netca_uri_getport(NETCA_URI uri);

/*
 *		netca_uri_getpath
 *			获取URI的路径
 *		参数：
 *			uri：URI句柄
 *			encoding：输入参数，编码
 *		返回值：
 *			成功返回URI的路径，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_getpath(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_getquery
 *			获取URI的查询部分
 *		参数：
 *			uri：URI句柄
 *			encoding：输入参数，编码
 *		返回值：
 *			成功返回URI的查询部分，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_getquery(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_hasquery
 *			判断URI的查询部分
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			如果有URI的查询部分则返回1，否则返回0
 */
int NETCAAPI netca_uri_hasquery(NETCA_URI uri);


/*
 *		netca_uri_getfragment
 *			获取URI的fragment部分
 *		参数：
 *			uri：URI句柄
 *			encoding：输入参数，编码
 *		返回值：
 *			成功返回URI的fragment部分，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_getfragment(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_hasfragment
 *			判断URI的fragment部分
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			如果有URI的fragment部分则返回1，否则返回0
 */
int NETCAAPI netca_uri_hasfragment(NETCA_URI uri);

/*
 *		netca_uri_isrelref
 *			判断URI的是否相对引用
 *		参数：
 *			uri：URI句柄
 *		返回值：
 *			如果有URI是相对引用则返回1，否则返回0
 */
int NETCAAPI netca_uri_isrelref(NETCA_URI uri);

/*
 *		netca_uri_ref_resolution
 *			构造完整的URI
 *		参数：
 *			baseuri：Base URI句柄
 *			relref：URI相对引用句柄
 *		返回值：
 *			成功构造返回构造得到的URI，否则返回NULL
 */
NETCA_URI NETCAAPI netca_uri_ref_resolution(NETCA_URI baseuri,NETCA_URI relref);

/*
 *		netca_uri_newfromunicode
 *			创建一个URI句柄
 *		参数：
 *			uri：URI引用
 *			encoding：输入参数，编码
 *		返回值：
 *			成功返回有效的URI句柄，失败返回NULL
 */
NETCA_URI NETCAAPI netca_uri_newfromunicode(NETCA_UString uri,const char *encoding);

/*
 *		netca_uri_getstring
 *			返回URI的字符串表示，ASCII编码，返回值使用NETCA_FREE来释放
 *		参数：
 *			uri：URI引用
 *		返回值：
 *			成功返回URI的字符串表，失败返回NULL
 */
char* NETCAAPI netca_uri_getstring(NETCA_URI uri);


/*
 *		netca_uri_getunicodestring
 *			返回URI的字符串表示
 *		参数：
 *			uri：URI引用
 *			encoding：输入参数，编码
 *		返回值：
 *			成功返回URI的字符串表，失败返回NULL
 */
NETCA_UString NETCAAPI netca_uri_getunicodestring(NETCA_URI uri,const char *encoding);

#ifdef __cplusplus
	}	
#endif

#endif

