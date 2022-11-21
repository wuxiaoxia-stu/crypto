#include "RevokeInfo.hpp"
#include "PKIException.hpp"

namespace Netca
{
	CRevokeInfo::CRevokeInfo(NETCA_PKI_REVOKEDCERT_HANDLE info)
	{
		if(info==0)
		{
			throw CPKIException("revoke info is null");
		}
		m_reason=NetcaPKICertGetRevokedCertRevokedReason(info);
		char *time=NetcaPKICertGetRevokedCertRevokedTime(info);
		if(time==0)
		{
			throw CPKIException("revoke info get revoke time fail");
		}
		try
		{
			m_time=time;
			NetcaPKICryptoFreeMemory(time);
			time=0;
		}
		catch(std::exception&)
		{
			NetcaPKICryptoFreeMemory(time);
			throw;
		}
	}
}
