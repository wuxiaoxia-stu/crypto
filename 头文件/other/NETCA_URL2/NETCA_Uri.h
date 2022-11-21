#ifndef NETCA_URI_INCLUDE_H
#define NETCA_URI_INCLUDE_H

#include "NETCA_UString.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_URI_st;
typedef struct NETCA_URI_st* NETCA_URI;

/*
 *		netca_uri_new
 *			����һ��URI���
 *		������
 *			uri�����������URI���ã�ASCII����
 *		����ֵ��
 *			�ɹ�������Ч��URI�����ʧ�ܷ���NULL
 */
NETCA_URI NETCAAPI netca_uri_new(const char *uri);


/*
 *		netca_uri_free
 *			�ͷ�URI���
 *		������
 *			uri��URI���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_uri_free(NETCA_URI uri);

/*
 *		netca_uri_getscheme
 *			��ȡURI��scheme
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�ɹ�������Ч��URI��scheme��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_getscheme(NETCA_URI uri);


/*
 *		netca_uri_gethost
 *			��ȡURI��������IP
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�ɹ�������Ч��URI��������IP��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_gethost(NETCA_URI uri);


/*
 *		netca_url_getport
 *			��ȡURI�Ķ˿ں�
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�ɹ�����URI�Ķ˿ںţ�ʧ�ܷ���-1
 */
int NETCAAPI netca_uri_getport(NETCA_URI uri);

/*
 *		netca_uri_getpath
 *			��ȡURI��·��
 *		������
 *			uri��URI���
 *			encoding���������������
 *		����ֵ��
 *			�ɹ�����URI��·����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_getpath(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_getquery
 *			��ȡURI�Ĳ�ѯ����
 *		������
 *			uri��URI���
 *			encoding���������������
 *		����ֵ��
 *			�ɹ�����URI�Ĳ�ѯ���֣�ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_getquery(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_hasquery
 *			�ж�URI�Ĳ�ѯ����
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�����URI�Ĳ�ѯ�����򷵻�1�����򷵻�0
 */
int NETCAAPI netca_uri_hasquery(NETCA_URI uri);


/*
 *		netca_uri_getfragment
 *			��ȡURI��fragment����
 *		������
 *			uri��URI���
 *			encoding���������������
 *		����ֵ��
 *			�ɹ�����URI��fragment���֣�ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_getfragment(NETCA_URI uri,const char *encoding);

/*
 *		netca_uri_hasfragment
 *			�ж�URI��fragment����
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�����URI��fragment�����򷵻�1�����򷵻�0
 */
int NETCAAPI netca_uri_hasfragment(NETCA_URI uri);

/*
 *		netca_uri_isrelref
 *			�ж�URI���Ƿ��������
 *		������
 *			uri��URI���
 *		����ֵ��
 *			�����URI����������򷵻�1�����򷵻�0
 */
int NETCAAPI netca_uri_isrelref(NETCA_URI uri);

/*
 *		netca_uri_ref_resolution
 *			����������URI
 *		������
 *			baseuri��Base URI���
 *			relref��URI������þ��
 *		����ֵ��
 *			�ɹ����췵�ع���õ���URI�����򷵻�NULL
 */
NETCA_URI NETCAAPI netca_uri_ref_resolution(NETCA_URI baseuri,NETCA_URI relref);

/*
 *		netca_uri_newfromunicode
 *			����һ��URI���
 *		������
 *			uri��URI����
 *			encoding���������������
 *		����ֵ��
 *			�ɹ�������Ч��URI�����ʧ�ܷ���NULL
 */
NETCA_URI NETCAAPI netca_uri_newfromunicode(NETCA_UString uri,const char *encoding);

/*
 *		netca_uri_getstring
 *			����URI���ַ�����ʾ��ASCII���룬����ֵʹ��NETCA_FREE���ͷ�
 *		������
 *			uri��URI����
 *		����ֵ��
 *			�ɹ�����URI���ַ�����ʧ�ܷ���NULL
 */
char* NETCAAPI netca_uri_getstring(NETCA_URI uri);


/*
 *		netca_uri_getunicodestring
 *			����URI���ַ�����ʾ
 *		������
 *			uri��URI����
 *			encoding���������������
 *		����ֵ��
 *			�ɹ�����URI���ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_uri_getunicodestring(NETCA_URI uri,const char *encoding);

#ifdef __cplusplus
	}	
#endif

#endif

