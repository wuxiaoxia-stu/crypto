#ifndef NETCA_CRYPTO_INLCUDE_H
#define NETCA_CRYPTO_INLCUDE_H

#include "NETCA_Crypto_Hash.h"
#include "NETCA_Cert.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#define NETCA_SIGANTURE_ALGORITHM_MD5WITHRSA				1
#define NETCA_SIGANTURE_ALGORITHM_MD5WITHRSA_NOHASHOID			2
#define NETCA_SIGANTURE_ALGORITHM_SHA1WITHRSA				3
#define NETCA_SIGANTURE_ALGORITHM_SHA1WITHRSA_NOHASHOID			4
#define NETCA_SIGANTURE_ALGORITHM_SHA224WITHRSA				5
#define NETCA_SIGANTURE_ALGORITHM_SHA224WITHRSA_NOHASHOID		6
#define NETCA_SIGANTURE_ALGORITHM_SHA256WITHRSA				7
#define NETCA_SIGANTURE_ALGORITHM_SHA256WITHRSA_NOHASHOID		8
#define NETCA_SIGANTURE_ALGORITHM_SHA384WITHRSA				9
#define NETCA_SIGANTURE_ALGORITHM_SHA384WITHRSA_NOHASHOID		10
#define NETCA_SIGANTURE_ALGORITHM_SHA512WITHRSA				11
#define NETCA_SIGANTURE_ALGORITHM_SHA512WITHRSA_NOHASHOID		12
#define NETCA_SIGANTURE_ALGORITHM_SHA1MD5WITHRSA_NOHASHOID		13
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA1				14
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA1				15
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA1				16
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA224				17
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA256				18
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA384				19
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA512				20
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA224				21
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA256				22
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA224			23
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA256			24
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA384			25
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA512			26
#define NETCA_SIGANTURE_ALGORITHM_SM3WITHRSA				27
#define NETCA_SIGANTURE_ALGORITHM_SM3WITHRSA_NOHASHOID		28
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA512_224			29
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA512_256			30
#define NETCA_SIGANTURE_ALGORITHM_SHA512_224WITHRSA			31
#define NETCA_SIGANTURE_ALGORITHM_SHA512_256WITHRSA			32
#define NETCA_SIGANTURE_ALGORITHM_SHA512_224WITHRSA_NOHASHOID			33
#define NETCA_SIGANTURE_ALGORITHM_SHA512_256WITHRSA_NOHASHOID			34
#define NETCA_SIGANTURE_ALGORITHM_SHA3_224WITHRSA			35
#define NETCA_SIGANTURE_ALGORITHM_SHA3_256WITHRSA			36
#define NETCA_SIGANTURE_ALGORITHM_SHA3_384WITHRSA			37
#define NETCA_SIGANTURE_ALGORITHM_SHA3_512WITHRSA			38
#define NETCA_SIGANTURE_ALGORITHM_SHA3_224WITHRSA_NOHASHOID			39
#define NETCA_SIGANTURE_ALGORITHM_SHA3_256WITHRSA_NOHASHOID			40
#define NETCA_SIGANTURE_ALGORITHM_SHA3_384WITHRSA_NOHASHOID			41
#define NETCA_SIGANTURE_ALGORITHM_SHA3_512WITHRSA_NOHASHOID			42
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA3_224			43
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA3_256			44
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA3_384			45
#define NETCA_SIGANTURE_ALGORITHM_RSAPSS_SHA3_512			46

#define NETCA_HASH_ALGORITHM_MD2					0x100
#define NETCA_HASH_ALGORITHM_MD5					0x200
#define NETCA_HASH_ALGORITHM_SHA1					0x300
#define NETCA_HASH_ALGORITHM_SHA224					0x400
#define NETCA_HASH_ALGORITHM_SHA256					0x500
#define NETCA_HASH_ALGORITHM_SHA384					0x600
#define NETCA_HASH_ALGORITHM_SHA512					0x700
#define NETCA_HASH_ALGORITHM_SM3					0x800
#define NETCA_HASH_ALGORITHM_SHA512_224				0x900
#define NETCA_HASH_ALGORITHM_SHA512_256				0xA00
#define NETCA_HASH_ALGORITHM_SHA3_224				0xB00
#define NETCA_HASH_ALGORITHM_SHA3_256				0xC00
#define NETCA_HASH_ALGORITHM_SHA3_384				0xD00
#define NETCA_HASH_ALGORITHM_SHA3_512				0xE00


#define NETCA_ENCRYPT_ALGORITHM_RSA_PKCS1V1_5_ENCRYPT			0x1000
#define NETCA_ENCRYPT_ALGORITHM_RSA_PKCS1_OAEP					0x2000
#define NETCA_ENCRYPT_ALGORITHM_RSA_RAW_ENCRYPT					0x3000

#define NETCA_SIGANTURE_ALGORITHM_RSA_PKCS1V1_5_SIGN			0x10000
#define NETCA_SIGANTURE_ALGORITHM_RSA_PKCS1_PSS_SIGN			0x20000


#define NETCA_ALGORITHM_RSA						0x1
#define NETCA_ALGORITHM_DSA						0x2
#define NETCA_ALGORITHM_DH						0x3
#define NETCA_ALGORITHM_ECDSA					0x4



#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA1		1
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA224	2
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA256	3
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA384	4
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA512	5
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA512_224	6
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA512_256	7
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA3_224	8
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA3_256	9
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA3_384	10
#define NETCA_MGF_ALGORITHM_PKCS1_MGF1SHA3_512	11

struct NETCA_RSA_PARAM_PKCS1_OAEP_st
{
	long m_hashalgo;
	long m_mgfalgo;
	unsigned char *m_label;
	long m_labellen;	
};

struct NETCA_RSA_PARAM_PKCS1_PSS_st
{
	long m_mgfalgo;
	long m_saltlen;
	long m_hashalgo;	
};

/*
 *		netca_crypto_dsakey_new
 *			创建DSA公钥
 *		参数：
 *			p：输入参数，p
 *			q：输入参数，q
 *			g：输入参数，g
 *			y：输入参数，y
 *		返回值：
 *			成功返回DSA公钥，失败返回NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_crypto_dsakey_new(NETCA_BigInteger p,NETCA_BigInteger q,NETCA_BigInteger g,NETCA_BigInteger y);

/*
 *		netca_crypto_dsakey_free
 *			释放DSA公钥
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_dsakey_free(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_dup
 *			复制DSA公钥
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			成功返回复制的DSA公钥，失败返回NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_crypto_dsakey_dup(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getp
 *			获取DSA公钥的p
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			成功返回DSA公钥的p，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getp(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getq
 *			获取DSA公钥的q
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			成功返回DSA公钥的q，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getq(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getg
 *			获取DSA公钥的g
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			成功返回DSA公钥的g，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getg(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_gety
 *			获取DSA公钥的y
 *		参数：
 *			key：DSA公钥
 *		返回值：
 *			成功返回DSA公钥的y，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_gety(NETCA_Crypto_DSAKey key);

/*
 *		netca_crypto_dsactx_new
 *			创建一个DSA上下文
 *		参数：
 *			key：DSA公钥
 *			hash：Hash函数
 *		返回值：
 *			成功返回DSA上下文，失败返回NULL
 */
NETCA_Crypto_DSACtx NETCAAPI netca_crypto_dsactx_new(NETCA_Crypto_DSAKey key,netca_md_func_cptr hash);
/*
 *		netca_crypto_dsactx_free
 *			释放DSA上下文
 *		参数：
 *			ctx：上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_dsactx_free(NETCA_Crypto_DSACtx ctx);

/*
 *		netca_crypto_dsa_verify_init
 *			初始化DSA上下文
 *		参数：
 *			ctx：上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dsa_verify_init(NETCA_Crypto_DSACtx ctx);
/*
 *		netca_crypto_dsa_verify_update
 *			添加要验证签名的数据
 *		参数：
 *			ctx：上下文
 *			data：输入参数，数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dsa_verify_update(NETCA_Crypto_DSACtx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_dsa_verify_final
 *			验证DSA签名
 *		参数：
 *			ctx：上下文
 *			sign：输入参数，签名值
 *			signlen：输入参数，sign的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dsa_verify_final(NETCA_Crypto_DSACtx ctx,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_dsa_verifyhash
 *			验证DSA签名，输入是Hash值
 *		参数：
 *			ctx：上下文
 *			hash：输入参数，Hash值
 *			hashlen：输入参数，Hash长度
 *			sign：输入参数，签名值
 *			signlen：输入参数，sign的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dsa_verifyhash(NETCA_Crypto_DSACtx ctx,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_dsa_verify_finalex
 *			验证DSA签名
 *		参数：
 *			ctx：上下文
 *			r：输入参数，签名值中的r
 *			s：输入参数，签名值中的s
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dsa_verify_finalex(NETCA_Crypto_DSACtx ctx,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_crypto_rsakey_new
 *			创建RSA公钥
 *		参数：
 *			m：输入参数，模
 *			e：输入参数，公钥指数
 *		返回值：
 *			成功返回RSA公钥，失败返回NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_crypto_rsakey_new(NETCA_BigInteger m,NETCA_BigInteger e);
/*
 *		netca_crypto_rsakey_free
 *			释放RSA公钥
 *		参数：
 *			key：RSA公钥
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_rsakey_free(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_dup
 *			复制RSA公钥
 *		参数：
 *			key：RSA公钥
 *		返回值：
 *			成功返回复制的RSA公钥，失败返回NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_crypto_rsakey_dup(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_getmodulus
 *			获取RSA公钥的模
 *		参数：
 *			key：RSA公钥
 *		返回值：
 *			成功返回RSA公钥的模，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_rsakey_getmodulus(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_getpubexp
 *			获取RSA公钥的公钥指数
 *		参数：
 *			key：RSA公钥
 *		返回值：
 *			成功返回RSA公钥的公钥指数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_rsakey_getpubexp(NETCA_Crypto_RSAKey key);

/*
 *		netca_crypto_rsactx_new
 *			获取RSA上下文
 *		参数：
 *			key：RSA公钥
 *			algo：输入参数，算法
 *			param：输入参数，参数
 *		返回值：
 *			成功返回RSA上下文，失败返回NULL
 */
NETCA_Crypto_RSACtx NETCAAPI netca_crypto_rsactx_new(NETCA_Crypto_RSAKey key,long algo,void *param);
/*
 *		netca_crypto_rsactx_free
 *			释放RSA上下文
 *		参数：
 *			ctx：RSA上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_rsactx_free(NETCA_Crypto_RSACtx ctx);
/*
 *		netca_crypto_rsactx_sethashoid
 *			设置RSA验证是使用DigestInfo编码还是单纯的Hash值
 *		参数：
 *			ctx：RSA上下文
 *			usehashoid：输入参数，为真表示使用DigestInfo编码，为假表示使用Hash值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsactx_sethashoid(NETCA_Crypto_RSACtx ctx,int usehashoid);

/*
 *		netca_crypto_rsa_verify_init
 *			验证签名初始化
 *		参数：
 *			ctx：RSA上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsa_verify_init(NETCA_Crypto_RSACtx ctx);
/*
 *		netca_crypto_rsa_verify_update
 *			添加签名的数据
 *		参数：
 *			ctx：RSA上下文
 *			data：输入参数，要签名的数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsa_verify_update(NETCA_Crypto_RSACtx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_rsa_verify_final
 *			验证签名
 *		参数：
 *			ctx：RSA上下文
 *			sign：输入参数，签名值
 *			signlen：输入参数，sign的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsa_verify_final(NETCA_Crypto_RSACtx ctx,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_rsa_verifyex
 *			验证签名，这个函数只是对data进行PKCS#1V1.5的解码或者PSS处理。
 *		参数：
 *			ctx：RSA上下文
 *			data：输入参数，数据
 *			datalen：输入参数，data的长度
 *			sign：输入参数，签名值
 *			signlen：输入参数，sign的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsa_verifyex(NETCA_Crypto_RSACtx ctx,const unsigned char *data,long datalen,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_rsa_encrypt
 *			RSA加密
 *		参数：
 *			ctx：RSA上下文
 *			clear：输入参数，明文
 *			clearlen：输入参数，clear的长度
 *			cipher：输出参数，返回的密文
 *			cipherlen：输入输出参数，返回密文长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_rsa_encrypt(NETCA_Crypto_RSACtx ctx,const unsigned char *clear,int clearlen,unsigned char *cipher,int *cipherlen);


/*
 *		netca_ecc_newdomainparameters
 *			创建ECC域参数
 *		参数：
 *			name：输入参数，ECC曲线名或者OID
 *		返回值：
 *			成功返回有效的ECC域参数，失败返回NULL
 */
NETCA_ECC_Domain_Parameters NETCAAPI netca_ecc_newdomainparameters(const char *name);


/*
 *		netca_ecc_domainparameters_getbits
 *			获取ECC密钥长度
 *		参数：
 *			param：输入参数，域参数
 *		返回值：
 *			成功返回密钥长度，失败返回-1
 */
int NETCAAPI netca_ecc_domainparameters_getbits(NETCA_ECC_Domain_Parameters param);


/*
 *		netca_ecc_domainparameters_getbits
 *			获取ECC域的名称
 *		参数：
 *			param：输入参数，域参数
 *		返回值：
 *			成功返回ECC域的名称，失败返回NULL
 */
char* NETCAAPI netca_ecc_domainparameters_getname(NETCA_ECC_Domain_Parameters param);

/*
 *		netca_ecc_freedomainparameters
 *			释放ECC域参数
 *		参数：
 *			param：ECC域参数
 *		返回值：
 *			无
 */
void NETCAAPI netca_ecc_freedomainparameters(NETCA_ECC_Domain_Parameters param);

/*
 *		netca_ecc_newpoint
 *			创建一个ECC点
 *		参数：
 *			x：输入参数，横坐标
 *			y：输入参数，竖坐标
 *		返回值：
 *			成功返回有效的ECC点，失败返回NULL
 */
NETCA_ECC_Point NETCAAPI netca_ecc_newpoint(NETCA_BigInteger x, NETCA_BigInteger y);

/*
 *		netca_ecc_freepoint
 *			释放ECC点
 *		参数：
 *			point：ECC点
 *		返回值：
 *			无
 */
void NETCAAPI netca_ecc_freepoint(NETCA_ECC_Point point);

/*
 *		netca_ecc_newpubkey
 *			创建ECC公钥
 *		参数：
 *			param：ECC域参数
 *			Q：ECC点
 *		返回值：
 *			成功返回有效的ECC点，失败返回NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_ecc_newpubkey(NETCA_ECC_Domain_Parameters param,NETCA_ECC_Point Q);

/*
 *		netca_ecc_newpubkey
 *			创建ECC公钥
 *		参数：
 *			param：ECC域参数
 *			data：ECC点的编码
 *			datalen：ECC点的编码的长度
 *		返回值：
 *			成功返回有效的ECC点，失败返回NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_ecc_newpubkeyfromocts(NETCA_ECC_Domain_Parameters param,const unsigned char *data,int datalen);

/*
 *		netca_ecc_freepubkey
 *			释放ECC公钥
 *		参数：
 *			pubKey：ECC公钥
 *		返回值：
 *			无
 */
void NETCAAPI netca_ecc_freepubkey(NETCA_ECC_PubKey pubKey);

/*
 *		netca_ecc_getdomainparametersfrompubkey
 *			从ECC公钥获取域参数
 *		参数：
 *			pubKey：ECC公钥
 *		返回值：
 *			成功返回给域参数，失败返回NULL
 */
NETCA_ECC_Domain_Parameters NETCAAPI netca_ecc_getdomainparametersfrompubkey(NETCA_ECC_PubKey pubKey);


/*
 *		netca_ecc_getpubkeypoint
 *			从ECC公钥获取公钥的点
 *		参数：
 *			pubKey：ECC公钥
 *		返回值：
 *			成功返回给公钥的点，失败返回NULL
 */
NETCA_ECC_Point NETCAAPI netca_ecc_getpubkeypoint(NETCA_ECC_PubKey pubKey);

/*
 *		netca_ecc_encode_point
 *			编码ECC的点
 *		参数：
 *			keylen：ECC密钥位数
 *			point：ECC的点
 *			data：ECC点的编码
 *			datalen：ECC点的编码的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ecc_encode_point(int keylen,NETCA_ECC_Point point,unsigned char *data,int *datalen);

/*
 *		netca_ecc_ecdsa_verifyhash
 *			验证ECDSA签名
 *		参数：
 *			pubKey：ECC公钥
 *			hash：输入参数，hash值
 *			hashlen：输入参数，hash长度
 *			r：输入参数，签名的r
 *			s：输入参数，签名的s
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ecc_ecdsa_verifyhash(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_ecc_ecdsa_verifyhashex
 *			验证ECDSA签名
 *		参数：
 *			pubKey：ECC公钥
 *			hash：输入参数，hash值
 *			hashlen：输入参数，hash长度
 *			sign：输入参数，签名
 *			signlen：输入参数，签名的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ecc_ecdsa_verifyhashex(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_ecc_sm2_verifyhash
 *			验证ECDSA签名
 *		参数：
 *			pubKey：ECC公钥
 *			hash：输入参数，hash值（是Za和要签名数据的hash值）
 *			hashlen：输入参数，hash长度
 *			r：输入参数，签名的r
 *			s：输入参数，签名的s
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ecc_sm2_verifyhash(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_ecc_sm2_verifyhashex
 *			验证ECDSA签名
 *		参数：
 *			pubKey：ECC公钥
 *			hash：输入参数，hash值（是Za和要签名数据的hash值）
 *			hashlen：输入参数，hash长度
 *			sign：输入参数，签名
 *			signlen：输入参数，签名的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ecc_sm2_verifyhashex(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_privkey_list_init
 *			私钥环境初始化
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_privkey_list_init(void);
/*
 *		netca_privkey_list_end
 *			释放私钥环境
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_privkey_list_end(void);

/*
 *		netca_crypto_privkey_new
 *			获取私钥
 *		参数：
 *			attr：输入参数，私钥属性
 *			pwd：输入参数，私钥密码，可以为NULL
 *		返回值：
 *			成功返回私钥，失败返回NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_crypto_privkey_new(NETCA_PrivKey_Attr attr,const char *pwd);
/*
 *		netca_crypto_privkey_free
 *			释放私钥
 *		参数：
 *			handle：私钥句柄
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_privkey_free(NETCA_PrivKey_Handle handle);

/*
 *		netca_crypto_privkey_sign
 *			签名
 *		参数：
 *			handle：私钥句柄
 *			algoid：输入参数，签名算法
 *			param：输入参数，签名算法参数
 *			data：输入参数，要签名的数据
 *			datalen：输入参数，data的长度
 *			sign：输出参数，返回的签名值
 *			signlen：输入输出参数，返回的签名值长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_sign(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *data,int datalen,unsigned char *sign,int *signlen);
/*
 *		netca_crypto_privkey_decrypt
 *			私钥解密
 *		参数：
 *			handle：私钥句柄
 *			algoid：输入参数，加密算法
 *			param：输入参数，加密算法参数
 *			data：输入参数，密文
 *			datalen：输入参数，data的长度
 *			clear：输出参数，返回的明文
 *			clearlen：输入输出参数，返回的明文长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_decrypt(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *data,int datalen,unsigned char *clear,int *clearlen);

/*
 *		netca_crypto_privkey_sign_init
 *			初始化签名
 *		参数：
 *			handle：私钥句柄
 *			algoid：输入参数，签名算法
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_sign_init(NETCA_PrivKey_Handle handle,int algoid);
/*
 *		netca_crypto_privkey_sign_update
 *			添加要签名的数据
 *		参数：
 *			handle：私钥句柄
 *			data：输入参数，要签名的数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_sign_update(NETCA_PrivKey_Handle handle,const unsigned char *data,int datalen);
/*
 *		netca_crypto_privkey_sign_final
 *			签名
 *		参数：
 *			handle：私钥句柄
 *			param：输入参数，签名算法参数
 *			sign：输出参数，返回的签名值
 *			signlen：输入输出参数，返回的签名值长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_sign_final(NETCA_PrivKey_Handle handle,void *param,unsigned char *sign,int *signlen);
/*
 *		netca_crypto_privkey_sign_hash
 *			签名
 *		参数：
 *			handle：私钥句柄
 *			algoid：输入参数，签名算法
 *			param：输入参数，签名算法参数
 *			hash：输入参数，hash值
 *			hashlen：输入参数，hash的长度
 *			sign：输出参数，返回的签名值
 *			signlen：输入输出参数，返回的签名值长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_sign_hash(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *hash,int hashlen,unsigned char *sign,int *signlen);

/*
 *		netca_crypto_privkey_attr_free
 *			释放私钥属性
 *		参数：
 *			attr：私钥属性
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_privkey_attr_free(NETCA_PrivKey_Attr attr);
/*
 *		netca_crypto_privkey_attr_needpwd
 *			判断私钥属性是否需要密码
 *		参数：
 *			attr：私钥属性
 *		返回值：
 *			如果私钥属性需要密码返回1，否则返回0
 */
int NETCAAPI netca_crypto_privkey_attr_needpwd(NETCA_PrivKey_Attr attr);
/*
 *		netca_crypto_privkey_gen
 *			产生私钥
 *		参数：
 *			attr：私钥属性
 *			pwd：输入参数，密码
 *			alogId：输入参数，密钥对算法
 *			keybits：输入参数，密钥对长度
 *			param：输入参数，相关参数
 *		返回值：
 *			成功返回私钥，失败返回NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_crypto_privkey_gen(NETCA_PrivKey_Attr attr,const char *pwd,int alogId,int keybits,void *param);
/*
 *		netca_crypto_privkey_getpubkey
 *			获取公钥
 *		参数：
 *			handle：私钥
 *			pubkey：输出参数，返回的公钥
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_privkey_getpubkey(NETCA_PrivKey_Handle handle,void **pubkey);

/*
 *		netca_cert_getprivkey
 *			获取私钥
 *		参数：
 *			cert：证书
 *			pwd：输入参数，密码
 *		返回值：
 *			成功返回私钥，失败返回NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_cert_getprivkey(NETCA_CERT cert,const char *pwd);

#ifdef _WIN32
#include <wincrypt.h>
/*
 *		netca_mskeyprovinfo2privkeyattr
 *			获取私钥属性
 *		参数：
 *			provinfo：提供者信息
 *		返回值：
 *			成功返回私钥属性，失败返回NULL
 */
NETCA_PrivKey_Attr NETCAAPI netca_mskeyprovinfo2privkeyattr(PCRYPT_KEY_PROV_INFO provinfo);
#endif

/*
 *		netca_crypto_prng_init
 *			初始化随机数发生器
 *		参数：
 *			无
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_prng_init(void);
/*
 *		netca_crypto_prng_seed
 *			设置随机数发生器的种子
 *		参数：
 *			data：输入参数，种子
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_prng_seed(const unsigned char *data,long datalen);
/*
 *		netca_crypto_prng_getrand
 *			获取随机数
 *		参数：
 *			data：输出参数，返回的随机数
 *			datalen：输入参数，随机数的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_prng_getrand(unsigned char *data,long datalen);

#define NETCA_PKCS12_FALG_USEALLUNICOE					0x1
#define NETCA_PKCS12_FALG_MSTRUN						0x2

/*
 *		netca_crypto_pbkdf1
 *			根据口令产生密钥，使用PKCS#5V1的方法
 *		参数：
 *			md_func：输入参数，Hash函数
 *			pwd：输入参数，口令
 *			pwdlen：输入参数，pwd的长度
 *			salt：输入参数，盐
 *			saltlen：输入参数，salt的长度
 *			iter：输入参数，迭代次数
 *			keylen：输入参数，密钥长度
 *			key：输出参数，返回密钥值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_pbkdf1(netca_md_func_cptr md_func,const unsigned char *pwd,long pwdlen,const unsigned char *salt,long saltlen,int iter ,long keylen,unsigned char *key);
/*
 *		netca_crypto_pbkdf2_hmac
 *			根据口令产生密钥，使用PKCS#5V2的方法
 *		参数：
 *			md_func：输入参数，Hash函数
 *			pwd：输入参数，口令
 *			pwdlen：输入参数，pwd的长度
 *			salt：输入参数，盐
 *			saltlen：输入参数，salt的长度
 *			iter：输入参数，迭代次数
 *			keylen：输入参数，密钥长度
 *			key：输出参数，返回密钥值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_pbkdf2_hmac(netca_md_func_cptr md_func,const unsigned char *pwd,long pwdlen,const unsigned char *salt,long saltlen,int iter ,long keylen,unsigned char *key);
/*
 *		netca_crypto_pkcs12_kdf
 *			根据口令产生密钥，使用PKCS#12的方法
 *		参数：
 *			md_func：输入参数，Hash函数
 *			pwd：输入参数，口令
 *			ID：输入参数，ID
 *			salt：输入参数，盐
 *			saltlen：输入参数，salt的长度
 *			iter：输入参数，迭代次数
 *			flag：输入参数，标志
 *			keylen：输入参数，密钥长度
 *			key：输出参数，返回密钥值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_pkcs12_kdf(netca_md_func_cptr md_func,NETCA_UString pwd,int ID,const unsigned char *salt,long saltlen,int iter ,int flag,long keylen,unsigned char *key);
/*
 *		netca_crypto_dh_kdf
 *			根据DH协商得到的数据产生密钥
 *		参数：
 *			md_func：输入参数，Hash函数
 *			zz：输入参数，DH协商得到的数据
 *			plen：输入参数，p的长度
 *			kekoid：输入参数，KEK的OID
 *			partyainfo：输入参数，partyainfo
 *			partyainfolen：输入参数，partyainfo的长度
 *			keylen：输入参数，密钥长度
 *			key：输出参数，返回密钥值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_dh_kdf(netca_md_func_cptr md_func,NETCA_BigInteger zz,long plen,const char *kekoid,const unsigned char *partyainfo,long partyainfolen,long keylen,unsigned char *key);

/*
 *		netca_crypto_keywrap
 *			用对称密钥加密另一对称密钥
 *		参数：
 *			algo：输入参数，keywrap算法
 *			ishmackey：输入参数，为真是HMAC的密钥，为假不是
 *			kek：输入参数，用来加密的密钥
 *			keklen：输入参数，kek的长度
 *			cek：输入参数，被加密的密钥
 *			ceklen：输入参数，cek的长度
 *			keywrap：输出参数，返回keywrap值
 *			keywraplen：输入输出参数，返回keywrap的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_keywrap(int algo,int ishmackey,const unsigned char *kek,int keklen,long effkekbits,const unsigned char *cek,long ceklen,unsigned char *keywrap,long *keywraplen);
/*
 *		netca_crypto_keyunwrap
 *			keyunwrap
 *		参数：
 *			algo：输入参数，keywrap算法
 *			ishmackey：输入参数，为真是HMAC的密钥，为假不是
 *			kek：输入参数，用来加密的密钥
 *			keklen：输入参数，kek的长度
 *			keywrap：输入参数，要解密的keywrap值
 *			keywraplen：输入参数，keywrap的长度
 *			cek：输出参数，返回解密得到的密钥
 *			ceklen：输入输出参数，返回cek的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_keyunwrap(int algo,int ishmackey,const unsigned char *kek,int keklen,long effkekbits,const unsigned char *keywrap,long keywraplen,unsigned char *cek,long *ceklen);

/*
 *		netca_newrsaprivkeyattr
 *			获取私钥属性
 *		参数：
 *			data：输入参数，私钥属性的编码
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
NETCA_PrivKey_Attr NETCAAPI netca_newrsaprivkeyattr(const unsigned char *data,long datalen);

#ifdef __cplusplus
	}	
#endif
#endif


