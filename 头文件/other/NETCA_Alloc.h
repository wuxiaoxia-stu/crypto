#ifndef NETCA_ALLOC_INLCUDE_H
#define NETCA_ALLOC_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#define NETCA_MALLOC(size) netca_malloc(size,__FILE__,__LINE__) 
#define NETCA_FREE(buf) netca_free(buf) 

typedef void *(NETCAAPI *netca_malloc_func)(long size,const char *filename,int lineno);
typedef void (NETCAAPI *netca_free_func)(void *buf);

/*
 *		netca_malloc
 *			内存分配
 *		参数：
 *			size：输入参数，要分配的内存大小
 *			filename：输入参数，调用本函数的文件名，通常使用__FILE__
 *			lineno：输入参数，调用本函数的行号，通常使用__LINE__
 *		返回值：
 *			成功返回有效的分配到的内存指针，失败返回NULL
 */
void * NETCAAPI netca_malloc(long size,const char *filename,int lineno);

/*
 *		netca_free
 *			内存释放
 *		参数：
 *			buf：要释放的分配
 *		返回值：
 *			无
 */
void NETCAAPI netca_free(void *buf);

/*
 *		netca_setallocfunc
 *			设置内存分配和释放函数，必须在netca_malloc调用之前使用
 *		参数：
 *			my_malloc：输入参数，内存分配函数
 *			my_free：输入参数，内存释放函数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_setallocfunc(netca_malloc_func my_malloc,netca_free_func my_free);

/*
 *		netca_setdebugalloc
 *			设置使用调试的内存分配和释放函数，必须在netca_malloc调用之前使用
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_setdebugalloc(void);

/*
 *		netca_printdebugalloc
 *			输出内存分配信息到文件
 *		参数：
 *			filename：输入参数，文件名
 *		返回值：
 *			无
 */
void NETCAAPI netca_printdebugalloc(const char *filename);

/*
 *		netca_getmallocfunc
 *			获取内存分配函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回内存分配函数，失败返回NULL
 */
netca_malloc_func NETCAAPI netca_getmallocfunc(void);

/*
 *		netca_getfreefunc
 *			获取内存释放函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回内存释放函数，失败返回NULL
 */
netca_free_func NETCAAPI netca_getfreefunc(void);

#ifdef __cplusplus
	}	
#endif
#endif
