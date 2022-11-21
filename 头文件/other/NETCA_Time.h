#ifndef NETCA_TIME_INLCUDE_H
#define NETCA_TIME_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_time_newutctime
 *			����UTCʱ��
 *		������
 *			year�������������
 *			month�������������
 *			day�������������
 *			hour�����������ʱ
 *			minute�������������
 *			second�������������
 *			ns���������������
 *		����ֵ��
 *			�ɹ�����UTCʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_newutctime(int year,int month,int day,int hour,int minute,int second,long ns);

/*
 *		netca_time_newlocaltime
 *			��������ʱ��
 *		������
 *			year�������������
 *			month�������������
 *			day�������������
 *			hour�����������ʱ
 *			minute�������������
 *			second�������������
 *			ns���������������
 *			isdst�����������Ϊ���ʾʹ������ʱ��Ϊ�ٱ�ʾ��ʹ��
 *		����ֵ��
 *			�ɹ����ر���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_newlocaltime(int year,int month,int day,int hour,int minute,int second,long ns,int isdst);

/*
 *		netca_time_getyear
 *			��ȡʱ������
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ����꣬ʧ�ܷ���-1
 */
int NETCAAPI netca_time_getyear(NETCA_Time time);

/*
 *		netca_time_getmonth
 *			��ȡʱ�����
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ����£�ʧ�ܷ���-1
 */
int NETCAAPI netca_time_getmonth(NETCA_Time time);

/*
 *		netca_time_getday
 *			��ȡʱ�����
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ����գ�ʧ�ܷ���-1
 */
int NETCAAPI netca_time_getday(NETCA_Time time);

/*
 *		netca_time_gethour
 *			��ȡʱ���ʱ
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ���ʱ��ʧ�ܷ���-1
 */
int NETCAAPI netca_time_gethour(NETCA_Time time);

/*
 *		netca_time_getminute
 *			��ȡʱ��ķ�
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ��ķ֣�ʧ�ܷ���-1
 */
int NETCAAPI netca_time_getminute(NETCA_Time time);

/*
 *		netca_time_getsecond
 *			��ȡʱ�����
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ����룬ʧ�ܷ���-1
 */
int NETCAAPI netca_time_getsecond(NETCA_Time time);

/*
 *		netca_time_getns
 *			��ȡʱ�������
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ʱ������룬ʧ�ܷ���-1
 */
long NETCAAPI netca_time_getns(NETCA_Time time);

/*
 *		netca_time_isutctime
 *			�ж�ʱ���Ƿ���UTCʱ��
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�����UTCʱ�䷵��1�����򷵻�0
 */
int NETCAAPI netca_time_isutctime(NETCA_Time time);

/*
 *		netca_time_isdst
 *			�ж�ʱ���Ƿ�������ʱ
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			���������ʱ����1�����򷵻�0
 */
int NETCAAPI netca_time_isdst(NETCA_Time time);

/*
 *		netca_time_local2utc
 *			����ʱ��ת��ΪUTCʱ��
 *		������
 *			time������ʱ��
 *		����ֵ��
 *			�ɹ�����ת�����UTCʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_local2utc(NETCA_Time time);

/*
 *		netca_time_local2utc
 *			UTCʱ��ת��Ϊ����ʱ��
 *		������
 *			time��UTCʱ��
 *		����ֵ��
 *			�ɹ�����ת����ı���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_utc2local(NETCA_Time time);

/*
 *		netca_time_cmp
 *			ʱ��Ƚ�
 *		������
 *			time1��ʱ��1
 *			time2��ʱ��2
 *		����ֵ��
 *			���time1��time2֮ǰ������-1�����time2��time1֮ǰ����1�������ȷ���0
 */
int NETCAAPI netca_time_cmp(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_dup
 *			����ʱ��
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ����ظ��ƺ��ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_dup(NETCA_Time time);

/*
 *		netca_time_dup
 *			����ʱ��
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ����ظ��ƺ��ʱ�䣬ʧ�ܷ���NULL
 */
void NETCAAPI netca_time_free(NETCA_Time time);

/*
 *		netca_time_addyear
 *			ʱ�����
 *		������
 *			time��ʱ��
 *			year�������������
 *		����ֵ��
 *			�ɹ���������year����ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addyear(NETCA_Time time,int year);

/*
 *		netca_time_addmonth
 *			ʱ�����
 *		������
 *			time��ʱ��
 *			month�������������
 *		����ֵ��
 *			�ɹ���������month�º��ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addmonth(NETCA_Time time,int month);

/*
 *		netca_time_addday
 *			ʱ�����
 *		������
 *			time��ʱ��
 *			day�������������
 *		����ֵ��
 *			�ɹ���������day�պ��ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addday(NETCA_Time time,int day);

/*
 *		netca_time_addhour
 *			ʱ���Сʱ
 *		������
 *			time��ʱ��
 *			hour�����������Сʱ
 *		����ֵ��
 *			�ɹ���������hourСʱ���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addhour(NETCA_Time time,int hour);

/*
 *		netca_time_addminute
 *			ʱ��ӷ���
 *		������
 *			time��ʱ��
 *			minute���������������
 *		����ֵ��
 *			�ɹ���������minute���Ӻ��ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addminute(NETCA_Time time,int minute);
/*
 *		netca_time_addsecond
 *			ʱ�����
 *		������
 *			time��ʱ��
 *			second�������������
 *		����ֵ��
 *			�ɹ���������second����ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_addsecond(NETCA_Time time,int second);

/*
 *		netca_time_nowutctime
 *			��ȡ��ǰ��UTCʱ��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ�����UTCʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_nowutctime(void);

/*
 *		netca_time_nowlocaltime
 *			��ȡ��ǰ�ı���ʱ��
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ر���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_nowlocaltime(void);

/*
 *		netca_time_isleapyear
 *			�ж�ʱ���Ƿ�������
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			��������귵��1�����򷵻�0
 */
int NETCAAPI netca_time_isleapyear(NETCA_Time time);

/*
 *		netca_time_isleapsecond
 *			�ж�ʱ���Ƿ�������
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			��������뷵��1�����򷵻�0
 */
int NETCAAPI netca_time_isleapsecond(NETCA_Time time);

/*
 *		netca_time_gettime_t
 *			ʱ��ת��Ϊ1970��1��1�տ�ʼ������
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ת�����������ʧ�ܷ���INT64MIN
 */
integer64 NETCAAPI netca_time_gettime_t(NETCA_Time time);

/*
 *		netca_time_diffdays
 *			��������ʱ����������
 *		������
 *			time1��ʱ��1
 *			time2��ʱ��2
 *		����ֵ��
 *			����time1-time2������
 */
int NETCAAPI netca_time_diffdays(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_diffseconds
 *			��������ʱ����������
 *		������
 *			time1��ʱ��1
 *			time2��ʱ��2
 *		����ֵ��
 *			����time1-time2������
 */
integer64 NETCAAPI netca_time_diffseconds(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_getdayofweek
 *			��ȡʱ�������ڼ�
 *		������
 *			time��ʱ��
 *		����ֵ��
 *			����������췵��0������һ����1���������
 */
int NETCAAPI netca_time_getdayofweek(NETCA_Time time);

/*
 *		netca_time_newlocaltimebyzone
 *			����ʱ����������ʱ��
 *		������
 *			name�����������ʱ����
 *			year�������������
 *			month�������������
 *			day�������������
 *			hour�����������ʱ
 *			minute�������������
 *			second�������������
 *			ns���������������
 *			isdst�����������Ϊ���ʾʹ������ʱ��Ϊ�ٱ�ʾ��ʹ��
 *		����ֵ��
 *			�ɹ����ر���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_newlocaltimebyzone(const char *name,int year,int month,int day,int hour,int minute,int second,long ns,int isdst);
/*
 *		netca_time_utc2localbyzone
 *			����ʱ����UTCʱ��ת��Ϊ����ʱ��
 *		������
 *			name�����������ʱ����
 *			time��ʱ��
 *		����ֵ��
 *			�ɹ�����ת����ı���ʱ�䣬ʧ�ܷ���NULL
 */
NETCA_Time NETCAAPI netca_time_utc2localbyzone(const char *name,NETCA_Time time);


#ifdef __cplusplus
	}	
#endif
#endif
