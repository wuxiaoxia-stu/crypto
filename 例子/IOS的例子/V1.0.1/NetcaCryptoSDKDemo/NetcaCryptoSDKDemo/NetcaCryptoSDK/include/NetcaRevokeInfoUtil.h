//
//  NetcaRevokeInfoUtil.h
//  NetcaKeyXSDKTest
//
//  Created by cow on 2018/8/14.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaRevokeInfoUtil : NSObject

/**
 根据证书获取颁发者证书的OCSP地址

 @param cert 证书
 @return 颁发者证书的OCSP地址
 */
+ (nullable NSString *)getIssuerOCSPUrl:(NetcaCertificate *)cert;

/**
 根据证书获取根证书的CRL地址

 @param cert 证书
 @return 根证书的CRL地址
 */
+ (nullable NSString *)getRootCRLUrl:(NetcaCertificate *)cert;

@end
