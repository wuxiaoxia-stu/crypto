#ifndef NETCA_BIGINTER_INLCUDE_H
#define NETCA_BIGINTER_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_biginteger_newdata
 *			创建一个大整数，可正可负
 *		参数：
 *			buf：输入参数，整数的补码，最高位为1表示负数
 *			buflen：输入参数，buf的长度
 *		返回值：
 *			成功返回大整数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newdata(const unsigned char *buf,long buflen);

/*
 *		netca_biginteger_newunsigneddata
 *			创建一个非负的大整数
 *		参数：
 *			buf：输入参数，整数的补码
 *			buflen：输入参数，buf的长度
 *		返回值：
 *			成功返回大整数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newunsigneddata(const unsigned char *buf,long buflen);

/*
 *		netca_biginteger_free
 *			释放大整数
 *		参数：
 *			bn：大整数
 *		返回值：
 *			无
 */
void NETCAAPI netca_biginteger_free(NETCA_BigInteger bn);

/*
 *		netca_biginteger_new
 *			根据一个64位的整数转换为大整数
 *		参数：
 *			value：输入参数，64位的整数
 *		返回值：
 *			成功返回大整数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_new(integer64 value);

/*
 *		netca_biginteger_getvalue
 *			把大整数转换为64位的整数
 *		参数：
 *			bn：大整数
 *			value：输出参数，返回转换后的64位的整数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_biginteger_getvalue(NETCA_BigInteger bn,integer64 *value);

/*
 *		netca_biginteger_dup
 *			复制一个大整数
 *		参数：
 *			bn：大整数
 *		返回值：
 *			成功返回复制后的大整数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_dup(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getdata
 *			获取大整数的补码
 *		参数：
 *			bn：大整数
 *		返回值：
 *			成功返回大整数的补码，失败返回NULL
 */
NETCA_Data_Blob NETCAAPI netca_biginteger_getdata(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getsign
 *			获取大整数的符号
 *		参数：
 *			bn：大整数
 *		返回值：
 *			如果大整数大于0返回1，小于0返回-1，等于0返回0
 */
int NETCAAPI netca_biginteger_getsign(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getbitcount
 *			获取大整数的位数
 *		参数：
 *			bn：大整数
 *		返回值：
 *			成功返回大整数的位数，失败返回-1
 */
long NETCAAPI netca_biginteger_getbitcount(NETCA_BigInteger bn);


/*
 *		netca_biginteger_testbit
 *			判断第bit位是否为1
 *		参数：
 *			bn：大整数
 *			bit：位
 *		返回值：
 *			为1返回1，否则返回0
 */
int NETCAAPI netca_biginteger_testbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_setbit
 *			设置第bit位为1
 *		参数：
 *			bn：大整数
 *			bit：位
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_biginteger_setbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_setbit
 *			设置第bit位为0
 *		参数：
 *			bn：大整数
 *			bit：位
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_biginteger_clearbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_unsigned_tonbuf
 *			把无符号的大整数的补码，写入到缓冲区中，如果为负数则出错
 *		参数：
 *			bn：大整数
 *			n：输入参数，缓冲区大小
 *			buf：输出参数，缓冲区，如果大整数的补码的长度不够，则在最前面补0
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_biginteger_unsigned_tonbuf(NETCA_BigInteger bn,long n,unsigned char *buf);

/*
 *		netca_biginteger_unsigned_todec
 *			把无符号的大整数的转换为10进制表示，如果为负数则出错
 *		参数：
 *			bn：大整数
 *			dec：输出参数，返回的10进制表示
 *			declen：输出参数，返回的dec的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_biginteger_unsigned_todec(NETCA_BigInteger bn,char **dec,long *declen);

/*
 *		netca_biginteger_newdec
 *			根据10进制表示创建大整数
 *		参数：
 *			dec：输入参数，10进制表示
 *		返回值：
 *			成功返回大整数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newdec(const char *dec);

/*
 *		netca_biginteger_cmp
 *			比较两个大整数
 *		参数：
 *			a：输入参数，要比较的大整数1
 *			b：输入参数，要比较的大整数2
 *		返回值：
 *			如果a>b则返回1，如果a<b则返回-1，如果a==b则返回0
 */
int NETCAAPI netca_biginteger_cmp(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_add
 *			两个大整数相加
 *		参数：
 *			a：输入参数，要相加的大整数1
 *			b：输入参数，要相加的大整数2
 *		返回值：
 *			成功返回a+b，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_add(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_sub
 *			两个大整数相减
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *		返回值：
 *			成功返回a-b，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_sub(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_neg
 *			求大整数的相反数
 *		参数：
 *			a：输入参数，大整数
 *		返回值：
 *			成功返回-a，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_neg(NETCA_BigInteger a);

/*
 *		netca_biginteger_mul
 *			两个大整数相乘
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *		返回值：
 *			成功返回a*b，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mul(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_div
 *			两个大整数相除，retval*b+*rem=a
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *			rem：输出参数，返回余数
 *		返回值：
 *			成功返回商，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_div(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger *rem);

/*
 *		netca_biginteger_mod
 *			求大整数的模
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *		返回值：
 *			成功返回a mod b，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mod(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_expmod
 *			求大整数指数的模
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *			m：输入参数，模
 *		返回值：
 *			成功返回a^b mod m，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_expmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			求大整数相加的模
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *			m：输入参数，模
 *		返回值：
 *			成功返回(a+b) mod m，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_addmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			求大整数相减的模
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *			m：输入参数，模
 *		返回值：
 *			成功返回(a-b) mod m，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_submod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			求大整数相乘的模
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *			m：输入参数，模
 *		返回值：
 *			成功返回(a*b) mod m，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mulmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_gcd
 *			求大整数最大公约数
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *		返回值：
 *			成功返回gcd(a,b)，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_gcd(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_gcd
 *			求大整数最小公倍数
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，大整数2
 *		返回值：
 *			成功返回lcm(a,b)，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_lcm(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_invmod
 *			求大整数的逆
 *		参数：
 *			a：输入参数，大整数1
 *			b：输入参数，模
 *		返回值：
 *			成功返回1/a mod b，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_invmod(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_isprime
 *			判断大整数的是否为素数
 *		参数：
 *			bn：输入参数，大整数
 *		返回值：
 *			如果为素数返回1，否则返回0
 */
int NETCAAPI netca_biginteger_isprime(NETCA_BigInteger bn);

/*
 *		netca_biginteger_isprime_fasttest
 *			快速判断大整数的是否为素数
 *		参数：
 *			bn：输入参数，大整数
 *		返回值：
 *			如果为素数返回1，否则返回0
 */
int NETCAAPI netca_biginteger_isprime_fasttest(NETCA_BigInteger bn);

#define NETCA_PRIME_FLAG_SAFE		1
#define NETCA_PRIME_FLAG_2MSB_ON	2
#define NETCA_PRIME_FLAG_FAST		0x80

typedef int (NETCAAPI *netca_biginteger_random_cb)(void *context,unsigned char *rnd,long rndlen);

/*
 *		netca_biginteger_newprime
 *			产生一个素数
 *		参数：
 *			cb：回调函数，用来产生随机数
 *			context：回调函数的参数
 *			bits：输入参数，要产生的素数的位数
 *			flag：输入参数，标志，如果NETCA_PRIME_FLAG_SAFE置位则产生安全素数，如果NETCA_PRIME_FLAG_2MSB_ON置位则产生的素数最高2位都为1
 *		返回值：
 *			成功返回素数，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newprime(netca_biginteger_random_cb cb,void *context,int bits,int flag);

/*
 *		netca_biginteger_iseven
 *			判断大整数是否为偶数
 *		参数：
 *			bn：大整数
 *		返回值：
 *			如果大整数为偶数返回1，否则返回0
 */
int NETCAAPI netca_biginteger_iseven(NETCA_BigInteger bn);

/*
 *		netca_biginteger_isodd
 *			判断大整数是否为奇数
 *		参数：
 *			bn：大整数
 *		返回值：
 *			如果大整数为奇数返回1，否则返回0
 */
int NETCAAPI netca_biginteger_isodd(NETCA_BigInteger bn);

/*
 *		netca_biginteger_div_2
 *			计算a/2
 *		参数：
 *			a：大整数
 *		返回值：
 *			成功返回a/2，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_div_2(NETCA_BigInteger a);

/*
 *		netca_biginteger_sqrmod
 *			计算平方的模
 *		参数：
 *			a：大整数
 *			b：模
 *		返回值：
 *			成功返回a * a (mod b)，失败返回NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_sqrmod(NETCA_BigInteger a,NETCA_BigInteger b);

#ifdef __cplusplus
	}	
#endif
#endif

