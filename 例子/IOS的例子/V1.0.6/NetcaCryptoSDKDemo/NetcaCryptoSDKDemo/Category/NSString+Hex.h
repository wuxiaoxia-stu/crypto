//
//  NSString+Hex.h
//  NetcaKeyXSDK
//
//  Created by cow on 2018/4/10.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Hex)

- (NSString *)convertToHexString;
- (NSData *)convertToNSDataFromHexString;

@end
