#ifndef NETCA_STREAM_INLCUDE_H
#define NETCA_STREAM_INLCUDE_H

#include "NETCA_BasicType.h"
#include "NETCA_Error.h"

#ifdef __cplusplus
extern "C"
	{
#endif


#define NETCA_STREAM_TYPE_FILTER	0x10000
#define NETCA_STREAM_TYPE_SOURCE_SINK	0x20000

#define NETCA_STREAM_TYPE_MEM		(0x1|NETCA_STREAM_TYPE_SOURCE_SINK)
#define NETCA_STREAM_TYPE_FILE		(0x2|NETCA_STREAM_TYPE_SOURCE_SINK)
#define NETCA_STREAM_TYPE_MD		(0x3|NETCA_STREAM_TYPE_FILTER)
#define NETCA_STREAM_TYPE_HEX		(0x4|NETCA_STREAM_TYPE_FILTER)
#define NETCA_STREAM_TYPE_BASE64	(0x5|NETCA_STREAM_TYPE_FILTER)
#define NETCA_STREAM_TYPE_NULL		(0x6|NETCA_STREAM_TYPE_SOURCE_SINK)
#define NETCA_STREAM_TYPE_HMAC		(0x7|NETCA_STREAM_TYPE_FILTER)
#define NETCA_STREAM_TYPE_CIPHER	(0x8|NETCA_STREAM_TYPE_FILTER)

#define NETCA_STREAM_TYPE_USER		0x1000

#define NETCA_STREAM_READONLY	0x1

#define NETCA_STREAM_CTRL_RESET			0x1
#define NETCA_STREAM_CTRL_GETLENGTH		0x2
#define NETCA_STREAM_CTRL_GETMDLENGTH		0x3
#define NETCA_STREAM_CTRL_GETMDVALUE		0x4
#define NETCA_STREAM_CTRL_GETMDTYPE		0x5
#define NETCA_STREAM_CTRL_FLUSH			0x6
#define NETCA_STREAM_CTRL_GETPOS		0x7
#define NETCA_STREAM_CTRL_SETPOS		0x8
#define NETCA_STREAM_CTRL_CLOSE			0x9
#define NETCA_STREAM_CTRL_REOPEN		0xA
#define NETCA_STREAM_CTRL_ISEOS			0xB
#define NETCA_STREAM_CTRL_GETHMACVALUE		0xC
#define NETCA_STREAM_CTRL_ENCRYPT_FINISH	0xD
#define NETCA_STREAM_CTRL_GETREMCLEARDATA	0xE
#define NETCA_STREAM_CTRL_GETREADPOS	0xF
#define NETCA_STREAM_CTRL_GETWRITEPOS	0x10
#define NETCA_STREAM_CTRL_SETREADPOS	0x11
#define NETCA_STREAM_CTRL_SETWRITEPOS	0x12
#define NETCA_STREAM_CTRL_SETCAPACITY	0x13
#define NETCA_STREAM_CTRL_BASE64DECODE_FINISH	0x14

#define NETCA_STREAM_CTRL_USER			0x1000


#define NETCA_STREAM_POS_FROM_HEAD		1
#define NETCA_STREAM_POS_FROM_CURRENT	2
#define NETCA_STREAM_POS_FROM_NEXT		3

#define NETCA_STREAM_FILE_FLAG_READ		1
#define NETCA_STREAM_FILE_FLAG_WRITE		2
#define NETCA_STREAM_FILE_FLAG_APPEND		3

#define NETCA_STREAM_BASE64_CR		1
#define NETCA_STREAM_BASE64_CRLF	2
#define NETCA_STREAM_BASE64_LF		3
#define NETCA_STREAM_BASE64_NOCRLF	4

#define NETCA_STREAM_BASE64_NOPADDING	0x80

#define NETCA_STREAM_BASE64_STRICT	1
#define NETCA_STREAM_BASE64_IGNORECRLF	2
#define NETCA_STREAM_BASE64_IGNORESPACE	3

#define NETCA_STREAM_MDTYPE_MD2		1
#define NETCA_STREAM_MDTYPE_MD4		2
#define NETCA_STREAM_MDTYPE_MD5		3
#define NETCA_STREAM_MDTYPE_SHA1	4
#define NETCA_STREAM_MDTYPE_SHA224	5
#define NETCA_STREAM_MDTYPE_SHA256	6
#define NETCA_STREAM_MDTYPE_SHA384	7
#define NETCA_STREAM_MDTYPE_SHA512	8
#define NETCA_STREAM_MDTYPE_SM3		9
#define NETCA_STREAM_MDTYPE_SHA512_224	10
#define NETCA_STREAM_MDTYPE_SHA512_256	11
#define NETCA_STREAM_MDTYPE_SHA3_224	12
#define NETCA_STREAM_MDTYPE_SHA3_256	13
#define NETCA_STREAM_MDTYPE_SHA3_384	14
#define NETCA_STREAM_MDTYPE_SHA3_512	15


#define NETCA_STREAM_LENGTH_INDEFINITE		-1L

/*
 *		netca_stream_read
 *			�����ж�����
 *		������
 *			stream����
 *			buf��������������ض��õ�����
 *			buflen�������������������С
 *			retlen��������������ض���������
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_read(NETCA_STREAM stream,unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_write
 *			������д����
 *		������
 *			stream����
 *			buf�����������Ҫд�������
 *			buflen�������������������С
 *			retlen���������������д�������
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_write(NETCA_STREAM stream,const unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_free
 *			�ͷ���
 *		������
 *			stream����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_stream_free(NETCA_STREAM stream);

/*
 *		netca_stream_freeall
 *			�ͷ������е�������
 *		������
 *			stream����
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_stream_freeall(NETCA_STREAM stream);

/*
 *		netca_stream_ctrl
 *			������������ָ��
 *		������
 *			stream����
 *			ctrlcode���������������ָ��
 *			arg����ز���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_ctrl(NETCA_STREAM stream,long ctrlcode,void *arg,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_writen
 *			������дnlen�ֽڵ�����
 *		������
 *			stream����
 *			buf�����������Ҫд�������
 *			nlen�����������Ҫд������ݳ���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_writen(NETCA_STREAM stream,const unsigned char *buf,long nlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_readn
 *			�����ж�nlen�ֽڵ�����
 *		������
 *			stream����
 *			buf��������������ض��õ�����
 *			nlen�����������Ҫ�������ݳ���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_readn(NETCA_STREAM stream,unsigned char *buf,long nlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_push
 *			�ѹ�����newstream�ӵ�stream�ϣ��γ��µ�����
 *		������
 *			newstream��������
 *			stream����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_push(NETCA_STREAM newstream,NETCA_STREAM stream);

/*
 *		netca_stream_pop
 *			��ȥ�����ϵĵ�һ�����������ظ���
 *		������
 *			stream������
 *		����ֵ��
 *			�ɹ����������ϵĵ�һ������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_pop(NETCA_STREAM stream);

/*
 *		netca_stream_find_type
 *			��������Ѱ����
 *		������
 *			stream������
 *			pos�����������NETCA_STREAM_POS_FROM_HEAD��ʾ��ͷ��ʼ�ң�NETCA_STREAM_POS_FROM_CURRENT��ʾ�ӵ�ǰλ�ÿ�ʼ�ң�NETCA_STREAM_POS_FROM_NEXT��ʾ����һ������ʼ��
 *			type�������������������
 *		����ֵ��
 *			�ɹ������ҵ�������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_find_type(NETCA_STREAM stream,int pos,int type);

/*
 *		netca_stream_gettype
 *			��ȡ��������
 *		������
 *			stream����
 *		����ֵ��
 *			�ɹ������������ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_stream_gettype(NETCA_STREAM stream);

/*
 *		netca_stream_next
 *			��ȡ�����е���һ����
 *		������
 *			stream����
 *		����ֵ��
 *			�ɹ��������������е���һ������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_next(NETCA_STREAM stream);

/*
 *		netca_stream_new_mem
 *			����һ���ڴ���
 *		������
 *			len�������������ʼ������ڴ��С
 *			errctx������������
 *		����ֵ��
 *			�ɹ������ڴ�����ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_mem(long len,NETCA_ERR_CTX errctx);
/*
 *		netca_stream_new_rwspecmem
 *			����һ���ڴ������������е�����ֻ�ܶ�һ�Σ�����ͻᱻ����
 *		������
 *			len�������������ʼ������ڴ��С
 *			errctx������������
 *		����ֵ��
 *			�ɹ������ڴ�����ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_rwspecmem(long len,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_romem
 *			����һ��ֻ�����ڴ���
 *		������
 *			buf���������������
 *			buflen��������������ݳ���
 *			copy�����������Ϊ���򿽱����ݣ�����ֱ��ʹ��buf
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����ֻ�����ڴ�����ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_romem(const unsigned char *buf,long buflen,int copy,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_file
 *			����һ���ļ���
 *		������
 *			filename������������ļ���
 *			flag��������������
 *			errctx������������
 *		����ֵ��
 *			�ɹ������ļ�����ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_file(const char *filename,long flag,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_hex
 *			����һ��Hex����Ĺ�������д��ʱ������Hex���룬�������Hex����
 *		������
 *			captical�����������Ϊ���ʱ��д���Hex�����ô�д��ĸ��������Сд��ĸ
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_hex(int captical,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_base64
 *			����һ��Base64����Ĺ�������д��ʱ������Base64���룬�������Base64����
 *		������
 *			encodeflag�����������������
 *			linelen�����������ÿ�еĳ���
 *			decodeflag�����������������
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_base64(int encodeflag,int linelen,int decodeflag,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_base64
 *			����һ��NULL����д��ʱ��ᶪ�����еģ���֧�ֶ�����
 *		������
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_null(NETCA_ERR_CTX errctx);


/*
 *		netca_stream_writefromstream
 *			��srcstream�������е�����д�뵽descstream����
 *		������
 *			descstream��Ŀ����
 *			srcstream��Դ��
 *			retlen���������������д��ĳ���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_stream_writefromstream(NETCA_STREAM descstream,NETCA_STREAM srcstream,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_memstream_dup_readonly
 *			����һ���ڴ�����������Ϊֻ����ԭ������û�б仯��ֻ����ԭ���������ݣ������ƶ�дλ�ã��µ����Ķ�λ��Ϊ0
 *		������
 *			stream���ڴ���
 *		����ֵ��
 *			�ɹ����ƺ��ֻ���ڴ�����ʧ�ܷ���NULL��
 */
NETCA_STREAM NETCAAPI netca_memstream_dup_readonly(NETCA_STREAM stream);

/*
 *		netca_memstreamdeatch
 *			���ڴ����е����ݻ��������ڴ�������
 *		������
 *			stream���ڴ���
 *			data��������������صĻ�����
 *			len��������������صĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_memstreamdeatch(NETCA_STREAM stream,unsigned char **data,long *len);


typedef void *(*new_md_ptr)(void);
typedef void (*free_md_ptr)(void *md_st);
typedef long (*get_digist_length_ptr)(void);
typedef int (*get_md_type_ptr)(void);
typedef void (*md_init_ptr)(void *md_st);
typedef int (*md_update_ptr)(void *md_st,const unsigned char *data,long datalen);
typedef int (*md_finish_ptr)(void *md_st,unsigned char *mdvalue);
typedef long (*get_block_length_ptr)(void);
typedef void* (*md_dup_ptr)(void* md_st);

struct netca_md_func_st{
	new_md_ptr m_new_md_func;
	free_md_ptr m_free_md_func;
	get_digist_length_ptr m_get_digist_length_func;
	get_md_type_ptr	m_get_md_type_func;
	md_init_ptr m_md_init_func;
	md_update_ptr m_md_update_func;
	md_finish_ptr m_md_finish_func;
	get_block_length_ptr m_get_block_length_func;
	md_dup_ptr m_md_dup_func;
};

typedef struct netca_md_func_st* netca_md_func_ptr;
typedef const struct netca_md_func_st* netca_md_func_cptr;

/*
 *		netca_stream_new_md
 *			����һ��Hash�Ĺ�������д��ʱ�������ݽ���Hash
 *		������
 *			md_func�����������Hash����
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_md(netca_md_func_cptr md_func,NETCA_ERR_CTX errctx);


/*
 *		netca_stream_md_dup
 *			����һ��Hash�Ĺ�����
 *		������
 *			md_stream�����������Hash��
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�����ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_md_dup(NETCA_STREAM md_stream);

/*
 *		netca_stream_new_md
 *			����һ��HMAC�Ĺ�������д��ʱ�������ݽ���HMAC
 *		������
 *			md_func�����������Hash����
 *			key�������������Կ
 *			keylen�����������key�ĳ���
 *			errctx������������
 *		����ֵ��
 *			�ɹ�������Ч������ʧ�ܷ���NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_hmac(netca_md_func_cptr md_func,const unsigned char *key,long keylen,NETCA_ERR_CTX errctx);

#ifdef __cplusplus
}
#endif
#endif
