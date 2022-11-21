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
 *			打开文件名为filename的地址簿，如果文件不存在，则先创建
 *		参数：
 *			filename：输入参数，文件名，UTF-8编码
 *		返回值：
 *			成功返回地址簿句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_HANDLE NETCADLLAPI NetcaAddressBookOpen(const char * filename);

/*
 *		NetcaAddressBookClose
 *			关闭地址簿
 *		参数：
 *			hAddressBook：输入参数，地址簿句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookClose(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook);

/*
 *		NetcaAddressBookOpenStore
 *			打开作为联系人证书库的地址簿，如果不存在，则先创建
 *		参数：
 *			type：输入参数，证书库类型
 *		返回值：
 *			成功返回地址簿句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_HANDLE NETCADLLAPI NetcaAddressBookOpenStore(int type);

/*
 *		NetcaAddressBookCreateGroup
 *			创建一个组
 *		参数：
 *			hAddressBook：输入参数，地址簿句柄
 *			name：输入参数，组名，UTF-8编码
 *			description：输入参数，组的描述，UTF-8编码
 *		返回值：
 *			成功返回新创建的组句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookCreateGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook ,const char *name,const char *description);

/*
 *		NetcaAddressBookDupGroup
 *			复制一个组
 *		参数：
 *			hGroup：输入参数，原组句柄
 *		返回值：
 *			成功返回复制的组句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookDupGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookDeleteGroup
 *			删除一个组
 *		参数：
 *			hGroup：输入参数，原组句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeleteGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookFreeGroup
 *			释放组句柄
 *		参数：
 *			hGroup：输入参数，原组句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookFreeGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookAddChildGroup
 *			添加某个子组到父组中
 *		参数：
 *			hFartherGroup：输入参数，父组句柄
 *			hChildGroup：输入参数，子组句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddChildGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hFartherGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hChildGroup);

/*
 *		NetcaAddressBookGetBaseGroupCount
 *			获取地址簿中基本组的数量
 *		参数：
 *			hAddressBook：输入参数，地址簿。
 *		返回值：
 *			成功返回地址簿中基本组的数量，即没有父组的组，失败返回-1
 */
int NETCADLLAPI NetcaAddressBookGetBaseGroupCount(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook);

/*
 *		NetcaAddressBookGetBaseGroup
 *			获取地址簿中第index个基本组
 *		参数：
 *			hAddressBook：输入参数，地址簿。
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回地址簿中第index个基本组，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetBaseGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook,int index);

/*
 *		NetcaAddressBookGetMemberGroupCount
 *			获取地址簿中组的成员组个数
 *		参数：
 *			hGroup：输入参数，组句柄
 *		返回值：
 *			成功返回地址簿中名称句柄指定的组的成员组个数，失败返回-1
 */
int NETCADLLAPI NetcaAddressBookGetMemberGroupCount(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetMemberGroup
 *			获取地址簿中地址簿中名称为指定组的第index个成员组
 *		参数：
 *			hGroup：输入参数，组句柄
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回地址簿中名称为指定组的第index个成员组，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetMemberGroup( NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,int index);

/*
 *		NetcaAddressBookGetGroupName
 *			获取组的名称
 *		参数：
 *			hGroup：输入参数，组句柄
 *		返回值：
 *			成功返回组的UTF-8格式的名称，UTF-8编码，失败返回NULL。返回的组名用NETCA_FREE来释放
 */
char* NETCADLLAPI NetcaAddressBookGetGroupName(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookUpdateGroupName
 *			更改组的名称
 *		参数：
 *			hGroup：输入参数，组句柄
 *			name：输入参数，组的名称，UTF-8编码
 *		返回值：
 *			成功返回组NETCA_PKI_SUCCESS，失败返回其它值
 */
int NETCADLLAPI NetcaAddressBookUpdateGroupName(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,const char* name);

/*
 *		NetcaAddressBookGetGroupDescription
 *			获取地址簿中组对应描述
 *		参数：
 *			hGroup：输入参数，组句柄
 *		返回值：
 *			成功返回地址簿中名称为name组的描述,UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaAddressBookGetGroupDescription(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookUpdateGroupDescription
 *			修改地址簿中组的描述
 *		参数：
 *			hGroup：输入参数，组句柄
 *			description：输入参数，组描述,UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookUpdateGroupDescription(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,const char *description);

/*
 *		NetcaAddressBookGetMemberCount
 *			获取地址簿中组的成员个数
 *		参数：
 *			hGroup：输入参数，组句柄
 *		返回值：
 *			成功返回地址簿中名称句柄指定的组的成员个数，失败返回-1
 */
 int NETCADLLAPI NetcaAddressBookGetMemberCount(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetMember
 *			获取地址簿中地址簿中指定组的第index个成员
 *		参数：
 *			hGroup：输入参数，组句柄
 *			index：输入参数，索引值，从0算起
 *		返回值：
 *			成功返回地址簿中指定组的第index个成员，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookGetMember(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup,int index);

/*
 *		NetcaAddressBookFindMember
 *			搜索指定的联系人
 *		参数：
 *			hGroup：输入参数，组句柄
 *			searchType：输入参数，搜索的类型
 *			value：输入参数，搜索的值,UTF-8编码
 *			pPersons：输出参数，返回的符合条件的一组联系人
 *			count：输出参数，返回的联系人个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookFindMember(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int searchType,const char* value,NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE **pPersons,int *count);

/*
 *		NetcaAddressBookFindGroup
 *			根据名称搜索组
 *		参数：
 *			hAddressBook：输入参数，地址簿句柄
 *			name：输入参数，组的名称，,UTF-8编码
 *			hGroups：输出参数，适合条件的组
 *			count：输出参数，返回的hGroups元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookFindGroup(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook ,const char* name, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE** hGroups,int *count);

/*
 *		NetcaAddressBookGetGroupFromMemberGroup
 *			根据子组获取其所属的父组的句柄
 *		参数：
 *			hGroup：输入参数，子组句柄
 *		返回值：
 *			成功返回组句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE  NETCADLLAPI NetcaAddressBookGetGroupFromMemberGroup(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup);

/*
 *		NetcaAddressBookGetGroupFromMember
 *			根据联系人获取其所属的父组的句柄
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *		返回值：
 *			成功返回组句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE NETCADLLAPI NetcaAddressBookGetGroupFromMember(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookCreatePerson
 *			创建一个联系人
 *		参数：
 *			name：输入参数，地址簿句柄
 *		返回值：
 *			成功返回联系人句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookCreatePerson(const char *name);

/*
 *		NetcaAddressBookDupMember
 *			复制一个联系人句柄
 *		参数：
 *			hPerson：输入参数，l联系人句柄
 *		返回值：
 *			成功返回复制的联系人句柄，失败返回NULL
 */
NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE NETCADLLAPI NetcaAddressBookDupMember(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookFreePerson
 *			释放联系人句柄
 *		参数：
 *			hPerson：输入参数，l联系人句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookFreePerson(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookAddPerson
 *			把联系人加入组中。成功把联系人加入到组中时，联系人句柄所指向的组改为当前的组。
 *		参数：
 *			hGroup：输入参数，组句柄
 *			hPerson：输入参数，联系人句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddPerson(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookDeletePerson
 *			从数据库中删掉联系人记录
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeletePerson(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

/*
 *		NetcaAddressBookGetPersonName
 *			获得联系人的名称
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *		返回值：
 *			成功返回联系人的名称,UTF-8编码，失败返回NULL
 */
char * NETCADLLAPI NetcaAddressBookGetPersonName(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson);

 /*
 *		NetcaAddressBookUpdatePersonName
 *			更新联系人的名称
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			name：输入参数，名称,UTF-8编码
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonName(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson,const char *name);

/*
 *		NetcaAddressBookFindPerson
 *			搜索指定的联系人
 *		参数：
 *			hAddressBook：输入参数，地址簿句柄
 *			searchType：输入参数，搜索的类型
 *			value：输入参数，搜索的值,UTF-8编码
 *			pPersons：输出参数，返回的符合条件的一组联系人
 *			count：输出参数，返回的联系人个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookFindPerson(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook, int searchType,const char* value,NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE **pPersons,int *count);
 
/*
 *		NetcaAddressBookGetAllCert
 *			获取地址簿中所有的证书
 *		参数：
 *			hAddressBook：输入参数，联系人句柄
 *			pCerts：输出参数，返回的证书
 *			count：输出参数，返回的证书个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
 int NETCADLLAPI NetcaAddressBookGetAllCert(NETCA_PKI_ADDRESSBOOK_HANDLE hAddressBook, NETCA_PKI_CERTIFICATE_HANDLE **pCerts,int *count);

 /*
 *		NetcaAddressBookGetPersonStringAttrCount
 *			获取联系人某个字符类型属性的值的数量
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *		返回值：
 *			返回attrtype属性的值的个数，失败则返回-1
 */
int NETCADLLAPI NetcaAddressBookGetPersonStringAttrCount(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

 /*
 *		NetcaAddressBookGetPersonStringAttr
 *			根据索引，获取联系人某个字符类型属性的值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *		返回值：
 *			成功返回UTF-8字符串，失败返回NULL。返回值使用NetcaPKICryptoFreeMemory释放
 */
char* NETCADLLAPI NetcaAddressBookGetPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype,int index);

 /*
 *		NetcaAddressBookGetPersonCertCount
 *			获取联系人证书的数量
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，证书类型
 *		返回值：
 *			返回联系人证书个数，失败则返回-1
 */
int NETCADLLAPI NetcaAddressBookGetPersonCertCount(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookGetPersonCert
 *			根据索引，获取联系人某个证书
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *		返回值：
 *			成功返回证书句柄，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaAddressBookGetPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookAddPersonStringAttr
 *			联系人信息中，给attrtype添加值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			value：输入参数，属性的值
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, char* value);

/*
 *		NetcaAddressBookUpdatePersonStringAttr
 *			更改联系人属性的某一指定的值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *			value：输入参数，更新的值
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index,char* value);

/*
 *		NetcaAddressBookAddPersonCert
 *			添加联系人证书
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			hCert：输入参数，添加的证书句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, NETCA_PKI_CERTIFICATE_HANDLE hCert);

/*
 *		NetcaAddressBookUpdatePersonCert
 *			更新联系人某个索引指定的证书
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *			hCert：输入参数，添加的证书句柄
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookUpdatePersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index, NETCA_PKI_CERTIFICATE_HANDLE hCert);

/*
 *		NetcaAddressBookDeletePersonAttr
 *			删除联系人信息中某个属性的索引指定的值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeletePersonAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookSetPersonAttrDefault
 *			设置联系人属性的默认值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *			index：输入参数，属性的某一个值的索引
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookSetPersonAttrDefault(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype, int index);

/*
 *		NetcaAddressBookGetDefaultPersonStringAttr
 *			获取联系人某一string属性的默认值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *		返回值：
 *			成功返回属性默认值，失败返回NULL
 */
char* NETCADLLAPI NetcaAddressBookGetDefaultPersonStringAttr(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookGetDefaultPersonCert
 *			获取联系人的某一证书属性的默认值
 *		参数：
 *			hPerson：输入参数，联系人句柄
 *			attrtype：输入参数，联系人信息属性类型
 *		返回值：
 *			成功返回证书属性的默认证书，失败返回NULL
 */
NETCA_PKI_CERTIFICATE_HANDLE NETCADLLAPI NetcaAddressBookGetDefaultPersonCert(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE hPerson, int attrtype);

/*
 *		NetcaAddressBookAddPersons
 *			把多个联系人添加到一个组中
 *		参数：
 *			hGroup：输入参数，目标组句柄
 *			hPersons：输入参数，联系人数组
 *			size：输入参数，联系人个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddPersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookDeletePersonsByIndexs
 *			把某组中多个联系人删除
 *		参数：
 *			hGroup：输入参数，目标组句柄
 *			indexs：输入参数，需要删除的联系人在组中的联系人索引
 *			indexnum：输入参数，indexs的数量
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeletePersonsByIndexs(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int* indexs,int indexnum);

/*
 *		NetcaAddressBookAddGroups
 *		把多个子组添加到一个组中
 *		参数：
 *			hGroup：输入参数，目标组句柄
 *			hGroups：输入参数，组句柄数组
 *			size：输入参数，添加的组的个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookAddGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookDeleteGroupsByIndexs
 *			把某组中多个子组删除
 *		参数：
 *			hGroup：输入参数，目标组句柄
 *			indexs：输入参数，需要删除的子组在父组中的组索引
 *			indexnum：输入参数，indexs的数量
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeleteGroupsByIndexs(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, int* indexs,int indexnum);

/*
 *		NetcaAddressBookCopyPersons
 *			把多个联系人复制到组hGroup中
 *		参数：
 *			hGroup：输入参数，拷贝到的目标组
 *			hPersons：输入参数，联系人句柄数组
 *			size：输入参数，hPersons元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookCopyPersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookCopyGroups
 *			把多个子组复制到父组hGroup下
 *		参数：
 *			hGroup：输入参数，拷贝到的目标组
 *			hGroups：输入参数，组句柄数组
 *			size：输入参数，hGroups元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookCopyGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookMovePersons
 *			把多个联系人剪切到组hGroup中
 *		参数：
 *			hGroup：输入参数，目标父组
 *			hPersons：输入参数，联系人句柄数组
 *			size：输入参数，hPersons元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookMovePersons(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookMoveGroups
 *			把多个子组剪切到父组hGroup下
 *		参数：
 *			hGroup：输入参数，目标父组
 *			hGroups：输入参数，组句柄数组
 *			size：输入参数，hGroups元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookMoveGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE hGroup, NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);

/*
 *		NetcaAddressBookDeletePersons
 *			删除多个联系人
 *		参数：
 *			hPersons：输入参数，联系人句柄数组
 *			size：输入参数，hPersons元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeletePersons(NETCA_PKI_ADDRESSBOOK_PERSON_HANDLE* hPersons,int size);

/*
 *		NetcaAddressBookDeleteGroups
 *			删除多个组
 *		参数：
 *			hGroups：输入参数，组句柄数组
 *			size：输入参数，hGroups元素个数
 *		返回值：
 *			成功返回NETCA_PKI_SUCCESS，失败返回其他值
 */
int NETCADLLAPI NetcaAddressBookDeleteGroups(NETCA_PKI_ADDRESSBOOK_GROUP_HANDLE* hGroups,int size);


#ifdef __cplusplus
	}
#endif
#endif
