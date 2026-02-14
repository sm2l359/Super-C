#ifndef __KWPACK__
#include <super/stdbasic.h> /* looks unsafe, didn't like it. */
#define __KWPACK__

#line 6 "[kwpack.h]"

#include <stdint.h>
#include <super/sub/stdcrt.h>

/**
    Package Name: kwpack.h / kwpack,
    stands for "keyword-pack collection".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

#if COMPILER_ID == ID_GCC
#define _KWP_EXTENSION xsc_extension
#else
#define _KWP_EXTENSION
#endif

/* multiattribs, sharedattribs? forgot the original name was supposed to be. */
#define _kwp_auto_t __attribs(xsc_auto) /* .scdata, .SuperC/.Super, */
/* scdata is for data types and variables, SuperC is for functions only. */

#if XSCSET_OPTIMIZE > XSCOPT_OPTIMIZELEVELI
#define _KWP_PUBLIC xsc_hot xsc_visibility(default) xsc_section(".public")
#define _KWP_PRIVATE xsc_cold xsc_visibility(hidden) xsc_section(".private")
#else
#define _KWP_PUBLIC xsc_visibility(default) xsc_section(".public")
#define _KWP_PRIVATE xsc_visibility(hidden) xsc_section(".private")
#endif

#ifndef _STDBOOL_H
#define _STDBOOL_H
#define __bool_true_false_are_defined 1

#ifndef __cplusplus

typedef _Bool bool;

#define _Bool bool
#define TRUE ENABLED
#define FALSE DISABLED
#define true TRUE
#define false FALSE
#define on 1
#define off 0

#else /* #ifndef __cplusplus */

typedef bool _Bool;

#if __cplusplus < 201103L
 #define bool bool
 #define false false
 #define true true
#endif /* #if __cplusplus < 201103L */

#endif /* #ifndef __cplusplus */

#else /* fallback in case '_STDBOOL_H' is included, on/off have to be defined anyway. */
 #define on 1
 #define off 0
 #define TRUE on
 #define FALSE off
 #if !defined(XSC_LINUX) && !defined(XSC_MAC)
  #if XSCCONF_SUPRESS_WARNINGS <= DISABLED
   #warning It's not recommended to include 'stdbool.h' and 'kwpack.h' at the same time.
  #endif
 #else
  #undef bool
  typedef _Bool bool;
  #define _Bool bool
 #endif
#endif /* _STDBOOL_H */
#ifndef __cplusplus

 #if DISABLED
     #if COMPILER_ID == ID_UNKNOWN
      #if __STDC_VERSION__ >= 199901L
       typedef restrict __restrict__;
       typedef restrict __restrict;
      #else
       #define restrict
       #define __restrict__ restrict
       #define __restrict restrict
      #endif
     #elif __STDC_VERSION__ < 199901L
      #define restrict __restrict;
      #define __restrict__ __restrict
     #endif
 #else
     #if __STDC_VERSION__ >= 199901L
      #if COMPILER_ID == ID_UNKNOWN || COMPILER_ID == ID_MSVC
       #define __restrict__ restrict
       #define __restrict restrict
      #else
       typedef restrict __restrict__;
       typedef restrict __restrict;
      #endif
     #elif __STDC_VERSION__ < 199901L
      #if COMPILER_ID != ID_UNKNOWN
       #define restrict __restrict
       #define __restrict__ __restrict
      #else
       #define restrict
       #define __restrict restrict
       #define __restrict__ restrict
      #endif
     #endif
 #endif

#else /* __cplusplus */

 #if COMPILER_ID != ID_UNKNOWN || COMPILER_ID != ID_TINYC
   typedef __restrict restrict;
   #define __restrict__ restrict
 #else
  #define restrict
  #define __restrict__ restrict
  #define __rsetrict restrict
 #endif

#endif /* __cplusplus */

#ifndef XSC_KWP_MAINKEYWORDS
#define XSC_KWP_MAINKEYWORDS

#undef String
#undef ubyte
#undef sbyte

/* //extralong_t(long-long), hex_t, dword_t, byte_t(unsigned char). */
  #if XSCSET_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
    _KWP_EXTENSION typedef signed long long xlong;
    _KWP_EXTENSION typedef unsigned long long uxlong;
    _KWP_EXTENSION typedef signed int hex;
    _KWP_EXTENSION typedef unsigned int dword;
    _KWP_EXTENSION typedef unsigned long long qword;
    _KWP_EXTENSION typedef unsigned char ubyte;
    _KWP_EXTENSION typedef signed char sbyte;
  #elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELI
    _KWP_EXTENSION typedef int64_t xlong;
    _KWP_EXTENSION typedef uint64_t uxlong;
    _KWP_EXTENSION typedef int32_t hex;
    _KWP_EXTENSION typedef uint32_t dword;
    _KWP_EXTENSION typedef uint64_t qword;
    _KWP_EXTENSION typedef uint8_t ubyte;
    _KWP_EXTENSION typedef int8_t sbyte;
  #elif XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELII
    _KWP_EXTENSION typedef int_least64_t xlong;
    _KWP_EXTENSION typedef uint_least64_t uxlong;
    _KWP_EXTENSION typedef int_least32_t hex;
    _KWP_EXTENSION typedef uint_least64_t dword;
    _KWP_EXTENSION typedef uint_least64_t qword;
    _KWP_EXTENSION typedef uint_least8_t ubyte;
    _KWP_EXTENSION typedef int_least8_t sbyte;
  #endif

  #ifdef _MINWINDEF_
    _KWP_EXTENSION typedef unsigned long long QWORD;
  #endif

  _KWP_EXTENSION
  #ifndef __RPCNDR_H_VERSION__
    #if XSCSET_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
     typedef unsigned char byte; /* [RULE?] 1 space only with typedef keyword first? */
    #elif XSCSET_OPTIMIZE <= XSCOPT_OPTIMIZELEVELI
     typedef uint8_t byte;
    #else
     typedef uint_least8_t byte;
    #endif
  #else
    #undef byte
    #if XSCSET_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
     #define byte unsigned char
    #else
     #define byte uint8_t
    #endif
  #endif

  /**
  ///#ifndef byte
   /// #define byte ubyte // in case there's no byte data type. (also, not safe).
  ///#endif
  **/
/* //generics. */
#ifndef XSC_KWP_GEN
#define XSC_KWP_GEN
    #if defined(COMPILER_GCC) || COMPILER_ID == ID_MSVC || COMPILER_ID == ID_ICC
      _KWP_EXTENSION typedef void* voidptr;
      _KWP_EXTENSION typedef const void* voidptr_t;
      #               define var _kwp_auto_t
      _KWP_EXTENSION typedef void  empty_t; /* A.K.A. undefined_t. */
      _KWP_EXTENSION typedef void  Function;
    #else
      _KWP_EXTENSION typedef void* voidptr;
      _KWP_EXTENSION typedef const void* voidptr_t;
      _KWP_EXTENSION typedef void* var; /** The var {a.k.a, void*} type is not compatible with: float and double. **/
      _KWP_EXTENSION typedef void  empty_t;
      _KWP_EXTENSION typedef void  Function;
    #endif

#endif
/* //C++ features. */
#ifndef XSC_KWP_CPP
#define XSC_KWP_CPP /* in case you are more familiarized with C++ keywords. */
  #ifndef __cplusplus /* be careful, these does not serve the same purpose like in C++. */
    #if XSCSET_MODE == 2 /* //Use C Only Features. */
      #define public           extern xsc_section(".public")
      #define private          static xsc_section(".private")
      #define final            const xsc_section(".data")
    #else
      #define public           extern _KWP_PUBLIC
      #define private          static _KWP_PRIVATE
      #define final            const xsc_section(".rodata")
    #endif
    #define new(_VAR, _TAR)  (strcmp(tostr(_VAR), "char") == 0 ? printf("Parsing Error: cannot use 'char' as a valid name.") : (typeof(_VAR))calloc(_TAR *sizeof(_VAR)))
    #define delete(_TAR)     free(_TAR)
  #else /* also, the use of some of these keywords can make your code less portable. */

  #endif
#endif
/* //binaries. */
#ifndef _KWP_BINARIES_
#define _KWP_BINARIES_

   _KWP_EXTENSION typedef _Bool dbin[2];     //4      [0-3]
   _KWP_EXTENSION typedef _Bool qbin[4];    //16     [0-15]
   _KWP_EXTENSION typedef _Bool obin[8];   //256    [0-255]
   _KWP_EXTENSION typedef _Bool tbin[16]; //65536 [0-65535]

  #if XSCSET_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
   _KWP_EXTENSION typedef unsigned int bin;
  #elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELI
   _KWP_EXTENSION typedef uint32_t bin;
  #elif XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELII
   _KWP_EXTENSION typedef uint_least32_t bin;
  #endif
#endif
/* //strings. */
   _KWP_EXTENSION typedef char* String; /* string literal */
   _KWP_EXTENSION typedef char string[]; /* undefined string / automatic string */
  #if XSCSET_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
   _KWP_EXTENSION typedef char lostring  [sizeof(char) * 2048]; /* 2.048 */
   _KWP_EXTENSION typedef char mstring   [sizeof(char) * 4096]; /* 4.096 */
   _KWP_EXTENSION typedef char histring  [sizeof(char) * 8192]; /* 8.192 */
   _KWP_EXTENSION typedef char hihistring[sizeof(char) * 16384]; /* 16.384 */
  #elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELI
   _KWP_EXTENSION typedef char lostring  [sizeof(int8_t) * 1024]; /* 1.024 */
   _KWP_EXTENSION typedef char mstring   [sizeof(int8_t) * 2048]; /* 2.048 */
   _KWP_EXTENSION typedef char histring  [sizeof(int8_t) * 4096]; /* 4.096 */
   _KWP_EXTENSION typedef char hihistring[sizeof(int8_t) * 8192]; /* 8.192 */
  #elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELII
   _KWP_EXTENSION typedef char lostring  [sizeof(int_least8_t) * 1024]; /* 1.024 */
   _KWP_EXTENSION typedef char mstring   [sizeof(int_least8_t) * 2048]; /* 2.048 */
   _KWP_EXTENSION typedef char histring  [sizeof(int_least8_t) * 4096]; /* 4.096 */
   _KWP_EXTENSION typedef char hihistring[sizeof(int_least8_t) * 8192]; /* 8.192 */
  #elif XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELIII
   _KWP_EXTENSION typedef char lostring  [sizeof(int_least8_t) *  512]; /* 512 */
   _KWP_EXTENSION typedef char mstring   [sizeof(int_least8_t) * 1024]; /* 1.024 */
   _KWP_EXTENSION typedef char histring  [sizeof(int_least8_t) * 2048]; /* 2.048 */
   _KWP_EXTENSION typedef char hihistring[sizeof(int_least8_t) * 4096]; /* 4.096 */
  #endif

  /*
  //instruction: use _shared for more aggressive optimizations.
  //you can use _shared for the same purposes as shared, but
  //it's not recommended. again;
  //just because you can, doesn't mean you should.

  //instead, use shared if you think you're still going to use
  //the variable for other purposes, even if it's for not threading purposes.

  //there's also shared_t, but that one is defined on stdbasic.h
  //and the main difference is that shared is a modifier while
  //shared_t is a library built-in keyword used for actually redirecting
  //the data type in case threading is enabled.
  */

    #if XSCCONF_THREADING <= DISABLED
      #define shared xscs_shared xsc_hot
    #else
      #define shared xscs_shared xsc_cold
    #endif

    #ifndef _KWP_SIMPLIFIED_T_H
    #include <super/sub/stdcleanup.h>
    #include <super/simplified-t.h>
    #endif

#endif

#include <super/sub/stdcrt.h>

#undef _KWP_EXTENSION

#endif /* __KWPACK__ */
