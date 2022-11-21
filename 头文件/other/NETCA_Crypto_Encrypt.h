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
 *			ARC4����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����ARC4������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_arc4_function(void);
/*
 *		netca_crypto_des_function
 *			DES����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����DES������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_des_function(void);
/*
 *		netca_crypto_3des_function
 *			3DES����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����3DES������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_3des_function(void);
/*
 *		netca_crypto_rc2_function
 *			RC2����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����RC2������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_rc2_function(void);
/*
 *		netca_crypto_aes_function
 *			AES����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����AES������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_aes_function(void);

/*
 *		netca_crypto_sms4_function
 *			AES����
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����SMS4������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_sms4_function(void);

/*
 *		netca_crypto_zuc_function
 *			���֮�㷨������Ҫ��keyΪKey||IV
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����ARC4������ʧ�ܷ���NULL
 */
netca_encrypt_func_cptr NETCAAPI netca_crypto_zuc_function(void);

/*
 *		netca_crypto_newcontext
 *			��������������
 *		������
 *			encrypt_func��������������ܺ���
 *			key�������������Կ
 *			keylen�����������key�ĳ���
 *			mode������������������ģʽ
 *			padding��������������ģʽ
 *			enc�����������Ϊ���ʾ���ܣ�Ϊ�ұ�ʾ����
 *		����ֵ��
 *			�ɹ����ؼ��������ģ�ʧ�ܷ���NULL
 */
NETCA_Crypto_Ctx NETCAAPI netca_crypto_newcontext(netca_encrypt_func_cptr encrypt_func,const unsigned char *key,long keylen,int mode,int padding,int enc);
/*
 *		netca_crypto_update
 *			���мӽ���
 *		������
 *			ctx������������
 *			in��������������������
 *			inlen�����������in�ĳ���
 *			out������������������������
 *			outlen���������������������������ݵĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_update(NETCA_Crypto_Ctx ctx,const unsigned char *in,long inlen,unsigned char *out,long *outlen);
/*
 *		netca_crypto_final
 *			�����ӽ���
 *		������
 *			ctx������������
 *			out������������������������
 *			remlen���������������������������ݵĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_final(NETCA_Crypto_Ctx ctx,unsigned char *out,long *remlen);
/*
 *		netca_crypto_getalgo
 *			��ȡ�����㷨
 *		������
 *			ctx������������
 *		����ֵ��
 *			�ɹ����ؼ����㷨��ʧ�ܷ���-1
 */
int NETCAAPI netca_crypto_getalgo(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_getblocklen
 *			��ȡ���鳤��
 *		������
 *			ctx������������
 *		����ֵ��
 *			�ɹ����ط��鳤�ȣ�ʧ�ܷ���-1
 */
long NETCAAPI netca_crypto_getblocklen(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_setparam
 *			���ü��ܲ���
 *		������
 *			ctx������������
 *			type�������������������
 *			param���������������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_crypto_setparam(NETCA_Crypto_Ctx ctx,long type,void *param);
/*
 *		netca_crypto_freecontext
 *			�ͷż���������
 *		������
 *			ctx������������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_crypto_freecontext(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_getremdatalength
 *			��ȡ������������δ�������ݵĳ���
 *		������
 *			ctx������������
 *		����ֵ��
 *			�ɹ����ؼ�����������δ�������ݵĳ��ȣ�ʧ�ܷ���-1
 */
long NETCAAPI netca_crypto_getremdatalength(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_isweakkey
 *			�ж��Ƿ�������Կ
 *		������
 *			ctx������������
 *		����ֵ��
 *			���������Կ������1�����򷵻�0
 */
int NETCAAPI netca_crypto_isweakkey(NETCA_Crypto_Ctx ctx);
/*
 *		netca_crypto_des_normkey
 *			�淶��DES��Կ
 *		������
 *			key���������������DES��3DES��Կ
 *			keylen�����������key�ĳ���
 *		����ֵ��
 *			���������Կ������1�����򷵻�0
 */
int NETCAAPI netca_crypto_des_normkey(unsigned char *key,long keylen);

/*
 *		netca_stream_new_cipher
 *			����������
 *		������
 *			encctx������������
 *			decctx������������
 *			errctx������������
 *		����ֵ��
 *			�ɹ����ؼ�������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_cipher(NETCA_Crypto_Ctx encctx,NETCA_Crypto_Ctx decctx,NETCA_ERR_CTX errctx);


#ifdef __cplusplus
	}	
#endif
#endif
