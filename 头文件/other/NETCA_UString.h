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
 *			����һ��UNICODE�ַ���
 *		������
 *			wcs�����������UTF-16���������
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_new(const NETCA_WCHAR *wcs);
/*
 *		netca_ustring_newlength
 *			����һ��UNICODE�ַ���
 *		������
 *			wcs�����������UTF-16���������
 *			length�����������wcs�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newlength(const NETCA_WCHAR *wcs,long length);

/*
 *		netca_ustring_newutf8
 *			����UTF-8��������ݴ���һ��UNICODE�ַ���
 *		������
 *			utf8�����������UTF-8���������
 *			utf8len�����������utf8�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf8(const unsigned char *utf8,long utf8len);

/*
 *		netca_ustring_toutf8
 *			��ȡUNICODE�ַ�����UTF-8����
 *		������
 *			ustring��UNICODE�ַ���
 *			utf8��������������ص�UTF-8��������ݣ�Ҫʹ��NETCA_FREE���ͷ�
 *			utf8len��������������ص�utf8�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_toutf8(NETCA_UString ustring,unsigned char **utf8,long *utf8len);

/*
 *		netca_ustring_toutf16
 *			��ȡUNICODE�ַ�����UTF-16����
 *		������
 *			ustring��UNICODE�ַ���
 *			utf16��������������ص�UTF-16��������ݣ�Ҫʹ��NETCA_FREE���ͷ�
 *			utf16len��������������ص�utf16�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_toutf16(NETCA_UString ustring,NETCA_WCHAR **utf16,long *utf16len);

/*
 *		netca_ustring_newbmp
 *			����һ��UNICODE�ַ���
 *		������
 *			bmp�����������BMP���������
 *			bmplen�����������bmp�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newbmp(const unsigned char *bmp,long bmplen);
/*
 *		netca_ustring_tobmp
 *			��ȡUNICODE�ַ�����BMP����
 *		������
 *			ustring��UNICODE�ַ���
 *			bmp��������������ص�BMP��������ݣ�Ҫʹ��NETCA_FREE���ͷ�
 *			bmplen��������������ص�bmp�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_tobmp(NETCA_UString ustring,unsigned char **bmp,long *bmplen);

/*
 *		netca_ustring_newutf32be
 *			����UTF-32BE���봴��һ��UNICODE�ַ���
 *		������
 *			utf32be�����������UTF-32BE���������
 *			utf32belen�����������utf32be�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf32be(const unsigned char *utf32be,long utf32belen);

/*
 *		netca_ustring_toutf32be
 *			��ȡUNICODE�ַ�����UTF-32BE����
 *		������
 *			ustring��UNICODE�ַ���
 *			utf32be��������������ص�UTF-32BE��������ݣ�Ҫʹ��NETCA_FREE���ͷ�
 *			utf32belen��������������ص�utf32be�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_toutf32be(NETCA_UString ustring,unsigned char **utf32be,long *utf32belen);

/*
 *		netca_ustring_newutf32
 *			����UTF-32���봴��һ��UNICODE�ַ���
 *		������
 *			utf32�����������UTF-32����
 *			utf32len�����������utf32�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newutf32(const unsigned long *utf32,long utf32len);

/*
 *		netca_ustring_toutf32
 *			��ȡUNICODE�ַ�����UTF-32����
 *		������
 *			ustring��UNICODE�ַ���
 *			utf32��������������ص�UTF-32��������ݣ�Ҫʹ��NETCA_FREE���ͷ�
 *			utf32len��������������ص�utf32�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_toutf32(NETCA_UString ustring,unsigned long **utf32,long *utf32len);

/*
 *		netca_ustring_getcharcount
 *			��ȡUNICODE�ַ������ַ���
 *		������
 *			ustring��UNICODE�ַ���
 *		����ֵ��
 *			����UNICODE�ַ������ַ���
 */
long NETCAAPI netca_ustring_getcharcount(NETCA_UString ustring);

/*
 *		netca_ustring_dup
 *			����UNICODE�ַ���
 *		������
 *			ustring��UNICODE�ַ���
 *		����ֵ��
 *			�ɹ����ظ��ƺ��UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_dup(NETCA_UString ustring);

/*
 *		netca_ustring_free
 *			�ͷ�UNICODE�ַ���
 *		������
 *			ustring��UNICODE�ַ���
 *		����ֵ��
 *			��
 */
void NETCAAPI netca_ustring_free(NETCA_UString ustring);

/*
 *		netca_ustring_cmp
 *			�Ƚ�UNICODE�ַ���
 *		������
 *			lhs��UNICODE�ַ���1
 *			rhs��UNICODE�ַ���2
 *		����ֵ��
 *			��������ַ�����ȷ���0�����lhs>rhs����1�����lhs<rhs����-1��
 */
int NETCAAPI netca_ustring_cmp(NETCA_UString lhs,NETCA_UString rhs);

/*
 *		netca_ustring_ncmp
 *			�Ƚ�UNICODE�ַ�����ǰsize���ַ�
 *		������
 *			lhs��UNICODE�ַ���1
 *			rhs��UNICODE�ַ���2
 *			size������������ַ���
 *		����ֵ��
 *			ǰsize���ַ���������ַ�����ȷ���0�����lhs>rhs����1�����lhs<rhs����-1��
 */
int NETCAAPI netca_ustring_ncmp(NETCA_UString lhs,NETCA_UString rhs,long size);

/*
 *		netca_ustring_cat
 *			��������UNICODE�ַ���
 *		������
 *			ustring1��UNICODE�ַ���1
 *			ustring2��UNICODE�ַ���2
 *		����ֵ��
 *			�ɹ�����ustring1����ustring2��Ľ����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_cat(NETCA_UString ustring1,NETCA_UString ustring2);

/*
 *		netca_ustring_substring
 *			��ȡUNICODE�ַ��������ַ���
 *		������
 *			ustring��UNICODE�ַ���
 *			pos��������������ַ����Ŀ�ʼλ�ã���0����
 *			length��������������ַ�������
 *		����ֵ��
 *			�ɹ�����ustring�ĵ�posλ�ÿ�ʼ��length���ȵ����ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_substring(NETCA_UString ustring,long pos,long length);

/*
 *		netca_ustring_newascii
 *			����ASCII���봴��UNICODE�ַ���
 *		������
 *			ascii�����������ASCII���������
 *			length�����������ascii�ĳ���
 *		����ֵ��
 *			�ɹ�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newascii(const char *ascii,long length);

/*
 *		netca_ustring_ldapi18nstringprep
 *			LDAP�ַ������ʻ�����
 *		������
 *			type���������������
 *			ustring��LDAP�ַ���
 *		����ֵ��
 *			�ɹ�����LDAP�ַ������ʻ������UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_ldapi18nstringprep(long type,NETCA_UString ustring);

/*
 *		netca_ustring_getdefaultcharset
 *			��ȡ���ر��룬��NETCA_FREE�ͷ�
 *		������
 *			��
 *		����ֵ��
 *			�ɹ����ر��ر�������ʧ�ܷ���NULL
 */
char * NETCAAPI netca_ustring_getdefaultcharset(void);

/*
 *		netca_ustring_newmbs
 *			�����ַ���ת������ΪUNICODE�ַ���
 *		������
 *			charset������������ַ�������
 *			mbs������������ַ�����
 *			mbslen�����������mbs�ĳ���
 *		����ֵ��
 *			�ɹ�����ת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newmbs(const char *charset,const unsigned char *mbs,long mbslen);

/*
 *		netca_ustring_tombs
 *			�����ַ���ת��UNICODE�ַ���
 *		������
 *			ustring��UNICODE�ַ���
 *			charset������������ַ�������
 *			mbs��������������ص�ת��������ݣ���NETCA_FREE�ͷ�
 *			mbslen�����������mbs�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_tombs(NETCA_UString ustring,const char *charset,unsigned char **mbs,long *mbslen);

/*
 *		netca_ustring_find
 *			��UNICODE�ַ����������Ӵ�
 *		������
 *			ustring��UNICODE�ַ���
 *			startpos�������������ʼ����λ�ã���0����
 *			usubstring��Ҫ������UNICODE���ַ���
 *			pos������������ɹ��������ַ�����λ��
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_find(NETCA_UString ustring,long startpos,NETCA_UString usubstring,long *pos);

/*
 *		netca_ustring_normalize
 *			UNICODE�ַ����淶��
 *		������
 *			ustring��UNICODE�ַ���
 *			type������������淶������
 *		����ֵ��
 *			�ɹ����ع淶�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_normalize(NETCA_UString ustring,int type);

/*
 *		netca_ustring_tocasefold
 *			UNICODE�ַ�����casefoldת��
 *		������
 *			ustring��UNICODE�ַ���
 *			type�����������casefoldת������
 *		����ֵ��
 *			�ɹ�����casefoldдת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_tocasefold(NETCA_UString ustring,int type);

/*
 *		netca_ustring_idnlabel_toascii
 *			��IDN�ı�ǩת��ΪASCII
 *		������
 *			dnlabel��IDN�ı�ǩ
 *			allowunassigned��������������Ϊ��������ʹ��δ������ַ�����������
 *			usestd3asciirule��������������Ϊ����ʹ��STD3��ASCII���򣬷���ʹ��
 *			allowwildcardchar��������������Ϊ�������ʹ��ͨ��������򲻿���
 *			ascii���������������ASCII���룬��NETCA_FREE�ͷ�
 *			asciilen���������������ascii�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_idnlabel_toascii(NETCA_UString dnlabel,int allowunassigned,int usestd3asciirule,int allowwildcardchar,char **ascii,long *asciilen);
/*
 *		netca_ustring_idnlabel_toascii
 *			��IDN�ı�ǩת��ΪUNICODE
 *		������
 *			dnlabel��IDN�ı�ǩ
 *			allowunassigned��������������Ϊ��������ʹ��δ������ַ�����������
 *			usestd3asciirule��������������Ϊ����ʹ��STD3��ASCII���򣬷���ʹ��
 *			allowwildcardchar��������������Ϊ�������ʹ��ͨ��������򲻿���
 *		����ֵ��
 *			�ɹ�����ת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_idnlabel_tounicode(NETCA_UString dnlabel,int allowunassigned,int usestd3asciirule,int allowwildcardchar);

/*
 *		netca_ustring_idn_toascii
 *			��IDNת��ΪASCII
 *		������
 *			dn�����ʻ�����
 *			allowunassigned��������������Ϊ��������ʹ��δ������ַ�����������
 *			usestd3asciirule��������������Ϊ����ʹ��STD3��ASCII���򣬷���ʹ��
 *			allowwildcardchar��������������Ϊ�������ʹ��ͨ��������򲻿���
 *			ascii���������������ASCII���룬��NETCA_FREE�ͷ�
 *			asciilen���������������ascii�ĳ���
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_idn_toascii(NETCA_UString dn,int allowunassigned,int usestd3asciirule,int allowwildcardchar,char **ascii,long *asciilen);
/*
 *		netca_ustring_idnlabel_toascii
 *			��IDNת��ΪUNICODE
 *		������
 *			dn�����ʻ�����
 *			allowunassigned��������������Ϊ��������ʹ��δ������ַ�����������
 *			usestd3asciirule��������������Ϊ����ʹ��STD3��ASCII���򣬷���ʹ��
 *			allowwildcardchar��������������Ϊ�������ʹ��ͨ��������򲻿���
 *		����ֵ��
 *			�ɹ�����ת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_idn_tounicode(NETCA_UString dn,int allowunassigned,int usestd3asciirule,int allowwildcardchar);

#ifdef _WIN32
#include <windows.h>
#include <wtypes.h>

/*
 *		netca_ustring_tobstr
 *			��UNICODE�ַ���ת��ΪBSTR
 *		������
 *			ustring��UNICODE�ַ���
 *		����ֵ��
 *			�ɹ�����ת�����BSTR��ʧ�ܷ���NULL
 */
BSTR NETCAAPI netca_ustring_tobstr(NETCA_UString ustring);
/*
 *		netca_ustring_newbstr
 *			��BSTRת��ΪUNICODE�ַ���
 *		������
 *			bstr��BSTR�ַ���
 *		����ֵ��
 *			�ɹ�����ת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newbstr(BSTR bstr);
#endif

/*
 *		netca_ustring_tobstr
 *			��UNICODE�ַ���ת��Ϊ���ַ�������NETCA_FREE�ͷ�
 *		������
 *			ustring��UNICODE�ַ���
 *		����ֵ��
 *			�ɹ�����ת����Ŀ��ַ�����ʧ�ܷ���NULL
 */
wchar_t *NETCAAPI netca_ustring_towcs(NETCA_UString ustring);

/*
 *		netca_ustring_newwcs
 *			�ѿ��ַ���ת��ΪUNICODE�ַ���
 *		������
 *			wcs�����ַ���
 *		����ֵ��
 *			�ɹ�����ת�����UNICODE�ַ�����ʧ�ܷ���NULL
 */
NETCA_UString NETCAAPI netca_ustring_newwcs(const wchar_t *wcs);


typedef int (NETCAAPI *netca_mbstowcs_ptr)(void *context,const char *charset,const unsigned char *mbs,long mbslen,NETCA_WCHAR *wcs,long wcs_len,long *retlen);
typedef int (NETCAAPI *netca_wcstombs_ptr)(void *context,const char *charset,const NETCA_WCHAR *wcs,long wcslen,unsigned char *mbs,long mbslen,long *retlen);

/*
 *		netca_ustring_setmbstowcscallback
 *			���ö��ֽ�ת��Ϊ���ַ��Ļص�����
 *		������
 *			context���ص������Ĳ���
 *			callback���ص�����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_setmbstowcscallback(void *context,netca_mbstowcs_ptr callback);
/*
 *		netca_ustring_setwcstombscallback
 *			���ÿ��ַ�ת��Ϊ���ֽڵĻص�����
 *		������
 *			context���ص������Ĳ���
 *			callback���ص�����
 *		����ֵ��
 *			�ɹ�����NETCA_OK��ʧ�ܷ�������ֵ
 */
int NETCAAPI netca_ustring_setwcstombscallback(void *context,netca_wcstombs_ptr callback);

#ifdef __cplusplus
	}	
#endif

#endif

