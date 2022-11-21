#include "Mime.hpp"
#include "PKIException.hpp"
#include "SignedData.hpp"
#include "EnvelopedData.hpp"

namespace Netca
{
	CMime::CMime(int type)
	{
		m_hMime = NetcaPKIMsgNewMime(type);
		if (m_hMime == 0)
		{
			throw CPKIException("create mime fail");
		}
	}

	CMime::CMime(NETCA_PKI_MIME_HANDLE hMime)
	{
		m_hMime = hMime;
	}

	CMime::CMime(const unsigned char *data, int dataLen)
	{
		m_hMime = NetcaPKIMsgDecodeMime(data, dataLen);
		if (m_hMime == 0)
		{
			throw CPKIException("bad mime encode");
		}
	}

	CMime::~CMime()
	{
		NetcaPKIMsgFreeMime(m_hMime);
	}

	void CMime::addHeader(const char *header, int pos)
	{
		int rv = NetcaPKIMsgMimeAddHeaderString(m_hMime, pos, header);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"add header string fail");
		}
	}

	void CMime::addHeader(const std::string &header, int pos )
	{
		addHeader(header.c_str(), pos);
	}

	void CMime::addHeader(const char *name, const char *value, const char *params[], int paramCount, int pos )
	{
		int rv = NetcaPKIMsgMimeAddHeader(m_hMime, pos, name, value, params, paramCount);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "add header fail");
		}
	}

	void CMime::addHeader(const char *name, const char *value, int pos )
	{
		int rv = NetcaPKIMsgMimeAddHeader(m_hMime, pos, name, value,0,0);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "add header fail");
		}
	}

	void CMime::addHeader(const std::string &name, const std::string &value, const std::vector<std::string>& param, int pos)
	{
		const char **paramArray;
		int paramCount = (int)param.size();
		paramArray = (const char **)NetcaPKICryptoAllocMemory(sizeof(const char *)*paramCount);
		if (paramArray == 0)
		{
			throw CPKIException("alloc fail");
		}
		for (int i = 0; i<paramCount; i++)
		{
			paramArray[i] = param[i].c_str();
		}
		int rv;
		rv = NetcaPKIMsgMimeAddHeader(m_hMime, pos, name.c_str(), value.c_str(), paramArray, paramCount);
		NetcaPKICryptoFreeMemory(paramArray);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "add header fail");
		}
	}

	void CMime::addHeader(const std::string &name, const std::string &value, int pos)
	{
		addHeader(name.c_str(), value.c_str(),pos);
	}

	void CMime::addHeader(const char *name, const std::string &value, int pos)
	{
		addHeader(name, value.c_str(), pos);
	}

	void CMime::addHeader(const std::string &name, const char *value, int pos)
	{
		addHeader(name.c_str(), value, pos);
	}

	void CMime::setBody(const unsigned char *body, int bodyLen)
	{
		int rv = NetcaPKIMsgMimeSetBody(m_hMime, body, bodyLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "set body fail");
		}
	}

	void CMime::setBoundary(const char *boundary)
	{
		int rv = NetcaPKIMsgMimeSetBoundary(m_hMime, boundary);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "set boundary fail");
		}
	}

	void CMime::setBoundary(const std::string &boundary)
	{
		setBoundary(boundary.c_str());
	}

	void CMime::addSubEntity(const CMime &subMime)
	{
		int rv = NetcaPKIMsgMimeAddSubEntity(m_hMime, subMime.handle());
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "add subentity fail");
		}
	}

	void CMime::encode(CBlob &outData)const
	{
		unsigned char *data;
		int dataLen;
		int rv = NetcaPKIMsgMimeEncode(m_hMime, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "encode mime fail");
		}
		outData.attach(data, dataLen);
	}

	CMime CMime::sign(const CSignedData& signedData, bool detached)
	{
		int rv;
		NETCA_PKI_MIME_HANDLE hSignMime;
		rv = NetcaPKIMsgMimeSign(m_hMime, signedData.handle(), detached?1:0, &hSignMime);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "sign mime fail");
		}
		try
		{
			return CMime(hSignMime);
		}
		catch (std::exception&)
		{
			NetcaPKIMsgFreeMime(hSignMime);
			throw;
		}
	}

	CMime CMime::encrypt(const CEnvelopedData& envelopedData)
	{
		int rv;
		NETCA_PKI_MIME_HANDLE hEncMime;
		rv = NetcaPKIMsgMimeEncrypt(m_hMime, envelopedData.handle(), &hEncMime);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "encrypt mime fail");
		}
		try
		{
			return CMime(hEncMime);
		}
		catch (std::exception&)
		{
			NetcaPKIMsgFreeMime(hEncMime);
			throw;
		}
	}

	int CMime::type()const
	{
		return NetcaPKIMsgMimeGetType(m_hMime);
	}

	std::vector<std::string> CMime::getHeader() const
	{
		std::vector<std::string> v;
		int count = NetcaPKIMsgMimeGetHeaderCount(m_hMime);
		if (count < 0)
		{
			throw CPKIException("get header count fail");
		}
		v.reserve(count);

		char *header;
		for (int i = 0; i < count; i++)
		{
			header=NetcaPKIMsgMimeGetHeaderString(m_hMime,i);
			if (header == 0)
			{
				throw CPKIException("get header fail");
			}
			try
			{
				v.push_back(header);
			}
			catch (std::exception &)
			{
				NetcaPKICryptoFreeMemory(header);
				throw;
			}
			NetcaPKICryptoFreeMemory(header);
		}
		return v;
		
	}

	int CMime::getHeaderCount() const
	{
		return NetcaPKIMsgMimeGetHeaderCount(m_hMime);
	}

	void CMime::getHeader(int index, std::string& name, std::string& value, std::vector<std::string>& param) const
	{
		int rv;
		char *nameString;
		char *valueString;
		char **params;
		int paramCount;
		rv = NetcaPKIMsgMimeGetHeader(m_hMime, index, &nameString, &valueString, &params, &paramCount);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"get header fail");
		}
		param.clear();
		try
		{
			name = nameString;
			value = valueString;
			param.reserve(paramCount);
			for (int i = 0; i < paramCount; i++)
			{
				param.push_back(params[i]);
			}
		}
		catch (std::exception &)
		{
			NetcaPKICryptoFreeMemory(nameString);
			NetcaPKICryptoFreeMemory(valueString);
			for (int i = 0; i < paramCount; i++)
			{
				NetcaPKICryptoFreeMemory(params[i]);
			}
			NetcaPKICryptoFreeMemory(params);
			throw;
		}
		NetcaPKICryptoFreeMemory(nameString);
		NetcaPKICryptoFreeMemory(valueString);
		for (int i = 0; i < paramCount; i++)
		{
			NetcaPKICryptoFreeMemory(params[i]);
		}
		NetcaPKICryptoFreeMemory(params);
	}

	void CMime::deleteHeader(int index)
	{
		int rv;
		rv = NetcaPKIMsgMimeDeleteHeader(m_hMime, index);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "delete header fail");
		}
	}

	void CMime::getBody(CBlob &outData)const
	{
		int rv;
		unsigned char *data;
		int dataLen;

		rv = NetcaPKIMsgMimeGetBody(m_hMime, &data, &dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "get body fail");
		}
		outData.attach(data,dataLen);

	}

	std::string CMime::getBoundary()const
	{
		char * str=NetcaPKIMsgMimeGetBoundary(m_hMime);
		if (str == 0)
		{
			throw CPKIException("get boundary fail");
		}

		try
		{
			std::string boundary(str);
			NetcaPKICryptoFreeMemory(str);
			str = 0;
			return boundary;
		}
		catch (std::exception &)
		{
			NetcaPKICryptoFreeMemory(str);
			throw;
		}

	}

	int CMime::getSubEntityCount()const
	{
		return NetcaPKIMsgMimeGetSubEntityCount(m_hMime);
	}

	CMime CMime::getSubEntity(int index)const
	{
		NETCA_PKI_MIME_HANDLE hSubMime=NetcaPKIMsgMimeGetSubEntity(m_hMime, index);
		if (hSubMime == 0)
		{
			throw CPKIException("get submime fail");
		}

		try
		{
			return CMime(hSubMime);
		}
		catch (std::exception&)
		{
			NetcaPKIMsgFreeMime(hSubMime);
			throw;
		}
	}

	bool CMime::isSign(bool& detached)const
	{
		int value;
		int rv=NetcaPKIMsgMimeIsSign(m_hMime,&value);
		if (rv)
		{
			detached = (value != 0);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CMime::isEncrypt() const
	{
		return NetcaPKIMsgMimeIsEncrypt(m_hMime)!=0;
	}

	int CMime::verify(const CSignedData& signedData, bool& detached, CBlob &tbsData)
	{
		int rv;
		int detachedValue;
		unsigned char *tbs;
		int tbsLen;

		rv = NetcaPKIMsgMimeVerifyBySignedDataHandle(m_hMime, signedData.handle(),&detachedValue, &tbs,&tbsLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			return rv;
		}
		detached = (detachedValue!=0);
		tbsData.attach(tbs, tbsLen);
		return rv;
	}

	void CMime::QuotedPrintableEncode(const unsigned char * in, int inLen, CBlob &outData)
	{
		unsigned char *out;
		int outLen;
		int rv;
		rv = NetcaPKIMsgMimeQuotedPrintableEncode(in,inLen,&out,&outLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv,"QuotedPrintable encode fail");
		}
		outData.attach(out, outLen);
	}

	void CMime::QuotedPrintableDecode(const unsigned char * in, int inLen, CBlob &outData)
	{
		unsigned char *out;
		int outLen;
		int rv;
		rv = NetcaPKIMsgMimeQuotedPrintableDecode(in, inLen, &out, &outLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "QuotedPrintable decode fail");
		}
		outData.attach(out, outLen);
	}

	void CMime::MimeHeaderExtsEncode(const char *charset, int encode, const unsigned char * in, int inLen, CBlob &outData)
	{
		unsigned char *out;
		int outLen;
		int rv;
		rv = NetcaPKIMsgMimeHeaderExtsEncode(charset, encode,in, inLen, &out, &outLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "Mime Header Ext encode fail");
		}
		outData.attach(out, outLen);
	}
	void CMime::MimeHeaderExtsEncode(const std::string& charset, int encode, const unsigned char * in, int inLen, CBlob &outData)
	{
		MimeHeaderExtsEncode(charset.c_str(), encode, in, inLen, outData);
	}

	void CMime::MimeHeaderExtsDecode(const unsigned char * in, int inLen, std::string& charset, int &encode, CBlob &outData)
	{
		int rv;
		unsigned char *out;
		int outLen;
		char *charsetString;

		rv = NetcaPKIMsgMimeHeaderExtsDecode(in, inLen, &charsetString, &encode, &out, &outLen);
		if (rv!=NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "Mime Header Ext decode fail");
		}
		outData.attach(out, outLen);
		try
		{
			charset = charsetString;
			NetcaPKICryptoFreeMemory(charsetString);
			charsetString = 0;
		}
		catch (std::exception &)
		{
			NetcaPKICryptoFreeMemory(charsetString);
			throw;
		}
	}

	CMime CMime::NewAttachMime(const char *contentType, const char *charset, const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary)
	{
		NETCA_PKI_MIME_HANDLE hMime=NetcaPKIMsgNewAttachMime(isBinary?1:0,
			contentType, charset, fileName, fileContent, fileLen);
		if (hMime == 0)
		{
			throw CPKIException("NewAttachMime fail");
		}
		try
		{
			return CMime(hMime);
		}
		catch (std::exception&)
		{
			NetcaPKIMsgFreeMime(hMime);
			throw;
		}
	}

	CMime CMime::NewAttachMime(const std::string& contentType, const std::string& charset, const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary)
	{
		return NewAttachMime(contentType.c_str(), charset.c_str(), fileName.c_str(), fileContent, fileLen, isBinary);
	}
	CMime CMime::NewAttachMime(const char *charset, const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary)
	{
		return NewAttachMime(0, charset, fileName, fileContent, fileLen, isBinary);
	}

	CMime CMime::NewAttachMime(const std::string& charset, const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary )
	{
		return NewAttachMime(0, charset.c_str(), fileName.c_str(), fileContent, fileLen, isBinary);
	}

	CMime CMime::NewAttachMime(const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary)
	{
		return NewAttachMime(0, 0, fileName, fileContent, fileLen, isBinary);
	}

	CMime CMime::NewAttachMime(const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary)
	{
		return NewAttachMime(0, 0, fileName.c_str(), fileContent, fileLen, isBinary);
	}

	CMime CMime::NewAttachMime(const char *contentType, const char *charset, const char *fileName, bool isBinary)
	{
		return NewAttachMime(contentType, charset, fileName, 0, 0, isBinary);
	}

	CMime CMime::NewAttachMime(const std::string& contentType, const std::string& charset, const std::string& fileName, bool isBinary)
	{
		return NewAttachMime(contentType.c_str(), charset.c_str(), fileName.c_str(), 0, 0, isBinary);
	}
	CMime CMime::NewAttachMime(const char *charset, const char *fileName,  bool isBinary)
	{
		return NewAttachMime(0, charset, fileName, 0, 0, isBinary);
	}

	CMime CMime::NewAttachMime(const std::string& charset, const std::string& fileName,  bool isBinary)
	{
		return NewAttachMime(0, charset.c_str(), fileName.c_str(), 0,0, isBinary);
	}

	CMime CMime::NewAttachMime(const char *fileName,  bool isBinary)
	{
		return NewAttachMime(0, 0, fileName, 0, 0, isBinary);
	}

	CMime CMime::NewAttachMime(const std::string& fileName,  bool isBinary)
	{
		return NewAttachMime(0, 0, fileName.c_str(), 0, 0, isBinary);
	}

	void CMime::decrypt(const CEnvelopedData& envelopedData,CBlob &clearData)
	{
		int rv;
		unsigned char *data;
		int dataLen;
		rv = NetcaPKIMsgMimeDecryptByEnvelopedDataHandle(m_hMime, envelopedData.handle(), &data,&dataLen);
		if (rv != NETCA_PKI_SUCCESS)
		{
			throw CPKIException(rv, "decrypy mime fail");
		}
		clearData.attach(data,dataLen);
	}
}

