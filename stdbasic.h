#ifndef __STD_BASIC__
#define __STDB_DEFINED

#line 5 "[stdbasic.h]"

/**
    Package Name: stdbasic.h / stdbasic,
    stands for "standard-basic".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

/* perform macro reset */
#undef __INLINE_COMMENT__
#undef DISABLED
#undef ENABLED
#undef OFF
#undef ON
#undef FALSE
#undef TRUE

#define __INLINE_COMMENT__ 0
#define DISABLED 0
#define ENABLED 1

#define OFF 0
#define ON 1

#define TRUE 1
#define FALSE 0

#if __INLINE_COMMENT__

///Development Notes:

    ///      Non C-Standard Keywords:
        //the C language itself offers
        //a very small catalog of functions
        //and keywords to work with, and
        //while this is a really fun
        //little challenge to go.
        //it doesn't make any less complicated
        //the fact that it comes to deal with
        //some serious limitations.
        //most related to compatibility
        //it's important to develop a library
        //that is extremely well optimized
        //both in size and speed,
        //that happens to be a
        //really challenging goal.
        //
        //and that's why in this situation it's relatively
        //important to work with the compiler to help with
        //chances of optimization and to deal with some
        //limitations of the standard C language model.
        //
        //attribute keywords like hot, cold, unused, and weak
        //can help a lot, specially if you know what you're doing.
        //
        //but it's important to notice that since these are
        //Compiler Exclusive obviously they're going to be
        //hell in other compilers.
        //so it's important to use them with precaution.
        //
        //__attribute__((...));
        //__builtin_expect;
        //__builtin_prefetch;
        //__fastcall;
        //__typeof__;
        //__extension__;
        //__auto_type;
        //__asm__.
        //
        //these are all keywords that can help with
        //higher level control & optimization in the library.


    ///      Preprocessor Directives:
        //for preprocessor functions
        //that are going to be inside actual functions, the capitalization
        //should be small.

        //ex: "__stdb_return();"

    ///      Balanced Optimizations:
        //most of the code should be as optimized as maximum as possible;
        //both in terms of size and speed,
        //which is a really challenging goal.

    ///      Typedefs:
        //while typedef can be really useful for defining new structure types and help
        //with differentiation with custom libraries, even with simplification, it should be
        //used carefully and properly specified of it's type/what type it is. do not go doing stuff like:

        //"typedef void customlib1"
        //"typedef int customlib2"
        //"typedef bool customlib3"

        //...Or similar.

        //instead, choose to do this instead:

        //"typedef void customlib_Void"
        //"typedef int customlib_Int"
        //"typedef bool customlib_Bool"
    ///The Complete Development Catalog Guide:
        ///      Codes/Symbols/Keywords:
        //[NIP/N]=NothingInParticular "a acronym abbreviation, that has no meaning at all; pseudo-acronym."
        //[REM/R]=RemoveLater "useless content for the user, cut in a later version."
        //[CUT/C]=CutLater "unuseful/private comments. cut in the official release."
        //[DGR/D]=Danger "a function is dangerous and should be avoided, ex: gets()"
        //[OPT/O]=OptimizeLater "a function, variable, or preprocessor condition list that is unoptimized."
        //[NCS]=NotCStandard "a feature that is not available in all C compilers."
        //[CVE]=CVersionExclusive "means that a certain feature does not work for all versions of C."
        //[INV]=INDEV "still in development, do not release."
        //[UNC]=UnderConstruction "this feature is empty and is still yet to be built."
        //[ONF]=OptimizationNotFocused "do not focus on optimize this header. it's going to deal with big stuff."
        //[ORG]=Original "indicates that the featured content is the original version of something."
        //[ALT/Alt:]=Alternative "Alternative name/names proposed by the developer."
        //[KILL]=KillFunction "marked as to destroy a certain function from the library later."
        //[TEST]=TestFeature "specifies a certain feature of the library as experimental."
        //[REDO]=Redo "redo an entire function from scratch, either for optimization purposes or for fixes."
        //[RULE]=Rule "Establishes a new rule as comment for the library writing & semantics."
        //[TODO/TDO]=TODO "something is unfinished and needs to completed later, do not forget."
        //usage: rare, usually the dev. only writes down 'TODO:' like all other developers.

        //[ANSI]=AnsiC-Standard "this is a feature that is exclusive to Ansi C."
        //usage: rare, usually there's no need to document a feature that is not Ansi-C since the original
        //C is deprecated for +50 years. some examples of AnsiC include: printf() and scanf() themselves.
        //[TEXT]=PreprocessorText "a replacement for standard comments, #if 0, used for C-89 compatibility."
        //usage: not really necessary, since there's a way more beautiful (and efficient way) of writing
        //comments that is envolving the C++ standard comment by a C-89 standard multi-line comment.
        //[NOTE]=Note "The name is too self explanatory."
        //Multiple tags can be stacked like this:
        //[ANSI][CVE][OPT]

        //these are all the current development codes for now, however more may be added in the near future.

#endif

#ifndef __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 1
#endif

#ifndef XSCSET_MODE
#define XSCSET_MODE 0
/*
    //0 = Standard Mode A.K.A, 'Balance-Mode' (Alignment for balanced speed and size). {SP=[++++-],SZ=[++++-]}
    //1 = Thin-Mode, (Alignment for smaller size but at a very small cost for speed). {SP=[+++--],SZ=[+++++]}
    //2 = Fast-Mode, (Alignment for better speed but at a very small cost for size). {SP=[+++++],SZ=[+++--]}
*/

#endif

#define XSCOPT_SPEED 2
#define XSCOPT_SIZE 1
#define XSCOPT_STD 0

#if defined(__SHARED_LOCAL_MODES) || !defined(__SHARED_LOCAL_MODES)
#ifndef XSCSET_SHARED_MODE
#define XSCSET_SHARED_MODE DISABLED /* if it's shared==[threading is off] (do not confuse this) */
#endif

#ifndef XSCSET_LOCAL_MODE
#define XSCSET_LOCAL_MODE ENABLED
#endif
#endif

/** PRE-DEFINED SETTINGS. **/
#if !defined(CONF_DEFINED) || defined(CONF_DEFINED)

#ifndef XSCCONF_STDBASIC
#define XSCCONF_STDBASIC ENABLED /* used only for debugging/demo purposes */
#endif

#ifndef XSCCONF_ANSI_ESCAPE /* //1 = Automatic Activation of ANSI-ESC | 0 = Disabled or Manual Activation. // */
#define XSCCONF_ANSI_ESCAPE ENABLED /* //alt: OPT_ENABLED */
#endif

#ifndef XSCCONF_USE_ANSI_ONLY
#define XSCCONF_USE_ANSI_ONLY DISABLED
#else
#if XSCCONF_USE_ANSI_ONLY >= ENABLED
#undef XSCCONF_ANSI_ESCAPE
#define XSCCONF_ANSI_ESCAPE DISABLED
#endif
#endif
#ifndef XSCCONF_STDCON_NOCLEANUP /* //Windows Exclusive Option Only. // 'stdcon.h' // */
#define XSCCONF_STDCON_NOCLEANUP DISABLED
#endif

#ifndef XSCCONF_INCLUDE_ALL /* // 'stdbasic.h' // */
#define XSCCONF_INCLUDE_ALL DISABLED
#endif

#ifndef XSCCONF_NORETURN /* //converts some types like char* and int to void type, and disables returning of the functions containing them. // */
#define XSCCONF_NORETURN DISABLED
#endif

#ifndef XSCCONF_STDCON_NO_RETURN_CPOS /* // 'stdcon.h' // */
#define XSCCONF_STDCON_NO_RETURN_CPOS DISABLED
#endif

#ifndef XSCCONF_DRAWS_BOUNDS /* // 'draws.h' // */
#define XSCCONF_DRAWS_BOUNDS ENABLED
#endif

#ifndef XSCCONF_ADVANCED_DRAWS /* // 'draws.h' // */
#define XSCCONF_ADVANCED_DRAWS DISABLED
#endif

#ifndef XSCCONF_EXCLUSIVE_HDR
#define XSCCONF_EXCLUSIVE_HDR ENABLED /* Stands For: "Exclusive Headers" */
	/*
	///Ex: [ENABLED] stdcon clear(void); | draws draw_TextBox(void); (XSCCONF_EXCLUSIVE_HDR=on)
	///Ex: [DISABLED] void clear(void);   | void draw_TextBox(void); (XSCCONF_EXCLUSIVE_HDR=off)
	*/
#endif

#if defined(XSCCONF_STDCON_AUTO_UPDATE) /* // 'stdcon.h' // */
#if XSCCONF_STDCON_AUTO_UPDATE >= ENABLED
#ifndef XSCCONF_STDCON_AUTO_UPDATE_CSBI /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_CSBI ENABLED
#endif

#ifndef XSCCONF_STDCON_AUTO_UPDATE_COLOR /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_COLOR ENABLED
#endif
#elif XSCCONF_STDCON_AUTO_UPDATE <= DISABLED
#ifndef XSCCONF_STDCON_AUTO_UPDATE_CSBI /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_CSBI DISABLED
#endif

#ifndef XSCCONF_STDCON_AUTO_UPDATE_COLOR /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_COLOR DISABLED
#endif
#endif
#else
#ifndef XSCCONF_STDCON_AUTO_UPDATE_CSBI /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_CSBI ENABLED
#endif

#ifndef XSCCONF_STDCON_AUTO_UPDATE_COLOR /* // 'stdcon.h' // */
#define XSCCONF_STDCON_AUTO_UPDATE_COLOR ENABLED
#endif
#endif

#ifndef XSCCONF_STDCON_AUTO_UPDATE /* // 'stdcon.h' //  */
#if XSCCONF_STDCON_AUTO_UPDATE_COLOR != XSCCONF_STDCON_AUTO_UPDATE_CSBI
#define XSCCONF_STDCON_AUTO_UPDATE DISABLED
#else
#define XSCCONF_STDCON_AUTO_UPDATE ENABLED
#endif
#endif

#ifndef XSCCONF_SUPRESS_WARNINGS
#define XSCCONF_SUPRESS_WARNINGS DISABLED
#endif

#ifndef XSCCONF_SHARED /* mandatory to be set 'true' if working with multiple threads, some optimization will be undone. */
#define XSCCONF_SHARED DISABLED /* if the option is not set 'true', then it may result in severe issues with threading. */
#endif

#ifndef XSCCONF_TYPEOF_MOD3 /* // 'typeof.h' // */
#define XSCCONF_TYPEOF_MOD3 DISABLED
#endif

#ifndef XSCCONF_STRINGS_STRCUT_MODIFY_ALL /* // 'strings.h' // */
#define XSCCONF_STRINGS_STRCUT_MODIFY_ALL ENABLED
#endif

#ifndef XSCCONF_STDCON_UPDATE_COORDS /* // 'stdcon.h' // */
#define XSCCONF_STDCON_UPDATE_COORDS ENABLED
#endif

#ifndef XSCCONF_SUPER_C_SPLASH_SCREEN /* // 'SuperC/->stdcon.h' // */
#define XSCCONF_SUPER_C_SPLASH_SCREEN ENABLED
#endif

#ifndef XSCCONF_ALT_SPELLINGS
#define XSCCONF_ALT_SPELLINGS ENABLED
#endif

#ifndef XSCCONF_FUNCTION_ALT_SPELLINGS
#define XSCCONF_FUNCTION_ALT_SPELLINGS (XSCCONF_ALT_SPELLINGS)
#endif

#ifndef XSCCONF_OPRPACK_ALT_SPELLINGS
#define XSCCONF_OPRPACK_ALT_SPELLINGS (XSCCONF_ALT_SPELLINGS)
#endif

#ifndef XSCCONF_OPRPACK_ORIGINAL_NOT
#define XSCCONF_OPRPACK_ORIGINAL_NOT DISABLED
#endif

#ifndef XSCCONF_CUSTOM_SECTIONS /* [ALT] XSCCONF_EXCLUSIVE_SECTIONS */
#define XSCCONF_CUSTOM_SECTIONS ENABLED
#endif

#ifndef XSCCONF_CUSTOM_ATTRIBUTES /* [ALT] XSCCONF_OPTIMIZATION_ATTRIBUTES */
#define XSCCONF_CUSTOM_ATTRIBUTES ENABLED
#endif

#ifndef XSCCONF_CUSTOM_SCMATH_ATTRIBUTES /* // 'scmath.h' // */
#define XSCCONF_CUSTOM_SCMATH_ATTRIBUTES (XSCCONF_CUSTOM_ATTRIBUTES)
#endif

#ifndef XSCCONF_CUSTOM_DRAWS_ATTRIBUTES /* // 'draws.h' //* */
#define XSCCONF_CUSTOM_DRAWS_ATTRIBUTES (XSCCONF_CUSTOM_ATTRIBUTES)
#endif

#ifndef XSCCONF_CUSTOM_SPP_ATTRIBUTES /* // 'string++' //* */
#define XSCCONF_CUSTOM_SPP_ATTRIBUTES (XSCCONF_CUSTOM_ATTRIBUTES)
#endif

#ifndef XSCCONF_READ_LICENSE
#define XSCCONF_READ_LICENSE DISABLED
#endif


#define CONF_DEFINED 1

#endif

/* Standard Library */

#if XSCCONF_INCLUDE_ALL <= 1 /* Include Essentials Only. */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#include <super/sub/stdint.h>
#include <ctype.h>
#include <stddef.h>
#include <locale.h>
#else /* Include The Entire C Library. */
#include <super/sub/stdc.h>
#endif

/* OS-Specific Library (that are not api/abi-related). */
#ifndef OSLIB_ESSENTIALS
#define OSLIB_ESSENTIALS

#if defined(_WIN32)

#include <windows.h>
#include <conio.h>

#define XSC_OSNAME "Windows"

#elif defined(__linux__)

#include <ncurses.h>
#include <termios.h>
#include <dlfcn.h>
#include <unistd.h>

#define XSC_OSNAME "Linux"

#elif defined(__apple__) || defined(__APPLE__)

#include <Carbon/Carbon.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <dlfcn.h>

#define XSC_OSNAME "Mac"

#elif defined(__FreeBSD__)

#define XSC_OSNAME "FreeBSD"

#elif defined(__OpenBSD__)

#define XSC_OSNAME "OpenBSD"

#elif defined(__NetBSD__)

#define XSC_OSNAME "NetBSD"

#elif defined(__DragonFly__)

#define XSC_OSNAME "DragonFly"

#elif defined(__IRIS__) || defined(__IRIS_OS)

#define XSC_OSNAME "IrisOS" /* always watching over your safety. */
/* always watching over your privacy. (RANDOMIZED MESSAGE AT STARTUP) */
#else

#define XSC_OSNAME "Other"

#endif

#ifdef __unix__
#include <unistd.h>
#endif

#endif



/* HEADERS */

/* SuperC-Specific */
#include <super/attribs.h>
#include <super/version.h>

/* SuperC-Specific */
#include <super/sub/stdbasic-getos.h>

/* stdbasic-Specific */
#include <super/sub/stdbasic-keys.h>

/*

    //XSC_LMODE is the Attribute that Determines
    //How The Library Will Behave on it's General Purposes,
    //And How Most of The Function Will Be Stored and Behave.

    //0) = Means That The Attributes Will Be Stored As Preprocessor
    //Keywords and Function will Act Like Normal C Function. (Mostly)

    //1) = Is The Object Oriented Mode, Meaning That Most Of The
    //Information Will Be Stored In Type-Structs (typedef Structs),
    //And Most Of The Function Will Have a Object Oriented Design,
    //Giving a Glimpse Of C++, Recreating Some Of It's Features Like
    //Polymorphism, Abstraction, Etc..., It's Like Using a Totally
    //Different Language (And Library).

    //2) = Full C Mode, Follow the C-XX standard model. that is, pure C.
    //no additions, no modifications, no C++ features recreated manually,
    //the library will behave like normal C. it will still use compiler
    //attributes for practical utilities and
    //optimizations unless that is disabled too.

*/

#if XSC_LMODE == 0 /* XSC-Default a fair mix of Mostly raw C, and some mixed features borrowed from C++. */

#elif XSC_LMODE == 1

/* inline comment is usually only used at the beginning of the file and for important notes but i'm going to use it here though. */
#if __INLINE_COMMENT__
//C+ Mode, it's an intermediary between C and Artificial C++ created using
//a combination of meta-programming, syntax manipulation, artificial object orientation, and compiler features.

//C+ mode, semi++ mode, semi-C++ mode, call it how you want, but be aware
//that this mode is still in it's planning stages. so it won't be seen
//too early (YET).
#endif

#elif XSC_LMODE == 2 /* C-Only Features */

#endif /* XSC_MODE */

#ifndef SUPER_C_ATTR
#define SUPER_C_ATTR
#define XSCINF_BUILD 2
#define XSCINF_VERSION 1.4
#define XSCINF_RELEASE TRUE
#define XSCINF_DATELOG D14M02Y26
#define XSCINF_DATE 14022026
#endif

#ifndef XSCSET_BUILD1
#define XSCSET_BUILD1 DISABLED /* boolean set. */
#define XSCOPT_FIRSTBUILDENABLED
#endif

#ifndef XSCSET_OPTIMIZE
#define XSCSET_OPTIMIZE 1
#endif

/* the bigger the value the more unsafer the optimization is. */

#define XSCOPT_0PTIMIZELEVEL 0
#define XSCOPT_OPTIMIZELEVELI 1
#define XSCOPT_OPTIMIZELEVELII 2
#define XSCOPT_OPTIMIZELEVELIII 3

#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)

#  if XSCSET_OPTIMIZE == XSCOPT_0PTIMIZELEVEL
#   pragma GCC optimize("01")
#  elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELI
#   pragma GCC optimize("01")
#  elif XSCSET_OPTIMIZE == XSCOPT_OPTIMIZELEVELII
#   pragma GCC optimize("02")
#  elif XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELIII
#   pragma GCC optimize("03")
#  endif

# endif

/* [RULE] keywords (spacing: 2) */
#if LANG_VERSION < CC99
#define inline
#else
/* #define inline */
#endif

/* C-89 Compatibility */
#if LANG_VERSION < CC99 /* [TDO] __FILE__, __LINE__, __func__ */
#define __func__ NULL
#define __time__ NULL

/* fix most compatibility issues here, specifically, by re-defining missing macros
	from C99 > C23
	other issues not macro related, being a function, system, etc, should also be fixed
	here.
*/
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#endif /* - EXIT_SUCCESS - */

#if XSCCONF_STDCON_NO_RETURN_CPOS >= ENABLED /* limits certain functions in stdcon.h from returning cursor position. */
#define __xsc_decideparam(...) __VA_ARGS__
#else
#define __xsc_decideparam(...)
#endif

#ifdef __KWPACK__
  /* undefine all if "kwpack.h" is defined, same as doing: "#include <super/sub/stdcrt.h>" */
#undef String
#undef string
#undef lostring
#undef histring
#undef hihistring
#undef ubyte
#undef sbyte
#else /* In Case kwpack is not defined, define some features manually. */
/* for future update note: */
/* fixed some consistency issues; */
typedef char _XSC_FALLBACK_STRG[32];
#define String char*
#define string char* /* don't know what to put here without damaging the syntax. */
#define mstring (EMIT_WARNING(WARN_5C001));_XSC_FALLBACK_STRG /* typedef char string[32]; //string is defined anyway as improvised string, as a way to prevent syntax flaws and typeof_c() errors. */
#define lostring (EMIT_WARNING(WARN_5C001));_XSC_FALLBACK_STRG  /* lostring is also defined due to syntax & typeof_c(). */
#define histring (EMIT_WARNING(WARN_5C001));_XSC_FALLBACK_STRG /* histring is ALSO ALSO defined due to typeof_c(). */
#define hihistring (EMIT_WARNING(WARN_5C001));_XSC_FALLBACK_STRG /* hihistring is.. you get the point. */
#define ubyte unsigned char
#define sbyte signed char
#define byte ubyte
#define uchar unsigned char
#define ushort unsigned short
#define uint unsigned int
#define ulong unsigned long
#define xlong long long
#define uxlong unsigned long long
#endif /* - KWPACK - */

/* alternative Spellings for the function names.. */
#ifndef _ALT_SPELLINGS
#if defined(__STDCON__) && !defined(XSC_STDC_ALT) && \
XSCCONF_FUNCTION_ALT_SPELLINGS >= ENABLED
#define XSC_STDC_ALT
#define StdconOSName() StdconOSName()
#define XClear() StdconOSName()
#define editCursor(_Visibility, _SIZE, ...) EditCursor(_Visibility, _SIZE)
#define StdconOSName stdconOSName
#define getCursorPosition GetCursorPosition
#define getConsoleStats GetConsoleStats
#define Color256(_256Color) ColorAE(_256Color)
#endif

#ifdef _XSC_ASCII_PAINT && !defined(_XSC_ASCII_ALT)
#define _XSC_ASCII_ALT
#define drawEllipse(_X, _Y, _W, _H, _Ch) freeCircle(_X, _Y, _W, _H, _Ch)
#endif
#endif

#ifndef _XSC_ESSENTIALS

    /* There are three ways to clear the Screen:
        -Ansi Escape; [More Portable and faster than Console, but harder to use, and some minor flaws]
        -Os Api; [Harder to Code & handle but faster]
        -Os Console Command; [Easier to use but Usually Way... Slower]
        -Built-in; [Highly customizable, fast, O(n)]
        //clear, AKA, "standard clear" which is the full name of the function,
        //will auto-select one to be the standard way of clearing the screen.

        //STD_CLEAR: windows=[builtin]
        //STD_CLEAR: linux=[Ansi Escape]
        //STD_CLEAR: mac=[Ansi Escape]
    */

#define _ANSI_CLEAR printf("\x1b[1J\x1b[H") /* console (ansi). */

#if XSCCONF_USE_ANSI_ONLY <= DISABLED

#if XSC_OS == OsID_WINDOWS
#define _API_CLEAR xclear() /* No pre-defined function in windows API. built-in. */
#define _XSC_CLEAR xclear() /* built-in. */
#define _SYS_CLEAR system("cls") /* console. (cls:windows) */
#elif XSC_OS == OsID_LINUX || XSC_OSNAME == OsID_MAC
#define _API_CLEAR clear() /* ncurses. (Linux/Mac) */
#define _XSC_CLEAR _ANSI_CLEAR /* Ansi. */
#define _SYS_CLEAR system("clear") /* console. (clear:linux/Mac) */
#elif defined(XSC_UNIX)
#define _API_CLEAR clear() /* ncurses. (Presumed) */
#define _XSC_CLEAR _ANSI_CLEAR
#define _SYS_CLEAR system("clear") /* (clear:Unix-Version) */
#else
#define _API_CLEAR _ANSI_CLEAR
#define _XSC_CLEAR _ANSI_CLEAR
#define _SYS_CLEAR _ANSI_CLEAR
#endif

#else
#define _XSC_CLEAR _ANSI_CLEAR
#define _SYS_CLEAR _ANSI_CLEAR
#define _API_CLEAR _ANSI_CLEAR
#endif

/* directive that puts the Cursor back on The Beginning. */
#define resetCursorAE() printf("\x1b[H")
#if XSCCONF_USE_ANSI_ONLY <= DISABLED
#define resetCursor() CursorPosition(0, 0)
#else
#define resetCursor() resetCursorAE()
#endif
/* directive that makes clear the console compatible with windows, linux, and mac. */

#ifdef __STDCON__
#define clear _XSC_CLEAR /* the standard, pre-selected method for clearing up the screen. */
#else
#ifdef XSC_WINDOWS
#undef _XSC_CLEAR
#define _XSC_CLEAR _SYS_CLEAR
#undef _ANSI_CLEAR
#define _ANSI_CLEAR _SYS_CLEAR
#undef _API_CLEAR
#define _API_CLEAR _SYS_CLEAR

#undef clear
#define clear _SYS_CLEAR
#else
#undef clear
#define clear _ANSI_CLEAR
#undef _API_CLEAR
#define _API_CLEAR _ANSI_CLEAR
#endif
#endif

#define sysclear _SYS_CLEAR
#define clearAE _ANSI_CLEAR
#define apiclear _API_CLEAR
#if XSCCONF_STDCON_AUTO_UPDATE_CSBI >= ENABLED && defined(__STDCON__)
	#define __UPDATE_CSBI UpdateCSBI()
#else
	#define __UPDATE_CSBI
#endif

#if XSCCONF_STDCON_AUTO_UPDATE_COLOR >= ENABLED
	#define __UPDATE_COLOR Console.Color = _PreferredColor
	#define __UPDATE_AECOLOR Console.Color = _AnsiColor
#else
	#define __UPDATE_COLOR
	#define __UPDATE_AECOLOR
#endif

#if XSCCONF_NORETURN <= DISABLED
#  define __stdb_return(_Val) return _Val
#  define __xsc_return return
#else
#  define __stdb_return(_Val) (0)
#  define __xsc_return (void)
#endif

#endif /* - _XSC_ESSENTIALS - */

#ifndef XSC_STDB_CONSTRUCT
#define XSC_STDB_CONSTRUCT
    xsc_constructor(101) void __SCFULL_AUTO__(void);
    xsc_constructor(102) void __SCLINK_AUTO__(void);
    /* xsc_destructor (103) void Debug_atexit(void);
       xsc_constructor(104) void Debug_Runner(void); */
    xsc_constructor(105) void __STDCON_AUTO__(void);
    xsc_constructor(106) void __SCMATH_AUTO__(void);
#endif

#ifdef _SUPER_C_FULLY_DEFINED
#define _INIT_SUPER __SCFULL_AUTO__()
#else
#define _INIT_SUPER (0)
#endif
#ifdef _XSC_SCLINKER
#define _INIT_SCLINK __SCLINK_AUTO__()
#else
#define _INIT_SCLINK (0)
#endif
#ifdef _XSC_SCMATH
#define _INIT_SCMATH __SCMATH_AUTO__()
#else
#define _INIT_SCMATH (0)
#endif
#ifdef __STDCON__
#define _INIT_STDCON __STDCON_AUTO__()
#else
#define _INIT_STDCON (0)
#endif

#define _INIT_HEADERS _INIT_SUPER, _INIT_SCLINK, _INIT_SCMATH, _INIT_STDCON

#if COMPILER_HAS_CONSTRUCTOR <= FALSE
#define InitSuper (_INIT_HEADERS)
#else
#define InitSuper (EMIT_WARNING(5C000))
#endif

/** DEBUG MODE **/

#ifndef __DEBUGGER__
#define _SettList 0
#else
#undef _SettList
#endif

#ifndef OPT_INFO_READOUT
#define OPT_DISABLE_INTRO (_SettList >> 0) & 1
#define OPT_DISABLE_OUTRO (_SettList >> 1) & 1
#define OPT_INLINE_CONTINUE (_SettList >> 2) & 1
#define OPT_OUTPUT_PRINT (_SettList >> 3) & 1
#define OPT_ANSI_COLOR (_SettList >> 4) & 1
#define OPT_UNICODE_MODE (_SettList >> 5) & 1
#define OPT_EXTENDED_BUFFER (_SettList >> 6) & 1
#define OPT_INFO_READOUT (_SettList >> 7) & 1
#endif

#ifdef XSCSET_DEBUG

#ifndef XSC_DEBUG_BY_STDB
#ifndef __DEBUGGER__
#define __INCOMPLETE_DEBUGGING
#else
#undef __INCOMPLETE_DEBUGGING
#define __COMPLETE_DEBUGGING
#endif
#endif /* XSC_DEBUG_BY_STDB */

#if XSCSET_DEBUG >= ENABLED
#define XSC_DEBUG_BY_STDB
#include <super/debug>
#endif
#endif /* XSC_DEBUG */

/** shared variables **/

/*
//name ideas: mthread, shared_t, (i decided to go with shared)
//shared means that if multi thread is enabled: xsc_hot, else: xsc_unused.
*/

#if XSCCONF_SHARED == XSCSET_LOCAL_MODE
#define _shared xsc_hot
#else
#define _shared xsc_unused
#endif

/*
//instructions on how to use shared types:
//  differences between "_shared" and "shared"
//  _shared is a custom keyword found in "stdbasic.h"
//  designed for the lbr only,
//  even thought is designed for internal use only
//  it's possible to use it outside of the library.
//  but it optimizes way more aggressively
//  than "shared" and it's the more unsafer, aggressive version of
//  "shared" should be carefully maintained and administered
//  inside the limits of the library itself.
//  it's designed for internal use only, and it's library dependent.
//  meaning that it has an important optimization function inside
//  the library.
//
//  recommendation: do not use it unless you really know what you're doing.
//  but if you think you do, you certainly don't.
//
//  "shared" it's another custom keyword, this time found in "kwpack.h"
//  because it's an actual keyword designed for proper use.
//  and it's the correct keyword to use outside the library,
//  the difference between this keyword and the previous one is
//  that "_shared" tries to forcefully discard the variable
//  using the "unused" attribute.
*/

#ifndef XSC_SHARED_T
#define XSC_SHARED_T /* multi thread mode prevents shared variables from being used. */

  _shared String _sh_gblst = NULL; /* stands for Global String literalification, can be used by multiple functions & methods for optimization. */
  _shared size_t _sh_shared_len = 0; /* re-usable length format. */

#if XSCCONF_SHARED == XSCSET_LOCAL_MODE /* local-Mode */
#define _shared_t size_t /* full name: __def_shared_t */
#define __sh_len_ _lc_local_len
#define _xsc_choose_shared_t(_Shared, _Local) _Local
#else /* shared-Mode */
#define _shared_t
#define __sh_len_ _sh_shared_len /* didn't include _xsc_ because the code makes it way too large. */
#define _xsc_choose_shared_t(_Shared, _Local) _Shared
#endif

    /*_xsc_indentify_shared_expr*/
    /*_wsh_shared, _wsh_shared [NIP] NIP=NothingInParticular*/
#endif

/* //pre-defined Error Codes */
#ifndef __STXSC_ERROR_CODES
#define __STXSC_ERROR_CODES
#if XSCCONF_ANSI_ESCAPE <= DISABLED
#define ERR_5C000 "\r(Console Not Initialized)\n"
#define ERR_5C001 "\r(NULL String Parameter)\n"
#define ERR_5C002 "\rERROR: [0x5C002] (The Varidic Counter Can Only Count up to 8 Arguments)\n"
#define ERR_5C004 "\rERROR: [0x5C004] (error while parsing the file. something went wrong.. maybe the file doesn't exist)\n"
#define ERR_5C006 "\rERROR: [0x5C006] (Invalid Cycle Mode: %i)\n"
#define ERR_5C008 "\rERROR: [0x5C008] (please, include '%s' in order to use this function.) [LN:%i]"
#else
#define ERR_5C000 "\r(Console Not Initialized)\n"
#define ERR_5C001 "\r(NULL String Parameter)\n"
#define ERR_5C002 "\r\x1b[31m[ERROR]\x1b[0m -> \x1b[0;4m0x5C002 (The Varidic Counter Can Only Count up to 8 Arguments)\x1b[0m\n"
#define ERR_5C004 "\r\x1b[31m[ERROR]\x1b[0m -> \x1b[0;4m0(error while parsing the file. maybe it doesn't exist)\x1b[0m\n"
#define ERR_5C006 "\r\x1b[31m[ERROR]\x1b[0m -> \x1b[0;4m0x5C006 (Invalid Cycle Mode: %i)\x1b[0m\n"
#define ERR_5C008 "\r\x1b[31m[ERROR]\x1b[0m -> \x1b[0m4m00x5C008 (please, include '%s' in order to use this function.) [LN:%i]"
#endif
#endif

#if XSCCONF_SUPRESS_WARNINGS <= DISABLED
#ifndef __STXSC_WARNING_CODES
#define __STXSC_WARNING_CODES
#if XSCCONF_ANSI_ESCAPE <= DISABLED
#define WARN_5C000 "[Warning: Super-C Already Starts Automatically in Your Compiler.]\n\n"
#define WARN_5C001 "\r[WARNING]: Using data type \'char*\' as replacent due to lack of kwpach.h not included.\
lack of package inclusion will result in undefined behaviour if used with functions like scanf()\nHightly recommended to include \'kwpack.h\'.\
									[!]-[ Hightly recommended to include \'kwpack.h\'. ]"
#define WARN_5C008 "\r[WARNING]: (it's recommended to include '%s' in order for this function to work properly.) [LN:%i]"
#else
#define WARN_5C000 "[Warning: Super-C Already Starts Automatically in Your Compiler.]\n\n"
#define WARN_5C001 "\r\x1b[33m[WARNING]: Using data type \'char*\' as replacent due to lack of kwpach.h not included.\n\
lack of package inclusion will result in undefined behaviour if used with functions like scanf()\n\n\
							[\x1b[31m!\x1b[0m]\x1b[33m-\x1b[0m[ Hightly recommended to include \'kwpack.h\'. ]"

#define WARN_5C008 "\r\x1b[33m[WARNING]: (it's recommended to include '%s' in order for this function to work properly.) [LN:%i]\x1b[0m"
#endif
#endif
#else
#define WARN_5C000 ""
#define WARN_5C001 ""
#endif

#ifdef XSC_WINDOWS /* TODO: FIX POSITION LATER. */
#define __STDB_GETCH getch()
#else
#define __STDB_GETCH getchar()
#endif


#ifndef _STDB_MAIN_MACROS
#define _STDB_MAIN_MACROS /* // stdbasic.h general-purpose macros. // */

#define __EMIT_ERROR(_ERR_CODE, ...) \
(printf(ERR_##_ERR_CODE, __VA_ARGS__ +0), __STDB_GETCH, !((_SettList >> 2) & 1) ? exit(0x##_ERR_CODE) : 0)
#define tostr(ARG_) #ARG_ /* basic preprocessor 'stringification' system. */
#define printnq(...) printf("%s", #__VA_ARGS__) /* print-No-Quote. */
#define concat(_VAR_I, VAR_II_) _VAR_I##VAR_II_ /* basic preprocessor concatenation system. */
#define EMIT_WARNING(_WARN_CODE) (puts(_WARN_CODE)) /* emit standard library warning. */
#define EMIT_ERROR(...) __EMIT_ERROR(__VA_ARGS__) /* emit standard library error. */
#endif

#ifdef COMPILER_GCC
#define __EMIT_ERROR_LOG(MSG) xsc_error(MSG) /* GCC defined error */
#define __EMIT_WARNING_LOG(MSG) xsc_warning(MSG) /* GCC defined warning */
#define __EMIT_LOG(MSG)
#else
#define __EMIT_ERROR_LOG(MSG)
#define __EMIT_WARNING_LOG(MSG)
#define __EMIT_LOG(MSG)
#endif

#ifndef __STDCON__
#define __404_STDC __EMIT_ERROR(5C008, "stdcon.h", __LINE__)
#define EditCursor(_Vis, _Size) __404_STDC
#if C_VERSION >= CC99
#define printfln(_Main, ...) __404_STDC
#else
#define printfln(_Main, _Text) __404_STDC
#endif
#ifndef __DRAWS__
/* emit functions that are used/re-implemented by other packages. */
#define CursorPosition(_x, _y) __404_STDC
#else
#undef CursorPosition
#endif

/* auto-implement stuff that are simple enough */
#define ActivateAE() (system(""))
#else
#ifndef __STDC_TMP_RPL_UNDEFINED
#undef CursorPosition
#undef EditCursor
#undef ActivateAE
#undef printfln
#define __STDC_TMP_RPL_UNDEFINED 1
#endif
#endif /* - STDCON - */

#ifndef _XSC_ASCII_PAINT
#define __404_DRAWS EMIT_ERROR(5C008, "draws.h", __LINE__)
#define drawSquare(X, Y, W, H, Ch) __404_DRAWS
#define drawEllipse(X, Y, W, H, Ch) __404_DRAWS
#else
#ifndef __DRAWS_TMP_RPL_UNDEFINED
#undef drawSquare
#undef drawEllipse
#define __DRAWS_TMP_RPL_UNDEFINED 1
#endif
#endif /* - DRAWS - */

#if __INLINE_COMMENT__
#undef __404_DRAWS
#undef __404_STDC
#undef __404_DRAWS
#undef __404_STDC
#endif

/* [TDO] PUT THIS in GETOS, that by default is going to be a separate.
    header from stdcon.h that will be used by getos.h and
    stdcon.h
*/
#ifndef __STDB_DEFCONSL_WIDTH
#if XSC_OS == OsID_WINDOWS

#if XSC_OSVER > 9
#define __STDB_DEFCONSL_WIDTH 120
#define __STDB_DEFCONSL_HEIGHT 30
#else
#define __STDB_DEFCONSL_WIDTH 80
#define __STDB_DEFCONSL_HEIGHT 40
#endif

#elif XSC_OS == OsID_LINUX
#define __STDB_DEFCONSL_WIDTH 120
#define __STDB_DEFCONSL_HEIGHT 30
#elif XSC_OS == OsID_MAC && defined(__MACH__)
#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 110000
#define __STDB_DEFCONSL_WIDTH 100
#define __STDB_DEFCONSL_HEIGHT 30
#else
#define __STDB_DEFCONSL_WIDTH 80
#define __STDB_DEFCONSL_HEIGHT 24
#endif
#else
#define __STDB_DEFCONSL_WIDTH 80
#define __STDB_DEFCONSL_HEIGHT 40
#endif

#endif

#if VERSION >= C99

#define __c89_decl_loop(I) /* use this only when you need to specify a name and value to the variable. */
#define __c99_decl_loop(I) int I

#define __c89_decl
#define __c99_decl int I = 0

#define __c89_decl_sr_loop(I) /* Note: sr = set/reset */
#else
/* Alt: __CXX_DECL_LOOP, __CXX_DECL */
#define __c89_decl_loop(I) int I
#define __c99_decl_loop(I) I

#define __c89_decl int I = 0
#define __c99_decl I

#define __c89_decl_sr_loop(I) I
#endif

#ifdef COMPILER_MSVC /* resolve assembly issues. */
#  define asm __asm
#endif

/* resolve compiler issues in this section. */
#ifdef __TINYC__
#define usleep(_slp)
#endif

#if LANG_VERSION >= CC99
#define _C99_INLINE inline
#else
#define _C99_INLINE
#endif

#ifndef _STDB_TYPEOF_
#include <super/sub/typeof.h>
#endif

#ifndef _STDINT_H
#include <super/sub/stdcrt.h>
#endif

#ifndef __SCIFI_H__ /* changed meaning to: SC-InFo-Internal-storage */
#include <super/sub/scinfo.h>
#endif

#endif /* __STDBASIC__ */

