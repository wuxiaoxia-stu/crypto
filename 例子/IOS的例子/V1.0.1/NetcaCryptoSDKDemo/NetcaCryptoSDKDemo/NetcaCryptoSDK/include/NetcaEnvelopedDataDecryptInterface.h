//
//  NetcaEnvelopedDataDecryptInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/9/29.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaEnvelopedDataDecryptInterface : NSObject

/**
 设置解密证书

 @param cert 证书
 @return 成功返回true
 */
- (bool)setDecryptCertificate:(NetcaCertificate *)cert;


#pragma mark - 一步完成数字信封解密
/**
 一步完成数字信封解密

 @param pwd 密码
 @param data 数字信封编码
 @return 输出明文
 */
- (NSData *)decrypt:(NSString *)pwd data:(NSData *)data;


/**
 获取解密证书

 @return 返回解密证书
 */
- (NetcaCertificate *)getDecryptCert;


#pragma mark - 多步完成数字信封解密
/**
 开始多步解开数字信封

 @param pwd 密码
 @return 成功返回true
 */
- (bool)decryptInit:(NSString *)pwd;


/**
 多次输入数字信封编码，解开数字信封

 @param data 数字信封编码
 @return 返回明文
 */
- (NSData *)decryptUpdate:(NSData *)data;


/**
 结束多步解开数字信封

 @return 成功返回true
 */
- (bool)decryptFinal;

/**
 解密RecipientInfo获取对称密钥
 
 @return 成功返回对称密钥
 */
- (NSData *)decodeKeyOfRecipientInfo:(NSData *)recipientInfo usingPwd:(NSString *)pwd;

@end
