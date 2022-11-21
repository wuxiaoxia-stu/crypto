#ifndef _NETCA_PKI_APPLICATION_INLCUDE_H_
#define _NETCA_PKI_APPLICATION_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif




/* �����ŷ���غ��� */

/*
 *	NetcaPKIMsgNewEnvelopedData
 *		���������ŷ���
 *	������
 *		enc�����������Ϊ���ʾ�ڴ��������ŷ⣬Ϊ�ٱ�ʾ�ڽ⿪�����ŷ�
 *	����ֵ��
 *		�ɹ����������ŷ�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_ENVELOPEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgNewEnvelopedData(int enc);

/*
 *	NetcaPKIMsgFreeEnvelopedData
 *		�ͷ������ŷ���
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeEnvelopedData(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataSetEncAlgorithm
 *		���������ŷ�ĶԳƼ����㷨
 *	������
 *		hEnvelopedData�������ŷ���
 *		encAlgo������������ԳƼ����㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int encAlgo);


/*
 *	NetcaPKIMsgEnvelopedDataAddCert
 *		�������ŷ�����Ӽ���֤��
 *	������
 *		hEnvelopedData�������ŷ���
 *		cert���������������֤��
 *		flag�������������־
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataAddCert(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_CERTIFICATE_HANDLE cert,int flag);


/*
 *	NetcaPKIMsgEnvelopedDataSetCryptoHandle
 *		���������ŷ����ԳƼӽ���ʹ�õ��豸���
 *	������
 *		hEnvelopedData�������ŷ���
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetCryptoHandle(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKIMsgEnvelopedDataSetUseSM2Q7
 *		����ʹ��GM/T 0010-2012�������ŷ��ʽ
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetUseSM2Q7(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataSetNoContentInfo
 *		���������ŷ��������ContentInfo�ķ�װ��������EnvelopedData
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetNoContentInfo(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataSetIntegerAttribute
 *		���������ŷ���������͵�����
 *	������
 *		hEnvelopedData�������ŷ���
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetIntegerAttribute(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int atrrId,int value);

/*
 *	NetcaPKIMsgEnvelopedDataSetStringAttribute
 *		���������ŷ���ַ������͵�����
 *	������
 *		hEnvelopedData�������ŷ���
 *		atrrId���������������ID
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetStringAttribute(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int atrrId,const char* value);

/*
 *	NetcaPKIMsgEnvelopedDataEncryptInit
 *		��ʼ���������ŷ�
 *	������
 *		hEnvelopedData�������ŷ���
 *		cipher���������������
 *		cipherlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptInit(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,unsigned char **cipher,int *cipherlen);

/*
 *	NetcaPKIMsgEnvelopedDataEncryptUpdate
 *		������ģ����м���
 *	������
 *		hEnvelopedData�������ŷ���
 *		clear���������������
 *		clearlen��������������ĳ���
 *		cipher���������������
 *		cipherlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptUpdate(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *clear,int clearlen,unsigned char **cipher,int *cipherlen);


/*
 *	NetcaPKIMsgEnvelopedDataEncryptFinal
 *		��������
 *	������
 *		hEnvelopedData�������ŷ���
 *		cipher���������������
 *		cipherlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncryptFinal(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, unsigned char **cipher,int *cipherlen);


/*
 *	NetcaPKIMsgEnvelopedDataEncrypt
 *		���м��ܣ�������������ŷ�
 *	������
 *		hEnvelopedData�������ŷ���
 *		clear���������������
 *		clearlen��������������ĳ���
 *		cipher���������������
 *		cipherlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataEncrypt(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const unsigned char *clear,int clearlen,unsigned char **cipher,int *cipherlen);

/*
 *	NetcaPKIMsgEnvelopedDataAddStore
 *		��ӽ��ܵ�֤�����ڵ�֤���
 *	������
 *		hEnvelopedData�������ŷ���
 *		store��֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataAddStore(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKIMsgEnvelopedDataSetDecryptKeyCallback
 *		���ý��ܶԳ���Կ�Ļص�����
 *	������
 *		hEnvelopedData�������ŷ���
 *		callback���ص�����
 *		context���ص������Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetDecryptKeyCallback(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NetcaEnvelopedDataDecryptKeyCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgEnvelopedDataDecrypt
 *		���������ŷ�
 *	������
 *		hEnvelopedData�������ŷ���
 *		cipher���������������
 *		cipherlen��������������ĳ���
 *		clear���������������
 *		clearlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecrypt(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *cipher,int cipherlen,unsigned char **clear,int *clearlen);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptInit
 *		��ʼ���������ŷ�
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptInit(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptUpdate
 *		���������ŷ⣬���Ե��ö�Ρ�
 *	������
 *		hEnvelopedData�������ŷ���
 *		cipher���������������
 *		cipherlen��������������ĳ���
 *		clear���������������
 *		clearlen��������������ص����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptUpdate(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, const unsigned char *cipher,int cipherlen,unsigned char **clear,int *clearlen);

/*
 *	NetcaPKIMsgEnvelopedDataDecryptFinal
 *		�������������ŷ⡣
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataDecryptFinal(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataSetPwd
 *		�������롣������ʹ��
 *	������
 *		hEnvelopedData�������ŷ���
 *		pwd���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetPwd(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const char *pwd);

/*
 *	NetcaPKIMsgEnvelopedDataSetKey
 *		���ý��ܵĶԳ���Կ
 *	������
 *		hEnvelopedData�������ŷ���
 *		key���������������ʹ�õĶԳ���Կ
 *		keyLen:�������������ʹ�õĶԳ���Կ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetKey(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,const unsigned char *key,int keyLen);

/*
 *	NetcaPKIMsgEnvelopedDataGetEncAlgorithm
 *		��ȡ�����ŷ�ĶԳƼ����㷨��
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ����ضԳƼ����㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataGetEncAlgorithm(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataGetCert
 *		��ȡ�����ŷ�Ľ���֤�顣
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�ɹ����ؽ���֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgEnvelopedDataGetCert(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);

/*
 *	NetcaPKIMsgEnvelopedDataIsContentInfo
 *		�ж������ŷ���Ƿ�ΪContentInfo��װ
 *	������
 *		hEnvelopedData�������ŷ���
 *	����ֵ��
 *		�Ƿ���1�����Ƿ���0
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataIsContentInfo(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData);


/*
 *	NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode
 *		��ȡ�����ŷ�Ľ�������Ϣ�ı���
 *	������
 *		hEnvelopedData�������ŷ���
 *		recipientInfos�������������������Ϣ�ı���
 *		recipientInfosLen��������������صĽ�������Ϣ�ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��NETCA_PKI_NEED_MORE_DATA��ʾ���޷��жϣ�ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData, unsigned char **recipientInfos ,int *recipientInfosLen);


/*
 *	NetcaPKIMsgEnvelopedDataMaybe
 *		�ж��Ƿ�����������ŷ�
 *	������
 *		data����������������ŷ�����ǰ�沿��
 *		dataLen�����������data�ĳ���
 *	����ֵ��
 *		�����Ƿ���1�����Ƿ���0
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataMaybe(const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgEnvelopedDataSetPromptMsg
 *		���ý���ʱ����ʾ��Ϣ��
 *	������
 *		hEnvelopedData�������ŷ���
 *		flag�����������NETCA_PKI_PROMTMSG_FLAG_NO_ARGUMENT��ʾû�в�����ֱ����ʾmsg��
 *		msg�������������ʾ��Ϣ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKIMsgEnvelopedDataSetPromptMsg(NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,int flag,const char *msg);

/*
 *	NetcaPKIMsgNewSignedData
 *		����SignedData���
 *	������
 *		sign�����������Ϊ���ʾ������ǩ����Ϊ�ٱ�ʾ��������֤��
 *	����ֵ��
 *		�ɹ�������Ч��SignedData�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgNewSignedData(int sign);


/*
 *	NetcaPKIMsgFreeSignedData
 *		�ͷ�SignedData���
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeSignedData(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataSetIntegerAttribute
 *		����SignedData����������
 *	������
 *		hSignedData��SignedData���
 *		atrrId���������������ID
 *		index���������������ֵ����0����ĳЩ���Ի�������ֵ
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetIntegerAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,int value);


/*
 *	NetcaPKIMsgSignedDataSetStringAttribute
 *		����SignedData���ַ�������
 *	������
 *		hSignedData��SignedData���
 *		atrrId���������������ID
 *		index���������������ֵ����0����ĳЩ���Ի�������ֵ
 *		value���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetStringAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,const char *value);

/*
 *	NetcaPKIMsgSignedDataSetSignCert
 *		����SignedData��ǩ��֤��
 *	������
 *		hSignedData��SignedData���
 *		cert��ǩ��֤��
 *		pwd��������������롣����ΪNULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSignCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd);

/*
 *	NetcaPKIMsgSignedDataSetEncCert
 *		����SignedData��ǩ���߶�Ӧ�ļ���֤��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ������ֵ
 *		flag:�������������֤��ı�־����
 *		cert������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetEncCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, int index,int flag,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedDataAddCert
 *		ΪSignedData�����֤��
 *	������
 *		hSignedData��SignedData���
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedDataAddCRLObject
 *		ΪSignedData�����CRL
 *	������
 *		hSignedData��SignedData���
 *		crlObj�����������CRL���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCRLObject(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, NETCA_PKI_CRL_HANDLE crlObj);

/*
 *	NetcaPKIMsgSignedDataAddCRL
 *		ΪSignedData�����CRL
 *	������
 *		hSignedData��SignedData���
 *		crl�����������CRL�ı���
 *		crlLen:���������CRL�ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCRL(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *crl,int crlLen);

/*
 *	NetcaPKIMsgSignedDataAddOCSP
 *		ΪSignedData�����OCSP
 *	������
 *		hSignedData��SignedData���
 *		flag�������������־����ǰΪ0
 *		vaCert�����������OCSP��֤��
 *		ocsp�����������OCSP�ı���
 *		ocspLen:���������OCSP�ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddOCSP(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int flag,NETCA_PKI_CERTIFICATE_HANDLE vaCert,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKIMsgSignedDataSetCryptoHandle
 *		����SignedData���Hashʹ�õ��豸���
 *	������
 *		hSignedData��SignedData���
 *		hDevice���豸���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCryptoHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_DEVICE_HANDLE hDevice);

/*
 *	NetcaPKIMsgSignedDataAddSignedAttribute
 *		���ǩ������
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddSignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKIMsgSignedDataAddUnsSignedAttribute
 *		���δǩ������
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType,const unsigned char *attrValue,int attrValueLen);

/*
 *	NetcaPKIMsgSignedDataDeleteUnsignedAttribute
 *		ɾ��δǩ������
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		attrType�������������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDeleteUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const char *attrType);

/*
 *	NetcaPKIMsgSignedDataSetCompleteCertificateRefs
 *		����CompleteCertificateRefs����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		hashAlgo�����������Hash�㷨
 *		hasIssuerSN������������Ƿ�ʹ�ð䷢���������к�
 *		certs�����������CA֤��
 *		certCount�����������CA֤��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCompleteCertificateRefs(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,int hasIssuerSN,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount);

/*
 *	NetcaPKIMsgSignedDataAddCompleteRevocationRef
 *		���CompleteRevocationRefs����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		flag�������������־
 *		hashAlgo�����������Hash�㷨
 *		crlData�����������CRL�ı���
 *		crlDataLen�����������CRL�ı��볤��
 *		ocsp�����������OCSP��Ӧ�ı���
 *		ocspLen�����������OCSP��Ӧ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCompleteRevocationRef(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int flag,int hashAlgo,const unsigned char *crlData,int crlDataLen,const unsigned char *ocsp,int ocspLen);

/*
 *	NetcaPKIMsgSignedDataSetCertificateValues
 *		����CertificateValues����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		certs�����������CA֤��
 *		certCount�����������CA֤��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetCertificateValues(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount);

/*
 *	NetcaPKIMsgSignedDataSetRevocationValues
 *		����RevocationValues����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		crls�����������CRL���������
 *		crlsLen�����������CRL���볤�ȵ�����
 *		crlCount�����������CRL�ĸ���
 *		ocsps�����������OCSP���������
 *		ocspsLen�����������OCSP���볤�ȵ�����
 *		ocspCount�����������OCSP����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetRevocationValues(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount);

/*
 *	NetcaPKIMsgSignedDataSetAdbeRevocationInfoArchival
 *		����Adbe RevocationInfoArchival����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		crls�����������CRL���������
 *		crlsLen�����������CRL���볤�ȵ�����
 *		crlCount�����������CRL�ĸ���
 *		ocsps�����������OCSP���������
 *		ocspsLen�����������OCSP���볤�ȵ�����
 *		ocspCount�����������OCSP����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetAdbeRevocationInfoArchival(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *crls[],int crlsLen[],int crlCount,const unsigned char *ocsps[],int ocspsLen[],int ocspCount);

/*
 *	NetcaPKIMsgSignedDataEncode
 *		��SignedData�ٴν��б��룬ͨ�����������δǩ�����Ժ�
 *	������
 *		hSignedData��SignedData���
 *		sign�����������ǩ��ֵ
 *		signLen��������������ص�sign����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataEncode(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char **sign,int *signLen);

/*
 *	NetcaPKIMsgSignedDataSetSignCallback
 *		����ǩ���Ļص�����
 *	������
 *		hSignedData��SignedData���
 *		callback���ص�����
 *		context���ص������Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSignCallback(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NetcaSignedDataSignHashCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgSignedDataSign
 *		����ǩ�����������һ�η���ǩ���Ľ��
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ��
 *		tbslen�����������tbs�ĳ���
 *		sign�����������ǩ��ֵ
 *		signlen��������������ص�sign����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSign(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *tbs,int tbslen, unsigned char **sign,int *signlen);


/*
 *	NetcaPKIMsgSignedDataCountersign
 *		����ǩ��
 *	������
 *		hSignedData��SignedData���
 *		index�����������������
 *		algo�����������ǩ���㷨 
 *		cert�����������ǩ��֤��
 *		pwd���������������
 *		sign�����������ǩ��ֵ
 *		signlen��������������ص�sign����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataCountersign(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int algo,NETCA_PKI_CERTIFICATE_HANDLE cert,const char *pwd,unsigned char **sign,int *signlen);

/*
 *	NetcaPKIMsgSignedDataSignWithTimeStamp
 *		���д�ʱ���ǩ�����������һ�η���ǩ���Ľ��
 *	������
 *		hSignedData��SignedData���
 *		tsaName�����������ʱ���������������
 *		tbs�����������ԭ��
 *		tbslen�����������tbs�ĳ���
 *		sign�����������ǩ��ֵ
 *		signlen��������������ص�sign����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignWithTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const char *tsaName, const unsigned char *tbs,int tbslen, unsigned char **sign,int *signlen);

/*
 *	NetcaPKIMsgSignedDataSetContentTimeStamp
 *		���content-time-stamp��������ԭ������֮ǰ����
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetContentTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAttachSignatureTimeStamp
 *		���Signature-time-stamp�����ԭ������Signature-time-stamp�������µ��滻���ɵ�
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachSignatureTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddEscTimeStamp
 *		���ES-C Timestamp Attribute��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddEscTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddCertCRLTimeStamp
 *		���Time-Stamped Certificates and CRLs��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddCertCRLTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV2
 *		���archive-time-stamp V2 Attribute��
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ�ġ����SignedData����б�����ԭ�ģ�����Ըò���
 *		tbsLen�����������ԭ�ĳ���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV2(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV3
 *		���archive-time-stamp V3 Attribute��
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ�ġ����SignedData����б�����ԭ�ģ�����Ըò���
 *		tbsLen�����������ԭ�ĳ���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int hashAlgo,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAddArchiveTimeStampV3ByHashValue
 *		���archive-time-stamp V3 Attribute��
 *	������
 *		hSignedData��SignedData���
 *		hashAlgo�����������Hash�㷨
 *		hashValue�����������ԭ�ĵ�Hashֵ
 *		hashLen�����������ԭ�ĵ�Hash����
 *		tsaName�����������ʱ���������������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddArchiveTimeStampV3ByHashValue(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,const unsigned char *hashValue,int hashLen,const char *tsaName);

/*
 *	NetcaPKIMsgSignedDataAttachATSHashIndex
 *		���ats-hash-index��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachATSHashIndex(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo);

/*
 *	NetcaPKIMsgSignedDataAttachATSHashIndexV3
 *		���ats-hash-index-v3��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������ֵ
 *		hashAlgo�����������Hash�㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAttachATSHashIndexV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo);

/*
 *	NetcaPKIMsgSignedDataSignInit
 *		���жಽǩ���ĳ�ʼ��
 *	������
 *		hSignedData��SignedData���
 *		out���������������Ľ��
 *		outlen��������������ص�out����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignUpdate
 *		���жಽǩ����ԭ�����룬���Ե��ö��
 *	������
 *		hSignedData��SignedData���
 *		in��������������������
 *		inlen�����������in�ĳ���
 *		out���������������Ľ��
 *		outlen��������������ص�out����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const unsigned char *in,int inlen ,unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignFinal
 *		����ǩ���������ಽǩ��
 *	������
 *		hSignedData��SignedData���
 *		out���������������Ľ��
 *		outlen��������������ص�out����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, unsigned char **out,int *outlen);

/*
 *	NetcaPKIMsgSignedDataSignWithTimeStampFinal
 *		���д�ʱ�����ǩ���������ಽǩ��
 *	������
 *		hSignedData��SignedData���
 *		tsaName�����������ʱ���������������
 *		out���������������Ľ��
 *		outlen��������������ص�out����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSignWithTimeStampFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData, const char *tsaName,unsigned char **out,int *outlen);


/*
 *	NetcaPKIMsgSignedDataGetCert
 *		��ȡSignedData��֤��
 *	������
 *		sign�����������SignedData�ı���ֵ
 *		signlen�����������sign�ĳ���
 *		certs��������������ص�֤������
 *		count��������������ص�֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCert(const unsigned char *sign,int signlen, NETCA_PKI_CERTIFICATE_HANDLE **certs,int* count);

/*
 *	NetcaPKIMsgSignedDataGetCertificates
 *		��ȡSignedData��֤��
 *	������
 *		hSignedData�����������SignedData���
 *		certs��������������ص�֤������
 *		count��������������ص�֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCertificates(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_CERTIFICATE_HANDLE **certs,int* count);


/*
 *	NetcaPKIMsgSignedDataGetAllPublicKeyCertificate
 *		��ȡSignedData�е����е�֤�飬����ʱ������֤��
 *	������
 *		hSignedData�����������SignedData���
 *		certs��������������ص�֤������
 *		count��������������ص�֤����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetAllPublicKeyCertificate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_CERTIFICATE_HANDLE **certs,int* count);

/*
 *	NetcaPKIMsgSignedDataGetCertificateSet
 *		��ȡSignedData��֤����룬Ҳ����SignedData.certificates
 *	������
 *		hSignedData�����������SignedData���
 *		certs��������������ص�֤����������
 *		certLen��������������ص�֤�����ĳ�������
 *		count��������������ص�֤��ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCertificateSet(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***certs, int **certLen,int* count);


/*
 *	NetcaPKIMsgSignedDataGetCRLs
 *		��ȡSignedData��CRL
 *	������
 *		hSignedData�����������SignedData���
 *		crls��������������ص�CRL���������
 *		crlLen��������������ص�CRL����ĳ�������
 *		count��������������ص�CRL����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetCRLs(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***crls, int **crlLen,int* count);

/*
 *	NetcaPKIMsgSignedDataGetRevocationInfoChoices
 *		��ȡSignedData��������Ϣ���룬Ҳ����SignedData.crls
 *	������
 *		hSignedData�����������SignedData���
 *		crls��������������ص�������Ϣ���������
 *		crlLen��������������ص�������Ϣ����ĳ�������
 *		count��������������ص�������Ϣ�ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetRevocationInfoChoices(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,unsigned char ***crls, int **crlLen,int* count);

/*
 *	NetcaPKIMsgSignedDataGetAllRevocationInfo
 *		��ȡSignedData�е����е�CRL��OCSP������ʱ������
 *	������
 *		hSignedData�����������SignedData���
 *		infos��������������ص�CRL��OCSP����
 *		count��������������ص�CRL��OCSP��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetAllRevocationInfo(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_REVOKE_INFO_SOURCE_HANDLE **infos,int* count);

/*
 *	NetcaPKIMsgSignedDataAddRootCert
 *		��Ӹ�֤�飬Ϊ��֤��׼��
 *	������
 *		hSignedData��SignedData���
 *		rootCert����֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataAddRootCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_CERTIFICATE_HANDLE rootCert);

/*
 *	NetcaPKIMsgSignedDataSetSigningCertificateAttribute
 *		����SigningCertificate����SigningCertificateV2����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ
 *		hashAlgo�����������Hash�㷨�����ΪSHA-1������SigningCertificate���ԣ���������SigningCertificateV2����
 *		includeIssuerSerial�����������Ϊ��������䷢�����кţ�Ϊ���򲻰���
 *		certs:���������֤��
 *		certCount�����������֤�����
 *		policies�����������֤����Եı���
 *		policiesLen�����������֤����Եı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetSigningCertificateAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int hashAlgo,int includeIssuerSerial,NETCA_PKI_CERTIFICATE_HANDLE certs[],int certCount,const unsigned char *policies,int policiesLen);


/*
 *	NetcaPKIMsgSignedDataVerify
 *		��֤��ԭ�ĵ�ǩ��������һ����ɵĲ���
 *	������
 *		hSignedData��SignedData���
 *		sign�����������SignedData�ı���ֵ
 *		signlen�����������sign�ĳ���
 *		tbs��������������ص�ԭ��
 *		tbslen�����������ԭ�ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerify(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *sign,int signlen,unsigned char **tbs,int *tbslen);

/*
 *	NetcaPKIMsgSignedDataVerifyTimeStamp
 *		��֤ʱ�����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ
 *		tsaCert�����������ʱ���֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE tsaCert);

/*
 *	NetcaPKIMsgSignedDataGetTimeStampHandle
 *		��ȡʱ��������������֤ʱ����ɹ��󣬲��ܵ��óɹ�
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ
 *	����ֵ��
 *		�ɹ�����ʱ��������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetTimeStampHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataVerifyContentTimeStamp
 *		��֤Contentʱ�����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyContentTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyEscTimeStamp
 *		��֤ES-Cʱ�����
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyEscTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyCertCRLTimeStamp
 *		��֤CertCRLʱ�����
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyCertCRLTimeStamp(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV2
 *		��֤archive-time-stamp V2�����
 *	������
 *		hSignedData��SignedData���
 *		signedData�����������SignedData����
 *		signedDataLen�����������SignedData����ĳ���
 *		tbs�����������ԭ�ģ����Բ���ԭ�ĵ�ǩ������SignedData����в�������ԭ����Ч
 *		tbsLen�����������ԭ�ĳ���
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV2(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *signedData,long long signedDataLen,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3
 *		��֤archive-time-stamp V3ʱ�����
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ�ģ�����SignedData����в�������ԭ����Ч
 *		tbsLen�����������ԭ�ĳ���
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,long long tbsLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3ByHashValue
 *		��֤archive-time-stamp V3ʱ�����
 *	������
 *		hSignedData��SignedData���
 *		hashValue�����������ԭ�ĵ�Hashֵ
 *		hashLen�����������Hash����
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *		tsaCert�����������ʱ���֤��
 *		phTimeStamp�����������ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyArchiveTimeStampV3ByHashValue(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *hashValue,int hashLen,int index,int tsIndex,NETCA_PKI_CERTIFICATE_HANDLE tsaCert,NETCA_PKI_TIMESTAMP_HANDLE *phTimeStamp);

/*
 *	NetcaPKIMsgSignedDataGetArchiveTimeStampV3HashAlgo
 *		��ȡarchive-time-stamp V3ʱ�����Hash�㷨��
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��ֵ����
 *		tsIndex�����������ʱ�������
 *	����ֵ��
 *		�ɹ�����archive-time-stamp V3�����Hash�㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetArchiveTimeStampV3HashAlgo(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int tsIndex);

/*
 *	NetcaPKIMsgSignedDataDecodeAttributeForATSHashIndexV3
 *		�����Ա���ת��ΪATSHashIndexV3��Ҫ�ĸ������
 *	������
 *		attrEncode��������������Եı���
 *		attrLen��������������Ա���ĳ���
 *		data��������������ص���������������
 *		dataLen��������������ص�������ĳ�������
 *		count��������������ص�������ĸ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDecodeAttributeForATSHashIndexV3(const unsigned char *attrEncode,int attrLen,unsigned char ***data, int **dataLen,int* count);

/*
 *	NetcaPKIMsgSignedDataVerifyCountersignature
 *		��֤����ǩ����
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ
 *		countersignIndex���������������ǩ������ֵ����0����
 *		cert�����������ǩ��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyCountersignature(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int countersignIndex,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKIMsgSignedDataVerifyInit
 *		��ʼ����֤��ԭ�ĵ�ǩ��
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataVerifyUpdate
 *		�������SignedData�ı���ֵ���д�ԭ�ĵ�ǩ����֤
 *	������
 *		hSignedData��SignedData���
 *		sign�����������SignedData�ı���ֵ
 *		signlen�����������sign�ĳ���
 *		tbs��������������ص�ԭ��
 *		tbslen�����������ԭ�ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char * sign,int signlen, unsigned char **tbs,int *tbslen);

/*
 *	NetcaPKIMsgSignedDataVerifyFinal
 *		������ԭ�ĵ�ǩ����֤
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataVerifyFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);


/*
 *	NetcaPKIMsgSignedDataDetachedVerifyInit
 *		��ʼ����֤����ԭ�ĵ�ǩ��
 *	������
 *		hSignedData��SignedData���
 *		sign�����������ǩ��ֵ
 *		signlen���������,sign�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyInit(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *sign,int signlen);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyUpdate
 *		���벻��ԭ�ĵ�ǩ����Ӧ��ԭ��
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ��
 *		tbslen�����������tbs�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyUpdate(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,int tbslen);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyFinal
 *		��������ԭ�ĵ�ǩ������֤��
 *	������
 *		hSignedData��SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyFinal(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData);

/*
 *	NetcaPKIMsgSignedDataDetachedVerifyHash
 *		����Hashֵ���в���ԭ�ĵ�ǩ������֤
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������
 *		hash�����������Hashֵ
 *		hashlen���������,Hashֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerifyHash(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *hash,int hashlen);

/*
 *	NetcaPKIMsgSignedDataDetachedSetHashValue
 *		����ԭ�ĵ�ǩ�����ⲿ����Hashֵ�����Hashֵ�ض���ԭ�ĵ�Hashֵ��������Hash(Z||ԭ��)
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ��������
 *		hash�����������Hashֵ
 *		hashlen���������,Hashֵ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedSetHashValue(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,const unsigned char *hash,int hashlen);


/*
 *	NetcaPKIMsgSignedDataDetachedVerify
 *		��֤����ԭ�ĵ�ǩ��
 *	������
 *		hSignedData��SignedData���
 *		tbs�����������ԭ��
 *		tbslen�����������tbs�ĳ���
 *		sign�����������ǩ��ֵ
 *		signlen���������,sign�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataDetachedVerify(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,const unsigned char *tbs,int tbslen,const unsigned char *sign,int signlen);

/*
 *	NetcaPKIMsgSignedDataSetGetCertCallback
 *		���û�ȡǩ��֤��Ļص�����
 *	������
 *		hSignedData��SignedData���
 *		callback���ص�����
 *		context���ص������Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetGetCertCallback(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NetcaSignedDataGetCertCallback_Ptr callback,void *context);


/*
 *	NetcaPKIMsgSignedDataGetIntegerAttribute
 *		��ȡSignedData���������ԡ�
 *	������
 *		hSignedData��SignedData���
 *		atrrId���������������ID
 *		index���������������ֵ����0����ĳЩ���Ի�������ֵ
 *		value�������������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetIntegerAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,int *value);


/*
 *	NetcaPKIMsgSignedDataGetStringAttribute
 *		��ȡSignedData���ַ�������
 *	������
 *		hSignedData��SignedData���
 *		atrrId���������������ID
 *		index���������������ֵ����0����ĳЩ���Ի�������ֵ
 *		value�������������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetStringAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int atrrId,int index,char **value);


/*
 *	NetcaPKIMsgSignedDataGetSignedAttribute
 *		��ȡǩ������
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ������ֵ����0����
 *		attrIndex�������������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetSignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIMsgSignedDataGetUnsignedAttribute
 *		��ȡ��ǩ������
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ������ֵ����0����
 *		attrIndex�������������������ֵ����0����
 *		attrType�������������������
 *		attrValue���������������ֵ��DER����
 *		attrValueLen���������������ֵ��DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetUnsignedAttribute(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,char **attrType,unsigned char **attrValue,int *attrValueLen);

/*
 *	NetcaPKIMsgSignedDataGetUnsignedAttributeEncode
 *		��ȡ��ǩ�����Եı���
 *	������
 *		hSignedData��SignedData���
 *		index�����������ǩ������ֵ����0����
 *		attrIndex�������������������ֵ����0����
 *		attrEncode��������������Եı���
 *		attrEncodeLen��������������Եı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetUnsignedAttributeEncode(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int attrIndex,unsigned char **attrEncode,int *attrEncodeLen);

/*
 *	NetcaPKIMsgSignedDataGetSignCert
 *		��ȡSignedData�ĵ�index��ǩ��֤��
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *	����ֵ��
 *		�ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetSignCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataGetVerifyHandle
 *		��ȡSignedData�ĵ�index��ǩ����֤����֤���
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *	����ֵ��
 *		�ɹ����ص�index��ǩ����֤����֤�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERT_VERIFY_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetVerifyHandle(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);

/*
 *	NetcaPKIMsgSignedDataGetEncCert
 *		��ȡSignedData�ĵ�index��ǩ���߶�Ӧ�ļ���֤��
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		cert:����������ɹ����ؼ���֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataGetEncCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,NETCA_PKI_CERTIFICATE_HANDLE *cert);

/*
 *	NetcaPKIMsgSignedDataGetTSACert
 *		��ȡSignedData�ĵ�index��ǩ���е�ʱ���ǩ����֤��
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *	����ֵ��
 *		�ɹ�����ʱ���ǩ����֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetTSACert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index);


/*
 *	NetcaPKIMsgSignedDataGetCountersignatureCert
 *		��ȡSignedData�ĵ�index��ǩ���ĵ�countersignIndex������ǩ����֤��
 *	������
 *		hSignedData��SignedData���
 *		index���������������ֵ����0����
 *		countersignIndex���������������ǩ������ֵ����0����
 *	����ֵ��
 *		�ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedDataGetCountersignatureCert(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int index,int countersignIndex);

/*
 *	NetcaPKIMsgSignedDataMaybe
 *		�ж��Ƿ������SignedData
 *	������
 *		data�����������SignedData��ǰ�沿��
 *		dataLen�����������data�ĳ���
 *		detached����������������ԭ�ķ���0����������1
 *	����ֵ��
 *		�����Ƿ���1�����Ƿ���0
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataMaybe(const unsigned char *data,int dataLen,int *detached);

/*
 *	NetcaPKIMsgSignedDataSetPromptMsg
 *		����ǩ��ʱ����ʾ��Ϣ��
 *	������
 *		hSignedData��SignedData���
 *		flag�����������NETCA_PKI_PROMTMSG_FLAG_NO_ARGUMENT��ʾû�в�����ֱ����ʾmsg��
 *		msg�������������ʾ��Ϣ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ���NETCA_PKI_FAIL
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedDataSetPromptMsg(NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int flag,const char *msg);


/* ʱ�����غ��� */
/*
 *	NetcaPKIMsgNewTimeStamp
 *		����ʱ��������
 *	������
 *		��
 *	����ֵ��
 *		�ɹ�����ʱ��������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgNewTimeStamp(void);


/*
 *	NetcaPKIMsgFreeTimeStamp
 *		�ͷ�ʱ��������
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeTimeStamp(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);


/*
 *	NetcaPKIMsgTimeStampSetTSA
 *		����ʱ�����������
 *	������
 *		hTimeStamp��ʱ������
 *		tsaurl�����������TSA��URL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetTSA(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *tsaurl);

/*
 *	NetcaPKIMsgTimeStampSetHashAlgorithm
 *		����ʱ��������Hash�㷨��
 *	������
 *		hTimeStamp��ʱ������
 *		algo�����������ʱ���Hash�㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetHashAlgorithm(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int algo);


/*
 *	NetcaPKIMsgTimeStampSetMessageImprint
 *		����Ҫ���͸�ʱ�����������Hashֵ��
 *	������
 *		hTimeStamp��ʱ������
 *		hash�����������Hashֵ
 *		hashlen�����������Hash����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetMessageImprint(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const unsigned char *hash,int hashlen);

/*
 *	NetcaPKIMsgTimeStampGetReqEncode
 *		��ȡʱ��������DER���롣
 *	������
 *		hTimeStamp��ʱ������
 *		encode���������������ʱ��������DER����
 *		encodeLen���������������ʱ��������DER����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetReqEncode(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **encode,int *encodeLen);

/*
 *	NetcaPKIMsgTimeStampGetResponse
 *		��ʱ���������������Ӧ������֤�ͻ�ȡʱ��ֵ��
 *	������
 *		hTimeStamp��ʱ������
 *		status���������������ʱ�����Ӧ״̬
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetResponse(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *status);

/*
 *	NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse
 *		��ʱ�����Ӧ�����ȡʱ���Token�ı��롣
 *	������
 *		resp�����������ʱ�����Ӧ��DER����
 *		respLen�����������ʱ�����Ӧ��DER����ĳ���
 *		status���������������ʱ�����Ӧ״̬
 *		token��������������ص�ʱ���token����ֵ
 *		tokenLen���������������token�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse(const unsigned char *resp,int respLen,int *status,unsigned char **token,int *tokenLen);

/*
 *	NetcaPKIMsgTimeStampGetTimeStampToken
 *		��ȡʱ������롣
 *	������
 *		hTimeStamp��ʱ������
 *		token��������������ص�ʱ�������ֵ
 *		ptokenlen���������������token�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTimeStampToken(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **token,int *ptokenlen);

/*
 *	NetcaPKIMsgTimeStampGetTSACert
 *		��ȡʱ���֤��
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ���֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgTimeStampGetTSACert(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);


/*
 *	NetcaPKIMsgVerifyTimeStampToken
 *		��֤ʱ����ı���
 *	������
 *		token�����������ʱ�������
 *		tokenlen�����������token�ĳ���
 *		cert��ʱ���֤�飬����ΪNULL
 *	����ֵ��
 *		�ɹ�����ʱ��������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKIMsgVerifyTimeStampToken(const unsigned char *token,int tokenlen,NETCA_PKI_CERTIFICATE_HANDLE cert);


/*
 *	NetcaPKIMsgVerifyTimeStampTokenBySignedDataHandle
 *		��֤ʱ����ı���
 *	������
 *		token�����������ʱ�������
 *		tokenlen�����������token�ĳ���
 *		hSignedData��SignedData��֤���
 *		hTimeStamp������������ɹ�����ʱ������
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgVerifyTimeStampTokenBySignedDataHandle(const unsigned char *token,int tokenlen,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,NETCA_PKI_TIMESTAMP_HANDLE *hTimeStamp);


/*
 *	NetcaPKIMsgTimeStampGetHashAlgorithm
 *		���ʱ�����Hash�㷨
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ���ʹ�õ�Hash�㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetHashAlgorithm(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetMessageImprint 
 *		��÷��͸�ʱ�����Hashֵ
 *	������
 *		hTimeStamp��ʱ������
 *		hash���������������Hashֵ
 *		phashlen���������������Hash����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetMessageImprint(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **hash,int *phashlen);

/*
 *	NetcaPKIMsgTimeStampGetTime 
 *		��ȡʱ���
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ��ֵ��ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetTime(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetPolicy 
 *		��ȡʱ�������
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ�������OID��ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetPolicy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampSetPolicy 
 *		����ʱ�������
 *	������
 *		hTimeStamp��ʱ������
 *		policy��ʱ�������OID
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetPolicy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *policy);

/*
 *	NetcaPKIMsgTimeStampGetSerialNumber 
 *		��ȡʱ��������к�
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ��������кţ�ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgTimeStampGetSerialNumber(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetNonce 
 *		��ȡʱ�����Nonceֵ
 *	������
 *		hTimeStamp��ʱ������
 *		nonce���������������Nonceֵ
 *		nonceLen���������������Nonce����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetNonce(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **nonce,int *nonceLen);

/*
 *	NetcaPKIMsgTimeStampSetNonce 
 *		����ʱ�����Nonceֵ
 *	������
 *		hTimeStamp��ʱ������
 *		flag�����������NETCA_PKI_TIMESTAMP_NONCE_FLAG_NONE��ʾ��ҪNonce��NETCA_PKI_TIMESTAMP_NONCE_FLAG_RANDOM��ʾʹ�����������nonceLen�ֽڵ�Nonce��NETCA_PKI_TIMESTAMP_NONCE_FLAG_FIX��ʾʹ��nonce��ΪNonce
 *		nonce�����������Nonceֵ��NETCA_PKI_TIMESTAMP_NONCE_FLAG_FIX��Ч
 *		nonceLen�����������Nonce����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetNonce(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int flag,const unsigned char *nonce,int nonceLen);


/*
 *	NetcaPKIMsgTimeStampSetCertReq
 *		����ʱ���������Ƿ�Ҫ����Ӧ��֤�顣
 *	������
 *		hTimeStamp��ʱ������
 *		certReq�����������Ϊ���ʾҪ����Ӧ��֤�飬Ϊ�ٱ�ʾҪ����Ӧ����֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetCertReq(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int certReq);

/*
 *	NetcaPKIMsgTimeStampGetCertReq
 *		�ж�ʱ���������Ƿ�Ҫ����Ӧ��֤�顣
 *	������
 *		hTimeStamp��ʱ������
 *		pCertReq�����������Ϊ���ʾҪ����Ӧ��֤�飬Ϊ�ٱ�ʾҪ����Ӧ����֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetCertReq(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *pCertReq);

/*
 *	NetcaPKIMsgTimeStampSetTSACert
 *		����ʱ���֤�飬������֤��Ӧ��
 *	������
 *		hTimeStamp��ʱ������
 *		cert�����������ʱ���֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampSetTSACert(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgTimeStampGetSignedData
 *		���ʱ�����SignedData���
 *	������
 *		hTimeStamp��ʱ������
 *	����ֵ��
 *		�ɹ�����ʱ�����SignedData�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_SIGNEDDATA_HANDLE NETCADLLAPI NetcaPKIMsgTimeStampGetSignedData(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp);

/*
 *	NetcaPKIMsgTimeStampGetAccuracy
 *		���ʱ�����ʱ�侫��
 *	������
 *		hTimeStamp��ʱ������
 *		seconds�������������
 *		millis���������������
 *		micros�����������΢��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS����Ӧ��û�о��ȷ���NETCA_PKI_NOTEXISIT��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetAccuracy(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *seconds,int *millis,int *micros);


/*
 *	NetcaPKIMsgTimeStampAddReqExt 
 *		���ʱ����������չ
 *	������
 *		hTimeStamp��ʱ������
 *		oid�������������չOID
 *		critical�������������չ�Ƿ�ؼ�
 *		value�������������չֵ�ı���
 *		valueLen�������������չֵ�ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampAddReqExt(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,const char *oid,int critical,const unsigned char *value,int valueLen);

/*
 *	NetcaPKIMsgTimeStampGetTSTInfo
 *		��ȡʱ�����TSTInfo���롣
 *	������
 *		hTimeStamp��ʱ������
 *		tstInfo��������������ص�ʱ���TSTInfo����ֵ
 *		pTstInfoLen���������������TSTInfo����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetTSTInfo(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,unsigned char **tstInfo,int *pTstInfoLen);

/*
 *	NetcaPKIMsgTimeStampGetFailInfo
 *		���ʱ����Ĵ���ԭ��
 *	������
 *		hTimeStamp��ʱ������
 *		failInfo���������������ԭ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS����Ӧ��û��failInfo����NETCA_PKI_NOTEXISIT��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgTimeStampGetFailInfo(NETCA_PKI_TIMESTAMP_HANDLE hTimeStamp,int *failInfo);

/*
 *	NetcaPKIMsgAuthenticodeSign 
 *		���ļ�����Authenticode��ʽ�Ĵ���ǩ����
 *	������
 *		fileName������������ļ������ļ�����ɶ���д��ʹ��ǰ�뱣���ļ���������Ϊʧ�ܿ���Ҳ���д�ļ�
 *		flag�������������־
 *		hashAlgo:������������ļ�����Hash��Hash�㷨
 *		signAlgo:���������ǩ���㷨
 *		cert��ǩ��֤�飬������˽Կ
 *		otherCerts:�������������֤�����飬��flag��NETCA_PKI_AUTHENTICODE_FLAG_DONTBUILDCERTPATH��λ����Ч����ʾʹ����Щ֤����湹���֤��·����otherCerts��Ӧ�ð���ǩ��֤�飬��Ϊǩ�������ǰ���ǩ��֤���
 *		otherCertCount:�������������֤�����
 *		description:�������������������ΪNULL��UTF-8����
 *		publisherUrl:��������������̵�URL,����ΪNULL��
 *		tsaUrl�����������ʱ�����������ַ������ΪNULL��
 *		reserve:������������ǰδʹ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgAuthenticodeSign(const char *fileName,int flag,int hashAlgo,int signAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert,NETCA_PKI_CERTIFICATE_HANDLE* otherCerts,int otherCertCount,const char *description,const char *publisherUrl,const char *tsaUrl,void *reserve);


/* JSONǩ����غ��� */
/*
 *	NetcaPKIMsgNewJWS
 *		����JSONǩ�������
 *	������
 *		type:���������JWS������
 *	����ֵ��
 *		�ɹ�����JSONǩ�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWS_HANDLE NETCADLLAPI NetcaPKIMsgNewJWS(int type);


/*
 *	NetcaPKIMsgFreeJWS
 *		�ͷ�JSONǩ�������
 *	������
 *		hJWS��JSONǩ�����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeJWS(NETCA_PKI_JWS_HANDLE hJWS);

/*
 *	NetcaPKIMsgJWSSetCertIdType
 *		����JWSǩ����֤��ı�ʶ���͡�
 *	������
 *		hJWS��JSONǩ�����
 *		type�����������JWSǩ����֤��ı�ʶ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSetCertIdType(NETCA_PKI_JWS_HANDLE hJWS,int type);


/*
 *	NetcaPKIMsgJWSSetFlag
 *		����JWSǩ���ı�־��
 *	������
 *		hJWS��JSONǩ�����
 *		flag�������������־
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSetFlag(NETCA_PKI_JWS_HANDLE hJWS,int flag);

/*
 *	NetcaPKIMsgJWSGetFlag
 *		��ȡJWSǩ���ı�־��
 *	������
 *		hJWS��JSONǩ�����
 *	����ֵ��
 *		�ɹ�����JWSǩ���ı�־��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetFlag(NETCA_PKI_JWS_HANDLE hJWS);

/*
 *	NetcaPKIMsgJWSSetAdditionalProtectedHeader
 *		����JWSǩ���ĸ��ӵı���ͷ����Щ����ͷ��ͨ��������ʽ���õģ���Ҫ����������
 *	������
 *		hJWS��JSONǩ�����
 *		header���������������ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen���������������ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSetAdditionalProtectedHeader(NETCA_PKI_JWS_HANDLE hJWS,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWSSetUnprotectedHeader
 *		����JWSǩ���Ĳ�����ͷ��
 *	������
 *		hJWS��JSONǩ�����
 *		header�����������������ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen�����������������ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSetUnprotectedHeader(NETCA_PKI_JWS_HANDLE hJWS,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWSSetPayload
 *		����JWSǩ�����غɡ�
 *	������
 *		hJWS��JSONǩ�����
 *		data������������غ�
 *		dataLen������������غɵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSetPayload(NETCA_PKI_JWS_HANDLE hJWS,const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgJWSSign
 *		ǩ������JWS
 *	������
 *		hJWS��JSONǩ�����
 *		cert��֤��
 *		algo�����������ǩ���㷨
 *		param�����������ǩ���㷨����
 *		sign������������ɹ�����JWS�ı���
 *		signLen������������ɹ�����JWS�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSSign(NETCA_PKI_JWS_HANDLE hJWS,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,unsigned char **sign,int *signLen);

/*
 *	NetcaPKIMsgJWSMac
 *		MAC����JWS
 *	������
 *		hJWS��JSONǩ�����
 *		algo�����������ǩ���㷨
 *		param�����������ǩ���㷨����
 *		key�����������MAC����Կ
 *		keyLen�����������MAC����Կ����
 *		sign������������ɹ�����JWS�ı���
 *		signLen������������ɹ�����JWS�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSMac(NETCA_PKI_JWS_HANDLE hJWS,int algo,const void *param,const unsigned char *key,int keyLen,unsigned char **sign,int *signLen);


/*
 *	NetcaPKIMsgJWSDecode
 *		����õ�JSONǩ�������
 *	������
 *		type�����������JWS������
 *		data�����������JWS�ı���
 *		dataLen�����������JWS�ı�����ֽ���
 *	����ֵ��
 *		�ɹ�����JSONǩ�������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWS_HANDLE NETCADLLAPI NetcaPKIMsgJWSDecode(int type,const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgJWSGetType
 *		��ȡJWSǩ�������͡�
 *	������
 *		hJWS��JSONǩ�����
 *	����ֵ��
 *		�ɹ�����JWSǩ�������ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetType(NETCA_PKI_JWS_HANDLE hJWS);

/*
 *	NetcaPKIMsgJWSGetSignCount
 *		��ȡJWSǩ����ǩ����MAC���ܸ�����
 *	������
 *		hJWS��JSONǩ�����
 *	����ֵ��
 *		�ɹ�����ǩ����MAC���ܸ�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetSignCount(NETCA_PKI_JWS_HANDLE hJWS);

/*
 *	NetcaPKIMsgJWSGetAlgo
 *		��ȡJWSǩ�����㷨��
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		type����������������ǩ������NETCA_PKI_JWS_TYPE_SIGN�������MAC����NETCA_PKI_JWS_TYPE_MAC
 *		algo������������ɹ�����ǩ���㷨����MAC�㷨
 *		param������������ɹ������㷨���������ܷ���NULL
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetAlgo(NETCA_PKI_JWS_HANDLE hJWS,int index,int *type,int *algo,void **param);

/*
 *	NetcaPKIMsgJWSVerifySignature
 *		��֤JWSǩ����ǩ����
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		cert�����������ǩ��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�����ǩ��֤����ڣ�����NETCA_PKI_SUCCESS��NetcaPKIGetLastError()����NETCA_PKI_NOT_IN_VALIDITY
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSVerifySignature(NETCA_PKI_JWS_HANDLE hJWS,int index,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgJWSVerifySignatureByPublicKey
 *		ʹ�ù�Կ��֤JWSǩ����ǩ����
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		hPublicKey�������������Կ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ��
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSVerifySignatureByPublicKey(NETCA_PKI_JWS_HANDLE hJWS,int index,NETCA_PKI_PUBLICKEY_HANDLE hPublicKey);

/*
 *	NetcaPKIMsgJWSVerifyMac
 *		��֤JWSǩ���е�MACֵ
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		key�����������Mac����Կ
 *		keyLen�����������Mac����Կ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSVerifyMac(NETCA_PKI_JWS_HANDLE hJWS,int index,const unsigned char *key,int keyLen);

/*
 *	NetcaPKIMsgJWSGetProtectedHeader
 *		��ȡJWSǩ���ı���ͷ��
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		header���������������ͷ
 *		headerLen������������ɹ����ر���ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetProtectedHeader(NETCA_PKI_JWS_HANDLE hJWS,int index,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWSGetUnprotectedHeader
 *		��ȡJWSǩ���Ĳ�����ͷ��
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		header�����������������ͷ
 *		headerLen������������ɹ����ز�����ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetUnprotectedHeader(NETCA_PKI_JWS_HANDLE hJWS,int index,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWSGetCriticalHeaderValue
 *		��ȡJWSǩ���Ĺؼ�ͷ��ֵ��
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *		value������������ؼ�ͷ
 *		count������������ɹ����عؼ�ͷ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�������ڷ���NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetCriticalHeaderValue(NETCA_PKI_JWS_HANDLE hJWS,int index,char ***value,int *count);

/*
 *	NetcaPKIMsgJWSGetPayload
 *		��ȡJWSǩ�����غɡ�
 *	������
 *		hJWS��JSONǩ�����
 *		data������������غ�
 *		dataLen������������غɵ��ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWSGetPayload(NETCA_PKI_JWS_HANDLE hJWS,unsigned char **data,int *dataLen);

/*
 *	NetcaPKIMsgJWSGetSignCert
 *		��ȡJWSǩ����ǩ��֤�顣
 *	������
 *		hJWS��JSONǩ�����
 *		index����������������ţ���0����
 *	����ֵ��
 *		�ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgJWSGetSignCert(NETCA_PKI_JWS_HANDLE hJWS,int index);

/* JSON������غ��� */
/*
 *	NetcaPKIMsgNewJWE
 *		����JSON���ܾ����
 *	������
 *		type:���������JWE������
 *	����ֵ��
 *		�ɹ�����JSON���ܾ����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWE_HANDLE NETCADLLAPI NetcaPKIMsgNewJWE(int type);


/*
 *	NetcaPKIMsgFreeJWE
 *		�ͷ�JSON���ܾ����
 *	������
 *		hJWE��JSON���ܾ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeJWE(NETCA_PKI_JWE_HANDLE hJWE);

/*
 *	NetcaPKIMsgJWESetContentEncAlgo
 *		����JSON���ܵ����ݼ����㷨
 *	������
 *		hJWE��JSON���ܾ��
 *		algo�����������JSON���ܵ����ݼ����㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetContentEncAlgo(NETCA_PKI_JWE_HANDLE hJWE,int algo);

/*
 *	NetcaPKIMsgJWESetAdditionalProtectedHeader
 *		����JWE���ܵĸ��ӵı���ͷ����Щ����ͷ��ͨ��������ʽ���õģ���Ҫ����������
 *	������
 *		hJWE��JSON���ܾ��
 *		header���������������ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen���������������ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetAdditionalProtectedHeader(NETCA_PKI_JWE_HANDLE hJWE,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWESetSharedUnprotectedHeader
 *		����JWE���ܵĹ�������ͷ��
 *	������
 *		hJWE��JSON���ܾ��
 *		header�������������������ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen�������������������ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetSharedUnprotectedHeader(NETCA_PKI_JWE_HANDLE hJWE,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWESetAAD
 *		����JWE���ܵ�AAD��
 *	������
 *		hJWE��JSON���ܾ��
 *		aad�����������AADֵ
 *		aadLen�����������AAD�ĳ��ȣ��ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetAAD(NETCA_PKI_JWE_HANDLE hJWE,const unsigned char *aad,int aadLen);

/*
 *	NetcaPKIMsgJWEAddCert
 *		���JWE���ܵļ���֤��
 *	������
 *		hJWE��JSON���ܾ��
 *		cert������֤��
 *		algo������������������ݼ�����Կ���㷨
 *		param������������㷨����
 *		certIdType�����������JWE���ܵ�֤��ı�ʶ����
 *		header����������������߲�����ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen����������������߲�����ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEAddCert(NETCA_PKI_JWE_HANDLE hJWE,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,int certIdType,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWEAddKey
 *		���JWE���ܵ���Կ���߿���
 *	������
 *		hJWE��JSON���ܾ��
 *		algo������������������ݼ�����Կ���㷨
 *		param������������㷨��صĲ���
 *		key�������������Կ���߿���
 *		keyLen�������������Կ���ֽ���
 *		header����������������߲�����ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen����������������߲�����ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEAddKey(NETCA_PKI_JWE_HANDLE hJWE,int algo,const void *param,const unsigned char *key,int keyLen,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWEEncrypt
 *		����JWE����
 *	������
 *		hJWE��JSON���ܾ��
 *		data���������������
 *		dataLen��������������ĳ���
 *		jweData������������ɹ�����JWE�ı���
 *		jweDataLen������������ɹ�����JWE�ı����ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEEncrypt(NETCA_PKI_JWE_HANDLE hJWE,const unsigned char *data,int dataLen,unsigned char **jweData,int *jweDataLen);

/*
 *	NetcaPKIMsgJWEDecode
 *		����JWE
 *	������
 *		type���������������
 *		data�����������JWE�ı���
 *		dataLen�����������JWE�ĳ���
 *	����ֵ��
 *		�ɹ�����JSON���ܾ����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWE_HANDLE NETCADLLAPI NetcaPKIMsgJWEDecode(int type,const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgJWESetStore
 *		����JWE�����õ�֤���
 *	������
 *		hJWE��JSON���ܾ��
 *		store��֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetStore(NETCA_PKI_JWE_HANDLE hJWE,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKIMsgJWEDecrypt
 *		JWE����
 *	������
 *		hJWE��JSON���ܾ��
 *		clearText��������������ܷ��ص�����
 *		clearLen��������������ܷ��ص����ĳ��ȣ��ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEDecrypt(NETCA_PKI_JWE_HANDLE hJWE,unsigned char **clearText,int *clearLen);

/*
 *	NetcaPKIMsgJWEGetType
 *		��ȡJWE������
 *	������
 *		hJWE��JSON���ܾ��
 *	����ֵ��
 *		�ɹ�����JWE�Ĺ淶�����ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetType(NETCA_PKI_JWE_HANDLE hJWE);

/*
 *	NetcaPKIMsgJWEGetRecipientCount
 *		��ȡJWE�Ľ����߸���
 *	������
 *		hJWE��JSON���ܾ��
 *	����ֵ��
 *		�ɹ�����JWE�Ľ����߸�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetRecipientCount(NETCA_PKI_JWE_HANDLE hJWE);

/*
 *	NetcaPKIMsgJWEGetContentEncryptAlgo
 *		��ȡJWE�Ķ����ļ��ܵĶԳƼ����㷨
 *	������
 *		hJWE��JSON���ܾ��
 *	����ֵ��
 *		�ɹ�����JWE�Ķ����ļ��ܵĶԳƼ����㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetContentEncryptAlgo(NETCA_PKI_JWE_HANDLE hJWE);

/*
 *	NetcaPKIMsgJWEGetCEKEncryptAlgo
 *		��ȡJWE�ļ���CEK���㷨
 *	������
 *		hJWE��JSON���ܾ��
 *		index���������������������
 *	����ֵ��
 *		�ɹ����ؼ���CEK���㷨��ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetCEKEncryptAlgo(NETCA_PKI_JWE_HANDLE hJWE,int index);

/*
 *	NetcaPKIMsgJWESetDecryptCert
 *		����JWE����֤��
 *	������
 *		hJWE��JSON���ܾ��
 *		index���������������������
 *		cert������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetDecryptCert(NETCA_PKI_JWE_HANDLE hJWE,int index,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgJWESetKey
 *		����JWE���ܵ���Կ
 *	������
 *		hJWE��JSON���ܾ��
 *		index���������������������
 *		key�������������Կ���߿���
 *		keyLen�������������Կ���߿�����ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWESetKey(NETCA_PKI_JWE_HANDLE hJWE,int index,const unsigned char *key,int keyLen);


/*
 *	NetcaPKIMsgJWEGetDecryptCert
 *		��ȡJWE����֤�飬�����ڽ��ܳɹ������ʹ��
 *	������
 *		hJWE��JSON���ܾ��
 *	����ֵ��
 *		�ɹ����ؽ���֤������ʧ�ܷ���NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgJWEGetDecryptCert(NETCA_PKI_JWE_HANDLE hJWE);


/*
 *	NetcaPKIMsgJWEGetProtectedHeader
 *		��ȡJWE���ܵı���ͷ��
 *	������
 *		hJWE��JSON���ܾ��
 *		header���������������ͷ
 *		headerLen������������ɹ����ر���ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetProtectedHeader(NETCA_PKI_JWE_HANDLE hJWE,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWEGetSharedUnprotectedHeader
 *		��ȡJWE���ܵĹ�������ͷ��
 *	������
 *		hJWE��JSON���ܾ��
 *		header�������������������ͷ
 *		headerLen������������ɹ����ع�������ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetSharedUnprotectedHeader(NETCA_PKI_JWE_HANDLE hJWE,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWEGetRecipientUnprotectedHeader
 *		��ȡJWE���ܵĵ�index�������߲�����ͷ��
 *	������
 *		hJWE��JSON���ܾ��
 *		index���������������ֵ
 *		header����������������߲�����ͷ
 *		headerLen������������ɹ����ؽ����߲�����ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetRecipientUnprotectedHeader(NETCA_PKI_JWE_HANDLE hJWE,int index,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWEGetCriticalHeaderValue
 *		��ȡJWE���ܵĹؼ�ͷ��ֵ��
 *	������
 *		hJWE��JSON���ܾ��
 *		index����������������ţ���0����
 *		value������������ؼ�ͷ
 *		count������������ɹ����عؼ�ͷ������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�������ڷ���NETCA_PKI_NOTEXISIT
 *
 */
int NETCADLLAPI NetcaPKIMsgJWEGetCriticalHeaderValue(NETCA_PKI_JWE_HANDLE hJWE,int index,char ***value,int *count);

/* JSON Web Token��غ��� */
/*
 *	NetcaPKIMsgNewJWT
 *		����JSON Web Token�����
 *	������
 *		type:���������JWT������
 *	����ֵ��
 *		�ɹ�����JSON Web Token�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWT_HANDLE NETCADLLAPI NetcaPKIMsgNewJWT(int type);


/*
 *	NetcaPKIMsgFreeJWT
 *		�ͷ�JSON Web Token�����
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeJWT(NETCA_PKI_JWT_HANDLE hJWT);


/*
 *	NetcaPKIMsgJWTSetClaim
 *		����Claim��
 *	������
 *		hJWT��JSON Web Token���
 *		name���������������
 *		value�����������ֵ�����˱�׼�ļ����⣬��������JSONֵ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTSetClaim(NETCA_PKI_JWT_HANDLE hJWT,const char *name,const char *value);

/*
 *	NetcaPKIMsgJWTSetNestedJWT
 *		����ʹ��Ƕ�׵�JWT��
 *	������
 *		hJWT��JSON Web Token���
 *		hSubJWT���ڲ��JSON Web Token���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTSetNestedJWT(NETCA_PKI_JWT_HANDLE hJWT,NETCA_PKI_JWT_HANDLE hSubJWT);

/*
 *	NetcaPKIMsgJWTSetAdditionalProtectedHeader
 *		����JWT�ĸ��ӵı���ͷ����Щ����ͷ��ͨ��������ʽ���õģ���Ҫ����������
 *	������
 *		hJWT��JSON Web Token���
 *		header���������������ͷ�ı���,JSON��UTF-8��ʽ
 *		headerLen���������������ͷ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTSetAdditionalProtectedHeader(NETCA_PKI_JWT_HANDLE hJWT,const unsigned char *header,int headerLen);

/*
 *	NetcaPKIMsgJWTSign
 *		ǩ������JWT
 *	������
 *		hJWT��JSON Web Token���
 *		cert��ǩ��֤��
 *		algo�����������ǩ���㷨
 *		param�����������ǩ���㷨����
 *		certIdType�����������ǩ��֤��ı�ʶ����
 *		sign������������ɹ�����JWT�ı���
 *		signLen������������ɹ�����JWT�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTSign(NETCA_PKI_JWT_HANDLE hJWT,NETCA_PKI_CERTIFICATE_HANDLE cert,int algo,const void *param,int certIdType,unsigned char **sign,int *signLen);

/*
 *	NetcaPKIMsgJWTMac
 *		MAC����JWT
 *	������
 *		hJWT��JSON Web Token���
 *		algo�����������ǩ���㷨
 *		param�����������ǩ���㷨����
 *		key�����������MAC����Կ
 *		keyLen�����������MAC����Կ����
 *		sign������������ɹ�����JWT�ı���
 *		signLen������������ɹ�����JWT�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTMac(NETCA_PKI_JWT_HANDLE hJWT,int algo,const void *param,const unsigned char *key,int keyLen,unsigned char **sign,int *signLen);

/*
 *	NetcaPKIMsgJWTEncryptByCert
 *		ʹ��֤����ܲ���JWT
 *	������
 *		hJWT��JSON Web Token���
 *		cekAlgo��������������ݼ����㷨
 *		cert���������������֤��
 *		kekAlgo���������������CEK���㷨
 *		param���������������CEK���㷨�Ĳ���
 *		key�������������Կ���߿���
 *		keyLen�������������Կ���߿�����ֽ���
 *		jwtData������������ɹ�����JWT�ı���
 *		jwtDataLen������������ɹ�����JWT�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTEncryptByCert(NETCA_PKI_JWT_HANDLE hJWT,int cekAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert,int kekAlgo,const void *param,int certIdType,unsigned char **jwtData,int *jwtDataLen);


/*
 *	NetcaPKIMsgJWTEncryptByKey
 *		ʹ����Կ���ܲ���JWT
 *	������
 *		hJWT��JSON Web Token���
 *		cekAlgo��������������ݼ����㷨
 *		kekAlgo���������������CEK���㷨
 *		param���������������CEK���㷨�Ĳ���
 *		certIdType���������������֤��ı�ʶ����
 *		jwtData������������ɹ�����JWT�ı���
 *		jwtDataLen������������ɹ�����JWT�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTEncryptByKey(NETCA_PKI_JWT_HANDLE hJWT,int cekAlgo,int kekAlgo,const void *param,const unsigned char *key,int keyLen,unsigned char **jwtData,int *jwtDataLen);

/*
 *	NetcaPKIMsgJWTDecode
 *		����JWT
 *	������
 *		data�����������JWT�ı���
 *		dataLen�����������JWT�ı���ĳ���
 *	����ֵ��
 *		�ɹ�����JSON Web Token�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWT_HANDLE NETCADLLAPI NetcaPKIMsgJWTDecode(const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgJWTGetType
 *		��ȡJWT������
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		�ɹ�����JWT�����ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTGetType(NETCA_PKI_JWT_HANDLE hJWT);

/*
 *	NetcaPKIMsgJWTIsNestedJWT
 *		�ж�JWT���Ƿ�Ƕ��
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		���Ƕ�׷���1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTIsNestedJWT(NETCA_PKI_JWT_HANDLE hJWT);

/*
 *	NetcaPKIMsgJWTGetInnerJWT
 *		��ȡ�ڲ���JWT
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		�ɹ������ڲ���JWT�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWT_HANDLE NETCADLLAPI NetcaPKIMsgJWTGetInnerJWT(NETCA_PKI_JWT_HANDLE hJWT);

/*
 *	NetcaPKIMsgJWTGetHeader
 *		��ȡJWT��ͷ��
 *	������
 *		hJWT��JSON Web Token���
 *		header�����������ͷ
 *		headerLen������������ɹ�����ͷ���ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTGetHeader(NETCA_PKI_JWT_HANDLE hJWT,unsigned char **header,int *headerLen);

/*
 *	NetcaPKIMsgJWTGetClaimsEncode
 *		��ȡJWT��Claims�ı��롣
 *	������
 *		hJWT��JSON Web Token���
 *		encode�����������Claims�ı���
 *		encodeLen������������ɹ�����Claims�ı�����ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTGetClaimsEncode(NETCA_PKI_JWT_HANDLE hJWT,unsigned char **encode,int *encodeLen);

/*
 *	NetcaPKIMsgJWTVerifySignature
 *		��֤JWT��ǩ����
 *	������
 *		hJWT��JSON Web Token���
 *		cert�����������ǩ��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ�����ǩ��֤����ڣ�����NETCA_PKI_SUCCESS��NetcaPKIGetLastError()����NETCA_PKI_NOT_IN_VALIDITY
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTVerifySignature(NETCA_PKI_JWT_HANDLE hJWT,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgJWTVerifyMac
 *		��֤JWT��MACֵ
 *	������
 *		hJWT��JSON Web Token���
 *		key�����������Mac����Կ
 *		keyLen�����������Mac����Կ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTVerifyMac(NETCA_PKI_JWT_HANDLE hJWT,const unsigned char *key,int keyLen);

/*
 *	NetcaPKIMsgJWTDecryptByCert
 *		ʹ��֤�����JWT
 *	������
 *		hJWT��JSON Web Token���
 *		cert���������������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTDecryptByCert(NETCA_PKI_JWT_HANDLE hJWT,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgJWTDecryptByCert
 *		ʹ����Կ����JWT
 *	������
 *		hJWT��JSON Web Token���
 *		key�������������Կ���߿���
 *		keyLen�������������Կ����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTDecryptByKey(NETCA_PKI_JWT_HANDLE hJWT,const unsigned char *key,int keyLen);

/*
 *	NetcaPKIMsgJWTGetJWS
 *		��ȡJWT��Ӧ��JWS���
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		�ɹ�����JWS�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWS_HANDLE NETCADLLAPI NetcaPKIMsgJWTGetJWS(NETCA_PKI_JWT_HANDLE hJWT);

/*
 *	NetcaPKIMsgJWTGetJWE
 *		��ȡJWT��Ӧ��JWE���
 *	������
 *		hJWT��JSON Web Token���
 *	����ֵ��
 *		�ɹ�����JWE�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_JWE_HANDLE NETCADLLAPI NetcaPKIMsgJWTGetJWE(NETCA_PKI_JWT_HANDLE hJWT);

/*
 *	NetcaPKIMsgJWTGetClaimValue
 *		��ȡClaim��ֵ��
 *	������
 *		hJWT��JSON Web Token���
 *		name���������������
 *		value������������ɹ�����ֵ�����˱�׼�ļ����⣬��������JSONֵ��UTF-8����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTGetClaimValue(NETCA_PKI_JWT_HANDLE hJWT,const char *name,char **value);

/*
 *	NetcaPKIMsgJWTGetEncode
 *		��ȡJWT�ı��롣
 *	������
 *		hJWT��JSON Web Token���
 *		encode�����������JWT�ı���
 *		encodeLen������������ɹ�����JWT�ı�����ֽ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgJWTGetEncode(NETCA_PKI_JWT_HANDLE hJWT,unsigned char **encode,int *encodeLen);


/* SignedAndEnvelopedData��غ��� */
/*
 *	NetcaPKIMsgNewSignedAndEnvelopedData
 *		����SignedAndEnvelopedData���
 *	������
 *		enc�����������Ϊ���ʾ�ڴ���NetcaPKIMsgNewSignedAndEnvelopedData��Ϊ�ٱ�ʾ�ڽ⿪NetcaPKIMsgNewSignedAndEnvelopedData
 *	����ֵ��
 *		�ɹ�����SignedAndEnvelopedData�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE NETCADLLAPI NetcaPKIMsgNewSignedAndEnvelopedData(int enc);

/*
 *	NetcaPKIMsgFreeSignedAndEnvelopedData
 *		�ͷ�SignedAndEnvelopedData���
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeSignedAndEnvelopedData(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSetEncAlgorithm
 *		����SignedAndEnvelopedData�ĶԳƼ����㷨
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		encAlgo������������ԳƼ����㷨
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSetEncAlgorithm(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,int encAlgo);


/*
 *	NetcaPKIMsgSignedAndEnvelopedDataAddEncCert
 *		��SignedAndEnvelopedData����Ӽ���֤��
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		cert���������������֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataAddEncCert(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSetUseContentInfo
 *		����SignedAndEnvelopedData����Ƿ�ʹ��ContentInfo�ķ�װ
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		value�����������Ϊ���ʾʹ��ContentInfo��װ��Ϊ�ٱ�ʾ��ʹ��ContentInfo��װ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSetUseContentInfo(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,int value);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSetClearText
 *		����SignedAndEnvelopedData������
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		data���������������
 *		dataLen��������������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSetClearText(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSignAndEncrypt
 *		���м��ܺ�ǩ�����������SignedAndEnvelopedData
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		signAlgo�����������ǩ���㷨
 *		param�����������ǩ���㷨����
 *		signCert�����������ǩ��֤��
 *		includeCertOption���������������֤���ѡ��
 *		out�����������SignedAndEnvelopedData�ı���
 *		outLen��������������ص�SignedAndEnvelopedData�ı��볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSignAndEncrypt(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,int signAlgo,const void *param,NETCA_PKI_CERTIFICATE_HANDLE signCert,int includeCertOption,unsigned char **out,int *outLen);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSetSignCallback
 *		����ǩ���Ļص�����
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		callback���ص�����
 *		context���ص������Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSetSignCallback(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,NetcaSignedAndEnvelopedDataSignHashCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataAddStore
 *		��ӽ��ܵ�֤�����ڵ�֤���
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		store��֤���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataAddStore(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,NETCA_PKI_CERT_STORE store);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataSetDecryptKeyCallback
 *		���ý��ܶԳ���Կ�Ļص�����
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		callback���ص�����
 *		context���ص������Ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataSetDecryptKeyCallback(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,NetcaSignedAndEnvelopedDataDecryptKeyCallback_Ptr callback,void *context);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataDecryptAndVerify
 *		���н��ܺ���֤ǩ��
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		verifyValidity������������Ƿ���֤ǩ��֤�����Ч��
 *		data�����������SignedAndEnvelopedData�ı���
 *		dataLen�����������SignedAndEnvelopedData�ı��볤��
 *		out��������������ܵõ�������
 *		outLen��������������ص����ĵĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataDecryptAndVerify(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,int verifyValidity,const unsigned char *data,int dataLen,unsigned char **out,int *outLen);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataAddCert
 *		ǩ��ʱ����Ӹ����֤�顣��֤ʱ����ӿ��ܵ�ǩ��֤��
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		cert��֤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataAddCert(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataIsContentInfo
 *		�ж�SignedAndEnvelopedData�Ƿ�ʹ��ContentInfo��װ
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *	����ֵ��
 *		����Ƿ���1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataIsContentInfo(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData);


/*
 *	NetcaPKIMsgSignedAndEnvelopedDataGetDecryptCert
 *		����SignedAndEnvelopedData�ɹ��󣬻�ȡʹ�õĽ���֤��
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *	����ֵ��
 *		�ɹ����ؽ���֤�飬ʧ�ܷ��� NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataGetDecryptCert(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataGetSignerInfoCount
 *		��ȡSignedAndEnvelopedData��SignerInfo�ĸ���
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *	����ֵ��
 *		�ɹ�����SignerInfo�ĸ�����ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataGetSignerInfoCount(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData);

/*
 *	NetcaPKIMsgSignedAndEnvelopedDataGetSignCert
 *		��ȡSignedAndEnvelopedData�ĵ�index��ǩ��֤��
 *	������
 *		hSignedAndEnvelopedData��SignedAndEnvelopedData���
 *		index�����������������
 *	����ֵ��
 *		�ɹ����ص�index��ǩ��֤�飬ʧ�ܷ��� NULL
 *
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKIMsgSignedAndEnvelopedDataGetSignCert(NETCA_PKI_SIGNED_AND_ENVELOPED_DATA_HANDLE hSignedAndEnvelopedData,int index);


/*
 *	NetcaPKIMsgEncryptedDataEncryptByPkcs5Pwd
 *		ʹ��PKCS#5�ķ�ʽ�ÿ������Կ���ܵõ�EncryptedData
 *	������
 *      hDevice:��������������豸���������ΪNULL
 *		flag�������������־
 *      encryptedDataLen�����������EncryptedData��BER���볤��
 *      encAlgo����������������㷨
 *      hashAlgo�����������Hash�㷨
 *      saltLen������������εĳ��ȣ�����16
 *      iterCount�������������������������1000
 *      pwd���������������
 *      pwdLen����������������
 *      clear���������������
 *      clearLen��������������ĳ���
 *		encryptedData������������ɹ�����EncryptedData��BER����
 *      encryptedDataLen������������ɹ�����EncryptedData��BER���볤��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEncryptedDataEncryptByPkcs5Pwd(NETCA_PKI_DEVICE_HANDLE hDevice, int flag,int encAlgo,int hashAlgo,int saltLen,int iterCount,const unsigned char* pwd, int pwdLen, const unsigned char* clear, int clearLen, unsigned char **encryptedData, int* encryptedDataLen);


/*
 *	NetcaPKIMsgEncryptedDataDecryptByPwd
 *		ʹ�ÿ������EncryptedData
 *	������
 *      hDevice:��������������豸���������ΪNULL
 *      pwd���������������
 *      pwdLen����������������
 *		encryptedData�����������EncryptedData��BER����
 *      encryptedDataLen�����������EncryptedData��BER���볤��
 *      clear������������ɹ���������
 *      clearLen������������ɹ��������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgEncryptedDataDecryptByPwd(NETCA_PKI_DEVICE_HANDLE hDevice, const unsigned char* pwd, int pwdLen, const unsigned char *encryptedData, int encryptedDataLen, unsigned char** clear, int* clearLen);

#ifdef __cplusplus
	}	
#endif
#endif

