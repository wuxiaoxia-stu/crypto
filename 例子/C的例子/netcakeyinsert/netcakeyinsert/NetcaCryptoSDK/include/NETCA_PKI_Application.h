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
 *		��֤archive-time-stamp V3�����
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
 *		��֤archive-time-stamp V3�����
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
 *		��֤archive-time-stamp V3�����Hash�㷨��
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

#ifdef __cplusplus
	}	
#endif
#endif

