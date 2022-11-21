/*----------------------------------------------------------------------|
|	SDF.h -   The header file of SDF.c 									
|	Version :     1.0												
|	Author:       by wyf.								
| Description:  �����豸Ӧ�ú���ͷ�ļ������ݹ��ܹ淶���塣
|               �μ���GM/T 0018 �����豸Ӧ�ýӿڹ淶��
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
 * NETCA �����ڹ㶫��֤ͨ���Ƶ������ӿ�
 * SDF_InternalPrivateKeyOperation_RSA_EX
 * SDF_InternalDecrypt_ECC
 * �޸�SDF_GetPrivateKeyAccessRight����Ϊ���ܺ���
*/
#define NETCA

// API����򿪵����Ự����
#define MAX_SESSIONS     2048   

// �Գ��㷨����

#define SGD_SM1_ECB	     0x00000101	// SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC	     0x00000102	// SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB	     0x00000104	// SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB	     0x00000108	// SM1�㷨OFB����ģʽ
#define SGD_SM1_MAC	     0x00000110	// SM1�㷨MAC�㷨
#define SGD_SSF33_ECB    0x00000201	// SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC    0x00000202	// SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB    0x00000204	// SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB    0x00000208	// SSF33�㷨OFB����ģʽ
#define SGD_SSF33_MAC    0x00000210	// SSF33�㷨MAC�㷨
#define SGD_SM4_ECB	     0x00000401	// SM4�㷨ECB����ģʽ
#define SGD_SM4_CBC	     0x00000402	// SM4�㷨CBC����ģʽ
#define SGD_SM4_CFB	     0x00000404	// SM4�㷨CFB����ģʽ
#define SGD_SM4_OFB	     0x00000408	// SM4�㷨OFB����ģʽ
#define SGD_SM4_MAC	     0x00000410	// SM4�㷨MAC�㷨

#define SGD_ZUC_EEA3     0x00000801	// ZUC���֮�ӽ����㷨128-EEA3
#define SGD_ZUC_EIA3     0x00000802	// ZUC���֮MAC�㷨128-EIA3
#define SGD_RC4_STREAM   0x00000804 //RC4�㷨

// �ǶԳ��㷨����
#define SGD_RSA          0x00010000	// RSA�㷨 

/*��ӻ���*/
#define SGD_RSA_SIGN_EX	 0x00010001  //����򵼳�RSAǩ������֤��Կʱʹ��
#define SGD_RSA_ENC_EX   0x00010002  //����򵼳�RSA���ܻ������Կʱʹ��

#define SGD_SM2	         0x00020100	// SM2��Բ���������㷨


#define SGD_SM2_1        0x00020200	// SM2��Բ����ǩ���㷨
#define SGD_SM2_2        0x00020400	// SM2��Բ������Կ����Э��
#define SGD_SM2_3        0x00020800	// SM2��Բ���߼����㷨

// ժҪ�㷨
#define SGD_SM3	         0x00000001	// SM3�Ӵ��㷨 SM3-256
#define SGD_SHA1         0x00000002	// SHA_1�Ӵ��㷨
#define SGD_SHA256       0x00000004	// SHA_256�Ӵ��㷨

/* ECC�������� */
//NIST��׼
#define NIST_FP_160           1

//NIST��׼
#define NIST_FP_192           2
#define NIST_FP_224           3
#define NIST_FP_256           4

//���ֱܾ�׼
#define OSCCA_FP_192          5
#define OSCCA_FP_256          6
#define OSCCA_NEWFP_256       7

#define PARAID       OSCCA_NEWFP_256


// �ṹ�嶨��
/***************************************************************************
* name:   �豸��Ϣ�ṹ��
* number: 
*    @IssuerName��    �豸��������
*    @DeviceName��    �豸�ͺ�
*    @DeviceSerial��  �豸��ţ����������ڣ�8�������κţ�3������ˮ�ţ�5��
*    @DeviceVersion�� �����豸�ڲ��汾��
*    @DeviceVersion�� �����豸֧�ֵĽӿڹ淶�汾��
*    @AsymAlgAbility��ǰ4�ֽڱ�ʾ֧�ֵ��㷨����ʾ����Ϊ�ǶԳ��㷨��λ����
*                     �������4�ֽڱ�ʾ�㷨���ģ������ʾ����Ϊ֧��ģ����λ�����
*    @SymAlgAbility�� ����֧�ֵĶԳ��㷨����ʾ����Ϊ�Գ��㷨��ʶ��λ��������
*    @HashAlgAbility������֧�ֵ��Ӵ��㷨����ʾ����Ϊ�Ӵ��㷨��ʶ��λ��������
*    @BufferSize��    ֧�ֵ�����ļ��洢�ռ䣨��λ�ֽڣ�
*    @Dmkcv:          DMKУ��ֵ

* Description������SDF_GetDeviceInfoʹ�ã����ڻ�ȡ�豸��Ϣ
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

// RSA �ṹ��궨��
#define RSAref_MAX_BITS    4096
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)


/***************************************************************************
* name:   RSA��Կ�ṹ��
* number: 
*    @bits��          ģ������������
*    @m��             RSA��ԿģN
*    @e��             RSA��Կָ��E
*
* Description��RSA��ԿĿǰ֧�ֵ����ģ��Ϊ4096��
*              m��e��BUFFER���ݲ��ú���뷽ʽ
* *************************************************************************/
typedef struct RSArefPublicKey_st {
    unsigned int     bits;
    unsigned char    m[RSAref_MAX_LEN];
    unsigned char    e[RSAref_MAX_LEN];
} RSArefPublicKey;

/***************************************************************************
* name:   RSA˽Կ�ṹ��
* number: 
*    @bits��          ģ������������
*    @m��             RSA��ԿģN
*    @e��             RSA��Կָ��E
*    @d��             RSA˽Կָ��D
*    @prime[0]��      ����P
*    @prime[1]��      ����Q
*    @pexp[0]��       (D % (P - 1) )
*    @pexp[1]��       (D % (Q - 1) )
*    @coef��          (1 / (Q % P) )
*
* Description��RSA��ԿĿǰ֧�ֵ����ģ��Ϊ2048��
*              m��e��d��prime��pexp��coef��BUFFER���ݲ��ú���뷽ʽ
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

// ECC��Կ�궨��
#define ECCref_MAX_BITS    512 
#define ECCref_MAX_LEN     ((ECCref_MAX_BITS+7) / 8)

/***************************************************************************
* name:  ECC��Կ�ṹ��
* number: 
*    @bits��          ģ������������
*    @x��             ��Կx����
*    @y��             ��Կy����
*
* Description��SM2��Կģ��Ϊ256
*              x��y��BUFFER���ݲ��ú����ķ�ʽ
* *************************************************************************/
typedef struct ECCrefPublicKey_st {
    unsigned int     bits;
    unsigned char    x[ECCref_MAX_LEN]; 
    unsigned char    y[ECCref_MAX_LEN]; 
} ECCrefPublicKey;

/***************************************************************************
* name:  ECC˽Կ�ṹ��
* number: 
*    @bits��          ģ������������
*    @D��             ˽Կ
*
* Description��SM2��Կģ��Ϊ256
*              D��BUFFER���ݲ��ú���뷽ʽ
* *************************************************************************/
typedef struct ECCrefPrivateKey_st
{
    unsigned int     bits;
    unsigned char    D[ECCref_MAX_LEN];
} ECCrefPrivateKey;

// ECC��Կ������󳤶�
#define ECC_CIPHER_MAX	1912
/***************************************************************************
* name:  ECC���Ľṹ��
* number: 
*    @x��          ��y�����Բ�����ϵĵ�(x, y)
*    @y��          ��x�����Բ�����ϵĵ�(x, y)
*    @M��          ���ĵ�SM3�Ӵ�ֵ
*    @L��          �������ݳ���
*    @C��          ��������,�֧��1912�ֽ�
*
* Description��ECC��Կ�ӽ�������ʱʹ��
*              �������ݲ���ǰ���뷽ʽ
* *************************************************************************/
typedef struct ECCCipher_st {
    unsigned char    x[ECCref_MAX_LEN];
    unsigned char    y[ECCref_MAX_LEN];
    unsigned char    M[32];
    unsigned int     L;
    unsigned char    C[ECC_CIPHER_MAX];
} ECCCipher;

/***************************************************************************
* name:  ECCǩ���ṹ��
* number: 
*    @r��          ǩ��r����
*    @s��          ǩ��s����
*
* Description��ECC��Կǩ��(��֤ǩ��)����ʱʹ��
* *************************************************************************/
typedef struct ECCSignature_st {
    unsigned char r[ECCref_MAX_LEN];	
    unsigned char s[ECCref_MAX_LEN];	
} ECCSignature;

/***************************************************************************
* name:  ��ԿЭ�̵���������
* number: 
*    @pucSelfTmpPublicKey��            ECC��Կ
*    @pucSelfTmpPrivateKey��           ECC˽Կ
*
* Description��ECC��Կǩ��(��֤ǩ��)����ʱʹ��
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

// �����ӿ�
#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************
* Subroutine: SDF_OpenDevice
* Function:   �������豸
* Input:      
*   ��  
* 
* Output:     
*   @phDeviceHandle ���ص��豸��� 
*
* Return:       0 for success, other is error
* Description:  API��ʼ����������ʼ�������豸����ʼ��API�ڲ���Դ��
*               ����phDeviceHandle�豸�����
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int
SDF_OpenDevice  ( void  ** phDeviceHandle );

/***************************************************************************
* Subroutine: SDF_CloseDevice
* Function:   �ر������豸���ͷ������Դ
* Input:      
*   @hDeviceHandle  �򿪵������豸���  
* 
* Output:     
*    
*
* Return:       0 for success, other is error
* Description:  �ͷ��豸���ڲ�API��Դ��
*               
* Date:         2014.05.11
* ModifyRecord:
* *************************************************************************/
SDFAPI int
SDF_CloseDevice ( void   * hDeviceHandle  );

/***************************************************************************
* Subroutine: SDF_OpenSession
* Function:   �����������豸�ĻỰ
* Input:      
*   @hDeviceHandle   �Ѵ򿪵������豸���  
*    
* Output:     
*   @phSessionHandle �����������豸�������»Ự��� 
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
* Function:   �ر��������豸�����ĻỰ�����ͷ���Դ
* Input:      
*   @hSessionHandle   �Ѵ������豸�Ự���  
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
* Function:   ��ȡ�����豸��������
* Input:      
*   @hSessionHandle   �Ѵ������豸�Ự���  
*    
* Output:     
*   @pstDeviceInfo   �����豸����������Ϣ�����豸��Ϣ�ṹ���� 
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
* Function:   ����ָ�����ȵ�����������
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiLength        ��������������� ���2048
*    
* Output:     
*   @pucRandom       ������ָ�룬���ڴ�Ų����������
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
* Function:   ��ȡ�����豸�ڲ��洢ָ������˽Կ��ʹ��Ȩ��
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyType       ��Կ���� SGD_RSA, SGD_SM2
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*   @pucPassword     ˽ԿȨ�޿�����
*   @uiPwdLength     ˽ԿȨ�޿����볤�ȡ���Χ[8-16�ֽ�]
*
* Output:     
*   @
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �ڲ��ǶԳ���Կ��RSA or SM2����˽Կ����ǰʹ�á�˽Կ������ɺ�
*                  �����SDF_ReleasePrivateKeyAccessRight�����ͷ�˽Կʹ��Ȩ�ޣ�
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
* Function:   �ͷ������豸�ڲ��洢ָ������˽Կ��ʹ��Ȩ��
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyType       ��Կ����  SGD_RSA, SGD_SM2
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*
* Output:     
*   @
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. ˽Կ������ɺ󣬵��øú����ͷ�˽Կʹ��Ȩ�ޣ�
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
* Function:   ��ȡ�����豸�ڲ��洢ָ������RSAǩ����Կ
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*
* Output:     
*   @pucPublicKey    ��ȡ��RSAǩ����Կ���ṹ�����RSA��Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. ͬһ����λ�ö�Ӧ2����Կ��ǩ����Կ�ͼ�����Կ��
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
* Function:   ��ȡ�����豸�ڲ��洢ָ������RSA���ܹ�Կ
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*
* Output:     
*   @pucPublicKey    ��ȡ��RSA���ܹ�Կ���ṹ�����RSA��Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. ͬһ����λ�ö�Ӧ2����Կ��ǩ����Կ�ͼ�����Կ��
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
* Function:   ͨ�������豸����ָ��ģ����RSA������Կ�ԡ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyBits       ָ������Կģ������Χ[1024-2048������]
*
* Output:     
*   @pucPublicKey    RSA��Կ���ṹ�����RSA��Կ�ṹ�嶨��
*   @pucPrivateKey   RSA˽Կ���ṹ�����RSA˽Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  ������RSA��Կ��ָ��Ϊ65537
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
* Function:   ͨ�������豸�����Ự��Կ����ʹ���ڲ�RSA��Կ���������
*             ͬʱ���ػỰ��Կ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiIPKIndex      �����豸�ڲ�RSA���ܹ�Կ��������Χ[1-n]
*   @uiKeyBits       ָ���Ự��Կ���ȡ���Χ[64��128��192������]
*
* Output:     
*   @pucKey          �Ự��Կ���ģ��ڲ�RSA��Կ����
*   @puiKeyLength    �Ự��Կ���ĳ��ȣ�����ȡ�����ڲ�RSA��Կģ��
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �Ự��Կ����ͨ��Ϊ128[SM1\SM4]����������Ϊ�Ժ���չʹ�ã�
*               3. RSA��Կ���ܻỰ��Կʱ����䷽ʽ��ѭPKCS#1 V1.5��׼��
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
* Function:   ͨ�������豸�����Ự��Կ����ʹ������RSA��Կ���������
*             ͬʱ���ػỰ��Կ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyBits       ָ���Ự��Կ���ȡ���Χ[64��128��192������]
*   @pucPublicKey    RSA��Կ�����ڼ��ܻỰ��Կ
*
* Output:     
*   @pucKey          �Ự��Կ���ģ�����RSA��Կ����
*   @puiKeyLength    �Ự��Կ���ĳ��ȣ�����ȡ��������RSA��Կģ��
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. �Ự��Կ����ͨ��Ϊ128[SM1\SM4]����������Ϊ�Ժ���չʹ�ã�
*               2. RSA��Կ���ܻỰ��Կʱ����䷽ʽ��ѭPKCS#1 V1.5��׼��
*               3. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   ����Ự��Կ�������豸��ָ��������ͬʱ���ػỰ��Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      �����豸�ڲ�RSA����˽Կ���������ڽ��ܻỰ��Կ����Χ[1-n]
*   @pucKey          �Ự��Կ����
*   @uiKeyLength     �Ự��Կ���ĳ��ȣ��ֽ��������ȵ���(RSA��Կģ��+7/8)
*
* Output:     
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. RSA��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. RSA��Կ���ܻỰ��Կʱ����䷽ʽ��ѭPKCS#1 V1.5��׼��
*               3. �Ự��Կ���ģ�ʹ���ڲ�RSA����˽Կ���н��ܡ�
*               4. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   �������ĻỰ��Կ��ͬʱ������Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucKey          ������ָ�룬���ڴ���������Կ����
*   @puiKeyLength    �������Կ���ĳ���
*
* Output:     
*   @phKeyHandle     �Ự��Կ���
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
* Function:   ���ڲ�RSA���ܹ�Կ���ܵĻỰ��ԿתΪ����RSA��Կ���ܣ������������ŷ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      �����豸�ڲ�RSA����˽Կ���������ڽ��ܻỰ��Կ����Χ[1-n]
*   @pucPublicKey    RSA��Կ�����ڼ��ܻỰ��Կ
*   @pucDEInput      �Ự��Կ���ģ��ڲ�RSA��Կ����
*   @uiDELength      �Ự��Կ���ĳ��ȣ��ֽ��������ȵ���(�ڲ�RSA��Կģ��+7/8)
*
* Output:     
*   @pucDEOutput     �Ự��Կ���ģ�����RSA��Կ����
*   @puiDELength     �Ự��Կ���ĳ��ȣ��ֽ��������ȵ���(����RSA��Կģ��+7/8)
*
* Return:       0 for success, other is error
* Description:  1. RSA��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. RSA��Կ���ܻỰ��Կʱ����䷽ʽ��ѭPKCS#1 V1.5��׼��
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
* Function:   ��ȡ�����豸�ڲ��洢ָ������SM2ǩ����Կ
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*
* Output:     
*   @pucPublicKey    ��ȡ��SM2ǩ����Կ���ṹ�����SM2��Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. ͬһ����λ�ö�Ӧ2����Կ��ǩ����Կ�ͼ�����Կ��
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
* Function:   ��ȡ�����豸�ڲ��洢ָ������SM2���ܹ�Կ
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*
* Output:     
*   @pucPublicKey    ��ȡ��SM2���ܹ�Կ���ṹ�����SM2��Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. ͬһ����λ�ö�Ӧ2����Կ��ǩ����Կ�Ժͼ�����Կ�ԣ�
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
* Function:   ͨ�������豸����ָ�����ͺ�ģ����SM2������Կ�ԡ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiAlgID         �㷨ID;PARAID
*   @uiKeyBits       ָ����SM2��Կģ������Χ[256]
* Output:     
*   @pucPublicKey    SM2��Կ���ṹ�����SM2��Կ�ṹ�嶨��
*   @pucPrivateKey   SM2˽Կ���ṹ�����SM2˽Կ�ṹ�嶨��
*
* Return:       0 for success, other is error
* Description:  Ŀǰ�ú�����֧�ֹ���SM2��Կ������ģ����֧��256���ء���������
*               ��Կ��NIST��׼ECC��Կ��w��֧�֡�
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
* Function:   ͨ�������豸�����Ự��Կ����ʹ���ڲ�SM2���ܹ�Կ���������
*             ͬʱ���ػỰ��Կ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiIPKIndex      �����豸�ڲ�SM2���ܹ�Կ��������Χ[1-n]
*   @uiKeyBits       ָ���Ự��Կ���ȡ���Χ[64��128��192������]
*
* Output:     
*   @pucKey          �Ự��Կ���Ľṹ���ڲ�SM2���ܹ�Կ���ܡ�
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �Ự��Կ����ͨ��Ϊ128[SM1\SM4]���أ���������Ϊ�Ժ���չʹ�ã�
*               3. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   ͨ�������豸�����Ự��Կ����ʹ������SM2��Կ���������
*             ͬʱ���ػỰ��Կ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyBits       ָ���Ự��Կ���ȡ���Χ[64��128��192������]
*   @uiAlgID         ����ECC��Կ�㷨��ʶ����Χ[SGD_SM2]
*   @pucPublicKey    SM2��Կ�����ڼ��ܻỰ��Կ
*
* Output:     
*   @pucKey          �Ự��Կ���Ľṹ������SM2��Կ���ܡ�
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �Ự��Կ����ͨ��Ϊ128[SM1\SM4]����������Ϊ�Ժ���չʹ�ã�
*               3. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   ����Ự��Կ�������豸��ָ��������ͬʱ���ػỰ��Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      �����豸�ڲ�SM2����˽Կ���������ڽ��ܻỰ��Կ����Χ[1-n]
*   @pucKey          �Ự��Կ���Ľṹ��
*
* Output:     
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. SM2��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               3. �Ự��Կ���ģ�ʹ���ڲ�SM2����˽Կ���н��ܡ�
*               4. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   ���ڲ�SM2���ܹ�Կ���ܵĻỰ��ԿתΪ����SM2��Կ���ܣ������������ŷ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �����豸�ڲ�SM2����˽Կ���������ڽ��ܻỰ��Կ����Χ[1-n]
*   @uiAlgID         ����ECC��Կ�㷨��ʶ����Χ[SGD_SM2]
*   @pucPublicKey    SM2��Կ�����ڼ��ܻỰ��Կ
*   @pucEncDataIn    �Ự��Կ���Ľṹ�壬�ڲ�SM2���ܹ�Կ����
*
* Output:     
*   @pucEncDataOut   �Ự��Կ���Ľṹ�壬����SM2��Կ����
*
* Return:       0 for success, other is error
* Description:  1. SM2��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �����㷨��֧�ֹ��ܱ�׼��SM2�㷨�������㷨�ݲ�֧�֣�
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
* Function:   ���𷽻Ự��ԿЭ�̲�������������
*             ʹ��SM2��ԿЭ���㷨��Ϊ����Ự��Կ������Э�̲�����ͬʱ����ָ��
*             ����λ�õ�SM2��Կ����ʱSM2��Կ��Э�̾����
* Input:      
*   @hSessionHandle         �Ѵ������豸�Ự���
*   @uiISKIndex             �����豸�ڲ�SM2����˽Կ����������Э�̻Ự��Կ����Χ[1-n]
*   @uiKeyBits              Э�̻Ự��Կ���ȡ���Χ[64��128��192������]
*   @pucSponsorID           ����Э�̵ķ��𷽵�IDֵ��
*   @uiSponsorIDLength      ����Э�̵ķ��𷽵�IDֵ���ȡ���Χ[1-128�ֽ���]
*
* Output:     
*   @pucSponsorPublicKey    ����ָ������[uiISKIndex]SM2�Ĺ�Կ�ṹ
*   @pucSponsorTmpPublicKey ������ʱSM2�Ĺ�Կ�ṹ
*   @phAgreementHandle      Э�̾�������ڼ���Э�̻Ự��Կ
*
* Return:       0 for success, other is error
* Description:  1. ΪЭ�̻Ự��Կ��Э�̵ķ������ȵ��øú�����
*               2. �ú��������ؽ��pucSponsorPublicKey��pucSponsorTmpPublicKey
*                  ���������pucSponsorID��uiSponsorIDLength����Ӧ����
*                  SDF_GenerateAgreementDataAndKeyWithECC����ʹ�á�
*               3. ��Ӧ��SDF_GenerateAgreementDataAndKeyWithECC�������ݷ��𷽵�Э�̲�����
*                  ������Ӧ����Э�̲����ͻỰ��Կ�����
*               4. ����ʹ��SDF_GenerateKeyWithECC����������Ӧ��Э�̲�������Ự��Կ�����
*               5. ����phAgreementHandle������ʱЭ����Ϣ���ɺ�����ʼ�����ڷ��𷽵���
*                  SDF_GenerateKeyWithECC����ʱʹ�á�
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
* Function:   ����ʹ�ú������㷨ʵ�ֲμ����ܱ�׼ GM/T 0009
*             ʹ��ECC��ԿЭ���㷨��ʹ������Э�̾������Ӧ����Э�̲�������Ự��Կ��
*             ͬʱ���ػỰ��Կ�����
* Input:      
*   @hSessionHandle          �Ѵ������豸�Ự���
*   @pucResponseID           ����Э�̵���Ӧ����IDֵ��
*   @uiResponseIDLength      ����Э�̵���Ӧ����IDֵ���ȡ���Χ[1-128�ֽ���]
*   @pucResponsePublicKey    ����Э�̵���Ӧ����Կ�ṹ
*   @pucResponseTmpPublicKey ����Э�̵���Ӧ����ʱSM2�Ĺ�Կ�ṹ
*   @phAgreementHandle       Э�̾������SDF_GenerateAgreementDataWithECC����
*
* Output:     
*   @phKeyHandle             ����Э�̵ĻỰ��Կ���
*
* Return:       0 for success, other is error
* Description:  1. Э�̵ķ��𷽻�ȡ��Ӧ����Э�̲�������ñ�����������Ự��Կ��
*               2. �������д�(��Ӧ��)�����Ĳ�����������SDF_GenerateAgreementDataAndKeyWithECC
*                  �����ṩ��
*               3. ����phKeyHandleΪЭ�̵ĻỰ��Կ�������ʹ��ʱ��Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   ��Ӧ��ʹ�ú������㷨ʵ�ֲμ����ܱ�׼ GM/T 0009
*             ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ��ͬʱ���ز�����Э��
*             ��������Կ�����
* Input:      
*   @hSessionHandle         �Ѵ������豸�Ự���
*   @uiISKIndex             �����豸�ڲ�SM2����˽Կ����������Э�̻Ự��Կ����Χ[1-n]
*   @uiKeyBits              Э�̻Ự��Կ���ȡ���Χ[64��128��192������]
*   @pucResponseID          ����Э�̵���Ӧ��IDֵ��
*   @uiResponseIDLength     ����Э�̵���Ӧ��IDֵ���ȡ���Χ[1-128�ֽ���]
*   @pucSponsorID           ����Э�̵ķ���IDֵ��
*   @uiSponsorIDLength      ����Э�̵ķ���IDֵ���ȡ���Χ[1-128�ֽ���]
*   @pucSponsorPublicKey    ����Э�̵ķ���ECC��Կ�ṹ��
*   @pucSponsorTmpPublicKey ����Э�̵ķ�����ʱECC��Կ�ṹ
*
* Output:     
*   @pucResponsePublicKey    ��Ӧ��ָ������[uiISKIndex]SM2�Ĺ�Կ�ṹ
*   @pucResponseTmpPublicKey ��Ӧ����ʱSM2�Ĺ�Կ�ṹ
*   @phKeyHandle             ��Ӧ��Э�̵ĻỰ��Կ���
*
* Return:       0 for success, other is error
* Description:  1. �ú���Ϊ��Ӧ�����ú�������ԿЭ��ʱ��ֻ�����һ�θú������ɣ�
*               2. �������д�(����)�����Ĳ�����������SDF_GenerateAgreementDataWithECC
*                  �����ṩ��
*               3. ����phKeyHandleΪЭ�̵ĻỰ��Կ�������ʹ��ʱ��Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:   �����Ự��Կʹ����Կ������Կ���������ͬʱ���ػỰ��Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyBits       ָ���Ự��Կ���ȡ���Χ[64��128��192������]
*   @uiAlgID         KEK���ܻỰ��Կ�㷨��ʶ��
*                    ��Χ[SGD_SM1_ECB��SGD_SM4_ECB]
*   @uiKEKIndex      �����豸�ڲ�KEK��Կ���������ڼ��ܻỰ��Կ����Χ[1-n]
*
* Output:     
*   @pucKey          �Ự��Կ���ģ����ڲ�KEK����
*   @puiKeyLength    �Ự��Կ���ĳ��ȣ��ֽ���;
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. KEK��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �����㷨ʹ�õ�ECB�㷨
*               4. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:  ����Ự��Կ����KEK���ܣ�ͬʱ���ػỰ��Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiAlgID         KEK���ܻỰ��Կ�㷨��ʶ��
*                    ��Χ[SGD_SM1_ECB��SGD_SM4_ECB]
*   @uiKEKIndex      �����豸�ڲ�KEK��Կ���������ڽ��ܻỰ��Կ����Χ[1-n]
*   @pucKey          �Ự��Կ���ģ����ڲ�KEK����
*   @puiKeyLength    �Ự��Կ���ĳ��ȣ��ֽ���;
*
* Output:     
*   @phKeyHandle     �Ự��Կ���
*
* Return:       0 for success, other is error
* Description:  1. KEK��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
*               2. �����㷨ʹ�õ�ECB�㷨
*               4. �Ự��Կ��������ڼӽ������ݣ�ʹ�ú���Ҫ����
*                  SDF_DestoryKey�������٣�
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
* Function:  ���ٻỰ��Կ���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @hKeyHandle      �Ự��Կ�����ͨ��������������
*
* Output:     
*   no.
*
* Return:       0 for success, other is error
* Description:  1. �ú����������ٻỰ��Կ�������豸�ڲ���Կ�������Ҫ���øú�����
*               2. �����Ự��Կ�������Ҫ���ٵĺ������£�
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
* Function:  ����RSA��Կ�����ݽ�������
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucPublicKey    RSA��Կ�ṹ�壬���ڶ�������������Կ���㡣
*   @pucDataInput    ��������������ݡ�
*   @uiInputLength   ��������������ݳ��ȣ��ֽ��������ȱ���Ϊ(RSA��Կģ��+7/8)
*
* Output:     
*   @pucDataOutput   ��Կ�������
*   @puiOutputLength ��Կ����������ȡ���������(RSA��Կģ��+7/8)
*
* Return:       0 for success, other is error
* Description:  1. �������������ҪӦ�ò��װ�������ڲ���������
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
* Function:  �ڲ�ָ������RSAǩ����Կ�����ݽ�������
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢�Ĺ�Կ����ֵ����Χ[1-n]
*   @pucDataInput    ��������������ݡ�
*   @uiInputLength   ��������������ݳ��ȣ��ֽ��������ȱ���Ϊ(RSA��Կģ��+7/8)
*
* Output:     
*   @pucDataOutput   ��Կ�������
*   @puiOutputLength ��Կ����������ȡ���������(RSA��Կģ��+7/8)
*
* Return:       0 for success, other is error
* Description: 1. ����[uiKeyIndex]ֻ�����ڲ�ǩ����Կ
*              2. �������������ҪӦ�ò��װ�������ڲ���������
*              3. RSA��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
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
* Function:  �ڲ�ָ������RSAǩ��˽Կ�����ݽ�������
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*   @pucDataInput    ��������������ݡ�
*   @uiInputLength   ��������������ݳ��ȣ��ֽ��������ȱ���Ϊ(RSA��Կģ��+7/8)
*
* Output:     
*   @pucDataOutput   RSA˽Կ�������
*   @puiOutputLength RSA˽Կ����������ȡ���������(RSA��Կģ��+7/8)
*
* Return:       0 for success, other is error
* Description: 1. ����[uiKeyIndex]ֻ�����ڲ�ǩ��˽Կ
*              2. �������������ҪӦ�ò��װ�������ڲ���������
*              3. RSA��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
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
* Function:  �ڲ�ָ������ECCǩ��˽Կ�����ݽ���ǩ��
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      �豸�ڲ��洢��˽Կ����ֵ����Χ[1-n]
*   @pucData         ��ǩ���������ݵ��Ӵս����
*   @uiDataLength    ��ǩ�����������Ӵս������;
*
* Output:     
*   @pucSignature    ECCǩ���������(r || s)��ɣ��μ�ECCǩ���ṹ���壻
*
* Return:       0 for success, other is error
* Description: 1. �ڲ�ECC��Կʹ�õ��Ƕ�Ӧ������ǩ��˽Կ
*              2. ��ǩ��������λ�Ӵս��ֵ�������SM2ǩ������������ʹ�õ���
*                 ��ID�͹�Կ��SM3��ϣ���ֵ���μ�����GM/T 0009.
*              3. ECC��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
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
* Function:  �ⲿECC��Կ�����ݽ�����֤ǩ��
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiAlgID         �㷨ID��SM2��Կʹ��[PARAID].
*   @pucPublicKey    SM2��֤ǩ����Կ���ṹ�����SM2��Կ�ṹ�嶨��
*   @pucData         �������ݵ��Ӵս����
*   @uiDataLength    ���������Ӵս������;
*   @pucSignature    ECCǩ���������(r || s)��ɣ��μ�ECCǩ���ṹ���壻
*
* Output:     
*   ��
* Return:       0 for success, other is error
* Description: 1. ��������Ϊ�Ӵս��ֵ�������SM2ǩ������������ʹ�õ���
*                 ��ID�͹�Կ��SM3��ϣ���ֵ���μ�����GM/T 0009.
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
* Function:  �ڲ�ECCǩ����Կ�����ݽ�����֤ǩ��
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      �豸�ڲ��洢�Ĺ�Կ����ֵ����Χ[1-n]
*   @pucData         �������ݵ��Ӵս����
*   @uiDataLength    ���������Ӵս������;   
*   @pucSignature    ECCǩ���������(r || s)��ɣ��μ�ECCǩ���ṹ���壻
* 
* Return:       0 for success, other is error
* Description: 1. ��������Ϊ�Ӵս��ֵ�������SM2ǩ������������ʹ�õ���
*                 ��ID�͹�Կ��SM3��ϣ���ֵ���μ�����GM/T 0009.
*              2. �ڲ�ECC��Կʹ�õ��Ƕ�Ӧ������ǩ����Կ��
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
* Function:  �ⲿECC��Կ�����ݽ��м���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiAlgID         ���߱�ʶ��ʹ��PARAID.
*   @pucPublicKey    SM2��֤���ܹ�Կ���ṹ�����SM2��Կ�ṹ�嶨��
*   @pucData         �������ݡ�
*   @uiDataLength    �������ݳ���[1-1024];
*
* Output:     
*   @pucEncData      ECC���ܽ�����μ�ECC���ܽṹ���壻
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
* Function:  ʹ��ָ������Կ�����IV�����ݽ��м������㣬�Գ���Կ���ܡ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @hKeyHandle      ��Կ�������������Կ�������������������ľ����
*   @uiAlgID         �����㷨���㷨Ϊ��
*                       SGD_SM1_ECB��SGD_SM1_CBC��SGD_SM1_CFB��SGD_SM1_OFB
*                       SGD_SM4_ECB��SGD_SM4_CBC��SGD_SM4_CFB��SGD_SM4_OFB
*                        
*   @pucIV           �����IV���ݡ����㷨ΪCBC��CFB��OFB�㷨ʱ����
*   @pucData         �������ݡ�
*   @uiDataLength    �������ݳ��ȣ����ܳ���2048����������16�ֽڵı���;
*
* Output:     
*   @pucIV             ���ص�IV���ݣ����ڶ�����㡣���㷨ΪCBC��CFB��OFB�㷨ʱ����
*   @pucEncData        ���ܽ����
*   @puiEncDataLength  ���ܽ�����ȣ�
*
* Return:       0 for success, other is error
* Description: 1. �����������������ݽ�����䴦���������ݱ�������ָ���㷨���鳤��������
*              2. IV�����������ݣ�Ҳ�Ƿ������ݡ����㷨��ΪECBʱ���ڡ�
*              3. ���������Կ���Ϊ��Կ����ʱ����Կ�����ָ��ָ�������������ɡ�
*              4. ���������Կ���������Կ����ʱ��ʹ����������SDF_DestoryKey���ٸþ����
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
* Function:  ʹ��ָ������Կ�����IV�����ݽ��н������㣬�Գ���Կ���ܡ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @hKeyHandle      ��Կ�������������Կ�������������������ľ����
*   @uiAlgID         �����㷨���㷨Ϊ��
*                       SGD_SM1_ECB��SGD_SM1_CBC��SGD_SM1_CFB��SGD_SM1_OFB
*                       SGD_SM4_ECB��SGD_SM4_CBC��SGD_SM4_CFB��SGD_SM4_OFB
*                        
*   @pucIV           �����IV���ݡ����㷨ΪCBC��CFB��OFB�㷨ʱ����
*   @pucEncData      �����������ݡ�
*   @uiEncDataLength �����������ݳ��ȣ���������16�ֽڵı���;
*
* Output:     
*   @pucIV           ���ص�IV���ݣ����ڶ�����㡣���㷨ΪCBC��CFB��OFB�㷨ʱ����
*   @pucData         ���ܽ����
*   @puiDataLength   ���ܽ�����ȣ�
*
* Return:       0 for success, other is error
* Description: 1. ������������ݱ�������ָ���㷨���鳤��������
*              1. ���������Խ������ݽ���ȥ��䴦����ҪӦ�ò㴦��������ݣ�
*              2. IV�����������ݣ�Ҳ�Ƿ������ݡ����㷨��ΪECBʱ���ڡ�
*              3. ���������Կ���Ϊ��Կ����ʱ����Կ�����ָ��ָ�������������ɡ�
*              4. ���������Կ���������Կ����ʱ��ʹ����������SDF_DestoryKey���ٸþ����
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
* Function:  ʹ��ָ������Կ�����IV�����ݽ���MAC���㣬�Գ�MAC���㡣
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @hKeyHandle      ��Կ�������������Կ�������������������ľ����
*   @uiAlgID         MAC�㷨��ʶ���㷨Ϊ��
*                       SGD_SM1_MAC
*                       SGD_SM4_MAC
*                        
*   @pucIV           �����IV���ݣ�����MACʱʹ�á�
*   @pucData         �������ݡ�
*   @uiDataLength    �������ݳ��ȣ���������16�ֽڵı���;
*
* Output:     
*   @pucIV           ���ص�IV���ݣ����ڶ��MAC���㡣
*   @pucMAC          �������MAC�����
*   @puiMACLength    MAC������ȣ�
*
* Return:       0 for success, other is error
* Description: 1. ��������ݱ�������ָ���㷨���鳤����������
*              2. �������������ݽ�����䴦����ҪӦ�ò㴦��������ݣ�
*              3. IV�����������ݣ�Ҳ�Ƿ������ݣ�
*              4. ���������Կ���Ϊ��Կ����ʱ����Կ�����ָ��ָ�������������ɣ�
*              5. ���������Կ���������Կ����ʱ��ʹ����������SDF_DestoryKey���ٸþ����
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
* Function:  ժҪ��ʼ������������ʽժҪ�����һ����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiAlgID         ժҪ�㷨��ʶ����ѡ�㷨���£�
*                        SGD_SHA1��SGD_SHA256��SGD_SM3
*   @pucPublicKey    SM2ǩ����Կ�����㷨��ʶΪSGD_SM3ʱ��Ч
*   @pucID           ǩ��ID�����㷨��ʶΪSGD_SM3ʱ��Ч
*   @uiIDLength      ǩ��ID����.
*
* Output:     
*   ��
* Return:       0 for success, other is error
* Description: 1. ��ժҪ�������SM2ǩ��ʱ��SM2ǩ����ԿpucPublicKey������ڣ�
*                 ǩ��ID��ѡ����ǩ��ID�����ڣ��ڲ�ʹ��Ĭ��ֵ�ַ���[1234567812345678]��
*                 ����ִ��SM2��Ԥ����1������������̼���GM/T 0009
*              2. ��ժҪ�����ΪSM3ʱ������pucPublicKey��pucID����ΪNULL��
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
* Function:  ժҪ��ʼ������������ʽժҪ����ڶ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucData         �������ݡ�
*   @uiDataLength    �������ݳ��ȡ���Χ[0-2048]
*
* Output:     
*   ��
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
* Function:  ժҪ��ʼ������������ʽժҪ�����������
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*
* Output:     
*   @pucHash         ժҪ������ݡ�
*   @puiHashLength   ժҪ������ݳ��ȡ���Χ[SHA1-20��SHA256-32��SM3-32]
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
* Function:  �������豸�ڲ��������ڴ洢�û����ݵ��ļ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucFileName     �ļ����ơ�
*   @uiNameLen       �ļ����Ƴ��ȡ��������Ϊ128�ֽ�
*   @uiFileSize      �ļ��洢����С��
* Output:     
*   ��
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
* Function:  ��ȡ�����豸�ڲ��洢�û����ݵ��ļ�����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucFileName     �ļ����ơ�
*   @uiNameLen       �ļ����Ƴ��ȡ��������Ϊ128�ֽ�
*   @uiOffset        ָ���ļ���ȡ��ƫ������
*   @puiFileLength   ���ָ����ȡ���ļ����ȡ�
*
* Output:     
*   @puiFileLength   ����ָ��ʵ�ʶ�ȡ���ļ����ȡ�
*   @pucBuffer       ��ȡ���ļ�����
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
* Function:  �������豸�ڲ��洢����д����
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucFileName     �ļ����ơ�
*   @uiNameLen       �ļ����Ƴ��ȡ��������Ϊ128�ֽ�
*   @uiOffset        ָ��д���ļ���ƫ������
*   @uiFileLength    д���ļ����ݵĳ��ȡ�
*   @pucBuffer       д���ļ������ݡ�
*
* Output:     
*   ��
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
* Function:  ɾ�������豸�ڲ��洢�����û����ݵ��ļ�
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @pucFileName     �ļ����ơ�
*   @uiNameLen       �ļ����Ƴ��ȡ��������Ϊ128�ֽ�
*
* Output:     
*   ��
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
* Function:  ���ⲿ����RSA��ECC��Կ��
* Input:      
*   @hSessionHandle        �Ѵ������豸�Ự���
*   @Mechanism             �㷨��ʶ  SGD_RSA, SGD_SM2
*   @KeyId                 ��Կ��ŵ������� ��Χ[1-n]
*   @PrivateKeyDerBuf      ˽ԿDER������ָ��
*   @prikeyDerLen          ˽ԿDER����������
*   @PublicKeyDerBuf       ��ԿDER������ָ��
*   @PublicDerLen          ��ԿDER����������
*
* Output:     
*   ��
*   
* Return:       0 for success, other is error
* Description:  1. ��Կ�����ķ�ΧΪ[1-n]�������豸��ʵ�ʴ洢������n��
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
* Function:  ����RSA��Կ�Բ���������Կ�� 
* Input:      
*   @hSessionHandle        �Ѵ������豸�Ự���
*   @Mechanism             �㷨��ʶ ǩ����SGD_RSA_SIGN_EX  ���ܣ�SGD_RSA_ENC_EX
*   @KeySize               ��Կ����
*   @KeyId                 ��ԿID
*
* Output:     
*   ��
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
* Function:  ����ECC��Կ�Բ���������Կ�� 
* Input:      
*   @hSessionHandle        �Ѵ������豸�Ự���
*   @Mechanism             �㷨��ʶ ǩ����SGD_SM2_1  ���ܣ�SGD_SM2_3
*   @uiAlgID               ECC�㷨��ʶ  PARAID
*   @KeyId                 ��ԿID
*
* Output:     
*   ��
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



#ifdef NETCA // ��֤ͨר�ú���
/***************************************************************************
* Subroutine: SDF_InternalPrivateKeyOperation_RSA_EX
* Function:  RSA�ڲ�˽Կ����
* Input:
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiKeyIndex      RSA��Կ������1-64��
*   @signKeyType     ��Կ����, 1-SGD_RSA_SIGN_EXǩ����Կ��2-SGD_RSA_ENC_EX������Կ
*   @pucDataInput    ��������������ݡ�
*   @uiInputLength   ��������������ݳ��ȣ��ֽ��������ȱ���Ϊ(RSA��Կģ��+7/8)
*
* Output:
*   @pucDataOutput   RSA˽Կ�������
*   @puiOutputLength RSA˽Կ����������ȡ���������(RSA��Կģ��+7/8)
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
* Function:  �ڲ���ECC˽Կ�����ݽ��н���
* Input:      
*   @hSessionHandle  �Ѵ������豸�Ự���
*   @uiISKIndex      ECC��Կ��������Χ(1-64) 
*   @signKeyType     ��Կ���ͣ�1-SGD_SM2_1ʹ��ǩ����Կ���ܣ�������3-SGD_SM2_3��ʹ�ü�����Կ���ܡ�
*   @pucEncData      �����ܵ�ECC����
*
* Output:     
*   @pucData         ���ܺ�����ģ�
*   @uiDataLength    ���ܺ�����ĳ��ȣ�
*
* Return:       0 for success, other is error
* Description: 1. ��������Ҫ��Ȩ��
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

#define SDR_OK                               0x00000000	 // �����ɹ�
#define SDR_BASE                             0x01000000  // ���������ֵ
#define SDR_UNKNOWERR             SDR_BASE + 0x00000001	 // δ֪����
#define SDR_NOTSUPPORT            SDR_BASE + 0x00000002	 // ��֧�ֵĽӿڵ���
#define SDR_COMMFAIL              SDR_BASE + 0x00000003	 // ���豸ͨ��ʧ��
#define SDR_HARDFAIL              SDR_BASE + 0x00000004	 // ����ģ������Ӧ
#define SDR_OPENDEVICE            SDR_BASE + 0x00000005	 // ���豸ʧ��
#define SDR_OPENSESSION           SDR_BASE + 0x00000006	 // �����Ựʧ��
#define SDR_PARDENY               SDR_BASE + 0x00000007	 // ��˽Կʹ��Ȩ��
#define SDR_KEYNOTEXIST           SDR_BASE + 0x00000008	 // �����ڵ���Կ����
#define SDR_ALGNOTSUPPORT         SDR_BASE + 0x00000009	 // ��֧�ֵ��㷨����
#define SDR_ALGMODNOTSUPPORT      SDR_BASE + 0x0000000A	 // ��֧�ֵ��㷨ģʽ����
#define SDR_PKOPERR               SDR_BASE + 0x0000000B	 // ��Կ����ʧ��
#define SDR_SKOPERR               SDR_BASE + 0x0000000C	 // ˽Կ����ʧ��
#define SDR_SIGNERR               SDR_BASE + 0x0000000D	 // ǩ������ʧ��
#define SDR_VERIFYERR             SDR_BASE + 0x0000000E	 // ��֤ǩ��ʧ��
#define SDR_SYMOPERR              SDR_BASE + 0x0000000F	 // �Գ��㷨����ʧ��
#define SDR_STEPERR               SDR_BASE + 0x00000010	 // �ಽ���㲽�����
#define SDR_FILESIZEERR           SDR_BASE + 0x00000011	 // �ļ����ȳ�������
#define SDR_FILENOEXIST           SDR_BASE + 0x00000012	 // ָ�����ļ�������
#define SDR_FILEOFSERR            SDR_BASE + 0x00000013	 // �ļ���ʼλ�ô���
#define SDR_KEYTYPEERR            SDR_BASE + 0x00000014	 // ��Կ���ʹ���
#define SDR_KEYERR                SDR_BASE + 0x00000015	 // ��Կ����
#define SDR_ENCDATAERR            SDR_BASE + 0x00000016	 // ECC��Կ����
#define SDR_RANDERR               SDR_BASE + 0x00000017	 // �������������
#define SDR_PRKRERR               SDR_BASE + 0x00000018	 // ˽Կʹ��Ȩ�޻�ȡʧ��
#define SDR_MACERR                SDR_BASE + 0x00000019	 // MAC����ʧ��
#define SDR_FILEEXITS             SDR_BASE + 0x0000001A	 // ָ�����ļ��Ѿ�����
#define SDR_FILEWRITEERR          SDR_BASE + 0x0000001B	 // �ļ�д����
#define SDR_NUBUFFER              SDR_BASE + 0x0000001C	 // �洢�ռ䲻��
#define SDR_INARGERR              SDR_BASE + 0x0000001D	 // �����������
#define SDR_OUTARGERR             SDR_BASE + 0x0000001E	 // �����������


#define SDR_HANDLE_CLOSED         SDR_BASE + 0x0000001F //����ִ�й����У��ûỰ�Ѿ��ر�
#define SDR_HANDLE_COUNT          SDR_BASE + 0x00000020 //�򿪵ĻỰ̫��
#define SDR_HANDLE_INVALID        SDR_BASE + 0x00000021 //ָ���ĻỰ�����Ч
#define SDR_LOGIN_FAILED          SDR_BASE + 0x00000022 //��ȡ˽Կʹ��Ȩ��ʧ��
#define SDR_LOGIN_REPEAT          SDR_BASE + 0x00000023 //��ȡ˽Կʹ��Ȩ���ظ�
#define SDR_NOT_LOGIN             SDR_BASE + 0x00000024 //˽Կʹ��Ȩ��δ��ȡ
#define SDR_INPUT_LEN_ERROR       SDR_BASE + 0x00000025 //�����������ָʾ����
#define SDR_KEYID_INVALID         SDR_BASE + 0x00000026 //ָ������Կ�ŷǷ�
#define SDR_MECHANISM_INVALID     SDR_BASE + 0x00000027 //������Ч
#define SDR_NOT_INITIALIZED       SDR_BASE + 0x00000028 //δ���ó�ʼ��
#define SDR_ALREADY_INITIALIZED   SDR_BASE + 0x00000029 //��ʼ���ѵ���
#define SDR_DEVICEHANDLE_INVALID  SDR_BASE + 0x0000002A //�豸�����Ч


#define SDR_DEVICE_ERROR		      SDR_BASE + 0x0000002B
#define SDR_KEY_MEM_FULL		      SDR_BASE + 0x0000002C
#define SDR_KEY_GEN_FAIL		      SDR_BASE + 0x0000002D //������Կʧ��
#define SDR_FILE_OPR_ERR		      SDR_BASE + 0x0000002E
#define SDR_KEY_NO_EXIST		      SDR_BASE + 0x0000002F
#define SDR_MALLOC_ERR			      SDR_BASE + 0x00000030
#define SDR_DATA_INVALID		      SDR_BASE + 0x00000031
#define SDR_SM2_KEYBITS			      SDR_BASE + 0x00000032
#define SDR_SESSION_INIT              SDR_BASE + 0x00000033
#define SDR_RANDOM_GEN                SDR_BASE + 0x00000034 //���������
#define SDR_KEYPAIR_LENGTH            SDR_BASE + 0x00000035 //�ǶԳ���Կ��ָ������
#define SDR_PADDING_RSA               SDR_BASE + 0x00000036 // RSA padding ����
#define SDR_UNPADDING_RSA             SDR_BASE + 0x00000037 // RSA unpadding ����
#define SDR_HANDLE_SYMKEY_INVALID     SDR_BASE + 0x00000038 // �Ự��Կ�����Ч
#define SDR_READ_INI_ERR              SDR_BASE + 0x00000039 // ��ȡ�����ļ�ʧ��
#define SDR_HEADBEAT_TEST_ERR         SDR_BASE + 0x00000040 // �����������������ʧ��
#define SDR_DATA_TRANS_ERR            SDR_BASE + 0x00000041 // ���ݴ������

#define SDR_DATA_DEVINFO_ERR          SDR_BASE + 0x00000042 // �豸��Ϣ��ȡʧ��
#define SDR_DATA_GEN_RANDOM_ERR       SDR_BASE + 0x00000043 // ���������ʧ��
#define SDR_DATA_INDEX_OUT_ERR        SDR_BASE + 0x00000044 // ����������Χ
#define SDR_HANDLE_INPUT_INVALID      SDR_BASE + 0x00000045 // ����ľ����Ч
#define SDR_DATA_PRI_ACCESS_ERR       SDR_BASE + 0x00000046 // ��ȡ�ڲ�˽ԿȨ��ʧ��
#define SDR_DATA_EXP_PUBKEY_ERR       SDR_BASE + 0x00000047 // ������Կʧ��
#define SDR_DATA_GEN_SESKEY_ERR       SDR_BASE + 0x00000048 // ���ɻỰ��Կʧ��
#define SDR_DATA_DIGI_ENEV_ERR        SDR_BASE + 0x00000049 // �����ŷ�ת��ʧ�� 
#define SDR_DATA_GEN_AGREE_KEY_ERR    SDR_BASE + 0x00000050 // ����Э����Կʧ��
#define SDR_DATA_IM_RSA_KEY_ERR       SDR_BASE + 0x00000051 // ����RSA��Կ��ʧ��
#define SDR_DATA_IM_ECC_KEY_ERR       SDR_BASE + 0x00000052 // ����ECC��Կ��ʧ��
#define SDR_DATA_IM_ECC_ENC_ERR       SDR_BASE + 0x00000053 // ECC��Կ����ʧ��
#define SDR_DATA_IV_SYM_ERR           SDR_BASE + 0x00000054 // IV���ݴ���
#define SDR_DATA_HASH_INIT_ERR        SDR_BASE + 0x00000055 // �Ӵ������ʼ��ʧ��
#define SDR_DATA_HASH_OP_ERR          SDR_BASE + 0x00000056 // �Ӵ�����ʧ��
#define SDR_DATA_CREATE_FILE_ERR      SDR_BASE + 0x00000057 // �����ļ�ʧ��
#define SDR_DATA_DELETE_FILE_ERR      SDR_BASE + 0x00000058 // ɾ���ļ�ʧ��
/* sm2��Կ����˽Կbits���ȴ��� */

#endif // _TASS_SDF_H_
