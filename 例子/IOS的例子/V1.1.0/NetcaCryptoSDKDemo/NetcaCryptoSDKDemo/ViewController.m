//
//  ViewController.m
//  NetcaCryptoSDKDemo
//
//  Created by NetcaDeveloper on 2018/10/17.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import "ViewController.h"
#import "NSFileManager+Netca.h"
#import "BluetoothViewController.h"
#import <NetcaCryptoSDK/NetcaCryptoSDK.h>

static NSString *PIN = @"12345678";
@interface ViewController ()<NetcaQRCodeScannerDelegate>

@property (nonatomic, strong) NetcaCryptoSDK *crypto;
@property (nonatomic, copy) NSString *qrCodeContent;
@property (nonatomic, strong) NSData *cipher;
@property (copy, nonatomic) NSString *cipherFilePath;//大文件进行数字信封加密后的密文保存路径

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _crypto = [NetcaCryptoSDK sharedInstance];
}

- (IBAction)applyCertificateTapped:(id)sender {
    [self testApplyCertificate];
}

- (IBAction)bleConnectTapped:(id)sender {
    [self testConnectBluetoothDevice];
}

- (IBAction)selectSignCertTapped:(id)sender {
    [self testSelectSignCert];
}

- (IBAction)selectEncCertTapped:(id)sender {
    [self testSelectEncCert];
}

- (IBAction)signTapped:(id)sender {
    [self testSign];
}

- (IBAction)signHashTapped:(id)sender {
    [self testSignHash];
}

- (IBAction)signedDataTapped:(id)sender {
    [self testSignedDataSign];
}

- (IBAction)PDFSignTapped:(id)sender {
    [self testPDFSign];
}

- (IBAction)encryptTapped:(id)sender {
    [self testEncrypt];
}

- (IBAction)decryptTapped:(id)sender {
    [self testDecrypt];
}

- (IBAction)EnvEncTapped:(id)sender {
    [self testEnvelopedDataEncrypt];
}

- (IBAction)EnvDecTapped:(id)sender {
    [self testEnvelopedDataDecrypt];
}

- (IBAction)BigFileSignTapped:(id)sender {
    [self testSign_BigFile];
}

- (IBAction)BigFileSignedDataTapped:(id)sender {
    [self testSignedDataSign_BigFile];
}

- (IBAction)BigFileEnvEncTapped:(id)sender {
    [self testEnvelopedDataEncrypt_BigFile];
}

- (IBAction)BigFileEnvDecTapped:(id)sender {
    [self testEnvelopedDataDecrypt_BigFile];
}

- (IBAction)qrcodeScanTapped:(id)sender {
    NetcaQRCodeScannerController *vc = [[NetcaQRCodeScannerController alloc]init];
    vc.qrCodeScannerDelegate = self;
    [self.navigationController pushViewController:vc animated:true];
}

- (IBAction)qrcodeSignTapped:(id)sender {
    [self testQrcodeSign];
}

- (void)testApplyCertificate {
    NetcaSelfServiceViewController *vc = [[NetcaSelfServiceViewController alloc]init];
    vc.netca_ss_networkurl = @"https://14.18.158.147:6300/um/index.html";//测试环境地址
    [self.navigationController pushViewController:vc animated:true];
}

- (void)testConnectBluetoothDevice {
    BluetoothViewController *vc = [[BluetoothViewController alloc]init];
    [self.navigationController pushViewController:vc animated:true];
}

- (void)testSelectSignCert {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    NSLog(@"签名证书个数为:%d",(int)signCertList.count);
}

- (void)testSelectEncCert {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    NSLog(@"加密证书个数为:%d",(int)encCertList.count);
}

- (void)testSign {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    NetcaCertificate *signCert = signCertList[0];
    int algo = signCert.isSM2 ? NetcaSignAlgorithmSM3WithSM2 : NetcaSignAlgorithmSHA256WithRSA;
    
    NetcaSignatureInterface *signatureInterface = [[NetcaSignatureInterface alloc]init];
    signatureInterface.signCert = signCert;
    signatureInterface.signAlgo = algo;
    NSData *data = [@"hello world" dataUsingEncoding:NSUTF8StringEncoding];
    NSData *p1Signature = [signatureInterface sign:PIN data:data];
    NSString *p1SignatureBase64String = [p1Signature base64EncodedStringWithOptions:0];
    NSLog(@"p1签名成功，签名值的base64编码: %@", p1SignatureBase64String);
}

- (void)testSignHash {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    NetcaCertificate *signCert = signCertList[0];
    int algo = signCert.isSM2 ? NetcaSignAlgorithmSM3WithSM2 : NetcaSignAlgorithmSHA256WithRSA;

    NetcaSignatureInterface *signatureInterface = [[NetcaSignatureInterface alloc]init];
    signatureInterface.signCert = signCert;
    signatureInterface.signAlgo = algo;
    
    //需要先计算hash
    NSData *data = [@"hello world" dataUsingEncoding:NSUTF8StringEncoding];
    NetcaHashInterface *hashInterface = [[NetcaHashInterface alloc]init];
    NSData *hash = [hashInterface hash:NetcaHashAlgorithmSHA256 data:data];
    NSData *p1Signature = [signatureInterface signHash:PIN hash:hash];
    NSString *p1SignatureBase64String = [p1Signature base64EncodedStringWithOptions:0];
    NSLog(@"p1签名成功，签名值的base64编码: %@", p1SignatureBase64String);
}

- (void)testSignedDataSign {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    NetcaCertificate *signCert = signCertList[0];
    int algo = signCert.isSM2 ? NetcaSignAlgorithmSM3WithSM2 : NetcaSignAlgorithmSHA256WithRSA;
    
    NSData *data = [@"hello world" dataUsingEncoding:NSUTF8StringEncoding];
    NetcaSignedDataSignInterface *signedDataInterface = [[NetcaSignedDataSignInterface alloc]init];
    signedDataInterface.signCert = signCert;
    signedDataInterface.signAlgo = algo;
    signedDataInterface.detach = false;
    NSData *p7Signature = [signedDataInterface sign:PIN data:data];
    NSString *p7SignatureBase64String = [p7Signature base64EncodedStringWithOptions:0];
    NSLog(@"p7签名成功，签名值的base64编码: %@", p7SignatureBase64String);
}

- (void)testEncrypt {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    
    NSData *data = [@"hello world" dataUsingEncoding:NSUTF8StringEncoding];
    NetcaEncryptInterface *encryptInterface = [NetcaEncryptInterface new];
    NSData *cipher = [encryptInterface encrypt:data usingCert:encCertList[0]];
    if (cipher) {
        NSString *cipherBase64String = [cipher base64EncodedStringWithOptions:0];
        NSLog(@"非对称加密成功，密文的base64编码: %@", cipherBase64String);
        self.cipher = cipher;
    }else {
        NSLog(@"非对称加密失败");
    }
}

- (void)testDecrypt {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    if (!self.cipher) {
        NSLog(@"请先做非对称加密");
        return;
    }
    NetcaDecryptInterface *decryptInterface = [[NetcaDecryptInterface alloc]init];
    decryptInterface.encCert = encCertList[0];
    int algo = NetcaEncryptAlgorithm_RSA_PKCS1_V1_5_ENC;
    if (decryptInterface.encCert.isSM2) {
        algo = NetcaEncryptAlgorithm_SM2_ENC;
    }
    NSData *plain = [decryptInterface privateKeyDecrypt:self.cipher pwd:PIN usingDecryptAlgo:algo isDecryptKey:false];
    if (plain) {
        NSLog(@"非对称解密结果: %@", plain);
    }else {
        NSLog(@"非对称解密失败");
    }
}

- (void)testEnvelopedDataEncrypt {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    
    NSData *data = [@"hello world" dataUsingEncoding:NSUTF8StringEncoding];
    NetcaEnvelopedDataEncryptInterface *envelopedDataEncryptInterface = [[NetcaEnvelopedDataEncryptInterface alloc]init];
    NSData *cipher = [envelopedDataEncryptInterface encrypt:encCertList[0] data:data useKeyId:true];
    if (cipher) {
        NSString *cipherBase64String = [cipher base64EncodedStringWithOptions:0];
        NSLog(@"数字信封加密成功，密文的base64编码: %@", cipherBase64String);
        self.cipher = cipher;
    }else {
        NSLog(@"数字信封加密失败");
    }
}

- (void)testEnvelopedDataDecrypt {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    if (!self.cipher) {
        NSLog(@"请先做数字信封加密");
        return;
    }
    NetcaEnvelopedDataDecryptInterface *envelopedDataDecryptInterface = [[NetcaEnvelopedDataDecryptInterface alloc]init];
    [envelopedDataDecryptInterface setDecryptCertificate:encCertList[0]];
    NSData *plain = [envelopedDataDecryptInterface decrypt:PIN data:self.cipher];
    if (plain) {
        NSLog(@"数字信封解密结果: %@", plain);
    }else {
        NSLog(@"数字信封解密失败");
    }
}

- (void)testSign_BigFile {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    NetcaCertificate *signCert = signCertList[0];
    
    NSString *plainFilePath = [[NSBundle mainBundle]pathForResource:@"DemoPDF" ofType:@"pdf"];
    NSFileHandle *plainFileHandle = [NSFileHandle fileHandleForReadingAtPath:plainFilePath];
    int algo = signCert.isSM2 ? NetcaSignAlgorithmSM3WithSM2 : NetcaSignAlgorithmSHA256WithRSA;
    
    // 分块读取大文件，计算signature
    NetcaSignatureInterface *signatureInterface = [[NetcaSignatureInterface alloc]init];
    signatureInterface.signCert = signCert;
    signatureInterface.signAlgo = algo;
    bool ret = [signatureInterface signInit:PIN];
    if (!ret) {
        NSLog(@"大文件签名失败");
        return;
    }
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    unsigned long long offset = 0;
    unsigned long long fileLen = [fileManager sizeOfFileAtPath:plainFilePath];
    while (offset <fileLen) {
        NSData *data = [plainFileHandle readDataOfLength:1024];
        offset += 1024;
        
        ret = [signatureInterface signUpdate:data];
        if (!ret) {
            NSLog(@"大文件签名失败");
            return;
        }
        
        [plainFileHandle seekToFileOffset:offset];
    }
    [plainFileHandle closeFile];
    NSData *hash = [signatureInterface signFinal];
    if (hash == nil) {
        NSLog(@"大文件签名失败");
        return;
    }else {
        NSString *signatureBase64Str = [hash base64EncodedStringWithOptions:0];
        NSLog(@"大文件签名成功, 签名值的base64编码:%@", signatureBase64Str);
    }
}

- (void)testSignedDataSign_BigFile {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    NetcaCertificate *signCert = signCertList[0];
    
    NSString *plainFilePath = [[NSBundle mainBundle]pathForResource:@"DemoPDF" ofType:@"pdf"];
    NSFileHandle *plainFileHandle = [NSFileHandle fileHandleForReadingAtPath:plainFilePath];
    int algo = signCert.isSM2 ? NetcaSignAlgorithmSM3WithSM2 : NetcaSignAlgorithmSHA256WithRSA;

    
    // 分块读取大文件，计算SignedData
    NetcaSignedDataSignInterface *signedDataSignInterface = [[NetcaSignedDataSignInterface alloc]init];
    signedDataSignInterface.signCert = signCert;
    signedDataSignInterface.signAlgo = algo;
    signedDataSignInterface.detach = false;
    NSMutableData *signature = [NSMutableData new];
    NSData *temp = [signedDataSignInterface signInit:PIN];
    if (!temp) {
        NSLog(@"大文件SignedData签名失败");
        return;
    }
    [signature appendData:temp];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    unsigned long long offset = 0;
    unsigned long long fileLen = [fileManager sizeOfFileAtPath:plainFilePath];
    while (offset <fileLen) {
        NSData *data = [plainFileHandle readDataOfLength:1024];
        offset += 1024;
        
        NSData *temp = [signedDataSignInterface signUpdate:data];
        if (!temp) {
            NSLog(@"大文件SignedData签名失败");
            return;
        }
        [signature appendData:temp];
        [plainFileHandle seekToFileOffset:offset];
    }
    [plainFileHandle closeFile];
    temp = [signedDataSignInterface signFinal];
    if (!temp) {
        NSLog(@"大文件SignedData签名失败");
        return;
    }
    [signature appendData:temp];
    
    NSString *signatureBase64Str = [signature base64EncodedStringWithOptions:0];
    NSLog(@"大文件SignedData签名成功, 签名值的base64编码:%@", signatureBase64Str);
}


- (void)testEnvelopedDataEncrypt_BigFile {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    
    NSString *plainFilePath = [[NSBundle mainBundle]pathForResource:@"DemoPDF" ofType:@"pdf"];
    bool useKeyId = true;
    
    NetcaEnvelopedDataEncryptInterface *envelopedDataEncryptInterface = [[NetcaEnvelopedDataEncryptInterface alloc]init];
    [envelopedDataEncryptInterface addCert:encCertList[0] useKeyId:true];
    NSMutableData *cipher = [NSMutableData new];
    NSData *temp = [envelopedDataEncryptInterface encryptInit];
    if (!cipher) {
        NSLog(@"大文件数据信封加密失败");
        return;
    }
    [cipher appendData:temp];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSFileHandle *plainFileHandle = [NSFileHandle fileHandleForReadingAtPath:plainFilePath];
    unsigned long long offset = 0;
    unsigned long long fileLen = [fileManager sizeOfFileAtPath:plainFilePath];
    while (offset <fileLen) {
        NSData *data = [plainFileHandle readDataOfLength:1024];
        offset += 1024;
        
        NSData *temp = [envelopedDataEncryptInterface encryptUpdate:data];
        if (!temp) {
            NSLog(@"大文件数据信封加密失败");
            return;
        }
        [cipher appendData:temp];
    }
    [plainFileHandle closeFile];
    
    temp = [envelopedDataEncryptInterface encryptFinal];
    if (!temp) {
        NSLog(@"大文件数据信封加密失败");
        return;
    }
    [cipher appendData:temp];
    
    //将密文写入文件
    NSString *docDir = [fileManager documentsPath];
    NSString *cipherFilePath = [docDir stringByAppendingPathComponent:@"NETCA/NetcaEnvelopedCipher.txt"];
    if (![fileManager createFileAtPath:cipherFilePath deleteExitFile:YES]) {
        return;
    }
    NSFileHandle *fileHandle = [NSFileHandle fileHandleForUpdatingAtPath:cipherFilePath];
    [fileHandle seekToEndOfFile];
    [fileHandle writeData:cipher];
    [fileHandle closeFile];
    
    self.cipherFilePath = cipherFilePath;
    NSLog(@"大文件数据信封加密成功, 密文路径:%@",cipherFilePath);
}

- (void)testEnvelopedDataDecrypt_BigFile {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *encCertList = [certInterface getEncCertList];
    if (encCertList.count <= 0) {
        NSLog(@"加密证书个数为0");
        return;
    }
    if (!self.cipherFilePath) {
        NSLog(@"请先做大文件数字信封加密");
        return;
    }
    NetcaEnvelopedDataDecryptInterface *envelopedDataDecryptInterface = [[NetcaEnvelopedDataDecryptInterface alloc]init];
    [envelopedDataDecryptInterface setDecryptCertificate:encCertList[0]];
    bool ret = [envelopedDataDecryptInterface decryptInit:PIN];
    if (!ret) {
        NSLog(@"大文件数据信封解密失败");
        return;
    }
    
    NSMutableData *plain = [NSMutableData new];
    NSFileHandle *cipherfileHandle = [NSFileHandle fileHandleForUpdatingAtPath:self.cipherFilePath];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    unsigned long long offset = 0;
    unsigned long long fileLen = [fileManager sizeOfFileAtPath:self.cipherFilePath];
    while (offset <fileLen) {
        NSData *data = [cipherfileHandle readDataOfLength:1024];
        offset += 1024;
        
        NSData *temp = [envelopedDataDecryptInterface decryptUpdate:data];
        if (!temp) {
            NSLog(@"大文件数据信封解密失败");
            return;
        }
        [plain appendData:temp];
        [cipherfileHandle seekToFileOffset:offset];
    }
    [cipherfileHandle closeFile];
    
    ret = [envelopedDataDecryptInterface decryptFinal];
    if (!ret) {
        NSLog(@"大文件数据信封解密失败");
        return;
    }
    
    NSLog(@"大文件数据信封解密成功, 明文:%@", plain);
}

- (void)testPDFSign {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    
    NSString *pdfFilePath = [[NSBundle mainBundle]pathForResource:@"DemoPDF" ofType:@"pdf"];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *docDir = [fileManager documentsPath];
    NSString *signedPdfFilePath = [docDir stringByAppendingPathComponent:@"DemoPDF_signed.pdf"];
    NSString *name = @"signature001";
    int pageIndex = 0;
    float left = 100;
    float top = 100;
    float width = 200;
    float height = 50;
    NetcaPDFArea *area = [[NetcaPDFArea alloc]initWithDic:@{@"name":name,
                                                            @"pageIndex":[NSNumber numberWithInt:pageIndex],
                                                            @"left":[NSNumber numberWithFloat:left],
                                                            @"top":[NSNumber numberWithFloat:top],
                                                            @"width":[NSNumber numberWithFloat:width],
                                                            @"height":[NSNumber numberWithFloat:height]
                                                            }];
    
    // 下载OCSP和CRL
    NSString *rootCRLUrl = [NetcaRevokeInfoUtil getRootCRLUrl:signCertList[0]];
    if (!rootCRLUrl) {
        return;
    }
    NSString *issuerOCSPUrl = [NetcaRevokeInfoUtil getIssuerOCSPUrl:signCertList[0]];
    if (!issuerOCSPUrl) {
        return;
    }
    int statusCode = 0;
    NSData *crlData = [certInterface getCRLDataFrom:rootCRLUrl statusCode:&statusCode];
    if (statusCode!=200 || crlData==nil || crlData.length==0) {
        NSLog(@"下载CRL失败");
        return;
    }
    // TODO: 验证CRL
    [certInterface openssl_OCSPRequest:signCertList[0] fromURL:issuerOCSPUrl completedBlock:^(NSData * _Nonnull respData) {
        if (!respData || respData.length==0) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"下载OCSP失败");
                return ;
            });
        }
        // TODO: 验证OCSP
        // 签名
        bool result = [NetcaPDFSignInterface signPDFFile:pdfFilePath
                                               imagePath:nil
                                       signedPdfFilePath:signedPdfFilePath
                                                    cert:signCertList[0]
                                                     pin:PIN
                                                 crlData:crlData
                                                ocspData:respData
                                                  tsaurl:nil
                                                    area:area];
        dispatch_async(dispatch_get_main_queue(), ^{
            if (result) {
                NSLog(@"PDF签名成功, 已签名的PDF文档路径:%@",signedPdfFilePath);
            }else {
                NSLog(@"PDF签名失败");
            }
        });
    }];
}

- (void)testQrcodeSign {
    NetcaCertInterface *certInterface = [_crypto getCertInterface];
    NSArray *signCertList = [certInterface getSignCertList];
    if (signCertList.count <= 0) {
        NSLog(@"签名证书个数为0");
        return;
    }
    
    NetcaQrCodeSignInterface *qrCodeSignInterface = [[NetcaQrCodeSignInterface alloc]init];
    [qrCodeSignInterface setQrCodeContent:self.qrCodeContent];
    NSString *signContent = [qrCodeSignInterface querySignData:NULL];
    if (!signContent || signContent.length==0) {
        NSLog(@"获取签名内容失败");
    }else {
        long ret = [qrCodeSignInterface qrcodeSign:signCertList[0] pin:PIN];
        if (ret != NetcaErrorCodeSuccess) {
            NSLog(@"二维码签名失败, 原因:%@", [qrCodeSignInterface errorMessage]);
        }else {
            NSLog(@"二维码签名成功");
        }
    }
}

#pragma mark - QrCodeScannerDelegate
-(void)getQrCodeContent:(NSString *)content {
    self.qrCodeContent = content;
    NSLog(@"二维码内容:%@", content);
}

@end


