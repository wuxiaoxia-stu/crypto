#include "NETCA_PKI_Crypto.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int SignAndVerify(NETCA_PKI_KEYPAIR_HANDLE hKeypair);
static int AsyEncryptAndDecrypt(NETCA_PKI_KEYPAIR_HANDLE hKeypair);
int T_CryptoSimpleTest();


int main()
{
	T_CryptoSimpleTest();
	return 1;
}

int AsyEncryptAndDecrypt(NETCA_PKI_KEYPAIR_HANDLE hKeypair)
{
	int rv;
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=0;
	int algo=NETCA_PKI_ALGORITHM_RSA_RAW_ENC;
	int keybits;
	int usage=NETCA_PKI_USAGE_DECRYPT;
	unsigned char *clear=0;
	int clearlen=0;
	unsigned char *encdata=0;
	int encdatalen=0;
	unsigned char *decdata=0;
	int decdatalen=0;

	if(!hKeypair)
	{
		return 0;
	}

	keybits=NetcaPKICryptoGetKeypairBits(hKeypair);
	if(keybits==-1)
	{
		printf("NetcaPKICryptoGetKeypairBits, fail\n");
		return 0;
	}

	if(keybits==256)
	{
		algo=NETCA_PKI_ALGORITHM_SM2_ENC;
	}
	

	hPublicKey=NetcaPKICryptoGetPublicKeyFromKeypair(hKeypair);
	if(!hPublicKey)
	{
		printf("NetcaPKICryptoGetPublicKeyFromKeypair, fail\n");
		return 0;
	}
	
	clearlen=keybits/8;
	clear=(unsigned char *)malloc(clearlen*sizeof(unsigned char));
	memset(clear, '1', clearlen*sizeof(unsigned char));
	rv=NetcaPKICryptoPublicKeyEncrypt(hPublicKey, algo, NULL, clear, clearlen, &encdata, &encdatalen);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	hPublicKey=0;
	free(clear);
	clear=0;
	if(rv!=1)
	{
		printf("NetcaPKICryptoPublicKeyEncrypt, fail\n");
		return 0;
	}

	rv=NetcaPKICryptoPrivateKeyDecrypt(hKeypair, algo, NULL, encdata, encdatalen, &decdata, &decdatalen);
	NetcaPKICryptoFreeMemory(encdata);
	encdata=0;
	if(rv!=1)
	{
		printf("NetcaPKICryptoPrivateKeyDecrypt, fail\n");
		return 0;
	}

	NetcaPKICryptoFreeMemory(decdata);
	decdata=0;
	return 1;
}


int SignAndVerify(NETCA_PKI_KEYPAIR_HANDLE hKeypair)
{
	int rv;
	unsigned char data[1024];
	int datalen=1024;
	unsigned char *sign=0;
	int signlen=0;
	int keybits;
	int algo=NETCA_PKI_ALGORITHM_SHA256WITHRSA;
	NETCA_PKI_SIGN_HANDLE hSign=0;
	NETCA_PKI_DEVICE_VERIFY_HANDLE hVerify=0;
	NETCA_PKI_PUBLICKEY_HANDLE hPublicKey=0;
	
	if(!hKeypair)
	{
		return 0;
	}

	keybits=NetcaPKICryptoGetKeypairBits(hKeypair);
	if(keybits==-1)
	{
		printf("NetcaPKICryptoGetKeypairBits, fail\n");
		return 0;
	}

	if(keybits==256)
	{
		algo=NETCA_PKI_ALGORITHM_SHA256WITHSM2;
	}

	hSign=NetcaPKICryptoNewSign(hKeypair, algo, 0);
	if(!hSign)
	{
		printf("NetcaPKICryptoNewSign, fail\n");
		return 0;
	}
	
	memset(data, '1', 1024);
	rv=NetcaPKICryptoSignUpdate(hSign, data, datalen);
	if(rv!=1)
	{
		printf("NetcaPKICryptoSignUpdate, fail\n");
		NetcaPKICryptoFreeSign(hSign);
		hSign=0;
		return 0;
	}

	rv=NetcaPKICryptoSignFinal(hSign, &sign, &signlen);
	NetcaPKICryptoFreeSign(hSign);
	hSign=0;
	if(rv!=1)
	{	
		printf("NetcaPKICryptoSignFinal, fail\n");
		return 0;
	}

	hPublicKey=NetcaPKICryptoGetPublicKeyFromKeypair(hKeypair);
	if(!hPublicKey)
	{
		printf("NetcaPKICryptoGetPublicKeyFromKeypair, fail\n");
		NetcaPKICryptoFreeMemory(sign);
		sign=0;
		return 0;
	}
	
	hVerify=NetcaPKICryptoNewVerify(hPublicKey, algo, 0);
	NetcaPKICryptoFreePublicKey(hPublicKey);
	hPublicKey=0;
	if(!hVerify)
	{
		printf("NetcaPKICryptoNewVerify, fail\n");
		NetcaPKICryptoFreeMemory(sign);
		sign=0;
		return 0;
	}

	rv=NetcaPKICryptoVerifyUpdate(hVerify, data, datalen);
	if(rv!=1)
	{
		printf("NetcaPKICryptoVerifyUpdate, fail\n");
		NetcaPKICryptoFreeVerify(hVerify);
		hVerify=0;
		NetcaPKICryptoFreeMemory(sign);
		sign=0;
		return 0;
	}

	rv=NetcaPKICryptoVerifyFinal(hVerify, sign, signlen);
	NetcaPKICryptoFreeVerify(hVerify);
	hVerify=0;
	NetcaPKICryptoFreeMemory(sign);
	sign=0;
	if(rv!=1)
	{
		printf("NetcaPKICryptoVerifyFinal, fail\n");
		return 0;
	}

	return 1;
}


int T_CryptoSimpleTest()
{
	int rv;
	NETCA_PKI_KEYPAIR_HANDLE hKeypair=0;
	NETCA_PKI_DEVICE_HANDLE hSoft=0;

	hSoft=NetcaPKICryptoGetPseudoDevice();
	if(!hSoft)
	{
		return 0;
	}

	rv=NetcaPKICryptoGenerateKeypair(hSoft, NETCA_PKI_ALGORITHM_GENKEYPAIR_RSA, 1024, 0, 
		NETCA_PKI_KEYPAIRTYPE_SIGNATURE, "Sign_Keypair_RSA_1024", &hKeypair);
	NetcaPKICryptoFreeDevice(hSoft);
	hSoft=0;
	if(rv!=1)
	{	
		return 0;
	}
	
	rv=AsyEncryptAndDecrypt(hKeypair);
	if(rv==1)
	{
		printf("NETCA Crypto Simple Test : asymmetric encryption and decryption, OK\n");
	}

	rv=SignAndVerify(hKeypair);
	if(rv==1)
	{
		printf("NETCA Crypto Simple Test : signature and verification, OK\n");
	}

	NetcaPKICryptoFreeKeypair(hKeypair);
	hKeypair=0;
	return 1;
}

