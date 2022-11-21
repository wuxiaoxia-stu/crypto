//
//  NetcaPinManageSystemInterface.h
//  NetcaCryptoSDK
//
//  Created by cow on 2020/5/13.
//  Copyright © 2020 cow. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NetcaDevice;
@interface NetcaPinManageSystemInterface : NSObject

@property(nonatomic, strong) NetcaDevice *device;

/**
 注册管理员密钥

 @param userPin 用户口令
 @param completion 结果回调
*/
- (void)registerSoPin:(nullable NSString *)phoneNum
              userPin:(nonnull NSString *)userPin
           completion:(void (^_Nonnull)(NSError *_Nullable error))completion;


/**
 请求获取管理员密钥

 @param completion 结果回调
*/
- (void)requestGetSoPin:(void (^_Nonnull)(NSError *_Nullable error, NSString *_Nullable dataToSign))completion;


/**
 重置用户口令

 @param newUserPin 新的用户口令
 @param signature 签名值
 @param completion 结果回调
*/
- (void)unlockUserPin:(nonnull NSString *)newUserPin
            signature:(nonnull NSString *)signature
           completion:(void (^_Nonnull)(NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
