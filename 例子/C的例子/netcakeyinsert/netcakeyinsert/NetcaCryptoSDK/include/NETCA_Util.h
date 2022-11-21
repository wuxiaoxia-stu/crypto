#ifndef NETCA_UTIL_INLCUDE_H
#define NETCA_UTIL_INLCUDE_H


#include "NETCA_BasicType.h"
#include "NETCA_Stream.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_util_version
 *			获取NETCA_UTIL库的版本信息
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_UTIL库的版本信息，失败返回NULL
 */
const char *NETCAAPI netca_util_version(void);

/*
 *		netca_hexencode
 *			HEX编码
 *		参数：
 *			cap：输入参数，如果为真使用大写字母，否则使用小写字母
 *			src：输入参数，要编码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的HEX编码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_hexencode(int cap,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_hexencode
 *			HEX解码
 *		参数：
 *			src：输入参数，要解码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的HEX解码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_hexdecode(const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_base64encode
 *			Base64编码
 *		参数：
 *			flag：输入参数，Base64编码标记
 *			src：输入参数，要编码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的Base64编码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_base64encode(int flag,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_base64decode
 *			Base64解码
 *		参数：
 *			flag：输入参数，Base64解码标记
 *			src：输入参数，要解码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的Base64解码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_base64decode(int flag,const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_pemencode
 *			PEM编码
 *		参数：
 *			headname：输入参数，PEM头名称
 *			src：输入参数，要编码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的PEM编码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_pemencode(const char *headname,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_pemdecode
 *			PEM解码
 *		参数：
 *			headname：输入参数，PEM头名称
 *			src：输入参数，要解码的数据
 *			srclen：输入参数，src的长度
 *			desc：输出参数，返回的PEM解码后的数据，用NETCA_FREE释放
 *			desclen：输出参数，返回desc的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_pemdecode(const char *headname,const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_bsearch
 *			二分搜索
 *		参数：
 *			key：输入参数，要搜索的key
 *			base：输入参数，进行搜索的数据
 *			count：输入参数，数据的项数
 *			size：输入参数，每项数据的大小
 *			compare：输入参数，比较函数
 *			pos：输出参数，返回第一个可以插入的位置
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_bsearch(const void *key,const void *base,long count,long size,
						   int (*compare)(const void *the_key,const void *a_value),long *pos);

/*
 *		netca_data_blob_new
 *			创建一个NETCA_Data_Blob
 *		参数：
 *			data：输入参数，数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_Data_Blob，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_data_blob_new(const unsigned char *data,long datalen);
/*
 *		netca_data_blob_free
 *			释放NETCA_Data_Blob
 *		参数：
 *			blob：BLOB
 *		返回值：
 *			无
 */
void NETCAAPI netca_data_blob_free(NETCA_Data_Blob blob);

/*
 *		netca_dso_load
 *			动态加载一个DLL
 *		参数：
 *			filename：文件名
 *		返回值：
 *			成功返回DLL句柄，失败返回NULL
 */
NETCA_DSOHandle NETCAAPI netca_dso_load(NETCA_UString filename);
/*
 *		netca_dso_free
 *			释放DLL句柄
 *		参数：
 *			handle：DLL句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_dso_free(NETCA_DSOHandle handle);

/*
 *		netca_dso_getfunction
 *			获取DLL中的函数
 *		参数：
 *			handle：DLL句柄
 *			funcname：输入参数，函数名
 *		返回值：
 *			成功返回函数指针，失败返回NULL
 */
netca_dso_func NETCAAPI netca_dso_getfunction(NETCA_DSOHandle handle,const char *funcname);

/*
 *		netca_tls_alloc
 *			获取线程局部存储的索引
 *		参数：
 *			index：输出参数，成功返回线程局部存储的索引
 *			destructor：输入参数，在线程退出的时候释放数据的函数，可以为NULL
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_tls_alloc(NETCA_TLSIndex *index,void (*destructor)(void*)); 

/*
 *		netca_tls_setvalue
 *			设置线程局部存储的值
 *		参数：
 *			index：输入参数，线程局部存储的索引
 *			value：输入参数，线程局部存储的值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_tls_setvalue(NETCA_TLSIndex index,void *value);

/*
 *		netca_tls_getvalue
 *			获取线程局部存储的值
 *		参数：
 *			index：输入参数，线程局部存储的索引
 *		返回值：
 *			成功返回线程局部存储的值，失败返回NULL
 */
void *NETCAAPI netca_tls_getvalue(NETCA_TLSIndex index);


/*
 *		netca_tls_free
 *			释放线程局部存储的索引
 *		参数：
 *			index：输入参数，线程局部存储的索引
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_tls_free(NETCA_TLSIndex index);

/*
 *		netca_setlasterror
 *			设置错误号
 *		参数：
 *			value：输入参数，错误号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_setlasterror(int value);

/*
 *		netca_getlasterror
 *			获取错误号
 *		参数：
 *			无
 *		返回值：
 *			成功返回错误号
 */
int NETCAAPI netca_getlasterror();


#ifdef _WIN32

/*
 *		netca_getwinversion
 *			获取windows版本
 *		参数：
 *			无
 *		返回值：
 *			返回windows版本信息
 */
OSVERSIONINFO NETCAAPI netca_getwinversion(void);
/*
 *		netca_winuseunicode
 *			判断windows是否使用UNICODE编码
 *		参数：
 *			无
 *		返回值：
 *			如果是使用UNICODE编码返回1，否则返回0
 */
int NETCAAPI netca_winuseunicode(void);
#endif

#ifdef __cplusplus
}
#endif
#endif
