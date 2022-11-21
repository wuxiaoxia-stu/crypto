#ifndef NETCA_BASICTYPE_INLCUDE_H
#define NETCA_BASICTYPE_INLCUDE_H

#include "NETCA_ErrorCode.h"

#ifdef __cplusplus
extern "C"
	{
#endif

#ifdef __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE
        #define IOS
        #define BUILD_AS_STATIC_LIBRARY
        #include <CoreFoundation/CoreFoundation.h>
    #endif
    #if TARGET_OS_OSX
        #define OSX
    #endif
#endif

#ifdef _WIN32
	#define NETCAAPI __stdcall
	#include <windows.h>
#else
	#define NETCAAPI
#endif

struct NETCA_ERR_CTX_st;
typedef struct NETCA_ERR_CTX_st *NETCA_ERR_CTX;

struct NETCA_STREAM_st;
typedef struct NETCA_STREAM_st *NETCA_STREAM;

typedef unsigned short NETCA_WCHAR;

struct NETCA_UString_st;
typedef struct NETCA_UString_st *NETCA_UString;

struct NETCA_Time_st;
typedef struct NETCA_Time_st *NETCA_Time;


#if defined(_WIN32) && !defined(__GNUC__)
	typedef __int64 integer64; 
	typedef unsigned __int64 uinteger64; 
	#define INT64MIN _I64_MIN 
	#define INT64MAX _I64_MAX 
	#define UINT64MAX _UI64_MAX 
#else
	typedef long long integer64; 
	typedef unsigned long long uinteger64;
	#define INT64MIN LLONG_MIN
	#define INT64MAX LLONG_MAX 
	#define UINT64MAX ULLONG_MAX 
#endif


struct NETCA_BigInteger_st;
typedef struct NETCA_BigInteger_st *NETCA_BigInteger;


struct NETCA_BitSet_st;
typedef struct NETCA_BitSet_st *NETCA_BitSet;

struct NETCA_Data_Blob_st{
	unsigned char *m_data;
	long m_datalen;
};
typedef struct NETCA_Data_Blob_st *NETCA_Data_Blob;


typedef void *(NETCAAPI * netca_arraylist_dupitem_func)(void *);
typedef void (NETCAAPI * netca_arraylist_freeitem_func)(void *);

struct NETCA_ARRAYLIST_st;
typedef struct NETCA_ARRAYLIST_st *NETCA_ArrayList;


#ifdef _WIN32
	typedef HMODULE NETCA_DSOHandle;
#else
	typedef void * NETCA_DSOHandle;	
#endif

typedef void *(NETCAAPI * netca_dso_func)(void);

struct NETCA_Lock_st;
typedef struct NETCA_Lock_st *NETCA_Lock;


struct NETCA_RWLock_st;
typedef struct NETCA_RWLock_st *NETCA_RWLock;


struct NETCA_Condition_st;
typedef struct NETCA_Condition_st *NETCA_Condition_Ptr;


#ifndef _HAS_NETCA_JSON_
#define _HAS_NETCA_JSON_
struct NETCA_JSON_st;
typedef struct NETCA_JSON_st *NETCA_JSON;


typedef int (NETCAAPI * netca_json_traverse_func)(void *,const unsigned char *name,int nameLen,NETCA_JSON value);

#endif

#if defined(_WIN32)
	typedef DWORD NETCA_TLSIndex;
#else
	#include <pthread.h>
	typedef pthread_key_t NETCA_TLSIndex;
#endif

#ifdef __cplusplus
	}	
#endif
#endif

