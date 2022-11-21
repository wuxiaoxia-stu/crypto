//
//  NetcaEnvelopedDataEncryptInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/9/29.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaEnvelopedDataEncryptInterface : NSObject

#pragma mark - 一步完成数字信封加密
/**
 一步完成数字信封加密

 @param cert 加密证书
 @param data 原文
 @param useKeyId 为真使用主体密钥标识符，为假使用颁发者名和序列号
 @return 成功返回加密密文
 */
- (NSData *)encrypt:(NetcaCertificate *)cert data:(NSData *)data useKeyId:(BOOL)useKeyId;


#pragma mark - 多步实现数字信封加密
//加密结果为encryptInit, 多次(1..n)encryptUpdate, encryptFinal三者返回值的拼接

/**
 在数字信封里添加加密证书

 @param cert 加密证书
 @param useKeyId 为真使用主体密钥标识符，为假使用颁发者名和序列号
 @return 成功返回true
 */
- (bool)addCert:(NetcaCertificate *)cert useKeyId:(BOOL)useKeyId;


/**
 开始构造数字信封

 @return 返回部分密文
 */
- (NSData *)encryptInit;


/**
 多次输入原文，进行加密

 @param data 原文
 @return 返回部分密文
 */
- (NSData *)encryptUpdate:(NSData *)data;


/**
 结束构造数字信封

 @return 返回部分密文
 */
- (NSData *)encryptFinal;

@end
