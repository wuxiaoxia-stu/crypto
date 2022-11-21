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
 *			创建一个SOCKET句柄
 *		参数：
 *			type：输入参数，SOCKET的类型
 *		返回值：
 *			成功返回有效的SOCKET句柄，失败返回NULL
 */
NETCA_SOCKET NETCAAPI netca_socket_new(int type);

/*
 *		netca_socket_free
 *			释放SOCKET句柄
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_socket_free(NETCA_SOCKET sock);


/*
 *		netca_socket_connect
 *			连接服务器
 *		参数：
 *			sock：SOCKET句柄
 *			host：服务器域名或IP，支持IDN
 *			port：输入参数，服务器端口号
 *			timeout：输入参数，连接超时的毫秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout毫秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_connect(NETCA_SOCKET sock,NETCA_UString host,int port,int timeout);


/*
 *		netca_socket_disconnect
 *			断开socket连接
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_disconnect(NETCA_SOCKET sock);

/*
 *		netca_socket_settimeout
 *			设置socket的读写超时值
 *		参数：
 *			sock：SOCKET句柄
 *			timeout：输入参数，超时的毫秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout毫秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_settimeout(NETCA_SOCKET sock,int timeout);


/*
 *		netca_socket_read
 *			读数据
 *		参数：
 *			sock：SOCKET句柄
 *			data：输出参数，返回读到的数据
 *			length：输入参数，要读的数据长度
 *			readlen：输出参数，返回读到的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_read(NETCA_SOCKET sock,unsigned char *data,int length,int *readlen);

/*
 *		netca_socket_readn
 *			读N字节的数据，读不到N字节算失败
 *		参数：
 *			sock：SOCKET句柄
 *			data：输出参数，返回读到的数据
 *			length：输入参数，要读的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_readn(NETCA_SOCKET sock,unsigned char *data,int length);


/*
 *		netca_socket_write
 *			发送数据
 *		参数：
 *			sock：SOCKET句柄
 *			data：输入参数，要发送的数据
 *			length：输入参数，要发送的数据长度
 *			writelen：输出参数，返回发送的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_write(NETCA_SOCKET sock,const unsigned char *data,int length,int* writelen);

/*
 *		netca_socket_write
 *			发送N自己的数据，发送不到N字节算失败
 *		参数：
 *			sock：SOCKET句柄
 *			data：输入参数，要发送的数据
 *			length：输入参数，要发送的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_writen(NETCA_SOCKET sock,const unsigned char *data,int length);


/*
 *		netca_socket_setreadbuflen
 *			设置接收缓冲区大小
 *		参数：
 *			sock：SOCKET句柄
 *			length：输入参数，接收缓冲区大小
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_setreadbuflen(NETCA_SOCKET sock,int length);


/*
 *		netca_socket_setwritebuflen
 *			设置发送缓冲区大小
 *		参数：
 *			sock：SOCKET句柄
 *			length：输入参数，发送缓冲区大小
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_setwritebuflen(NETCA_SOCKET sock,int length);



/*
 *		netca_socket_reconnect
 *			重新连接服务器
 *		参数：
 *			sock：SOCKET句柄
 *			timeout：输入参数，连接超时的毫秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout毫秒超时
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_reconnect(NETCA_SOCKET sock,int timeout);


#ifdef __cplusplus
	}	
#endif

#endif
