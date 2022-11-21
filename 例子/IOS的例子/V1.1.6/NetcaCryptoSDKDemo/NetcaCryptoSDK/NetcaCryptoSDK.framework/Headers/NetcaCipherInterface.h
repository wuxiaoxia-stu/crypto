//
//  NetcaCipherInterface.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/2.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 DES的Key必须是8个字节
 3DES的Key必须大于等于16个字节
 */
@interface NetcaCipherInterface : NSObject

@property (nonatomic, strong, nullable) NSData *iv;
@property (nonatomic, strong, nullable) NSData *key;
@property (nonatomic) int algo;
@property (nonatomic, copy, nullable) NSString *aad;
@property (nonatomic) int padding;

- (BOOL)cipherInit:(BOOL)isEncrypt;
- (nullable NSData *)cipherUpdate:(nonnull NSData *)data;
- (nullable NSData *)cipherFinal;

@end
