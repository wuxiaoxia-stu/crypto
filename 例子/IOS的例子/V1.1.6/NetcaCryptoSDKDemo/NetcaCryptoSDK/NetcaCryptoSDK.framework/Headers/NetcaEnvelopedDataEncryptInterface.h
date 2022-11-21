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

@property(nonatomic) BOOL useKeyId;//为真使用主体密钥标识符，为假使用颁发者名和序列号

#pragma mark - 一步完成数字信封加密
/**
 一步完成数字信封加密

 @param data 原文
 @param certs 加密证书列表
 @return 成功返回加密密文
 */
- (NSData *)encrypt:(NSData *)data certs:(NSArray<NetcaCertificate *> *)certs;


#pragma mark - 多步实现数字信封加密
//加密结果为encryptInit, 多次(1..n)encryptUpdate, encryptFinal三者返回值的拼接

/**
 开始构造数字信封

 @param certs 加密证书列表
 @return 返回部分密文
 */
- (NSData *)encryptInit:(NSArray<NetcaCertificate *> *)certs;


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
