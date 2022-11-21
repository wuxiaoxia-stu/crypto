#include <string.h>
#include "Blob.hpp"
#include "PKIException.hpp"

namespace
{
	bool decodeHexChar(const unsigned char *hex,unsigned char *ch)
	{
		int high;
		int low;
		static int hexDecodeTable[128]={
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,
			-1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
			-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
		};
		
		if(hex[0]>127||hex[1]>127)
		{
			return false;
		}
		
		high=hexDecodeTable[hex[0]];
		low=hexDecodeTable[hex[1]];
		if(high<0||low<0)
		{
			return false;
		}
		*ch=(unsigned char)(high<<4|low);
		return true;
	}

	bool decodeHexString(const unsigned char *hexStr,int hexLen,unsigned char *outBuf)
	{
		for(int i=0;i<hexLen;i+=2)
		{
			if(decodeHexChar(&hexStr[i],outBuf)==false)
			{
				return false;
			}
			outBuf++;
		}
		return true;
	}

}

namespace Netca
{
	CBlob::CBlob()
	{
		m_data=0;
		m_dataLen=0;
	}

	CBlob::CBlob(const unsigned char *data,int dataLen)
	{
		m_dataLen=dataLen;
		m_data=(unsigned char*)NetcaPKICryptoAllocMemory(m_dataLen);
		if(m_data==0)
		{
			throw CPKIException("alloc fail");
		}
		memcpy(m_data,data,dataLen);
	}
	CBlob::~CBlob()
	{
		if(m_data)
		{
			NetcaPKICryptoFreeMemory(m_data);
		}
	}

	void CBlob::attach(unsigned char *data,int dataLen)
	{
		if(m_data)
		{
			NetcaPKICryptoFreeMemory(m_data);
		}

		m_dataLen=dataLen;
		m_data=data;
	}

	void CBlob::clear()
	{
		if(m_data)
		{
			memset(m_data,0,m_dataLen);
			NetcaPKICryptoFreeMemory(m_data);
		}
		m_data=0;
		m_dataLen=0;
	}

	bool CBlob::isEmpty()const 
	{
		if(m_data==0 || m_dataLen==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void CBlob::assign(const unsigned char *data,int dataLen)
	{
		
		unsigned char *newData=(unsigned char*)NetcaPKICryptoAllocMemory(dataLen);
		if(newData==0)
		{
			throw CPKIException("alloc fail");
		}
		memcpy(newData,data,dataLen);
		NetcaPKICryptoFreeMemory(m_data);
		m_data=newData;
		m_dataLen=dataLen;
	}
	void CBlob::assign(const CBlob &blob)
	{
		if(&blob==this)
		{
			return;
		}

		if(blob.isEmpty())
		{
			NetcaPKICryptoFreeMemory(m_data);
			m_data=0;
			m_dataLen=0;
		}
		else
		{
			assign(blob.m_data,blob.m_dataLen);
		}
	}

	void CBlob::decodeHexString(const char *str,int strLen)
	{
		if(strLen%2!=0)
		{
			throw CPKIException("HexString's length is odd");
		}
		if(strLen<0)
		{
			throw CPKIException("HexString's length is negative");
		}

		unsigned char *data;
		int dataLen=strLen/2;

		data=(unsigned char *)NetcaPKICryptoAllocMemory(dataLen);
		if(data==0)
		{
			throw CPKIException("alloc fail");
		}
		if(::decodeHexString((const unsigned char *)str,strLen,data)==false)
		{
			NetcaPKICryptoFreeMemory(data);
			throw CPKIException("bad HexString");
		}
		attach(data,dataLen);
	}

	void CBlob::decodeHexString(const char *str)
	{
		decodeHexString(str,(int)strlen(str));
	}
	void CBlob::decodeHexString(std::string str)
	{
		decodeHexString(str.c_str(),(int)str.length());
	}

	std::string CBlob::encodeHexString(bool capital)const
	{
		return HexEncode(capital,m_data,m_dataLen);
	}

	std::string HexEncode(bool capital,const unsigned char *data,int dataLen)
	{
		char *hex;
		int i;
		const char *formatStr=capital?"%02X":"02x";

		if(dataLen<0)
		{
			throw CPKIException("bad argurement");
		}
		if(	data==0 && dataLen!=0)
		{
			throw CPKIException("bad argurement");
		}
		hex=(char *)NetcaPKICryptoAllocMemory(dataLen*2+1);
		if(hex==0)
		{
			throw CPKIException("alloc fail");
		}

		for(i=0;i<dataLen;i++)
		{
			sprintf(&hex[2*i],formatStr,data[i]);
		}
		try
		{
			std::string str(hex);
			NetcaPKICryptoFreeMemory(hex);
			hex=0;
			return str;
		}
		catch(...)
		{
			if(hex)
			{
				NetcaPKICryptoFreeMemory(hex);
			}
			throw;
		}
	}
};

