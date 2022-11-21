#ifndef _NETCA_LOG_H_
#define _NETCA_LOG_H_

#include "NETCA_PKI_Const.h"
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif

// ��־�ȼ�
#define NETCA_LOG_LEVEL_DEBUG		1
#define NETCA_LOG_LEVEL_INFO		2
#define NETCA_LOG_LEVEL_WARN		3
#define NETCA_LOG_LEVEL_ERROR		4
#define NETCA_LOG_LEVLE_FATAL		5

// ���ģʽ
#define NETCA_LOG_MODE_FILE				1
#define NETCA_LOG_MODE_CONSOLE	2

// ��������������
#define NETCA_LOG_BINTYPE_HEX			1
#define NETCA_LOG_BINTYPE_BASE64		2

/*
 *	NetcaLogSetConfigParam
 *		������־����������û�е��øýӿڣ���Ĭ�ϵ�����¼�¼����־�ȼ�Ϊerror�������ʽΪ�ļ�
 *	������
 *		level�������������¼��־�ĵȼ������ڸõȼ�����־�����¼
 *		type����������������ʽ
 *		filepath�������������־�ļ���·����UTF-8��ʽ�������涨������־�ļ������ƣ�������־�ļ��ᰴ�ղ�ͬ���ڲ������ơ��ļ�����+���ڣ�����ʵ�ʵ���־�ļ����ơ�
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogSetConfigParam(int level, int type, const char* filepath);

/*
 *	NetcaLogReadConfigFile
 *		�������ļ��л�ȡ��־�����������û�����õĲ�����Ĭ���������NetcaLogSetConfigParam˵��һ�¡�
 *	������
 *		filepath�������������־���������ļ�·����UTF-8��ʽ��
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogReadConfigFile(const char* filepath);

/*
 *	NetcaLogClose
 *		�ر�Log�ļ������øýӿں������д����־�ļ�������Ĭ�ϲ�������ʽ��¼��־
 *	������
 *
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogClose(void);

/*
 *	NetcaLogLogger
 *		д��ָ���ȼ�����־��Ϣ�������־��Ϣд�뵽�ļ��У������ʹ��������Զ���־��Ϣ���л��塣
 *	������
 *		level�����������д�����־��Ϣ�ĵȼ�
 *		msg�������������־��Ϣ��UTF-8����
 *		����0�����߶���������������������sprintfһ�¡��ַ���UTF-8����
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogLogger(int level, const char* msg, ...);

/*
 *	NetcaLogBinLogger
 *		д��ָ���ȼ��Ķ��������ݵ���־��Ϣ�������־��Ϣд�뵽�ļ��У������ʹ��������Զ���־��Ϣ���л��塣
 *	������
 *		level�����������д�����־��Ϣ�ĵȼ���
 *		msg�������������־��Ϣ������������
 *		length�����������msg�ĳ���
 *		type�������������ʾʹ��Base64�������ʮ�����Ʊ��롣
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogBinLogger(int level, const unsigned char* msg, int length, int type);

/*
 *	NetcaLogBeginTransaction
 *		��ʼ��־���񣬼���־��Ϣ�ᱻ�����������������д����־�ļ���ģʽ��Ч�����ڴ�ӡ�ڿ���̨�ķ�ʽ��Ч��
 *	������
 *		
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogBeginTransaction(void);

/*
 *	NetcaCommitTransaction
 *		�ύ���񣬼��ѻ������־��Ϣȫ����ӡ������
 *	������
 *		
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI NetcaLogCommitTransaction(void);

/*
 *	NetcaGetLogLevel
 *		��ȡ��ǰд���ļ����߿���̨����־�ȼ���
 *	������
 *		
 *	����ֵ��
 *		�ɹ���־�ȼ���ʧ�ܷ���-1
 *
 */
int NETCADLLAPI NetcaLogGetLogLevel(void);

/*
 *	NetcaLogLevelEnabled
 *		�ж�ĳһ�ȼ���־�Ƿ��ܹ�д��
 *	������
 *		level�������������Ҫ�жϵĵȼ���
 *	����ֵ��
 *		��д�·���1�����򷵻�0
 *
 */
int NETCADLLAPI NetcaLogLevelEnabled(int level);

#ifdef __cplusplus
	}	
#endif
#endif
