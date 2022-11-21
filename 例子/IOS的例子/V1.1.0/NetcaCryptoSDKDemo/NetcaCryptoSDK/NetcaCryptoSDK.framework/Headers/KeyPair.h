//
//  KeyPair.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/1.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NETCA_PKI_Type.h"

@class NetcaCertificate;
@interface KeyPair : NSObject

@property (nonatomic, copy, nullable, readonly) NSString *label;
@property (nonatomic, readonly) int type;
@property (nonatomic, readonly) int algo;
@property (nonatomic, readonly) int curve;

- (nullable instancetype)initWithHandle:(nonnull NETCA_PKI_KEYPAIR_HANDLE)handle;
- (nullable NETCA_PKI_KEYPAIR_HANDLE)getHandle;

#pragma mark - PrivateKeyDecryptObject
+ (int)getSuitableDecryptAlgo:(nonnull NetcaCertificate *)cert;

@end
