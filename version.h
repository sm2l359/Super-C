#ifndef __VERSION_INC_
#define __VERSION_INC_

/*
//Note: this is for checking the version, not determining the Language, this will be set on another library.
*/

#define __DETECT_CLANG_MODEL 1
#include <super/langpak.h>
#undef __DETECT_CLANG_MODEL

#if XSC_LANGUAGE == XSC_CLANGUAGE
#ifndef __STDC_VERSION__
#define __STDC_VERSION__ 198912L
#endif

#define LANG_VERSION __STDC_VERSION__

#define XSC_C_VERSION LANG_VERSION
#define _C_VERSION_DEF
#else

#ifdef __cplusplus
#define LANG_VERSION __cplusplus
#else
#error : unable to identify the language being used as either C or CPP.
#endif

#define XSC_CPP_VERSION LANG_VERSION
#define _CPP_VERSION_DEF
#endif

/* CC = Extended C/C++ Version */

#if defined(__STDC_VERSION__)
#define C89 1989L
#define C95 1994L
#define C99 1999L
#define C11 2011L
#define C17 2017L
#define C23 2023L
#elif defined(__cplusplus)
#define C89 0L
#define C95 0L
#define C99 0L
#define C11 0L
#define C17 0L
#define C23 0L
#endif

#if defined(__STDC_VERSION__)
#define CC89 198912L
#define CC95 199409L
#define CC99 199901L
#define CC11 201112L
#define CC17 201710L
#define CC23 202311L
#elif defined(__cplusplus)
#define CC89 0L
#define CC95 0L
#define CC99 0L
#define CC11 0L
#define CC17 0L
#define CC23 0L
#endif

#ifdef __cplusplus
#define CPP98 1997L
#define CPP03 1997L
#define CPP11 2011L
#define CPP14 2014L
#define CPP17 2017L
#define CPP20 2020L
#define CPP23 2023L
#else
#define CPP98 0L
#define CPP03 0L
#define CPP11 0L
#define CPP14 0L
#define CPP17 0L
#define CPP20 0L
#define CPP23 0L
#endif

#ifdef __cplusplus
#define CCPP98 199711L
#define CCPP03 199711L
#define CCPP11 201103L
#define CCPP14 201402L
#define CCPP17 201703L
#define CCPP20 202002L
#define CCPP23 202302L
#else
#define CCPP98 0L
#define CCPP03 0L
#define CCPP11 0L
#define CCPP14 0L
#define CCPP17 0L
#define CCPP20 0L
#define CCPP23 0L
#endif

#if defined(_C_VERSION_DEF)
#undef _C_VERSION_DEF
#if LANG_VERSION == CC89
#define _C_VERSION_DEF 1989L
#elif LANG_VERSION == CC95
#define _C_VERSION_DEF 1994L
#elif LANG_VERSION == CC99
#define _C_VERSION_DEF 1999L
#elif LANG_VERSION == CC11
#define _C_VERSION_DEF 2011L
#elif LANG_VERSION == CC17
#define _C_VERSION_DEF 2017L
#elif LANG_VERSION == CC23
#define _C_VERSION_DEF 2023L
#endif
#elif defined(_CPP_VERSION_DEF)
#undef _CPP_VERSION_DEF
#if LANG_VERSION == CCPP98
#define _CPP_VERSION_DEF 1997L
#elif LANG_VERSION == CCPP03
#define _CPP_VERSION_DEF 1997L
#elif LANG_VERSION == CCPP11
#define _CPP_VERSION_DEF 2011L
#elif LANG_VERSION == CCPP14
#define _CPP_VERSION_DEF 2014L
#elif LANG_VERSION == CCPP17
#define _CPP_VERSION_DEF 2017L
#elif LANG_VERSION == CCPP20
#define _CPP_VERSION_DEF 2020L
#elif LANG_VERSION == CCPP23
#define _CPP_VERSION_DEF 2023L
#endif
#endif

#ifdef _C_VERSION_DEF
#define C_VERSION __STDC_VERSION__ /* 6 Digit date version */
#define VERSION _C_VERSION_DEF /* 4 Digit date version */
#else
#define CPP_VERSION __cplusplus
#define VERSION _CPP_VERSION_DEF
#endif

/* Example Usage:

    #if VERSION >= C99
        struct _struct1 = {0};
        #define strout(...) __VA_ARGS__ //macro vprintf(...);
    #elif VERSION == C89
        struct _struct2 = {NULL,NULL,NULL};
        #define strout(_str, _str2) _str, _str2
    #endif

    //Alt:
    #if C_VERSION > CC89
        #define _sysout(...) __VA_ARGS__
    #endif

    //IMPORTANT: If your goal is to provide language cross compatibility, it's
    //not recommended to use the '<' operator, since all standard are zeroed
    //when the language is incompatible.

*/

enum CLanguage {
    Lang = LANG_VERSION,
    LangVersion = (int)(LANG_VERSION / 100) - (int)(LANG_VERSION / 10000) * 100,
    YearVersion = (int)(LANG_VERSION * 0.01f), /* ex: 1999, 2011, 2017; etc... */
    LongVersion = LANG_VERSION /* ex: 199711L */
} Version= LangVersion;

#endif /* __VERSION_INC_ */
