//
//  NetcaHashInterface.h
//  KeyX_iOS
//
//  Created by cow on 2018/2/6.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetcaHashInterface : NSObject

- (nullable NSData *)hash:(int)hashAlgo data:(nonnull NSData *)data;

@end
