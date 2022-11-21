#ifndef _NETCA_PKI_CONFIG_INLCUDE_H_
#define _NETCA_PKI_CONFIG_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIConfigSetSelectCertPolicy 
 *		����֤���ѡ�����
 *	������
 *		policy�����������ѡ��֤��Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetSelectCertPolicy(const char* policy);


/*
 *	NetcaPKIConfigGetSelectCertPolicy 
 *		��ȡ֤���ѡ�����
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����֤���ѡ����ԣ�ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetSelectCertPolicy(void);


/*
 *	NetcaPKIConfigSetFilterCertCondition 
 *		����֤���ѡ�����
 *	������
 *		condition���������������֤�������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetFilterCertCondition(const char* condition);


/*
 *	NetcaPKIConfigGetFilterCertCondition 
 *		��ȡ����֤�������
 *	������
 *		��
 *	����ֵ��
 *		�ɹ����ع���֤���������ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetFilterCertCondition(void);


/*
 *	NetcaPKIConfigReset 
 *		���»�ȡĬ�ϵ�����
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigReset(void);

/*
 *	NetcaPKIConfigGetSignAlgo 
 *		��ȡǩ���㷨
 *	������
 *		cert�����������ǩ��֤��
 *		param�����������ǩ���㷨����������ΪNULL
 *	����ֵ��
 *		�ɹ�����ǩ���㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIConfigGetSignAlgo(NETCA_PKI_CERTIFICATE_HANDLE cert,void **param);

/*
 *	NetcaPKIConfigSetSignAlgo 
 *		����ǩ���㷨
 *	������
 *		publicKeyType�������������Կ���ͣ�RSA��SM2��
 *		algo�����������ǩ���㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetSignAlgo(const char* publicKeyType,int algo);


/*
 *	NetcaPKIConfigGetPublicKeyEncryptAlgo 
 *		��ȡ��Կ�����㷨
 *	������
 *		cert���������������֤��
 *		param�������������Կ�����㷨����������ΪNULL
 *	����ֵ��
 *		�ɹ����ع�Կ�����㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIConfigGetPublicKeyEncryptAlgo(NETCA_PKI_CERTIFICATE_HANDLE cert,void **param);

/*
 *	NetcaPKIConfigSetPublicKeyEncryptAlgo 
 *		���ù�Կ�����㷨
 *	������
 *		publicKeyType�������������Կ���ͣ�RSA��SM2��
 *		algo�������������Կ�����㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetPublicKeyEncryptAlgo(const char* publicKeyType,int algo);


/*
 *	NetcaPKIConfigEnvelopedDataGetEncryptAlgo 
 *		��ȡ�����ŷ�ĶԳƼ����㷨
 *	������
 *		��
 *	����ֵ��
 *		�ɹ����������ŷ�ĶԳƼ����㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataGetEncryptAlgo(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetEncryptAlgo 
 *		���������ŷ�ԳƼ����㷨
 *	������
 *		algo����������������ŷ�ԳƼ����㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetEncryptAlgo(int algo);


/*
 *	NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier 
 *		��ȡ�����ŷ���Ƿ�ʹ��������Կ��ʶ���ʶ����֤��
 *	������
 *		��
 *	����ֵ��
 *		���������ŷ���Ƿ�ʹ��������Կ��ʶ���ʶ����֤��
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier 
 *		���������ŷ���Ƿ�ʹ��������Կ��ʶ���ʶ����֤��
 *	������
 *		value�����������Ϊ���ʾʹ�ã�Ϊ�ٱ�ʾ��ʹ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier(int value);

/*
 *	NetcaPKIConfigSetPwdCacheOption 
 *		�����Ƿ�������뻺��
 *	������
 *		option�����������1Ϊ�����棬0Ϊ���棬-1Ϊ�������������ǰ�Ļ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetPwdCacheOption(int option);

/*
 *	NetcaPKIConfigGetPwdCacheOption 
 *		��ȡ�Ƿ�������뻺��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ������Ƿ�������뻺�棬ʧ�ܷ���-2
 *
 */
int NETCADLLAPI NetcaPKIConfigGetPwdCacheOption(void);

/*
 *	NetcaPKIConfigSignedDataGetIncludeCertOption 
 *		��ȡSignedData�İ���֤��ѡ��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����SignedData�İ���֤��ѡ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIConfigSignedDataGetIncludeCertOption(void);


/*
 *	NetcaPKIConfigSignedDataSetIncludeCertOption 
 *		����SignedData�İ���֤��ѡ��
 *	������
 *		option:���������SignedData�İ���֤��ѡ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSignedDataSetIncludeCertOption(int option);


/*
 *	NetcaPKIConfigSetConfig 
 *		��������
 *	������
 *		config:������������õ�JSON���룬UTF-8��ʽ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigSetConfig(const char* config);

/*
 *	NetcaPKIConfigGetConfig 
 *		��ȡ����
 *	������
 *		��
 *	����ֵ��
 *		�ɹ��������õ�JSON���룬UTF-8��ʽ��ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIConfigGetConfig(void);

/*
 *	NetcaPKIAppCertEncrypt 
 *		ʹ��֤����зǶԳƼ���
 *	������
 *		cert:�������������֤��
 *		clearText:�������������
 *		clearTextLen:������������ĳ���
 *		cipherText:����������ɹ���������
 *		cipherTextLen:����������ɹ��������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppCertEncrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* clearText,int clearTextLen,unsigned char** cipherText,int* cipherTextLen);

/*
 *	NetcaPKIAppCertDecrypt 
 *		ʹ��֤���Ӧ��˽Կ���зǶԳƼ���
 *	������
 *		cert:�������������֤��
 *		cipherText:�������������
 *		cipherTextLen:������������ĳ���
 *		clearText:����������ɹ���������
 *		clearTextLen:����������ɹ��������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppCertDecrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* cipherText,int cipherTextLen,unsigned char** clearText,int* clearTextLen);

/*
 *	NetcaPKIAppSign 
 *		ʹ��֤���Ӧ��˽Կ����ǩ��
 *	������
 *		cert:���������ǩ��֤��
 *		tbs:���������ԭ��
 *		tbsLen:���������ԭ�ĳ���
 *		signature:����������ɹ�����ǩ��ֵ
 *		signatureLen:����������ɹ�����ǩ��ֵ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSign(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* tbs,int tbsLen,unsigned char** signature,int* signatureLen);

/*
 *	NetcaPKIAppVerify 
 *		ʹ��֤�������֤
 *	������
 *		cert:���������ǩ��֤��
 *		tbs:���������ԭ��
 *		tbsLen:���������ԭ�ĳ���
 *		signature:���������ǩ��ֵ
 *		signatureLen:���������ǩ��ֵ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppVerify(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* tbs,int tbsLen,const unsigned char* signature,int signatureLen);

/*
 *	NetcaPKIAppEnvelopedDataEncrypt 
 *		ʹ�������ŷ���м���
 *	������
 *		cert:���������ǩ��֤��
 *		clearText:�������������
 *		clearTextLen:������������ĳ���
 *		cipherText:����������ɹ����������ŷ�
 *		cipherTextLen:����������ɹ����������ŷⳤ��
 *		hEnvelopedData:����������ɹ����������ŷ���������ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataEncrypt(NETCA_PKI_CERTIFICATE_HANDLE cert,const unsigned char* clearText,int clearTextLen,unsigned char** cipherText,int* cipherTextLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);

/*
 *	NetcaPKIAppNewEnvelopedDataEncryptHandle 
 *		���������ŷ���ܾ��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�������Ч�������ŷ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewEnvelopedDataEncryptHandle(void);

/*
 *	NetcaPKIConfigEnvelopedDataSetDecryptCert 
 *		���������ŷ����֤�飬֤������ж�Ӧ����Կ��
 *	������
 *		cert:�������������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIConfigEnvelopedDataSetDecryptCert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIAppEnvelopedDataDecrypt 
 *		���������ŷ�
 *	������
 *		cipherText:��������������ŷ�
 *		cipherTextLen����������������ŷ�ĳ���
 *		clearText������������ɹ���������
 *		clearTextLen������������ɹ��������ĵĳ���
 *		hEnvelopedData������������ɹ����������ŷ���������ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataDecrypt(const unsigned char* cipherText,int cipherTextLen,unsigned char** clearText,int* clearTextLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);


/*
 *	NetcaPKIAppNewEnvelopedDataDecryptHandle 
 *		���������ŷ���ܾ��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�������Ч�������ŷ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewEnvelopedDataDecryptHandle(void);

/*
 *	NetcaPKIAppEnvelopedDataDecryptPostCheck 
 *		���������ŷ�����Ƿ��������
 *	������
 *		hEnvelopedData����������������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppEnvelopedDataDecryptPostCheck(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIAppSignedDataSign 
 *		����SignedDataǩ��
 *	������
 *		cert�����������ǩ��֤��
 *		detached�����������Ϊ���ʾ����ԭ�ģ������ԭ��
 *		tbs�����������Ҫǩ��������
 *		tbsLen�����������Ҫǩ�������ݳ���
 *		signature������������ɹ�����SignedData
 *		signatureLen������������ɹ�����SignedData����
 *		hSignedData������������ɹ�����SignedData���������ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataSign(NETCA_PKI_CERTIFICATE_HANDLE cert,int detached,const unsigned char* tbs,int tbsLen,unsigned char** signature,int* signatureLen,NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIAppSignedDataApplySignConfig 
 *		ʹ��������Ϣ��������SignedDataǩ��
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataApplySignConfig(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIAppSignedDataVerify 
 *		��֤SignedDataǩ��
 *	������
 *		cert�����������ǩ��֤�飬����ΪNULL�������ΪNULL�������Ϊ���е�һ��ǩ��֤��
 *		tbs�����������Ҫǩ��������
 *		tbsLen�����������Ҫǩ�������ݳ���
 *		signature�����������SignedData
 *		signatureLen�����������SignedData����
 *		hSignedData������������ɹ�����SignedData���������ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataVerify(NETCA_PKI_CERTIFICATE_HANDLE cert, const unsigned char* tbs,int tbsLen, const unsigned char* signature,int signatureLen, NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIAppNewSignedDataVerifyHandle 
 *		�������ô�����֤SignedDataǩ���ľ��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�������Ч��SignedData�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIAppNewSignedDataVerifyHandle(void);

/*
 *	NetcaPKIAppSignedDataVerifyPostCheck 
 *		��֤SignedData�����Ƿ��������
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataVerifyPostCheck(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);

/*
 *	NetcaPKIAppTimeStampGetToken 
 *		��ʱ�������������ȡʱ���Token
 *	������
 *		data�����������Ҫ�ύ������
 *		dataLen�����������Ҫ�ύ�����ݵĳ���
 *		token������������ɹ�����ʱ���Token
 *		tokenLen������������ɹ�����ʱ���Token�ĳ���
 *		hTimeStamp������������ɹ�����ʱ������,����ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int  NETCADLLAPI NetcaPKIAppTimeStampGetToken(const unsigned char* data,int dataLen, unsigned char** token,int* tokenLen,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);

/*
 *	NetcaPKIAppTimeStampVerifyToken 
 *		��֤ʱ���Token
 *	������
 *		data�����������Ҫ�ύ������
 *		dataLen�����������Ҫ�ύ�����ݵĳ���
 *		token�����������ʱ���Token
 *		tokenLen�������������ʱ���Token�ĳ���
 *		hTimeStamp������������ɹ�����ʱ������,����ΪNULL
 *	����ֵ��
 *		�ɹ�����ʱ���ʱ�䣬ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppTimeStampVerifyToken(const unsigned char* data,int dataLen,const unsigned char* token,int tokenLen,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);

/*
 *	NetcaPKIAppSignedDataAttachTimeStamp 
 *		��ǩ�������ʱ���������Ѿ�����ʱ����������µ������������ж��ǩ��ֵ��ֻ�������һ��
 *	������
 *		hSignedData��SignedData���
 *		signature������������ɹ��������ʱ������SignedData
 *		signatureLen������������ɹ��������ʱ������SignedData�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppSignedDataAttachTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char** signature,int* signatureLen);


/*
 *	NetcaPKIAppGetUserCert 
 *		��ȡ�û�֤��
 *	������
 *		type�����������֤������
 *		condition�����������ѡ��֤�������
 *	����ֵ��
 *		�ɹ����ػ�ȡ����֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIAppGetUserCert(int type,const char* condition);

/*
 *	NetcaPKIAppCertGetKeypair 
 *		��ȡ֤���Ӧ����Կ�Ծ��
 *	������
 *		cert�����������֤��
 *		pwd�����������ʹ��˽Կ��Ҫ�����룬ͨ������ΪNULL
 *		hKeypair:����������ɹ�������Կ�Ծ��������ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppCertGetKeypair(NETCA_PKI_CERTIFICATE_HANDLE cert, const char *pwd,NETCA_PKI_KEYPAIR_HANDLE* hKeypair);

/*
 *	NetcaPKIAppCertGetStringExtension 
 *		��ȡ֤����ַ������͵���չ��ֵ
 *	������
 *		cert�����������֤��
 *		extOid�������������չ��OID
 *	����ֵ��
 *		�ɹ�����UTF-8�������չֵ��ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppCertGetStringExtension(NETCA_PKI_CERTIFICATE_HANDLE cert,const char* extOid);

/*
 *	NetcaPKIAppDeviceGetDeviceId 
 *		��ȡ��ǰ���ӵ������豸��ID����ʽΪ�豸����#�豸���к�
 *	������
 *		ids������������ɹ��������е��豸��ID
 *		idCount������������ɹ������豸�ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceGetDeviceId(char*** ids,int* idCount);

/*
 *	NetcaPKIAppDeviceVerifyPwd 
 *		��֤�豸������
 *	������
 *		id������������豸��ID
 *		pwd������������豸������
 *		retryNum������������������ʱ���������Դ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceVerifyPwd(const char* id,const char *pwd,int *retryNum);


/*
 *	NetcaPKIAppDeviceIsDeviceConnent 
 *		�ж��Ƿ����豸����
 *	������
 *		��
 *	����ֵ��
 *		�з���1���޷���0
 *
 */
int NETCADLLAPI NetcaPKIAppDeviceIsDeviceConnent(void);

/*
 *	NetcaPKIAppGetVersionInfo 
 *		��ȡ�汾��Ϣ
 *	������
 *		��
 *	����ֵ��
 *		�ɹ����ذ汾��Ϣ��ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAppGetVersionInfo(void);


#ifdef __cplusplus
	}	
#endif
#endif
