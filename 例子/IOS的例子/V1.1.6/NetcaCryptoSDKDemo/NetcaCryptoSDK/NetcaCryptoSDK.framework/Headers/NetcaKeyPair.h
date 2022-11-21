//
//  NetcaKeyPair.h
//  NetcaCryptoSDK
//
//  Created by cow on 2020/9/3.
//  Copyright © 2020 cow. All rights reserved.
//

#import <Foundation/Foundation.h>

/* 密钥对句柄 */
struct NETCA_PrivKey_Handle_st;
typedef struct NETCA_PrivKey_Handle_st * NETCA_PKI_KEYPAIR_HANDLE;

@class NetcaCertificate;
@interface NetcaKeyPair : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *label;
@property (nonatomic, readonly) int type;
@property (nonatomic, readonly) int algo;
@property (nonatomic, readonly) int curve;

- (nullable instancetype)initWithHandle:(nonnull NETCA_PKI_KEYPAIR_HANDLE)handle;
- (nullable NETCA_PKI_KEYPAIR_HANDLE)getHandle;

#pragma mark - PrivateKeyDecryptObject
+ (int)getSuitableDecryptAlgo:(nonnull NetcaCertificate *)cert;

@end
