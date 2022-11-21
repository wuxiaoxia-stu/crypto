#ifndef _NETCA_PKI_SES_INLCUDE_H_
#define _NETCA_PKI_SES_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
{
#endif
/*
 *   NetcaPKISESNewStamp
 *       ��������ӡ�¾�����ڴ�������ӡ��
 *   ������
 *       format���������������ӡ�µĸ�ʽ��Ҳ������ѭ�ı�׼��
 *   ����ֵ��
 *      �ɹ����ص���ӡ�¾����ʧ�ܷ���NULL
 */
NETCA_PKI_SES_STAMP_HANDLE NETCADLLAPI NetcaPKISESNewStamp(int format);
/*
 *   NetcaPKISESFreeStamp
 *       �ͷŵ���ӡ�¾��
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESFreeStamp(NETCA_PKI_SES_STAMP_HANDLE stamp);
/*
 *   NetcaPKISESStampSetVersion
 *       ���õ���ӡ�µİ汾��
 *   ������
 *       stamp������ӡ�¾��
 *       version������������汾��,GB/T 38540����Ϊ4
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetVersion(NETCA_PKI_SES_STAMP_HANDLE stamp,int version);

/*
 *   NetcaPKISESStampSetVid
 *       ���õ���ӡ�µĳ���ID
 *   ������
 *       stamp������ӡ�¾��
 *       vid���������������ӡ�³���ID��ASCII����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetVid(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* vid);

/*
 *   NetcaPKISESStampSetId
 *       ���õ���ӡ�µ�ID
 *   ������
 *       stamp������ӡ�¾��
 *       id���������������ӡ��ID��ASCII����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetId(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* id);

/*
 *   NetcaPKISESStampSetType
 *       ���õ���ӡ�µ�����
 *   ������
 *       stamp������ӡ�¾��
 *       type���������������ӡ�µ�����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetType(NETCA_PKI_SES_STAMP_HANDLE stamp, int type);

/*
 *   NetcaPKISESStampSetName
 *       ���õ���ӡ�µ�����
 *   ������
 *       stamp������ӡ�¾��
 *       name���������������ӡ�µ����ƣ�UTF-8����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetName(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* name);

/*
 *   NetcaPKISESStampAddCert
 *       ��ӵ���ӡ�µ�ǩ����֤��
 *   ������
 *       stamp������ӡ�¾��
 *		 type�����������֤���б�����
 *		 hashAlgo�����������Hash�㷨
 *       cert�����������ǩ����֤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampAddCert(NETCA_PKI_SES_STAMP_HANDLE stamp, int type,int hashAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *   NetcaPKISESStampSetCreateDate
 *       ���õ���ӡ�µ�����ʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time���������������ӡ�µ�����ʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetCreateDate(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetValidStart
 *       ���õ���ӡ�µ���Ч�ڿ�ʼʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time���������������ӡ�µ���Ч�ڿ�ʼʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetValidStart(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetValidEnd
 *       ���õ���ӡ�µ���Ч�ڽ���ʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time���������������ӡ�µ���Ч�ڽ���ʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetValidEnd(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetPicture
 *       ���õ���ӡ�µ�ͼƬ
 *   ������
 *       stamp������ӡ�¾��
 *       type�����������ͼƬ����
 *       data�����������ͼƬ����
 *       dataLen�����������ͼƬ���ݵ��ֽ���
 *       width�����������ͼƬ��ʾ���(mm)
 *       heigth�����������ͼƬ��ʾ�߶�(mm)
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetPicture(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* type,const unsigned char* data,int dataLen,int width,int heigth);

/*
 *   NetcaPKISESStampAddExtension
 *       ��ӵ���ӡ�µ���չ
 *   ������
 *       stamp������ӡ�¾��
 *       oid�������������չ��OID
 *       critical������������Ƿ�ؼ���չ
 *       value�������������չֵ
 *       valueLen�������������չֵ���ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampAddExtension(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* oid,int critical,const unsigned char* value,int valueLen);

/*
 *   NetcaPKISESStampSetEmptyExtension
 *       ���õ���ӡ�µ���չΪ��
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSetEmptyExtension(NETCA_PKI_SES_STAMP_HANDLE stamp);


/*
 *   NetcaPKISESStampSign
 *       ǩ���õ�����ӡ�±���
 *   ������
 *       stamp������ӡ�¾��
 *       signCert�����������������֤��
 *       signAlgo�����������ǩ���㷨
 *       param�����������ǩ���㷨����
 *       stampEncode������������ɹ����ص���ӡ�µı���
 *       stampEncodeLen������������ɹ����ص���ӡ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSign(NETCA_PKI_SES_STAMP_HANDLE stamp, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** stampEncode,int* stampEncodeLen);

/*
 *   NetcaPKISESStampSignWithCallback
 *       ʹ�ûص�����ǩ���õ�����ӡ�±���
 *   ������
 *       stamp������ӡ�¾��
 *       signCallback�����������ǩ���ص�����
 *       context�����������ǩ���ص����������Ĳ���
 *       signCert�����������������֤��
 *       signAlgo�����������ǩ���㷨
 *       param�����������ǩ���㷨����
 *       stampEncode������������ɹ����ص���ӡ�µı���
 *       stampEncodeLen������������ɹ����ص���ӡ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampSignWithCallback(NETCA_PKI_SES_STAMP_HANDLE stamp, NetcaSESSignCallback_Ptr signCallback, void *context, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** stampEncode, int* stampEncodeLen);

/*
 *   NetcaPKISESStampDecode
 *       �������ӡ�±���õ�����ӡ�¾��
 *   ������
 *       data���������������ӡ�µı���
 *       dataLen���������������ӡ�µı��볤��
 *   ����ֵ��
 *      �ɹ����ص���ӡ�¾����ʧ�ܷ���NULL
 */
NETCA_PKI_SES_STAMP_HANDLE NETCADLLAPI NetcaPKISESStampDecode(const unsigned char* data,int dataLen);

/*
 *   NetcaPKISESStampGetFormat
 *       ��ȡ����ӡ�µĸ�ʽ,NETCA_PKI_SES_FORMAT_GMT_0031����NETCA_PKI_SES_FORMAT_GBT_38540
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ����ص���ӡ�µĸ�ʽ��ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESStampGetFormat(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetVersion
 *       ��ȡ����ӡ�µİ汾��
 *   ������
 *       stamp������ӡ�¾��
 *       version������������ɹ����ذ汾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetVersion(NETCA_PKI_SES_STAMP_HANDLE stamp, int* version);

/*
 *   NetcaPKISESStampGetVid
 *       ��ȡ����ӡ�µĳ���ID
 *   ������
 *       stamp������ӡ�¾��
 *       vid������������ɹ����ص���ӡ�³���ID
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetVid(NETCA_PKI_SES_STAMP_HANDLE stamp, char** vid);

/*
 *   NetcaPKISESStampGetId
 *       ��ȡ����ӡ�µ�ID
 *   ������
 *       stamp������ӡ�¾��
 *       id������������ɹ����ص���ӡ��ID
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetId(NETCA_PKI_SES_STAMP_HANDLE stamp, char** id);

/*
 *   NetcaPKISESStampGetType
 *       ��ȡ����ӡ�µ�����
 *   ������
 *       stamp������ӡ�¾��
 *       type������������ɹ����ص���ӡ�µ�����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetType(NETCA_PKI_SES_STAMP_HANDLE stamp, int* type);

/*
 *   NetcaPKISESStampGetName
 *       ��ȡ����ӡ�µ�����
 *   ������
 *       stamp������ӡ�¾��
 *       name������������ɹ����ص���ӡ�µ�����
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetName(NETCA_PKI_SES_STAMP_HANDLE stamp, char** name);

/*
 *   NetcaPKISESStampGetCertListType
 *       ��ȡ����ӡ�µ�ǩ����֤���б������
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����ǩ����֤���б�����ͣ�ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertListType(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCertCount
 *       ��ȡ����ӡ�µ�ǩ����֤�����
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����ǩ����֤�������ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCert
 *       ��ȡ����ӡ�µ�ǩ����֤��
 *   ������
 *       stamp������ӡ�¾��
 *       index����������������ţ���0����
 *   ����ֵ��
 *      �ɹ����ص�index��ǩ����֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESStampGetCert(NETCA_PKI_SES_STAMP_HANDLE stamp,int index);

/*
 *   NetcaPKISESStampGetCertDigestCount
 *       ��ȡ����ӡ�µ�ǩ����֤���Ӵյĸ���
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����ǩ����֤���Ӵյĸ�����ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertDigestCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCertDigest
 *       ��ȡ����ӡ�µĵ�index��ǩ����֤���Ӵ�
 *   ������
 *      stamp������ӡ�¾��
 *		index�����������������
 *		type������������ɹ���������
 *		hashValue������������ɹ������Ӵ�ֵ
 *		hashLen������������ɹ������Ӵճ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetCertDigest(NETCA_PKI_SES_STAMP_HANDLE stamp,int index,char** type,unsigned char** hashValue,int* hashLen);

/*
 *   NetcaPKISESStampGetCreateDate
 *       ��ȡ����ӡ�µ�����ʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time������������ɹ����ص���ӡ�µ�����ʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetCreateDate(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetValidStart
 *       ��ȡ����ӡ�µ���Ч�ڿ�ʼʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time������������ɹ����ص���ӡ�µ���Ч�ڿ�ʼʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetValidStart(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetValidEnd
 *       ��ȡ����ӡ�µ���Ч�ڽ���ʱ��
 *   ������
 *       stamp������ӡ�¾��
 *       time������������ɹ����ص���ӡ�µ���Ч�ڽ���ʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetValidEnd(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetPicture
 *       ��ȡ����ӡ�µ�ͼƬ
 *   ������
 *       stamp������ӡ�¾��
 *       type������������ɹ�����ͼƬ����
 *       data������������ɹ�����ͼƬ����
 *       dataLen������������ɹ�����ͼƬ���ݵ��ֽ���
 *       width������������ɹ�����ͼƬ��ʾ���(mm)
 *       heigth������������ɹ�����ͼƬ��ʾ�߶�(mm)
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetPicture(NETCA_PKI_SES_STAMP_HANDLE stamp, char** type, unsigned char** data, int* dataLen, int* width, int* heigth);

/*
 *   NetcaPKISESStampGetExtensionCount
 *       ��ȡ����ӡ�µ���չ����
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ����ص���ӡ�µ���չ������ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESStampGetExtensionCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetExtension
 *       ��ȡ����ӡ�µ���չ
 *   ������
 *       stamp������ӡ�¾��
 *       index:��������������ţ���0����
 *       oid������������ɹ�������չ��OID
 *       critical������������ɹ������Ƿ�ؼ���չ
 *       value������������ɹ�������չֵ
 *       valueLen������������ɹ�������չֵ���ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetExtension(NETCA_PKI_SES_STAMP_HANDLE stamp, int index,char** oid, int* critical, unsigned char** value, int* valueLen);

/*
 *   NetcaPKISESStampGetEncode
 *       ��ȡ����ӡ�µı���
 *   ������
 *       stamp������ӡ�¾��
 *       encode������������ɹ����ص���ӡ�µı���
 *       encodeLen������������ɹ����ص���ӡ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetEncode(NETCA_PKI_SES_STAMP_HANDLE stamp, unsigned char** encode, int* encodeLen);


/*
 *   NetcaPKISESStampGetSignCert
 *       ��ȡ����ӡ�µ�������֤��
 *   ������
 *       stamp������ӡ�¾��
 *   ����ֵ��
 *      �ɹ�����������֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESStampGetSignCert(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetSignAlgorithm
 *       ��ȡ����ӡ�µ�ǩ���㷨
 *   ������
 *       stamp������ӡ�¾��
 *       algo������������ɹ����ص���ӡ�µ�ǩ���㷨
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampGetSignAlgorithm(NETCA_PKI_SES_STAMP_HANDLE stamp, int* algo);


/*
 *   NetcaPKISESStampVerify
 *       ��֤����ӡ��
 *   ������
 *       stamp������ӡ�¾��
 *       time�������������֤��ʱ�䣬���ΪNULL����Ϊ��ǰʱ��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESStampVerify(NETCA_PKI_SES_STAMP_HANDLE stamp,const char* time);

/*
 *   NetcaPKISESNewSeal
 *       ��������ǩ�¾�����ڴ�������ǩ��
 *   ������
 *       format���������������ӡ�µĸ�ʽ��Ҳ������ѭ�ı�׼��
 *   ����ֵ��
 *      �ɹ����ص���ǩ�¾����ʧ�ܷ���NULL
 */
NETCA_PKI_SES_SEAL_HANDLE NETCADLLAPI NetcaPKISESNewSeal(int format);

/*
 *   NetcaPKISESFreeSeal
 *       �ͷŵ���ǩ�¾��
 *   ������
 *       stamp������ǩ�¾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESFreeSeal(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealSetVersion
 *       ���õ���ǩ�µİ汾��
 *   ������
 *       seal������ǩ�¾��
 *       version������������汾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetVersion(NETCA_PKI_SES_SEAL_HANDLE seal, int version);

/*
 *   NetcaPKISESSealSetStamp
 *       ���õ���ǩ�µĵ���ӡ��
 *   ������
 *       seal������ǩ�¾��
 *       stamp���������������ӡ��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetStamp(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_SES_STAMP_HANDLE stamp);


/*
 *   NetcaPKISESSealSetTime
 *       ���õ���ǩ�µ�ǩ��ʱ��
 *   ������
 *       seal������ǩ�¾��
 *       time�����������ǩ��ʱ�䣬��ʽΪYYYYMMDDhhmmssZ
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetTime(NETCA_PKI_SES_SEAL_HANDLE seal, const char* time);


/*
 *   NetcaPKISESSealGMT0031SetTimeInfo
 *       ���õ���ǩ�µ�ǩ��ʱ��
 *   ������
 *       seal������ǩ�¾��
 *       timeInfo�����������ǩ��ʱ�䣬��ʽ����
 *       timeInfoLen�����������timeInfo�ĳ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGMT0031SetTimeInfo(NETCA_PKI_SES_SEAL_HANDLE seal, const unsigned char* timeInfo,int timeInfoLen);

/*
 *   NetcaPKISESSealSetDataHash
 *       ���õ���ǩ�µ�ԭ���Ӵ�ֵ
 *   ������
 *       seal������ǩ�¾��
 *       hashValue�����������ԭ���Ӵ�ֵ
 *       hashValueLen�����������ԭ���Ӵ�ֵ�ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetDataHash(NETCA_PKI_SES_SEAL_HANDLE seal, const unsigned char* hashValue,int hashValueLen);

/*
 *   NetcaPKISESSealSetProperty
 *       ���õ���ǩ�µ�ԭ��������Ϣ
 *   ������
 *       seal������ǩ�¾��
 *       property�����������ԭ��������Ϣ��ASCII��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetProperty(NETCA_PKI_SES_SEAL_HANDLE seal, const char* property);

/*
 *   NetcaPKISESSealAddExtension
 *       ��ӵ���ǩ�µ���չ
 *   ������
 *       seal������ǩ�¾��
 *       oid�������������չ��OID
 *       critical������������Ƿ�ؼ���չ
 *       value�������������չֵ
 *       valueLen�������������չֵ���ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealAddExtension(NETCA_PKI_SES_SEAL_HANDLE seal, const char* oid,int critical,const unsigned char* value,int valueLen);
/*
 *   NetcaPKISESSealSetEmptyExtension
 *       ���õ���ǩ�µ���չΪ��
 *   ������
 *       seal������ǩ�¾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSetEmptyExtension(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealSign
 *       ǩ���õ�����ǩ�±���
 *   ������
 *       seal������ǩ�¾��
 *       signCert�����������ǩ����֤��
 *       signAlgo�����������ǩ���㷨
 *       param�����������ǩ���㷨����
 *       sealEncode������������ɹ����ص���ǩ�µı���
 *       sealEncodeLen������������ɹ����ص���ǩ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSign(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** sealEncode, int* sealEncodeLen);


/*
 *   NetcaPKISESSealSignWithCallback
 *       ʹ�ûص�����ǩ���õ�����ǩ�±���
 *   ������
 *       seal������ǩ�¾��
 *       signCallback�����������ǩ���ص�����
 *       context�����������ǩ���ص����������Ĳ���
 *       signCert�����������ǩ����֤��
 *       signAlgo�����������ǩ���㷨
 *       param�����������ǩ���㷨����
 *       sealEncode������������ɹ����ص���ǩ�µı���
 *       sealEncodeLen������������ɹ����ص���ǩ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealSignWithCallback(NETCA_PKI_SES_SEAL_HANDLE seal, NetcaSESSignCallback_Ptr signCallback, void *context, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** sealEncode, int* sealEncodeLen);

/*
 *   NetcaPKISESSealGetHashAlgorithmFromSignAlgorithm
 *       ��ǩ���㷨�л�ȡ�Ӵ��㷨
 *   ������
 *       signAlgo�����������ǩ���㷨
 *   ����ֵ��
 *      �ɹ����ض�Ӧ���Ӵ��㷨��ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESSealGetHashAlgorithmFromSignAlgorithm(int signAlgo);

/*
 *   NetcaPKISESSealDecode
 *       �������ǩ�±���õ�����ǩ�¾��
 *   ������
 *       data���������������ǩ�µı���
 *       dataLen���������������ǩ�µı��볤��
 *   ����ֵ��
 *      �ɹ����ص���ǩ�¾����ʧ�ܷ���NULL
 */
NETCA_PKI_SES_SEAL_HANDLE NETCADLLAPI NetcaPKISESSealDecode(const unsigned char* data, int dataLen);

/*
 *   NetcaPKISESSealGetFormat
 *       ��ȡ����ǩ�µĸ�ʽ,NETCA_PKI_SES_FORMAT_GMT_0031����NETCA_PKI_SES_FORMAT_GBT_38540
 *   ������
 *       seal������ǩ�¾��
 *   ����ֵ��
 *      �ɹ����ص���ǩ�µĸ�ʽ��ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESSealGetFormat(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetVersion
 *       ��ȡ����ǩ�µİ汾��
 *   ������
 *       seal������ǩ�¾��
 *       version������������ɹ����ذ汾��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetVersion(NETCA_PKI_SES_SEAL_HANDLE seal, int* version);

/*
 *   NetcaPKISESSealGetStamp
 *       ��ȡ����ǩ�µĵ���ӡ��
 *   ������
 *       seal������ǩ�¾��
 *       stamp������������ɹ����ص���ӡ��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetStamp(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_SES_STAMP_HANDLE* stamp);


/*
 *   NetcaPKISESSealGetTime
 *       ��ȡ����ǩ�µ�ǩ��ʱ��
 *   ������
 *       seal������ǩ�¾��
 *       time������������ɹ�����ǩ��ʱ��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetTime(NETCA_PKI_SES_SEAL_HANDLE seal, char** time);

/*
 *   NetcaPKISESSealGMT0031GetTimeInfo
 *       ��ȡ����ǩ�µ�ǩ��ʱ��
 *   ������
 *       seal������ǩ�¾��
 *       timeInfo������������ɹ�����ǩ��ʱ��
 *       timeInfoLen������������ɹ�����timeInfo�ĳ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGMT0031GetTimeInfo(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** timeInfo,int *timeInfoLen);

/*
 *   NetcaPKISESSealGetDataHash
 *       ��ȡ����ǩ�µ�ԭ���Ӵ�ֵ
 *   ������
 *       seal������ǩ�¾��
 *       hashValue������������ɹ�����ԭ���Ӵ�ֵ
 *       hashValueLen������������ɹ�����ԭ���Ӵ�ֵ���ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetDataHash(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** hashValue,int* hashValueLen);

/*
 *   NetcaPKISESSealGetProperty
 *       ��ȡ����ǩ�µ�ԭ������
 *   ������
 *       seal������ǩ�¾��
 *       property������������ɹ�����ԭ������
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetProperty(NETCA_PKI_SES_SEAL_HANDLE seal, char** property);

/*
 *   NetcaPKISESSealGetExtensionCount
 *       ��ȡ����ǩ�µ���չ����
 *   ������
 *       seal������ǩ�¾��
 *   ����ֵ��
 *      �ɹ����ص���ǩ�µ���չ������ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaPKISESSealGetExtensionCount(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESStampGetExtension
 *       ��ȡ����ǩ�µ���չ
 *   ������
 *       seal������ǩ�¾��
 *       index:��������������ţ���0����
 *       oid������������ɹ�������չ��OID
 *       critical������������ɹ������Ƿ�ؼ���չ
 *       value������������ɹ�������չֵ
 *       valueLen������������ɹ�������չֵ���ֽ���
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetExtension(NETCA_PKI_SES_SEAL_HANDLE seal, int index,char** oid, int* critical, unsigned char** value, int* valueLen);

/*
 *   NetcaPKISESSealGetSignCert
 *       ��ȡ����ǩ�µ�ǩ��֤��
 *   ������
 *       seal������ǩ�¾��
 *   ����ֵ��
 *      �ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESSealGetSignCert(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetSignAlgorithm
 *       ��ȡ����ǩ�µ�ǩ���㷨
 *   ������
 *       seal������ǩ�¾��
 *       algo������������ɹ����ص���ǩ�µ�ǩ���㷨
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetSignAlgorithm(NETCA_PKI_SES_SEAL_HANDLE seal, int* algo);


/*
 *   NetcaPKISESSealVerify
 *       ��֤����ǩ�£�����֤ԭ��
 *   ������
 *       seal������ǩ�¾��
 *       time�������������֤��ʱ�䣬���ΪNULL����Ϊ��ǰʱ��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealVerify(NETCA_PKI_SES_SEAL_HANDLE seal, const char* time);

/*
 *   NetcaPKISESSealAttachTimeStamp
 *       ׷��ʱ���
 *   ������
 *       seal������ǩ�¾��
 *       hashAlgo�����������ʱ�����Hash�㷨
 *       tsaUrl�����������ʱ�����Url
 *       sealEncode������������ɹ����ص���ǩ�µı���
 *       sealEncodeLen������������ɹ����ص���ǩ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealAttachTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal, int hashAlgo,const char *tsaUrl, unsigned char** sealEncode, int* sealEncodeLen);

/*
 *   NetcaPKISESSealHasTimeStamp
 *       �ж��Ƿ���ʱ���
 *   ������
 *   ����ֵ��
 *      �з���1��û�з���0
 */
int NETCADLLAPI NetcaPKISESSealHasTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealVerifyTimeStamp
 *       ��֤ʱ���
 *   ������
 *       seal������ǩ�¾��
 *       tsaCert�����������ʱ���֤�飬����ΪNULL
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealVerifyTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal,NETCA_PKI_CERTIFICATE_HANDLE tsaCert);

/*
 *   NetcaPKISESGetTimeStampHandle
 *       ��ȡʱ������
 *   ������
 *       seal������ǩ�¾��
 *   ����ֵ��
 *      �ɹ�����ʱ��������ʧ�ܷ���NULL
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKISESGetTimeStampHandle(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetEncode
 *       ��ȡ����ǩ�µı���
 *   ������
 *       seal������ǩ�¾��
 *       encode������������ɹ����ص���ǩ�µı���
 *       encodeLen������������ɹ����ص���ǩ�µı��볤��
 *   ����ֵ��
 *      �ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaPKISESSealGetEncode(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** encode, int* encodeLen);

#ifdef __cplusplus
}
#endif
#endif

