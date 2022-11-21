#ifndef _NETCA_PKI_INTERNAL_INLCUDE_H_
#define _NETCA_PKI_INTERNAL_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif


/*
 *	NetcaPKICertSetTrustAnchor
 *		���õ�ǰ����ʹ�õ�TrustAnchor
 *	������
 *		flag�������������־
 *		store��TrustAnchor������ɵ�֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetTrustAnchor(int flag,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertSetCACert
 *		���õ�ǰ����ʹ�õ�CA֤��
 *	������
 *		flag�������������־
 *		store��CA֤�鼯����ɵ�֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetCACert(int flag,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKICertGetTrustAnchor
 *		��ȡTrustAnchor
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����TrustAnchor������ɵ�֤��⣬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertGetTrustAnchor(void);

/*
 *	NetcaPKICertGetCACert
 *		��ȡCA֤��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����CA֤�鼯����ɵ�֤��⣬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_STORE NETCADLLAPI NetcaPKICertGetCACert(void);

/*
 *	NetcaPKICryptoSetDeviceFlag
 *		���õ�ǰ����ʹ�õļ����豸�ı�־
 *	������
 *		flag�������������־
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDeviceFlag(int flag);

/*
 *	NetcaPKICryptoGetDeviceFlag
 *		��ȡ��ǰ����ʹ�õļ����豸�ı�־
 *	������
 *		��
 *	����ֵ��
 *		�ɹ����ؼ����豸�ı�־
 *
 */
int NETCADLLAPI NetcaPKICryptoGetDeviceFlag(void);


/*
 *	NetcaPKICertSetSelectCertConfig
 *		���õ�ǰ����ʹ�õ�ѡ��֤�������
 *	������
 *		config����������������ַ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetSelectCertConfig(const char *config);


/*
 *	NetcaPKICertGetSelectCertConfig
 *		��ȡ��ǰ����ʹ�õ�ѡ��֤�������
 *	������
 *		��
 *	����ֵ��
 *		�ɹ����������ַ��������û�л���ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKICertGetSelectCertConfig(void);


/*
 *	NetcaPKISetSM2SignParamConfig
 *		����SM2ǩ���Ĳ�������
 *	������
 *		useNull��������������Ϊ�棬��ʾʹ��NULL��Ϊ���򲻱���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKISetSM2SignParamConfig(int useNull);


/*
 *	NetcaPKIGetSM2SignParamConfig
 *		��ȡSM2ǩ���Ĳ�������
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����SM2ǩ���Ĳ�������
 *
 */
int NETCADLLAPI NetcaPKIGetSM2SignParamConfig(void);


/*
 *	NetcaPKICryptoSetDefaultDeviceConfig
 *		���õ�ǰ����ʹ�õ�Ĭ�ϼ����豸
 *	������
 *		config����������������ַ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetDefaultDeviceConfig(const char *config);

/*
 *	NetcaPKICryptoGetDefaultDevice
 *		��ȡĬ�ϵļ����豸
 *	������
 *		algo����������������㷨
 *		usage�������������;
 *	����ֵ��
 *		�ɹ�����Ĭ�ϵļ����豸�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_DEVICE_HANDLE NETCADLLAPI NetcaPKICryptoGetDefaultDevice(int algo,int usage);

/*
 *	NetcaPKICryptoAddHttpAuthInfo
 *		����HTTP����֤��Ϣ
 *	������
 *		url�����������HTTP��URL
 *		authFlag:�����������֤�ķ�ʽ
 *		cert:���������SSL˫����֤�Ŀͻ���֤�飬����Ҫ�й�������Կ��
 *		userName������������û���
 *		pwd:�������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoAddHttpAuthInfo(const char *url,int authFlag,NETCA_PKI_CERTIFICATE_HANDLE cert,const char *userName,const char *pwd);

/*
 *	NetcaPKICryptoClearHttpAuthInfo
 *		���HTTP����֤��Ϣ
 *	������
 *		url�����������HTTP��URL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoClearHttpAuthInfo(const char *url);

/*
 *	NetcaPKICryptoGetHttpAuthInfo
 *		��ȡ���õ�HTTP����֤��Ϣ
 *	������
 *		url�����������HTTP��URL
 *		authFlag:�����������֤�ķ�ʽ
 *		cert:���������SSL˫����֤�Ŀͻ���֤�飬����Ҫ�й�������Կ��
 *		userName������������û���
 *		pwd:�������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS�������ڷ���NETCA_PKI_NOTEXISIT��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHttpAuthInfo(const char *url,int *authFlag,NETCA_PKI_CERTIFICATE_HANDLE *cert,char **userName,char **pwd);

/*
 *	NetcaPKICryptoSetHttpProxy
 *		����HTTP����
 *	������
 *		host�����������HTTP�Ĵ����������
 *		port�����������HTTP����Ķ˿ں�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpProxy(const char *host,int port);

/*
 *	NetcaPKICryptoGetHttpProxy
 *		��ȡHTTP����
 *	������
 *		host������������ɹ�����HTTP�Ĵ����������
 *		port������������ɹ�����HTTP����Ķ˿ں�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHttpProxy(char **host,int* port);
/*
 *	NetcaPKICryptoAddNotUseHttpProxyHost
 *		��Ӳ�ʹ��HTTP���������
 *	������
 *		host�����������������HTTP�Ĵ����������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoAddNotUseHttpProxyHost(const char *host);
/*
 *	NetcaPKICryptoDeleteNotUseHttpProxyHost
 *		ɾ����ʹ��HTTP���������
 *	������
 *		host�����������Ҫɾ���Ĳ�����HTTP�Ĵ����������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoDeleteNotUseHttpProxyHost(const char *host);

/*
 *	NetcaPKICryptoGetNotUseHttpProxyHosts
 *		��ȡ���в�ʹ��HTTP������������б�
 *	������
 *		hosts������������ɹ��������в�ʹ��HTTP������������б�
 *		count������������ɹ��������в�ʹ��HTTP�������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetNotUseHttpProxyHosts(char ***hosts,int* count);

/*
 *	NetcaPKICryptoHttpGet
 *		ͨ��HTTP��Get������ȡ����
 *	������
 *		url�����������HTTP��URL
 *		reqHeads:������������ӵ�HTTPͷ�򣬿���ΪNULL
 *		reqHeadCount��������������ӵ�HTTPͷ�ĸ���
 *		status:�������������HTTP״̬��
 *		contentType:���������������ص�ContentType,�������ΪNULL�������
 *		data:������������ػ�ȡ������
 *		dataLen��������������ػ�ȡ�����ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoHttpGet(const char *url,const char *reqHeads[],int reqHeadCount,int *status,char **contentType,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICryptoHttpPost
 *		ͨ��HTTP��Post������ȡ����
 *	������
 *		url�����������HTTP��URL
 *		reqHeads:������������ӵ�HTTPͷ�򣬿���ΪNULL
 *		reqHeadCount��������������ӵ�HTTPͷ�ĸ���
 *		data:�����������������
 *		dataLen������������������ݵĳ���
 *		status:�������������HTTP״̬��
 *		contentType:���������������ص�ContentType,�������ΪNULL�������
 *		resp:������������ػ�ȡ������
 *		respLen��������������ػ�ȡ�����ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoHttpPost(const char *url,const char *reqHeads[],int reqHeadCount,const unsigned char *data,int dataLen,int *status,char **contentType,unsigned char **resp,int *respLen);

/*
 *	NetcaPKICryptoSetHttpImplement
 *		����HTTP��ʵ��
 *	������
 *		name�����������HTTPʵ�ֵ�����,UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpImplement(const char *name);

/*
 *	NetcaPKICryptoSetHttpsVerifyFlag
 *		����HTTPS����֤��־
 *	������
 *		name�����������HTTPS����֤��־
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpsVerifyFlag(int flag);


/*
 *	NetcaPKICryptoSetHttpTimeout
 *		����HTTP�ĳ�ʱʱ��
 *	������
 *		timeout�������������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetHttpTimeout(int timeout);

/*
 *	NetcaPKICryptoGetHttpTimeout
 *		��ȡHTTP�ĳ�ʱʱ��
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����HTTP�ĳ�ʱ������
 *
 */
int NETCADLLAPI NetcaPKICryptoGetHttpTimeout(void);


/*
 *	NetcaPKICryptoLdapGetAttributes
 *		ͨ��Ldap��ȡ����
 *	������
 *		url�����������LDAP��URL
 *		names:������������ػ�ȡ������������
 *		values:������������ػ�ȡ������ֵ����
 *		valueLens��������������ػ�ȡ�����Գ�������
 *		count��������������ػ�ȡ��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoLdapGetAttributes(const char *url,char ***names,unsigned char ***values,int **valueLens,int* count);

/*
 *	NetcaPKICryptoLdapSearch
 *		ͨ��Ldap��������
 *	������
 *		host�����������LDAP����������ASCII����
 *		port�����������LDAP�Ķ˿ںţ�-1ΪĬ�϶˿ں�
 *		flag�������������־
 *		baseDN�����������������ʼ��DN��UTF-8����
 *		scope:��������������ķ�Χ
 *		filter��������������˱��ʽ��UTF-8����
 *		sizeLimit:������������ص���Ŀ���������
 *		attrNames:���������Ҫ��ȡ������������,������ΪUTF-8����
 *		attrNameCount��������������Ը���
 *		names:������������ػ�ȡ������������
 *		values:������������ػ�ȡ������ֵ����
 *		valueLens��������������ػ�ȡ�����Գ�������
 *		count��������������ػ�ȡ��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoLdapSearch(const char *host,int port,int flag,const char *baseDN,int scope,const char *filter,int sizeLimit,const char **attrNames,int attrNameCount,char ***names,unsigned char ***values,int **valueLens,int* count);

/*
 *	NetcaPKICryptoSetLdapImplement
 *		����LDAP��ʵ��
 *	������
 *		name�����������LDAPʵ�ֵ�����,UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetLdapImplement(const char *name);

/*
 *	NetcaPKICryptoAddTSACert
 *		������ε�TSA֤��
 *	������
 *		cert��������������ε�TSA֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoAddTSACert(NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKICryptoGetTSACerts
 *		��ȡ���ε�TSA֤��
 *	������
 *		certs��������������ε�TSA֤��
 *		count��������������ε�TSA֤��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoGetTSACerts(NETCA_PKI_CERTIFICATE_HANDLE **certs,int *count);

/*
 *	NetcaPKICertGetAllowCertType
 *		��ȡ�����֤������
 *	������
 *		allowCertType������������ɹ����������֤������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertGetAllowCertType(char **allowCertType);
/*
 *	NetcaPKICertSetAllowCertType
 *		���������֤������
 *	������
 *		allowCertType����������������֤�����ͣ�NULLΪ�������е�֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKICertSetAllowCertType(const char *allowCertType);

/*
 *	NetcaPKICryptoSetExplicitlyTrustTSACert
 *		�����Ƿ�Ҫ����ʽ����ʱ���TSA֤��
 *	������
 *		value�����������Ϊ���ʾҪ����ʽ����ʱ���TSA֤�飬Ҳ���ǽ�������NetcaPKICryptoAddTSACert��ӵ���Щʱ���TSA֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICryptoSetExplicitlyTrustTSACert(int value);

/*
 *	NetcaPKICryptoGetExplicitlyTrustTSACert
 *		�ж��Ƿ�Ҫ����ʽ����ʱ���TSA֤��
 *	������
 *		��
 *	����ֵ��
 *		Ҫ����ʽ����ʱ���TSA֤�鷵��1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKICryptoGetExplicitlyTrustTSACert(void);

/*
 *	NetcaPKIUISetUIFunction
 *		����UI����
 *	������
 *		UIVerifyPasswordFunction����������������Ի����ȡ��������벢��֤�Ļص�����
 *		UISelectCertFunction����������������Ի���ѡ��֤��Ļص�����
 *		UIGetStringFunction�������������ȡĬ�ϵ���ʾ��Ϣ�Ļص�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIUISetUIFunction(NetcaPKIUIVerifyPassword_Ptr UIVerifyPasswordFunction,NetcaPKIUISelectCert_Ptr UISelectCertFunction,NetcaPKIUIGetString_Ptr UIGetStringFunction);


/*
 *	NetcaPKICryptoSetInitString
 *		�����豸�ĳ�ʼ���ַ���
 *	������
 *		type������������豸����
 *		initString������������豸�ĳ�ʼ���ַ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKICryptoSetInitString(int type,const char *initString);

/*
 *	NetcaPKICryptoResetInitString
 *		�����豸�ĳ�ʼ���ַ���
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKICryptoResetInitString(int type);

/*
 *	NetcaPKICryptoGetInitString
 *		��ȡ�豸�ĳ�ʼ���ַ���
 *	������
 *		type������������豸����
 *	����ֵ��
 *		�ɹ������豸�ĳ�ʼ���ַ�����ʧ�ܻ�û�з���NULL
 */
char *NETCADLLAPI NetcaPKICryptoGetInitString(int type);


/*
 *	NetcaPKICertSetEntityUniqueIdConfig 
 *		����֤���ʵ��Ψһ��ʶ��ѡ�����
 *	������
 *		config�����������֤���ʵ��Ψһ��ʶ��ѡ�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertSetEntityUniqueIdConfig(const char* config);


/*
 *	NetcaPKICertGetEntityUniqueIdConfig 
 *		��ȡ֤���ʵ��Ψһ��ʶ��ѡ�����
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����֤���ʵ��Ψһ��ʶ��ѡ����ԣ�ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKICertGetEntityUniqueIdConfig(void);

#ifdef __cplusplus
	}	
#endif
#endif
