//
//  NetcaMobileKeyInterface.h
//  NetcaCryptoSDK
//
//  Created by cow on 2020/6/5.
//  Copyright © 2020 cow. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NetcaType.h"
#import "NetcaError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol NetcaMobileKeyDelegate <NSObject>

@optional
/* 连接成功的回调 */
- (void)netcaMobileKeyDidConnectPC;
/* 连接失败的回调 */
- (void)netcaMobileKeyDidFailToConnectPC:(nonnull NSError *)error;
/* 连接断开的回调，用户在PC或手机端主动断开时error为nil，网络中断 */
- (void)netcaMobileKeyDidDisconnectPC:(nullable NSError *)error;

@end




@interface NetcaMobileKeyInterface : NSObject
@property (nonatomic, weak, nullable)id<NetcaMobileKeyDelegate> delegate;

/**
 设置是否需要密码缓存
 
 @param type 样式，参考 NetcaPINCacheType
 */
- (void)setNeedPINCache:(NetcaPINCacheType)type;

/**
 设置密码输入框的样式
 
 @param type 样式，参考 NetcaPINUIType
*/
- (void)setPINUIType:(NetcaPINUIType)type;

/**
 调起移动电子密钥的UI

 @param qrcode PC端的二维码内容
 @param sourceVC 调起 UI 界面的 ViewController
 @param mode 调起UI的模式，参考 NetcaVCDisplayMode
 @param parameter 保留参数
 @return 错误码
 */
- (NetcaError)connectToPC:(NSString *_Nonnull)qrcode
                 sourceVC:(UIViewController *_Nullable)sourceVC
              displayMode:(NetcaVCDisplayMode)mode
                parameter:(NSString *_Nullable)parameter;


@end

NS_ASSUME_NONNULL_END
