//
//  NetcaEncryptInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 2018/10/31.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaEncryptInterface : NSObject

/**
 公钥加密
 
 @param data 原文
 @param cert 加密证书
 @return 密文
 */
- (NSData *)encrypt:(NSData *)data usingCert:(NetcaCertificate *)cert;

@end
