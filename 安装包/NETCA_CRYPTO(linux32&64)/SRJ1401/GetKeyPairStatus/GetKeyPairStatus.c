#include <stdio.h>
#include <string.h>
#include "function.h"
#include "NETCA_Util.h"
#include "NETCA_UString.h"
#include "NETCA_Alloc.h"
#include "pkcs11/pkcs11types.h"

#ifdef _WIN32
#ifdef _M_X64
#pragma comment(lib, "lib/NETCA_UTIL_x64.lib")
#else
#pragma comment(lib, "lib/NETCA_UTIL.lib")
#endif
#endif

NETCA_DSOHandle g_devDso = 0;
SDF_OpenDevice_Ptr SDF_OpenDevice;
SDF_CloseDevice_Ptr SDF_CloseDevice;
SDF_OpenSession_Ptr SDF_OpenSession;
SDF_CloseSession_Ptr SDF_CloseSession;
SDF_ExportSignPublicKey_RSA_Ptr SDF_ExportSignPublicKey_RSA;
SDF_ExportEncPublicKey_RSA_Ptr SDF_ExportEncPublicKey_RSA;
SDF_ExportSignPublicKey_ECC_Ptr SDF_ExportSignPublicKey_ECC;
SDF_ExportEncPublicKey_ECC_Ptr SDF_ExportEncPublicKey_ECC;

#define MAX_KEYPAIR_INDEX 1024
int g_sm2KeypairStatusArray[1024] = {0};
int g_rsaKeypairStatusArray[1024] = {0};
int g_eccKeypairStatusArray[1024] = {0};

NETCA_DSOHandle g_p11Dso = 0;
CK_FUNCTION_LIST_PTR g_pkcs11func;
typedef CK_RV (*C_GetFunctionList_Ptr)(CK_FUNCTION_LIST_PTR_PTR ppFunctionList);

static int GetDevDso(const char *dsoName);
static int GetP11Dso(const char *dsoName);
static void FreeDevP11Dso();
static int GetRSAKeypairStatus(void *hSession);
static int GetSM2KeypairStatus(void *hSession);
static int GetDevKeypairs();
static int GetP11Keypairs();

int main()
{
    int rv;
    int i;
    const char *devName = "";
    const char *p11Name = "";
    FILE *fp;
    int rv2;

#ifdef _WIN32
    devName = "srj1401DevAPI.dll";
    p11Name = "srj1401pkcs11.dll";
#else
    devName = "libsrj1401DevAPI.so";
    p11Name = "libsrj1401pkcs11.so";
#endif

#ifdef _WIN32
    printf("正在打印密钥对的状态......\n");
#else
    printf("Keypairs infomation is printing...\n");
#endif

    rv = GetP11Dso(p11Name);
    if (rv != 1)
    {
        printf("Not Supported ECC\n");
    }
    else
    {
        rv = GetP11Keypairs();
        if (rv != 1)
        {
            FreeDevP11Dso();
            printf("GetP11Keypairs fail\n");
            return -1;
        }
    }

    rv2 = GetDevDso(devName);
    if (rv2 != 1)
    {
        printf("Not Supported SM2\n");
    }
    else
    {
        rv2 = GetDevKeypairs();
        if (rv2 != 1)
        {
            FreeDevP11Dso();
            printf("GetP1GetDevKeypairs1Keypairs fail\n");
            return -1;
        }
    }
    FreeDevP11Dso();
    if (rv != 1 && rv2 != 1)
    {
        return -1;
    }

    fp = fopen("SRJ1401KeyPairStatus", "wb");
    if (fp == 0)
    {
        FreeDevP11Dso();
        return -1;
    }
    fprintf(fp, "HasSM1=1\r\nHasSMS4=1\r\nHasSSF33=1\r\nHasSM3=0\r\n");

    fprintf(fp, "SM2KeyPairStatus=");
    for (i = 0; i < MAX_KEYPAIR_INDEX; ++i)
    {
        fprintf(fp, "%d", g_sm2KeypairStatusArray[i]);
    }
    fprintf(fp, "\r\n");

    fprintf(fp, "RSAKeyPairStatus=");
    for (i = 0; i < MAX_KEYPAIR_INDEX; ++i)
    {
        fprintf(fp, "%d", g_rsaKeypairStatusArray[i]);
    }
    fprintf(fp, "\r\n");

    fprintf(fp, "ECCKeyPairStatus=");
    for (i = 0; i < MAX_KEYPAIR_INDEX; ++i)
    {
        fprintf(fp, "%d", g_eccKeypairStatusArray[i]);
    }
    fprintf(fp, "\r\n");
    fclose(fp);

    return 0;
}

void FreeDevP11Dso()
{
    if (g_devDso)
    {
        netca_dso_free(g_devDso);
        g_devDso = 0;
    }

    if (g_p11Dso)
    {
        netca_dso_free(g_p11Dso);
        g_p11Dso = 0;
    }
}

int GetP11Dso(const char *dsoName)
{
    NETCA_UString uDsoName;
    C_GetFunctionList_Ptr pkcs11func;
    CK_RV rv;

    uDsoName = netca_ustring_newutf8((const unsigned char *)dsoName, (int)strlen(dsoName));
    if (uDsoName == 0)
    {
        return 0;
    }

    g_p11Dso = netca_dso_load(uDsoName);
    netca_ustring_free(uDsoName);
    if (g_p11Dso == 0)
    {
        return 0;
    }

    pkcs11func = (C_GetFunctionList_Ptr)netca_dso_getfunction(g_p11Dso, "C_GetFunctionList");
    if (pkcs11func == 0)
    {
        netca_dso_free(g_p11Dso);
        g_p11Dso = 0;
        return 0;
    }

    rv = pkcs11func(&g_pkcs11func);
    if (rv != CKR_OK)
    {
        netca_dso_free(g_p11Dso);
        g_p11Dso = 0;
        return 0;
    }
    return 1;
}

int GetDevDso(const char *dsoName)
{
    NETCA_UString uDsoName;

    uDsoName = netca_ustring_newutf8((const unsigned char *)dsoName, (int)strlen(dsoName));
    if (uDsoName == 0)
    {
        return 0;
    }

    g_devDso = netca_dso_load(uDsoName);
    netca_ustring_free(uDsoName);
    if (g_devDso == 0)
    {
        return 0;
    }

    SDF_OpenDevice = (SDF_OpenDevice_Ptr)netca_dso_getfunction(g_devDso, "SDF_OpenDevice");
    SDF_CloseDevice = (SDF_CloseDevice_Ptr)netca_dso_getfunction(g_devDso, "SDF_CloseDevice");
    SDF_OpenSession = (SDF_OpenSession_Ptr)netca_dso_getfunction(g_devDso, "SDF_OpenSession");
    SDF_CloseSession = (SDF_CloseSession_Ptr)netca_dso_getfunction(g_devDso, "SDF_CloseSession");
    SDF_ExportSignPublicKey_RSA = (SDF_ExportSignPublicKey_RSA_Ptr)netca_dso_getfunction(g_devDso, "SDF_ExportSignPublicKey_RSA");
    SDF_ExportEncPublicKey_RSA = (SDF_ExportEncPublicKey_RSA_Ptr)netca_dso_getfunction(g_devDso, "SDF_ExportEncPublicKey_RSA");
    SDF_ExportSignPublicKey_ECC = (SDF_ExportSignPublicKey_ECC_Ptr)netca_dso_getfunction(g_devDso, "SDF_ExportSignPublicKey_ECC");
    SDF_ExportEncPublicKey_ECC = (SDF_ExportEncPublicKey_ECC_Ptr)netca_dso_getfunction(g_devDso, "SDF_ExportEncPublicKey_ECC");

    if (SDF_OpenDevice == 0 || SDF_CloseDevice == 0 ||
        SDF_OpenSession == 0 || SDF_CloseSession == 0 ||
        SDF_ExportSignPublicKey_RSA == 0 || SDF_ExportEncPublicKey_RSA == 0 ||
        SDF_ExportSignPublicKey_ECC == 0 || SDF_ExportEncPublicKey_ECC == 0)
    {
        netca_dso_free(g_devDso);
        g_devDso = 0;
        return 0;
    }

    return 1;
}

int GetSM2KeypairStatus(void *hSession)
{
    int rv1;
    int rv2;
    int i;
    ECCrefPublicKey publicKey1;
    ECCrefPublicKey publicKey2;
    for (i = 1; i < MAX_KEYPAIR_INDEX + 1; ++i)
    {
        int status = 0;

        memset(&publicKey1, 0, sizeof(publicKey1));
        rv1 = SDF_ExportEncPublicKey_ECC(hSession, i, &publicKey1);

        memset(&publicKey2, 0, sizeof(publicKey2));
        rv2 = SDF_ExportSignPublicKey_ECC(hSession, i, &publicKey2);

        if (rv1 == SDR_OK)
        {
            status |= 0x01;
        }

        if (rv2 == SDR_OK)
        {
            status |= 0x02;
        }

        if (rv1 == SDR_OK && rv2 == SDR_OK)
        {
            if (memcmp(publicKey1.x, publicKey2.x, sizeof(publicKey1.x)) == 0 && memcmp(publicKey1.y, publicKey2.y, sizeof(publicKey1.y)) == 0)
            {
                status |= 0x04;
            }
        }

        g_sm2KeypairStatusArray[i - 1] = status;
    }

    return 1;
}

int GetRSAKeypairStatus(void *hSession)
{
    int rv1;
    int rv2;
    int i;
    RSArefPublicKey publicKey1;
    RSArefPublicKey publicKey2;

    for (i = 1; i < MAX_KEYPAIR_INDEX + 1; ++i)
    {
        int status = 0;

        memset(&publicKey1, 0, sizeof(publicKey1));
        rv1 = SDF_ExportEncPublicKey_RSA(hSession, i, &publicKey1);

        memset(&publicKey2, 0, sizeof(publicKey2));
        rv2 = SDF_ExportSignPublicKey_RSA(hSession, i, &publicKey2);

        if (rv1 == SDR_OK)
        {
            status |= 0x01;
        }

        if (rv2 == SDR_OK)
        {
            status |= 0x02;
        }

        if (rv1 == SDR_OK && rv2 == SDR_OK)
        {
            if (memcmp(&publicKey1, &publicKey2, sizeof(RSArefPublicKey)) == 0)
            {
                status |= 0x04;
            }
        }
        g_rsaKeypairStatusArray[i - 1] = status;
    }
    return 1;
}

int GetDevKeypairs()
{
    int rv;
    void *hDevice = 0;
    void *hSession = 0;

    rv = SDF_OpenDevice(&hDevice);
    if (rv != SDR_OK)
    {
        return 0;
    }

    rv = SDF_OpenSession(hDevice, &hSession);
    if (rv != SDR_OK)
    {
        SDF_CloseDevice(hDevice);
        return 0;
    }

    GetSM2KeypairStatus(hSession);
    GetRSAKeypairStatus(hSession);

    SDF_CloseSession(hSession);
    SDF_CloseDevice(hDevice);
    return 1;
}

int GetP11Keypairs()
{
    CK_RV rv;
    CK_SESSION_HANDLE hSession;

    CK_BBOOL tokenType = TRUE;
    CK_ULONG classType = CKO_PUBLIC_KEY;
    CK_ULONG keyType = CKK_EC;

    CK_OBJECT_HANDLE hObjects[1024];
    CK_ULONG index;
    CK_ULONG ulObjectCount = 0;
    CK_ATTRIBUTE eccKeyTemplate[] = {
        {CKA_TOKEN, &tokenType, sizeof(tokenType)},
        {CKA_CLASS, &classType, sizeof(classType)},
        {CKA_KEY_TYPE, &keyType, sizeof(keyType)}};

    CK_BBOOL isSign;
    CK_BBOOL isEnc;
    CK_BYTE curve[16];
    char label[64];
    CK_ATTRIBUTE GetObjectTemplate[] = {
        {CKA_SIGN, &isSign, sizeof(isSign)},
        {CKA_ENCRYPT, &isEnc, sizeof(isEnc)},
        {CKA_EC_PARAMS, curve, sizeof(curve)},
        {CKA_LABEL, NULL_PTR, 0}};

    rv = g_pkcs11func->C_Initialize(NULL_PTR);
    if (rv == CKR_VENDOR_DEFINED)
    {
        printf("Not supported CKR_VENDOR_DEFINED\n");
        return 1;
    }
    if (rv != CKR_OK && rv != CKR_CRYPTOKI_ALREADY_INITIALIZED)
    {
        return 0;
    }

    rv = g_pkcs11func->C_OpenSession(0, CKF_RW_SESSION | CKF_SERIAL_SESSION, 0, 0, &hSession);
    if (rv != CKR_OK)
    {
        g_pkcs11func->C_Finalize(NULL_PTR);
        return 0;
    }

    rv = g_pkcs11func->C_FindObjectsInit(hSession, eccKeyTemplate, sizeof(eccKeyTemplate) / sizeof(eccKeyTemplate[0]));
    if (rv != CKR_OK)
    {
        g_pkcs11func->C_CloseSession(hSession);
        g_pkcs11func->C_Finalize(NULL_PTR);
        return 0;
    }

    rv = g_pkcs11func->C_FindObjects(hSession, hObjects, sizeof(hObjects) / sizeof(hObjects[0]), &ulObjectCount);
    g_pkcs11func->C_FindObjectsFinal(hSession);
    if (rv != CKR_OK)
    {
        g_pkcs11func->C_CloseSession(hSession);
        g_pkcs11func->C_Finalize(NULL_PTR);
        return 0;
    }

    for (index = 0; index < ulObjectCount; ++index)
    {
        memset(label, 0, sizeof(label));
        GetObjectTemplate[3].pValue = label;
        GetObjectTemplate[3].ulValueLen = sizeof(label);
        rv = g_pkcs11func->C_GetAttributeValue(hSession, hObjects[index], GetObjectTemplate, 4);
        if (rv == CKR_OK)
        {
            if (memcmp(label, "ECCommon_PUBLIC_KEY_", strlen("ECCommon_PUBLIC_KEY_")) == 0)
            {
                int i = atoi(&label[strlen("ECCommon_PUBLIC_KEY_")]);
                g_eccKeypairStatusArray[i - 1] = 7;
            }
        }
    }

    g_pkcs11func->C_CloseSession(hSession);
    g_pkcs11func->C_Finalize(NULL_PTR);
    return 1;
}