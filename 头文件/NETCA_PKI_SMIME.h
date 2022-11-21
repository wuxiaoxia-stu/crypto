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
 *		创建MIME句柄
 *	参数：
 *		type：输入参数，Mime的类型
 *	返回值：
 *		成功返回MIME句柄，失败返回NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgNewMime(int type);

/*
 *	NetcaPKIMsgFreeMime
 *		释放MIME句柄
 *	参数：
 *		hMime：MIME句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgFreeMime(NETCA_PKI_MIME_HANDLE hMime);


/*
 *	NetcaPKIMsgMimeAddHeaderString
 *		添加MIME头
 *	参数：
 *		hMime：MIME句柄
 *		pos:输入参数，插入的位置，小于0为最开始，大于等于头个数为结尾。
 *		header: 输入参数，MIME头，ASCII编码
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddHeaderString(NETCA_PKI_MIME_HANDLE hMime,int pos,const char *header);

/*
 *	NetcaPKIMsgMimeAddHeader
 *		添加MIME头
 *	参数：
 *		hMime：MIME句柄
 *		pos:输入参数，插入的位置，小于0为最开始，大于等于头个数为结尾。
 *		name: 输入参数，MIME头的名称，ASCII编码
 *		value：输入参数，MIME头的值，ASCII编码
 *		params：输入参数，MIME头的参数，ASCII编码，可以为NULL
 *		paramCount:输入参数，MIME头的参数个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddHeader(NETCA_PKI_MIME_HANDLE hMime,int pos,const char *name,const char* value,const char *params[],int paramCount);

/*
 *	NetcaPKIMsgMimeSetBody
 *		设置MIME体
 *	参数：
 *		hMime：MIME句柄
 *		body: 输入参数，MIME体
 *		bodyLen:输入参数，MIME体的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSetBody(NETCA_PKI_MIME_HANDLE hMime,const unsigned char *body,int bodyLen);

/*
 *	NetcaPKIMsgMimeSetBoundary
 *		添加MIME的边界字符串
 *	参数：
 *		hMime：MIME句柄
 *		boundary: 输入参数，边界字符串
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSetBoundary(NETCA_PKI_MIME_HANDLE hMime,const char *boundary);

/*
 *	NetcaPKIMsgMimeAddSubEntity
 *		添加MIME子实体
 *	参数：
 *		hMime：MIME句柄
 *		hSubMime: 输入参数，MIME子实体
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeAddSubEntity(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_MIME_HANDLE hSubMime);

/*
 *	NetcaPKIMsgMimeEncode
 *		添加MIME子实体
 *	参数：
 *		hMime：MIME句柄
 *		encode: 输出参数，编码
 *		encodeLen：输出参数，编码的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeEncode(NETCA_PKI_MIME_HANDLE hMime,unsigned char **encode,int *encodeLen);

/*
 *	NetcaPKIMsgMimeSign
 *		对MIME进行签名
 *	参数：
 *		hMime：MIME句柄
 *		hSignedData: 输入参数，SignedData句柄
 *		detached:输入参数，为真使用multipart/signed，为假使用application/pkcs7-mime
 *		hSignMime：输出参数，成功返回签名的SMIME句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeSign(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int detached,NETCA_PKI_MIME_HANDLE *hSignMime);

/*
 *	NetcaPKIMsgMimeEncrypt
 *		对MIME进行加密
 *	参数：
 *		hMime：MIME句柄
 *		hEnvelopedData: 输入参数，EnvelopedData句柄
 *		hSignMime：输出参数，成功返回数字信封的SMIME句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeEncrypt(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,NETCA_PKI_MIME_HANDLE *hEncMime);


/*
 *	NetcaPKIMsgDecodeMime
 *		解码MIME数据得到句柄
 *	参数：
 *		data：输入参数，Mime数据
 *		dataLen：输入参数，data的长度
 *	返回值：
 *		成功返回MIME句柄，失败返回NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgDecodeMime(const unsigned char *data,int dataLen);

/*
 *	NetcaPKIMsgMimeGetType
 *		获取MIME的类型
 *	参数：
 *		hMime：Mime句柄
 *	返回值：
 *		成功返回MIME的类型，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetType(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeGetHeaderCount
 *		获取MIME的头个数
 *	参数：
 *		hMime：Mime句柄
 *	返回值：
 *		成功返回MIME的头个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetHeaderCount(NETCA_PKI_MIME_HANDLE hMime);
/*
 *	NetcaPKIMsgMimeGetHeaderString
 *		获取第index个MIME的头的字符串表示
 *	参数：
 *		hMime：Mime句柄
 *		index：输入参数，索引值
 *	返回值：
 *		成功返回第index个MIME的头的字符串表示，失败返回NULL
 *
 */
char *NETCADLLAPI NetcaPKIMsgMimeGetHeaderString(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeGetHeader
 *		获取第index个MIME的头
 *	参数：
 *		hMime：Mime句柄
 *		index：输入参数，索引值
 *		name：输出参数，返回名称
 *		value:输出参数，返回值
 *		params:输出参数，返回的相关参数数组，没有返回NULL
 *		paramCount：输出参数，返回的相关参数个数
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetHeader(NETCA_PKI_MIME_HANDLE hMime,int index,char **name,char **value,char ***params,int *paramCount);

/*
 *	NetcaPKIMsgMimeDeleteHeader
 *		删除第index个MIME的头
 *	参数：
 *		hMime：Mime句柄
 *		index：输入参数，索引值
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDeleteHeader(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeGetBody
 *		获取MIME的体
 *	参数：
 *		hMime：Mime句柄
 *		body：输出参数，MIME的体的编码值
 *		bodyLen：输出参数，MIME的体的长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetBody(NETCA_PKI_MIME_HANDLE hMime,unsigned char **body,int *bodyLen);

/*
 *	NetcaPKIMsgMimeGetBoundary
 *		获取MIME的边界字符串
 *	参数：
 *		hMime：MIME句柄
 *	返回值：
 *		成功返回边界字符串，失败返回NULL
 *
 */
char * NETCADLLAPI NetcaPKIMsgMimeGetBoundary(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeGetSubEntityCount
 *		获取MIME的子实体个数
 *	参数：
 *		hMime：MIME句柄
 *	返回值：
 *		成功返回MIME的子实体个数，失败返回-1
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeGetSubEntityCount(NETCA_PKI_MIME_HANDLE hMime);


/*
 *	NetcaPKIMsgMimeGetSubEntity
 *		获取MIME的第index子实体
 *	参数：
 *		hMime：MIME句柄
 *		index:输入参数，索引值
 *	返回值：
 *		成功返回MIME的第index个子实体，失败返回NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgMimeGetSubEntity(NETCA_PKI_MIME_HANDLE hMime,int index);

/*
 *	NetcaPKIMsgMimeIsSign
 *		判断是否签名的MIME
 *	参数：
 *		hMime：MIME句柄
 *		detached:输出参数，为真使用multipart/signed，为假使用application/pkcs7-mime
 *	返回值：
 *		如果是签名的Mime返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeIsSign(NETCA_PKI_MIME_HANDLE hMime,int *detached);

/*
 *	NetcaPKIMsgMimeIsEncrypt
 *		判断是否数字信封的MIME
 *	参数：
 *		hMime：MIME句柄
 *	返回值：
 *		如果是数字信封的Mime返回1，否则返回0
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeIsEncrypt(NETCA_PKI_MIME_HANDLE hMime);

/*
 *	NetcaPKIMsgMimeVerify
 *		验证SMIME的签名。不验证证书是否过期
 *	参数：
 *		hMime：MIME句柄
 *		cert:输入参数，可能的签名证书，可以为NULL
 *		detached:输出参数，为真使用multipart/signed，为假使用application/pkcs7-mime
 *		tbs:输出参数，原文
 *		tbsLen:输出参数，原文长度
 *		hSignedData:输出参数，成功返回SignedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeVerify(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_CERTIFICATE_HANDLE cert,int *detached,unsigned char **tbs,int *tbsLen,NETCA_PKI_SIGNEDDATA_HANDLE *hSignedData);

/*
 *	NetcaPKIMsgMimeVerifyBySignedDataHandle
 *		验证SMIME的签名
 *	参数：
 *		hMime：MIME句柄
 *		hSignedData:输入参数，SignedData句柄
 *		detached:输出参数，为真使用multipart/signed，为假使用application/pkcs7-mime
 *		tbs:输出参数，原文
 *		tbsLen:输出参数，原文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeVerifyBySignedDataHandle(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_SIGNEDDATA_HANDLE hSignedData,int *detached,unsigned char **tbs,int *tbsLen);

/*
 *	NetcaPKIMsgMimeDecrypt
 *		解密SMIME
 *	参数：
 *		hMime：MIME句柄
 *		hDevice:输入参数，设备句柄，可以为NULL
 *		cert:输入参数，解密证书，可以为NULL
 *		clear:输出参数，解密得到的明文
 *		clearLen:输出参数，解密得到的明文长度
 *		hEnvelopedData:输出参数，成功返回EnvelopedData句柄
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDecrypt(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_DEVICE_HANDLE hDevice,NETCA_PKI_CERTIFICATE_HANDLE cert,unsigned char **clear,int *clearLen,NETCA_PKI_ENVELOPEDDATA_HANDLE *hEnvelopedData);

/*
 *	NetcaPKIMsgMimeDecryptByEnvelopedDataHandle
 *		解密SMIME
 *	参数：
 *		hMime：MIME句柄
 *		hEnvelopedData:EnvelopedData句柄
 *		clear:输出参数，解密得到的明文
 *		clearLen:输出参数，解密得到的明文长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeDecryptByEnvelopedDataHandle(NETCA_PKI_MIME_HANDLE hMime,NETCA_PKI_ENVELOPEDDATA_HANDLE hEnvelopedData,unsigned char **clear,int *clearLen);

/*
 *	NetcaPKIMsgMimeQuotedPrintableEncode
 *		进行Quoted-Printable编码
 *	参数：
 *		in:输入参数，要编码的数据
 *		inLen:输入参数，要编码的数据长度
 *		out:输出参数，编码得到的数据
 *		poutLen:输出参数，编码得到的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeQuotedPrintableEncode(const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeQuotedPrintableDecode
 *		进行Quoted-Printable解码
 *	参数：
 *		in:输入参数，要解码的数据
 *		inLen:输入参数，要解码的数据长度
 *		out:输出参数，解码得到的数据
 *		poutLen:输出参数，解码得到的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeQuotedPrintableDecode(const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeHeaderExtsEncode
 *		进行RFC2047的编码
 *	参数：
 *		charset:输入参数，字符集
 *		encode：输入参数，编码类型。Q或者B
 *		in:输入参数，要编码的数据
 *		inLen:输入参数，要编码的数据长度
 *		out:输出参数，编码得到的数据
 *		poutLen:输出参数，编码得到的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeHeaderExtsEncode(const char *charset,int encode,const unsigned char * in,int inLen,unsigned char **out,int *poutLen);

/*
 *	NetcaPKIMsgMimeHeaderExtsDecode
 *		进行RFC2047解码
 *	参数：
 *		in:输入参数，要解码的数据
 *		inLen:输入参数，要解码的数据长度
 *		charset:输出参数，字符集
 *		encode:输出参数，编码
 *		out:输出参数，解码得到的数据
 *		poutLen:输出参数，解码得到的数据长度
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeHeaderExtsDecode(const unsigned char * in,int inLen,char **charset,int *encode,unsigned char **out,int *poutLen);


/*
 *	NetcaPKIMsgNewAttachMime
 *		创建一个MIME附件句柄
 *	参数：
 *		isBinary：输入参数，为真表示，不附件内容进行编码，为假表示进行Base64编码
 *		contentType：输入参数，附件的Content-Type,必须是ASCII码
 *		charset：输入参数，文件名要编码的字符集
 *		fileName：输入参数，文件名，UTF-8编码
 *		fileContent:输入参数，文件内容，如果fileContent为NULL，且fileLen为0，则直接从fileName中读取数据，否则使用fileContent
 *		fileLen：输入参数，文件长度
 *	返回值：
 *		成功返回MIME句柄，失败返回NULL
 *
 */
NETCA_PKI_MIME_HANDLE NETCADLLAPI NetcaPKIMsgNewAttachMime(int isBinary,const char *contentType,const char *charset,const char *fileName,const unsigned char *fileContent,int fileLen);

/*
 *	NetcaPKIMsgMimeTrimHeaderComment
 *		删掉MIME头的注释。只有明确可以使用注释的头才能使用
 *	参数：
 *		hMime：MIME句柄
 *		header:输入参数，带注释的头。
 *		newHeader: 输出参数，删除注释后的头
 *	返回值：
 *		成功返回NETCA_PKI_SUCCESS，失败返回其他值
 *
 */
int NETCADLLAPI NetcaPKIMsgMimeTrimHeaderComment(const char *header,char** newHeader);

#ifdef __cplusplus
	}	
#endif
#endif
