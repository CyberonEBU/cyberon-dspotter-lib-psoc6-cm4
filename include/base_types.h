/*
PLEASE READ THE CYBERON END USER LICENSE AGREEMENT ("LICENSE(Cyberon)") CAREFULLY BEFORE DOWNLOADING, INSTALLING, COPYING, OR USING THIS SOFTWARE AND ACCOMPANYING DOCUMENTATION.
BY DOWNLOADING, INSTALLING, COPYING OR USING THE SOFTWARE, YOU ARE AGREEING TO BE BOUND BY THE AGREEMENT.
IF YOU DO NOT AGREE TO ALL OF THE TERMS OF THE AGREEMENT, PROMPTLY RETURN AND DO NOT USE THE SOFTWARE.
*/

#ifndef	__BASE_TYPES_H
#define	__BASE_TYPES_H

//#define _CEVA_SIMULATE_
//#define _DIM_40_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)


#ifdef _CEVA_SIMULATE_
	typedef signed short CHAR;
	typedef unsigned short BYTE;
	typedef signed short INT8;
	typedef unsigned short UINT8;
	typedef signed short SHORT;
	typedef unsigned short WORD;
	typedef unsigned short USHORT;
	typedef signed long LONG;
	typedef unsigned int DWORD;
	typedef unsigned long ULONG;
	typedef signed int INT;
	typedef unsigned int UINT;
	typedef int BOOL;
	typedef void VOID;
	typedef unsigned short WCHAR;	/*typedef wchar_t WCHAR;*/
	typedef float FLOAT;
#else
	#include <windows.h>
	typedef signed char INT8;
	typedef unsigned char UINT8;
	typedef unsigned short USHORT;
	typedef unsigned int UINT;
	typedef unsigned long ULONG;
#endif

	
#if (_MSC_VER < 1400)
	typedef unsigned short WCHAR;
#endif

#else

#ifdef _CEVA_SIMULATE_
	typedef signed short CHAR;
	typedef unsigned short BYTE;
	typedef signed short INT8;
	typedef unsigned short UINT8;
#else
	typedef signed char CHAR;
	typedef unsigned char BYTE;
	typedef signed char INT8;
	typedef unsigned char UINT8;
#endif

	typedef signed short SHORT;
	typedef unsigned short WORD;
	typedef unsigned short USHORT;
	typedef signed long LONG;
	typedef unsigned int DWORD;
	typedef unsigned long ULONG;
	typedef signed int INT;
	typedef unsigned int UINT;
	typedef int BOOL;
	typedef void VOID;
	typedef unsigned short WCHAR;	/*typedef wchar_t WCHAR;*/
	typedef float FLOAT;

#endif

#ifdef UNICODE
#undef UNICODE
#endif

#define UNICODE WCHAR

#ifdef LPVOID
#undef LPVOID
#endif
#define LPVOID	void*

#ifndef TRUE
#define TRUE	(1 == 1)
#endif

#ifndef FALSE
#define FALSE	(1 == 0)
#endif

#ifndef HANDLE
#define HANDLE	VOID*
#endif

#ifndef NULL
#define NULL	((VOID*)0)
#endif

#define PNULL	((VOID*)0)

#ifndef STATIC
#define STATIC 	static
#endif

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#if defined(_WIN32)
	#define EXPAPI WINAPI
#else
	#define EXPAPI
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(a)	if ( (a) != NULL ) {delete (a); (a) = NULL;}
#endif

#ifndef SAFE_FREE
#define SAFE_FREE(a)	if ( (a) != NULL ) {free(a); (a) = NULL;}
#endif

#if !defined(_WIN32)
//#include "SubName.h"
//#include "License_SubName.h"
#endif

//#include "DMemory.h"

#ifndef INLINE
#if defined ( _WIN32 )
	#define INLINE		__inline		// inline keyword for WIN32 Compiler
#elif defined ( __CC_ARM )
	#define INLINE		__inline		// inline keyword for ARM Compiler
#elif defined ( __ICCARM__ )
	#define INLINE		inline			// inline keyword for IAR Compiler. Only available in High optimization mode!
#elif defined ( __GNUC__ )
	#define INLINE		inline			// inline keyword for GNU Compiler
#else
	#define INLINE		inline
#endif
#endif	// INLINE

#endif	/* __BASE_TYPES_H */
