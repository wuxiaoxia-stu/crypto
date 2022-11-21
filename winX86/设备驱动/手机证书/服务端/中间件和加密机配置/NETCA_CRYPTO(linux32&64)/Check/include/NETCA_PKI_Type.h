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
	const unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* PKCS#12 KDF�Ĳ��� */
struct NETCA_PKI_PKCS12_KDF_PARAM_st
{
	int m_hashalgo;
	int m_flag;
	int m_id;
	const unsigned char *m_salt;
	int m_saltlen;
	int m_iter;
};

/* DH KDF�Ĳ��� */
struct NETCA_PKI_DH_KDF_PARAM_st
{
	int m_hashalgo;
	const char *m_kekoid;
	const unsigned char *m_partyainfo;
	int m_partyainfolen;
};

/* ECC KDF�Ĳ��� */
struct NETCA_PKI_ECC_KDF_PARAM_st
{
	int m_hashalgo;
	const unsigned char *m_sharedinfo;
	int m_sharedinfolen;
};

/* Ӧ�ó���ʹ�õľ�� */
/* �豸����� */
struct NETCA_PKI_DEVICE_HANDLE_SET_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_SET_st* NETCA_PKI_DEVICE_HANDLE_SET;
/* �豸��� */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;
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
struct NETCA_PKI_SIGNEDDATA_HANLDE_st;
typedef struct NETCA_PKI_SIGNEDDATA_HANLDE_st* NETCA_PKI_SIGNEDDATA_HANLDE;

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
typedef char * (NETCADLLAPI* NetcaPKIUIGetString_Ptr)(int id);
#endif

#ifdef _WIN32
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(HWND hParentWnd, const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#else
typedef NETCA_PKI_CERTIFICATE_HANDLE (NETCADLLAPI* NetcaPKIUISelectCert_Ptr)(void* hParentWnd,const  wchar_t *title, const  wchar_t *msg, NETCA_PKI_CERTIFICATE_HANDLE *certs,int count);
#endif

/* ʱ������ */
struct NETCA_PKI_TIMESTAMP_HANDLE_st;
typedef struct NETCA_PKI_TIMESTAMP_HANDLE_st *NETCA_PKI_TIMESTAMP_HANDLE;


/* ֤�������� */
struct NETCA_PKI_CERTREQ_HANLDE_st;
typedef struct NETCA_PKI_CERTREQ_HANLDE_st *NETCA_PKI_CERTREQ_HANLDE;

#ifdef __cplusplus
	}	
#endif
#endif
