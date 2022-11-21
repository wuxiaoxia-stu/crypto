#ifndef NETCA_SSL_INCLUDE_H
#define NETCA_SSL_INCLUDE_H

#include "NETCA_Socket.h"
#include "NETCA_Http.h"
#include "NETCA_Cert.h"

#ifdef __cplusplus
extern "C"
	{
#endif


struct NETCA_SSLContext_st;
typedef struct NETCA_SSLContext_st* NETCA_SSLContext;

struct NETCA_SSLSession_st;
typedef struct NETCA_SSLSession_st* NETCA_SSLSession;


enum
{
	NETCA_SSL_VERIFY_LEVEL_NONE	=0,					/* �Է�����֤�鲻�����κ���֤ */
	NETCA_SSL_VERIFY_LEVEL_CERT	=1,					/* �Է�����֤�����֤��·������֤�����ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_HTTP_NO_WILDCARD=2,		/* �Է�����֤�����֤��·������֤��������֤����֧��ͨ��������ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_HTTP	=3,					/* �Է�����֤�����֤��·������֤��������֤�����ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_NO_REVOCATION =3,		/* �Է�����֤�����֤��·������֤��������֤�����ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_SERVER_REVOCATION =4,		/* �Է�����֤�����֤��·������֤��������֤��������֤������֤�������״̬��������֤CA֤�������״̬ */
	NETCA_SSL_VERIFY_LEVEL_CA_REVOCATION =5,		/* �Է�����֤�����֤��·������֤��������֤��������֤����֤��·��������״̬ */
};

/*
 *		netca_ssl_init
 *			��ʼ��SSL��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ssl_init(void);


/*
 *		netca_socket_sslctx_new
 *			����һ��SSL������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��SSL�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_sslctx_new(void);


/*
 *		netca_socket_sslctx_new
 *			�ͷ�SSL������
 *		������
 *			ssl��SSL������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_socket_sslctx_free(NETCA_SSLContext ssl);

/*
 *		netca_socket_setssl
 *			����ʹ��SSL
 *		������
 *			sock��SOCKET���
 *			ssl��SSL������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_setssl(NETCA_SOCKET sock,NETCA_SSLContext ssl);

/*
 *		netca_socket_sslctx_dup
 *			����һ��SSL������
 *		������
 *			ssl��SSL������
 *		����ֵ��
 *			�ɹ�����SSL�����ģ�ʧ�ܷ���0
 */
NETCA_SSLContext NETCAAPI netca_socket_sslctx_dup(NETCA_SSLContext ssl);

/*
 *		netca_http_setssl
 *			����ʹ��SSL
 *		������
 *			http��HTTP���
 *			ssl��SSL������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_http_setssl(NETCA_HTTP http,NETCA_SSLContext ssl);



/*
 *		netca_socket_sslctx_setverifyparam
 *			����SSL��֤����
 *		������
 *			ssl��SSL������
 *			verifylevel�������������֤�ļ���
 *			cacerts�����������һ��CA֤��
 *			cacount�����������CA֤�����
 *			rootcerts�����������һ���֤��
 *			rootcount�������������֤�����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_sslctx_setverifyparam(NETCA_SSLContext ssl,int verifylevel,NETCA_CERT* cacerts,int cacount,NETCA_CERT* rootcerts,int rootcount);


/*
 *		netca_socket_sslctx_setverifytime
 *			����SSL��֤ʱ��
 *		������
 *			ssl��SSL������
 *			date�������������֤��ʱ�䣬���ΪNULL����Ϊ��ǰʱ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_sslctx_setverifytime(NETCA_SSLContext ssl,NETCA_Time date);

/*
 *		netca_socket_sslctx_setclientcert
 *			����SSL˫����֤��SSL�Ŀͻ���֤��
 *		������
 *			ssl��SSL������
 *			cert���ͻ���֤��
 *			pwd���������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_sslctx_setclientcert(NETCA_SSLContext ssl,NETCA_CERT cert,const char *pwd);

/*
 *		netca_socket_getsslservercert
 *			��ȡSSL������֤��
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����SSL������֤�飬ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_socket_getsslservercert(NETCA_SOCKET sock);


/*
 *		netca_http_getsslservercert
 *			��ȡSSL������֤��
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����SSL������֤�飬ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_http_getsslservercert(NETCA_HTTP http);


/*
 *		netca_http_getsslctx
 *			��ȡSSL�����ľ��
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����SSL�����ľ��
 */
NETCA_SSLContext NETCAAPI netca_http_getsslctx(NETCA_HTTP http);

#ifdef __cplusplus
	}	
#endif

#endif
