//
//  PDFDocument.h
//  KeyX_iOS
//
//  Created by KeyX on 2018/5/14.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PDFSignConfig.h"
#import "PDFSignArea.h"
#import "NetcaPDFArea.h"

@interface PDFDocuments : NSObject

@property (nonatomic) int totalPage;
@property (nonatomic) int totalSize;                  //下载的PDF总大小
@property (nonatomic, copy) NSString *pdfFileName;                //下载的PDF文档名称
@property (nonatomic, copy) NSString *pdfSaveFullPath;            //下载的PDF保存全路径

// 签名信息
@property (nonatomic, strong) PDFSignConfig *signConfigModel;   //签名配置文件信息
@property (nonatomic, strong) NSArray<PDFSignArea *> *signInfoModelList;    //签名信息数组
@property (nonatomic, strong) NSArray<NetcaPDFArea *> *signAreaModelList;        //签名域数组
@property (nonatomic, getter=isFinishSigned, readonly) BOOL finishSigned;

- (int)initPDFDocument:(NSString *)filePath type:(NSString *)type;
- (UIImage *)getImageOfPageIndex:(int)pageIndex width:(CGFloat *)pageWidth height:(CGFloat *)pageHeight;

- (PDFSignArea *)nextSignInfoArea;


@end
