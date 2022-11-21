//
//  NetcaCryptoPINInputUIManager.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/5.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@class NetcaCryptoPinInputView;

@interface NetcaCryptoPINInputUIManager : NSObject

- (instancetype)init;
- (void)setCustomPinInputView:(NetcaCryptoPinInputView *)pinInputView;
- (NSString *)askUserForPINOfDeivce:(NSString *)deviceName retryNumber:(int)retryNumber;

@end
