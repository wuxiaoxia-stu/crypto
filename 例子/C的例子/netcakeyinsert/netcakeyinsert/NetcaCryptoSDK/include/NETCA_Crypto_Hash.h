#ifndef NETCA_CRYPTO_HASH_INLCUDE_H
#define NETCA_CRYPTO_HASH_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Crypto_Type.h"
#include "NETCA_Stream.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#ifndef NETCA_HASH_MAX_LENGTH
	#define NETCA_HASH_MAX_LENGTH	128
#endif

/*
 *		netca_crypto_sha1_function
 *			SHA1函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA1函数，失败返回NULL
 */
netca_md_func_cptr NETCAAPI netca_crypto_sha1_function(void);
/*
 *		netca_crypto_md5_function
 *			MD5函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回MD5函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_md5_function(void);

/*
 *		netca_crypto_sha256_function
 *			SHA256函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA256函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha256_function(void);
/*
 *		netca_crypto_sha224_function
 *			SHA224函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA224函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha224_function(void);
/*
 *		netca_crypto_sha384_function
 *			SHA384函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA384函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha384_function(void);
/*
 *		netca_crypto_sha512_function
 *			SHA512函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA512函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_function(void);


/*
 *		netca_crypto_sha512_224_function
 *			SHA-512/224函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA-512/224函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_224_function(void);

/*
 *		netca_crypto_sha512_256_function
 *			SHA-512/256函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA-512/256函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_256_function(void);

/*
 *		netca_crypto_sm3_function
 *			SM3函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SM3函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sm3_function(void);

/*
 *		netca_crypto_sha3_224_function
 *			SHA3-224函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA3-224函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_224_function(void);

/*
 *		netca_crypto_sha3_256_function
 *			SHA3-256函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA3-256函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_256_function(void);

/*
 *		netca_crypto_sha3_384_function
 *			SHA3-256函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA3-384函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_384_function(void);

/*
 *		netca_crypto_sha3_512_function
 *			SHA3-256函数
 *		参数：
 *			无
 *		返回值：
 *			成功返回SHA3-512函数，失败返回NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_512_function(void);

/*
 *		netca_crypto_hash
 *			Hash数据
 *		参数：
 *			md_func：输入参数，Hash函数
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hash(netca_md_func_cptr md_func,const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha1
 *			SHA1
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sha1(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_md5
 *			MD5
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_md5(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha224
 *			SHA224
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sha224(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha256
 *			SHA256
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sha256(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha384
 *			SHA384
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sha384(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha512
 *			SHA512
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sha512(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);

/*
 *		netca_crypto_sm3
 *			SM3
 *		参数：
 *			data：输入参数，进行Hash的数据
 *			datalen：输入参数，data的长度
 *			md：输出参数，返回的Hash值
 *			mdlen：输入输出参数，返回的Hash长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_sm3(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_hash_new
 *			创建Hash上下文
 *		参数：
 *			md_func：输入参数，Hash函数
 *		返回值：
 *			成功返回Hash上下文，失败返回其他值
 */	
NETCA_Hash_Ctx NETCAAPI netca_crypto_hash_new(netca_md_func_cptr md_func);
/*
 *		netca_crypto_hash_gethashlength
 *			获取Hash值的长度
 *		参数：
 *			ctx：Hash上下文
 *		返回值：
 *			成功返回Hash值的长度，失败返回-1
 */	
int NETCAAPI netca_crypto_hash_gethashlength(NETCA_Hash_Ctx ctx);
/*
 *		netca_crypto_hash_getblocklength
 *			获取Hash的分组长度
 *		参数：
 *			ctx：Hash上下文
 *		返回值：
 *			成功返回Hash分组的长度，失败返回-1
 */	
int NETCAAPI netca_crypto_hash_getblocklength(NETCA_Hash_Ctx ctx);
/*
 *		netca_crypto_hash_getblocklength
 *			Hash数据
 *		参数：
 *			ctx：Hash上下文
 *			data：输入参数，要处理的数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hash_update(NETCA_Hash_Ctx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_hash_final
 *			结束Hash运算，获取Hash值
 *		参数：
 *			ctx：Hash上下文
 *			md：输出参数，返回Hash值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hash_final(NETCA_Hash_Ctx ctx,unsigned char *md);
/*
 *		netca_crypto_hash_reset
 *			重置Hash上下文状态
 *		参数：
 *			ctx：Hash上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hash_reset(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hash_dup
 *			复制Hash上下文
 *		参数：
 *			ctx：Hash上下文
 *		返回值：
 *			成功返回复制的Hash上下文，失败返回NULL
 */	
NETCA_Hash_Ctx NETCAAPI netca_crypto_hash_dup(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hash_free
 *			释放Hash上下文
 *		参数：
 *			ctx：Hash上下文
 *		返回值：
 *			无
 */	
void NETCAAPI netca_crypto_hash_free(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hmac_new
 *			创建HMAC上下文
 *		参数：
 *			md_func：Hash函数
 *			key：输入参数，密钥值
 *			keylen：输入参数，key的长度
 *		返回值：
 *			成功返回HMAC上下文，失败返回NULL
 */	
NETCA_HMAC_Ctx NETCAAPI netca_crypto_hmac_new(netca_md_func_cptr md_func,const unsigned char *key,long keylen);
/*
 *		netca_crypto_hmac_gethmaclength
 *			获取HMAC值的长度
 *		参数：
 *			ctx：HMAC上下文
 *		返回值：
 *			成功返回HMAC值的长度，失败返回-1
 */	
int NETCAAPI netca_crypto_hmac_gethmaclength(NETCA_HMAC_Ctx ctx);
/*
 *		netca_crypto_hmac_update
 *			HMAC运算
 *		参数：
 *			ctx：HMAC上下文
 *			data：输入参数，要处理的数据
 *			datalen：输入参数，data的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hmac_update(NETCA_HMAC_Ctx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_hmac_final
 *			结束HMAC运算，获得HMAC值
 *		参数：
 *			ctx：HMAC上下文
 *			hmac：输出参数，返回HMAC值
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hmac_final(NETCA_HMAC_Ctx ctx,unsigned char *hmac);
/*
 *		netca_crypto_hmac_free
 *			释放HMAC上下文
 *		参数：
 *			ctx：HMAC上下文
 *		返回值：
 *			无
 */	
void NETCAAPI netca_crypto_hmac_free(NETCA_HMAC_Ctx ctx);

/*
 *		netca_crypto_hmac
 *			HMAC运算
 *		参数：
 *			md_func：输入参数，Hash函数
 *			key：输入参数，密钥值
 *			keylen：输入参数，key的长度
 *			data：输入参数，要处理的数据
 *			datalen：输入参数，data的长度
 *			hmac：输出参数，返回HMAC值
 *			hmaclen：输入输出函数，返回HMAC值的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_hmac(netca_md_func_cptr md_func,const unsigned char *key,long keylen,const unsigned char *data,long datalen,unsigned char *hmac,int *hmaclen);

/*
 *		netca_crypto_mgf1
 *			MGF1
 *		参数：
 *			md_func：输入参数，Hash函数
 *			mgfseed：输入参数，种子
 *			mgfseedlen：输入参数，mgfseed的长度
 *			mask：输出参数，返回mask值
 *			masklen：输入函数，masklen值的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */	
int NETCAAPI netca_crypto_mgf1(netca_md_func_cptr md_func,const unsigned char *mgfseed,long mgfseedlen,unsigned char *mask,long masklen);


#ifdef __cplusplus
	}	
#endif
#endif


