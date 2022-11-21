//
//  NetcaCipherInterface.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/2.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetcaCipherInterface : NSObject

@property (nonatomic, strong, nullable) NSData *iv;
@property (nonatomic, strong, nonnull) NSData *key;
@property (nonatomic) int algo;
@property (nonatomic, copy, nullable) NSString *aad;
@property (nonatomic, readonly) int padding;

- (nonnull instancetype)initWithEncrypt:(BOOL)isEncrypt;

- (BOOL)cipherInit;
- (nullable NSData *)cipherUpdate:(nonnull NSData *)data;
- (nullable NSData *)cipherFinal;

@end
