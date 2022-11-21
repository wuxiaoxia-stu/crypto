//
//  NetcaPDFSignInterface.h
//  KeyX_iOS
//
//  Created by NetcaDeveloper on 17/11/1.
//  Copyright © 2017年 NetcaDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NetcaCertificate;
@class NetcaPDFArea;
@interface NetcaPDFSignInterface : NSObject

/**
 * 对PDF使用签章图片在指定域做签名，需要先调用getSignCert方法获取签名证书（必须异步调用，否则无法跳转回来）
 *
 * @param pdfFilePath       需要签名的pdf文档路径
 * @param imagePath         签章图片的路径
 * @param signedPdfFilePath 保存签名后的pdf文档路径
 * @param cert              签名证书
 * @param pin               电子密钥PIN码，若为NULL，则在WPKI中输入
 * @param crlData           验证的crl数据（可为NULL）
 * @param ocspData          验证的ocsp数据（可为NULL）
 * @param tsaurl            时间戳服务器地址（可为NULL）
 * @param area              签名域信息
 *
 * @return 成功返回true
 */
+ (bool)signPDFFile:(nonnull NSString *)pdfFilePath
          imagePath:(nullable NSString *)imagePath
  signedPdfFilePath:(nonnull NSString *)signedPdfFilePath
               cert:(nonnull NetcaCertificate *)cert
                pin:(nonnull NSString *)pin
            crlData:(nullable NSData *)crlData
           ocspData:(nullable NSData *)ocspData
             tsaurl:(nullable NSString *)tsaurl
               area:(nonnull NetcaPDFArea *)area;


@end


