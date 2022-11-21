//
//  NetcaScanCodeController.h
//  AlipayScanQRCode
//
//  Created by ShaoFeng on 2017/2/15.
//  Copyright © 2017年 ShaoFeng. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol QRCodeScannerDelegate<NSObject>

-(void)getQrCodeContent:(NSString *)content;

@end


@interface NetcaScanCodeController : UIViewController

@property (nonatomic, strong) UIStatusBar *statusBar;
@property (nonatomic, strong) UINavigationBar *navigationBar;
@property (nonatomic, weak) id<QRCodeScannerDelegate> qrCodeScannerDelegate;

@end
