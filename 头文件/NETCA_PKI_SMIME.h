#ifndef _NETCA_PKI_SMIME_INLCUDE_H_
#define _NETCA_PKI_SMIME_INLCUDE_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *	NetcaPKIMsgNewMime
 *		����MIME���
 *	������
 *		type�����������Mime������
 *	����ֵ��
 *		�ɹ�����MIME�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgNewMime(int type);

/*
 *	NetcaPKIMsgFreeMime
 *		�ͷ�MIME���
 *	������
 *		hMime��MIME���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeMime(NETCA_PKI_MIME_HANDLE hMime);


/*
 *	NetcaPKIMsgMimeAddHeaderString
 *		���MIMEͷ
 *	������
 *		hMime��MIME���
 *		pos:��������������λ�ã�С��0Ϊ�ʼ�����ڵ���ͷ����Ϊ��β��
 *		header: ���������MIMEͷ��ASCII����
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddHeaderString(NETCA_PKI_MIME_HANDLE hMime,int pos,const char *header);

/*
 *	NetcaPKIMsgMimeAddHeader
 *		���MIMEͷ
 *	������
 *		hMime��MIME���
 *		pos:��������������λ�ã�С��0Ϊ�ʼ�����ڵ���ͷ����Ϊ��β��
 *		name: ���������MIMEͷ�����ƣ�ASCII����
 *		value�����������MIMEͷ��ֵ��ASCII����
 *		params�����������MIMEͷ�Ĳ�����ASCII���룬����ΪNULL
 *		paramCount:���������MIMEͷ�Ĳ�������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddHeader(NETCA_PKI_MIME_HANDLE hMime,int pos,const char *name,const char* value,const char *params[],int paramCount);

/*
 *	NetcaPKIMsgMimeSetBody
 *		����MIME��
 *	������
 *		hMime��MIME���
 *		body: ���������MIME��
 *		bodyLen:���������MIME��ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSetBody(NETCA_PKI_MIME_HANDLE hMime,const unsigned char *body,int bodyLen);

/*
 *	NetcaPKIMsgMimeSetBoundary
 *		���MIME�ı߽��ַ���
 *	������
 *		hMime��MIME���
 *		boundary: ����������߽��ַ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSetBoundary(NETCA_PKI_MIME_HANDLE hMime,const char *boundary);

/*
 *	NetcaPKIMsgMimeAddSubEntity
 *		���MIME��ʵ��
 *	������
 *		hMime��MIME���
 *		hSubMime: ���������MIME��ʵ��
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddSubEntity(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_MIME_HANDLE hSubMime);

/*
 *	NetcaPKIMsgMimeEncode
 *		���MIME��ʵ��
 *	������
 *		hMime��MIME���
 *		encode: �������������
 *		encodeLen���������������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeEncode(NETCA_PKI_MIME_HANDLE hMime,unsigned char **encode,int *encodeLen);

/*
 *	NetcaPKIMsgMimeSign
 *		��MIME����ǩ��
 *	������
 *		hMime��MIME���
 *		hSignedData: ���������SignedData���
 *		detached:���������Ϊ��ʹ��multipart/signed��Ϊ��ʹ��application/pkcs7-mime
 *		hSignMime������������ɹ�����ǩ����SMIME���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSign(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int detached,NETCA_PKI_MIME_HANDLE *hSignMime);

/*
 *	NetcaPKIMsgMimeEncrypt
 *		��MIME���м���
 *	������
 *		hMime��MIME���
 *		hEnvelopedData: ���������EnvelopedData���
 *		hSignMime������������ɹ����������ŷ��SMIME���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeEncrypt(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_MIME_HANDLE *hEncMime);


/*
 *	NetcaPKIMsgDecodeMime
 *		����MIME���ݵõ����
 *	������
 *		data�����������Mime����
 *		dataLen�����������data�ĳ���
 *	����ֵ��
 *		�ɹ�����MIME�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgDecodeMime(const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgMimeGetType
 *		��ȡMIME������
 *	������
 *		hMime��Mime���
 *	����ֵ��
 *		�ɹ�����MIME�����ͣ�ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetType(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeGetHeaderCount
 *		��ȡMIME��ͷ����
 *	������
 *		hMime��Mime���
 *	����ֵ��
 *		�ɹ�����MIME��ͷ������ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetHeaderCount(NETCA_PKI_MIME_HANDLE hMime);
/*
 *	NetcaPKIMsgMimeGetHeaderString
 *		��ȡ��index��MIME��ͷ���ַ�����ʾ
 *	������
 *		hMime��Mime���
 *		index���������������ֵ
 *	����ֵ��
 *		�ɹ����ص�index��MIME��ͷ���ַ�����ʾ��ʧ�ܷ���NULL
 *
 */
char *NETCADLLAPI NetcaPKIMsgMimeGetHeaderString(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeGetHeader
 *		��ȡ��index��MIME��ͷ
 *	������
 *		hMime��Mime���
 *		index���������������ֵ
 *		name�������������������
 *		value:�������������ֵ
 *		params:������������ص���ز������飬û�з���NULL
 *		paramCount��������������ص���ز�������
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetHeader(NETCA_PKI_MIME_HANDLE hMime,int index,char **name,char **value,char ***params,int *paramCount);

/*
 *	NetcaPKIMsgMimeDeleteHeader
 *		ɾ����index��MIME��ͷ
 *	������
 *		hMime��Mime���
 *		index���������������ֵ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDeleteHeader(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeGetBody
 *		��ȡMIME����
 *	������
 *		hMime��Mime���
 *		body�����������MIME����ı���ֵ
 *		bodyLen�����������MIME����ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetBody(NETCA_PKI_MIME_HANDLE hMime,unsigned char **body,int *bodyLen);

/*
 *	NetcaPKIMsgMimeGetBoundary
 *		��ȡMIME�ı߽��ַ���
 *	������
 *		hMime��MIME���
 *	����ֵ��
 *		�ɹ����ر߽��ַ�����ʧ�ܷ���NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgMimeGetBoundary(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeGetSubEntityCount
 *		��ȡMIME����ʵ�����
 *	������
 *		hMime��MIME���
 *	����ֵ��
 *		�ɹ�����MIME����ʵ�������ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetSubEntityCount(NETCA_PKI_MIME_HANDLE hMime);


/*
 *	NetcaPKIMsgMimeGetSubEntity
 *		��ȡMIME�ĵ�index��ʵ��
 *	������
 *		hMime��MIME���
 *		index:�������������ֵ
 *	����ֵ��
 *		�ɹ�����MIME�ĵ�index����ʵ�壬ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgMimeGetSubEntity(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeIsSign
 *		�ж��Ƿ�ǩ����MIME
 *	������
 *		hMime��MIME���
 *		detached:���������Ϊ��ʹ��multipart/signed��Ϊ��ʹ��application/pkcs7-mime
 *	����ֵ��
 *		�����ǩ����Mime����1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeIsSign(NETCA_PKI_MIME_HANDLE hMime,int *detached);

/*
 *	NetcaPKIMsgMimeIsEncrypt
 *		�ж��Ƿ������ŷ��MIME
 *	������
 *		hMime��MIME���
 *	����ֵ��
 *		����������ŷ��Mime����1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeIsEncrypt(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeVerify
 *		��֤SMIME��ǩ��������֤֤���Ƿ����
 *	������
 *		hMime��MIME���
 *		cert:������������ܵ�ǩ��֤�飬����ΪNULL
 *		detached:���������Ϊ��ʹ��multipart/signed��Ϊ��ʹ��application/pkcs7-mime
 *		tbs:���������ԭ��
 *		tbsLen:���������ԭ�ĳ���
 *		hSignedData:����������ɹ�����SignedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeVerify(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_CERTIFICATE_HANDLE cert,int *detached,unsigned char **tbs,int *tbsLen,NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIMsgMimeVerifyBySignedDataHandle
 *		��֤SMIME��ǩ��
 *	������
 *		hMime��MIME���
 *		hSignedData:���������SignedData���
 *		detached:���������Ϊ��ʹ��multipart/signed��Ϊ��ʹ��application/pkcs7-mime
 *		tbs:���������ԭ��
 *		tbsLen:���������ԭ�ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeVerifyBySignedDataHandle(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int *detached,unsigned char **tbs,int *tbsLen);

/*
 *	NetcaPKIMsgMimeDecrypt
 *		����SMIME
 *	������
 *		hMime��MIME���
 *		hDevice:����������豸���������ΪNULL
 *		cert:�������������֤�飬����ΪNULL
 *		clear:������������ܵõ�������
 *		clearLen:������������ܵõ������ĳ���
 *		hEnvelopedData:����������ɹ�����EnvelopedData���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDecrypt(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_DEVICE_HANDLE hDevice,NETCA_PKI_CERTIFICATE_HANDLE cert,unsigned char **clear,int *clearLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);

/*
 *	NetcaPKIMsgMimeDecryptByEnvelopedDataHandle
 *		����SMIME
 *	������
 *		hMime��MIME���
 *		hEnvelopedData:EnvelopedData���
 *		clear:������������ܵõ�������
 *		clearLen:������������ܵõ������ĳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDecryptByEnvelopedDataHandle(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,unsigned char **clear,int *clearLen);

/*
 *	NetcaPKIMsgMimeQuotedPrintableEncode
 *		����Quoted-Printable����
 *	������
 *		in:���������Ҫ���������
 *		inLen:���������Ҫ��������ݳ���
 *		out:�������������õ�������
 *		poutLen:�������������õ������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeQuotedPrintableEncode(const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeQuotedPrintableDecode
 *		����Quoted-Printable����
 *	������
 *		in:���������Ҫ���������
 *		inLen:���������Ҫ��������ݳ���
 *		out:�������������õ�������
 *		poutLen:�������������õ������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeQuotedPrintableDecode(const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeHeaderExtsEncode
 *		����RFC2047�ı���
 *	������
 *		charset:����������ַ���
 *		encode������������������͡�Q����B
 *		in:���������Ҫ���������
 *		inLen:���������Ҫ��������ݳ���
 *		out:�������������õ�������
 *		poutLen:�������������õ������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeHeaderExtsEncode(const char *charset,int encode,const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeHeaderExtsDecode
 *		����RFC2047����
 *	������
 *		in:���������Ҫ���������
 *		inLen:���������Ҫ��������ݳ���
 *		charset:����������ַ���
 *		encode:�������������
 *		out:�������������õ�������
 *		poutLen:�������������õ������ݳ���
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeHeaderExtsDecode(const unsigned char * in,int inLen,char **charset,int *encode,unsigned char **out,int *poutLen);


/*
 *	NetcaPKIMsgNewAttachMime
 *		����һ��MIME�������
 *	������
 *		isBinary�����������Ϊ���ʾ�����������ݽ��б��룬Ϊ�ٱ�ʾ����Base64����
 *		contentType�����������������Content-Type,������ASCII��
 *		charset������������ļ���Ҫ������ַ���
 *		fileName������������ļ�����UTF-8����
 *		fileContent:����������ļ����ݣ����fileContentΪNULL����fileLenΪ0����ֱ�Ӵ�fileName�ж�ȡ���ݣ�����ʹ��fileContent
 *		fileLen������������ļ�����
 *	����ֵ��
 *		�ɹ�����MIME�����ʧ�ܷ���NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgNewAttachMime(int isBinary,const char *contentType,const char *charset,const char *fileName,const unsigned char *fileContent,int fileLen);

/*
 *	NetcaPKIMsgMimeTrimHeaderComment
 *		ɾ��MIMEͷ��ע�͡�ֻ����ȷ����ʹ��ע�͵�ͷ����ʹ��
 *	������
 *		hMime��MIME���
 *		header:�����������ע�͵�ͷ��
 *		newHeader: ���������ɾ��ע�ͺ��ͷ
 *	����ֵ��
 *		�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeTrimHeaderComment(const char *header,char** newHeader);

#ifdef __cplusplus
	}	
#endif
#endif
