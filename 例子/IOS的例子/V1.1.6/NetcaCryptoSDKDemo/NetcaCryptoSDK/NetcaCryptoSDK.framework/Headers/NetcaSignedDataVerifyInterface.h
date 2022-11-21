//
//  NetcaSignedDataVerifyInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/9/29.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaSignedDataVerifyInterface : NSObject

#pragma mark - 一步验证带原文的SignedData签名
/**
 一步验证带原文的签名
 
 @param signature 签名值
 @return 验证成功返回true，失败返回false
 */
- (bool)verify:(NSData *)signature;



#pragma mark - 一步验证不带原文的SignedData签名
/**
 一步验证不带原文的签名

 @param data 签名原文
 @param signature 签名值
 @return 验证成功返回true，失败返回false
 */
- (bool)verify:(NSData *)data signature:(NSData *)signature;



/**
 获取签名证书

 @return 返回签名证书
 */
- (NetcaCertificate *)getSignCert;



#pragma mark - 多步验证带原文的SignedData签名
/**
 初始化带原文的签名验证

 @return 成功返回true
 */
- (bool)verifyInit;


/**
 多次输入SignedData的编码值进行带原文的签名验证

 @param signature 签名值
 @return 返回签名原文
 */
- (NSData *)verifyUpdate:(NSData *)signature;


/**
 结束带原文的签名验证

 @return 成功返回true
 */
- (bool)verifyFinal;



#pragma mark - 多步验证不带原文的SignedData签名
/**
 初始化不带原文的签名验证

 @param signature 签名值
 @return 成功返回true
 */
- (bool)detachedVerifyInit:(NSData *)signature;


/**
 多次输入不带原文的签名对应的原文
 
 @param data 签名原文
 @return 成功返回true
 */
- (bool)detachedVerifyUpdate:(NSData *)data;


/**
 结束不带原文的签名验证
 
 @return 成功返回true
 */
- (bool)detachedVerifyFinal;

@end
