#ifndef _NETCA_LOG_H_
#define _NETCA_LOG_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

// 日志等级
#define NETCA_LOG_LEVEL_DEBUG		1
#define NETCA_LOG_LEVEL_INFO		2
#define NETCA_LOG_LEVEL_WARN		3
#define NETCA_LOG_LEVEL_ERROR		4
#define NETCA_LOG_LEVLE_FATAL		5

// 输出模式
#define NETCA_LOG_MODE_FILE				1
#define NETCA_LOG_MODE_CONSOLE	2

// 二进制数据类型
#define NETCA_LOG_BINTYPE_HEX			1
#define NETCA_LOG_BINTYPE_BASE64		2

/*
 *	NetcaLogSetConfigParam
 *		设置日志库参数。如果没有调用该接口，则默认的情况下记录的日志等级为error，输出方式为文件
 *	参数：
 *		level：输入参数，记录日志的等级，高于该等级的日志将会记录
 *		type：输入参数，输出方式
 *		filepath：输入参数，日志文件的路径，UTF-8格式。这里面定义了日志文件的名称，不过日志文件会按照不同日期产生名称。文件名称+日期，构成实际的日志文件名称。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogSetConfigParam(int level, int type, const char* filepath);

/*
 *	NetcaLogReadConfigFile
 *		从配置文件中获取日志库参数。对于没有设置的参数，默认情况下与NetcaLogSetConfigParam说明一致。
 *	参数：
 *		filepath：输入参数，日志参数配置文件路径，UTF-8格式。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogReadConfigFile(const char* filepath);

/*
 *	NetcaLogClose
 *		关闭Log文件。调用该接口后，如果再写入日志文件，则以默认参数的形式记录日志
 *	参数：
 *
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogClose(void);

/*
 *	NetcaLogLogger
 *		写入指定等级的日志信息。如果日志信息写入到文件中，则可以使用事务可以对日志信息进行缓冲。
 *	参数：
 *		level：输入参数，写入的日志信息的等级
 *		msg：输入参数，日志信息，UTF-8编码
 *		…：0个或者多个输入参数，参数规则与sprintf一致。字符串UTF-8编码
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogLogger(int level, const char* msg, ...);

/*
 *	NetcaLogBinLogger
 *		写入指定等级的二进制数据的日志信息。如果日志信息写入到文件中，则可以使用事务可以对日志信息进行缓冲。
 *	参数：
 *		level：输入参数，写入的日志信息的等级。
 *		msg：输入参数，日志信息。二进制数据
 *		length：输入参数，msg的长度
 *		type：输入参数，表示使用Base64编码或者十六进制编码。
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogBinLogger(int level, const unsigned char* msg, int length, int type);

/*
 *	NetcaLogBeginTransaction
 *		开始日志事务，即日志信息会被缓冲起来。事务对于写入日志文件的模式有效，对于打印在控制台的方式无效。
 *	参数：
 *		
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogBeginTransaction(void);

/*
 *	NetcaCommitTransaction
 *		提交事务，即把缓冲的日志信息全部打印出来。
 *	参数：
 *		
 *	返回值：
 *		成功NETCA_PKI_SUCCESS，失败返回其它值
 *
 */
int NETCADLLAPI NetcaLogCommitTransaction(void);

/*
 *	NetcaGetLogLevel
 *		获取当前写到文件或者控制台的日志等级。
 *	参数：
 *		
 *	返回值：
 *		成功日志等级，失败返回-1
 *
 */
int NETCADLLAPI NetcaLogGetLogLevel(void);

/*
 *	NetcaLogLevelEnabled
 *		判断某一等级日志是否能够写下
 *	参数：
 *		level：输入参数，需要判断的等级。
 *	返回值：
 *		能写下返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaLogLevelEnabled(int level);

#ifdef __cplusplus
	}	
#endif
#endif
