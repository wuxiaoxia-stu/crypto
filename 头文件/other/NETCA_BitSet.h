#ifndef NETCA_BITSET_INLCUDE_H
#define NETCA_BITSET_INLCUDE_H

#include "NETCA_BasicType.h"
#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_bitset_empty
 *			创建一个空的位集
 *		参数：
 *			无
 *		返回值：
 *			成功返回位集，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_empty(void);

/*
 *		netca_bitset_new
 *			创建一个位集
 *		参数：
 *			unusedbit：输入参数，未使用位
 *			data：输入参数，数据
 *			datalen：输入参数，data长度
 *		返回值：
 *			成功返回位集，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_new(int unusedbit,const unsigned char *data,long datalen);

/*
 *		netca_bitset_free
 *			释放位集
 *		参数：
 *			bitset：位集
 *		返回值：
 *			无
 */
void NETCAAPI netca_bitset_free(NETCA_BitSet bitset);

/*
 *		netca_bitset_getdata
 *			获取位集的数据
 *		参数：
 *			bitset：位集
 *			unusedbit：输出参数，返回未使用位
 *		返回值：
 *			成功返回位集的数据，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_bitset_getdata(NETCA_BitSet bitset,int *unusedbit);

/*
 *		netca_bitset_getbitcount
 *			获取位集中的位数。
 *		参数：
 *			bitset：位集
 *		返回值：
 *			成功返回位集中的位数，失败返回-1
 */
long NETCAAPI netca_bitset_getbitcount(NETCA_BitSet bitset);

/*
 *		netca_bitset_set
 *			设置位集的第bit位为1
 *		参数：
 *			bitset：位集
 *			bit：输入参数，位索引，以0开始
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_bitset_set(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_clear
 *			设置位集的第bit位为0
 *		参数：
 *			bitset：位集
 *			bit：输入参数，位索引，以0开始
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_bitset_clear(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_isset
 *			判断位集的第bit位是否为1
 *		参数：
 *			bitset：位集
 *			bit：输入参数，位索引，以0开始
 *		返回值：
 *			如果已经置位返回1，否则返回0
 */
int NETCAAPI netca_bitset_isset(NETCA_BitSet bitset,long bit);

/*
 *		netca_bitset_dup
 *			复制位集
 *		参数：
 *			bitset：位集
 *		返回值：
 *			成功返回复制后的位集，失败返回NULL
 */
NETCA_BitSet NETCAAPI netca_bitset_dup(NETCA_BitSet bitset);


#ifdef __cplusplus
	}	
#endif
#endif
