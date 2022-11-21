#ifndef NETCA_MIME_INCLUDE_HPP
#define NETCA_MIME_INCLUDE_HPP

#include "NETCA_PKI_SMIMe.h"
#include "Blob.hpp"
#include <climits>
#include <string>
#include <vector>

namespace Netca
{
	class CSignedData;
	class CEnvelopedData;

	class CMime
	{
	public:
		CMime(int type);
		CMime(const unsigned char *data,int dataLen);
		~CMime();

		void addHeader(const char *header,int pos=INT_MAX);
		void addHeader(const std::string &header, int pos = INT_MAX);
		void addHeader(const char *name, const char *value, const char *params[], int paramCount,int pos = INT_MAX);
		void addHeader(const char *name, const char *value, int pos = INT_MAX);
		void addHeader(const std::string &name, const std::string &value, const std::vector<std::string>& param, int pos = INT_MAX);
		void addHeader(const std::string &name, const std::string &value, int pos = INT_MAX);
		void addHeader(const char *name, const std::string &value, int pos = INT_MAX);
		void addHeader(const std::string &name, const char *value, int pos = INT_MAX);

		void setBody(const unsigned char *body, int bodyLen);

		void setBoundary(const char *boundary);
		void setBoundary(const std::string& boundary);

		void addSubEntity(const CMime &subMime);

		void encode(CBlob &outData)const;

		CMime sign(const CSignedData& signedData, bool detached);

		CMime encrypt(const CEnvelopedData& envelopedData);

		void decrypt(const CEnvelopedData& envelopedData,CBlob &clearData);

		int type()const;

		std::vector<std::string> getHeader() const;
		int getHeaderCount() const;
		void getHeader(int index, std::string& name, std::string& value, std::vector<std::string>& param) const;

		void deleteHeader(int index);

		void getBody(CBlob &outData)const;

		std::string getBoundary()const;

		int getSubEntityCount()const;
		CMime getSubEntity(int index)const;

		bool isSign(bool& detached)const;

		bool isEncrypt() const;

		int verify(const CSignedData& signedData, bool& detached, CBlob &tbsData);
		

		static void QuotedPrintableEncode(const unsigned char * in, int inLen, CBlob &outData);
		static void QuotedPrintableDecode(const unsigned char * in, int inLen, CBlob &outData);


		static void MimeHeaderExtsEncode(const char *charset, int encode, const unsigned char * in, int inLen, CBlob &outData);
		static void MimeHeaderExtsEncode(const std::string& charset, int encode, const unsigned char * in, int inLen, CBlob &outData);

		static void MimeHeaderExtsDecode(const unsigned char * in, int inLen, std::string& charset, int &encode, CBlob &outData);

		static CMime NewAttachMime(const char *contentType, const char *charset, const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const std::string& contentType, const std::string& charset, const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const char *charset, const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const std::string& charset, const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const char *fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const std::string& fileName, const unsigned char *fileContent, int fileLen, bool isBinary = false);
		static CMime NewAttachMime(const char *contentType, const char *charset, const char *fileName, bool isBinary = false);
		static CMime NewAttachMime(const std::string& contentType, const std::string& charset, const std::string& fileName, bool isBinary = false);
		static CMime NewAttachMime(const char *charset, const char *fileName,  bool isBinary = false);
		static CMime NewAttachMime(const std::string& charset, const std::string& fileName, bool isBinary = false);
		static CMime NewAttachMime(const char *fileName, bool isBinary = false);
		static CMime NewAttachMime(const std::string& fileName, bool isBinary = false);


	private:
		CMime(NETCA_PKI_MIME_HANDLE hMime);
		CMime(const CMime& mime);
		CMime& operator =(const CMime& mime);

		NETCA_PKI_MIME_HANDLE handle() const { return m_hMime;}
		NETCA_PKI_MIME_HANDLE m_hMime;
	};

};

#endif

