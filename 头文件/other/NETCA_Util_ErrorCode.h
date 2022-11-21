#ifndef NETCA_UTIL_ERRORCODE_INLCUDE_H
#define NETCA_UTIL_ERRORCODE_INLCUDE_H
#ifdef __cplusplus
extern "C"
	{
#endif
	
#define NETCA_UTIL_ERROR_WRITEREADONLYSTREAM	0x10100
#define NETCA_UTIL_ERROR_STREAMCANNOTGROW		0x10101
#define NETCA_UTIL_ERROR_BADSTREAM				0x10102
#define NETCA_UTIL_ERROR_READPASSEND			0x10103
#define NETCA_UTIL_ERROR_WRITESTRAMEFAIL		0x10104
#define NETCA_UTIL_ERROR_INVALIDPOS			0x10105
#define NETCA_UTIL_ERROR_READFILEFAIL			0x10106
#define NETCA_UTIL_ERROR_WRITEFILEFAIL			0x10107
#define NETCA_UTIL_ERROR_FILECLOSED			0x10108
#define NETCA_UTIL_ERROR_RESETFAIL				0x10109
#define NETCA_UTIL_ERROR_FILECLOSEFAIL			0x1010A
#define NETCA_UTIL_ERROR_BADFILEMODE			0x1010B
#define NETCA_UTIL_ERROR_OPENFILEFAIL			0x1010C
#define NETCA_UTIL_ERROR_NOSOURCESTREAM		0x1010D
#define NETCA_UTIL_ERROR_WRONGSTREAMLENGTH		0x1010E
#define NETCA_UTIL_ERROR_HEXDECODEFAIL			0x1010F
#define NETCA_UTIL_ERROR_BADBASE64FLAG			0x10110
#define NETCA_UTIL_ERROR_BASE64DECODEFAIL		0x10111
#define NETCA_UTIL_ERROR_FILEFLUSHFAIL			0x10112
#define NETCA_UTIL_ERROR_BADMDFUNCTION			0x10113
#define NETCA_UTIL_ERROR_GETSTREAMLENGTHERROR	0x10114
#define NETCA_UTIL_ERROR_UNSUPPORTCTRLCODE		0x10115
#define NETCA_UTIL_ERROR_PEMDECODEFAIL			0x10116
#define NETCA_UTIL_ERROR_MDUPDATEFAIL			0x10117
#define NETCA_UTIL_ERROR_MDFINISHFAIL			0x10118
#define NETCA_UTIL_ERROR_NOTFORREAD				0x10119
#define NETCA_UTIL_ERROR_NOTFORWRITE			0x1011A
#define NETCA_UTIL_ERROR_POSDIFFER				0x1011B

#ifdef __cplusplus
	}	
#endif
#endif
