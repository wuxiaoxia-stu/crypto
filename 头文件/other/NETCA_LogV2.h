#ifndef NETCA_LOG_V2_H
#define NETCA_LOG_V2_H

#include "NETCA_PKI_Const.h"


#ifdef __cplusplus
extern "C"
{
#endif


// ��־�ȼ�
#define NETCA_LOG_LEVEL_DEBUG		1
#define NETCA_LOG_LEVEL_INFO		2
#define NETCA_LOG_LEVEL_WARN		3
#define NETCA_LOG_LEVEL_ERROR		4
#define NETCA_LOG_LEVEL_FATAL		5

	// ���ģʽ
#define NETCA_LOG_MODE_FILE				1
#define NETCA_LOG_MODE_CONSOLE	2

	// ��������������
#define NETCA_LOG_BINTYPE_HEX			1
#define NETCA_LOG_BINTYPE_BASE64		2


struct NetcaLogStruct;
typedef NetcaLogStruct * NetcaLogHandle;


/*
 * NetcaCreateLogHandle
 * ������־�ľ��
 * ����
 *        handle, ָ���ȡ������־���ָ�롣
 * return
 *       �ɹ����� NETCA_PKI_SUCCESS�� ʧ�ܷ���������
 */
int NETCADLLAPI  NetcaCreateLogHandle(NetcaLogHandle * handle); 


/*
 * NetcaFreeLogHandle
 * �ͷ���־�ľ��
 * ����
 *        handle, ָ���ȡ������־���ָ�롣
 * return
 *       �ɹ����� NETCA_PKI_SUCCESS�� ʧ�ܷ���������
 */
void NETCADLLAPI  NetcaFreeLogHandle(NetcaLogHandle  handle); 



/*
 *	NetcaLogHandleSetConfigParam
 *		������־����������û�е��øýӿڣ���Ĭ�ϵ�����¼�¼����־�ȼ�Ϊerror�������ʽΪ�ļ�
 *	������
 *      handle: ��־���
 *		level�������������¼��־�ĵȼ������ڸõȼ�����־�����¼
 *		type����������������ʽ
 *		filepath�������������־�ļ���·����UTF-8��ʽ��
 *                �����涨������־�ļ������ƣ�������־�ļ��ᰴ�ղ�ͬ���ڲ������ơ�
 *                �ļ�����+���ڣ�����ʵ�ʵ���־�ļ����ơ���type����Ϊ����̨ʱ��filepath������ΪNULL��
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
int NETCADLLAPI  NetcaLogHandleSetConfigParam(NetcaLogHandle handle,int level, int type, const char* filepath);


/*
 *	NetcaLogHandleReadConfigFile
 *		�������ļ��л�ȡ��־�����������û�����õĲ�����Ĭ���������NetcaLogSetConfigParam˵��һ�¡�
 *	������
 *      handle: ��־���
 *		filepath�������������־���������ļ�·����UTF-8��ʽ��
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI  NetcaLogHandleReadConfigFile(NetcaLogHandle handle,const char* filepath);

/*
 *	NetcaLogClose
 *		�ر�Log�ļ������øýӿں������д����־�ļ�������Ĭ�ϲ�������ʽ��¼��־
 *	������
 *      handle: ��־���
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI  NetcaLogHandleClose(NetcaLogHandle handle);

/*
 *	NetcaLogHandleLogger
 *		д��ָ���ȼ�����־��Ϣ�������־��Ϣд�뵽�ļ��У������ʹ��������Զ���־��Ϣ���л��塣
 *	������
 *      handle: ��־���
 *		level�����������д�����־��Ϣ�ĵȼ�
 *		msg�������������־��Ϣ��UTF-8����
 *		����0�����߶���������������������sprintfһ�¡��ַ���UTF-8����
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI NetcaLogHandleLogger(NetcaLogHandle handle,int level, const char* msg, ...);

/*
 *	NetcaLogHandleBinLogger
 *		д��ָ���ȼ��Ķ��������ݵ���־��Ϣ�������־��Ϣд�뵽�ļ��У������ʹ��������Զ���־��Ϣ���л��塣
 *	������
 *      handle: ��־���
 *		level�����������д�����־��Ϣ�ĵȼ���
 *		msg�������������־��Ϣ������������
 *		length�����������msg�ĳ���
 *		type�������������ʾʹ��Base64�������ʮ�����Ʊ��롣
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI  NetcaLogHandleBinLogger(NetcaLogHandle handle,int level, const unsigned char* msg, int length, int type);

/*
 *	NetcaLogHandleBeginTransaction
 *		��ʼ��־���񣬼���־��Ϣ�ᱻ�����������������д����־�ļ���ģʽ��Ч�����ڴ�ӡ�ڿ���̨�ķ�ʽ��Ч��
 *	������
 *      handle: ��־���		
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI  NetcaLogHandleBeginTransaction(NetcaLogHandle handle);

/*
 *	NetcaCommitTransaction
 *		�ύ���񣬼��ѻ������־��Ϣȫ����ӡ������
 *	������
 *      handle: ��־���		
 *	����ֵ��
 *		�ɹ�NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 *
 */
 int NETCADLLAPI  NetcaLogHandleCommitTransaction(NetcaLogHandle handle);

/*
 *	NetcaLogHandleGetLogLevel
 *		��ȡ��ǰд���ļ����߿���̨����־�ȼ���
 *	������
 *      handle: ��־���
 *	����ֵ��
 *		�ɹ���־�ȼ���ʧ�ܷ���-1
 *
 */
 int NETCADLLAPI  NetcaLogHandleGetLogLevel(NetcaLogHandle handle);

/*
 *	NetcaLogHandleLevelEnabled
 *		�ж�ĳһ�ȼ���־�Ƿ��ܹ�д��
 *	������
 *      handle: ��־���
 *		level�������������Ҫ�жϵĵȼ���
 *	����ֵ��
 *		��д�·���1�����򷵻�0
 *
 */
 int NETCADLLAPI  NetcaLogHandleLevelEnabled(NetcaLogHandle handle,int level);

#ifdef __cplusplus
}
#endif

#endif