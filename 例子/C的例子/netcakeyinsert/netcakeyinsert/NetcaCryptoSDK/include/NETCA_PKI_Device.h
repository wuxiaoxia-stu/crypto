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
 *		��ʼ��DLLʹ�õ�ȫ����Դ����ʹ���豸�ӿ�ǰ�����ȵ��øú���
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceInit(void);

/*
 *	DeviceEnd
 *		�ͷ�DLLʹ�õ�ȫ����Դ�����豸�ӿڲ���ʹ��ǰӦ�õ��øú���
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceEnd(void);

/*
 *	DeviceGetAllDevices
 *		��ȡ��ǰ���ӵ����е��豸��ɵ��豸��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�������Ч���豸�������ʧ�ܷ���NULL
 *
 */
SPI_DEVICE_HANDLE_SET NETCADLLAPI DeviceGetAllDevices(void);


/*
 *	DeviceGetDeviceCount
 *		��ȡ�豸�����豸����
 *	������
 *		hDeviceSet���豸�����
 *	����ֵ��
 *		�ɹ������豸�����豸�ĸ�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI DeviceGetDeviceCount(SPI_DEVICE_HANDLE_SET hDeviceSet);

/*
 *	DeviceGetDevice
 *		��ȡ�豸���е��豸
 *	������
 *		hDeviceSet���豸�����
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ������豸���е�index���豸�����ʧ�ܷ���NULL
 *
 */
SPI_DEVICE_HANDLE NETCADLLAPI DeviceGetDevice(SPI_DEVICE_HANDLE_SET hDeviceSet,int index);


/*
 *	DeviceFreeDevices
 *		�ͷ��豸��
 *	������
 *		hDeviceSet���豸�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI DeviceFreeDevices(SPI_DEVICE_HANDLE_SET hDeviceSet);


/*
 *	DeviceFindDevice
 *		�������кŻ�ȡ�豸
 *	������
 *		sn������������豸���кţ�ASCII����
 *		phDevice������������ɹ����ص�ǰ���ӵ����к�Ϊsn���豸���豸�����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceFindDevice(const char *sn,SPI_DEVICE_HANDLE *phDevice);


/*
 *	DeviceGetSerialNumber
 *		��ȡ�豸�����к�
 *	������
 *		hDevice���豸���
 *		sn����������������豸���кţ�ASCII����
 *		snlen�����������sn�Ļ���������
 *		pretsnlen��������������snΪNULL���򷵻ؿ����������кŵĳ��ȡ����򣬷������кŵĳ��ȣ���������'\0'��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��snlen̫С����NETCA_PKI_MOREDATA��
 *
 */
int NETCADLLAPI DeviceGetSerialNumber(SPI_DEVICE_HANDLE hDevice,char *sn,int snlen,int *pretsnlen);



/*
 *	DeviceGetSerialNumber
 *		��ȡ�豸�ľ��
 *	������
 *		hDevice���豸���
 *		label����������������豸�ľ�꣬UTF-8����
 *		labellen�����������label�Ļ���������
 *		pretlabellen��������������labelΪNULL���򷵻ؿ������ɾ��ĳ��ȡ����򣬷��ؾ��ĳ��ȣ���������'\0'��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��labellen̫С����NETCA_PKI_MOREDATA��
 *
 */
int NETCADLLAPI DeviceGetLabel(SPI_DEVICE_HANDLE hDevice,char *label,int labellen,int *pretlabellen);

/*
 *	DeviceVerifyPwd
 *		��֤�豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա���롣
 *		pwd��������������룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceVerifyPwd(SPI_DEVICE_HANDLE hDevice,int type,const char *pwd,int *pretrynum);


/*
 *	DeviceChangePwd
 *		�޸��豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա���롣
 *		oldpwd������������ɵ����룬ASCII����
 *		newpwd������������µ����룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceChangePwd(SPI_DEVICE_HANDLE hDevice,int type, const char *oldpwd,const char *newpwd,int *pretrynum);


/*
 *	DeviceUnlockPwd
 *		�����豸������
 *	������
 *		hDevice���豸���
 *		type������������������ͣ���ǰ�汾ֻ����NETCA_PKI_USER_PWD��ʾ�û����롣
 *		sopwd���������������Ա�����룬ASCII����
 *		newpwd������������µ��û����룬ASCII����
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��������󷵻�NETCA_PKI_PWD_ERROR��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceUnlockPwd(SPI_DEVICE_HANDLE hDevice,int type, const char *sopwd,const char *newpwd,int *pretrynum);

/*
 *	DeviceGetPwdRetryNum
 *		��ȡ�豸��������Դ���
 *	������
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա���롣
 *		pretrynum�������������֤�������ʱ���������뻹�������ԵĴ����������֧�ַ������뻹�������ԵĴ���������NETCA_PKI_UNSUPPORTED_RETRY_NUMBER��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceGetPwdRetryNum(SPI_DEVICE_HANDLE hDevice,int type, int *pretrynum);


/*
 *	DeviceLockDevice
 *		���豸����
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceLockDevice(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceUnlockDevice
 *		���豸����
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceUnlockDevice(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceFreeDevice
 *		�ͷ��豸���
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI DeviceFreeDevice(SPI_DEVICE_HANDLE hDevice);




/*
 *	DeviceCreateData
 *		���豸�д���һ��־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		mode������������־����ݵ�Ȩ��
 *		length������������־����ݵ���󳤶�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL������־������Ѿ����ڣ�����NETCA_PKI_EXISIT�����ûȨ�޴����־����ݣ�����NETCA_PKI_ ACCESSDENIED�������֧��ָ����ʶ�ĳ־����ݣ�����NETCA_PKI_ UNSUPPORTED
 *
 */
int NETCADLLAPI DeviceCreateData(SPI_DEVICE_HANDLE hDevice,int dataId, const char * mode,int length);


/*
 *	DeviceReadDataEx
 *		���־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		offset������������־����ݵ�λ��
 *		data��������������ض��������ݣ�����ΪNULL
 *		datalen�����������data�ĳ���
 *		pretdatalen��������������ض����ĳ־����ݵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ�޶��־����ݣ�����NETCA_PKI_ ACCESSDENIED��
 *
 */
int NETCADLLAPI DeviceReadDataEx(SPI_DEVICE_HANDLE hDevice,int dataId, int offset,unsigned char *data,int datalen,int*  pretdatalen);

/*
 *	DeviceWriteDataEx
 *		д�־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *		offset������������־����ݵ�λ��
 *		data�����������Ҫд�������
 *		datalen�����������data�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ��д�־����ݣ�����NETCA_PKI_ ACCESSDENIED
 *
 */
int NETCADLLAPI DeviceWriteDataEx(SPI_DEVICE_HANDLE hDevice,int dataId,int offset, const unsigned char *data,int datalen);

/*
 *	DeviceDeleteData
 *		ɾ���־�����
 *	������
 *		hDevice���豸���
 *		dataId������������־����ݱ�ʶ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��ָ���ĳ־����ݣ�����NETCA_PKI_NOTEXISIT�����ûȨ��ɾ���־����ݣ�����NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceDeleteData(SPI_DEVICE_HANDLE hDevice,int dataId);


/*
 *	DeviceGetKeypairCount
 *		��ȡ�豸����Կ������
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ������豸����Կ��������ʧ�ܷ���-1
 */
int NETCADLLAPI DeviceGetKeypairCount(SPI_DEVICE_HANDLE hDevice);

/*
 *	DeviceGetKeypair
 *		��ȡ�豸�е���Կ��
 *	������
 *		hDevice���豸���
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ������豸�е�index����Կ�ԣ�ʧ�ܷ���NULL
 */
SPI_KEYPAIR_HANDLE NETCADLLAPI DeviceGetKeypair(SPI_DEVICE_HANDLE hDevice,int index);

/*
 *	DeviceFindKeypair
 *		������Կ�Ե����ͺͱ�ǩ����ȡ�豸�е���Կ��
 *	������
 *		hDevice���豸���
 *		type�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ������豸��ָ������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI DeviceFindKeypair(SPI_DEVICE_HANDLE hDevice,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);

/*
 *	DeviceFreeKeypair
 *		�ͷ���Կ�Ծ��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceFreeKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairLabel
 *		��ȡ��Կ�Եı�ǩ
 *	������
 *		hKeypair����Կ�Ծ��
 *		label��������������ص���Կ�Եı�ǩ��UTF-8����
 *		labellen�����������label�Ļ���������
 *		pretlabellen��������������labelΪNULL���򷵻ؿ������ɾ��ĳ��ȡ����򣬷��ؾ��ĳ��ȣ���������'\0'������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��labellen̫С����NETCA_PKI_MOREDATA
 */
int NETCADLLAPI DeviceGetKeypairLabel(SPI_KEYPAIR_HANDLE hKeypair,char *label,int labellen,int *pretlabellen);

/*
 *	DeviceGetKeypairType
 *		��ȡ��Կ�Ե�����
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե����ͣ�ʧ�ܷ���-1
 */
int NETCADLLAPI DeviceGetKeypairType(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairAlgorithm
 *		��ȡ��Կ�Ե��㷨
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե��㷨��ʧ�ܷ���-1
 */
int NETCADLLAPI DeviceGetKeypairAlgorithm(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetKeypairBits
 *		��ȡ��Կ�Եĳ��ȣ���λΪ��λ
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�Ե�λ����ʧ�ܷ���-1
 */
int NETCADLLAPI DeviceGetKeypairBits(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGenerateKeypair
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
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵ��㷨����NETCA_PKI_ UNSUPPORTED�����ûȨ�޲�����Կ�ԣ�����NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceGenerateKeypair(SPI_DEVICE_HANDLE hDevice,int algo,int keybits,const void *param,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);


/*
 *	DeviceImportKeypair
 *		������Կ�Ե��豸��ȥ
 *	������
 *		hDevice���豸���
 *		keyblob�������������Կ�Եı���
 *		keybloblen�������������Կ�Եı���ĳ���
 *		type�������������Կ�Ե�����
 *		label�������������Կ�Ա�ǩ��UTF-8����
 *		phKeypair������������ɹ����ز�������Կ�Ծ����ʧ�ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ַ���NETCA_PKI_ UNSUPPORTED�����ûȨ�޵�����Կ�ԣ�����NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DeviceImportKeypair(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,int type,const char *label,SPI_KEYPAIR_HANDLE *phKeypair);

/*
 *	DeviceExportKeypair
 *		������Կ��
 *	������
 *		hKeypair����Կ�Ծ��
 *		keyblob�����������������Կ�Եı���
 *		keybloblen�����������keyblob�Ļ������ĳ��ȡ�
 *		pretkeybloblen��������������keyblobΪNULL�����������ɵ�����Կ�Եĳ��ȣ����򷵻ص�����Կ�Եĳ��ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����keybloblen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceExportKeypair(SPI_KEYPAIR_HANDLE hKeypair,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);

/*
 *	DeviceDeleteKeypair
 *		���豸��ɾ����Կ�Լ�����ص�֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL���ûȨ��ɾ����Կ�ԣ�����NETCA_PKI_ACCESSDENIED
 */
int NETCADLLAPI DeviceDeleteKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetPublicKeyFromKeypair
 *		��ȡ��Կ�ԵĹ�Կ���
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ�ԵĹ�Կ�����ʧ�ܷ���NULL
 */
SPI_PUBLICKEY_HANDLE NETCADLLAPI DeviceGetPublicKeyFromKeypair(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceExportPublicKey
 *		������Կ
 *	������
 *		hPublicKey����Կ���
 *		keyblob��������������ع�Կ�ı���
 *		keybloblen�����������keyblob�Ļ������ĳ��ȡ�
 *		pretkeybloblen��������������keyblobΪNULL�����������ɵ�����Կ�ĳ��ȣ����򷵻ص�����Կ�ĳ��ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵĹ�Կ����NETCA_PKI_ UNSUPPORTED�����keybloblen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceExportPublicKey(SPI_PUBLICKEY_HANDLE hPublicKey,unsigned char *keyblob,int keybloblen, int* pretkeybloblen);


/*
 *	DeviceImportPublicKey
 *		������ʱ�Ĺ�Կ
 *	������
 *		hDevice���豸���
 *		keyblob�������������Կ�ı���
 *		keybloblen�������������Կ�ı���ĳ��ȡ�
 *		phPublicKey������������ɹ�������ʱ�Ĺ�Կ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ֵĹ�Կ����NETCA_PKI_ UNSUPPORTED�����keybloblen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceImportPublicKey(SPI_DEVICE_HANDLE hDevice,const unsigned char *keyblob,int keybloblen,SPI_PUBLICKEY_HANDLE *phPublicKey);

/*
 *	DeviceGetPublicKeyBits
 *		��ȡ��Կ�ĳ��ȣ���λΪ��λ
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ع�Կ��λ����ʧ�ܷ���-1��
 */
int NETCADLLAPI DeviceGetPublicKeyBits(SPI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	DeviceFreePublicKey
 *		�ͷŹ�Կ���
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��
 */
int NETCADLLAPI DeviceFreePublicKey(SPI_PUBLICKEY_HANDLE hPublicKey);


/*
 *	DeviceGetPublicKeyAlgorithm
 *		��ȡ��Կ���㷨
 *	������
 *		hPublicKey����Կ���
 *	����ֵ��
 *		�ɹ����ع�Կ���㷨��ʧ�ܷ���-1��
 */
int NETCADLLAPI DeviceGetPublicKeyAlgorithm(SPI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	DeviceGetCertificateCount
 *		��ȡ��Կ����ص�֤�����
 *	������
 *		hKeypair����Կ�Ծ��
 *	����ֵ��
 *		�ɹ�������Կ����ص�֤�������ʧ�ܷ���-1��
 */
int NETCADLLAPI DeviceGetCertificateCount(SPI_KEYPAIR_HANDLE hKeypair);


/*
 *	DeviceGetCertificate
 *		��ȡ��Կ����صĵ�index��֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		index����������������ţ���0����
 *		certblob��������������ص�index��֤���DER����
 *		certbloblen�����������certblob�������Ĵ�С
 *		pretcertbloblen��������������certblobΪNULL���򷵻ؿ�������֤���DER����ĳ��ȡ����򣬷���֤���DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����certbloblen̫С����NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceGetCertificate(SPI_KEYPAIR_HANDLE hKeypair,int index,unsigned char *certblob,int certbloblen,int *pretcertbloblen);

/*
 *	DeviceDeleteCertificate
 *		��ȡ��Կ����صĵ�index��֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��ɾ��֤�飬����NETCA_PKI_ ACCESSDENIED��
 */
int NETCADLLAPI DeviceDeleteCertificate(SPI_KEYPAIR_HANDLE hKeypair,int index);


/*
 *	DeviceUpdateCertificate
 *		��֤��д���豸������Կ������������������ɾ����ǰ����Կ�Թ�����֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		certblob�����������֤���DER����
 *		certbloblen�����������֤���DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��д֤�飬����NETCA_PKI_ ACCESSDENIED��
 */
int NETCADLLAPI DeviceUpdateCertificate(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);


/*
 *	DeviceAddCertificate
 *		��֤��д���豸������Կ�����������������ᱣ����ǰ����Կ�Թ�����֤��
 *	������
 *		hKeypair����Կ�Ծ��
 *		certblob�����������֤���DER����
 *		certbloblen�����������֤���DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����û��Ȩ��д֤�飬����NETCA_PKI_ ACCESSDENIED��
 */
int NETCADLLAPI DeviceAddCertificate(SPI_KEYPAIR_HANDLE hKeypair,const unsigned char *certblob,int certbloblen);



/*
 *	DeviceIsSupportedAlgorithm
 *		ѯ���豸�Ƿ�֧��ĳ���㷨����������Ѿ���������Ҫ��ʵ������Ӧ��ʵ��DeviceIsSupportedAlgorithm2�������
 *	������
 *		hDevice���豸���
 *		algo������������㷨
 *	����ֵ��
 *		���֧�ַ���1����֧�ַ���0��
 */
int NETCADLLAPI DeviceIsSupportedAlgorithm(SPI_DEVICE_HANDLE hDevice,int algo);


/*
 *	DeviceIsSupportedAlgorithm2
 *		ѯ���豸�Ƿ�֧��ĳ���㷨������������ڴ���DeviceIsSupportedAlgorithm
 *	������
 *		hDevice���豸���
 *		algo������������㷨
 *		keyLen�������������Կ���ȣ���λΪ��λ
 *		usage������������㷨����;��������ܽ���֮��
 *		param������������㷨��صĲ���
 *		
 *	����ֵ��
 *		���֧�ַ���1����֧�ַ���0��
 */
int NETCADLLAPI DeviceIsSupportedAlgorithm2(SPI_DEVICE_HANDLE hDevice,int algo,int keyLen,int usage,const void *param);


/*
 *	DeviceGenerateRandom
 *		��ȡ�����
 *	������
 *		hDevice���豸���
 *		len��������������������
 *		rand��������������ص����������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 */
int NETCADLLAPI DeviceGenerateRandom(SPI_DEVICE_HANDLE hDevice,int len,unsigned char *rand);



/*
 *	DeviceNewHash
 *		����Hash���
 *	������
 *		hDevice���豸���
 *		algo�����������Hash�㷨
 *	����ֵ��
 *		�ɹ�����Hash�����ʧ�ܷ���NULL��
 */
SPI_HASH_HANDLE NETCADLLAPI DeviceNewHash(SPI_DEVICE_HANDLE hDevice,int algo);


/*
 *	DeviceHashUpdate
 *		Hash���ݣ�����������Զ�ε���
 *	������
 *		hHash��Hash���
 *		data�����������Ҫ����Hash���������
 *		datalen�����������data���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 */
int NETCADLLAPI DeviceHashUpdate(SPI_HASH_HANDLE hHash,const unsigned char *data,int datalen);

/*
 *	DeviceHashFinal
 *		����Hash���㣬��ȡHashֵ
 *	������
 *		hHash��Hash���
 *		hashvalue��������������ص�Hashֵ������ΪNULL
 *		hashvaluelen�����������hashvalue�������Ĵ�С
 *		prethashvaluelen���������������Hashֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����hashvaluelen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceHashFinal(SPI_HASH_HANDLE hHash,unsigned char *hashvalue, int hashvaluelen,int *prethashvaluelen);


/*
 *	DeviceFreeHash
 *		�ͷ�Hash���
 *	������
 *		hHash��Hash���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��
 */
int NETCADLLAPI DeviceFreeHash(SPI_HASH_HANDLE hHash);

/*
 *	DeviceDuplicateHash
 *		����Hash��������Ʋ���ʹ�����ü����ķ�ʽ�����븴��Hash���ڲ���״̬
 *	������
 *		hHash��Ҫ���Ƶ�Hash���
 *		phNewHash��������������ظ��Ƶõ���Hash���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL����֧�ַ���NETCA_PKI_UNSUPPORTED��
 */
int NETCADLLAPI DeviceDuplicateHash(SPI_HASH_HANDLE hHash,SPI_HASH_HANDLE *phNewHash);

/*
 *	DeviceNewMac
 *		����MAC���
 *	������
 *		hDevice���豸���
 *		algo�����������Mac�㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param�����������Mac�㷨�Ĳ���������HMAC��˵��ΪNULL
 *	����ֵ��
 *		�ɹ�����MAC�����ʧ�ܷ���NULL��
 */
SPI_MAC_HANDLE NETCADLLAPI DeviceNewMac(SPI_DEVICE_HANDLE hDevice,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	DeviceMacUpdate
 *		Mac���ݣ�����������Զ�ε���
 *	������
 *		hMac��Mac���
 *		data�����������Ҫ����Mac���������
 *		datalen�����������data���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 */
int NETCADLLAPI DeviceMacUpdate(SPI_MAC_HANDLE hMac,const unsigned char *data,int datalen);

/*
 *	DeviceMacFinal
 *		����Mac���㣬��ȡMacֵ
 *	������
 *		hMac��Mac���
 *		macvalue��������������ص�Macֵ������ΪNULL
 *		macvaluelen: �������, macvalue�������Ĵ�С
 *		pretmacvaluelen���������������MAC�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����macvaluelen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceMacFinal(SPI_MAC_HANDLE hMac,unsigned char *macvalue,int macvaluelen,int *pretmacvaluelen);


/*
 *	DeviceFreeMac
 *		�ͷ�Mac���
 *	������
 *		hMac��Mac���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 */
int NETCADLLAPI DeviceFreeMac(SPI_MAC_HANDLE hMac);



/*
 *	DeviceNewCipher
 *		�����ӽ��ܾ��
 *	������
 *		hDevice���豸���
 *		enc�����������1����ܣ�0��ʾ����
 *		algo����������������㷨
 *		key�������������Կ
 *		keylen�������������Կ���ֽ���
 *		param������������ӽ��ܵĲ���
 *	����ֵ��
 *		�ɹ����ش����ӽ��ܾ����ʧ�ܷ���NULL��
 */
SPI_CIPHER_HANDLE NETCADLLAPI DeviceNewCipher(SPI_DEVICE_HANDLE hDevice,int enc,int algo,const unsigned char *key,int keylen,const void *param);

/*
 *	DeviceImportKeyAndNewCipher
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
int NETCADLLAPI DeviceImportKeyAndNewCipher(SPI_KEYPAIR_HANDLE hKeypair,int pubkeyencalgo,const void *pubkeyencparam,const unsigned char *enckey,int enckeylen,int enc,int algo,const void *param,SPI_CIPHER_HANDLE *phCipher);

/*
 *	DeviceCipherUpdate
 *		�ӽ������ݣ�����������Զ�ε���
 *	������
 *		hCipher���ӽ��ܾ��
 *		in�������������������
 *		inlen�����������in���ֽ���
 *		out��������������ص�����
 *		outlen�����������out�������Ĵ�С
 *		pretoutlen��������������outΪNULL�������������ļӽ��ܣ����ؿ������ɵ�������ȣ����򣬷���������ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��outlen̫С������NETCA_PKI_MOREDATA��
 */
int NETCADLLAPI DeviceCipherUpdate(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,int inlen,unsigned char *out,int outlen,int *pretoutlen);

/*
 *	DeviceCipher
 *		һ����ɼӽ�������
 *	������
 *		hCipher���ӽ��ܾ��
 *		in�������������������
 *		inlen�����������in���ֽ���
 *		out��������������ص�����
 *		outlen�����������out�������Ĵ�С
 *		pretoutlen��������������outΪNULL�������������ļӽ��ܣ����ؿ������ɵ�������ȣ����򣬷���������ȡ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��outlen̫С������NETCA_PKI_MOREDATA������㷨��NETCA_PKI_UNSUPPORTED
 */
int NETCADLLAPI DeviceCipher(SPI_CIPHER_HANDLE hCipher,const unsigned char *in,long long inlen,unsigned char *out,long long outlen,long long *pretoutlen);

/*
 *	DeviceFreeCipher
 *		�ͷżӽ��ܾ��
 *	������
 *		hCipher���ӽ��ܾ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL��
 */
int NETCADLLAPI DeviceFreeCipher(SPI_CIPHER_HANDLE hCipher);


/*
 *	DeviceSign
 *		����ǩ��
 *	������
 *		hKeypair����Կ�Ծ��
 *		algo�����������ǩ���㷨
 *		param�����������ǩ������
 *		tbs���������������Ҫǩ��������
 *		tbslen�����������tbs���ֽ���
 *		sign��������������ص�ǩ��ֵ
 *		signlen�����������sign�������Ĵ�С
 *		pretsignlen��������������signΪNULL���򷵻�����������ĳ��ȡ����򣬷���ǩ���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����signlen̫С������NETCA_PKI_MOREDATA�����û��Ȩ��ǩ��������NETCA_PKI_ACCESSDENIED�������֧�ֵ�ǩ���㷨������NETCA_PKI_ UNSUPPORTED��
 */
int NETCADLLAPI DeviceSign(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *tbs,int tbslen,unsigned char *sign,int signlen,int *pretsignlen);



/*
 *	DeviceVerify
 *		��֤ǩ��
 *	������
 *		hPublicKey����Կ���
 *		algo�����������ǩ���㷨
 *		param�����������ǩ������
 *		tbs���������������Ҫǩ��������
 *		tbslen�����������tbs���ֽ���
 *		sign�����������ǩ��ֵ
 *		signlen�����������ǩ��ֵ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����֧�ֵ�ǩ���㷨������NETCA_PKI_ UNSUPPORTED
 */
int NETCADLLAPI DeviceVerify(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *tbs,int tbslen,const unsigned char *sign,int signlen);


/*
 *	DevicePublicKeyEncrypt
 *		��Կ����
 *	������
 *		hPublicKey����Կ���
 *		algo�������������Կ�����㷨
 *		param�������������Կ���ܲ���
 *		clear���������������
 *		clearlen��������������ĵ��ֽ���
 *		cipher��������������ص�����
 *		cipherlen�����������cipher���������ֽ���
 *		pretcipherlen��������������cipherΪNULL���������������ĵĳ��ȡ����򷵻����ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����֧�ֵĹ�Կ�����㷨������NETCA_PKI_ UNSUPPORTED�����cipherlen̫С������NETCA_PKI_MOREDATA
 */
int NETCADLLAPI DevicePublicKeyEncrypt(SPI_PUBLICKEY_HANDLE hPublicKey,int algo,const void *param,const unsigned char *clear,int clearlen,unsigned char *cipher,int cipherlen,int *pretcipherlen);


/*
 *	DevicePrivateKeyDecrypt
 *		˽Կ����
 *	������
 *		hKeypair����Կ�Ծ��
 *		algo�������������Կ�����㷨
 *		param�������������Կ���ܲ���
 *		cipher���������������
 *		cipherlen��������������ĵ��ֽ���
 *		clear��������������ص�����
 *		clearlen�����������clear���������ֽ���
 *		pretclearlen��������������clearΪNULL���������������ĵĳ��ȡ����򷵻����ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL�����֧�ֵĹ�Կ�����㷨������NETCA_PKI_ UNSUPPORTED�����clearlen̫С������NETCA_PKI_MOREDATA�����û��Ȩ�޽��ܣ�����NETCA_PKI_ ACCESSDENIED
 */
int NETCADLLAPI DevicePrivateKeyDecrypt(SPI_KEYPAIR_HANDLE hKeypair,int algo,const void *param,const unsigned char *cipher,int cipherlen,unsigned char *clear,int clearlen,int *pretclearlen);


/*
 *	DeviceKeyAgreement
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
int NETCADLLAPI DeviceKeyAgreement(SPI_KEYPAIR_HANDLE hKeypair,SPI_PUBLICKEY_HANDLE hRespPublicKey,SPI_KEYPAIR_HANDLE hTempKeypair,SPI_PUBLICKEY_HANDLE hTempRespPublicKey,int algo,void *param,int keylen,unsigned char *key);

/*
 *	DeviceGetState
 *		��ȡ�豸��״̬�������Ƿ��Ѿ���ʽ������
 *	������
 *		hDevice���豸���
 *		pState������������ɹ������豸��״̬��NETCA_PKI_DEVICE_STATE_NORMAL��ʾ����ʹ��״̬��Ҳ�����Ѿ���ʽ�����ˣ���NETCA_PKI_DEVICE_ STATE_UNINITIALIZED��ʾδ��ʽ��״̬��NETCA_PKI_DEVICE_ STATE_OTHER��ʾ����CA��KEY
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI DeviceGetState(SPI_DEVICE_HANDLE hDevice,int *pState);

/*
 *	DeviceFormatDevice
 *		��ʽ���豸��
 *	������
 *		hDevice���豸���
 *		soPwd������������������룬ASCII����
 *		soPwdRetryNumber�����������������������Դ�����ȡֵ��Χ1~15
 *		userPwd������������û����룬ASCII����
 *		userPwdRetryNumber������������û���������Դ�����ȡֵ��Χ1~15
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��û��Ȩ�޷���NETCA_PKI_ACCESSDENIED����֧�ַ���NETCA_PKI_UNSUPPORTED��ʧ�ܷ���NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceFormatDevice(SPI_DEVICE_HANDLE hDevice,const char *soPwd,int soPwdRetryNumer,const char *userPwd,int userPwdRetryNumber);


/*
 *	DeviceNewDevice
 *		��ʽ���豸��
 *	������
 *		hDevice���豸���
 *		subDeviceName��������������豸����
 *		soPwd������������������룬ASCII����
 *		soPwdRetryNumber�����������������������Դ�����ȡֵ��Χ1~15
 *		userPwd������������û����룬ASCII����
 *		userPwdRetryNumber������������û���������Դ�����ȡֵ��Χ1~15
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��û��Ȩ�޷���NETCA_PKI_ACCESSDENIED����֧�ַ���NETCA_PKI_UNSUPPORTED�����豸���Ѿ����ڣ�����NETCA_PKI_EXIST��ʧ�ܷ���NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceNewDevice(SPI_DEVICE_HANDLE hDevice, const char *subDeviceName, const char *soPwd, int soPwdRetryNumer, const char *userPwd, int userPwdRetryNumber, SPI_DEVICE_HANDLE *phDevice2);


/*
 *	DeviceDeleteDevice
 *		ɾ���߼��豸��
 *	������
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��û��Ȩ�޷���NETCA_PKI_ACCESSDENIED����֧�ַ���NETCA_PKI_UNSUPPORTED��ʧ�ܷ���NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceDeleteDevice(SPI_DEVICE_HANDLE hDevice);


/*
 *	DeviceIsSamePhysicalDevice
 *		�ж��Ƿ���ͬһ�����豸��
 *	������
 *		hDevice1���豸���1
 *		hDevice2���豸���2
 *	����ֵ��
 *		�����ͬһ�����豸����1�����򷵻�0
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
 *		��ȡ�����б�
 *	������
 *		functionList��������������غ����б�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 */
int NETCADLLAPI DeviceGetFunctionList(NETCA_PKI_Device_FunctionList_Ptr functionList);

typedef int (NETCADLLAPI* DeviceGetFunctionList_Ptr)(NETCA_PKI_Device_FunctionList_Ptr functionList);


#ifdef __cplusplus
	}	
#endif
#endif
