#ifndef NETCA_CERTPATH_INLCUDE_H
#define NETCA_CERTPATH_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"
#include "NETCA_PKI_Type.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_certpathbuider_new
 *			����һ��֤��·���������
 *		������
 *			tas�����������һ���֤��
 *			tacount�������������֤��ĸ���
 *		����ֵ��
 *			�ɹ�����֤��·���������ʧ�ܷ���NULL
 */
NETCA_CertPathBuilder NETCAAPI netca_certpathbuider_new(NETCA_CERT *tas,int tacount);
/*
 *		netca_certpathbuider_free
 *			�ͷ�֤��·���������
 *		������
 *			builder��֤��·���������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_certpathbuider_free(NETCA_CertPathBuilder builder);

/*
 *		netca_certpathbuider_addcacert
 *			��֤��·��������������CA֤��
 *		������
 *			builder��֤��·���������
 *			cert��CA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathbuider_addcacert(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_setmustincludecert
 *			��֤��·�������������ӱ��������CA֤��
 *		������
 *			builder��֤��·���������
 *			cert��CA֤��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathbuider_setmustincludecert(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_setmaxcount
 *			��֤��·����������������෵�ص�֤��·������
 *		������
 *			builder��֤��·���������
 *			count��������������ص�֤��·������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathbuider_setmaxcount(NETCA_CertPathBuilder builder,int count);

/*
 *		netca_certpathbuider_getcertpath
 *			����֤��·��
 *		������
 *			builder��֤��·���������
 *			cert��Ҫ����֤��·�����ն�֤��
 *		����ֵ��
 *			�ɹ����ع���õ���֤��·����ʧ�ܷ���NULL
 */
NETCA_CertPaths NETCAAPI netca_certpathbuider_getcertpath(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_getcrlpath
 *			����CRL·��
 *		������
 *			builder��֤��·���������
 *			crl��Ҫ����֤��·����CRL
 *		����ֵ��
 *			�ɹ����ع���õ���CRL·����ʧ�ܷ���NULL
 */
NETCA_CertPaths NETCAAPI netca_certpathbuider_getcrlpath(NETCA_CertPathBuilder builder,NETCA_CRL crl);

/*
 *		netca_certpaths_free
 *			�ͷ�֤��·����
 *		������
 *			paths��֤��·����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_certpaths_free(NETCA_CertPaths paths);
/*
 *		netca_certpaths_getcount
 *			��ȡ֤��·������֤��·������
 *		������
 *			paths��֤��·����
 *		����ֵ��
 *			�ɹ�����֤��·��������ʧ�ܷ���-1
 */
int NETCAAPI netca_certpaths_getcount(NETCA_CertPaths paths);
/*
 *		netca_certpaths_get
 *			��ȡ֤��·������֤��·��
 *		������
 *			paths��֤��·����
 *			index:�������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����֤��·�����ĵ�index��֤��·����ʧ�ܷ���NULL
 */
NETCA_CertPath NETCAAPI netca_certpaths_get(NETCA_CertPaths paths,int index);

/*
 *		netca_certpath_new
 *			�ֹ�����һ��֤��·��
 *		������
 *			ta����֤��
 *			certs:һ��֤��
 *			count�����������֤�����
 *		����ֵ��
 *			�ɹ�����֤��·����ʧ�ܷ���NULL
 */
NETCA_CertPath NETCAAPI netca_certpath_new(NETCA_CERT ta,NETCA_CERT *certs,int count);
/*
 *		netca_certpath_free
 *			�ͷ�֤��·��
 *		������
 *			path��֤��·��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_certpath_free(NETCA_CertPath path);
/*
 *		netca_certpath_dup
 *			����֤��·��
 *		������
 *			path��֤��·��
 *		����ֵ��
 *			�ɹ����ظ��Ƶõ���֤��·����ʧ�ܷ���NULL
 */
NETCA_CertPath NETCAAPI netca_certpath_dup(NETCA_CertPath path);
/*
 *		netca_certpath_getta
 *			���֤��·���ĸ�֤��
 *		������
 *			path��֤��·��
 *		����ֵ��
 *			�ɹ�����֤��·���ĸ�֤�飬ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_certpath_getta(NETCA_CertPath path);

/*
 *		netca_certpath_getcount
 *			���֤��·����֤�����
 *		������
 *			path��֤��·��
 *		����ֵ��
 *			�ɹ�����֤��·����֤�������ʧ�ܷ���-1
 */
int NETCAAPI netca_certpath_getcount(NETCA_CertPath path);

/*
 *		netca_certpath_getcert
 *			���֤��·����֤��
 *		������
 *			path��֤��·��
 *			index:�������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����֤��·���ĵ�index��֤�飬ʧ�ܷ���NULL
 */
NETCA_CERT NETCAAPI netca_certpath_getcert(NETCA_CertPath path,int index);

/*
 *		netca_certpath_calcvalidity
 *			����֤��·��������������������֤�����Ч�ڵĽ���
 *		������
 *			path��֤��·��
 *			startTime:���������������Ч�Ŀ�ʼʱ�䣬�������Ϊ�ռ����򷵻�NULL
 *			endTime:���������������Ч�Ľ���ʱ�䣬�������Ϊ�ռ����򷵻�NULL
 *		����ֵ��
 *			�ɹ�NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpath_calcvalidity(NETCA_CertPath path,NETCA_Time *startTime,NETCA_Time *endTime);

enum
{
	NETCA_CERTPATH_VERIFY_ERROR_INVALIDARG=-1,
	NETCA_CERTPATH_VERIFY_ERROR_OUTOFMEMORY=-2,
	NETCA_CERTPATH_VERIFY_ERROR_DECODEERROR=-3,
	NETCA_CERTPATH_VERIFY_ERROR_INVALIDATA=-4,
	NETCA_CERTPATH_VERIFY_ERROR_UNKNOWNALGO=-5,
	NETCA_CERTPATH_VERIFY_ERROR_MISMATCHALGO=-6,
	NETCA_CERTPATH_VERIFY_ERROR_VERIFYSIGNATUREFAIL=-7,
	NETCA_CERTPATH_VERIFY_ERROR_MISMATCHALGOPARAM=-8,
	NETCA_CERTPATH_VERIFY_ERROR_NOTINVALIDY=-9,
	NETCA_CERTPATH_VERIFY_ERROR_MISMATCHNAME=-10,
	NETCA_CERTPATH_VERIFY_ERROR_BREAKPOLICYCONSTRAINT=-11,
	NETCA_CERTPATH_VERIFY_ERROR_BADPOLICYMAPPINGS=-12,
	NETCA_CERTPATH_VERIFY_ERROR_NOBASICCONSTRAINTS=-13,
	NETCA_CERTPATH_VERIFY_ERROR_NOTCA=-14,
	NETCA_CERTPATH_VERIFY_ERROR_BREAKPATHCONSTRAINTS=-15,
	NETCA_CERTPATH_VERIFY_ERROR_NOKEYCERTSIGN=-16,
	NETCA_CERTPATH_VERIFY_ERROR_PROCCESSEXTHANDLEFAIL=-17,
	NETCA_CERTPATH_VERIFY_ERROR_UNKNOWNCRITICALEXT=-18,
	NETCA_CERTPATH_VERIFY_ERROR_GETTIMEFAIL=-19,
	NETCA_CERTPATH_VERIFY_ERROR_BREAKNAMECONSTRAINTS=-20,
	NETCA_CERTPATH_VERIFY_ERROR_UNKNOWNNAMECONSTRAINTS=-21,
	NETCA_CERTPATH_VERIFY_ERROR_NOTCRLISSUER=-22,
	NETCA_CERTPATH_VERIFY_ERROR_DUPEXT=-23,
	NETCA_CERTPATH_VERIFY_ERROR_CRLNOTINVALIDY=-24,
};

#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_RSA			0x1
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_DSA			0x2
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_DH			0x3
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_EC			0x4
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_RSA_OAEP		0x5
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_RSA_PSS		0x6
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_ECDH			0x7
#define NETCA_SUBJECT_PUBLICKEY_ALGORITHM_ECMQV			0x8


typedef int (NETCAAPI *netca_cert_extension_handler)(NETCA_CertPath path,int index,NETCA_CERT_Extension ext,void *context);
typedef int (NETCAAPI *netca_cert_nameconstraint_handler)(NETCA_CERT_GeneralSubtree constraint,NETCA_CERT_GeneralName gn,void *context);

/*
 *		netca_certpathvalidator_new
 *			����һ��֤��·����֤����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����֤��·����֤����ʧ�ܷ���NULL
 */
NETCA_CertPathValidator NETCAAPI netca_certpathvalidator_new(void);
/*
 *		netca_certpathvalidator_free
 *			�ͷ�֤��·����֤����
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_certpathvalidator_free(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_setchecktime
 *			������֤ʱ��
 *		������
 *			validator��֤��·����֤����
 *			t�������������֤ʱ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setchecktime(NETCA_CertPathValidator validator,NETCA_Time t);

/*
 *		netca_certpathvalidator_setacceptablepolicy
 *			���ÿ��Խ��ܵ�֤�����
 *		������
 *			validator��֤��·����֤����
 *			ploicies�����������һ��֤�����
 *			count�����������֤����Ը���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setacceptablepolicy(NETCA_CertPathValidator validator,const char *ploicies[],int count);

/*
 *		netca_certpathvalidator_setacceptablepolicy
 *			�����Ƿ��������ӳ��
 *		������
 *			validator��֤��·����֤����
 *			value�����������Ϊ���ʾ�������ӳ�䣬Ϊ�ٱ�ʾ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setallowpolicymapping(NETCA_CertPathValidator validator,int value);
/*
 *		netca_certpathvalidator_setallowanypolicy
 *			�����Ƿ�����ANY����
 *		������
 *			validator��֤��·����֤����
 *			value�����������Ϊ���ʾ����ANY���ԣ�Ϊ�ٱ�ʾ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setallowanypolicy(NETCA_CertPathValidator validator,int value);
/*
 *		netca_certpathvalidator_setrequestpolicy
 *			�����Ƿ���Ҫ֤�����
 *		������
 *			validator��֤��·����֤����
 *			value�����������Ϊ���ʾ��Ҫ֤����ԣ�Ϊ�ٱ�ʾ����Ҫ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setrequestpolicy(NETCA_CertPathValidator validator,int value);

/*
 *		netca_certpathvalidator_verify
 *			��֤֤��·��
 *		������
 *			validator��֤��·����֤����
 *			path��֤��·��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_verify(NETCA_CertPathValidator validator,NETCA_CertPath path);
/*
 *		netca_certpathvalidator_verifycrl
 *			��֤CRL·��
 *		������
 *			validator��֤��·����֤����
 *			path��֤��·��
 *			crl��CRL
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_verifycrl(NETCA_CertPathValidator validator,NETCA_CertPath path,NETCA_CRL crl);
/*
 *		netca_certpathvalidator_setparam
 *			����֤��·����֤����
 *		������
 *			validator��֤��·����֤����
 *			param�����������֤��·����֤����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_setparam(NETCA_CertPathValidator validator,const char *param);
/*
 *		netca_certpathvalidator_addexthandler
 *			����֤��·����֤����չ������
 *		������
 *			validator��֤��·����֤����
 *			extid�������������չOID
 *			context:��չ����������
 *			exthandler�������������չ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_addexthandler(NETCA_CertPathValidator validator,const char *extid,void *context,netca_cert_extension_handler exthandler);

/*
 *		netca_certpathvalidator_getpolicynodecount
 *			��ȡ֤��·����֤����Ĳ��Խڵ���
 *		������
 *			validator��֤��·����֤����
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����֤��·����֤����ĵ�index����Խڵ�����ʧ�ܷ���-1
 */
int NETCAAPI netca_certpathvalidator_getpolicynodecount(NETCA_CertPathValidator validator,int index);

/*
 *		netca_certpathvalidator_getpolicynodeinfo
 *			��ȡ֤��·����֤����Ĳ�����Ϣ
 *		������
 *			validator��֤��·����֤����
 *			certindex������������ڼ��㣬��0����
 *			nodeindex������������ڼ�������0����
 *		����ֵ��
 *			�ɹ�����֤��·����֤����ĵ�certindex��ĵ�nodeindex�����Խڵ�Ĳ�����Ϣ��ʧ�ܷ���NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_certpathvalidator_getpolicynodeinfo(NETCA_CertPathValidator validator,int certindex,int nodeindex);

/*
 *		netca_certpathvalidator_addnameconstrainthandler
 *			���֤��·����֤������Լ����չ������
 *		������
 *			validator��֤��·����֤����
 *			type���������������
 *			othernameid�����������OtherName��OID
 *			context���������������������
 *			handler�����������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_addnameconstrainthandler(NETCA_CertPathValidator validator,int type,const char *othernameid,void *context,netca_cert_nameconstraint_handler handler);
/*
 *		netca_certpathvalidator_addnameconstraint
 *			���֤��·����֤�ĳ�ʼ������Լ��
 *		������
 *			validator��֤��·����֤����
 *			type���������������
 *			othernameid�����������OtherName��OID
 *			constraint�����������Լ��ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_certpathvalidator_addnameconstraint(NETCA_CertPathValidator validator,int permit,int type,const char *othernameid,void *constraint);
/*
 *		netca_certpathvalidator_geterrorcode
 *			��ȡ֤��·����֤ʧ�ܵ�ԭ��
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			֤��·����֤ʧ�ܵ�ԭ��
 */
int NETCAAPI netca_certpathvalidator_geterrorcode(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_getauthpolicyset
 *			��ȡ֤��·����֤��CA֤����Լ�
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤��·����֤��CA֤����Լ���ʧ�ܷ���NULL
 */
NETCA_PolicySet NETCAAPI netca_certpathvalidator_getauthpolicyset(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getuserpolicyset
 *			��ȡ֤��·����֤���û�֤����Լ�
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤��·����֤���û�֤����Լ���ʧ�ܷ���NULL
 */
NETCA_PolicySet NETCAAPI netca_certpathvalidator_getuserpolicyset(NETCA_CertPathValidator validator);

/*
 *		netca_policyset_free
 *			�ͷ�֤����Լ�
 *		������
 *			policyset��֤����Լ�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_policyset_free(NETCA_PolicySet policyset);
/*
 *		netca_policyset_count
 *			��ȡ֤����Լ���֤����Ը���
 *		������
 *			policyset��֤����Լ�
 *		����ֵ��
 *			�ɹ�����֤����Լ���֤����Ը�����ʧ�ܷ���-1
 */
int NETCAAPI netca_policyset_count(NETCA_PolicySet policyset);

/*
 *		netca_policyset_getpolicy
 *			��ȡ֤����Լ���֤�����
 *		������
 *			policyset��֤����Լ�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����֤����Լ��ĵ�index��֤����ԣ�ʧ�ܷ���NULL
 */
char * NETCAAPI netca_policyset_getpolicy(NETCA_PolicySet policyset,int index);

/*
 *		netca_certpathvalidator_getpubkeyalgo
 *			��ȡ֤��Ĺ�Կ�㷨
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤��Ĺ�Կ�㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_certpathvalidator_getpubkeyalgo(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getdsa
 *			��ȡ֤���DSA��Կ
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤���DSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_certpathvalidator_getdsa(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getrsa
 *			��ȡ֤���RSA��Կ
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤���RSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_certpathvalidator_getrsa(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getpubkeyprarm
 *			��ȡ֤��Ĺ�Կ����
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤��Ĺ�Կ������ʧ�ܷ���NULL
 */
void * NETCAAPI netca_certpathvalidator_getpubkeyprarm(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_getecc
 *			��ȡ֤���ECC��Կ
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤���ECC��Կ��ʧ�ܷ���NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_certpathvalidator_getecc(NETCA_CertPathValidator validator);


/*
 *		netca_certpathvalidator_getpubkey
 *			��ȡ֤��Ĺ�Կ���
 *		������
 *			validator��֤��·����֤����
 *		����ֵ��
 *			�ɹ�����֤��Ĺ�Կ�����ʧ�ܷ���NULL
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCAAPI netca_certpathvalidator_getpubkey(NETCA_CertPathValidator validator);

#ifdef __cplusplus
	}	
#endif
#endif
