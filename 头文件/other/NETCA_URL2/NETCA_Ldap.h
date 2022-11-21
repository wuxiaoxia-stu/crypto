#ifndef NETCA_LDAP_INCLUDE_H
#define NETCA_LDAP_INCLUDE_H

#include "NETCA_Uri.h"
#include "NETCA_UString.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/* ����ֵ */
/* ��Ч���� */
#define NETCA_LDAP_INVALIDARG					0x50000
/* �Ѿ����� */
#define NETCA_LDAP_EXISIT							0x50001
/* ������ */
#define NETCA_LDAP_NOTEXISIT					0x50002
/* �ڴ����ʧ�� */
#define NETCA_LDAP_OUTOFMEMORY			0x50003
/* �ռ䲻�� */
#define NETCA_LDAP_NEEDMOREDATA			0x50004
/* ��Ŀ������������ */
#define NETCA_LDAP_SIZELIMIT_EXCEEDED		0x50005	
/* ��ʱ */
#define NETCA_LDAP_TIMEOUT						0x50006
/* ����DN����������� */
#define NETCA_LDAP_PWD_ERROR					0x50007
/* filter ����ȷ */
#define NETCA_LDAP_BADFILTER						0x50008
/* �ܾ����� */
#define NETCA_LDAP_ACCESSDENIED				0x50009
/* ��֧�� */
#define NETCA_LDAP_UNSUPPORTED				0x5000A
/* �޷����ӣ��������busy��down�� */
#define NETCA_LDAP_UNAVAILABLE				0x5000B
#define NETCA_LDAP_TIMELIMIT_EXCEEDED		0x5000C
/* ���������󻹼����� */
#define NETCA_LDAP_READ_EOS		0x5000D

struct NETCA_LDAP_st;
typedef struct NETCA_LDAP_st* NETCA_LDAP;

struct NETCA_LDAP_Result_st;
typedef struct NETCA_LDAP_Result_st* NETCA_LDAP_Result;

struct NETCA_LDAP_ResultItem_st;
typedef struct NETCA_LDAP_ResultItem_st* NETCA_LDAP_ResultItem;

struct NETCA_LDAP_Filter_st;
typedef struct NETCA_LDAP_Filter_st* NETCA_LDAP_Filter;

struct NETCA_LDAP_Attribute_st;
typedef struct NETCA_LDAP_Attribute_st* NETCA_LDAP_Attribute;

struct NETCA_LDAP_ResultIterator_st;
typedef struct NETCA_LDAP_ResultIterator_st* NETCA_LDAP_ResultIterator;

enum
{
	NETCA_LDAP_SCOPE_BASEOBJECT		=0,		
	NETCA_LDAP_SCOPE_SINGLELEVEL	=1,		
	NETCA_LDAP_SCOPE_WHOLESUBTREE	=2,
};


enum
{
	NETCA_LDAP_DEREF_NEVER			=0,
	NETCA_LDAP_DEREF_INSEARCHING	=1,
	NETCA_LDAP_DEREF_FINDINGBASEOBJ	=2,
	NETCA_LDAP_DEREF_ALWAYS			=3,
};

/*
 *		netca_ldap_new
 *			����һ��LDAP���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��LDAP�����ʧ�ܷ���NULL
 */
NETCA_LDAP NETCAAPI netca_ldap_new(void);

/*
 *		netca_ldap_free
 *			�ͷ�LDAP���
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_free(NETCA_LDAP ldap);


/*
 *		netca_ldap_sethost
 *			����LDAP��������IP
 *		������
 *			ldap��LDAP���
 *			host��������IP
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_sethost(NETCA_LDAP ldap,NETCA_UString host);

/*
 *		netca_ldap_gethost
 *			���LDAP��������IP
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			�ɹ�����LDAP��������IP��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ldap_gethost(NETCA_LDAP ldap);


/*
 *		netca_ldap_setport
 *			����LDAP�Ķ˿ں�
 *		������
 *			ldap��LDAP���
 *			port������������˿ں�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_setport(NETCA_LDAP ldap,int port);

/*
 *		netca_ldap_getport
 *			��ȡLDAP�Ķ˿ں�
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			�ɹ����ض˿ںţ�ʧ�ܷ���-1
 */
int NETCAAPI netca_ldap_getport(NETCA_LDAP ldap);

/*
 *		netca_ldap_connect
 *			����LDAP�������������������֤
 *		������
 *			ldap��LDAP���
 *			dn������������󶨵�DN
 *			pwd�����������DN��Ӧ�����룬���dn��pwd��ΪNULL�����ʾ������
 *			timeout��������������ӳ�ʱ�����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout�볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK����ʱ����NETCA_ERROR_TIMEOUT��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_connect(NETCA_LDAP ldap,NETCA_UString dn,NETCA_UString pwd,int timeout);

/*
 *		netca_ldap_disconnect
 *			�Ͽ�LDAP������
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_disconnect(NETCA_LDAP ldap);

/*
 *		netca_ldap_setderefoption
 *			����LDAP��������ķ�ʽ
 *		������
 *			ldap��LDAP���
 *			option�����������NETCA_LDAP_DEREF_NEVER��NETCA_LDAP_DEREF_INSEARCHING��NETCA_LDAP_DEREF_FINDINGBASEOBJ��NETCA_LDAP_DEREF_ALWAYS֮һ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_setderefoption(NETCA_LDAP ldap,int option);

/*
 *		netca_ldap_settimeout
 *			����LDAP����ĳ�ʱֵ
 *		������
 *			ldap��LDAP���
 *			timeout�����������LDAP����ʱ�����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout�볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_settimeout(NETCA_LDAP ldap,int timeout);

/*
 *		netca_ldap_setmaxentrynum
 *			����LDAP���ص�������Ŀ��
 *		������
 *			ldap��LDAP���
 *			number����������������Ŀ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_setmaxentrynum(NETCA_LDAP ldap,int number);

/*
 *		netca_ldap_search
 *			����LDAP
 *		������
 *			ldap��LDAP���
 *			basedn�����������������ʼ��DN
 *			scope����������������ķ�Χ��NETCA_LDAP_SCOPE_BASEOBJECT��NETCA_LDAP_SCOPE_SINGLELEVEL��NETCA_LDAP_SCOPE_WHOLESUBTREE֮һ
 *			filter�����������LDAP��������
 *			attrs�����������Ҫ���ص�������������
 *			attrcount�����������Ҫ���ص�������������Ԫ�ظ���
 *			result��������������ص��������
 *		����ֵ��
 *			�ɹ�����NETCA_OK����ʱ����NETCA_ERROR_TIMEOUT��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_search(NETCA_LDAP ldap,NETCA_UString basedn,int scope,NETCA_LDAP_Filter filter,const NETCA_UString *attrs,int attrcount,NETCA_LDAP_Result *result);

/*
 *		netca_ldap_search2
 *			����LDAP
 *		������
 *			ldap��LDAP���
 *			basedn�����������������ʼ��DN
 *			scope����������������ķ�Χ��NETCA_LDAP_SCOPE_BASEOBJECT��NETCA_LDAP_SCOPE_SINGLELEVEL��NETCA_LDAP_SCOPE_WHOLESUBTREE֮һ
 *			filter�����������LDAP��������
 *			attrs�����������Ҫ���ص�������������
 *			attrcount�����������Ҫ���ص�������������Ԫ�ظ���
 *			iterator��������������ص���������ĵ�����
 *		����ֵ��
 *			�ɹ�����NETCA_OK����ʱ����NETCA_ERROR_TIMEOUT��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_search2(NETCA_LDAP ldap,NETCA_UString basedn,int scope,NETCA_LDAP_Filter filter,const NETCA_UString *attrs,int attrcount,NETCA_LDAP_ResultIterator *iterator);


/*
 *		netca_ldap_filter_new
 *			�����ַ���������������
 *		������
 *			filterstr����������������������ַ�����ʾ
 *		����ֵ��
 *			�ɹ���������������ʧ�ܷ���NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_new(NETCA_UString filterstr);

/*
 *		netca_ldap_filter_and
 *			��������������������
 *		������
 *			filter1����������1
 *			filter2����������2
 *		����ֵ��
 *			�ɹ�����filter1 && filter2������������ʧ�ܷ���NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_and(NETCA_LDAP_Filter filter1,NETCA_LDAP_Filter filter2);

/*
 *		netca_ldap_filter_or
 *			�������������������
 *		������
 *			filter1����������1
 *			filter2����������2
 *		����ֵ��
 *			�ɹ�����filter1 || filter2������������ʧ�ܷ���NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_or(NETCA_LDAP_Filter filter1,NETCA_LDAP_Filter filter2);


/*
 *		netca_ldap_filter_or
 *			�������������������
 *		������
 *			filter����������
 *		����ֵ��
 *			�ɹ�����!filter������������ʧ�ܷ���NULL
 */
NETCA_LDAP_Filter NETCAAPI netca_ldap_filter_not(NETCA_LDAP_Filter filter);

/*
 *		netca_ldap_filter_free
 *			�ͷ���������
 *		������
 *			filter����������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_filter_free(NETCA_LDAP_Filter filter);

/*
 *		netca_ldap_result_free
 *			�ͷ��������
 *		������
 *			result���������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_result_free(NETCA_LDAP_Result result);

/*
 *		netca_ldap_result_count
 *			��������������
 *		������
 *			result���������
 *		����ֵ��
 *			�ɹ������������������ʧ�ܷ���-1
 */
int NETCAAPI netca_ldap_result_count(NETCA_LDAP_Result result);

/*
 *		netca_ldap_result_getitem
 *			������������
 *		������
 *			result���������
 *			index�������������������0����
 *		����ֵ��
 *			�ɹ����ص�index����������ʧ�ܷ���NULL
 */
NETCA_LDAP_ResultItem NETCAAPI netca_ldap_result_getitem(NETCA_LDAP_Result result,int index);

/*
 *		netca_ldap_resultitem_getdn
 *			�������������DN
 *		������
 *			item�����������
 *		����ֵ��
 *			�ɹ���������������DN��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ldap_resultitem_getdn(NETCA_LDAP_ResultItem item);


/*
 *		netca_ldap_resultitem_getattrcount
 *			����������������Ը���
 *		������
 *			item�����������
 *		����ֵ��
 *			�ɹ������������������Ը�����ʧ�ܷ���-1
 */
int NETCAAPI netca_ldap_resultitem_getattrcount(NETCA_LDAP_ResultItem item);

/*
 *		netca_ldap_resultitem_getattr
 *			�����������������
 *		������
 *			item�����������
 *			index�������������������0����
 *		����ֵ��
 *			�ɹ��������������ĵ�index�����ԣ�ʧ�ܷ���NULL
 */
NETCA_LDAP_Attribute NETCAAPI netca_ldap_resultitem_getattr(NETCA_LDAP_ResultItem item,int index);

/*
 *		netca_ldap_resultitem_free
 *			�ͷ����������
 *		������
 *			item�����������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_resultitem_free(NETCA_LDAP_ResultItem item);


/*
 *		netca_ldap_attribute_free
 *			�ͷ�����
 *		������
 *			attr������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_attribute_free(NETCA_LDAP_Attribute attr);

/*
 *		netca_ldap_attribute_getname
 *			��ȡ��������
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ������������ƣ�ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ldap_attribute_getname(NETCA_LDAP_Attribute attr);

/*
 *		netca_ldap_attribute_getvalue
 *			��ȡ����ֵ����������Ϊ�ַ�����ΪUTF-8��ʽ������û�а����ַ���������\0
 *		������
 *			attr������
 *			value��������������ص�����ֵ
 *			valuelen������������������valueΪNULL����*valuelen��������ֵ�������ܳ��ȣ���������ʱ*valuelen���벻С������ֵ�ĳ��ȣ������������ֵ�ĳ��ȡ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK�����Ȳ��㷵��NETCA_NEEDMOREDATA��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_attribute_getvalue(NETCA_LDAP_Attribute attr,unsigned char *value,int *valuelen);


/*
 *		netca_ldap_newfromurl
 *			����URL����һ��LDAP���
 *		������
 *			url��LDAP��URL���
 *		����ֵ��
 *			�ɹ�������Ч��LDAP�����ʧ�ܷ���NULL
 */
NETCA_LDAP NETCAAPI netca_ldap_newfromurl(NETCA_URI url);

/*
 *		netca_ldap_getresult
 *			����LDAP
 *		������
 *			ldap��LDAP���
 *			result��������������ص��������
 *		����ֵ��
 *			�ɹ�����NETCA_OK����ʱ����NETCA_ERROR_TIMEOUT��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_getresult(NETCA_LDAP ldap,NETCA_LDAP_Result *result);

/*
 *		netca_ldap_getresult
 *			����LDAP
 *		������
 *			ldap��LDAP���
 *			iterator��������������ص��������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_getresultiterator(NETCA_LDAP ldap,NETCA_LDAP_ResultIterator* iterator);

/*
 *		netca_ldap_getnextresultitem
 *			��ȡ��һ��������
 *		������
 *			iterator��������
 *			item��������������ص����������,ʧ�ܻ�û����һ���ʱ�򷵻�NULL
 *		����ֵ��
 *			�ɹ�����NETCA_OK����ʱ����NETCA_ERROR_TIMEOUT��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_getnextresultitem(NETCA_LDAP_ResultIterator iterator,NETCA_LDAP_ResultItem* item);

/*
 *		netca_ldap_iterator_free
 *			�ͷŵ�����
 *		������
 *			iterator��������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ldap_iterator_free(NETCA_LDAP_ResultIterator iterator);
#ifdef __cplusplus
	}	
#endif

#endif

