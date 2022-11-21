//
//  NSFileManager+Netca.h
//  NetcaKeyXSDKTest
//
//  Created by cow on 2018/4/20.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (Netca)

- (NSString *)homePath;
- (NSString *)documentsPath;
- (NSString *)libraryPath;
- (NSString *)cachesPath;


- (BOOL)createFileAtPath:(NSString *)filePath deleteExitFile:(BOOL)deleteExitFile;
- (unsigned long long)sizeOfFileAtPath:(NSString *)filePath;

@end
