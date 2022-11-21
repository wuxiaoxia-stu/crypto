#ifndef _NETCA_PKI_CRYPTO_INLCUDE_H_
#define _NETCA_PKI_CRYPTO_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif




/* �����豸�������������㺯�� */

/*
 *	NetcaPKICryptoGetAllDevices 
 *		��ȡ���ӵ��豸
 *	������
 *		type������������豸������ͣ�NETCA_PKI_DEVICE_TYPE_ANY��ʾҪ��ȡ���е��豸
 *		flag������������豸�ı�־��NETCA_PKI_DEVICE_FLAG_SILENT��λ��ʾ�豸������������κ�UI�ӿڡ���1��2λ��ֵ����ĩλ��0����ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS��ʾ��PIN�뻺�������������У�ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE��ʾֻ���豸���������PIN�롣 ΪNETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN��ʾ�Ӳ�Cache PIN�롣���� PIN��ֻ��USB KEY��Ч
 *	����ֵ��
 *		�ɹ�������Ч���豸�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetAllDevices(int type,int flag);


/*
 *	NetcaPKICryptoGetAllDevicesEx 
 *		��ȡ���ӵ��豸
 *	������
 *		types������������豸����������飬���ܰ���NETCA_PKI_DEVICE_TYPE_ANY
 *		count������������豸������͸���
 *		flag������������豸�ı�־��NETCA_PKI_DEVICE_FLAG_SILENT��λ��ʾ�豸������������κ�UI�ӿڡ���1��2λ��ֵ����ĩλ��0����ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS��ʾ��PIN�뻺�������������У�ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE��ʾֻ���豸���������PIN�롣 ΪNETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN��ʾ�Ӳ�Cache PIN�롣���� PIN��ֻ��USB KEY��Ч
 *	����ֵ��
 *		�ɹ�������Ч���豸�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetAllDevicesEx(const int *types,int count,int flag);

/*
 *	NetcaPKICryptoGetUSBDevices 
 *		��ȡ���ӵ�USB�豸
 *	������
 *		vid�����������VID
 *		pid�����������PID
 *		flag������������豸�ı�־��NETCA_PKI_DEVICE_FLAG_SILENT��λ��ʾ�豸������������κ�UI�ӿڡ���1��2λ��ֵ����ĩλ��0����ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_PROCESS��ʾ��PIN�뻺�������������У�ΪNETCA_PKI_DEVICE_FLAG_CACHE_PIN_IN_HANDLE��ʾֻ���豸���������PIN�롣 ΪNETCA_PKI_DEVICE_FLAG_NOT_CACHE_PIN��ʾ�Ӳ�Cache PIN�롣���� PIN��ֻ��USB KEY��Ч
 *	����ֵ��
 *		�ɹ�������Ч���豸�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE_SET NETCADLLAPI NetcaPKICryptoGetUSBDevices(int vid,int pid,int flag);

/*
 *	NetcaPKICryptoGetDeviceCount
 *		��ȡ�豸�����豸�ĸ���
 *	������
 *		hDeviceSet���豸�����
 *	����ֵ��
 *		�ɹ������豸�����豸�ĸ�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDeviceCount(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	NetcaPKICryptoGetDevice
 *		��ȡ�豸���е��豸
 *	������
 *		hDeviceSet���豸�����
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ������豸���е�index���豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDevice(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet,int index);

/*
 *	NetcaPKICryptoFreeDevices
 *		�ͷ��豸��
 *	������
 *		hDeviceSet���豸�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeDevices(NETCA_PKI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	NetcaPKICryptoFindDevice
 *		�����豸���ͺ����кŻ�ȡ�豸���
 *	������
 *		type������������豸����
 *		sn������������豸���кţ�ASCII����
 *		flag�������������־����NetcaPKICryptoGetAllDevices��˵��
 *		phDevice������������ɹ����ص�ǰ���ӵ�����Ϊtype�����к�Ϊsn���豸���豸�����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoFindDevice(int type,const char *sn,int flag, NETCA_PKI_DEVICE_HANDLE *phDevice);

/*
 *	NetcaPKICryptoGetType
 *		��ȡ�豸������
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ������豸�����ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetType(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoGetSerialNumber
 *		��ȡ�豸�����кš��ɹ����ص����к�Ҫʹ��NetcaPKICryptoFreeMemory���ͷ�
 *	������
 *		hDevice���豸���
 *		sn����������������豸���кţ�ASCII����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGetSerialNumber(NETCA_PKI_DEVICE_HANDLE hDevice,char **sn);


/*
 *	NetcaPKICryptoGetLabel
 *		��ȡ�豸�ľ�ꡣ�ɹ����صľ��Ҫʹ��NetcaPKICryptoFreeMemory���ͷ�
 *	������
 *		hDevice���豸���
 *		label����������������豸�ľ�꣬UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetLabel(NETCA_PKI_DEVICE_HANDLE hDevice,char **label);


/*
 *	NetcaPKICryptoGetClass
 *		��ȡ�豸�����
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetClass(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoIsImportOnlyEncryptKeyPair
 *		�ж��豸���Ƿ�ֻ֧�ֵ�����ܵ���Կ��
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		֧�ַ���1����֧�ַ���0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsImportOnlyEncryptKeyPair(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoIsSamePhysicalDevice
 *		�ж��Ƿ�ͬһ�����豸
 *	������
 *		hDevice1���豸���1
 *	    hDevice2���豸���2
 *	����ֵ��
 *		�Ƿ���1���񷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsSamePhysicalDevice(NETCA_PKI_DEVICE_HANDLE hDevice1,NETCA_PKI_DEVICE_HANDLE hDevice2);


/*
 *	NetcaPKICryptoGetUsbInfo
 *		��ȡUSB�豸��VID��PID
 *	������
 *		hDevice���豸���
 *		vid��������������ص�VID
 *		pid��������������ص�PID
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetUsbInfo(NETCA_PKI_DEVICE_HANDLE hDevice,int *vid,int *pid);

/*
 *	NetcaPKICryptoGetUsbInfo
 *		����USB�豸��VID��PID����ȡ֧���豸����
 *	������
 *		vid��������������ص�VID
 *		pid��������������ص�PID
 *		types��������������ص��豸��������
 *		count��������������ص��豸���͸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetTypeFromUsbInfo(int vid,int pid,int **types,int *count);


/*
 *	NetcaPKICryptoGetAllTypes
 *		��ȡ����֧�ֵ��豸����
 *	������
 *		types��������������ص��豸��������
 *		count��������������ص��豸���͸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetAllTypes(int **types,int *count);


/*
 *	NetcaPKICryptoGetClassFromType
 *		�����豸���ͻ�ȡ�豸�����
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetClassFromType(int type);

/*
 *	NetcaPKICryptoGetNameFromType
 *		�����豸���ͻ�ȡ�豸������
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�ɹ������豸������(UTF-8����)��ʧ�ܷ���NULL
 *
 */
char *NETCADLLAPI NetcaPKICryptoGetNameFromType(int type);


/*
 *	NetcaPKICryptoGetDisplayNameFromType
 *		�����豸���ͻ�ȡ�豸����ʾ����
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�ɹ������豸����ʾ����(UTF-8����)��ʧ�ܷ���NULL
 *
 */
char *NETCADLLAPI NetcaPKICryptoGetDisplayNameFromType(int type);

/*
 *	NetcaPKICryptoIsMultiDevice
 *		�ж��Ƿ�ӳ��Ϊ����豸�����ͣ�����Կ�Ա�ǩ�����к��а���
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�����ӳ��Ϊ����豸�����ͷ���1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsMultiDeviceType(int type);


/*
 *	NetcaPKICryptoIsServerType
 *		�ж��Ƿ��������������
 *	������
 *		type������������豸����
 *	����ֵ��
 *		����ǿ�����������������1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsServerType(int type);

/*
 *	NetcaPKICryptoGetUsbInfoFromType
 *		�����豸���ͻ�ȡUSB�豸��VID��PID
 *	������
 *		type���豸����
 *		vid��������������ص�VID����
 *		pid��������������ص�PID����
 *		count�������������Ӧ������Ԫ�ظ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetUsbInfoFromType(int type,int **vid,int **pid,int *count);

/*
 *	NetcaPKICryptoDeviceMustLogin
 *		�жϼ����豸�Ƿ������֤�û��������ʹ��
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		����Ǳ���ɹ���֤�û��������ʹ�÷���1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoDeviceMustLogin(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoVerifyPwd
 *		��֤�豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա����
 *		pwd��������������룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyPwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *pwd,int *pretrynum);


/*
 *	NetcaPKICryptoChangePwd
 *		�޸��豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա����
 *		oldpwd������������ɵ����룬ASCII����
 *		newpwd������������µ����룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoChangePwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type, const char *oldpwd,const char *newpwd,int *pretrynum);


/*
 *	NetcaPKICryptoUnlockPwd
 *		�����豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ���ǰ�汾ֻ����NETCA_PKI_USER_PWD��ʾ�û�����
 *		sopwd���������������Ա�����룬ASCII����
 *		newpwd������������µ��û����룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoUnlockPwd(NETCA_PKI_DEVICE_HANDLE hDevice,int type, const char *sopwd,const char *newpwd,int *pretrynum);


/*
 *	NetcaPKICryptoGetPwdRetryNum
 *		��ȡ�豸���������Դ���
 *	������
 *		hDevice���豸���
 *		type������������������ͣ���ǰ�汾ֻ����NETCA_PKI_USER_PWD��ʾ�û�����
 *		pretrynum������������ɹ��������뻹�������ԵĴ�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ַ���NETCA_PKI_UNSUPPORTED
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPwdRetryNum(NETCA_PKI_DEVICE_HANDLE hDevice,int type, int *pretrynum);


/*
 *	NetcaPKICryptoSetCachePwdSecond
 *		���û����û������ʱ�䣬����Ϊ��λ
 *	������
 *		hDevice���豸���,NULLΪȫ������
 *		second��������������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetCachePwdSecond(NETCA_PKI_DEVICE_HANDLE hDevice,int second);

/*
 *	NetcaPKICryptoClearPwdCache
 *		����û����뻺��
 *	������
 *		hDevice���豸���,NULLΪȫ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoClearPwdCache(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoDupDevice
 *		�����豸���
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ����ظ��ƺ��豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoDupDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoFreeDevice
 *		�ͷ��豸���
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeDevice(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoLockDevice
 *		���豸����
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoLockDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoUnlockDevice
 *		���豸����
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoUnlockDevice(NETCA_PKI_DEVICE_HANDLE hDevice);


/*
 *	NetcaPKICryptoGetPseudoDevice
 *		����һ��α�豸�����������ֻ�����ʵ�ֵļӽ��ܹ��ܣ���û��������ص��豸���ܡ���ʵ�ϣ��������������κ�ʵ�ʵ��豸��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����һ��α�豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetPseudoDevice(void);
/*
 *	NetcaPKICryptoClearPseudoDevice
 *		���α�豸���˽Կ��Ϣ
 *	������
 *		hDevice��α�豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoClearPseudoDevice(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoCreateData
 *		���豸�д���һ��־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		mode������������־����ݵ�Ȩ��
 *		length������������־����ݵ���󳤶�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL������־������Ѿ����ڣ�����NETCA_PKI_EXISIT�����ûȨ�޴����־����ݣ�����NETCA_PKI_ ACCESSDENIED�������֧��ָ����ʶ�ĳ־����ݣ�����NETCA_PKI_UNSUPPORTED
 *
 */
int NETCADLLAPI NetcaPKICryptoCreateData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, const char *mode,int length);

/*
 *	NetcaPKICryptoGetDataLength
 *		��ȡ�־����ݵĳ���
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		plen��������������س־����ݵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ACCESSDENIED��
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDataLength(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, int* plen);


/*
 *	NetcaPKICryptoReadData
 *		���־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		data��������������ض��������ݣ�����ΪNULL
 *		datalen�����������data�ĳ���
 *		pretdatalen��������������ض����ĳ־����ݵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ACCESSDENIED��
 *
 */
int NETCADLLAPI NetcaPKICryptoReadData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	NetcaPKICryptoReadDataEx
 *		���־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		offset���������,�־����ݵ�λ��
 *		data��������������ض��������ݣ�����ΪNULL
 *		datalen�����������data�ĳ���
 *		pretdatalen��������������ض����ĳ־����ݵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ACCESSDENIED��
 *
 */
int NETCADLLAPI NetcaPKICryptoReadDataEx(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId,int offset,unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	NetcaPKICryptoWriteData
 *		д�־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		data�����������Ҫд�������
 *		datalen�����������data�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ACCESSDENIED��
 *
 */
int NETCADLLAPI NetcaPKICryptoWriteData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoWriteDataEx
 *		д�־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		offset������������־����ݵ�λ��
 *		data�����������Ҫд�������
 *		datalen�����������data�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ACCESSDENIED��
 *
 */
int NETCADLLAPI NetcaPKICryptoWriteDataEx(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId, int offset,const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoDeleteData
 *		ɾ���־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ��ɾ���־����ݣ�����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoDeleteData(NETCA_PKI_DEVICE_HANDLE hDevice,int dataId);

/*
 *	NetcaPKICryptoGetKeypairCount
 *		��ȡ�豸����Կ������
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ������豸����Կ��������ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairCount(NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKICryptoGetKeypair
 *		��ȡ�豸�е���Կ��
 *	������
 *		hDevice���豸���
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ������豸�е�index����Կ�ԣ�ʧ�ܷ���NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICryptoGetKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int index);

/*
 *	NetcaPKICryptoInstallCertificate
 *		��װ֤��
 *	������
 *		hDevice���豸���
 *		type��������������ܹ��ļ�����Կ�Ե�����
 *		encKeypair:������������ܹ��ļ�����Կ�Եı���ֵ
 *		encKeypairLen:������������ܹ��ļ�����Կ�Եı೤��
 *		encCert:����֤��
 *		signCert��ǩ��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoInstallCertificate(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const unsigned char *encKeypair,int encKeypairLen,NETCA_PKI_CERTIFICATE_HANDLE encCert,NETCA_PKI_CERTIFICATE_HANDLE signCert);


/*
 *	NetcaPKICryptoDupKeypair
 *		������Կ�Ծ��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ����ظ��ƺ����Կ�ԣ�ʧ�ܷ���NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICryptoDupKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoFindKeypair
 *		������Կ�Ե����ͺͱ�ǩ����ȡ�豸�е���Կ��
 *	������
 *		hDevice���豸���
 *		type�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ������豸��ָ������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoFindKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);


/*
 *	NetcaPKICryptoFindKeypairEx
 *		������Կ�Ե����ͺͱ�ǩ����ȡ�豸�е���Կ��
 *	������
 *		deviceType������������豸����
 *		sn������������豸�����к�
 *		flag:����������豸�ı�־
 *		pwd������������豸������
 *		keypairType�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ������豸��ָ������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoFindKeypairEx(int deviceType,const char *sn,int flag,const char *pwd,int keypairType,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);


/*
 *	NetcaPKICryptoFreeKeypair
 *		�ͷ���Կ�Ծ��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

#ifdef _WIN32
#include <windows.h>
#include <wincrypt.h>
/*
 *	NetcaPKIGetKeypairMSProvInfo
 *		��ȡ��Կ�Զ�Ӧ��CSP��Ϣ
 *	������
 *		hKeypair����Կ�Ծ��
 *		pinfo�����������CSP��Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIGetKeypairMSProvInfo(NETCA_PKI_KEYPAIR_HANDLE hKeypair, PCRYPT_KEY_PROV_INFO pinfo);
#endif

/*
 *	NetcaPKICryptoGetKeypairLabel
 *		��ȡ��Կ�Եı�ǩ���ɹ���ȡ�ı�ǩҪʹ��NetcaPKICryptoFreeMemory���ͷ�
 *	������
 *		hKeypair����Կ�Ծ��
 *		label��������������ص���Կ�Եı�ǩ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairLabel(NETCA_PKI_KEYPAIR_HANDLE hKeypair,char **label);



/*
 *	NetcaPKICryptoGetKeypairType
 *		��ȡ��Կ�Ե�����
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե����ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairType(NETCA_PKI_KEYPAIR_HANDLE hKeypair);



/*
 *	NetcaPKICryptoGetKeypairAlgorithm
 *		��ȡ��Կ�Ե��㷨
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե��㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairAlgorithm(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGetKeypairBits
 *		��ȡ��Կ�Եĳ��ȣ���λΪ��λ
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե�λ����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairBits(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetKeypairECCCurve
 *		��ȡ��Կ�Ե���Բ���ߺ�
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե���Բ���ߺţ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetKeypairECCCurve(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoIsTemporaryKeypair
 *		�ж���Կ���Ƿ���ʱ��Կ��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		����ǣ�����1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoIsTemporaryKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGenerateKeypair
 *		������Կ��
 *	������
 *		hDevice���豸���
 *		algo�������������Կ�Ե��㷨
 *		keybits�������������Կ�Եĳ���
 *		param�����������������Կ����Ҫ�Ĳ���������RSA�㷨������ΪNULL��
 *		type�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ����ز�������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵ��㷨����NETCA_PKI_UNSUPPORTED�����ûȨ�޲�����Կ�ԣ�����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keybits,const void *param,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);

/*
 *	NetcaPKICryptoImportKeypair
 *		������Կ�Ե��豸��ȥ
 *	������
 *		hDevice���豸���
 *		keyblob�������������Կ�Եı���
 *	 	keybloblen�������������Կ�Եı���ĳ���
 *	 	type�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ����ز�������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ַ���NETCA_PKI_UNSUPPORTED�����ûȨ�޵�����Կ�ԣ�����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoImportKeypair(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,int type,const char *label, NETCA_PKI_KEYPAIR_HANDLE *phKeypair);

/*
 *	NetcaPKICryptoExportKeypair
 *		������Կ��
 *	������
 *		hKeypair����Կ�Ծ��
 *		keyblob�����������������Կ�Եı���
 *		pretkeybloblen�����������������Կ�Եĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��
 */
int NETCADLLAPI NetcaPKICryptoExportKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair,unsigned char **keyblob, int* pretkeybloblen);

/*
 *	NetcaPKICryptoDeleteKeypair 
 *		���豸��ɾ����Կ�Լ�����ص�֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�����ûȨ��ɾ����Կ�ԣ�����NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoDeleteKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetDeviceHandleFromKeypair 
 *		��ȡ��Կ����ص��豸���
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���NULL
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICryptoGetPublicKeyFromKeypair
 *		��ȡ��Կ�ԵĹ�Կ���
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�ԵĹ�Կ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICryptoGetPublicKeyFromKeypair(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoExportPublicKey
 *		������Կ
 *	������
 *		hPublicKey����Կ���
 *		keyblob��������������ع�Կ�ı���
 *		pretkeybloblen��������������ص�����Կ�ĳ��ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵĹ�Կ����NETCA_PKI_ UNSUPPORTED��
 *
 */
int NETCADLLAPI NetcaPKICryptoExportPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,unsigned char **keyblob, int* pretkeybloblen);

/*
 *	NetcaPKICryptoGetSubjectPublicKeyInfoEncode
 *		��ȡ��Կ��SubjectPublicKeyInfo��DER����
 *	������
 *		hPublicKey����Կ���
 *		encode���������������SubjectPublicKeyInfo�ı���
 *		pencodeLen���������������SubjectPublicKeyInfo�ĳ��ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 *
 */
int NETCADLLAPI NetcaPKICryptoGetSubjectPublicKeyInfoEncode(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,unsigned char **encode, int* pencodeLen);

/*
 *	NetcaPKICryptoImportPublicKeyFromSubjectPublicKeyInfo
 *		����SubjectPublicKeyInfo��DER���뵼�빫Կ
 *	������
 *		hDevice���豸���
 *		encode�����������SubjectPublicKeyInfo�ı���
 *		encodeLen�����������SubjectPublicKeyInfo�ĳ��ȡ�
 *		phPublicKey��������������صĹ�Կ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 *
 */
int NETCADLLAPI NetcaPKICryptoImportPublicKeyFromSubjectPublicKeyInfo(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *encode, int encodeLen,NETCA_PKI_PUBLICKEY_HANDLE *phPublicKey);


/*
 *	NetcaPKICryptoImportPublicKey
 *		������ʱ�Ĺ�Կ
 *	������
 *		hDevice���豸���
 *		keyblob�������������Կ�ı���
 *		keybloblen�������������Կ�ı���ĳ��ȡ�
 *		phPublicKey������������ɹ�������ʱ�Ĺ�Կ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵĹ�Կ����NETCA_PKI_ UNSUPPORTED��
 *
 */
int NETCADLLAPI NetcaPKICryptoImportPublicKey(NETCA_PKI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen, NETCA_PKI_PUBLICKEY_HANDLE *phPublicKey);


/*
 *	NetcaPKICryptoGetPublicKeyBits
 *		��ȡ��Կ�ĳ��ȣ���λΪ��λ
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ع�Կ��λ����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyBits(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoGetPublicKeyECCCurve
 *		��ȡ��Կ����Բ���ߺ�
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ع�Կ����Բ���ߺţ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyECCCurve(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	NetcaPKICryptoGetPublicKeyAlgorithm
 *		��ȡ��Կ���㷨
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ع�Կ���㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetPublicKeyAlgorithm(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	NetcaPKICryptoDupPublicKey
 *		���ƹ�Կ���
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ظ��ƺ�Կ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICryptoDupPublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoFreePublicKey
 *		�ͷŹ�Կ���
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoFreePublicKey(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKICryptoPublicKeyEqual
 *		�Ƚ�������Կ���
 *	������
 *		hPublicKey1��Ҫ�ȽϵĹ�Կ���1
 *		hPublicKey2��Ҫ�ȽϵĹ�Կ���2
 *	����ֵ��
 *		�����Ĺ�Կ��ͬ����1����ͬ����0
 *
 */
int NETCADLLAPI NetcaPKICryptoPublicKeyEqual(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey1,NETCA_PKI_PUBLICKEY_HANDLE hPublicKey2);


/*
 *	NetcaPKICryptoGetCertificateCount
 *		��ȡ��Կ����ص�֤�����
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ����ص�֤�������ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCertificateCount(NETCA_PKI_KEYPAIR_HANDLE hKeypair);


/*
 *	NetcaPKICryptoGetCertificate
 *		��ȡ��Կ����صĵ�index��֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		index����������������ţ���0����
 *		pcert��������������ص�index��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int index, NETCA_PKI_CERTIFICATE_HANDLE *pcert);

/*
 *	NetcaPKICryptoDeleteCertificate
 *		ɾ����Կ����صĵ�index��֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��ɾ��֤�飬����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoDeleteCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int index);



/*
 *	NetcaPKICryptoUpdateCertificate
 *		��֤��д���豸������Կ������������������ɾ����ǰ����Կ�Թ�����֤�顣
 *	������
 *		hKeypair����Կ�Ծ��
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��д֤�飬����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoUpdateCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoAddCertificate
 *		��֤��д���豸������Կ�����������������ᱣ����ǰ����Կ�Թ�����֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��д֤�飬����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI NetcaPKICryptoAddCertificate(NETCA_PKI_KEYPAIR_HANDLE hKeypair, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoIsSupportedAlgorithm
 *		ѯ���豸�Ƿ�֧��ĳ���㷨��
 *	������
 *		hDevice���豸���
 *		algo������������㷨
 *		keyBits�������������Կ���ȣ���λΪ��λ
 *		usage������������㷨����;��������ܽ���֮��
 *		param������������㷨��صĲ���
 *		
 *	����ֵ��
 *		���֧�ַ���1����֧�ַ���0��
 */
int NETCADLLAPI NetcaPKICryptoIsSupportedAlgorithm(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keyBits,int usage,const void *param);

/*
 *	NetcaPKICryptoGenerateRandom
 *		��ȡ�����
 *	������
 *		hDevice���豸���������ΪNULL
 *		len��������������������
 *		rand��������������ص����������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateRandom(NETCA_PKI_DEVICE_HANDLE hDevice,int len,unsigned char *rand);

/*
 *	NetcaPKICryptoAddRandomSeed
 *		��������������������
 *	������
 *		seed���������������
 *		seedLen��������������ӳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoAddRandomSeed(const unsigned char *seed,int seedLen);

/*
 *	NetcaPKICryptoGenerateKey
 *		�����Գ���Կ
 *	������
 *		hDevice���豸���
 *		algo���ԳƼ����㷨
 *		keyLen�������������Կ���ȣ����ֽ�Ϊ��λ
 *		key��������������صĶԳ���Կ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGenerateKey(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,int keyLen,unsigned char *key);



/*
 *	NetcaPKICryptoNewHash
 *		����Hash���������豸���û��ʵ�ָ�Hash�㷨�����Ҹ�Hash�㷨���������ʵ�ֵģ���ʹ�����ʵ�֡�
 *	������
 *		hDevice���豸���
 *		algo�����������Hash�㷨
 *	����ֵ��
 *		�ɹ�����Hash�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_HASH_HANDLE NETCADLLAPI NetcaPKICryptoNewHash(NETCA_PKI_DEVICE_HANDLE hDevice,int algo);

/*
 *	NetcaPKICryptoGetHashHandle
 *		�������õ���Ϣ����ȡHash�����
 *	������
 *		algo�����������Hash�㷨
 *	����ֵ��
 *		�ɹ�����Hash�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_HASH_HANDLE NETCADLLAPI NetcaPKICryptoGetHashHandle(int algo);

/*
 *	NetcaPKICryptoGetHashLength
 *		��ȡHashֵ�ĳ���
 *	������
 *		hHash��Hash���
 *	����ֵ��
 *		�ɹ�����Hashֵ�ĳ��ȣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHashLength(NETCA_PKI_HASH_HANDLE hHash);


/*
 *	NetcaPKICryptoGetHashAlgorithm
 *		��ȡHash�㷨
 *	������
 *		hHash��Hash���
 *	����ֵ��
 *		�ɹ�����Hash�㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHashAlgorithm(NETCA_PKI_HASH_HANDLE hHash);

/*
 *	NetcaPKICryptoGetDeviceHandleFromHash
 *		��ȡHash�����Ӧ���豸���
 *	������
 *		hHash��Hash���
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromHash(NETCA_PKI_HASH_HANDLE hHash);


/*
 *	NetcaPKICryptoHashUpdate
 *		����Hash����
 *	������
 *		hHash��Hash���
 *		data���������������
 *		datalen�����������data�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoHashUpdate(NETCA_PKI_HASH_HANDLE hHash,const unsigned char *data,int datalen);

/*
 *	NetcaPKICryptoHashFinal
 *		����Hash���㣬��ȡHashֵ��
 *	������
 *		hHash��Hash���
 *		hashvalue��������������ص�Hashֵ
 *		prethashvaluelen���������������Hashֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoHashFinal(NETCA_PKI_HASH_HANDLE hHash,unsigned char **hashvalue, int *prethashvaluelen);


/*
 *	NetcaPKICryptoHashFinal
 *		�ͷ�Hash�����
 *	������
 *		hHash��Hash���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeHash(NETCA_PKI_HASH_HANDLE hHash);

/*
 *	NetcaPKICryptoDuplicateHash
 *		����Hash�����
 *	������
 *		hHash��Ҫ���Ƶ�Hash���
 *		phNewHash��������������ظ��Ƶõ���Hash���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 */
int NETCADLLAPI NetcaPKICryptoDuplicateHash(NETCA_PKI_HASH_HANDLE hHash,NETCA_PKI_HASH_HANDLE *phNewHash);

/*
 *	NetcaPKICryptoNewMac
 *		����MAC���������豸û��ʵ��ĳ�ֿ��������ʵ�ֵ��㷨����ʹ�����ʵ��
 *	������
 *		hDevice���豸���
 *		algo�����������Mac�㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param�����������Mac�㷨�Ĳ�������ӦHMAC��˵��ΪNULL
 *	����ֵ��
 *		�ɹ�����MAC�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MAC_HANDLE NETCADLLAPI NetcaPKICryptoNewMac(NETCA_PKI_DEVICE_HANDLE hDevice,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	NetcaPKICryptoGetMacHandle
 *		�������õ���Ϣ����ȡMac�����
 *	������
 *		algo�����������Mac�㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param�����������Mac�㷨�Ĳ�������ӦHMAC��˵��ΪNULL
 *	����ֵ��
 *		�ɹ�����MAC�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MAC_HANDLE NETCADLLAPI NetcaPKICryptoGetMacHandle(int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	NetcaPKICryptoGetMacLength
 *		��ȡMac�ĳ��ȡ�
 *	������
 *		hMac��Mac���
 *	����ֵ��
 *		�ɹ�����Mac�ĳ��ȣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetMacLength(NETCA_PKI_MAC_HANDLE hMac);


/*
 *	NetcaPKICryptoGetMacAlgorithm
 *		��ȡMac�㷨��
 *	������
 *		hMac��Mac���
 *	����ֵ��
 *		�ɹ�����Mac�㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetMacAlgorithm(NETCA_PKI_MAC_HANDLE hMac);

/*
 *	NetcaPKICryptoGetDeviceHandleFromMac
 *		��ȡMac�����Ӧ���豸���
 *	������
 *		hMac��Mac���
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromMac(NETCA_PKI_MAC_HANDLE hMac);

/*
 *	NetcaPKICryptoMacUpdate
 *		Mac���ݣ�����������Զ�ε��á�
 *	������
 *		hMac��Mac���
 *		data�����������Ҫ����Mac���������
 *		datalen�����������data���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoMacUpdate(NETCA_PKI_MAC_HANDLE hMac,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoMacFinal
 *		����Mac���㣬��ȡMacֵ��
 *	������
 *		hMac��Mac���
 *		macvalue��������������ص�Macֵ
 *		retmacvaluelen���������������MAC�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoMacFinal(NETCA_PKI_MAC_HANDLE hMac,unsigned char **macvalue,int  *pretmacvaluelen);

/*
 *	NetcaPKICryptoFreeMac
 *		�ͷ�Mac�����
 *	������
 *		hMac��Mac���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeMac(NETCA_PKI_MAC_HANDLE hMac);


/*
 *	NetcaPKICryptoNewCipher
 *		�����ӽ��ܾ������������������˵��paramΪNULL������ECBģʽ��RC2�㷨��˵��paramΪint *����ʾ��Ч��Կλ�����������������ECBģʽ��paramΪNULL������ECBģʽ��RC2�㷨��˵��paramΪstruct NETCA_PKI_RC2CBCParam_st*��������Ϊunsigned char *����ʾIV��IV�ĳ����Ƿ��鳤�ȡ�
 *	������
 *		hDevice���豸���
 *		enc�����������1����ܣ�0��ʾ����
 *		algo����������������㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param������������ӽ��ܵĲ���
 *	����ֵ��
 *		�ɹ����ش����ӽ��ܾ����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CIPHER_HANDLE NETCADLLAPI NetcaPKICryptoNewCipher(NETCA_PKI_DEVICE_HANDLE hDevice,int enc,int algo,const unsigned char *key,int keylen,const void *param);


/*
 *	DeviceNewCipher
 *		���ܶԳ���Կ�����ӽ��ܾ��
 *	������
 *		hKeypair����Կ�Ծ��
 *		pubkeyencalgo�������������Կ�����㷨
 *		pubkeyencparam�������������Կ���ܲ���
 *		enckey:�����������Կ���ܵĶԳ���Կ
 *		enckeylen�������������Կ���ܵĶԳ���Կ�ĳ���
 *		enc�����������1����ܣ�0��ʾ����
 *		algo������������ԳƼ����㷨
 *		param������������ԳƼӽ��ܵĲ���
 *		phCipher:����������ɹ����ش����ļӽ��ܾ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ�޽��ܣ�����NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoImportKeyAndNewCipher(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int pubkeyencalgo,const void *pubkeyencparam,const unsigned char *enckey,int enckeylen,int enc,int algo,const void *param,NETCA_PKI_CIPHER_HANDLE *phCipher);

/*
 *	NetcaPKICryptoGetCipherHandle
 *		�������õ���Ϣ����ȡ�ӽ��ܾ����
 *	������
 *		enc�����������1����ܣ�0��ʾ����
 *		algo����������������㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param������������ӽ��ܵĲ���
 *	����ֵ��
 *		�ɹ����ش����ӽ��ܾ����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CIPHER_HANDLE NETCADLLAPI NetcaPKICryptoGetCipherHandle(int enc,int algo,const unsigned char *key,int keylen,const void *param);


/*
 *	NetcaPKICryptoGetCipherAlgorithm
 *		��ȡ�����㷨
 *	������
 *		hCipher���ӽ��ܾ��
 *	����ֵ��
 *		�ɹ����ؼ����㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICryptoGetCipherAlgorithm(NETCA_PKI_CIPHER_HANDLE hCipher);

/*
 *	NetcaPKICryptoGetDeviceHandleFromCipher
 *		��ȡ�ӽ��ܾ����Ӧ���豸���
 *	������
 *		hCipher���ӽ��ܾ��
 *	����ֵ��
 *		�ɹ������豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDeviceHandleFromCipher(NETCA_PKI_CIPHER_HANDLE hCipher);

/*
 *	NetcaPKICryptoCipherUpdate
 *		�ӽ������ݣ�����������Զ�ε��á�
 *	������
 *		hCipher���ӽ��ܾ��
 *		in�������������������
 *		inlen�����������in���ֽ���
 *		out��������������ص�����
 *		pretoutlen���������������������ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherUpdate(NETCA_PKI_CIPHER_HANDLE hCipher,const unsigned char *in,int inlen,unsigned char **out,int *pretoutlen);


/*
 *	NetcaPKICryptoCipherFinal
 *		�����ӽ��ܡ�
 *	������
 *		hCipher���ӽ��ܾ��
 *		remdata��������������ص�����
 *		pretremdatalen���������������������ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherFinal(NETCA_PKI_CIPHER_HANDLE hCipher,unsigned char **remdata,int *pretremdatalen);

/*
 *	NetcaPKICryptoFreeCipher
 *		�ͷżӽ��ܾ����
 *	������
 *		hCipher���ӽ��ܾ��
 *		
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeCipher(NETCA_PKI_CIPHER_HANDLE hCipher);


/*
 *	NetcaPKICryptoCipherSetPadding
 *		���÷�����ܵ����ģʽ��
 *	������
 *		hCipher���ӽ��ܾ��
 *		padding��������������ģʽ
 *		
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoCipherSetPadding(NETCA_PKI_CIPHER_HANDLE hCipher,int padding);

/*
 *	NetcaPKICryptoNewSign
 *		����ǩ�������
 *	������
 *		hKeypair����Կ�Ծ��
 *		algo�����������ǩ���㷨
 *		param�����������ǩ������
 *	����ֵ��
 *		�ɹ�����ǩ�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_SIGN_HANDLE NETCADLLAPI NetcaPKICryptoNewSign(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param);


/*
 *	NetcaPKICryptoSignUpdate
 *		����ǩ������������Hash���㣬����������Ե��ö��
 *	������
 *		hSign��ǩ�����
 *		data���������������
 *		datalen��������������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignUpdate(NETCA_PKI_SIGN_HANDLE hSign,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoSignFinal
 *		����˽Կ��������ǩ��
 *	������
 *		hSign��ǩ�����
 *		sign��������������ص�ǩ��ֵ
 *		psignlen���������������sign�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignFinal(NETCA_PKI_SIGN_HANDLE hSign,unsigned char **sign,int *psignlen);


/*
 *	NetcaPKICryptoFreeSign
 *		�ͷ�ǩ�������
 *	������
 *		hSign��ǩ�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeSign(NETCA_PKI_SIGN_HANDLE hSign);



/*
 *	NetcaPKICryptoSignHash
 *		ǩ����������Hashֵ
 *	������
 *		hKeypair����Կ�Ծ��
 *		algo�����������ǩ���㷨
 *		param���������������
 *		hash�����������Hashֵ
 *		hashlen��Hashֵ�ĳ���
 *		sign��������������ص�ǩ��ֵ
 *		psignlen���������������sign�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSignHash(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *hash,int hashlen,unsigned char **sign,int *psignlen);


/*
 *	NetcaPKICryptoNewVerify
 *		����ǩ����֤���
 *	������
 *		hPublicKey����Կ���
 *		algo�����������ǩ���㷨
 *		param���������������
 *	����ֵ��
 *		�ɹ�����ǩ����֤�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_VERIFY_HANDLE NETCADLLAPI NetcaPKICryptoNewVerify(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param);



/*
 *	NetcaPKICryptoVerifyUpdate
 *		����ǩ����֤��Ҫ��Hash���㣬����������Ե��ö��
 *	������
 *		hVerify��ǩ����֤���
 *		data���������������
 *		datalen��������������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyUpdate(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify,const unsigned char *data,int datalen);


/*
 *	NetcaPKICryptoVerifyFinal
 *		����ǩ����֤
 *	������
 *		hVerify��ǩ����֤���
 *		sign�����������ǩ��ֵ
 *		signlen�����������ǩ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyFinal(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify,const unsigned char *sign,int signlen);


/*
 *	NetcaPKICryptoFreeVerify
 *		�ͷ�ǩ����֤���
 *	������
 *		hVerify��ǩ����֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeVerify(NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify);

/*
 *	NetcaPKICryptoVerifyHash
 *		��֤ǩ����������Hashֵ
 *	������
 *		hPublicKey����Կ���
 *		algo�����������ǩ���㷨
 *		param���������������
 *		hash�����������Hashֵ
 *		hashlen��Hashֵ�ĳ���
 *		sign�����������ǩ��ֵ
 *		signlen�����������ǩ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoVerifyHash(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *hash,int hashlen,const unsigned char *sign,int signlen);


/*
 *	NetcaPKICryptoPublicKeyEncrypt
 *		��Կ����
 *	������
 *		hPublicKey����Կ���
 *		algo�������������Կ�����㷨
 *		param���������������
 *		clear���������������
 *		clearlen��������������ĳ���
 *		cipher��������������ص�����
 *		pcipherlen������������������ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoPublicKeyEncrypt(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *clear,int clearlen,unsigned char **cipher,int *pcipherlen);

/*
 *	NetcaPKICryptoPrivateKeyDecrypt
 *		˽Կ����
 *	������
 *		hKeypair����Կ�Ծ��
 *		algo�������������Կ�����㷨
 *		param���������������
 *		cipher���������������
 *		cipherlen��������������ĳ���
 *		clear��������������ص�����
 *		pclearlen������������������ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoPrivateKeyDecrypt(NETCA_PKI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *cipher,int cipherlen,unsigned char **clear,int *pclearlen);


/*
 *	NetcaPKICryptoKeyAgreement
 *		��ԿЭ��
 *	������
 *		hKeypair���Լ�����Կ�Ծ��
 *		hRespPublicKey���Է���Կ����ľ��
 *		hTempKeypair���Լ�����ʱ��Կ�Ծ��
 *		hTempRespPublicKey���Է�����ʱ��Կ����ľ��
 *		algo�������������ԿЭ���㷨
 *		param�����������������ԿЭ�̲���
 *		keylen�������������ԿЭ�̵õ��Ĺ�����Ϣ���ȣ����ֽ�Ϊ��λ
 *		key�������������ԿЭ�̵õ��Ĺ�����Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�������֧�ַ���NETCA_PKI_UNSUPPORTED�����û��Ȩ��ʹ��˽Կ������NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI NetcaPKICryptoKeyAgreement(NETCA_PKI_KEYPAIR_HANDLE hKeypair,NETCA_PKI_PUBLICKEY_HANDLE hRespPublicKey,NETCA_PKI_KEYPAIR_HANDLE hTempKeypair,NETCA_PKI_PUBLICKEY_HANDLE hTempRespPublicKey,int algo,void *param,int keylen,unsigned char *key);

#ifdef _WIN32

/*
 *	NetcaPKICryptoRegisterPullOutInfo
 *		ע���豸�����Ϣ��
 *	������
 *		isPullOut�����������1Ϊ�γ���0Ϊ����
 *		type������������豸����
 *		sn������������豸�����к�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoRegisterPullOutInfo(int isPullOut,int type,const char *sn);


/*
 *	NetcaPKICryptoSetWindowHandle
 *		������صĴ��ھ����Ӧ�ñ�֤���ھ�����豸������������ڽ���ǰһֱ��Ч��
 *	������
 *		hDevice���豸���
 *		hwnd�����ھ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetWindowHandle(NETCA_PKI_DEVICE_HANDLE hDevice,HWND hwnd);

/*
 *	NetcaPKICryptoSetVerifyPwdCallback
 *		������֤����Ļص�������
 *	������
 *		hDevice���豸�����ΪNULL���ʾ�ص�������ȫ�ֵģ��²����ľ�������µĻص�����
 *		func����֤����Ļص�������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetVerifyPwdCallback(NETCA_PKI_DEVICE_HANDLE hDevice,NetcaPKIUIVerifyPassword_Ptr func);

#endif

/*
 *	NetcaPKICryptoSetLoginPromptMsg
 *		���õ�¼����ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetLoginPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetGenKeyPairPromptMsg
 *		���ò�����Կ�Ե���ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetGenKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetImportKeyPairPromptMsg
 *		���õ�����Կ�Ե���ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetImportKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);


/*
 *	NetcaPKICryptoSetDeleteKeyPairPromptMsg
 *		����ɾ����Կ�Ե���ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeleteKeyPairPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetWriteCertPromptMsg
 *		����д��֤�����ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetWriteCertPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetDeleteCertPromptMsg
 *		����ɾ��֤�����ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeleteCertPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/*
 *	NetcaPKICryptoSetSignPromptMsg
 *		����ǩ������ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetSignPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);


/*
 *	NetcaPKICryptoSetPrivKeyDecryptPromptMsg
 *		����˽Կ���ܵ���ʾ��Ϣ��
 *	������
 *		hDevice���豸���
 *		flag�����������������������ǰֻ��ȡ0
 *		msg�������������ʾ��Ϣ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoSetPrivKeyDecryptPromptMsg(NETCA_PKI_DEVICE_HANDLE hDevice,int flag,const char *msg);

/* ���ຯ�� */

/*
 *	NetcaPKICryptoAllocMemory
 *		�����ڴ棬�ɹ�������ڴ�ֻ����NetcaPKICryptoFreeMemory���ͷ�
 *	������
 *		size�����������Ҫ������ڴ���ֽ���
 *	����ֵ��
 *		�ɹ����ط�����ڴ棬ʧ�ܷ���NULL
 *
 */
void * NETCADLLAPI NetcaPKICryptoAllocMemory(long size);



/*
 *	NetcaPKICryptoFreeMemory
 *		�ͷ��ڴ�
 *	������
 *		mem���ڴ�
 *	����ֵ��
 *		��
 *
 */
void NETCADLLAPI NetcaPKICryptoFreeMemory(void *mem);



/*
 *	NetcaPKICryptoNewBase64
 *		����Base64���
 *	������
 *		enc�������������0ΪBase64���룬0ΪBase64����
 *		flag�������������־�����NETCA_PKI_BASE64_NO_NL��λ�������ʱ������
 *	����ֵ��
 *		�ɹ�����Base64�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_BASE64_HANDLE NETCADLLAPI NetcaPKICryptoNewBase64(int enc,int flag);


/*
 *	NetcaPKICryptoBase64Update
 *		����Base64���㣬��������������ж��
 *	������
 *		hBase64��Base64���
 *		in�����������Ҫ���������
 *		inlen�����������in�ĳ���
 *		out��������������ش���������
 *		poutlen���������������out�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoBase64Update(NETCA_PKI_BASE64_HANDLE hBase64,const unsigned char * in,int inlen,unsigned char **out,int *poutlen);


/*
 *	NetcaPKICryptoBase64Final
 *		����Base64����
 *	������
 *		hBase64��Base64���
 *		remdata��������������������������
 *		premlen���������������remdata�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoBase64Final(NETCA_PKI_BASE64_HANDLE hBase64,unsigned char **remdata,int *premlen);

/*
 *	NetcaPKICryptoFreeBase64
 *		�ͷ�Base64���
 *	������
 *		hBase64��Base64���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKICryptoFreeBase64(NETCA_PKI_BASE64_HANDLE hBase64);

/*
 *	NetcaPKICryptoRSAPubKeyToDER
 *		�ѵ�����RSA��Կ��ʽת��ΪDER�����ʽ
 *	������
 *		in�����������������RSA��Կ��ʽ����
 *		inLen�����������in�ĳ���
 *		out��������������ص�DER�����ʽ
 *		outLen�����������DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPubKeyToDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoRSAPubKeyFromDER
 *		��DER�����ʽ��RSA��Կ��ʽת��Ϊ�����RSA��Կ��ʽ
 *	������
 *		in�����������DER�����RSA��Կ��ʽ����
 *		inLen�����������in�ĳ���
 *		out��������������صĵ����RSA��Կ��ʽ
 *		outLen�����������out�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPubKeyFromDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoRSAPrivKeyToDER
 *		�ѵ�����RSA˽Կ��ʽת��ΪDER�����ʽ
 *	������
 *		in�����������������RSA˽Կ��ʽ����
 *		inLen�����������in�ĳ���
 *		out��������������ص�DER�����ʽ
 *		outLen�����������DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPrivKeyToDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);


/*
 *	NetcaPKICryptoRSAPrivKeyFromDER
 *		��DER�����ʽ��RSA˽Կ��ʽת��Ϊ�����RSA˽Կ��ʽ
 *	������
 *		in�����������DER�����RSA˽Կ��ʽ����
 *		inLen�����������in�ĳ���
 *		out��������������صĵ����RSA˽Կ��ʽ
 *		outLen�����������out�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoRSAPrivKeyFromDER(const unsigned char *in,int inLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKICryptoSM2CipherToDER
 *		��SM2���ܽ��ת��ΪDER�����ʽ��Ҳ����SM2�����㷨ʹ�ù淶��Ҫ�ĸ�ʽ��
 *	������
 *		curve�������������Բ���ߺţ�ͨ��ΪSM2
 *		hashAlfo�����������Hash�㷨��ͨ��ΪSM3
 *		in�����������SM2���ܽ��
 *		inLen�����������in�ĳ���
 *		out��������������ص�DER�����ʽ
 *		outLen�����������DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSM2CipherToDER(int curve,int hashAlgo,const unsigned char *in,int inLen,unsigned char **out,int *outLen);


/*
 *	NetcaPKICryptoSM2CipherFromDER
 *		��DER�����ʽ��SM2����ת��Ϊ������Ҫ��SM2����
 *	������
 *		curve:�����������Բ���ߺţ�ͨ��ΪSM2
 *		in�����������DER�����SM2����
 *		inLen�����������in�ĳ���
 *		out��������������صĽ�����Ҫ��SM2����
 *		outLen�����������out�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSM2CipherFromDER(int curve,const unsigned char *in,int inLen,unsigned char **out,int *outLen);



/*
 *	NetcaPKICryptoEncodeRSAPubKey
 *		RSA��Կ��ʽ����
 *	������
 *		n�����������RSA��ģ
 *		nLen�����������n�ĳ���
 *		e�����������RSA�Ĺ�Կָ��
 *		eLen�����������e�ĳ���
 *		publicKey��������������صĵ����RSA��Կ��ʽ
 *		publicKeyLen�����������publicKey�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeRSAPubKey(const unsigned char *n,int nLen,const unsigned char *e,int eLen,unsigned char **publicKey,int *publicKeyLen);

/*
 *	NetcaPKICryptoDecodeRSAPubKey
 *		RSA��Կ��ʽ����
 *	������
 *		publicKey����������������RSA��Կ��ʽ
 *		publicKeyLen�����������publicKey�ĳ���
 *		n�����������RSA��ģ
 *		nLen�����������n�ĳ���
 *		e�����������RSA�Ĺ�Կָ��
 *		eLen�����������e�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeRSAPubKey(const unsigned char *publicKey,int publicKeyLen,unsigned char **n,int *nLen,unsigned char **e,int *eLen);

/*
 *	NetcaPKICryptoEncodeECCPubKey
 *		ECC��Կ��ʽ����
 *	������
 *		curve�������������Բ���ߺ�
 *		x�����������x
 *		xLen�����������x�ĳ���
 *		y�����������y
 *		yLen�����������y�ĳ���
 *		publicKey��������������صĵ����ECC��Կ��ʽ
 *		publicKeyLen�����������publicKey�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCPubKey(int curve,const unsigned char *x,int xLen,const unsigned char *y,int yLen,unsigned char **publicKey,int *publicKeyLen);

/*
 *	NetcaPKICryptoDecodeECCPubKey
 *		ECC��Կ��ʽ����
 *	������
 *		publicKey����������������ECC��Կ��ʽ
 *		publicKeyLen�����������publicKey�ĳ���
 *		curve�������������Բ���ߺ�
 *		x�����������x
 *		xLen�����������x�ĳ���
 *		y�����������y
 *		yLen�����������y�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCPubKey(const unsigned char *publicKey,int publicKeyLen,int *curve,unsigned char **x,int *xLen,unsigned char **y,int *yLen);

/*
 *	NetcaPKICryptoEncodeECCSignature
 *		ECCǩ����ʽ����
 *	������
 *		r�����������r
 *		rLen�����������r�ĳ���
 *		s�����������s
 *		sLen�����������s�ĳ���
 *		signature��������������ص�ECC��ǩ����ʽ
 *		signatureLen�����������signature�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCSignature(const unsigned char *r,int rLen,const unsigned char *s,int sLen,unsigned char **signature,int *signatureLen);


/*
 *	NetcaPKICryptoDecodeECCSignature
 *		ECCǩ����ʽ����
 *	������
 *		signature�����������ECC��ǩ����ʽ
 *		signatureLen�����������signature�ĳ���
 *		r�����������r
 *		rLen�����������r�ĳ���
 *		s�����������s
 *		sLen�����������s�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCSignature(const unsigned char *signature,int signatureLen,unsigned char **r,int *rLen,unsigned char **s,int *sLen);

/*
 *	NetcaPKICryptoEncodeECCKeyPair
 *		ECC��Կ�Ը�ʽ����
 *	������
 *		curve�������������Բ���ߺ�
 *		x�����������x
 *		xLen�����������x�ĳ���
 *		y�����������y
 *		yLen�����������y�ĳ���
 *		d�����������˽Կd
 *		dLen�����������d�ĳ���
 *		keypair��������������صĵ����ECC��Կ�Ը�ʽ
 *		keypairLen�����������keypair�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoEncodeECCKeyPair(int curve,const unsigned char *x,int xLen,const unsigned char *y,int yLen,const unsigned char *d,int dLen,unsigned char **keypair,int *keypairLen);

/*
 *	NetcaPKICryptoDecodeECCKeyPair
 *		ECC��Կ�Ը�ʽ����
 *	������
 *		keypair����������������ECC��Կ�Ը�ʽ
 *		keypairLen�����������keypair�ĳ���
 *		curve�������������Բ���ߺ�
 *		x�����������x
 *		xLen�����������x�ĳ���
 *		y�����������y
 *		yLen�����������y�ĳ���
 *		d�����������˽Կd
 *		dLen�����������d�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoDecodeECCKeyPair(const unsigned char *keypair,int keypairLen,int *curve,unsigned char **x,int *xLen,unsigned char **y,int *yLen,unsigned char **d,int *dLen);

/*
 *	NetcaPKICryptoEncodeRSAKeyPair
 *		RSA��Կ�Ը�ʽ����
 *	������
 *		n�����������RSA��ģ
 *		nLen�����������n�ĳ���
 *		e�����������RSA�Ĺ�Կָ��
 *		eLen�����������e�ĳ���
 *		d�����������RSA��˽Կָ��
 *		dLen�����������d�ĳ���
 *		p�����������p
 *		pLen�����������p�ĳ���
 *		q�����������q
 *		qLen�����������q�ĳ���
 *		dP�����������dP
 *		dPLen�����������dP�ĳ���
 *		dQ�����������dQ
 *		dQLen�����������dQ�ĳ���
 *		invQ�����������invQ
 *		invQLen�����������invQ�ĳ���
 *		keypair��������������صĵ����RSA��Կ�Ը�ʽ
 *		keypair�����������keypair�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
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
 *		RSA��Կ�Ը�ʽ����
 *	������
 *		keypair��������������صĵ����RSA��Կ�Ը�ʽ
 *		keypair�����������keypair�ĳ���
 *		n�����������RSA��ģ
 *		nLen�����������n�ĳ���
 *		e�����������RSA�Ĺ�Կָ��
 *		eLen�����������e�ĳ���
 *		d�����������RSA��˽Կָ��
 *		dLen�����������d�ĳ���
 *		p�����������p
 *		pLen�����������p�ĳ���
 *		q�����������q
 *		qLen�����������q�ĳ���
 *		dP�����������dP
 *		dPLen�����������dP�ĳ���
 *		dQ�����������dQ
 *		dQLen�����������dQ�ĳ���
 *		invQ�����������invQ
 *		invQLen�����������invQ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
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


/* ����֤�麯�� */

/*
 *	NetcaPKICertNewCert
 *		����֤����
 *	������
 *		data�����������֤��ı���
 *		len�����������֤��ı���ĳ���
 *	����ֵ��
 *		�ɹ�������Ч��֤������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertNewCert(const unsigned char *data,int len);

/*
 *	NetcaPKICertFreeCert
 *		�ͷ�֤����
 *	������
 *		cert��֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertFreeCert(NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertDupCert
 *		����֤����
 *	������
 *		cert��֤����
 *	����ֵ��
 *		�ɹ����ظ��ƺ��֤������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertDupCert(NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertGetCertEncode
 *		��ȡ֤�����
 *	������
 *		cert��֤����
 *		flag�����������֤���������
 *		buf��������������ص�֤�����
 *		pbuflen��������������ص�֤�����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetCertEncode(NETCA_PKI_CERTIFICATE_HANDLE cert,int flag,unsigned char **buf,int *pbuflen);

/*
 *	NetcaPKICertEqual
 *		�Ƚ�����֤��ı���
 *	������
 *		cert1��Ҫ�Ƚϵ�֤��1
 *		cert2��Ҫ�Ƚϵ�֤��2
 *	����ֵ��
 *		������֤�������ͬ����1����ͬ����0
 *
 */
int NETCADLLAPI NetcaPKICertEqual(NETCA_PKI_CERTIFICATE_HANDLE cert1,NETCA_PKI_CERTIFICATE_HANDLE cert2);

/*
 *	NetcaPKICertMatch
 *		�ж�֤���Ƿ�ƥ��
 *	������
 *		cert��֤����������ΪNULL��ΪNULL���ʾ���expr�﷨�Ƿ���ȷ
 *		expr������������������ʽ��UTF-8����
 *	����ֵ��
 *		���ƥ�䷵��1����ƥ�䷵��0�����ʽ���󷵻�-1,���������-2
 *
 */
int NETCADLLAPI NetcaPKICertMatch(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *expr);

/*
 *	NetcaPKISelectCert
 *		�������û�ȡ����Ϊtype������expr������֤��
 *	������
 *		type�����������֤�������
 *		expr������������������ʽ��UTF-8���룬����ΪNULL���߿մ�����ʾ����֤����
 *		pCert������������ɹ����ػ�ȡ��֤���������û���з���������֤�鷵��NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKISelectCert(const char *type,const char *expr,NETCA_PKI_CERTIFICATE_HANDLE* pCert);

/*
 *	NetcaPKICertGetCertIntegerAttribute
 *		��ȡ֤����������͵�����
 *	������
 *		cert��֤����
 *		attrId���������������
 *		pvalue��������������ص�����ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetCertIntegerAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,long *pvalue);

/*
 *	NetcaPKICertGetCertStringAttribute
 *		��ȡ֤����ַ������͵�����
 *	������
 *		cert��֤����
 *		attrId���������������
 *		pvalue��������������ص�����ֵ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetCertStringAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,char **pvalue);

/*
 *	NetcaPKICertGetCertHashAttribute
 *		��ȡ֤���Hashֵ����
 *	������
 *		cert��֤����
 *		attrId���������������
 *		algo:���������Hash�㷨
 *		pvalue��������������ص�Hashֵ
 *		pvalueLen��������������ص�Hashֵ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetCertHashAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,int algo,unsigned char **pvalue,int *pvalueLen);


/*
 *	NetcaPKICertSetCertIntegerAttribute
 *		����֤����������͵�����
 *	������
 *		cert��֤����
 *		attrId���������������
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetCertIntegerAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,long value);


/*
 *	NetcaPKICertSetCertStringAttribute
 *		����֤����ַ������͵�����
 *	������
 *		cert��֤����
 *		attrId���������������
 *		value���������������ֵ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetCertStringAttribute(NETCA_PKI_CERTIFICATE_HANDLE cert,int attrId,const char *value);

/*
 *	NetcaPKICertFindExtension
 *		��ȡ֤�����չ
 *	������
 *		cert��֤����
 *		oid�������������չ��OID
 *		pcrical����������������չ�ǹؼ��ķ���1�����򷵻�0
 *		pvalue�����������������չ�ı���ֵ
 *		pvaluelen�����������������չ�ı���ֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�������չ�����ڷ���NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKICertFindExtension(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *oid,int *pcrical,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKIDecodeStringExtension
 *		���ַ����������չ���н���
 *	������
 *		type����������
 *		ext�������������չֵ
 *		extlen�������������չֵ����
 *		pvalue����������������ַ���ֵ
 *		pvaluelen����������������ַ����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIDecodeStringExtension(int type,const unsigned char *ext,int extlen,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKICertGetCertPublicKey
 *		��ȡ֤��Ĺ�Կ
 *	������
 *		cert��֤����
 *		purpose�����������Ŀ��
 *	����ֵ��
 *		�ɹ�����֤��Ĺ�Կ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertGetCertPublicKey(NETCA_PKI_CERTIFICATE_HANDLE cert,int purpose);


/*
 *	NetcaPKICertGetCertKeyPair
 *		��ȡ֤��Ķ�Ӧ����Կ�Ծ��
 *	������
 *		cert��֤����
 *		flag�������������־�����NETCA_PKI_SEARCH_KEYPAIR_FLAG_LOCAL_MACHINE��λ�������������֤��⣬���NETCA_PKI_SEARCH_KEYPAIR_FLAG_CURRENT_USER��λ�����������ǰ�û�֤���
 *		purpose�����������Ŀ��
 *		pwd���������������
 *	����ֵ��
 *		�ɹ�����֤�����Կ�Ծ����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_KEYPAIR_HANDLE NETCADLLAPI NetcaPKICertGetCertKeyPair(NETCA_PKI_CERTIFICATE_HANDLE cert,int flag,int purpose,const char *pwd);

/*
 *	NetcaPKICertSetCertKeyPair
 *		����֤��Ķ�Ӧ����Կ�Ծ����ע��֤��ʱʹ�á�����������ж�֤�����Կ���Ƿ�ƥ��
 *	������
 *		cert��֤����
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�����֤�����Կ�Ծ����ʧ�ܷ���NULL
 *
 */
int NETCADLLAPI NetcaPKICertSetCertKeyPair(NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_KEYPAIR_HANDLE hKeypair);

/*
 *	NetcaPKICertGetDefaultCert
 *		��ȡȱʡ��֤����
 *	������
 *		purpose�����������Ŀ�ģ����NETCA_PKI_CERT_TYPE_LOCAL_MACHINE��λ����ʾȡ������ȱʡ֤�飬����Ϊ��ǰ�û���
 *	����ֵ��
 *		�ɹ�����ȱʡ��֤������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertGetDefaultCert(int purpose);

/*
 *	NetcaPKICertSetDefaultCert
 *		����ȱʡ��֤����
 *	������
 *		purpose�����������Ŀ�ģ����NETCA_PKI_CERT_TYPE_LOCAL_MACHINE��λ����ʾ���ñ�����ȱʡ֤�飬����Ϊ��ǰ�û���
 *		cert��֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetDefaultCert(int purpose, NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertVerifySelfSignCertSignature
 *		��֤��ǩ֤���ǩ��
 *	������
 *		cert��֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifySelfSignCertSignature(NETCA_PKI_CERTIFICATE_HANDLE cert);


#ifdef _WIN32
#include <wincrypt.h>
/*
 *	NetcaPKICertToMsCertContext
 *		ת��֤����Ϊ΢��ʹ�õ�֤����
 *	������
 *		cert��֤����
 *	����ֵ��
 *		�ɹ�����ת����ľ����ʧ�ܷ���NULL
 *
 */
PCCERT_CONTEXT NETCADLLAPI NetcaPKICertToMsCertContext(NETCA_PKI_CERTIFICATE_HANDLE cert);
#endif

/*
 *	NetcaPKICertVerifyUserPIN
 *		��֤ʹ��֤���˽Կ��Ҫ��PIN��
 *	������
 *		cert��֤����
 *		pwd��������������룬ASCII����
 *		pretrynum�����������������󷵻��������Դ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyUserPIN(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,int *pretrynum);

/* ֤��⺯�� */

/*
 *	NetcaPKICertOpenStore
 *		��֤���
 *	������
 *		type�����������֤�������
 *		name�����������֤�������
 *	����ֵ��
 *		�ɹ����ش򿪵�֤��⣬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertOpenStore(int type,const char *name);

/*
 *	NetcaPKICertCloseStore
 *		�ر�֤���
 *	������
 *		store��֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertCloseStore(NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertGetStoreCertCount
 *		��ȡ֤�����֤��ĸ���
 *	������
 *		store��֤���
 *	����ֵ��
 *		�ɹ�����֤�����֤��ĸ�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKICertGetStoreCertCount(NETCA_PKI_CERT_STORE store);


/*
 *	NetcaPKICertGetStoreCert
 *		��ȡ֤������֤��
 *	������
 *		store��֤���
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ�����֤������index��֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKICertGetStoreCert(NETCA_PKI_CERT_STORE store,int index);


/*
 *	NetcaPKICertAddStoreCert
 *		���֤�鵽֤�����
 *	������
 *		store��֤���
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertAddStoreCert(NETCA_PKI_CERT_STORE store,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertDeleteStoreCert
 *		ɾ��֤�����֤��
 *	������
 *		store��֤���
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertDeleteStoreCert(NETCA_PKI_CERT_STORE store,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICertLoadPFX
 *		����PFX
 *	������
 *		data�����������PFX�ı���
 *		len�����������PFX�ı��볤��
 *		pwd��������������룬UTF-8����
 *	����ֵ��
 *		�ɹ�����PFX֤��⣬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertLoadPFX(const unsigned char *data,int len,const char *pwd);


/*
 *	NetcaPKICertExportPFX
 *		����PFX
 *	������
 *		cert��Ҫ����PFX��֤�飬������˽Կ����˽Կ�ܵ���
 *		pwd�����������PFX�����룬UTF-8����
 *		otherCerts�����������PFX�ļ���Ҫ��������������
 *		otherCertCount�����������otherCerts�ĸ���
 *		friendlyName������������üǵ�����
 *		pfx�����������������PFX����
 *		pfxLen�����������pfx�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertExportPFX(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,const NETCA_PKI_CERTIFICATE_HANDLE otherCerts[],int otherCertCount,const char *friendlyName,unsigned char **pfx,int *pfxLen);

/*
 *	NetcaPKICertLoadP7c
 *		����P7c
 *	������
 *		data�����������P7c�ı���
 *		len�����������P7c�ı��볤��
 *	����ֵ��
 *		�ɹ�����P7c֤��⣬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertLoadP7c(const unsigned char *data,int len);


/* ֤��·��������֤���� */

/*
 *	NetcaPKICertVerifyCert
 *		��֤֤��
 *	������
 *		cert��֤��
 *		checktime�������������֤��ʱ�䣬ΪNULL��ʾ��ǰʱ�䡣��ʽΪYYYYMMDDhhmmssZ
 *		flag�������������֤��־
 *		status�����������֤�������״̬��NETCA_PKI_CERTIFICATE_STATUS_UNREVOKEDΪδ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_REVOKEDΪ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINEDΪ��ȷ��,NETCA_PKI_CERTIFICATE_STATUS_CA_REVOKEDΪCA����
 *		info���������������ʱ����������Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const char *checktime,int flag,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);


/*
 *	NetcaPKICertGetCertPath
 *		����֤��·��
 *	������
 *		cert��֤��
 *		certpath��������������ص�֤��·��
 *		count��������������ص�path��֤�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetCertPath(NETCA_PKI_CERTIFICATE_HANDLE cert, NETCA_PKI_CERTIFICATE_HANDLE **certpath,int* count);

/*
 *	NetcaPKICertFreeCertPath
 *		�ͷ�֤��·��
 *	������
 *		cert��֤��
 *		certpath��֤��·��
 *		count�����������path��֤�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertFreeCertPath(NETCA_PKI_CERTIFICATE_HANDLE *certpath,int count);

/*
 *	NetcaPKICertFreeRevokedCert
 *		�ͷ�����֤��
 *	������
 *		cert������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertFreeRevokedCert(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertGetRevokedCertRevokedTime
 *		��ȡ����֤�������ʱ��
 *	������
 *		cert������֤��
 *	����ֵ��
 *		�ɹ���������֤�������ʱ�䣬ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKICertGetRevokedCertRevokedTime(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertGetRevokedCertRevokedReason
 *		��ȡ����֤�������ԭ��
 *	������
 *		cert������֤��
 *	����ֵ��
 *		�ɹ���������֤�������ԭ��û������ԭ�򷵻�-1
 *
 */
int  NETCADLLAPI NetcaPKICertGetRevokedCertRevokedReason(NETCA_PKI_REVOKEDCERT_HANDLE cert);


/*
 *	NetcaPKICertCRLVerifyCert
 *		ʹ��CRL��֤֤�������״̬
 *	������
 *		cert��֤��
 *		crl�����������CRL�ı���
 *		crllen�����������CRL�ĳ���
 *		checktime�������������֤��ʱ�䣬ΪNULL��ʾ��ǰʱ�䡣��ʽΪYYYYMMDDhhmmssZ
 *		status�����������֤�������״̬��NETCA_PKI_CERTIFICATE_STATUS_UNREVOKEDΪδ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_REVOKEDΪ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINEDΪ��ȷ��
 *		info���������������ʱ������������Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertCRLVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* crl,int crllen,const char *checktime,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);


/*
 *	NetcaPKICertOCSPVerifyCert
 *		ʹ��OCSP��֤֤�������״̬
 *	������
 *		cert��֤��
 *		ocspurl�����������OCSP��URL�����ΪNULL����ʹ�ð�ȫ����������ֵ
 *		vacert�����������OCSP֤�飬����ΪNULL
 *		status�����������֤�������״̬��NETCA_PKI_CERTIFICATE_STATUS_UNREVOKEDΪδ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_REVOKEDΪ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINEDΪ��ȷ��
 *		info���������������ʱ������������Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertOCSPVerifyCert(NETCA_PKI_CERTIFICATE_HANDLE cert,const char* ocspurl,NETCA_PKI_CERTIFICATE_HANDLE vacert,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);

/*
 *	NetcaPKICertNewVerify
 *		����֤����֤���
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����֤����֤�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_VERIFY_HANDLE NETCADLLAPI NetcaPKICertNewVerify(void);

/*
 *	NetcaPKICertFreeVerify
 *		�ͷ�֤����֤���
 *	������
 *		hCertVerify��֤����֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertFreeVerify(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify);

/*
 *	NetcaPKICertVerifySetOption
 *		����֤����֤��ѡ��
 *	������
 *		hCertVerify��֤����֤���
 *		option:�����������֤ѡ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetOption(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,int option);

/*
 *	NetcaPKICertVerifySetParam
 *		����֤����֤��ѡ��
 *	������
 *		hCertVerify��֤����֤���
 *		param:�����������֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetParam(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *param);

/*
 *	NetcaPKICertVerifyAddRootCert
 *		��Ӹ�֤��
 *	������
 *		hCertVerify��֤����֤���
 *		cert:�����������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddRootCert(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKICertVerifyAddCACert
 *		���CA֤��
 *	������
 *		hCertVerify��֤����֤���
 *		cert:���������CA֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddCACert(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICertVerifySetVerifyTime
 *		������֤��ʱ��
 *	������
 *		hCertVerify��֤����֤���
 *		verifyTime:�����������֤��ʱ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifySetVerifyTime(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *verifyTime);

/*
 *	NetcaPKICertVerifyAddIgnoreExtension
 *		��ӿɲ�����Ĺؼ���չ
 *	������
 *		hCertVerify��֤����֤���
 *		ext:�����������չ��OID
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddIgnoreExtension(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const char *ext);

/*
 *	NetcaPKICertVerifyAddCRL
 *		���CRL
 *	������
 *		hCertVerify��֤����֤���
 *		crl:���������CRL�ı���
 *		crlLen:���������CRL��ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddCRL(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,const unsigned char *crl,int crlLen);

/*
 *	NetcaPKICertVerifyAddOCSP
 *		���OCSP
 *	������
 *		hCertVerify��֤����֤���
 *		vaCert:���������OCSP֤��
 *		ocsp:���������CRL�ı���
 *		ocspLen:���������CRL��ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyAddOCSP(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE vaCert,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKICertVerify
 *		��֤֤��
 *	������
 *		hCertVerify��֤����֤���
 *		cert��֤��
 *		status�����������֤�������״̬��NETCA_PKI_CERTIFICATE_STATUS_UNREVOKEDΪδ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_REVOKEDΪ���ϣ�NETCA_PKI_CERTIFICATE_STATUS_UNDETERMINEDΪ��ȷ��
 *		info���������������ʱ������������Ϣ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerify(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,NETCA_PKI_CERTIFICATE_HANDLE cert,int *status,NETCA_PKI_REVOKEDCERT_HANDLE *info);

/*
 *	NetcaPKICertVerifyGetCertPath
 *		��ȡ֤��·��
 *	������
 *		hCertVerify��֤����֤���
 *		certpath��������������ص�֤��·��
 *		count��������������ص�path��֤�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetCertPath(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, NETCA_PKI_CERTIFICATE_HANDLE **certpath,int* count);

/*
 *	NetcaPKICertVerifyGetPublicKey
 *		��ȡ֤��Ĺ�Կ
 *	������
 *		hCertVerify��֤����֤���
 *		purpose�����������Ŀ��
 *	����ֵ��
 *		�ɹ�����֤��Ĺ�Կ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertVerifyGetPublicKey(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify,int purpose);

/*
 *	NetcaPKICertVerifyGetAuthPolicySet
 *		��ȡ֤��İ䷢�������Լ�
 *	������
 *		hCertVerify��֤����֤���
 *		policySet��������������صİ䷢�������Լ�
 *		count��������������صİ䷢�������Լ��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetAuthPolicySet(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, char ***policySet,int* count);

/*
 *	NetcaPKICertVerifyGetUserPolicySet
 *		��ȡ֤����û����Լ�
 *	������
 *		hCertVerify��֤����֤���
 *		policySet��������������ص��û����Լ�
 *		count��������������ص��û����Լ��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertVerifyGetUserPolicySet(NETCA_PKI_CERT_VERIFY_HANDLE hCertVerify, char ***policySet,int* count);


/*
 *	NetcaPKIComputeSM2Z
 *		����SM2ǩ��Ҫ�õ���Z��ֵ
 *	������
 *		hPublicKey��ECC��Կ
 *		hashAlgo�����������Hash�㷨
 *		param�����������ID
 *		Z��������������ص�Z
 *		pZLen��������������ص�Z�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIComputeSM2Z(NETCA_PKI_PUBLICKEY_HANDLE hPublicKey,int hashAlgo,const struct NETCA_PKI_SM2Sign_PARAM_st *param,unsigned char **Z,int *pZLen);


/*
 *	NetcaPKIKDF
 *		KDF����Կ��������
 *	������
 *		kdfAlgo�����������KDF�㷨
 *		param�����������KDF�㷨�Ĳ���
 *		data���������������
 *		dataLen�����������data�ĳ���
 *		keyLen�������������Կ�ĳ���
 *		key��������������صĵ�������Կ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIKDF(int kdfAlgo,const void *param,const unsigned char *data,int dataLen,int keyLen,unsigned char *key);

/*
 *	NetcaPKIKeyWrap
 *		�öԳ���Կ������һ�Գ���Կ
 *	������
 *		algo������������ԳƼ����㷨
 *		isHmacKey�����������Ϊ���ʾHMAC��Key,Ϊ�ٱ�ʾ�Գ���Կ��Key
 *		param������������㷨����
 *		kek������������������ܵ���Կ
 *		kekLen�����������kek�ĳ���
 *		cek����������������ܵ���Կ
 *		cekLen�����������cek�ĳ���
 *		keywrap���������������keywrapֵ
 *		keywrapLen���������������keywrap�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIKeyWrap(int algo,int isHmacKey,const void *param,const unsigned char *kek,int kekLen,const unsigned char *cek,int cekLen,unsigned char **keywrap,int *keywrapLen);

/*
 *	NetcaPKIKeyUnwrap
 *		�öԳ���Կ������һ�Գ���Կ
 *	������
 *		algo������������ԳƼ����㷨
 *		isHmacKey�����������Ϊ���ʾHMAC��Key,Ϊ�ٱ�ʾ�Գ���Կ��Key
 *		param������������㷨����
 *		kek������������������ܵ���Կ
 *		kekLen�����������kek�ĳ���
 *		keywrap�����������Ҫ���ܵ�keywrapֵ
 *		keywrapLen�����������keywrap�ĳ���
 *		cek��������������ؽ��ܵõ�����Կ
 *		cekLen���������������cek�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIKeyUnwrap(int algo,int isHmacKey,const void *param,const unsigned char *kek,int kekLen,const unsigned char *keywrap,int keywrapLen,unsigned char **cek,int *cekLen);


#ifdef __cplusplus
	}	
#endif
#endif

