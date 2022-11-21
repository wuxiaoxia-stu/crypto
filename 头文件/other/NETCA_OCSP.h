#ifndef NETCA_OCSP_INLCUDE_H
#define NETCA_OCSP_INLCUDE_H


#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


#define NETCA_OCSP_REQUEST_V1		0

/*
 *		netca_ocspreq_new
 *			创建一个OCSP请求对象
 *		参数：
 *			无	
 *		返回值：
 *			成功返回有效的OCSP请求对象，失败返回NULL
 */
NETCA_OCSPRequest NETCAAPI netca_ocspreq_new(void);


/*
 *		netca_ocspreq_free
 *			释放OCSP请求对象
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_ocspreq_free(NETCA_OCSPRequest req);


/*
 *		netca_ocspreq_addcert
 *			添加证书到OCSP请求对象
 *		参数：
 *			req：OCSP请求对象
 *			certid：OCSP的CERTID对象
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspreq_addcert(NETCA_OCSPRequest req,NETCA_OCSPRequest_CertID certid);

/*
 *		netca_ocspreq_addprefsignalgo
 *			添加PreferredSignatureAlgorithm到OCSP请求对象的id-pkix-ocsp-pref-sig-algs扩展
 *		参数：
 *			req：OCSP请求对象
 *			signAlgo：输入参数，签名算法
 *			signAlgoParam：输入参数，签名算法参数
 *			pubkeyAlgo：输入参数，公钥算法，可以为NULL
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspreq_addprefsignalgo(NETCA_OCSPRequest req,int signAlgo,void *signAlgoParam,const char *pubkeyAlgo);

/*
 *		netca_ocspreq_getcertcount
 *			获取OCSP请求对象的证书个数
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			成功返回证书个数，失败返回-1
 */
int NETCAAPI netca_ocspreq_getcertcount(NETCA_OCSPRequest req);


/*
 *		netca_ocspreq_getcertcount
 *			获取OCSP请求对象的第index证书ID
 *		参数：
 *			req：OCSP请求对象
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回第index证书ID，失败返回NULL
 */
NETCA_OCSPRequest_CertID NETCAAPI netca_ocspreq_getcertid(NETCA_OCSPRequest req,int index);


/*
 *		netca_ocspreq_addnonce
 *			在OCSP请求对象添加nonce信息
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspreq_addnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_setnonce
 *			在OCSP请求对象添加nonce信息
 *		参数：
 *			req：OCSP请求对象
 *			nonce：输入参数，Nonce的值
 *			nonceLen: 输入参数，Nonce的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspreq_setnonce(NETCA_OCSPRequest req,const unsigned char *nonce,int nonceLen);

/*
 *		netca_ocspreq_hasnonce
 *			判断在OCSP请求对象是否存在nonce
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			有则返回1，没有返回0
 */
int NETCAAPI netca_ocspreq_hasnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_getnonce
 *			获取在OCSP请求对象的nonce
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			成功返回nonce编码值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_getnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocsp_certid_create
 *			创建一个OCSP的CERTID对象
 *		参数：
 *			无	
 *		返回值：
 *			成功返回有效的OCSP的CERTID对象，失败返回NULL
 */
NETCA_OCSPRequest_CertID NETCAAPI netca_ocsp_certid_create(int hashAlgo,NETCA_CERT issuer,NETCA_CERT cert);

/*
 *		netca_ocsp_certid_destory
 *			释放OCSP的CERTID对象
 *		参数：
 *			certid：OCSP的CERTID对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_ocsp_certid_destory(NETCA_OCSPRequest_CertID certid);


/*
 *		netca_ocsp_certid_equals
 *			比较OCSP的CERTID对象是否相等
 *		参数：
 *			certid1：OCSP的CERTID对象1
 *			certid2：OCSP的CERTID对象2
 *		返回值：
 *			如果相等返回1，否则返回0
 */
int NETCAAPI netca_ocsp_certid_equals(NETCA_OCSPRequest_CertID certid1,NETCA_OCSPRequest_CertID certid2);


/*
 *		netca_ocsp_certid_equals
 *			判断OCSP的CERTID对象certid是否是证书cert产生的
 *		参数：
 *			certid：OCSP的CERTID对象
 *			issuer：颁发者证书
 *			cert：证书对象
 *		返回值：
 *			如果是返回1，否则返回0
 */
int NETCAAPI netca_ocsp_certid_match(NETCA_OCSPRequest_CertID certid,NETCA_CERT issuer,NETCA_CERT cert);


/*
 *		netca_ocspreq_encode
 *			对OCSP请求对象进行编码
 *		参数：
 *			req：OCSP请求对象
 *		返回值：
 *			成功返回OCSP请求的DER编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_encode(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_sign
 *			对OCSP请求进行签名
 *		参数：
 *			req：OCSP请求对象
 *			cert：签名证书
 *			handle：签名私钥
 *			algoid：签名算法
 *			param：签名相关参数
 *		返回值：
 *			成功返回OCSP请求的DER编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_sign(NETCA_OCSPRequest req,NETCA_CERT cert,NETCA_PKI_KEYPAIR_HANDLE handle,int algoid,const void *param);


/*
 *		netca_ocspreq_decode
 *			解码一个OCSP请求对象
 *		参数：
 *			data：输入参数，OCSP请求的DER编码
 *			dataLen：输入参数，data的长度
 *		返回值：
 *			成功返回有效的OCSP请求对象，失败返回NULL
 */
NETCA_OCSPRequest NETCAAPI netca_ocspreq_decode(const unsigned char *data,int dataLen);




/*
 *		netca_ocspresp_decode
 *			解码一个OCSP响应对象
 *		参数：
 *			data：输入参数，OCSP响应的DER编码
 *			dataLen：输入参数，data的长度
 *		返回值：
 *			成功返回有效的OCSP响应对象，失败返回NULL
 */
NETCA_OCSPResponse NETCAAPI netca_ocspresp_decode(const unsigned char *data,int dataLen);


/*
 *		netca_basicocspresp_decode
 *			解码一个OCSP响应对象
 *		参数：
 *			data：输入参数，BasicOCSPResponse的DER编码
 *			dataLen：输入参数，data的长度
 *		返回值：
 *			成功返回有效的OCSP响应对象，失败返回NULL
 */
NETCA_OCSPResponse NETCAAPI netca_basicocspresp_decode(const unsigned char *data,int dataLen);

/*
 *		netca_ocspresp_free
 *			释放OCSP响应对象
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_ocspresp_free(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_encode
 *			对OCSP响应对象进行编码
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回OCSP响应的DER编码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspresp_encode(NETCA_OCSPResponse resp);


#define NETCA_OCSP_RESPONSE_STATUS_SUCCESSFUL			0
#define NETCA_OCSP_RESPONSE_STATUS_MALFORMEDREQUEST		1
#define NETCA_OCSP_RESPONSE_STATUS_INTERNALERROR		2
#define NETCA_OCSP_RESPONSE_STATUS_TRYLATER				3
#define NETCA_OCSP_RESPONSE_STATUS_SIGREQUIRED			5
#define NETCA_OCSP_RESPONSE_STATUS_UNAUTHORIZED			6

/*
 *		netca_ocspresp_getstatus
 *			获取OCSP响应的状态
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回响应的状态，失败返回-1
 */
int NETCAAPI netca_ocspresp_getstatus(NETCA_OCSPResponse resp);


/*
 *		netca_ocspresp_addcert
 *			添加OCSP响应的签名证书
 *		参数：
 *			resp：OCSP响应对象
 *			cert：证书
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspresp_addcert(NETCA_OCSPResponse resp,NETCA_CERT cert);


/*
 *		netca_ocspresp_verify
 *			验证OCSP响应
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspresp_verify(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_getsigncert
 *			获取OCSP响应的签名证书
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回签名证书，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_ocspresp_getsigncert(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_hasnonce
 *			判断在OCSP响应对象是否存在nonce
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			有则返回1，没有返回0
 */
int NETCAAPI netca_ocspresp_hasnonce(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_getnonce
 *			获取在OCSP响应对象的nonce
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回nonce编码值，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspresp_getnonce(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_matchprefsignalgo
 *			判断ocsp响应中的算法是否和请求的PreferredSignatureAlgorithms扩展匹配，如果请求中没有PreferredSignatureAlgorithms扩展,返回1
 *		参数：
 *			resp：OCSP响应对象
 *			req：OCSP请求对象
 *		返回值：
 *			匹配返回1，否则返回0
 */
int NETCAAPI netca_ocspresp_matchprefsignalgo(NETCA_OCSPResponse resp,NETCA_OCSPRequest req);

/*
 *		netca_ocspresp_getproducedat
 *			获取在OCSP响应对象的产生时间
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回产生时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_ocspresp_getproducedat(NETCA_OCSPResponse resp);


/*
 *		netca_ocspresp_getcertstatuscount
 *			获取在OCSP响应对象中的证书状态个数
 *		参数：
 *			resp：OCSP响应对象
 *		返回值：
 *			成功返回证书状态个数，失败返回-1
 */
int NETCAAPI netca_ocspresp_getcertstatuscount(NETCA_OCSPResponse resp);


#define NETCA_OCSP_CERT_STATUS_GOOD				0
#define NETCA_OCSP_CERT_STATUS_REVOKED			1
#define NETCA_OCSP_CERT_STATUS_UNKNOWN			2
/*
 *		netca_ocspresp_getcertstatus
 *			在OCSP响应中获取证书状态
 *		参数：
 *			resp：OCSP响应对象
 *			certid：证书ID
 *			thisUpdate：输出参数，成功返回thisUpdate
 *			nextUpdate：输出参数，成功返回nextUpdate
 *			status：输出参数，成功返回证书的状态
 *			revResaon：输出参数，证书作废时，返回作废的原因，没有作废的原因则返回-1
 *			revTime：输出参数，证书作废时，返回作废的时间
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspresp_getcertstatus(NETCA_OCSPResponse resp,NETCA_OCSPRequest_CertID certid,NETCA_Time *thisUpdate,NETCA_Time *nextUpdate,int *status,int *revResaon,NETCA_Time *revTime);

/*
 *		netca_ocspresp_getcertstatus
 *			在OCSP响应中获取证书状态
 *		参数：
 *			resp：OCSP响应对象
 *			issuer：颁发者证书
 *			cert：证书
 *			thisUpdate：输出参数，成功返回thisUpdate
 *			nextUpdate：输出参数，成功返回nextUpdate
 *			status：输出参数，成功返回证书的状态
 *			revResaon：输出参数，证书作废时，返回作废的原因，没有作废的原因则返回-1
 *			revTime：输出参数，证书作废时，返回作废的时间
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocspresp_getcertstatus_ex(NETCA_OCSPResponse resp,NETCA_CERT issuer,NETCA_CERT cert,NETCA_Time *thisUpdate,NETCA_Time *nextUpdate,int *status,int *revResaon,NETCA_Time *revTime);


/*
 *		netca_ocsp_getcertstatus
 *			根据OCSP获取证书状态
 *		参数：
 *			ocspurl：输入参数，OCSP的URL
 *			hashAlgo：输入参数，Hash算法
 *			usenonce：输入参数，为真，则使用nonce，为假则不使用
 *			issuer：颁发者证书
 *			cert：要查询状态的证书
 *			vacert：OCSP服务器证书，可以为NULL
 *			status：输出参数，成功返回证书的状态
 *			revResaon：输出参数，证书作废时，返回作废的原因，没有作废的原因则返回-1
 *			revTime：输出参数，证书作废时，返回作废的时间
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ocsp_getcertstatus(const char *ocspurl,int hashAlgo,int usenonce,NETCA_CERT issuer,NETCA_CERT cert,NETCA_CERT vacert,int *status,int *revResaon,NETCA_Time *revTime);

#ifdef __cplusplus
	}	
#endif
#endif
