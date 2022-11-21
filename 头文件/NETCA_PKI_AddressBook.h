#ifndef NETCA_PKI_ADDRESSBOOK_H
#define NETCA_PKI_ADDRESSBOOK_H

#include <wchar.h>
#include "NETCA_PKI_Type.h"

#ifdef __cplusplus
extern "C"
	{
#endif


/*
 *		NetcaAddressBookOpen
 *			���ļ���Ϊfilename�ĵ�ַ��������ļ������ڣ����ȴ���
 *		������
 *			filename������������ļ�����UTF-8����
 *		����ֵ��
 *			�ɹ����ص�ַ�������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_HANDLE NETCADLLAPI NetcaAddressBookOpen(const char * filename);

/*
 *		NetcaAddressBookClose
 *			�رյ�ַ��
 *		������
 *			hAddressBook�������������ַ�����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookClose(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook);

/*
 *		NetcaAddressBookOpenStore
 *			����Ϊ��ϵ��֤���ĵ�ַ������������ڣ����ȴ���
 *		������
 *			type�����������֤�������
 *		����ֵ��
 *			�ɹ����ص�ַ�������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_HANDLE NETCADLLAPI NetcaAddressBookOpenStore(int type);

/*
 *		NetcaAddressBookCreateGroup
 *			����һ����
 *		������
 *			hAddressBook�������������ַ�����
 *			name�����������������UTF-8����
 *			description��������������������UTF-8����
 *		����ֵ��
 *			�ɹ������´�����������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookCreateGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook ,const char *name,const char *description);

/*
 *		NetcaAddressBookDupGroup
 *			����һ����
 *		������
 *			hGroup�����������ԭ����
 *		����ֵ��
 *			�ɹ����ظ��Ƶ�������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookDupGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookDeleteGroup
 *			ɾ��һ����
 *		������
 *			hGroup�����������ԭ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeleteGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookFreeGroup
 *			�ͷ�����
 *		������
 *			hGroup�����������ԭ����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookFreeGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookAddChildGroup
 *			���ĳ�����鵽������
 *		������
 *			hFartherGroup�����������������
 *			hChildGroup�����������������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddChildGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hFartherGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hChildGroup);

/*
 *		NetcaAddressBookGetBaseGroupCount
 *			��ȡ��ַ���л����������
 *		������
 *			hAddressBook�������������ַ����
 *		����ֵ��
 *			�ɹ����ص�ַ���л��������������û�и�����飬ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaAddressBookGetBaseGroupCount(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook);

/*
 *		NetcaAddressBookGetBaseGroup
 *			��ȡ��ַ���е�index��������
 *		������
 *			hAddressBook�������������ַ����
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�ַ���е�index�������飬ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetBaseGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook,int index);

/*
 *		NetcaAddressBookGetMemberGroupCount
 *			��ȡ��ַ������ĳ�Ա�����
 *		������
 *			hGroup���������������
 *		����ֵ��
 *			�ɹ����ص�ַ�������ƾ��ָ������ĳ�Ա�������ʧ�ܷ���-1
 */
int NETCADLLAPI NetcaAddressBookGetMemberGroupCount(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetMemberGroup
 *			��ȡ��ַ���е�ַ��������Ϊָ����ĵ�index����Ա��
 *		������
 *			hGroup���������������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�ַ��������Ϊָ����ĵ�index����Ա�飬ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetMemberGroup( NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,int index);

/*
 *		NetcaAddressBookGetGroupName
 *			��ȡ�������
 *		������
 *			hGroup���������������
 *		����ֵ��
 *			�ɹ��������UTF-8��ʽ�����ƣ�UTF-8���룬ʧ�ܷ���NULL�����ص�������NETCA_FREE���ͷ�
 */
char* NETCADLLAPI NetcaAddressBookGetGroupName(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookUpdateGroupName
 *			�����������
 *		������
 *			hGroup���������������
 *			name�����������������ƣ�UTF-8����
 *		����ֵ��
 *			�ɹ�������NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookUpdateGroupName(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,const char* name);

/*
 *		NetcaAddressBookGetGroupDescription
 *			��ȡ��ַ�������Ӧ����
 *		������
 *			hGroup���������������
 *		����ֵ��
 *			�ɹ����ص�ַ��������Ϊname�������,UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaAddressBookGetGroupDescription(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookUpdateGroupDescription
 *			�޸ĵ�ַ�����������
 *		������
 *			hGroup���������������
 *			description�����������������,UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookUpdateGroupDescription(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,const char *description);

/*
 *		NetcaAddressBookGetMemberCount
 *			��ȡ��ַ������ĳ�Ա����
 *		������
 *			hGroup���������������
 *		����ֵ��
 *			�ɹ����ص�ַ�������ƾ��ָ������ĳ�Ա������ʧ�ܷ���-1
 */
 int NETCADLLAPI NetcaAddressBookGetMemberCount(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetMember
 *			��ȡ��ַ���е�ַ����ָ����ĵ�index����Ա
 *		������
 *			hGroup���������������
 *			index���������������ֵ����0����
 *		����ֵ��
 *			�ɹ����ص�ַ����ָ����ĵ�index����Ա��ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookGetMember(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,int index);

/*
 *		NetcaAddressBookFindMember
 *			����ָ������ϵ��
 *		������
 *			hGroup���������������
 *			searchType���������������������
 *			value�����������������ֵ,UTF-8����
 *			pPersons��������������صķ���������һ����ϵ��
 *			count��������������ص���ϵ�˸���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookFindMember(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int searchType,const char* value,NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE **pPersons,int *count);

/*
 *		NetcaAddressBookFindGroup
 *			��������������
 *		������
 *			hAddressBook�������������ַ�����
 *			name�����������������ƣ�,UTF-8����
 *			hGroups������������ʺ���������
 *			count��������������ص�hGroupsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookFindGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook ,const char* name, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE** hGroups,int *count);

/*
 *		NetcaAddressBookGetGroupFromMemberGroup
 *			���������ȡ�������ĸ���ľ��
 *		������
 *			hGroup�����������������
 *		����ֵ��
 *			�ɹ�����������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE  NETCADLLAPI NetcaAddressBookGetGroupFromMemberGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetGroupFromMember
 *			������ϵ�˻�ȡ�������ĸ���ľ��
 *		������
 *			hPerson�������������ϵ�˾��
 *		����ֵ��
 *			�ɹ�����������ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetGroupFromMember(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookCreatePerson
 *			����һ����ϵ��
 *		������
 *			name�������������ַ�����
 *		����ֵ��
 *			�ɹ�������ϵ�˾����ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookCreatePerson(const char *name);

/*
 *		NetcaAddressBookDupMember
 *			����һ����ϵ�˾��
 *		������
 *			hPerson�����������l��ϵ�˾��
 *		����ֵ��
 *			�ɹ����ظ��Ƶ���ϵ�˾����ʧ�ܷ���NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookDupMember(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookFreePerson
 *			�ͷ���ϵ�˾��
 *		������
 *			hPerson�����������l��ϵ�˾��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookFreePerson(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookAddPerson
 *			����ϵ�˼������С��ɹ�����ϵ�˼��뵽����ʱ����ϵ�˾����ָ������Ϊ��ǰ���顣
 *		������
 *			hGroup���������������
 *			hPerson�������������ϵ�˾��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddPerson(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookDeletePerson
 *			�����ݿ���ɾ����ϵ�˼�¼
 *		������
 *			hPerson�������������ϵ�˾��
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeletePerson(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookGetPersonName
 *			�����ϵ�˵�����
 *		������
 *			hPerson�������������ϵ�˾��
 *		����ֵ��
 *			�ɹ�������ϵ�˵�����,UTF-8���룬ʧ�ܷ���NULL
 */
char * NETCADLLAPI NetcaAddressBookGetPersonName(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

 /*
 *		NetcaAddressBookUpdatePersonName
 *			������ϵ�˵�����
 *		������
 *			hPerson�������������ϵ�˾��
 *			name���������������,UTF-8����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonName(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson,const char *name);

/*
 *		NetcaAddressBookFindPerson
 *			����ָ������ϵ��
 *		������
 *			hAddressBook�������������ַ�����
 *			searchType���������������������
 *			value�����������������ֵ,UTF-8����
 *			pPersons��������������صķ���������һ����ϵ��
 *			count��������������ص���ϵ�˸���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookFindPerson(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook, int searchType,const char* value,NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE **pPersons,int *count);
 
/*
 *		NetcaAddressBookGetAllCert
 *			��ȡ��ַ�������е�֤��
 *		������
 *			hAddressBook�������������ϵ�˾��
 *			pCerts��������������ص�֤��
 *			count��������������ص�֤�����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
 int NETCADLLAPI NetcaAddressBookGetAllCert(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook, NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

 /*
 *		NetcaAddressBookGetPersonStringAttrCount
 *			��ȡ��ϵ��ĳ���ַ��������Ե�ֵ������
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *		����ֵ��
 *			����attrtype���Ե�ֵ�ĸ�����ʧ���򷵻�-1
 */
int NETCADLLAPI NetcaAddressBookGetPersonStringAttrCount(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

 /*
 *		NetcaAddressBookGetPersonStringAttr
 *			������������ȡ��ϵ��ĳ���ַ��������Ե�ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *		����ֵ��
 *			�ɹ�����UTF-8�ַ�����ʧ�ܷ���NULL������ֵʹ��NetcaPKICryptoFreeMemory�ͷ�
 */
char* NETCADLLAPI NetcaAddressBookGetPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype,int index);

 /*
 *		NetcaAddressBookGetPersonCertCount
 *			��ȡ��ϵ��֤�������
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�����������֤������
 *		����ֵ��
 *			������ϵ��֤�������ʧ���򷵻�-1
 */
int NETCADLLAPI NetcaAddressBookGetPersonCertCount(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookGetPersonCert
 *			������������ȡ��ϵ��ĳ��֤��
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *		����ֵ��
 *			�ɹ�����֤������ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaAddressBookGetPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookAddPersonStringAttr
 *			��ϵ����Ϣ�У���attrtype���ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			value��������������Ե�ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, char* value);

/*
 *		NetcaAddressBookUpdatePersonStringAttr
 *			������ϵ�����Ե�ĳһָ����ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *			value��������������µ�ֵ
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index,char* value);

/*
 *		NetcaAddressBookAddPersonCert
 *			�����ϵ��֤��
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			hCert�������������ӵ�֤����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, NETCA_PKI_CERTIFICATE_HANDLE hCert);

/*
 *		NetcaAddressBookUpdatePersonCert
 *			������ϵ��ĳ������ָ����֤��
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *			hCert�������������ӵ�֤����
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index, NETCA_PKI_CERTIFICATE_HANDLE hCert);

/*
 *		NetcaAddressBookDeletePersonAttr
 *			ɾ����ϵ����Ϣ��ĳ�����Ե�����ָ����ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeletePersonAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookSetPersonAttrDefault
 *			������ϵ�����Ե�Ĭ��ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *			index��������������Ե�ĳһ��ֵ������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookSetPersonAttrDefault(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookGetDefaultPersonStringAttr
 *			��ȡ��ϵ��ĳһstring���Ե�Ĭ��ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *		����ֵ��
 *			�ɹ���������Ĭ��ֵ��ʧ�ܷ���NULL
 */
char* NETCADLLAPI NetcaAddressBookGetDefaultPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookGetDefaultPersonCert
 *			��ȡ��ϵ�˵�ĳһ֤�����Ե�Ĭ��ֵ
 *		������
 *			hPerson�������������ϵ�˾��
 *			attrtype�������������ϵ����Ϣ��������
 *		����ֵ��
 *			�ɹ�����֤�����Ե�Ĭ��֤�飬ʧ�ܷ���NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaAddressBookGetDefaultPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookAddPersons
 *			�Ѷ����ϵ����ӵ�һ������
 *		������
 *			hGroup�����������Ŀ������
 *			hPersons�������������ϵ������
 *			size�������������ϵ�˸���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddPersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookDeletePersonsByIndexs
 *			��ĳ���ж����ϵ��ɾ��
 *		������
 *			hGroup�����������Ŀ������
 *			indexs�������������Ҫɾ������ϵ�������е���ϵ������
 *			indexnum�����������indexs������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeletePersonsByIndexs(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int* indexs,int indexnum);

/*
 *		NetcaAddressBookAddGroups
 *		�Ѷ��������ӵ�һ������
 *		������
 *			hGroup�����������Ŀ������
 *			hGroups�������������������
 *			size�������������ӵ���ĸ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookAddGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookDeleteGroupsByIndexs
 *			��ĳ���ж������ɾ��
 *		������
 *			hGroup�����������Ŀ������
 *			indexs�������������Ҫɾ���������ڸ����е�������
 *			indexnum�����������indexs������
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeleteGroupsByIndexs(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int* indexs,int indexnum);

/*
 *		NetcaAddressBookCopyPersons
 *			�Ѷ����ϵ�˸��Ƶ���hGroup��
 *		������
 *			hGroup�������������������Ŀ����
 *			hPersons�������������ϵ�˾������
 *			size�����������hPersonsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookCopyPersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookCopyGroups
 *			�Ѷ�����鸴�Ƶ�����hGroup��
 *		������
 *			hGroup�������������������Ŀ����
 *			hGroups�������������������
 *			size�����������hGroupsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookCopyGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookMovePersons
 *			�Ѷ����ϵ�˼��е���hGroup��
 *		������
 *			hGroup�����������Ŀ�길��
 *			hPersons�������������ϵ�˾������
 *			size�����������hPersonsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookMovePersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookMoveGroups
 *			�Ѷ��������е�����hGroup��
 *		������
 *			hGroup�����������Ŀ�길��
 *			hGroups�������������������
 *			size�����������hGroupsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookMoveGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookDeletePersons
 *			ɾ�������ϵ��
 *		������
 *			hPersons�������������ϵ�˾������
 *			size�����������hPersonsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeletePersons(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookDeleteGroups
 *			ɾ�������
 *		������
 *			hGroups�������������������
 *			size�����������hGroupsԪ�ظ���
 *		����ֵ��
 *			�ɹ�����NETCA_PKI_SUCCESS��ʧ�ܷ�������ֵ
 */
int NETCADLLAPI NetcaAddressBookDeleteGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);


#ifdef __cplusplus
	}
#endif
#endif
