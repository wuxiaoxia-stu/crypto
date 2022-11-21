//
//  NetcaDecryptInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 2018/10/31.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaDecryptInterface : NSObject

@property(nonatomic, strong) NetcaCertificate *encCert;

/**
 私钥解密
 
 @param cipherData 密文
 @param algo 加密算法
 @param isDecryptKey 是否用于解密数字信封的对称密钥
 @return 明文，如果是大文件数字信封解密，则结果为对称密钥
 */
- (nullable NSData *)privateKeyDecrypt:(nonnull NSData *)cipherData
                                   pwd:(nonnull NSString *)pwd
                      usingDecryptAlgo:(int)algo
                          isDecryptKey:(bool)isDecryptKey;

@end
