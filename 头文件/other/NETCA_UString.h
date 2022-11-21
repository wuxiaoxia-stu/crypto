#ifndef NETCA_USTRING_INCLUDE_H
#define NETCA_USTRING_INCLUDE_H

#include "NETCA_BasicType.h"
#include <wchar.h>

#ifdef __cplusplus
extern "C"
	{
#endif

enum{
	NETCA_USTRING_UNICODE_NFD	=1,
	NETCA_USTRING_UNICODE_NFC	=2,
	NETCA_USTRING_UNICODE_NFKD	=3,
	NETCA_USTRING_UNICODE_NFKC	=4,
};


enum{
	NETCA_USTRING_UNICODE_CASEFOLDING_FULL	=1,
	NETCA_USTRING_UNICODE_CASEFOLDING_FULL_AND_FC_NFKC_CLOSURE	=2,
};

enum{
	NETCA_USTRING_LDAPSTRINGPREP_EXACTSTRING				=0x0,
	NETCA_USTRING_LDAPSTRINGPREP_EXACTSTRING_CASEIGNORE		=0x1,
	NETCA_USTRING_LDAPSTRINGPREP_NUMERICSTRING				=0x3,
	NETCA_USTRING_LDAPSTRINGPREP_TELNUMBER					=0x4,
	NETCA_USTRING_LDAPSTRINGPREP_TELNUMBER_CASEIGNORE		=0x5,
};

/*
 *		netca_ustring_new
 *			创建一个UNICODE字符串
 *		参数：
 *			wcs：输入参数，UTF-16编码的数据
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_new(const NETCA_WCHAR *wcs);
/*
 *		netca_ustring_newlength
 *			创建一个UNICODE字符串
 *		参数：
 *			wcs：输入参数，UTF-16编码的数据
 *			length：输入参数，wcs的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newlength(const NETCA_WCHAR *wcs,long length);

/*
 *		netca_ustring_newutf8
 *			根据UTF-8编码的数据创建一个UNICODE字符串
 *		参数：
 *			utf8：输入参数，UTF-8编码的数据
 *			utf8len：输入参数，utf8的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf8(const unsigned char *utf8,long utf8len);

/*
 *		netca_ustring_toutf8
 *			获取UNICODE字符串的UTF-8编码
 *		参数：
 *			ustring：UNICODE字符串
 *			utf8：输出参数，返回的UTF-8编码的数据，要使用NETCA_FREE来释放
 *			utf8len：输出参数，返回的utf8的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_toutf8(NETCA_UString ustring,unsigned char **utf8,long *utf8len);

/*
 *		netca_ustring_toutf16
 *			获取UNICODE字符串的UTF-16编码
 *		参数：
 *			ustring：UNICODE字符串
 *			utf16：输出参数，返回的UTF-16编码的数据，要使用NETCA_FREE来释放
 *			utf16len：输出参数，返回的utf16的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_toutf16(NETCA_UString ustring,NETCA_WCHAR **utf16,long *utf16len);

/*
 *		netca_ustring_newbmp
 *			创建一个UNICODE字符串
 *		参数：
 *			bmp：输入参数，BMP编码的数据
 *			bmplen：输入参数，bmp的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newbmp(const unsigned char *bmp,long bmplen);
/*
 *		netca_ustring_tobmp
 *			获取UNICODE字符串的BMP编码
 *		参数：
 *			ustring：UNICODE字符串
 *			bmp：输出参数，返回的BMP编码的数据，要使用NETCA_FREE来释放
 *			bmplen：输出参数，返回的bmp的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_tobmp(NETCA_UString ustring,unsigned char **bmp,long *bmplen);

/*
 *		netca_ustring_newutf32be
 *			根据UTF-32BE编码创建一个UNICODE字符串
 *		参数：
 *			utf32be：输入参数，UTF-32BE编码的数据
 *			utf32belen：输入参数，utf32be的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf32be(const unsigned char *utf32be,long utf32belen);

/*
 *		netca_ustring_toutf32be
 *			获取UNICODE字符串的UTF-32BE编码
 *		参数：
 *			ustring：UNICODE字符串
 *			utf32be：输出参数，返回的UTF-32BE编码的数据，要使用NETCA_FREE来释放
 *			utf32belen：输出参数，返回的utf32be的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_toutf32be(NETCA_UString ustring,unsigned char **utf32be,long *utf32belen);

/*
 *		netca_ustring_newutf32
 *			根据UTF-32编码创建一个UNICODE字符串
 *		参数：
 *			utf32：输入参数，UTF-32数据
 *			utf32len：输入参数，utf32的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf32(const unsigned long *utf32,long utf32len);

/*
 *		netca_ustring_toutf32
 *			获取UNICODE字符串的UTF-32编码
 *		参数：
 *			ustring：UNICODE字符串
 *			utf32：输出参数，返回的UTF-32编码的数据，要使用NETCA_FREE来释放
 *			utf32len：输出参数，返回的utf32的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_toutf32(NETCA_UString ustring,unsigned long **utf32,long *utf32len);

/*
 *		netca_ustring_getcharcount
 *			获取UNICODE字符串的字符数
 *		参数：
 *			ustring：UNICODE字符串
 *		返回值：
 *			返回UNICODE字符串的字符数
 */
long NETCAAPI netca_ustring_getcharcount(NETCA_UString ustring);

/*
 *		netca_ustring_dup
 *			复制UNICODE字符串
 *		参数：
 *			ustring：UNICODE字符串
 *		返回值：
 *			成功返回复制后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_dup(NETCA_UString ustring);

/*
 *		netca_ustring_free
 *			释放UNICODE字符串
 *		参数：
 *			ustring：UNICODE字符串
 *		返回值：
 *			无
 */
void NETCAAPI netca_ustring_free(NETCA_UString ustring);

/*
 *		netca_ustring_cmp
 *			比较UNICODE字符串
 *		参数：
 *			lhs：UNICODE字符串1
 *			rhs：UNICODE字符串2
 *		返回值：
 *			如果两个字符串相等返回0，如果lhs>rhs返回1，如果lhs<rhs返回-1。
 */
int NETCAAPI netca_ustring_cmp(NETCA_UString lhs,NETCA_UString rhs);

/*
 *		netca_ustring_ncmp
 *			比较UNICODE字符串的前size个字符
 *		参数：
 *			lhs：UNICODE字符串1
 *			rhs：UNICODE字符串2
 *			size：输入参数，字符数
 *		返回值：
 *			前size个字符如果两个字符串相等返回0，如果lhs>rhs返回1，如果lhs<rhs返回-1。
 */
int NETCAAPI netca_ustring_ncmp(NETCA_UString lhs,NETCA_UString rhs,long size);

/*
 *		netca_ustring_cat
 *			连接两个UNICODE字符串
 *		参数：
 *			ustring1：UNICODE字符串1
 *			ustring2：UNICODE字符串2
 *		返回值：
 *			成功返回ustring1连接ustring2后的结果，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_cat(NETCA_UString ustring1,NETCA_UString ustring2);

/*
 *		netca_ustring_substring
 *			获取UNICODE字符串的子字符串
 *		参数：
 *			ustring：UNICODE字符串
 *			pos：输入参数，子字符串的开始位置，从0算起
 *			length：输入参数，子字符串长度
 *		返回值：
 *			成功返回ustring的第pos位置开始的length长度的子字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_substring(NETCA_UString ustring,long pos,long length);

/*
 *		netca_ustring_newascii
 *			根据ASCII编码创建UNICODE字符串
 *		参数：
 *			ascii：输入参数，ASCII编码的数据
 *			length：输入参数，ascii的长度
 *		返回值：
 *			成功返回UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newascii(const char *ascii,long length);

/*
 *		netca_ustring_ldapi18nstringprep
 *			LDAP字符串国际化编码
 *		参数：
 *			type：输入参数，类型
 *			ustring：LDAP字符串
 *		返回值：
 *			成功返回LDAP字符串国际化编码的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_ldapi18nstringprep(long type,NETCA_UString ustring);

/*
 *		netca_ustring_getdefaultcharset
 *			获取本地编码，用NETCA_FREE释放
 *		参数：
 *			无
 *		返回值：
 *			成功返回本地编码名，失败返回NULL
 */
char * NETCAAPI netca_ustring_getdefaultcharset(void);

/*
 *		netca_ustring_newmbs
 *			根据字符集转换数据为UNICODE字符串
 *		参数：
 *			charset：输入参数，字符集名称
 *			mbs：输入参数，字符编码
 *			mbslen：输入参数，mbs的长度
 *		返回值：
 *			成功返回转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newmbs(const char *charset,const unsigned char *mbs,long mbslen);

/*
 *		netca_ustring_tombs
 *			根据字符集转换UNICODE字符串
 *		参数：
 *			ustring：UNICODE字符串
 *			charset：输入参数，字符集名称
 *			mbs：输出参数，返回的转换后的数据，用NETCA_FREE释放
 *			mbslen：输出参数，mbs的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_tombs(NETCA_UString ustring,const char *charset,unsigned char **mbs,long *mbslen);

/*
 *		netca_ustring_find
 *			在UNICODE字符串中搜索子串
 *		参数：
 *			ustring：UNICODE字符串
 *			startpos：输入参数，开始搜索位置，从0算起
 *			usubstring：要搜索的UNICODE子字符串
 *			pos：输出参数，成功返回子字符串的位置
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_find(NETCA_UString ustring,long startpos,NETCA_UString usubstring,long *pos);

/*
 *		netca_ustring_normalize
 *			UNICODE字符串规范化
 *		参数：
 *			ustring：UNICODE字符串
 *			type：输入参数，规范化类型
 *		返回值：
 *			成功返回规范化后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_normalize(NETCA_UString ustring,int type);

/*
 *		netca_ustring_tocasefold
 *			UNICODE字符串的casefold转换
 *		参数：
 *			ustring：UNICODE字符串
 *			type：输入参数，casefold转换类型
 *		返回值：
 *			成功返回casefold写转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_tocasefold(NETCA_UString ustring,int type);

/*
 *		netca_ustring_idnlabel_toascii
 *			把IDN的标签转换为ASCII
 *		参数：
 *			dnlabel：IDN的标签
 *			allowunassigned：输入参数，如果为真则允许使用未分配的字符，否则不允许
 *			usestd3asciirule：输入参数，如果为真则使用STD3的ASCII规则，否则不使用
 *			allowwildcardchar：输入参数，如果为真则可以使用通配符，否则不可以
 *			ascii：输出参数，返回ASCII编码，用NETCA_FREE释放
 *			asciilen：输出参数，返回ascii的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_idnlabel_toascii(NETCA_UString dnlabel,int allowunassigned,int usestd3asciirule,int allowwildcardchar,char **ascii,long *asciilen);
/*
 *		netca_ustring_idnlabel_toascii
 *			把IDN的标签转换为UNICODE
 *		参数：
 *			dnlabel：IDN的标签
 *			allowunassigned：输入参数，如果为真则允许使用未分配的字符，否则不允许
 *			usestd3asciirule：输入参数，如果为真则使用STD3的ASCII规则，否则不使用
 *			allowwildcardchar：输入参数，如果为真则可以使用通配符，否则不可以
 *		返回值：
 *			成功返回转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_idnlabel_tounicode(NETCA_UString dnlabel,int allowunassigned,int usestd3asciirule,int allowwildcardchar);

/*
 *		netca_ustring_idn_toascii
 *			把IDN转换为ASCII
 *		参数：
 *			dn：国际化域名
 *			allowunassigned：输入参数，如果为真则允许使用未分配的字符，否则不允许
 *			usestd3asciirule：输入参数，如果为真则使用STD3的ASCII规则，否则不使用
 *			allowwildcardchar：输入参数，如果为真则可以使用通配符，否则不可以
 *			ascii：输出参数，返回ASCII编码，用NETCA_FREE释放
 *			asciilen：输出参数，返回ascii的长度
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_idn_toascii(NETCA_UString dn,int allowunassigned,int usestd3asciirule,int allowwildcardchar,char **ascii,long *asciilen);
/*
 *		netca_ustring_idnlabel_toascii
 *			把IDN转换为UNICODE
 *		参数：
 *			dn：国际化域名
 *			allowunassigned：输入参数，如果为真则允许使用未分配的字符，否则不允许
 *			usestd3asciirule：输入参数，如果为真则使用STD3的ASCII规则，否则不使用
 *			allowwildcardchar：输入参数，如果为真则可以使用通配符，否则不可以
 *		返回值：
 *			成功返回转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_idn_tounicode(NETCA_UString dn,int allowunassigned,int usestd3asciirule,int allowwildcardchar);

#ifdef _WIN32
#include <windows.h>
#include <wtypes.h>

/*
 *		netca_ustring_tobstr
 *			把UNICODE字符串转换为BSTR
 *		参数：
 *			ustring：UNICODE字符串
 *		返回值：
 *			成功返回转换后的BSTR，失败返回NULL
 */
BSTR NETCAAPI netca_ustring_tobstr(NETCA_UString ustring);
/*
 *		netca_ustring_newbstr
 *			把BSTR转换为UNICODE字符串
 *		参数：
 *			bstr：BSTR字符串
 *		返回值：
 *			成功返回转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newbstr(BSTR bstr);
#endif

/*
 *		netca_ustring_tobstr
 *			把UNICODE字符串转换为宽字符串，用NETCA_FREE释放
 *		参数：
 *			ustring：UNICODE字符串
 *		返回值：
 *			成功返回转换后的宽字符串，失败返回NULL
 */
wchar_t *NETCAAPI netca_ustring_towcs(NETCA_UString ustring);

/*
 *		netca_ustring_newwcs
 *			把宽字符串转换为UNICODE字符串
 *		参数：
 *			wcs：宽字符串
 *		返回值：
 *			成功返回转换后的UNICODE字符串，失败返回NULL
 */
NETCA_UString NETCAAPI netca_ustring_newwcs(const wchar_t *wcs);


typedef int (NETCAAPI *netca_mbstowcs_ptr)(void *context,const char *charset,const unsigned char *mbs,long mbslen,NETCA_WCHAR *wcs,long wcs_len,long *retlen);
typedef int (NETCAAPI *netca_wcstombs_ptr)(void *context,const char *charset,const NETCA_WCHAR *wcs,long wcslen,unsigned char *mbs,long mbslen,long *retlen);

/*
 *		netca_ustring_setmbstowcscallback
 *			设置多字节转换为宽字符的回调函数
 *		参数：
 *			context：回调函数的参数
 *			callback：回调函数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_setmbstowcscallback(void *context,netca_mbstowcs_ptr callback);
/*
 *		netca_ustring_setwcstombscallback
 *			设置宽字符转换为多字节的回调函数
 *		参数：
 *			context：回调函数的参数
 *			callback：回调函数
 *		返回值：
 *			成功返回NETCA_OK，失败返回其他值
 */
int NETCAAPI netca_ustring_setwcstombscallback(void *context,netca_wcstombs_ptr callback);

#ifdef __cplusplus
	}	
#endif

#endif

