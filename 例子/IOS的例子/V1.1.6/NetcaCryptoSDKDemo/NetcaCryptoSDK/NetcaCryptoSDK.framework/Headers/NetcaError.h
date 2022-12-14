//
//  NetcaError.h
//  NetcaKeyXSDK
//
//  Created by Chris Cheung on 2018/4/9.
//  Copyright © 2018年 Netca. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(long long, NetcaError) {
    
#pragma mark - 中间件错误码
    /* 失败，未知原因 */
    NetcaErrorCodeFailure = 0,
    /* 成功 */
    NetcaErrorCodeSuccess = 1,
    /* 无效的参数 */
    NetcaErrorCodeInValidArg = -1,
    /* 无效的句柄 */
    NetcaErrorCodeInValidHandle = -2,
    /* 内存空间不足 */
    NetcaErrorCodeOutOfMemory = -3,
    /* 需要更多数据 */
    NetcaErrorCodeMoreData = -4,
    /* 密码错误 */
    NetcaErrorCodePinError = -5,
    /* 已经存在 */
    NetcaErrorCodeExisit = -6,
    /* 不存在 */
    NetcaErrorCodeNotExisit = -7,
    /* 拒绝访问 */
    NetcaErrorCodeAccessDenied = -8,
    /* 不支持 */
    NetcaErrorCodeUnsupported = -9,
    /* 未实现 */
    NetcaErrorCodeNotImplement = -10,
    /* 超时 */
    NetcaErrorCodeTimeout = -11,
    /* 构造证书链失败 */
    NetcaErrorCodeBuildCertPathFail = -12,
    /* 验证证书链失败 */
    NetcaErrorCodeVerifyCertPathFail = -13,
    /* 不在有效期内 */
    NetcaErrorCodeNotInValidity = -14,
    /* CRL或OCSP不在有效期内 */
    NetcaErrorCodeRevokeInfoNotInValidity = -15,
    /* 不符合安全环境的要求 */
    NetcaErrorCodeViolate = -16,
    /* 用户取消 */
    NetcaErrorCodeUserCancel = -18,
    /* 密码长度错误 */
    NetcaErrorCodePinLengthError = -19,
    /* 密码格式错误 */
    NetcaErrorCodePinFormatError = -20,
    /* 数据长度过大 */
    NetcaErrorCodeDataTooLong = -21,
    /* 密码没有被锁死 */
    NetcaErrorCodePinNotLock = -22,
    /* 没有匹配的设备 */
    NetcaErrorCodeNoSuchDevice = -25,
    /* 没有匹配的密钥对 */
    NetcaErrorCodeNoSuchKeyPair = -26,
    /* 证书匹配表达式错误 */
    NetcaErrorCodeBadCertMatchExpr = -27,
    /* 没有根证书 */
    NetcaErrorCodeNoRootCert = -28,
    /* 没有合适的作废信息 */
    NetcaErrorCodeNoRevokeInfo = -29,
    /* 没有合适的CA作废信息 */
    NetcaErrorCodeNoCARevokeInfo = -30,
    /* 验证MAC失败 */
    NetcaErrorCodeVerifyMacFail = -31,
    /* 验证SignedData时，至少一个SignerInfo成功，其他的失败 */
    NetcaErrorCodeVerifySignedDataPartlyFail = -32,
    /* 不支持HTTP */
    NetcaErrorCodeHttpUnSupported = -33,
    /* 不支持LDAP */
    NetcaErrorCodeLdapUnSupported = -34,
    /* 验证SignedData的证书失败 */
    NetcaErrorCodeVerifySignedDataCertFail = -36,
    /* EnvelopedData格式错误 */
    NetcaErrorCodeEnvelopedDataBadData = -37,
    /* EnvelopedData解密对称密钥失败 */
    NetcaErrorCodeEnvelopedDataDecryptKeyFail = -38,
    /* EnvelopedData解密数据失败 */
    NetcaErrorCodeEnvelopedDataDecryptDataFail = -39,
    /* EnvelopedData没有匹配的证书用于解密对称密钥 */
    NetcaErrorCodeEnvelopedDataNoMatchCert = -40,
    /* SignedData格式错误 */
    NetcaErrorCodeSignedDataBadData = -41,
    /* 验证SignedData的Content-Type失败 */
    NetcaErrorCodeSignedDataVerifyContentTypeFail = -42,
    /* 验证SignedData的Hash失败 */
    NetcaErrorCodeSignedDataVerifyHashFail = -43,
    /* 验证SignedData的签名失败 */
    NetcaErrorCodeSignedDataVerifySignatureFail = -44,
    /* 没有签名证书用于验证SignedData的签名 */
    NetcaErrorCodeSignedDataNoMatchCert = -45,
    /* 验证证书路径的签名失败 */
    NetcaErrorCodeVerifyCertPathSignatureFile = -46,
    /* 验证证书路径的基本限制失败 */
    NetcaErrorCodeVerifyCertPathBasicConstraintsFail = -47,
    /* 验证证书路径的策略相关扩展失败 */
    NetcaErrorCodeVerifyCertPathPolicyFail = -48,
    /* 验证证书路径的名字和名字约束失败 */
    NetcaErrorCodeVerifyCertPathNameFail = -49,
    /* 验证证书路径时存在未知关键扩展 */
    NetcaErrorCodeVerifyCertPathUnknownExtensionExist = -50,
    /* 验证证书路径的KeyUsage失败 */
    NetcaErrorCodeVerifyCertPathKeyUsageFail = -51,
    /* 验证时间戳的MessageImprint失败 */
    NetcaErrorCodeVerifyTimestampMessageImprintFail = -52,
    /* 错误的填充数据 */
    NetcaErrorCodeBadPadding = -53,
    /* 签名算法和密钥对不匹配 */
    NetcaErrorCodeSignAlgoKeyPairNotMatch = -54,
    /* 签名算法和公钥不匹配 */
    NetcaErrorCodeSignAlgoPublicKeyNotMatch = -55,
    /* 加密算法和公钥不匹配 */
    NetcaErrorCodeEncAlgoPublicKeyNotMatch = -56,
    /* 加密算法和密钥对不匹配 */
    NetcaErrorCodeEncAlgoKeyPairNotMatch = -57,
    /* 密钥协商算法和密钥对不匹配 */
    NetcaErrorCodeKeyAgreementAlgoKeyPairNotMatch = -58,
    /* 错误的CRL的编码 */
    NetcaErrorCodeBadCrlEncode = -59,
    /* 错误的OCSP响应的编码 */
    NetcaErrorCodeBadOCSPEncode = -60,
    /* EnvelopedData错误的加密算法 */
    NetcaErrorCodeEnvelopedDataBadEncAlgo = -61,
    /* EnvelopedData错误的加密证书 */
    NetcaErrorCodeEnvelopedDataBadCert = -62,
    /* EnvelopedData加密出错 */
    NetcaErrorCodeEnvelopedDataEncryptFail = -63,
    /* 证书没有Subjet Key Id扩展 */
    NetcaErrorCodeNoSubjectKeyID = -64,
    /* 不是签名证书 */
    NetcaErrorCodeNotSignCert = -65,
    /* 不是加密证书 */
    NetcaErrorCodeNotEncCert = -66,
    /* 错误的属性的编码 */
    NetcaErrorCodeBadAttribute = -67,
    /* SignedData签名进行Hash运算失败 */
    NetcaErrorCodeSignedDataHashFail = -68,
    /* SignedData签名进行签名运算失败 */
    NetcaErrorCodeSignedDataSignFail = -69,
    /* SignedData签名进行编码失败 */
    NetcaErrorCodeSignedDataEncodeFail = -70,
    /* SignedData签名创建SID失败 */
    NetcaErrorCodeSignedDataCreateSIDFail = -71,
    /* SignedData签名追加时间戳失败 */
    NetcaErrorCodeSignedDataAddSignAtureTimestampFail = -72,
    /* 获取时间戳失败 */
    NetcaErrorCodeGetTimestampFail = -73,
    /* 连接服务器失败 */
    NetcaErrorCodeConnectFail = -74,
    /* HTTP失败 */
    NetcaErrorCodeHTTPFail = -75,
    /* LDAP失败 */
    NetcaErrorCodeLDAPFail = -76,
    /* 获取公钥失败 */
    NetcaErrorCodeGetPublicKeyFail = -78,
    /* 转化为国密DER编码的SM2密文失败 */
    NetcaErrorCodeToDerSM2CipherFail = -79,
    /* 错误的国密DER编码的SM2密文 */
    NetcaErrorCodeBadDerSM2Cipher = -80,
    /* 获取密钥对失败 */
    NetcaErrorCodeGetKeyPairFail = -81,
    /* 不可接受的数字信封对称加密算法 */
    NetcaErrorCodeEnvelopedDataUnacceptableEncAlgo = -82,
    /* 数字信封ContentInfo不匹配 */
    NetcaErrorCodeEnvelopedDataOuterContentInfoNotMatch = -83,
    /* SignedData的原文不匹配 */
    NetcaErrorCodeSignedDataTBSNotMatch = -84,
    /* SignedData的签名证书不匹配 */
    NetcaErrorCodeSignedDataSignedCertNotMatch = -85,
    /* 不可接受的SignedData签名算法 */
    NetcaErrorCodeSignedDataUnacceptableSignAlgo = -86,
    /* SignedData的ContentInfo不匹配 */
    NetcaErrorCodeSignedDataOuterContentInfoNotMatch = -87,
    /* 不可接受的SigningCert属性 */
    NetcaErrorCodeSignedDataUnacceptableSigningCertAttribute = -88,
    /* 没有时间戳的配置 */
    NetcaErrorCodeNO_TimestampConfig = -89,
    /* 不可接受的时间戳Hash算法 */
    NetcaErrorCodeTimestampUnacceptableHashAlgo = -90,
    /* 不可接受的时间戳策略 */
    NetcaErrorCodeTimestampUnacceptablePolicy = -91,
    /* 没有输入密码 */
    NetcaErrorCodeNoPin = -92,
    /* 错误的设备ID */
    NetcaErrorCodeBadDeviceID = -93,
    /* 不可接受的签名时间戳 */
    NetcaErrorCodeSignedDataUnacceptableSignatureTimestamp = -94,
    /* 需要输入更多的数据，否则无法判断  */
    NetcaErrorCodeNEED_MoreData = -95,
    /* 验证RSA PSS参数失败  */
    NetcaErrorCodeVerifyPSSParamFail = -97,
    /* 验证TLS服务器证书失败 */
    NetcaErrorCodeBadTLSCert = -98,
    /* 既没有ATS_HASH_INDEX属性也没有ATS_HASH_INDEX_V3属性 */
    NetcaErrorCodeNoATSHashIndex = -99,
    /* b64头冲突 */
    NetcaErrorCodeB64HeaderConflict = -136,
    /* 禁止使用初始的用户密码 */
    NetcaErrorCodeForbidInitUserPin = -137,
    /* 应用密码错误 */
    NetcaErrorCodeAppPinError = 0x10000,
    /* 错误的设备类型 */
    NetcaErrorCodeBadDeviceType = 0x20002,
    /* 索引值超出了范围 */
    NetcaErrorCodeOutOfRange = 0x20003,
    /* 加锁失败 */
    NetcaErrorCodeLockFail = 0x20008,
    /* 解锁失败 */
    NetcaErrorCodeUnlockFail = 0x20009,
    /* 获取密钥对数目失败 */
    NetcaErrorCodeGetKeyPairCountFail = 0x2000A,
    /* 获取密钥对失败 */
    NetcaErrorCodeGetKeyPairsFail = 0x2000B,
    /* 错误的SubjectPublicKeyInfo的编码 */
    NetcaErrorCodeBadSubjectPubKeyInfo = 0x2000C,
    /* 错误的公钥证书的编码 */
    NetcaErrorCodeBadCertEncode = 0x2000D,
    /* 错误的公钥证书使用目的 */
    NetcaErrorCodeBadCertPurpose = 0x2000E,
    /* 部分的公钥 */
    NetcaErrorCodePartCertPublicKey = 0x2000F,
    /* 没有时间戳 */
    NetcaErrorCodenoTimestamp = 0x20014,
    /* 时间戳的Hash值不匹配 */
    NetcaErrorCodeTimestampHashNotMatch = 0x20016,
    /* 不是字符串类型的扩展 */
    NetcaErrorCodeNotStringTypeExt = 0x20017,
    /* 字符串类型的扩展编码错误 */
    NetcaErrorCodeBadStringExtEncode = 0x20018,
    /* LDAP条目超出限制，但返回了数据 */
    NetcaErrorCodeLDAPSizeLimitExceeded = 0x20019,
    /* LDAP超时，但返回了数据 */
    NetcaErrorCodeLDAPTimeLimitExceeded = 0x2001A,
    /* 注册公钥需要身份认证 */
    NetecaErrorCodeRegPubkeyMustAuth = 0x30000,
    /* 已经初始化过*/
    NetcaErrorCodeDeviceAlreadyInitialize = 0x30001,
    /* 公钥已经注册过*/
    NetcaErrorCodePubkeyAlreadyReg = 0x30002,
    /* HTTPS证书验证失败*/
    NetcaErrorCodeHttpsCertVerifyFail = 0x30003,
    /* 密钥服务器签名证书验证失败 */
    NetcaErrorCodeKeypairServerCertVerifyFail = 0x30004,
    /* 证书扩展密钥用法错误 */
    NetcaErrorCodeCertExtKeyUsageError = 0x30005,
    /* 证书密钥用法错误 */
    NetcaErrorCodeCertKeyUsageError = 0x30006,
    
#pragma mark - 自定义错误码
    /* APPID为空 */
    NetcaErrorCodeAppIDNull = 0x80000004,
    /* 签名内容为空 */
    NetcaErrorCodeSignDataNull = 0x80000006,
    /* openurl失败 */
    NetcaErrorCodeOpenURLFail = 0x80000007,
    /* 返回结果有误 */
    NetcaErrorCodeResultResolveFail = 0x80000008,
    /* 获取签名内容失败 */
    NetcaErrorCodeGetSignDataFail = 0x80000009,
    /* 验证码有误 */
    NetcaErrorCodeAuthCodeError = 0x8000000A,
    /* 网络错误 */
    NetcaErrorCodeNetworkError = 0x8000000B,
    /* 签名算法有误 */
    NetcaErrorCodeSignAlgError = 0x8000000C,
    /* 生成X509证书对象失败 */
    NetcaErrorCodeGenerateX509Fail = 0x8000000D,
    /* 无可用证书 */
    NetcaErrorCodeNoAvailableCert = 0x80000011,
    /* 设备配置信息有误 */
    NetcaErrorCodeDeviceConfigInfoError = 0x80000012,
    /* 设备配置信息为空 */
    NetcaErrorCodeConfigInfoNULL = 0x80000013,
    /* 口令管理系统服务器地址为空 */
    NetcaErrorCodePINManageSystemUrlNULL = 0x80000014,
    /* 二维码内容有误 */
    NetcaErrorCodeQrCodeContentError = 0x80000015,
};

/**
 获取详细的错误信息

 @return 返回错误码对应的错误信息
 */
NSString *errMsgOfCode(long long code);
