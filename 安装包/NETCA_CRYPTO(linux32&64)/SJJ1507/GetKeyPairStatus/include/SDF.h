/*----------------------------------------------------------------------|
|	SDF.h -   The header file of SDF.c 									
|	Version :     1.0												
|	Author:       by wyf.								
| Description:  密码设备应用函数头文件，根据国密规范定义。
|               参见《GM/T 0018 密码设备应用接口规范》
|
|	Copyright :   Beijing JN TASS Technology Co., Ltd.				
|	data:         2014-5-9. Create										            
|-----------------------------------------------------------------------|
|	Modify History:
|----------------------------------------------------------------------*/
#ifndef _TASS_SDF_H_
#define _TASS_SDF_H_
 
#ifdef UNIX
#define SDFAPI
#else
#define SDFAPI _declspec (dllexport)
#endif

/****************************************
 * NETCA 宏用于广东网证通定制的两个接口
 * SDF_InternalPrivateKeyOperation_RSA_EX
 * SDF_InternalDecrypt_ECC
 * 修改SDF_GetPrivateKeyAccessRight函数为国密函数
*/
#define NETCA

// API允许打开的最大会话个数
#define MAX_SESSIONS     2048   

// 对称算法机制

#define SGD_SM1_ECB	     0x00000101	// SM1算法ECB加密模式
#define SGD_SM1_CBC	     0x00000102	// SM1算法CBC加密模式
#define SGD_SM1_CFB	     0x00000104	// SM1算法CFB加密模式
#define SGD_SM1_OFB	     0x00000108	// SM1算法OFB加密模式
#define SGD_SM1_MAC	     0x00000110	// SM1算法MAC算法
#define SGD_SSF33_ECB    0x00000201	// SSF33算法ECB加密模式
#define SGD_SSF33_CBC    0x00000202	// SSF33算法CBC加密模式
#define SGD_SSF33_CFB    0x00000204	// SSF33算法CFB加密模式
#define SGD_SSF33_OFB    0x00000208	// SSF33算法OFB加密模式
#define SGD_SSF33_MAC    0x00000210	// SSF33算法MAC算法
#define SGD_SM4_ECB	     0x00000401	// SM4算法ECB加密模式
#define SGD_SM4_CBC	     0x00000402	// SM4算法CBC加密模式
#define SGD_SM4_CFB	     0x00000404	// SM4算法CFB加密模式
#define SGD_SM4_OFB	     0x00000408	// SM4算法OFB加密模式
#define SGD_SM4_MAC	     0x00000410	// SM4算法MAC算法

#define SGD_ZUC_EEA3     0x00000801	// ZUC祖冲之加解密算法128-EEA3
#define SGD_ZUC_EIA3     0x00000802	// ZUC祖冲之MAC算法128-EIA3
#define SGD_RC4_STREAM   0x00000804 //RC4算法

// 非对称算法机制
#define SGD_RSA          0x00010000	// RSA算法 

/*外加机制*/
#define SGD_RSA_SIGN_EX	 0x00010001  //导入或导出RSA签名或验证密钥时使用
#define SGD_RSA_ENC_EX   0x00010002  //导入或导出RSA加密或解密密钥时使用

#define SGD_SM2	         0x00020100	// SM2椭圆曲线密码算法


#define SGD_SM2_1        0x00020200	// SM2椭圆曲线签名算法
#define SGD_SM2_2        0x00020400	// SM2椭圆曲线密钥交换协议
#define SGD_SM2_3        0x00020800	// SM2椭圆曲线加密算法

// 摘要算法
#define SGD_SM3	         0x00000001	// SM3杂凑算法 SM3-256
#define SGD_SHA1         0x00000002	// SHA_1杂凑算法
#define SGD_SHA256       0x00000004	// SHA_256杂凑算法

/* ECC曲线类型 */
//NIST标准
#define NIST_FP_160           1

//NIST标准
#define NIST_FP_192           2
#define NIST_FP_224           3
#define NIST_FP_256           4

//国密局标准
#define OSCCA_FP_192          5
#define OSCCA_FP_256          6
#define OSCCA_NEWFP_256       7

#define PARAID       OSCCA_NEWFP_256


// 结构体定义
/***************************************************************************
* name:   设备信息结构体
* number: 
*    @IssuerName：    设备厂商名称
*    @DeviceName：    设备型号
*    @DeviceSerial：  设备编号，包含：日期（8）、批次号（3）、流水号（5）
*    @DeviceVersion： 密码设备内部版本号
*    @DeviceVersion： 密码设备支持的接口规范版本号
*    @AsymAlgAbility：前4字节表示支持的算法，表示方法为非对称算法按位异或的
*                     结果，后4字节表示算法最大模长，表示方法为支持模长按位异或结果
*    @SymAlgAbility： 所有支持的对称算法，表示方法为对称算法标识按位或运算结果
*    @HashAlgAbility：所有支持的杂凑算法，表示方法为杂凑算法标识按位或运算结果
*    @BufferSize：    支持的最大文件存储空间（单位字节）
*    @Dmkcv:          DMK校验值

* Description：函数SDF_GetDeviceInfo使用，用于获取设备信息
* *************************************************************************/
typedef struct DeviceInfo_st {
    unsigned char    IssuerName[40];
    unsigned char    DeviceName[16];
    unsigned char    DeviceSerial[16];
    unsigned int     DeviceVersion;
    unsigned int     StandardVersion;
    unsigned int     AsymAlgAbility[2];
    unsigned int     SymAlgAbility;
    unsigned int     HashAlgAbility;
    unsigned int     BufferSize;
    unsigned int     Dmkcv[2];
} DEVICEINFO;

// RSA 结构体宏定义
#define RSAref_MAX_BITS    4096
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)


/***************************************************************************
* name:   RSA公钥结构体
* number: 
*    @bits：          模长（比特数）
*    @m：             RSA公钥模N
*    @e：             RSA公钥指数E
*
* Description：RSA密钥目前支持的最大模长为4096。
*              m和e的BUFFER数据采用后对齐方式
* *************************************************************************/
typedef struct RSArefPublicKey_st {
    unsigned int     bits;
    unsigned char    m[RSAref_MAX_LEN];
    unsigned char    e[RSAref_MAX_LEN];
} RSArefPublicKey;

/***************************************************************************
* name:   RSA私钥结构体
* number: 
*    @bits：          模长（比特数）
*    @m：             RSA公钥模N
*    @e：             RSA公钥指数E
*    @d：             RSA私钥指数D
*    @prime[0]：      素数P
*    @prime[1]：      素数Q
*    @pexp[0]：       (D % (P - 1) )
*    @pexp[1]：       (D % (Q - 1) )
*    @coef：          (1 / (Q % P) )
*
* Description：RSA密钥目前支持的最大模长为2048。
*              m、e、d、prime、pexp、coef的BUFFER数据采用后对齐方式
* *************************************************************************/
typedef struct RSArefPrivateKey_st {
    unsigned int     bits;
    unsigned char    m[RSAref_MAX_LEN];
    unsigned char    e[RSAref_MAX_LEN];
    unsigned char    d[RSAref_MAX_LEN];
    unsigned char    prime[2][RSAref_MAX_PLEN];
    unsigned char    pexp[2][RSAref_MAX_PLEN];
    unsigned char    coef[RSAref_MAX_PLEN];
} RSArefPrivateKey;

// ECC密钥宏定义
#define ECCref_MAX_BITS    512 
#define ECCref_MAX_LEN     ((ECCref_MAX_BITS+7) / 8)

/***************************************************************************
* name:  ECC公钥结构体
* number: 
*    @bits：          模长（比特数）
*    @x：             公钥x坐标
*    @y：             公钥y坐标
*
* Description：SM2密钥模长为256
*              x和y的BUFFER数据采用后对齐的方式
* *************************************************************************/
typedef struct ECCrefPublicKey_st {
    unsigned int     bits;
    unsigned char    x[ECCref_MAX_LEN]; 
    unsigned char    y[ECCref_MAX_LEN]; 
} ECCrefPublicKey;

/***************************************************************************
* name:  ECC私钥结构体
* number: 
*    @bits：          模长（比特数）
*    @D：             私钥
*
* Description：SM2密钥模长为256
*              D的BUFFER数据采用后对齐方式
* *************************************************************************/
typedef struct ECCrefPrivateKey_st
{
    unsigned int     bits;
    unsigned char    D[ECCref_MAX_LEN];
} ECCrefPrivateKey;

// ECC密钥密文最大长度
#define ECC_CIPHER_MAX	1912
/***************************************************************************
* name:  ECC密文结构体
* number: 
*    @x：          与y组成椭圆曲线上的点(x, y)
*    @y：          与x组成椭圆曲线上的点(x, y)
*    @M：          明文的SM3杂凑值
*    @L：          密文数据长度
*    @C：          密文数据,最长支持1912字节
*
* Description：ECC密钥加解密运算时使用
*              密文数据采用前对齐方式
* *************************************************************************/
typedef struct ECCCipher_st {
    unsigned char    x[ECCref_MAX_LEN];
    unsigned char    y[ECCref_MAX_LEN];
    unsigned char    M[32];
    unsigned int     L;
    unsigned char    C[ECC_CIPHER_MAX];
} ECCCipher;

/***************************************************************************
* name:  ECC签名结构体
* number: 
*    @r：          签名r部分
*    @s：          签名s部分
*
* Description：ECC密钥签名(验证签名)运算时使用
* *************************************************************************/
typedef struct ECCSignature_st {
    unsigned char r[ECCref_MAX_LEN];	
    unsigned char s[ECCref_MAX_LEN];	
} ECCSignature;

/***************************************************************************
* name:  密钥协商的自身数据
* number: 
*    @pucSelfTmpPublicKey：            ECC公钥
*    @pucSelfTmpPrivateKey：           ECC私钥
*
* Description：ECC密钥签名(验证签名)运算时使用
* *************************************************************************/

typedef struct Agreement_st
{
    unsigned int uiAgreementcode;
    unsigned int uiISKIndex;
    unsigned int uiKeyBits;
    unsigned int uiSponsorIDLength;
    unsigned char pucSelfID[ECCref_MAX_LEN*2];
    ECCrefPublicKey  pucSelfTmpPublicKey;
    ECCrefPrivateKey pucSelfTmpPrivateKey;
} Agreement;

// 函数接口
#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************
* Subroutine: SDF_OpenDevice
* Function:   打开密码设备
* Input:      
*   无  
* 
* Output:     
*   @phDeviceHandle 返回的设备句柄 
*
* Return:       0 for success, other is error
* Description:  API初始化函数，初始化密码设备、初始化API内部资源。
*               返回phDeviceHandle设备句柄。
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int
SDF_OpenDevice  ( void  ** phDeviceHandle );

/***************************************************************************
* Subroutine: SDF_CloseDevice
* Function:   关闭密码设备，释放相关资源
* Input:      
*   @hDeviceHandle  打开的密码设备句柄  
* 
* Output:     
*    
*
* Return:       0 for success, other is error
* Description:  释放设备、内部API资源。
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int
SDF_CloseDevice ( void   * hDeviceHandle  );

/***************************************************************************
* Subroutine: SDF_OpenSession
* Function:   创建与密码设备的会话
* Input:      
*   @hDeviceHandle   已打开的密码设备句柄  
*    
* Output:     
*   @phSessionHandle 返回与密码设备建立的新会话句柄 
*
* Return:       0 for success, other is error
* Description:  
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_OpenSession ( 
        void             * hDeviceHandle, 
        void            ** phSessionHandle);

/***************************************************************************
* Subroutine: SDF_CloseSession
* Function:   关闭与密码设备建立的会话，并释放资源
* Input:      
*   @hSessionHandle   已打开密码设备会话句柄  
*    
* Output:     
*   @ 
*
* Return:       0 for success, other is error
* Description:  
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_CloseSession ( void  * hSessionHandle );

/***************************************************************************
* Subroutine: SDF_GetDeviceInfo
* Function:   获取密码设备能力描述
* Input:      
*   @hSessionHandle   已打开密码设备会话句柄  
*    
* Output:     
*   @pstDeviceInfo   密码设备能力描述信息，见设备信息结构定义 
*
* Return:       0 for success, other is error
* Description:  
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GetDeviceInfo ( 
        void             * hSessionHandle, 
        DEVICEINFO       * pstDeviceInfo);

/***************************************************************************
* Subroutine: SDF_GenerateRandom
* Function:   产生指定长度的随机数并输出
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiLength        产生的随机数长度 最大2048
*    
* Output:     
*   @pucRandom       缓冲区指针，用于存放产生的随机数
*
* Return:       0 for success, other is error
* Description: 
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateRandom ( 
        void             * hSessionHandle, 
        unsigned int       uiLength,
        unsigned char    * pucRandom   );
				
/***************************************************************************
* Subroutine: SDF_GetPrivateKeyAccessRight
* Function:   获取密码设备内部存储指定索引私钥的使用权限
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyType       密钥类型 SGD_RSA, SGD_SM2
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*   @pucPassword     私钥权限控制码
*   @uiPwdLength     私钥权限控制码长度。范围[8-16字节]
*
* Output:     
*   @
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 内部非对称密钥（RSA or SM2）作私钥操作前使用。私钥运算完成后，
*                  需调用SDF_ReleasePrivateKeyAccessRight函数释放私钥使用权限；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
#ifdef NETCA
SDFAPI int 
SDF_GetPrivateKeyAccessRight (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        unsigned char    * pucPassword,
        unsigned int       uiPwdLength  );
#else
SDFAPI int 
SDF_GetPrivateKeyAccessRight (
        void             * hSessionHandle, 
        unsigned int       uiKeyType,
        unsigned int       uiKeyIndex,
        unsigned char    * pucPassword,
        unsigned int       uiPwdLength  );
#endif

/***************************************************************************
* Subroutine: SDF_ReleasePrivateKeyAccessRight
* Function:   释放密码设备内部存储指定索引私钥的使用权限
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyType       密钥类型  SGD_RSA, SGD_SM2
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*
* Output:     
*   @
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 私钥运算完成后，调用该函数释放私钥使用权限；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ReleasePrivateKeyAccessRight ( 
        void             * hSessionHandle, 
        unsigned int       uiKeyType,
        unsigned int       uiKeyIndex   );
        
/***************************************************************************
* Subroutine: SDF_ExportSignPublicKey_RSA
* Function:   获取密码设备内部存储指定索引RSA签名公钥
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*
* Output:     
*   @pucPublicKey    获取的RSA签名公钥。结构定义见RSA公钥结构体定义
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 同一索引位置对应2个密钥，签名密钥和加密密钥；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int                                  
SDF_ExportSignPublicKey_RSA (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        RSArefPublicKey  * pucPublicKey );

/***************************************************************************
* Subroutine: SDF_ExportSignPublicKey_RSA
* Function:   获取密码设备内部存储指定索引RSA加密公钥
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*
* Output:     
*   @pucPublicKey    获取的RSA加密公钥。结构定义见RSA公钥结构体定义
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 同一索引位置对应2个密钥，签名密钥和加密密钥；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExportEncPublicKey_RSA (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        RSArefPublicKey  * pucPublicKey );
                                 
/***************************************************************************
* Subroutine: SDF_GenerateKeyPair_RSA
* Function:   通过密码设备产生指定模长的RSA明文密钥对。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyBits       指定的密钥模长。范围[1024-2048比特数]
*
* Output:     
*   @pucPublicKey    RSA公钥。结构定义见RSA公钥结构体定义
*   @pucPrivateKey   RSA私钥。结构定义见RSA私钥结构体定义
*
* Return:       0 for success, other is error
* Description:  产生的RSA密钥对指数为65537
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyPair_RSA ( 
        void             * hSessionHandle, 
        unsigned int       uiKeyBits,
        RSArefPublicKey  * pucPublicKey,
        RSArefPrivateKey * pucPrivateKey);
        
/***************************************************************************
* Subroutine: SDF_GenerateKeyWithIPK_RSA
* Function:   通过密码设备产生会话密钥，并使用内部RSA公钥加密输出，
*             同时返回会话密钥句柄。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiIPKIndex      密码设备内部RSA加密公钥索引。范围[1-n]
*   @uiKeyBits       指定会话密钥长度。范围[64、128、192比特数]
*
* Output:     
*   @pucKey          会话密钥密文，内部RSA公钥加密
*   @puiKeyLength    会话密钥密文长度，长度取决于内部RSA密钥模长
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 会话密钥长度通常为128[SM1\SM4]，其它长度为以后扩展使用；
*               3. RSA公钥加密会话密钥时，填充方式遵循PKCS#1 V1.5标准；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithIPK_RSA (
        void             * hSessionHandle,
        unsigned int       uiIPKIndex, 
        unsigned int       uiKeyBits,
        unsigned char    * pucKey,						
        unsigned int     * puiKeyLength, 
        void            ** phKeyHandle  );
				
/***************************************************************************
* Subroutine: SDF_GenerateKeyWithEPK_RSA
* Function:   通过密码设备产生会话密钥，并使用外送RSA公钥加密输出，
*             同时返回会话密钥句柄。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyBits       指定会话密钥长度。范围[64、128、192比特数]
*   @pucPublicKey    RSA公钥，用于加密会话密钥
*
* Output:     
*   @pucKey          会话密钥密文，外送RSA公钥加密
*   @puiKeyLength    会话密钥密文长度，长度取决于外送RSA密钥模长
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 会话密钥长度通常为128[SM1\SM4]，其它长度为以后扩展使用；
*               2. RSA公钥加密会话密钥时，填充方式遵循PKCS#1 V1.5标准；
*               3. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithEPK_RSA (
        void             * hSessionHandle, 
        unsigned int       uiKeyBits,
        RSArefPublicKey  * pucPublicKey,
        unsigned char    * pucKey, 
        unsigned int     * puiKeyLength, 
        void            ** phKeyHandle  );

/***************************************************************************
* Subroutine: SDF_ImportKeyWithISK_RSA
* Function:   导入会话密钥到密码设备的指定索引，同时返回会话密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      密码设备内部RSA加密私钥索引，用于解密会话密钥。范围[1-n]
*   @pucKey          会话密钥密文
*   @uiKeyLength     会话密钥密文长度，字节数，长度等于(RSA密钥模长+7/8)
*
* Output:     
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. RSA密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. RSA公钥加密会话密钥时，填充方式遵循PKCS#1 V1.5标准；
*               3. 会话密钥密文，使用内部RSA加密私钥进行解密。
*               4. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ImportKeyWithISK_RSA (
        void             * hSessionHandle, 
        unsigned int       uiISKIndex, 
        unsigned char    * pucKey, 
        unsigned int       uiKeyLength, 
        void            ** phKeyHandle  );
/***************************************************************************
* Subroutine: SDF_ImportKey
* Function:   导入明文会话密钥，同时返回密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucKey          缓冲区指针，用于存放输入的密钥明文
*   @puiKeyLength    输入的密钥明文长度
*
* Output:     
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI 
int SDF_ImportKey(void *hSessionHandle, 
                      unsigned char *pucKey, 
                      unsigned int uiKeyLength, 
                      void **phKeyHandle);
/***************************************************************************
* Subroutine: SDF_ExchangeDigitEnvelopeBaseOnRSA
* Function:   将内部RSA加密公钥加密的会话密钥转为外送RSA公钥加密，可用于数字信封
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      密码设备内部RSA加密私钥索引，用于解密会话密钥。范围[1-n]
*   @pucPublicKey    RSA公钥，用于加密会话密钥
*   @pucDEInput      会话密钥密文，内部RSA公钥加密
*   @uiDELength      会话密钥密文长度，字节数，长度等于(内部RSA密钥模长+7/8)
*
* Output:     
*   @pucDEOutput     会话密钥密文，外送RSA公钥加密
*   @puiDELength     会话密钥密文长度，字节数，长度等于(外送RSA密钥模长+7/8)
*
* Return:       0 for success, other is error
* Description:  1. RSA密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. RSA公钥加密会话密钥时，填充方式遵循PKCS#1 V1.5标准；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExchangeDigitEnvelopeBaseOnRSA (
				void             * hSessionHandle, 
				unsigned int       uiKeyIndex,
				RSArefPublicKey  * pucPublicKey,
				unsigned char    * pucDEInput,
				unsigned int       uiDELength,
				unsigned char    * pucDEOutput,
				unsigned int     * puiDELength  );
				
/***************************************************************************
* Subroutine: SDF_ExportSignPublicKey_ECC
* Function:   获取密码设备内部存储指定索引SM2签名公钥
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*
* Output:     
*   @pucPublicKey    获取的SM2签名公钥。结构定义见SM2公钥结构体定义
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 同一索引位置对应2个密钥，签名密钥和加密密钥；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExportSignPublicKey_ECC (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        ECCrefPublicKey  * pucPublicKey );
                                 
/***************************************************************************
* Subroutine: SDF_ExportEncPublicKey_ECC
* Function:   获取密码设备内部存储指定索引SM2加密公钥
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*
* Output:     
*   @pucPublicKey    获取的SM2加密公钥。结构定义见SM2公钥结构体定义
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 同一索引位置对应2个密钥，签名密钥对和加密密钥对；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExportEncPublicKey_ECC (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        ECCrefPublicKey  * pucPublicKey );
				
/***************************************************************************
* Subroutine: SDF_GenerateKeyPair_ECC
* Function:   通过密码设备产生指定类型和模长的SM2明文密钥对。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiAlgID         算法ID;PARAID
*   @uiKeyBits       指定的SM2密钥模长。范围[256]
* Output:     
*   @pucPublicKey    SM2公钥。结构定义见SM2公钥结构体定义
*   @pucPrivateKey   SM2私钥。结构定义见SM2私钥结构体定义
*
* Return:       0 for success, other is error
* Description:  目前该函数仅支持国密SM2密钥产生，模长仅支持256比特。其它类型
*               密钥如NIST标准ECC密钥暂w不支持。
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyPair_ECC (
        void             * hSessionHandle, 
        unsigned int       uiAlgID,
        unsigned int       uiKeyBits,
        ECCrefPublicKey  * pucPublicKey,
        ECCrefPrivateKey * pucPrivateKey);
				
/***************************************************************************
* Subroutine: SDF_GenerateKeyWithIPK_ECC
* Function:   通过密码设备产生会话密钥，并使用内部SM2加密公钥加密输出，
*             同时返回会话密钥句柄。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiIPKIndex      密码设备内部SM2加密公钥索引。范围[1-n]
*   @uiKeyBits       指定会话密钥长度。范围[64、128、192比特数]
*
* Output:     
*   @pucKey          会话密钥密文结构，内部SM2加密公钥加密。
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 会话密钥长度通常为128[SM1\SM4]比特，其它长度为以后扩展使用；
*               3. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithIPK_ECC (
        void             * hSessionHandle, 
        unsigned int       uiIPKIndex,
        unsigned int       uiKeyBits,
        ECCCipher        * pucKey,
        void            ** phKeyHandle  );
				
/***************************************************************************
* Subroutine: SDF_GenerateKeyWithEPK_ECC
* Function:   通过密码设备产生会话密钥，并使用外送SM2公钥加密输出，
*             同时返回会话密钥句柄。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyBits       指定会话密钥长度。范围[64、128、192比特数]
*   @uiAlgID         外送ECC公钥算法标识。范围[SGD_SM2]
*   @pucPublicKey    SM2公钥，用于加密会话密钥
*
* Output:     
*   @pucKey          会话密钥密文结构，外送SM2公钥加密。
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 会话密钥长度通常为128[SM1\SM4]，其它长度为以后扩展使用；
*               3. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithEPK_ECC (
        void             * hSessionHandle, 
        unsigned int       uiKeyBits,
        unsigned int       uiAlgID,
        ECCrefPublicKey  * pucPublicKey,
        ECCCipher        * pucKey,
        void            ** phKeyHandle  );
								  
/***************************************************************************
* Subroutine: SDF_ImportKeyWithISK_ECC
* Function:   导入会话密钥到密码设备的指定索引，同时返回会话密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      密码设备内部SM2加密私钥索引，用于解密会话密钥。范围[1-n]
*   @pucKey          会话密钥密文结构体
*
* Output:     
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. SM2密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               3. 会话密钥密文，使用内部SM2加密私钥进行解密。
*               4. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ImportKeyWithISK_ECC (
        void             * hSessionHandle,
        unsigned int       uiISKIndex,
        ECCCipher        * pucKey,
        void            ** phKeyHandle  );
				
/***************************************************************************
* Subroutine: SDF_ExchangeDigitEnvelopeBaseOnECC
* Function:   将内部SM2加密公钥加密的会话密钥转为外送SM2公钥加密，可用于数字信封
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      密码设备内部SM2加密私钥索引，用于解密会话密钥。范围[1-n]
*   @uiAlgID         外送ECC公钥算法标识。范围[SGD_SM2]
*   @pucPublicKey    SM2公钥，用于加密会话密钥
*   @pucEncDataIn    会话密钥密文结构体，内部SM2加密公钥加密
*
* Output:     
*   @pucEncDataOut   会话密钥密文结构体，外送SM2公钥加密
*
* Return:       0 for success, other is error
* Description:  1. SM2密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 加密算法仅支持国密标准的SM2算法。其它算法暂不支持；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExchangeDigitEnvelopeBaseOnECC (
        void             * hSessionHandle, 
        unsigned int       uiKeyIndex,
        unsigned int       uiAlgID,
        ECCrefPublicKey  * pucPublicKey,
        ECCCipher        * pucEncDataIn,
        ECCCipher        * pucEncDataOut);
										   
/***************************************************************************
* Subroutine: SDF_GenerateAgreementDataWithECC
* Function:   发起方会话密钥协商参数产生函数。
*             使用SM2密钥协商算法，为计算会话密钥而产生协商参数，同时返回指定
*             索引位置的SM2公钥，临时SM2公钥及协商句柄。
* Input:      
*   @hSessionHandle         已打开密码设备会话句柄
*   @uiISKIndex             密码设备内部SM2加密私钥索引，用于协商会话密钥。范围[1-n]
*   @uiKeyBits              协商会话密钥长度。范围[64、128、192比特数]
*   @pucSponsorID           参与协商的发起方的ID值。
*   @uiSponsorIDLength      参与协商的发起方的ID值长度。范围[1-128字节数]
*
* Output:     
*   @pucSponsorPublicKey    发起方指定索引[uiISKIndex]SM2的公钥结构
*   @pucSponsorTmpPublicKey 发起方临时SM2的公钥结构
*   @phAgreementHandle      协商句柄，用于计算协商会话密钥
*
* Return:       0 for success, other is error
* Description:  1. 为协商会话密钥，协商的发起方首先调用该函数。
*               2. 该函数将返回结果pucSponsorPublicKey、pucSponsorTmpPublicKey
*                  和输入参数pucSponsorID、uiSponsorIDLength给响应方的
*                  SDF_GenerateAgreementDataAndKeyWithECC函数使用。
*               3. 响应方SDF_GenerateAgreementDataAndKeyWithECC函数根据发起方的协商参数，
*                  计算响应方的协商参数和会话密钥句柄。
*               4. 发起方使用SDF_GenerateKeyWithECC函数根据响应方协商参数计算会话密钥句柄。
*               5. 参数phAgreementHandle保存临时协商信息，由函数初始化。在发起方调用
*                  SDF_GenerateKeyWithECC函数时使用。
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateAgreementDataWithECC (
        void             * hSessionHandle,
        unsigned int       uiISKIndex,
        unsigned int       uiKeyBits,
        unsigned char    * pucSponsorID,
        unsigned int       uiSponsorIDLength,
        ECCrefPublicKey  * pucSponsorPublicKey,
        ECCrefPublicKey  * pucSponsorTmpPublicKey,
        void            ** phAgreementHandle);
										  

/***************************************************************************
* Subroutine: SDF_GenerateKeyWithECC
* Function:   发起方使用函数。算法实现参见国密标准 GM/T 0009
*             使用ECC密钥协商算法，使用自身协商句柄和响应方的协商参数计算会话密钥，
*             同时返回会话密钥句柄。
* Input:      
*   @hSessionHandle          已打开密码设备会话句柄
*   @pucResponseID           参与协商的响应方的ID值。
*   @uiResponseIDLength      参与协商的响应方的ID值长度。范围[1-128字节数]
*   @pucResponsePublicKey    参与协商的响应方公钥结构
*   @pucResponseTmpPublicKey 参与协商的响应方临时SM2的公钥结构
*   @phAgreementHandle       协商句柄，由SDF_GenerateAgreementDataWithECC产生
*
* Output:     
*   @phKeyHandle             发起方协商的会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 协商的发起方获取响应方的协商参数后调用本函数，计算会话密钥。
*               2. 参数所有带(响应方)字样的参数，都是由SDF_GenerateAgreementDataAndKeyWithECC
*                  函数提供；
*               3. 参数phKeyHandle为协商的会话密钥句柄，不使用时需要调用
*                  SDF_DestoryKey函数销毁；
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithECC (
        void             * hSessionHandle, 
        unsigned char    * pucResponseID,
        unsigned int       uiResponseIDLength,
        ECCrefPublicKey  * pucResponsePublicKey,
        ECCrefPublicKey  * pucResponseTmpPublicKey,
        void             * phAgreementHandle,
        void            ** phKeyHandle  );

/***************************************************************************
* Subroutine: SDF_GenerateAgreementDataAndKeyWithECC
* Function:   响应方使用函数。算法实现参见国密标准 GM/T 0009
*             使用ECC密钥协商算法，产生协商参数并计算会话密钥，同时返回产生的协商
*             参数和密钥句柄。
* Input:      
*   @hSessionHandle         已打开密码设备会话句柄
*   @uiISKIndex             密码设备内部SM2加密私钥索引，用于协商会话密钥。范围[1-n]
*   @uiKeyBits              协商会话密钥长度。范围[64、128、192比特数]
*   @pucResponseID          参与协商的响应方ID值。
*   @uiResponseIDLength     参与协商的响应方ID值长度。范围[1-128字节数]
*   @pucSponsorID           参与协商的发起方ID值。
*   @uiSponsorIDLength      参与协商的发起方ID值长度。范围[1-128字节数]
*   @pucSponsorPublicKey    参与协商的发起方ECC公钥结构。
*   @pucSponsorTmpPublicKey 参与协商的发起方临时ECC公钥结构
*
* Output:     
*   @pucResponsePublicKey    响应方指定索引[uiISKIndex]SM2的公钥结构
*   @pucResponseTmpPublicKey 响应方临时SM2的公钥结构
*   @phKeyHandle             响应方协商的会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. 该函数为响应方调用函数，密钥协商时，只需调用一次该函数即可；
*               2. 参数所有带(发起方)字样的参数，都是由SDF_GenerateAgreementDataWithECC
*                  函数提供；
*               3. 参数phKeyHandle为协商的会话密钥句柄，不使用时需要调用
*                  SDF_DestoryKey函数销毁；
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateAgreementDataAndKeyWithECC (
        void             * hSessionHandle, 
        unsigned int       uiISKIndex,
        unsigned int       uiKeyBits,
        unsigned char    * pucResponseID,
        unsigned int       uiResponseIDLength,
        unsigned char    * pucSponsorID,
        unsigned int       uiSponsorIDLength,
        ECCrefPublicKey  * pucSponsorPublicKey,
        ECCrefPublicKey  * pucSponsorTmpPublicKey,
        ECCrefPublicKey  * pucResponsePublicKey,
        ECCrefPublicKey  * pucResponseTmpPublicKey,
        void            ** phKeyHandle  );
				
/***************************************************************************
* Subroutine: SDF_GenerateKeyWithKEK
* Function:   产生会话密钥使用密钥加密秘钥加密输出，同时返回会话密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyBits       指定会话密钥长度。范围[64、128、192比特数]
*   @uiAlgID         KEK加密会话密钥算法标识。
*                    范围[SGD_SM1_ECB、SGD_SM4_ECB]
*   @uiKEKIndex      密码设备内部KEK密钥索引，用于加密会话密钥。范围[1-n]
*
* Output:     
*   @pucKey          会话密钥密文，由内部KEK加密
*   @puiKeyLength    会话密钥密文长度，字节数;
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. KEK密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 加密算法使用的ECB算法
*               4. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyWithKEK (
        void             * hSessionHandle, 
		unsigned int       uiKeyBits,
        unsigned int       uiAlgID,
        unsigned int       uiKEKIndex, 
        unsigned char    * pucKey, 
        unsigned int     * puiKeyLength,
        void            ** phKeyHandle  );
        
/***************************************************************************
* Subroutine: SDF_ImportKeyWithKEK
* Function:  导入会话密钥并用KEK解密，同时返回会话密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiAlgID         KEK加密会话密钥算法标识。
*                    范围[SGD_SM1_ECB、SGD_SM4_ECB]
*   @uiKEKIndex      密码设备内部KEK密钥索引，用于解密会话密钥。范围[1-n]
*   @pucKey          会话密钥密文，由内部KEK加密
*   @puiKeyLength    会话密钥密文长度，字节数;
*
* Output:     
*   @phKeyHandle     会话密钥句柄
*
* Return:       0 for success, other is error
* Description:  1. KEK密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*               2. 加密算法使用的ECB算法
*               4. 会话密钥句柄可用于加解密数据，使用后需要调用
*                  SDF_DestoryKey函数销毁；
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ImportKeyWithKEK (
        void             * hSessionHandle, 
        unsigned int       uiAlgID,
        unsigned int       uiKEKIndex, 
        unsigned char    * pucKey, 
        unsigned int       uiKeyLength, 
        void            ** phKeyHandle  );

/***************************************************************************
* Subroutine: SDF_DestroyKey
* Function:  销毁会话密钥句柄
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @hKeyHandle      会话密钥句柄，通过其它函数产生
*
* Output:     
*   no.
*
* Return:       0 for success, other is error
* Description:  1. 该函数用于销毁会话密钥，密码设备内部密钥句柄不需要调用该函数。
*               2. 产生会话密钥句柄并需要销毁的函数如下：
*                  SDF_ImportKeyWithKEK
*                  SDF_GenerateKeyWithKEK
*                  SDF_GenerateAgreementDataAndKeyWithECC
*                  SDF_ImportKeyWithISK_ECC
*                  SDF_GenerateKeyWithEPK_ECC
*                  SDF_GenerateKeyWithIPK_ECC
*                  SDF_ImportKeyWithISK_RSA
*                  SDF_GenerateKeyWithEPK_RSA
*                  SDF_GenerateKeyWithIPK_RSA
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_DestroyKey (
        void             * hSessionHandle, 
        void             * hKeyHandle   );

/***************************************************************************
* Subroutine: SDF_ExternalPublicKeyOperation_RSA
* Function:  外送RSA公钥对数据进行运算
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucPublicKey    RSA公钥结构体，用于对输入数据作公钥运算。
*   @pucDataInput    待运算的输入数据。
*   @uiInputLength   待运算的输入数据长度，字节数。长度必须为(RSA公钥模长+7/8)
*
* Output:     
*   @pucDataOutput   公钥运算后结果
*   @puiOutputLength 公钥运算后结果长度。长度满足(RSA公钥模长+7/8)
*
* Return:       0 for success, other is error
* Description:  1. 待运算的数据需要应用层封装。函数内部不作处理。
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExternalPublicKeyOperation_RSA (
        void             * hSessionHandle, 
        RSArefPublicKey  * pucPublicKey,
        unsigned char    * pucDataInput,
        unsigned int       uiInputLength,
        unsigned char    * pucDataOutput,
        unsigned int     * puiOutputLength);
				
/***************************************************************************
* Subroutine: SDF_InternalPublicKeyOperation_RSA
* Function:  内部指定索引RSA签名公钥对数据进行运算
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的公钥索引值。范围[1-n]
*   @pucDataInput    待运算的输入数据。
*   @uiInputLength   待运算的输入数据长度，字节数。长度必须为(RSA公钥模长+7/8)
*
* Output:     
*   @pucDataOutput   公钥运算后结果
*   @puiOutputLength 公钥运算后结果长度。长度满足(RSA公钥模长+7/8)
*
* Return:       0 for success, other is error
* Description: 1. 索引[uiKeyIndex]只限于内部签名公钥
*              2. 待运算的数据需要应用层封装。函数内部不作处理。
*              3. RSA密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalPublicKeyOperation_RSA (
        void             * hSessionHandle,
        unsigned int       uiKeyIndex,
        unsigned char    * pucDataInput,
        unsigned int       uiInputLength,
        unsigned char    * pucDataOutput,
        unsigned int     * puiOutputLength);

/***************************************************************************
* Subroutine: SDF_InternalPrivateKeyOperation_RSA
* Function:  内部指定索引RSA签名私钥对数据进行运算
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      设备内部存储的私钥索引值。范围[1-n]
*   @pucDataInput    待运算的输入数据。
*   @uiInputLength   待运算的输入数据长度，字节数。长度必须为(RSA公钥模长+7/8)
*
* Output:     
*   @pucDataOutput   RSA私钥运算后结果
*   @puiOutputLength RSA私钥运算后结果长度。长度满足(RSA公钥模长+7/8)
*
* Return:       0 for success, other is error
* Description: 1. 索引[uiKeyIndex]只限于内部签名私钥
*              2. 待运算的数据需要应用层封装。函数内部不作处理。
*              3. RSA密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalPrivateKeyOperation_RSA ( 
        void             * hSessionHandle,
        unsigned int       uiKeyIndex,
        unsigned char    * pucDataInput,
        unsigned int       uiInputLength,
        unsigned char    * pucDataOutput,
        unsigned int     * puiOutputLength);
				
/***************************************************************************
* Subroutine: SDF_InternalSign_ECC
* Function:  内部指定索引ECC签名私钥对数据进行签名
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      设备内部存储的私钥索引值。范围[1-n]
*   @pucData         待签名输入数据的杂凑结果。
*   @uiDataLength    待签名输入数据杂凑结果长度;
*
* Output:     
*   @pucSignature    ECC签名结果，由(r || s)组成，参见ECC签名结构定义；
*
* Return:       0 for success, other is error
* Description: 1. 内部ECC密钥使用的是对应索引的签名私钥
*              2. 待签名的数据位杂凑结果值，如果是SM2签名，输入数据使用的是
*                 带ID和公钥的SM3哈希结果值。参见国密GM/T 0009.
*              3. ECC密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalSign_ECC (
        void             * hSessionHandle,
        unsigned int       uiISKIndex,
        unsigned char    * pucData,
        unsigned int       uiDataLength,
        ECCSignature     * pucSignature );


/***************************************************************************
* Subroutine: SDF_ExternalSign_ECC
* Function:  外部ECC公钥对数据进行验证签名
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiAlgID         算法ID，SM2密钥使用[PARAID].
*   @pucPublicKey    SM2验证签名公钥。结构定义见SM2公钥结构体定义
*   @pucData         输入数据的杂凑结果。
*   @uiDataLength    输入数据杂凑结果长度;
*   @pucSignature    ECC签名结果，由(r || s)组成，参见ECC签名结构定义；
*
* Output:     
*   无
* Return:       0 for success, other is error
* Description: 1. 输入数据为杂凑结果值，如果是SM2签名，输入数据使用的是
*                 带ID和公钥的SM3哈希结果值。参见国密GM/T 0009.
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExternalVerify_ECC (
        void             * hSessionHandle,
        unsigned int       uiAlgID,
        ECCrefPublicKey  * pucPublicKey,
        unsigned char    * pucData,
        unsigned int       uiDataLength,
        ECCSignature     * pucSignature );
						
/***************************************************************************
* Subroutine: SDF_InternalVerify_ECC
* Function:  内部ECC签名公钥对数据进行验证签名
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      设备内部存储的公钥索引值。范围[1-n]
*   @pucData         输入数据的杂凑结果。
*   @uiDataLength    输入数据杂凑结果长度;   
*   @pucSignature    ECC签名结果，由(r || s)组成，参见ECC签名结构定义；
* 
* Return:       0 for success, other is error
* Description: 1. 输入数据为杂凑结果值，如果是SM2签名，输入数据使用的是
*                 带ID和公钥的SM3哈希结果值。参见国密GM/T 0009.
*              2. 内部ECC密钥使用的是对应索引的签名密钥。
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalVerify_ECC (
        void             * hSessionHandle,
        unsigned int       uiISKIndex,
        unsigned char    * pucData,
        unsigned int       uiDataLength,
        ECCSignature     * pucSignature );
							
/***************************************************************************
* Subroutine: SDF_ExternalEncrypt_ECC
* Function:  外部ECC公钥对数据进行加密
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiAlgID         曲线标识，使用PARAID.
*   @pucPublicKey    SM2验证加密公钥。结构定义见SM2公钥结构体定义
*   @pucData         输入数据。
*   @uiDataLength    输入数据长度[1-1024];
*
* Output:     
*   @pucEncData      ECC加密结果，参见ECC加密结构定义；
*
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ExternalEncrypt_ECC (
    void             * hSessionHandle,
    unsigned int       uiAlgID,
    ECCrefPublicKey  * pucPublicKey,
    unsigned char    * pucData,
    unsigned int       uiDataLength,
    ECCCipher        * pucEncData);

/***************************************************************************
* Subroutine: SDF_Encrypt
* Function:  使用指定的密钥句柄和IV对数据进行加密运算，对称密钥加密。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @hKeyHandle      密钥句柄。可以是密钥索引和其它函数产生的句柄。
*   @uiAlgID         加密算法。算法为：
*                       SGD_SM1_ECB、SGD_SM1_CBC、SGD_SM1_CFB、SGD_SM1_OFB
*                       SGD_SM4_ECB、SGD_SM4_CBC、SGD_SM4_CFB、SGD_SM4_OFB
*                        
*   @pucIV           输入的IV数据。当算法为CBC、CFB、OFB算法时存在
*   @pucData         输入数据。
*   @uiDataLength    输入数据长度，不能超过2048，必须满足16字节的倍数;
*
* Output:     
*   @pucIV             返回的IV数据，用于多包运算。当算法为CBC、CFB、OFB算法时存在
*   @pucEncData        加密结果；
*   @puiEncDataLength  加密结果长度；
*
* Return:       0 for success, other is error
* Description: 1. 本函数不对输入数据进行填充处理。输入数据必须满足指定算法分组长度整数倍
*              2. IV即是输入数据，也是返回数据。当算法不为ECB时存在。
*              3. 当输入的密钥句柄为密钥索引时，密钥句柄的指针指向索引变量即可。
*              4. 当输入的密钥句柄不是密钥索引时，使用完后需调用SDF_DestoryKey销毁该句柄。
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_Encrypt (
    void             * hSessionHandle,
    void             * hKeyHandle,
    unsigned int       uiAlgID,
    unsigned char    * pucIV,
    unsigned char    * pucData,
    unsigned int       uiDataLength,
    unsigned char    * pucEncData,
    unsigned int     * puiEncDataLength);
                    
/***************************************************************************
* Subroutine: SDF_Decrypt
* Function:  使用指定的密钥句柄和IV对数据进行解密运算，对称密钥解密。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @hKeyHandle      密钥句柄。可以是密钥索引和其它函数产生的句柄。
*   @uiAlgID         解密算法。算法为：
*                       SGD_SM1_ECB、SGD_SM1_CBC、SGD_SM1_CFB、SGD_SM1_OFB
*                       SGD_SM4_ECB、SGD_SM4_CBC、SGD_SM4_CFB、SGD_SM4_OFB
*                        
*   @pucIV           输入的IV数据。当算法为CBC、CFB、OFB算法时存在
*   @pucEncData      输入密文数据。
*   @uiEncDataLength 输入密文数据长度，必须满足16字节的倍数;
*
* Output:     
*   @pucIV           返回的IV数据，用于多包运算。当算法为CBC、CFB、OFB算法时存在
*   @pucData         解密结果；
*   @puiDataLength   解密结果长度；
*
* Return:       0 for success, other is error
* Description: 1. 输入的密文数据必须满足指定算法分组长度整数倍
*              1. 本函数不对解密数据进行去填充处理。需要应用层处理填充数据；
*              2. IV即是输入数据，也是返回数据。当算法不为ECB时存在。
*              3. 当输入的密钥句柄为密钥索引时，密钥句柄的指针指向索引变量即可。
*              4. 当输入的密钥句柄不是密钥索引时，使用完后需调用SDF_DestoryKey销毁该句柄。
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_Decrypt (
        void             * hSessionHandle,
        void             * hKeyHandle,
        unsigned int       uiAlgID,
        unsigned char    * pucIV,
        unsigned char    * pucEncData,
        unsigned int       uiEncDataLength,
        unsigned char    * pucData,
        unsigned int     * puiDataLength);

/***************************************************************************
* Subroutine: SDF_CalculateMAC
* Function:  使用指定的密钥句柄和IV对数据进行MAC运算，对称MAC运算。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @hKeyHandle      密钥句柄。可以是密钥索引和其它函数产生的句柄。
*   @uiAlgID         MAC算法标识。算法为：
*                       SGD_SM1_MAC
*                       SGD_SM4_MAC
*                        
*   @pucIV           输入的IV数据，计算MAC时使用。
*   @pucData         输入数据。
*   @uiDataLength    输入数据长度，必须满足16字节的倍数;
*
* Output:     
*   @pucIV           返回的IV数据，用于多包MAC运算。
*   @pucMAC          计算出的MAC结果；
*   @puiMACLength    MAC结果长度；
*
* Return:       0 for success, other is error
* Description: 1. 输入的数据必须满足指定算法分组长度整数倍；
*              2. 本函数不对数据进行填充处理。需要应用层处理填充数据；
*              3. IV即是输入数据，也是返回数据；
*              4. 当输入的密钥句柄为密钥索引时，密钥句柄的指针指向索引变量即可；
*              5. 当输入的密钥句柄不是密钥索引时，使用完后需调用SDF_DestoryKey销毁该句柄。
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_CalculateMAC (
        void             * hSessionHandle,
        void             * hKeyHandle,
        unsigned int       uiAlgID,
        unsigned char    * pucIV,
        unsigned char    * pucData,
        unsigned int       uiDataLength,
        unsigned char    * pucMAC,
        unsigned int     * puiMACLength);


/***************************************************************************
* Subroutine: SDF_HashInit
* Function:  摘要初始化操作。三步式摘要运算第一步。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiAlgID         摘要算法标识。可选算法如下：
*                        SGD_SHA1、SGD_SHA256、SGD_SM3
*   @pucPublicKey    SM2签名公钥。当算法标识为SGD_SM3时有效
*   @pucID           签名ID，当算法标识为SGD_SM3时有效
*   @uiIDLength      签名ID长度.
*
* Output:     
*   无
* Return:       0 for success, other is error
* Description: 1. 当摘要结果用作SM2签名时，SM2签名公钥pucPublicKey必须存在，
*                 签名ID可选，当签名ID不存在，内部使用默认值字符串[1234567812345678]。
*                 函数执行SM2的预处理1操作。计算过程见：GM/T 0009
*              2. 当摘要结果作为SM3时，参数pucPublicKey和pucID必须为NULL；
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_HashInit (
        void             * hSessionHandle,
        unsigned int       uiAlgID,
        ECCrefPublicKey  * pucPublicKey,
        unsigned char    * pucID,
        unsigned int       uiIDLength   );


/***************************************************************************
* Subroutine: SDF_HashUpdate
* Function:  摘要初始化操作。三步式摘要运算第二步。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucData         输入数据。
*   @uiDataLength    输入数据长度。范围[0-2048]
*
* Output:     
*   无
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_HashUpdate (
        void             * hSessionHandle,
        unsigned char    * pucData,
        unsigned int       uiDataLength );

/***************************************************************************
* Subroutine: SDF_HashFinal
* Function:  摘要初始化操作。三步式摘要运算第三步。
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*
* Output:     
*   @pucHash         摘要结果数据。
*   @puiHashLength   摘要结果数据长度。范围[SHA1-20、SHA256-32、SM3-32]
*
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_HashFinal (
        void             * hSessionHandle,
        unsigned char    * pucHash,
        unsigned int     * puiHashLength);


/***************************************************************************
* Subroutine: SDF_CreateFile
* Function:  在密码设备内部创建用于存储用户数据的文件
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucFileName     文件名称。
*   @uiNameLen       文件名称长度。长度最大为128字节
*   @uiFileSize      文件存储区大小。
* Output:     
*   无
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_CreateFile ( 
        void             * hSessionHandle,
        unsigned char    * pucFileName,
        unsigned int       uiNameLen,
        unsigned int       uiFileSize   );

/***************************************************************************
* Subroutine: SDF_ReadFile
* Function:  读取密码设备内部存储用户数据的文件内容
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucFileName     文件名称。
*   @uiNameLen       文件名称长度。长度最大为128字节
*   @uiOffset        指定文件读取的偏移量。
*   @puiFileLength   入参指定读取的文件长度。
*
* Output:     
*   @puiFileLength   出参指定实际读取的文件长度。
*   @pucBuffer       读取的文件数据
*
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ReadFile (
        void             * hSessionHandle,
        unsigned char    * pucFileName,
        unsigned int       uiNameLen,
        unsigned int       uiOffset,
        unsigned int     * puiFileLength,
        unsigned char    * pucBuffer    );

/***************************************************************************
* Subroutine: SDF_WriteFile
* Function:  向密码设备内部存储用区写数据
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucFileName     文件名称。
*   @uiNameLen       文件名称长度。长度最大为128字节
*   @uiOffset        指定写入文件的偏移量。
*   @uiFileLength    写入文件内容的长度。
*   @pucBuffer       写入文件的内容。
*
* Output:     
*   无
*   
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_WriteFile (
        void             * hSessionHandle,
        unsigned char    * pucFileName,
        unsigned int       uiNameLen,
        unsigned int       uiOffset,
        unsigned int       uiFileLength,
        unsigned char    * pucBuffer    );

/***************************************************************************
* Subroutine: SDF_DeleteFile
* Function:  删除密码设备内部存储用区用户数据的文件
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @pucFileName     文件名称。
*   @uiNameLen       文件名称长度。长度最大为128字节
*
* Output:     
*   无
*   
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_DeleteFile (
    void             * hSessionHandle, 
    unsigned char    * pucFileName,
    unsigned int       uiNameLen    );


/***************************************************************************
* Subroutine: SDF_ImportKeyPair
* Function:  从外部导入RSA或ECC密钥对
* Input:      
*   @hSessionHandle        已打开密码设备会话句柄
*   @Mechanism             算法标识  SGD_RSA, SGD_SM2
*   @KeyId                 密钥存放的索引号 范围[1-n]
*   @PrivateKeyDerBuf      私钥DER缓冲区指针
*   @prikeyDerLen          私钥DER缓冲区长度
*   @PublicKeyDerBuf       公钥DER缓冲区指针
*   @PublicDerLen          公钥DER缓冲区长度
*
* Output:     
*   无
*   
* Return:       0 for success, other is error
* Description:  1. 密钥索引的范围为[1-n]，密码设备的实际存储量决定n；
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_ImportKeyPair(
        void             *hSessionHandle, 
        unsigned  int    Mechanism,		   
        unsigned  int    KeyId,
        unsigned  char   *PrivateKeyDerBuf,
        unsigned  int    prikeyDerLen,
        unsigned  char   *PublicKeyDerBuf,
        unsigned  int    PublicDerLen  );


/***************************************************************************
* Subroutine: SDF_GenerateKeyPairEx_RSA
* Function:  产生RSA密钥对并保存至密钥表 
* Input:      
*   @hSessionHandle        已打开密码设备会话句柄
*   @Mechanism             算法标识 签名：SGD_RSA_SIGN_EX  加密：SGD_RSA_ENC_EX
*   @KeySize               密钥长度
*   @KeyId                 密钥ID
*
* Output:     
*   无
*   
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyPairEx_RSA(
       void           *hSessionHandle, 
       unsigned  int  Mechanism,
       unsigned  int  KeySize,
       unsigned  int  keyid   );

/***************************************************************************
* Subroutine: SDF_GenerateKeyPairEx_ECC
* Function:  产生ECC密钥对并保存至密钥表 
* Input:      
*   @hSessionHandle        已打开密码设备会话句柄
*   @Mechanism             算法标识 签名：SGD_SM2_1  加密：SGD_SM2_3
*   @uiAlgID               ECC算法标识  PARAID
*   @KeyId                 密钥ID
*
* Output:     
*   无
*   
* Return:       0 for success, other is error
* Description: 
*
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_GenerateKeyPairEx_ECC(
       void           *hSessionHandle, 
       unsigned  int  Mechanism,
       unsigned  int  uiAlgID,
       unsigned  int  keyid   );



#ifdef NETCA // 网证通专用函数
/***************************************************************************
* Subroutine: SDF_InternalPrivateKeyOperation_RSA_EX
* Function:  RSA内部私钥运算
* Input:
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiKeyIndex      RSA密钥索引（1-64）
*   @signKeyType     密钥类型, 1-SGD_RSA_SIGN_EX签名密钥，2-SGD_RSA_ENC_EX加密密钥
*   @pucDataInput    待运算的输入数据。
*   @uiInputLength   待运算的输入数据长度，字节数。长度必须为(RSA公钥模长+7/8)
*
* Output:
*   @pucDataOutput   RSA私钥运算后结果
*   @puiOutputLength RSA私钥运算后结果长度。长度满足(RSA公钥模长+7/8)
*
* Return:       0 for success, other is error
* Description:
*
* Date:         2015.11.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalPrivateKeyOperation_RSA_EX(
       void         *hSessionHandle, 
       unsigned int  uiKeyIndex, 
       unsigned int  signKeyType, 
       unsigned char *pucDataInput, 
       unsigned int  uiInputLength, 
       unsigned char *pucDataOutput, 
       unsigned int  *puiOutputLength);

/***************************************************************************
* Subroutine: SDF_InternalDecrypt_ECC
* Function:  内部或ECC私钥对数据进行解密
* Input:      
*   @hSessionHandle  已打开密码设备会话句柄
*   @uiISKIndex      ECC密钥索引，范围(1-64) 
*   @signKeyType     密钥类型，1-SGD_SM2_1使用签名密钥解密，其它（3-SGD_SM2_3）使用加密密钥解密。
*   @pucEncData      待解密的ECC密文
*
* Output:     
*   @pucData         解密后的明文；
*   @uiDataLength    解密后的明文长度；
*
* Return:       0 for success, other is error
* Description: 1. 该运算需要授权。
*
* Date:         2015.11.11
*
* ModifyRecord:
* *************************************************************************/
SDFAPI int 
SDF_InternalDecrypt_ECC(
        void             * hSessionHandle, 
        unsigned int       uiISKIndex, 
        unsigned int       signKeyType, 
        ECCCipher        * pucEncData, 
        unsigned char    * pucData, 
        unsigned int     * puiDataLength);
#endif

#ifdef __cplusplus
}
#endif

#define SDR_OK                               0x00000000	 // 操作成功
#define SDR_BASE                             0x01000000  // 错误码基础值
#define SDR_UNKNOWERR             SDR_BASE + 0x00000001	 // 未知错误
#define SDR_NOTSUPPORT            SDR_BASE + 0x00000002	 // 不支持的接口调用
#define SDR_COMMFAIL              SDR_BASE + 0x00000003	 // 与设备通信失败
#define SDR_HARDFAIL              SDR_BASE + 0x00000004	 // 运算模块无响应
#define SDR_OPENDEVICE            SDR_BASE + 0x00000005	 // 打开设备失败
#define SDR_OPENSESSION           SDR_BASE + 0x00000006	 // 创建会话失败
#define SDR_PARDENY               SDR_BASE + 0x00000007	 // 无私钥使用权限
#define SDR_KEYNOTEXIST           SDR_BASE + 0x00000008	 // 不存在的密钥调用
#define SDR_ALGNOTSUPPORT         SDR_BASE + 0x00000009	 // 不支持的算法调用
#define SDR_ALGMODNOTSUPPORT      SDR_BASE + 0x0000000A	 // 不支持的算法模式调用
#define SDR_PKOPERR               SDR_BASE + 0x0000000B	 // 公钥运算失败
#define SDR_SKOPERR               SDR_BASE + 0x0000000C	 // 私钥运算失败
#define SDR_SIGNERR               SDR_BASE + 0x0000000D	 // 签名运算失败
#define SDR_VERIFYERR             SDR_BASE + 0x0000000E	 // 验证签名失败
#define SDR_SYMOPERR              SDR_BASE + 0x0000000F	 // 对称算法运算失败
#define SDR_STEPERR               SDR_BASE + 0x00000010	 // 多步运算步骤错误
#define SDR_FILESIZEERR           SDR_BASE + 0x00000011	 // 文件长度超出限制
#define SDR_FILENOEXIST           SDR_BASE + 0x00000012	 // 指定的文件不存在
#define SDR_FILEOFSERR            SDR_BASE + 0x00000013	 // 文件起始位置错误
#define SDR_KEYTYPEERR            SDR_BASE + 0x00000014	 // 密钥类型错误
#define SDR_KEYERR                SDR_BASE + 0x00000015	 // 密钥错误
#define SDR_ENCDATAERR            SDR_BASE + 0x00000016	 // ECC密钥密文
#define SDR_RANDERR               SDR_BASE + 0x00000017	 // 随机数产生错误
#define SDR_PRKRERR               SDR_BASE + 0x00000018	 // 私钥使用权限获取失败
#define SDR_MACERR                SDR_BASE + 0x00000019	 // MAC运算失败
#define SDR_FILEEXITS             SDR_BASE + 0x0000001A	 // 指定的文件已经存在
#define SDR_FILEWRITEERR          SDR_BASE + 0x0000001B	 // 文件写错误
#define SDR_NUBUFFER              SDR_BASE + 0x0000001C	 // 存储空间不足
#define SDR_INARGERR              SDR_BASE + 0x0000001D	 // 输入参数错误
#define SDR_OUTARGERR             SDR_BASE + 0x0000001E	 // 输出参数错误


#define SDR_HANDLE_CLOSED         SDR_BASE + 0x0000001F //函数执行过程中，该会话已经关闭
#define SDR_HANDLE_COUNT          SDR_BASE + 0x00000020 //打开的会话太多
#define SDR_HANDLE_INVALID        SDR_BASE + 0x00000021 //指定的会话句柄无效
#define SDR_LOGIN_FAILED          SDR_BASE + 0x00000022 //获取私钥使用权限失败
#define SDR_LOGIN_REPEAT          SDR_BASE + 0x00000023 //获取私钥使用权限重复
#define SDR_NOT_LOGIN             SDR_BASE + 0x00000024 //私钥使用权限未获取
#define SDR_INPUT_LEN_ERROR       SDR_BASE + 0x00000025 //输入参数长度指示错误
#define SDR_KEYID_INVALID         SDR_BASE + 0x00000026 //指定的密钥号非法
#define SDR_MECHANISM_INVALID     SDR_BASE + 0x00000027 //机制无效
#define SDR_NOT_INITIALIZED       SDR_BASE + 0x00000028 //未调用初始化
#define SDR_ALREADY_INITIALIZED   SDR_BASE + 0x00000029 //初始化已调用
#define SDR_DEVICEHANDLE_INVALID  SDR_BASE + 0x0000002A //设备句柄无效


#define SDR_DEVICE_ERROR		      SDR_BASE + 0x0000002B
#define SDR_KEY_MEM_FULL		      SDR_BASE + 0x0000002C
#define SDR_KEY_GEN_FAIL		      SDR_BASE + 0x0000002D //产生密钥失败
#define SDR_FILE_OPR_ERR		      SDR_BASE + 0x0000002E
#define SDR_KEY_NO_EXIST		      SDR_BASE + 0x0000002F
#define SDR_MALLOC_ERR			      SDR_BASE + 0x00000030
#define SDR_DATA_INVALID		      SDR_BASE + 0x00000031
#define SDR_SM2_KEYBITS			      SDR_BASE + 0x00000032
#define SDR_SESSION_INIT              SDR_BASE + 0x00000033
#define SDR_RANDOM_GEN                SDR_BASE + 0x00000034 //产生随机数
#define SDR_KEYPAIR_LENGTH            SDR_BASE + 0x00000035 //非对称密钥的指数长度
#define SDR_PADDING_RSA               SDR_BASE + 0x00000036 // RSA padding 错误
#define SDR_UNPADDING_RSA             SDR_BASE + 0x00000037 // RSA unpadding 错误
#define SDR_HANDLE_SYMKEY_INVALID     SDR_BASE + 0x00000038 // 会话密钥句柄无效
#define SDR_READ_INI_ERR              SDR_BASE + 0x00000039 // 读取配置文件失败
#define SDR_HEADBEAT_TEST_ERR         SDR_BASE + 0x00000040 // 连接密码机心跳测试失败
#define SDR_DATA_TRANS_ERR            SDR_BASE + 0x00000041 // 数据传输错误

#define SDR_DATA_DEVINFO_ERR          SDR_BASE + 0x00000042 // 设备信息获取失败
#define SDR_DATA_GEN_RANDOM_ERR       SDR_BASE + 0x00000043 // 随机数生成失败
#define SDR_DATA_INDEX_OUT_ERR        SDR_BASE + 0x00000044 // 索引超出范围
#define SDR_HANDLE_INPUT_INVALID      SDR_BASE + 0x00000045 // 输入的句柄无效
#define SDR_DATA_PRI_ACCESS_ERR       SDR_BASE + 0x00000046 // 获取内部私钥权限失败
#define SDR_DATA_EXP_PUBKEY_ERR       SDR_BASE + 0x00000047 // 导出公钥失败
#define SDR_DATA_GEN_SESKEY_ERR       SDR_BASE + 0x00000048 // 生成会话密钥失败
#define SDR_DATA_DIGI_ENEV_ERR        SDR_BASE + 0x00000049 // 数字信封转换失败 
#define SDR_DATA_GEN_AGREE_KEY_ERR    SDR_BASE + 0x00000050 // 生成协商密钥失败
#define SDR_DATA_IM_RSA_KEY_ERR       SDR_BASE + 0x00000051 // 导入RSA密钥对失败
#define SDR_DATA_IM_ECC_KEY_ERR       SDR_BASE + 0x00000052 // 导入ECC密钥对失败
#define SDR_DATA_IM_ECC_ENC_ERR       SDR_BASE + 0x00000053 // ECC公钥加密失败
#define SDR_DATA_IV_SYM_ERR           SDR_BASE + 0x00000054 // IV数据错误
#define SDR_DATA_HASH_INIT_ERR        SDR_BASE + 0x00000055 // 杂凑运算初始化失败
#define SDR_DATA_HASH_OP_ERR          SDR_BASE + 0x00000056 // 杂凑运算失败
#define SDR_DATA_CREATE_FILE_ERR      SDR_BASE + 0x00000057 // 创建文件失败
#define SDR_DATA_DELETE_FILE_ERR      SDR_BASE + 0x00000058 // 删除文件失败
/* sm2公钥或者私钥bits长度错误 */

#endif // _TASS_SDF_H_
