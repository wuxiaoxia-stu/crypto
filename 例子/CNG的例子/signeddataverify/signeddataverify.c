#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

static int GetFileLength(FILE *fp);
static void Usage(const char *progName);
static int ReadFileData(const char *fileName, unsigned char **data, int *dataLen);
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
	int pos;
	int detached;
	unsigned char* sign;
	int signLen;
	int rv;

	if (argc != 3 && argc != 4)
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

	rv = ReadFileData(signFileName,&sign,&signLen);
	if (rv == 0)
	{
		printf("Read sign file fail");
		return -1;
	}

	if (detached)
	{
		rv = DetachedVerify((const unsigned char*)tbs, (int)strlen(tbs),
			sign, signLen);
	}
	else
	{
		rv = Verify((const unsigned char*)tbs, (int)strlen(tbs),
			sign, signLen);
	}
	free(sign);
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

PCCERT_CONTEXT GetCert(const char *fileName)
{
	PCCERT_CONTEXT cert;
	unsigned char *data;
	int dataLen;
	int rv;

	rv = ReadFileData(fileName, &data, &dataLen);
	if (rv == 0)
	{
		return NULL;
	}
	cert = CertCreateCertificateContext(X509_ASN_ENCODING, data, dataLen);
	free(data);
	return cert;
}

int Verify(const unsigned char *tbs, int tbsLen,const unsigned char *signature, int signatureLen)
{
	CRYPT_VERIFY_MESSAGE_PARA param;
	BOOL b;
	DWORD index = 0;
	DWORD len;
	unsigned char *out = 0;
	int outLen=0;

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
