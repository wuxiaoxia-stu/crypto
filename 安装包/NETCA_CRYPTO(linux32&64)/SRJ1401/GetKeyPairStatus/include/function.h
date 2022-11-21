#ifndef _FUNCTION_INLCUDE_H_
#define _FUNCTION_INLCUDE_H_


#ifdef __cplusplus
extern "C" {
#endif

#define SDR_OK                                                      0x0								/*�����ɹ�*/
#define SDR_BASE                                                  0x01000000					/*���������ֵ*/
#define SDR_UNKNOWERR                                 (SDR_BASE + 0x00000001)		/*δ֪����*/
#define SDR_NOTSUPPORT                                  (SDR_BASE + 0x00000002)		/*��֧�ֵĽӿڵ���*/
#define SDR_COMMFAIL                                       (SDR_BASE + 0x00000003)		/*���豸ͨ��ʧ��*/
#define SDR_HARDFAIL                                         (SDR_BASE + 0x00000004)		/*����ģ������Ӧ*/
#define SDR_OPENDEVICE                                   (SDR_BASE + 0x00000005)		/*���豸ʧ��*/
#define SDR_OPENSESSION                                 (SDR_BASE + 0x00000006)		/*�����Ựʧ��*/
#define SDR_PARDENY                                          (SDR_BASE + 0x00000007)		/*��˽Կʹ��Ȩ��*/
#define SDR_KEYNOTEXIST                                (SDR_BASE + 0x00000008)		/*�����ڵ���Կ����*/
#define SDR_ALGNOTSUPPORT                          (SDR_BASE + 0x00000009)		/*��֧�ֵ��㷨����*/
#define SDR_ALGMODNOTSUPPORT                (SDR_BASE + 0x0000000A)		/*��֧�ֵ��㷨ģʽ����*/
#define SDR_PKOPERR                                         (SDR_BASE + 0x0000000B)		/*��Կ����ʧ��*/
#define SDR_SKOPERR                                         (SDR_BASE + 0x0000000C)		/*˽Կ����ʧ��*/
#define SDR_SIGNERR                                           (SDR_BASE + 0x0000000D)		/*ǩ������ʧ��*/
#define SDR_VERIFYERR                                      (SDR_BASE + 0x0000000E)		/*��֤ǩ��ʧ��*/
#define SDR_SYMOPERR                                      (SDR_BASE + 0x0000000F)		/*�Գ��㷨����ʧ��*/
#define SDR_STEPERR                                          (SDR_BASE + 0x00000010)		/*�ಽ���㲽�����*/
#define SDR_FILESIZEERR                                   (SDR_BASE + 0x00000011)		/*�ļ����ȳ�������*/
#define SDR_FILENOEXIST                                  (SDR_BASE + 0x00000012)		/*ָ�����ļ�������*/
#define SDR_FILEOFSERR                                    (SDR_BASE + 0x00000013)		/*�ļ���ʼλ�ô���*/
#define SDR_KEYTYPEERR                                  (SDR_BASE + 0x00000014)		/*��Կ���ʹ���*/
#define SDR_KEYERR                                            (SDR_BASE + 0x00000015)		/*��Կ����*/
#define SDR_ENCDATAERR                                  (SDR_BASE + 0x00000016)		/*ECC�������ݴ���*/


#define SDR_HANDLE_CLOSED						(SDR_BASE + 0x0000001F)		/*����ִ�й����У��ûỰ�Ѿ��ر�*/
#define SDR_HANDLE_COUNT						(SDR_BASE + 0x00000020)		/*�򿪵ĻỰ̫��*/
#define SDR_HANDLE_INVALID						(SDR_BASE + 0x00000021)		/*ָ���ĻỰ�����Ч*/
#define SDR_LOGIN_FAILED							(SDR_BASE + 0x00000022)		/*��ȡ˽Կʹ��Ȩ��ʧ��*/
#define SDR_LOGIN_REPEAT							(SDR_BASE + 0x00000023)		/*��ȡ˽Կʹ��Ȩ���ظ�*/
#define SDR_NOT_LOGIN                                 (SDR_BASE + 0x00000024)		/*˽Կʹ��Ȩ��δ��ȡ*/
#define SDR_INPUT_LEN_ERROR					(SDR_BASE + 0x00000025)		/*�����������ָʾ����*/
#define SDR_KEYID_INVALID							(SDR_BASE + 0x00000026)		/*ָ������Կ�ŷǷ�*/
#define SDR_MECHANISM_INVALID				(SDR_BASE + 0x00000027)		/*������Ч*/
#define SDR_NOT_INITIALIZED						(SDR_BASE + 0x00000028)		/*δ���ó�ʼ��*/
#define SDR_ALREADY_INITIALIZED			(SDR_BASE + 0x00000029)		/*��ʼ���ѵ���*/
#define SDR_DEVICEHANDLE_INVALID		(SDR_BASE + 0x0000002A)		/*�豸�����Ч*/
#define SDR_DEVICE_ERROR							(SDR_BASE + 0x0000002B)
#define SDR_KEY_MEM_FULL						(SDR_BASE + 0x0000002C)
#define SDR_KEY_GEN_FAIL							(SDR_BASE + 0x0000002D)		/*������Կʧ��*/
#define SDR_FILE_OPR_ERR							(SDR_BASE + 0x0000002E)
#define SDR_KEY_NO_EXIST							(SDR_BASE + 0x0000002F)
#define SDR_MALLOC_ERR                            (SDR_BASE + 0x00000030)
#define SDR_DATA_INVALID							(SDR_BASE + 0x00000031)
#define SDR_SM2_KEYBITS                             (SDR_BASE + 0x00000032)
#define SDR_SESSION_INIT                             (SDR_BASE + 0x00000033)
#define SDR_RANDOM_GEN							(SDR_BASE + 0x00000034)		/*���������*/
#define SDR_KEYPAIR_LENGTH                     (SDR_BASE + 0x00000035)		/*�ǶԳ���Կ��ָ������*/
#define SDR_PADDING_RSA							(SDR_BASE + 0x00000036)		/*RSA padding ����*/
#define SDR_UNPADDING_RSA						(SDR_BASE + 0x00000037)		/*RSA unpadding ����*/
#define SDR_HANDLE_SYMKEY_INVALID	(SDR_BASE + 0x00000038)		/*�Ự��Կ�����Ч*/
#define SDR_READ_INI_ERR							(SDR_BASE + 0x00000039)		/*��ȡ�����ļ�ʧ��*/
#define SDR_HEADBEAT_TEST_ERR				(SDR_BASE + 0x00000040)		/*�����������������ʧ��*/
#define SDR_DATA_TRANS_ERR                    (SDR_BASE + 0x00000041)		/*���ݴ������*/

#define SDR_DATA_DEVINFO_ERR					(SDR_BASE + 0x00000042)		/*�豸��Ϣ��ȡʧ��*/
#define SDR_DATA_GEN_RANDOM_ERR        (SDR_BASE + 0x00000043)		/*���������ʧ��*/
#define SDR_DATA_INDEX_OUT_ERR              (SDR_BASE + 0x00000044)		/*����������Χ*/
#define SDR_HANDLE_INPUT_INVALID			(SDR_BASE + 0x00000045)		/*����ľ����Ч*/
#define SDR_DATA_PRI_ACCESS_ERR             (SDR_BASE + 0x00000046)		/*��ȡ�ڲ�˽ԿȨ��ʧ��*/
#define SDR_DATA_EXP_PUBKEY_ERR			(SDR_BASE + 0x00000047)		/*������Կʧ��*/
#define SDR_DATA_GEN_SESKEY_ERR			(SDR_BASE + 0x00000048)		/*���ɻỰ��Կʧ��*/
#define SDR_DATA_DIGI_ENEV_ERR				(SDR_BASE + 0x00000049)		/*�����ŷ�ת��ʧ��*/
#define SDR_DATA_GEN_AGREE_KEY_ERR	(SDR_BASE + 0x00000050)		/*����Э����Կʧ��*/
#define SDR_DATA_IM_RSA_KEY_ERR			(SDR_BASE + 0x00000051)		/*����RSA��Կ��ʧ��*/
#define SDR_DATA_IM_ECC_KEY_ERR			(SDR_BASE + 0x00000052)		/*����ECC��Կ��ʧ��*/
#define SDR_DATA_IM_ECC_ENC_ERR			(SDR_BASE + 0x00000053)		/*ECC��Կ����ʧ��*/
#define SDR_DATA_IV_SYM_ERR                      (SDR_BASE + 0x00000054)		/*IV���ݴ���*/
#define SDR_DATA_HASH_INIT_ERR                (SDR_BASE + 0x00000055)		/*�Ӵ������ʼ��ʧ��*/
#define SDR_DATA_HASH_OP_ERR                   (SDR_BASE + 0x00000056)		/*�Ӵ�����ʧ��*/
#define SDR_DATA_CREATE_FILE_ERR			(SDR_BASE + 0x00000057)		/*�����ļ�ʧ��*/
#define SDR_DATA_DELETE_FILE_ERR			(SDR_BASE + 0x00000058)		/*ɾ���ļ�ʧ��*/


#define SGD_SM1_ECB				0x00000101		/*SM1�㷨ECB����ģʽ*/
#define SGD_SM1_CBC				0x00000102		/*SM1�㷨CBC����ģʽ*/
#define SGD_SM1_CFB				0x00000104		/*SM1�㷨CFB����ģʽ*/
#define SGD_SM1_OFB				0x00000108		/*SM1�㷨OFB����ģʽ*/
#define SGD_SM1_MAC				0x00000110		/*SM1�㷨MAC����*/
#define SGD_SSF33_ECB				0x00000201		/*SSF33�㷨ECB����ģʽ*/
#define SGD_SSF33_CBC				0x00000202		/*SSF33�㷨CBC����ģʽ*/
#define SGD_SSF33_CFB				0x00000204		/*SSF33�㷨CFB����ģʽ*/
#define SGD_SSF33_OFB				0x00000208		/*SSF33�㷨OFB����ģʽ*/
#define SGD_SSF33_MAC			0x00000210		/*SSF33�㷨MAC����*/
#define SGD_SMS4_ECB				0x00000401		/*SMS4�㷨ECB����ģʽ*/
#define SGD_SMS4_CBC				0x00000402		/*SMS4�㷨CBC����ģʽ*/
#define SGD_SMS4_CFB				0x00000404		/*SMS4�㷨CFB����ģʽ*/
#define SGD_SMS4_OFB				0x00000408		/*SMS4�㷨OFB����ģʽ*/
#define SGD_SMS4_MAC				0x00000410		/*SMS4�㷨MAC����*/


#define SGD_RSA							0x00010000		/*RSA�㷨*/
#define SGD_SM2_1						0x00020100		/*��Բ����ǩ���㷨*/
#define SGD_SM2_2						0x00020200		/*��Բ������Կ����Э��*/
#define SGD_SM2_3						0x00020400		/*��Բ���߼����㷨*/


#define SGD_SM3							0x00000001		/*SM3�Ӵ��㷨*/
#define SGD_SHA1						0x00000002		/*SHA_1�Ӵ��㷨*/
#define SGD_SHA256					0x00000004		/*SHA_256�Ӵ��㷨*/


#define DEVICEAPI


//�豸��Ϣ����
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

//RSA��Կ���ݽṹ����
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

//ECC��Կ���ݽṹ����
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

//ECCǩ�����ݽṹ����
typedef struct ECCSignature_st
{
	unsigned char r[ECCref_MAX_LEN];	
	unsigned char s[ECCref_MAX_LEN];	
} ECCSignature;


/* �������豸 */
typedef int (DEVICEAPI *SDF_OpenDevice_Ptr)(void **phDeviceHandle);
/* �ر������豸�����ͷ������Դ */
typedef int (DEVICEAPI *SDF_CloseDevice_Ptr)(void *hDeviceHandle);
/* �����������豸�ĻỰ */
typedef int (DEVICEAPI *SDF_OpenSession_Ptr)(void *hDeviceHandle, void **phSessionHandle);
/* �ر��������豸�ѽ����ĻỰ�����ͷ������Դ */
typedef int (DEVICEAPI *SDF_CloseSession_Ptr)(void *hSessionHandle);
/* ��ȡ�����豸�������� */
typedef int (DEVICEAPI *SDF_GetDeviceInfo_Ptr)(void *hSessionHandle,DEVICEINFO *pstDeviceInfo);
/* ��ȡָ�����ȵ������ */
typedef int (DEVICEAPI *SDF_GenerateRandom_Ptr)(void *hSessionHandle, unsigned int  uiLength,unsigned char *pucRandom);
/* ��ȡ�����豸�ڲ��洢��ָ������˽Կ��ʹ��Ȩ */
typedef int (DEVICEAPI *SDF_GetPrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex,unsigned char *pucPassword,unsigned int  uiPwdLength);
/* �ͷ������豸�洢��ָ������˽Կ��ʹ����Ȩ */
typedef int (DEVICEAPI *SDF_ReleasePrivateKeyAccessRight_Ptr)(void *hSessionHandle, unsigned int  uiKeyIndex);
/* ���������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* ���������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ */
typedef int  (DEVICEAPI *SDF_ExportEncPublicKey_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,RSArefPublicKey *pucPublicKey);
/* ���������豸����ָ��ģ����RSA��Կ�� */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_RSA_Ptr)(void *hSessionHandle,unsigned int  uiKeyBits,RSArefPublicKey *pucPublicKey,RSArefPrivateKey *pucPrivateKey);

/* ���������豸�ڲ��洢��ָ������λ�õ�ǩ����Կ */
typedef int (DEVICEAPI *SDF_ExportSignPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* ���������豸�ڲ��洢��ָ������λ�õļ��ܹ�Կ */
typedef int (DEVICEAPI *SDF_ExportEncPublicKey_ECC_Ptr)(void *hSessionHandle,unsigned int  uiKeyIndex,ECCrefPublicKey *pucPublicKey);
/* ���������豸����ָ�����ͺ�ģ����ECC��Կ�� */
typedef int (DEVICEAPI *SDF_GenerateKeyPair_ECC_Ptr)(void *hSessionHandle,unsigned int  uiAlgID,unsigned int  uiKeyBits,ECCrefPublicKey *pucPublicKey,ECCrefPrivateKey *pucPrivateKey);

/* �������ĻỰ��Կ��ͬʱ������Կ���*/
typedef int (DEVICEAPI *SDF_ImportKey_Ptr)(void *hSessionHandle,unsigned char *pucKey, unsigned int uiKeyLength,void **phKeyHandle);
/* ���ٻỰ��Կ�����ͷ�Ϊ��Կ���������ڴ����Դ��*/
typedef int (DEVICEAPI *SDF_DestroyKey_Ptr)(void *hSessionHandle,void *hKeyHandle);

typedef int(DEVICEAPI *SDF_InternalPrivateKeyOperation_RSA_Ptr)(void *hSessionHandle, unsigned int  uiISKIndex,unsigned char *pucDataInput,unsigned int  uiInputLength,unsigned char *pucDataOutput,unsigned int  *puiOutputLengt);
/* ʹ���ڲ�ECC˽Կ�����ݽ���ǩ������ */
typedef int (DEVICEAPI *SDF_InternalSign_ECC_Ptr)(void *hSessionHandle,unsigned int  uiISKIndex,unsigned char *pucData,unsigned int  uiDataLength,ECCSignature *pucSignature);

/* ʹ��ָ������Կ�����IV�����ݽ��жԳƼ������� */
typedef int (DEVICEAPI *SDF_Encrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucData,unsigned int uiDataLength,unsigned char *pucEncData,unsigned int  *puiEncDataLength);
/* ʹ��ָ������Կ�����IV�����ݽ��жԳƽ������� */
typedef int (DEVICEAPI *SDF_Decrypt_Ptr)(void *hSessionHandle,void *hKeyHandle,unsigned int uiAlgID,unsigned char *pucIV,unsigned char *pucEncData,unsigned int  uiEncDataLength,unsigned char *pucData,unsigned int *puiDataLength);


/* ����ʽ�����Ӵ������һ����*/
typedef int (DEVICEAPI *SDF_HashInit_Ptr)(void *hSessionHandle,unsigned int uiAlgID,ECCrefPublicKey *pucPublicKey,unsigned char *pucID,unsigned int uiIDLength);
/* ����ʽ�����Ӵ�����ڶ���������������Ľ����Ӵ����� */
typedef int (DEVICEAPI *SDF_HashUpdate_Ptr)(void *hSessionHandle,unsigned char *pucData,unsigned int  uiDataLength);
/* ����ʽ�����Ӵ�������������Ӵ�������������Ӵ����ݲ�����м����� */
typedef int (DEVICEAPI *SDF_HashFinal_Ptr)(void *hSessionHandle,unsigned char *pucHash,unsigned int  *puiHashLength);



#ifdef __cplusplus
}
#endif

#endif
