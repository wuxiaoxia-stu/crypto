//
//  NetcaCryptoPinComfirmView.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/3/26.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NetcaCryptoPinComfirmView : UIView

@property (nonatomic, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIButton *okButton;
@property (nonatomic, strong) UILabel *deviceNameLabel;
@property (nonatomic, strong) UILabel *pinTipLabel;
@property (nonatomic, strong) UITextField *pinInputTextField;
@property (nonatomic, strong) UILabel *comfirmTipLabel;
@property (nonatomic, strong) UITextField *comfirmTextField;

- (instancetype)initWithDefaultStyle;

@end
