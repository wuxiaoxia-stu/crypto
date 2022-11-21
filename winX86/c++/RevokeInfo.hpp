#ifndef NETCA_REVOKEINFO_INCLUDE_HPP
#define NETCA_REVOKEINFO_INCLUDE_HPP

#include "NETCA_PKI_Crypto.h"
#include <string>
namespace Netca
{
	class CRevokeInfo
	{
	public:
		enum
		{
			NO_INIT_REASON=-2
		};
		CRevokeInfo(){ m_reason=NO_INIT_REASON;}
		CRevokeInfo(int reason,const char *time) 
			:m_reason(reason),m_time(time)
		{
		}
		
		CRevokeInfo(int reason,const std::string& time) 
			:m_reason(reason),m_time(time)
		{
		}

		CRevokeInfo(NETCA_PKI_REVOKEDCERT_HANDLE info);

		int reason()const { return m_reason;}
		std::string revokeTime() const  {return m_time;}
		
	private:
		int m_reason;
		std::string m_time;
	};

};

#endif

