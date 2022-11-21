//
//  NetcaBluetoothDevice.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 2018/10/9.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetcaBluetoothDevice : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *mac;
@property int type;

@end
