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

/* ZUC算法使用的参数 */
struct NETCA_PKI_ZUCParam_st
{
	int m_count;		/* 计数器 */
	int m_bearer;		/* 承载层标识，5位 */
	int m_direction;	/* 传输方向标识，1位 */
	int m_unusedBits;			/*	未使用位，MAC需要 */
};

/* CCM模式使用的参数 */
struct NETCA_PKI_CCMParam_st
{
	int m_tLen;		/* Mac的字节数 */
	unsigned char m_nonce[NETCA_PKI_CRYPT_BLOCK_MAXLEN]; /* Nonce值 */
	int m_nonceLen;	/* Nonce的字节数 */
	unsigned char *m_adata;	/* Adata */
	int m_adataLen;/* Adata的字节数 */
	unsigned long long m_p;	/* 明文的字节数 */
	void *m_reserve;
};

/* GCM模式使用的参数 */
struct NETCA_PKI_GCMParam_st
{
	int m_tLen;		/* Mac的字节数 */
	unsigned char *m_iv; /* IV值 */
	int m_ivLen;	/* IV的字节数 */
	unsigned char *m_aad;	/* 附加的认证数据 */
	long long m_aadLen;/* aad的字节数 */
};

/* FF1模式使用的参数 */
struct NETCA_PKI_FF1Param_st
{
	int m_radix;		/* 基数 */
	unsigned char *m_tweak; /* tweak值 */
	int m_tweakLen;	/* tweak的字节数 */
};

/* FF3模式使用的参数 */
struct NETCA_PKI_FF3Param_st
{
	int m_radix;		/* 基数 */
	unsigned char m_tweak[8]; /* tweak值 */
};

#ifndef NETCA_CRYPT_BLOCK_MAXBYTELEN
	#define NETCA_CRYPT_BLOCK_MAXBYTELEN	32
#endif
/* CFB模式使用的参数 */
struct NETCA_PKI_CFBParam_st
{
	int m_s;		/* s的值,以位为单位 */
	unsigned char m_iv[NETCA_CRYPT_BLOCK_MAXBYTELEN]; /* IV值 */
};


/* EAX模式使用的参数 */
struct NETCA_PKI_EAXParam_st
{
	int m_tLen;		/* Mac的字节数 */
	unsigned char *m_nonce; /* Nonce值 */
	int m_nonceLen;	/* Nonce的字节数 */
	unsigned char *m_header;	/* 附加的认证数据 */
	int m_headerLen;/* header的字节数 */
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
	unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* PKCS#12 KDF的参数 */
struct NETCA_PKI_PKCS12_KDF_PARAM_st
{
	int m_hashalgo;
	int m_flag;
	int m_id;
	unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* DH KDF的参数 */
struct NETCA_PKI_DH_KDF_PARAM_st
{
	int m_hashalgo;
	char *m_kekoid;
	unsigned char *m_partyainfo;
	int m_partyainfolen;
};

/* ECC KDF的参数 */
struct NETCA_PKI_ECC_KDF_PARAM_st
{
	int m_hashalgo;
	unsigned char *m_sharedinfo;
	int m_sharedinfolen;
};

/* PFX导出的参数 */
struct NETCA_PKI_PFX_EXPORT_PARAM_st
{
	int m_flag;			/* 通常为0 */
	int m_useSM2PrivKey;/* 为真使用GM/T 0010-2012方式的私钥编码 */
	int m_usePbkdf2;	/* 为真表示加密导出密钥使用PKCS#5 PBKDF2的方式，为假表示PKCS#12方式的KDF */
	int m_encCert;		/* 为真表示对证书进行加密，为假则不进行 */
	int m_hashAlgo;		/* KDF使用的HASH算法 */
	int m_saltLen;		/* 盐的长度 */
	int m_iterCount;	/* 迭代次数 */
	void *m_reserve;	/* 保留值 */
};
typedef struct NETCA_PKI_PFX_EXPORT_PARAM_st* NETCA_PKI_PFX_EXPORT_PARAM;


/* 作废信息来源 */
struct NETCA_PKI_REVOKE_INFO_SOURCE_st
{
	int m_type;
	unsigned char *m_data;
	int m_dataLen;
};
typedef struct NETCA_PKI_REVOKE_INFO_SOURCE_st* NETCA_PKI_REVOKE_INFO_SOURCE_HANDLE;

/* 应用程序使用的句柄 */
/* 设备集句柄 */
struct NETCA_PKI_DEVICE_HANDLE_SET_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_SET_st* NETCA_PKI_DEVICE_HANDLE_SET;
/* 设备句柄 */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;

typedef int (NETCADLLAPI* NetcaPKICryptoFreeDeviceExtraDataFunction_Ptr)(NETCA_PKI_DEVICE_HANDLE hDevice,void *data);

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

/* CRL句柄 */
struct NETCA_CRL_st;
typedef struct NETCA_CRL_st* NETCA_PKI_CRL_HANDLE;

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
struct NETCA_PKI_SIGNEDDATA_HANDLE_st;
typedef struct NETCA_PKI_SIGNEDDATA_HANDLE_st* NETCA_PKI_SIGNEDDATA_HANLDE;
typedef struct NETCA_PKI_SIGNEDDATA_HANDLE_st* NETCA_PKI_SIGNEDDATA_HANDLE;

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
#else
typedef int (NETCADLLAPI* NetcaPKIUIVerifyPassword_Ptr)(void* hParentWnd,NETCA_PKI_DEVICE_HANDLE hDevice,int type,const char *msg,char **pwd);
#endif
typedef char * (NETCADLLAPI* NetcaPKIUIGetString_Ptr)(int id);


#ifdef _WIN32
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(HWND hParentWnd, const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#else
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(void* hParentWnd,const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#endif

/* 时间戳句柄 */
struct NETCA_PKI_TIMESTAMP_HANDLE_st;
typedef struct NETCA_PKI_TIMESTAMP_HANDLE_st *NETCA_PKI_TIMESTAMP_HANDLE;


/* 证书请求句柄 */
struct NETCA_PKI_CERTREQ_HANDLE_st;
typedef struct NETCA_PKI_CERTREQ_HANDLE_st *NETCA_PKI_CERTREQ_HANLDE;
typedef struct NETCA_PKI_CERTREQ_HANDLE_st *NETCA_PKI_CERTREQ_HANDLE;

typedef int (NETCADLLAPI* NetcaCertReqSignHashCallback_Ptr)(void *context,int algo,const void *param,const unsigned char *hashValue,int hashLen,unsigned char **signature,int *signatureLen);


typedef int (NETCADLLAPI* NetcaMonitorDeviceCallback_Ptr)(void *context,int isPullOut,NETCA_PKI_DEVICE_HANDLE hDevice);
typedef int (NETCADLLAPI* NetcaDevicePullOutCallback_Ptr)(void *context,int isPullOut,int type,const char *sn);


struct NETCA_PKI_ENVELOPEDDATA_KEYAGREEMENT_CALLBACK_PARAM_st
{
	unsigned char * m_publicKeyEncode;  /* 对方公钥的SubjectPublicKeyInfo的DER编码 */
	int m_publicKeyLen;
	void *m_reserve;
};

typedef int (NETCADLLAPI* NetcaEnvelopedDataDecryptKeyCallback_Ptr)(void *context,int ridType,const unsigned char *rid,int ridLen,int algo,const void *param,const unsigned char *cipher,int cipherLen,unsigned char **key,int *keyLen);
typedef int (NETCADLLAPI* NetcaSignedDataGetCertCallback_Ptr)(void *context,int sidType,const unsigned char *sid,int sidLen,NETCA_PKI_CERTIFICATE_HANDLE **certs,int *certCount);
typedef int (NETCADLLAPI* NetcaSignedDataSignHashCallback_Ptr)(void *context,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,const unsigned char *hashValue,int hashLen,unsigned char **signature,int *signatureLen);


/* MIME句柄 */
struct NETCA_PKI_MIME_HANDLE_st;
typedef struct NETCA_PKI_MIME_HANDLE_st *NETCA_PKI_MIME_HANDLE;

/* 高层配置信息句柄 */
struct NETCA_PKI_CONFIG_st;
typedef struct NETCA_PKI_CONFIG_st* NETCA_PKI_CONFIG_HANDLE;

/* JSON签名句柄 */
struct NETCA_PKI_JWS_st;
typedef struct NETCA_PKI_JWS_st* NETCA_PKI_JWS_HANDLE;

/* JSON加密句柄 */
struct NETCA_PKI_JWE_st;
typedef struct NETCA_PKI_JWE_st* NETCA_PKI_JWE_HANDLE;


/* JWE中ECDH-ES、ECDH-ES+A128KW、ECDH-ES+A192KW和ECDH-ES+A256KW使用的参数 */
struct NETCA_PKI_JWE_ECDH_ESParam_st
{
	unsigned char *m_partyUInfo;
	int m_partyUInfoLen;
	unsigned char *m_partyVInfo;
	int m_partyVInfoLen;
};


/* JSON Web Token句柄 */
struct NETCA_PKI_JWT_st;
typedef struct NETCA_PKI_JWT_st* NETCA_PKI_JWT_HANDLE;


/* SignedAndEnvelopedData句柄 */
struct NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_st;
typedef struct NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_st* NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE;

typedef int (NETCADLLAPI* NetcaSignedAndEnvelopedDataSignHashCallback_Ptr)(void *context,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,const unsigned char *hashValue,int hashLen,unsigned char **signature,int *signatureLen);
typedef int (NETCADLLAPI* NetcaSignedAndEnvelopedDataDecryptKeyCallback_Ptr)(void *context,int ridType,const unsigned char *rid,int ridLen,int algo,const void *param,const unsigned char *cipher,int cipherLen,unsigned char **key,int *keyLen);

struct NETCA_PKI_ATTRIBUTE_CERT_HANDLE_st;
typedef struct NETCA_PKI_ATTRIBUTE_CERT_HANDLE_st *NETCA_PKI_ATTRIBUTE_CERT_HANDLE;

struct NETCA_PKI_SES_STAMP_st;
typedef struct NETCA_PKI_SES_STAMP_st* NETCA_PKI_SES_STAMP_HANDLE;

struct NETCA_PKI_SES_SEAL_st;
typedef struct NETCA_PKI_SES_SEAL_st* NETCA_PKI_SES_SEAL_HANDLE;

typedef int (NETCADLLAPI* NetcaSESSignCallback_Ptr)(void *context, NETCA_PKI_CERTIFICATE_HANDLE cert, int algo, const void *param, const unsigned char *data, int dataLen, unsigned char **signature, int *signatureLen);


#ifdef __cplusplus
	}	
#endif
#endif
