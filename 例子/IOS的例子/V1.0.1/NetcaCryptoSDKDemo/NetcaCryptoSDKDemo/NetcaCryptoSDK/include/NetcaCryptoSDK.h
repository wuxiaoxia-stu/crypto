//
//  NetcaCryptoSDK.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/9/28.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetcaDevice.h"
#import "NetcaCertificate.h"
#import "NetcaDeviceInterface.h"
#import "NetcaCertInterface.h"
#import "NetcaSignatureInterface.h"
#import "NetcaSignatureVerifyInterface.h"
#import "NetcaSignedDataSignInterface.h"
#import "NetcaSignedDataVerifyInterface.h"
#import "NetcaEnvelopedDataEncryptInterface.h"
#import "NetcaEnvelopedDataDecryptInterface.h"
#import "NetcaPDFSignInterface.h"
#import "NetcaCipherInterface.h"
#import "NetcaHashInterface.h"
#import "NetcaQrCodeSignInterface.h"
#import "NetcaBluetoothManager.h"
#import "NetcaBluetoothDevice.h"
#import "NetcaSelfServiceViewController.h"
#import "NetcaQRCodeScannerController.h"
#import "NetcaPDFArea.h"
#import "NetcaRevokeInfoUtil.h"
#import "NetcaError.h"
#import "NetcaType.h"
#import "NetcaAlgorithm.h"
#import "NetcaDecryptInterface.h"
#import "NetcaEncryptInterface.h"

@interface NetcaCryptoSDK : NSObject

/**
 单例

 @return 返回NetcaCryptoSDK实例
 */
+ (nonnull instancetype)sharedInstance;

/**
 获取错误码

 @return 返回最后的错误码
 */
+ (int)getLastErrorCode;

/**
 获取设备接口实例
 
 @return 返回设备接口实例
 */
- (NetcaDeviceInterface *)getDeviceInterface;

/**
 获取证书接口实例
 
 @return 返回证书接口实例
 */
- (NetcaCertInterface *)getCertInterface;

@end
