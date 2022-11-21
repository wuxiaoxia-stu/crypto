//
//  NetcaDeviceInterface.h
//  NetcaCryptoiOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

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
 断开蓝牙设备，飞天蓝牙(50) 文鼎创蓝牙(53)
 */
- (BOOL)disconnectBluetoothDevice:(int)type;

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

@end
