#ifndef _NETCA_SAF_INLCUDE_H_
#define _NETCA_SAF_INLCUDE_H_

#ifdef __cplusplus
extern "C"
	{
#endif

#define SGD_SM1_ECB             0x00000101
#define SGD_SM1_CBC             0x00000102
#define SGD_SM1_CFB             0x00000104
#define SGD_SM1_OFB             0x00000108
#define SGD_SM1_MAC             0x00000110
#define SGD_SSF33_ECB           0x00000201
#define SGD_SSF33_CBC           0x00000202
#define SGD_SSF33_CFB           0x00000204
#define SGD_SSF33_OFB           0x00000208
#define SGD_SSF33_MAC           0x00000210
#define SGD_SM4_ECB             0x00000401
#define SGD_SM4_CBC             0x00000402
#define SGD_SM4_CFB             0x00000404
#define SGD_SM4_OFB             0x00000408
#define SGD_SM4_MAC             0x00000410
#define SGD_ZUC_EEA3            0x00000801
#define SGD_ZUC_EIA3            0x00000802

#define SGD_RSA                 0x00010000
#define SGD_SM2                 0x00020100
#define SGD_SM2_1               0x00020200
#define SGD_SM2_2               0x00020400
#define SGD_SM2_3               0x00020800

#define SGD_SM3                 0x00000001
#define SGD_SHA1                0x00000002
#define SGD_SHA256              0x00000004

#define SGD_SM3_RSA             0x00010001
#define SGD_SHA1_RSA            0x00010002
#define SGD_SHA256_RSA          0x00010004
#define SGD_SM3_SM2             0x00020201

#define SGD_CERT_VERSION                        0x00000001
#define SGD_CERT_SERIAL                         0x00000002
#define SGD_CERT_ISSUER                         0x00000005
#define SGD_CERT_VALID_TIME                     0x00000006
#define SGD_CERT_SUBJECT                        0x00000007
#define SGD_CERT_DER_PUBLIC_KEY                 0x00000008
#define SGD_CERT_DER_EXTENSIONS                 0x00000009
#define SGD_EXT_AUTHORITYKEYIDENTIFIER_INFO     0x00000011
#define SGD_EXT_SUBJECTKEYIDENTIFIER_INFO       0x00000012
#define SGD_EXT_KEYUSAGE_INFO                   0x00000013
#define SGD_EXT_PRIVATEKEYKEYUSAGE_INFO         0x00000014
#define SGD_EXT_CERTIFICATEPOLICIES_INFO        0x00000015
#define SGD_EXT_POLICYMAPPINGS_INFO             0x00000016
#define SGD_EXT_BASICCONSTRAINTS_INFO           0x00000017
#define SGD_EXT_POLICYCONSTRAINTS_INFO          0x00000018
#define SGD_EXT_EXTKEYUSAGE_INFO                0x00000019
#define SGD_EXT_CRLDISTRIBUTIONPOINTS_INFO      0x0000001A
#define SGD_EXT_NETSCAPE_CERT_TYPE_INFO         0x0000001B
#define SGD_EXT_SELFDEFINED_EXTENSION_INFO      0x0000001C
#define SGD_CERT_ISSUER_CN                      0x00000021
#define SGD_CERT_ISSUER_O                       0x00000022
#define SGD_CERT_ISSUER_OU                      0x00000023
#define SGD_CERT_SUBJECT_CN                     0x00000031
#define SGD_CERT_SUBJECT_O                      0x00000032
#define SGD_CERT_SUBJECT_OU                     0x00000033
#define SGD_CERT_SUBJECT_EMAIL                  0x00000034
#define SGD_CERT_NOTBEFORE_TIME                 0x00000035
#define SGD_CERT_NOTAFTER_TIME                  0x00000036

#define SGD_MAX_COUNT           64
#define SGD_MAX_NAME_SIZE       256

#define SGD_KEYUSAGE_ENCRYPT        1
#define SGD_KEYUSAGE_SIGN           2
#define SGD_KEYUSAGE_KEYAGREEMENT   3

#define SGD_KEYTYPE_SM2             1
#define SGD_KEYTYPE_RSA1024         2
#define SGD_KEYTYPE_RSA2048         3
#define SGD_KEYTYPE_RSA3072         4
#define SGD_KEYTYPE_RSA4096         5

#define SGD_USERTYPE_ADMIN          0
#define SGD_USERTYPE_USER           1


#define SAR_OK                      0
#define SAR_UnknownErr              0X02000001
#define SAR_NotSupportYetErr        0X02000002
#define SAR_FileErr                 0X02000003
#define SAR_ProviderTypeErr         0X02000004
#define SAR_LoadProviderErr         0X02000005
#define SAR_LoadDevMngApiErr        0X02000006
#define SAR_AlgoTypeErr             0X02000007
#define SAR_NameLenErr              0X02000008
#define SAR_KeyUsageErr             0X02000009
#define SAR_ModulusLenErr           0X02000010
#define SAR_NotInititalizeErr       0X02000011
#define SAR_ObjErr                  0X02000012
#define SAR_MemoryErr               0X02000100
#define SAR_TimeoutErr              0X02000101
#define SAR_IndataLenErr            0X02000200
#define SAR_IndataErr               0X02000201
#define SAR_GenRandErr              0X02000300
#define SAR_HashObjErr              0X02000301
#define SAR_HashErr                 0X02000302
#define SAR_GenRsaKeyErr            0X02000303
#define SAR_RsaModulusLenErr        0X02000304
#define SAR_CspImprtPubKeyErr       0X02000305
#define SAR_RsaEncErr               0X02000306
#define SAR_RsaDecErr               0X02000307
#define SAR_HashNotEqualErr         0X02000308
#define SAR_KeyNotFoundErr          0X02000309
#define SAR_CertNotFoundErr         0X02000310
#define SAR_NotExportErr            0X02000311
#define SAR_CertRevokedErr          0X02000316
#define SAR_CertNotYetValidErr      0X02000317
#define SAR_CertHasExpiredErr       0X02000318
#define SAR_CertVerifyErr           0X02000319
#define SAR_CertEncodeErr           0X02000320
#define SAR_DecryptPadErr           0X02000400
#define SAR_MacLenErr               0X02000401
#define SAR_KeyInfoTypeErr          0X02000402
#define SAR_NotLogin                0X02000403

#define SAR_INVILD_ARG                          0X05000000
#define SAR_INVILD_CONTAINER_NAME               0X05000001
#define SAR_ANOTHER_DEVICE_ALREADY_LOGIN        0X05000002
#define SAR_LOGIN_FAIL                          0X05000003
#define SAR_NO_SUCH_DEVICE                      0X05000004
#define SAR_BAD_CONFIGURE_FILE                  0X05000005
#define SAR_BAD_CERTIFICATE						0X05000006
#define SAR_OUT_OF_RANGE						0X05000007
#define SAR_MORE_DATA							0X05000008
#define SAR_BAD_CRL								0X05000009
#define SAR_INVILD_CRL							0X0500000A
#define SAR_LDAP_FAIL							0X0500000B
#define SAR_NO_CRL								0X0500000C
#define SAR_BAD_CERT_VERSION					0X0500000D
#define SAR_NO_CERT_EXTENSION					0X0500000E
#define SAR_NO_SUCH_EXTENSION					0X0500000F
#define SAR_TOO_MUCH_CERT						0X05000010
#define SAR_TOO_MUCH_KEYPAIR					0X05000011
#define SAR_BAD_SM2_PUBLIC_KEY					0X05000012
#define SAR_BAD_KEYUSAGE    					0X05000013
#define SAR_CONNECT_DEVICE_FAIL					0X05000014
#define SAR_GET_KEYPAIR_FAIL					0X05000015
#define SAR_NOT_RSA_KEYPAIR						0X05000016
#define SAR_NOT_LOGIN_KEYPAIR					0X05000017
#define SAR_BAD_HASH_ALGO						0X05000018
#define SAR_SIGN_FAIL							0X05000019
#define SAR_BAD_RSA_PUBLIC_KEY					0X0500001A
#define SAR_VERIFY_SIGNATURE_FAIL				0X0500001B
#define SAR_NOT_SM2_KEYPAIR						0X0500001C
#define SAR_SM2_ENCRYPT_FAIL					0X0500001D
#define SAR_BAD_IV_LENGTH						0X0500001E
#define SAR_BAD_KEY_LENGTH						0X0500001F
#define SAR_RSA_ENCRYPT_FAIL					0X05000020
#define SAR_BAD_SM2_CIPHER						0X05000021
#define SAR_SM2_DECRYPT_FAIL					0X05000022
#define SAR_KEY_NOT_FOR_ENCRYPT 				0X05000022
#define SAR_KEY_NOT_FOR_DECRYPT 				0X05000023
#define SAR_ENCRYPT_FAIL         				0X05000024
#define SAR_DECRYPT_FAIL         				0X05000025
#define SAR_KEY_NOT_FOR_MAC      				0X05000026
#define SAR_MAC_FAIL              				0X05000027
#define SAR_BAD_ENCRYPT_ALGO					0X05000028
#define SAR_ADD_ENCRYPT_CERT_FAIL				0X05000029
#define SAR_ENCODE_SIGNEDANDENVELOPEDDATA_FAIL	0X0500002A
#define SAR_DECRYPT_KEY_FAIL					0X0500002B
#define SAR_DECODE_SIGNEDANDENVELOPEDDATA_FAIL	0X0500002C
#define SAR_ENCODE_SIGNEDDATA_FAIL				0X0500002D
#define SAR_VERIFY_SIGNEDDATA_FAIL				0X0500002E
#define SAR_ENCODE_ENVELOPEDDATA_FAIL			0X0500002F
#define SAR_DECRYPT_ENVELOPEDDATA_FAIL			0X05000030
#define SAR_DECODE_DIGESTEDDATA_FAIL			0X05000031
#define SAR_VERIFY_DIGESTEDDATA_FAIL			0X05000032
#define SAR_NO_SUCH_KEYPAIR                     0X05000033
#define SAR_CONNECT_ANOTHER_DEVICE              0X05000034
#define SAR_GENERATE_SM2_KEYPAIR_FAIL           0X05000035
#define SAR_KEYAGREEMENT_FAIL			        0X05000036
#define SAR_LOCK_FAIL					        0X05000037
#define SAR_UNSUPPROT_PUBLICKEY			        0X05000038

typedef struct SGD_USR_CERT_ENUMLIST_{
    unsigned int certCount;
    unsigned char* certificate[SGD_MAX_COUNT];
    unsigned int certificateLen[SGD_MAX_COUNT];
    unsigned char* containerName[SGD_MAX_COUNT];
    unsigned int containerNameLen[SGD_MAX_COUNT];
    unsigned int keyUsage[SGD_MAX_COUNT];
}SGD_USR_CERT_ENUMLIST;

typedef struct SGD_KEYCONTAINERINFO_ENUMLIST_{
    unsigned int keyPairCount;
    unsigned char* containerName[SGD_MAX_COUNT];
    unsigned int containerNameLen[SGD_MAX_COUNT];
    unsigned int keyUsage[SGD_MAX_COUNT];
    unsigned int keyType[SGD_MAX_COUNT];
}SGD_KEYCONTAINERINFO_ENUMLIST;

typedef struct{
    unsigned char dn_c[SGD_MAX_NAME_SIZE];
    unsigned char dn_c_len[1];
    unsigned char dn_s[SGD_MAX_NAME_SIZE];
    unsigned char dn_s_len[1];
    unsigned char dn_l[SGD_MAX_NAME_SIZE];
    unsigned char dn_l_len[1];
    unsigned char dn_o[5][SGD_MAX_NAME_SIZE];
    unsigned char dn_o_len[5];
    unsigned char dn_ou[5][SGD_MAX_NAME_SIZE];
    unsigned char dn_ou_len[5];
    unsigned char dn_cn[2][SGD_MAX_NAME_SIZE];
    unsigned char dn_cn_len[2];
    unsigned char dn_email[2][SGD_MAX_NAME_SIZE];
    unsigned char dn_email_len[2];
}SGD_NAME_INFO;

/* ��ʼ������ */
int SAF_Initialize(void** phAppHandle,char* pucCfgFilePath);

/* ������� */
int SAF_Finalize(void* hAppHandle);

/* ��ȡ�ӿڰ汾��Ϣ */
int SAF_GetVersion(unsigned int* puiVersion);

/* �û���¼ */
int SAF_Login(void* hAppHandle,unsigned int uiUserType,
    unsigned char* pucContainerName,unsigned int uiContainerNameLen,
    unsigned char* pucPin,unsigned int uiPinLen,unsigned int* puiRemainCount);

/* �޸�PIN */
int SAF_ChangePin(void* hAppHandle,unsigned int uiUserType,
    unsigned char* pucContainerName,unsigned int uiContainerNameLen,
    unsigned char* pucOldPin,unsigned int uiOldPinLen,
    unsigned char* pucNewPin,unsigned int uiNewPinLen,unsigned int* puiRemainCount);

/* ע����¼ */
int SAF_Logout(void* hAppHandle,unsigned int uiUserType);

/* ������ε�CA��֤�� */
int SAF_AddTrustedRootCaCertificate(void* hAppHandle,unsigned char* pucCertificate,unsigned int uiCertificateLen);

/* ��ȡ��CA֤����� */
int SAF_GetRootCaCertificateCount(void* hAppHandle,unsigned int* puiCount);

/* ��ȡ��CA֤�� */
int SAF_GetRootCaCertificate(void* hAppHandle,unsigned int uiIndex,unsigned char* pucCertificate,unsigned int* puiCertificateLen);

/* ɾ����CA֤�� */
int SAF_RemoveRootCaCertificate(void* hAppHandle,unsigned int uiIndex);

/* ���CA֤�� */
int SAF_AddCaCertificate(void* hAppHandle,unsigned char* pucCertificate,unsigned int uiCertificateLen);

/* ��ȡCA֤����� */
int SAF_GetCaCertificateCount(void* hAppHandle,unsigned int* puiCount);

/* ��ȡCA֤�� */
int SAF_GetCaCertificate(void* hAppHandle,unsigned int uiIndex,unsigned char* pucCertificate,unsigned int* puiCertificateLen);

/* ɾ��CA֤�� */
int SAF_RemoveCaCertificate(void* hAppHandle,unsigned int uiIndex);

/* ���CRL */
int  SAF_AddCrl(void* hAppHandle,unsigned char* pucDerCrl,unsigned int uiDerCrlLen);

/* ��֤�û�֤�� */
int SAF_VerifyCertificate(void* hAppHandle,unsigned char* pucUsrCertificate,unsigned int uiUsrCertificateLen);

/* ����CRL�ļ���ȡ�û�֤��״̬ */
int SAF_VerifyCertificateByCrl(void* hAppHandle,unsigned char* pucUsrCertificate,unsigned int uiUsrCertificateLen,
    unsigned char* pucDerCrl,unsigned int uiDerCrlLen);

/* ����OCSP��ȡ֤��״̬ */
int SAF_GetCertificateStateByOCSP(void* hAppHandle,unsigned char* pcOcspHostURL,unsigned int uiOcspHostURLLen,
    unsigned char* pucUsrCertificate,unsigned int uiUsrCertificateLen,
    unsigned char* pucCACertificate,unsigned int pucCACertificateLen);

/* ͨ��LDAP��ʽ��ȡ֤�� */
int  SAF_GetCertFromLdap(void* hAppHandle,char* pcLdapHostURL,unsigned int uiLdapHostURLLen,
    unsigned char* pucQueryDN,unsigned int uiQueryDNLen,
    unsigned char* pucOutCert,unsigned int* puiOutCertLen);

/* ͨ��LDAP��ʽ��ȡ֤���Ӧ��CRL */
int SAF_GetCrlFromLdap(void* hAppHandle,char* pcLdapHostURL,unsigned int uiLdapHostURLLen,
    unsigned char* pucCertificate,unsigned int uiCertificateLen,
    unsigned char* pucCrlData,unsigned int* puiCrlDataLen);

/* ȡ֤����Ϣ */
int SAF_GetCertificateInfo(void* hAppHandle,unsigned char* pucCertificate,unsigned int uiCertificateLen,
    unsigned int uiInfoType,unsigned char* pucInfo,unsigned int* pucInfoLen);

/* ȡ֤����չ��Ϣ */
int SAF_GetExtTypeInfo(void* hAppHandle,unsigned char* pucDerCert,unsigned int uiDerCertLen,
    unsigned int uiInfoType,unsigned char* pucPriOid,unsigned int pucPriOidLen,
    unsigned char* pucInfo,unsigned int* pucInfoLen);

/* �о��û�֤�� */
int SAF_EnumCertificates(void* hAppHandle,SGD_USR_CERT_ENUMLIST* usrCerts);

/* �о��û�����Կ������Ϣ */
int SAF_EnumKeyContainerInfo(void* hAppHandle,SGD_KEYCONTAINERINFO_ENUMLIST* keyContainerInfo);

/* �ͷ��о��û�֤����ڴ� */
int SAF_EnumCertificatesFree(void* hAppHandle,SGD_USR_CERT_ENUMLIST* usrCerts);

/* �ͷ��о���Կ������Ϣ���ڴ� */
int SAF_EnumKeyContainerInfoFree(void* hAppHandle,SGD_KEYCONTAINERINFO_ENUMLIST* keyContainerInfo);

/* ����base64���롡*/
int SAF_Base64_Encode(unsigned char* pucInData,unsigned int puiInDataLen,unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ����base64���� */
int SAF_Base64_Decode(unsigned char* pucInData,unsigned int puiInDataLen,unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ����base64���� */
int SAF_Base64_CreateBase64Obj(void** phBase64Obj);

/* ����base64���� */
int SAF_Base64_DestroyBase64Obj(void* phBase64Obj);

/* ͨ��base64��������� */
int SAF_Base64_EncodeUpdate(void* phBase64Obj,unsigned char* pucInData,unsigned int puiInDataLen,
    unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ͨ��base64���������� */
int SAF_Base64_EncodeFinal(void* phBase64Obj,unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ͨ��base64��������� */
int SAF_Base64_DecodeUpdate(void* phBase64Obj,unsigned char* pucInData,unsigned int puiInDataLen,
    unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ͨ��base64���������� */
int SAF_Base64_DecodeFinal(void* phBase64Obj,unsigned char* pucOutData,unsigned int *puiOutDataLen);

/* ��������� */
int SAF_GenRandom(unsigned int uiRandLen,unsigned char* pucRand);

/* HASH���� */
int SAF_Hash(unsigned int uiAlgoType,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,unsigned char* pucID,unsigned int ulIDLen,
    unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����HASH���� */
int SAF_CreateHashObj(void** phHashObj,unsigned int uiAlgoType,unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,unsigned char* pucID,unsigned int ulIDLen);

/* ɾ��HASH���� */
int SAF_DestroyHashObj(void* phHashObj);


/* ͨ��������ж��HASH���� */
int SAF_HashUpdate(void* phHashObj,unsigned char* pucInData,unsigned int uiInDataLen);

/* ����HASH���� */
int SAF_HashFinal(void* phHashObj,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����RSA��Կ�� */
int SAF_GenRsaKeyPair(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiKeyBits,unsigned int uiKeyUsage,unsigned int uiExportFlag);

/* ��ȡRSA��Կ */
int SAF_GetRsaPublicKey(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiKeyUsage,unsigned char* pucPublicKey,unsigned int* puiPublicKeyLen);

/* RSAǩ������ */
int SAF_RsaSign(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int* puiSignDataLen);

/* ���ļ�����RSAǩ������ */
int SAF_RsaSignFile(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucFileName,
    unsigned char* pucSignData,unsigned int* puiSignDataLen);

/* RSA��֤ǩ������ */
int SAF_RsaVerifySign(unsigned int uiHashAlgorithmID,unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,
    unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int uiSignDataLen);

/* ���ļ�����ǩ������RSA��֤ */
int SAF_RsaVerifySignFile(unsigned int uiHashAlgorithmID,unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,
    unsigned char* pucFileName,unsigned char* pucSignData,unsigned int uiSignDataLen);

/* ����֤���RSA��Կ��֤ */
int SAF_RsaVerifySignByCert(unsigned int uiHashAlgorithmID,unsigned char* pucCertificate,unsigned int ulCertificateLen,
    unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int uiSignDataLen);

/* ����ECC��Կ�� */
int SAF_GenEccKeyPair(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiKeyBits,unsigned int uiKeyUsage,unsigned int uiExportFlag);

/* ��ȡECC��Կ */
int SAF_GetEccPublicKey(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiKeyUsage,unsigned char* pucPublicKey,unsigned int* puiPublicKeyLen);

/* ECCǩ�� */
int SAF_EccSign(void* hAppHandle,unsigned char* pucContainterName,unsigned int uiContainerNameLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int* puiSignDataLen);

/* ECC��֤ */
int SAF_EccVerifySign(unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int uiSignDataLen);

/* ECC��Կ���� */
int SAF_EccPublicKeyEnc(unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����֤���ECC��Կ���� */
int SAF_EccPublicKeyEncByCert(unsigned char* pucCertificate,unsigned int ulCertificateLen,
    unsigned int uiHashAlgorithmID,unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����֤���ECC��Կ��֤ */
int SAF_EccVerifySignByCert(unsigned int uiHashAlgorithmID,unsigned char* pucCertificate,unsigned int ulCertificateLen,
    unsigned char* pucInData,unsigned int uiInDataLen,
    unsigned char* pucSignData,unsigned int uiSignDataLen);

/* �����Գ��㷨���� */
int SAF_CreateSymmKeyObj(void* hAppHandle,void** phSymmKeyObj,unsigned char*pucContainterName,unsigned int uiContainerNameLen,
    unsigned char* pucIV,unsigned int uiIVLen,unsigned int uiEncOrDec,unsigned int uiCryptoAlgID);

/* ���ɻỰ��Կ�����ⲿ��Կ������� */
int SAF_GenerateKeyWithEPK(void* hSymmKeyObj,unsigned char* pucPublicKey,unsigned int ulPublicKeyLen,
    unsigned char* pucSymmKey,unsigned int* puiSymmKeyLen,void** phKeyhandle);

/* ������ܵĻỰ��Կ */
int SAF_ImportEncedKey(void* hSymmKeyObj,unsigned char* pucSymmKey,unsigned int uiSymmKeyLen,void** phKeyhandle);

/* ������ԿЭ�̲�������� */
int SAF_GenerateAgreementDataWithECC(void* hSymmKeyObj,unsigned int uiISKIndex,unsigned int uiKeyBits,
    unsigned char* pucSponsorID,unsigned int uiSponsorIDLength,
    unsigned char* pucSponsorPublicKey,unsigned int* puiSponsorPublicKeyLen,
    unsigned char* pucSponsorTempPublicKey,unsigned int* puiSponsorTempPublicKeyLen,
    void** phAgreementHandle);

/* ����Ự��Կ */
int SAF_GenerateKeyWithECC(void* hAgreementHandle,unsigned char* pucResponsorID,unsigned int pucResponsorIDLength,
    unsigned char* pucResponsorPublicKey,unsigned int pucResponsorPublicKeyLen,
    unsigned char* pucResponsorTempPublicKey,unsigned int pucResponsorTempPublicKeyLen,
    void **phKeyhandle);

/* ����Э�����ݲ�����Ự��Կ */
int SAF_GenerateAgreementDataAndKeyWithECC(
    void* hSymmKeyObj,unsigned int uiISKIndex,unsigned int uiKeyBits,
    unsigned char* pucResponsorID,unsigned int uiResponsorIDLength,
    unsigned char* pucSponsorID,unsigned int uiSponsorIDLength,
    unsigned char* pucSponsorPublicKey,unsigned int uiSponsorPublicKeyLen,
    unsigned char* pucSponsorTempPublicKey,unsigned int uiSponsorTempPublicKeyLen,
    unsigned char* pucResponsorPublicKey,unsigned int* pucResponsorPublicKeyLen,
    unsigned char* pucResponsorTempPublicKey,unsigned int* pucResponsorTempPublicKeyLen,
    void **phKeyhandle);

/* ���ٶԳ��㷨���� */
int SAF_DestorySymmKeyObj(void* hSymmKeyObj);

/* ���ٻỰ��Կ��� */
int SAF_DestoryKeyHandle(void *hKeyHandle);

/* �ͷ���ԿЭ�̾��,�������GM/T 0019֮�� */
int SAF_DestoryKeyAgreementHandle(void *hKeyAgreementHandle);

/* ����������� */
int SAF_SymmEncrypt(void* hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ���������� */
int SAF_SymmEncryptUpdate(void * hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ������������ */
int SAF_SymmEncryptFinal(void * hKeyHandle,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����������� */
int SAF_SymmDecrypt(void* hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ���������� */
int SAF_SymmDecryptUpdate(void * hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ������������ */
int SAF_SymmDecryptFinal(void * hKeyHandle,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����������Ϣ�������� */
int SAF_Mac(void* hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����������Ϣ���������� */
int SAF_MacUpdate(void* hKeyHandle,unsigned char* pucInData,unsigned int uiInDataLen);

/* ������Ϣ���������� */
int SAF_MacFinal(void* hKeyHandle,unsigned char* pucOutData,unsigned int* puiOutDataLen);

/* ����PKCS#7��ʽ�Ĵ�ǩ���������ŷ����� */
int SAF_Pkcs7_EncodeData(void* hAppHandle,unsigned char* pucSignContainerName,unsigned int uiSignContainerNameLen,
    unsigned int uiSignKeyUsage,unsigned char* puSignerCertificate,unsigned int uiSignerCertificateLen,
    unsigned int uiDigestAlgorithms,unsigned char* pucEncCertificate,unsigned int uiEncCertificateLen,
    unsigned int uiSymmAlgorithm,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char* pucDerP7Data,unsigned int* puiDerP7DataLen);

/* ����PKCS#7��ʽ�Ĵ�ǩ���������ŷ����� */
int SAF_Pkcs7_DecodeData(void* hAppHandle,unsigned char* puDecContainerName,unsigned int uiDecContainerNameLen,
    unsigned int uiDecKeyUsage,unsigned char* pucDerP7Data,unsigned int uiDerP7DataLen,
    unsigned char* pucData,unsigned int* puiDataLen,
    unsigned char* pucSignerCertificate,unsigned int* puiSignCertCertificateLen,
    unsigned int* puiDigestAlgorithms,
    unsigned char* pucSignedData,unsigned int* puiSignedDataLen);

/* ����PKCS#7��ʽ��ǩ������ */
int SAF_Pkcs7_EncodeSignedData(void* hAppHandle,unsigned char* pucSignContainerName,unsigned int uiSignContainerNameLen,
    unsigned int uiSignKeyUsage,unsigned char* pucSignerCertificate,unsigned int uiSignerCertificateLen,
    unsigned int uiDigestAlgorithms,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char* pucDerP7SignedData,unsigned int* puiDerP7SignedDataLen);

/* ����PKCS#7��ʽ��ǩ������ */
int SAF_Pkcs7_DecodeSignedData(void* hAppHandle,unsigned char* pucDerP7SignedData,unsigned int uiDerP7SignedDataLen,
    unsigned char* pucSignerCertificate,unsigned int* puiSignerCertificateLen,
    unsigned int* uiDigestAlgorithms,unsigned char* pucData,unsigned int* puiDataLen,
    unsigned char* pucSign,unsigned int* puiSignLen);

/* ����PKCS#7��ʽ�������ŷ� */
int SAF_Pkcs7_EncodeEnvelopedData(void* hAppHandle,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char*pucEncCertificate,unsigned int uiEncCertificateLen,
    unsigned int uiSymmAlgorithm,unsigned char* pucDerP7EnvelopedData,unsigned int*puiDerP7EnvelopedDataLen);

/* ����PKCS#7��ʽ�������ŷ� */
int SAF_Pkcs7_DecodeEnvelopedData(void* hAppHandle,unsigned char* pucDecContainerName,unsigned int uiDecContainerNameLen,
    unsigned int uiDecKeyUsage,unsigned char* pucDerP7EnvelopedData,unsigned int uiDerP7EnvelopedDataLen,
    unsigned char* pucData,unsigned int* puiDataLen);

/* ����PKCS#7��ʽ��ժҪ���� */
int SAF_Pkcs7_EncodeDigestedData(void* hAppHandle,unsigned int uiDigestAlgorithm,
    unsigned char* pucData,unsigned int uiDataLen,
    unsigned char* pucDerP7DigestedData,unsigned int* puiDerP7DigestedDataLen);

/* ����PKCS#7��ʽ��ժҪ���� */
int SAF_Pkcs7_DecodeDigestedData(void* hAppHandle,unsigned int uiDigestAlgorithm,
    unsigned char* pucDerP7DigestedData,unsigned int uiDerP7DigestedDataLen,
    unsigned char* pucData,unsigned int* puiDataLen,
    unsigned char* pucDigest,unsigned int* puiDigestLen);

/* �������SM2�㷨�Ĵ�ǩ���������ŷ����� */
int SAF_SM2_EncodeSignedAndEnvelopedData(void* hAppHandle,unsigned char* pucSignContainerName,unsigned int uiSignContainerNameLen,
    unsigned int uiSignKeyUsage,unsigned char* puSignerCertificate,unsigned int uiSignerCertificateLen,
    unsigned int uiDigestAlgorithms,unsigned char* pucEncCertificate,unsigned int uiEncCertificateLen,
    unsigned int uiSymmAlgorithm,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char* pucDerSignedAndEnvelopedData,unsigned int* puiDerSignedAndEnvelopedDataLen);

/* �������SM2�㷨�Ĵ�ǩ���������ŷ����� */
int SAF_SM2_DecodeSignedAndEnvelopedData(void* hAppHandle,unsigned char* puDecContainerName,unsigned int uiDecContainerNameLen,
    unsigned int uiDecKeyUsage,unsigned char* pucDerSignedAndEnvelopedData,unsigned int uiDerSignedAndEnvelopedDataLen,
    unsigned char* pucData,unsigned int* puiDataLen,
    unsigned char* pucSignerCertificate,unsigned int* puiSignCertCertificateLen,
    unsigned int* puiDigestAlgorithms);

/* �������SM2�㷨��ǩ������ */
int SAF_SM2_EncodeSignedData(void* hAppHandle,unsigned char* pucSignContainerName,unsigned int uiSignContainerNameLen,
    unsigned int uiSignKeyUsage,unsigned char* pucSignerCertificate,unsigned int uiSignerCertificateLen,
    unsigned int uiDigestAlgorithms,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char* pucDerSignedData,unsigned int* puiDerSignedDataLen);

/* �������SM2�㷨��ǩ������ */
int SAF_SM2_DecodeSignedData(void* hAppHandle,unsigned char* pucDerSignedData,unsigned int uiDerSignedDataLen,
    unsigned char* pucSignerCertificate,unsigned int* puiSignerCertificateLen,
    unsigned int* uiDigestAlgorithms,unsigned char* pucData,unsigned int* puiDataLen,
    unsigned char* pucSign,unsigned int* puiSignLen);

/* �������SM2�㷨�������ŷ� */
int SAF_SM2_EncodeEnvelopedData(void* hAppHandle,unsigned char* pucData,unsigned int uiDataLen,
    unsigned char*pucEncCertificate,unsigned int uiEncCertificateLen,
    unsigned int uiSymmAlgorithm,unsigned char* pucDerEnvelopedData,unsigned int*puiDerEnvelopedDataLen);

/* �������SM2�㷨�������ŷ� */
int SAF_SM2_DecodeEnvelopedData(void* hAppHandle,unsigned char* pucDecContainerName,unsigned int uiDecContainerNameLen,
    unsigned int uiDecKeyUsage,unsigned char* pucDerEnvelopedData,unsigned int uiDerEnvelopedDataLen,
    unsigned char* pucData,unsigned int* puiDataLen);

#ifdef __cplusplus
	}	
#endif

#endif

