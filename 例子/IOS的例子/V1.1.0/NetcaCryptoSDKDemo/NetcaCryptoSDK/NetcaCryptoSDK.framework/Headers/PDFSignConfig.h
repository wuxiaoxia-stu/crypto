//
//  PDFSignConfig.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/5/14.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PDFSignArea;
@interface PDFSignConfig : NSObject

@property(nonatomic) int version;
@property(nonatomic) BOOL isNeedHandWriteSignature;
@property(nonatomic, copy) NSString *postSignedPDFUrl;
@property(nonatomic, copy) NSString *successTips;
@property NSArray<PDFSignArea *> *signAreas;

- (instancetype)initWithDic:(NSDictionary *)dic;

@end
