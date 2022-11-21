#ifndef NETCA_PKI_CRYPTO_UI_INLCUDE_H
#define NETCA_PKI_CRYPTO_UI_INLCUDE_H

#ifdef _WIN32
#include <windows.h>
typedef HWND NETCA_UI_HANDLE;
#else
#include <wchar.h>
typedef void * NETCA_UI_HANDLE;
#endif
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIUIGetPassword
 *		�����Ի����ȡ���������
 *	������
 *		hParentWnd����������������ھ��
 *		msg�������������ʾ��Ϣ��UTF-8����
 *		pwd��������������ص����룬ʹ��NetcaPKICryptoFreeMemory���ͷ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIUIGetPassword(NETCA_UI_HANDLE hParentWnd,const char *msg,char **pwd);

/*
 *	NetcaPKIUIVerifyPassword
 *		�����Ի����ȡ��������벢��֤��
 *	������
 *		hParentWnd����������������ھ��
 *		hDevice���豸���
 *		type������������������ͣ�NETCA_PKI_USER_PWD��ʾ�û����룬NETCA_PKI_SO_PWD��ʾ����Ա����
 *		msg�������������ʾ��Ϣ��UTF-8����
 *		pwd��������������ص����룬ʹ��NetcaPKICryptoFreeMemory���ͷ�
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIUIVerifyPassword(NETCA_UI_HANDLE hParentWnd,NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *msg,char **pwd);

/*
 *	NetcaPKIUIDisplayCert
 *		��ʾ֤�顣
 *	������
 *		hParentWnd����������������ھ��
 *		hCert��֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIUIDisplayCert(NETCA_UI_HANDLE hParentWnd, NETCA_PKI_CERTIFICATE_HANDLE  hCert);

/*
 *	NetcaPKIUIDisplayCRL
 *		��ʾCRL��
 *	������
 *		hParentWnd����������������ھ��
 *		crl���������,CRL�ı���
 *		crllen���������,CRL�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIUIDisplayCRL(NETCA_UI_HANDLE hParentWnd, const unsigned char *crl,int crllen);

/*
 *	NetcaPKIUISelectCert
 *		�����Ի���ѡ��֤�顣
 *	������
 *		hParentWnd����������������ھ��
 *		title���������,�Ի������
 *		msg���������,�Ի�����ʾ��Ϣ
 *		certs�����������һ��֤��
 *		count�����������֤�����
 *	����ֵ��
 *		�ɹ�����ѡ���֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIUISelectCert(NETCA_UI_HANDLE hParentWnd, const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);

#define NETCA_PKI_UI_MESSAGE_ID_LOGIN				1
#define NETCA_PKI_UI_MESSAGE_ID_GEN_KEYPAIR			2
#define NETCA_PKI_UI_MESSAGE_ID_IMPORT_KEYPAIR		3
#define NETCA_PKI_UI_MESSAGE_ID_DELETE_KEYPAIR		4
#define NETCA_PKI_UI_MESSAGE_ID_WRITE_CERT			5
#define NETCA_PKI_UI_MESSAGE_ID_DELETE_CERT			6
#define NETCA_PKI_UI_MESSAGE_ID_SIGN				7
#define NETCA_PKI_UI_MESSAGE_ID_PRIVKEY_DECRYPT		8
#define NETCA_PKI_UI_MESSAGE_ID_ENVELOPEDDATA_PRIVKEY_DECRYPT		9
#define NETCA_PKI_UI_MESSAGE_ID_SIGNEDDATA_SIGN		10
#define NETCA_PKI_UI_MESSAGE_ID_KEYAGREEMENT		11


/*
 *	NetcaPKIUIGetString
 *		��ȡĬ�ϵ���ʾ��Ϣ��
 *	������
 *		id�������������Ϣ��ID��
 *	����ֵ��
 *		�ɹ�������Ӧ����Ϣ��UTF-8���룬ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKIUIGetString(int id);


#ifdef __cplusplus
	}	
#endif

#endif
