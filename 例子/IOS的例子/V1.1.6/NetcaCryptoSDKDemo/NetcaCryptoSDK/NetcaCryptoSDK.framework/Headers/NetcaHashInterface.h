//
//  NetcaHashInterface.h
//  KeyX_iOS
//
//  Created by cow on 2018/2/6.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetcaHashInterface : NSObject

/**
一步完成Hash运算，用于原文比较小时

@param hashAlgo Hash算法
@param data 要进行Hash的数据
@return Hash值
*/
- (nullable NSData *)hash:(int)hashAlgo data:(nonnull NSData *)data;

/**
 多步计算Hash的初始化

 @param hashAlgo Hash算法
 */
- (BOOL)hashInit:(int)hashAlgo;


/**
 多次输入原文进行Hash运算

 @param data 要进行Hash的数据
 */
- (BOOL)hashUpdate:(nonnull NSData *)data;


/**
 结束Hash运算

 @return 返回签名值
 */
- (nullable NSData *)hashFinal;

@end
