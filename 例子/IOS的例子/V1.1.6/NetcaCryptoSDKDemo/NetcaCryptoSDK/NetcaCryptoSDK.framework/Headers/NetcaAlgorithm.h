//
//  NetcaAlgorithm.h
//  NetcaKeyXSDK
//
//  Created by KeyX on 2018/4/9.
//  Copyright © 2018年 Netca. All rights reserved.
//

/* Hash 算法 */
typedef NS_ENUM(NSUInteger, NetcaHashAlgorithm) {
    NetcaHashAlgorithmMD5 = 0x1000,
    NetcaHashAlgorithmSHA1 = 0x2000,
    NetcaHashAlgorithmSHA224 = 0x3000,
    NetcaHashAlgorithmSHA256 = 0x4000,
    NetcaHashAlgorithmSHA384 = 0x5000,
    NetcaHashAlgorithmSHA512 = 0x6000,
    NetcaHashAlgorithmSM3 = 0x7000
};

/* 密钥对算法 */
typedef NS_ENUM(NSUInteger, NetcaKeyPairAlgorithm) {
    NetcaKeyPairAlgorithmRSA = 1,
    NetcaKeyPairAlgorithmDSA = 2,
    NetcaKeyPairAlgorithmDH = 3,
    NetcaKeyPairAlgorithmECC = 4
};

/* 非对称加密算法 */
typedef NS_ENUM(NSUInteger, NetcaEncryptAlgorithm) {
    NetcaEncryptAlgorithm_RSA_PKCS1_V1_5_ENC = 0x10,
    NetcaEncryptAlgorithm_RSA_PKCS1_OAEP = 0x20,
    NetcaEncryptAlgorithm_RSA_RAW_ENC = 0x30,
    NetcaEncryptAlgorithm_SM2_ENC = 0x40,
    NetcaEncryptAlgorithm_ECIES = 0x50
};

/* 对称加密算法 */
typedef NS_ENUM(NSUInteger, NetcaCipherAlgorithm) {
    NetcaCipherAlgorithmDES_ECB = 0x400000,
    NetcaCipherAlgorithmDES_CBC = 0x800000,
    NetcaCipherAlgorithm3DES_ECB = 0xC00000,
    NetcaCipherAlgorithm3DES_CBC = 0x1000000,
    NetcaCipherAlgorithm3DES_CTR = 0x1400000,
    NetcaCipherAlgorithmARC4 = 0x1800000,
    NetcaCipherAlgorithmRC2_ECB = 0x1C00000,
    NetcaCipherAlgorithmRC2_CBC = 0x2000000,
    NetcaCipherAlgorithmAES_ECB = 0x2400000,
    NetcaCipherAlgorithmAES_CBC = 0x2800000,
    NetcaCipherAlgorithmAES_CTR = 0x2C00000,
    NetcaCipherAlgorithmSSF33_ECB = 0x3000000,
    NetcaCipherAlgorithmSSF33_CBC = 0x3400000,
    NetcaCipherAlgorithmSSF33_CTR = 0x3800000,
    NetcaCipherAlgorithmSM1_ECB = 0x3C00000,
    NetcaCipherAlgorithmSM1_CBC = 0x4000000,
    NetcaCipherAlgorithmSM1_CTR = 0x4400000,
    NetcaCipherAlgorithmSM4_ECB = 0x4800000,
    NetcaCipherAlgorithmSM4_CBC = 0x4C00000,
    NetcaCipherAlgorithmSM4_CTR = 0x5000000,
    NetcaCipherAlgorithmSM1_ECB_MOD = 0x5400000,
    NetcaCipherAlgorithmZUC = 0x5800000,
    NetcaCipherAlgorithmZUC_BASE = 0x5C00000,
    NetcaCipherAlgorithmAES_CCM = 0x6000000,
    NetcaCipherAlgorithmSM4_CCM = 0x6400000,
    NetcaCipherAlgorithmAES_GCM = 0x6800000,
    NetcaCipherAlgorithmAES_XTS = 0x6C00000
};

/* 对称加密算法 */
typedef NS_ENUM(NSUInteger, NetcaEnvelopedDataAlgorithm) {
    NetcaEnvelopedDataAlgorithmDESCBC = 1,
    NetcaEnvelopedDataAlgorithmRC2CBC = 2,
    NetcaEnvelopedDataAlgorithmTDESCBC = 3,
    NetcaEnvelopedDataAlgorithmAES128CBC = 4,
    NetcaEnvelopedDataAlgorithmAES192CBC = 5,
    NetcaEnvelopedDataAlgorithmAES256CBC = 6,
    NetcaEnvelopedDataAlgorithmSSF33CBC = 7,
    NetcaEnvelopedDataAlgorithmSM1CBC = 8,
    NetcaEnvelopedDataAlgorithmSM4CBC = 9,
    NetcaEnvelopedDataAlgorithmRC4 = 10
};

/* 签名算法 */
typedef NS_ENUM(NSUInteger, NetcaSignAlgorithm) {
    NetcaSignAlgorithmMD5WithRSA = 1,
    NetcaSignAlgorithmSHA1WithRSA = 2,
    NetcaSignAlgorithmSHA224WithRSA = 3,
    NetcaSignAlgorithmSHA256WithRSA = 4,
    NetcaSignAlgorithmSHA384WithRSA = 5,
    NetcaSignAlgorithmSHA512WithRSA = 6,
    NetcaSignAlgorithmMD5WithRSANOHASHID = 7,
    NetcaSignAlgorithmSHA1WithRSANOHASHID = 8,
    NetcaSignAlgorithmSHA224WithRSANOHASHID = 9,
    NetcaSignAlgorithmSHA256WithRSANOHASHID = 10,
    NetcaSignAlgorithmSHA384WithRSANOHASHID = 11,
    NetcaSignAlgorithmSHA512WithRSANOHASHID = 12,
    NetcaSignAlgorithmDSAWithSHA1 = 13,
    NetcaSignAlgorithmDSAWithSHA224 = 14,
    NetcaSignAlgorithmDSAWithSHA256 = 15,
    NetcaSignAlgorithmECDSAWithSHA1 = 16,
    NetcaSignAlgorithmECDSAWithSHA224 = 17,
    NetcaSignAlgorithmECDSAWithSHA256 = 18,
    NetcaSignAlgorithmECDSAWithSHA384 = 19,
    NetcaSignAlgorithmECDSAWithSHA512 = 20,
    NetcaSignAlgorithmSSLRSA = 21,
    NetcaSignAlgorithmSM3WithSM2 = 25,
    NetcaSignAlgorithmSHA1WithSM2 = 26,
    NetcaSignAlgorithmSHA224WithSM2 = 27,
    NetcaSignAlgorithmSHA256WithSM2 = 28,
    NetcaSignAlgorithmSHA384WithSM2 = 29,
    NetcaSignAlgorithmSHA512WithSM2 = 30,
    NetcaSignAlgorithmSM3WithRSA = 31
};
