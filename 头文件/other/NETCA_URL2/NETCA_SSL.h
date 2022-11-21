#ifndef NETCA_SSL_INCLUDE_H
#define NETCA_SSL_INCLUDE_H

#include "NETCA_Socket.h"
#include "NETCA_Http.h"
#include "NETCA_Ldap.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


struct NETCA_SSLContext_st;
typedef struct NETCA_SSLContext_st* NETCA_SSLContext;

enum
{
	NETCA_SSL_VERIFY_LEVEL_NONE	=0,					/* �Է�����֤�鲻�����κ���֤ */
	NETCA_SSL_VERIFY_LEVEL_CERT	=1,					/* �Է�����֤�����֤��·������֤�����ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_HTTP_NO_WILDCARD=2,		/* �Է�����֤�����֤��·������֤��������֤����֧��ͨ��������ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_HTTP	=3,					/* �Է�����֤�����֤��·������֤��������֤�����ǲ���֤����״̬ */
    NETCA_SSL_VERIFY_LEVEL_HTTPS = 3,
    NETCA_SSL_VERIFY_LEVEL_NO_REVOCATION =3,		/* �Է�����֤�����֤��·������֤��������֤�����ǲ���֤����״̬ */
	NETCA_SSL_VERIFY_LEVEL_SERVER_REVOCATION =4,	/* �Է�����֤�����֤��·������֤��������֤��������֤������֤�������״̬��������֤CA֤�������״̬ */
	NETCA_SSL_VERIFY_LEVEL_CA_REVOCATION =5,		/* �Է�����֤�����֤��·������֤��������֤��������֤����֤��·��������״̬ */
};



#define NETCA_TLS_TYPE_GMSSL			0
#define NETCA_TLS_TYPE_LEGACY_TLS1_0	1
#define NETCA_TLS_TYPE_TLS1_3			3
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
 *		netca_ssl_end
 *			����SSL��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ssl_end(void);

/*
 *		netca_ssl_set_special_host
 *			�������������
 *		������
 *			type���������������
 *			host�����������������IP��ַ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ssl_set_special_host(int type,const char* host);

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
 *		netca_socket_legacy_tls1_0ctx_new
 *			����һ��TLS V1.0�����ģ����ڷ���windows2003��IIS
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��SSL�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_legacy_tls1_0ctx_new(void);

/*
 *		netca_socket_islegacy_tls1_0
 *			�ж��Ƿ�ʹ��TLS V1.0������
 *		������
 *			host��������������IP��ַ
 *		����ֵ��
 *			���ʹ��TLS V1.0�����ķ���1�����򷵻�0
 */
int NETCAAPI netca_socket_islegacy_tls1_0(NETCA_UString host);

/*
 *		netca_socket_tls1_3ctx_new
 *			����һ��TLS V1.3������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��SSL�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_tls1_3ctx_new(void);

/*
 *		netca_socket_istls1_3
 *			�ж��Ƿ�ʹ��TLS 1.3������
 *		������
 *			host��������������IP��ַ
 *		����ֵ��
 *			���ʹ��TLS 1.3�����ķ���1�����򷵻�0
 */
int NETCAAPI netca_socket_istls1_3(NETCA_UString host);

/*
 *		netca_socket_https2ctx_new
 *			����һ��HTTP 2.0��TLS������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч��SSL�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_https2ctx_new(void);

/*
 *		netca_socket_ishttps2_host
 *			�ж��Ƿ�ʹ��HTTP 2.0��TLS������
 *		������
 *			host��������������IP��ַ
 *		����ֵ��
 *			���ʹ��HTTP 2.0��TLS�����ķ���1�����򷵻�0
 */
int NETCAAPI netca_socket_ishttps2_host(NETCA_UString host);

/*
 *		netca_socket_ishttps2_connect
 *			�ж��Ƿ�ʹ��HTTP 2.0
 *		������
 *			ssl��������������IP��ַ
 *		����ֵ��
 *			���ʹ��HTTP 2.0����1�����򷵻�0
 */
int NETCAAPI netca_socket_ishttps2_connect(NETCA_SSLContext ssl);

/*
 *		netca_socket_gmsslctx_new
 *			����һ������SSL������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч�Ĺ���SSL�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_gmsslctx_new(void);

/*
 *		netca_socket_gmssl_https2ctx_new
 *			����һ������SSL��HTTPS 2������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�������Ч�Ĺ���SSL��HTTPS 2�����ģ�ʧ�ܷ���NULL
 */
NETCA_SSLContext NETCAAPI netca_socket_gmssl_https2ctx_new(void);

/*
 *		netca_socket_isgmssl
 *			�ж��Ƿ�ʹ�ù���SSL
 *		������
 *			host��������������IP��ַ
 *		����ֵ��
 *			���ʹ�ù���SSL����1�����򷵻�0
 */
int NETCAAPI netca_socket_isgmssl(NETCA_UString host);
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
 *		netca_http_setssl
 *			����ʹ��SSL
 *		������
 *			ldap��LDAP���
 *			ssl��SSL������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ldap_setssl(NETCA_LDAP ldap,NETCA_SSLContext ssl);

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
int NETCAAPI netca_socket_sslctx_setverifyparam(NETCA_SSLContext ssl,int verifylevel, NETCA_PKI_CERTIFICATE_HANDLE* cacerts,int cacount, NETCA_PKI_CERTIFICATE_HANDLE* rootcerts,int rootcount);


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
int NETCAAPI netca_socket_sslctx_setclientcert(NETCA_SSLContext ssl, NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd);

/*
 *		netca_socket_getsslservercert
 *			��ȡSSL������֤��
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����SSL������֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_socket_getsslservercert(NETCA_SOCKET sock);


/*
 *		netca_http_getsslservercert
 *			��ȡSSL������֤��
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����SSL������֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_http_getsslservercert(NETCA_HTTP http);


/*
 *		netca_ldap_getsslservercert
 *			��ȡSSL������֤��
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			�ɹ�����SSL������֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCAAPI netca_ldap_getsslservercert(NETCA_LDAP ldap);
/*
 *		netca_http_getsslctx
 *			��ȡSSL�����ľ��
 *		������
 *			http��HTTP���
 *		����ֵ��
 *			�ɹ�����SSL�����ľ��
 */
NETCA_SSLContext NETCAAPI netca_http_getsslctx(NETCA_HTTP http);


/*
 *		netca_ldap_getsslctx
 *			��ȡSSL�����ľ��
 *		������
 *			ldap��LDAP���
 *		����ֵ��
 *			�ɹ�����SSL�����ľ��
 */
NETCA_SSLContext NETCAAPI netca_ldap_getsslctx(NETCA_LDAP ldap);

/*
 *		netca_socket_getsslctx
 *			��ȡSSL�����ľ��
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����SSL�����ľ��
 */
NETCA_SSLContext NETCAAPI netca_socket_getsslctx(NETCA_SOCKET sock);

/*
 *		netca_socket_write_ssl_alert_close_notify
 *			����SSL�Ĺرո澯��Ϣ
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_write_ssl_alert_close_notify(NETCA_SOCKET sock);

#ifdef __cplusplus
	}	
#endif

#endif
