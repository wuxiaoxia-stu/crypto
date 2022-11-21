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
 *			����һ��OCSP�������
 *		������
 *			��	
 *		����ֵ��
 *			�ɹ�������Ч��OCSP�������ʧ�ܷ���NULL
 */
NETCA_OCSPRequest NETCAAPI netca_ocspreq_new(void);


/*
 *		netca_ocspreq_free
 *			�ͷ�OCSP�������
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ocspreq_free(NETCA_OCSPRequest req);


/*
 *		netca_ocspreq_addcert
 *			���֤�鵽OCSP�������
 *		������
 *			req��OCSP�������
 *			certid��OCSP��CERTID����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspreq_addcert(NETCA_OCSPRequest req,NETCA_OCSPRequest_CertID certid);

/*
 *		netca_ocspreq_addprefsignalgo
 *			���PreferredSignatureAlgorithm��OCSP��������id-pkix-ocsp-pref-sig-algs��չ
 *		������
 *			req��OCSP�������
 *			signAlgo�����������ǩ���㷨
 *			signAlgoParam�����������ǩ���㷨����
 *			pubkeyAlgo�������������Կ�㷨������ΪNULL
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspreq_addprefsignalgo(NETCA_OCSPRequest req,int signAlgo,void *signAlgoParam,const char *pubkeyAlgo);

/*
 *		netca_ocspreq_getcertcount
 *			��ȡOCSP��������֤�����
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			�ɹ�����֤�������ʧ�ܷ���-1
 */
int NETCAAPI netca_ocspreq_getcertcount(NETCA_OCSPRequest req);


/*
 *		netca_ocspreq_getcertcount
 *			��ȡOCSP�������ĵ�index֤��ID
 *		������
 *			req��OCSP�������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�index֤��ID��ʧ�ܷ���NULL
 */
NETCA_OCSPRequest_CertID NETCAAPI netca_ocspreq_getcertid(NETCA_OCSPRequest req,int index);


/*
 *		netca_ocspreq_addnonce
 *			��OCSP����������nonce��Ϣ
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspreq_addnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_setnonce
 *			��OCSP����������nonce��Ϣ
 *		������
 *			req��OCSP�������
 *			nonce�����������Nonce��ֵ
 *			nonceLen: ���������Nonce�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspreq_setnonce(NETCA_OCSPRequest req,const unsigned char *nonce,int nonceLen);

/*
 *		netca_ocspreq_hasnonce
 *			�ж���OCSP��������Ƿ����nonce
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			���򷵻�1��û�з���0
 */
int NETCAAPI netca_ocspreq_hasnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_getnonce
 *			��ȡ��OCSP��������nonce
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			�ɹ�����nonce����ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_getnonce(NETCA_OCSPRequest req);

/*
 *		netca_ocsp_certid_create
 *			����һ��OCSP��CERTID����
 *		������
 *			��	
 *		����ֵ��
 *			�ɹ�������Ч��OCSP��CERTID����ʧ�ܷ���NULL
 */
NETCA_OCSPRequest_CertID NETCAAPI netca_ocsp_certid_create(int hashAlgo,NETCA_CERT issuer,NETCA_CERT cert);

/*
 *		netca_ocsp_certid_destory
 *			�ͷ�OCSP��CERTID����
 *		������
 *			certid��OCSP��CERTID����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ocsp_certid_destory(NETCA_OCSPRequest_CertID certid);


/*
 *		netca_ocsp_certid_equals
 *			�Ƚ�OCSP��CERTID�����Ƿ����
 *		������
 *			certid1��OCSP��CERTID����1
 *			certid2��OCSP��CERTID����2
 *		����ֵ��
 *			�����ȷ���1�����򷵻�0
 */
int NETCAAPI netca_ocsp_certid_equals(NETCA_OCSPRequest_CertID certid1,NETCA_OCSPRequest_CertID certid2);


/*
 *		netca_ocsp_certid_equals
 *			�ж�OCSP��CERTID����certid�Ƿ���֤��cert������
 *		������
 *			certid��OCSP��CERTID����
 *			issuer���䷢��֤��
 *			cert��֤�����
 *		����ֵ��
 *			����Ƿ���1�����򷵻�0
 */
int NETCAAPI netca_ocsp_certid_match(NETCA_OCSPRequest_CertID certid,NETCA_CERT issuer,NETCA_CERT cert);


/*
 *		netca_ocspreq_encode
 *			��OCSP���������б���
 *		������
 *			req��OCSP�������
 *		����ֵ��
 *			�ɹ�����OCSP�����DER���룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_encode(NETCA_OCSPRequest req);

/*
 *		netca_ocspreq_sign
 *			��OCSP�������ǩ��
 *		������
 *			req��OCSP�������
 *			cert��ǩ��֤��
 *			handle��ǩ��˽Կ
 *			algoid��ǩ���㷨
 *			param��ǩ����ز���
 *		����ֵ��
 *			�ɹ�����OCSP�����DER���룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspreq_sign(NETCA_OCSPRequest req,NETCA_CERT cert,NETCA_PKI_KEYPAIR_HANDLE handle,int algoid,const void *param);


/*
 *		netca_ocspreq_decode
 *			����һ��OCSP�������
 *		������
 *			data�����������OCSP�����DER����
 *			dataLen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�������Ч��OCSP�������ʧ�ܷ���NULL
 */
NETCA_OCSPRequest NETCAAPI netca_ocspreq_decode(const unsigned char *data,int dataLen);




/*
 *		netca_ocspresp_decode
 *			����һ��OCSP��Ӧ����
 *		������
 *			data�����������OCSP��Ӧ��DER����
 *			dataLen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�������Ч��OCSP��Ӧ����ʧ�ܷ���NULL
 */
NETCA_OCSPResponse NETCAAPI netca_ocspresp_decode(const unsigned char *data,int dataLen);


/*
 *		netca_basicocspresp_decode
 *			����һ��OCSP��Ӧ����
 *		������
 *			data�����������BasicOCSPResponse��DER����
 *			dataLen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�������Ч��OCSP��Ӧ����ʧ�ܷ���NULL
 */
NETCA_OCSPResponse NETCAAPI netca_basicocspresp_decode(const unsigned char *data,int dataLen);

/*
 *		netca_ocspresp_free
 *			�ͷ�OCSP��Ӧ����
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ocspresp_free(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_encode
 *			��OCSP��Ӧ������б���
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�����OCSP��Ӧ��DER���룬ʧ�ܷ���NULL
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
 *			��ȡOCSP��Ӧ��״̬
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�������Ӧ��״̬��ʧ�ܷ���-1
 */
int NETCAAPI netca_ocspresp_getstatus(NETCA_OCSPResponse resp);


/*
 *		netca_ocspresp_addcert
 *			���OCSP��Ӧ��ǩ��֤��
 *		������
 *			resp��OCSP��Ӧ����
 *			cert��֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspresp_addcert(NETCA_OCSPResponse resp,NETCA_CERT cert);


/*
 *		netca_ocspresp_verify
 *			��֤OCSP��Ӧ
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspresp_verify(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_getsigncert
 *			��ȡOCSP��Ӧ��ǩ��֤��
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�����ǩ��֤�飬ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_ocspresp_getsigncert(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_hasnonce
 *			�ж���OCSP��Ӧ�����Ƿ����nonce
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			���򷵻�1��û�з���0
 */
int NETCAAPI netca_ocspresp_hasnonce(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_getnonce
 *			��ȡ��OCSP��Ӧ�����nonce
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�����nonce����ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_ocspresp_getnonce(NETCA_OCSPResponse resp);

/*
 *		netca_ocspresp_matchprefsignalgo
 *			�ж�ocsp��Ӧ�е��㷨�Ƿ�������PreferredSignatureAlgorithms��չƥ�䣬���������û��PreferredSignatureAlgorithms��չ,����1
 *		������
 *			resp��OCSP��Ӧ����
 *			req��OCSP�������
 *		����ֵ��
 *			ƥ�䷵��1�����򷵻�0
 */
int NETCAAPI netca_ocspresp_matchprefsignalgo(NETCA_OCSPResponse resp,NETCA_OCSPRequest req);

/*
 *		netca_ocspresp_getproducedat
 *			��ȡ��OCSP��Ӧ����Ĳ���ʱ��
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ����ز���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_ocspresp_getproducedat(NETCA_OCSPResponse resp);


/*
 *		netca_ocspresp_getcertstatuscount
 *			��ȡ��OCSP��Ӧ�����е�֤��״̬����
 *		������
 *			resp��OCSP��Ӧ����
 *		����ֵ��
 *			�ɹ�����֤��״̬������ʧ�ܷ���-1
 */
int NETCAAPI netca_ocspresp_getcertstatuscount(NETCA_OCSPResponse resp);


#define NETCA_OCSP_CERT_STATUS_GOOD				0
#define NETCA_OCSP_CERT_STATUS_REVOKED			1
#define NETCA_OCSP_CERT_STATUS_UNKNOWN			2
/*
 *		netca_ocspresp_getcertstatus
 *			��OCSP��Ӧ�л�ȡ֤��״̬
 *		������
 *			resp��OCSP��Ӧ����
 *			certid��֤��ID
 *			thisUpdate������������ɹ�����thisUpdate
 *			nextUpdate������������ɹ�����nextUpdate
 *			status������������ɹ�����֤���״̬
 *			revResaon�����������֤������ʱ���������ϵ�ԭ��û�����ϵ�ԭ���򷵻�-1
 *			revTime�����������֤������ʱ���������ϵ�ʱ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspresp_getcertstatus(NETCA_OCSPResponse resp,NETCA_OCSPRequest_CertID certid,NETCA_Time *thisUpdate,NETCA_Time *nextUpdate,int *status,int *revResaon,NETCA_Time *revTime);

/*
 *		netca_ocspresp_getcertstatus
 *			��OCSP��Ӧ�л�ȡ֤��״̬
 *		������
 *			resp��OCSP��Ӧ����
 *			issuer���䷢��֤��
 *			cert��֤��
 *			thisUpdate������������ɹ�����thisUpdate
 *			nextUpdate������������ɹ�����nextUpdate
 *			status������������ɹ�����֤���״̬
 *			revResaon�����������֤������ʱ���������ϵ�ԭ��û�����ϵ�ԭ���򷵻�-1
 *			revTime�����������֤������ʱ���������ϵ�ʱ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocspresp_getcertstatus_ex(NETCA_OCSPResponse resp,NETCA_CERT issuer,NETCA_CERT cert,NETCA_Time *thisUpdate,NETCA_Time *nextUpdate,int *status,int *revResaon,NETCA_Time *revTime);


/*
 *		netca_ocsp_getcertstatus
 *			����OCSP��ȡ֤��״̬
 *		������
 *			ocspurl�����������OCSP��URL
 *			hashAlgo�����������Hash�㷨
 *			usenonce�����������Ϊ�棬��ʹ��nonce��Ϊ����ʹ��
 *			issuer���䷢��֤��
 *			cert��Ҫ��ѯ״̬��֤��
 *			vacert��OCSP������֤�飬����ΪNULL
 *			status������������ɹ�����֤���״̬
 *			revResaon�����������֤������ʱ���������ϵ�ԭ��û�����ϵ�ԭ���򷵻�-1
 *			revTime�����������֤������ʱ���������ϵ�ʱ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ocsp_getcertstatus(const char *ocspurl,int hashAlgo,int usenonce,NETCA_CERT issuer,NETCA_CERT cert,NETCA_CERT vacert,int *status,int *revResaon,NETCA_Time *revTime);

#ifdef __cplusplus
	}	
#endif
#endif
