//
//  NetcaPDFArea.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/5/14.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface NetcaPDFArea : NSObject

@property(nonatomic, copy) NSString *name;
@property(nonatomic) int pageIndex;
@property(nonatomic) CGFloat left;
@property(nonatomic) CGFloat top;
@property(nonatomic) CGFloat width;
@property(nonatomic) CGFloat height;

- (instancetype)initWithDic:(NSDictionary *)dic;

@end
