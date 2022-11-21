#ifndef NETCA_CRYPTO_INLCUDE_H
#define NETCA_CRYPTO_INLCUDE_H

#include "NETCA_Crypto_Hash.h"
#include "NETCA_Cert.h"
#include "NETCA_PKI_Type.h"

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
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA3_224			47
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA3_256			48
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA3_384			49
#define NETCA_SIGANTURE_ALGORITHM_ECDSAWITHSHA3_512			50
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA384				51
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA512				52
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA3_224			53
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA3_256			54
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA3_384			55
#define NETCA_SIGANTURE_ALGORITHM_DSAWITHSHA3_512			56

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
 *			����DSA��Կ
 *		������
 *			p�����������p
 *			q�����������q
 *			g�����������g
 *			y�����������y
 *		����ֵ��
 *			�ɹ�����DSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_crypto_dsakey_new(NETCA_BigInteger p,NETCA_BigInteger q,NETCA_BigInteger g,NETCA_BigInteger y);

/*
 *		netca_crypto_dsakey_free
 *			�ͷ�DSA��Կ
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_dsakey_free(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_dup
 *			����DSA��Կ
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�DSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_DSAKey NETCAAPI netca_crypto_dsakey_dup(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getp
 *			��ȡDSA��Կ��p
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			�ɹ�����DSA��Կ��p��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getp(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getq
 *			��ȡDSA��Կ��q
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			�ɹ�����DSA��Կ��q��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getq(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_getg
 *			��ȡDSA��Կ��g
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			�ɹ�����DSA��Կ��g��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_getg(NETCA_Crypto_DSAKey key);
/*
 *		netca_crypto_dsakey_gety
 *			��ȡDSA��Կ��y
 *		������
 *			key��DSA��Կ
 *		����ֵ��
 *			�ɹ�����DSA��Կ��y��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_dsakey_gety(NETCA_Crypto_DSAKey key);

/*
 *		netca_crypto_dsactx_new
 *			����һ��DSA������
 *		������
 *			key��DSA��Կ
 *			hash��Hash����
 *		����ֵ��
 *			�ɹ�����DSA�����ģ�ʧ�ܷ���NULL
 */
NETCA_Crypto_DSACtx NETCAAPI netca_crypto_dsactx_new(NETCA_Crypto_DSAKey key,netca_md_func_cptr hash);
/*
 *		netca_crypto_dsactx_free
 *			�ͷ�DSA������
 *		������
 *			ctx��������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_dsactx_free(NETCA_Crypto_DSACtx ctx);

/*
 *		netca_crypto_dsa_verify_init
 *			��ʼ��DSA������
 *		������
 *			ctx��������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dsa_verify_init(NETCA_Crypto_DSACtx ctx);
/*
 *		netca_crypto_dsa_verify_update
 *			���Ҫ��֤ǩ��������
 *		������
 *			ctx��������
 *			data���������������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dsa_verify_update(NETCA_Crypto_DSACtx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_dsa_verify_final
 *			��֤DSAǩ��
 *		������
 *			ctx��������
 *			sign�����������ǩ��ֵ
 *			signlen�����������sign�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dsa_verify_final(NETCA_Crypto_DSACtx ctx,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_dsa_verifyhash
 *			��֤DSAǩ����������Hashֵ
 *		������
 *			ctx��������
 *			hash�����������Hashֵ
 *			hashlen�����������Hash����
 *			sign�����������ǩ��ֵ
 *			signlen�����������sign�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dsa_verifyhash(NETCA_Crypto_DSACtx ctx,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_dsa_verify_finalex
 *			��֤DSAǩ��
 *		������
 *			ctx��������
 *			r�����������ǩ��ֵ�е�r
 *			s�����������ǩ��ֵ�е�s
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dsa_verify_finalex(NETCA_Crypto_DSACtx ctx,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_crypto_rsakey_new
 *			����RSA��Կ
 *		������
 *			m�����������ģ
 *			e�������������Կָ��
 *		����ֵ��
 *			�ɹ�����RSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_crypto_rsakey_new(NETCA_BigInteger m,NETCA_BigInteger e);
/*
 *		netca_crypto_rsakey_free
 *			�ͷ�RSA��Կ
 *		������
 *			key��RSA��Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_rsakey_free(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_dup
 *			����RSA��Կ
 *		������
 *			key��RSA��Կ
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�RSA��Կ��ʧ�ܷ���NULL
 */
NETCA_Crypto_RSAKey NETCAAPI netca_crypto_rsakey_dup(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_getmodulus
 *			��ȡRSA��Կ��ģ
 *		������
 *			key��RSA��Կ
 *		����ֵ��
 *			�ɹ�����RSA��Կ��ģ��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_rsakey_getmodulus(NETCA_Crypto_RSAKey key);
/*
 *		netca_crypto_rsakey_getpubexp
 *			��ȡRSA��Կ�Ĺ�Կָ��
 *		������
 *			key��RSA��Կ
 *		����ֵ��
 *			�ɹ�����RSA��Կ�Ĺ�Կָ����ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_crypto_rsakey_getpubexp(NETCA_Crypto_RSAKey key);

/*
 *		netca_crypto_rsactx_new
 *			��ȡRSA������
 *		������
 *			key��RSA��Կ
 *			algo������������㷨
 *			param���������������
 *		����ֵ��
 *			�ɹ�����RSA�����ģ�ʧ�ܷ���NULL
 */
NETCA_Crypto_RSACtx NETCAAPI netca_crypto_rsactx_new(NETCA_Crypto_RSAKey key,long algo,void *param);
/*
 *		netca_crypto_rsactx_free
 *			�ͷ�RSA������
 *		������
 *			ctx��RSA������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_rsactx_free(NETCA_Crypto_RSACtx ctx);
/*
 *		netca_crypto_rsactx_sethashoid
 *			����RSA��֤��ʹ��DigestInfo���뻹�ǵ�����Hashֵ
 *		������
 *			ctx��RSA������
 *			usehashoid�����������Ϊ���ʾʹ��DigestInfo���룬Ϊ�ٱ�ʾʹ��Hashֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsactx_sethashoid(NETCA_Crypto_RSACtx ctx,int usehashoid);

/*
 *		netca_crypto_rsa_verify_init
 *			��֤ǩ����ʼ��
 *		������
 *			ctx��RSA������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsa_verify_init(NETCA_Crypto_RSACtx ctx);
/*
 *		netca_crypto_rsa_verify_update
 *			���ǩ��������
 *		������
 *			ctx��RSA������
 *			data�����������Ҫǩ��������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsa_verify_update(NETCA_Crypto_RSACtx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_rsa_verify_final
 *			��֤ǩ��
 *		������
 *			ctx��RSA������
 *			sign�����������ǩ��ֵ
 *			signlen�����������sign�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsa_verify_final(NETCA_Crypto_RSACtx ctx,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_rsa_verifyex
 *			��֤ǩ�����������ֻ�Ƕ�data����PKCS#1V1.5�Ľ������PSS����
 *		������
 *			ctx��RSA������
 *			data���������������
 *			datalen�����������data�ĳ���
 *			sign�����������ǩ��ֵ
 *			signlen�����������sign�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsa_verifyex(NETCA_Crypto_RSACtx ctx,const unsigned char *data,long datalen,const unsigned char *sign,long signlen);

/*
 *		netca_crypto_rsa_encrypt
 *			RSA����
 *		������
 *			ctx��RSA������
 *			clear���������������
 *			clearlen�����������clear�ĳ���
 *			cipher��������������ص�����
 *			cipherlen����������������������ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_rsa_encrypt(NETCA_Crypto_RSACtx ctx,const unsigned char *clear,int clearlen,unsigned char *cipher,int *cipherlen);


/*
 *		netca_ecc_newdomainparameters
 *			����ECC�����
 *		������
 *			name�����������ECC����������OID
 *		����ֵ��
 *			�ɹ�������Ч��ECC�������ʧ�ܷ���NULL
 */
NETCA_ECC_Domain_Parameters NETCAAPI netca_ecc_newdomainparameters(const char *name);


/*
 *		netca_ecc_domainparameters_getbits
 *			��ȡECC��Կ����
 *		������
 *			param����������������
 *		����ֵ��
 *			�ɹ�������Կ���ȣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_ecc_domainparameters_getbits(NETCA_ECC_Domain_Parameters param);


/*
 *		netca_ecc_domainparameters_getbits
 *			��ȡECC�������
 *		������
 *			param����������������
 *		����ֵ��
 *			�ɹ�����ECC������ƣ�ʧ�ܷ���NULL
 */
char* NETCAAPI netca_ecc_domainparameters_getname(NETCA_ECC_Domain_Parameters param);

/*
 *		netca_ecc_freedomainparameters
 *			�ͷ�ECC�����
 *		������
 *			param��ECC�����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ecc_freedomainparameters(NETCA_ECC_Domain_Parameters param);

/*
 *		netca_ecc_newpoint
 *			����һ��ECC��
 *		������
 *			x�����������������
 *			y�����������������
 *		����ֵ��
 *			�ɹ�������Ч��ECC�㣬ʧ�ܷ���NULL
 */
NETCA_ECC_Point NETCAAPI netca_ecc_newpoint(NETCA_BigInteger x, NETCA_BigInteger y);

/*
 *		netca_ecc_freepoint
 *			�ͷ�ECC��
 *		������
 *			point��ECC��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ecc_freepoint(NETCA_ECC_Point point);

/*
 *		netca_ecc_newpubkey
 *			����ECC��Կ
 *		������
 *			param��ECC�����
 *			Q��ECC��
 *		����ֵ��
 *			�ɹ�������Ч��ECC�㣬ʧ�ܷ���NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_ecc_newpubkey(NETCA_ECC_Domain_Parameters param,NETCA_ECC_Point Q);

/*
 *		netca_ecc_newpubkey
 *			����ECC��Կ
 *		������
 *			param��ECC�����
 *			data��ECC��ı���
 *			datalen��ECC��ı���ĳ���
 *		����ֵ��
 *			�ɹ�������Ч��ECC�㣬ʧ�ܷ���NULL
 */
NETCA_ECC_PubKey NETCAAPI netca_ecc_newpubkeyfromocts(NETCA_ECC_Domain_Parameters param,const unsigned char *data,int datalen);

/*
 *		netca_ecc_freepubkey
 *			�ͷ�ECC��Կ
 *		������
 *			pubKey��ECC��Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ecc_freepubkey(NETCA_ECC_PubKey pubKey);

/*
 *		netca_ecc_getdomainparametersfrompubkey
 *			��ECC��Կ��ȡ�����
 *		������
 *			pubKey��ECC��Կ
 *		����ֵ��
 *			�ɹ����ظ��������ʧ�ܷ���NULL
 */
NETCA_ECC_Domain_Parameters NETCAAPI netca_ecc_getdomainparametersfrompubkey(NETCA_ECC_PubKey pubKey);


/*
 *		netca_ecc_getpubkeypoint
 *			��ECC��Կ��ȡ��Կ�ĵ�
 *		������
 *			pubKey��ECC��Կ
 *		����ֵ��
 *			�ɹ����ظ���Կ�ĵ㣬ʧ�ܷ���NULL
 */
NETCA_ECC_Point NETCAAPI netca_ecc_getpubkeypoint(NETCA_ECC_PubKey pubKey);

/*
 *		netca_ecc_encode_point
 *			����ECC�ĵ�
 *		������
 *			keylen��ECC��Կλ��
 *			point��ECC�ĵ�
 *			data��ECC��ı���
 *			datalen��ECC��ı���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ecc_encode_point(int keylen,NETCA_ECC_Point point,unsigned char *data,int *datalen);

/*
 *		netca_ecc_ecdsa_verifyhash
 *			��֤ECDSAǩ��
 *		������
 *			pubKey��ECC��Կ
 *			hash�����������hashֵ
 *			hashlen�����������hash����
 *			r�����������ǩ����r
 *			s�����������ǩ����s
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ecc_ecdsa_verifyhash(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_ecc_ecdsa_verifyhashex
 *			��֤ECDSAǩ��
 *		������
 *			pubKey��ECC��Կ
 *			hash�����������hashֵ
 *			hashlen�����������hash����
 *			sign�����������ǩ��
 *			signlen�����������ǩ���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ecc_ecdsa_verifyhashex(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_ecc_sm2_verifyhash
 *			��֤ECDSAǩ��
 *		������
 *			pubKey��ECC��Կ
 *			hash�����������hashֵ����Za��Ҫǩ�����ݵ�hashֵ��
 *			hashlen�����������hash����
 *			r�����������ǩ����r
 *			s�����������ǩ����s
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ecc_sm2_verifyhash(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,NETCA_BigInteger r,NETCA_BigInteger s);

/*
 *		netca_ecc_sm2_verifyhashex
 *			��֤ECDSAǩ��
 *		������
 *			pubKey��ECC��Կ
 *			hash�����������hashֵ����Za��Ҫǩ�����ݵ�hashֵ��
 *			hashlen�����������hash����
 *			sign�����������ǩ��
 *			signlen�����������ǩ���ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ecc_sm2_verifyhashex(NETCA_ECC_PubKey pubKey,const unsigned char *hash,int hashlen,const unsigned char *sign,long signlen);

/*
 *		netca_sm9_masterkey_generate
 *			����SM9����Կ��
 *		������
 *			type�������������Կ����
 *			hid�����������˽Կ���ɺ���ʶ���
 *		����ֵ��
 *			�ɹ����ز���SM9������Կ��ʧ�ܷ���NULL
 */
NETCA_SM9_MasterKey NETCAAPI netca_sm9_masterkey_generate(int type,int hid);
/*
 *		netca_sm9_masterkey_free
 *			�ͷ�SM9����Կ
 *		������
 *			key�����������SM9����Կ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_sm9_masterkey_free(NETCA_SM9_MasterKey key);

/*
 *		netca_sm9_masterkey_gettype
 *			��ȡSM9����Կ������
 *		������
 *			key�����������SM9����Կ
 *		����ֵ��
 *			�ɹ�����SM9����Կ�����ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_sm9_masterkey_gettype(NETCA_SM9_MasterKey key);

/*
 *		netca_sm9_masterkey_gethid
 *			��ȡSM9����Կ��hid
 *		������
 *			key�����������SM9����Կ
 *		����ֵ��
 *			�ɹ�����SM9����Կ��hid��ʧ�ܷ���-1
 */
int NETCAAPI netca_sm9_masterkey_gethid(NETCA_SM9_MasterKey key);

/*
 *		netca_sm9_masterkey_dup
 *			����SM9����Կ
 *		������
 *			key�����������SM9����Կ
 *		����ֵ��
 *			�ɹ����ظ��ƺ��SM9������Կ��ʧ�ܷ���NULL
 */
NETCA_SM9_MasterKey NETCAAPI netca_sm9_masterkey_dup(NETCA_SM9_MasterKey key);

/*
 *		netca_sm9_masterkey_export_publickey
 *			����SM9����Կ
 *		������
 *			key�����������SM9����Կ
 *			data������������ɹ����ع�Կ����
 *			dataLen������������ɹ�����data���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_masterkey_export_publickey(NETCA_SM9_MasterKey key,unsigned char **data,int *dataLen);

/*
 *		netca_sm9_masterkey_export_keypair
 *			����SM9����Կ��
 *		������
 *			key�����������SM9����Կ
 *			data������������ɹ�������Կ�Ա���
 *			dataLen������������ɹ�����data���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_masterkey_export_keypair(NETCA_SM9_MasterKey key,unsigned char **data,int *dataLen);

/*
 *		netca_sm9_masterkey_import_publickey
 *			���ݱ������SM9����Կ
 *		������
 *			data�������������Կ����
 *			dataLen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ����ز���SM9������Կ��ʧ�ܷ���NULL
 */
NETCA_SM9_MasterKey NETCAAPI netca_sm9_masterkey_import_publickey(const unsigned char *data,int dataLen);

/*
 *		netca_sm9_masterkey_import_keypair
 *			���ݱ������SM9����Կ��
 *		������
 *			data�������������Կ�Ա���
 *			dataLen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ����ز���SM9������Կ�ԣ�ʧ�ܷ���NULL
 */
NETCA_SM9_MasterKey NETCAAPI netca_sm9_masterkey_import_keypair(const unsigned char *data,int dataLen);

/*
 *		netca_sm9_userkey_generate
 *			����SM9�û���Կ��
 *		������
 *			masterKey�����������SM9����Կ��
 *			hashAlgo�����������Hash�㷨
 *			id������������û�ID
 *			idLen������������û�ID����
 *			userKey������������ɹ������û�����Կ��
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_userkey_generate(NETCA_SM9_MasterKey masterKey,int hashAlgo,const unsigned char *id,int idLen,NETCA_SM9_UserKeyPair *userKey);
/*
 *		netca_sm9_userkey_free
 *			�ͷ�SM9�û���Կ��
 *		������
 *			key�����������SM9�û���Կ��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_sm9_userkey_free(NETCA_SM9_UserKeyPair key);

/*
 *		netca_sm9_masterkey_getfromuserkey
 *			���û���Կ���л�ȡ����Կ
 *		������
 *			key�����������SM9�û���Կ��
 *		����ֵ��
 *			�ɹ���������Կ��ʧ�ܷ���null
 */
NETCA_SM9_MasterKey NETCAAPI netca_sm9_masterkey_getfromuserkey(NETCA_SM9_UserKeyPair key);

/*
 *		netca_sm9_userkey_export
 *			����SM9�û���Կ��
 *		������
 *			key�����������SM9�û���Կ
 *			data������������ɹ�������Կ�Ա���
 *			dataLen������������ɹ�����data���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_userkey_export(NETCA_SM9_UserKeyPair key,unsigned char **data,int *dataLen);

/*
 *		netca_sm9_userkey_getid
 *			��ȡ�û���ʶ
 *		������
 *			key�����������SM9�û���Կ
 *			data������������ɹ������û���ʶ
 *			dataLen������������ɹ�����data���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_userkey_getid(NETCA_SM9_UserKeyPair key,unsigned char **data,int *dataLen);

/*
 *		netca_sm9_userkey_import
 *			���ݱ������SM9�û���Կ��
 *		������
 *			data�������������Կ�Ա���
 *			dataLen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ����ز���SM9���û���Կ�ԣ�ʧ�ܷ���NULL
 */
NETCA_SM9_UserKeyPair NETCAAPI netca_sm9_userkey_import(const unsigned char *data,int dataLen);

/*
 *		netca_sm9_sign
 *			SM9ǩ��
 *		������
 *			userKey�����������SM9�û�����Կ��
 *			hashAlgo�����������Hash�㷨
 *			M�����������Ҫǩ��������
 *			MLen�����������M���ֽ���
 *			signature������������ɹ�����ǩ��ֵ����ʽΪh||S
 *			signatureLen������������ɹ�����signature���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_sign(NETCA_SM9_UserKeyPair userKey,int hashAlgo,const unsigned char *M,int MLen,unsigned char **signature,int *signatureLen);

/*
 *		netca_sm9_signhash
 *			SM9ǩ��
 *		������
 *			userKey�����������SM9�û�����Կ��
 *			hHash�����������Hash������Ѿ�����0x02||M������
 *			signature������������ɹ�����ǩ��ֵ����ʽΪh||S
 *			signatureLen������������ɹ�����signature���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_signhash(NETCA_SM9_UserKeyPair userKey,NETCA_PKI_HASH_HANDLE hHash,unsigned char **signature,int *signatureLen);

/*
 *		netca_sm9_verifyhash
 *			��֤SM9ǩ��
 *		������
 *			masterKey�����������SM9����Կ
 *			id������������û�ID
 *			idLen������������û�ID����
 *			hHash�����������Hash������Ѿ�����0x02||M������
 *			signature�����������ǩ��ֵ����ʽΪh||S
 *			signatureLen�����������signature���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_verifyhash(NETCA_SM9_MasterKey masterKey,const unsigned char *id,int idLen,NETCA_PKI_HASH_HANDLE hHash,const unsigned char *signature,int signatureLen);

/*
 *		netca_sm9_verify
 *			��֤SM9ǩ��
 *		������
 *			masterKey�����������SM9����Կ
 *			id������������û�ID
 *			idLen������������û�ID����
 *			hashAlgo�����������Hash�㷨
 *			M�����������Ҫǩ��������
 *			MLen�����������M���ֽ���
 *			signature�����������ǩ��ֵ����ʽΪh||S
 *			signatureLen�����������signature���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_verify(NETCA_SM9_MasterKey masterKey,const unsigned char *id,int idLen,int hashAlgo,const unsigned char *M,int MLen,const unsigned char *signature,int signatureLen);

/*
 *		netca_sm9_generate_key
 *			SM9��Կ��װ
 *		������
 *			masterKey�����������SM9����Կ
 *			id������������û�ID
 *			idLen������������û�ID����
 *			hashAlgo�����������Hash�㷨
 *			keyLen�����������Ҫ��������Կ�ֽ���
 *			outData������������ɹ�������Կ��װ����ʽΪK||C
 *			outLen������������ɹ�����outData���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_generate_key(NETCA_SM9_MasterKey masterKey,const unsigned char *id,int idLen,int hashAlgo,int keyLen,unsigned char **outData,int *outLen);

/*
 *		netca_sm9_encrypt
 *			SM9����
 *		������
 *			masterKey�����������SM9����Կ
 *			id������������û�ID
 *			idLen������������û�ID����
 *			hashAlgo�����������Hash�㷨
 *			macKeyLen�����������Ҫ������MAC��Կ�ֽ���
 *			inData�����������Ҫ���ܵ�����
 *			inLen��������������ĳ���
 *			outData������������ɹ����ؼ��ܵõ������ģ���ʽΪC1||C3||C2
 *			outLen������������ɹ�����outData���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_encrypt(NETCA_SM9_MasterKey masterKey,const unsigned char *id,int idLen,int hashAlgo,int macKeyLen,const unsigned char* inData,int inLen,unsigned char **outData,int *outLen);


/*
 *		netca_sm9_decrypt_key
 *			SM9��Կ���װ
 *		������
 *			userKey������������û���Կ��
 *			hashAlgo�����������Hash�㷨
 *			c�������������װ���ġ���ѹ������
 *			cLen�����������c���ֽ���
 *			keyLen�����������Ҫ��������Կ�ֽ���
 *			key������������ɹ�����������Կ
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_decrypt_key(NETCA_SM9_UserKeyPair userKey,int hashAlgo,const unsigned char *c,int cLen,int keyLen,unsigned char *key);

/*
 *		netca_sm9_decrypt
 *			SM9��Կ����
 *		������
 *			userKey������������û���Կ��
 *			hashAlgo�����������Hash�㷨
 *			macKeyLen�����������MAC��Կ�ĳ���
 *			cipherText���������������
 *			cipherLen��������������ĳ���
 *			clearText������������ɹ���������
 *			clearLen������������ɹ����������ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_decrypt(NETCA_SM9_UserKeyPair userKey,int hashAlgo,int macKeyLen,const unsigned char *cipherText,int cipherLen,unsigned char **clearText,int* clearLen);

/*
 *		netca_sm9_sender_keyexchange_1ststep
 *			SM9��Կ�������𷽵�һ��
 *		������
 *			masterKey���������������Կ
 *			idb�������������Ӧ����ID
 *			idbLen�����������idb���ֽ���
 *			hashAlgo�����������Hash�㷨
 *			ra������������ɹ�����ra
 *			raLen������������ɹ�����ra���ֽ���
 *			Ra������������ɹ�����Ҫ���͸���Ӧ����Ra
 *			RaLen������������ɹ�����Ra���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_sender_keyexchange_1ststep(NETCA_SM9_MasterKey masterKey,const unsigned char *idb,int idbLen,int hashAlgo,unsigned char **ra,int *raLen,unsigned char **Ra,int *RaLen);

/*
 *		netca_sm9_receiver_keyexchange
 *			SM9��Ӧ����Կ����
 *		������
 *			userKey�������������Ӧ���û���Կ
 *			ida��������������ͷ���ID
 *			idaLen�����������ida���ֽ���
 *			hashAlgo�����������Hash�㷨
 *			Ra��������������ͷ�����Ӧ����Ra
 *			RaLen�����������Ra���ֽ���
 *			keyLen�������������������Կ���ֽ���
 *			key�������������������Կ
 *			Rb�������������Ӧ�����͸����ͷ���Rb
 *			RbLen�����������Rb���ֽ�
 *			confirm������������Ƿ�Ҫȷ�ϣ����Ϊ0�������4���������÷���
 *			Sa�����������Sa
 *			SaLen�����������Sa���ֽ���
 *			Sb�����������Sb
 *			SbLen�����������Sb���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_receiver_keyexchange(NETCA_SM9_UserKeyPair userKey,const unsigned char *ida,int idaLen,int hashAlgo,const unsigned char *Ra,int RaLen,int keyLen,unsigned char *key,unsigned char **Rb,int *RbLen,int confirm,unsigned char **Sa,int *SaLen,unsigned char **Sb,int *SbLen);
/*
 *		netca_sm9_sender_keyexchange
 *			SM9���ͷ���Կ����
 *		������
 *			userKey�������������Ӧ���û���Կ
 *			idb�������������Ӧ����ID
 *			idbLen�����������idb���ֽ���
 *			hashAlgo�����������Hash�㷨
 *			ra��������������ͷ���ra
 *			raLen�����������ra���ֽ���
 *			Ra��������������ͷ���Ra
 *			RaLen�����������Ra���ֽ���
 *			Rb�������������Ӧ����Rb
 *			RbLen�����������Rb���ֽ���
 *			keyLen�������������������Կ���ֽ���
 *			key�������������������Կ
 *			confirm������������Ƿ�Ҫȷ�ϣ����Ϊ0�������4���������÷���
 *			Sa�����������Sa
 *			SaLen�����������Sa���ֽ���
 *			Sb�����������Sb
 *			SbLen�����������Sb���ֽ���
 *		����ֵ��
 *			�ɹ�NETCA_PKI_SUCCESS,ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_sm9_sender_keyexchange(NETCA_SM9_UserKeyPair userKey,const unsigned char *idb,int idbLen,int hashAlgo,const unsigned char *ra,int raLen,const unsigned char *Ra,int RaLen,const unsigned char *Rb,int RbLen,int keyLen,unsigned char *key,int confirm,unsigned char **Sa,int *SaLen,unsigned char **Sb,int *SbLen);

/*
 *		netca_privkey_list_init
 *			˽Կ������ʼ��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_privkey_list_init(void);
/*
 *		netca_privkey_list_end
 *			�ͷ�˽Կ����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_privkey_list_end(void);

/*
 *		netca_crypto_privkey_new
 *			��ȡ˽Կ
 *		������
 *			attr�����������˽Կ����
 *			pwd�����������˽Կ���룬����ΪNULL
 *		����ֵ��
 *			�ɹ�����˽Կ��ʧ�ܷ���NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_crypto_privkey_new(NETCA_PrivKey_Attr attr,const char *pwd);
/*
 *		netca_crypto_privkey_free
 *			�ͷ�˽Կ
 *		������
 *			handle��˽Կ���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_privkey_free(NETCA_PrivKey_Handle handle);

/*
 *		netca_crypto_privkey_sign
 *			ǩ��
 *		������
 *			handle��˽Կ���
 *			algoid�����������ǩ���㷨
 *			param�����������ǩ���㷨����
 *			data�����������Ҫǩ��������
 *			datalen�����������data�ĳ���
 *			sign��������������ص�ǩ��ֵ
 *			signlen������������������ص�ǩ��ֵ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_sign(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *data,int datalen,unsigned char *sign,int *signlen);
/*
 *		netca_crypto_privkey_decrypt
 *			˽Կ����
 *		������
 *			handle��˽Կ���
 *			algoid����������������㷨
 *			param����������������㷨����
 *			data���������������
 *			datalen�����������data�ĳ���
 *			clear��������������ص�����
 *			clearlen������������������ص����ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_decrypt(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *data,int datalen,unsigned char *clear,int *clearlen);

/*
 *		netca_crypto_privkey_sign_init
 *			��ʼ��ǩ��
 *		������
 *			handle��˽Կ���
 *			algoid�����������ǩ���㷨
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_sign_init(NETCA_PrivKey_Handle handle,int algoid);
/*
 *		netca_crypto_privkey_sign_update
 *			���Ҫǩ��������
 *		������
 *			handle��˽Կ���
 *			data�����������Ҫǩ��������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_sign_update(NETCA_PrivKey_Handle handle,const unsigned char *data,int datalen);
/*
 *		netca_crypto_privkey_sign_final
 *			ǩ��
 *		������
 *			handle��˽Կ���
 *			param�����������ǩ���㷨����
 *			sign��������������ص�ǩ��ֵ
 *			signlen������������������ص�ǩ��ֵ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_sign_final(NETCA_PrivKey_Handle handle,void *param,unsigned char *sign,int *signlen);
/*
 *		netca_crypto_privkey_sign_hash
 *			ǩ��
 *		������
 *			handle��˽Կ���
 *			algoid�����������ǩ���㷨
 *			param�����������ǩ���㷨����
 *			hash�����������hashֵ
 *			hashlen�����������hash�ĳ���
 *			sign��������������ص�ǩ��ֵ
 *			signlen������������������ص�ǩ��ֵ����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_sign_hash(NETCA_PrivKey_Handle handle,int algoid,void *param,const unsigned char *hash,int hashlen,unsigned char *sign,int *signlen);

/*
 *		netca_crypto_privkey_attr_free
 *			�ͷ�˽Կ����
 *		������
 *			attr��˽Կ����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_privkey_attr_free(NETCA_PrivKey_Attr attr);
/*
 *		netca_crypto_privkey_attr_needpwd
 *			�ж�˽Կ�����Ƿ���Ҫ����
 *		������
 *			attr��˽Կ����
 *		����ֵ��
 *			���˽Կ������Ҫ���뷵��1�����򷵻�0
 */
int NETCAAPI netca_crypto_privkey_attr_needpwd(NETCA_PrivKey_Attr attr);
/*
 *		netca_crypto_privkey_gen
 *			����˽Կ
 *		������
 *			attr��˽Կ����
 *			pwd���������������
 *			alogId�������������Կ���㷨
 *			keybits�������������Կ�Գ���
 *			param�������������ز���
 *		����ֵ��
 *			�ɹ�����˽Կ��ʧ�ܷ���NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_crypto_privkey_gen(NETCA_PrivKey_Attr attr,const char *pwd,int alogId,int keybits,void *param);
/*
 *		netca_crypto_privkey_getpubkey
 *			��ȡ��Կ
 *		������
 *			handle��˽Կ
 *			pubkey��������������صĹ�Կ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_privkey_getpubkey(NETCA_PrivKey_Handle handle,void **pubkey);

/*
 *		netca_cert_getprivkey
 *			��ȡ˽Կ
 *		������
 *			cert��֤��
 *			pwd���������������
 *		����ֵ��
 *			�ɹ�����˽Կ��ʧ�ܷ���NULL
 */
NETCA_PrivKey_Handle NETCAAPI netca_cert_getprivkey(NETCA_CERT cert,const char *pwd);

#ifdef _WIN32
#include <wincrypt.h>
/*
 *		netca_mskeyprovinfo2privkeyattr
 *			��ȡ˽Կ����
 *		������
 *			provinfo���ṩ����Ϣ
 *		����ֵ��
 *			�ɹ�����˽Կ���ԣ�ʧ�ܷ���NULL
 */
NETCA_PrivKey_Attr NETCAAPI netca_mskeyprovinfo2privkeyattr(PCRYPT_KEY_PROV_INFO provinfo);
#endif

/*
 *		netca_crypto_prng_init
 *			��ʼ�������������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_prng_init(void);
/*
 *		netca_crypto_prng_seed
 *			���������������������
 *		������
 *			data���������������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_prng_seed(const unsigned char *data,long datalen);
/*
 *		netca_crypto_prng_getrand
 *			��ȡ�����
 *		������
 *			data��������������ص������
 *			datalen�����������������ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_prng_getrand(unsigned char *data,long datalen);

#define NETCA_PKCS12_FALG_USEALLUNICOE					0x1
#define NETCA_PKCS12_FALG_MSTRUN						0x2

/*
 *		netca_crypto_pbkdf1
 *			���ݿ��������Կ��ʹ��PKCS#5V1�ķ���
 *		������
 *			md_func�����������Hash����
 *			pwd���������������
 *			pwdlen�����������pwd�ĳ���
 *			salt�������������
 *			saltlen�����������salt�ĳ���
 *			iter�������������������
 *			keylen�������������Կ����
 *			key�����������������Կֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_pbkdf1(netca_md_func_cptr md_func,const unsigned char *pwd,long pwdlen,const unsigned char *salt,long saltlen,int iter ,long keylen,unsigned char *key);
/*
 *		netca_crypto_pbkdf2_hmac
 *			���ݿ��������Կ��ʹ��PKCS#5V2�ķ���
 *		������
 *			md_func�����������Hash����
 *			pwd���������������
 *			pwdlen�����������pwd�ĳ���
 *			salt�������������
 *			saltlen�����������salt�ĳ���
 *			iter�������������������
 *			keylen�������������Կ����
 *			key�����������������Կֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_pbkdf2_hmac(netca_md_func_cptr md_func,const unsigned char *pwd,long pwdlen,const unsigned char *salt,long saltlen,int iter ,long keylen,unsigned char *key);
/*
 *		netca_crypto_pkcs12_kdf
 *			���ݿ��������Կ��ʹ��PKCS#12�ķ���
 *		������
 *			md_func�����������Hash����
 *			pwd���������������
 *			ID�����������ID
 *			salt�������������
 *			saltlen�����������salt�ĳ���
 *			iter�������������������
 *			flag�������������־
 *			keylen�������������Կ����
 *			key�����������������Կֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_pkcs12_kdf(netca_md_func_cptr md_func,NETCA_UString pwd,int ID,const unsigned char *salt,long saltlen,int iter ,int flag,long keylen,unsigned char *key);
/*
 *		netca_crypto_dh_kdf
 *			����DHЭ�̵õ������ݲ�����Կ
 *		������
 *			md_func�����������Hash����
 *			zz�����������DHЭ�̵õ�������
 *			plen�����������p�ĳ���
 *			kekoid�����������KEK��OID
 *			partyainfo�����������partyainfo
 *			partyainfolen�����������partyainfo�ĳ���
 *			keylen�������������Կ����
 *			key�����������������Կֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_dh_kdf(netca_md_func_cptr md_func,NETCA_BigInteger zz,long plen,const char *kekoid,const unsigned char *partyainfo,long partyainfolen,long keylen,unsigned char *key);

/*
 *		netca_crypto_keywrap
 *			�öԳ���Կ������һ�Գ���Կ
 *		������
 *			algo�����������keywrap�㷨
 *			ishmackey�����������Ϊ����HMAC����Կ��Ϊ�ٲ���
 *			kek������������������ܵ���Կ
 *			keklen�����������kek�ĳ���
 *			cek����������������ܵ���Կ
 *			ceklen�����������cek�ĳ���
 *			keywrap���������������keywrapֵ
 *			keywraplen�������������������keywrap�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_keywrap(int algo,int ishmackey,const unsigned char *kek,int keklen,long effkekbits,const unsigned char *cek,long ceklen,unsigned char *keywrap,long *keywraplen);
/*
 *		netca_crypto_keyunwrap
 *			keyunwrap
 *		������
 *			algo�����������keywrap�㷨
 *			ishmackey�����������Ϊ����HMAC����Կ��Ϊ�ٲ���
 *			kek������������������ܵ���Կ
 *			keklen�����������kek�ĳ���
 *			keywrap�����������Ҫ���ܵ�keywrapֵ
 *			keywraplen�����������keywrap�ĳ���
 *			cek��������������ؽ��ܵõ�����Կ
 *			ceklen�������������������cek�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_keyunwrap(int algo,int ishmackey,const unsigned char *kek,int keklen,long effkekbits,const unsigned char *keywrap,long keywraplen,unsigned char *cek,long *ceklen);

/*
 *		netca_newrsaprivkeyattr
 *			��ȡ˽Կ����
 *		������
 *			data�����������˽Կ���Եı���
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
NETCA_PrivKey_Attr NETCAAPI netca_newrsaprivkeyattr(const unsigned char *data,long datalen);

#ifdef __cplusplus
	}	
#endif
#endif


