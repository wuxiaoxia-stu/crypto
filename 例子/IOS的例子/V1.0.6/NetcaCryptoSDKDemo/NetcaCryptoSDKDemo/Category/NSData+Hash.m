//
//  NSData+Hash.m
//  NetcaKeyXSDKTest
//
//  Created by cow on 2018/4/10.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import "NSData+Hash.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSData (Hash)

- (NSData *)sha256 {
    uint8_t digest[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256(self.bytes, self.length, digest);
    NSData *dataSha256 = [[NSData alloc]initWithBytes:digest length:CC_SHA256_DIGEST_LENGTH];
    return dataSha256;
}

@end
