//
//  NetcaMKeyDevice.h
//  NetcaMKeyClient
//
//  Created by NetcaDeveloper on 2019/8/5.
//  Copyright © 2019年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ECCPublicKey;
@class ECCPrivateKey;
@interface NetcaMKeyDevice : NSObject

+ (nonnull instancetype)sharedInstance;

/**
 获取移动Key设备句柄

 @return 设备句柄
 */
- (int)getDeviceHandle;

/**
 获取上一次失败错误码

 @return 最后一次错误码
 */
- (int)getLastErrorCode;

/**
 初始化设备

 @param url 服务器地址
 @param appId 应用id
 @param userPin 用户口令
 @return 成功返回NETCA_RESULT_SUCCESS
 */
- (int)initDeviceWith:(NSString *)url appId:(NSString *)appId userPin:(NSString *)userPin;

/**
 安装key

 @param userPin 用户口令
 @return 成功返回NETCA_RESULT_SUCCESS，已安装返回NETCA_RESULT_KEYPAIR_EXIST
 */
- (int)installKey:(NSString *)userPin;

/**
 校验用户口令

 @param pin 用户口令
 @param retryCount 若口令错误，返回重试次数
 @return 成功返回NETCA_RESULT_SUCCESS
 */
- (int)verifyUserPin:(NSString *)pin retryCount:(int *)retryCount;

/**
 修改用户口令

 @param oldPin 旧的用户口令
 @param newPin 新的用户口令
 @param retryCount 若口令错误，返回重试次数
 @return 成功返回NETCA_RESULT_SUCCESS
 */
- (int)changeUserPin:(NSString *)oldPin newPin:(NSString *)newPin retryCount:(int *)retryCount;

/**
 获取密钥对列表

 @param type 0表示签名密钥对，1表示加密密钥对
 @return 所有符合条件的密钥对ID（跟容器名一样）
 */
- (NSArray<NSString *> *)getKeyPairList:(int)type;

/**
 判断设备是否已经初始化

 @return 已初始化返回true，否则返回false
 */
- (BOOL)hasDeviceInit;



#pragma mark - 国密检测
// 生成ECC签名密钥对
- (int)GenECCKeyPair:(NSString *)pin
               algId:(int)algId
           publicKey:(ECCPublicKey **)publicKey
          privateKey:(ECCPrivateKey **)privateKey;

// ECC外来私钥解密
- (int)ExtECCDecrypt:(NSString *)pin
       eccPrivateKey:(ECCPrivateKey *)eccPrivateKey
              cipher:(NSData *)cipher
               plain:(NSData **)plain;

// ECC外来私钥签名
- (int)ExtECCSign:(NSString *)pin
    eccPrivateKey:(ECCPrivateKey *)eccPrivateKey
             data:(NSData *)data
        signature:(NSData **)signature;

// 自检测
- (int)SelfTest;

// 签名值der转r+s
- (NSData *)DecodeEccSignature:(NSData *)signature;



#pragma mark - 粤商通项目定制接口

/**
 产生管理员密钥

 @param pin 旧的用户口令
 @param publicKeyData 公钥数据，前32个字节是x，后32个字节是y
 @param soPinCipher 返回管理员密钥的密文
 @return 成功返回NETCA_RESULT_SUCCESS
 */
- (int)genEncryptedSoPin:(NSString *)pin
           publicKeyData:(NSData *)publicKeyData
             soPinCipher:(NSData **)soPinCipher;

/**
 重置用户口令

 @param soPin 管理员密钥
 @param newPin 新的用户口令
 @return 成功返回NETCA_RESULT_SUCCESS
*/
- (int)resetUserPin:(NSData *)soPin newPin:(NSString *)newPin;

@end

NS_ASSUME_NONNULL_END
