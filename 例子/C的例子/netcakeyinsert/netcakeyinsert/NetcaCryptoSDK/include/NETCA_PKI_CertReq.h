#ifndef _NETCA_PKI_CERTREQ_INLCUDE_H_
#define _NETCA_PKI_CERTREQ_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKICertReqNew
 *		����֤��������
 *	������
 *		�ޡ�
 *	����ֵ��
 *		�ɹ�������Ч��֤����������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTREQ_HANDLE NETCADLLAPI NetcaPKICertReqNew(void);


/*
 *	NetcaPKICertReqFree
 *		�ͷ�֤��������
 *	������
 *		hCertReq��֤��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqFree(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqSetIntegerAttribute
 *		����֤���������������
 *	������
 *		hCertReq��֤��������
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqSetIntegerAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,int value);


/*
 *	NetcaPKICertReqSetStringAttribute
 *		����֤��������ַ�������
 *	������
 *		hCertReq��֤��������
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqSetStringAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,const char *value);

/*
 *	NetcaPKICertReqSign
 *		ǩ������֤������
 *	������
 *		hCertReq��֤��������
 *		hKeypair��ǩ��˽Կ
 *		signAlgo�����������ǩ���㷨
 *		param�����������ǩ������
 *		certReq��������������ص�֤������
 *		certReqLen��������������ص�֤������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqSign(NETCA_PKI_CERTREQ_HANDLE hCertReq,NETCA_PKI_KEYPAIR_HANDLE hKeypair,int signAlgo,const void *param,unsigned char **certReq,int *certReqLen);

/*
 *	NetcaPKICertReqSignWithCallback
 *		ǩ������֤������
 *	������
 *		hCertReq��֤��������
 *		spki��������������幫Կ��DER����
 *		spkiLen��������������幫Կ��DER����ĳ���
 *		signAlgo�����������ǩ���㷨
 *		param�����������ǩ������
 *		signCallback�����������ǩ���ص�����
 *		context���ص������Ĳ���
 *		certReq��������������ص�֤������
 *		certReqLen��������������ص�֤������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqSignWithCallback(NETCA_PKI_CERTREQ_HANDLE hCertReq,const unsigned char *spki,int spkiLen,int signAlgo,const void *param,NetcaCertReqSignHashCallback_Ptr signCallback,void *context,unsigned char **certReq,int *certReqLen);


/*
 *	NetcaPKICertReqDecode
 *		����֤��������
 *	������
 *		data��֤������ı��롣
 *		dataLen��֤������ı��볤�ȡ�
 *	����ֵ��
 *		�ɹ�������Ч��֤����������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTREQ_HANDLE NETCADLLAPI NetcaPKICertReqDecode(const unsigned char *data,int dataLen);


/*
 *	NetcaPKICertReqGetIntegerAttribute
 *		��ȡ֤���������������
 *	������
 *		hCertReq��֤��������
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqGetIntegerAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,int *value);


/*
 *	NetcaPKICertReqGetStringAttribute
 *		��ȡ֤��������ַ�������
 *	������
 *		hCertReq��֤��������
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqGetStringAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int atrrId,char **value);


/*
 *	NetcaPKICertReqVerify
 *		��֤֤�������ǩ��
 *	������
 *		hCertReq��֤��������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqVerify(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqSetSubject
 *		����֤�����������
 *	������
 *		hCertReq��֤��������
 *		data���������������ı���
 *		dataLen���������������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqSetSubject(NETCA_PKI_CERTREQ_HANDLE hCertReq,const unsigned char *data,int dataLen);

/*
 *	NetcaPKICertReqGetSubject
 *		��ȡ֤�����������
 *	������
 *		hCertReq��֤��������
 *		data���������������ı���
 *		dataLen���������������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqGetSubject(NETCA_PKI_CERTREQ_HANDLE hCertReq,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICertReqGetSubject
 *		��ȡ֤�����������
 *	������
 *		hCertReq��֤��������
 *		data���������������ı���
 *		dataLen���������������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCADLLAPI NetcaPKICertReqGetPublicKey(NETCA_PKI_CERTREQ_HANDLE hCertReq);


/*
 *	NetcaPKICertReqGetEncode
 *		��ȡ֤�������DER����
 *	������
 *		hCertReq��֤��������
 *		data���������������ı���
 *		dataLen���������������ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqGetEncode(NETCA_PKI_CERTREQ_HANDLE hCertReq,unsigned char **data,int *dataLen);

/*
 *	NetcaPKICertReqAddAttribute
 *		���֤����������
 *	������
 *		hCertReq��֤��������
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqAddAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKICertReqGetAttribute
 *		��ȡ֤�����������
 *	������
 *		hCertReq��֤��������
 *		index�������������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKICertReqGetAttribute(NETCA_PKI_CERTREQ_HANDLE hCertReq,int index,char **attrType,unsigned char **attrValue,int *attrValueLen);

#ifdef __cplusplus
	}	
#endif
#endif
