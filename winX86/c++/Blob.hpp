#ifndef NETCA_BLOB_INCLUDE_HPP
#define NETCA_BLOB_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include <string>
namespace Netca
{

	class CBlob
	{
	public:
		CBlob();
		CBlob(const unsigned char *data,int dataLen);
		~CBlob();
				
		void attach(unsigned char *data,int dataLen);
		void assign(const unsigned char *data,int dataLen);
		void assign(const CBlob &blob);
		unsigned char *data() { return m_data; }
		const unsigned char *data()const { return m_data; }
		int length() const { return m_dataLen; }
		
		void clear();
		bool isEmpty()const ;

		void decodeHexString(const char *str,int strLen);
		void decodeHexString(const char *str);
		void decodeHexString(std::string str);

		std::string encodeHexString(bool capital=true)const;
	private:
		CBlob(const CBlob& blob);
		CBlob& operator =(const CBlob& blob);

		unsigned char *m_data;
		int m_dataLen;
	};

	std::string HexEncode(bool capital,const unsigned char *data,int dataLen);
};

#endif

