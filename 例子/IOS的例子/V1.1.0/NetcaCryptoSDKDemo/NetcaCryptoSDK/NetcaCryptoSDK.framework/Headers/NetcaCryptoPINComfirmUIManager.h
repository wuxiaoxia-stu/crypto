//
//  NetcaCryptoPINComfirmUIManager.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/3/26.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@class NetcaCryptoPinComfirmView;

@interface NetcaCryptoPINComfirmUIManager : NSObject

- (instancetype)init;
- (void)setCustomPinComfirmView:(NetcaCryptoPinComfirmView *)pinComfirmView;
- (NSString *)askUserForPINOfDeivce:(NSString *)deviceName;

@end
