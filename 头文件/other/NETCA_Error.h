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
 *			����һ������������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ش��������ģ�ʧ�ܷ���NULL
 */
NETCA_ERR_CTX NETCAAPI netca_err_ctx_new(void);

/*
 *		netca_err_ctx_free
 *			�ͷŴ���������
 *		������
 *			ctx������������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_err_ctx_free(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_put
 *			�Ѵ�����Ϣ�������������
 *		������
 *			ctx������������
 *			filename������������ļ�����ͨ��Ϊ__FILE__
 *			lineno������������кţ�ͨ��Ϊ__LINE__
 *			errcode����������������
 *			errdesc�������������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_put(NETCA_ERR_CTX ctx,const char *filename,int lineno,int errcode,const char *errdesc);

/*
 *		netca_err_ctx_print
 *			�Ѵ��������ĵĴ�����Ϣ�������׼�������
 *		������
 *			ctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_print(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_output
 *			�Ѵ��������ĵĴ�����Ϣ�������
 *		������
 *			stream����
 *			ctx������������
 *			errcode���������������ʱ���صĴ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_output(NETCA_STREAM stream,NETCA_ERR_CTX ctx,int *errcode);

/*
 *		netca_err_ctx_clean
 *			�Ѵ��������ĵĴ�����Ϣ�����
 *		������
 *			ctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_clean(NETCA_ERR_CTX ctx);

/*
 *		netca_err_ctx_geterrcode
 *			��ȡ���������ĵĴ����
 *		������
 *			ctx������������
 *			errcode��������������صĴ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_geterrcode(NETCA_ERR_CTX ctx,int *errcode);

/*
 *		netca_err_ctx_geterrdesc
 *			��ȡ���������ĵĴ�������
 *		������
 *			ctx������������
 *			buf��������������صĴ�������
 *			buflen�������������������С
 *			retlen��������������ش��������ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_geterrdesc(NETCA_ERR_CTX ctx,char *buf,int buflen,int *retlen);

/*
 *		netca_err_ctx_copy
 *			���ƴ��������ģ���srcctx�еĴ�����Ϣ���Ƶ�descctx��ȥ
 *		������
 *			srcctx��Դ����������
 *			descctx��Ŀ�����������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_err_ctx_copy(NETCA_ERR_CTX srcctx,NETCA_ERR_CTX descctx);

#ifdef __cplusplus
	}	
#endif
#endif
