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
 *			关闭socket连接
 *		参数：
 *			sock：SOCKET句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_disconnect(NETCA_SOCKET sock);

/*
 *		netca_socket_shutdown
 *			断开socket连接
 *		参数：
 *			sock：SOCKET句柄
 *			howto：输入参数，断开连接的方向
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_shutdown(NETCA_SOCKET sock,int howto);
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

/*
 *		netca_socket_getstatus
 *			获取SOCKET句柄的状态
 *		参数：
 *			sock：SOCKET句柄
 *			status：输出参数，成功返回SOCKET句柄的状态
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_getstatus(NETCA_SOCKET sock,int* status);


/*
 *		netca_socket_sendto
 *			发送UDP数据
 *		参数：
 *			sock：SOCKET句柄
 *			data：输入参数，要发送的数据
 *			length：输入参数，要读的数据长度
 *			writelen：输出参数，返回发送的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_sendto(NETCA_SOCKET sock,const unsigned char *data,int length,int *writelen);

/*
 *		netca_socket_recvfrom
 *			UDP读数据
 *		参数：
 *			sock：SOCKET句柄
 *			data：输出参数，返回读到的数据
 *			length：输入参数，要读的数据长度
 *			readlen：输出参数，返回读到的数据长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_recvfrom(NETCA_SOCKET sock,unsigned char *data,int length,int *readlen);

/*
 *		netca_socket_getipaddress
 *			使用DNS解析得到IP地址
 *		参数：
 *			dnsServerIp：输入参数，DNS服务器的IP
 *			hostName：输入参数，ASCII码的域名，如果是国际化域名请先转换为ASCII码
 *			type：输入参数，IP地址的类型
 *			timeout：输入参数，超时的毫秒数，如果为0则为默认超时值，为负数则不会超时，为正数，则timeout毫秒超时
 *			ips：输出参数，成功返回得到的IP地址数组，使用NETCA_FREE释放
 *			ipCount：输出参数，成功返回IP地址数目。
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_getipaddress(const char* dnsServerIp,const char* hostName,int type,int timeout,NETCA_DNS_IP_ADDRESS* ips,int *ipCount);
/*
 *		netca_socket_setdnsserveripaddress
 *			设置DNS服务器的IP地址
 *		参数：
 *			dnsServerIp：输入参数，DNS服务器的IP
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_socket_setdnsserveripaddress(const char* dnsServerIp);

#ifdef __cplusplus
	}	
#endif

#endif
