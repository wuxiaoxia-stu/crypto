#ifndef NETCA_TIME_INLCUDE_H
#define NETCA_TIME_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_time_newutctime
 *			创建UTC时间
 *		参数：
 *			year：输入参数，年
 *			month：输入参数，月
 *			day：输入参数，日
 *			hour：输入参数，时
 *			minute：输入参数，分
 *			second：输入参数，秒
 *			ns：输入参数，纳秒
 *		返回值：
 *			成功返回UTC时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_newutctime(int year,int month,int day,int hour,int minute,int second,long ns);

/*
 *		netca_time_newlocaltime
 *			创建本地时间
 *		参数：
 *			year：输入参数，年
 *			month：输入参数，月
 *			day：输入参数，日
 *			hour：输入参数，时
 *			minute：输入参数，分
 *			second：输入参数，秒
 *			ns：输入参数，纳秒
 *			isdst：输入参数，为真表示使用夏令时，为假表示不使用
 *		返回值：
 *			成功返回本地时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_newlocaltime(int year,int month,int day,int hour,int minute,int second,long ns,int isdst);

/*
 *		netca_time_getyear
 *			获取时间的年份
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的年，失败返回-1
 */
int NETCAAPI netca_time_getyear(NETCA_Time time);

/*
 *		netca_time_getmonth
 *			获取时间的月
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的月，失败返回-1
 */
int NETCAAPI netca_time_getmonth(NETCA_Time time);

/*
 *		netca_time_getday
 *			获取时间的日
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的日，失败返回-1
 */
int NETCAAPI netca_time_getday(NETCA_Time time);

/*
 *		netca_time_gethour
 *			获取时间的时
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的时，失败返回-1
 */
int NETCAAPI netca_time_gethour(NETCA_Time time);

/*
 *		netca_time_getminute
 *			获取时间的分
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的分，失败返回-1
 */
int NETCAAPI netca_time_getminute(NETCA_Time time);

/*
 *		netca_time_getsecond
 *			获取时间的秒
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的秒，失败返回-1
 */
int NETCAAPI netca_time_getsecond(NETCA_Time time);

/*
 *		netca_time_getns
 *			获取时间的纳秒
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回时间的纳秒，失败返回-1
 */
long NETCAAPI netca_time_getns(NETCA_Time time);

/*
 *		netca_time_isutctime
 *			判断时间是否是UTC时间
 *		参数：
 *			time：时间
 *		返回值：
 *			如果是UTC时间返回1，否则返回0
 */
int NETCAAPI netca_time_isutctime(NETCA_Time time);

/*
 *		netca_time_isdst
 *			判断时间是否是夏令时
 *		参数：
 *			time：时间
 *		返回值：
 *			如果是夏令时返回1，否则返回0
 */
int NETCAAPI netca_time_isdst(NETCA_Time time);

/*
 *		netca_time_local2utc
 *			本地时间转换为UTC时间
 *		参数：
 *			time：本地时间
 *		返回值：
 *			成功返回转换后的UTC时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_local2utc(NETCA_Time time);

/*
 *		netca_time_local2utc
 *			UTC时间转换为本地时间
 *		参数：
 *			time：UTC时间
 *		返回值：
 *			成功返回转换后的本地时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_utc2local(NETCA_Time time);

/*
 *		netca_time_cmp
 *			时间比较
 *		参数：
 *			time1：时间1
 *			time2：时间2
 *		返回值：
 *			如果time1在time2之前，返回-1，如果time2在time1之前返回1，如果相等返回0
 */
int NETCAAPI netca_time_cmp(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_dup
 *			复制时间
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回复制后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_dup(NETCA_Time time);

/*
 *		netca_time_dup
 *			复制时间
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回复制后的时间，失败返回NULL
 */
void NETCAAPI netca_time_free(NETCA_Time time);

/*
 *		netca_time_addyear
 *			时间加年
 *		参数：
 *			time：时间
 *			year：输入参数，年
 *		返回值：
 *			成功返回增加year年后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addyear(NETCA_Time time,int year);

/*
 *		netca_time_addmonth
 *			时间加月
 *		参数：
 *			time：时间
 *			month：输入参数，月
 *		返回值：
 *			成功返回增加month月后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addmonth(NETCA_Time time,int month);

/*
 *		netca_time_addday
 *			时间加日
 *		参数：
 *			time：时间
 *			day：输入参数，日
 *		返回值：
 *			成功返回增加day日后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addday(NETCA_Time time,int day);

/*
 *		netca_time_addhour
 *			时间加小时
 *		参数：
 *			time：时间
 *			hour：输入参数，小时
 *		返回值：
 *			成功返回增加hour小时后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addhour(NETCA_Time time,int hour);

/*
 *		netca_time_addminute
 *			时间加分钟
 *		参数：
 *			time：时间
 *			minute：输入参数，分钟
 *		返回值：
 *			成功返回增加minute分钟后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addminute(NETCA_Time time,int minute);
/*
 *		netca_time_addsecond
 *			时间加秒
 *		参数：
 *			time：时间
 *			second：输入参数，秒
 *		返回值：
 *			成功返回增加second秒后的时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_addsecond(NETCA_Time time,int second);

/*
 *		netca_time_nowutctime
 *			获取当前的UTC时间
 *		参数：
 *			无
 *		返回值：
 *			成功返回UTC时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_nowutctime(void);

/*
 *		netca_time_nowlocaltime
 *			获取当前的本地时间
 *		参数：
 *			无
 *		返回值：
 *			成功返回本地时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_nowlocaltime(void);

/*
 *		netca_time_isleapyear
 *			判断时间是否是闰年
 *		参数：
 *			time：时间
 *		返回值：
 *			如果是闰年返回1，否则返回0
 */
int NETCAAPI netca_time_isleapyear(NETCA_Time time);

/*
 *		netca_time_isleapsecond
 *			判断时间是否是闰秒
 *		参数：
 *			time：时间
 *		返回值：
 *			如果是闰秒返回1，否则返回0
 */
int NETCAAPI netca_time_isleapsecond(NETCA_Time time);

/*
 *		netca_time_gettime_t
 *			时间转换为1970年1月1日开始的秒数
 *		参数：
 *			time：时间
 *		返回值：
 *			成功返回转换后的秒数，失败返回INT64MIN
 */
integer64 NETCAAPI netca_time_gettime_t(NETCA_Time time);

/*
 *		netca_time_diffdays
 *			计算两个时间相差的天数
 *		参数：
 *			time1：时间1
 *			time2：时间2
 *		返回值：
 *			返回time1-time2的天数
 */
int NETCAAPI netca_time_diffdays(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_diffseconds
 *			计算两个时间相差的秒数
 *		参数：
 *			time1：时间1
 *			time2：时间2
 *		返回值：
 *			返回time1-time2的秒数
 */
integer64 NETCAAPI netca_time_diffseconds(NETCA_Time time1,NETCA_Time time2);

/*
 *		netca_time_getdayofweek
 *			获取时间是星期几
 *		参数：
 *			time：时间
 *		返回值：
 *			如果是星期天返回0，星期一返回1，如此类推
 */
int NETCAAPI netca_time_getdayofweek(NETCA_Time time);

/*
 *		netca_time_newlocaltimebyzone
 *			根据时区创建本地时间
 *		参数：
 *			name：输入参数，时区名
 *			year：输入参数，年
 *			month：输入参数，月
 *			day：输入参数，日
 *			hour：输入参数，时
 *			minute：输入参数，分
 *			second：输入参数，秒
 *			ns：输入参数，纳秒
 *			isdst：输入参数，为真表示使用夏令时，为假表示不使用
 *		返回值：
 *			成功返回本地时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_newlocaltimebyzone(const char *name,int year,int month,int day,int hour,int minute,int second,long ns,int isdst);
/*
 *		netca_time_utc2localbyzone
 *			根据时区把UTC时间转换为本地时间
 *		参数：
 *			name：输入参数，时区名
 *			time：时间
 *		返回值：
 *			成功返回转换后的本地时间，失败返回NULL
 */
NETCA_Time NETCAAPI netca_time_utc2localbyzone(const char *name,NETCA_Time time);


#ifdef __cplusplus
	}	
#endif
#endif
