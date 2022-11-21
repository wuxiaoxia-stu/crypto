#ifndef NETCA_JSON_INLCUDE_H
#define NETCA_JSON_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif


#ifndef NETCA_JSON_TYPE_STRING

#define NETCA_JSON_TYPE_STRING		1
#define NETCA_JSON_TYPE_NUMBER		2
#define NETCA_JSON_TYPE_BOOLEAN		3
#define NETCA_JSON_TYPE_NULL		4
#define NETCA_JSON_TYPE_OBJECT		5
#define NETCA_JSON_TYPE_ARRAY		6

#define NETCA_JSON_ENCODE_FLAG_COMPACT		0
#define NETCA_JSON_ENCODE_FLAG_INDENT		0x80000000	
#define NETCA_JSON_ENCODE_FLAG_USE_SPACE	0x40000000	
#define NETCA_JSON_ENCODE_FLAG_USE_RETURN	0x20000000	
#define NETCA_JSON_ENCODE_FLAG_USE_NEWLINE	0x10000000	
#define NETCA_JSON_ENCODE_FLAG_SORT			0x100000	
#define NETCA_JSON_ENCODE_FLAG_NORMAL	(NETCA_JSON_ENCODE_FLAG_INDENT|NETCA_JSON_ENCODE_FLAG_USE_NEWLINE)

#endif


/*
 *		netca_json_newboolean
 *			创建一个表示布尔值的JSON句柄
 *		参数：
 *			value：输入参数，0为假，非0为真
 *		返回值：
 *			成功返回表示布尔值的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newboolean(int value);

/*
 *		netca_json_newnull
 *			创建一个表示null值的JSON句柄
 *		参数：
 *			无
 *		返回值：
 *			成功返回表示null值的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newnull(void);

/*
 *		netca_json_newnumber
 *			创建一个表示数字的JSON句柄
 *		参数：
 *			number：输入参数，数字
 *		返回值：
 *			成功返回表示数字的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newnumber(double number);

/*
 *		netca_json_newstring
 *			创建一个表示字符串的JSON句柄
 *		参数：
 *			str：输入参数，字符串值，UTF-8编码
 *			strLen:输入参数，字符串字节数
 *		返回值：
 *			成功返回表示字符串的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newstring(const unsigned char *str,int strLen);


/*
 *		netca_json_newobject
 *			创建一个表示空对象的JSON句柄
 *		参数：
 *			无
 *		返回值：
 *			成功返回表示空对象的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newobject(void);


/*
 *		netca_json_newarray
 *			创建一个表示空数组的JSON句柄
 *		参数：
 *			无
 *		返回值：
 *			成功返回表示空数组的JSON句柄
 */
NETCA_JSON NETCAAPI netca_json_newarray(void);

/*
 *		netca_json_free
 *			释放JSON句柄
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_json_free(NETCA_JSON json);


/*
 *		netca_json_free
 *			复制JSON句柄
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回复制后的JSON句柄，失败返回NULL
 */
NETCA_JSON NETCAAPI netca_json_dup(NETCA_JSON json);


/*
 *		netca_json_free
 *			解析JSON编码的数据得到JSON句柄
 *		参数：
 *			data：输入参数，JSON的编码
 *			dataLen：输入参数，data的字节数
 *		返回值：
 *			成功返回JSON句柄，失败返回NULL
 */
NETCA_JSON NETCAAPI netca_json_decode(const unsigned char *data,int dataLen);

/*
 *		netca_json_addobjectitem
 *			添加一项到JSON对象,这个函数不检查是否重复
 *		参数：
 *			json：要添加项的JSON对象
 *			name：输入参数，名称的UTF-8编码
 *			nameLen：输入参数，名称的字节数
 *			value:输入参数，值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_json_addobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen,NETCA_JSON value);

/*
 *		netca_json_updateobjectitem
 *			更新JSON对象,如果名字不存在，添加一项
 *		参数：
 *			json：要添加项的JSON对象
 *			name：输入参数，名称的UTF-8编码
 *			nameLen：输入参数，名称的字节数
 *			value:输入参数，值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_json_updateobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen,NETCA_JSON value);

/*
 *		netca_json_deleteobjectitem
 *			删除JSON对象的指定项
 *		参数：
 *			json：要添加项的JSON对象
 *			name：输入参数，名称的UTF-8编码
 *			nameLen：输入参数，名称的字节数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_json_deleteobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen);

/*
 *		netca_json_addarrayitem
 *			添加一项到JSON数组
 *		参数：
 *			json：要添加项的JSON数组
 *			value:输入参数，值
 *		返回值：
 *			成功返回JSON句柄，失败返回其他值
 */
int NETCAAPI netca_json_addarrayitem(NETCA_JSON json,NETCA_JSON value);

/*
 *		netca_json_deletearrayitem
 *			在JSON数组中删除项
 *		参数：
 *			json：要添加项的JSON数组
 *			index:输入参数，索引值，从0算起
 *		返回值：
 *			成功返回JSON句柄，失败返回其他值
 */
int NETCAAPI netca_json_deletearrayitem(NETCA_JSON json,int index);

/*
 *		netca_json_encode
 *			对JSON进行编码
 *		参数：
 *			json：JSON句柄
 *			flag:输入参数，编码标志
 *			encode：输出参数，UTF-8编码
 *			encodeLen：输出参数，UTF-8编码的字节数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_json_encode(NETCA_JSON json,int flag,unsigned char **encode,int* encodeLen);

/*
 *		netca_json_gettype
 *			获取JSON的类型
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回JSON的类型，失败返回-1
 */
int NETCAAPI netca_json_gettype(NETCA_JSON json);


/*
 *		netca_json_istrue
 *			判断JSON是否为true
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			如果JSON为true，返回1，否则返回0
 */
int NETCAAPI netca_json_istrue(NETCA_JSON json);

/*
 *		netca_json_getnumber
 *			获取JSON的数值
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回JSON的数值，如果不是数值类型返回-1
 */
double NETCAAPI netca_json_getnumber(NETCA_JSON json);


/*
 *		netca_json_getstring
 *			获取JSON的字符串
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回JSON的字符串，失败返回NULL
 */
const char * NETCAAPI netca_json_getstring(NETCA_JSON json);

/*
 *		netca_json_getstringlength
 *			获取JSON的字符串的长度
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回JSON的字符串的字节数，失败返回NULL
 */
int NETCAAPI netca_json_getstringlength(NETCA_JSON json);

/*
 *		netca_json_getarraysize
 *			获取JSON的数组元素个数
 *		参数：
 *			json：JSON句柄
 *		返回值：
 *			成功返回JSON的数组元素个数，失败返回-1
 */
int NETCAAPI netca_json_getarraysize(NETCA_JSON json);


/*
 *		netca_json_getarrayitem
 *			获取JSON的数组元素
 *		参数：
 *			json：JSON句柄
 *			index：输入参数，索引值
 *		返回值：
 *			成功返回JSON的数组的第index个元素，失败返回NULL
 */
NETCA_JSON NETCAAPI netca_json_getarrayitem(NETCA_JSON json,int index);

/*
 *		netca_json_traverse
 *			遍历JSON对象
 *		参数：
 *			json：JSON句柄
 *			func：输入参数，遍历函数
 *			context:遍历函数的第一个参数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_json_traverse(NETCA_JSON json,netca_json_traverse_func func,void *context);

/*
 *		netca_json_getobjectvalue
 *			获取JSON的对象元素的值
 *		参数：
 *			json：JSON句柄
 *			name：输入参数，名称,UTF-8编码
 *			nameLen：输入参数，名称的长度
 *		返回值：
 *			成功返回JSON的对应名称的值，失败返回NULL
 */
NETCA_JSON NETCAAPI netca_json_getobjectvalue(NETCA_JSON json,const unsigned char *name,int nameLen);


#ifdef __cplusplus
	}	
#endif
#endif
