#ifndef NETCA_CERT_INLCUDE_H
#define NETCA_CERT_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"
#include "NETCA_UString.h"
#include "NETCA_Error.h"
#include "NETCA_Time.h"
#include "NETCA_Crypto.h"

#ifdef __cplusplus
extern "C"
	{
#endif

enum{
	NETCA_CERT_V1=0,
	NETCA_CERT_V2=1,
	NETCA_CERT_V3=2,
};

#define NETCA_ATTRIBUTE_STRING_TYPE_PRINTABLESTRING		1
#define NETCA_ATTRIBUTE_STRING_TYPE_IA5STRING			2
#define NETCA_ATTRIBUTE_STRING_TYPE_BMPSTRING			4
#define NETCA_ATTRIBUTE_STRING_TYPE_UTF8STRING			8


#define NETCA_DN_LDAP_FLAG_XMLSIG			1

/*
 *		netca_cert_new
 *			����һ��֤�����
 *		������
 *			data�����������֤��ı���ֵ
 *			datalen�����������data�ĳ���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч��֤�����ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_cert_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);

/*
 *		netca_cert_free
 *			�ͷ�֤�����
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_free(NETCA_CERT cert);

/*
 *		netca_cert_dup
 *			����֤�����
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�֤�����ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_cert_dup(NETCA_CERT cert);

/*
 *		netca_cert_encode
 *			��ȡ֤������DER����
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤���DER���룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_encode(NETCA_CERT cert);

/*
 *		netca_cert_cmp
 *			�Ƚ�֤��
 *		������
 *			cert1��֤�����1
 *			cert2��֤�����2
 *		����ֵ��
 *			���cert1>cert2����1������cert1<cert2����-1��������߱�����ȷ���0
 */
int NETCAAPI netca_cert_cmp(NETCA_CERT cert1,NETCA_CERT cert2);

/*
 *		netca_cert_getversion
 *			��ȡ֤��İ汾��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��İ汾�ţ�ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_getversion(NETCA_CERT cert);

/*
 *		netca_cert_getserialnumber
 *			��ȡ֤������к�
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤������кţ�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_getserialnumber(NETCA_CERT cert);

/*
 *		netca_cert_getsignalgorithm
 *			��ȡ֤���ǩ���㷨
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤���ǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getsignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getinnersignalgorithm
 *			��ȡ֤����ڲ��ǩ���㷨
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤����ڲ��ǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getinnersignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getoutersignalgorithm
 *			��ȡ֤�������ǩ���㷨
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤�������ǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getoutersignalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getissuer
 *			��ȡ֤��İ䷢��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��İ䷢�ߣ�ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_getissuer(NETCA_CERT cert);

/*
 *		netca_cert_getsubject
 *			��ȡ֤�������
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤������壬ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_getsubject(NETCA_CERT cert);

/*
 *		netca_cert_getvaliditystart
 *			��ȡ֤�����Ч�ڿ�ʼʱ��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤�����Ч�ڿ�ʼʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_cert_getvaliditystart(NETCA_CERT cert);

/*
 *		netca_cert_getvalidityend
 *			��ȡ֤�����Ч�ڽ���ʱ��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤�����Ч�ڽ���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_cert_getvalidityend(NETCA_CERT cert);

/*
 *		netca_cert_getpubkeyalgorithm
 *			��ȡ֤��Ĺ�Կ�㷨
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��Ĺ�Կ�㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_getpubkeyalgorithm(NETCA_CERT cert);

/*
 *		netca_cert_getpubkey
 *			��ȡ֤��Ĺ�Կ
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��Ĺ�Կ��ʧ�ܷ���NULL
 */
NETCA_CERT_PubKey NETCAAPI netca_cert_getpubkey(NETCA_CERT cert);

/*
 *		netca_cert_hasissueruid
 *			�ж�֤����Ƿ��а䷢��ΨһID
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			���֤���а䷢��ΨһID����1�����򷵻�0
 */
int NETCAAPI netca_cert_hasissueruid(NETCA_CERT cert);

/*
 *		netca_cert_getissueruid
 *			��ȡ֤��İ䷢��ΨһID
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��İ䷢��ΨһID��ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_cert_getissueruid(NETCA_CERT cert);

/*
 *		netca_cert_hassubjectuid
 *			�ж�֤����Ƿ�������ΨһID
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			���֤��������ΨһID����1�����򷵻�0
 */
int NETCAAPI netca_cert_hassubjectuid(NETCA_CERT cert);

/*
 *		netca_cert_getsubjectuid
 *			��ȡ֤�������ΨһID
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤�������ΨһID��ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_cert_getsubjectuid(NETCA_CERT cert);

/*
 *		netca_cert_hasexts
 *			�ж�֤����Ƿ�����չ
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			���֤������չ����1�����򷵻�0
 */
int NETCAAPI netca_cert_hasexts(NETCA_CERT cert);

/*
 *		netca_cert_getexts
 *			��ȡ֤�����չ
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤�����չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_cert_getexts(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalue
 *			��ȡ֤���ǩ��ֵ
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤���ǩ��ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_getsignvalue(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalueunusedbits
 *			��ȡ֤���ǩ��ֵ��δʹ��λ��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤���ǩ��ֵ��δʹ��λ����ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_getsignvalueunusedbits(NETCA_CERT cert);

/*
 *		netca_cert_getsignvalue
 *			��ȡ֤���Ҫǩ�����ֵı���
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤���Ҫǩ�����ֵı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_gettbs(NETCA_CERT cert);

/*
 *		netca_cert_isinvalidity
 *			�ж�֤���Ƿ�����Ч����
 *		������
 *			cert��֤�����
 *			t��ʱ��
 *		����ֵ��
 *			�����ʱ���t��֤������Ч���ڷ���1�����򷵻�0
 */
int NETCAAPI netca_cert_isinvalidity(NETCA_CERT cert,NETCA_Time t);

/*
 *		netca_cert_getsubjectdisplayname
 *			��ȡ֤����������ʾ��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤����������ʾ����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_getsubjectdisplayname(NETCA_CERT cert);

/*
 *		netca_cert_getissuerdisplayname
 *			��ȡ֤��İ䷢�ߵ���ʾ��
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			�ɹ�����֤��İ䷢�ߵ���ʾ����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_getissuerdisplayname(NETCA_CERT cert);

/*
 *		netca_cert_algorithmid_free
 *			�ͷ��㷨
 *		������
 *			cert��֤�����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_algorithmid_free(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_dup
 *			�����㷨
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ����ظ��Ƶ��㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_algorithmid_dup(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getoid
 *			��ȡ�㷨��OID��ʹ��NETCA_FREE���ͷ�
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ������㷨��OID��ʧ�ܷ���NULL
 */
char *NETCAAPI netca_cert_algorithmid_getoid(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_hasparams
 *			�ж��㷨�Ƿ��в���
 *		������
 *			algo���㷨
 *		����ֵ��
 *			����㷨�в�������1�����򷵻�0
 */
int NETCAAPI netca_cert_algorithmid_hasparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_hasnullparam
 *			�ж��㷨�Ƿ���NULL����
 *		������
 *			algo���㷨
 *		����ֵ��
 *			����㷨��NULL��������1�����򷵻�0
 */
int NETCAAPI netca_cert_algorithmid_hasnullparam(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getparamsencode
 *			��ȡ�㷨�Ĳ�������
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ������㷨�Ĳ������룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_algorithmid_getparamsencode(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getdssparams
 *			��ȡ�㷨�ĵ�DSS������Ҫ�㷨������DSS�������ܳɹ�
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ������㷨��DSS������ʧ�ܷ���NULL
 */
NETCA_CERT_DssParms NETCAAPI netca_cert_algorithmid_getdssparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getoaepparams
 *			��ȡ�㷨�ĵ�OAEP������Ҫ�㷨������OAEP�������ܳɹ�
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ������㷨��OAEP������ʧ�ܷ���NULL
 */
struct NETCA_RSA_PARAM_PKCS1_OAEP_st* NETCAAPI netca_cert_algorithmid_getoaepparams(NETCA_CERT_AlgorithmIdentifier algo);

/*
 *		netca_cert_algorithmid_getpssparams
 *			��ȡ�㷨�ĵ�PSS������Ҫ�㷨������PSS�������ܳɹ�
 *		������
 *			algo���㷨
 *		����ֵ��
 *			�ɹ������㷨��PSS������ʧ�ܷ���NULL
 */
struct NETCA_RSA_PARAM_PKCS1_PSS_st* NETCAAPI netca_cert_algorithmid_getpssparams(NETCA_CERT_AlgorithmIdentifier algo);


/*
 *		netca_cert_dn_dup
 *			����DN
 *		������
 *			dn��DN
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�DN��ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_dup(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_free
 *			�ͷ�DN
 *		������
 *			dn��DN
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_dn_free(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getitemcount
 *			��ȡDN��RDN����
 *		������
 *			dn��DN
 *		����ֵ��
 *			�ɹ�����DN��RDN������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_dn_getitemcount(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getitem
 *			��ȡDN��RDN
 *		������
 *			dn��DN
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����DN�ĵ�index��RDN��ʧ�ܷ���NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_dn_getitem(NETCA_CERT_X500_DN dn,int index);

/*
 *		netca_cert_dn_equals
 *			�ж�����DN�Ƿ����
 *		������
 *			dn1��DN1
 *			dn2��DN2
 *		����ֵ��
 *			���DN��ȷ���1�����򷵻�0
 */
int NETCAAPI netca_cert_dn_equals(NETCA_CERT_X500_DN dn1,NETCA_CERT_X500_DN dn2);

/*
 *		netca_cert_dn_getdisplayname
 *			��ȡDN����ʾ��
 *		������
 *			dn��DN
 *		����ֵ��
 *			�ɹ�����DN����ʾ����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_dn_getdisplayname(NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_getldapstring
 *			��ȡDN��LDAP�ַ�����ʾ
 *		������
 *			dn��DN
 *		����ֵ��
 *			�ɹ�����DN��LDAP�ַ�����ʾ��ʧ�ܷ���NULL
 */
char *NETCAAPI netca_cert_dn_getldapstring(int flag,NETCA_CERT_X500_DN dn);

/*
 *		netca_cert_dn_matchldapstring
 *			�ж�DN��LDAP�ַ�����ʾ�Ƿ�ƥ��
 *		������
 *			dn��DN
 *			str�����������LDAP�ַ�����ʾ
 *		����ֵ��
 *			���ƥ�䷵��1�����򷵻�0
 */
int NETCAAPI netca_cert_dn_matchldapstring(NETCA_CERT_X500_DN dn,const char *str);


/*
 *		netca_cert_dn_empty
 *			����һ���յ�DN
 *		������
 *			dn��DN
 *		����ֵ��
 *			�ɹ����ؿյ�DN��ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_dn_empty(void);

/*
 *		netca_cert_dn_add
 *			��DN��ĩβ����һ��RDN
 *		������
 *			dn��DN
 *			rdn��RDN
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_cert_dn_add(NETCA_CERT_X500_DN dn,NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_dup
 *			����RDN
 *		������
 *			rdn��RDN
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�RDN��ʧ�ܷ���NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_rdn_dup(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_free
 *			�ͷ�RDN
 *		������
 *			rdn��RDN
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_rdn_free(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_getitemcount
 *			��ȡRDN��������
 *		������
 *			rdn��RDN
 *		����ֵ��
 *			�ɹ�����RDN����������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_rdn_getitemcount(NETCA_CERT_X500_RDN rdn);

/*
 *		netca_cert_rdn_getitem
 *			��ȡRDN������
 *		������
 *			rdn��RDN
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����RDN�ĵ�index�����ԣ�ʧ�ܷ���NULL
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_rdn_getitem(NETCA_CERT_X500_RDN rdn,int index);

/*
 *		netca_cert_rdn_new
 *			����һ��ֻ����һ�����Ե�RDN
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ�����RDN��ʧ�ܷ���NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_rdn_new(NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_rdn_add
 *			��RDN�����һ������
 *		������
 *			rdn��RDN
 *			attr������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_cert_rdn_add(NETCA_CERT_X500_RDN rdn,NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_attrtypeandvalue_dup
 *			��������
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ����ظ��Ƶ����ԣ�ʧ�ܷ���NULL
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_attrtypeandvalue_dup(NETCA_CERT_AttributeTypeAndValue attr);

/*
 *		netca_cert_attrtypeandvalue_free
 *			�ͷ�����
 *		������
 *			attr_value������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_attrtypeandvalue_free(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_gettype
 *			��ȡ���Ե�OID��ʹ��NETCA_FREE���ͷ�
 *		������
 *			attr_value������
 *		����ֵ��
 *			�ɹ��������Ե�OID��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_attrtypeandvalue_gettype(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getstring
 *			��ȡ����ֵ���ַ�����ʾ
 *		������
 *			attr_value������
 *		����ֵ��
 *			�ɹ���������ֵ���ַ�����ʾ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_attrtypeandvalue_getstring(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getvalencode
 *			��ȡ����ֵ�ı���
 *		������
 *			attr_value������
 *		����ֵ��
 *			�ɹ���������ֵ�ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_attrtypeandvalue_getvalencode(NETCA_CERT_AttributeTypeAndValue attr_value);

/*
 *		netca_cert_attrtypeandvalue_getstrtype
 *			��ȡ����ֵ���ַ�������
 *		������
 *			attr_value������
 *			strtype�������������������ֵ���ַ�������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_cert_attrtypeandvalue_getstrtype(NETCA_CERT_AttributeTypeAndValue attr_value,int *strtype);

/*
 *		netca_cert_attrtypeandvalue_newstring
 *			����һ������
 *		������
 *			type����������OID
 *			strmask���������������ֵ���ַ�������
 *			value������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
NETCA_CERT_AttributeTypeAndValue NETCAAPI netca_cert_attrtypeandvalue_newstring(const char *type,int strmask,NETCA_UString value);

/*
 *		netca_cert_pubkey_dup
 *			���ƹ�Կ
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ����ظ��ƵĹ�Կ��ʧ�ܷ���NULL
 */
NETCA_CERT_PubKey NETCAAPI netca_cert_pubkey_dup(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_free
 *			�ͷŹ�Կ
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_pubkey_free(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_toeccpubkey
 *			��Կת��ΪECC��Կ
 *		������
 *			algo����Կ�㷨
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ�����ECC��Կ��ʧ�ܷ���NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_cert_pubkey_toeccpubkey(NETCA_CERT_AlgorithmIdentifier algo,NETCA_CERT_PubKey pubkey);
/*
 *		netca_cert_pubkey_torsapubkey
 *			��Կת��ΪRSA��Կ
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ�����RSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_cert_pubkey_torsapubkey(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_getencode
 *			��ȡ��Կ����
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ����ع�Կ���룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_pubkey_getencode(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_pubkey_getunusedbits
 *			��ȡ��Կ��δʹ��λ��
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ����ع�Կ��δʹ��λ����ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_pubkey_getunusedbits(NETCA_CERT_PubKey pubkey);


/*
 *		netca_cert_pubkey_todsapubkey
 *			��Կת��ΪDSA��Կ
 *		������
 *			pubkey����Կ
 *		����ֵ��
 *			�ɹ�����DSA��Կ��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_pubkey_todsapubkey(NETCA_CERT_PubKey pubkey);

/*
 *		netca_cert_dssparams_free
 *			�ͷ�DSS����
 *		������
 *			params��DSS����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_dssparams_free(NETCA_CERT_DssParms params);

/*
 *		netca_cert_dssparams_getp
 *			��ȡDSS������p
 *		������
 *			params��DSS����
 *		����ֵ��
 *			�ɹ�����DSS������p��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getp(NETCA_CERT_DssParms params);

/*
 *		netca_cert_dssparams_getq
 *			��ȡDSS������q
 *		������
 *			params��DSS����
 *		����ֵ��
 *			�ɹ�����DSS������q��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getq(NETCA_CERT_DssParms params);
/*
 *		netca_cert_dssparams_getg
 *			��ȡDSS������g
 *		������
 *			params��DSS����
 *		����ֵ��
 *			�ɹ�����DSS������g��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_dssparams_getg(NETCA_CERT_DssParms params);

/*
 *		netca_cert_exts_dup
 *			������չ��
 *		������
 *			exts����չ��
 *		����ֵ��
 *			�ɹ����ظ��Ƶ���չ����ʧ�ܷ���NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_cert_exts_dup(NETCA_CERT_Extensions exts);
/*
 *		netca_cert_exts_free
 *			�ͷ���չ��
 *		������
 *			exts����չ��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_exts_free(NETCA_CERT_Extensions exts);

/*
 *		netca_cert_exts_getitemcount
 *			��ȡ��չ������չ����
 *		������
 *			exts����չ��
 *		����ֵ��
 *			�ɹ�������չ������չ������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_exts_getitemcount(NETCA_CERT_Extensions exts);
/*
 *		netca_cert_exts_getitem
 *			��ȡ��չ������չ
 *		������
 *			exts����չ��
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�������չ���ĵ�index����չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_exts_getitem(NETCA_CERT_Extensions exts,int index);
/*
 *		netca_cert_exts_find
 *			������չOID��Ѱ����չֵ
 *		������
 *			exts����չ��
 *			oid���������������ֵ����չOID
 *		����ֵ��
 *			�ɹ�����OIDΪoid����չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_exts_find(NETCA_CERT_Extensions exts,const char *oid);

/*
 *		netca_cert_ext_free
 *			�ͷ���չ
 *		������
 *			ext����չ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_ext_free(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_dup
 *			������չ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ����ظ��Ƶ���չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extension NETCAAPI netca_cert_ext_dup(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_getextid
 *			��ȡ��չ��OID
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��OID��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_ext_getextid(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_iscrical
 *			�ж���չ�Ƿ�ؼ���չ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�����չ�Ƿ�ؼ���չ����1�����򷵻�0
 */
int NETCAAPI netca_cert_ext_iscrical(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_getvalue
 *			��ȡ��չ�ı���ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ�ı���ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_ext_getvalue(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tooctetstring
 *			��ȡ��չ��OCTET STRING��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��OCTET STRING��ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI  netca_cert_ext_tooctetstring(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tobitstring
 *			��ȡ��չ��BIT STRING��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��BIT STRING��ֵ��ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI  netca_cert_ext_tobitstring(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_togeneralnames
 *			��ȡ��չ��GeneralNames��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��GeneralNames��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralNames  NETCAAPI netca_cert_ext_togeneralnames(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_toakid
 *			��ȡ��չ��AKID��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��AKID��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_AKID  NETCAAPI netca_cert_ext_toakid(NETCA_CERT_Extension ext);

/*
 *		netca_cert_ext_tointeger
 *			��ȡ��չ��������ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�������չ��������ֵ��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_ext_tointeger(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tonull
 *			��ȡ��չ��NULL��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ����ط�NULL�������ͷţ�ʧ�ܷ���NULL
 */
void * NETCAAPI netca_cert_ext_tonull(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toenum
 *			��ȡ��չ��ö�ٵ�ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����ö�ٵ�ֵ��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_ext_toenum(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_topolicymappings
 *			��ȡ��չ��PolicyMappings��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����PolicyMappings��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyMappings NETCAAPI netca_cert_ext_topolicymappings(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toattrs
 *			��ȡ��չ��Attributes��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����Attributes��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_ext_toattrs(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tobasicconstraints
 *			��ȡ��չ��BasicConstraints��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����BasicConstraints��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_BasicConstraints NETCAAPI netca_cert_ext_tobasicconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tonameconstraints
 *			��ȡ��չ��NameConstraints��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����NameConstraints��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_NameConstraints NETCAAPI netca_cert_ext_tonameconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_topolicyconstraints
 *			��ȡ��չ��PolicyConstraints��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����PolicyConstraints��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyConstraints NETCAAPI netca_cert_ext_topolicyconstraints(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toextkeyusage
 *			��ȡ��չ��ExtKeyUsage��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����ExtKeyUsage��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_ExtKeyUsage NETCAAPI netca_cert_ext_toextkeyusage(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tocrldp
 *			��ȡ��չ��CRLDistributionPoints��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����CRLDistributionPoints��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_CRLDistributionPoints NETCAAPI netca_cert_ext_tocrldp(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toaccessdescs
 *			��ȡ��չ��AccessDescriptions��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����AccessDescriptions��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_AccessDescriptions NETCAAPI netca_cert_ext_toaccessdescs(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_togeneralizedtime
 *			��ȡ��չ��GeneralizationTime��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����GeneralizationTime��ֵ��ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_cert_ext_togeneralizedtime(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toidp
 *			��ȡ��չ��IssuingDistributionPoint��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����IssuingDistributionPoint��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_IssuingDistributionPoint NETCAAPI netca_cert_ext_toidp(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tooid
 *			��ȡ��չֵ��OID��ֵ����չֵ������OID����
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����OID��ֵ��ʧ�ܷ���NULL
 */
char *netca_cert_ext_tooid(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toprivkeyusageperiod
 *			��ȡ��չֵ��PrivateKeyUsagePeriod��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����PrivateKeyUsagePeriod��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_PrivateKeyUsagePeriod NETCAAPI netca_cert_ext_toprivkeyusageperiod(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tocertpolicies
 *			��ȡ��չֵ��CertificatePolicies��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����CertificatePolicies��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_CertificatePolicies NETCAAPI netca_cert_ext_tocertpolicies(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_todigestinfolist
 *			��ȡ��չֵ��DigestInfoList��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����DigestInfoList��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_DigestInfoList NETCAAPI netca_cert_ext_todigestinfolist(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toutf8string
 *			��ȡ��չֵ��UTF8String��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����UTF8String��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toutf8string(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toia5string
 *			��ȡ��չֵ��IA5String��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����IA5String��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toia5string(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toprintablestring
 *			��ȡ��չֵ��PrintableString��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����PrintableString��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_toprintablestring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tovisiblestring
 *			��ȡ��չֵ��VisibleString��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����VisibleString��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_tovisiblestring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_tobmpstring
 *			��ȡ��չֵ��BMPString��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����BMPString��ֵ��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ext_tobmpstring(NETCA_CERT_Extension ext);
/*
 *		netca_cert_ext_toidentificationitems
 *			��ȡ��չֵ��IdentificationItems��ֵ
 *		������
 *			ext����չ
 *		����ֵ��
 *			�ɹ�����IdentificationItems��ֵ��ʧ�ܷ���NULL
 */
NETCA_CERT_IdentificationItems NETCAAPI netca_cert_ext_toidentificationitems(NETCA_CERT_Extension ext);

/*
 *		netca_cert_generalnames_free
 *			�ͷ�GeneralNames
 *		������
 *			gns��GeneralNames
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_generalnames_free(NETCA_CERT_GeneralNames gns);

/*
 *		netca_cert_generalnames_getitemcount
 *			��ȡGeneralNames������
 *		������
 *			gns��GeneralNames
 *		����ֵ��
 *			�ɹ�����GeneralNames��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_generalnames_getitemcount(NETCA_CERT_GeneralNames gns);
/*
 *		netca_cert_generalnames_getitem
 *			��ȡGeneralNames����
 *		������
 *			gns��GeneralNames
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����GeneralNames�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalnames_getitem(NETCA_CERT_GeneralNames gns,int index);
/*
 *		netca_cert_generalnames_dup
 *			����GeneralNames
 *		������
 *			gns��GeneralNames
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�GeneralNames��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_generalnames_dup(NETCA_CERT_GeneralNames gns);

/*
 *		netca_cert_generalname_free
 *			�ͷ�GeneralName
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_generalname_free(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_gettype
 *			��ȡGeneralName������
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName�����ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_generalname_gettype(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_dup
 *			����GeneralName
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�GeneralName��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalname_dup(NETCA_CERT_GeneralName gn);

/*
 *		netca_cert_generalname_getothername
 *			���GeneralName��OtherName
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��OtherName��ʧ�ܷ���NULL
 */
NETCA_CERT_OtherName NETCAAPI netca_cert_generalname_getothername(NETCA_CERT_GeneralName gn);

/*
 *		netca_cert_generalname_getrfc822name
 *			���GeneralName��email
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��email��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_getrfc822name(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getdnsname
 *			���GeneralName������
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��������ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_getdnsname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getdirname
 *			���GeneralName��Ŀ¼��
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��Ŀ¼����ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_cert_generalname_getdirname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getediname
 *			���GeneralName��EDIPartyName
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��EDIPartyName��ʧ�ܷ���NULL
 */
NETCA_CERT_EDIPartyName NETCAAPI netca_cert_generalname_getediname(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			���GeneralName��URI
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��URI��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_generalname_geturi(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			���GeneralName��IP
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��IP��ʧ�ܷ���NULL
 */
char *NETCAAPI netca_cert_generalname_getip(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_geturi
 *			���GeneralName��ע��ID
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName��ע��ID��ʧ�ܷ���NULL
 */
char *NETCAAPI netca_cert_generalname_getregid(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_getencode
 *			��ȡGeneralName�ı���
 *		������
 *			gn��GeneralName
 *		����ֵ��
 *			�ɹ�����GeneralName�ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_generalname_getencode(NETCA_CERT_GeneralName gn);
/*
 *		netca_cert_generalname_equals
 *			�ж�����GeneralName���Ƿ����
 *		������
 *			gn1��GeneralName1
 *			gn2��GeneralName2
 *		����ֵ��
 *			�������GeneralName��ȷ���1�����򷵻�0
 */
int NETCAAPI netca_cert_generalname_equals(NETCA_CERT_GeneralName gn1,NETCA_CERT_GeneralName gn2);

/*
 *		netca_cert_ediparyname_free
 *			�ͷ�EDIPartyName
 *		������
 *			edi��EDIPartyName
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_ediparyname_free(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_dup
 *			����EDIPartyName
 *		������
 *			edi��EDIPartyName
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�EDIPartyName��ʧ�ܷ���NULL
 */
NETCA_CERT_EDIPartyName NETCAAPI netca_cert_ediparyname_dup(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_getnameassigner
 *			��ȡEDIPartyName��Assigner
 *		������
 *			edi��EDIPartyName
 *		����ֵ��
 *			�ɹ�����EDIPartyName��Assigner��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ediparyname_getnameassigner(NETCA_CERT_EDIPartyName edi);
/*
 *		netca_cert_ediparyname_getpartyname
 *			��ȡEDIPartyName��partyname
 *		������
 *			edi��EDIPartyName
 *		����ֵ��
 *			�ɹ�����EDIPartyName��partyname��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_ediparyname_getpartyname(NETCA_CERT_EDIPartyName edi);

/*
 *		netca_cert_othername_free
 *			�ͷ�OtherName
 *		������
 *			othername��OtherName
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_othername_free(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_dup
 *			����OtherName
 *		������
 *			othername��OtherName
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�OtherName��ʧ�ܷ���NULL
 */
NETCA_CERT_OtherName NETCAAPI netca_cert_othername_dup(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_gettype
 *			��ȡOtherName��OID
 *		������
 *			othername��OtherName
 *		����ֵ��
 *			�ɹ�����OtherName��OID��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_othername_gettype(NETCA_CERT_OtherName othername);
/*
 *		netca_cert_othername_getvalue
 *			��ȡOtherName��ֵ�ı���ֵ
 *		������
 *			othername��OtherName
 *		����ֵ��
 *			�ɹ�����OtherName��ֵ�ı���ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_othername_getvalue(NETCA_CERT_OtherName othername);

/*
 *		netca_cert_akid_free
 *			�ͷ�AKID
 *		������
 *			akid��AKID
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_akid_free(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getkeyid
 *			��ȡAKID����Կ��ʶ
 *		������
 *			akid��AKID
 *		����ֵ��
 *			�ɹ�����AKID����Կ��ʶ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_akid_getkeyid(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getissuerissuername
 *			��ȡAKID�İ䷢�ߵİ䷢����
 *		������
 *			akid��AKID
 *		����ֵ��
 *			�ɹ�����AKID�İ䷢�ߵİ䷢������ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_akid_getissuerissuername(NETCA_CERT_AKID akid);
/*
 *		netca_cert_akid_getissuercertsn
 *			��ȡAKID�İ䷢��֤������к�
 *		������
 *			akid��AKID
 *		����ֵ��
 *			�ɹ�����AKID�İ䷢��֤������кţ�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_akid_getissuercertsn(NETCA_CERT_AKID akid);

/*
 *		netca_cert_policymaps_getitemcount
 *			��ȡPolicyMappings������
 *		������
 *			policymaps��PolicyMappings
 *		����ֵ��
 *			�ɹ�����PolicyMappings��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_policymaps_getitemcount(NETCA_CERT_PolicyMappings policymaps);
/*
 *		netca_cert_policymaps_getitem
 *			��ȡPolicyMappings����
 *		������
 *			policymaps��PolicyMappings
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����PolicyMappings�ĵ�index�ʧ�ܷ���-1
 */
NETCA_CERT_PolicyMapping NETCAAPI netca_cert_policymaps_getitem(NETCA_CERT_PolicyMappings policymaps,int index);
/*
 *		netca_cert_policymaps_free
 *			�ͷ�PolicyMappings
 *		������
 *			policymaps��PolicyMappings
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_policymaps_free(NETCA_CERT_PolicyMappings policymaps);

/*
 *		netca_cert_policymap_free
 *			�ͷ�PolicyMapping
 *		������
 *			policymap��PolicyMapping
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_policymap_free(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_dup
 *			����PolicyMapping
 *		������
 *			policymap��PolicyMapping
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�PolicyMapping��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyMapping NETCAAPI netca_cert_policymap_dup(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_getissuerpolicy
 *			��ȡPolicyMapping�İ䷢����Ĳ���
 *		������
 *			policymap��PolicyMapping
 *		����ֵ��
 *			�ɹ�PolicyMapping�İ䷢����Ĳ��ԣ�ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_policymap_getissuerpolicy(NETCA_CERT_PolicyMapping policymap);
/*
 *		netca_cert_policymap_getsubjectpolicy
 *			��ȡPolicyMapping��������Ĳ���
 *		������
 *			policymap��PolicyMapping
 *		����ֵ��
 *			�ɹ�PolicyMapping��������Ĳ��ԣ�ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_policymap_getsubjectpolicy(NETCA_CERT_PolicyMapping policymap);

/*
 *		netca_cert_basicconstraints_free
 *			�ͷ�BasicConstraints
 *		������
 *			bc��BasicConstraints
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_basicconstraints_free(NETCA_CERT_BasicConstraints bc);
/*
 *		netca_cert_basicconstraints_isca
 *			�ж�BasicConstraints�Ƿ�CA
 *		������
 *			bc��BasicConstraints
 *		����ֵ��
 *			���BasicConstraints��iscaΪ�棬�򷵻�1�����򷵻�0
 */
int NETCAAPI netca_cert_basicconstraints_isca(NETCA_CERT_BasicConstraints bc);
/*
 *		netca_cert_basicconstraints_getpathlen
 *			��ȡBasicConstraints��·������
 *		������
 *			bc��BasicConstraints
 *		����ֵ��
 *			�ɹ�����BasicConstraints��·�����ƣ�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_basicconstraints_getpathlen(NETCA_CERT_BasicConstraints bc);

/*
 *		netca_cert_polqualifierinfo_free
 *			�ͷ�PolicyQualifierInfo
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_polqualifierinfo_free(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_dup
 *			����PolicyQualifierInfo
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�PolicyQualifierInfo��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyQualifierInfo NETCAAPI netca_cert_polqualifierinfo_dup(NETCA_CERT_PolicyQualifierInfo pqinfo);

/*
 *		netca_cert_polqualifierinfo_getid
 *			���PolicyQualifierInfo�����͵�OID
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			�ɹ�����PolicyQualifierInfo�����͵�OID��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_polqualifierinfo_getid(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getqualifierencode
 *			���PolicyQualifierInfo��ֵ�ı���
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			�ɹ�����PolicyQualifierInfo��ֵ�ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_polqualifierinfo_getqualifierencode(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getcpsuri
 *			���PolicyQualifierInfo��CPS URI
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			�ɹ�����PolicyQualifierInfo��CPS URI��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_polqualifierinfo_getcpsuri(NETCA_CERT_PolicyQualifierInfo pqinfo);
/*
 *		netca_cert_polqualifierinfo_getusernotice
 *			���PolicyQualifierInfo���û�ͨ��
 *		������
 *			pqinfo��PolicyQualifierInfo
 *		����ֵ��
 *			�ɹ�����PolicyQualifierInfo���û�ͨ�棬ʧ�ܷ���NULL
 */
NETCA_CERT_UserNotice NETCAAPI netca_cert_polqualifierinfo_getusernotice(NETCA_CERT_PolicyQualifierInfo pqinfo);

/*
 *		netca_cert_policyinfo_free
 *			�ͷ�PolicyInformation
 *		������
 *			polinfo��PolicyInformation
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_policyinfo_free(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_dup
 *			����PolicyInformation
 *		������
 *			polinfo��PolicyInformation
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�PolicyInformation��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_cert_policyinfo_dup(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getid
 *			��ȡPolicyInformation�����͵�OID
 *		������
 *			polinfo��PolicyInformation
 *		����ֵ��
 *			�ɹ�����PolicyInformation�����͵�OID��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_policyinfo_getid(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_hasqualifier
 *			�ж�PolicyInformation�Ƿ���qualifier
 *		������
 *			polinfo��PolicyInformation
 *		����ֵ��
 *			���PolicyInformation��qualifier������1�����򷵻�0
 */
int NETCAAPI netca_cert_policyinfo_hasqualifier(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getqualifiercount
 *			��ȡPolicyInformation��qualifier����
 *		������
 *			polinfo��PolicyInformation
 *		����ֵ��
 *			�ɹ�����PolicyInformation��qualifier������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_policyinfo_getqualifiercount(NETCA_CERT_PolicyInformation polinfo);
/*
 *		netca_cert_policyinfo_getqualifier
 *			��ȡPolicyInformation��qualifier
 *		������
 *			polinfo��PolicyInformation
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����PolicyInformation�ĵ�index��qualifier��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyQualifierInfo NETCAAPI netca_cert_policyinfo_getqualifier(NETCA_CERT_PolicyInformation polinfo,int index);

/*
 *		netca_cert_certpolicies_free
 *			�ͷ�CertificatePolicies
 *		������
 *			certpols��CertificatePolicies
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_certpolicies_free(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_dup
 *			����CertificatePolicies
 *		������
 *			certpols��CertificatePolicies
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�CertificatePolicies��ʧ�ܷ���NULL
 */
NETCA_CERT_CertificatePolicies NETCAAPI netca_cert_certpolicies_dup(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_getitemcount
 *			��ȡCertificatePolicies������
 *		������
 *			certpols��CertificatePolicies
 *		����ֵ��
 *			�ɹ�����CertificatePolicies��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_certpolicies_getitemcount(NETCA_CERT_CertificatePolicies certpols);
/*
 *		netca_cert_certpolicies_getitem
 *			��ȡCertificatePolicies����
 *		������
 *			certpols��CertificatePolicies
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����CertificatePolicies�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_cert_certpolicies_getitem(NETCA_CERT_CertificatePolicies certpols,int index);


/*
 *		netca_cert_usernotice_free
 *			�ͷ�UserNotice
 *		������
 *			usernotice��UserNotice
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_usernotice_free(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getexplicittext
 *			��ȡUserNotice��explicittext
 *		������
 *			usernotice��UserNotice
 *		����ֵ��
 *			�ɹ�����UserNotice��explicittext��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_usernotice_getexplicittext(NETCA_CERT_UserNotice usernotice);

/*
 *		netca_cert_usernotice_getreforg
 *			��ȡUserNotice��reforg
 *		������
 *			usernotice��UserNotice
 *		����ֵ��
 *			�ɹ�����UserNotice��reforg��ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_cert_usernotice_getreforg(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getrefnumberscount
 *			��ȡUserNotice��refnumber�ĸ���
 *		������
 *			usernotice��UserNotice
 *		����ֵ��
 *			�ɹ�����UserNotice��refnumber�ĸ�����ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_usernotice_getrefnumberscount(NETCA_CERT_UserNotice usernotice);
/*
 *		netca_cert_usernotice_getrefnumber
 *			��ȡUserNotice��refnumber
 *		������
 *			usernotice��UserNotice
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����UserNotice�ĵ�index��refnumber��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_usernotice_getrefnumber(NETCA_CERT_UserNotice usernotice,int index);

/*
 *		netca_cert_attributes_free
 *			�ͷ�Attributes
 *		������
 *			attrs��Attributes
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_attributes_free(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_dup
 *			����Attributes
 *		������
 *			attrs��Attributes
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�Attributes��ʧ�ܷ���NULL
 */
NETCA_CERT_Attributes NETCAAPI netca_cert_attributes_dup(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_getitemcount
 *			��ȡAttributes�����Ը���
 *		������
 *			attrs��Attributes
 *		����ֵ��
 *			�ɹ�����Attributes�����Ը�����ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_attributes_getitemcount(NETCA_CERT_Attributes attrs);
/*
 *		netca_cert_attributes_getitem
 *			��ȡAttributes������
 *		������
 *			attrs��Attributes
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����Attributes�ĵ�index�����ԣ�ʧ�ܷ���NULL
 */
NETCA_CERT_Attribute NETCAAPI netca_cert_attributes_getitem(NETCA_CERT_Attributes attrs,int index);

/*
 *		netca_cert_attribute_free
 *			�ͷ�����
 *		������
 *			attr������
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_attribute_free(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_dup
 *			��������
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ����ظ��Ƶ����ԣ�ʧ�ܷ���NULL
 */
NETCA_CERT_Attribute NETCAAPI  netca_cert_attribute_dup(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_gettype
 *			��ȡ���Ե�����OID
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ��������Ե�����OID��ʧ�ܷ���NULL
 */
char *NETCAAPI  netca_cert_attribute_gettype(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_getvaluescount
 *			��ȡ���Ե�ֵ�ĸ���
 *		������
 *			attr������
 *		����ֵ��
 *			�ɹ��������Ե�ֵ�ĸ�����ʧ�ܷ���-1
 */
int NETCAAPI  netca_cert_attribute_getvaluescount(NETCA_CERT_Attribute attr);
/*
 *		netca_cert_attribute_getvaluescount
 *			��ȡ���Ե�ֵ�ı���
 *		������
 *			attr������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ��������Եĵ�index��ֵ�ı��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI  netca_cert_attribute_getvalue(NETCA_CERT_Attribute attr,int index);

/*
 *		netca_cert_generalsubtree_free
 *			�ͷ�GeneralSubtree
 *		������
 *			subtree��GeneralSubtree
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_generalsubtree_free(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_dup
 *			����GeneralSubtree
 *		������
 *			subtree��GeneralSubtree
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�GeneralSubtree��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralSubtree NETCAAPI  netca_cert_generalsubtree_dup(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getbase
 *			��ȡGeneralSubtree��base
 *		������
 *			subtree��GeneralSubtree
 *		����ֵ��
 *			�ɹ�����GeneralSubtree��base��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_generalsubtree_getbase(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getmin
 *			��ȡGeneralSubtree��min
 *		������
 *			subtree��GeneralSubtree
 *		����ֵ��
 *			�ɹ�����GeneralSubtree��min��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_generalsubtree_getmin(NETCA_CERT_GeneralSubtree subtree);
/*
 *		netca_cert_generalsubtree_getmax
 *			��ȡGeneralSubtree��max
 *		������
 *			subtree��GeneralSubtree
 *		����ֵ��
 *			�ɹ�����GeneralSubtree��max��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_generalsubtree_getmax(NETCA_CERT_GeneralSubtree subtree);

/*
 *		netca_cert_generalsubtrees_free
 *			�ͷ�GeneralSubtrees
 *		������
 *			subtrees��GeneralSubtrees
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_generalsubtrees_free(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_dup
 *			����GeneralSubtrees
 *		������
 *			subtrees��GeneralSubtrees
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�GeneralSubtrees��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_generalsubtrees_dup(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_getitemcount
 *			��ȡGeneralSubtrees������
 *		������
 *			subtrees��GeneralSubtrees
 *		����ֵ��
 *			�ɹ�����GeneralSubtrees��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_generalsubtrees_getitemcount(NETCA_CERT_GeneralSubtrees subtrees);
/*
 *		netca_cert_generalsubtrees_getitemcount
 *			��ȡGeneralSubtrees����
 *		������
 *			subtrees��GeneralSubtrees
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����GeneralSubtrees�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralSubtree NETCAAPI netca_cert_generalsubtrees_getitem(NETCA_CERT_GeneralSubtrees subtrees,int index);

/*
 *		netca_cert_nameconstraints_free
 *			�ͷ�����Լ��
 *		������
 *			nameconstraints������Լ��
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_nameconstraints_free(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_dup
 *			��������Լ��
 *		������
 *			nameconstraints������Լ��
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�����Լ����ʧ�ܷ���NULL
 */
NETCA_CERT_NameConstraints NETCAAPI netca_cert_nameconstraints_dup(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_getpremit
 *			��ȡ����Լ����������
 *		������
 *			nameconstraints������Լ��
 *		����ֵ��
 *			�ɹ���������Լ���������ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_nameconstraints_getpremit(NETCA_CERT_NameConstraints nameconstraints);
/*
 *		netca_cert_nameconstraints_getexclude
 *			��ȡ����Լ���Ľ�ֹ��
 *		������
 *			nameconstraints������Լ��
 *		����ֵ��
 *			�ɹ���������Լ���Ľ�ֹ�ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralSubtrees NETCAAPI netca_cert_nameconstraints_getexclude(NETCA_CERT_NameConstraints nameconstraints);

/*
 *		netca_cert_policyconstraints_free
 *			�ͷŲ���Լ��
 *		������
 *			policyconstraints������Լ��
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_policyconstraints_free(NETCA_CERT_PolicyConstraints policyconstraints);
/*
 *		netca_cert_policyconstraints_getreqexppolicy
 *			��ȡ����Լ����reqexppolicy
 *		������
 *			policyconstraints������Լ��
 *		����ֵ��
 *			�ɹ���������Լ����reqexppolicy��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_policyconstraints_getreqexppolicy(NETCA_CERT_PolicyConstraints policyconstraints);
/*
 *		netca_cert_policyconstraints_getinhibtpolicymapping
 *			��ȡ����Լ����inhibtpolicymapping
 *		������
 *			policyconstraints������Լ��
 *		����ֵ��
 *			�ɹ���������Լ����inhibtpolicymapping��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_cert_policyconstraints_getinhibtpolicymapping(NETCA_CERT_PolicyConstraints policyconstraints);

/*
 *		netca_cert_extkeyusage_free
 *			�ͷ���չ��Կ�÷�
 *		������
 *			extkeyusage����չ��Կ�÷�
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_extkeyusage_free(NETCA_CERT_ExtKeyUsage extkeyusage);
/*
 *		netca_cert_extkeyusage_getitemcount
 *			��ȡ��չ��Կ�÷�������
 *		������
 *			extkeyusage����չ��Կ�÷�
 *		����ֵ��
 *			�ɹ�������չ��Կ�÷���������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_extkeyusage_getitemcount(NETCA_CERT_ExtKeyUsage extkeyusage);
/*
 *		netca_cert_extkeyusage_getitemcount
 *			��ȡ��չ��Կ�÷�����
 *		������
 *			extkeyusage����չ��Կ�÷�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�������չ��Կ�÷��ĵ�index������ʧ�ܷ���NULL
 */
char *NETCAAPI netca_cert_extkeyusage_getitem(NETCA_CERT_ExtKeyUsage extkeyusage,int index);

/*
 *		netca_cert_dpname_free
 *			�ͷŷֲ�����
 *		������
 *			dpname���ֲ�����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_dpname_free(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_gettype
 *			��ȡ�ֲ�����������
 *		������
 *			dpname���ֲ�����
 *		����ֵ��
 *			�ɹ����طֲ����������ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_dpname_gettype(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_dup
 *			���Ʒֲ�����
 *		������
 *			dpname���ֲ�����
 *		����ֵ��
 *			�ɹ����ظ��Ƶķֲ�������ʧ�ܷ���NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_dpname_dup(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_getfullname
 *			��ȡ�ֲ�������ȫ��
 *		������
 *			dpname���ֲ�����
 *		����ֵ��
 *			�ɹ����طֲ�������ȫ����ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_dpname_getfullname(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_getrelname
 *			��ȡ�ֲ������������
 *		������
 *			dpname���ֲ�����
 *		����ֵ��
 *			�ɹ����طֲ��������������ʧ�ܷ���NULL
 */
NETCA_CERT_X500_RDN NETCAAPI netca_cert_dpname_getrelname(NETCA_CERT_DistributionPointName dpname);
/*
 *		netca_cert_dpname_equals
 *			�жϷֲ������Ƿ����
 *		������
 *			dpname1���ֲ�����1
 *			dpname2���ֲ�����2
 *		����ֵ��
 *			��������ֲ�������ȣ�����1�����򷵻�0
 */
int NETCAAPI netca_cert_dpname_equals(NETCA_CERT_DistributionPointName dpname1,NETCA_CERT_DistributionPointName dpname2);

/*
 *		netca_cert_distpoint_free
 *			�ͷŷֲ�����
 *		������
 *			dp���ֲ���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_distpoint_free(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_dup
 *			���Ʒֲ���
 *		������
 *			dp���ֲ���
 *		����ֵ��
 *			�ɹ����ظ��Ƶķֲ��㣬ʧ�ܷ���NULL
 */
NETCA_CERT_DistributionPoint NETCAAPI netca_cert_distpoint_dup(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getdpname
 *			��ȡ�ֲ���ķֲ�����
 *		������
 *			dp���ֲ���
 *		����ֵ��
 *			�ɹ����طֲ���ķֲ�������ʧ�ܷ���NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_distpoint_getdpname(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getreasons
 *			��ȡ�ֲ����reasons
 *		������
 *			dp���ֲ���
 *		����ֵ��
 *			�ɹ����طֲ����reasons��ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_cert_distpoint_getreasons(NETCA_CERT_DistributionPoint dp);
/*
 *		netca_cert_distpoint_getcrlissuer
 *			��ȡ�ֲ����CRL�䷢��
 *		������
 *			dp���ֲ���
 *		����ֵ��
 *			�ɹ����طֲ����CRL�䷢�ߣ�ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralNames NETCAAPI netca_cert_distpoint_getcrlissuer(NETCA_CERT_DistributionPoint dp);

/*
 *		netca_cert_crldps_free
 *			�ͷ�CRLDistributionPoints
 *		������
 *			crldps��CRLDistributionPoints
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_crldps_free(NETCA_CERT_CRLDistributionPoints crldps);
/*
 *		netca_cert_crldps_getitemcount
 *			��ȡCRLDistributionPoints������
 *		������
 *			crldps��CRLDistributionPoints
 *		����ֵ��
 *			�ɹ�����CRLDistributionPoints��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_crldps_getitemcount(NETCA_CERT_CRLDistributionPoints crldps);
/*
 *		netca_cert_crldps_getitem
 *			��ȡCRLDistributionPoints����
 *		������
 *			crldps��CRLDistributionPoints
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����CRLDistributionPoints�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_DistributionPoint NETCAAPI netca_cert_crldps_getitem(NETCA_CERT_CRLDistributionPoints crldps,int index);

/*
 *		netca_cert_accessdescs_free
 *			�ͷ�AccessDescriptions
 *		������
 *			accessdescs��AccessDescriptions
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_accessdescs_free(NETCA_CERT_AccessDescriptions accessdescs);
/*
 *		netca_cert_accessdescs_getitemcount
 *			��ȡAccessDescriptions������
 *		������
 *			accessdescs��AccessDescriptions
 *		����ֵ��
 *			�ɹ�����AccessDescriptions��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_accessdescs_getitemcount(NETCA_CERT_AccessDescriptions accessdescs);
/*
 *		netca_cert_accessdescs_getitem
 *			��ȡAccessDescriptions����
 *		������
 *			accessdescs��AccessDescriptions
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����AccessDescriptions�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_AccessDescription NETCAAPI netca_cert_accessdescs_getitem(NETCA_CERT_AccessDescriptions accessdescs,int index);

/*
 *		netca_cert_accessdesc_free
 *			�ͷ�AccessDescription
 *		������
 *			accessdesc��AccessDescription
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_accessdesc_free(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_dup
 *			����AccessDescription
 *		������
 *			accessdesc��AccessDescription
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�AccessDescription��ʧ�ܷ���NULL
 */
NETCA_CERT_AccessDescription NETCAAPI netca_cert_accessdesc_dup(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_getmethod
 *			��ȡAccessDescription��method
 *		������
 *			accessdesc��AccessDescription
 *		����ֵ��
 *			�ɹ�����AccessDescription��method��ʧ�ܷ���NULL
 */
char * NETCAAPI netca_cert_accessdesc_getmethod(NETCA_CERT_AccessDescription accessdesc);
/*
 *		netca_cert_accessdesc_getlocation
 *			��ȡAccessDescription��location
 *		������
 *			accessdesc��AccessDescription
 *		����ֵ��
 *			�ɹ�����AccessDescription��location��ʧ�ܷ���NULL
 */
NETCA_CERT_GeneralName NETCAAPI netca_cert_accessdesc_getlocation(NETCA_CERT_AccessDescription accessdesc);

/*
 *		netca_cert_idp_free
 *			�ͷ�IssuingDistributionPoint
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_idp_free(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_getdpname
 *			��ȡIssuingDistributionPoint�ķֲ�����
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			�ɹ�����IssuingDistributionPoint�ķֲ�������ʧ�ܷ���NULL
 */
NETCA_CERT_DistributionPointName NETCAAPI netca_cert_idp_getdpname(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainsusercerts
 *			�ж�IssuingDistributionPoint���Ƿ�ֻ�����û�֤��
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			���IssuingDistributionPoint��ֻ�����û�֤�飬����1�����򷵻�0
 */
int NETCAAPI netca_cert_idp_isonlycontainsusercerts(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainscacerts
 *			�ж�IssuingDistributionPoint���Ƿ�ֻ����CA֤��
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			���IssuingDistributionPoint��ֻ����CA֤�飬����1�����򷵻�0
 */
int NETCAAPI netca_cert_idp_isonlycontainscacerts(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_getconverreasons
 *			��ȡIssuingDistributionPoint�ĸ��ǵ�����ԭ��
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			�ɹ�����IssuingDistributionPoint�ĸ��ǵ�����ԭ��ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_cert_idp_getconverreasons(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isindirectcrl
 *			��ȡIssuingDistributionPoint���Ƿ��Ǽ��CRL
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			���IssuingDistributionPoint�Ǽ��CRL������1�����򷵻�0
 */
int NETCAAPI netca_cert_idp_isindirectcrl(NETCA_CERT_IssuingDistributionPoint idp);
/*
 *		netca_cert_idp_isonlycontainsattrcerts
 *			��ȡIssuingDistributionPoint���Ƿ�ֻ��������֤��
 *		������
 *			idp��IssuingDistributionPoint
 *		����ֵ��
 *			���IssuingDistributionPointֻ��������֤�飬����1�����򷵻�0
 */
int NETCAAPI netca_cert_idp_isonlycontainsattrcerts(NETCA_CERT_IssuingDistributionPoint idp);

/*
 *		netca_cert_privkeyusageperiod_free
 *			�ͷ�˽Կ��Ч��
 *		������
 *			privkeyusageperiod��˽Կ��Ч��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_privkeyusageperiod_free(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);
/*
 *		netca_cert_privkeyusageperiod_getnotbefore
 *			��ȡ˽Կ��Ч�ڵ�notbefore
 *		������
 *			privkeyusageperiod��˽Կ��Ч��
 *		����ֵ��
 *			�ɹ�����˽Կ��Ч�ڵ�notbefore��ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_cert_privkeyusageperiod_getnotbefore(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);
/*
 *		netca_cert_privkeyusageperiod_getnotafter
 *			��ȡ˽Կ��Ч�ڵ�notafter
 *		������
 *			privkeyusageperiod��˽Կ��Ч��
 *		����ֵ��
 *			�ɹ�����˽Կ��Ч�ڵ�notafter��ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_cert_privkeyusageperiod_getnotafter(NETCA_CERT_PrivateKeyUsagePeriod privkeyusageperiod);


/*
 *		netca_cert_identificationitems_free
 *			�ͷ�IdentificationItems
 *		������
 *			items��IdentificationItems
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_identificationitems_free(NETCA_CERT_IdentificationItems items);

/*
 *		netca_cert_identificationitems_getitemcount
 *			��ȡIdentificationItem������
 *		������
 *			items��IdentificationItems
 *		����ֵ��
 *			�ɹ�����IdentificationItems��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_identificationitems_getitemcount(NETCA_CERT_IdentificationItems items);
/*
 *		netca_cert_identificationitems_getitem
 *			��ȡIdentificationItems����
 *		������
 *			items��IdentificationItems
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����IdentificationItems�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CERT_IdentificationItem NETCAAPI netca_cert_identificationitems_getitem(NETCA_CERT_IdentificationItems items,int index);

/*
 *		netca_cert_identificationitem_free
 *			�ͷ�IdentificationItem
 *		������
 *			item��IdentificationItem
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_identificationitem_free(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_gettype
 *			��ȡIdentificationItem������
 *		������
 *			item��IdentificationItem
 *		����ֵ��
 *			�ɹ�����IdentificationItem�����ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_identificationitem_gettype(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_getencode
 *			��ȡIdentificationItem�ı��뷽ʽ
 *		������
 *			item��IdentificationItem
 *		����ֵ��
 *			�ɹ�����IdentificationItem�ı��뷽ʽ��ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_identificationitem_getencode(NETCA_CERT_IdentificationItem item);

/*
 *		netca_cert_identificationitem_getencode
 *			��ȡIdentificationItem��ֵ
 *		������
 *			item��IdentificationItem
 *		����ֵ��
 *			�ɹ�����IdentificationItem��ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_identificationitem_getvalue(NETCA_CERT_IdentificationItem item);

enum{
	NETCA_CRL_V1=0,
	NETCA_CRL_V2=1,
};

enum{
	NETCA_CRL_VERIFY_UNDETERMINED			=-1,
	NETCA_CRL_VERIFY_UNREVOKED			=0,
	NETCA_CRL_VERIFY_REVOKED			=1,
	NETCA_CRL_VERIFY_BADCERT			=2,
	NETCA_CRL_VERIFY_BADCRL				=3,
	NETCA_CRL_VERIFY_CRLDISMATCH			=4,
	NETCA_CRL_VERIFY_UNKNOWN_CRITICAL_CRL_EXT	=5,
	NETCA_CRL_VERIFY_UNKNOWN_CRITICAL_CRLENTRY_EXT	=6,
	NETCA_CRL_VERIFY_TWOCRLDISMATCH			=7,
	NETCA_CRL_VERIFY_BADCRLENTRY			=8,
};

enum{
	NETCA_CRLREASON_UNSPECIFIED			=0,
	NETCA_CRLREASON_KEYCOMPROMISE			=1,
	NETCA_CRLREASON_CACOMPROMISE			=2,
	NETCA_CRLREASON_AFFILIATIONCHANGED		=3,
	NETCA_CRLREASON_SUPERSEDED			=4,
	NETCA_CRLREASON_CESSATIONOFOPERTION		=5,
	NETCA_CRLREASON_CERTIFICATEHOLD			=6,
	NETCA_CRLREASON_REMOVEFROMCRL			=8,
	NETCA_CRLREASON_PRIVILEGEWITHDRAWN		=9,
	NETCA_CRLREASON_AACOMPROMISE			=10,
};

/*
 *		netca_crl_new
 *			����CRL
 *		������
 *			data�����������CRL�ı���
 *			datalen:���������CRL�ı���ĳ���
 *			errctx:����������
 *		����ֵ��
 *			�ɹ�����CRL��ʧ�ܷ���NULL
 */
NETCA_CRL NETCAAPI netca_crl_new(const unsigned char *data,long datalen,NETCA_ERR_CTX errctx);
/*
 *		netca_crl_free
 *			�ͷ�CRL
 *		������
 *			crl��CRL
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crl_free(NETCA_CRL crl);
/*
 *		netca_crl_dup
 *			����CRL
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�CRL��ʧ�ܷ���NULL
 */
NETCA_CRL NETCAAPI netca_crl_dup(NETCA_CRL crl);
/*
 *		netca_crl_getversion
 *			��ȡCRL�İ汾��
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL�İ汾�ţ�ʧ�ܷ���-1
 */
int NETCAAPI netca_crl_getversion(NETCA_CRL crl);
/*
 *		netca_crl_getsignalgorithm
 *			��ȡCRL��ǩ���㷨
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��ǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getsignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getinnersignalgorithm
 *			��ȡCRL���ڲ�ǩ���㷨
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL���ڲ�ǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getinnersignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getoutersignalgorithm
 *			��ȡCRL���ⲿǩ���㷨
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL���ⲿǩ���㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_crl_getoutersignalgorithm(NETCA_CRL crl);

/*
 *		netca_crl_getissuer
 *			��ȡCRL�İ䷢��
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL�İ䷢�ߣ�ʧ�ܷ���NULL
 */
NETCA_CERT_X500_DN NETCAAPI netca_crl_getissuer(NETCA_CRL crl);
/*
 *		netca_crl_getthisupdate
 *			��ȡCRL��thisupdate
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��thisupdate��ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_crl_getthisupdate(NETCA_CRL crl);
/*
 *		netca_crl_getnextupdate
 *			��ȡCRL��nextupdate
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��nextupdate��ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_crl_getnextupdate(NETCA_CRL crl);
/*
 *		netca_crl_hasnextupdate
 *			�ж�CRL�Ƿ���nextupdate
 *		������
 *			crl��CRL
 *		����ֵ��
 *			���CRL��nextupdate����1�����򷵻�0
 */
int NETCAAPI netca_crl_hasnextupdate(NETCA_CRL crl);
/*
 *		netca_crl_hasexts
 *			�ж�CRL�Ƿ�����չ
 *		������
 *			crl��CRL
 *		����ֵ��
 *			���CRL����չ����1�����򷵻�0
 */
int NETCAAPI netca_crl_hasexts(NETCA_CRL crl);
/*
 *		netca_crl_getexts
 *			��ȡCRL����չ
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL����չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_crl_getexts(NETCA_CRL crl);
/*
 *		netca_crl_getsignvalue
 *			��ȡCRL��ǩ��ֵ
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��ǩ��ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_getsignvalue(NETCA_CRL crl);

/*
 *		netca_crl_getsignvalueunusedbits
 *			��ȡCRL��ǩ��ֵ��δʹ��λ��
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��ǩ��ֵ��δʹ��λ����ʧ�ܷ���-1
 */
int NETCAAPI netca_crl_getsignvalueunusedbits(NETCA_CRL crl);

/*
 *		netca_crl_hasrevokedcertlist
 *			�ж�CRL�Ƿ�������֤���б�
 *		������
 *			crl��CRL
 *		����ֵ��
 *			���CRL������֤���б���1�����򷵻�0
 */
int NETCAAPI netca_crl_hasrevokedcertlist(NETCA_CRL crl);
/*
 *		netca_crl_getrevokedcertlist
 *			��ȡCRL������֤���б�
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL������֤���б�ʧ�ܷ���NULL
 */
NETCA_CRL_RevokedCertList NETCAAPI netca_crl_getrevokedcertlist(NETCA_CRL crl);
/*
 *		netca_crl_ismatchdcrl
 *			�ж�CRL��delta CRL�Ƿ�ƥ��
 *		������
 *			crl��CRL
 *			dcrl��delta CRL
 *		����ֵ��
 *			���CRL��delta CRLƥ�䷵��1�����򷵻�0
 */
int NETCAAPI netca_crl_ismatchdcrl(NETCA_CRL crl,NETCA_CRL dcrl);
/*
 *		netca_crl_isdcrl
 *			�ж�CRL�Ƿ�delta CRL
 *		������
 *			dcrl��delta CRL
 *		����ֵ��
 *			���dcrl��delta CRL����1�����򷵻�0
 */
int NETCAAPI netca_crl_isdcrl(NETCA_CRL dcrl);
/*
 *		netca_crl_encode
 *			��ȡCRL��DER����
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��DER���룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_encode(NETCA_CRL crl);
/*
 *		netca_crl_gettbs
 *			��ȡCRL��Ҫǩ�����ֵı���ֵ
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL��Ҫǩ�����ֵı���ֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_crl_gettbs(NETCA_CRL crl);
/*
 *		netca_crl_verifycert
 *			ʹ��CRL����֤֤���Ƿ�����
 *		������
 *			crl��CRL
 *			dcrl��delta CRL����ΪNULL
 *			cert:֤��
 *			revtime��������������ص�����ʱ��
 *			revreason��������������ص�����ԭ��
 *			reasonscope��������������ص�CRL���ǵ�����ԭ��Χ
 *		����ֵ��
 *			δ���Ϸ���NETCA_CRL_VERIFY_UNREVOKED�����Ϸ���NETCA_CRL_VERIFY_REVOKED������ȷ������NETCA_CRL_VERIFY_UNDETERMINED
 */
int NETCAAPI netca_crl_verifycert(NETCA_CRL crl,NETCA_CRL dcrl,NETCA_CERT cert,NETCA_Time *revtime,int *revreason,long *reasonscope);
/*
 *		netca_crl_isinvalidity
 *			�ж�CRL�Ƿ�����Ч����
 *		������
 *			crl��CRL
 *			t��ʱ��
 *		����ֵ��
 *			�����ʱ��t��CRL����Ч���ڣ�����1�����򷵻�0
 */
int NETCAAPI netca_crl_isinvalidity(NETCA_CRL crl,NETCA_Time t);
/*
 *		netca_crl_getissuerdisplayname
 *			��ȡCRL�İ䷢�ߵ���ʾ��
 *		������
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����CRL�İ䷢�ߵ���ʾ����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_crl_getissuerdisplayname(NETCA_CRL crl);

/*
 *		netca_crl_revokedcert_dup
 *			����CRL������֤����Ŀ
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�CRL������֤����Ŀ��ʧ�ܷ���NULL
 */
NETCA_CRL_RevokedCert NETCAAPI netca_crl_revokedcert_dup(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_free
 *			�ͷ�CRL������֤����Ŀ
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crl_revokedcert_free(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getserialnumber
 *			��ȡCRL������֤����Ŀ�����к�
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			�ɹ�����CRL������֤����Ŀ�����кţ�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crl_revokedcert_getserialnumber(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getrevdate
 *			��ȡCRL������֤����Ŀ������ʱ��
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			�ɹ�����CRL������֤����Ŀ������ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_crl_revokedcert_getrevdate(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_hasexts
 *			�ж�CRL������֤����Ŀ�Ƿ�����չ
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			���CRL������֤����Ŀ����չ����1�����򷵻�0
 */
int NETCAAPI netca_crl_revokedcert_hasexts(NETCA_CRL_RevokedCert cert);
/*
 *		netca_crl_revokedcert_getexts
 *			��ȡCRL������֤����Ŀ����չ
 *		������
 *			cert��CRL������֤����Ŀ
 *		����ֵ��
 *			�ɹ�����CRL������֤����Ŀ����չ��ʧ�ܷ���NULL
 */
NETCA_CERT_Extensions NETCAAPI netca_crl_revokedcert_getexts(NETCA_CRL_RevokedCert cert);

/*
 *		netca_crl_revokedcertlist_free
 *			�ͷ�CRL������֤���б�
 *		������
 *			certlist��CRL������֤���б�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crl_revokedcertlist_free(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_dup
 *			����CRL������֤���б�
 *		������
 *			certlist��CRL������֤���б�
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�CRL������֤���б�ʧ�ܷ���NULL
 */
NETCA_CRL_RevokedCertList NETCAAPI netca_crl_revokedcertlist_dup(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_getitemcount
 *			��ȡCRL������֤���б������
 *		������
 *			certlist��CRL������֤���б�
 *		����ֵ��
 *			�ɹ�����CRL������֤���б��������ʧ�ܷ���-1
 */
int NETCAAPI netca_crl_revokedcertlist_getitemcount(NETCA_CRL_RevokedCertList certlist);
/*
 *		netca_crl_revokedcertlist_getitem
 *			��ȡCRL������֤���б����
 *		������
 *			certlist��CRL������֤���б�
 *			index:�������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����CRL������֤���б�ĵ�index�ʧ�ܷ���NULL
 */
NETCA_CRL_RevokedCert NETCAAPI netca_crl_revokedcertlist_getitem(NETCA_CRL_RevokedCertList certlist,int index);

/*
 *		netca_cert_digestinfo_free
 *			�ͷ�DigestInfo
 *		������
 *			hash��DigestInfo
 *		����ֵ��
 *			��
 */
void NETCAAPI  netca_cert_digestinfo_free(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_dup
 *			����DigestInfo
 *		������
 *			hash��DigestInfo
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�DigestInfo��ʧ�ܷ���NULL
 */
NETCA_CERT_DigestInfo NETCAAPI  netca_cert_digestinfo_dup(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_getalgorithm
 *			��ȡDigestInfo��ժҪ�㷨
 *		������
 *			hash��DigestInfo
 *		����ֵ��
 *			�ɹ�����DigestInfo��ժҪ�㷨��ʧ�ܷ���NULL
 */
NETCA_CERT_AlgorithmIdentifier NETCAAPI netca_cert_digestinfo_getalgorithm(NETCA_CERT_DigestInfo hash);
/*
 *		netca_cert_digestinfo_gethashvalue
 *			��ȡDigestInfo��ժҪֵ
 *		������
 *			hash��DigestInfo
 *		����ֵ��
 *			�ɹ�����DigestInfo��ժҪֵ��ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_cert_digestinfo_gethashvalue(NETCA_CERT_DigestInfo hash);

/*
 *		netca_cert_digestinfolist_free
 *			�ͷ�DigestInfo�б�
 *		������
 *			list��DigestInfo�б�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_digestinfolist_free(NETCA_CERT_DigestInfoList list);
/*
 *		netca_cert_digestinfolist_getitemcount
 *			��ȡDigestInfo�б������
 *		������
 *			list��DigestInfo�б�
 *		����ֵ��
 *			�ɹ�����DigestInfo�б��������ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_digestinfolist_getitemcount(NETCA_CERT_DigestInfoList list);
/*
 *		netca_cert_digestinfolist_getitem
 *			��ȡDigestInfo�б����
 *		������
 *			list��DigestInfo�б�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����DigestInfo�б�ĵ�index�ʧ�ܷ���-1
 */
NETCA_CERT_DigestInfo NETCAAPI netca_cert_digestinfolist_getitem(NETCA_CERT_DigestInfoList list,int index);


/*
 *		netca_cert_setattribute
 *			����֤������
 *		������
 *			cert��֤��
 *			type�������������������
 *			value���������������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK,ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_cert_setattribute(NETCA_CERT cert,int type,void *value);
/*
 *		netca_cert_getattribute
 *			��ȡ֤������
 *		������
 *			cert��֤��
 *			type�������������������
 *			value��������������ص�����ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK,ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_cert_getattribute(NETCA_CERT cert,int type,void **value);


enum{
	NETCA_CERT_STORE_TYPE_CURRENTUSER=0,
	NETCA_CERT_STORE_TYPE_LOCALMACHINE=1,
};

#define NETCA_CERT_STORE_NAME_MY	"my"
#define NETCA_CERT_STORE_NAME_OTHERS	"others"
#define NETCA_CERT_STORE_NAME_CA	"ca"
#define NETCA_CERT_STORE_NAME_ROOT	"root"
#define NETCA_CERT_STORE_NAME_DEVICE	"device"



/*
 *		netca_cert_store_open
 *			��֤���
 *		������
 *			type�����������֤��������
 *			name�����������֤��������
 *		����ֵ��
 *			�ɹ�����֤���,ʧ�ܷ���NULL
 */
NETCA_CERT_Store NETCAAPI netca_cert_store_open(int type,const char *name);
/*
 *		netca_cert_store_getcertcount
 *			��ȡ֤�����֤�����
 *		������
 *			store��֤���
 *		����ֵ��
 *			�ɹ�����֤�����֤�����,ʧ�ܷ���-1
 */
int NETCAAPI netca_cert_store_getcertcount(NETCA_CERT_Store store);
/*
 *		netca_cert_store_getcert
 *			��ȡ֤�����֤��
 *		������
 *			store��֤���
 *			index:�������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����֤����е�index��֤��,ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_cert_store_getcert(NETCA_CERT_Store store,int index);
/*
 *		netca_cert_store_close
 *			�ر�֤���
 *		������
 *			store��֤���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_cert_store_close(NETCA_CERT_Store store);
/*
 *		netca_cert_store_save
 *			����֤���
 *		������
 *			store��֤���
 *		����ֵ��
 *			�ɹ�����NETCA_OK,ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_cert_store_save(NETCA_CERT_Store store);
/*
 *		netca_cert_store_addcert
 *			���֤�鵽֤���
 *		������
 *			store��֤���
 *			cert��֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK,ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_cert_store_addcert(NETCA_CERT_Store store,NETCA_CERT cert);
/*
 *		netca_cert_store_delete
 *			��֤�����ɾ��֤��
 *		������
 *			store��֤���
 *			cert��֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK,ʧ�ܷ���NETCA_FAIL
 */
int NETCAAPI netca_cert_store_delete(NETCA_CERT_Store store,NETCA_CERT cert);

/*
 *		netca_cert_store_loadpfx
 *			��PFX��ʽ������װ�ص�֤���
 *		������
 *			data�����������PFX��ʽ������
 *			datalen�����������data�ĳ���
 *			pwd����������PFX������
 *		����ֵ��
 *			�ɹ�����֤���,ʧ�ܷ���NULL
 */
NETCA_CERT_Store NETCAAPI netca_cert_store_loadpfx(const unsigned char *data,long datalen,NETCA_UString pwd);


#ifdef __cplusplus
	}	
#endif
#endif

