#ifndef NETCA_LDAP_INCLUDE_H
#define NETCA_LDAP_INCLUDE_H

#include "NETCA_Uri.h"
#include "NETCA_UString.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/* 错误值 */
/* 无效参数 */
#define NETCA_LDAP_INVALIDARG					0x50000
/* 已经存在 */
#define NETCA_LDAP_EXISIT							0x50001
/* 不存在 */
#define NETCA_LDAP_NOTEXISIT					0x50002
/* 内存分配失败 */
#define NETCA_LDAP_OUTOFMEMORY			0x50003
/* 空间不足 */
#define NETCA_LDAP_NEEDMOREDATA			0x50004
/* 条目数量超出限制 */
#define NETCA_LDAP_SIZELIMIT_EXCEEDED		0x50005	
/* 超时 */
#define NETCA_LDAP_TIMEOUT						0x50006
/* 错误DN或者密码错误 */
#define NETCA_LDAP_PWD_ERROR					0x50007
/* filter 不正确 */
#define NETCA_LDAP_BADFILTER						0x50008
/* 拒绝访问 */
#define NETCA_LDAP_ACCESSDENIED				0x50009
/* 不支持 */
#define NETCA_LDAP_UNSUPPORTED				0x5000A
/* 无法连接，或服务器busy、down机 */
#define NETCA_LDAP_UNAVAILABLE				0x5000B
#define NETCA_LDAP_TIMELIMIT_EXCEEDED		0x5000C
/* 迭代结束后还继续读 */
#define NETCA_LDAP_READ_EOS		0x5000D

struct NETCA_LDAP_st;
typedef struct NETCA_LDAP_st* NETCA_LDAP;

struct NETCA_LDAP_Result_st;
typedef struct NETCA_LDAP_Result_st* NETCA_LDAP_Result;

struct NETCA_LDAP_ResultItem_st;
typedef struct NETCA_LDAP_ResultItem_st* NETCA_LDAP_ResultItem;

struct NETCA_LDAP_Filter_st;
typedef struct NETCA_LDAP_Filter_st* NETCA_LDAP_Filter;

struct NETCA_LDAP_Attribute_st;
typedef struct NETCA_LDAP_Attribute_st* NETCA_LDAP_Attribute;

struct NETCA_LDAP_ResultIterator_st;
typedef struct NETCA_LDAP_ResultIterator_st* NETCA_LDAP_ResultIterator;

enum
{
	NETCA_LDAP_SCOPE_BASEOBJECT		=0,		
	NETCA_LDAP_SCOPE_SINGLELEVEL	=1,		
	NETCA_LDAP_SCOPE_WHOLESUBTREE	=2,
};


enum
{
	NETCA_LDAP_DEREF_NEVER			=0,
	NETCA_LDAP_DEREF_INSEARCHING	=1,
	NETCA_LDAP_DEREF_FINDINGBASEOBJ	=2,
	NETCA_LDAP_DEREF_ALWAYS			=3,
};

/*
 *		netca_ldap_new
 *			创建一个LDAP句柄
 *		参数：
 *			无
 *		返回值：
 *			成功返回有效的LDAP句柄，失败返回NULL
 */
NETCA_LDAP NETCAAPI netca_ldap_new(void);

/*
 *		netca_ldap_free
 *			释放LDAP句柄
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_free(NETCA_LDAP ldap);


/*
 *		netca_ldap_sethost
 *			设置LDAP的域名或IP
 *		参数：
 *			ldap：LDAP句柄
 *			host：域名或IP
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_sethost(NETCA_LDAP ldap,NETCA_UString host);

/*
 *		netca_ldap_gethost
 *			获得LDAP的域名或IP
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			成功返回LDAP的域名或IP，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ldap_gethost(NETCA_LDAP ldap);


/*
 *		netca_ldap_setport
 *			设置LDAP的端口号
 *		参数：
 *			ldap：LDAP句柄
 *			port：输入参数，端口号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_setport(NETCA_LDAP ldap,int port);

/*
 *		netca_ldap_getport
 *			获取LDAP的端口号
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			成功返回端口号，失败返回-1
 */
int NETCAAPI netca_ldap_getport(NETCA_LDAP ldap);

/*
 *		netca_ldap_connect
 *			连接LDAP服务器，并进行身份验证
 *		参数：
 *			ldap：LDAP句柄
 *			dn：输入参数，绑定的DN
 *			pwd：输入参数，DN对应的密码，如果dn和pwd都为NULL，则表示匿名绑定
 *			timeout：输入参数，连接超时的秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout秒超时
 *		返回值：
 *			成功返回NETCA_OK，超时返回NETCA_ERROR_TIMEOUT，失败返回其他值
 */
int NETCAAPI netca_ldap_connect(NETCA_LDAP ldap,NETCA_UString dn,NETCA_UString pwd,int timeout);

/*
 *		netca_ldap_disconnect
 *			断开LDAP的连接
 *		参数：
 *			ldap：LDAP句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_disconnect(NETCA_LDAP ldap);

/*
 *		netca_ldap_setderefoption
 *			设置LDAP处理别名的方式
 *		参数：
 *			ldap：LDAP句柄
 *			option：输入参数，NETCA_LDAP_DEREF_NEVER、NETCA_LDAP_DEREF_INSEARCHING、NETCA_LDAP_DEREF_FINDINGBASEOBJ和NETCA_LDAP_DEREF_ALWAYS之一
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_setderefoption(NETCA_LDAP ldap,int option);

/*
 *		netca_ldap_settimeout
 *			设置LDAP处理的超时值
 *		参数：
 *			ldap：LDAP句柄
 *			timeout：输入参数，LDAP处理超时的秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_settimeout(NETCA_LDAP ldap,int timeout);

/*
 *		netca_ldap_setmaxentrynum
 *			设置LDAP返回的最多的条目数
 *		参数：
 *			ldap：LDAP句柄
 *			number：输入参数，最大条目数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_setmaxentrynum(NETCA_LDAP ldap,int number);

/*
 *		netca_ldap_search
 *			搜索LDAP
 *		参数：
 *			ldap：LDAP句柄
 *			basedn：输入参数，搜索开始的DN
 *			scope：输入参数，搜索的范围，NETCA_LDAP_SCOPE_BASEOBJECT、NETCA_LDAP_SCOPE_SINGLELEVEL和NETCA_LDAP_SCOPE_WHOLESUBTREE之一
 *			filter：输入参数，LDAP搜索条件
 *			attrs：输入参数，要返回的属性名称数组
 *			attrcount：输入参数，要返回的属性名称数组元素个数
 *			result：输出参数，返回的搜索结果
 *		返回值：
 *			成功返回NETCA_OK，超时返回NETCA_ERROR_TIMEOUT，失败返回其他值
 */
int NETCAAPI netca_ldap_search(NETCA_LDAP ldap,NETCA_UString basedn,int scope,NETCA_LDAP_Filter filter,const NETCA_UString *attrs,int attrcount,NETCA_LDAP_Result *result);

/*
 *		netca_ldap_search2
 *			搜索LDAP
 *		参数：
 *			ldap：LDAP句柄
 *			basedn：输入参数，搜索开始的DN
 *			scope：输入参数，搜索的范围，NETCA_LDAP_SCOPE_BASEOBJECT、NETCA_LDAP_SCOPE_SINGLELEVEL和NETCA_LDAP_SCOPE_WHOLESUBTREE之一
 *			filter：输入参数，LDAP搜索条件
 *			attrs：输入参数，要返回的属性名称数组
 *			attrcount：输入参数，要返回的属性名称数组元素个数
 *			iterator：输出参数，返回的搜索结果的迭代器
 *		返回值：
 *			成功返回NETCA_OK，超时返回NETCA_ERROR_TIMEOUT，失败返回其他值
 */
int NETCAAPI netca_ldap_search2(NETCA_LDAP ldap,NETCA_UString basedn,int scope,NETCA_LDAP_Filter filter,const NETCA_UString *attrs,int attrcount,NETCA_LDAP_ResultIterator *iterator);


/*
 *		netca_ldap_filter_new
 *			根据字符串构造搜索条件
 *		参数：
 *			filterstr：输入参数，搜索条件的字符串表示
 *		返回值：
 *			成功返回搜索条件，失败返回NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_new(NETCA_UString filterstr);

/*
 *		netca_ldap_filter_and
 *			构造与条件的搜索条件
 *		参数：
 *			filter1：搜索条件1
 *			filter2：搜索条件2
 *		返回值：
 *			成功返回filter1 && filter2的搜索条件，失败返回NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_and(NETCA_LDAP_Filter filter1,NETCA_LDAP_Filter filter2);

/*
 *		netca_ldap_filter_or
 *			构造或条件的搜索条件
 *		参数：
 *			filter1：搜索条件1
 *			filter2：搜索条件2
 *		返回值：
 *			成功返回filter1 || filter2的搜索条件，失败返回NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_or(NETCA_LDAP_Filter filter1,NETCA_LDAP_Filter filter2);


/*
 *		netca_ldap_filter_or
 *			构造非条件的搜索条件
 *		参数：
 *			filter：搜索条件
 *		返回值：
 *			成功返回!filter的搜索条件，失败返回NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_not(NETCA_LDAP_Filter filter);

/*
 *		netca_ldap_filter_free
 *			释放搜索条件
 *		参数：
 *			filter：搜索条件
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_filter_free(NETCA_LDAP_Filter filter);

/*
 *		netca_ldap_result_free
 *			释放搜索结果
 *		参数：
 *			result：搜索结果
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_result_free(NETCA_LDAP_Result result);

/*
 *		netca_ldap_result_count
 *			获得搜索结果项数
 *		参数：
 *			result：搜索结果
 *		返回值：
 *			成功返回搜索结果项数，失败返回-1
 */
int NETCAAPI netca_ldap_result_count(NETCA_LDAP_Result result);

/*
 *		netca_ldap_result_getitem
 *			获得搜索结果项
 *		参数：
 *			result：搜索结果
 *			index：输入参数，索引，从0算起
 *		返回值：
 *			成功返回第index个搜索结果项，失败返回NULL
 */
NETCA_LDAP_ResultItem NETCAAPI netca_ldap_result_getitem(NETCA_LDAP_Result result,int index);

/*
 *		netca_ldap_resultitem_getdn
 *			获得搜索结果项的DN
 *		参数：
 *			item：搜索结果项
 *		返回值：
 *			成功返回搜索结果项的DN，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ldap_resultitem_getdn(NETCA_LDAP_ResultItem item);


/*
 *		netca_ldap_resultitem_getattrcount
 *			获得搜索结果项的属性个数
 *		参数：
 *			item：搜索结果项
 *		返回值：
 *			成功返回搜索结果项的属性个数，失败返回-1
 */
int NETCAAPI netca_ldap_resultitem_getattrcount(NETCA_LDAP_ResultItem item);

/*
 *		netca_ldap_resultitem_getattr
 *			获得搜索结果项的属性
 *		参数：
 *			item：搜索结果项
 *			index：输入参数，索引，从0算起
 *		返回值：
 *			成功返回搜索结果项的第index个属性，失败返回NULL
 */
NETCA_LDAP_Attribute NETCAAPI netca_ldap_resultitem_getattr(NETCA_LDAP_ResultItem item,int index);

/*
 *		netca_ldap_resultitem_free
 *			释放搜索结果项
 *		参数：
 *			item：搜索结果项
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_resultitem_free(NETCA_LDAP_ResultItem item);


/*
 *		netca_ldap_attribute_free
 *			释放属性
 *		参数：
 *			attr：属性
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_attribute_free(NETCA_LDAP_Attribute attr);

/*
 *		netca_ldap_attribute_getname
 *			获取属性名称
 *		参数：
 *			attr：属性
 *		返回值：
 *			成功返回属性名称，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ldap_attribute_getname(NETCA_LDAP_Attribute attr);

/*
 *		netca_ldap_attribute_getvalue
 *			获取属性值，返回属性为字符串则为UTF-8格式，而且没有包含字符串结束符\0
 *		参数：
 *			attr：属性
 *			value：输出参数，返回的属性值
 *			valuelen：输入输出参数，如果value为NULL，则*valuelen返回属性值的最大可能长度，否则输入时*valuelen必须不小于属性值的长度，输出返回属性值的长度。
 *		返回值：
 *			成功返回NETCA_OK，长度不足返回NETCA_NEEDMOREDATA，失败返回其他值
 */
int NETCAAPI netca_ldap_attribute_getvalue(NETCA_LDAP_Attribute attr,unsigned char *value,int *valuelen);


/*
 *		netca_ldap_newfromurl
 *			根据URL创建一个LDAP句柄
 *		参数：
 *			url：LDAP的URL句柄
 *		返回值：
 *			成功返回有效的LDAP句柄，失败返回NULL
 */
NETCA_LDAP NETCAAPI netca_ldap_newfromurl(NETCA_URI url);

/*
 *		netca_ldap_getresult
 *			搜索LDAP
 *		参数：
 *			ldap：LDAP句柄
 *			result：输出参数，返回的搜索结果
 *		返回值：
 *			成功返回NETCA_OK，超时返回NETCA_ERROR_TIMEOUT，失败返回其他值
 */
int NETCAAPI netca_ldap_getresult(NETCA_LDAP ldap,NETCA_LDAP_Result *result);

/*
 *		netca_ldap_getresult
 *			搜索LDAP
 *		参数：
 *			ldap：LDAP句柄
 *			iterator：输出参数，返回的搜索结果迭代器
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ldap_getresultiterator(NETCA_LDAP ldap,NETCA_LDAP_ResultIterator* iterator);

/*
 *		netca_ldap_getnextresultitem
 *			获取下一个属性项
 *		参数：
 *			iterator：迭代器
 *			item：输出参数，返回的搜索结果项,失败或没有下一项的时候返回NULL
 *		返回值：
 *			成功返回NETCA_OK，超时返回NETCA_ERROR_TIMEOUT，失败返回其他值
 */
int NETCAAPI netca_ldap_getnextresultitem(NETCA_LDAP_ResultIterator iterator,NETCA_LDAP_ResultItem* item);

/*
 *		netca_ldap_iterator_free
 *			释放迭代器
 *		参数：
 *			iterator：迭代器
 *		返回值：
 *			无
 */
void NETCAAPI netca_ldap_iterator_free(NETCA_LDAP_ResultIterator iterator);
#ifdef __cplusplus
	}	
#endif

#endif

