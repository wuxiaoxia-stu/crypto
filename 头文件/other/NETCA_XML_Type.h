#ifndef NETCA_XML_TYPE_INCLUDE_H
#define NETCA_XML_TYPE_INCLUDE_H


#ifdef __cplusplus
extern "C"
	{
#endif

#define NETCA_XML_NODETYPE_ELEMENT		1
#define NETCA_XML_NODETYPE_ATTRIBUTE		2
#define NETCA_XML_NODETYPE_TEXT			3
#define NETCA_XML_NODETYPE_PI			4
#define NETCA_XML_NODETYPE_COMMENT		5
#define NETCA_XML_NODETYPE_DOCUMENT		6
#define NETCA_XML_NODETYPE_NAMESPACE		7


typedef struct _xmlDoc  *NETCA_XML_DocPtr;
typedef struct _xmlNode *NETCA_XML_NodePtr;


struct NETCA_XML_Signature_VerifyCtx_st;
typedef struct NETCA_XML_Signature_VerifyCtx_st *NETCA_XML_Signature_VerifyCtx;

#define NETCA_XML_SIGNATURE_C14N_WITHOUT_COMMETNTS		0x1
#define NETCA_XML_SIGNATURE_C14N_WITH_COMMENTS			0x2
#define NETCA_XML_SIGNATURE_C14NV1_0_WITHOUT_COMMETNTS		0x1
#define NETCA_XML_SIGNATURE_C14NV1_0_WITH_COMMENTS			0x2
#define NETCA_XML_SIGNATURE_EXCLUSIVE_C14N_WITHOUT_COMMETNTS	0x3
#define NETCA_XML_SIGNATURE_EXCLUSIVE_C14N_WITH_COMMENTS	0x4
#define NETCA_XML_SIGNATURE_MINIMAL_C14N			0x5
#define NETCA_XML_SIGNATURE_C14NV1_1_WITHOUT_COMMETNTS		0x6
#define NETCA_XML_SIGNATURE_C14NV1_1_WITH_COMMENTS			0x7

#define NETCA_XML_SIGNATURE_TRANSFORM_BASE64			0x10
#define NETCA_XML_SIGNATURE_TRANSFORM_XPATH_FILTER		0x20
#define NETCA_XML_SIGNATURE_TRANSFORM_ENVELOPED_SIGNATURE	0x30
#define NETCA_XML_SIGNATURE_TRANSFORM_XSLT			0x40

#define NETCA_XML_SIGNATURE_ALGORITHM_SHA1			0x1
#define NETCA_XML_SIGNATURE_ALGORITHM_MD5			0x2
#define NETCA_XML_SIGNATURE_ALGORITHM_SHA224			0x3
#define NETCA_XML_SIGNATURE_ALGORITHM_SHA256			0x4
#define NETCA_XML_SIGNATURE_ALGORITHM_SHA384			0x5
#define NETCA_XML_SIGNATURE_ALGORITHM_SHA512			0x6
#define NETCA_XML_SIGNATURE_ALGORITHM_RIPEMD160			0x7
#define NETCA_XML_SIGNATURE_ALGORITHM_SM3				0x8

#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_SHA1			0x21
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_MD5			0x22
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_SHA224		0x23
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_SHA256		0x24
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_SHA384		0x25
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_SHA512		0x26
#define NETCA_XML_SIGNATURE_ALGORITHM_HMAC_RIPEMD160		0x27

#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_SHA1			0x41
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_MD5			0x42
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_SHA224		0x43
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_SHA256		0x44
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_SHA384		0x45
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_SHA512		0x46
#define NETCA_XML_SIGNATURE_ALGORITHM_RSA_RIPEMD160		0x47
#define NETCA_XML_SIGNATURE_ALGORITHM_DSA_SHA1			0x48
#define NETCA_XML_SIGNATURE_ALGORITHM_ECDSA_SHA1		0x49
#define NETCA_XML_SIGNATURE_ALGORITHM_ECDSA_SHA224		0x4A
#define NETCA_XML_SIGNATURE_ALGORITHM_ECDSA_SHA256		0x4B
#define NETCA_XML_SIGNATURE_ALGORITHM_ECDSA_SHA384		0x4C
#define NETCA_XML_SIGNATURE_ALGORITHM_ECDSA_SHA512		0x4D
#define NETCA_XML_SIGNATURE_ALGORITHM_ESIGN_SHA1		0x4E
#define NETCA_XML_SIGNATURE_ALGORITHM_ESIGN_SHA224		0x4F
#define NETCA_XML_SIGNATURE_ALGORITHM_ESIGN_SHA256		0x50
#define NETCA_XML_SIGNATURE_ALGORITHM_ESIGN_SHA384		0x51
#define NETCA_XML_SIGNATURE_ALGORITHM_ESIGN_SHA512		0x52
#define NETCA_XML_SIGNATURE_ALGORITHM_SM2_SM3			0x53




#define NETCA_XML_SIGNATURE_VERIFY_FLAG_ONLINE			1
#define NETCA_XML_SIGNATURE_VERIFY_FLAG_VERIFYMANIFEST	2


#define NETCA_XML_SIGNATURE_INCLUDE_CERT_FLAG_NONE					1
#define NETCA_XML_SIGNATURE_INCLUDE_CERT_FLAG_SELF					2
#define NETCA_XML_SIGNATURE_INCLUDE_CERT_FLAG_CERTPATH				3
#define NETCA_XML_SIGNATURE_INCLUDE_CERT_FLAG_CERTPATHWITHROOT		4

#define NETCA_XML_SIGNATURE_INCLUDE_CRLIDENTIFIER		1



struct NETCA_XML_Signature_Key_st;
typedef struct NETCA_XML_Signature_Key_st *NETCA_XML_Signature_Key;


#define NETCA_XML_SIGNATURE_KEYTYPE_HMAC	1
#define NETCA_XML_SIGNATURE_KEYTYPE_CERT	4
#define NETCA_XML_SIGNATURE_KEYTYPE_PUBKEY	5


struct NETCA_XML_Signature_TransformCtx_st;
typedef struct NETCA_XML_Signature_TransformCtx_st *NETCA_XML_Signature_TransformCtx;

struct NETCA_XML_Signature_ReferenceCtx_st;
typedef struct NETCA_XML_Signature_ReferenceCtx_st *NETCA_XML_Signature_ReferenceCtx;


struct NETCA_XML_Signature_SignedInfoCtx_st;
typedef struct NETCA_XML_Signature_SignedInfoCtx_st *NETCA_XML_Signature_SignedInfoCtx;

struct NETCA_XML_Signature_ObjectCtx_st;
typedef struct NETCA_XML_Signature_ObjectCtx_st *NETCA_XML_Signature_ObjectCtx;


struct NETCA_XML_Signature_SignaturePropertyCtx_st;
typedef struct NETCA_XML_Signature_SignaturePropertyCtx_st *NETCA_XML_Signature_SignaturePropertyCtx;

struct NETCA_XAdES_CertID_st;
typedef struct NETCA_XAdES_CertID_st *NETCA_XAdES_CertID;

#ifdef __cplusplus
}
#endif
#endif
