#ifndef NETCA_CRYPTO_ENCRYPT_INLCUDE_H
#define NETCA_CRYPTO_ENCRYPT_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"


#ifdef __cplusplus
extern "C"
	{
#endif

#ifndef NETCA_CRYPT_BLOCK_MAXBYTELEN
	#define NETCA_CRYPT_BLOCK_MAXBYTELEN	32
#endif

#define NETCA_CRYPTO_TYPE_BLOCK		0
#define NETCA_CRYPTO_TYPE_STREAM	1
#define NETCA_CRYPTO_TYPE_MASK		1


#define NETCA_CRYPTO_TYPE_ARC4		0x3
#define NETCA_CRYPTO_TYPE_ZUC		0x5

#define NETCA_CRYPTO_TYPE_DES			0x2
#define NETCA_CRYPTO_TYPE_3DES			0x4
#define NETCA_CRYPTO_TYPE_RC2			0x6
#define NETCA_CRYPTO_TYPE_AES			0x8
#define NETCA_CRYPTO_TYPE_SSF33			0xA
#define NETCA_CRYPTO_TYPE_SM1			0xC
#define NETCA_CRYPTO_TYPE_SMS4			0xE
#define NETCA_CRYPTO_TYPE_SM4			0xE

#define NETCA_CRYPTO_MODE_ECB			1
#define NETCA_CRYPTO_MODE_CBC			2
#define NETCA_CRYPTO_MODE_CFB			3
#define NETCA_CRYPTO_MODE_OFB			4
#define NETCA_CRYPTO_MODE_CTR			5
#define NETCA_CRYPTO_MODE_XTS			6
#define NETCA_CRYPTO_MODE_BC			7
#define NETCA_CRYPTO_MODE_OFBNLF		8


#define NETCA_CRYPTO_PADDING_NONE		1
#define NETCA_CRYPTO_PADDING_PKCS5		2

#define NETCA_CRYPTO_PARAMTYPE_IV		1
#define NETCA_CRYPTO_PARAMTYPE_CFBPARAM	2
#define NETCA_CRYPTO_PARAMTYPE_CTRPARAM	3
#define NETCA_CRYPTO_PARAMTYPE_EFFECTIVE_KEY_BITS	4
#define NETCA_CRYPTO_PARAMTYPE_BLOCK_BITS	5
#define NETCA_CRYPTO_PARAMTYPE_ROUND_BITS	6
#define NETCA_CRYPTO_PARAMTYPE_TWEAK		7



typedef void *(*new_encryptctx_ptr)(const unsigned char *key,long keylen);
typedef void (*free_encryptctx_ptr)(void *encrypt_ctx);
typedef int (*get_encrypt_type_ptr)(void);
typedef int (*encrypt_ptr)(void *encrypt_ctx,const unsigned char *in,long inlen,unsigned char *out);
typedef int (*decrypt_ptr)(void *encrypt_ctx,const unsigned char *in,long inlen,unsigned char *out);
typedef long (*get_block_bits_ptr)(void *encrypt_ctx);
typedef int (*isweakkey_ptr)(void *encrypt_ctx);
typedef int (*set_effective_keybits_ptr)(void *encrypt_ctx,long keybits);
typedef int (*set_block_bits_ptr)(void *encrypt_ctx,long blockbits);
typedef int (*set_round_ptr)(void *encrypt_ctx,long round);

struct netca_encrypt_func_st{
	new_encryptctx_ptr new_encryptctx;
	free_encryptctx_ptr free_encryptctx;
	get_encrypt_type_ptr get_encrypt_type;
	encrypt_ptr encrypt;
	decrypt_ptr decrypt;
	get_block_bits_ptr get_block_length;
	isweakkey_ptr isweakkey;
	set_effective_keybits_ptr set_effective_keybits;
	set_block_bits_ptr set_block_length;
	set_round_ptr set_round;
};

struct netca_encrypt_cfbparam_st{
	long m_bits;
	unsigned char m_iv[NETCA_CRYPT_BLOCK_MAXBYTELEN];
};

struct netca_encrypt_ctrparam_st{
	long m_bits;
	unsigned char m_iv[NETCA_CRYPT_BLOCK_MAXBYTELEN];
};


/*
 *		netca_crypto_arc4_function
 *			ARC4函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回ARC4函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_arc4_function(void);
/*
 *		netca_crypto_des_function
 *			DES函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回DES函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_des_function(void);
/*
 *		netca_crypto_3des_function
 *			3DES函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回3DES函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_3des_function(void);
/*
 *		netca_crypto_rc2_function
 *			RC2函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回RC2函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_rc2_function(void);
/*
 *		netca_crypto_aes_function
 *			AES函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回AES函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_aes_function(void);

/*
 *		netca_crypto_sms4_function
 *			AES函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SMS4函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_sms4_function(void);

/*
 *		netca_crypto_zuc_function
 *			祖冲之算法函数，要求key为Key||IV
 *		参数：
 *			无
 *		返回值：
 *			成功返回ARC4函数，失败返回NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_zuc_function(void);

/*
 *		netca_crypto_newcontext
 *			创建加密上下文
 *		参数：
 *			encrypt_func：输入参数，加密函数
 *			key：输入参数，密钥
 *			keylen：输入参数，key的长度
 *			mode：输入参数，分组加密模式
 *			padding：输入参数，填充模式
 *			enc：输入参数，为真表示加密，为家表示解密
 *		返回值：
 *			成功返回加密上下文，失败返回NULL
 */
NETCA_Crypto_Ctx NETCAAPI netca_crypto_newcontext(netca_encrypt_func_cptr encrypt_func,const unsigned char *key,long keylen,int mode,int padding,int enc);
/*
 *		netca_crypto_update
 *			进行加解密
 *		参数：
 *			ctx：加密上下文
 *			in：输入参数，输入的数据
 *			inlen：输入参数，in的长度
 *			out：输出参数，返回输出的数据
 *			outlen：输入输出参数，返回输出的数据的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_update(NETCA_Crypto_Ctx ctx,const unsigned char *in,long inlen,unsigned char *out,long *outlen);
/*
 *		netca_crypto_final
 *			结束加解密
 *		参数：
 *			ctx：加密上下文
 *			out：输出参数，返回输出的数据
 *			remlen：输入输出参数，返回输出的数据的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_final(NETCA_Crypto_Ctx ctx,unsigned char *out,long *remlen);
/*
 *		netca_crypto_getalgo
 *			获取加密算法
 *		参数：
 *			ctx：加密上下文
 *		返回值：
 *			成功返回加密算法，失败返回-1
 */
int NETCAAPI netca_crypto_getalgo(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_getblocklen
 *			获取分组长度
 *		参数：
 *			ctx：加密上下文
 *		返回值：
 *			成功返回分组长度，失败返回-1
 */
long NETCAAPI netca_crypto_getblocklen(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_setparam
 *			设置加密参数
 *		参数：
 *			ctx：加密上下文
 *			type：输入参数，参数类型
 *			param：输入参数，参数值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_crypto_setparam(NETCA_Crypto_Ctx ctx,long type,void *param);
/*
 *		netca_crypto_freecontext
 *			释放加密上下文
 *		参数：
 *			ctx：加密上下文
 *		返回值：
 *			无
 */
void NETCAAPI netca_crypto_freecontext(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_getremdatalength
 *			获取加密上下文中未处理数据的长度
 *		参数：
 *			ctx：加密上下文
 *		返回值：
 *			成功返回加密上下文中未处理数据的长度，失败返回-1
 */
long NETCAAPI netca_crypto_getremdatalength(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_isweakkey
 *			判断是否是弱密钥
 *		参数：
 *			ctx：加密上下文
 *		返回值：
 *			如果是弱密钥，返回1，否则返回0
 */
int NETCAAPI netca_crypto_isweakkey(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_des_normkey
 *			规范化DES密钥
 *		参数：
 *			key：输入输出参数，DES或3DES密钥
 *			keylen：输入参数，key的长度
 *		返回值：
 *			如果是弱密钥，返回1，否则返回0
 */
int NETCAAPI netca_crypto_des_normkey(unsigned char *key,long keylen);

/*
 *		netca_stream_new_cipher
 *			创建加密流
 *		参数：
 *			encctx：加密上下文
 *			decctx：解密上下文
 *			errctx：错误上下文
 *		返回值：
 *			成功返回加密流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_cipher(NETCA_Crypto_Ctx encctx,NETCA_Crypto_Ctx decctx,NETCA_ERR_CTX errctx);


#ifdef __cplusplus
	}	
#endif
#endif
