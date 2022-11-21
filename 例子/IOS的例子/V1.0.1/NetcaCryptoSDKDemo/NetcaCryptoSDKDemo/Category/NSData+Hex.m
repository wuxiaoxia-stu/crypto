//
//  NSData+Hex.m
//  NetcaKeyXSDK
//
//  Created by cow on 2018/4/10.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import "NSData+Hex.h"

@implementation NSData (Hex)

- (NSString *)convertToHexString {
    if (!self || [self length] == 0) {
        return nil;
    }
    NSMutableString *string = [[NSMutableString alloc] initWithCapacity:[self length]];
    
    [self enumerateByteRangesUsingBlock:^(const void *bytes, NSRange byteRange, BOOL *stop) {
        unsigned char *dataBytes = (unsigned char*)bytes;
        for (NSInteger i = 0; i < byteRange.length; i++) {
            NSString *hexStr = [NSString stringWithFormat:@"%x", (dataBytes[i]) & 0xff];
            if ([hexStr length] == 2) {
                [string appendString:hexStr];
            } else {
                [string appendFormat:@"0%@", hexStr];
            }
        }
    }];
    
    return string;
}

@end
