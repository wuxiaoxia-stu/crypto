#ifndef NETCA_JSON_INLCUDE_H
#define NETCA_JSON_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif


#ifndef NETCA_JSON_TYPE_STRING

#define NETCA_JSON_TYPE_STRING		1
#define NETCA_JSON_TYPE_NUMBER		2
#define NETCA_JSON_TYPE_BOOLEAN		3
#define NETCA_JSON_TYPE_NULL		4
#define NETCA_JSON_TYPE_OBJECT		5
#define NETCA_JSON_TYPE_ARRAY		6

#define NETCA_JSON_ENCODE_FLAG_COMPACT		0
#define NETCA_JSON_ENCODE_FLAG_INDENT		0x80000000	
#define NETCA_JSON_ENCODE_FLAG_USE_SPACE	0x40000000	
#define NETCA_JSON_ENCODE_FLAG_USE_RETURN	0x20000000	
#define NETCA_JSON_ENCODE_FLAG_USE_NEWLINE	0x10000000	
#define NETCA_JSON_ENCODE_FLAG_SORT			0x100000	
#define NETCA_JSON_ENCODE_FLAG_NORMAL	(NETCA_JSON_ENCODE_FLAG_INDENT|NETCA_JSON_ENCODE_FLAG_USE_NEWLINE)

#endif


/*
 *		netca_json_newboolean
 *			����һ����ʾ����ֵ��JSON���
 *		������
 *			value�����������0Ϊ�٣���0Ϊ��
 *		����ֵ��
 *			�ɹ����ر�ʾ����ֵ��JSON���
 */
NETCA_JSON NETCAAPI netca_json_newboolean(int value);

/*
 *		netca_json_newnull
 *			����һ����ʾnullֵ��JSON���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ر�ʾnullֵ��JSON���
 */
NETCA_JSON NETCAAPI netca_json_newnull(void);

/*
 *		netca_json_newnumber
 *			����һ����ʾ���ֵ�JSON���
 *		������
 *			number���������������
 *		����ֵ��
 *			�ɹ����ر�ʾ���ֵ�JSON���
 */
NETCA_JSON NETCAAPI netca_json_newnumber(double number);

/*
 *		netca_json_newstring
 *			����һ����ʾ�ַ�����JSON���
 *		������
 *			str������������ַ���ֵ��UTF-8����
 *			strLen:����������ַ����ֽ���
 *		����ֵ��
 *			�ɹ����ر�ʾ�ַ�����JSON���
 */
NETCA_JSON NETCAAPI netca_json_newstring(const unsigned char *str,int strLen);


/*
 *		netca_json_newobject
 *			����һ����ʾ�ն����JSON���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ر�ʾ�ն����JSON���
 */
NETCA_JSON NETCAAPI netca_json_newobject(void);


/*
 *		netca_json_newarray
 *			����һ����ʾ�������JSON���
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ر�ʾ�������JSON���
 */
NETCA_JSON NETCAAPI netca_json_newarray(void);

/*
 *		netca_json_free
 *			�ͷ�JSON���
 *		������
 *			json��JSON���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_json_free(NETCA_JSON json);


/*
 *		netca_json_free
 *			����JSON���
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ����ظ��ƺ��JSON�����ʧ�ܷ���NULL
 */
NETCA_JSON NETCAAPI netca_json_dup(NETCA_JSON json);


/*
 *		netca_json_free
 *			����JSON��������ݵõ�JSON���
 *		������
 *			data�����������JSON�ı���
 *			dataLen�����������data���ֽ���
 *		����ֵ��
 *			�ɹ�����JSON�����ʧ�ܷ���NULL
 */
NETCA_JSON NETCAAPI netca_json_decode(const unsigned char *data,int dataLen);

/*
 *		netca_json_addobjectitem
 *			���һ�JSON����,�������������Ƿ��ظ�
 *		������
 *			json��Ҫ������JSON����
 *			name��������������Ƶ�UTF-8����
 *			nameLen��������������Ƶ��ֽ���
 *			value:���������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_addobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen,NETCA_JSON value);

/*
 *		netca_json_updateobjectitem
 *			����JSON����,������ֲ����ڣ����һ��
 *		������
 *			json��Ҫ������JSON����
 *			name��������������Ƶ�UTF-8����
 *			nameLen��������������Ƶ��ֽ���
 *			value:���������ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_updateobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen,NETCA_JSON value);

/*
 *		netca_json_deleteobjectitem
 *			ɾ��JSON�����ָ����
 *		������
 *			json��Ҫ������JSON����
 *			name��������������Ƶ�UTF-8����
 *			nameLen��������������Ƶ��ֽ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_deleteobjectitem(NETCA_JSON json,const unsigned char *name,int nameLen);

/*
 *		netca_json_addarrayitem
 *			���һ�JSON����
 *		������
 *			json��Ҫ������JSON����
 *			value:���������ֵ
 *		����ֵ��
 *			�ɹ�����JSON�����ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_addarrayitem(NETCA_JSON json,NETCA_JSON value);

/*
 *		netca_json_deletearrayitem
 *			��JSON������ɾ����
 *		������
 *			json��Ҫ������JSON����
 *			index:�������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����JSON�����ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_deletearrayitem(NETCA_JSON json,int index);

/*
 *		netca_json_encode
 *			��JSON���б���
 *		������
 *			json��JSON���
 *			flag:��������������־
 *			encode�����������UTF-8����
 *			encodeLen�����������UTF-8������ֽ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_encode(NETCA_JSON json,int flag,unsigned char **encode,int* encodeLen);

/*
 *		netca_json_gettype
 *			��ȡJSON������
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ�����JSON�����ͣ�ʧ�ܷ���-1
 */
int NETCAAPI netca_json_gettype(NETCA_JSON json);


/*
 *		netca_json_istrue
 *			�ж�JSON�Ƿ�Ϊtrue
 *		������
 *			json��JSON���
 *		����ֵ��
 *			���JSONΪtrue������1�����򷵻�0
 */
int NETCAAPI netca_json_istrue(NETCA_JSON json);

/*
 *		netca_json_getnumber
 *			��ȡJSON����ֵ
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ�����JSON����ֵ�����������ֵ���ͷ���-1
 */
double NETCAAPI netca_json_getnumber(NETCA_JSON json);


/*
 *		netca_json_getstring
 *			��ȡJSON���ַ���
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ�����JSON���ַ�����ʧ�ܷ���NULL
 */
const char * NETCAAPI netca_json_getstring(NETCA_JSON json);

/*
 *		netca_json_getstringlength
 *			��ȡJSON���ַ����ĳ���
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ�����JSON���ַ������ֽ�����ʧ�ܷ���NULL
 */
int NETCAAPI netca_json_getstringlength(NETCA_JSON json);

/*
 *		netca_json_getarraysize
 *			��ȡJSON������Ԫ�ظ���
 *		������
 *			json��JSON���
 *		����ֵ��
 *			�ɹ�����JSON������Ԫ�ظ�����ʧ�ܷ���-1
 */
int NETCAAPI netca_json_getarraysize(NETCA_JSON json);


/*
 *		netca_json_getarrayitem
 *			��ȡJSON������Ԫ��
 *		������
 *			json��JSON���
 *			index���������������ֵ
 *		����ֵ��
 *			�ɹ�����JSON������ĵ�index��Ԫ�أ�ʧ�ܷ���NULL
 */
NETCA_JSON NETCAAPI netca_json_getarrayitem(NETCA_JSON json,int index);

/*
 *		netca_json_traverse
 *			����JSON����
 *		������
 *			json��JSON���
 *			func�������������������
 *			context:���������ĵ�һ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_json_traverse(NETCA_JSON json,netca_json_traverse_func func,void *context);

/*
 *		netca_json_getobjectvalue
 *			��ȡJSON�Ķ���Ԫ�ص�ֵ
 *		������
 *			json��JSON���
 *			name���������������,UTF-8����
 *			nameLen��������������Ƶĳ���
 *		����ֵ��
 *			�ɹ�����JSON�Ķ�Ӧ���Ƶ�ֵ��ʧ�ܷ���NULL
 */
NETCA_JSON NETCAAPI netca_json_getobjectvalue(NETCA_JSON json,const unsigned char *name,int nameLen);


#ifdef __cplusplus
	}	
#endif
#endif
