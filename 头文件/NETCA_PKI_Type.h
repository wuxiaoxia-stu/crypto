#ifndef _NETCA_PKI_TYPE_INLCUDE_H_
#define _NETCA_PKI_TYPE_INLCUDE_H_

#include <wchar.h>
#include "NETCA_PKI_Const.h"

#ifdef __cplusplus
extern "C"
	{
#endif


/* �豸�ӿھ�� */
/* �豸����� */
struct SPI_DEVICE_HANDLE_SET_st;
typedef struct SPI_DEVICE_HANDLE_SET_st* SPI_DEVICE_HANDLE_SET;
/* �豸��� */
struct SPI_DEVICE_HANDLE_st;
typedef struct SPI_DEVICE_HANDLE_st* SPI_DEVICE_HANDLE;
/* ��Կ�Ծ�� */
struct SPI_KEYPAIR_HANDLE_st;
typedef struct SPI_KEYPAIR_HANDLE_st* SPI_KEYPAIR_HANDLE;
/* ��Կ��� */
struct SPI_PUBLICKEY_HANDLE_st;
typedef struct SPI_PUBLICKEY_HANDLE_st* SPI_PUBLICKEY_HANDLE;
/* Hash��� */
struct SPI_HASH_HANDLE_st;
typedef struct SPI_HASH_HANDLE_st* SPI_HASH_HANDLE;
/* Mac��� */
struct SPI_MAC_HANDLE_st;
typedef struct SPI_MAC_HANDLE_st* SPI_MAC_HANDLE;
/* �ԳƼӽ��ܾ�� */
struct SPI_CIPHER_HANDLE_st;
typedef struct SPI_CIPHER_HANDLE_st* SPI_CIPHER_HANDLE;

/* RC2 CBCģʽʹ�õĲ��� */
struct NETCA_PKI_RC2CBCParam_st
{
	int m_effective_keybits;
	unsigned char m_iv[8];
};

/* CTRģʽʹ�õĲ��� */
struct NETCA_PKI_CTRParam_st
{
	int m_count_bits;		/* ������ռ��λ�� */
	unsigned char m_iv[NETCA_PKI_CRYPT_BLOCK_MAXLEN]; /* ��ʼֵ��ֻȡǰ��һ�����鳤�� */
};

/* ZUC�㷨ʹ�õĲ��� */
struct NETCA_PKI_ZUCParam_st
{
	int m_count;		/* ������ */
	int m_bearer;		/* ���ز��ʶ��5λ */
	int m_direction;	/* ���䷽���ʶ��1λ */
	int m_unusedBits;			/*	δʹ��λ��MAC��Ҫ */
};

/* CCMģʽʹ�õĲ��� */
struct NETCA_PKI_CCMParam_st
{
	int m_tLen;		/* Mac���ֽ��� */
	unsigned char m_nonce[NETCA_PKI_CRYPT_BLOCK_MAXLEN]; /* Nonceֵ */
	int m_nonceLen;	/* Nonce���ֽ��� */
	unsigned char *m_adata;	/* Adata */
	int m_adataLen;/* Adata���ֽ��� */
	unsigned long long m_p;	/* ���ĵ��ֽ��� */
	void *m_reserve;
};

/* GCMģʽʹ�õĲ��� */
struct NETCA_PKI_GCMParam_st
{
	int m_tLen;		/* Mac���ֽ��� */
	unsigned char *m_iv; /* IVֵ */
	int m_ivLen;	/* IV���ֽ��� */
	unsigned char *m_aad;	/* ���ӵ���֤���� */
	long long m_aadLen;/* aad���ֽ��� */
};

/* FF1ģʽʹ�õĲ��� */
struct NETCA_PKI_FF1Param_st
{
	int m_radix;		/* ���� */
	unsigned char *m_tweak; /* tweakֵ */
	int m_tweakLen;	/* tweak���ֽ��� */
};

/* FF3ģʽʹ�õĲ��� */
struct NETCA_PKI_FF3Param_st
{
	int m_radix;		/* ���� */
	unsigned char m_tweak[8]; /* tweakֵ */
};

#ifndef NETCA_CRYPT_BLOCK_MAXBYTELEN
	#define NETCA_CRYPT_BLOCK_MAXBYTELEN	32
#endif
/* CFBģʽʹ�õĲ��� */
struct NETCA_PKI_CFBParam_st
{
	int m_s;		/* s��ֵ,��λΪ��λ */
	unsigned char m_iv[NETCA_CRYPT_BLOCK_MAXBYTELEN]; /* IVֵ */
};


/* EAXģʽʹ�õĲ��� */
struct NETCA_PKI_EAXParam_st
{
	int m_tLen;		/* Mac���ֽ��� */
	unsigned char *m_nonce; /* Nonceֵ */
	int m_nonceLen;	/* Nonce���ֽ��� */
	unsigned char *m_header;	/* ���ӵ���֤���� */
	int m_headerLen;/* header���ֽ��� */
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

/* ����Գ���Կ�Ĳ�����DeviceIsSupportedAlgorithm2ʹ�� */
struct NETCA_PKI_ImportKey_PARAM_st
{
	int m_pubkeyalgo;
	void *m_pubkeyalgoparam;
	void *m_algoparam;
};

/* ����RSA��Կ��ʹ�õĲ��� */
struct NETCA_PKI_GenRSA_PARAM_st
{
	unsigned char *m_e;
	int m_elen;
	int m_temp;		/* Ϊ���ʾ��ʱ����Կ�� */
	void *m_reserve;
};

/* ����DSA��Կ��ʹ�õĲ��� */
struct NETCA_PKI_GenDSA_PARAM_st
{
	unsigned char *m_p;
	int m_plen;
	unsigned char *m_q;
	int m_qlen;
	unsigned char *m_g;
	int m_glen;
	int m_temp;		/* Ϊ���ʾ��ʱ����Կ�� */
	void *m_reserve;
};

/* ����ECC��Կ��ʹ�õĲ��� */
struct NETCA_PKI_GenECC_PARAM_st
{
	int m_curve;
	int m_temp;		/* Ϊ���ʾ��ʱ����Կ�� */
	void *m_reserve;
};

/* SM2ǩ���Ĳ��� */
struct NETCA_PKI_SM2Sign_PARAM_st
{
	unsigned char *m_id;
	int m_idbits;
};

/* SM2��ԿЭ�̵Ĳ��� */
struct NETCA_PKI_SM2KeyAgreement_PARAM_st
{
	int m_hashalgo;
	unsigned char *m_id;
	int m_idbits;
	unsigned char *m_respid;
	int m_respidbits;
	int m_issender;			/* ���Ϊ�棬��ʾ�Ƿ��𷽣�Ϊ�ٱ�ʾ����Ӧ�� */

	int m_reservepoint;			/* ���Ϊ�棬��ѵõ��Ĺ���ĵ��δѹ�����뱣����m_point�У�������Կȷ�� */
	unsigned char *m_point;
	int m_pointlen;
};

/* PKCS#5 PBKDF1�Ĳ��� */
struct NETCA_PKI_PKCS5_PBKDF_PARAM_st
{
	int m_hashalgo;
	unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* PKCS#12 KDF�Ĳ��� */
struct NETCA_PKI_PKCS12_KDF_PARAM_st
{
	int m_hashalgo;
	int m_flag;
	int m_id;
	unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* DH KDF�Ĳ��� */
struct NETCA_PKI_DH_KDF_PARAM_st
{
	int m_hashalgo;
	char *m_kekoid;
	unsigned char *m_partyainfo;
	int m_partyainfolen;
};

/* ECC KDF�Ĳ��� */
struct NETCA_PKI_ECC_KDF_PARAM_st
{
	int m_hashalgo;
	unsigned char *m_sharedinfo;
	int m_sharedinfolen;
};

/* PFX�����Ĳ��� */
struct NETCA_PKI_PFX_EXPORT_PARAM_st
{
	int m_flag;			/* ͨ��Ϊ0 */
	int m_useSM2PrivKey;/* Ϊ��ʹ��GM/T 0010-2012��ʽ��˽Կ���� */
	int m_usePbkdf2;	/* Ϊ���ʾ���ܵ�����Կʹ��PKCS#5 PBKDF2�ķ�ʽ��Ϊ�ٱ�ʾPKCS#12��ʽ��KDF */
	int m_encCert;		/* Ϊ���ʾ��֤����м��ܣ�Ϊ���򲻽��� */
	int m_hashAlgo;		/* KDFʹ�õ�HASH�㷨 */
	int m_saltLen;		/* �εĳ��� */
	int m_iterCount;	/* �������� */
	void *m_reserve;	/* ����ֵ */
};
typedef struct NETCA_PKI_PFX_EXPORT_PARAM_st* NETCA_PKI_PFX_EXPORT_PARAM;


/* ������Ϣ��Դ */
struct NETCA_PKI_REVOKE_INFO_SOURCE_st
{
	int m_type;
	unsigned char *m_data;
	int m_dataLen;
};
typedef struct NETCA_PKI_REVOKE_INFO_SOURCE_st* NETCA_PKI_REVOKE_INFO_SOURCE_HANDLE;

/* Ӧ�ó���ʹ�õľ�� */
/* �豸����� */
struct NETCA_PKI_DEVICE_HANDLE_SET_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_SET_st* NETCA_PKI_DEVICE_HANDLE_SET;
/* �豸��� */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;

typedef int (NETCADLLAPI* NetcaPKICryptoFreeDeviceExtraDataFunction_Ptr)(NETCA_PKI_DEVICE_HANDLE hDevice,void *data);

/* ��Կ�Ծ�� */
struct NETCA_PrivKey_Handle_st;
typedef struct NETCA_PrivKey_Handle_st * NETCA_PKI_KEYPAIR_HANDLE;
/* ��Կ��� */
struct NETCA_PKI_PUBLICKEY_HANDLE_st;
typedef struct NETCA_PKI_PUBLICKEY_HANDLE_st *NETCA_PKI_PUBLICKEY_HANDLE;
/* ֤���� */
struct NETCA_CERT_st;
typedef struct NETCA_CERT_st* NETCA_PKI_CERTIFICATE_HANDLE;
/* Hash��� */
struct NETCA_PKI_HASH_HANDLE_st;
typedef struct NETCA_PKI_HASH_HANDLE_st* NETCA_PKI_HASH_HANDLE;
/* Mac��� */
struct NETCA_PKI_MAC_HANDLE_st;
typedef struct NETCA_PKI_MAC_HANDLE_st* NETCA_PKI_MAC_HANDLE;
/* �ԳƼӽ��ܾ�� */
struct NETCA_PKI_CIPHER_HANDLE_st;
typedef struct NETCA_PKI_CIPHER_HANDLE_st* NETCA_PKI_CIPHER_HANDLE;
/* ǩ����� */
struct NETCA_PKI_SIGN_HANDLE_st;
typedef struct NETCA_PKI_SIGN_HANDLE_st* NETCA_PKI_SIGN_HANDLE;
/* ��֤ǩ����� */
struct NETCA_PKI_DEVICE_VERIFY_HANDLE_st;
typedef struct NETCA_PKI_DEVICE_VERIFY_HANDLE_st* NETCA_PKI_DEVICE_VERIFY_HANDLE;

/* CRL��� */
struct NETCA_CRL_st;
typedef struct NETCA_CRL_st* NETCA_PKI_CRL_HANDLE;

/* Base64��� */
struct NETCA_PKI_BASE64_HANDLE_st;
typedef struct NETCA_PKI_BASE64_HANDLE_st* NETCA_PKI_BASE64_HANDLE;

/* ֤����� */
struct NETCA_CERT_Store_st;
typedef struct NETCA_CERT_Store_st* NETCA_PKI_CERT_STORE;

/* ����֤����Ϣ��� */
struct NETCA_PKI_REVOKEDCERT_HANDLE_st;
typedef struct NETCA_PKI_REVOKEDCERT_HANDLE_st* NETCA_PKI_REVOKEDCERT_HANDLE;

/* ��֤֤���� */
struct NETCA_PKI_CERT_VERIFY_HANDLE_st;
typedef struct NETCA_PKI_CERT_VERIFY_HANDLE_st* NETCA_PKI_CERT_VERIFY_HANDLE;


/* �����ŷ��� */
struct NETCA_PKI_ENVELOPEDDATA_HANDLE_st;
typedef struct NETCA_PKI_ENVELOPEDDATA_HANDLE_st* NETCA_PKI_ENVELOPEDDATA_HANDLE;


/* SignedData��� */
struct NETCA_PKI_SIGNEDDATA_HANDLE_st;
typedef struct NETCA_PKI_SIGNEDDATA_HANDLE_st* NETCA_PKI_SIGNEDDATA_HANLDE;
typedef struct NETCA_PKI_SIGNEDDATA_HANDLE_st* NETCA_PKI_SIGNEDDATA_HANDLE;

/* ��ַ����� */
struct NETCA_PKI_ADDRESSBOOK_HANDLE_st;
typedef struct NETCA_PKI_ADDRESSBOOK_HANDLE_st *NETCA_PKI_ADDRESSBOOK_HANDLE;

/* ��ϵ�˾�� */
struct NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE_st;
typedef struct NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE_st *NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE;

/* ��ϵ������ */
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

/* ʱ������ */
struct NETCA_PKI_TIMESTAMP_HANDLE_st;
typedef struct NETCA_PKI_TIMESTAMP_HANDLE_st *NETCA_PKI_TIMESTAMP_HANDLE;


/* ֤�������� */
struct NETCA_PKI_CERTREQ_HANDLE_st;
typedef struct NETCA_PKI_CERTREQ_HANDLE_st *NETCA_PKI_CERTREQ_HANLDE;
typedef struct NETCA_PKI_CERTREQ_HANDLE_st *NETCA_PKI_CERTREQ_HANDLE;

typedef int (NETCADLLAPI* NetcaCertReqSignHashCallback_Ptr)(void *context,int algo,const void *param,const unsigned char *hashValue,int hashLen,unsigned char **signature,int *signatureLen);


typedef int (NETCADLLAPI* NetcaMonitorDeviceCallback_Ptr)(void *context,int isPullOut,NETCA_PKI_DEVICE_HANDLE hDevice);
typedef int (NETCADLLAPI* NetcaDevicePullOutCallback_Ptr)(void *context,int isPullOut,int type,const char *sn);


struct NETCA_PKI_ENVELOPEDDATA_KEYAGREEMENT_CALLBACK_PARAM_st
{
	unsigned char * m_publicKeyEncode;  /* �Է���Կ��SubjectPublicKeyInfo��DER���� */
	int m_publicKeyLen;
	void *m_reserve;
};

typedef int (NETCADLLAPI* NetcaEnvelopedDataDecryptKeyCallback_Ptr)(void *context,int ridType,const unsigned char *rid,int ridLen,int algo,const void *param,const unsigned char *cipher,int cipherLen,unsigned char **key,int *keyLen);
typedef int (NETCADLLAPI* NetcaSignedDataGetCertCallback_Ptr)(void *context,int sidType,const unsigned char *sid,int sidLen,NETCA_PKI_CERTIFICATE_HANDLE **certs,int *certCount);
typedef int (NETCADLLAPI* NetcaSignedDataSignHashCallback_Ptr)(void *context,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,const unsigned char *hashValue,int hashLen,unsigned char **signature,int *signatureLen);


/* MIME��� */
struct NETCA_PKI_MIME_HANDLE_st;
typedef struct NETCA_PKI_MIME_HANDLE_st *NETCA_PKI_MIME_HANDLE;

/* �߲�������Ϣ��� */
struct NETCA_PKI_CONFIG_st;
typedef struct NETCA_PKI_CONFIG_st* NETCA_PKI_CONFIG_HANDLE;

/* JSONǩ����� */
struct NETCA_PKI_JWS_st;
typedef struct NETCA_PKI_JWS_st* NETCA_PKI_JWS_HANDLE;

/* JSON���ܾ�� */
struct NETCA_PKI_JWE_st;
typedef struct NETCA_PKI_JWE_st* NETCA_PKI_JWE_HANDLE;


/* JWE��ECDH-ES��ECDH-ES+A128KW��ECDH-ES+A192KW��ECDH-ES+A256KWʹ�õĲ��� */
struct NETCA_PKI_JWE_ECDH_ESParam_st
{
	unsigned char *m_partyUInfo;
	int m_partyUInfoLen;
	unsigned char *m_partyVInfo;
	int m_partyVInfoLen;
};


/* JSON Web Token��� */
struct NETCA_PKI_JWT_st;
typedef struct NETCA_PKI_JWT_st* NETCA_PKI_JWT_HANDLE;


/* SignedAndEnvelopedData��� */
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
