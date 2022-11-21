//
//  NetcaSignatureVerifyInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/10/27.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaSignatureVerifyInterface : NSObject

/**
 设置签名证书

 @param cert 签名证书
 @return 成功返回true
 */
- (bool)setSignCertificate:(NetcaCertificate *)cert;


/**
 设置签名算法

 @param algo 签名算法
 @return 成功返回true
 */
- (bool)setSignAlgorithm:(int)algo;


#pragma mark - 一步验证签名
/**
 一步验证签名

 @param data 签名原文
 @param signature 签名值
 @return 验证成功返回true，失败返回false
 */
- (bool)verify:(NSData *)data signature:(NSData *)signature;

/**
 一步验证hash签名
 
 @param hash 要签名的hash
 @param signature 签名值
 @return 验证成功返回true，失败返回false
 */
- (bool)verifyHash:(NSData *)hash signature:(NSData *)signature;

#pragma mark - 多步验证签名

/**
 初始化多步签名验证

 @return 成功返回true
 */
- (bool)verifyInit;


/**
 多次输入签名原文进行hash运算

 @param data 签名原文
 @return 成功返回true
 */
- (bool)verifyUpdate:(NSData *)data;


/**
 结束多步签名验证

 @param signature 签名值
 @return 成功返回true
 */
- (bool)verifyFinal:(NSData *)signature;

@end
