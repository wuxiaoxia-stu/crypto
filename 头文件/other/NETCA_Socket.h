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


struct NETCA_SOCKET_st;
typedef struct NETCA_SOCKET_st* NETCA_SOCKET;


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
 *			�Ͽ�socket����
 *		������
 *			sock��SOCKET���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_socket_disconnect(NETCA_SOCKET sock);

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


#ifdef __cplusplus
	}	
#endif

#endif
