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
 *			SHA1����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA1������ʧ�ܷ���NULL
 */
netca_md_func_cptr NETCAAPI netca_crypto_sha1_function(void);
/*
 *		netca_crypto_md5_function
 *			MD5����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����MD5������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_md5_function(void);

/*
 *		netca_crypto_sha256_function
 *			SHA256����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA256������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha256_function(void);
/*
 *		netca_crypto_sha224_function
 *			SHA224����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA224������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha224_function(void);
/*
 *		netca_crypto_sha384_function
 *			SHA384����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA384������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha384_function(void);
/*
 *		netca_crypto_sha512_function
 *			SHA512����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA512������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_function(void);


/*
 *		netca_crypto_sha512_224_function
 *			SHA-512/224����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA-512/224������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_224_function(void);

/*
 *		netca_crypto_sha512_256_function
 *			SHA-512/256����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA-512/256������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha512_256_function(void);

/*
 *		netca_crypto_sm3_function
 *			SM3����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SM3������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sm3_function(void);

/*
 *		netca_crypto_sha3_224_function
 *			SHA3-224����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA3-224������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_224_function(void);

/*
 *		netca_crypto_sha3_256_function
 *			SHA3-256����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA3-256������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_256_function(void);

/*
 *		netca_crypto_sha3_384_function
 *			SHA3-256����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA3-384������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_384_function(void);

/*
 *		netca_crypto_sha3_512_function
 *			SHA3-256����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SHA3-512������ʧ�ܷ���NULL
 */	
netca_md_func_cptr NETCAAPI netca_crypto_sha3_512_function(void);

/*
 *		netca_crypto_hash
 *			Hash����
 *		������
 *			md_func�����������Hash����
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hash(netca_md_func_cptr md_func,const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha1
 *			SHA1
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sha1(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_md5
 *			MD5
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_md5(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha224
 *			SHA224
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sha224(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha256
 *			SHA256
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sha256(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha384
 *			SHA384
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sha384(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_sha512
 *			SHA512
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sha512(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);

/*
 *		netca_crypto_sm3
 *			SM3
 *		������
 *			data���������������Hash������
 *			datalen�����������data�ĳ���
 *			md��������������ص�Hashֵ
 *			mdlen������������������ص�Hash����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_sm3(const unsigned char *data,long datalen,unsigned char *md,int *mdlen);
/*
 *		netca_crypto_hash_new
 *			����Hash������
 *		������
 *			md_func�����������Hash����
 *		����ֵ��
 *			�ɹ�����Hash�����ģ�ʧ�ܷ�������ֵ
 */	
NETCA_Hash_Ctx NETCAAPI netca_crypto_hash_new(netca_md_func_cptr md_func);
/*
 *		netca_crypto_hash_gethashlength
 *			��ȡHashֵ�ĳ���
 *		������
 *			ctx��Hash������
 *		����ֵ��
 *			�ɹ�����Hashֵ�ĳ��ȣ�ʧ�ܷ���-1
 */	
int NETCAAPI netca_crypto_hash_gethashlength(NETCA_Hash_Ctx ctx);
/*
 *		netca_crypto_hash_getblocklength
 *			��ȡHash�ķ��鳤��
 *		������
 *			ctx��Hash������
 *		����ֵ��
 *			�ɹ�����Hash����ĳ��ȣ�ʧ�ܷ���-1
 */	
int NETCAAPI netca_crypto_hash_getblocklength(NETCA_Hash_Ctx ctx);
/*
 *		netca_crypto_hash_getblocklength
 *			Hash����
 *		������
 *			ctx��Hash������
 *			data�����������Ҫ���������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hash_update(NETCA_Hash_Ctx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_hash_final
 *			����Hash���㣬��ȡHashֵ
 *		������
 *			ctx��Hash������
 *			md���������������Hashֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hash_final(NETCA_Hash_Ctx ctx,unsigned char *md);
/*
 *		netca_crypto_hash_reset
 *			����Hash������״̬
 *		������
 *			ctx��Hash������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hash_reset(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hash_dup
 *			����Hash������
 *		������
 *			ctx��Hash������
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�Hash�����ģ�ʧ�ܷ���NULL
 */	
NETCA_Hash_Ctx NETCAAPI netca_crypto_hash_dup(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hash_free
 *			�ͷ�Hash������
 *		������
 *			ctx��Hash������
 *		����ֵ��
 *			��
 */	
void NETCAAPI netca_crypto_hash_free(NETCA_Hash_Ctx ctx);

/*
 *		netca_crypto_hmac_new
 *			����HMAC������
 *		������
 *			md_func��Hash����
 *			key�������������Կֵ
 *			keylen�����������key�ĳ���
 *		����ֵ��
 *			�ɹ�����HMAC�����ģ�ʧ�ܷ���NULL
 */	
NETCA_HMAC_Ctx NETCAAPI netca_crypto_hmac_new(netca_md_func_cptr md_func,const unsigned char *key,long keylen);
/*
 *		netca_crypto_hmac_gethmaclength
 *			��ȡHMACֵ�ĳ���
 *		������
 *			ctx��HMAC������
 *		����ֵ��
 *			�ɹ�����HMACֵ�ĳ��ȣ�ʧ�ܷ���-1
 */	
int NETCAAPI netca_crypto_hmac_gethmaclength(NETCA_HMAC_Ctx ctx);
/*
 *		netca_crypto_hmac_update
 *			HMAC����
 *		������
 *			ctx��HMAC������
 *			data�����������Ҫ���������
 *			datalen�����������data�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hmac_update(NETCA_HMAC_Ctx ctx,const unsigned char *data,long datalen);
/*
 *		netca_crypto_hmac_final
 *			����HMAC���㣬���HMACֵ
 *		������
 *			ctx��HMAC������
 *			hmac���������������HMACֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hmac_final(NETCA_HMAC_Ctx ctx,unsigned char *hmac);
/*
 *		netca_crypto_hmac_free
 *			�ͷ�HMAC������
 *		������
 *			ctx��HMAC������
 *		����ֵ��
 *			��
 */	
void NETCAAPI netca_crypto_hmac_free(NETCA_HMAC_Ctx ctx);

/*
 *		netca_crypto_hmac
 *			HMAC����
 *		������
 *			md_func�����������Hash����
 *			key�������������Կֵ
 *			keylen�����������key�ĳ���
 *			data�����������Ҫ���������
 *			datalen�����������data�ĳ���
 *			hmac���������������HMACֵ
 *			hmaclen�������������������HMACֵ�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_hmac(netca_md_func_cptr md_func,const unsigned char *key,long keylen,const unsigned char *data,long datalen,unsigned char *hmac,int *hmaclen);

/*
 *		netca_crypto_mgf1
 *			MGF1
 *		������
 *			md_func�����������Hash����
 *			mgfseed���������������
 *			mgfseedlen�����������mgfseed�ĳ���
 *			mask���������������maskֵ
 *			masklen�����뺯����masklenֵ�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */	
int NETCAAPI netca_crypto_mgf1(netca_md_func_cptr md_func,const unsigned char *mgfseed,long mgfseedlen,unsigned char *mask,long masklen);


#ifdef __cplusplus
	}	
#endif
#endif


