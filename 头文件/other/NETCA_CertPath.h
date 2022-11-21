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
 *			创建一个证书路径构造对象
 *		参数：
 *			tas：输入参数，一组根证书
 *			tacount：输入参数，根证书的个数
 *		返回值：
 *			成功返回证书路径构造对象，失败返回NULL
 */
NETCA_CertPathBuilder NETCAAPI netca_certpathbuider_new(NETCA_CERT *tas,int tacount);
/*
 *		netca_certpathbuider_free
 *			释放证书路径构造对象
 *		参数：
 *			builder：证书路径构造对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_certpathbuider_free(NETCA_CertPathBuilder builder);

/*
 *		netca_certpathbuider_addcacert
 *			在证书路径构造对象中添加CA证书
 *		参数：
 *			builder：证书路径构造对象
 *			cert：CA证书
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathbuider_addcacert(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_setmustincludecert
 *			在证书路径构造对象中添加必须包含的CA证书
 *		参数：
 *			builder：证书路径构造对象
 *			cert：CA证书
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathbuider_setmustincludecert(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_setmaxcount
 *			在证书路径构造对象中添加最多返回的证书路径限制
 *		参数：
 *			builder：证书路径构造对象
 *			count：输入参数，返回的证书路径上限
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathbuider_setmaxcount(NETCA_CertPathBuilder builder,int count);

/*
 *		netca_certpathbuider_getcertpath
 *			构造证书路径
 *		参数：
 *			builder：证书路径构造对象
 *			cert：要构造证书路径的终端证书
 *		返回值：
 *			成功返回构造得到的证书路径，失败返回NULL
 */
NETCA_CertPaths NETCAAPI netca_certpathbuider_getcertpath(NETCA_CertPathBuilder builder,NETCA_CERT cert);
/*
 *		netca_certpathbuider_getcrlpath
 *			构造CRL路径
 *		参数：
 *			builder：证书路径构造对象
 *			crl：要构造证书路径的CRL
 *		返回值：
 *			成功返回构造得到的CRL路径，失败返回NULL
 */
NETCA_CertPaths NETCAAPI netca_certpathbuider_getcrlpath(NETCA_CertPathBuilder builder,NETCA_CRL crl);

/*
 *		netca_certpaths_free
 *			释放证书路径集
 *		参数：
 *			paths：证书路径集
 *		返回值：
 *			无
 */
void NETCAAPI netca_certpaths_free(NETCA_CertPaths paths);
/*
 *		netca_certpaths_getcount
 *			获取证书路径集的证书路径个数
 *		参数：
 *			paths：证书路径集
 *		返回值：
 *			成功返回证书路径个数，失败返回-1
 */
int NETCAAPI netca_certpaths_getcount(NETCA_CertPaths paths);
/*
 *		netca_certpaths_get
 *			获取证书路径集的证书路径
 *		参数：
 *			paths：证书路径集
 *			index:输入参数，索引值，从0算起
 *		返回值：
 *			成功返回证书路径集的第index个证书路径，失败返回NULL
 */
NETCA_CertPath NETCAAPI netca_certpaths_get(NETCA_CertPaths paths,int index);

/*
 *		netca_certpath_new
 *			手工构造一个证书路径
 *		参数：
 *			ta：根证书
 *			certs:一组证书
 *			count：输入参数，证书个数
 *		返回值：
 *			成功返回证书路径，失败返回NULL
 */
NETCA_CertPath NETCAAPI netca_certpath_new(NETCA_CERT ta,NETCA_CERT *certs,int count);
/*
 *		netca_certpath_free
 *			释放证书路径
 *		参数：
 *			path：证书路径
 *		返回值：
 *			无
 */
void NETCAAPI netca_certpath_free(NETCA_CertPath path);
/*
 *		netca_certpath_dup
 *			复制证书路径
 *		参数：
 *			path：证书路径
 *		返回值：
 *			成功返回复制得到的证书路径，失败返回NULL
 */
NETCA_CertPath NETCAAPI netca_certpath_dup(NETCA_CertPath path);
/*
 *		netca_certpath_getta
 *			获得证书路径的根证书
 *		参数：
 *			path：证书路径
 *		返回值：
 *			成功返回证书路径的根证书，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_certpath_getta(NETCA_CertPath path);

/*
 *		netca_certpath_getcount
 *			获得证书路径的证书个数
 *		参数：
 *			path：证书路径
 *		返回值：
 *			成功返回证书路径的证书个数，失败返回-1
 */
int NETCAAPI netca_certpath_getcount(NETCA_CertPath path);

/*
 *		netca_certpath_getcert
 *			获得证书路径的证书
 *		参数：
 *			path：证书路径
 *			index:输入参数，索引值，从0算起
 *		返回值：
 *			成功返回证书路径的第index个证书，失败返回NULL
 */
NETCA_CERT NETCAAPI netca_certpath_getcert(NETCA_CertPath path,int index);

/*
 *		netca_certpath_calcvalidity
 *			计算证书路径（不包括根）的所有证书的有效期的交集
 *		参数：
 *			path：证书路径
 *			startTime:输出参数，返回有效的开始时间，如果交集为空集，则返回NULL
 *			endTime:输出参数，返回有效的结束时间，如果交集为空集，则返回NULL
 *		返回值：
 *			成功NETCA_OK，失败返回其他值
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
 *			创建一个证书路径验证对象
 *		参数：
 *			无
 *		返回值：
 *			成功返回证书路径验证对象，失败返回NULL
 */
NETCA_CertPathValidator NETCAAPI netca_certpathvalidator_new(void);
/*
 *		netca_certpathvalidator_free
 *			释放证书路径验证对象
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			无
 */
void NETCAAPI netca_certpathvalidator_free(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_setchecktime
 *			设置验证时间
 *		参数：
 *			validator：证书路径验证对象
 *			t：输入参数，验证时间
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setchecktime(NETCA_CertPathValidator validator,NETCA_Time t);

/*
 *		netca_certpathvalidator_setacceptablepolicy
 *			设置可以接受的证书策略
 *		参数：
 *			validator：证书路径验证对象
 *			ploicies：输入参数，一组证书策略
 *			count：输入参数，证书策略个数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setacceptablepolicy(NETCA_CertPathValidator validator,const char *ploicies[],int count);

/*
 *		netca_certpathvalidator_setacceptablepolicy
 *			设置是否允许策略映射
 *		参数：
 *			validator：证书路径验证对象
 *			value：输入参数，为真表示允许策略映射，为假表示不允许
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setallowpolicymapping(NETCA_CertPathValidator validator,int value);
/*
 *		netca_certpathvalidator_setallowanypolicy
 *			设置是否允许ANY策略
 *		参数：
 *			validator：证书路径验证对象
 *			value：输入参数，为真表示允许ANY策略，为假表示不允许
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setallowanypolicy(NETCA_CertPathValidator validator,int value);
/*
 *		netca_certpathvalidator_setrequestpolicy
 *			设置是否需要证书策略
 *		参数：
 *			validator：证书路径验证对象
 *			value：输入参数，为真表示需要证书策略，为假表示不需要
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setrequestpolicy(NETCA_CertPathValidator validator,int value);

/*
 *		netca_certpathvalidator_verify
 *			验证证书路径
 *		参数：
 *			validator：证书路径验证对象
 *			path：证书路径
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_verify(NETCA_CertPathValidator validator,NETCA_CertPath path);
/*
 *		netca_certpathvalidator_verifycrl
 *			验证CRL路径
 *		参数：
 *			validator：证书路径验证对象
 *			path：证书路径
 *			crl：CRL
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_verifycrl(NETCA_CertPathValidator validator,NETCA_CertPath path,NETCA_CRL crl);
/*
 *		netca_certpathvalidator_setparam
 *			设置证书路径验证参数
 *		参数：
 *			validator：证书路径验证对象
 *			param：输入参数，证书路径验证参数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_setparam(NETCA_CertPathValidator validator,const char *param);
/*
 *		netca_certpathvalidator_addexthandler
 *			设置证书路径验证的扩展处理函数
 *		参数：
 *			validator：证书路径验证对象
 *			extid：输入参数，扩展OID
 *			context:扩展处理函数参数
 *			exthandler：输入参数，扩展处理函数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_addexthandler(NETCA_CertPathValidator validator,const char *extid,void *context,netca_cert_extension_handler exthandler);

/*
 *		netca_certpathvalidator_getpolicynodecount
 *			获取证书路径验证结果的策略节点数
 *		参数：
 *			validator：证书路径验证对象
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回证书路径验证结果的第index层策略节点数，失败返回-1
 */
int NETCAAPI netca_certpathvalidator_getpolicynodecount(NETCA_CertPathValidator validator,int index);

/*
 *		netca_certpathvalidator_getpolicynodeinfo
 *			获取证书路径验证结果的策略信息
 *		参数：
 *			validator：证书路径验证对象
 *			certindex：输入参数，第几层，从0算起
 *			nodeindex：输入参数，第几个，从0算起
 *		返回值：
 *			成功返回证书路径验证结果的第certindex层的第nodeindex个策略节点的策略信息，失败返回NULL
 */
NETCA_CERT_PolicyInformation NETCAAPI netca_certpathvalidator_getpolicynodeinfo(NETCA_CertPathValidator validator,int certindex,int nodeindex);

/*
 *		netca_certpathvalidator_addnameconstrainthandler
 *			添加证书路径验证的名字约束扩展处理函数
 *		参数：
 *			validator：证书路径验证对象
 *			type：输入参数，类型
 *			othernameid：输入参数，OtherName的OID
 *			context：输入参数，处理函数参数
 *			handler：输入参数，处理函数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_addnameconstrainthandler(NETCA_CertPathValidator validator,int type,const char *othernameid,void *context,netca_cert_nameconstraint_handler handler);
/*
 *		netca_certpathvalidator_addnameconstraint
 *			添加证书路径验证的初始的名字约束
 *		参数：
 *			validator：证书路径验证对象
 *			type：输入参数，类型
 *			othernameid：输入参数，OtherName的OID
 *			constraint：输入参数，约束值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_certpathvalidator_addnameconstraint(NETCA_CertPathValidator validator,int permit,int type,const char *othernameid,void *constraint);
/*
 *		netca_certpathvalidator_geterrorcode
 *			获取证书路径验证失败的原因
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			证书路径验证失败的原因
 */
int NETCAAPI netca_certpathvalidator_geterrorcode(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_getauthpolicyset
 *			获取证书路径验证的CA证书策略集
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书路径验证的CA证书策略集，失败返回NULL
 */
NETCA_PolicySet NETCAAPI netca_certpathvalidator_getauthpolicyset(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getuserpolicyset
 *			获取证书路径验证的用户证书策略集
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书路径验证的用户证书策略集，失败返回NULL
 */
NETCA_PolicySet NETCAAPI netca_certpathvalidator_getuserpolicyset(NETCA_CertPathValidator validator);

/*
 *		netca_policyset_free
 *			释放证书策略集
 *		参数：
 *			policyset：证书策略集
 *		返回值：
 *			无
 */
void NETCAAPI netca_policyset_free(NETCA_PolicySet policyset);
/*
 *		netca_policyset_count
 *			获取证书策略集的证书策略个数
 *		参数：
 *			policyset：证书策略集
 *		返回值：
 *			成功返回证书策略集的证书策略个数，失败返回-1
 */
int NETCAAPI netca_policyset_count(NETCA_PolicySet policyset);

/*
 *		netca_policyset_getpolicy
 *			获取证书策略集的证书策略
 *		参数：
 *			policyset：证书策略集
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回证书策略集的第index个证书策略，失败返回NULL
 */
char * NETCAAPI netca_policyset_getpolicy(NETCA_PolicySet policyset,int index);

/*
 *		netca_certpathvalidator_getpubkeyalgo
 *			获取证书的公钥算法
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的公钥算法，失败返回-1
 */
int NETCAAPI netca_certpathvalidator_getpubkeyalgo(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getdsa
 *			获取证书的DSA公钥
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的DSA公钥，失败返回NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_certpathvalidator_getdsa(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getrsa
 *			获取证书的RSA公钥
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的RSA公钥，失败返回NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_certpathvalidator_getrsa(NETCA_CertPathValidator validator);
/*
 *		netca_certpathvalidator_getpubkeyprarm
 *			获取证书的公钥参数
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的公钥参数，失败返回NULL
 */
void * NETCAAPI netca_certpathvalidator_getpubkeyprarm(NETCA_CertPathValidator validator);

/*
 *		netca_certpathvalidator_getecc
 *			获取证书的ECC公钥
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的ECC公钥，失败返回NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_certpathvalidator_getecc(NETCA_CertPathValidator validator);


/*
 *		netca_certpathvalidator_getpubkey
 *			获取证书的公钥句柄
 *		参数：
 *			validator：证书路径验证对象
 *		返回值：
 *			成功返回证书的公钥句柄，失败返回NULL
 */
NETCA_PKI_PUBLICKEY_HANDLE NETCAAPI netca_certpathvalidator_getpubkey(NETCA_CertPathValidator validator);

#ifdef __cplusplus
	}	
#endif
#endif
