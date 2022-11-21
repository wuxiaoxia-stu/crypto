#ifndef NETCA_LOCK_INLCUDE_H
#define NETCA_LOCK_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_lock_new
 *			����һ��������
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ػ�������ʧ�ܷ���NULL
 */
NETCA_Lock NETCAAPI netca_lock_new(void);
/*
 *		netca_lock_free
 *			�ͷŻ�����
 *		������
 *			lock��������
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_lock_free(NETCA_Lock lock);

/*
 *		netca_lock_lock
 *			����
 *		������
 *			lock��������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_lock_lock(NETCA_Lock lock);

/*
 *		netca_lock_unlock
 *			����
 *		������
 *			lock��������
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_lock_unlock(NETCA_Lock lock);


/*
 *		netca_lock_trylock
 *			����
 *		������
 *			lock��������
 *		����ֵ��
 *			����NETCA_OK��ʾ��ȡ����������������ֵ��ʾ���ܻ����
 */
int NETCAAPI netca_lock_trylock(NETCA_Lock lock);

/*
 *		netca_rwlock_new
 *			����һ����д��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ض�д����ʧ�ܷ���NULL
 */
NETCA_RWLock NETCAAPI netca_rwlock_new(void);

/*
 *		netca_rwlock_free
 *			�ͷŶ�д��
 *		������
 *			lock����д��
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_rwlock_free(NETCA_RWLock lock);

/*
 *		netca_rwlock_readerlock
 *			�϶���
 *		������
 *			lock����д��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_rwlock_readerlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_readerunlock
 *			�����
 *		������
 *			lock����д��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_rwlock_readerunlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_writerlock
 *			��д��
 *		������
 *			lock����д��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_rwlock_writerlock(NETCA_RWLock lock);

/*
 *		netca_rwlock_writerunlock
 *			��д��
 *		������
 *			lock����д��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_rwlock_writerunlock(NETCA_RWLock lock);


/*
 *		netca_atomic_inc
 *			ԭ�Ӽ�1
 *		������
 *			value������ֵ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_atomic_inc(volatile int* value);

/*
 *		netca_atomic_dec
 *			ԭ�Ӽ�1
 *		������
 *			value������ֵ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_atomic_dec(volatile int* value);

/*
 *		netca_atomic_set
 *			ԭ����ֵ
 *		������
 *			value������ֵ
 *			newvalue��Ҫ���õ���ֵ
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_atomic_set(volatile int* value,int newvalue);

/*
 *		netca_atomic_get
 *			ԭ�Ӷ�
 *		������
 *			value������ֵ
 *			newvalue��Ҫ���õ���ֵ
 *		����ֵ��
 *			��
 */
int NETCAAPI netca_atomic_get(volatile int* value);


/*
 *		netca_atomic_dec_and_test
 *			ԭ�Ӽ�1���������Ƿ�Ϊ0
 *		������
 *			value������ֵ
 *		����ֵ��
 *			���Ϊ0���򷵻�1�����򷵻�0
 */
int NETCAAPI netca_atomic_dec_and_test(volatile int* value);

#ifdef __cplusplus
	}	
#endif
#endif
