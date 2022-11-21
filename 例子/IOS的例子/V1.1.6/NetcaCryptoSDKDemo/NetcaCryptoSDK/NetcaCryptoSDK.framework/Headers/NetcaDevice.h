//
//  NetcaDevice.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/10/23.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetcaError.h"
#import "NetcaType.h"
#import "NetcaAlgorithm.h"

NS_ASSUME_NONNULL_BEGIN

/* 设备句柄 */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;

@class NetcaKeyPair;
@class NetcaCertificate;

@interface NetcaDevice : NSObject

@property(nonatomic, copy, nullable, readonly) NSString *label;
@property(nonatomic, copy, nullable, readonly) NSString *sn;
@property(nonatomic, readonly) int type;
@property(nonatomic, strong, nullable, readonly) NSArray<NetcaKeyPair *> *keypairs;

- (nullable instancetype)init:(NETCA_PKI_DEVICE_HANDLE)handle;
- (NETCA_PKI_DEVICE_HANDLE)getDeviceHandle;

# pragma mark - Password
- (BOOL)verifyPwdOfType:(nullable NSNumber *)type pwd:(NSString *)pwd pRetryNum:(nullable int *)pRetryNum;
- (BOOL)changePwdOfType:(nullable NSNumber *)type oldpwd:(NSString *)oldPwd newPwd:(NSString *)newPwd pRetryNum:(nullable int *)pRetryNum;
- (int)pwdRetryNumberOfType:(nullable NSNumber *)type;
- (BOOL)unlockDeviceOfType:(nullable NSNumber *)type sopwd:(NSString *)sopwd newPwd:(NSString *)newPwd pRetryNum:(nullable int *)pRetryNum;

# pragma mark - Certificate
- (NSString *)generateCetificateRequest:(NetcaSignAlgorithm)signAlgo keybits:(int)keybits keypairType:(NetcaKeyPairType)keypairType subject:(NSString *)subject;
- (BOOL)verifyCetificateRequest:(NSString *)certreq;
- (BOOL)installCertificatesFrom:(int)platform signCert:(nullable NSString *)signCert encCert:(nullable NSString *)encCert encKeyPair:(nullable NSString *)encKeyPair;
- (nullable NSArray<NetcaCertificate *> *)getCerts;
- (nullable NetcaCertificate *)findCertByKeyPairLabel:(NSString *)label;
- (nullable NSString *)getKeyPairLabelBy:(NetcaCertificate *)target;

# pragma mark - PersistentData
- (BOOL)createPersistentData:(int)dataId mode:(NSString *)mode length:(int)length;
- (BOOL)deletePersistentData:(int)dataId;
- (int)getPersistentDataLength:(int)dataId;
- (BOOL)writePersistentData:(int)dataId withOffset:(int)offset dataHex:(NSString *)dataHex;
- (nullable NSData *)readPersistentData:(int)dataId withOffset:(int)offset length:(int)length;

# pragma mark - Seal
/**
 判断设备是否支持签章读写

 @return 支持返回true
 */
- (BOOL)isSupportSeal;

/**
 获取设备中的签章个数

 @return 签章个数
 */
- (int)getSealCount;

/**
 读章
 @param count 第几个，从0开始

 @return 签章图片数据
 */
- (nullable NSData *)readSeal:(int)count;

/**
 写章
 调用前需要先验证PIN码
 @param sealName 签章名称
 @param picture 签章图片数据

 @return 成功返回true
 */
- (BOOL)writeSeal:(NSString *)sealName picture:(NSData *)picture;

/**
 根据ID删除签章
 调用前需要先验证PIN码
 @param sealId 签章ID

 @return 成功返回true
 */
- (BOOL)deleteSealById:(int)sealId;

/**
 根据名称删除签章
 调用前需要先验证PIN码
 @param sealName 签章名称

 @return 成功返回true
*/
- (BOOL)deleteSealByName:(NSString *)sealName;

/**
 删除签章
 调用前需要先验证PIN码
 @param count 第几个，从0开始

 @return 成功返回true
 */
- (BOOL)deleteSeal:(int)count;

/**
 删除全部签章
 调用前需要先验证PIN码

 @return 成功返回true
 */
- (BOOL)deleteAllSeal;

# pragma mark - 证书生命周期

/**
 产生证书请求

 @param pwd PIN码
 @param dn 证书DN
 @param algo 算法
 @param keyBits 密钥位数
 @param keyType 密钥对类型

 @return 成功返回Base64编码的证书请求，失败返回nil，错误码通过NetcaPKIGetLastError()获取
 */
- (NSString *)genP10:(NSString *)pwd
                  dn:(NSString *)dn
                algo:(NetcaSignAlgorithm)algo
             keyBits:(int)keyBits
             keyType:(NetcaKeyPairType)keyType;

/**
 安装证书

 @param pwd PIN码
 @param platform 平台
 @param signCert 签名证书的Base64编码
 @param encCert 加密证书的Base64编码
 @param encKeyPair 加密的加密密钥对的Base64编码

 @return 成功返回true
 */
- (BOOL)installCert:(NSString *)pwd
           platform:(int)platform
           signCert:(nullable NSString *)signCert
            encCert:(nullable NSString *)encCert
         encKeyPair:(nullable NSString *)encKeyPair;


# pragma mark - 错误码
/**
 获取设备上一次的错误码

 @return 错误码
*/
- (int)getDeviceLastErrorCode:(int)errcode;

# pragma mark - 删除证书
/**
 删除证书

 @param pin 用户密码
 @param cert 证书
 @return 成功返回true
*/
- (BOOL)deleteCert:(NSString *)pin cert:(NetcaCertificate *)cert;

/**
 删除密钥对

 @param pin 用户密码
 @param label 密钥对label
 @return 成功返回true
*/
- (BOOL)deleteKeypair:(NSString *)pin label:(NSString *)label;

@end

NS_ASSUME_NONNULL_END
