//
//  NetcaCryptoPINManager.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/27.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaDevice;

@interface NetcaCryptoPINManager : NSObject

@property (nonatomic, getter=isCachePIN, readonly) BOOL cachePIN;
@property (nonatomic) int cachePINSecond;

+ (instancetype)sharedInstance;

/*
 针对其他iOS应用的密码缓存
 不可在主线程上调用
 */
- (NSString *)getPasswordAndVerify:(NetcaDevice *)device;
/*
 针对移动电子密钥的单独进程的PIN码缓存
 不可在主线程上调用
 */
- (NSString *)getPasswordAndVerify:(NetcaDevice *)device forProcessID:(NSString *)pid;

/*
 修改PIN码
 */
- (void)modifyPasswordOfDevice:(NetcaDevice *)device
                    revHandler:(void(^)(NSInteger errcode, NSInteger retryNumber))revHandler;

/*
 弹框输入初始化设备的PIN码
 */
- (NSString *)getPasswordOfNewDevice:(NetcaDevice *)device;

@end
