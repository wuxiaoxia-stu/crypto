//
//  NetcaCertInterface.h
//  NetcaCryptoiOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetcaType.h"

NS_ASSUME_NONNULL_BEGIN

@class NetcaCertificate;
@interface NetcaCertInterface : NSObject

/**
 获取所有设备的证书

 @return 证书列表
 */
- (NSArray<NetcaCertificate *> *)getAllCertsFromDevice;


/**
 获取有效期内的签名证书列表

 @return 签名证书列表
 */
- (NSArray<NetcaCertificate *> *)getSignCertList;


/**
 获取有效期内的加密证书列表

 @return 加密证书列表
 */
- (NSArray<NetcaCertificate *> *)getEncCertList;


/**
 根据查询条件查询证书
 
 @param type 证书类型
 @param expr 过滤条件表达式
 @return 证书列表
 */
- (nullable NetcaCertificate *)selectCert:(NSString *)type expr:(nullable NSString *)expr;


/**
 根据外来证书获取设备中的证书
 
 @param target 证书
 @return 对应设备或nil
 */
- (nullable NetcaCertificate *)findCertBy:(nonnull NetcaCertificate *)target;

#pragma mark - 验证证书链
/**
 验证证书

 @param cert 证书对象
 @param flag 验证标志。当flag=0时，只验证证书链
 @return 验证通过返回成功，其他返回失败
 */
- (BOOL)verifyCert:(NetcaCertificate *)cert flag:(NetcaCertStatusFlag)flag;


#pragma mark - 验证证书吊销信息
/**
 通过OCSP验证证书的作废状态

 @param cert 证书对象
 @param ocspData ocspData数据
 @return 证书未吊销返回成功，其他返回失败
 */
- (BOOL)verifyCertByOcsp:(NetcaCertificate *)cert ocspData:(nonnull NSData *)ocspData;


/**
 通过CRL验证证书的作废状态

 @param cert 证书对象
 @param crlData crl数据
 @return 证书未吊销返回成功，其他返回失败
 */
- (BOOL)verifyCertByCrl:(NetcaCertificate *)cert crlData:(nonnull NSData *)crlData;


#pragma mark - 获取证书吊销信息
/**
 获取CRL数据

 @param url CRL地址
 @param statusCode 错误码
 @return CRL数据
 */
- (nullable NSData *)getCRLDataFrom:(NSString *)url statusCode:(int *)statusCode;

/**
 获取OCSP数据
 
 @param cert 证书
 @param url OCSP地址
 @return OCSP响应数据
 */
- (nullable NSData *)getOCSPDataOf:(nonnull NetcaCertificate *)cert fromUrl:(nonnull NSString *)url;

/**
 OPENSSL获取OCSP数据
 
 @param cert 证书
 @param urlStr OCSP地址
 @param completion 下载完成后的操作
 */
- (void)openssl_OCSPRequest:(nonnull NetcaCertificate *)cert
            fromURL:(nonnull NSString *)urlStr
     completedBlock:(void (^)(NSData *respData))completion;


#pragma mark - 安全环境
/**
 注册证书到安全环境
 
 @param cert 证书
 */
- (BOOL)registerCertToTrust:(nonnull NetcaCertificate *)cert;

/**
 注册中级CA证书到安全环境
 
 @param cert 证书
 */
- (BOOL)addCaCertToTrust:(nonnull NetcaCertificate *)cert;

/**
 注册根证书到安全环境
 
 @param cert 证书
 */
- (BOOL)addRootCertToTrust:(nonnull NetcaCertificate *)cert;

@end

NS_ASSUME_NONNULL_END
