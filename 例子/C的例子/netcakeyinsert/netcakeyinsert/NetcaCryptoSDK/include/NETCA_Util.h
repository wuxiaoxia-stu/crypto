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
 *			��ȡNETCA_UTIL��İ汾��Ϣ
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_UTIL��İ汾��Ϣ��ʧ�ܷ���NULL
 */
const char *NETCAAPI netca_util_version(void);

/*
 *		netca_hexencode
 *			HEX����
 *		������
 *			cap��������������Ϊ��ʹ�ô�д��ĸ������ʹ��Сд��ĸ
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�HEX���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_hexencode(int cap,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_hexencode
 *			HEX����
 *		������
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�HEX���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_hexdecode(const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_base64encode
 *			Base64����
 *		������
 *			flag�����������Base64������
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�Base64���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_base64encode(int flag,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_base64decode
 *			Base64����
 *		������
 *			flag�����������Base64������
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�Base64���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_base64decode(int flag,const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_pemencode
 *			PEM����
 *		������
 *			headname�����������PEMͷ����
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�PEM���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_pemencode(const char *headname,const unsigned char *src,long srclen,char **desc,long *desclen);
/*
 *		netca_pemdecode
 *			PEM����
 *		������
 *			headname�����������PEMͷ����
 *			src�����������Ҫ���������
 *			srclen�����������src�ĳ���
 *			desc��������������ص�PEM���������ݣ���NETCA_FREE�ͷ�
 *			desclen���������������desc�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_pemdecode(const char *headname,const char *src,long srclen,unsigned char **desc,long *desclen);

/*
 *		netca_bsearch
 *			��������
 *		������
 *			key�����������Ҫ������key
 *			base�������������������������
 *			count��������������ݵ�����
 *			size�����������ÿ�����ݵĴ�С
 *			compare������������ȽϺ���
 *			pos��������������ص�һ�����Բ����λ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_bsearch(const void *key,const void *base,long count,long size,
						   int (*compare)(const void *the_key,const void *a_value),long *pos);

/*
 *		netca_data_blob_new
 *			����һ��NETCA_Data_Blob
 *		������
 *			data���������������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_Data_Blob��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_data_blob_new(const unsigned char *data,long datalen);
/*
 *		netca_data_blob_free
 *			�ͷ�NETCA_Data_Blob
 *		������
 *			blob��BLOB
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_data_blob_free(NETCA_Data_Blob blob);

/*
 *		netca_dso_load
 *			��̬����һ��DLL
 *		������
 *			filename���ļ���
 *		����ֵ��
 *			�ɹ�����DLL�����ʧ�ܷ���NULL
 */
NETCA_DSOHandle NETCAAPI netca_dso_load(NETCA_UString filename);
/*
 *		netca_dso_free
 *			�ͷ�DLL���
 *		������
 *			handle��DLL���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_dso_free(NETCA_DSOHandle handle);

/*
 *		netca_dso_getfunction
 *			��ȡDLL�еĺ���
 *		������
 *			handle��DLL���
 *			funcname�����������������
 *		����ֵ��
 *			�ɹ����غ���ָ�룬ʧ�ܷ���NULL
 */
netca_dso_func NETCAAPI netca_dso_getfunction(NETCA_DSOHandle handle,const char *funcname);

/*
 *		netca_tls_alloc
 *			��ȡ�ֲ߳̾��洢������
 *		������
 *			index������������ɹ������ֲ߳̾��洢������
 *			destructor��������������߳��˳���ʱ���ͷ����ݵĺ���������ΪNULL
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_tls_alloc(NETCA_TLSIndex *index,void (*destructor)(void*)); 

/*
 *		netca_tls_setvalue
 *			�����ֲ߳̾��洢��ֵ
 *		������
 *			index������������ֲ߳̾��洢������
 *			value������������ֲ߳̾��洢��ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_tls_setvalue(NETCA_TLSIndex index,void *value);

/*
 *		netca_tls_getvalue
 *			��ȡ�ֲ߳̾��洢��ֵ
 *		������
 *			index������������ֲ߳̾��洢������
 *		����ֵ��
 *			�ɹ������ֲ߳̾��洢��ֵ��ʧ�ܷ���NULL
 */
void *NETCAAPI netca_tls_getvalue(NETCA_TLSIndex index);


/*
 *		netca_tls_free
 *			�ͷ��ֲ߳̾��洢������
 *		������
 *			index������������ֲ߳̾��洢������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_tls_free(NETCA_TLSIndex index);

/*
 *		netca_setlasterror
 *			���ô����
 *		������
 *			value����������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_setlasterror(int value);

/*
 *		netca_getlasterror
 *			��ȡ�����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ش����
 */
int NETCAAPI netca_getlasterror();


#ifdef _WIN32

/*
 *		netca_getwinversion
 *			��ȡwindows�汾
 *		������
 *			��
 *		����ֵ��
 *			����windows�汾��Ϣ
 */
OSVERSIONINFO NETCAAPI netca_getwinversion(void);
/*
 *		netca_winuseunicode
 *			�ж�windows�Ƿ�ʹ��UNICODE����
 *		������
 *			��
 *		����ֵ��
 *			�����ʹ��UNICODE���뷵��1�����򷵻�0
 */
int NETCAAPI netca_winuseunicode(void);
#endif

#ifdef __cplusplus
}
#endif
#endif
