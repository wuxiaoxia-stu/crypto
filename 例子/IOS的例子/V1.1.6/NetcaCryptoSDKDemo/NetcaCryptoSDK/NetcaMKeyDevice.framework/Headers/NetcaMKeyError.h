//
//  NetcaMKeyError.h
//  NetcaMKeyDevice
//
//  Created by NetcaDeveloper on 2019/9/5.
//  Copyright © 2019年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetcaMobileCryptoModuleConst.h"

//不支持该操作
#define NETCA_RESULT_UNSUPPORT 0x2000000
//二维码内容有误
#define NETCA_RESULT_QRCODE_ERROR 0x2000001
//PIN码长度不能少于6位
#define NETCA_RESULT_PIN_LENGTH_ERROR 0x2000002
//缓存PIN为空，需要先校验PIN
#define NETCA_RESULT_VERIFY_PIN_FIRST 0x2000003
//openurl失败
#define NETCA_RESULT_OPEN_URL_FAIL 0x2000004

@interface NetcaMKeyError : NSObject

+ (NSString *)getErrorMsg:(int)errorCode;

@end
