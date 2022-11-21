#ifndef NETCA_LOCK_INLCUDE_H
#define NETCA_LOCK_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_lock_new
 *			创建一个互斥锁
 *		参数：
 *			无
 *		返回值：
 *			成功返回互斥锁，失败返回NULL
 */
NETCA_Lock NETCAAPI netca_lock_new(void);
/*
 *		netca_lock_free
 *			释放互斥锁
 *		参数：
 *			lock：互斥锁
 *		返回值：
 *			无
 */
void NETCAAPI netca_lock_free(NETCA_Lock lock);

/*
 *		netca_lock_lock
 *			上锁
 *		参数：
 *			lock：互斥锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_lock_lock(NETCA_Lock lock);

/*
 *		netca_lock_unlock
 *			解锁
 *		参数：
 *			lock：互斥锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_lock_unlock(NETCA_Lock lock);


/*
 *		netca_lock_trylock
 *			解锁
 *		参数：
 *			lock：互斥锁
 *		返回值：
 *			返回NETCA_OK表示获取互斥锁，返回其他值表示不能获得锁
 */
int NETCAAPI netca_lock_trylock(NETCA_Lock lock);

/*
 *		netca_rwlock_new
 *			创建一个读写锁
 *		参数：
 *			无
 *		返回值：
 *			成功返回读写锁，失败返回NULL
 */
NETCA_RWLock NETCAAPI netca_rwlock_new(void);

/*
 *		netca_rwlock_free
 *			释放读写锁
 *		参数：
 *			lock：读写锁
 *		返回值：
 *			无
 */
void NETCAAPI netca_rwlock_free(NETCA_RWLock lock);

/*
 *		netca_rwlock_readerlock
 *			上读锁
 *		参数：
 *			lock：读写锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_rwlock_readerlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_readerunlock
 *			解读锁
 *		参数：
 *			lock：读写锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_rwlock_readerunlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_writerlock
 *			上写锁
 *		参数：
 *			lock：读写锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_rwlock_writerlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_writerunlock
 *			解写锁
 *		参数：
 *			lock：读写锁
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_rwlock_writerunlock(NETCA_RWLock lock);


/*
 *		netca_atomic_inc
 *			原子加1
 *		参数：
 *			value：整数值
 *		返回值：
 *			无
 */
void NETCAAPI netca_atomic_inc(volatile int* value);

/*
 *		netca_atomic_dec
 *			原子减1
 *		参数：
 *			value：整数值
 *		返回值：
 *			无
 */
void NETCAAPI netca_atomic_dec(volatile int* value);

/*
 *		netca_atomic_set
 *			原子设值
 *		参数：
 *			value：整数值
 *			newvalue：要设置的新值
 *		返回值：
 *			无
 */
void NETCAAPI netca_atomic_set(volatile int* value,int newvalue);

/*
 *		netca_atomic_get
 *			原子读
 *		参数：
 *			value：整数值
 *			newvalue：要设置的新值
 *		返回值：
 *			无
 */
int NETCAAPI netca_atomic_get(volatile int* value);


/*
 *		netca_atomic_dec_and_test
 *			原子减1，并测试是否为0
 *		参数：
 *			value：整数值
 *		返回值：
 *			如果为0，则返回1，否则返回0
 */
int NETCAAPI netca_atomic_dec_and_test(volatile int* value);

#ifdef __cplusplus
	}	
#endif
#endif
