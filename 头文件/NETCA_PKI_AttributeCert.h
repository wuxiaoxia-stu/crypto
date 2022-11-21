#ifndef NETCA_PKI_ATTRIBUTE_CERT_INCLUDE_H
#define NETCA_PKI_ATTRIBUTE_CERT_INCLUDE_H

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIAttributeCertNew
 *		��������֤����
 *	������
 *		data���������������֤��ı���
 *		len���������������֤��ı���ĳ���
 *	����ֵ��
 *		�ɹ�������Ч������֤������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_ATTRIBUTE_CERT_HANDLE NETCADLLAPI NetcaPKIAttributeCertNew(const unsigned char *data,int len);


/*
 *	NetcaPKIAttributeCertFree
 *		�ͷ�����֤����
 *	������
 *		hCert������֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertFree(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetEncode
 *		��ȡ����֤���DER����
 *	������
 *		hCert������֤����
 *		data���������������ı���
 *		dataLen���������������ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetEncode(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,unsigned char **data,int *dataLen);

/*
 *	NetcaPKIAttributeCertGetSerialNumber
 *		��ȡ����֤������к�
 *	������
 *		hCert������֤����
 *	����ֵ��
 *		�ɹ��������кŵ�HEX���룬ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetSerialNumber(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetNotBefore
 *		��ȡ����֤�����Ч�ڿ�ʼʱ��
 *	������
 *		hCert������֤����
 *	����ֵ��
 *		�ɹ�������Ч�ڿ�ʼʱ�䣬ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetNotBefore(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetNotAfter
 *		��ȡ����֤�����Ч�ڽ���ʱ��
 *	������
 *		hCert������֤����
 *	����ֵ��
 *		�ɹ�������Ч�ڽ���ʱ�䣬ʧ�ܷ���NULL
 *
 */
char* NETCADLLAPI NetcaPKIAttributeCertGetNotAfter(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetAttributeCount
 *		��ȡ����֤������Ը���
 *	������
 *		hCert������֤����
 *	����ֵ��
 *		�ɹ��������Ը�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetAttributeCount(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert);

/*
 *	NetcaPKIAttributeCertGetAttribute
 *		��ȡ����֤�������
 *	������
 *		hCert������֤����
 *		index�������������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertGetAttribute(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,int index,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIAttributeCertFindExtension
 *		��ȡ����֤�����չ
 *	������
 *		hCert������֤����
 *		oid�������������չ��OID
 *		pcritical����������������չ�ǹؼ��ķ���1�����򷵻�0
 *		pvalue�����������������չ�ı���ֵ
 *		pvaluelen�����������������չ�ı���ֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�������չ�����ڷ���NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertFindExtension(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hCert,const char *oid,int *pcritical,unsigned char **pvalue,int *pvaluelen);

/*
 *	NetcaPKIAttributeCertVerify
 *		��֤����֤��
 *	������
 *		hAttrCert������֤����
 *		hIssuerCert������֤��İ䷢�߹�Կ֤��
 *		verifyTime�������������֤ʱ�䣬ΪNULL��Ϊ��ǰʱ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertVerify(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hAttrCert,NETCA_PKI_CERTIFICATE_HANDLE hIssuerCert,const char* verifyTime);

/*
 *	NetcaPKIAttributeCertMatchPublicKeyCert
 *		�ж�����֤���Ƿ�͹�Կ֤��ƥ��
 *	������
 *		hAttrCert������֤����
 *		hPublicKeyCert����Կ֤����
 *	����ֵ��
 *		ƥ�䷵��1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKIAttributeCertMatchPublicKeyCert(NETCA_PKI_ATTRIBUTE_CERT_HANDLE hAttrCert,NETCA_PKI_CERTIFICATE_HANDLE hPublicKeyCert);


#ifdef __cplusplus
	}	
#endif
#endif
