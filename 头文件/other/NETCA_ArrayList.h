#ifndef NETCA_XML_ARRAYLIST_INCLUDE_H
#define NETCA_XML_ARRAYLIST_INCLUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_arraylist_new
 *			创建一个动态增长的列表
 *		参数：
 *			dupitem：输入参数，复制元素的函数
 *			freeitem：输入参数，释放元素的函数
 *		返回值：
 *			成功返回有效的动态增长的列表，失败返回NULL
 */
NETCA_ArrayList NETCAAPI netca_arraylist_new(netca_arraylist_dupitem_func dupitem,netca_arraylist_freeitem_func freeitem);

/*
 *		netca_arraylist_free
 *			释放列表
 *		参数：
 *			NETCA_ArrayList：列表
 *		返回值：
 *			无
 */
void NETCAAPI netca_arraylist_free(NETCA_ArrayList list);

/*
 *		netca_arraylist_freeitem
 *			释放列表里的元素
 *		参数：
 *			NETCA_ArrayList：列表
 *			item：要释放的元素
 *		返回值：
 *			无
 */
void NETCAAPI netca_arraylist_freeitem(NETCA_ArrayList list,void *item);

/*
 *		netca_arraylist_count
 *			获取列表元素个数
 *		参数：
 *			NETCA_ArrayList：列表
 *		返回值：
 *			成功返回列表元素个数，失败返回-1
 */
int NETCAAPI netca_arraylist_count(NETCA_ArrayList list);

/*
 *		netca_arraylist_getitem
 *			获取列表元素
 *		参数：
 *			NETCA_ArrayList：列表
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回第index个列表元素，失败返回NULL
 */
void * NETCAAPI netca_arraylist_getitem(NETCA_ArrayList list,int index);

/*
 *		netca_arraylist_getitemref
 *			获取列表元素的指针
 *		参数：
 *			NETCA_ArrayList：列表
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回第index个列表元素的指针，失败返回NULL
 */
void * NETCAAPI netca_arraylist_getitemref(NETCA_ArrayList list,int index);

/*
 *		netca_arraylist_pushback
 *			增加一个元素到列表末尾
 *		参数：
 *			NETCA_ArrayList：列表
 *			item：元素
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_arraylist_pushback(NETCA_ArrayList list,void *item);

/*
 *		netca_arraylist_insert
 *			在index位置下插入一个元素
 *		参数：
 *			NETCA_ArrayList：列表
 *			index：输入参数，索引值，从0算起
 *			item：元素
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_arraylist_insert(NETCA_ArrayList list,int index,void *item);
/*
 *		netca_arraylist_delete
 *			删除列表的第index位置的元素
 *		参数：
 *			NETCA_ArrayList：列表
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_arraylist_delete(NETCA_ArrayList list,int index);


#ifdef __cplusplus
}
#endif
#endif

