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
 *		弹出对话框获取输入的密码
 *	参数：
 *		hParentWnd：输入参数，父窗口句柄
 *		msg：输入参数，提示信息，UTF-8编码
 *		pwd：输出参数，返回的密码，使用NetcaPKICryptoFreeMemory来释放
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIUIGetPassword(NETCA_UI_HANDLE hParentWnd,const char *msg,char **pwd);

/*
 *	NetcaPKIUIVerifyPassword
 *		弹出对话框获取输入的密码并验证。
 *	参数：
 *		hParentWnd：输入参数，父窗口句柄
 *		hDevice：设备句柄
 *		type：输入参数，密码类型，NETCA_PKI_USER_PWD表示用户密码，NETCA_PKI_SO_PWD表示管理员密码
 *		msg：输入参数，提示信息，UTF-8编码
 *		pwd：输出参数，返回的密码，使用NetcaPKICryptoFreeMemory来释放
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIUIVerifyPassword(NETCA_UI_HANDLE hParentWnd,NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *msg,char **pwd);

/*
 *	NetcaPKIUIDisplayCert
 *		显示证书。
 *	参数：
 *		hParentWnd：输入参数，父窗口句柄
 *		hCert：证书句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIUIDisplayCert(NETCA_UI_HANDLE hParentWnd, NETCA_PKI_CERTIFICATE_HANDLE  hCert);

/*
 *	NetcaPKIUIDisplayCRL
 *		显示CRL。
 *	参数：
 *		hParentWnd：输入参数，父窗口句柄
 *		crl：输入参数,CRL的编码
 *		crllen：输入参数,CRL的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIUIDisplayCRL(NETCA_UI_HANDLE hParentWnd, const unsigned char *crl,int crllen);

/*
 *	NetcaPKIUISelectCert
 *		弹出对话框选择证书。
 *	参数：
 *		hParentWnd：输入参数，父窗口句柄
 *		title：输入参数,对话框标题
 *		msg：输入参数,对话框提示信息
 *		certs：输入参数，一组证书
 *		count：输入参数，证书个数
 *	返回值：
 *		成功返回选择的证书，失败返回NULL
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
 *		获取默认的提示信息。
 *	参数：
 *		id：输入参数，信息的ID号
 *	返回值：
 *		成功返回相应的信息，UTF-8编码，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKIUIGetString(int id);


#ifdef __cplusplus
	}	
#endif

#endif
