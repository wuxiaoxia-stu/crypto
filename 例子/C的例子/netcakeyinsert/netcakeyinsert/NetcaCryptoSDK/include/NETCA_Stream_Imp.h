#ifndef NETCA_STREAM_IMP_INLCUDE_H
#define NETCA_STREAM_IMP_INLCUDE_H
#ifdef __cplusplus
extern "C"
	{
#endif

typedef struct NETCA_STREAM_METHOD_st
{
	int (*read)(NETCA_STREAM stream,unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);
	int (*write)(NETCA_STREAM stream,const unsigned char *buf,long buflen,long *retlen,NETCA_ERR_CTX errctx);
	void (*destroy)(NETCA_STREAM stream);
	int (*ctrl)(NETCA_STREAM stream,long ctrlcode,void *arg,NETCA_ERR_CTX errctx);

}NETCA_STREAM_METHOD;

struct NETCA_STREAM_st
{
	NETCA_STREAM_METHOD *m_method;
	int m_type;
	void *m_imp;
	NETCA_STREAM m_prev;
	NETCA_STREAM m_next;
};

#ifdef __cplusplus
}
#endif
#endif
