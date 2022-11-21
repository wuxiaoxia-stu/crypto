#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include "SDF.h"

#define false 0
#define true 1

static int GetKeyPairIndexStatus(void *hSession,int index,int *status);
static int GetKeyPairStatus(void *hSession,int max, unsigned char **outData, int *outDataLen);
static int IsRSAPublicKeyEquals(const RSArefPublicKey rsaSignPubKey,const RSArefPublicKey rsaEncPubKey);
static int IsSM2PublicKeyEquals(const ECCrefPublicKey sm2SignPubKey,const ECCrefPublicKey sm2EncPubKey);
static int g_maxKeyNum = 255;

int main()
{
    int rv;
    void *hDevice=0;
    
    rv=SDF_OpenDevice(&hDevice);
    if(rv!=SDR_OK)
    {
		printf("SDF_OpenDevice Fail, rv=0x%08x", rv);
        return 0;
    }
    
    void *hSession=0;
    rv=SDF_OpenSession(hDevice,&hSession);
    if(rv!=SDR_OK)
    {
		printf("SDF_OpenSession Fail, rv=0x%08x", rv);
        return 0;
    }

    unsigned char *buf = NULL;
    int bufLen = 0;
    if(GetKeyPairStatus(hSession,g_maxKeyNum, &buf, &bufLen) == false)
    {
        SDF_CloseSession(hSession);
        SDF_CloseDevice(hDevice);
        return 0;
    }
    SDF_CloseSession(hSession);
    SDF_CloseDevice(hDevice);
    int i;
    for(i=0; i<bufLen; i++)
    {
        printf("%c", buf[i]);
    }
    free(buf);

    return 0;
}

int GetKeyPairStatus(void *hSession,int max, unsigned char **outData, int *outDataLen)
{
    int status;
    int i;

    unsigned char *buf=(unsigned char *)malloc(sizeof(unsigned char)*(max+1));
    if(buf==0)
    {
        return false;
    }
    memset(buf, '0', max+1);
    for(i=1;i<=max;i++)
    {
        if(GetKeyPairIndexStatus(hSession,i,&status)==false)
        {
            return false;
        }
        buf[i] = status + '0';
    }
    *outData = buf;
    *outDataLen = max+1;
    return true;
}

int GetKeyPairIndexStatus(void *hSession,int index,int *status)
{
    int rv;
    int hasRSAEnc=false;
    int hasRSASign=false;
    RSArefPublicKey rsaSignPubKey;
    RSArefPublicKey rsaEncPubKey;

    int hasSM2Enc=false;
    int hasSM2Sign=false;
    ECCrefPublicKey sm2SignPubKey;
    ECCrefPublicKey sm2EncPubKey;

    memset(&rsaSignPubKey,0,sizeof(RSArefPublicKey));
    rv=SDF_ExportSignPublicKey_RSA(hSession,index,&rsaSignPubKey);
    if(rv==SDR_OK)
    {
        hasRSASign=true;
    }

    memset(&rsaEncPubKey,0,sizeof(RSArefPublicKey));
    rv=SDF_ExportEncPublicKey_RSA(hSession,index,&rsaEncPubKey);
    if(rv==SDR_OK)
    {
        hasRSAEnc=true;
    }

    if(hasRSASign || hasRSAEnc)
    {
        if(hasRSASign && hasRSAEnc && IsRSAPublicKeyEquals(rsaSignPubKey,rsaEncPubKey))
        {
            *status=5;
            return true;
        }
        else
        {
            *status=1;
            return true;
        }
    }

    memset(&sm2SignPubKey,0,sizeof(ECCrefPublicKey));
    rv=SDF_ExportSignPublicKey_ECC(hSession,index,&sm2SignPubKey);
    if(rv==SDR_OK)
    {
        hasSM2Sign=true;
    }

    memset(&sm2EncPubKey,0,sizeof(ECCrefPublicKey));
    rv=SDF_ExportEncPublicKey_ECC(hSession,index,&sm2EncPubKey);
    if(rv==SDR_OK)
    {
        hasSM2Enc=true;
    }

    if(hasSM2Sign || hasSM2Enc)
    {
        if(hasSM2Sign && hasSM2Sign && IsSM2PublicKeyEquals(sm2SignPubKey,sm2EncPubKey))
        {
            *status=6;
            return true;
        }
        else
        {
            *status=2;
            return true;
        }
    }

    *status=0;
    return true;    
}

int IsRSAPublicKeyEquals(const RSArefPublicKey rsaSignPubKey,const RSArefPublicKey rsaEncPubKey)
{
    if(rsaSignPubKey.bits!=rsaEncPubKey.bits)
    {
        return false;
    }

    if(memcmp(rsaSignPubKey.m,rsaEncPubKey.m,RSAref_MAX_LEN)!=0)
    {
        return false;
    }

    if(memcmp(rsaSignPubKey.e,rsaEncPubKey.e,RSAref_MAX_LEN)!=0)
    {
        return false;
    }

    return true;
}


int IsSM2PublicKeyEquals(const ECCrefPublicKey sm2SignPubKey,const ECCrefPublicKey sm2EncPubKey)
{
    if(sm2SignPubKey.bits!=sm2EncPubKey.bits)
    {
        return false;
    }

    if(memcmp(sm2SignPubKey.x,sm2EncPubKey.x,ECCref_MAX_LEN)!=0)
    {
        return false;
    }

    if(memcmp(sm2SignPubKey.y,sm2EncPubKey.y,ECCref_MAX_LEN)!=0)
    {
        return false;
    }

    return true;
}
