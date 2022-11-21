#ifndef NETCA_XML_ARRAYLIST_INCLUDE_H
#define NETCA_XML_ARRAYLIST_INCLUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_arraylist_new
 *			����һ����̬�������б�
 *		������
 *			dupitem���������������Ԫ�صĺ���
 *			freeitem������������ͷ�Ԫ�صĺ���
 *		����ֵ��
 *			�ɹ�������Ч�Ķ�̬�������б�ʧ�ܷ���NULL
 */
NETCA_ArrayList NETCAAPI netca_arraylist_new(netca_arraylist_dupitem_func dupitem,netca_arraylist_freeitem_func freeitem);

/*
 *		netca_arraylist_free
 *			�ͷ��б�
 *		������
 *			NETCA_ArrayList���б�
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_arraylist_free(NETCA_ArrayList list);

/*
 *		netca_arraylist_freeitem
 *			�ͷ��б����Ԫ��
 *		������
 *			NETCA_ArrayList���б�
 *			item��Ҫ�ͷŵ�Ԫ��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_arraylist_freeitem(NETCA_ArrayList list,void *item);

/*
 *		netca_arraylist_count
 *			��ȡ�б�Ԫ�ظ���
 *		������
 *			NETCA_ArrayList���б�
 *		����ֵ��
 *			�ɹ������б�Ԫ�ظ�����ʧ�ܷ���-1
 */
int NETCAAPI netca_arraylist_count(NETCA_ArrayList list);

/*
 *		netca_arraylist_getitem
 *			��ȡ�б�Ԫ��
 *		������
 *			NETCA_ArrayList���б�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�index���б�Ԫ�أ�ʧ�ܷ���NULL
 */
void * NETCAAPI netca_arraylist_getitem(NETCA_ArrayList list,int index);

/*
 *		netca_arraylist_getitemref
 *			��ȡ�б�Ԫ�ص�ָ��
 *		������
 *			NETCA_ArrayList���б�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�index���б�Ԫ�ص�ָ�룬ʧ�ܷ���NULL
 */
void * NETCAAPI netca_arraylist_getitemref(NETCA_ArrayList list,int index);

/*
 *		netca_arraylist_pushback
 *			����һ��Ԫ�ص��б�ĩβ
 *		������
 *			NETCA_ArrayList���б�
 *			item��Ԫ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_arraylist_pushback(NETCA_ArrayList list,void *item);

/*
 *		netca_arraylist_insert
 *			��indexλ���²���һ��Ԫ��
 *		������
 *			NETCA_ArrayList���б�
 *			index���������������ֵ����0����
 *			item��Ԫ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_arraylist_insert(NETCA_ArrayList list,int index,void *item);
/*
 *		netca_arraylist_delete
 *			ɾ���б�ĵ�indexλ�õ�Ԫ��
 *		������
 *			NETCA_ArrayList���б�
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_arraylist_delete(NETCA_ArrayList list,int index);


#ifdef __cplusplus
}
#endif
#endif

