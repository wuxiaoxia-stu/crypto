//
//  NetcaQrCodeSignInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/11/3.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@interface NetcaQrCodeSignInterface : NSObject

@property (nonatomic, copy) NSString *errorMessage;

/**
 * 初始化
 *
 * @param qrCodeContent  二维码内容
 *
 */
- (void)setQrCodeContent:(NSString *)qrCodeContent;

/**
 * 判断是否需要验证码
 *
 *
 * @return true需要，false不需要
 */

- (bool)isNeedAuthCode;

/**
 * 获取签名内容。根据二维码内容获取要签名的数据
 *
 * @param authCode  验证码
 *
 * @return 成功返回签名内容
 */
- (NSString *)querySignData:(NSString *)authCode;

/**
 * 二维码签名。签名并提交签名值，返回后台验证结果。
 *
 * @param pin  电子密钥PIN码
 *
 * @return 错误码
 */
- (long long)qrcodeSign:(NetcaCertificate *)cert pin:(NSString *)pin;

@end
