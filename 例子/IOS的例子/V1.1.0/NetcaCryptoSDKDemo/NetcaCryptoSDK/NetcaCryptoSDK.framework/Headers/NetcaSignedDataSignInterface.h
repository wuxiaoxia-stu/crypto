//
//  NetcaSignedDataSignInterface.h
//  NetcaCryptoiOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NetcaCertificate;
@interface NetcaSignedDataSignInterface : NSObject

@property(nonatomic, strong) NetcaCertificate *signCert;
@property(nonatomic, getter=isDetached) BOOL detach;
@property(nonatomic) int signAlgo;
@property(nonatomic) int includeCertOption;

/**
 添加CRL
 
 @param crl crl数据
 @return 成功返回YES
 */
- (BOOL)addCrl:(NSData *)crl;

/**
 添加OCSP
 
 @param ocsp ocsp数据
 @param cert ocsp证书，可以为nil
 @return 成功返回YES
 */
- (BOOL)addOCSP:(NSData *)ocsp cert:(nullable NetcaCertificate *)cert;


#pragma mark - 一步完成签名
/**
 一步完成SignedData签名，用于签名原文比较小时
 不带时间戳

 @param pwd 密码
 @param data 签名原文
 @return 返回签名值
 */
- (nullable NSData *)sign:(NSString *)pwd data:(NSData *)data;

/**
 一步完成SignedData签名，用于签名原文比较小时
 带时间戳
 
 @param pwd 密码
 @param data 签名原文
 @param tsaurl 时间戳地址
 @return 返回签名值
 */
- (nullable NSData *)sign:(NSString *)pwd data:(NSData *)data tsaUrl:(nullable NSString *)tsaurl;

#pragma mark - 多步进行签名
//签名结果为signInit, 多次(1..n)signUpdate, signFinal三者返回值的拼接

/**
 多步签名的初始化

 @param pwd 密码
 @return 返回部分签名值
 */
- (nullable NSData *)signInit:(NSString *)pwd;

- (nullable NSData *)pdfSignInit:(NSString *)pwd crlDatas:(NSArray<NSData *> *)crlDatas ocspDatas:(NSArray <NSData *> *)ocspDatas;

/**
 多次输入原文进行签名

 @param data 签名原文
 @return 返回部分签名值
 */
- (nullable NSData *)signUpdate:(NSData *)data;


/**
 结束多步签名

 @return 返回部分签名值
 */
- (nullable NSData *)signFinal;

/**
 结束多步签名，带时间戳
 
 @return 返回部分签名值
 */
- (nullable NSData *)signFinalWithTsaUrl:(NSString *)tsaurl;

@end

NS_ASSUME_NONNULL_END
