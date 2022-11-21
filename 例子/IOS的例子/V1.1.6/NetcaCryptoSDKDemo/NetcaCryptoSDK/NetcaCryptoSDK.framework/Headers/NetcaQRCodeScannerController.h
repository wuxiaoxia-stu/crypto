//
//  NetcaQRCodeScannerController.h
//  AlipayScanQRCode
//
//  Created by ShaoFeng on 2017/2/15.
//  Copyright © 2017年 ShaoFeng. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol NetcaQRCodeScannerDelegate<NSObject>
-(void)getQrCodeContent:(NSString *)content;
@end

@interface NetcaQRCodeScannerController : UIViewController
@property (nonatomic, weak) id<NetcaQRCodeScannerDelegate> qrCodeScannerDelegate;
@end
