#ifndef NETCA_PKI_TRUSTENV_H
#define NETCA_PKI_TRUSTENV_H

#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


/*
 *		NetcaPKIEnvLoad
 *			װ�ذ�ȫ����
 *		������
 *			data�������������ȫ������������
  *			datalen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvLoad(const unsigned char *data,int datalen);

/*
 *		NetcaPKIEnvLoadFromFile
 *			װ�ذ�ȫ����
 *		������
 *			filename�������������ȫ�����ļ�����UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvLoadFromFile(const char *filename);

/*
 *		NetcaPKIEnvLoadDefaultEnv
 *			װ��ȱʡ�İ�ȫ����
 *		������
 *			�ޡ�
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvLoadDefaultEnv(void);

/*
 *		NetcaPKIEnvSave
 *			���氲ȫ����
 *		������
 *			filename�������������ȫ�����ļ�����UTF-8���룬���ΪNULL����Ϊȱʡ�İ�ȫ������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvSave(const char *filename);

/*
 *		NetcaPKIEnvGetAllRootCerts
 *			��ȡ���еĸ�֤��
 *		������
 *			pCerts��������������ص�֤��
 *			count��������������ص�֤�����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvGetAllRootCerts(NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

/*
 *		NetcaPKIEnvGetAllCACerts
 *			��ȡ���е�CA֤��
 *		������
 *			pCerts��������������ص�֤��
  *			count��������������ص�֤�����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvGetAllCACerts(NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

/*
 *		NetcaPKIEnvAddRootCert
 *			��Ӹ�֤�鵽���λ���
 *		������
 *			name�������������CA�����ƣ�UTF-8����
 *			cert�������������֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddRootCert(const char *name,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvAddCACert
 *			���CA֤�鵽���λ���
 *		������
 *			name����������� CA�����ƣ�UTF-8����
 *			cert�����������CA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddCACert(const char *name,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvGetCACert
 *			�������ƻ�ȡCA֤����߸�֤��
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����֤������ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetCACert(const char *name);


/*
 *		NetcaPKIEnvUpdateRootCert
 *			���¸�֤��
 *		������
 *			name�������������CA�����ƣ�UTF-8����
 *			cert�������������֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateRootCert(const char *name, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvUpdateCACert
 *			����CA֤��
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			cert�����������CA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateCACert(const char *name, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteRootCA
 *			ɾ����CA
 *		������
 *			name�������������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteRootCA(const char *name);

/*
 *		NetcaPKIEnvDeleteCA
 *			ɾ��CA
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteCA(const char *name);

/*
 *		NetcaPKIEnvGetCRL
 *			��ȡCA�䷢��CRL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			crl���������������CRL�ı���
 *			crllen���������������CRL�ı���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvGetCRL(const char *name, unsigned char** crl,int *crllen);

/*
 *		NetcaPKIEnvGetDeltaCRL
 *			��ȡCA�䷢��Delta CRL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			crl���������������Delta CRL�ı���
 *			crllen���������������Delta CRL�ı���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvGetDeltaCRL(const char *name, unsigned char** crl,int *crllen);

/*
 *		NetcaPKIEnvUpdateCRL
 *			����CA�䷢��CRL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			crl�����������CRL�ı���
 *			crllen�����������CRL�ı���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateCRL(const char *name, const unsigned char* crl,int crllen);

/*
 *		NetcaPKIEnvUpdateDeltaCRL
 *			����CA�䷢��Delta CRL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			crl�����������Delta CRL�ı���
 *			crllen�����������Delta CRL�ı���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateDeltaCRL(const char *name, const unsigned char* crl,int crllen);

/*
 *		NetcaPKIEnvGetCRLURL
 *			��ȡCA�䷢��CRL��URL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ����ػ�ȡCA�䷢��CRL��URL��UTF-8���룬ʧ�ܷ���NULL
 */
char*  NETCADLLAPI NetcaPKIEnvGetCRLURL(const char *name);

/*
 *		NetcaPKIEnvGetDeltaCRLURL
 *			��ȡCA�䷢��Delta CRL��URL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ����ػ�ȡCA�䷢��Delta CRL��URL��UTF-8���룬ʧ�ܷ���NULL
 */
char*  NETCADLLAPI NetcaPKIEnvGetDeltaCRLURL(const char *name);

/*
 *		NetcaPKIEnvUpdateCRLURL
 *			���û�ȡCA�䷢��CRL��URL
 *		������
 *			name�����������CA�����ƣ�UTF-8���룬UTF-8����
 *			url�������������ȡCA�䷢��CRL��URL
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateCRLURL(const char *name, const char *url);

/*
 *		NetcaPKIEnvUpdateDeltaCRLURL
 *			���û�ȡCA�䷢��Delta CRL��URL
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			url�������������ȡCA�䷢��Delta CRL��URL��UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateDeltaCRLURL(const char *name, const char *url);

/*
 *		NetcaPKIEnvGetVerifyParam
 *			��ȡ��֤֤��ʹ�õĲ���
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�������֤֤��ʹ�õĲ�����UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetVerifyParam(const char *name);

/*
 *		NetcaPKIEnvUpdateVerifyParam
 *			���û�ȡ��֤֤��ʹ�õĲ���
 *		������
 *			name�����������CA�����ƣ�UTF-8����
 *			param�������������֤֤��ʹ�õĲ�����UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateVerifyParam(const char *name,const char *param);

/*
 *		NetcaAddressBookClose
 *			���OCSP
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *			url�����������OCSP��URL��UTF-8����
 *			hashalgo�����������֧�ֵ�OCSP�����Hash�㷨
 *			usenonce�����������Ϊ���ʾ֧��Nonce��Ϊ�ٱ�ʾ��֧��
 *			cert�����������OCSP������֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddOCSP(const char *name,const char *url,int hashalgo,int usenonce, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteOCSP
 *			ɾ��OCSP
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteOCSP(const char *name);

/*
 *		NetcaPKIEnvUpdateOCSP
 *			����OCSP��Ϣ
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *			url�����������OCSP��URL��UTF-8����
 *			hashalgo�����������֧�ֵ�OCSP�����Hash�㷨
 *			usenonce�����������Ϊ���ʾ֧��Nonce��Ϊ�ٱ�ʾ��֧��
 *			cert�����������OCSP������֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateOCSP(const char *name,const char *url,int hashalgo,int usenonce, NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *		NetcaPKIEnvGetOCSPURL
 *			��ȡOCSP��URL
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����OCSP��URL��UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPURL(const char *name);

/*
 *		NetcaPKIEnvGetOCSPHashAlgo
 *			��ȡOCSP��Hash�㷨
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����OCSP��Hash�㷨��ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKIEnvGetOCSPHashAlgo(const char *name);

/*
 *		NetcaPKIEnvIsOCSPUseNonce
 *			��ȡOCSP�Ƿ�֧��Nonce
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			���OCSP֧��Nonce����1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsOCSPUseNonce(const char *name);

/*
 *		NetcaPKIEnvGetOCSPCert
 *			��ȡOCSP֤��
 *		������
 *			name�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����OCSP֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetOCSPCert(const char *name);

/*
 *		NetcaPKIEnvGetAllOCSPCount
 *			��ȡOcsp�ĸ���
 *		������
 *			�ޡ�
 *		����ֵ��
 *			�ɹ�����Ocsp�ĸ�����ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKIEnvGetAllOCSPCount();

/*
 *		NetcaPKIEnvGetOCSPNameByIndex
 *			��ȡ��index��Ocsp����
 *		������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�index��Ocsp���ƣ�UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPNameByIndex(int index);

/*
 *		NetcaPKIEnvAddOCSPToCA
 *			��CA���OCSP��Ϣ
 *		������
 *			caname�����������CA�����ƣ�UTF-8����
 *			ocspname�����������OCSP�����ƣ�UTF-8����
 *			isdefault�����������Ϊ���ʾ����CA��ȱʡOCSP��Ϊ������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddOCSPToCA(const char *caname, const char *ocspname,int isdefault);

/*
 *		NetcaPKIEnvDeleteOCSPFromCA
 *			��CA��ɾ��OCSP��Ϣ
 *		������
 *			caname�����������CA�����ƣ�UTF-8����
 *			ocspname�����������OCSP�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteOCSPFromCA(const char *caname, const char *ocspname);

/*
 *		NetcaPKIEnvGetDefaultOCSP
 *			��ȡCA��ȱʡOCSP��
 *		������
 *			caname�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����CAȱʡ��OCSP��ʧ�ܷ���NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetDefaultOCSP(const char *caname);

/*
 *		NetcaPKIEnvGetOCSPCount
 *			��ȡCA��OCSP����
 *		������
 *			caname�����������CA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����CA��OCSP������ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKIEnvGetOCSPCount(const char *caname);

/*
 *		NetcaPKIEnvGetOCSPName 
 *			��ȡCA�ĵ�index��OCSP��
 *		������
 *			caname�����������CA�����ƣ�UTF-8����
 *			index���������������ֵ����0����
 *			isdefault�����������ΪȱʡOCSP�򷵻�1�����򷵻�0
 *		����ֵ��
 *			�ɹ�����CA�ĵ�index��OCSP����UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetOCSPName(const char *caname,int index,int * isdefault);

/*
 *		NetcaPKIEnvAddTSA
 *			���TSA
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *			url�����������TSA��URL��UTF-8����
 *			hashalgo�����������֧�ֵ�TSA�����Hash�㷨
 *			policy�����������֧�ֵ�TSA����Ĳ���OID
 *			cert�����������TSA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddTSA(const char *name,const char *url,int hashalgo,const char *policy, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvDeleteTSA
 *			ɾ��TSA
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteTSA(const char *name);

/*
 *		NetcaPKIEnvUpdateTSA
 *			����TSA
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *			url�����������TSA��URL��UTF-8����
 *			hashalgo�����������֧�ֵ�TSA�����Hash�㷨
 *			policy�����������֧�ֵ�TSA����Ĳ���OID
 *			cert�����������TSA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvUpdateTSA(const char *name,const char *url,int hashalgo,const char *policy, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *		NetcaPKIEnvSetDefaultTSA
 *			����ȱʡ��TSA
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvSetDefaultTSA(const char *name);

/*
 *		NetcaPKIEnvGetDefaultTSA
 *			��ȡȱʡ��TSA
 *		������
 *			�ޡ�
 *		����ֵ��
 *			�ɹ�����ȱʡ��TSA����ʧ�ܷ���NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetDefaultTSA(void);

/*
 *		NetcaPKIEnvGetTSAURL 
 *			��ȡTSA��URL
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����TSA��URL��ʧ�ܷ���NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetTSAURL(const char *name);

/*
 *		NetcaPKIEnvGetTSAHashAlgorithm
 *			��ȡTSA��Hash�㷨
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����TSA��Hash�㷨��ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKIEnvGetTSAHashAlgorithm(const char *name);

/*
 *		NetcaPKIEnvGetTSAPolicy
 *			��ȡTSA��֧�ֵĲ���
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����TSA��֧�ֵĲ��ԣ�ʧ�ܷ���NULL
 */
char* NETCADLLAPI NetcaPKIEnvGetTSAPolicy(const char *name);

/*
 *		NetcaPKIEnvGetTSACert
 *			��ȡTSA֤��
 *		������
 *			name�����������TSA�����ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����TSA֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIEnvGetTSACert(const char *name);

/*
 *		NetcaPKIEnvGetTSACount
 *			��ȡTSA�ĸ���
 *		������
 *			�ޡ�
 *		����ֵ��
 *			�ɹ�����TSA�ĸ�����ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKIEnvGetTSACount();

/*
 *		NetcaPKIEnvGetTSAName
 *			��ȡ��index��TSA����
 *		������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�index��TSA���ƣ�UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaPKIEnvGetTSAName(int index);

/*
 *		NetcaPKIEnvIsAcceptableHashAlgorithm
 *			�ж��Ƿ�֧��Hash�㷨
 *		������
 *			algo�����������Hash�㷨
 *		����ֵ��
 *			���֧�ָ�Hash�㷨������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableHashAlgorithm(int algo);

/*
 *		NetcaPKIEnvAddAcceptableHashAlgorithm
 *			���֧�ֵ�Hash�㷨
 *		������
 *			algo�����������Hash�㷨
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableHashAlgorithm(int algo);

/*
 *		NetcaPKIEnvDeleteAcceptableHashAlgorithm
 *			ɾ��Hash�㷨
 *		������
 *			algo�����������Hash�㷨
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableHashAlgorithm (int algo);

/*
 *		NetcaPKIEnvIsAcceptableMacAlgorithm
 *			�ж��Ƿ�֧��Mac�㷨
 *		������
 *			algo�����������Mac�㷨
 *		����ֵ��
 *			���֧�ָ�Mac�㷨������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvAddAcceptableMacAlgorithm
 *			���֧�ֵ�Mac�㷨
 *		������
 *			algo�����������Mac�㷨
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvDeleteAcceptableMacAlgorithm  
 *			ɾ��MAC�㷨
 *		������
 *			algo�����������Hash�㷨
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableMacAlgorithm(int algo);

/*
 *		NetcaPKIEnvIsAcceptableSymmetricAlgorithm
 *			�ж��Ƿ�֧�ֶԳƼ����㷨
 *		������
 *			algo������������ԳƼ����㷨
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			keybits�������������Կ����
 *		����ֵ��
 *			���֧�ָöԳƼ����㷨������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableSymmetricAlgorithm(int algo,int enc,int keybits);

/*
 *		NetcaPKIEnvAddAcceptableSymmetricAlgorithm
 *			���֧�ֵļ����㷨
 *		������
 *			algo������������ԳƼ����㷨
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableSymmetricAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptableSymmetricAlgorithm 
 *			ɾ�������㷨
 *		������
 *			algo������������ԳƼ����㷨
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableSymmetricAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptablePublickeyAlgorithm
 *			�ж��Ƿ�֧�ַǶԳƼ����㷨
 *		������
 *			algo������������ǶԳƼ����㷨�����Ϊ������Կ���㷨������enc
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			keybits�������������Կ����
 *		����ֵ��
 *			���֧�ָ÷ǶԳƼ����㷨������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptablePublicKeyAlgorithm(int algo,int enc,int keybits);

/*
 *		NetcaPKIEnvAddAcceptablePublicKeyAlgorithm
 *			���֧�ֵķǶԳƼ����㷨
 *		������
 *			algo������������ǶԳƼ����㷨�����Ϊ������Կ���㷨������enc
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptablePublicKeyAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptablePublicKeyAlgorithm
 *			ɾ���ǶԳƼ����㷨
 *		������
 *			algo������������ǶԳƼ����㷨�����Ϊ������Կ���㷨������enc
 *			enc�����������Ϊ���ʾ���������ܣ�Ϊ�ٱ�ʾ��������
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptablePublicKeyAlgorithm(int algo,int enc,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptableSignAlgorithm
 *			�ж��Ƿ�֧��ǩ���㷨
 *		������
 *			algo�����������ǩ���㷨
 *			sign�����������Ϊ���ʾ������ǩ����Ϊ�ٱ�ʾ������֤
 *			keybits�������������Կ����
 *		����ֵ��
 *			���֧�ָ�ǩ���㷨������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableSignAlgorithm(int algo,int sign,int keybits);

/*
 *		NetcaPKIEnvAddAcceptableSignAlgorithm
 *			���֧�ֵ�ǩ���㷨
 *		������
 *			algo�����������ǩ���㷨
 *			enc�����������Ϊ���ʾ������ǩ����Ϊ�ٱ�ʾ������֤
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableSignAlgorithm(int algo,int sign,int minkeybits);

/*
 *		NetcaPKIEnvDeleteAcceptableSignAlgorithm
 *			ɾ��ǩ���㷨
 *		������
 *			algo�����������ǩ���㷨
 *			enc�����������Ϊ���ʾ������ǩ����Ϊ�ٱ�ʾ������֤
 *			minkeybits�����������֧�ֵ���С��Կ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableSignAlgorithm(int algo,int sign,int minkeybits);

/*
 *		NetcaPKIEnvIsAcceptableDevice
 *			�ж��Ƿ�֧���豸
 *		������
 *			type������������豸����
 *		����ֵ��
 *			���֧���豸������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableDevice(int type);

/*
 *		NetcaPKIEnvAddAcceptableDevice
 *			���֧�ֵ��豸
 *		������
 *			type������������豸����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableDevice(int type);

/*
 *		NetcaPKIEnvDeleteAcceptableDevice
 *			ɾ��֧�ֵ��豸
 *		������
 *			type������������豸����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableDevice(int type);

/*
 *		NetcaPKIEnvIsAcceptableCSP
 *			�ж��Ƿ�֧��CSP
 *		������
 *			cspname�����������CSP���ƣ�UTF-8����
 *		����ֵ��
 *			���֧�ָ�CSP������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvAddAcceptableCSP
 *			���֧�ֵ�CSP
 *		������
 *			cspname�����������CSP���ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvDeleteAcceptableCSP
 *			ɾ��֧�ֵ�CSP
 *		������
 *			cspname�����������CSP���ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableCSP(const char *cspname);

/*
 *		NetcaPKIEnvIsAcceptablePKCS11
 *			�ж��Ƿ�֧��PKCS#11
 *		������
 *			name�����������PKCS#11���ƣ�UTF-8����
 *		����ֵ��
 *			���֧�ָ�PKCS#11������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvAddAcceptablePKCS11
 *			���֧�ֵ�PKCS#11
 *		������
 *			name�����������PKCS#11���ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvDeleteAcceptablePKCS11
 *			ɾ��֧�ֵ�PKCS#11
 *		������
 *			name�����������PKCS#11���ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptablePKCS11(const char *name);

/*
 *		NetcaPKIEnvIsAcceptableTSAPolicy
 *			�ж��Ƿ�֧��TSA�Ĳ���OID
 *		������
 *			policy�����������TSA�Ĳ���OID
 *		����ֵ��
 *			���֧�ָ�TSA�Ĳ���OID������1�����򷵻�0
 */
int NETCADLLAPI NetcaPKIEnvIsAcceptableTSAPolicy(const char *policy);

/*
 *		NetcaPKIEnvAddAcceptableTSAPolicy
 *			���֧�ֵ�TSA�Ĳ���OID
 *		������
 *			policy�����������TSA�Ĳ���OID
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvAddAcceptableTSAPolicy(const char *policy);

/*
 *		NetcaPKIEnvDeleteAcceptableTSAPolicy
 *			ɾ��֧�ֵ�TSA�Ĳ���OID
 *		������
 *			policy�����������TSA�Ĳ���OID
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKIEnvDeleteAcceptableTSAPolicy(const char *policy);


#ifdef __cplusplus
	}
#endif
#endif
