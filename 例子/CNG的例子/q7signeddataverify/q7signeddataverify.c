#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define SM3_OID			"1.2.156.10197.1.401"
#define SM2SIGN_OID		"1.2.156.10197.1.301.1"
#define SM2DATA_OID		"1.2.156.10197.6.1.4.2.1"
#define SM2SIGNEDDATA_OID		"1.2.156.10197.6.1.4.2.2"

static void Usage(const char *progName);
static int GetFileLength(FILE *fp);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
static int ToCMSSignedData(const unsigned char* in, int inLen, unsigned char **out, int *outLen);
static int Verify(const unsigned char *tbs, int tbsLen, const unsigned char *signature, int signatureLen);
static int DetachedVerify(const unsigned char *tbs, int tbsLen, const unsigned char *signature, int signatureLen);

void Usage(const char *progName)
{
	printf("Usage: %s [-detached] tbs signFileName\n", progName);
}

int main(int argc, char **argv)
{
	const char* tbs;
	const char* signFileName;
	int detached;
	int rv;
	unsigned char* sign;
	int signLen;
	int pos;
	unsigned char* cmsSign;
	int cmsSignLen;

	if (argc != 3 && argc!=4)
	{
		Usage(argv[0]);
		return -1;
	}
	pos = 1;
	detached = 0;
	if (argc == 4)
	{
		if (_stricmp(argv[1], "-detached") != 0
			&& _stricmp(argv[1], "/detached") != 0)
		{
			Usage(argv[0]);
			return -1;
		}
		pos = 2;
		detached = 1;
	}
	tbs = argv[pos];
	pos++;
	signFileName = argv[pos];
	rv=ReadFileData(signFileName,&sign,&signLen);
	if (rv == 0)
	{
		printf("Read signFile fail\n");
		return 0;
	}

	rv = ToCMSSignedData(sign, (int)signLen,&cmsSign,&cmsSignLen);
	free(sign);
	if (rv == 0)
	{
		printf("not q7 signeddata\n");
		return 0;
	}
	else if (rv == -1)
	{
		printf("too much signedinfo\n");
		return 0;
	}
	else if (rv == -2)
	{
		printf("no signedinfo\n");
		return 0;
	}
	if (detached)
	{
		rv = DetachedVerify((const unsigned char*)tbs, (int)strlen(tbs),
			cmsSign, cmsSignLen);
	}
	else
	{
		rv = Verify((const unsigned char*)tbs, (int)strlen(tbs),
			cmsSign, cmsSignLen);
	}
	
	free(cmsSign);
	if (rv == 0)
	{
		printf("Verify fail\n");
		return -1;
	}

	printf("Verify success\n");
	return 0;
}

int GetFileLength(FILE *fp)
{
	int  len;
	if (fseek(fp, 0, SEEK_END) != 0)
	{
		return -1;
	}
	len = ftell(fp);
	if (fseek(fp, 0, SEEK_SET) != 0)
	{
		return -1;
	}

	return len;
}

int ReadFileData(const char *fileName, unsigned char **data, int *dataLen)
{
	FILE *fp;
	int len;
	unsigned char *buf;

	fp = fopen(fileName, "rb");
	if (fp == 0)
	{
		return 0;
	}

	len = GetFileLength(fp);
	if (len<0)
	{
		fclose(fp);
		return 0;
	}

	buf = (unsigned char *)malloc(len);
	if (buf == 0)
	{
		fclose(fp);
		return 0;
	}
	if ((int)fread(buf, 1, len, fp) != len)
	{
		free(buf);
		fclose(fp);
		return 0;
	}
	fclose(fp);
	*data = buf;
	*dataLen = len;
	return 1;
}

int ToCMSSignedData(const unsigned char* in,int inLen,unsigned char **out,int *outLen)
{
	BOOL b;
	DWORD length;
	CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *q7SignedData;
	CRYPT_SEQUENCE_OF_ANY *signerInfos;
	CMSG_CMS_SIGNER_INFO  *signerInfo;
	unsigned char* innerContentInfoEncode=0;

	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		return 0;
	}
	q7SignedData = (CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY *)malloc(length);
	if (q7SignedData == 0)
	{
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		in, (DWORD)inLen,
		0, NULL,
		q7SignedData, &length
		);
	if (b == FALSE)
	{
		free(q7SignedData);
		return 0;
	}
	if (strcmp(q7SignedData->pszObjId, SM2SIGNEDDATA_OID) != 0)
	{
		free(q7SignedData);
		return 0;
	}
	q7SignedData->pszObjId = szOID_RSA_signedData;
	if (q7SignedData->cValue < 4)
	{
		free(q7SignedData);
		return 0;
	}

	if (q7SignedData->rgValue[q7SignedData->cValue - 1].cbData == 0)
	{
		free(q7SignedData);
		return 0;
	}

	/* 把SET OF 转换为SEQUECE OF */
	q7SignedData->rgValue[q7SignedData->cValue - 1].pbData[0] -= 1;
	
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		q7SignedData->rgValue[q7SignedData->cValue-1].pbData,
		q7SignedData->rgValue[q7SignedData->cValue - 1].cbData,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		free(q7SignedData);
		return 0;
	}
	signerInfos = (CRYPT_SEQUENCE_OF_ANY*)malloc(length);
	if (signerInfos == 0)
	{
		free(q7SignedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		X509_SEQUENCE_OF_ANY,
		q7SignedData->rgValue[q7SignedData->cValue - 1].pbData,
		q7SignedData->rgValue[q7SignedData->cValue - 1].cbData,
		0, NULL,
		signerInfos, &length
		);
	if (b == FALSE)
	{
		free(signerInfos);
		free(q7SignedData);
		return 0;
	}
	q7SignedData->rgValue[q7SignedData->cValue - 1].pbData[0] += 1;

	/* 只处理一个签名的情况 */
	if (signerInfos->cValue >1)
	{
		free(signerInfos);
		free(q7SignedData);
		return -1;
	}
	else if (signerInfos->cValue ==0)
	{
		free(signerInfos);
		free(q7SignedData);
		return -2;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		CMS_SIGNER_INFO,
		signerInfos->rgValue[0].pbData,
		signerInfos->rgValue[0].cbData,
		0, NULL,
		0, &length
		);
	if (b == FALSE)
	{
		free(signerInfos);
		free(q7SignedData);
		return 0;
	}
	signerInfo = (CMSG_CMS_SIGNER_INFO *)malloc(length);
	if (signerInfo == 0)
	{
		free(signerInfos);
		free(q7SignedData);
		return 0;
	}
	b = CryptDecodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		CMS_SIGNER_INFO,
		signerInfos->rgValue[0].pbData,
		signerInfos->rgValue[0].cbData,
		0, NULL,
		signerInfo, &length
		);
	free(signerInfos);
	if (b == FALSE)
	{
		free(signerInfo);
		free(q7SignedData);
		return 0;

	}

	if (signerInfo->AuthAttrs.cAttr == 0)
	{
		CRYPT_CONTENT_INFO *oldInnerContentInfo;
		

		free(signerInfo);
		b = CryptDecodeObjectEx(
			X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
			PKCS_CONTENT_INFO,
			q7SignedData->rgValue[2].pbData,
			q7SignedData->rgValue[2].cbData,
			0, 0,
			0, &length);
		if (b == FALSE)
		{
			free(q7SignedData);
			return 0;
		}

		oldInnerContentInfo = (CRYPT_CONTENT_INFO*)malloc(length);
		if (oldInnerContentInfo == 0)
		{
			free(q7SignedData);
			return 0;
		}
		b = CryptDecodeObjectEx(
			X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
			PKCS_CONTENT_INFO,
			q7SignedData->rgValue[2].pbData,
			q7SignedData->rgValue[2].cbData,
			0, 0,
			oldInnerContentInfo, &length);
		if (b == FALSE)
		{
			free(oldInnerContentInfo);
			free(q7SignedData);
			return 0;
		}
		if (strcmp(oldInnerContentInfo->pszObjId, SM2DATA_OID) != 0)
		{
			free(oldInnerContentInfo);
			free(q7SignedData);
			return 0;
		}
		oldInnerContentInfo->pszObjId = szOID_RSA_data;
		b = CryptEncodeObjectEx(
			X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
			PKCS_CONTENT_INFO,
			oldInnerContentInfo,
			0, 0,
			0, &length);
		if (b == FALSE)
		{
			free(oldInnerContentInfo);
			free(q7SignedData);
			return 0;
		}
		innerContentInfoEncode = (unsigned char*)malloc(length);
		if (innerContentInfoEncode == 0)
		{
			free(oldInnerContentInfo);
			free(q7SignedData);
			return 0;
		}
		b = CryptEncodeObjectEx(
			X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
			PKCS_CONTENT_INFO,
			oldInnerContentInfo,
			0, 0,
			innerContentInfoEncode, &length);
		free(oldInnerContentInfo);
		if (b == FALSE)
		{
			free(innerContentInfoEncode);
			free(q7SignedData);
			return 0;
		}
		q7SignedData->rgValue[2].pbData = innerContentInfoEncode;
		q7SignedData->rgValue[2].cbData = length;
	}
	else
	{
		free(signerInfo);
	}

	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		q7SignedData,
		0, 0,
		0, &length);
	if (b == FALSE)
	{
		free(innerContentInfoEncode);
		free(q7SignedData);
		return 0;
	}
	*out = (unsigned char*)malloc(length);
	if (*out == 0)
	{
		free(innerContentInfoEncode);
		free(q7SignedData);
		return 0;
	}
	b = CryptEncodeObjectEx(
		X509_ASN_ENCODING | PKCS_7_ASN_ENCODING,
		PKCS_CONTENT_INFO_SEQUENCE_OF_ANY,
		q7SignedData,
		0, 0,
		*out, &length);
	free(innerContentInfoEncode);
	free(q7SignedData);
	if (b == FALSE)
	{
		free(*out);
		return 0;
	}
	*outLen = (int)length;
	return 1;
}

int Verify(const unsigned char *tbs, int tbsLen, const unsigned char *signature, int signatureLen)
{
	CRYPT_VERIFY_MESSAGE_PARA param;
	BOOL b;
	DWORD index = 0;
	DWORD len;
	unsigned char *out = 0;
	int outLen = 0;

	memset(&param, 0, sizeof(param));
	param.cbSize = sizeof(param);
	param.dwMsgAndCertEncodingType = X509_ASN_ENCODING | PKCS_7_ASN_ENCODING;
	for (;;)
	{
		b = CryptVerifyMessageSignature(
			&param,
			index,
			signature,
			signatureLen,
			NULL,
			&len,
			NULL
			);
		if (b == FALSE)
		{
			if (GetLastError() == CRYPT_E_NO_SIGNER)
			{
				break;
			}
			else
			{
				free(out);
				return 0;
			}

		}
		if (out == 0)
		{
			out = (unsigned char *)malloc(len);
			if (out == 0)
			{
				return 0;
			}
		}
		b = CryptVerifyMessageSignature(
			&param,
			index,
			signature,
			signatureLen,
			out,
			&len,
			NULL
			);
		if (b == FALSE)
		{
			if (GetLastError() == CRYPT_E_NO_SIGNER)
			{
				break;
			}
			else
			{
				free(out);
				return 0;
			}

		}
		outLen = (int)len;
		index++;
	}

	if (out == 0)
	{
		return 0;
	}
	if (outLen != tbsLen)
	{
		free(out);
		return 0;
	}

	if (memcmp(out, tbs, tbsLen) != 0)
	{
		free(out);
		return 0;
	}
	free(out);
	return 1;
}

int DetachedVerify(const unsigned char *tbs, int tbsLen, const unsigned char *signature, int signatureLen)
{
	CRYPT_VERIFY_MESSAGE_PARA param;
	BOOL b;
	DWORD index = 0;

	memset(&param, 0, sizeof(param));
	param.cbSize = sizeof(param);
	param.dwMsgAndCertEncodingType = X509_ASN_ENCODING | PKCS_7_ASN_ENCODING;

	const unsigned char *tbsArray[1];
	DWORD tbsLenArray[1];

	tbsArray[0] = tbs;
	tbsLenArray[0] = tbsLen;
	for (;;)
	{
		b = CryptVerifyDetachedMessageSignature(
			&param,
			index,
			signature,
			signatureLen,
			1,
			tbsArray,
			tbsLenArray,
			NULL
			);
		if (b == FALSE)
		{
			if (GetLastError() == CRYPT_E_NO_SIGNER)
			{
				break;
			}
			else
			{
				return 0;
			}

		}
		index++;
	}

	if (index == 0)
	{
		return 0;
	}

	return 1;
}
