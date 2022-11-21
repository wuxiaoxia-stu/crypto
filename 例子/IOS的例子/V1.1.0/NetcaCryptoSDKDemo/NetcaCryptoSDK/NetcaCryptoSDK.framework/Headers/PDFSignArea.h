//
//  PDFSignArea.h
//  KeyX_iOS
//
//  Created by CKeyX on 2018/5/14.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaPDFArea;
@interface PDFSignArea : NSObject

@property(nonatomic, copy) NSString *showTips;
@property(nonatomic) BOOL createIfNotExit;
@property(nonatomic, strong) NSArray<NetcaPDFArea *> *area;
@property(nonatomic) BOOL isNeeded;

- (instancetype)initWithDic:(NSDictionary *)dic;

@end
