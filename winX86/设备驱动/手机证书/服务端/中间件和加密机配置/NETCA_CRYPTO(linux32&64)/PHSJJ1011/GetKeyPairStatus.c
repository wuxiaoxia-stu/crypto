#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <dlfcn.h>
#include "function.h"

void *g_Handle=NULL;
SDF_OpenDevice_Ptr SDF_OpenDevice;
SDF_CloseDevice_Ptr SDF_CloseDevice;
SDF_OpenSession_Ptr SDF_OpenSession;
SDF_CloseSession_Ptr SDF_CloseSession;

SDF_ExportSignPublicKey_RSA_Ptr SDF_ExportSignPublicKey_RSA;
SDF_ExportEncPublicKey_RSA_Ptr SDF_ExportEncPublicKey_RSA;
SDF_ExportSignPublicKey_ECC_Ptr SDF_ExportSignPublicKey_ECC;
SDF_ExportEncPublicKey_ECC_Ptr SDF_ExportEncPublicKey_ECC;

int Init(const char *soName)
{
	if(soName==NULL)
	{
		return 0;
	}
	
	g_Handle=dlopen(soName,RTLD_LAZY);
	if(g_Handle==NULL)
	{
		char *err=dlerror();
		printf("Load %s RTLD_NOW fail,reason %s\n",soName,err?err:"");
		return 0;
	}
	
	SDF_OpenDevice=(SDF_OpenDevice_Ptr)dlsym(g_Handle,"SDF_OpenDevice");
	if(SDF_OpenDevice==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_OpenSession=(SDF_OpenSession_Ptr)dlsym(g_Handle,"SDF_OpenSession");
	if(SDF_OpenSession==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_CloseDevice=(SDF_CloseDevice_Ptr)dlsym(g_Handle,"SDF_CloseDevice");
	if(SDF_CloseDevice==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_CloseSession=(SDF_CloseSession_Ptr)dlsym(g_Handle,"SDF_CloseSession");
	if(SDF_CloseSession==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_ExportSignPublicKey_RSA=(SDF_ExportSignPublicKey_RSA_Ptr)dlsym(g_Handle,"SDF_ExportSignPublicKey_RSA");
	if(SDF_ExportSignPublicKey_RSA==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_ExportEncPublicKey_RSA=(SDF_ExportEncPublicKey_RSA_Ptr)dlsym(g_Handle,"SDF_ExportEncPublicKey_RSA");
	if(SDF_ExportEncPublicKey_RSA==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_ExportSignPublicKey_ECC=(SDF_ExportSignPublicKey_ECC_Ptr)dlsym(g_Handle,"SDF_ExportSignPublicKey_ECC");
	if(SDF_ExportSignPublicKey_ECC==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	SDF_ExportEncPublicKey_ECC=(SDF_ExportEncPublicKey_ECC_Ptr)dlsym(g_Handle,"SDF_ExportEncPublicKey_ECC");
	if(SDF_ExportEncPublicKey_ECC==NULL)
	{
		dlclose(g_Handle);
		return 0;
	}
	
	return 1;
}

int End()
{
	if(g_Handle)
	{
		dlclose(g_Handle);
	}
	return 1;
}

int IsRSAPublicKeyEquals(RSArefPublicKey *rsaSignPubKey,RSArefPublicKey *rsaEncPubKey)
{
	if(rsaSignPubKey->bits!=rsaEncPubKey->bits)
	{
		return 0;
	}

	if(memcmp(rsaSignPubKey->m,rsaEncPubKey->m,RSAref_MAX_LEN)!=0)
	{
		return 0;
	}

	if(memcmp(rsaSignPubKey->e,rsaEncPubKey->e,RSAref_MAX_LEN)!=0)
	{
		return 0;
	}

	return 1;
}

int IsSM2PublicKeyEquals(ECCrefPublicKey *sm2SignPubKey, ECCrefPublicKey *sm2EncPubKey)
{
	if(sm2SignPubKey->bits!=sm2EncPubKey->bits)
	{
		return 0;
	}

	if(memcmp(sm2SignPubKey->x,sm2EncPubKey->x,ECCref_MAX_LEN)!=0)
	{
		return 0;
	}

	if(memcmp(sm2SignPubKey->y,sm2EncPubKey->y,ECCref_MAX_LEN)!=0)
	{
		return 0;
	}

	return 1;
}

int GetKeyPairStatus(void *hSession,int index,int *status)
{
	int rv;
	int hasRSAEnc=0;
	int hasRSASign=0;
	RSArefPublicKey rsaSignPubKey;
	RSArefPublicKey rsaEncPubKey;

	int hasSM2Enc=0;
	int hasSM2Sign=0;
	ECCrefPublicKey sm2SignPubKey;
	ECCrefPublicKey sm2EncPubKey;

	memset(&rsaSignPubKey,0,sizeof(RSArefPublicKey));
	rv=SDF_ExportSignPublicKey_RSA(hSession,index,&rsaSignPubKey);
	if(rv==SDR_OK)
	{
		hasRSASign=1;
	}

	memset(&rsaEncPubKey,0,sizeof(RSArefPublicKey));
	rv=SDF_ExportEncPublicKey_RSA(hSession,index,&rsaEncPubKey);
	if(rv==SDR_OK)
	{
		hasRSAEnc=1;
	}

	if(hasRSASign || hasRSAEnc)
	{
		if(hasRSASign && hasRSAEnc && IsRSAPublicKeyEquals(&rsaSignPubKey,&rsaEncPubKey))
		{
			*status=5;
			return 1;
		}
		else
		{
			*status=1;
			return 1;
		}
	}

	memset(&sm2SignPubKey,0,sizeof(ECCrefPublicKey));
	rv=SDF_ExportSignPublicKey_ECC(hSession,index,&sm2SignPubKey);
	if(rv==SDR_OK)
	{
		hasSM2Sign=1;
	}

	memset(&sm2EncPubKey,0,sizeof(ECCrefPublicKey));
	rv=SDF_ExportEncPublicKey_ECC(hSession,index,&sm2EncPubKey);
	if(rv==SDR_OK)
	{
		hasSM2Enc=1;
	}

	if(hasSM2Sign || hasSM2Enc)
	{
		if(hasSM2Sign && hasSM2Sign && IsSM2PublicKeyEquals(&sm2SignPubKey,&sm2EncPubKey))
		{
			*status=6;
			return 1;
		}
		else
		{
			*status=2;
			return 1;
		}
	}

	*status=0;
	return 1;
}


int main()
{
	int rv;
	int index;
	int m_key_max_num=255;
	int key_status=0;
	
	void* hDevice=NULL;
	void* hSession=NULL;
	const char *soName="libph_sdf.so";
	rv=Init(soName);
	if(rv!=1)
	{
		return 1;
	}
	
	rv=SDF_OpenDevice(&hDevice);
	if(rv!=SDR_OK)
	{
		printf("SDF_OpenDevice, Fail\n");
		End();
		return 1;
	}
	
	rv=SDF_OpenSession(hDevice,&hSession);
	if(rv!=SDR_OK)
	{
		printf("SDF_OpenSession, Fail\n");
		SDF_CloseDevice(hDevice);
		End();
		return 1;
	}
	
	printf("0");
	for(index=1; index<=m_key_max_num; ++index)
	{
		GetKeyPairStatus(hSession,index,&key_status);
		printf("%d", key_status);
	}
	printf("\n");

	SDF_CloseDevice(hDevice);
	SDF_CloseSession(hSession);
	End();
	return 0;
}
