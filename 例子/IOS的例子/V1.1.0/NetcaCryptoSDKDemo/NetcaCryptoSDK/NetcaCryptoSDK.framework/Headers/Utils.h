//
//  Utils.h
//  NetcaCertMgr
//
//  Created by NetcaDeveloper on 15/12/1.
//  Copyright (c) 2015年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Utils : NSObject

//时间字符串转NSDate
+ (NSDate *)NSStringToDate:(NSString *)time;

//获取系统当前时间
+ (NSDate *)getSysCurTime;

//判断证书是否过期
+ (bool)isCertOutDate:(NSString *)certValidDateBefore validDateAfter:(NSString *)certValidDateAfter;

//拼接请求字符串
+ (NSString *)getPostParamsString:(NSMutableDictionary *)params;

//分割请求字符串
+ (NSMutableDictionary *)getParamsDic:(NSString *)query;

//计算字符串的哈希值
+ (NSData *)sha256:(NSData *)data;

//NSData转换为十六进制
+ (NSString *)hexStringFromNSData:(NSData *)data;

//十六进制转NSData
+ (NSData *)nsdataFromHexString:(NSString *)hexStr;

//十六进制转换为普通字符串
+ (NSString *)stringFromHexString:(NSString *)hexString;

//普通字符串转换为十六进制
+ (NSString *)hexStringFromString:(NSString *)string;

//HmacSHA1加密
+ (NSData *)HmacSha1:(NSString *)key data:(NSString *)data;

//获取当前时间戳
+ (NSString *)getCurrentTimeStamp;

//从字符串中获取URL
+ (NSArray*)getURLFromStr:(NSString *)string;

+ (void)storeValue:(id)object ForKey:(NSString *)key;

+ (id)getValueForKey:(NSString *)key;

@end
