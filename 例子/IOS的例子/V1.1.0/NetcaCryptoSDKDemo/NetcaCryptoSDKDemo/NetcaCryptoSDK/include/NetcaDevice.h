//
//  NetcaDevice.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/10/23.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/* 设备句柄 */
struct NETCA_PKI_DEVICE_HANLDE_st;
typedef struct NETCA_PKI_DEVICE_HANDLE_st* NETCA_PKI_DEVICE_HANDLE;

@class KeyPair;
@class NetcaCertificate;

@interface NetcaDevice : NSObject

@property(nonatomic, copy, nullable, readonly) NSString *label;
@property(nonatomic, copy, nullable, readonly) NSString *sn;
@property(nonatomic, readonly) int type;
@property(nonatomic, strong, nullable, readonly) NSArray<KeyPair *> *keypairs;

- (nullable instancetype)init:(NETCA_PKI_DEVICE_HANDLE)handle;
- (NETCA_PKI_DEVICE_HANDLE)getDeviceHandle;

# pragma mark - Password
- (BOOL)verifyPwdOfType:(nullable NSNumber *)type pwd:(NSString *)pwd pRetryNum:(nullable int *)pRetryNum;
- (BOOL)changePwdOfType:(nullable NSNumber *)type oldpwd:(NSString *)oldPwd newPwd:(NSString *)newPwd pRetryNum:(nullable int *)pRetryNum;
- (int)pwdRetryNumberOfType:(nullable NSNumber *)type;
- (BOOL)unlockDeviceOfType:(nullable NSNumber *)type sopwd:(NSString *)sopwd newPwd:(NSString *)newPwd pRetryNum:(nullable int *)pRetryNum;

# pragma mark - Certificate
- (BOOL)installCertificatesFrom:(int)platform signCert:(nullable NSString *)signCert encCert:(nullable NSString *)encCert encKeyPair:(nullable NSString *)encKeyPair;
- (nullable NSArray<NetcaCertificate *> *)getCerts;
- (nullable NetcaCertificate *)findCertByKeyPairLabel:(NSString *)label;

# pragma mark - PersistentData
- (BOOL)createPersistentData:(int)dataId mode:(NSString *)mode length:(int)length;
- (BOOL)deletePersistentData:(int)dataId;
- (int)getPersistentDataLength:(int)dataId;
- (BOOL)writePersistentData:(int)dataId withOffset:(int)offset dataHex:(NSString *)dataHex;
- (nullable NSData *)readPersistentData:(int)dataId withOffset:(int)offset length:(int)length;

@end

NS_ASSUME_NONNULL_END
