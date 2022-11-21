//
//  NetcaBluetoothManager.h
//  KeyX_iOS
//
//  Created by cow on 2018/2/7.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/*
 由于设备厂家限制，同一时间，同一款key只能连一个
 */
@class NetcaBluetoothDevice;
@protocol NetcaBluetoothManagerDelegate;
@interface NetcaBluetoothManager : NSObject<CBCentralManagerDelegate, CBPeripheralDelegate>
@property (nonatomic, weak, nullable)id<NetcaBluetoothManagerDelegate> delegate;

- (void)startScan;
- (void)stopScan;
- (void)connectDevice:(NetcaBluetoothDevice *)device;
- (void)disconnectDevice:(NetcaBluetoothDevice *)device;
@end


@protocol NetcaBluetoothManagerDelegate <NSObject>
@required
- (void)bluetoothManagerDidUpdateState:(CBCentralManager *)central;

@optional
- (void)bluetoothManagerDidDiscoverDevice:(NetcaBluetoothDevice *)device;
- (void)bluetoothManagerDidConnectDevice:(NetcaBluetoothDevice *)device;
- (void)bluetoothManagerDidFailToConnectDevice:(NetcaBluetoothDevice *)device error:(nullable NSError *)error;
- (void)bluetoothManagerDidDisconnectDevice:(NetcaBluetoothDevice *)device error:(nullable NSError *)error;
@end
