//
//  PinInputView.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/2/5.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NetcaCryptoPinInputView : UIView

@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIButton *okButton;
@property (nonatomic, strong) UILabel *deviceNameLabel;
@property (nonatomic, strong) UILabel *retryNumberTipLabel;
@property (nonatomic, strong) UILabel *retryNumberLabel;
@property (nonatomic, strong) UILabel *pinTipLabel;
@property (nonatomic, strong) UITextField *pinInputTextField;

- (instancetype)initWithDefaultStyle;

@end
