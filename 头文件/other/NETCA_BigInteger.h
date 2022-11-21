#ifndef NETCA_BIGINTER_INLCUDE_H
#define NETCA_BIGINTER_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_biginteger_newdata
 *			����һ���������������ɸ�
 *		������
 *			buf����������������Ĳ��룬���λΪ1��ʾ����
 *			buflen�����������buf�ĳ���
 *		����ֵ��
 *			�ɹ����ش�������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newdata(const unsigned char *buf,long buflen);

/*
 *		netca_biginteger_newunsigneddata
 *			����һ���Ǹ��Ĵ�����
 *		������
 *			buf����������������Ĳ���
 *			buflen�����������buf�ĳ���
 *		����ֵ��
 *			�ɹ����ش�������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newunsigneddata(const unsigned char *buf,long buflen);

/*
 *		netca_biginteger_free
 *			�ͷŴ�����
 *		������
 *			bn��������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_biginteger_free(NETCA_BigInteger bn);

/*
 *		netca_biginteger_new
 *			����һ��64λ������ת��Ϊ������
 *		������
 *			value�����������64λ������
 *		����ֵ��
 *			�ɹ����ش�������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_new(integer64 value);

/*
 *		netca_biginteger_getvalue
 *			�Ѵ�����ת��Ϊ64λ������
 *		������
 *			bn��������
 *			value���������������ת�����64λ������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_biginteger_getvalue(NETCA_BigInteger bn,integer64 *value);

/*
 *		netca_biginteger_dup
 *			����һ��������
 *		������
 *			bn��������
 *		����ֵ��
 *			�ɹ����ظ��ƺ�Ĵ�������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_dup(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getdata
 *			��ȡ�������Ĳ���
 *		������
 *			bn��������
 *		����ֵ��
 *			�ɹ����ش������Ĳ��룬ʧ�ܷ���NULL
 */
NETCA_Data_Blob NETCAAPI netca_biginteger_getdata(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getsign
 *			��ȡ�������ķ���
 *		������
 *			bn��������
 *		����ֵ��
 *			�������������0����1��С��0����-1������0����0
 */
int NETCAAPI netca_biginteger_getsign(NETCA_BigInteger bn);

/*
 *		netca_biginteger_getbitcount
 *			��ȡ��������λ��
 *		������
 *			bn��������
 *		����ֵ��
 *			�ɹ����ش�������λ����ʧ�ܷ���-1
 */
long NETCAAPI netca_biginteger_getbitcount(NETCA_BigInteger bn);


/*
 *		netca_biginteger_testbit
 *			�жϵ�bitλ�Ƿ�Ϊ1
 *		������
 *			bn��������
 *			bit��λ
 *		����ֵ��
 *			Ϊ1����1�����򷵻�0
 */
int NETCAAPI netca_biginteger_testbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_setbit
 *			���õ�bitλΪ1
 *		������
 *			bn��������
 *			bit��λ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_biginteger_setbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_setbit
 *			���õ�bitλΪ0
 *		������
 *			bn��������
 *			bit��λ
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_biginteger_clearbit(NETCA_BigInteger bn,int bit);

/*
 *		netca_biginteger_unsigned_tonbuf
 *			���޷��ŵĴ������Ĳ��룬д�뵽�������У����Ϊ���������
 *		������
 *			bn��������
 *			n�������������������С
 *			buf�����������������������������Ĳ���ĳ��Ȳ�����������ǰ�油0
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_biginteger_unsigned_tonbuf(NETCA_BigInteger bn,long n,unsigned char *buf);

/*
 *		netca_biginteger_unsigned_todec
 *			���޷��ŵĴ�������ת��Ϊ10���Ʊ�ʾ�����Ϊ���������
 *		������
 *			bn��������
 *			dec��������������ص�10���Ʊ�ʾ
 *			declen��������������ص�dec�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_biginteger_unsigned_todec(NETCA_BigInteger bn,char **dec,long *declen);

/*
 *		netca_biginteger_newdec
 *			����10���Ʊ�ʾ����������
 *		������
 *			dec�����������10���Ʊ�ʾ
 *		����ֵ��
 *			�ɹ����ش�������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newdec(const char *dec);

/*
 *		netca_biginteger_cmp
 *			�Ƚ�����������
 *		������
 *			a�����������Ҫ�ȽϵĴ�����1
 *			b�����������Ҫ�ȽϵĴ�����2
 *		����ֵ��
 *			���a>b�򷵻�1�����a<b�򷵻�-1�����a==b�򷵻�0
 */
int NETCAAPI netca_biginteger_cmp(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_add
 *			�������������
 *		������
 *			a�����������Ҫ��ӵĴ�����1
 *			b�����������Ҫ��ӵĴ�����2
 *		����ֵ��
 *			�ɹ�����a+b��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_add(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_sub
 *			�������������
 *		������
 *			a�����������������1
 *			b�����������������2
 *		����ֵ��
 *			�ɹ�����a-b��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_sub(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_neg
 *			����������෴��
 *		������
 *			a�����������������
 *		����ֵ��
 *			�ɹ�����-a��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_neg(NETCA_BigInteger a);

/*
 *		netca_biginteger_mul
 *			�������������
 *		������
 *			a�����������������1
 *			b�����������������2
 *		����ֵ��
 *			�ɹ�����a*b��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mul(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_div
 *			���������������retval*b+*rem=a
 *		������
 *			a�����������������1
 *			b�����������������2
 *			rem�������������������
 *		����ֵ��
 *			�ɹ������̣�ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_div(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger *rem);

/*
 *		netca_biginteger_mod
 *			���������ģ
 *		������
 *			a�����������������1
 *			b�����������������2
 *		����ֵ��
 *			�ɹ�����a mod b��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mod(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_expmod
 *			�������ָ����ģ
 *		������
 *			a�����������������1
 *			b�����������������2
 *			m�����������ģ
 *		����ֵ��
 *			�ɹ�����a^b mod m��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_expmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			���������ӵ�ģ
 *		������
 *			a�����������������1
 *			b�����������������2
 *			m�����������ģ
 *		����ֵ��
 *			�ɹ�����(a+b) mod m��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_addmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			������������ģ
 *		������
 *			a�����������������1
 *			b�����������������2
 *			m�����������ģ
 *		����ֵ��
 *			�ɹ�����(a-b) mod m��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_submod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_addmod
 *			���������˵�ģ
 *		������
 *			a�����������������1
 *			b�����������������2
 *			m�����������ģ
 *		����ֵ��
 *			�ɹ�����(a*b) mod m��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_mulmod(NETCA_BigInteger a,NETCA_BigInteger b,NETCA_BigInteger m);

/*
 *		netca_biginteger_gcd
 *			����������Լ��
 *		������
 *			a�����������������1
 *			b�����������������2
 *		����ֵ��
 *			�ɹ�����gcd(a,b)��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_gcd(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_gcd
 *			���������С������
 *		������
 *			a�����������������1
 *			b�����������������2
 *		����ֵ��
 *			�ɹ�����lcm(a,b)��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_lcm(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_invmod
 *			�����������
 *		������
 *			a�����������������1
 *			b�����������ģ
 *		����ֵ��
 *			�ɹ�����1/a mod b��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_invmod(NETCA_BigInteger a,NETCA_BigInteger b);

/*
 *		netca_biginteger_isprime
 *			�жϴ��������Ƿ�Ϊ����
 *		������
 *			bn�����������������
 *		����ֵ��
 *			���Ϊ��������1�����򷵻�0
 */
int NETCAAPI netca_biginteger_isprime(NETCA_BigInteger bn);

/*
 *		netca_biginteger_isprime_fasttest
 *			�����жϴ��������Ƿ�Ϊ����
 *		������
 *			bn�����������������
 *		����ֵ��
 *			���Ϊ��������1�����򷵻�0
 */
int NETCAAPI netca_biginteger_isprime_fasttest(NETCA_BigInteger bn);

#define NETCA_PRIME_FLAG_SAFE		1
#define NETCA_PRIME_FLAG_2MSB_ON	2
#define NETCA_PRIME_FLAG_FAST		0x80

typedef int (NETCAAPI *netca_biginteger_random_cb)(void *context,unsigned char *rnd,long rndlen);

/*
 *		netca_biginteger_newprime
 *			����һ������
 *		������
 *			cb���ص��������������������
 *			context���ص������Ĳ���
 *			bits�����������Ҫ������������λ��
 *			flag�������������־�����NETCA_PRIME_FLAG_SAFE��λ�������ȫ���������NETCA_PRIME_FLAG_2MSB_ON��λ��������������2λ��Ϊ1
 *		����ֵ��
 *			�ɹ�����������ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_newprime(netca_biginteger_random_cb cb,void *context,int bits,int flag);

/*
 *		netca_biginteger_iseven
 *			�жϴ������Ƿ�Ϊż��
 *		������
 *			bn��������
 *		����ֵ��
 *			���������Ϊż������1�����򷵻�0
 */
int NETCAAPI netca_biginteger_iseven(NETCA_BigInteger bn);

/*
 *		netca_biginteger_isodd
 *			�жϴ������Ƿ�Ϊ����
 *		������
 *			bn��������
 *		����ֵ��
 *			���������Ϊ��������1�����򷵻�0
 */
int NETCAAPI netca_biginteger_isodd(NETCA_BigInteger bn);

/*
 *		netca_biginteger_div_2
 *			����a/2
 *		������
 *			a��������
 *		����ֵ��
 *			�ɹ�����a/2��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_div_2(NETCA_BigInteger a);

/*
 *		netca_biginteger_sqrmod
 *			����ƽ����ģ
 *		������
 *			a��������
 *			b��ģ
 *		����ֵ��
 *			�ɹ�����a * a (mod b)��ʧ�ܷ���NULL
 */
NETCA_BigInteger NETCAAPI netca_biginteger_sqrmod(NETCA_BigInteger a,NETCA_BigInteger b);

#ifdef __cplusplus
	}	
#endif
#endif

