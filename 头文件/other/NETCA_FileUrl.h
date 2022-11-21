#ifndef NETCA_FILEURL_INCLUDE_H
#define NETCA_FILEURL_INCLUDE_H

#include "NETCA_UString.h"
#include "NETCA_Uri.h"

#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_FileURL_st;
typedef struct NETCA_FileURL_st* NETCA_FileURL;


/*
 *		netca_fileurl_new
 *			创建一个FileURL句柄
 *		参数：
 *			filename：输入参数，文件名
 *		返回值：
 *			成功返回有效的FileURL句柄，失败返回NULL
 */
NETCA_FileURL NETCAAPI netca_fileurl_new(NETCA_UString filename);

/*
 *		netca_fileurl_free
 *			释放FileURL句柄
 *		参数：
 *			url：FileURL句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_fileurl_free(NETCA_FileURL url);


/*
 *		netca_fileurl_newfromurl
 *			创建一个FileURL句柄
 *		参数：
 *			url：URL
 *		返回值：
 *			成功返回有效的FileURL句柄，失败返回NULL
 */
NETCA_FileURL NETCAAPI netca_fileurl_newfromurl(NETCA_URI url);

/*
 *		netca_fileurl_open
 *			打开文件
 *		参数：
 *			url：FileURL句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_fileurl_open(NETCA_FileURL url);


/*
 *		netca_fileurl_close
 *			关闭文件
 *		参数：
 *			url：FileURL句柄
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_fileurl_close(NETCA_FileURL url);


/*
 *		netca_fileurl_getlength
 *			获取文件长度
 *		参数：
 *			url：FileURL句柄
 *			length：输出参数，文件长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回NETCA_FAIL
 */
int NETCAAPI netca_fileurl_getlength(NETCA_FileURL url,integer64* length);

/*
 *		netca_fileurl_read
 *			读文件，可多次调用
 *		参数：
 *			url：FileURL句柄
 *			buf：输出参数，返回读到的数据
 *			buflen：输入参数，buf的长度
 *			readlen：输出参数，返回读到的数据长度。
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_fileurl_read(NETCA_FileURL url,unsigned char *buf,int buflen,int *readlen);



#ifdef __cplusplus
	}	
#endif

#endif

