//
//  NetcaDeviceInterface.h
//  NetcaCryptoiOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetcaType.h"
#import "NetcaError.h"

@class NetcaDevice;
@class NetcaCertificate;
@interface NetcaDeviceInterface : NSObject

/**
 刷新
 */
- (void)refresh;

/*
 设置需要刷新
 */
- (void)setNeedRefresh;

/**
 连接蓝牙设备
 */
- (BOOL)connectBluetoothDevice:(nullable NSString *)name mac:(nullable NSString *)mac;

/**
 断开蓝牙设备，飞天蓝牙(50) 文鼎创蓝牙(53) 海泰（4）
 */
- (BOOL)disconnectBluetoothDevice:(NetcaDeviceType)type;

/**
 获取设备列表
 @return 返回设备列表
 */
- (nonnull NSArray<NetcaDevice *> *)getDeviceList;

/**
 根据设备类型和序列号获取设备
 
 @param deviceType 设备类型
 @param deviceSn 设备序列号
 @return 对应设备或nil
 */
- (nullable NetcaDevice *)findDeviceBy:(int)deviceType deviceSn:(nonnull NSString *)deviceSn;

/**
 通过证书获取设备
 
 @param target 证书
 @return 对应设备或nil
 */
- (nullable NetcaDevice *)findDeviceBy:(nonnull NetcaCertificate *)target;

/**
 根据设备类型获取设备（可能有多个，比如软证书）
 
 @param deviceType 设备类型
 @return 对应设备或nil
 */
- (nullable NSArray<NetcaDevice *> *)findDeviceByType:(int)deviceType;

/**
 设置设备的配置信息（如移动key的服务器地址和id等）

 @param type 设备类型
 @param jsonStr 配置信息
 @return 错误码
 */
- (NetcaError)setDeviceConfig:(NetcaDeviceType)type jsonStr:(NSString *_Nonnull)jsonStr;

/**
 创建设备

 @param type 设备类型
 @param pwd 用户口令
 @return 错误码
*/
- (NetcaError)createDevice:(NetcaDeviceType)type pwd:(NSString *_Nonnull)pwd;

/**
 设置口令管理系统地址

 @param addr 服务器地址，如"http://127.0.0.1"
 @return 错误码
*/
- (NetcaError)setPinManagerSystemAddr:(NSString *_Nonnull)addr;

/**
产生随机数

@param len 要产生随机数的长度
@return 成功返回随机数
*/
- (NSData * _Nullable )generateRandom:(int)len;

/**
 插入云设备（未登录）

 @param signCert 员工签名证书
 @param jsonParam json字符串参数，包含云设备类型、云设备服务器信息等
 @param completion 结果回调，成功返回设备类型、序列号和证书
*/
- (void)mountCloudDevice:(NetcaCertificate *_Nonnull)signCert
               jsonParam:(NSString *_Nonnull)jsonParam
              completion:(void (^_Nonnull)(NSError *_Nullable error, NSString *_Nullable jsonResult))completion;

/**
 登录云设备
 
 @param signCert 员工签名证书
 @param completion 结果回调
*/
- (void)loginCloudDevice:(NetcaCertificate *_Nonnull)signCert
                     pin:(NSString *_Nonnull)pin
              completion:(void (^_Nonnull)(NSError *_Nullable error))completion;

/**
 插入云设备

 @param signCert 员工签名证书
 @param pin 用户密码
 @param jsonParam json字符串参数，包含云设备类型、云设备服务器信息等
 @param completion 结果回调，成功返回设备类型、序列号和证书
*/
- (void)mountCloudDevice:(NetcaCertificate *_Nonnull)signCert
                     pin:(NSString *_Nonnull)pin
               jsonParam:(NSString *_Nonnull)jsonParam
              completion:(void (^_Nonnull)(NSError *_Nullable error, NSString *_Nullable jsonResult))completion;

/**
 移除云设备

 @param jsonParam json字符串参数，包含云设备类型、序列号等
 @param completion 结果回调
*/
- (void)unMountCloudDevice:(NSString *_Nullable)jsonParam
                completion:(void (^_Nonnull)(NSError *_Nullable error))completion;

/**
 设置云设备使用的印章类型，影响获取印章的接口

 @param type 印章类型
 @return 错误码
*/
- (NetcaError)setCloudDeviceSealType:(NetcaCloudDeviceSealTyp)type;

@end
