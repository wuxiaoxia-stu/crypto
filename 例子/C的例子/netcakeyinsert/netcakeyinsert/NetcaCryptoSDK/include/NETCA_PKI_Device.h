#ifndef _NETCA_PKI_DEVICE_INLCUDE_H_
#define _NETCA_PKI_DEVICE_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	DeviceInit
 *		初始化DLL使用的全局资源，在使用设备接口前必须先调用该函数
 *	参数：
 *		无
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceInit(void);

/*
 *	DeviceEnd
 *		释放DLL使用的全局资源，在设备接口不再使用前应该调用该函数
 *	参数：
 *		无
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceEnd(void);

/*
 *	DeviceGetAllDevices
 *		获取当前连接的所有的设备组成的设备集
 *	参数：
 *		无
 *	返回值：
 *		成功返回有效的设备集句柄，失败返回NULL
 *
 */
SPI_DEVICE_HANDLE_SET NETCADLLAPI DeviceGetAllDevices(void);


/*
 *	DeviceGetDeviceCount
 *		获取设备集的设备个数
 *	参数：
 *		hDeviceSet：设备集句柄
 *	返回值：
 *		成功返回设备集中设备的个数，失败返回-1
 *
 */
int NETCADLLAPI DeviceGetDeviceCount(SPI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	DeviceGetDevice
 *		获取设备集中的设备
 *	参数：
 *		hDeviceSet：设备集句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回设备集中第index个设备句柄，失败返回NULL
 *
 */
SPI_DEVICE_HANDLE NETCADLLAPI DeviceGetDevice(SPI_DEVICE_HANDLE_SET hDeviceSet,int index);


/*
 *	DeviceFreeDevices
 *		释放设备集
 *	参数：
 *		hDeviceSet：设备集句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI DeviceFreeDevices(SPI_DEVICE_HANDLE_SET hDeviceSet);


/*
 *	DeviceFindDevice
 *		根据序列号获取设备
 *	参数：
 *		sn：输入参数，设备序列号，ASCII编码
 *		phDevice：输出参数，成功返回当前连接的序列号为sn的设备的设备句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceFindDevice(const char *sn,SPI_DEVICE_HANDLE *phDevice);


/*
 *	DeviceGetSerialNumber
 *		获取设备的序列号
 *	参数：
 *		hDevice：设备句柄
 *		sn：输出参数，返回设备序列号，ASCII编码
 *		snlen：输入参数，sn的缓冲区长度
 *		pretsnlen：输出参数，如果sn为NULL，则返回可以容纳序列号的长度。否则，返回序列号的长度，包含最后的'\0'结束符。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，snlen太小返回NETCA_PKI_MOREDATA。
 *
 */
int NETCADLLAPI DeviceGetSerialNumber(SPI_DEVICE_HANDLE hDevice,char *sn,int snlen,int *pretsnlen);



/*
 *	DeviceGetSerialNumber
 *		获取设备的卷标
 *	参数：
 *		hDevice：设备句柄
 *		label：输出参数，返回设备的卷标，UTF-8编码
 *		labellen：输入参数，label的缓冲区长度
 *		pretlabellen：输出参数，如果label为NULL，则返回可以容纳卷标的长度。否则，返回卷标的长度，包含最后的'\0'结束符。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，labellen太小返回NETCA_PKI_MOREDATA。
 *
 */
int NETCADLLAPI DeviceGetLabel(SPI_DEVICE_HANDLE hDevice,char *label,int labellen,int *pretlabellen);

/*
 *	DeviceVerifyPwd
 *		验证设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码。
 *		pwd：输入参数，密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回其他值
 *
 */
int NETCADLLAPI DeviceVerifyPwd(SPI_DEVICE_HANDLE hDevice,int type,const char *pwd,int *pretrynum);


/*
 *	DeviceChangePwd
 *		修改设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码。
 *		oldpwd：输入参数，旧的密码，ASCII编码
 *		newpwd：输入参数，新的密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回其他值
 *
 */
int NETCADLLAPI DeviceChangePwd(SPI_DEVICE_HANDLE hDevice,int type, const char *oldpwd,const char *newpwd,int *pretrynum);


/*
 *	DeviceUnlockPwd
 *		解锁设备的密码
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，当前版本只能是NETCA_PKI_USER_PWD表示用户密码。
 *		sopwd：输入参数，管理员的密码，ASCII编码
 *		newpwd：输入参数，新的用户密码，ASCII编码
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，密码错误返回NETCA_PKI_PWD_ERROR，失败返回其他值
 *
 */
int NETCADLLAPI DeviceUnlockPwd(SPI_DEVICE_HANDLE hDevice,int type, const char *sopwd,const char *newpwd,int *pretrynum);

/*
 *	DeviceGetPwdRetryNum
 *		获取设备密码的重试次数
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码。
 *		pretrynum：输出参数，验证密码出错时，返回密码还可以重试的次数，如果不支持返回密码还可以重试的次数，返回NETCA_PKI_UNSUPPORTED_RETRY_NUMBER。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceGetPwdRetryNum(SPI_DEVICE_HANDLE hDevice,int type, int *pretrynum);


/*
 *	DeviceLockDevice
 *		给设备加锁
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceLockDevice(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceUnlockDevice
 *		给设备解锁
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceUnlockDevice(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceFreeDevice
 *		释放设备句柄
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI DeviceFreeDevice(SPI_DEVICE_HANDLE hDevice);




/*
 *	DeviceCreateData
 *		在设备中创建一项持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		mode：输入参数，持久数据的权限
 *		length：输入参数，持久数据的最大长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果持久数据已经存在，返回NETCA_PKI_EXISIT，如果没权限创建持久数据，返回NETCA_PKI_ ACCESSDENIED。如果不支持指定标识的持久数据，返回NETCA_PKI_ UNSUPPORTED
 *
 */
int NETCADLLAPI DeviceCreateData(SPI_DEVICE_HANDLE hDevice,int dataId, const char * mode,int length);


/*
 *	DeviceReadDataEx
 *		读持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		offset：输入参数，持久数据的位移
 *		data：输出参数，返回读到的数据，可以为NULL
 *		datalen：输入参数，data的长度
 *		pretdatalen：输出参数，返回读到的持久数据的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限读持久数据，返回NETCA_PKI_ ACCESSDENIED。
 *
 */
int NETCADLLAPI DeviceReadDataEx(SPI_DEVICE_HANDLE hDevice,int dataId, int offset,unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	DeviceWriteDataEx
 *		写持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *		offset：输入参数，持久数据的位移
 *		data：输出参数，要写入的数据
 *		datalen：输入参数，data的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限写持久数据，返回NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI DeviceWriteDataEx(SPI_DEVICE_HANDLE hDevice,int dataId,int offset, const unsigned char *data,int datalen);

/*
 *	DeviceDeleteData
 *		删除持久数据
 *	参数：
 *		hDevice：设备句柄
 *		dataId：输入参数，持久数据标识
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有指定的持久数据，返回NETCA_PKI_NOTEXISIT，如果没权限删除持久数据，返回NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceDeleteData(SPI_DEVICE_HANDLE hDevice,int dataId);


/*
 *	DeviceGetKeypairCount
 *		获取设备中密钥对数量
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回设备中密钥对数量，失败返回-1
 */
int NETCADLLAPI DeviceGetKeypairCount(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceGetKeypair
 *		获取设备中的密钥对
 *	参数：
 *		hDevice：设备句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回设备中第index个密钥对，失败返回NULL
 */
SPI_KEYPAIR_HANDLE NETCADLLAPI DeviceGetKeypair(SPI_DEVICE_HANDLE hDevice,int index);

/*
 *	DeviceFindKeypair
 *		根据密钥对的类型和标签，获取设备中的密钥对
 *	参数：
 *		hDevice：设备句柄
 *		type：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回设备中指定的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI DeviceFindKeypair(SPI_DEVICE_HANDLE hDevice,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);

/*
 *	DeviceFreeKeypair
 *		释放密钥对句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceFreeKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairLabel
 *		获取密钥对的标签
 *	参数：
 *		hKeypair：密钥对句柄
 *		label：输出参数，返回的密钥对的标签，UTF-8编码
 *		labellen：输入参数，label的缓冲区长度
 *		pretlabellen：输出参数，如果label为NULL，则返回可以容纳卷标的长度。否则，返回卷标的长度，包含最后的'\0'结束符
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，labellen太小返回NETCA_PKI_MOREDATA
 */
int NETCADLLAPI DeviceGetKeypairLabel(SPI_KEYPAIR_HANDLE hKeypair,char *label,int labellen,int *pretlabellen);

/*
 *	DeviceGetKeypairType
 *		获取密钥对的类型
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的类型，失败返回-1
 */
int NETCADLLAPI DeviceGetKeypairType(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairAlgorithm
 *		获取密钥对的算法
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的算法，失败返回-1
 */
int NETCADLLAPI DeviceGetKeypairAlgorithm(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairBits
 *		获取密钥对的长度，以位为单位
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的位数，失败返回-1
 */
int NETCADLLAPI DeviceGetKeypairBits(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGenerateKeypair
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
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的算法返回NETCA_PKI_ UNSUPPORTED，如果没权限产生密钥对，返回NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceGenerateKeypair(SPI_DEVICE_HANDLE hDevice,int algo,int keybits,const void *param,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);


/*
 *	DeviceImportKeypair
 *		导入密钥对到设备中去
 *	参数：
 *		hDevice：设备句柄
 *		keyblob：输入参数，密钥对的编码
 *		keybloblen：输入参数，密钥对的编码的长度
 *		type：输入参数，密钥对的类型
 *		label：输入参数，密钥对标签，UTF-8编码
 *		phKeypair：输出参数，成功返回产生的密钥对句柄，失败返回NULL
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持返回NETCA_PKI_ UNSUPPORTED，如果没权限导入密钥对，返回NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceImportKeypair(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);

/*
 *	DeviceExportKeypair
 *		导出密钥对
 *	参数：
 *		hKeypair：密钥对句柄
 *		keyblob：输出参数，返回密钥对的编码
 *		keybloblen：输入参数，keyblob的缓冲区的长度。
 *		pretkeybloblen：输出参数，如果keyblob为NULL，返回能容纳导出密钥对的长度，否则返回导出密钥对的长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果keybloblen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceExportKeypair(SPI_KEYPAIR_HANDLE hKeypair,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);

/*
 *	DeviceDeleteKeypair
 *		在设备中删除密钥对及其相关的证书
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL如果没权限删除密钥对，返回NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI DeviceDeleteKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetPublicKeyFromKeypair
 *		获取密钥对的公钥句柄
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对的公钥句柄，失败返回NULL
 */
SPI_PUBLICKEY_HANDLE NETCADLLAPI DeviceGetPublicKeyFromKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceExportPublicKey
 *		导出公钥
 *	参数：
 *		hPublicKey：公钥句柄
 *		keyblob：输出参数，返回公钥的编码
 *		keybloblen：输入参数，keyblob的缓冲区的长度。
 *		pretkeybloblen：输出参数，如果keyblob为NULL，返回能容纳导出公钥的长度，否则返回导出公钥的长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的公钥返回NETCA_PKI_ UNSUPPORTED，如果keybloblen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceExportPublicKey(SPI_PUBLICKEY_HANDLE hPublicKey,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);


/*
 *	DeviceImportPublicKey
 *		导入临时的公钥
 *	参数：
 *		hDevice：设备句柄
 *		keyblob：输入参数，公钥的编码
 *		keybloblen：输入参数，公钥的编码的长度。
 *		phPublicKey：输出参数，成功返回临时的公钥句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持的公钥返回NETCA_PKI_ UNSUPPORTED，如果keybloblen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceImportPublicKey(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,SPI_PUBLICKEY_HANDLE *phPublicKey);

/*
 *	DeviceGetPublicKeyBits
 *		获取公钥的长度，以位为单位
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回公钥的位数，失败返回-1。
 */
int NETCADLLAPI DeviceGetPublicKeyBits(SPI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	DeviceFreePublicKey
 *		释放公钥句柄
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL。
 */
int NETCADLLAPI DeviceFreePublicKey(SPI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	DeviceGetPublicKeyAlgorithm
 *		获取公钥的算法
 *	参数：
 *		hPublicKey：公钥句柄
 *	返回值：
 *		成功返回公钥的算法，失败返回-1。
 */
int NETCADLLAPI DeviceGetPublicKeyAlgorithm(SPI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	DeviceGetCertificateCount
 *		获取密钥对相关的证书个数
 *	参数：
 *		hKeypair：密钥对句柄
 *	返回值：
 *		成功返回密钥对相关的证书个数，失败返回-1。
 */
int NETCADLLAPI DeviceGetCertificateCount(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetCertificate
 *		获取密钥对相关的第index个证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		index：输入参数，索引号，从0算起
 *		certblob：输出参数，返回第index个证书的DER编码
 *		certbloblen：输入参数，certblob缓冲区的大小
 *		pretcertbloblen：输出参数，如果certblob为NULL，则返回可以容纳证书的DER编码的长度。否则，返回证书的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果certbloblen太小返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceGetCertificate(SPI_KEYPAIR_HANDLE hKeypair,int index,unsigned char *certblob,int certbloblen,int *pretcertbloblen);

/*
 *	DeviceDeleteCertificate
 *		获取密钥对相关的第index个证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		index：输入参数，索引号，从0算起
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限删除证书，返回NETCA_PKI_ ACCESSDENIED。
 */
int NETCADLLAPI DeviceDeleteCertificate(SPI_KEYPAIR_HANDLE hKeypair,int index);


/*
 *	DeviceUpdateCertificate
 *		把证书写入设备并和密钥对相关联，这个函数会删掉以前和密钥对关联的证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		certblob：输入参数，证书的DER编码
 *		certbloblen：输入参数，证书的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限写证书，返回NETCA_PKI_ ACCESSDENIED。
 */
int NETCADLLAPI DeviceUpdateCertificate(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);


/*
 *	DeviceAddCertificate
 *		把证书写入设备并和密钥对相关联，这个函数会保留以前和密钥对关联的证书
 *	参数：
 *		hKeypair：密钥对句柄
 *		certblob：输入参数，证书的DER编码
 *		certbloblen：输入参数，证书的DER编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果没有权限写证书，返回NETCA_PKI_ ACCESSDENIED。
 */
int NETCADLLAPI DeviceAddCertificate(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);



/*
 *	DeviceIsSupportedAlgorithm
 *		询问设备是否支持某个算法。这个函数已经废弃，不要再实现它，应该实现DeviceIsSupportedAlgorithm2这个函数
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，算法
 *	返回值：
 *		如果支持返回1，不支持返回0。
 */
int NETCADLLAPI DeviceIsSupportedAlgorithm(SPI_DEVICE_HANDLE hDevice,int algo);


/*
 *	DeviceIsSupportedAlgorithm2
 *		询问设备是否支持某个算法。这个函数用于代替DeviceIsSupportedAlgorithm
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，算法
 *		keyLen：输入参数，密钥长度，以位为单位
 *		usage：输入参数，算法的用途，比如加密解密之类
 *		param：输入参数，算法相关的参数
 *		
 *	返回值：
 *		如果支持返回1，不支持返回0。
 */
int NETCADLLAPI DeviceIsSupportedAlgorithm2(SPI_DEVICE_HANDLE hDevice,int algo,int keyLen,int usage,const void *param);


/*
 *	DeviceGenerateRandom
 *		获取随机数
 *	参数：
 *		hDevice：设备句柄
 *		len：输入参数，随机数长度
 *		rand：输出参数，返回的随机数长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 */
int NETCADLLAPI DeviceGenerateRandom(SPI_DEVICE_HANDLE hDevice,int len,unsigned char *rand);



/*
 *	DeviceNewHash
 *		创建Hash句柄
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，Hash算法
 *	返回值：
 *		成功返回Hash句柄，失败返回NULL。
 */
SPI_HASH_HANDLE NETCADLLAPI DeviceNewHash(SPI_DEVICE_HANDLE hDevice,int algo);


/*
 *	DeviceHashUpdate
 *		Hash数据，这个函数可以多次调用
 *	参数：
 *		hHash：Hash句柄
 *		data：输入参数，要进行Hash运算的数据
 *		datalen：输入参数，data的字节数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 */
int NETCADLLAPI DeviceHashUpdate(SPI_HASH_HANDLE hHash,const unsigned char *data,int datalen);

/*
 *	DeviceHashFinal
 *		结束Hash运算，获取Hash值
 *	参数：
 *		hHash：Hash句柄
 *		hashvalue：输出参数，返回的Hash值，可以为NULL
 *		hashvaluelen：输入参数，hashvalue缓冲区的大小
 *		prethashvaluelen：输出参数，返回Hash值的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果hashvaluelen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceHashFinal(SPI_HASH_HANDLE hHash,unsigned char *hashvalue, int hashvaluelen,int *prethashvaluelen);


/*
 *	DeviceFreeHash
 *		释放Hash句柄
 *	参数：
 *		hHash：Hash句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL。
 */
int NETCADLLAPI DeviceFreeHash(SPI_HASH_HANDLE hHash);

/*
 *	DeviceDuplicateHash
 *		复制Hash句柄。复制不能使用引用计数的方式，必须复制Hash的内部的状态
 *	参数：
 *		hHash：要复制的Hash句柄
 *		phNewHash：输出函数，返回复制得到的Hash句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，不支持返回NETCA_PKI_UNSUPPORTED。
 */
int NETCADLLAPI DeviceDuplicateHash(SPI_HASH_HANDLE hHash,SPI_HASH_HANDLE *phNewHash);

/*
 *	DeviceNewMac
 *		创建MAC句柄
 *	参数：
 *		hDevice：设备句柄
 *		algo：输入参数，Mac算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，Mac算法的参数，对于HMAC来说，为NULL
 *	返回值：
 *		成功返回MAC句柄，失败返回NULL。
 */
SPI_MAC_HANDLE NETCADLLAPI DeviceNewMac(SPI_DEVICE_HANDLE hDevice,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	DeviceMacUpdate
 *		Mac数据，这个函数可以多次调用
 *	参数：
 *		hMac：Mac句柄
 *		data：输入参数，要进行Mac运算的数据
 *		datalen：输入参数，data的字节数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 */
int NETCADLLAPI DeviceMacUpdate(SPI_MAC_HANDLE hMac,const unsigned char *data,int datalen);

/*
 *	DeviceMacFinal
 *		结束Mac运算，获取Mac值
 *	参数：
 *		hMac：Mac句柄
 *		macvalue：输出参数，返回的Mac值，可以为NULL
 *		macvaluelen: 输入参数, macvalue缓冲区的大小
 *		pretmacvaluelen：输出参数，返回MAC的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果macvaluelen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceMacFinal(SPI_MAC_HANDLE hMac,unsigned char *macvalue,int macvaluelen,int *pretmacvaluelen);


/*
 *	DeviceFreeMac
 *		释放Mac句柄
 *	参数：
 *		hMac：Mac句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值。
 */
int NETCADLLAPI DeviceFreeMac(SPI_MAC_HANDLE hMac);



/*
 *	DeviceNewCipher
 *		创建加解密句柄
 *	参数：
 *		hDevice：设备句柄
 *		enc：输入参数，1表加密，0表示解密
 *		algo：输入参数，加密算法
 *		key：输入参数，密钥
 *		keylen：输入参数，密钥的字节数
 *		param：输入参数，加解密的参数
 *	返回值：
 *		成功返回创建加解密句柄，失败返回NULL。
 */
SPI_CIPHER_HANDLE NETCADLLAPI DeviceNewCipher(SPI_DEVICE_HANDLE hDevice,int enc,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	DeviceImportKeyAndNewCipher
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
int NETCADLLAPI DeviceImportKeyAndNewCipher(SPI_KEYPAIR_HANDLE hKeypair,int pubkeyencalgo,const void *pubkeyencparam,const unsigned char *enckey,int enckeylen,int enc,int algo,const void *param,SPI_CIPHER_HANDLE *phCipher);

/*
 *	DeviceCipherUpdate
 *		加解密数据，这个函数可以多次调用
 *	参数：
 *		hCipher：加解密句柄
 *		in：输入参数，输入数据
 *		inlen：输入参数，in的字节数
 *		out：输出参数，返回的数据
 *		outlen：输入参数，out缓冲区的大小
 *		pretoutlen：输出参数，如果out为NULL，不进行真正的加解密，返回可以容纳的输出长度，否则，返回输出长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，outlen太小，返回NETCA_PKI_MOREDATA。
 */
int NETCADLLAPI DeviceCipherUpdate(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,int inlen,unsigned char *out,int outlen,int *pretoutlen);

/*
 *	DeviceCipher
 *		一步完成加解密数据
 *	参数：
 *		hCipher：加解密句柄
 *		in：输入参数，输入数据
 *		inlen：输入参数，in的字节数
 *		out：输出参数，返回的数据
 *		outlen：输入参数，out缓冲区的大小
 *		pretoutlen：输出参数，如果out为NULL，不进行真正的加解密，返回可以容纳的输出长度，否则，返回输出长度。
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，outlen太小，返回NETCA_PKI_MOREDATA。如果算法不NETCA_PKI_UNSUPPORTED
 */
int NETCADLLAPI DeviceCipher(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,long long inlen,unsigned char *out,long long outlen,long long *pretoutlen);

/*
 *	DeviceFreeCipher
 *		释放加解密句柄
 *	参数：
 *		hCipher：加解密句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL。
 */
int NETCADLLAPI DeviceFreeCipher(SPI_CIPHER_HANDLE hCipher);


/*
 *	DeviceSign
 *		进行签名
 *	参数：
 *		hKeypair：密钥对句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，签名参数
 *		tbs：输入参数，输入要签名的数据
 *		tbslen：输入参数，tbs的字节数
 *		sign：输出参数，返回的签名值
 *		signlen：输入参数，sign缓冲区的大小
 *		pretsignlen：输出参数，如果sign为NULL，则返回能容纳输出的长度。否则，返回签名的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL，如果signlen太小，返回NETCA_PKI_MOREDATA，如果没有权限签名，返回NETCA_PKI_ACCESSDENIED，如果不支持的签名算法，返回NETCA_PKI_ UNSUPPORTED。
 */
int NETCADLLAPI DeviceSign(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *tbs,int tbslen,unsigned char *sign,int signlen,int *pretsignlen);



/*
 *	DeviceVerify
 *		验证签名
 *	参数：
 *		hPublicKey：公钥句柄
 *		algo：输入参数，签名算法
 *		param：输入参数，签名参数
 *		tbs：输入参数，输入要签名的数据
 *		tbslen：输入参数，tbs的字节数
 *		sign：输入参数，签名值
 *		signlen：输入参数，签名值的字节数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL如果不支持的签名算法，返回NETCA_PKI_ UNSUPPORTED
 */
int NETCADLLAPI DeviceVerify(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *tbs,int tbslen,const unsigned char *sign,int signlen);


/*
 *	DevicePublicKeyEncrypt
 *		公钥加密
 *	参数：
 *		hPublicKey：公钥句柄
 *		algo：输入参数，公钥加密算法
 *		param：输入参数，公钥加密参数
 *		clear：输入参数，明文
 *		clearlen：输入参数，明文的字节数
 *		cipher：输出参数，返回的密文
 *		cipherlen：输入参数，cipher缓冲区的字节数
 *		pretcipherlen：输出参数，如果cipher为NULL，返回能容纳密文的长度。否则返回密文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL如果不支持的公钥加密算法，返回NETCA_PKI_ UNSUPPORTED。如果cipherlen太小，返回NETCA_PKI_MOREDATA
 */
int NETCADLLAPI DevicePublicKeyEncrypt(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *clear,int clearlen,unsigned char *cipher,int cipherlen,int *pretcipherlen);


/*
 *	DevicePrivateKeyDecrypt
 *		私钥解密
 *	参数：
 *		hKeypair：密钥对句柄
 *		algo：输入参数，公钥加密算法
 *		param：输入参数，公钥加密参数
 *		cipher：输入参数，密文
 *		cipherlen：输入参数，密文的字节数
 *		clear：输出参数，返回的明文
 *		clearlen：输入参数，clear缓冲区的字节数
 *		pretclearlen：输出参数，如果clear为NULL，返回能容纳明文的长度。否则返回明文的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL如果不支持的公钥加密算法，返回NETCA_PKI_ UNSUPPORTED。如果clearlen太小，返回NETCA_PKI_MOREDATA。如果没有权限解密，返回NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DevicePrivateKeyDecrypt(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *cipher,int cipherlen,unsigned char *clear,int clearlen,int *pretclearlen);


/*
 *	DeviceKeyAgreement
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
int NETCADLLAPI DeviceKeyAgreement(SPI_KEYPAIR_HANDLE hKeypair,SPI_PUBLICKEY_HANDLE hRespPublicKey,SPI_KEYPAIR_HANDLE hTempKeypair,SPI_PUBLICKEY_HANDLE hTempRespPublicKey,int algo,void *param,int keylen,unsigned char *key);

/*
 *	DeviceGetState
 *		获取设备的状态，看看是否已经格式化过。
 *	参数：
 *		hDevice：设备句柄
 *		pState：输出参数，成功返回设备的状态。NETCA_PKI_DEVICE_STATE_NORMAL表示正常使用状态（也就是已经格式化过了），NETCA_PKI_DEVICE_ STATE_UNINITIALIZED表示未格式化状态，NETCA_PKI_DEVICE_ STATE_OTHER表示其他CA的KEY
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI DeviceGetState(SPI_DEVICE_HANDLE hDevice,int *pState);

/*
 *	DeviceFormatDevice
 *		格式化设备。
 *	参数：
 *		hDevice：设备句柄
 *		soPwd：输入参数，解锁密码，ASCII编码
 *		soPwdRetryNumber：输入参数，解锁密码的重试次数，取值范围1~15
 *		userPwd：输入参数，用户密码，ASCII编码
 *		userPwdRetryNumber：输入参数，用户密码的重试次数，取值范围1~15
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，没有权限返回NETCA_PKI_ACCESSDENIED，不支持返回NETCA_PKI_UNSUPPORTED，失败返回NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceFormatDevice(SPI_DEVICE_HANDLE hDevice,const char *soPwd,int soPwdRetryNumer,const char *userPwd,int userPwdRetryNumber);


/*
 *	DeviceNewDevice
 *		格式化设备。
 *	参数：
 *		hDevice：设备句柄
 *		subDeviceName：输入参数，子设备名称
 *		soPwd：输入参数，解锁密码，ASCII编码
 *		soPwdRetryNumber：输入参数，解锁密码的重试次数，取值范围1~15
 *		userPwd：输入参数，用户密码，ASCII编码
 *		userPwdRetryNumber：输入参数，用户密码的重试次数，取值范围1~15
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，没有权限返回NETCA_PKI_ACCESSDENIED，不支持返回NETCA_PKI_UNSUPPORTED，子设备名已经存在，返回NETCA_PKI_EXIST，失败返回NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceNewDevice(SPI_DEVICE_HANDLE hDevice, const char *subDeviceName, const char *soPwd, int soPwdRetryNumer, const char *userPwd, int userPwdRetryNumber, SPI_DEVICE_HANDLE *phDevice2);


/*
 *	DeviceDeleteDevice
 *		删除逻辑设备。
 *	参数：
 *		hDevice：设备句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，没有权限返回NETCA_PKI_ACCESSDENIED，不支持返回NETCA_PKI_UNSUPPORTED，失败返回NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceDeleteDevice(SPI_DEVICE_HANDLE hDevice);


/*
 *	DeviceIsSamePhysicalDevice
 *		判断是否是同一物理设备。
 *	参数：
 *		hDevice1：设备句柄1
 *		hDevice2：设备句柄2
 *	返回值：
 *		如果是同一物理设备返回1，否则返回0
 */
int NETCADLLAPI DeviceIsSamePhysicalDevice(SPI_DEVICE_HANDLE hDevice1,SPI_DEVICE_HANDLE hDevice2);

typedef int (NETCADLLAPI * DeviceInit_Ptr)(void);
typedef int (NETCADLLAPI * DeviceEnd_Ptr)(void);
typedef SPI_DEVICE_HANDLE_SET (NETCADLLAPI * DeviceGetAllDevices_Ptr)(void);
typedef int (NETCADLLAPI * DeviceGetDeviceCount_Ptr)(SPI_DEVICE_HANDLE_SET hDeviceSet);
typedef SPI_DEVICE_HANDLE (NETCADLLAPI * DeviceGetDevice_Ptr)(SPI_DEVICE_HANDLE_SET hDeviceSet,int index);
typedef int (NETCADLLAPI * DeviceFreeDevices_Ptr)(SPI_DEVICE_HANDLE_SET hDeviceSet);
typedef int (NETCADLLAPI * DeviceFindDevice_Ptr)(const char *sn,SPI_DEVICE_HANDLE *phDevice);
typedef int (NETCADLLAPI * DeviceGetSerialNumber_Ptr)(SPI_DEVICE_HANDLE hDevice,char *sn,int snlen,int *pretsnlen);
typedef int (NETCADLLAPI * DeviceGetLabel_Ptr)(SPI_DEVICE_HANDLE hDevice,char *label,int labellen,int *pretlabellen);
typedef int (NETCADLLAPI * DeviceVerifyPwd_Ptr)(SPI_DEVICE_HANDLE hDevice,int type,const char *pwd,int *pretrynum);
typedef int (NETCADLLAPI * DeviceChangePwd_Ptr)(SPI_DEVICE_HANDLE hDevice,int type, const char *oldpwd,const char *newpwd,int *pretrynum);
typedef int (NETCADLLAPI * DeviceUnlockPwd_Ptr)(SPI_DEVICE_HANDLE hDevice,int type, const char *sopwd,const char *newpwd,int *pretrynum);
typedef int (NETCADLLAPI * DeviceGetPwdRetryNum_Ptr) (SPI_DEVICE_HANDLE hDevice,int type, int *pretrynum);
typedef int (NETCADLLAPI * DeviceLockDevice_Ptr)(SPI_DEVICE_HANDLE hDevice);
typedef int (NETCADLLAPI * DeviceUnlockDevice_Ptr)(SPI_DEVICE_HANDLE hDevice);
typedef int (NETCADLLAPI * DeviceFreeDevice_Ptr)(SPI_DEVICE_HANDLE hDevice);
typedef int (NETCADLLAPI * DeviceCreateData_Ptr) (SPI_DEVICE_HANDLE hDevice,int dataId, const char *mode,int length);
typedef int (NETCADLLAPI * DeviceReadData_Ptr)(SPI_DEVICE_HANDLE hDevice,int dataId, unsigned char *data,int datalen,int*  pretdatalen);
typedef int (NETCADLLAPI * DeviceWriteData_Ptr)(SPI_DEVICE_HANDLE hDevice,int dataId, const unsigned char *data,int datalen);
typedef int (NETCADLLAPI * DeviceDeleteData_Ptr)(SPI_DEVICE_HANDLE hDevice,int dataId);
typedef int (NETCADLLAPI * DeviceGetKeypairCount_Ptr)(SPI_DEVICE_HANDLE hDevice);
typedef SPI_KEYPAIR_HANDLE (NETCADLLAPI * DeviceGetKeypair_Ptr)(SPI_DEVICE_HANDLE hDevice,int index);
typedef int (NETCADLLAPI * DeviceFindKeypair_Ptr)(SPI_DEVICE_HANDLE hDevice,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);
typedef int (NETCADLLAPI * DeviceFreeKeypair_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceGetKeypairLabel_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,char *label,int labellen,int *pretlabellen);
typedef int (NETCADLLAPI * DeviceGetKeypairType_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceGetKeypairAlgorithm_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceGetKeypairBits_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceGenerateKeypair_Ptr)(SPI_DEVICE_HANDLE hDevice,int algo,int keybits,const void *param,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);
typedef int (NETCADLLAPI * DeviceImportKeypair_Ptr)(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);
typedef int (NETCADLLAPI * DeviceDeleteKeypair_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef SPI_PUBLICKEY_HANDLE (NETCADLLAPI *DeviceGetPublicKeyFromKeypair_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceExportPublicKey_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);
typedef int (NETCADLLAPI * DeviceImportPublicKey_Ptr)(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,SPI_PUBLICKEY_HANDLE *phPublicKey);
typedef int (NETCADLLAPI * DeviceGetPublicKeyBits_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey);
typedef int (NETCADLLAPI * DeviceFreePublicKey_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey);
typedef int (NETCADLLAPI * DeviceGetPublicKeyAlgorithm_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey);
typedef int (NETCADLLAPI * DeviceGetCertificateCount_Ptr)(SPI_KEYPAIR_HANDLE hKeypair);
typedef int (NETCADLLAPI * DeviceGetCertificate_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,int index,unsigned char *certblob,int certbloblen,int *pretcertbloblen);
typedef int (NETCADLLAPI * DeviceDeleteCertificate_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,int index);
typedef int (NETCADLLAPI * DeviceUpdateCertificate_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);
typedef int (NETCADLLAPI * DeviceAddCertificate_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);
typedef int (NETCADLLAPI * DeviceIsSupportedAlgorithm_Ptr)(SPI_DEVICE_HANDLE hDevice,int algo);
typedef int (NETCADLLAPI * DeviceGenerateRandom_Ptr)(SPI_DEVICE_HANDLE hDevice,int len,unsigned char *rand);
typedef SPI_HASH_HANDLE (NETCADLLAPI * DeviceNewHash_Ptr)(SPI_DEVICE_HANDLE hDevice,int algo);
typedef int (NETCADLLAPI *DeviceHashUpdate_Ptr)(SPI_HASH_HANDLE hHash,const unsigned char *data,int datalen);
typedef int (NETCADLLAPI *DeviceHashFinal_Ptr)(SPI_HASH_HANDLE hHash,unsigned char *hashvalue, int hashvaluelen,int *prethashvaluelen);
typedef int (NETCADLLAPI *DeviceFreeHash_Ptr)(SPI_HASH_HANDLE hHash);
typedef SPI_MAC_HANDLE (NETCADLLAPI *DeviceNewMac_Ptr)(SPI_DEVICE_HANDLE hDevice,int algo,const unsigned char *key,int keylen,const void *param);
typedef int (NETCADLLAPI *DeviceMacUpdate_Ptr)(SPI_MAC_HANDLE hMac,const unsigned char *data,int datalen);
typedef int (NETCADLLAPI *DeviceMacFinal_Ptr)(SPI_MAC_HANDLE hMac,unsigned char *macvalue,int macvaluelen,int *pretmacvaluelen);
typedef int (NETCADLLAPI *DeviceFreeMac_Ptr)(SPI_MAC_HANDLE hMac);
typedef SPI_CIPHER_HANDLE (NETCADLLAPI * DeviceNewCipher_Ptr)(SPI_DEVICE_HANDLE hDevice,int enc,int algo,const unsigned char *key,int keylen,const void *param);
typedef int (NETCADLLAPI * DeviceCipherUpdate_Ptr)(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,int inlen,unsigned char *out,int outlen,int *pretoutlen);
typedef int (NETCADLLAPI * DeviceFreeCipher_Ptr)(SPI_CIPHER_HANDLE hCipher);
typedef int (NETCADLLAPI * DeviceSign_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *tbs,int tbslen,unsigned char *sign,int signlen,int *pretsignlen);
typedef int (NETCADLLAPI * DeviceVerify_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *tbs,int tbslen,const unsigned char *sign,int signlen);
typedef int (NETCADLLAPI * DevicePublicKeyEncrypt_Ptr)(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *clear,int clearlen,unsigned char *cipher,int cipherlen,int *pretcipherlen);
typedef int (NETCADLLAPI * DevicePrivateKeyDecrypt_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *cipher,int cipherlen,unsigned char *clear,int clearlen,int *pretclearlen);

typedef int (NETCADLLAPI * DeviceIsSupportedAlgorithm2_Ptr)(SPI_DEVICE_HANDLE hDevice,int algo,int keyLen,int usage,const void *param);

typedef int (NETCADLLAPI * DeviceExportKeypair_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);

typedef int (NETCADLLAPI * DeviceKeyAgreement_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,SPI_PUBLICKEY_HANDLE hRespPublicKey,SPI_KEYPAIR_HANDLE hTempKeypair,SPI_PUBLICKEY_HANDLE hTempRespPublicKey,int algo,void *param,int keyLength,unsigned char *key);

typedef int (NETCADLLAPI *DeviceDuplicateHash_Ptr)(SPI_HASH_HANDLE hHash,SPI_HASH_HANDLE *phNewHash);

typedef int (NETCADLLAPI *DeviceImportKeyAndNewCipher_Ptr)(SPI_KEYPAIR_HANDLE hKeypair,int pubkeyencalgo,const void *pubkeyencparam,const unsigned char *enckey,int enckeylen,int enc,int algo,const void *param,SPI_CIPHER_HANDLE *phCipher);

typedef int (NETCADLLAPI * DeviceReadDataEx_Ptr)(SPI_DEVICE_HANDLE hDevice,int dataId, int offset,unsigned char *data,int datalen,int*  pretdatalen);
typedef int (NETCADLLAPI * DeviceWriteDataEx_Ptr)(SPI_DEVICE_HANDLE hDevice,int dataId, int offset,const unsigned char *data,int datalen);

typedef int (NETCADLLAPI * DeviceCipher_Ptr)(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,long long inlen,unsigned char *out,long long outlen,long long *pretoutlen);

typedef int (NETCADLLAPI *DeviceGetState_Ptr)(SPI_DEVICE_HANDLE hDevice,int *pState);

typedef int (NETCADLLAPI *DeviceFormatDevice_Ptr)(SPI_DEVICE_HANDLE hDevice,const char *soPwd,int soPwdRetryNumer,const char *userPwd,int userPwdRetryNumber);

typedef int (NETCADLLAPI *DeviceNewDevice_Ptr)(SPI_DEVICE_HANDLE hDevice, const char *subDeviceName, const char *soPwd, int soPwdRetryNumer, const char *userPwd, int userPwdRetryNumber, SPI_DEVICE_HANDLE *phDevice2);

typedef int (NETCADLLAPI *DeviceDeleteDevice_Ptr)(SPI_DEVICE_HANDLE hDevice);

typedef int (NETCADLLAPI *DeviceIsSamePhysicalDevice_Ptr)(SPI_DEVICE_HANDLE hDevice1,SPI_DEVICE_HANDLE hDevice2);

#define NETCA_PKI_DEVICE_FUNCTION_CURRENT_VERSION		1

struct NETCA_PKI_Device_FunctionList_st
{
	int m_version;
	DeviceInit_Ptr m_DeviceInit;
	DeviceEnd_Ptr m_DeviceEnd;
	DeviceGetAllDevices_Ptr m_DeviceGetAllDevices;
	DeviceGetDeviceCount_Ptr m_DeviceGetDeviceCount;
	DeviceGetDevice_Ptr m_DeviceGetDevice;
	DeviceFreeDevices_Ptr	m_DeviceFreeDevices;
	DeviceFindDevice_Ptr	m_DeviceFindDevice;
	DeviceGetSerialNumber_Ptr m_DeviceGetSerialNumber;
	DeviceGetLabel_Ptr m_DeviceGetLabel;
	DeviceVerifyPwd_Ptr m_DeviceVerifyPwd;
	DeviceChangePwd_Ptr m_DeviceChangePwd;
	DeviceUnlockPwd_Ptr m_DeviceUnlockPwd;
	DeviceGetPwdRetryNum_Ptr m_DeviceGetPwdRetryNum;
	DeviceLockDevice_Ptr m_DeviceLockDevice;
	DeviceUnlockDevice_Ptr m_DeviceUnlockDevice;
	DeviceFreeDevice_Ptr m_DeviceFreeDevice;
	DeviceCreateData_Ptr m_DeviceCreateData;
	DeviceDeleteData_Ptr m_DeviceDeleteData;
	DeviceGetKeypairCount_Ptr m_DeviceGetKeypairCount;
	DeviceGetKeypair_Ptr m_DeviceGetKeypair;
	DeviceFindKeypair_Ptr m_DeviceFindKeypair;
	DeviceFreeKeypair_Ptr m_DeviceFreeKeypair;
	DeviceGetKeypairLabel_Ptr m_DeviceGetKeypairLabel;
	DeviceGetKeypairType_Ptr m_DeviceGetKeypairType;
	DeviceGetKeypairAlgorithm_Ptr m_DeviceGetKeypairAlgorithm;
	DeviceGetKeypairBits_Ptr m_DeviceGetKeypairBits;
	DeviceGenerateKeypair_Ptr m_DeviceGenerateKeypair;
	DeviceImportKeypair_Ptr m_DeviceImportKeypair;
	DeviceDeleteKeypair_Ptr m_DeviceDeleteKeypair;
	DeviceGetPublicKeyFromKeypair_Ptr m_DeviceGetPublicKeyFromKeypair;
	DeviceExportPublicKey_Ptr m_DeviceExportPublicKey;
	DeviceImportPublicKey_Ptr m_DeviceImportPublicKey;
	DeviceGetPublicKeyBits_Ptr m_DeviceGetPublicKeyBits;
	DeviceFreePublicKey_Ptr m_DeviceFreePublicKey;
	DeviceGetPublicKeyAlgorithm_Ptr m_DeviceGetPublicKeyAlgorithm;
	DeviceGetCertificateCount_Ptr m_DeviceGetCertificateCount;
	DeviceGetCertificate_Ptr m_DeviceGetCertificate;
	DeviceDeleteCertificate_Ptr m_DeviceDeleteCertificate;
	DeviceUpdateCertificate_Ptr m_DeviceUpdateCertificate;
	DeviceAddCertificate_Ptr m_DeviceAddCertificate;
	DeviceGenerateRandom_Ptr m_DeviceGenerateRandom;
	DeviceNewHash_Ptr m_DeviceNewHash;
	DeviceHashUpdate_Ptr m_DeviceHashUpdate;
	DeviceHashFinal_Ptr m_DeviceHashFinal;
	DeviceFreeHash_Ptr m_DeviceFreeHash;
	DeviceNewMac_Ptr m_DeviceNewMac;
	DeviceMacUpdate_Ptr m_DeviceMacUpdate;
	DeviceMacFinal_Ptr m_DeviceMacFinal;
	DeviceFreeMac_Ptr m_DeviceFreeMac;
	DeviceNewCipher_Ptr m_DeviceNewCipher;
	DeviceCipherUpdate_Ptr m_DeviceCipherUpdate;
	DeviceFreeCipher_Ptr m_DeviceFreeCipher;
	DeviceSign_Ptr m_DeviceSign;
	DeviceVerify_Ptr m_DeviceVerify;
	DevicePublicKeyEncrypt_Ptr m_DevicePublicKeyEncrypt;
	DevicePrivateKeyDecrypt_Ptr m_DevicePrivateKeyDecrypt;
	DeviceIsSupportedAlgorithm2_Ptr m_DeviceIsSupportedAlgorithm2;
	DeviceExportKeypair_Ptr m_DeviceExportKeypair;
	DeviceKeyAgreement_Ptr m_DeviceKeyAgreement;
	DeviceDuplicateHash_Ptr m_DeviceDuplicateHash;
	DeviceImportKeyAndNewCipher_Ptr m_DeviceImportKeyAndNewCipher;
	DeviceReadDataEx_Ptr m_DeviceReadDataEx;
	DeviceWriteDataEx_Ptr m_DeviceWriteDataEx;
	DeviceCipher_Ptr m_DeviceCipher;
	DeviceGetState_Ptr m_DeviceGetState;
	DeviceFormatDevice_Ptr m_DeviceFormatDevice;
	DeviceNewDevice_Ptr m_DeviceNewDevice;
	DeviceDeleteDevice_Ptr m_DeviceDeleteDevice;
	DeviceIsSamePhysicalDevice_Ptr m_DeviceIsSamePhysicalDevice;
};

typedef struct NETCA_PKI_Device_FunctionList_st* NETCA_PKI_Device_FunctionList_Ptr;
/*
 *	DeviceGetFunctionList
 *		获取函数列表。
 *	参数：
 *		functionList：输出参数，返回函数列表
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceGetFunctionList(NETCA_PKI_Device_FunctionList_Ptr functionList);

typedef int (NETCADLLAPI* DeviceGetFunctionList_Ptr)(NETCA_PKI_Device_FunctionList_Ptr functionList);


#ifdef __cplusplus
	}	
#endif
#endif
