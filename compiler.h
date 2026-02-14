#ifndef XCM_COMPILER_INFO

#line 4 "[compiler.h]"

/* list of compiler preprocessor definitions [Do Not Forget]: */

/*
    - COMPILER_NAME
    - COMPILER_USED
    - COMPILER_SID
    - COMPILER_VERSION
    - COMPILER_HAS_MINGW
    - COMPILER_HAS_TYPEOF
    - COMPILER_HAS_CONSTRUCTOR
    - COMPILER_(TOKEN)
    - COMPILER_ID
*/

/*
    Preprocessor Definition Rules Examples:
        #define HAS_TYPEOF (TRINARY ALTERNATIVE)
            0 - NO
            1 - YES
            2 - UNKNOWN
        #define HAS_CONSTRUCTOR (TRINARY ALTERNATIVE)
            0 - NO
            1 - YES (ATTRIBUTE BASED)
            2 - YES (PRAGMA BASED)
        #define COMPILER_ID
            0 - UNKNOWN
            1-[inf] - (COMPILER NAME)
        these are the patterns that are going to repeat
        when dealing with preprocessor keywords in here.


*/

#ifndef COMPILER_ESSENTIALS
#define COMPILER_ESSENTIALS

    #ifdef __MINGW32__
        #define COMPILER_HAS_MINGW 1
    #else
        #define COMPILER_HAS_MINGW 0
    #endif

    #ifdef __GLIBC__
        #define COMPILER_USING_GLIBC 1
    #else
        #define COMPILER_USING_GLIBC 0
    #endif /* USING_GLIBC */

    #define _STRGFY0(x) #x
    #define _strFY(x) _STRGFY0(x) /* define stringfication. [stringfy] */

    #if defined(__clang__)
        #define COMPILER_USED "__clang__"
        #define COMPILER_NAME "clang"
        #define COMPILER_SID "CLANG"
        #define COMPILER_CLANG
        #define COMPILER_HAS_TYPEOF 1
        #define COMPILER_HAS_CONSTRUCTOR 1
        #define COMPILER_VERSION \
        _strFY(__clang_major__) ## "." ## _strFY(__clang_minor__) ## "." ## _strFY(__clang_patchlevel__)
        #define COMPILER_ID 2
    #elif defined(__GNUC__) || defined(__GNUG__)
        #define COMPILER_USED "__GNUC__"
        #define COMPILER_NAME "GNU-C Compiler"
        #define COMPILER_SID "GCC"
        #define COMPILER_GCC
        #define COMPILER_HAS_TYPEOF 1
        #define COMPILER_HAS_CONSTRUCTOR 1
        #define COMPILER_VERSION _strFY(__GNUC__) "." _strFY(__GNUC_MINOR__) "." _strFY(__GNUC_PATCHLEVEL__)
        #define COMPILER_ID 1
    #elif defined(_MSC_VER)
        #define COMPILER_USED "_MSC_VER"
        #define COMPILER_NAME "Microsoft Visual C/C++"
        #define COMPILER_SID "MSVC"
        #define COMPILER_MSVC
        #define COMPILER_HAS_TYPEOF 0
        #define COMPILER_HAS_CONSTRUCTOR 2 /* not a convetional one... */
        #define COMPILER_VERSION _strFY(_MSC_VER)
        #define COMPILER_ID 3
    #elif defined(__IBMC__)
        #define COMPILER_USED "__IBMC__"
        #define COMPILER_NAME "IBM-C Compiler"
        #define COMPILER_SID "IBMC"
        #define COMPILER_IBMC
        #define COMPILER_HAS_TYPEOF 0
        #define COMPILER_HAS_CONSTRUCTOR 1
        #define COMPILER_VERSION _strFY(_IBMC__)
        #define COMPILER_ID 4
    #elif defined(__OPEN64__)
        #define COMPILER_USED "__OPEN64__"
        #define COMPILER_NAME "Open64"
        #define COMPILER_SID "OPEN64" /* SID = StringID/SimplifiedID. */
        #define COMPILER_OPEN64
        #define COMPILER_HAS_TYPEOF 0
        #define COMPILER_HAS_CONSTRUCTOR 2 /* 1 = builtin based, 2 = #pragma based */
        #define COMPILER_VERSION "[Unavailable]"
        #define COMPILER_ID 5
    #elif defined(__INTEL_COMPILER) || defined(__ICC) || defined(__INTEL_CXX_COMPILER)
        #define COMPILER_USED "__INTEL_COMPILER"
        #define COMPILER_NAME "Intel-C Compiler"
        #define COMPILER_SID "ICC"
        #define COMPILER_HAS_TYPEOF 0
        #define COMPILER_HAS_CONSTRUCTOR 1
        #define COMPILER_VERSION _strFY(__INTEL_COMPILER) /* divide by 100 to get proper results.*/
        #define COMPILER_ICC
        #define COMPILER_ID 6
    #elif defined(__TINYC__)
        #define COMPILER_USED "__TINYC__"
        #define COMPILER_NAME "Tiny-C"
        #define COMPILER_SID "TCC"
        #define COMPILER_HAS_TYPEOF 1
        #define COMPILER_HAS_CONSTRUCTOR 0
        #define COMPILER_VERSION _strFY(__TINYC__)
        #define COMPILER_TINYC
        #define COMPILER_ID 7
    #else
        #define COMPILER_USED "UNDEFINED"
        #define COMPILER_NAME "[Not-Found]"
        #define COMPILER_SID "UNKNOWN"
        #define COMPILER_HAS_TYPEOF 0
        #define COMPILER_HAS_CONSTRUCTOR 0
        #define COMPILER_VERSION "[Unknown Version]"
        #define COMPILER_UNKNOWN
        #define COMPILER_ID 0
    #endif

    #define ID_GCC 1
    #define ID_CLANG 2
    #define ID_MSVC 3
    #define ID_IBM 4
    #define ID_OPEN64 5
    #define ID_ICC 6
    #define ID_TINYC 7
    #define ID_UNKNOWN 0

    #define COMPILER_GCCCLANG (COMPILER_ID <= 2)

    #define HAS_ATTRIBUTE_CONSTRUCTOR 1
    #define HAS_PRAGMA_CONSTRUCTOR 2
    #define HAS_NO_CONSTRUCTOR 0

#else /* after stdbasic include it for the first time, it can include the functions in the second time inclusion. */

    #define XCM_COMPILER_INFO



xsc_forceinline
    char* getCompiler(unsigned char _Return) { return !_Return ? COMPILER_USED : printf("%s", COMPILER_USED); }


#endif /* COMPILER_ESSENTIALS */
#endif /* XCM_COMPILER_INFO */
