#ifndef NETCA_UTIL_ERRORCODE_INT_INLCUDE_H
#define NETCA_UTIL_ERRORCODE_INT_INLCUDE_H

#include "NETCA_BasicType.h"

#ifdef __cplusplus
extern "C"
	{
#endif

/*
 *		netca_igetGeneralError
 *			����ͨ�õĴ�������
 *		������
 *			errcode����������������
 *		����ֵ��
 *			�ɹ�����ͨ�õĴ���������ʧ�ܷ���""
 */
const char * NETCAAPI netca_igetGeneralError(int errcode);
/*
 *		netca_igetStreamError
 *			����STREAM�Ĵ�������
 *		������
 *			errcode����������������
 *		����ֵ��
 *			�ɹ�����STREAM�Ĵ���������ʧ�ܷ���""
 */
const char * NETCAAPI netca_igetStreamError(int errcode);

#ifdef __cplusplus
	}	
#endif
#endif
