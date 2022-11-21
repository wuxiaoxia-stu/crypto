#ifndef NETCA_LOG_V2_H
#define NETCA_LOG_V2_H

#include "NETCA_PKI_Const.h"


#ifdef __cplusplus
extern "C"
{
#endif


// 日志等级
#define NETCA_LOG_LEVEL_DEBUG		1
#define NETCA_LOG_LEVEL_INFO		2
#define NETCA_LOG_LEVEL_WARN		3
#define NETCA_LOG_LEVEL_ERROR		4
#define NETCA_LOG_LEVEL_FATAL		5

	// 输出模式
#define NETCA_LOG_MODE_FILE				1
#define NETCA_LOG_MODE_CONSOLE	2

	// 二进制数据类型
#define NETCA_LOG_BINTYPE_HEX			1
#define NETCA_LOG_BINTYPE_BASE64		2


struct NetcaLogStruct;
typedef NetcaLogStruct * NetcaLogHandle;


/*
 * NetcaCreateLogHandle
 * 创建日志的句柄
 * 参数
 *        handle, 指向获取到的日志句柄指针。
 * return
 *       成功返回 NETCA_PKI_SUCCESS， 失败返回其它。
 */
int NETCADLLAPI  NetcaCreateLogHandle(NetcaLogHandle * handle); 


/*
 * NetcaFreeLogHandle
 * 释放日志的句柄
 * 参数
 *        handle, 指向获取到的日志句柄指针。
 * return
 *       成功返回 NETCA_PKI_SUCCESS， 失败返回其它。
 */
void NETCADLLAPI  NetcaFreeLogHandle(NetcaLogHandle  handle); 



/*
 *	NetcaLogHandleSetConfigParam
 *		设置日志库参数。如果没有调用该接口，则默认的情况下记录的日志等级为error，输出方式为文件
 *	参数：
 *      handle: 日志句柄
 *		level：输入参数，记录日志的等级，高于该等级的日志将会记录
 *		type：输入参数，输出方式
 *		filepath：输入参数，日志文件的路径，UTF-8格式。
 *                这里面定义了日志文件的名称，不过日志文件会按照不同日期产生名称。
 *                文件名称+日期，构成实际的日志文件名称。当type类型为控制台时，filepath可以设为NULL。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI  NetcaLogHandleSetConfigParam(NetcaLogHandle handle,int level, int type, const char* filepath);


/*
 *	NetcaLogHandleReadConfigFile
 *		从配置文件中获取日志库参数。对于没有设置的参数，默认情况下与NetcaLogSetConfigParam说明一致。
 *	参数：
 *      handle: 日志句柄
 *		filepath：输入参数，日志参数配置文件路径，UTF-8格式。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI  NetcaLogHandleReadConfigFile(NetcaLogHandle handle,const char* filepath);

/*
 *	NetcaLogClose
 *		关闭Log文件。调用该接口后，如果再写入日志文件，则以默认参数的形式记录日志
 *	参数：
 *      handle: 日志句柄
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI  NetcaLogHandleClose(NetcaLogHandle handle);

/*
 *	NetcaLogHandleLogger
 *		写入指定等级的日志信息。如果日志信息写入到文件中，则可以使用事务可以对日志信息进行缓冲。
 *	参数：
 *      handle: 日志句柄
 *		level：输入参数，写入的日志信息的等级
 *		msg：输入参数，日志信息，UTF-8编码
 *		…：0个或者多个输入参数，参数规则与sprintf一致。字符串UTF-8编码
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI NetcaLogHandleLogger(NetcaLogHandle handle,int level, const char* msg, ...);

/*
 *	NetcaLogHandleBinLogger
 *		写入指定等级的二进制数据的日志信息。如果日志信息写入到文件中，则可以使用事务可以对日志信息进行缓冲。
 *	参数：
 *      handle: 日志句柄
 *		level：输入参数，写入的日志信息的等级。
 *		msg：输入参数，日志信息。二进制数据
 *		length：输入参数，msg的长度
 *		type：输入参数，表示使用Base64编码或者十六进制编码。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI  NetcaLogHandleBinLogger(NetcaLogHandle handle,int level, const unsigned char* msg, int length, int type);

/*
 *	NetcaLogHandleBeginTransaction
 *		开始日志事务，即日志信息会被缓冲起来。事务对于写入日志文件的模式有效，对于打印在控制台的方式无效。
 *	参数：
 *      handle: 日志句柄		
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI  NetcaLogHandleBeginTransaction(NetcaLogHandle handle);

/*
 *	NetcaCommitTransaction
 *		提交事务，即把缓冲的日志信息全部打印出来。
 *	参数：
 *      handle: 日志句柄		
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
 int NETCADLLAPI  NetcaLogHandleCommitTransaction(NetcaLogHandle handle);

/*
 *	NetcaLogHandleGetLogLevel
 *		获取当前写到文件或者控制台的日志等级。
 *	参数：
 *      handle: 日志句柄
 *	返回值：
 *		成功日志等级，失败返回-1
 *
 */
 int NETCADLLAPI  NetcaLogHandleGetLogLevel(NetcaLogHandle handle);

/*
 *	NetcaLogHandleLevelEnabled
 *		判断某一等级日志是否能够写下
 *	参数：
 *      handle: 日志句柄
 *		level：输入参数，需要判断的等级。
 *	返回值：
 *		能写下返回1，否则返回0
 *
 */
 int NETCADLLAPI  NetcaLogHandleLevelEnabled(NetcaLogHandle handle,int level);

#ifdef __cplusplus
}
#endif

#endif