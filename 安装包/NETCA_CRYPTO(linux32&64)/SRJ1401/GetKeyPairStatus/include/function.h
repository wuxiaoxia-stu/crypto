#ifndef _FUNCTION_INLCUDE_H_
#define _FUNCTION_INLCUDE_H_


#ifdef __cplusplus
extern "C" {
#endif

#define SDR_OK                                                      0x0								/*操作成功*/
#define SDR_BASE                                                  0x01000000					/*错误码基础值*/
#define SDR_UNKNOWERR                                 (SDR_BASE + 0x00000001)		/*未知错误*/
#define SDR_NOTSUPPORT                                  (SDR_BASE + 0x00000002)		/*不支持的接口调用*/
#define SDR_COMMFAIL                                       (SDR_BASE + 0x00000003)		/*与设备通信失败*/
#define SDR_HARDFAIL                                         (SDR_BASE + 0x00000004)		/*运算模块无响应*/
#define SDR_OPENDEVICE                                   (SDR_BASE + 0x00000005)		/*打开设备失败*/
#define SDR_OPENSESSION                                 (SDR_BASE + 0x00000006)		/*创建会话失败*/
#define SDR_PARDENY                                          (SDR_BASE + 0x00000007)		/*无私钥使用权限*/
#define SDR_KEYNOTEXIST                                (SDR_BASE + 0x00000008)		/*不存在的密钥调用*/
#define SDR_ALGNOTSUPPORT                          (SDR_BASE + 0x00000009)		/*不支持的算法调用*/
#define SDR_ALGMODNOTSUPPORT                (SDR_BASE + 0x0000000A)		/*不支持的算法模式调用*/
#define SDR_PKOPERR                                         (SDR_BASE + 0x0000000B)		/*公钥运算失败*/
#define SDR_SKOPERR                                         (SDR_BASE + 0x0000000C)		/*私钥运算失败*/
#define SDR_SIGNERR                                           (SDR_BASE + 0x0000000D)		/*签名运算失败*/
#define SDR_VERIFYERR                                      (SDR_BASE + 0x0000000E)		/*验证签名失败*/
#define SDR_SYMOPERR                                      (SDR_BASE + 0x0000000F)		/*对称算法运算失败*/
#define SDR_STEPERR                                          (SDR_BASE + 0x00000010)		/*多步运算步骤错误*/
#define SDR_FILESIZEERR                                   (SDR_BASE + 0x00000011)		/*文件长度超出限制*/
#define SDR_FILENOEXIST                                  (SDR_BASE + 0x00000012)		/*指定的文件不存在*/
#define SDR_FILEOFSERR                                    (SDR_BASE + 0x00000013)		/*文件起始位置错误*/
#define SDR_KEYTYPEERR                                  (SDR_BASE + 0x00000014)		/*密钥类型错误*/
#define SDR_KEYERR                                            (SDR_BASE + 0x00000015)		/*密钥错误*/
#define SDR_ENCDATAERR                                  (SDR_BASE + 0x00000016)		/*ECC加密数据错误*/


#define SDR_HANDLE_CLOSED						(SDR_BASE + 0x0000001F)		/*函数执行过程中，该会话已经关闭*/
#define SDR_HANDLE_COUNT						(SDR_BASE + 0x00000020)		/*打开的会话太多*/
#define SDR_HANDLE_INVALID						(SDR_BASE + 0x00000021)		/*指定的会话句柄无效*/
#define SDR_LOGIN_FAILED							(SDR_BASE + 0x00000022)		/*获取私钥使用权限失败*/
#define SDR_LOGIN_REPEAT							(SDR_BASE + 0x00000023)		/*获取私钥使用权限重复*/
#define SDR_NOT_LOGIN                                 (SDR_BASE + 0x00000024)		/*私钥使用权限未获取*/
#define SDR_INPUT_LEN_ERROR					(SDR_BASE + 0x00000025)		/*输入参数长度指示错误*/
#define SDR_KEYID_INVALID							(SDR_BASE + 0x00000026)		/*指定的密钥号非法*/
#define SDR_MECHANISM_INVALID				(SDR_BASE + 0x00000027)		/*机制无效*/
#define SDR_NOT_INITIALIZED						(SDR_BASE + 0x00000028)		/*未调用初始化*/
#define SDR_ALREADY_INITIALIZED			(SDR_BASE + 0x00000029)		/*初始化已调用*/
#define SDR_DEVICEHANDLE_INVALID		(SDR_BASE + 0x0000002A)		/*设备句柄无效*/
#define SDR_DEVICE_ERROR							(SDR_BASE + 0x0000002B)
#define SDR_KEY_MEM_FULL						(SDR_BASE + 0x0000002C)
#define SDR_KEY_GEN_FAIL							(SDR_BASE + 0x0000002D)		/*产生密钥失败*/
#define SDR_FILE_OPR_ERR							(SDR_BASE + 0x0000002E)
#define SDR_KEY_NO_EXIST							(SDR_BASE + 0x0000002F)
#define SDR_MALLOC_ERR                            (SDR_BASE + 0x00000030)
#define SDR_DATA_INVALID							(SDR_BASE + 0x00000031)
#define SDR_SM2_KEYBITS                             (SDR_BASE + 0x00000032)
#define SDR_SESSION_INIT                             (SDR_BASE + 0x00000033)
#define SDR_RANDOM_GEN							(SDR_BASE + 0x00000034)		/*产生随机数*/
#define SDR_KEYPAIR_LENGTH                     (SDR_BASE + 0x00000035)		/*非对称密钥的指数长度*/
#define SDR_PADDING_RSA							(SDR_BASE + 0x00000036)		/*RSA padding 错误*/
#define SDR_UNPADDING_RSA						(SDR_BASE + 0x00000037)		/*RSA unpadding 错误*/
#define SDR_HANDLE_SYMKEY_INVALID	(SDR_BASE + 0x00000038)		/*会话密钥句柄无效*/
#define SDR_READ_INI_ERR							(SDR_BASE + 0x00000039)		/*读取配置文件失败*/
#define SDR_HEADBEAT_TEST_ERR				(SDR_BASE + 0x00000040)		/*连接密码机心跳测试失败*/
#define SDR_DATA_TRANS_ERR                    (SDR_BASE + 0x00000041)		/*数据传输错误*/

#define SDR_DATA_DEVINFO_ERR					(SDR_BASE + 0x00000042)		/*设备信息获取失败*/
#define SDR_DATA_GEN_RANDOM_ERR        (SDR_BASE + 0x00000043)		/*随机数生成失败*/
#define SDR_DATA_INDEX_OUT_ERR              (SDR_BASE + 0x00000044)		/*索引超出范围*/
#define SDR_HANDLE_INPUT_INVALID			(SDR_BASE + 0x00000045)		/*输入的句柄无效*/
#define SDR_DATA_PRI_ACCESS_ERR             (SDR_BASE + 0x00000046)		/*获取内部私钥权限失败*/
#define SDR_DATA_EXP_PUBKEY_ERR			(SDR_BASE + 0x00000047)		/*导出公钥失败*/
#define SDR_DATA_GEN_SESKEY_ERR			(SDR_BASE + 0x00000048)		/*生成会话密钥失败*/
#define SDR_DATA_DIGI_ENEV_ERR				(SDR_BASE + 0x00000049)		/*数字信封转换失败*/
#define SDR_DATA_GEN_AGREE_KEY_ERR	(SDR_BASE + 0x00000050)		/*生成协商密钥失败*/
#define SDR_DATA_IM_RSA_KEY_ERR			(SDR_BASE + 0x00000051)		/*导入RSA密钥对失败*/
#define SDR_DATA_IM_ECC_KEY_ERR			(SDR_BASE + 0x00000052)		/*导入ECC密钥对失败*/
#define SDR_DATA_IM_ECC_ENC_ERR			(SDR_BASE + 0x00000053)		/*ECC公钥加密失败*/
#define SDR_DATA_IV_SYM_ERR                      (SDR_BASE + 0x00000054)		/*IV数据错误*/
#define SDR_DATA_HASH_INIT_ERR                (SDR_BASE + 0x00000055)		/*杂凑运算初始化失败*/
#define SDR_DATA_HASH_OP_ERR                   (SDR_BASE + 0x00000056)		/*杂凑运算失败*/
#define SDR_DATA_CREATE_FILE_ERR			(SDR_BASE + 0x00000057)		/*创建文件失败*/
#define SDR_DATA_DELETE_FILE_ERR			(SDR_BASE + 0x00000058)		/*删除文件失败*/


#define SGD_SM1_ECB				0x00000101		/*SM1算法ECB加密模式*/
#define SGD_SM1_CBC				0x00000102		/*SM1算法CBC加密模式*/
#define SGD_SM1_CFB				0x00000104		/*SM1算法CFB加密模式*/
#define SGD_SM1_OFB				0x00000108		/*SM1算法OFB加密模式*/
#define SGD_SM1_MAC				0x00000110		/*SM1算法MAC运算*/
#define SGD_SSF33_ECB				0x00000201		/*SSF33算法ECB加密模式*/
#define SGD_SSF33_CBC				0x00000202		/*SSF33算法CBC加密模式*/
#define SGD_SSF33_CFB				0x00000204		/*SSF33算法CFB加密模式*/
#define SGD_SSF33_OFB				0x00000208		/*SSF33算法OFB加密模式*/
#define SGD_SSF33_MAC			0x00000210		/*SSF33算法MAC运算*/
#define SGD_SMS4_ECB				0x00000401		/*SMS4算法ECB加密模式*/
#define SGD_SMS4_CBC				0x00000402		/*SMS4算法CBC加密模式*/
#define SGD_SMS4_CFB				0x00000404		/*SMS4算法CFB加密模式*/
#define SGD_SMS4_OFB				0x00000408		/*SMS4算法OFB加密模式*/
#define SGD_SMS4_MAC				0x00000410		/*SMS4算法MAC运算*/


#define SGD_RSA							0x00010000		/*RSA算法*/
#define SGD_SM2_1						0x00020100		/*椭圆曲线签名算法*/
#define SGD_SM2_2						0x00020200		/*椭圆曲线密钥交换协议*/
#define SGD_SM2_3						0x00020400		/*椭圆曲线加密算法*/


#define SGD_SM3							0x00000001		/*SM3杂凑算法*/
#define SGD_SHA1						0x00000002		/*SHA_1杂凑算法*/
#define SGD_SHA256					0x00000004		/*SHA_256杂凑算法*/


#define DEVICEAPI


//设备信息定义
typedef struct DeviceInfo_st{
unsigned char IssuerName[40];
unsigned char DeviceName[16];
unsigned char DeviceSerial[16];
unsigned int  DeviceVersion;
unsigned int  StandardVersion;
unsigned int  AsymAlgAbility[2];
unsigned int  SymAlgAbility;
unsigned int  HashAlgAbility;
unsigned int  BufferSize;
}DEVICEINFO;

//RSA密钥数据结构定义
#define RSAref_MAX_BITS    2048
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)
typedef struct RSArefPublicKey_st
{
unsigned int  bits;
unsigned char m[RSAref_MAX_LEN];
unsigned char e[RSAref_MAX_LEN];
} RSArefPublicKey;

typedef struct RSArefPrivateKey_st
{
unsigned int  bits;
unsigned char m[RSAref_MAX_LEN];
unsigned char e[RSAref_MAX_LEN];
unsigned char d[RSAref_MAX_LEN];
unsigned char prime[2][RSAref_MAX_PLEN];
unsigned char pexp[2][RSAref_MAX_PLEN];
unsigned char coef[RSAref_MAX_PLEN];
} RSArefPrivateKey;

//ECC密钥数据结构定义
#define ECCref_MAX_BITS			512 
#define ECCref_MAX_LEN			((ECCref_MAX_BITS+7) / 8)
typedef struct ECCrefPublicKey_st
{
	unsigned int  bits;
	unsigned char x[ECCref_MAX_LEN]; 
	unsigned char y[ECCref_MAX_LEN]; 
} ECCrefPublicKey;

typedef struct ECCrefPrivateKey_st
{
    unsigned int  bits;
    unsigned char K[ECCref_MAX_LEN];
} ECCrefPrivateKey;

#define ECCCipher_MAX_C_LEN  4096
typedef struct ECCCipher_st
{
	unsigned char x[ECCref_MAX_LEN]; 
	unsigned char y[ECCref_MAX_LEN]; 
    unsigned char M[32];
	unsigned int L;
	unsigned char C[ECCCipher_MAX_C_LEN];
} ECCCipher;

//ECC签名数据结构定义
typedef struct ECCSignature_st
{
	unsigned char r[ECCref_MAX_LEN];	
	unsigned char s[ECCref_MAX_LEN];	
} ECCSignature;


/* 打开密码设备 */
typedef int (DEVICEAPI *SDF_OpenDevice_Ptr)(void **phDeviceHandle);
/* 关闭密码设备，并释放相关资源 */
typedef int (DEVICEAPI *SDF_CloseDevice_Ptr)(void *hDeviceHandle);
/* 创建与密码设备的会话 */
typedef int (DEVICEAPI *SDF_OpenSession_Ptr)(void *hDeviceHandle, void **phSessionHandle);
/* 关闭与密码设备已建立的会话，并释放相关资源 */
typedef int (DEVICEAPI *SDF_CloseSession_Ptr)(void *hSessionHandle);
/* 获取密码设备能力描述 */
typedef int (DEVICEAPI *SDF_GetDeviceInfo_Ptr)(void *hSessionHandle,DEVICEINFO *pstDeviceInfo);
/* 获取指定长度的随机数 */
typedef int (DEVICEAPI *SDF_GenerateRandom_Ptr)(void *hSessionHandle, unsigned int  uiLength,unsigned char *pucRandom);
/* 获取密码设备内部存储的指定索引私钥的使用权 */
typedef int (DEVICEAPI *SDF_GetPrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,unsigned char *pucPassword,unsigned int  uiPwdLength);
/* 释放密码设备存储的指定索引私钥的使用授权 */
typedef int (DEVICEAPI *SDF_ReleasePrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex);
/* 导出密码设备内部存储的指定索引位置的签名公钥 */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* 导出密码设备内部存储的指定索引位置的加密公钥 */
typedef int  (DEVICEAPI *SDF_ExportEncPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* 请求密码设备产生指定模长的RSA密钥对 */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyBits,RSArefPublicKey *pucPublicKey,RSArefPrivateKey *pucPrivateKey);

/* 导出密码设备内部存储的指定索引位置的签名公钥 */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* 导出密码设备内部存储的指定索引位置的加密公钥 */
typedef int (DEVICEAPI *SDF_ExportEncPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* 请求密码设备产生指定类型和模长的ECC密钥对 */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_ECC_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int  uiKeyBits,ECCrefPublicKey *pucPublicKey,ECCrefPrivateKey *pucPrivateKey);

/* 导入明文会话密钥，同时返回密钥句柄*/
typedef int (DEVICEAPI *SDF_ImportKey_Ptr)(void *hSessionHandle,unsigned char *pucKey, unsigned int uiKeyLength,void **phKeyHandle);
/* 销毁会话密钥，并释放为密钥句柄分配的内存等资源。*/
typedef int (DEVICEAPI *SDF_DestroyKey_Ptr)(void *hSessionHandle,void *hKeyHandle);

typedef int(DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle, unsigned int  uiISKIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLengt);
/* 使用内部ECC私钥对数据进行签名运算 */
typedef int (DEVICEAPI *SDF_InternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);

/* 使用指定的密钥句柄和IV对数据进行对称加密运算 */
typedef int (DEVICEAPI *SDF_Encrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucEncData,unsigned int  *puiEncDataLength);
/* 使用指定的密钥句柄和IV对数据进行对称解密运算 */
typedef int (DEVICEAPI *SDF_Decrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucEncData,unsigned int  uiEncDataLength,unsigned char *pucData,unsigned int *puiDataLength);


/* 三步式数据杂凑运算第一步。*/
typedef int (DEVICEAPI *SDF_HashInit_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucID,unsigned int uiIDLength);
/* 三步式数据杂凑运算第二步，对输入的明文进行杂凑运算 */
typedef int (DEVICEAPI *SDF_HashUpdate_Ptr)(void *hSessionHandle,unsigned char *pucData,unsigned int  uiDataLength);
/* 三步式数据杂凑运算第三步，杂凑运算结束返回杂凑数据并清除中间数据 */
typedef int (DEVICEAPI *SDF_HashFinal_Ptr)(void *hSessionHandle,unsigned char *pucHash,unsigned int  *puiHashLength);



#ifdef __cplusplus
}
#endif

#endif
