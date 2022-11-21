//
//  NetcaSelfServiceViewController.h
//  KeyX_iOS
//
//  Created by KeyX on 2017/12/21.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NetcaSelfServiceViewController : UIViewController

@property (nonatomic, copy) NSString *qrcode; // 具体的业务二维码
@property (nonatomic, copy) NSString *netca_ss_networkurl; // 自助服务地址，若不传，则使用生产环境的地址

@end
