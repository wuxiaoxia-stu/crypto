#ifndef NETCA_SOCKET_INCLUDE_H
#define NETCA_SOCKET_INCLUDE_H

#include "NETCA_UString.h"

#ifdef __cplusplus
extern "C"
	{
#endif

enum
{
	NETCA_SOCKET_TYPE_TCP			=0,		
	NETCA_SOCKET_TYPE_UDP			=1,		
};

enum
{
	NETCA_SOCKET_SHUTDOWN_TYPE_RECEIVE	=0,
	NETCA_SOCKET_SHUTDOWN_TYPE_SEND		=1,
	NETCA_SOCKET_SHUTDOWN_TYPE_BOTH		=2,
};

#define NETCA_SOCKET_STATUS_TYPE_READ		1
#define NETCA_SOCKET_STATUS_TYPE_WRITE		2
#define NETCA_SOCKET_STATUS_TYPE_EXCEPT		4


struct NETCA_SOCKET_st;
typedef struct NETCA_SOCKET_st* NETCA_SOCKET;


#define NETCA_DNS_TYPE_IPV4_ADDRESS		1
#define NETCA_DNS_TYPE_IPV6_ADDRESS		2

struct NETCA_DNS_IP_ADDRESS_st
{
	int m_isIpv4;
	int m_ttl;
	unsigned char m_ipaddress[16];
};
typedef struct NETCA_DNS_IP_ADDRESS_st* NETCA_DNS_IP_ADDRESS;


/*
 *		netca_socket_new
 *			����һ��SOCKET���
 *		������
 *			type�����������SOCKET������
 *		����ֵ��
 *			�ɹ�������Ч��SOCKET�����ʧ�ܷ���NULL
 */
NETCA_SOCKET NETCAAPI netca_socket_new(int type);

/*
 *		netca_socket_free
 *			�ͷ�SOCKET���
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_socket_free(NETCA_SOCKET sock);


/*
 *		netca_socket_connect
 *			���ӷ�����
 *		������
 *			sock��SOCKET���
 *			host��������������IP��֧��IDN
 *			port������������������˿ں�
 *			timeout��������������ӳ�ʱ�ĺ����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout���볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_connect(NETCA_SOCKET sock,NETCA_UString host,int port,int timeout);


/*
 *		netca_socket_disconnect
 *			�ر�socket����
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_disconnect(NETCA_SOCKET sock);

/*
 *		netca_socket_shutdown
 *			�Ͽ�socket����
 *		������
 *			sock��SOCKET���
 *			howto������������Ͽ����ӵķ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_shutdown(NETCA_SOCKET sock,int howto);
/*
 *		netca_socket_settimeout
 *			����socket�Ķ�д��ʱֵ
 *		������
 *			sock��SOCKET���
 *			timeout�������������ʱ�ĺ����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout���볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_settimeout(NETCA_SOCKET sock,int timeout);


/*
 *		netca_socket_read
 *			������
 *		������
 *			sock��SOCKET���
 *			data��������������ض���������
 *			length�����������Ҫ�������ݳ���
 *			readlen��������������ض��������ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_read(NETCA_SOCKET sock,unsigned char *data,int length,int *readlen);

/*
 *		netca_socket_readn
 *			��N�ֽڵ����ݣ�������N�ֽ���ʧ��
 *		������
 *			sock��SOCKET���
 *			data��������������ض���������
 *			length�����������Ҫ�������ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_readn(NETCA_SOCKET sock,unsigned char *data,int length);


/*
 *		netca_socket_write
 *			��������
 *		������
 *			sock��SOCKET���
 *			data�����������Ҫ���͵�����
 *			length�����������Ҫ���͵����ݳ���
 *			writelen��������������ط��͵����ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_write(NETCA_SOCKET sock,const unsigned char *data,int length,int* writelen);

/*
 *		netca_socket_write
 *			����N�Լ������ݣ����Ͳ���N�ֽ���ʧ��
 *		������
 *			sock��SOCKET���
 *			data�����������Ҫ���͵�����
 *			length�����������Ҫ���͵����ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_writen(NETCA_SOCKET sock,const unsigned char *data,int length);


/*
 *		netca_socket_setreadbuflen
 *			���ý��ջ�������С
 *		������
 *			sock��SOCKET���
 *			length��������������ջ�������С
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_setreadbuflen(NETCA_SOCKET sock,int length);


/*
 *		netca_socket_setwritebuflen
 *			���÷��ͻ�������С
 *		������
 *			sock��SOCKET���
 *			length��������������ͻ�������С
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_setwritebuflen(NETCA_SOCKET sock,int length);



/*
 *		netca_socket_reconnect
 *			�������ӷ�����
 *		������
 *			sock��SOCKET���
 *			timeout��������������ӳ�ʱ�ĺ����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout���볬ʱ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_reconnect(NETCA_SOCKET sock,int timeout);

/*
 *		netca_socket_getstatus
 *			��ȡSOCKET�����״̬
 *		������
 *			sock��SOCKET���
 *			status������������ɹ�����SOCKET�����״̬
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_getstatus(NETCA_SOCKET sock,int* status);


/*
 *		netca_socket_sendto
 *			����UDP����
 *		������
 *			sock��SOCKET���
 *			data�����������Ҫ���͵�����
 *			length�����������Ҫ�������ݳ���
 *			writelen��������������ط��͵����ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_sendto(NETCA_SOCKET sock,const unsigned char *data,int length,int *writelen);

/*
 *		netca_socket_recvfrom
 *			UDP������
 *		������
 *			sock��SOCKET���
 *			data��������������ض���������
 *			length�����������Ҫ�������ݳ���
 *			readlen��������������ض��������ݳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_recvfrom(NETCA_SOCKET sock,unsigned char *data,int length,int *readlen);

/*
 *		netca_socket_getipaddress
 *			ʹ��DNS�����õ�IP��ַ
 *		������
 *			dnsServerIp�����������DNS��������IP
 *			hostName�����������ASCII�������������ǹ��ʻ���������ת��ΪASCII��
 *			type�����������IP��ַ������
 *			timeout�������������ʱ�ĺ����������Ϊ0��ΪĬ�ϳ�ʱֵ��Ϊ�����򲻻ᳬʱ��Ϊ��������timeout���볬ʱ
 *			ips������������ɹ����صõ���IP��ַ���飬ʹ��NETCA_FREE�ͷ�
 *			ipCount������������ɹ�����IP��ַ��Ŀ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_getipaddress(const char* dnsServerIp,const char* hostName,int type,int timeout,NETCA_DNS_IP_ADDRESS* ips,int *ipCount);
/*
 *		netca_socket_setdnsserveripaddress
 *			����DNS��������IP��ַ
 *		������
 *			dnsServerIp�����������DNS��������IP
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_setdnsserveripaddress(const char* dnsServerIp);

#ifdef __cplusplus
	}	
#endif

#endif
