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
 *			从流中读数据
 *		参数：
 *			stream：流
 *			buf：输出参数，返回读得的数据
 *			buflen：输入参数，缓冲区大小
 *			retlen：输出参数，返回读到的数据
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_read(NETCA_STREAM stream,unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_write
 *			从流中写数据
 *		参数：
 *			stream：流
 *			buf：输入参数，要写入的数据
 *			buflen：输入参数，缓冲区大小
 *			retlen：输出参数，返回写入的数据
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_write(NETCA_STREAM stream,const unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_free
 *			释放流
 *		参数：
 *			stream：流
 *		返回值：
 *			无
 */
void NETCAAPI netca_stream_free(NETCA_STREAM stream);

/*
 *		netca_stream_freeall
 *			释放流链中的所有流
 *		参数：
 *			stream：流
 *		返回值：
 *			无
 */
void NETCAAPI netca_stream_freeall(NETCA_STREAM stream);

/*
 *		netca_stream_ctrl
 *			向流发出控制指令
 *		参数：
 *			stream：流
 *			ctrlcode：输入参数，控制指令
 *			arg：相关参数
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_ctrl(NETCA_STREAM stream,long ctrlcode,void *arg,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_writen
 *			从流中写nlen字节的数据
 *		参数：
 *			stream：流
 *			buf：输入参数，要写入的数据
 *			nlen：输入参数，要写入的数据长度
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_writen(NETCA_STREAM stream,const unsigned char *buf,long nlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_readn
 *			从流中读nlen字节的数据
 *		参数：
 *			stream：流
 *			buf：输出参数，返回读得的数据
 *			nlen：输入参数，要读的数据长度
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_readn(NETCA_STREAM stream,unsigned char *buf,long nlen,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_push
 *			把过滤流newstream加到stream上，形成新的流量
 *		参数：
 *			newstream：过滤流
 *			stream：流
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_push(NETCA_STREAM newstream,NETCA_STREAM stream);

/*
 *		netca_stream_pop
 *			除去流链上的第一个流，并返回该流
 *		参数：
 *			stream：流链
 *		返回值：
 *			成功返回流链上的第一个流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_pop(NETCA_STREAM stream);

/*
 *		netca_stream_find_type
 *			根据类型寻找流
 *		参数：
 *			stream：流链
 *			pos：输入参数，NETCA_STREAM_POS_FROM_HEAD表示从头开始找，NETCA_STREAM_POS_FROM_CURRENT表示从当前位置开始找，NETCA_STREAM_POS_FROM_NEXT表示从下一个流开始找
 *			type：输入参数，流的类型
 *		返回值：
 *			成功返回找到的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_find_type(NETCA_STREAM stream,int pos,int type);

/*
 *		netca_stream_gettype
 *			获取流的类型
 *		参数：
 *			stream：流
 *		返回值：
 *			成功返回流的类型，失败返回-1
 */
int NETCAAPI netca_stream_gettype(NETCA_STREAM stream);

/*
 *		netca_stream_next
 *			获取流链中的下一个流
 *		参数：
 *			stream：流
 *		返回值：
 *			成功返回流的流链中的下一个流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_next(NETCA_STREAM stream);

/*
 *		netca_stream_new_mem
 *			创建一个内存流
 *		参数：
 *			len：输入参数，初始分配的内存大小
 *			errctx：错误上下文
 *		返回值：
 *			成功返回内存流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_mem(long len,NETCA_ERR_CTX errctx);
/*
 *		netca_stream_new_rwspecmem
 *			创建一个内存流，但是其中的数据只能读一次，读后就会被丢弃
 *		参数：
 *			len：输入参数，初始分配的内存大小
 *			errctx：错误上下文
 *		返回值：
 *			成功返回内存流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_rwspecmem(long len,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_romem
 *			创建一个只读的内存流
 *		参数：
 *			buf：输入参数，数据
 *			buflen：输入参数，数据长度
 *			copy：输入参数，为真则拷贝数据，否则直接使用buf
 *			errctx：错误上下文
 *		返回值：
 *			成功返回只读的内存流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_romem(const unsigned char *buf,long buflen,int copy,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_file
 *			创建一个文件流
 *		参数：
 *			filename：输入参数，文件名
 *			flag：输入参数，标记
 *			errctx：错误上下文
 *		返回值：
 *			成功返回文件流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_file(const char *filename,long flag,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_hex
 *			创建一个Hex编码的过滤流，写的时候会进行Hex编码，读会进行Hex解码
 *		参数：
 *			captical：输入参数，为真的时候，写入的Hex编码用大写字母，否则用小写字母
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_hex(int captical,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_base64
 *			创建一个Base64编码的过滤流，写的时候会进行Base64编码，读会进行Base64解码
 *		参数：
 *			encodeflag：输入参数，编码标记
 *			linelen：输入参数，每行的长度
 *			decodeflag：输入参数，解码标记
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_base64(int encodeflag,int linelen,int decodeflag,NETCA_ERR_CTX errctx);

/*
 *		netca_stream_new_base64
 *			创建一个NULL流，写的时候会丢弃所有的，不支持读操作
 *		参数：
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_null(NETCA_ERR_CTX errctx);


/*
 *		netca_stream_writefromstream
 *			把srcstream流中所有的数据写入到descstream流中
 *		参数：
 *			descstream：目标流
 *			srcstream：源流
 *			retlen：输出参数，返回写入的长度
 *			errctx：错误上下文
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_stream_writefromstream(NETCA_STREAM descstream,NETCA_STREAM srcstream,long *retlen,NETCA_ERR_CTX errctx);

/*
 *		netca_memstream_dup_readonly
 *			复制一个内存流，并设置为只读。原来的流没有变化。只包含原来流的内容，不复制读写位置，新的流的读位置为0
 *		参数：
 *			stream：内存流
 *		返回值：
 *			成功复制后的只读内存流，失败返回NULL。
 */
NETCA_STREAM NETCAAPI netca_memstream_dup_readonly(NETCA_STREAM stream);

/*
 *		netca_memstreamdeatch
 *			把内存流中的数据缓存区和内存流分离
 *		参数：
 *			stream：内存流
 *			data：输出参数，返回的缓冲区
 *			len：输出参数，返回的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
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
 *			创建一个Hash的过滤流，写的时候会对数据进行Hash
 *		参数：
 *			md_func：输入参数，Hash函数
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_md(netca_md_func_cptr md_func,NETCA_ERR_CTX errctx);


/*
 *		netca_stream_md_dup
 *			复制一个Hash的过滤流
 *		参数：
 *			md_stream：输入参数，Hash流
 *		返回值：
 *			成功返回复制的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_md_dup(NETCA_STREAM md_stream);

/*
 *		netca_stream_new_md
 *			创建一个HMAC的过滤流，写的时候会对数据进行HMAC
 *		参数：
 *			md_func：输入参数，Hash函数
 *			key：输入参数，密钥
 *			keylen：输入参数，key的长度
 *			errctx：错误上下文
 *		返回值：
 *			成功返回有效的流，失败返回NULL
 */
NETCA_STREAM NETCAAPI netca_stream_new_hmac(netca_md_func_cptr md_func,const unsigned char *key,long keylen,NETCA_ERR_CTX errctx);

#ifdef __cplusplus
}
#endif
#endif
