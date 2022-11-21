#ifndef NETCA_FILEURL_INCLUDE_H
#define NETCA_FILEURL_INCLUDE_H

#include "NETCA_UString.h"
#include "NETCA_Uri.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_FileURL_st;
typedef struct NETCA_FileURL_st* NETCA_FileURL;


/*
 *		netca_fileurl_new
 *			����һ��FileURL���
 *		������
 *			filename������������ļ���
 *		����ֵ��
 *			�ɹ�������Ч��FileURL�����ʧ�ܷ���NULL
 */
NETCA_FileURL NETCAAPI netca_fileurl_new(NETCA_UString filename);

/*
 *		netca_fileurl_free
 *			�ͷ�FileURL���
 *		������
 *			url��FileURL���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_fileurl_free(NETCA_FileURL url);


/*
 *		netca_fileurl_newfromurl
 *			����һ��FileURL���
 *		������
 *			url��URL
 *		����ֵ��
 *			�ɹ�������Ч��FileURL�����ʧ�ܷ���NULL
 */
NETCA_FileURL NETCAAPI netca_fileurl_newfromurl(NETCA_URI url);

/*
 *		netca_fileurl_open
 *			���ļ�
 *		������
 *			url��FileURL���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_fileurl_open(NETCA_FileURL url);


/*
 *		netca_fileurl_close
 *			�ر��ļ�
 *		������
 *			url��FileURL���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_fileurl_close(NETCA_FileURL url);


/*
 *		netca_fileurl_getlength
 *			��ȡ�ļ�����
 *		������
 *			url��FileURL���
 *			length������������ļ�����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_fileurl_getlength(NETCA_FileURL url,integer64* length);

/*
 *		netca_fileurl_read
 *			���ļ����ɶ�ε���
 *		������
 *			url��FileURL���
 *			buf��������������ض���������
 *			buflen�����������buf�ĳ���
 *			readlen��������������ض��������ݳ��ȡ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_fileurl_read(NETCA_FileURL url,unsigned char *buf,int buflen,int *readlen);



#ifdef __cplusplus
	}	
#endif

#endif

