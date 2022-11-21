//
//  NetcaCertificate.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/10/24.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/* 证书句柄 */
struct NETCA_CERT_st;
typedef struct NETCA_CERT_st* NETCA_PKI_CERTIFICATE_HANDLE;

@interface NetcaCertificate : NSObject

#pragma mark - Properties
/* 证书DER编码 */
@property(nonatomic, strong, readonly) NSData *derEncode;
/* 证书版本号 */
@property(nonatomic, readonly, assign) NSInteger version;
/* 签名算法 */
@property(nonatomic, readonly, assign) NSInteger signAlgo;
/* 公钥算法 */
@property(nonatomic, readonly, assign) NSInteger pubKeyAlgo;
/* 密钥对位数 */
@property(nonatomic, readonly, assign) NSInteger pubKeyBits;
/* 证书用途 */
@property(nonatomic, readonly, assign) NSInteger keyusage;
/* 序列号 */
@property(nonatomic, copy, readonly) NSString *sn;
/* 是否在有效期内 */
@property(nonatomic, getter=isValid, readonly) BOOL valid;
/* 颁发者信息 */
@property(nonatomic, copy, readonly) NSString *issuer;
@property(nonatomic, copy, nullable, readonly) NSString *issuerC;
@property(nonatomic, copy, nullable, readonly) NSString *issuerO;
@property(nonatomic, copy, nullable, readonly) NSString *issuerOU;
@property(nonatomic, copy, nullable, readonly) NSString *issuerCN;
@property(nonatomic, copy, nullable, readonly) NSString *issuerST;
@property(nonatomic, copy, nullable, readonly) NSString *issuerL;
@property(nonatomic, copy, nullable, readonly) NSString *issuerEmail;
/* 证书使用者 */
@property(nonatomic, copy, readonly) NSString *subject;
@property(nonatomic, copy, readonly) NSString *subjectDisplayName;
@property(nonatomic, copy, nullable, readonly) NSString *subjectC;
@property(nonatomic, copy, nullable, readonly) NSString *subjectST;
@property(nonatomic, copy, nullable, readonly) NSString *subjectO;
@property(nonatomic, copy, nullable, readonly) NSString *subjectL;
@property(nonatomic, copy, nullable, readonly) NSString *subjectOU;
@property(nonatomic, copy, nullable, readonly) NSString *subjectCN;
@property(nonatomic, copy, nullable, readonly) NSString *subjectEmail;
/* 有效期 */
@property(nonatomic, copy, readonly) NSString *validityStart;
@property(nonatomic, copy, readonly) NSString *validityEnd;
/* 证书姆印 */
@property(nonatomic, copy, nullable, readonly) NSString *thumbprintMD5;
@property(nonatomic, copy, nullable, readonly) NSString *thumbprintSHA1;
@property(nonatomic, copy, nullable, readonly) NSString *thumbprintSHA256;
@property(nonatomic, copy, nullable, readonly) NSString *thumbprintSHA512;
/* CRL URLs */
@property(nonatomic, strong, nullable, readonly) NSArray<NSString *> *crlURLs;
/* OCSP URLs */
@property(nonatomic, strong, nullable, readonly) NSArray<NSString *> *ocspURLs;

#pragma mark - Methods
/**
 初始化方法
 */
- (instancetype)init:(void *)handle;
- (instancetype)initWithDer:(NSData *)der;
/**
 获取证书句柄
 */
- (NETCA_PKI_CERTIFICATE_HANDLE)getCertHandle;
/**
 将中间件提取的时间数据转换成用户易读的格式
 
 @return 证书的有效期时间的易读格式,如: 2017-01-01 - 2018-01-01
 */
- (nullable NSString *)simpleValidity;
/**
 获取证书对应的证书链

 @return 证书链
 */
- (nullable NSArray<NetcaCertificate *> *)buildCertPath;
/**
 判断是否是SM2证书
 
 @return 是返回true
 */
- (bool)isSM2;
/**
 判断是否是签名证书
 
 @return 是返回true
 */
- (bool)isSignCert;
/**
 判断是否是加密证书

 @return 是返回true
 */
- (bool)isEncCert;
@end

NS_ASSUME_NONNULL_END
