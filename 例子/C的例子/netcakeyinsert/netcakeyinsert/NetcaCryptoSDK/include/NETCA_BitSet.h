#ifndef NETCA_BITSET_INLCUDE_H
#define NETCA_BITSET_INLCUDE_H

#include "NETCA_BasicType.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_bitset_empty
 *			����һ���յ�λ��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����λ����ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_empty(void);

/*
 *		netca_bitset_new
 *			����һ��λ��
 *		������
 *			unusedbit�����������δʹ��λ
 *			data���������������
 *			datalen�����������data����
 *		����ֵ��
 *			�ɹ�����λ����ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_new(int unusedbit,const unsigned char *data,long datalen);

/*
 *		netca_bitset_free
 *			�ͷ�λ��
 *		������
 *			bitset��λ��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_bitset_free(NETCA_BitSet bitset);

/*
 *		netca_bitset_getdata
 *			��ȡλ��������
 *		������
 *			bitset��λ��
 *			unusedbit���������������δʹ��λ
 *		����ֵ��
 *			�ɹ�����λ�������ݣ�ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_bitset_getdata(NETCA_BitSet bitset,int *unusedbit);

/*
 *		netca_bitset_getbitcount
 *			��ȡλ���е�λ����
 *		������
 *			bitset��λ��
 *		����ֵ��
 *			�ɹ�����λ���е�λ����ʧ�ܷ���-1
 */
long NETCAAPI netca_bitset_getbitcount(NETCA_BitSet bitset);

/*
 *		netca_bitset_set
 *			����λ���ĵ�bitλΪ1
 *		������
 *			bitset��λ��
 *			bit�����������λ��������0��ʼ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_bitset_set(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_clear
 *			����λ���ĵ�bitλΪ0
 *		������
 *			bitset��λ��
 *			bit�����������λ��������0��ʼ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_bitset_clear(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_isset
 *			�ж�λ���ĵ�bitλ�Ƿ�Ϊ1
 *		������
 *			bitset��λ��
 *			bit�����������λ��������0��ʼ
 *		����ֵ��
 *			����Ѿ���λ����1�����򷵻�0
 */
int NETCAAPI netca_bitset_isset(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_dup
 *			����λ��
 *		������
 *			bitset��λ��
 *		����ֵ��
 *			�ɹ����ظ��ƺ��λ����ʧ�ܷ���NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_dup(NETCA_BitSet bitset);


#ifdef __cplusplus
	}	
#endif
#endif
