#ifndef NETCA_ERROR_INLCUDE_H
#define NETCA_ERROR_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_ErrorCode.h"

#ifdef __cplusplus
extern "C"
	{
#endif
	
/*
 *		netca_err_ctx_new
 *			创建一个错误上下文
 *		参数：
 *			无
 *		返回值：
 *			成功返回错误上下文，失败返回NULL
 */
NETCA_ERR_CTX NETCAAPI netca_err_ctx_new(void);

/*
 *		netca_err_ctx_free
 *			释放错误上下文
 *		参数：
 *			ctx：错误上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_err_ctx_free(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_put
 *			把错误信息加入错误上下文
 *		参数：
 *			ctx：错误上下文
 *			filename：输入参数，文件名，通常为__FILE__
 *			lineno：输入参数，行号，通常为__LINE__
 *			errcode：输入参数，错误号
 *			errdesc：输入参数，错误描述
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_put(NETCA_ERR_CTX ctx,const char *filename,int lineno,int errcode,const char *errdesc);

/*
 *		netca_err_ctx_print
 *			把错误上下文的错误信息输出到标准错误输出
 *		参数：
 *			ctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_print(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_output
 *			把错误上下文的错误信息输出到流
 *		参数：
 *			stream：流
 *			ctx：错误上下文
 *			errcode：输出参数，出错时返回的错误号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_output(NETCA_STREAM stream,NETCA_ERR_CTX ctx,int *errcode);

/*
 *		netca_err_ctx_clean
 *			把错误上下文的错误信息清除掉
 *		参数：
 *			ctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_clean(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_geterrcode
 *			获取错误上下文的错误号
 *		参数：
 *			ctx：错误上下文
 *			errcode：输出参数，返回的错误号
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_geterrcode(NETCA_ERR_CTX ctx,int *errcode);

/*
 *		netca_err_ctx_geterrdesc
 *			获取错误上下文的错误描述
 *		参数：
 *			ctx：错误上下文
 *			buf：输出参数，返回的错误描述
 *			buflen：输入参数，缓冲区大小
 *			retlen：输出参数，返回错误描述的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_geterrdesc(NETCA_ERR_CTX ctx,char *buf,int buflen,int *retlen);

/*
 *		netca_err_ctx_copy
 *			复制错误上下文，把srcctx中的错误信息复制到descctx中去
 *		参数：
 *			srcctx：源错误上下文
 *			descctx：目标错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_err_ctx_copy(NETCA_ERR_CTX srcctx,NETCA_ERR_CTX descctx);

#ifdef __cplusplus
	}	
#endif
#endif
