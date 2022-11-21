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
 *       创建电子印章句柄用于创建电子印章
 *   参数：
 *       format：输入参数，电子印章的格式，也就是遵循的标准。
 *   返回值：
 *      成功返回电子印章句柄，失败返回NULL
 */
NETCA_PKI_SES_STAMP_HANDLE NETCADLLAPI NetcaPKISESNewStamp(int format);
/*
 *   NetcaPKISESFreeStamp
 *       释放电子印章句柄
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESFreeStamp(NETCA_PKI_SES_STAMP_HANDLE stamp);
/*
 *   NetcaPKISESStampSetVersion
 *       设置电子印章的版本号
 *   参数：
 *       stamp：电子印章句柄
 *       version：输入参数，版本号,GB/T 38540必须为4
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetVersion(NETCA_PKI_SES_STAMP_HANDLE stamp,int version);

/*
 *   NetcaPKISESStampSetVid
 *       设置电子印章的厂商ID
 *   参数：
 *       stamp：电子印章句柄
 *       vid：输入参数，电子印章厂商ID，ASCII编码
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetVid(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* vid);

/*
 *   NetcaPKISESStampSetId
 *       设置电子印章的ID
 *   参数：
 *       stamp：电子印章句柄
 *       id：输入参数，电子印章ID，ASCII编码
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetId(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* id);

/*
 *   NetcaPKISESStampSetType
 *       设置电子印章的类型
 *   参数：
 *       stamp：电子印章句柄
 *       type：输入参数，电子印章的类型
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetType(NETCA_PKI_SES_STAMP_HANDLE stamp, int type);

/*
 *   NetcaPKISESStampSetName
 *       设置电子印章的名称
 *   参数：
 *       stamp：电子印章句柄
 *       name：输入参数，电子印章的名称，UTF-8编码
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetName(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* name);

/*
 *   NetcaPKISESStampAddCert
 *       添加电子印章的签章人证书
 *   参数：
 *       stamp：电子印章句柄
 *		 type：输入参数，证书列表类型
 *		 hashAlgo：输入参数，Hash算法
 *       cert：输入参数，签章人证书
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampAddCert(NETCA_PKI_SES_STAMP_HANDLE stamp, int type,int hashAlgo,NETCA_PKI_CERTIFICATE_HANDLE cert);

/*
 *   NetcaPKISESStampSetCreateDate
 *       设置电子印章的制作时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输入参数，电子印章的制作时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetCreateDate(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetValidStart
 *       设置电子印章的有效期开始时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输入参数，电子印章的有效期开始时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetValidStart(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetValidEnd
 *       设置电子印章的有效期结束时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输入参数，电子印章的有效期结束时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetValidEnd(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* time);

/*
 *   NetcaPKISESStampSetPicture
 *       设置电子印章的图片
 *   参数：
 *       stamp：电子印章句柄
 *       type：输入参数，图片类型
 *       data：输入参数，图片内容
 *       dataLen：输入参数，图片内容的字节数
 *       width：输入参数，图片显示宽度(mm)
 *       heigth：输入参数，图片显示高度(mm)
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetPicture(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* type,const unsigned char* data,int dataLen,int width,int heigth);

/*
 *   NetcaPKISESStampAddExtension
 *       添加电子印章的扩展
 *   参数：
 *       stamp：电子印章句柄
 *       oid：输入参数，扩展的OID
 *       critical：输入参数，是否关键扩展
 *       value：输入参数，扩展值
 *       valueLen：输入参数，扩展值的字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampAddExtension(NETCA_PKI_SES_STAMP_HANDLE stamp, const char* oid,int critical,const unsigned char* value,int valueLen);

/*
 *   NetcaPKISESStampSetEmptyExtension
 *       设置电子印章的扩展为空
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSetEmptyExtension(NETCA_PKI_SES_STAMP_HANDLE stamp);


/*
 *   NetcaPKISESStampSign
 *       签名得到电子印章编码
 *   参数：
 *       stamp：电子印章句柄
 *       signCert：输入参数，制章人证书
 *       signAlgo：输入参数，签名算法
 *       param：输入参数，签名算法参数
 *       stampEncode：输出参数，成功返回电子印章的编码
 *       stampEncodeLen：输出参数，成功返回电子印章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSign(NETCA_PKI_SES_STAMP_HANDLE stamp, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** stampEncode,int* stampEncodeLen);

/*
 *   NetcaPKISESStampSignWithCallback
 *       使用回调函数签名得到电子印章编码
 *   参数：
 *       stamp：电子印章句柄
 *       signCallback：输入参数，签名回调函数
 *       context：输入参数，签名回调函数上下文参数
 *       signCert：输入参数，制章人证书
 *       signAlgo：输入参数，签名算法
 *       param：输入参数，签名算法参数
 *       stampEncode：输出参数，成功返回电子印章的编码
 *       stampEncodeLen：输出参数，成功返回电子印章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampSignWithCallback(NETCA_PKI_SES_STAMP_HANDLE stamp, NetcaSESSignCallback_Ptr signCallback, void *context, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** stampEncode, int* stampEncodeLen);

/*
 *   NetcaPKISESStampDecode
 *       解码电子印章编码得到电子印章句柄
 *   参数：
 *       data：输入参数，电子印章的编码
 *       dataLen：输入参数，电子印章的编码长度
 *   返回值：
 *      成功返回电子印章句柄，失败返回NULL
 */
NETCA_PKI_SES_STAMP_HANDLE NETCADLLAPI NetcaPKISESStampDecode(const unsigned char* data,int dataLen);

/*
 *   NetcaPKISESStampGetFormat
 *       获取电子印章的格式,NETCA_PKI_SES_FORMAT_GMT_0031或者NETCA_PKI_SES_FORMAT_GBT_38540
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回电子印章的格式，失败返回-1
 */
int NETCADLLAPI NetcaPKISESStampGetFormat(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetVersion
 *       获取电子印章的版本号
 *   参数：
 *       stamp：电子印章句柄
 *       version：输出参数，成功返回版本号
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetVersion(NETCA_PKI_SES_STAMP_HANDLE stamp, int* version);

/*
 *   NetcaPKISESStampGetVid
 *       获取电子印章的厂商ID
 *   参数：
 *       stamp：电子印章句柄
 *       vid：输出参数，成功返回电子印章厂商ID
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetVid(NETCA_PKI_SES_STAMP_HANDLE stamp, char** vid);

/*
 *   NetcaPKISESStampGetId
 *       获取电子印章的ID
 *   参数：
 *       stamp：电子印章句柄
 *       id：输出参数，成功返回电子印章ID
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetId(NETCA_PKI_SES_STAMP_HANDLE stamp, char** id);

/*
 *   NetcaPKISESStampGetType
 *       获取电子印章的类型
 *   参数：
 *       stamp：电子印章句柄
 *       type：输出参数，成功返回电子印章的类型
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetType(NETCA_PKI_SES_STAMP_HANDLE stamp, int* type);

/*
 *   NetcaPKISESStampGetName
 *       获取电子印章的名称
 *   参数：
 *       stamp：电子印章句柄
 *       name：输出参数，成功返回电子印章的名称
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetName(NETCA_PKI_SES_STAMP_HANDLE stamp, char** name);

/*
 *   NetcaPKISESStampGetCertListType
 *       获取电子印章的签章人证书列表的类型
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回签章人证书列表的类型，失败返回-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertListType(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCertCount
 *       获取电子印章的签章人证书个数
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回签章人证书个数，失败返回-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCert
 *       获取电子印章的签章人证书
 *   参数：
 *       stamp：电子印章句柄
 *       index：输入参数，索引号，从0算起
 *   返回值：
 *      成功返回第index个签章人证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESStampGetCert(NETCA_PKI_SES_STAMP_HANDLE stamp,int index);

/*
 *   NetcaPKISESStampGetCertDigestCount
 *       获取电子印章的签章人证书杂凑的个数
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回签章人证书杂凑的个数，失败返回-1
 */
int NETCADLLAPI NetcaPKISESStampGetCertDigestCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetCertDigest
 *       获取电子印章的第index个签章人证书杂凑
 *   参数：
 *      stamp：电子印章句柄
 *		index：输入参数，索引号
 *		type：输出参数，成功返回类型
 *		hashValue：输出参数，成功返回杂凑值
 *		hashLen：输出参数，成功返回杂凑长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetCertDigest(NETCA_PKI_SES_STAMP_HANDLE stamp,int index,char** type,unsigned char** hashValue,int* hashLen);

/*
 *   NetcaPKISESStampGetCreateDate
 *       获取电子印章的制作时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输出参数，成功返回电子印章的制作时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetCreateDate(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetValidStart
 *       获取电子印章的有效期开始时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输出参数，成功返回电子印章的有效期开始时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetValidStart(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetValidEnd
 *       获取电子印章的有效期结束时间
 *   参数：
 *       stamp：电子印章句柄
 *       time：输出参数，成功返回电子印章的有效期结束时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetValidEnd(NETCA_PKI_SES_STAMP_HANDLE stamp, char** time);

/*
 *   NetcaPKISESStampGetPicture
 *       获取电子印章的图片
 *   参数：
 *       stamp：电子印章句柄
 *       type：输出参数，成功返回图片类型
 *       data：输出参数，成功返回图片内容
 *       dataLen：输出参数，成功返回图片内容的字节数
 *       width：输出参数，成功返回图片显示宽度(mm)
 *       heigth：输出参数，成功返回图片显示高度(mm)
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetPicture(NETCA_PKI_SES_STAMP_HANDLE stamp, char** type, unsigned char** data, int* dataLen, int* width, int* heigth);

/*
 *   NetcaPKISESStampGetExtensionCount
 *       获取电子印章的扩展个数
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回电子印章的扩展个数，失败返回-1
 */
int NETCADLLAPI NetcaPKISESStampGetExtensionCount(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetExtension
 *       获取电子印章的扩展
 *   参数：
 *       stamp：电子印章句柄
 *       index:输入参数，索引号，从0算起
 *       oid：输出参数，成功返回扩展的OID
 *       critical：输出参数，成功返回是否关键扩展
 *       value：输出参数，成功返回扩展值
 *       valueLen：输出参数，成功返回扩展值的字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetExtension(NETCA_PKI_SES_STAMP_HANDLE stamp, int index,char** oid, int* critical, unsigned char** value, int* valueLen);

/*
 *   NetcaPKISESStampGetEncode
 *       获取电子印章的编码
 *   参数：
 *       stamp：电子印章句柄
 *       encode：输出参数，成功返回电子印章的编码
 *       encodeLen：输出参数，成功返回电子印章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetEncode(NETCA_PKI_SES_STAMP_HANDLE stamp, unsigned char** encode, int* encodeLen);


/*
 *   NetcaPKISESStampGetSignCert
 *       获取电子印章的制章人证书
 *   参数：
 *       stamp：电子印章句柄
 *   返回值：
 *      成功返回制章人证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESStampGetSignCert(NETCA_PKI_SES_STAMP_HANDLE stamp);

/*
 *   NetcaPKISESStampGetSignAlgorithm
 *       获取电子印章的签名算法
 *   参数：
 *       stamp：电子印章句柄
 *       algo：输出参数，成功返回电子印章的签名算法
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampGetSignAlgorithm(NETCA_PKI_SES_STAMP_HANDLE stamp, int* algo);


/*
 *   NetcaPKISESStampVerify
 *       验证电子印章
 *   参数：
 *       stamp：电子印章句柄
 *       time：输入参数，验证的时间，如果为NULL，则为当前时间
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESStampVerify(NETCA_PKI_SES_STAMP_HANDLE stamp,const char* time);

/*
 *   NetcaPKISESNewSeal
 *       创建电子签章句柄用于创建电子签章
 *   参数：
 *       format：输入参数，电子印章的格式，也就是遵循的标准。
 *   返回值：
 *      成功返回电子签章句柄，失败返回NULL
 */
NETCA_PKI_SES_SEAL_HANDLE NETCADLLAPI NetcaPKISESNewSeal(int format);

/*
 *   NetcaPKISESFreeSeal
 *       释放电子签章句柄
 *   参数：
 *       stamp：电子签章句柄
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESFreeSeal(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealSetVersion
 *       设置电子签章的版本号
 *   参数：
 *       seal：电子签章句柄
 *       version：输入参数，版本号
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetVersion(NETCA_PKI_SES_SEAL_HANDLE seal, int version);

/*
 *   NetcaPKISESSealSetStamp
 *       设置电子签章的电子印章
 *   参数：
 *       seal：电子签章句柄
 *       stamp：输入参数，电子印章
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetStamp(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_SES_STAMP_HANDLE stamp);


/*
 *   NetcaPKISESSealSetTime
 *       设置电子签章的签章时间
 *   参数：
 *       seal：电子签章句柄
 *       time：输入参数，签章时间，格式为YYYYMMDDhhmmssZ
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetTime(NETCA_PKI_SES_SEAL_HANDLE seal, const char* time);


/*
 *   NetcaPKISESSealGMT0031SetTimeInfo
 *       设置电子签章的签章时间
 *   参数：
 *       seal：电子签章句柄
 *       timeInfo：输入参数，签章时间，格式不限
 *       timeInfoLen：输入参数，timeInfo的长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGMT0031SetTimeInfo(NETCA_PKI_SES_SEAL_HANDLE seal, const unsigned char* timeInfo,int timeInfoLen);

/*
 *   NetcaPKISESSealSetDataHash
 *       设置电子签章的原文杂凑值
 *   参数：
 *       seal：电子签章句柄
 *       hashValue：输入参数，原文杂凑值
 *       hashValueLen：输入参数，原文杂凑值字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetDataHash(NETCA_PKI_SES_SEAL_HANDLE seal, const unsigned char* hashValue,int hashValueLen);

/*
 *   NetcaPKISESSealSetProperty
 *       设置电子签章的原文属性信息
 *   参数：
 *       seal：电子签章句柄
 *       property：输入参数，原文属性信息，ASCII码
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetProperty(NETCA_PKI_SES_SEAL_HANDLE seal, const char* property);

/*
 *   NetcaPKISESSealAddExtension
 *       添加电子签章的扩展
 *   参数：
 *       seal：电子签章句柄
 *       oid：输入参数，扩展的OID
 *       critical：输入参数，是否关键扩展
 *       value：输入参数，扩展值
 *       valueLen：输入参数，扩展值的字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealAddExtension(NETCA_PKI_SES_SEAL_HANDLE seal, const char* oid,int critical,const unsigned char* value,int valueLen);
/*
 *   NetcaPKISESSealSetEmptyExtension
 *       设置电子签章的扩展为空
 *   参数：
 *       seal：电子签章句柄
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSetEmptyExtension(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealSign
 *       签名得到电子签章编码
 *   参数：
 *       seal：电子签章句柄
 *       signCert：输入参数，签章人证书
 *       signAlgo：输入参数，签名算法
 *       param：输入参数，签名算法参数
 *       sealEncode：输出参数，成功返回电子签章的编码
 *       sealEncodeLen：输出参数，成功返回电子签章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSign(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** sealEncode, int* sealEncodeLen);


/*
 *   NetcaPKISESSealSignWithCallback
 *       使用回调函数签名得到电子签章编码
 *   参数：
 *       seal：电子签章句柄
 *       signCallback：输入参数，签名回调函数
 *       context：输入参数，签名回调函数上下文参数
 *       signCert：输入参数，签章人证书
 *       signAlgo：输入参数，签名算法
 *       param：输入参数，签名算法参数
 *       sealEncode：输出参数，成功返回电子签章的编码
 *       sealEncodeLen：输出参数，成功返回电子签章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealSignWithCallback(NETCA_PKI_SES_SEAL_HANDLE seal, NetcaSESSignCallback_Ptr signCallback, void *context, NETCA_PKI_CERTIFICATE_HANDLE signCert, int signAlgo, const void* param, unsigned char** sealEncode, int* sealEncodeLen);

/*
 *   NetcaPKISESSealGetHashAlgorithmFromSignAlgorithm
 *       从签名算法中获取杂凑算法
 *   参数：
 *       signAlgo：输入参数，签名算法
 *   返回值：
 *      成功返回对应的杂凑算法，失败返回-1
 */
int NETCADLLAPI NetcaPKISESSealGetHashAlgorithmFromSignAlgorithm(int signAlgo);

/*
 *   NetcaPKISESSealDecode
 *       解码电子签章编码得到电子签章句柄
 *   参数：
 *       data：输入参数，电子签章的编码
 *       dataLen：输入参数，电子签章的编码长度
 *   返回值：
 *      成功返回电子签章句柄，失败返回NULL
 */
NETCA_PKI_SES_SEAL_HANDLE NETCADLLAPI NetcaPKISESSealDecode(const unsigned char* data, int dataLen);

/*
 *   NetcaPKISESSealGetFormat
 *       获取电子签章的格式,NETCA_PKI_SES_FORMAT_GMT_0031或者NETCA_PKI_SES_FORMAT_GBT_38540
 *   参数：
 *       seal：电子签章句柄
 *   返回值：
 *      成功返回电子签章的格式，失败返回-1
 */
int NETCADLLAPI NetcaPKISESSealGetFormat(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetVersion
 *       获取电子签章的版本号
 *   参数：
 *       seal：电子签章句柄
 *       version：输出参数，成功返回版本号
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetVersion(NETCA_PKI_SES_SEAL_HANDLE seal, int* version);

/*
 *   NetcaPKISESSealGetStamp
 *       获取电子签章的电子印章
 *   参数：
 *       seal：电子签章句柄
 *       stamp：输出参数，成功返回电子印章
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetStamp(NETCA_PKI_SES_SEAL_HANDLE seal, NETCA_PKI_SES_STAMP_HANDLE* stamp);


/*
 *   NetcaPKISESSealGetTime
 *       获取电子签章的签章时间
 *   参数：
 *       seal：电子签章句柄
 *       time：输出参数，成功返回签章时间
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetTime(NETCA_PKI_SES_SEAL_HANDLE seal, char** time);

/*
 *   NetcaPKISESSealGMT0031GetTimeInfo
 *       获取电子签章的签章时间
 *   参数：
 *       seal：电子签章句柄
 *       timeInfo：输出参数，成功返回签章时间
 *       timeInfoLen：输出参数，成功返回timeInfo的长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGMT0031GetTimeInfo(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** timeInfo,int *timeInfoLen);

/*
 *   NetcaPKISESSealGetDataHash
 *       获取电子签章的原文杂凑值
 *   参数：
 *       seal：电子签章句柄
 *       hashValue：输出参数，成功返回原文杂凑值
 *       hashValueLen：输出参数，成功返回原文杂凑值的字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetDataHash(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** hashValue,int* hashValueLen);

/*
 *   NetcaPKISESSealGetProperty
 *       获取电子签章的原文属性
 *   参数：
 *       seal：电子签章句柄
 *       property：输出参数，成功返回原文属性
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetProperty(NETCA_PKI_SES_SEAL_HANDLE seal, char** property);

/*
 *   NetcaPKISESSealGetExtensionCount
 *       获取电子签章的扩展个数
 *   参数：
 *       seal：电子签章句柄
 *   返回值：
 *      成功返回电子签章的扩展个数，失败返回-1
 */
int NETCADLLAPI NetcaPKISESSealGetExtensionCount(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESStampGetExtension
 *       获取电子签章的扩展
 *   参数：
 *       seal：电子签章句柄
 *       index:输入参数，索引号，从0算起
 *       oid：输出参数，成功返回扩展的OID
 *       critical：输出参数，成功返回是否关键扩展
 *       value：输出参数，成功返回扩展值
 *       valueLen：输出参数，成功返回扩展值的字节数
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetExtension(NETCA_PKI_SES_SEAL_HANDLE seal, int index,char** oid, int* critical, unsigned char** value, int* valueLen);

/*
 *   NetcaPKISESSealGetSignCert
 *       获取电子签章的签名证书
 *   参数：
 *       seal：电子签章句柄
 *   返回值：
 *      成功返回签名证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaPKISESSealGetSignCert(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetSignAlgorithm
 *       获取电子签章的签名算法
 *   参数：
 *       seal：电子签章句柄
 *       algo：输出参数，成功返回电子签章的签名算法
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetSignAlgorithm(NETCA_PKI_SES_SEAL_HANDLE seal, int* algo);


/*
 *   NetcaPKISESSealVerify
 *       验证电子签章，不验证原文
 *   参数：
 *       seal：电子签章句柄
 *       time：输入参数，验证的时间，如果为NULL，则为当前时间
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealVerify(NETCA_PKI_SES_SEAL_HANDLE seal, const char* time);

/*
 *   NetcaPKISESSealAttachTimeStamp
 *       追加时间戳
 *   参数：
 *       seal：电子签章句柄
 *       hashAlgo：输入参数，时间戳的Hash算法
 *       tsaUrl：输入参数，时间戳的Url
 *       sealEncode：输出参数，成功返回电子签章的编码
 *       sealEncodeLen：输出参数，成功返回电子签章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealAttachTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal, int hashAlgo,const char *tsaUrl, unsigned char** sealEncode, int* sealEncodeLen);

/*
 *   NetcaPKISESSealHasTimeStamp
 *       判断是否有时间戳
 *   参数：
 *   返回值：
 *      有返回1，没有返回0
 */
int NETCADLLAPI NetcaPKISESSealHasTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealVerifyTimeStamp
 *       验证时间戳
 *   参数：
 *       seal：电子签章句柄
 *       tsaCert：输入参数，时间戳证书，可以为NULL
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealVerifyTimeStamp(NETCA_PKI_SES_SEAL_HANDLE seal,NETCA_PKI_CERTIFICATE_HANDLE tsaCert);

/*
 *   NetcaPKISESGetTimeStampHandle
 *       获取时间戳句柄
 *   参数：
 *       seal：电子签章句柄
 *   返回值：
 *      成功返回时间戳句柄，失败返回NULL
 */
NETCA_PKI_TIMESTAMP_HANDLE NETCADLLAPI NetcaPKISESGetTimeStampHandle(NETCA_PKI_SES_SEAL_HANDLE seal);

/*
 *   NetcaPKISESSealGetEncode
 *       获取电子签章的编码
 *   参数：
 *       seal：电子签章句柄
 *       encode：输出参数，成功返回电子签章的编码
 *       encodeLen：输出参数，成功返回电子签章的编码长度
 *   返回值：
 *      成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaPKISESSealGetEncode(NETCA_PKI_SES_SEAL_HANDLE seal, unsigned char** encode, int* encodeLen);

#ifdef __cplusplus
}
#endif
#endif

