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
 *			��ȡ֤������к�
 *		������
 *			cert��֤��
 *		����ֵ��
 *			�ɹ�����֤������к�,ʧ�ܷ���NULL
 */
NETCA_ASN1_Integer_Ptr NETCAAPI netca_cert_getserialnumber_ex(NETCA_CERT cert);

/*
 *		netca_crl_revokedcert_getserialnumber_ex
 *			��ȡCRL����֤����Ŀ�����к�
 *		������
 *			cert��CRL����֤����Ŀ
 *		����ֵ��
 *			�ɹ�����CRL����֤����Ŀ�����к�,ʧ�ܷ���NULL
 */
NETCA_ASN1_Integer_Ptr NETCAAPI netca_crl_revokedcert_getserialnumber_ex(NETCA_CRL_RevokedCert cert);

/*
 *		netca_igetCertError
 *			��ȡ֤�鲿�ֵĴ�����Ϣ����
 *		������
 *			errcode�������
 *		����ֵ��
 *			�ɹ����ض�Ӧ�Ĵ�����Ϣ����,ʧ�ܷ���""
 */
const char * NETCAAPI netca_igetCertError(int errcode);
/*
 *		netca_cert_new2
 *			����֤��
 *		������
 *			cert��֤���ASN.1�ṹ
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����֤��,ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_cert_new2(NETCA_X509PubKeyCertificate_Ptr cert,NETCA_ERR_CTX errctx);
/*
 *		netca_cert_getasn1
 *			��ȡ֤���ASN.1�ṹ
 *		������
 *			cert��֤��
 *		����ֵ��
 *			�ɹ�����֤���ASN.1�ṹ,ʧ�ܷ���NULL
 */
NETCA_X509PubKeyCertificate_Ptr NETCAAPI netca_cert_getasn1(NETCA_CERT cert);

/*
 *		netca_crl_new2
 *			����CRL
 *		������
 *			crl��CRL��ASN.1�ṹ
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����CRL,ʧ�ܷ���NULL
 */
NETCA_CRL NETCAAPI netca_crl_new2(NETCA_X509CRL_Ptr crl,NETCA_ERR_CTX errctx);
/*
 *		netca_crl_getasn1
 *			��ȡCRL��ASN.1�ṹ
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��ASN.1�ṹ,ʧ�ܷ���NULL
 */
NETCA_X509CRL_Ptr NETCAAPI netca_crl_getasn1(NETCA_CRL crl);

/*
 *		netca_cert_algorithmid_new
 *			�����㷨
 *		������
 *			algo���㷨��ASN.1�ṹ
 *		����ֵ��
 *			�ɹ������㷨,ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_algorithmid_new(NETCA_X509AlgorithmIdentifier_Ptr algo);
/*
 *		netca_cert_dn_new
 *			����DN
 *		������
 *			dn��DN��ASN.1�ṹ
 *		����ֵ��
 *			�ɹ�����DN,ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_new(NETCA_X500Name_Ptr dn);

/*
 *		netca_cert_attributes_new
 *			��������
 *		������
 *			list�����Ե�ASN.1�ṹ
 *		����ֵ��
 *			�ɹ���������,ʧ�ܷ���NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_attributes_new(NETCA_ASN1_List_Ptr list);

#ifdef __cplusplus
	}	
#endif
#endif

