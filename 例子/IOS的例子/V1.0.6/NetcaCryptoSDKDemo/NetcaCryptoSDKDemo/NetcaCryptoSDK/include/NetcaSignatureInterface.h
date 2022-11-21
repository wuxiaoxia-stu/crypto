//
//  NetcaSignatureInterface.h
//  NetcaCryptoiOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NetcaCertificate;
@interface NetcaSignatureInterface : NSObject

@property(nonatomic, strong) NetcaCertificate *signCert;
@property(nonatomic) int signAlgo;

#pragma mark - 一步完成签名
/**
 一步完成签名，用于签名原文比较小时
 
 @param pwd 密码
 @param data 签名原文
 @return 签名值
 */
- (nullable NSData *)sign:(NSString *)pwd data:(NSData *)data;

/**
 一步完成hash签名，用于对hash进行签名
 
 @param pwd 密码
 @param hash 需要签名的hash值
 @return 签名值
 */
- (nullable NSData *)signHash:(NSString *)pwd hash:(NSData *)hash;

#pragma mark - 多步进行签名

/**
 多步签名的初始化

 @param pwd 密码
 */
- (BOOL)signInit:(NSString *)pwd;


/**
 多次输入原文进行签名

 @param data 签名原文
 */
- (BOOL)signUpdate:(NSData *)data;


/**
 结束多步签名

 @return 返回签名值
 */
- (nullable NSData *)signFinal;

@end

NS_ASSUME_NONNULL_END
