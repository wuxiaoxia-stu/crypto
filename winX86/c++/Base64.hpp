#ifndef NETCA_BASE64_INCLUDE_HPP
#define NETCA_BASE64_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include "Blob.hpp"
#include <string>

namespace Netca
{

	class CBase64
	{
	public:
		CBase64(bool encode,int flag);
		~CBase64();
		
		void update(const unsigned char *inData,int inDataLen,CBlob& outData);
		void final(CBlob& outData);

		static std::string Encode(int flag,const unsigned char *inData,int inDataLen);
		static void Decode(int flag,const unsigned char *inData,int inDataLen,CBlob& outData);
		static void Decode(int flag,const std::string &b64String,CBlob& outData);
		static void Decode(int flag,const char *b64String,CBlob& outData);
		
	private:
		CBase64(const CBase64& base64);
		CBase64& operator =(const CBase64& base64);
		NETCA_PKI_BASE64_HANDLE m_hBase64;
	};

};

#endif

