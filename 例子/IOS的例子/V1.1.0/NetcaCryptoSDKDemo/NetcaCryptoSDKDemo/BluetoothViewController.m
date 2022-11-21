//
//  BluetoothViewController.m
//  NetcaCryptoSDKDemo
//
//  Created by NetcaDeveloper on 2018/11/14.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import "BluetoothViewController.h"
#import <NetcaCryptoSDK/NetcaBluetoothManager.h>

@interface BluetoothViewController ()<NetcaBluetoothManagerDelegate>

@property (nonatomic, strong)NetcaBluetoothManager *bluetoothManager;

@end

@implementation BluetoothViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _bluetoothManager = [NetcaBluetoothManager new];
    _bluetoothManager.delegate = self;
    self.navigationItem.title = @"蓝牙";
    
    self.view.backgroundColor = [UIColor whiteColor];
}

- (void)bluetoothManagerDidUpdateState:(CBCentralManager *)central {
    switch (central.state) {
        case CBManagerStatePoweredOn:
            NSLog(@"开始扫描蓝牙设备");
            [_bluetoothManager startScan];
            break;
        case CBManagerStatePoweredOff:
            NSLog(@"请先开启蓝牙访问权限");
        default:
            break;
    }
}

- (void)bluetoothManagerDidDiscoverDevice:(NetcaBluetoothDevice *)device {
    [_bluetoothManager connectDevice:device];
}

- (void)bluetoothManagerDidConnectDevice:(NetcaBluetoothDevice *)device {
    NSLog(@"连接蓝牙成功");
}

- (void)bluetoothManagerDidFailToConnectDevice:(NetcaBluetoothDevice *)device error:(NSError *)error {
    NSLog(@"连接蓝牙失败");
}

- (void)bluetoothManagerDidDisconnectDevice:(NetcaBluetoothDevice *)device error:(NSError *)error {
    NSLog(@"蓝牙已断开");
}

@end
