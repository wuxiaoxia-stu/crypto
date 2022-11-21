#ifndef NETCA_PKIEXCEPTION_INCLUDE_HPP
#define NETCA_PKIEXCEPTION_INCLUDE_HPP

#include "NETCA_PKI_Const.h"
#include <exception>

namespace Netca
{

	class CPKIException:public std::exception
	{
	public:
		CPKIException() :std::exception(){ m_errorCode = NETCA_PKI_FAIL; }
		CPKIException(const char *what) :std::exception(what){ m_errorCode = NETCA_PKI_FAIL; }
		CPKIException(int errorCode, const char *what) :std::exception(what){ m_errorCode = errorCode; }

		int errorCode()const { return m_errorCode; }
	private:
		int m_errorCode;
	};

};

#endif
