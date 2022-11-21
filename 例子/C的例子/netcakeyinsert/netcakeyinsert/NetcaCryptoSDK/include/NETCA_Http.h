#ifndef NETCA_HTTP_INCLUDE_H
#define NETCA_HTTP_INCLUDE_H

#include "NETCA_Uri.h"
#include "NETCA_Socket.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_HTTP_st;
typedef struct NETCA_HTTP_st* NETCA_HTTP;

enum
{
	NETCA_HTTP_METHOD_GET			=0,		
	NETCA_HTTP_METHOD_POST			=1,		
};

/*
 *		netca_http_new
 *			����һ��HTTP���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��HTTP�����ʧ�ܷ���NULL
 */
NETCA_HTTP NETCAAPI netca_http_new(void);

/*
 *		netca_http_free
 *			�ͷ�HTTP���
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_http_free(NETCA_HTTP http);


/*
 *		netca_http_newfromurl
 *			����URL����һ��HTTP���
 *		������
 *			url��HTTP��URL���
 *		����ֵ��
 *			�ɹ�������Ч��HTTP�����ʧ�ܷ���NULL
 */
NETCA_HTTP NETCAAPI netca_http_newfromurl(NETCA_URI url);


/*
 *		netca_http_sethost
 *			����HTTP��������IP
 *		������
 *			http��HTTP���
 *			host��������IP
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_sethost(NETCA_HTTP http,NETCA_UString host);

/*
 *		netca_http_gethost
 *			���HTTP��������IP
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����HTTP��������IP��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_http_gethost(NETCA_HTTP http);


/*
 *		 
 *			����HTTP�Ķ˿ں�
 *		������
 *			http��HTTP���
 *			port������������˿ں�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setport(NETCA_HTTP http,int port);


/*
 *		netca_http_getport
 *			��ȡHTTP�Ķ˿ں�
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ����ض˿ںţ�ʧ�ܷ���-1
 */
int NETCAAPI netca_http_getport(NETCA_HTTP http);


/*
 *		netca_http_connect
 *			����HTTP������
 *		������
 *			http��HTTP���
 *			timeout��������������ӳ�ʱ�����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout�볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_connect(NETCA_HTTP http,int timeout);

/*
 *		netca_ldap_disconnect
 *			�Ͽ���HTTP������������
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_disconnect(NETCA_HTTP http);

/*
 *		netca_http_setmethod
 *			����HTTP����ķ���
 *		������
 *			http��HTTP���
 *			method���������������ķ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setmethod(NETCA_HTTP http,int method);


/*
 *		netca_http_setrequestcharset
 *			����HTTP������ַ���
 *		������
 *			http��HTTP���
 *			charset�����������������ַ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setrequestcharset(NETCA_HTTP http,const char *charset);


/*
 *		netca_http_setrequestcharset
 *			����HTTP����ͷ��
 *		������
 *			http��HTTP���
 *			name���������������
 *			value�����������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setrequestheader(NETCA_HTTP http,const char *name,const char *value);

/*
 *		netca_http_setpath
 *			����HTTP������Դ��·��
 *		������
 *			http��HTTP���
 *			path��������Դ��·��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setpath(NETCA_HTTP http,NETCA_UString path);

/*
 *		netca_http_setformrequest
 *			����HTTP������
 *		������
 *			http��HTTP���
 *			name����������
 *			value������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setformrequest(NETCA_HTTP http,NETCA_UString name,NETCA_UString value);

/*
 *		netca_http_clearrequest
 *			���HTTP����
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_clearrequest(NETCA_HTTP http);


/*
 *		netca_http_setrequestlength
 *			����HTTP��Content-Length��ֵ
 *		������
 *			http��HTTP���
 *			length������������������ݵĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setrequestlength(NETCA_HTTP http,int length);

/*
 *		netca_http_requestdata_init
 *			����HTTPͷ
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_requestdata_init(NETCA_HTTP http);
/*
 *		netca_http_requestdata_update
 *			���HTTP���������ݣ��ɶ�ε���
 *		������
 *			http��HTTP���
 *			data�������������������
 *			length������������������ݵĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_requestdata_update(NETCA_HTTP http,const unsigned char *data,int length);

/*
 *		netca_http_requestdata_finish
 *			����HTTP����������
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_requestdata_finish(NETCA_HTTP http);


/*
 *		netca_http_getresponsestatus
 *			��ȡHTTP��Ӧ
 *		������
 *			http��HTTP���
 *			status�����������HTTP��Ӧ״̬
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_getresponsestatus(NETCA_HTTP http,int *status);

/*
 *		netca_http_getresponse
 *			��ȡHTTP��Ӧ��Content-Length
 *		������
 *			http��HTTP���
 *			length�����������HTTP��Ӧ�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_getresponselength(NETCA_HTTP http,int *length);

/*
 *		netca_http_getresponseheadercount
 *			��ȡHTTP��Ӧͷ����ֵ�Ը���
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�������Ӧͷ����ֵ�Ը�����ʧ�ܷ���-1
 */
int NETCAAPI netca_http_getresponseheadercount(NETCA_HTTP http);

/*
 *		netca_http_getresponseheadername
 *			��ȡHTTP��Ӧͷ������,����ֵʹ��NETCA_FREE���ͷ�
 *		������
 *			http��HTTP���
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�������Ӧͷ�ĵ�index�����ƣ�ʧ�ܷ���NULL
 */
char* NETCAAPI netca_http_getresponseheadername(NETCA_HTTP http,int index);


/*
 *		netca_http_getresponseheadervalue
 *			��ȡHTTP��Ӧͷ��ֵ,����ֵʹ��NETCA_FREE���ͷ�
 *		������
 *			http��HTTP���
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�������Ӧͷ�ĵ�index��ֵ��ʧ�ܷ���NULL
 */
char* NETCAAPI netca_http_getresponseheadervalue(NETCA_HTTP http,int index);

/*
 *		netca_http_findresponseheadervalue
 *			��ȡHTTP��Ӧͷ��ֵ,����ֵʹ��NETCA_FREE���ͷ�
 *		������
 *			http��HTTP���
 *			name�������������Ӧͷ����
 *		����ֵ��
 *			�ɹ�������Ӧͷ�����ƶ�Ӧ��ֵ��ʧ�ܷ���NULL
 */
char* NETCAAPI netca_http_findresponseheadervalue(NETCA_HTTP http,const char *name);

/*
 *		netca_http_setresponsecharset
 *			����HTTP��Ӧ���ַ���
 *		������
 *			http��HTTP���
 *			charset�������������Ӧ���ַ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setresponsecharset(NETCA_HTTP http,const char *charset);



/*
 *		netca_http_getresponse
 *			��ȡHTTP��Ӧ�����ݣ��ɶ�ε���
 *		������
 *			http��HTTP���
 *			buf���������������HTTP��Ӧ������
 *			buflen�����������buf�ĳ���
 *			readlen��������������ض��������ݳ��ȡ�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_getresponse(NETCA_HTTP http,unsigned char *buf,int buflen,int *readlen);





/*
 *		netca_http_settimeout
 *			���ó�ʱֵ
 *		������
 *			http��HTTP���
 *			timeout�������������ʱ�����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout�볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_settimeout(NETCA_HTTP http,int timeout);

/*
 *		netca_http_setpersistentconnection
 *			���ó־�����
 *		������
 *			http��HTTP���
 *			value�����������Ϊ����ʹ�ó־����ӣ�Ϊ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setpersistentconnection(NETCA_HTTP http,int value);

/*
 *		netca_http_setabsoluteURI
 *			�����Ƿ�ʹ�þ���URI
 *		������
 *			http��HTTP���
 *			value�����������Ϊ����ʹ��ʹ�þ���URI��Ϊ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setabsoluteURI(NETCA_HTTP http,int value);

#define NETCA_HTTP_AUTH_IMMEDIATE_BASIC	1
/*
 *		netca_http_setauthinfo
 *			����HTTP��֤��Ϣ�����������������ȥ��֤�û��������Ƿ���ȷ��Ҫ������Ӧ��״̬�����ж��û��������Ƿ���ȷ��
 *		������
 *			http��HTTP���
 *			flag��������������������NETCA_HTTP_AUTH_IMMEDIATE_BASICλ��һ��ʼ�ͷ���HTTP Basic��֤��ͷ
 *			username������������û���
 *			pwd���������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setauthinfo(NETCA_HTTP http,int flag,const char *username,const char *pwd);


#define NETCA_HTTP_PROXY_TYPE_GLOBAL	1
#define NETCA_HTTP_PROXY_TYPE_LOCAL		2
/*
 *		netca_http_setproxy
 *			����HTTP������Ϣ��
 *		������
 *			http��HTTP���
 *			flag��������������ΪNETCA_HTTP_PROXY_TYPE_GLOBAL�������Ч�����ΪNETCA_HTTP_PROXY_TYPE_LOCAL�򱾾����Ч
 *			host������������������������ΪNULL���ʾ��ʹ�ô���
 *			port���������������Ķ˿ں�
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setproxy(NETCA_HTTP http,int flag,NETCA_UString host,int port);

#ifdef __cplusplus
	}	
#endif

#endif

