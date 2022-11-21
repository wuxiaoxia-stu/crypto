#ifndef _NETCA_PKI_TYPE_INLCUDE_H_
#define _NETCA_PKI_TYPE_INLCUDE_H_

#include <wchar.h>
#include "NETCA_PKI_Const.h"

#ifdef __cplusplus
extern "C"
	{
#endif


/* 设备接口句柄 */
/* 设备集句柄 */
struct SPI_DEVICE_HANDLE_SET_st;
typedef struct SPI_DEVICE_HANDLE_SET_st* SPI_DEVICE_HANDLE_SET;
/* 设备句柄 */
struct SPI_DEVICE_HANDLE_st;
typedef struct SPI_DEVICE_HANDLE_st* SPI_DEVICE_HANDLE;
/* 密钥对句柄 */
struct SPI_KEYPAIR_HANDLE_st;
typedef struct SPI_KEYPAIR_HANDLE_st* SPI_KEYPAIR_HANDLE;
/* 公钥句柄 */
struct SPI_PUBLICKEY_HANDLE_st;
typedef struct SPI_PUBLICKEY_HANDLE_st* SPI_PUBLICKEY_HANDLE;
/* Hash句柄 */
struct SPI_HASH_HANDLE_st;
typedef struct SPI_HASH_HANDLE_st* SPI_HASH_HANDLE;
/* Mac句柄 */
struct SPI_MAC_HANDLE_st;
typedef struct SPI_MAC_HANDLE_st* SPI_MAC_HANDLE;
/* 对称加解密句柄 */
struct SPI_CIPHER_HANDLE_st;
typedef struct SPI_CIPHER_HANDLE_st* SPI_CIPHER_HANDLE;

/* RC2 CBC模式使用的参数 */
struct NETCA_PKI_RC2CBCParam_st
{
	int m_effective_keybits;
	unsigned char m_iv[8];
};

/* CTR模式使用的参数 */
struct NETCA_PKI_CTRParam_st
{
	int m_count_bits;		/* 计数器占的位数 */
	unsigned char m_iv[NETCA_PKI_CRYPT_BLOCK_MAXLEN]; /* 初始值，只取前面一个分组长度 */
};

struct NETCA_PKI_RSA_PARAM_PKCS1_OAEP_st
{
	int m_hashalgo;
	int m_mgfalgo;
	unsigned char *m_label;
	int m_labellen;	
};

struct NETCA_PKI_RSA_PARAM_PKCS1_PSS_st
{
	int m_mgfalgo;
	int m_saltlen;
	int m_hashalgo;	
};

/* 导入对称密钥的参数，DeviceIsSupportedAlgorithm2使用 */
struct NETCA_PKI_ImportKey_PARAM_st
{
	int m_pubkeyalgo;
	void *m_pubkeyalgoparam;
	void *m_algoparam;
};

/* 产生RSA密钥对使用的参数 */
struct NETCA_PKI_GenRSA_PARAM_st
{
	unsigned char *m_e;
	int m_elen;
	int m_temp;		/* 为真表示临时的密钥对 */
	void *m_reserve;
};

/* 产生DSA密钥对使用的参数 */
struct NETCA_PKI_GenDSA_PARAM_st
{
	unsigned char *m_p;
	int m_plen;
	unsigned char *m_q;
	int m_qlen;
	unsigned char *m_g;
	int m_glen;
	int m_temp;		/* 为真表示临时的密钥对 */
	void *m_reserve;
};

/* 产生ECC密钥对使用的参数 */
struct NETCA_PKI_GenECC_PARAM_st
{
	int m_curve;
	int m_temp;		/* 为真表示临时的密钥对 */
	void *m_reserve;
};

/* SM2签名的参数 */
struct NETCA_PKI_SM2Sign_PARAM_st
{
	unsigned char *m_id;
	int m_idbits;
};

/* SM2密钥协商的参数 */
struct NETCA_PKI_SM2KeyAgreement_PARAM_st
{
	int m_hashalgo;
	unsigned char *m_id;
	int m_idbits;
	unsigned char *m_respid;
	int m_respidbits;
	int m_issender;			/* 如果为真，表示是发起方，为假表示是响应方 */

	int m_reservepoint;			/* 如果为真，则把得到的共享的点的未压缩编码保存在m_point中，用于密钥确认 */
	unsigned char *m_point;
	int m_pointlen;
};

/* PKCS#5 PBKDF1的参数 */
struct NETCA_PKI_PKCS5_PBKDF_PARAM_st
{
	int m_hashalgo;
	const unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* PKCS#12 KDF的参数 */
struct NETCA_PKI_PKCS12_KDF_PARAM_st
{
	int m_hashalgo;
	int m_flag;
	int m_id;
	const unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* DH KDF的参数 */
struct NETCA_PKI_DH_KDF_PARAM_st
{
	int m_hashalgo;
	const char *m_kekoid;
	const unsigned char *m_partyainfo;
	int m_partyainfolen;
};

/* ECC KDF的参数 */
struct NETCA_PKI_ECC_KDF_PARAM_st
{
	int m_hashalgo;
	const unsigned char *m_sharedinfo;
	int m_sharedinfolen;
};

/* 应用程序使用的句柄 */
/* 设备集句柄 */
struct NETCA_PKI_DEVICE_HANDLE_SET_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_SET_st* NETCA_PKI_DEVICE_HANDLE_SET;
/* 设备句柄 */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;
/* 密钥对句柄 */
struct NETCA_PrivKey_Handle_st;
typedef struct NETCA_PrivKey_Handle_st * NETCA_PKI_KEYPAIR_HANDLE;
/* 公钥句柄 */
struct NETCA_PKI_PUBLICKEY_HANDLE_st;
typedef struct NETCA_PKI_PUBLICKEY_HANDLE_st *NETCA_PKI_PUBLICKEY_HANDLE;
/* 证书句柄 */
struct NETCA_CERT_st;
typedef struct NETCA_CERT_st* NETCA_PKI_CERTIFICATE_HANDLE;
/* Hash句柄 */
struct NETCA_PKI_HASH_HANDLE_st;
typedef struct NETCA_PKI_HASH_HANDLE_st* NETCA_PKI_HASH_HANDLE;
/* Mac句柄 */
struct NETCA_PKI_MAC_HANDLE_st;
typedef struct NETCA_PKI_MAC_HANDLE_st* NETCA_PKI_MAC_HANDLE;
/* 对称加解密句柄 */
struct NETCA_PKI_CIPHER_HANDLE_st;
typedef struct NETCA_PKI_CIPHER_HANDLE_st* NETCA_PKI_CIPHER_HANDLE;
/* 签名句柄 */
struct NETCA_PKI_SIGN_HANDLE_st;
typedef struct NETCA_PKI_SIGN_HANDLE_st* NETCA_PKI_SIGN_HANDLE;
/* 验证签名句柄 */
struct NETCA_PKI_DEVICE_VERIFY_HANDLE_st;
typedef struct NETCA_PKI_DEVICE_VERIFY_HANDLE_st* NETCA_PKI_DEVICE_VERIFY_HANDLE;

/* Base64句柄 */
struct NETCA_PKI_BASE64_HANDLE_st;
typedef struct NETCA_PKI_BASE64_HANDLE_st* NETCA_PKI_BASE64_HANDLE;

/* 证书库句柄 */
struct NETCA_CERT_Store_st;
typedef struct NETCA_CERT_Store_st* NETCA_PKI_CERT_STORE;

/* 作废证书信息句柄 */
struct NETCA_PKI_REVOKEDCERT_HANDLE_st;
typedef struct NETCA_PKI_REVOKEDCERT_HANDLE_st* NETCA_PKI_REVOKEDCERT_HANDLE;

/* 验证证书句柄 */
struct NETCA_PKI_CERT_VERIFY_HANDLE_st;
typedef struct NETCA_PKI_CERT_VERIFY_HANDLE_st* NETCA_PKI_CERT_VERIFY_HANDLE;


/* 数字信封句柄 */
struct NETCA_PKI_ENVELOPEDDATA_HANDLE_st;
typedef struct NETCA_PKI_ENVELOPEDDATA_HANDLE_st* NETCA_PKI_ENVELOPEDDATA_HANDLE;


/* SignedData句柄 */
struct NETCA_PKI_SIGNEDDATA_HANLDE_st;
typedef struct NETCA_PKI_SIGNEDDATA_HANLDE_st* NETCA_PKI_SIGNEDDATA_HANLDE;

/* 地址簿句柄 */
struct NETCA_PKI_ADDRESSBOOK_HANDLE_st;
typedef struct NETCA_PKI_ADDRESSBOOK_HANDLE_st *NETCA_PKI_ADDRESSBOOK_HANDLE;

/* 联系人句柄 */
struct NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE_st;
typedef struct NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE_st *NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE;

/* 联系人组句柄 */
struct NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE_st;
typedef struct NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE_st *NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE;


#ifdef _WIN32
#include <windows.h>
typedef int (NETCADLLAPI* NetcaPKIUIVerifyPassword_Ptr)(HWND hParentWnd,NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *msg,char **pwd);
typedef char * (NETCADLLAPI* NetcaPKIUIGetString_Ptr)(int id);
#endif

#ifdef _WIN32
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(HWND hParentWnd, const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#else
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(void* hParentWnd,const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#endif

/* 时间戳句柄 */
struct NETCA_PKI_TIMESTAMP_HANDLE_st;
typedef struct NETCA_PKI_TIMESTAMP_HANDLE_st *NETCA_PKI_TIMESTAMP_HANDLE;


/* 证书请求句柄 */
struct NETCA_PKI_CERTREQ_HANLDE_st;
typedef struct NETCA_PKI_CERTREQ_HANLDE_st *NETCA_PKI_CERTREQ_HANLDE;

#ifdef __cplusplus
	}	
#endif
#endif
