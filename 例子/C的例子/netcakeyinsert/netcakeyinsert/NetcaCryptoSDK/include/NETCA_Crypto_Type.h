#ifndef NETCA_CRYPTO_TYPE_INLCUDE_H
#define NETCA_CRYPTO_TYPE_INLCUDE_H


#ifdef __cplusplus
extern "C"
	{
#endif

struct NETCA_CERT_st;
typedef struct NETCA_CERT_st * NETCA_CERT;

struct NETCA_CERT_X500_DN_st;
typedef struct NETCA_CERT_X500_DN_st * NETCA_CERT_X500_DN;

struct NETCA_CERT_X500_RDN_st;
typedef struct NETCA_CERT_X500_RDN_st * NETCA_CERT_X500_RDN;

struct NETCA_CERT_AttributeTypeAndValue_st;
typedef struct NETCA_CERT_AttributeTypeAndValue_st * NETCA_CERT_AttributeTypeAndValue;

struct NETCA_CERT_AlgorithmIdentifier_st;
typedef struct NETCA_CERT_AlgorithmIdentifier_st * NETCA_CERT_AlgorithmIdentifier;

struct NETCA_CERT_PubKey_st;
typedef struct NETCA_CERT_PubKey_st * NETCA_CERT_PubKey;


struct NETCA_CERT_DssParms_st;
typedef struct NETCA_CERT_DssParms_st *NETCA_CERT_DssParms;


struct NETCA_CERT_Extensions_st;
typedef struct NETCA_CERT_Extensions_st * NETCA_CERT_Extensions;

struct NETCA_CERT_Extension_st;
typedef struct NETCA_CERT_Extension_st * NETCA_CERT_Extension;


struct NETCA_CERT_GeneralNames_st;
typedef struct NETCA_CERT_GeneralNames_st *NETCA_CERT_GeneralNames;


#define NETCA_CERT_GENERALNAME_TYPE_OTHERNAME		0
#define NETCA_CERT_GENERALNAME_TYPE_RFC822NAME		1
#define NETCA_CERT_GENERALNAME_TYPE_DNSNAME			2
#define NETCA_CERT_GENERALNAME_TYPE_X400ADDRESS		3
#define NETCA_CERT_GENERALNAME_TYPE_DIRNAME			4
#define NETCA_CERT_GENERALNAME_TYPE_EDIPARTYNAME	5
#define NETCA_CERT_GENERALNAME_TYPE_URI				6
#define NETCA_CERT_GENERALNAME_TYPE_IPADDRESS		7
#define NETCA_CERT_GENERALNAME_TYPE_REGID			8

struct NETCA_CERT_GeneralName_st;
typedef struct NETCA_CERT_GeneralName_st *NETCA_CERT_GeneralName;

struct NETCA_CERT_OtherName_st;
typedef struct NETCA_CERT_OtherName_st *NETCA_CERT_OtherName;

struct NETCA_CERT_EDIPartyName_st;
typedef struct NETCA_CERT_EDIPartyName_st *NETCA_CERT_EDIPartyName;

struct NETCA_CERT_AKID_st;
typedef struct NETCA_CERT_AKID_st *NETCA_CERT_AKID;


struct NETCA_CERT_PolicyMapping_st;
typedef struct NETCA_CERT_PolicyMapping_st *NETCA_CERT_PolicyMapping;

struct NETCA_CERT_PolicyMappings_st;
typedef struct NETCA_CERT_PolicyMappings_st *NETCA_CERT_PolicyMappings;

struct NETCA_CERT_BasicConstraints_st;
typedef struct NETCA_CERT_BasicConstraints_st *NETCA_CERT_BasicConstraints;

struct NETCA_CERT_CertificatePolicies_st;
typedef struct NETCA_CERT_CertificatePolicies_st *NETCA_CERT_CertificatePolicies;

struct NETCA_CERT_PolicyInformation_st;
typedef struct NETCA_CERT_PolicyInformation_st *NETCA_CERT_PolicyInformation;


struct NETCA_CERT_PolicyQualifierInfo_st;
typedef struct NETCA_CERT_PolicyQualifierInfo_st *NETCA_CERT_PolicyQualifierInfo;

struct NETCA_CERT_UserNotice_st;
typedef struct NETCA_CERT_UserNotice_st *NETCA_CERT_UserNotice;


struct NETCA_CERT_Attributes_st;
typedef struct NETCA_CERT_Attributes_st *NETCA_CERT_Attributes;

struct NETCA_CERT_Attribute_st;
typedef struct NETCA_CERT_Attribute_st *NETCA_CERT_Attribute;


struct NETCA_CERT_GeneralSubtree_st;
typedef struct NETCA_CERT_GeneralSubtree_st *NETCA_CERT_GeneralSubtree;

struct NETCA_CERT_GeneralSubtrees_st;
typedef struct NETCA_CERT_GeneralSubtrees_st *NETCA_CERT_GeneralSubtrees;

struct NETCA_CERT_NameConstraints_st;
typedef struct NETCA_CERT_NameConstraints_st *NETCA_CERT_NameConstraints;


struct NETCA_CERT_PolicyConstraints_st;
typedef struct NETCA_CERT_PolicyConstraints_st *NETCA_CERT_PolicyConstraints;


struct NETCA_CERT_ExtKeyUsage_st;
typedef struct NETCA_CERT_ExtKeyUsage_st *NETCA_CERT_ExtKeyUsage;

#define NETCA_CERT_DPNAME_TYPE_FULLNAME				0
#define NETCA_CERT_DPNAME_TYPE_RELTOCRLISSUER		1

struct NETCA_CERT_DistributionPointName_st;
typedef struct NETCA_CERT_DistributionPointName_st *NETCA_CERT_DistributionPointName;

struct NETCA_CERT_DistributionPoint_st;
typedef struct NETCA_CERT_DistributionPoint_st *NETCA_CERT_DistributionPoint;

struct NETCA_CERT_CRLDistributionPoints_st;
typedef struct NETCA_CERT_CRLDistributionPoints_st *NETCA_CERT_CRLDistributionPoints;


struct NETCA_CERT_AccessDescription_st;
typedef struct NETCA_CERT_AccessDescription_st *NETCA_CERT_AccessDescription;

struct NETCA_CERT_AccessDescriptions_st;
typedef struct NETCA_CERT_AccessDescriptions_st *NETCA_CERT_AccessDescriptions;


struct NETCA_CERT_IssuingDistributionPoint_st;
typedef struct NETCA_CERT_IssuingDistributionPoint_st *NETCA_CERT_IssuingDistributionPoint;


struct NETCA_CERT_PrivateKeyUsagePeriod_st;
typedef struct NETCA_CERT_PrivateKeyUsagePeriod_st *NETCA_CERT_PrivateKeyUsagePeriod;

struct NETCA_Crypto_DSAKey_st;
typedef struct NETCA_Crypto_DSAKey_st *NETCA_Crypto_DSAKey;

struct NETCA_Crypto_DSACtx_st;
typedef struct NETCA_Crypto_DSACtx_st *NETCA_Crypto_DSACtx;

struct NETCA_Crypto_RSAKey_st;
typedef struct NETCA_Crypto_RSAKey_st *NETCA_Crypto_RSAKey;

struct NETCA_Crypto_RSACtx_st;
typedef struct NETCA_Crypto_RSACtx_st *NETCA_Crypto_RSACtx;


struct NETCA_CRL_st;
typedef struct NETCA_CRL_st * NETCA_CRL;

struct NETCA_CRL_RevokedCertList_st;
typedef struct NETCA_CRL_RevokedCertList_st * NETCA_CRL_RevokedCertList;


struct NETCA_CRL_RevokedCert_st;
typedef struct NETCA_CRL_RevokedCert_st * NETCA_CRL_RevokedCert;

struct NETCA_CERT_DigestInfo_st;
typedef struct NETCA_CERT_DigestInfo_st * NETCA_CERT_DigestInfo;

struct NETCA_CERT_DigestInfoList_st;
typedef struct NETCA_CERT_DigestInfoList_st * NETCA_CERT_DigestInfoList;

struct NETCA_CERT_IdentificationItem_st;
typedef struct NETCA_CERT_IdentificationItem_st * NETCA_CERT_IdentificationItem;

struct NETCA_CERT_IdentificationItems_st;
typedef struct NETCA_CERT_IdentificationItems_st * NETCA_CERT_IdentificationItems;

struct NETCA_PrivKey_Attr_st;
typedef struct NETCA_PrivKey_Attr_st * NETCA_PrivKey_Attr;

struct NETCA_PrivKey_Handle_st;
typedef struct NETCA_PrivKey_Handle_st * NETCA_PrivKey_Handle;

struct NETCA_CERT_Store_st;
typedef struct NETCA_CERT_Store_st * NETCA_CERT_Store;


#define NETCA_CERT_STORE_ATTRIBUTE_TYPE_PRIVATEKEY	1

struct NETCA_CERT_Store_Attribute_st;
typedef struct NETCA_CERT_Store_Attribute_st * NETCA_CERT_Store_Attribute;


typedef struct netca_encrypt_func_st* netca_encrypt_func_ptr;
typedef const struct netca_encrypt_func_st* netca_encrypt_func_cptr;

struct NETCA_Crypto_Ctx_st;
typedef struct NETCA_Crypto_Ctx_st *NETCA_Crypto_Ctx;

struct NETCA_Hash_Ctx_st;
typedef struct NETCA_Hash_Ctx_st *NETCA_Hash_Ctx;

struct NETCA_HMAC_Ctx_st;
typedef struct NETCA_HMAC_Ctx_st *NETCA_HMAC_Ctx;


struct NETCA_CertPath_st;
typedef struct NETCA_CertPath_st * NETCA_CertPath;

struct NETCA_CertPaths_st;
typedef struct NETCA_CertPaths_st * NETCA_CertPaths;

struct NETCA_CertPathBuilder_st;
typedef struct NETCA_CertPathBuilder_st * NETCA_CertPathBuilder;


struct NETCA_CertPathValidator_st;
typedef struct NETCA_CertPathValidator_st * NETCA_CertPathValidator;

struct NETCA_PolicySet_st;
typedef struct NETCA_PolicySet_st * NETCA_PolicySet;

struct NETCA_OCSPRequest_st;
typedef struct NETCA_OCSPRequest_st *NETCA_OCSPRequest;

struct NETCA_OCSPRequest_CertID_st;
typedef struct NETCA_OCSPRequest_CertID_st* NETCA_OCSPRequest_CertID;

struct NETCA_OCSPRequest_RequestItem_st;
typedef struct NETCA_OCSPRequest_RequestItem_st *NETCA_OCSPRequest_RequestItem;

struct NETCA_OCSPRequest_RequestList_st;
typedef struct NETCA_OCSPRequest_RequestList_st *NETCA_OCSPRequest_RequestList;


struct NETCA_OCSPResponse_st;
typedef struct NETCA_OCSPResponse_st *NETCA_OCSPResponse;

struct NETCA_ECC_Domain_Parameters_st;
typedef struct NETCA_ECC_Domain_Parameters_st* NETCA_ECC_Domain_Parameters;

struct NETCA_ECC_Point_st;
typedef struct NETCA_ECC_Point_st* NETCA_ECC_Point;

struct NETCA_ECC_PubKey_st;
typedef struct NETCA_ECC_PubKey_st* NETCA_ECC_PubKey;



#ifdef __cplusplus
	}	
#endif
#endif
