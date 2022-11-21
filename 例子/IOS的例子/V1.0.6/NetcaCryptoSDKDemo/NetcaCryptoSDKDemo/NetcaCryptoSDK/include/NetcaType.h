//
//  NetcaType.h
//  NetcaKeyXSDK
//
//  Created by KeyX on 2018/4/9.
//  Copyright © 2018年 Netca. All rights reserved.
//

/* ECC椭圆曲线号 */
typedef NS_ENUM(NSUInteger, NetcaECCCurveType) {
    NetcaECCCurveTypeP192 = 1,
    NetcaECCCurveTypeP224 = 2,
    NetcaECCCurveTypeP256 = 3,
    NetcaECCCurveTypeP384 = 4,
    NetcaECCCurveTypeP521 = 5,
    NetcaECCCurveTypeWAPI = 6,
    NetcaECCCurveTypeSM2 = 7,
};

/* 证书验证标志 */
typedef NS_ENUM(NSUInteger, NetcaCertStatusFlag) {
    /* 验证证书是否作废 */
    NetcaCertStatusFlagVerifyRevoke = 1,
    /* 在线验证证书 */
    NetcaCertStatusFlagVerifyOnline = 2,
    /* 验证CA的证书是否作废 */
    NetcaCertStatusFlagVerifyCACertRevoke = 4,
    /* 使用OCSP来验证 */
    NetcaCertStatusFlagVerifyOCSP = 0x10,
    /* 使用CRL来验证 */
    NetcaCertStatusFlagVerifyCRL = 0x20
};

/* 证书状态 */
typedef NS_ENUM(NSInteger, NetcaCertStatus) {
    /* 证书未作废 */
    NetcaCertStatusUnrevoked = 1,
    /* 证书的状态不确定 */
    NetcaCertStatusUndetermined = -1,
    /* 证书已经作废 */
    NetcaCertStatusRevoked = 0,
    /* CA证书已经作废 */
    NetcaCertStatusCA_Revoked = -2
};

/* 证书吊销原因 */
typedef NS_ENUM(NSUInteger, NetcaCertRevokeReason) {
    /* 未指定 */
    NetcaCertRevokeReasonUnspecified = 0,
    /* 密钥泄漏 */
    NetcaCertRevokeReasonKeyCompromise = 1,
    /* 证书是CA证书，其密钥泄漏 */
    NetcaCertRevokeReasonCACompromise = 2,
    /* 附属关系改变 */
    NetcaCertRevokeReasonAffiliationChanged = 3,
    /* 被取代 */
    NetcaCertRevokeReasonSuperseded = 4,
    /* 停止操作 */
    NetcaCertRevokeReasonCessationOfOperation = 5,
    /* 挂失，临时的作废 */
    NetcaCertRevokeReasonCertifateHold = 6,
    /* 特权作废 */
    NetcaCertRevokeReasonPrivilegeWithdrawn = 9,
    /* 证书是属性权威机构，其密钥泄漏 */
    NetcaCertRevokeReasonAACompromise = 10
};

/* 选择证书类型 */
typedef NS_ENUM(NSUInteger, NetcaCertificateType) {
    /* 自定义选择条件 */
    NetcaCertificateTypeUsingCustomConfig = 0,
    /* 选择签名证书 */
    NetcaCertificateTypeSignature = 1,
    /* 选择加密证书 */
    NetcaCertificateTypeEncrypt = 2,
    /* 选择解密证书 */
    NetcaCertificateTypeDecrypt = 3,
    /* 选择设备证书 */
    NetcaCertificateTypeDevice = 4
};

/* 设备类型 */
typedef NS_ENUM(NSUInteger, NetcaDeviceType) {
    /* 文件型设备 */
    NetcaDeviceTypeSoftDevice = 52
};

/* SignedData包含证书的选项 */
typedef NS_ENUM(NSUInteger, NetcaSignedDataIncludeCertOption) {
    /* 不包含签名证书 */
    NetcaSignedDataIncludeCertOptionNone = 1,
    /* 包含签名证书 */
    NetcaSignedDataIncludeCertOptionSelf = 2,
    /* 包含签名证书和可能的证书链，但不包含根证书 */
    NetcaSignedDataIncludeCertOptionCertPath = 3,
    /* 包含签名证书和可能的证书链 */
    NetcaSignedDataIncludeCertOptionCertPathWithRoot = 4
};

/* 密钥用法 */
typedef NS_ENUM(NSUInteger, NetcaKeyUsage) {
    /* 数字签名 */
    NetcaKeyUsageDigitalSignature = 1,
    /* 不可否认 */
    NetcaKeyUsageNonRepudiation = 2,
    /* 同NetcaKeyUsageNonRepudiation */
    NetcaKeyUsageContentCommitment = 2,
    /* 加密密钥 */
    NetcaKeyUsageKeyEncipherment = 4,
    /* 加密数据 */
    NetcaKeyUsageDataEncipherment = 8,
    /* 密钥协商 */
    NetcaKeyUsageKeyAgreement = 16,
    /* 签证书 */
    NetcaKeyUsageKeyCertSign = 32,
    /* 签CRL */
    NetcaKeyUsageCrlSign = 64,
    /* 密钥协商时，仅加密 */
    NetcaKeyUsageEncipherOnly = 128,
    /* 密钥协商时，仅解密 */
    NetcaKeyUsageDecipherOnly = 256
};

