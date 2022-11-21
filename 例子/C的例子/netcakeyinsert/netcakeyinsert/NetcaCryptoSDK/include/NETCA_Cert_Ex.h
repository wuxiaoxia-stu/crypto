#ifndef NETCA_CERT_EX_INLCUDE_H
#define NETCA_CERT_EX_INLCUDE_H

#include "NETCA_Crypto_Type.h"
#include "NETCA_ASN1.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_cert_getserialnumber_ex
 *			获取证书的序列号
 *		参数：
 *			cert：证书
 *		返回值：
 *			成功返回证书的序列号,失败返回NULL
 */
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cert_getserialnumber_ex(NETCA_CERT cert);

/*
 *		netca_crl_revokedcert_getserialnumber_ex
 *			获取CRL作废证书条目的序列号
 *		参数：
 *			cert：CRL作废证书条目
 *		返回值：
 *			成功返回CRL作废证书条目的序列号,失败返回NULL
 */
NETCA_ASN1_Integer_Ptr NETCAAPI netca_crl_revokedcert_getserialnumber_ex(NETCA_CRL_RevokedCert cert);

/*
 *		netca_igetCertError
 *			获取证书部分的错误信息描述
 *		参数：
 *			errcode：错误号
 *		返回值：
 *			成功返回对应的错误信息描述,失败返回""
 */
const char * NETCAAPI netca_igetCertError(int errcode);
/*
 *		netca_cert_new2
 *			创建证书
 *		参数：
 *			cert：证书的ASN.1结构
 *			errctx：错误上下文
 *		返回值：
 *			成功返回证书,失败返回NULL
 */
NETCA_CERT NETCAAPI netca_cert_new2(NETCA_X509PubKeyCertificate_Ptr cert,NETCA_ERR_CTX errctx);
/*
 *		netca_cert_getasn1
 *			获取证书的ASN.1结构
 *		参数：
 *			cert：证书
 *		返回值：
 *			成功返回证书的ASN.1结构,失败返回NULL
 */
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_cert_getasn1(NETCA_CERT cert);

/*
 *		netca_crl_new2
 *			创建CRL
 *		参数：
 *			crl：CRL的ASN.1结构
 *			errctx：错误上下文
 *		返回值：
 *			成功返回CRL,失败返回NULL
 */
NETCA_CRL NETCAAPI netca_crl_new2(NETCA_X509CRL_Ptr crl,NETCA_ERR_CTX errctx);
/*
 *		netca_crl_getasn1
 *			获取CRL的ASN.1结构
 *		参数：
 *			crl：CRL
 *		返回值：
 *			成功返回CRL的ASN.1结构,失败返回NULL
 */
NETCA_X509CRL_Ptr NETCAAPI netca_crl_getasn1(NETCA_CRL crl);

/*
 *		netca_cert_algorithmid_new
 *			创建算法
 *		参数：
 *			algo：算法的ASN.1结构
 *		返回值：
 *			成功返回算法,失败返回NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_algorithmid_new(NETCA_X509AlgorithmIdentifier_Ptr algo);
/*
 *		netca_cert_dn_new
 *			创建DN
 *		参数：
 *			dn：DN的ASN.1结构
 *		返回值：
 *			成功返回DN,失败返回NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_new(NETCA_X500Name_Ptr dn);

/*
 *		netca_cert_attributes_new
 *			创建属性
 *		参数：
 *			list：属性的ASN.1结构
 *		返回值：
 *			成功返回属性,失败返回NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_attributes_new(NETCA_ASN1_List_Ptr list);

#ifdef __cplusplus
	}	
#endif
#endif

