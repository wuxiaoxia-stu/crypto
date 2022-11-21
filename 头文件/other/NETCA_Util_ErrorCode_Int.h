#ifndef NETCA_UTIL_ERRORCODE_INT_INLCUDE_H
#define NETCA_UTIL_ERRORCODE_INT_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_igetGeneralError
 *			返回通用的错误描述
 *		参数：
 *			errcode：输入参数，错误号
 *		返回值：
 *			成功返回通用的错误描述，失败返回""
 */
const char * NETCAAPI netca_igetGeneralError(int errcode);
/*
 *		netca_igetStreamError
 *			返回STREAM的错误描述
 *		参数：
 *			errcode：输入参数，错误号
 *		返回值：
 *			成功返回STREAM的错误描述，失败返回""
 */
const char * NETCAAPI netca_igetStreamError(int errcode);

#ifdef __cplusplus
	}	
#endif
#endif
