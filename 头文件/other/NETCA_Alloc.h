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
 *			�ڴ����
 *		������
 *			size�����������Ҫ������ڴ��С
 *			filename��������������ñ��������ļ�����ͨ��ʹ��__FILE__
 *			lineno��������������ñ��������кţ�ͨ��ʹ��__LINE__
 *		����ֵ��
 *			�ɹ�������Ч�ķ��䵽���ڴ�ָ�룬ʧ�ܷ���NULL
 */
void * NETCAAPI netca_malloc(long size,const char *filename,int lineno);

/*
 *		netca_free
 *			�ڴ��ͷ�
 *		������
 *			buf��Ҫ�ͷŵķ���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_free(void *buf);

/*
 *		netca_setallocfunc
 *			�����ڴ������ͷź�����������netca_malloc����֮ǰʹ��
 *		������
 *			my_malloc������������ڴ���亯��
 *			my_free������������ڴ��ͷź���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_setallocfunc(netca_malloc_func my_malloc,netca_free_func my_free);

/*
 *		netca_setdebugalloc
 *			����ʹ�õ��Ե��ڴ������ͷź�����������netca_malloc����֮ǰʹ��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_setdebugalloc(void);

/*
 *		netca_printdebugalloc
 *			����ڴ������Ϣ���ļ�
 *		������
 *			filename������������ļ���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_printdebugalloc(const char *filename);

/*
 *		netca_getmallocfunc
 *			��ȡ�ڴ���亯��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ������ڴ���亯����ʧ�ܷ���NULL
 */
netca_malloc_func NETCAAPI netca_getmallocfunc(void);

/*
 *		netca_getfreefunc
 *			��ȡ�ڴ��ͷź���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ������ڴ��ͷź�����ʧ�ܷ���NULL
 */
netca_free_func NETCAAPI netca_getfreefunc(void);

#ifdef __cplusplus
	}	
#endif
#endif
