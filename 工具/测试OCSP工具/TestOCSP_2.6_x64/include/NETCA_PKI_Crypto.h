#ifndef _NETCA_PKI_CRYPTO_INLCUDE_H_
#define _NETCA_PKI_CRYPTO_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif




/* 加密设备及基本加密运算函数 */

/*
 *	NetcaPKICryptoGetAllDevices 
 *		获取连接的设备
 *	参数：
 *		type：输入参数，设备库的类型，NETCA_PKI_DEVICE_TYPE_ANY表示要获取所有的设备
 *		flag：输入参数，设备的标志，NETCA_PKI_DEVICE_FLAG_SILENT置位表示设备操作不会出现任何UI接口。第1、2位的值（最末位从0算起）为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS表示把PIN码缓存在整个进程中，为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE表示只在设备句柄本身缓存PIN码。 为NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN表示从不Cache PIN码。缓存 PIN码只对USB KEY有效
 *	返回值：
 *		成功返回有效的设备集句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetAllDevices(int type,int flag);


/*
 *	NetcaPKICryptoGetAllDevicesEx 
 *		获取连接的设备
 *	参数：
 *		types：输入参数，设备库的类型数组，不能包含NETCA_PKI_DEVICE_TYPE_ANY
 *		count：输入参数，设备库的类型个数
 *		flag：输入参数，设备的标志，NETCA_PKI_DEVICE_FLAG_SILENT置位表示设备操作不会出现任何UI接口。第1、2位的值（最末位从0算起）为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS表示把PIN码缓存在整个进程中，为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE表示只在设备句柄本身缓存PIN码。 为NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN表示从不Cache PIN码。缓存 PIN码只对USB KEY有效
 *	返回值：
 *		成功返回有效的设备集句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetAllDevicesEx(const int *types,int count,int flag);

/*
 *	NetcaPKICryptoGetUSBDevices 
 *		获取连接的USB设备
 *	参数：
 *		vid：输入参数，VID
 *		pid：输入参数，PID
 *		flag：输入参数，设备的标志，NETCA_PKI_DEVICE_FLAG_SILENT置位表示设备操作不会出现任何UI接口。第1、2位的值（最末位从0算起）为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS表示把PIN码缓存在整个进程中，为NETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE表示只在设备句柄本身缓存PIN码。 为NETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN表示从不Cache PIN码。缓存 PIN码只对USB KEY有效
 *	返回值：
 *		成功返回有效的设备集句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetUSBDevices(int vid,int pid,int flag);

/*
 *	NetcaPKICryptoGetDeviceCount
 *		获取设备集中设备的个数
 *	参数：
 *		hDeviceSet：设备集句柄
 *	返回值：
 *		成功返回设备集中设备的个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDeviceCount(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	NetcaPKICryptoGetDevice
 *		获取设备集中的设备
 *	参数：
 *		hDeviceSet：设备集句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回设备集中第index个设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDevice(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet,int index);

/*
 *	NetcaPKICryptoFreeDevices
 *		释放设备集
 *	参数：
 *		hDeviceSet：设备集句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeDevices(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	NetcaPKICryptoFindDevice
 *		根据设备类型和序列号获取设备句柄
 *	参数：
 *		type：输入参数，设备类型
 *		sn：输入参数，设备序列号，ASCII编码
 *		flag：输入参数，标志，见NetcaPKICryptoGetAllDevices的说明
 *		phDevice：输出参数，成功返回当前连接的类型为type且序列号为sn的设备的设备句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoFindDevice(int type,const char *sn,int flag, NETCA_PKI_DEVICE_HANDLE *phDevice);

/*
 *	NetcaPKICryptoGetType
 *		获取设备的类型
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回设备的类型，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetType(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoGetSerialNumber
 *		获取设备的序列号。成功返回的序列号要使用NetcaPKICryptoFreeMemory来释放
 *	参数：
 *		hDevice：设备句柄
 *		sn：输出参数，返回设备序列号，ASCII编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGetSerialNumber(NETCA_PKI_DEVICE_HANDLE hDevice,char **sn);


/*
 *	NetcaPKICryptoGetLabel
 *		获取设备的卷标。成功返回的卷标要使用NetcaPKICryptoFreeMemory来释放
 *	参数：
 *		hDevice：设备句柄
 *		label：输出参数，返回设备的卷标，UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetLabel(NETCA_PKI_DEVICE_HANDLE hDevice,char **label);


/*
 *	NetcaPKICryptoGetClass
 *		获取设备的类别
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回设备的类别，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetClass(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoIsImportOnlyEncryptKeyPair
 *		判断设备的是否只支持导入加密的密钥对
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		支持返回1，不支持返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsImportOnlyEncryptKeyPair(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoIsSamePhysicalDevice
 *		判断是否同一物理设备
 *	参数：
 *		hDevice1：设备句柄1
 *	    hDevice2：设备句柄2
 *	返回值：
 *		是返回1，否返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsSamePhysicalDevice(NETCA_PKI_DEVICE_HANDLE hDevice1,NETCA_PKI_DEVICE_HANDLE hDevice2);


/*
 *	NetcaPKICryptoGetUsbInfo
 *		获取USB设备的VID和PID
 *	参数：
 *		hDevice：设备句柄
 *		vid：输出参数，返回的VID
 *		pid：输出参数，返回的PID
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetUsbInfo(NETCA_PKI_DEVICE_HANDLE hDevice,int *vid,int *pid);

/*
 *	NetcaPKICryptoGetUsbInfo
 *		根据USB设备的VID和PID，获取支持设备类型
 *	参数：
 *		vid：输入参数，返回的VID
 *		pid：输入参数，返回的PID
 *		types：输出参数，返回的设备类型数组
 *		count：输出参数，返回的设备类型个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetTypeFromUsbInfo(int vid,int pid,int **types,int *count);


/*
 *	NetcaPKICryptoGetAllTypes
 *		获取所有支持的设备类型
 *	参数：
 *		types：输出参数，返回的设备类型数组
 *		count：输出参数，返回的设备类型个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetAllTypes(int **types,int *count);


/*
 *	NetcaPKICryptoGetClassFromType
 *		根据设备类型获取设备的类别
 *	参数：
 *		type：输入参数，设备类型
 *	返回值：
 *		成功返回设备的类别，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetClassFromType(int type);

/*
 *	NetcaPKICryptoGetNameFromType
 *		根据设备类型获取设备的名称
 *	参数：
 *		type：输入参数，设备类型
 *	返回值：
 *		成功返回设备的名称(UTF-8编码)，失败返回NULL
 *
 */
char *NETCADLLAPI NetcaPKICryptoGetNameFromType(int type);


/*
 *	NetcaPKICryptoGetDisplayNameFromType
 *		根据设备类型获取设备的显示名称
 *	参数：
 *		type：输入参数，设备类型
 *	返回值：
 *		成功返回设备的显示名称(UTF-8编码)，失败返回NULL
 *
 */
char *NETCADLLAPI NetcaPKICryptoGetDisplayNameFromType(int type);

/*
 *	NetcaPKICryptoIsMultiDevice
 *		判断是否映射为多个设备的类型，且密钥对标签在序列号中包含
 *	参数：
 *		type：输入参数，设备类型
 *	返回值：
 *		如果是映射为多个设备的类型返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsMultiDeviceType(int type);


/*
 *	NetcaPKICryptoIsServerType
 *		判断是否可以用作服务器
 *	参数：
 *		type：输入参数，设备类型
 *	返回值：
 *		如果是可以用作服务器返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsServerType(int type);

/*
 *	NetcaPKICryptoGetUsbInfoFromType
 *		根据设备类型获取USB设备的VID和PID
 *	参数：
 *		type：设备类型
 *		vid：输出参数，返回的VID数组
 *		pid：输出参数，返回的PID数组
 *		count：输出参数，对应的数组元素个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetUsbInfoFromType(int type,int **vid,int **pid,int *count);

/*
 *	NetcaPKICryptoDeviceMustLogin
 *		判断加密设备是否必须验证用户密码才能使用
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		如果是必须成功验证用户密码才能使用返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoDeviceMustLogin(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoVerifyPwd
 *		验证设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码
 *		pwd：输入参数，密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyPwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *pwd,int *pretrynum);


/*
 *	NetcaPKICryptoChangePwd
 *		修改设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码
 *		oldpwd：输入参数，旧的密码，ASCII编码
 *		newpwd：输入参数，新的密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoChangePwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type, const char *oldpwd,const char *newpwd,int *pretrynum);


/*
 *	NetcaPKICryptoUnlockPwd
 *		解锁设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，当前版本只能是NETCA_PKI_USER_PWD表示用户密码
 *		sopwd：输入参数，管理员的密码，ASCII编码
 *		newpwd：输入参数，新的用户密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoUnlockPwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type, const char *sopwd,const char *newpwd,int *pretrynum);


/*
 *	NetcaPKICryptoGetPwdRetryNum
 *		获取设备的密码重试次数
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，当前版本只能是NETCA_PKI_USER_PWD表示用户密码
 *		pretrynum：输出参数，成功返回密码还可以重试的次数。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持返回NETCA_PKI_UNSUPPORTED
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPwdRetryNum(NETCA_PKI_DEVICE_HANDLE hDevice,int type, int *pretrynum);


/*
 *	NetcaPKICryptoSetCachePwdSecond
 *		设置缓存用户密码的时间，以秒为单位
 *	参数：
 *		hDevice：设备句柄,NULL为全局设置
 *		second：输入参数，缓存的秒数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetCachePwdSecond(NETCA_PKI_DEVICE_HANDLE hDevice,int second);

/*
 *	NetcaPKICryptoClearPwdCache
 *		清除用户密码缓存
 *	参数：
 *		hDevice：设备句柄,NULL为全局设置
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoClearPwdCache(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoDupDevice
 *		复制设备句柄
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回复制后设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoDupDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoFreeDevice
 *		释放设备句柄
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeDevice(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoLockDevice
 *		对设备加锁
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoLockDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoUnlockDevice
 *		对设备解锁
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoUnlockDevice(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoGetPseudoDevice
 *		返回一个伪设备句柄，这个句柄只有软件实现的加解密功能，而没有其他相关的设备功能。事实上，它根本不代表任何实质的设备。
 *	参数：
 *		无
 *	返回值：
 *		成功返回一个伪设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetPseudoDevice(void);
/*
 *	NetcaPKICryptoClearPseudoDevice
 *		清除伪设备里的私钥信息
 *	参数：
 *		hDevice：伪设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoClearPseudoDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoCreateData
 *		在设备中创建一项持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		mode：输入参数，持久数据的权限
 *		length：输入参数，持久数据的最大长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果持久数据已经存在，返回NETCA_PKI_EXISIT，如果没权限创建持久数据，返回NETCA_PKI_ ACCESSDENIED。如果不支持指定标识的持久数据，返回NETCA_PKI_UNSUPPORTED
 *
 */
int NETCADLLAPI NetcaPKICryptoCreateData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, const char *mode,int length);

/*
 *	NetcaPKICryptoGetDataLength
 *		获取持久数据的长度
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		plen：输出参数，返回持久数据的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ACCESSDENIED。
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDataLength(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, int* plen);


/*
 *	NetcaPKICryptoReadData
 *		读持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		data：输出参数，返回读到的数据，可以为NULL
 *		datalen：输入参数，data的长度
 *		pretdatalen：输出参数，返回读到的持久数据的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ACCESSDENIED。
 *
 */
int NETCADLLAPI NetcaPKICryptoReadData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	NetcaPKICryptoReadDataEx
 *		读持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		offset：输入参数,持久数据的位移
 *		data：输出参数，返回读到的数据，可以为NULL
 *		datalen：输入参数，data的长度
 *		pretdatalen：输出参数，返回读到的持久数据的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ACCESSDENIED。
 *
 */
int NETCADLLAPI NetcaPKICryptoReadDataEx(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId,int offset,unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	NetcaPKICryptoWriteData
 *		写持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		data：输入参数，要写入的数据
 *		datalen：输入参数，data的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ACCESSDENIED。
 *
 */
int NETCADLLAPI NetcaPKICryptoWriteData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoWriteDataEx
 *		写持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		offset：输入参数，持久数据的位移
 *		data：输入参数，要写入的数据
 *		datalen：输入参数，data的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ACCESSDENIED。
 *
 */
int NETCADLLAPI NetcaPKICryptoWriteDataEx(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, int offset,const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoDeleteData
 *		删除持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限删除持久数据，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoDeleteData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId);

/*
 *	NetcaPKICryptoGetKeypairCount
 *		获取设备中密钥对数量
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回设备中密钥对数量，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairCount(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoGetKeypair
 *		获取设备中的密钥对
 *	参数：
 *		hDevice：设备句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回设备中第index个密钥对，失败返回NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICryptoGetKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int index);

/*
 *	NetcaPKICryptoInstallCertificate
 *		安装证书
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，加密过的加密密钥对的类型
 *		encKeypair:输入参数，加密过的加密密钥对的编码值
 *		encKeypairLen:输入参数，加密过的加密密钥对的编长度
 *		encCert:加密证书
 *		signCert：签名证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoInstallCertificate(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const unsigned char *encKeypair,int encKeypairLen,NETCA_PKI_CERTIFICATE_HANDLE encCert,NETCA_PKI_CERTIFICATE_HANDLE signCert);


/*
 *	NetcaPKICryptoDupKeypair
 *		复制密钥对句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回复制后的密钥对，失败返回NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICryptoDupKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoFindKeypair
 *		根据密钥对的类型和标签，获取设备中的密钥对
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回设备中指定的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoFindKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);


/*
 *	NetcaPKICryptoFindKeypairEx
 *		根据密钥对的类型和标签，获取设备中的密钥对
 *	参数：
 *		deviceType：输入参数，设备类型
 *		sn：输入参数，设备的序列号
 *		flag:输入参数，设备的标志
 *		pwd：输入参数，设备的密码
 *		keypairType：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回设备中指定的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoFindKeypairEx(int deviceType,const char *sn,int flag,const char *pwd,int keypairType,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);


/*
 *	NetcaPKICryptoFreeKeypair
 *		释放密钥对句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
/*
 *	NetcaPKIGetKeypairMSProvInfo
 *		获取密钥对对应的CSP信息
 *	参数：
 *		hKeypair：密钥对句柄
 *		pinfo：输出参数，CSP信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIGetKeypairMSProvInfo(NETCA_PKI_KEYPAIR_HANDLE hKeypair, PCRYPT_KEY_PROV_INFO pinfo);
#endif

/*
 *	NetcaPKICryptoGetKeypairLabel
 *		获取密钥对的标签。成功获取的标签要使用NetcaPKICryptoFreeMemory来释放
 *	参数：
 *		hKeypair：密钥对句柄
 *		label：输出参数，返回的密钥对的标签，UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairLabel(NETCA_PKI_KEYPAIR_HANDLE hKeypair,char **label);



/*
 *	NetcaPKICryptoGetKeypairType
 *		获取密钥对的类型
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的类型，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairType(NETCA_PKI_KEYPAIR_HANDLE hKeypair);



/*
 *	NetcaPKICryptoGetKeypairAlgorithm
 *		获取密钥对的算法
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairAlgorithm(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGetKeypairBits
 *		获取密钥对的长度，以位为单位
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的位数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairBits(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetKeypairECCCurve
 *		获取密钥对的椭圆曲线号
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的椭圆曲线号，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairECCCurve(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoIsTemporaryKeypair
 *		判断密钥对是否临时密钥对
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		如果是，返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsTemporaryKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGenerateKeypair
 *		产生密钥对
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，密钥对的算法
 *		keybits：输入参数，密钥对的长度
 *		param：输入参数，产生密钥对需要的参数，对于RSA算法，可以为NULL。
 *		type：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回产生的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的算法返回NETCA_PKI_UNSUPPORTED，如果没权限产生密钥对，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keybits,const void *param,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);

/*
 *	NetcaPKICryptoImportKeypair
 *		导入密钥对到设备中去
 *	参数：
 *		hDevice：设备句柄
 *		keyblob：输入参数，密钥对的编码
 *	 	keybloblen：输入参数，密钥对的编码的长度
 *	 	type：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回产生的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持返回NETCA_PKI_UNSUPPORTED，如果没权限导入密钥对，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoImportKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);

/*
 *	NetcaPKICryptoExportKeypair
 *		导出密钥对
 *	参数：
 *		hKeypair：密钥对句柄
 *		keyblob：输出参数，返回密钥对的编码
 *		pretkeybloblen：输出参数，返回密钥对的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL。
 */
int NETCADLLAPI NetcaPKICryptoExportKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair,unsigned char **keyblob, int* pretkeybloblen);

/*
 *	NetcaPKICryptoDeleteKeypair 
 *		在设备中删除密钥对及其相关的证书
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值，如果没权限删除密钥对，返回NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoDeleteKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetDeviceHandleFromKeypair 
 *		获取密钥对相关的设备句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回设备句柄，失败返回NULL
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetPublicKeyFromKeypair
 *		获取密钥对的公钥句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的公钥句柄，失败返回NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICryptoGetPublicKeyFromKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoExportPublicKey
 *		导出公钥
 *	参数：
 *		hPublicKey：公钥句柄
 *		keyblob：输出参数，返回公钥的编码
 *		pretkeybloblen：输出参数，返回导出公钥的长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的公钥返回NETCA_PKI_ UNSUPPORTED。
 *
 */
int NETCADLLAPI NetcaPKICryptoExportPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,unsigned char **keyblob, int* pretkeybloblen);

/*
 *	NetcaPKICryptoGetSubjectPublicKeyInfoEncode
 *		获取公钥的SubjectPublicKeyInfo的DER编码
 *	参数：
 *		hPublicKey：公钥句柄
 *		encode：输出参数，返回SubjectPublicKeyInfo的编码
 *		pencodeLen：输出参数，返回SubjectPublicKeyInfo的长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 *
 */
int NETCADLLAPI NetcaPKICryptoGetSubjectPublicKeyInfoEncode(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,unsigned char **encode, int* pencodeLen);

/*
 *	NetcaPKICryptoImportPublicKeyFromSubjectPublicKeyInfo
 *		根据SubjectPublicKeyInfo的DER编码导入公钥
 *	参数：
 *		hDevice：设备句柄
 *		encode：输入参数，SubjectPublicKeyInfo的编码
 *		encodeLen：输入参数，SubjectPublicKeyInfo的长度。
 *		phPublicKey：输出参数，返回的公钥句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 *
 */
int NETCADLLAPI NetcaPKICryptoImportPublicKeyFromSubjectPublicKeyInfo(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *encode, int encodeLen,NETCA_PKI_PUBLICKEY_HANDLE *phPublicKey);


/*
 *	NetcaPKICryptoImportPublicKey
 *		导入临时的公钥
 *	参数：
 *		hDevice：设备句柄
 *		keyblob：输入参数，公钥的编码
 *		keybloblen：输入参数，公钥的编码的长度。
 *		phPublicKey：输出参数，成功返回临时的公钥句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的公钥返回NETCA_PKI_ UNSUPPORTED。
 *
 */
int NETCADLLAPI NetcaPKICryptoImportPublicKey(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen, NETCA_PKI_PUBLICKEY_HANDLE *phPublicKey);


/*
 *	NetcaPKICryptoGetPublicKeyBits
 *		获取公钥的长度，以位为单位
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回公钥的位数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyBits(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoGetPublicKeyECCCurve
 *		获取公钥的椭圆曲线号
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回公钥的椭圆曲线号，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyECCCurve(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	NetcaPKICryptoGetPublicKeyAlgorithm
 *		获取公钥的算法
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回公钥的算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyAlgorithm(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	NetcaPKICryptoDupPublicKey
 *		复制公钥句柄
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回复制后公钥句柄，失败返回NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICryptoDupPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoFreePublicKey
 *		释放公钥句柄
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoFreePublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoPublicKeyEqual
 *		比较两个公钥句柄
 *	参数：
 *		hPublicKey1：要比较的公钥句柄1
 *		hPublicKey2：要比较的公钥句柄2
 *	返回值：
 *		包含的公钥相同返回1，不同返回0
 *
 */
int NETCADLLAPI NetcaPKICryptoPublicKeyEqual(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey1,NETCA_PKI_PUBLICKEY_HANDLE hPublicKey2);


/*
 *	NetcaPKICryptoGetCertificateCount
 *		获取密钥对相关的证书个数
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对相关的证书个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCertificateCount(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGetCertificate
 *		获取密钥对相关的第index个证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		index：输入参数，索引号，从0算起
 *		pcert：输出参数，返回第index个证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int index, NETCA_PKI_CERTIFICATE_HANDLE *pcert);

/*
 *	NetcaPKICryptoDeleteCertificate
 *		删除密钥对相关的第index个证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限删除证书，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoDeleteCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int index);



/*
 *	NetcaPKICryptoUpdateCertificate
 *		把证书写入设备并和密钥对相关联，这个函数会删掉以前和密钥对关联的证书。
 *	参数：
 *		hKeypair：密钥对句柄
 *		cert：证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限写证书，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoUpdateCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoAddCertificate
 *		把证书写入设备并和密钥对相关联，这个函数会保留以前和密钥对关联的证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		cert：证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限写证书，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoAddCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoIsSupportedAlgorithm
 *		询问设备是否支持某个算法。
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，算法
 *		keyBits：输入参数，密钥长度，以位为单位
 *		usage：输入参数，算法的用途，比如加密解密之类
 *		param：输入参数，算法相关的参数
 *		
 *	返回值：
 *		如果支持返回1，不支持返回0。
 */
int NETCADLLAPI NetcaPKICryptoIsSupportedAlgorithm(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keyBits,int usage,const void *param);

/*
 *	NetcaPKICryptoGenerateRandom
 *		获取随机数
 *	参数：
 *		hDevice：设备句柄，可以为NULL
 *		len：输入参数，随机数长度
 *		rand：输出参数，返回的随机数长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateRandom(NETCA_PKI_DEVICE_HANDLE hDevice,int len,unsigned char *rand);

/*
 *	NetcaPKICryptoAddRandomSeed
 *		添加随机数发生器的种子
 *	参数：
 *		seed：输入参数，种子
 *		seedLen：输入参数，种子长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoAddRandomSeed(const unsigned char *seed,int seedLen);

/*
 *	NetcaPKICryptoGenerateKey
 *		产生对称密钥
 *	参数：
 *		hDevice：设备句柄
 *		algo：对称加密算法
 *		keyLen：输入参数，密钥长度，以字节为单位
 *		key：输出参数，返回的对称密钥
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateKey(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keyLen,unsigned char *key);



/*
 *	NetcaPKICryptoNewHash
 *		创建Hash句柄。如果设备句柄没有实现该Hash算法，而且该Hash算法是软件可以实现的，则使用软件实现。
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，Hash算法
 *	返回值：
 *		成功返回Hash句柄，失败返回NULL
 *
 */
NETCA_PKI_HASH_HANDLE NETCADLLAPI NetcaPKICryptoNewHash(NETCA_PKI_DEVICE_HANDLE hDevice,int algo);

/*
 *	NetcaPKICryptoGetHashHandle
 *		根据配置的信息，获取Hash句柄。
 *	参数：
 *		algo：输入参数，Hash算法
 *	返回值：
 *		成功返回Hash句柄，失败返回NULL
 *
 */
NETCA_PKI_HASH_HANDLE NETCADLLAPI NetcaPKICryptoGetHashHandle(int algo);

/*
 *	NetcaPKICryptoGetHashLength
 *		获取Hash值的长度
 *	参数：
 *		hHash：Hash句柄
 *	返回值：
 *		成功返回Hash值的长度，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHashLength(NETCA_PKI_HASH_HANDLE hHash);


/*
 *	NetcaPKICryptoGetHashAlgorithm
 *		获取Hash算法
 *	参数：
 *		hHash：Hash句柄
 *	返回值：
 *		成功返回Hash算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHashAlgorithm(NETCA_PKI_HASH_HANDLE hHash);

/*
 *	NetcaPKICryptoGetDeviceHandleFromHash
 *		获取Hash句柄对应的设备句柄
 *	参数：
 *		hHash：Hash句柄
 *	返回值：
 *		成功返回设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromHash(NETCA_PKI_HASH_HANDLE hHash);


/*
 *	NetcaPKICryptoHashUpdate
 *		进行Hash运算
 *	参数：
 *		hHash：Hash句柄
 *		data：输入参数，数据
 *		datalen：输入参数，data的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoHashUpdate(NETCA_PKI_HASH_HANDLE hHash,const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoHashFinal
 *		结束Hash运算，获取Hash值。
 *	参数：
 *		hHash：Hash句柄
 *		hashvalue：输出参数，返回的Hash值
 *		prethashvaluelen：输出参数，返回Hash值的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoHashFinal(NETCA_PKI_HASH_HANDLE hHash,unsigned char **hashvalue, int *prethashvaluelen);


/*
 *	NetcaPKICryptoHashFinal
 *		释放Hash句柄。
 *	参数：
 *		hHash：Hash句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeHash(NETCA_PKI_HASH_HANDLE hHash);

/*
 *	NetcaPKICryptoDuplicateHash
 *		复制Hash句柄。
 *	参数：
 *		hHash：要复制的Hash句柄
 *		phNewHash：输出函数，返回复制得到的Hash句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 */
int NETCADLLAPI NetcaPKICryptoDuplicateHash(NETCA_PKI_HASH_HANDLE hHash,NETCA_PKI_HASH_HANDLE *phNewHash);

/*
 *	NetcaPKICryptoNewMac
 *		创建MAC句柄。如果设备没有实现某种可以用软件实现的算法，则使用软件实现
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，Mac算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，Mac算法的参数，对应HMAC来说，为NULL
 *	返回值：
 *		成功返回MAC句柄，失败返回NULL
 *
 */
NETCA_PKI_MAC_HANDLE NETCADLLAPI NetcaPKICryptoNewMac(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	NetcaPKICryptoGetMacHandle
 *		根据配置的信息，获取Mac句柄。
 *	参数：
 *		algo：输入参数，Mac算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，Mac算法的参数，对应HMAC来说，为NULL
 *	返回值：
 *		成功返回MAC句柄，失败返回NULL
 *
 */
NETCA_PKI_MAC_HANDLE NETCADLLAPI NetcaPKICryptoGetMacHandle(int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	NetcaPKICryptoGetMacLength
 *		获取Mac的长度。
 *	参数：
 *		hMac：Mac句柄
 *	返回值：
 *		成功返回Mac的长度，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetMacLength(NETCA_PKI_MAC_HANDLE hMac);


/*
 *	NetcaPKICryptoGetMacAlgorithm
 *		获取Mac算法。
 *	参数：
 *		hMac：Mac句柄
 *	返回值：
 *		成功返回Mac算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetMacAlgorithm(NETCA_PKI_MAC_HANDLE hMac);

/*
 *	NetcaPKICryptoGetDeviceHandleFromMac
 *		获取Mac句柄对应的设备句柄
 *	参数：
 *		hMac：Mac句柄
 *	返回值：
 *		成功返回设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromMac(NETCA_PKI_MAC_HANDLE hMac);

/*
 *	NetcaPKICryptoMacUpdate
 *		Mac数据，这个函数可以多次调用。
 *	参数：
 *		hMac：Mac句柄
 *		data：输入参数，要进行Mac运算的数据
 *		datalen：输入参数，data的字节数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoMacUpdate(NETCA_PKI_MAC_HANDLE hMac,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoMacFinal
 *		结束Mac运算，获取Mac值。
 *	参数：
 *		hMac：Mac句柄
 *		macvalue：输出参数，返回的Mac值
 *		retmacvaluelen：输出参数，返回MAC的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoMacFinal(NETCA_PKI_MAC_HANDLE hMac,unsigned char **macvalue,int  *pretmacvaluelen);

/*
 *	NetcaPKICryptoFreeMac
 *		释放Mac句柄。
 *	参数：
 *		hMac：Mac句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeMac(NETCA_PKI_MAC_HANDLE hMac);


/*
 *	NetcaPKICryptoNewCipher
 *		创建加解密句柄。对于序列密码来说，param为NULL。对于ECB模式的RC2算法来说，param为int *，表示有效密钥位数。其他分组密码的ECB模式，param为NULL。对于ECB模式的RC2算法来说，param为struct NETCA_PKI_RC2CBCParam_st*，其他的为unsigned char *，表示IV，IV的长度是分组长度。
 *	参数：
 *		hDevice：设备句柄
 *		enc：输入参数，1表加密，0表示解密
 *		algo：输入参数，加密算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，加解密的参数
 *	返回值：
 *		成功返回创建加解密句柄，失败返回NULL
 *
 */
NETCA_PKI_CIPHER_HANDLE NETCADLLAPI NetcaPKICryptoNewCipher(NETCA_PKI_DEVICE_HANDLE hDevice,int enc,int algo,const unsigned char *key,int keylen,const void *param);


/*
 *	DeviceNewCipher
 *		解密对称密钥创建加解密句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *		pubkeyencalgo：输入参数，公钥加密算法
 *		pubkeyencparam：输入参数，公钥加密参数
 *		enckey:输入参数，公钥加密的对称密钥
 *		enckeylen：输入参数，公钥加密的对称密钥的长度
 *		enc：输入参数，1表加密，0表示解密
 *		algo：输入参数，对称加密算法
 *		param：输入参数，对称加解密的参数
 *		phCipher:输出参数，成功返回创建的加解密句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限解密，返回NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoImportKeyAndNewCipher(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int pubkeyencalgo,const void *pubkeyencparam,const unsigned char *enckey,int enckeylen,int enc,int algo,const void *param,NETCA_PKI_CIPHER_HANDLE *phCipher);

/*
 *	NetcaPKICryptoGetCipherHandle
 *		根据配置的信息，获取加解密句柄。
 *	参数：
 *		enc：输入参数，1表加密，0表示解密
 *		algo：输入参数，加密算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，加解密的参数
 *	返回值：
 *		成功返回创建加解密句柄，失败返回NULL
 *
 */
NETCA_PKI_CIPHER_HANDLE NETCADLLAPI NetcaPKICryptoGetCipherHandle(int enc,int algo,const unsigned char *key,int keylen,const void *param);


/*
 *	NetcaPKICryptoGetCipherAlgorithm
 *		获取加密算法
 *	参数：
 *		hCipher：加解密句柄
 *	返回值：
 *		成功返回加密算法，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCipherAlgorithm(NETCA_PKI_CIPHER_HANDLE hCipher);

/*
 *	NetcaPKICryptoGetDeviceHandleFromCipher
 *		获取加解密句柄对应的设备句柄
 *	参数：
 *		hCipher：加解密句柄
 *	返回值：
 *		成功返回设备句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromCipher(NETCA_PKI_CIPHER_HANDLE hCipher);

/*
 *	NetcaPKICryptoCipherUpdate
 *		加解密数据，这个函数可以多次调用。
 *	参数：
 *		hCipher：加解密句柄
 *		in：输入参数，输入数据
 *		inlen：输入参数，in的字节数
 *		out：输出参数，返回的数据
 *		pretoutlen：输出参数，返回输出长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherUpdate(NETCA_PKI_CIPHER_HANDLE hCipher,const unsigned char *in,int inlen,unsigned char **out,int *pretoutlen);


/*
 *	NetcaPKICryptoCipherFinal
 *		结束加解密。
 *	参数：
 *		hCipher：加解密句柄
 *		remdata：输出参数，返回的数据
 *		pretremdatalen：输出参数，返回输出长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherFinal(NETCA_PKI_CIPHER_HANDLE hCipher,unsigned char **remdata,int *pretremdatalen);

/*
 *	NetcaPKICryptoFreeCipher
 *		释放加解密句柄。
 *	参数：
 *		hCipher：加解密句柄
 *		
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeCipher(NETCA_PKI_CIPHER_HANDLE hCipher);


/*
 *	NetcaPKICryptoCipherSetPadding
 *		设置分组加密的填充模式。
 *	参数：
 *		hCipher：加解密句柄
 *		padding：输入参数，填充模式
 *		
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherSetPadding(NETCA_PKI_CIPHER_HANDLE hCipher,int padding);

/*
 *	NetcaPKICryptoNewSign
 *		创建签名句柄。
 *	参数：
 *		hKeypair：密钥对句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，签名参数
 *	返回值：
 *		成功返回签名句柄，失败返回NULL
 *
 */
NETCA_PKI_SIGN_HANDLE NETCADLLAPI NetcaPKICryptoNewSign(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param);


/*
 *	NetcaPKICryptoSignUpdate
 *		进行签名运算的所需的Hash运算，这个函数可以调用多次
 *	参数：
 *		hSign：签名句柄
 *		data：输入参数，数据
 *		datalen：输入参数，数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignUpdate(NETCA_PKI_SIGN_HANDLE hSign,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoSignFinal
 *		调用私钥进行最后的签名
 *	参数：
 *		hSign：签名句柄
 *		sign：输出参数，返回的签名值
 *		psignlen：输出参数，返回sign的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignFinal(NETCA_PKI_SIGN_HANDLE hSign,unsigned char **sign,int *psignlen);


/*
 *	NetcaPKICryptoFreeSign
 *		释放签名句柄。
 *	参数：
 *		hSign：签名句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeSign(NETCA_PKI_SIGN_HANDLE hSign);



/*
 *	NetcaPKICryptoSignHash
 *		签名，输入是Hash值
 *	参数：
 *		hKeypair：密钥对句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，参数
 *		hash：输入参数，Hash值
 *		hashlen：Hash值的长度
 *		sign：输出参数，返回的签名值
 *		psignlen：输出参数，返回sign的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignHash(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *hash,int hashlen,unsigned char **sign,int *psignlen);


/*
 *	NetcaPKICryptoNewVerify
 *		创建签名验证句柄
 *	参数：
 *		hPublicKey：公钥句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，参数
 *	返回值：
 *		成功返回签名验证句柄，失败返回NULL
 *
 */
NETCA_PKI_DEVICE_VERIFY_HANDLE NETCADLLAPI NetcaPKICryptoNewVerify(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param);



/*
 *	NetcaPKICryptoVerifyUpdate
 *		进行签名验证需要的Hash运算，这个函数可以调用多次
 *	参数：
 *		hVerify：签名验证句柄
 *		data：输入参数，数据
 *		datalen：输入参数，数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyUpdate(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoVerifyFinal
 *		进行签名验证
 *	参数：
 *		hVerify：签名验证句柄
 *		sign：输入参数，签名值
 *		signlen：输入参数，签名长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyFinal(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify,const unsigned char *sign,int signlen);


/*
 *	NetcaPKICryptoFreeVerify
 *		释放签名验证句柄
 *	参数：
 *		hVerify：签名验证句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeVerify(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify);

/*
 *	NetcaPKICryptoVerifyHash
 *		验证签名，输入是Hash值
 *	参数：
 *		hPublicKey：公钥句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，参数
 *		hash：输入参数，Hash值
 *		hashlen：Hash值的长度
 *		sign：输入参数，签名值
 *		signlen：输入参数，签名长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyHash(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *hash,int hashlen,const unsigned char *sign,int signlen);


/*
 *	NetcaPKICryptoPublicKeyEncrypt
 *		公钥加密
 *	参数：
 *		hPublicKey：公钥句柄
 *		algo：输入参数，公钥加密算法
 *		param：输入参数，参数
 *		clear：输入参数，明文
 *		clearlen：输入参数，明文长度
 *		cipher：输出参数，返回的密文
 *		pcipherlen：输出参数，返回密文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoPublicKeyEncrypt(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *clear,int clearlen,unsigned char **cipher,int *pcipherlen);

/*
 *	NetcaPKICryptoPrivateKeyDecrypt
 *		私钥解密
 *	参数：
 *		hKeypair：密钥对句柄
 *		algo：输入参数，公钥加密算法
 *		param：输入参数，参数
 *		cipher：输入参数，密文
 *		cipherlen：输入参数，密文长度
 *		clear：输出参数，返回的明文
 *		pclearlen：输出参数，返回明文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoPrivateKeyDecrypt(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *cipher,int cipherlen,unsigned char **clear,int *pclearlen);


/*
 *	NetcaPKICryptoKeyAgreement
 *		密钥协商
 *	参数：
 *		hKeypair：自己的密钥对句柄
 *		hRespPublicKey：对方公钥导入的句柄
 *		hTempKeypair：自己的临时密钥对句柄
 *		hTempRespPublicKey：对方的临时公钥导入的句柄
 *		algo：输入参数，密钥协商算法
 *		param：输入输出参数，密钥协商参数
 *		keylen：输入参数，密钥协商得到的共享信息长度，以字节为单位
 *		key：输出参数，密钥协商得到的共享信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果不支持返回NETCA_PKI_UNSUPPORTED。如果没有权限使用私钥，返回NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoKeyAgreement(NETCA_PKI_KEYPAIR_HANDLE hKeypair,NETCA_PKI_PUBLICKEY_HANDLE hRespPublicKey,NETCA_PKI_KEYPAIR_HANDLE hTempKeypair,NETCA_PKI_PUBLICKEY_HANDLE hTempRespPublicKey,int algo,void *param,int keylen,unsigned char *key);

#ifdef _WIN32

/*
 *	NetcaPKICryptoRegisterPullOutInfo
 *		注册设备插拔信息。
 *	参数：
 *		isPullOut：输入参数，1为拔出，0为插入
 *		type：输入参数，设备类型
 *		sn：输入参数，设备的序列号
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoRegisterPullOutInfo(int isPullOut,int type,const char *sn);


/*
 *	NetcaPKICryptoSetWindowHandle
 *		设置相关的窗口句柄，应该保证窗口句柄在设备句柄的生命周期结束前一直有效。
 *	参数：
 *		hDevice：设备句柄
 *		hwnd：窗口句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetWindowHandle(NETCA_PKI_DEVICE_HANDLE hDevice,HWND hwnd);

/*
 *	NetcaPKICryptoSetVerifyPwdCallback
 *		设置验证密码的回调函数。
 *	参数：
 *		hDevice：设备句柄，为NULL则表示回调函数是全局的，新产生的句柄都用新的回调函数
 *		func：验证密码的回调函数。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetVerifyPwdCallback(NETCA_PKI_DEVICE_HANDLE hDevice,NetcaPKIUIVerifyPassword_Ptr func);

#endif

/*
 *	NetcaPKICryptoSetLoginPromptMsg
 *		设置登录的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetLoginPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetGenKeyPairPromptMsg
 *		设置产生密钥对的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetGenKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetImportKeyPairPromptMsg
 *		设置导入密钥对的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetImportKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);


/*
 *	NetcaPKICryptoSetDeleteKeyPairPromptMsg
 *		设置删除密钥对的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeleteKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetWriteCertPromptMsg
 *		设置写入证书的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetWriteCertPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetDeleteCertPromptMsg
 *		设置删除证书的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeleteCertPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetSignPromptMsg
 *		设置签名的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetSignPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);


/*
 *	NetcaPKICryptoSetPrivKeyDecryptPromptMsg
 *		设置私钥解密的提示信息。
 *	参数：
 *		hDevice：设备句柄
 *		flag：输入参数，保留参数，当前只能取0
 *		msg：输入参数，提示信息。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetPrivKeyDecryptPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/* 杂类函数 */

/*
 *	NetcaPKICryptoAllocMemory
 *		分配内存，成功分配的内存只能由NetcaPKICryptoFreeMemory来释放
 *	参数：
 *		size：输入参数，要分配的内存的字节数
 *	返回值：
 *		成功返回分配的内存，失败返回NULL
 *
 */
void * NETCADLLAPI NetcaPKICryptoAllocMemory(long size);



/*
 *	NetcaPKICryptoFreeMemory
 *		释放内存
 *	参数：
 *		mem：内存
 *	返回值：
 *		无
 *
 */
void NETCADLLAPI NetcaPKICryptoFreeMemory(void *mem);



/*
 *	NetcaPKICryptoNewBase64
 *		创建Base64句柄
 *	参数：
 *		enc：输入参数，非0为Base64编码，0为Base64解码
 *		flag：输入参数，标志，如果NETCA_PKI_BASE64_NO_NL置位，则编码时不换行
 *	返回值：
 *		成功返回Base64句柄，失败返回NULL
 *
 */
NETCA_PKI_BASE64_HANDLE NETCADLLAPI NetcaPKICryptoNewBase64(int enc,int flag);


/*
 *	NetcaPKICryptoBase64Update
 *		进行Base64运算，这个函数可以运行多次
 *	参数：
 *		hBase64：Base64句柄
 *		in：输入参数，要处理的数据
 *		inlen：输入参数，in的长度
 *		out：输出参数，返回处理后的数据
 *		poutlen：输出参数，返回out的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoBase64Update(NETCA_PKI_BASE64_HANDLE hBase64,const unsigned char * in,int inlen,unsigned char **out,int *poutlen);


/*
 *	NetcaPKICryptoBase64Final
 *		结束Base64运算
 *	参数：
 *		hBase64：Base64句柄
 *		remdata：输出参数，返回最后处理后的数据
 *		premlen：输出参数，返回remdata的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoBase64Final(NETCA_PKI_BASE64_HANDLE hBase64,unsigned char **remdata,int *premlen);

/*
 *	NetcaPKICryptoFreeBase64
 *		释放Base64句柄
 *	参数：
 *		hBase64：Base64句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeBase64(NETCA_PKI_BASE64_HANDLE hBase64);

/*
 *	NetcaPKICryptoRSAPubKeyToDER
 *		把导出的RSA公钥格式转换为DER编码格式
 *	参数：
 *		in：输入参数，导出的RSA公钥格式数据
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的DER编码格式
 *		outLen：输出参数，DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPubKeyToDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoRSAPubKeyFromDER
 *		把DER编码格式的RSA公钥格式转换为导入的RSA公钥格式
 *	参数：
 *		in：输入参数，DER编码的RSA公钥格式数据
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的导入的RSA公钥格式
 *		outLen：输出参数，out的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPubKeyFromDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoRSAPrivKeyToDER
 *		把导出的RSA私钥格式转换为DER编码格式
 *	参数：
 *		in：输入参数，导出的RSA私钥格式数据
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的DER编码格式
 *		outLen：输出参数，DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPrivKeyToDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);


/*
 *	NetcaPKICryptoRSAPrivKeyFromDER
 *		把DER编码格式的RSA私钥格式转换为导入的RSA私钥格式
 *	参数：
 *		in：输入参数，DER编码的RSA私钥格式数据
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的导入的RSA私钥格式
 *		outLen：输出参数，out的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPrivKeyFromDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoSM2CipherToDER
 *		把SM2加密结果转换为DER编码格式（也就是SM2密码算法使用规范需要的格式）
 *	参数：
 *		curve：输入参数，椭圆曲线号，通常为SM2
 *		hashAlfo：输入参数，Hash算法，通常为SM3
 *		in：输入参数，SM2加密结果
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的DER编码格式
 *		outLen：输出参数，DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSM2CipherToDER(int curve,int hashAlgo,const unsigned char *in,int inLen,unsigned char **out,int *outLen);


/*
 *	NetcaPKICryptoSM2CipherFromDER
 *		把DER编码格式的SM2密文转换为解密需要的SM2密文
 *	参数：
 *		curve:输入参数，椭圆曲线号，通常为SM2
 *		in：输入参数，DER编码的SM2密文
 *		inLen：输入参数，in的长度
 *		out：输出参数，返回的解密需要的SM2密文
 *		outLen：输出参数，out的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoSM2CipherFromDER(int curve,const unsigned char *in,int inLen,unsigned char **out,int *outLen);



/*
 *	NetcaPKICryptoEncodeRSAPubKey
 *		RSA公钥格式编码
 *	参数：
 *		n：输入参数，RSA的模
 *		nLen：输入参数，n的长度
 *		e：输入参数，RSA的公钥指数
 *		eLen：输入参数，e的长度
 *		publicKey：输出参数，返回的导入的RSA公钥格式
 *		publicKeyLen：输出参数，publicKey的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeRSAPubKey(const unsigned char *n,int nLen,const unsigned char *e,int eLen,unsigned char **publicKey,int *publicKeyLen);

/*
 *	NetcaPKICryptoDecodeRSAPubKey
 *		RSA公钥格式解码
 *	参数：
 *		publicKey：输入参数，导入的RSA公钥格式
 *		publicKeyLen：输入参数，publicKey的长度
 *		n：输出参数，RSA的模
 *		nLen：输出参数，n的长度
 *		e：输出参数，RSA的公钥指数
 *		eLen：输出参数，e的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeRSAPubKey(const unsigned char *publicKey,int publicKeyLen,unsigned char **n,int *nLen,unsigned char **e,int *eLen);

/*
 *	NetcaPKICryptoEncodeECCPubKey
 *		ECC公钥格式编码
 *	参数：
 *		curve：输入参数，椭圆曲线号
 *		x：输入参数，x
 *		xLen：输入参数，x的长度
 *		y：输入参数，y
 *		yLen：输入参数，y的长度
 *		publicKey：输出参数，返回的导入的ECC公钥格式
 *		publicKeyLen：输出参数，publicKey的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCPubKey(int curve,const unsigned char *x,int xLen,const unsigned char *y,int yLen,unsigned char **publicKey,int *publicKeyLen);

/*
 *	NetcaPKICryptoDecodeECCPubKey
 *		ECC公钥格式解码
 *	参数：
 *		publicKey：输入参数，导入的ECC公钥格式
 *		publicKeyLen：输入参数，publicKey的长度
 *		curve：输出参数，椭圆曲线号
 *		x：输出参数，x
 *		xLen：输出参数，x的长度
 *		y：输出参数，y
 *		yLen：输出参数，y的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCPubKey(const unsigned char *publicKey,int publicKeyLen,int *curve,unsigned char **x,int *xLen,unsigned char **y,int *yLen);

/*
 *	NetcaPKICryptoEncodeECCSignature
 *		ECC签名格式编码
 *	参数：
 *		r：输入参数，r
 *		rLen：输入参数，r的长度
 *		s：输入参数，s
 *		sLen：输入参数，s的长度
 *		signature：输出参数，返回的ECC的签名格式
 *		signatureLen：输出参数，signature的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCSignature(const unsigned char *r,int rLen,const unsigned char *s,int sLen,unsigned char **signature,int *signatureLen);


/*
 *	NetcaPKICryptoDecodeECCSignature
 *		ECC签名格式解码
 *	参数：
 *		signature：输入参数，ECC的签名格式
 *		signatureLen：输入参数，signature的长度
 *		r：输出参数，r
 *		rLen：输出参数，r的长度
 *		s：输出参数，s
 *		sLen：输出参数，s的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCSignature(const unsigned char *signature,int signatureLen,unsigned char **r,int *rLen,unsigned char **s,int *sLen);

/*
 *	NetcaPKICryptoEncodeECCKeyPair
 *		ECC密钥对格式编码
 *	参数：
 *		curve：输入参数，椭圆曲线号
 *		x：输入参数，x
 *		xLen：输入参数，x的长度
 *		y：输入参数，y
 *		yLen：输入参数，y的长度
 *		d：输入参数，私钥d
 *		dLen：输入参数，d的长度
 *		keypair：输出参数，返回的导入的ECC密钥对格式
 *		keypairLen：输出参数，keypair的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCKeyPair(int curve,const unsigned char *x,int xLen,const unsigned char *y,int yLen,const unsigned char *d,int dLen,unsigned char **keypair,int *keypairLen);

/*
 *	NetcaPKICryptoDecodeECCKeyPair
 *		ECC密钥对格式解码
 *	参数：
 *		keypair：输入参数，导入的ECC密钥对格式
 *		keypairLen：输入参数，keypair的长度
 *		curve：输出参数，椭圆曲线号
 *		x：输出参数，x
 *		xLen：输出参数，x的长度
 *		y：输入参数，y
 *		yLen：输出参数，y的长度
 *		d：输出参数，私钥d
 *		dLen：输出参数，d的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCKeyPair(const unsigned char *keypair,int keypairLen,int *curve,unsigned char **x,int *xLen,unsigned char **y,int *yLen,unsigned char **d,int *dLen);

/*
 *	NetcaPKICryptoEncodeRSAKeyPair
 *		RSA密钥对格式编码
 *	参数：
 *		n：输入参数，RSA的模
 *		nLen：输入参数，n的长度
 *		e：输入参数，RSA的公钥指数
 *		eLen：输入参数，e的长度
 *		d：输入参数，RSA的私钥指数
 *		dLen：输入参数，d的长度
 *		p：输入参数，p
 *		pLen：输入参数，p的长度
 *		q：输入参数，q
 *		qLen：输入参数，q的长度
 *		dP：输入参数，dP
 *		dPLen：输入参数，dP的长度
 *		dQ：输入参数，dQ
 *		dQLen：输入参数，dQ的长度
 *		invQ：输入参数，invQ
 *		invQLen：输入参数，invQ的长度
 *		keypair：输出参数，返回的导入的RSA密钥对格式
 *		keypair：输出参数，keypair的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeRSAKeyPair(const unsigned char *n,int nLen,
											   const unsigned char *e,int eLen,
											   const unsigned char *d,int dLen,
											   const unsigned char *p,int pLen,
											   const unsigned char *q,int qLen,
											   const unsigned char *dP,int dPLen,
											   const unsigned char *dQ,int dQLen,
											   const unsigned char *invQ,int invQLen,
											   unsigned char **keypair,int *keypairLen);

/*
 *	NetcaPKICryptoDecodeRSAKeyPair
 *		RSA密钥对格式解码
 *	参数：
 *		keypair：输入参数，返回的导入的RSA密钥对格式
 *		keypair：输入参数，keypair的长度
 *		n：输出参数，RSA的模
 *		nLen：输出参数，n的长度
 *		e：输入参数，RSA的公钥指数
 *		eLen：输出参数，e的长度
 *		d：输出参数，RSA的私钥指数
 *		dLen：输出参数，d的长度
 *		p：输出参数，p
 *		pLen：输出参数，p的长度
 *		q：输出参数，q
 *		qLen：输出参数，q的长度
 *		dP：输出参数，dP
 *		dPLen：输出参数，dP的长度
 *		dQ：输出参数，dQ
 *		dQLen：输出参数，dQ的长度
 *		invQ：输出参数，invQ
 *		invQLen：输出参数，invQ的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeRSAKeyPair(const unsigned char *keypair,int keypairLen,
											   unsigned char **n,int *nLen,
											   unsigned char **e,int *eLen,
											   unsigned char **d,int *dLen,
											   unsigned char **p,int *pLen,
											   unsigned char **q,int *qLen,
											   unsigned char **dP,int *dPLen,
											   unsigned char **dQ,int *dQLen,
											   unsigned char **invQ,int *invQLen
											   );


/* 基本证书函数 */

/*
 *	NetcaPKICertNewCert
 *		创建证书句柄
 *	参数：
 *		data：输入参数，证书的编码
 *		len：输入参数，证书的编码的长度
 *	返回值：
 *		成功返回有效的证书句柄，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertNewCert(const unsigned char *data,int len);

/*
 *	NetcaPKICertFreeCert
 *		释放证书句柄
 *	参数：
 *		cert：证书句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertFreeCert(NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertDupCert
 *		复制证书句柄
 *	参数：
 *		cert：证书句柄
 *	返回值：
 *		成功返回复制后的证书句柄，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertDupCert(NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertGetCertEncode
 *		获取证书编码
 *	参数：
 *		cert：证书句柄
 *		flag：输入参数，证书编码类型
 *		buf：输出参数，返回的证书编码
 *		pbuflen：输出参数，返回的证书编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetCertEncode(NETCA_PKI_CERTIFICATE_HANDLE cert,int flag,unsigned char **buf,int *pbuflen);

/*
 *	NetcaPKICertEqual
 *		比较两个证书的编码
 *	参数：
 *		cert1：要比较的证书1
 *		cert2：要比较的证书2
 *	返回值：
 *		包含的证书编码相同返回1，不同返回0
 *
 */
int NETCADLLAPI NetcaPKICertEqual(NETCA_PKI_CERTIFICATE_HANDLE cert1,NETCA_PKI_CERTIFICATE_HANDLE cert2);

/*
 *	NetcaPKICertMatch
 *		判断证书是否匹配
 *	参数：
 *		cert：证书句柄，可以为NULL，为NULL则表示检测expr语法是否正确
 *		expr：输入参数，条件表达式，UTF-8编码
 *	返回值：
 *		如果匹配返回1，不匹配返回0，表达式错误返回-1,处理出错返回-2
 *
 */
int NETCADLLAPI NetcaPKICertMatch(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *expr);

/*
 *	NetcaPKISelectCert
 *		根据配置获取类型为type，符合expr条件的证书
 *	参数：
 *		type：输入参数，证书的类型
 *		expr：输入参数，条件表达式，UTF-8编码，可以为NULL或者空串，表示不验证条件
 *		pCert：输出参数，成功返回获取的证书句柄，如果没有有符合条件的证书返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKISelectCert(const char *type,const char *expr,NETCA_PKI_CERTIFICATE_HANDLE* pCert);

/*
 *	NetcaPKICertGetCertIntegerAttribute
 *		获取证书的整数类型的属性
 *	参数：
 *		cert：证书句柄
 *		attrId：输入参数，属性
 *		pvalue：输出参数，返回的属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetCertIntegerAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,long *pvalue);

/*
 *	NetcaPKICertGetCertStringAttribute
 *		获取证书的字符串类型的属性
 *	参数：
 *		cert：证书句柄
 *		attrId：输入参数，属性
 *		pvalue：输出参数，返回的属性值，UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetCertStringAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,char **pvalue);

/*
 *	NetcaPKICertGetCertHashAttribute
 *		获取证书的Hash值属性
 *	参数：
 *		cert：证书句柄
 *		attrId：输入参数，属性
 *		algo:输入参数，Hash算法
 *		pvalue：输出参数，返回的Hash值
 *		pvalueLen：输出参数，返回的Hash值长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetCertHashAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,int algo,unsigned char **pvalue,int *pvalueLen);


/*
 *	NetcaPKICertSetCertIntegerAttribute
 *		设置证书的整数类型的属性
 *	参数：
 *		cert：证书句柄
 *		attrId：输入参数，属性
 *		value：输入参数，属性值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetCertIntegerAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,long value);


/*
 *	NetcaPKICertSetCertStringAttribute
 *		设置证书的字符串类型的属性
 *	参数：
 *		cert：证书句柄
 *		attrId：输入参数，属性
 *		value：输入参数，属性值，UTF-8编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetCertStringAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,const char *value);

/*
 *	NetcaPKICertFindExtension
 *		获取证书的扩展
 *	参数：
 *		cert：证书句柄
 *		oid：输入参数，扩展的OID
 *		pcrical：输出参数，如果扩展是关键的返回1，否则返回0
 *		pvalue：输出参数，返回扩展的编码值
 *		pvaluelen：输出参数，返回扩展的编码值的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值，如果扩展不存在返回NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKICertFindExtension(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *oid,int *pcrical,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKIDecodeStringExtension
 *		对字符串编码的扩展进行解码
 *	参数：
 *		type：编码类型
 *		ext：输入参数，扩展值
 *		extlen：输入参数，扩展值长度
 *		pvalue：输出参数，返回字符串值
 *		pvaluelen：输出参数，返回字符串的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIDecodeStringExtension(int type,const unsigned char *ext,int extlen,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKICertGetCertPublicKey
 *		获取证书的公钥
 *	参数：
 *		cert：证书句柄
 *		purpose：输入参数，目的
 *	返回值：
 *		成功返回证书的公钥句柄，失败返回NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertGetCertPublicKey(NETCA_PKI_CERTIFICATE_HANDLE cert,int purpose);


/*
 *	NetcaPKICertGetCertKeyPair
 *		获取证书的对应的密钥对句柄
 *	参数：
 *		cert：证书句柄
 *		flag：输入参数，标志，如果NETCA_PKI_SEARCH_KEYPAIR_FLAG_LOCAL_MACHINE置位，则会搜索本机证书库，如果NETCA_PKI_SEARCH_KEYPAIR_FLAG_CURRENT_USER置位，则会搜索当前用户证书库
 *		purpose：输入参数，目的
 *		pwd：输入参数，密码
 *	返回值：
 *		成功返回证书的密钥对句柄，失败返回NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICertGetCertKeyPair(NETCA_PKI_CERTIFICATE_HANDLE cert,int flag,int purpose,const char *pwd);

/*
 *	NetcaPKICertSetCertKeyPair
 *		设置证书的对应的密钥对句柄，注册证书时使用。这个函数不判断证书和密钥对是否匹配
 *	参数：
 *		cert：证书句柄
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回证书的密钥对句柄，失败返回NULL
 *
 */
int NETCADLLAPI NetcaPKICertSetCertKeyPair(NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICertGetDefaultCert
 *		获取缺省的证书句柄
 *	参数：
 *		purpose：输入参数，目的，如果NETCA_PKI_CERT_TYPE_LOCAL_MACHINE置位，表示取本机的缺省证书，否则为当前用户的
 *	返回值：
 *		成功返回缺省的证书句柄，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertGetDefaultCert(int purpose);

/*
 *	NetcaPKICertSetDefaultCert
 *		设置缺省的证书句柄
 *	参数：
 *		purpose：输入参数，目的，如果NETCA_PKI_CERT_TYPE_LOCAL_MACHINE置位，表示设置本机的缺省证书，否则为当前用户的
 *		cert：证书句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertSetDefaultCert(int purpose, NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertVerifySelfSignCertSignature
 *		验证自签证书的签名
 *	参数：
 *		cert：证书句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifySelfSignCertSignature(NETCA_PKI_CERTIFICATE_HANDLE cert);


#ifdef _WIN32
#include <wincrypt.h>
/*
 *	NetcaPKICertToMsCertContext
 *		转换证书句柄为微软使用的证书句柄
 *	参数：
 *		cert：证书句柄
 *	返回值：
 *		成功返回转换后的句柄，失败返回NULL
 *
 */
PCCERT_CONTEXT NETCADLLAPI NetcaPKICertToMsCertContext(NETCA_PKI_CERTIFICATE_HANDLE cert);
#endif

/*
 *	NetcaPKICertVerifyUserPIN
 *		验证使用证书的私钥需要的PIN码
 *	参数：
 *		cert：证书句柄
 *		pwd：输入参数，密码，ASCII编码
 *		pretrynum：输出参数，密码错误返回密码重试次数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyUserPIN(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,int *pretrynum);

/* 证书库函数 */

/*
 *	NetcaPKICertOpenStore
 *		打开证书库
 *	参数：
 *		type：输入参数，证书库类型
 *		name：输入参数，证书库名称
 *	返回值：
 *		成功返回打开的证书库，失败返回NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertOpenStore(int type,const char *name);

/*
 *	NetcaPKICertCloseStore
 *		关闭证书库
 *	参数：
 *		store：证书库
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertCloseStore(NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertGetStoreCertCount
 *		获取证书库里证书的个数
 *	参数：
 *		store：证书库
 *	返回值：
 *		成功返回证书库里证书的个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKICertGetStoreCertCount(NETCA_PKI_CERT_STORE store);


/*
 *	NetcaPKICertGetStoreCert
 *		获取证书库里的证书
 *	参数：
 *		store：证书库
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回证书库里第index个证书，失败返回NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertGetStoreCert(NETCA_PKI_CERT_STORE store,int index);


/*
 *	NetcaPKICertAddStoreCert
 *		添加证书到证书库里
 *	参数：
 *		store：证书库
 *		cert：证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertAddStoreCert(NETCA_PKI_CERT_STORE store,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertDeleteStoreCert
 *		删除证书库里证书
 *	参数：
 *		store：证书库
 *		cert：证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertDeleteStoreCert(NETCA_PKI_CERT_STORE store,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICertLoadPFX
 *		解析PFX
 *	参数：
 *		data：输入参数，PFX的编码
 *		len：输入参数，PFX的编码长度
 *		pwd：输入参数，密码，UTF-8编码
 *	返回值：
 *		成功返回PFX证书库，失败返回NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertLoadPFX(const unsigned char *data,int len,const char *pwd);


/*
 *	NetcaPKICertExportPFX
 *		导出PFX
 *	参数：
 *		cert：要导出PFX的证书，必须有私钥而且私钥能导出
 *		pwd：输入参数，PFX的密码，UTF-8编码
 *		otherCerts：输入参数，PFX文件里要包含的其他参数
 *		otherCertCount：输入参数，otherCerts的个数
 *		friendlyName：输入参数，好记的名字
 *		pfx：输出参数，导出的PFX编码
 *		pfxLen：输出参数，pfx的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertExportPFX(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,const NETCA_PKI_CERTIFICATE_HANDLE otherCerts[],int otherCertCount,const char *friendlyName,unsigned char **pfx,int *pfxLen);

/*
 *	NetcaPKICertLoadP7c
 *		解析P7c
 *	参数：
 *		data：输入参数，P7c的编码
 *		len：输入参数，P7c的编码长度
 *	返回值：
 *		成功返回P7c证书库，失败返回NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertLoadP7c(const unsigned char *data,int len);


/* 证书路径及其验证函数 */

/*
 *	NetcaPKICertVerifyCert
 *		验证证书
 *	参数：
 *		cert：证书
 *		checktime：输入参数，验证的时间，为NULL表示当前时间。格式为YYYYMMDDhhmmssZ
 *		flag：输入参数，验证标志
 *		status：输出参数，证书的作废状态，NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED为未作废，NETCA_PKI_CERTIFICATE_STATUS_REVOKED为作废，NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINED为不确定,NETCA_PKI_CERTIFICATE_STATUS_CA_REVOKED为CA作废
 *		info：输出参数，作废时返回作废信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *checktime,int flag,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);


/*
 *	NetcaPKICertGetCertPath
 *		构造证书路径
 *	参数：
 *		cert：证书
 *		certpath：输出参数，返回的证书路径
 *		count：输出参数，返回的path的证书个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertGetCertPath(NETCA_PKI_CERTIFICATE_HANDLE cert, NETCA_PKI_CERTIFICATE_HANDLE **certpath,int* count);

/*
 *	NetcaPKICertFreeCertPath
 *		释放证书路径
 *	参数：
 *		cert：证书
 *		certpath：证书路径
 *		count：输入参数，path的证书个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertFreeCertPath(NETCA_PKI_CERTIFICATE_HANDLE *certpath,int count);

/*
 *	NetcaPKICertFreeRevokedCert
 *		释放作废证书
 *	参数：
 *		cert：作废证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertFreeRevokedCert(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertGetRevokedCertRevokedTime
 *		获取作废证书的作废时间
 *	参数：
 *		cert：作废证书
 *	返回值：
 *		成功返回作废证书的作废时间，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKICertGetRevokedCertRevokedTime(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertGetRevokedCertRevokedReason
 *		获取作废证书的作废原因
 *	参数：
 *		cert：作废证书
 *	返回值：
 *		成功返回作废证书的作废原因，没有作废原因返回-1
 *
 */
int  NETCADLLAPI NetcaPKICertGetRevokedCertRevokedReason(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertCRLVerifyCert
 *		使用CRL验证证书的作废状态
 *	参数：
 *		cert：证书
 *		crl：输入参数，CRL的编码
 *		crllen：输入参数，CRL的长度
 *		checktime：输入参数，验证的时间，为NULL表示当前时间。格式为YYYYMMDDhhmmssZ
 *		status：输出参数，证书的作废状态，NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED为未作废，NETCA_PKI_CERTIFICATE_STATUS_REVOKED为作废，NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINED为不确定
 *		info：输出参数，作废时，返回作废信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertCRLVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* crl,int crllen,const char *checktime,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);


/*
 *	NetcaPKICertOCSPVerifyCert
 *		使用OCSP验证证书的作废状态
 *	参数：
 *		cert：证书
 *		ocspurl：输入参数，OCSP的URL，如果为NULL，则使用安全环境的配置值
 *		vacert：输入参数，OCSP证书，可以为NULL
 *		status：输出参数，证书的作废状态，NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED为未作废，NETCA_PKI_CERTIFICATE_STATUS_REVOKED为作废，NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINED为不确定
 *		info：输出参数，作废时，返回作废信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertOCSPVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const char* ocspurl,NETCA_PKI_CERTIFICATE_HANDLE vacert,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);

/*
 *	NetcaPKICertNewVerify
 *		创建证书验证句柄
 *	参数：
 *		无
 *	返回值：
 *		成功返回证书验证句柄，失败返回NULL
 *
 */
NETCA_PKI_CERT_VERIFY_HANDLE NETCADLLAPI NetcaPKICertNewVerify(void);

/*
 *	NetcaPKICertFreeVerify
 *		释放证书验证句柄
 *	参数：
 *		hCertVerify：证书验证句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertFreeVerify(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify);

/*
 *	NetcaPKICertVerifySetOption
 *		设置证书验证的选项
 *	参数：
 *		hCertVerify：证书验证句柄
 *		option:输入参数，验证选项
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetOption(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,int option);

/*
 *	NetcaPKICertVerifySetParam
 *		设置证书验证的选项
 *	参数：
 *		hCertVerify：证书验证句柄
 *		param:输入参数，验证参数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetParam(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *param);

/*
 *	NetcaPKICertVerifyAddRootCert
 *		添加根证书
 *	参数：
 *		hCertVerify：证书验证句柄
 *		cert:输入参数，根证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddRootCert(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertVerifyAddCACert
 *		添加CA证书
 *	参数：
 *		hCertVerify：证书验证句柄
 *		cert:输入参数，CA证书
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddCACert(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICertVerifySetVerifyTime
 *		设置验证的时间
 *	参数：
 *		hCertVerify：证书验证句柄
 *		verifyTime:输入参数，验证的时间
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetVerifyTime(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *verifyTime);

/*
 *	NetcaPKICertVerifyAddIgnoreExtension
 *		添加可不处理的关键扩展
 *	参数：
 *		hCertVerify：证书验证句柄
 *		ext:输入参数，扩展的OID
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddIgnoreExtension(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *ext);

/*
 *	NetcaPKICertVerifyAddCRL
 *		添加CRL
 *	参数：
 *		hCertVerify：证书验证句柄
 *		crl:输入参数，CRL的编码
 *		crlLen:输入参数，CRL的值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddCRL(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const unsigned char *crl,int crlLen);

/*
 *	NetcaPKICertVerifyAddOCSP
 *		添加OCSP
 *	参数：
 *		hCertVerify：证书验证句柄
 *		vaCert:输入参数，OCSP证书
 *		ocsp:输入参数，CRL的编码
 *		ocspLen:输入参数，CRL的值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddOCSP(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE vaCert,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKICertVerify
 *		验证证书
 *	参数：
 *		hCertVerify：证书验证句柄
 *		cert：证书
 *		status：输出参数，证书的作废状态，NETCA_PKI_CERTIFICATE_STATUS_UNREVOKED为未作废，NETCA_PKI_CERTIFICATE_STATUS_REVOKED为作废，NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINED为不确定
 *		info：输出参数，作废时，返回作废信息
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerify(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);

/*
 *	NetcaPKICertVerifyGetCertPath
 *		获取证书路径
 *	参数：
 *		hCertVerify：证书验证句柄
 *		certpath：输出参数，返回的证书路径
 *		count：输出参数，返回的path的证书个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetCertPath(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, NETCA_PKI_CERTIFICATE_HANDLE **certpath,int* count);

/*
 *	NetcaPKICertVerifyGetPublicKey
 *		获取证书的公钥
 *	参数：
 *		hCertVerify：证书验证句柄
 *		purpose：输入参数，目的
 *	返回值：
 *		成功返回证书的公钥句柄，失败返回NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertVerifyGetPublicKey(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,int purpose);

/*
 *	NetcaPKICertVerifyGetAuthPolicySet
 *		获取证书的颁发机构策略集
 *	参数：
 *		hCertVerify：证书验证句柄
 *		policySet：输出参数，返回的颁发机构策略集
 *		count：输出参数，返回的颁发机构策略集的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetAuthPolicySet(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, char ***policySet,int* count);

/*
 *	NetcaPKICertVerifyGetUserPolicySet
 *		获取证书的用户策略集
 *	参数：
 *		hCertVerify：证书验证句柄
 *		policySet：输出参数，返回的用户策略集
 *		count：输出参数，返回的用户策略集的个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetUserPolicySet(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, char ***policySet,int* count);


/*
 *	NetcaPKIComputeSM2Z
 *		计算SM2签名要用到的Z的值
 *	参数：
 *		hPublicKey：ECC公钥
 *		hashAlgo：输入参数，Hash算法
 *		param：输入参数，ID
 *		Z：输出参数，返回的Z
 *		pZLen：输出参数，返回的Z的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIComputeSM2Z(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int hashAlgo,const struct NETCA_PKI_SM2Sign_PARAM_st *param,unsigned char **Z,int *pZLen);


/*
 *	NetcaPKIKDF
 *		KDF，密钥导出函数
 *	参数：
 *		kdfAlgo：输入参数，KDF算法
 *		param：输入参数，KDF算法的参数
 *		data：输入参数，数据
 *		dataLen：输入参数，data的长度
 *		keyLen：输入参数，密钥的长度
 *		key：输出参数，返回的导出的密钥
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIKDF(int kdfAlgo,const void *param,const unsigned char *data,int dataLen,int keyLen,unsigned char *key);

/*
 *	NetcaPKIKeyWrap
 *		用对称密钥加密另一对称密钥
 *	参数：
 *		algo：输入参数，对称加密算法
 *		isHmacKey：输入参数，为真表示HMAC的Key,为假表示对称密钥的Key
 *		param：输入参数，算法参数
 *		kek：输入参数，用来加密的密钥
 *		kekLen：输入参数，kek的长度
 *		cek：输入参数，被加密的密钥
 *		cekLen：输入参数，cek的长度
 *		keywrap：输出参数，返回keywrap值
 *		keywrapLen：输出参数，返回keywrap的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIKeyWrap(int algo,int isHmacKey,const void *param,const unsigned char *kek,int kekLen,const unsigned char *cek,int cekLen,unsigned char **keywrap,int *keywrapLen);

/*
 *	NetcaPKIKeyUnwrap
 *		用对称密钥解密另一对称密钥
 *	参数：
 *		algo：输入参数，对称加密算法
 *		isHmacKey：输入参数，为真表示HMAC的Key,为假表示对称密钥的Key
 *		param：输入参数，算法参数
 *		kek：输入参数，用来加密的密钥
 *		kekLen：输入参数，kek的长度
 *		keywrap：输入参数，要解密的keywrap值
 *		keywrapLen：输入参数，keywrap的长度
 *		cek：输出参数，返回解密得到的密钥
 *		cekLen：输出参数，返回cek的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIKeyUnwrap(int algo,int isHmacKey,const void *param,const unsigned char *kek,int kekLen,const unsigned char *keywrap,int keywrapLen,unsigned char **cek,int *cekLen);


#ifdef __cplusplus
	}	
#endif
#endif

