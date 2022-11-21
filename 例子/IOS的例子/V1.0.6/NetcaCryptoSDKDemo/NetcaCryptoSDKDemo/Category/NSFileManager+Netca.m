//
//  NSFileManager+Netca.m
//  NetcaKeyXSDKTest
//
//  Created by cow on 2018/4/20.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import "NSFileManager+Netca.h"

@implementation NSFileManager (Netca)

// 获取指定directory的路径
- (NSString *)pathForDirectory:(NSSearchPathDirectory)directory {
    return NSSearchPathForDirectoriesInDomains(directory, NSUserDomainMask, YES)[0];
}

- (NSString *)homePath {
    return NSHomeDirectory();
}

- (NSString *)documentsPath {
    NSLog(@"hahahaha--------------");
    return [self pathForDirectory:NSDocumentDirectory];
}

- (NSString *)libraryPath {
    return [self pathForDirectory:NSLibraryDirectory];
}

- (NSString *)cachesPath {
    return [self pathForDirectory:NSCachesDirectory];
}


- (BOOL)createFileAtPath:(NSString *)filePath deleteExitFile:(BOOL)deleteExitFile {
    if (!filePath) {
        return false;
    }
    
    BOOL isSuccess = true;
    NSError *error;
    NSFileManager *fileManager = [NSFileManager defaultManager];
    BOOL exist = [fileManager fileExistsAtPath:filePath];
    if (exist && deleteExitFile) {
        isSuccess = [fileManager removeItemAtPath:filePath error:&error];
        if (error) {
            return false;
        }
    }
    if (exist) {
        return true;
    }
    
    NSString *dirPath = [filePath stringByDeletingLastPathComponent];
    exist = [fileManager fileExistsAtPath:dirPath];
    if (!exist) {
        [fileManager createDirectoryAtPath:dirPath withIntermediateDirectories:YES attributes:nil error:&error];
        if (error) {
            return false;
        }
    }
    
    isSuccess = [fileManager createFileAtPath:filePath contents:nil attributes:nil];
    return isSuccess;
}

- (unsigned long long)sizeOfFileAtPath:(NSString *)filePath {
    NSFileManager* manager = [NSFileManager defaultManager];
    if ([manager fileExistsAtPath:filePath]){
        return [[manager attributesOfItemAtPath:filePath error:nil] fileSize];
    }
    return 0;
}

@end
