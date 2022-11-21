//
//  ViewController.m
//  NetcaCryptoSDKDemo
//
//  Created by NetcaDeveloper on 2018/10/17.
//  Copyright © 2018年 NetcaDeveloper. All rights reserved.
//

#import "ViewController.h"
#import "NSFileManager+Netca.h"
//#import "BluetoothViewController.h"
#import <NetcaCryptoSDK/NetcaCryptoSDK.h>

static NSString *PIN = @"12345678";
@interface ViewController ()<NetcaQRCodeScannerDelegate>

@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (nonatomic, strong) NetcaCryptoSDK *crypto;
@property (nonatomic, copy) NSString *qrCodeContent;
@property (nonatomic, strong) NSData *cipher;
@property (copy, nonatomic) NSString *cipherFilePath;//大文件进行数字信封加密后的密文保存路径
@property (nonatomic, strong) NetcaPinManageSystemInterface *pinManageSystemInterface;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.scrollView.contentSize = CGSizeMake(self.view.frame.size.width, 1100);

    _crypto = [NetcaCryptoSDK sharedInstance];
    _pinManageSystemInterface = [[NetcaPinManageSystemInterface alloc]init];
}

#pragma mark - 按钮事件
- (IBAction)applyCertificateTapped:(id)sender {
    [self testApplyCertificate];
}

- (IBAction)bleConnectTapped:(id)sender {
//    [self testConnectBluetoothDevice];
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

// 以移动Key为例，简要描述设备的配置、创建、产生P10和安装证书的步骤
- (IBAction)setDeviceConfigInfoTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    
    //配置信息是一个json串，包括服务器地址和appid。这是测试环境的地址，正式使用需要替换
    NSString *configInfo = @"{\"u\":\"http://120.25.164.100:7091\",\"id\":\"263277445690425344\"}";
    NetcaError rv = [deviceInterface setDeviceConfig:NetcaDeviceTypeMKeyDevice jsonStr:configInfo];
    if (rv != NetcaErrorCodeSuccess) {
        NSLog(@"设置设备信息失败");
    }
}

- (IBAction)createDeviceTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NetcaError rv = [deviceInterface createDevice:NetcaDeviceTypeMKeyDevice pwd:PIN];
    if (rv != NetcaErrorCodeSuccess && rv!= NetcaErrorCodeExisit) {
        NSLog(@"创建设备失败");
    }
}

- (IBAction)genP10Tapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];//移动Key只会有一个
    
    // dn: 证书的各项信息
    // algo: NetcaSignAlgorithmSM3WithSM2
    // keyBits: 256
    // keyType: NetcaKeyPairTypeSignature
    NSString *dn = @"CN=移动key测试,OU=部门,O=移动key测试,S=Guangdong,C=CN";
    NSString *p10 = [device genP10:PIN dn:dn algo:NetcaSignAlgorithmSM3WithSM2 keyBits:256 keyType:NetcaKeyPairTypeSignature];
    if (!p10) {
        NetcaError rv = [NetcaCryptoSDK getLastErrorCode];
        NSLog(@"产生p10失败, 错误码:%lld, 错误信息:%@", rv, errMsgOfCode(rv));
    }
    
    //产生p10后，由调用者自行将p10发到CA后台进行制证，得到签名证书、加密证书和加密密钥对
}

- (IBAction)installCertTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    NSString *signCert = @"";// 签名证书的base64编码
    NSString *encCert = @"";// 加密证书的base64编码
    NSString *encKeyPair = @"";// 加密密钥对的base64编码
    BOOL rv = [device installCert:PIN platform:NetcaEncKeyPairTypeGBT_35276 signCert:signCert encCert:encCert encKeyPair:encKeyPair];
    if (!rv) {
        NetcaError rv = [NetcaCryptoSDK getLastErrorCode];
        NSLog(@"安装证书失败, 错误码:%lld, 错误信息:%@", rv, errMsgOfCode(rv));
    }
}

// 以移动Key为例，简要描述重置密码的步骤
- (IBAction)setPinManageSystemAddrTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    
    //配置信息是一个json串，包括服务器地址和appid。这是测试环境的地址，正式使用需要替换
    NSString *serverUrl = @"http://120.25.164.100:7093/sopin";
    NetcaError rv = [deviceInterface setPinManagerSystemAddr:serverUrl];
    if (rv != NetcaErrorCodeSuccess) {
        NSLog(@"设置口令管理系统服务器地址失败");
    }
}

- (IBAction)registerSoPinTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    _pinManageSystemInterface.device = device;
    [_pinManageSystemInterface registerSoPin:@"" userPin:@"123456" completion:^(NSError * _Nullable error) {
        if (error) {
            NSLog(@"注册管理员密钥失败，错误码:%ld, 错误信息:%@", (long)error.code, error.localizedDescription);
        } else {
            NSLog(@"注册管理员密钥成功");
        }
    }];
}

- (IBAction)requestSoPinTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    _pinManageSystemInterface.device = device;
    [_pinManageSystemInterface requestGetSoPin:^(NSError * _Nullable error, NSString * _Nullable dataToSign) {
        if (error) {
            NSLog(@"请求获取管理员密钥失败，错误码:%ld, 错误信息:%@", (long)error.code, error.localizedDescription);
        } else {
            NSLog(@"请求获取管理员密钥成功，要签名的内容:%@", dataToSign);
        }
    }];
    
    // 接下来，调用者自行对dataToSign进行签名，得到签名值后，进行下一步
}

- (IBAction)resetUserPinTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    _pinManageSystemInterface.device = device;
    NSString *newUserPin = @"123456"; //新的用户密码
    NSString *signature = @""; //上一步的签名值

    [_pinManageSystemInterface unlockUserPin:newUserPin signature:signature completion:^(NSError * _Nullable error) {
        if (error) {
            NSLog(@"重置密码失败，错误码:%ld, 错误信息:%@", (long)error.code, error.localizedDescription);
        } else {
            NSLog(@"重置密码成功");
        }
    }];
}

- (IBAction)writeSealTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    // 判断设备是否支持读写章
    BOOL ret = [device isSupportSeal];
    if (!ret) {
        NSLog(@"该设备不支持读写章");
        return;
    }
    
    // 验证用户PIN码
    int retryNum;
    ret = [device verifyPwdOfType:@1 pwd:PIN pRetryNum:&retryNum];
    if (!ret) {
        NSLog(@"用户PIN码验证不通过");
        return;
    }
    
    NSString *sealName = @"用户签章";//签章名称
    NSString *sealImagePath = [[NSBundle mainBundle]pathForResource:@"seal" ofType:@"png"];
    NSData *sealImageData = [NSData dataWithContentsOfFile:sealImagePath];//签章图片数据
    ret = [device writeSeal:sealName picture:sealImageData];
    if (!ret) {
        NSLog(@"写章失败");
        return;
    }
    NSLog(@"写章成功");
}

- (IBAction)readSealTapped:(id)sender {
    NetcaDeviceInterface *deviceInterface = [_crypto getDeviceInterface];
    NSArray<NetcaDevice *> *deviceList = [deviceInterface findDeviceByType:NetcaDeviceTypeMKeyDevice];
    if (deviceList.count <= 0) {
        NSLog(@"设备个数为0");
        return;
    }
    NetcaDevice *device = deviceList[0];
    
    // 判断设备是否支持读写章
    BOOL ret = [device isSupportSeal];
    if (!ret) {
        NSLog(@"该设备不支持读写章");
        return;
    }
    
    // 获取签章个数
    int count = [device getSealCount];
    if (count <= 0) {
        NSLog(@"该设备中没有签章");
        return;
    }
    
    // 获取第1个签章
    NSData *imageData = [device readSeal:0];
    if (!imageData) {
        NSLog(@"读章失败");
        return;
    }
    NSLog(@"读章成功，签章图片数据:%@", imageData);
}

#pragma mark - 实现
- (void)testApplyCertificate {
    NetcaSelfServiceViewController *vc = [[NetcaSelfServiceViewController alloc]init];
    vc.netca_ss_networkurl = @"https://14.18.158.147:6300/um/index.html";//这是测试环境的地址，正式使用需要替换
    [self.navigationController pushViewController:vc animated:true];
}

//- (void)testConnectBluetoothDevice {
//    BluetoothViewController *vc = [[BluetoothViewController alloc]init];
//    [self.navigationController pushViewController:vc animated:true];
//}

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
    
    // 验证签名
    NetcaSignatureVerifyInterface *verifyInterface = [[NetcaSignatureVerifyInterface alloc]init];
    [verifyInterface setSignCertificate:signCert];
    [verifyInterface setSignAlgorithm:algo];
    BOOL ret = [verifyInterface verify:data signature:p1Signature];
    if (!ret) {
        NSLog(@"验签失败");
        return;
    }
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
    NSData *hash;
    //SM3需要先计算Z
    if (algo == NetcaSignAlgorithmSM3WithSM2) {
        NSData *Z = [signatureInterface computeSM2Z:nil];
        if (!Z) {
            NSLog(@"计算Z失败");
        }
        if (![hashInterface hashInit:NetcaHashAlgorithmSM3]) {
            NSLog(@"hashInit失败");
        }
        if (![hashInterface hashUpdate:Z]) {
            NSLog(@"hashUpdate失败");
        }
        if (![hashInterface hashUpdate:data]) {
            NSLog(@"hashUpdate失败");
        }
        hash = [hashInterface hashFinal];
    } else {
        hash = [hashInterface hash:NetcaHashAlgorithmSHA256 data:data];
    }
    
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
    signedDataInterface.detach = true;//不带原文
    NSData *p7Signature = [signedDataInterface sign:PIN data:data];
    NSString *p7SignatureBase64String = [p7Signature base64EncodedStringWithOptions:0];
    NSLog(@"p7签名成功，签名值的base64编码: %@", p7SignatureBase64String);
    
    // 验证签名
    NetcaSignedDataVerifyInterface *verifyInterface = [[NetcaSignedDataVerifyInterface alloc]init];
    BOOL ret = [verifyInterface verify:data signature:p7Signature];
    if (!ret) {
        NSLog(@"验签失败");
        return;
    }
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
    envelopedDataEncryptInterface.useKeyId = true;
    NSData *cipher = [envelopedDataEncryptInterface encrypt:data certs:encCertList[0] ];
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
    signedDataSignInterface.detach = true;
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
    
    NetcaEnvelopedDataEncryptInterface *envelopedDataEncryptInterface = [[NetcaEnvelopedDataEncryptInterface alloc]init];
    envelopedDataEncryptInterface.useKeyId = true;
    NSMutableData *cipher = [NSMutableData new];
    NSData *temp = [envelopedDataEncryptInterface encryptInit:encCertList[0]];
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
    
    // 验证中级证书有效性
    NetcaCertificate *signCert = signCertList[0];
    NSArray<NetcaCertificate *> *certPath = [signCert buildCertPath];
    if (!certPath || certPath.count <= 2) {
        NSLog(@"构造证书链失败");
        return;
    }
    NetcaCertificate *caCert = certPath[1];
    NSString *rootCRLUrl = [caCert crlURL];
    if (!rootCRLUrl) {
        NSLog(@"获取证书CRL地址失败");
        return;
    }
    int statusCode = 0;
    NSData *crlData = [certInterface getCRLDataFrom:rootCRLUrl statusCode:&statusCode];
    if (statusCode!=200 || crlData==nil || crlData.length==0) {
        NSLog(@"下载中级证书CRL数据失败");
        return;
    }
    if (![certInterface verifyCertByCrl:caCert crlData:crlData]) {
        NSLog(@"中级证书验证失败");
        return;
    }
    
    // 验证签名证书有效性
    NSString *issuerOCSPUrl = [signCert ocspURL];
    if (!issuerOCSPUrl) {
        NSLog(@"获取证书OCSP地址失败");
        return;
    }
    [certInterface openssl_OCSPRequest:signCert fromURL:issuerOCSPUrl completedBlock:^(NSData * _Nonnull respData) {
        if (!respData || respData.length==0) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"下载签名证书OCSP数据失败");
                return ;
            });
        }
        if (![certInterface verifyCertByOcsp:signCert ocspData:respData]) {
            dispatch_async(dispatch_get_main_queue(), ^{
                NSLog(@"签名证书验证失败");
                return ;
            });
        }
        // 签名
        bool result = [NetcaPDFSignInterface signPDFFile:pdfFilePath
                                               imageData:nil
                                       signedPdfFilePath:signedPdfFilePath
                                                    cert:signCert
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



