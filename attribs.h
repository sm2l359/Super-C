#ifndef _XCD_COMPILER_ATTRIBS
#define _XCD_COMPILER_ATTRIBS

#include <super/compiler.h>
#include <super/version.h> /* version.h should NOT use any "attribs.h" features, otherwise that would cause a loophole. */

/* Essentials: */
#if COMPILER_ID == 0 /* Unknown Compiler */
#line 10 "[COMPILER-ATTRIBS]"
#elif COMPILER_ID == 1 /* GCC */
#line 12 "[GCC-ATTRIBS]"
#elif COMPILER_ID == 2 /* CLANG */
#line 14 "[CLANG-ATTRIBS]"
#elif COMPILER_ID == 3  /* MICROSOFT VISUAL C/C++ */
#line 16 "[MSC-ATTRIBS]"
#elif COMPILER_ID == 4 /* IBM-C */
#line 18 "[IBMC-ATTRIBS]"
#elif COMPILER_ID == 5 /* Open-64 */
#line 20 "[OPEN64-ATTRIBS]"
#elif COMPILER_ID == 6 /* Intel-C Compiler */
#line 22 "[INTELC-ATTRIBS]"
#elif COMPILER_ID == 7
#line 24 "[TINYC-ATTRIBS]"
#endif

/**
    Package Name: attribs.h / attribs,
    stands for "compiler attributes".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

/*** These Features Are Compiler Specific And Are Not  ***/
/*** Available For All C/C++ Compilers Out There, So Use Them Wisely And Carefully. ***/

#if __INLINE_COMMENT__

//Each Function Explained:

//Constructor - built-in constructor, Even thought C does not have constructors, GCC does have a feature that allows you to execute code-
//              before the main function.
//Destructor - Same as constructor, but not really useful since C already has a function that allows you to run code at the end: "atexit()".
//Hot - it Indicates that a function is really used. allowing the compiler to do optimizations based on this information.
//Cold - the opposite of hot, It Indicates that a function is rarely used. hinting the compiler to do optimizations based on this information.
//fastcall - calling convention, changes how function arguments are passed by making the first args be passed in CPU registers instead of the stack.

#endif

/*
placeholder guide to help the developer with all the compilers support:
__attribute__((constructor))
- MSVC: "#pragma startup" Clang: "__attribute__((constructor))".
__attribute__((destructor)) --> MSVC-alt: "#pragma exit".
__attribute__((always_inline)) --> MSVC-alt: "__forceinline".
__attribute__((noreturn)) - MSVC-alt: "__declspec(noreturn)".
__attribute__((deprecated)) - MSVC-alt: "__declspec(deprecated)".
__attribute__((packed)) - MSVC-alt: "#pragma pack".
__attribute__((dllimport)) - Not portable;
__attribute__((dllexport)) - Not portable;
__attribute__((noinline)) - MSVC: "__declspec(noinline)". Clang: ""
__attribute__((used)) - Not portable;
__attribute__((unused)) - Not portable;
__attribute__((nothrow)) - Not portable;
__attribute__((naked)) - MSVC-alt: "__declspec(naked)". Other compilers may or may not support similar features.
__attribute__((artificial)) - Not portable;
__attribute__((flatten)) - Not portable;
__attribute__((pure)) - Not portable;
__attribute__((hot)) - Not portable;
__attribute__((cold)) - Not portable;
__attribute__((near)) - Not portable;
__attribute__((cdecl)) - Not portable;
__attribute__((fastcall)) - Not portable;
__attribute__((interrupt(#INT))) - Not portable;
__attribute__((constructor(VAL))) - Not portable;
__attribute__((destructor(VAL))) - Not portable;
__attribute__((section(#VAL))) - MSVC-alt: "#pragma section". Clang: "__attribute__((section(#VAL)))". Other compilers might support similar mechanisms.
__attribute__((optimize(#OPT))) - Not portable;
__attribute__((version_id(#VER))) - Not portable;
__attribute__((function_vector(VEC))) - Not portable;
__attribute__((error(ERR))) - Not portable;
__attribute__((warning(WRN))) - Not portable;
__attribute__((visibility(#VIS))) - Not portable;
__attribute__((visibility("hidden"))) - Not portable;
__attribute__((visibility("protected"))) - Not portable;
__attribute__((visibility("default"))) - Not portable;
__attribute__((visibility("internal"))) - Not portable;
__attribute__((__nonnull__ (_V))) - Not portable;
*/

#if LANG_VERSION >= C99
#define _C99_INLINE inline
#else
#define _C99_INLINE
#endif

#if defined(__GNUC__) || defined(__clang__) || defined(__GNUG__) /* GNU-C / Clang Compilers. */

#define attrib    (_Cmnd)        __attribute__((_Cmnd)) /* supports 1 argument only. */
#define attribs    (...)         __attribute__((__VA_ARGS__))
#define xsc_construct            __attribute__((constructor))
#define xsc_destruct             __attribute__((destructor))
#define xsc_forceinline          __attribute__((always_inline))
#define xsc_noreturn             __attribute__((noreturn))
#define xsc_deprecated           __attribute__((deprecated))
#define xsc_packed               __attribute__((packed))
#define xsc_dllimport            __attribute__((dllimport))
#define xsc_dllexport            __attribute__((dllexport))
#define xsc_noinline             __attribute__((noinline))
#define xsc_used                 __attribute__((used))
#define xsc_unused               __attribute__((unused))
#define xsc_nothrow              __attribute__((nothrow))
#define xsc_naked                __attribute__((naked))
#define xsc_artificial           __attribute__((artificial))
#define xsc_flatten              __attribute__((flatten))
#define xsc_const                __attribute__((const))
#define xsc_pure                 __attribute__((pure))
#define xsc_hot                  __attribute__((hot))
#define xsc_cold                 __attribute__((cold))
#define xsc_near                 __attribute__((near))
#define xsc_cdecl                __attribute__((cdecl))
#define xsc_fastcall             __attribute__((fastcall))
#define xsc_interrupt(INT)       __attribute__((interrupt(#INT)))
#define xsc_constructor(VAL)     __attribute__((constructor(VAL))) /* ID/ORDER */
#define xsc_destructor(VAL)      __attribute__((destructor(VAL)))
#define xsc_section(STR)         __attribute__((section(STR)))
#define xsc_optimize(LVL)        __attribute__((optimize(#LVL))) /*NOTE: use # only for numbers. with visibility being the only exception.*/
#define xsc_version_id(VER)      __attribute__((version_id(#VER))) /*(automatize string-fication [only for numbers])*/
#define xsc_vector(VEC)          __attribute__((function_vector(VEC)))
#define xsc_aligned(ALG)         __attribute__((aligned(ALG))
#define xsc_error(ERR)           __attribute__((error(ERR)))
#define xsc_warning(WRN)         __attribute__((warning(WRN)))
#define xsc_visibility(VIS)      __attribute__((visibility(#VIS)))
#define xsc_hidden_visibility    __attribute__((visibility("hidden")))
#define xsc_protected_visibility __attribute__((visibility("protected")))
#define xsc_default_visibility   __attribute__((visibility("default")))
#define xsc_internal_visibility  __attribute__((visibility("internal")))
#define xsc_format(_arch, i, A1) __attribute__((format(_arch, i, A1))) /* i = index, A1 = 1st Argument. */
#define xsc_nonull(_V)           __attribute__((__nonnull__ (_V)))
/* */
#define xsc_expect(_Condition, _Probability) __builtin_expect(_Condition, _Probability)
#define xsc_likely(_Condition) xsc_expect(_Condition, 1)
#define xsc_unlikely(_Condition) xsc_expect(_Condition, 0)

#ifdef __clang__
#define xsc_assume(_Condition) __builtin_assume(_Condition)
#define xsc_presume(_Condition) __builtin_assume(_Condition)
#else
#define xsc_assume(_Condition)
#define xsc_presume(_Condition) __builtin_expect(_Condition, 1)
#endif
/* */
#ifdef __GNUC__
#define xsc_extension __extension__
#else
#define xsc_extension
#endif

#define xsc_auto __auto_type

#elif defined(_MSC_VER)

#define attrib    (_Cmnd)        __declspec(_Cmnd)
#define attribs    (...)         __declspec(__VA_ARGS__)
#define xsc_construct
#define xsc_destruct
#define xsc_forceinline          __forceinline
#define xsc_noreturn             __declspec(noreturn)
#define xsc_deprecated           __declspec(deprecated)
#define xsc_packed               __declspec(align)
#define xsc_dllimport            __declspec(dllimport)
#define xsc_dllexport            __declspec(dllexport)
#define xsc_noinline             __declspec(noinline)
#define xsc_used
#define xsc_unused
#define xsc_nothrow              __declspec(nothrow)
#define xsc_naked                __declspec(naked)
#define xsc_artificial
#define xsc_flatten
#define xsc_const
#define xsc_pure
#define xsc_hot
#define xsc_cold
#define xsc_near
#define xsc_cdecl
#define xsc_fastcall
#define xsc_interrupt(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_constructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_destructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_section(STR) __declspec(allocate(STR))
#define xsc_optimize(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_version_id(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_vector(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_aligned(ALG) __declspec(align(ALG))
#define xsc_error(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_warning(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_visibility(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_hidden_visibility
#define xsc_protected_visibility
#define xsc_default_visibility
#define xsc_internal_visibility
#define xsc_format(_arch, i, A1)
#define xsc_nonull(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_expect(_Condition, _Probability)
#define xsc_likely(_Condition)
#define xsc_unlikely(_Condition)

#define xsc_assume(_Condition) __assume(_Condition)
#define xsc_presume(_Condition) __assume(_Condition)
/* */
#define xsc_extension

#define xsc_auto void*

#elif defined(__IBMC__) /* IBM C/C++ Compiler. */

#if defined(__GNUC__)
#define attrib    (_Cmnd)      __attribute__((_Cmnd))
#define attribs    (...)       __attribute__((__VA_ARGS__))
#define xsc_construct          __attribute__((constructor))
#define xsc_destruct           __attribute__((destructor))
#define xsc_forceinline        __attribute__((always_inline))
#define xsc_noreturn           __attribute__((noreturn))
#define xsc_deprecated         __attribute__((deprecated))
#define xsc_packed             __attribute__((packed))
#define xsc_dllexport
#define xsc_dllimport
#define xsc_noinline           __attribute__((noinline))
#define xsc_used               __attribute__((used))
#define xsc_unused             __attribute__((unused))
#define xsc_nothrow
#define xsc_naked
#define xsc_artificial
#define xsc_flatten
#define xsc_pure
#define xsc_hot
#define xsc_cold
#define xsc_near
#define xsc_cdecl
#define xsc_fastcall
#define xsc_interrupt(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_constructor(VAL)   __attribute__((constructor, VAL))
#define xsc_destructor(VAL)    __attribute__((destructor, VAL))
#define xsc_section(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_optimize(LVL)        __attribute__((optimize(#LVL)))
#define xsc_version_id(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_vector(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_aligned(ALG)       __attribute__((aligned(ALG))
#define xsc_error(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_warning(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_visibility(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_hidden_visibility
#define xsc_protected_visibility
#define xsc_default_visibility
#define xsc_internal_visibility
#define xsc_format(_arch, i, A1)
#define xsc_nonull(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_expect(_Condition, _Probability) __builtin_expect(_Condition, _Probability)
#define xsc_likely(_Condition) xsc_expect(_Condition, 1)
#define xsc_unlikely(_Condition) xsc_expect(_Condition, 0)

#define xsc_assume(_Condition)
#define xsc_presume(_Condition) xsc_expect(_Condition, 1) /* assume is promoted to builtin-expect if doesn't exist. */
/* */
#define xsc_extension
#define xsc_auto void*
#endif

/*
//__INTEL_COMPILER = ICC - Partial Compat.
//__INTEL_CLANG_COMPILER = ICX - Full Compat.
//_ICL = Windows/MSVC - uses declspec, probably.
*/

#elif defined(__INTEL_CLANG_COMPILER) /* Intel-C (Clang) / ICX, Full Compatibility. */

#define attrib    (_Cmnd)        __attribute__((_Cmnd))
#define attribs    (...)         __attribute__((__VA_ARGS__))
#define xsc_construct            __attribute__((constructor))
#define xsc_destruct             __attribute__((destructor))
#define xsc_forceinline          __attribute__((always_inline))
#define xsc_noreturn             __attribute__((noreturn))
#define xsc_deprecated           __attribute__((deprecated))
#define xsc_packed               __attribute__((packed))
#define xsc_dllimport            __attribute__((dllimport))
#define xsc_dllexport            __attribute__((dllexport))
#define xsc_noinline             __attribute__((noinline))
#define xsc_used                 __attribute__((used))
#define xsc_unused               __attribute__((unused))
#define xsc_nothrow              __attribute__((nothrow))
#define xsc_naked                __attribute__((naked))
#define xsc_artificial           __attribute__((artificial))
#define xsc_flatten              __attribute__((flatten))
#define xsc_const                __attribute__((const))
#define xsc_pure                 __attribute__((pure))
#define xsc_hot                  __attribute__((hot))
#define xsc_cold                 __attribute__((cold))
#define xsc_near                 __attribute__((near))
#define xsc_cdecl                __attribute__((cdecl))
#define xsc_fastcall             __attribute__((fastcall))
#define xsc_interrupt(INT)       __attribute__((interrupt(#INT)))
#define xsc_constructor(VAL)     __attribute__((constructor(VAL)))
#define xsc_destructor(VAL)      __attribute__((destructor(VAL)))
#define xsc_section(STR)         __attribute__((section(STR)))
#define xsc_optimize(LVL)        __attribute__((optimize(#LVL)))
#define xsc_version_id(VER)      __attribute__((version_id(#VER)))
#define xsc_vector(VEC)          __attribute__((function_vector(VEC)))
#define xsc_aligned(ALG)         __attribute__((aligned(ALG))
#define xsc_error(ERR)           __attribute__((error(ERR)))
#define xsc_warning(WRN)         __attribute__((warning(WRN)))
#define xsc_visibility(VIS)      __attribute__((visibility(#VIS)))
#define xsc_hidden_visibility    __attribute__((visibility("hidden")))
#define xsc_protected_visibility __attribute__((visibility("protected")))
#define xsc_default_visibility   __attribute__((visibility("default")))
#define xsc_internal_visibility  __attribute__((visibility("internal")))
#define xsc_format(_arch, i, A1) __attribute__((format(_arch, _f, A1)))
#define xsc_nonull(_V)           __attribute__((__nonnull__ (_V)))
/* */
#define xsc_expect(_Condition, _Probability) __builtin_expect(_Condition, _Probability)
#define xsc_likely(_Condition) xsc_expect(_Condition, 1)
#define xsc_unlikely(_Condition) xsc_expect(_Condition, 0)

#define xsc_assume(_Condition)
#define xsc_presume(_Condition) __builtin_expect(_Condition, 1)
/* */
#ifdef __GNUC__
#define xsc_extension __extension__
#else
#define xsc_extension
#endif
#define xsc_auto __auto_type

#elif (defined(__INTEL_COMPILER) || defined(__ICC) || defined(__INTEL_CXX_COMPILER)) && \
!defined(XSC_MAC) /* Intel-C (Classic Intel-C) / ICC */
/* Windows Mode (Partial Compatibility.), MSVC-Like */
#if defined(XSC_WINDOWS)

#define attrib    (_Cmnd)      __declspec(_Cmnd)
#define attribs    (...)       __declspec(__VA_ARGS__)
#define xsc_construct
#define xsc_destruct
#define xsc_forceinline          __forceinline
#define xsc_noreturn             __declspec(noreturn)
#define xsc_deprecated           __declspec(deprecated)
#define xsc_packed               __declspec(align)
#define xsc_dllimport            __declspec(dllimport)
#define xsc_dllexport            __declspec(dllexport)
#define xsc_noinline             __declspec(noinline)
#define xsc_used
#define xsc_unused
#define xsc_nothrow              __declspec(nothrow)
#define xsc_naked                __declspec(naked)
#define xsc_artificial
#define xsc_flatten
#define xsc_const
#define xsc_pure
#define xsc_hot
#define xsc_cold
#define xsc_near
#define xsc_cdecl
#define xsc_fastcall
#define xsc_interrupt(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_constructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_destructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_section(STR) __declspec(allocate(STR))
#define xsc_optimize(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_version_id(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_vector(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_aligned(ALG)        __declspec(align(ALG))
#define xsc_error(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_warning(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_visibility(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_hidden_visibility
#define xsc_protected_visibility
#define xsc_default_visibility
#define xsc_internal_visibility
#define xsc_format(_arch, i, A1)
#define xsc_nonull(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_expect(_Condition, _Probability)
#define xsc_likely(_Condition)
#define xsc_unlikely(_Condition)

#define xsc_assume(_Condition) __assume(_Condition)
#define xsc_presume(_Condition) __assume(_Condition)
/* */
#define xsc_extension
#define xsc_auto void*
#elif defined(XSC_LINUX)
#define attrib    (_Cmnd)        __attribute__((_Cmnd))
#define attribs    (...)         __attribute__((__VA_ARGS__))
#define xsc_construct            __attribute__((constructor))
#define xsc_destruct             __attribute__((destructor))
#define xsc_forceinline          __attribute__((always_inline))
#define xsc_noreturn             __attribute__((noreturn))
#define xsc_deprecated           __attribute__((deprecated))
#define xsc_packed               __attribute__((packed))
#define xsc_dllimport            __attribute__((dllimport))
#define xsc_dllexport            __attribute__((dllexport))
#define xsc_noinline             __attribute__((noinline))
#define xsc_used                 __attribute__((used))
#define xsc_unused               __attribute__((unused))
#define xsc_nothrow              __attribute__((nothrow))
#define xsc_naked                __attribute__((naked))
#define xsc_artificial           __attribute__((artificial))
#define xsc_flatten              __attribute__((flatten))
#define xsc_const                __attribute__((const))
#define xsc_pure                 __attribute__((pure))
#define xsc_hot                  __attribute__((hot))
#define xsc_cold                 __attribute__((cold))
#define xsc_near                 __attribute__((near))
#define xsc_cdecl                __attribute__((cdecl))
#define xsc_fastcall             __attribute__((fastcall))
#define xsc_interrupt(INT)       __attribute__((interrupt(#INT)))
#define xsc_constructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_destructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_section(STR)         __attribute__((section(STR)))
#define xsc_optimize(LVL)        __attribute__((optimize(#LVL)))
#define xsc_version_id(VER)      __attribute__((version_id(#VER)))
#define xsc_vector(VEC)          __attribute__((function_vector(VEC)))
#define xsc_aligned(ALG)         __attribute__((aligned(ALG))
#define xsc_error(ERR)           __attribute__((error(ERR)))
#define xsc_warning(WRN)         __attribute__((warning(WRN)))
#define xsc_visibility(VIS)      __attribute__((visibility(#VIS)))
#define xsc_hidden_visibility    __attribute__((visibility("hidden")))
#define xsc_protected_visibility __attribute__((visibility("protected")))
#define xsc_default_visibility   __attribute__((visibility("default")))
#define xsc_internal_visibility  __attribute__((visibility("internal")))
#define xsc_format(_arch, i, A1) __attribute__((format(_arch, _f, A1)))
#define xsc_nonull(_V)           __attribute__((__nonnull__ (_V)))
/* */
#define xsc_expect(_Condition, _Probability) __builtin_expect(_Condition, _Probability)
#define xsc_likely(_Condition) xsc_expect(_Condition, 1)
#define xsc_unlikely(_Condition) xsc_expect(_Condition, 0)

#define xsc_assume(_Condition)
#define xsc_presume(_Condition) __builtin_expect(_Condition, 1)
/* */
#define xsc_extension
#define xsc_auto void*
#endif

#elif defined(__TINYC__)
#define attrib    (_Cmnd) __attribute__((_Cmnd))
#define attribs    (...)  __attribute__((__VA_ARGS__))
#define xsc_construct
#define xsc_destruct
#define xsc_forceinline _C99_INLINE
#define xsc_noreturn
#define xsc_deprecated
#define xsc_packed
#define xsc_dllimport
#define xsc_dllexport
#define xsc_noinline
#define xsc_used
#define xsc_unused
#define xsc_nothrow
#define xsc_naked
#define xsc_artificial
#define xsc_flatten
#define xsc_const
#define xsc_pure
#define xsc_hot
#define xsc_cold
#define xsc_near
#define xsc_cdecl
#define xsc_fastcall
#define xsc_interrupt(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_constructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_destructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_section (INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_optimize(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_version_id(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_vector(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_aligned(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_error(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_warning(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_visibility(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_hidden_visibility
#define xsc_protected_visibility
#define xsc_default_visibility
#define xsc_internal_visibility
#define xsc_format(INCOMPATIBLE_IN,_YOUR,_COMPILER)
#define xsc_nonull(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_expect(INCOMPATIBLE_IN,_YOUR_COMPILER)
#define xsc_likely(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_unlikely(INCOMPATIBLE_IN_YOUR_COMPILER)

#define xsc_assume(_Condition)
#define xsc_presume(_Condition)
/* */
#define xsc_extension
#define xsc_auto void*
#elif defined(__RYC__) /* identify if you're using the official compiler. */
/* #define attribs(...) attrib(__VA_ARGS__) */
#define xsc_construct attrib(construct)
#define xsc_destruct attrib(destruct)
#define xsc_forceinline attrib(inline)
#define xsc_noreturn attrib(noreturn)
#define xsc_deprecated attrib(deprecated)
#define xsc_packed attrib(packed)
#define xsc_dllimport attrib(shimport) /* osimport, osexport, stdimport, stdexport */
#define xsc_dllexport attrib(shexport) /* sh = shared, oil = os internal library */
#define xsc_noinline attrib(noinline)
#define xsc_used attrib(used)
#define xsc_unused attrib(unused)
#define xsc_nothrow attrib(nothrow)
#define xsc_naked attrib(naked)
#define xsc_artificial attrib(artificial)
#define xsc_flatten attrib(flatten)
#define xsc_const attrib(const)
#define xsc_pure attrib(pure)
#define xsc_hot attrib(hot) /* AKA, overused */
#define xsc_cold attrib(cold) /* AKA, selused */
#define xsc_near attrib(near)
#define xsc_cdecl attrib(cdecl)
#define xsc_fastcall attrib(fastcall)
#define xsc_interrupt(INT) attrib(int(INT)) /* AKA, Interrupt */
#define xsc_constructor(...?) attrib(constructor(VMA_ARGS)) /* allows the argument number to be 0 */
#define xsc_destructor(...?) attrib(destructor(VMA_ARGS)) /* mandatory to use VMA_ARGS */
#define xsc_section(STR) attrib(section(STR))
#define xsc_optimize(LVL) attrib(optimize(LVL))
#define xsc_version_id(VER) attrib(verid(VER))
#define xsc_vector(VEC) attrib(vector(VEC))
#define xsc_aligned(ALG) attrib(aligned(ALG))
#define xsc_error(ERR) attrib(error(ERR))
#define xsc_warning(WRN) attrib(warning(WRN))
#define xsc_visibility(_VISLEVEL) attrib(vis:_VISLEVEL)
#define xsc_hidden_visibility attrib(vis:hidden)
#define xsc_protected_visibility attrib(vis:protected)
#define xsc_default_visibility attrib(vis:default)
#define xsc_internal_visibility attrib(vis:internal)
#define xsc_format(...) attrib(format:printf(VMA_ARGS)) /* VARIDIC MACRO */
#define xsc_nonull(...) attrib(notnull(__VA_ARGS__))
/* the Power C compiler, royal C collection. */
#define xsc_expect(_Condition, _Probability) attrib(expect(_Condition, _Probability))
#define xsc_likely(_Condition) xsc_expect(_Condition)
#define xsc_unlikely(_Condition) xsc_expect(_Condition)

#define xsc_assume(_Condition) attrib(assume(_Condition))
#define xsc_presume(_Condition) attrib(assume(_Condition))
/* */
#define xsc_extension __acbc_ext__
#define xsc_auto __var__ /* the var tag is used only for Cross Compiler compatibility */
#else /* If the Compiler is not Recognized, Redefine The Macros to Do Nothing Instead. */
#define attrib(_Cmnd)
#define attribs(...)
#define xsc_construct
#define xsc_destruct
#define xsc_forceinline _C99_INLINE
#define xsc_noreturn
#define xsc_deprecated
#define xsc_packed
#define xsc_dllimport
#define xsc_dllexport
#define xsc_noinline
#define xsc_used
#define xsc_unused
#define xsc_nothrow
#define xsc_naked
#define xsc_artificial
#define xsc_flatten
#define xsc_const
#define xsc_pure
#define xsc_hot
#define xsc_cold
#define xsc_near
#define xsc_cdecl
#define xsc_fastcall
#define xsc_interrupt(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_constructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_destructor(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_section(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_optimize(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_version_id(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_vector(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_aligned(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_error(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_warning(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_visibility(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_hidden_visibility
#define xsc_protected_visibility
#define xsc_default_visibility
#define xsc_internal_visibility
#define xsc_format(INCOMPATIBLE_IN,_YOUR,_COMPILER)
#define xsc_nonull(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_expect(INCOMPATIBLE_IN,_YOUR_COMPILER)
#define xsc_likely(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_unlikely(INCOMPATIBLE_IN_YOUR_COMPILER)

#define xsc_assume(INCOMPATIBLE_IN_YOUR_COMPILER)
#define xsc_presume(INCOMPATIBLE_IN_YOUR_COMPILER)
/* */
#define xsc_extension
#define xsc_auto void*
#endif

/* cross-compatible types section, (attributes that change 1 small detail. when impl.) */
#if COMPILER_USING_GLIBC == 1
#define xsc_crossformat(_Fmt, _Str, _VArg) xsc_format(gnu_##_Fmt, _Str, _VArg)
#elif COMPILER_ID == ID_GCC
#define xsc_crossformat(_Fmt, _Str, _VArg) xsc_format(_Fmt, _Str, _VArg)
#elif COMPILER_ID == ID_MSVC
#define xsc_crossformat(_Fmt, _Str, _VArg) xsc_format(ms_##_Fmt, _Str, _VArg)
#elif COMPILER_ID == ID_CLANG
#if XSC_OS == OsID_MAC
#define xsc_crossformat(_Fmt, _Str, _VArg) xsc_format(cmn_##_Fmt, _Str, _VArg)
#endif
#else
#define xsc_crossformat(_Fmt, _Str, _VArg) xsc_format(_Fmt, _Str, _VArg)
#endif

/** Global Definitions Section. **/
#define xscs_text xsc_section(".text")
#define xscs_data xsc_section(".data")
#define xscs_rodata xsc_section(".rodata")
#define xscs_bss xsc_section(".bss")
/* Super-C Exclusive */
#define xscs_super xsc_section(".Super") /* main section start, no specification. */
#define xscs_data xsc_section(".Super.data") /* build, version, compiled program date, standard program language, etc... */
#define xscs_info xsc_section(".Super.info") /* development/release, acquirement place, general license info, publisher name, etc... */
#define xscs_shared xsc_section(".shared") /* reserved for the shared modifier. */
#define xscs_shared_t xsc_section(".sharedt") /* reserved for shared types. */

#if XSCCONF_CUSTOM_SECTIONS == 1
#define xscs_stdbasic xsc_section(".Super.std")
#define xscs_scmath xsc_section(".Super.scmath")
#define xscs_stdcon xsc_section(".Super.console")
#define xscs_cycles xsc_section(".Super.cycles")
#define xscs_draws xsc_section(".Super.draws")
#define xscs_aniframe xsc_section(".Super.anif")
#define xscs_strings xsc_section(".Super.strings")
#define xscs_stringpp xsc_section(".Super.spp") /* string++ */
#define xscs_sciopak xsc_section(".Super.experiments") /* sciopak.h */
#define xscs_logic xsc_section("Super.gate") /* logic.h */

#define xscs_pltstd xsc_section(".platspec")
#define xscs_misc xsc_section(".miscellaneous")
#else
#define xscs_stdbasic
#define xscs_scmath
#define xscs_stdcon
#define xscs_cycles
#define xscs_draws
#define xscs_aniframe
#define xscs_strings
#define xscs_stringpp
#define xscs_sciopak
#define xscs_logic

#define xscs_pltstd
#define xscs_misc
#endif

/* have no effect at all, only used for organization. */
#define __attribs(_ARG) _ARG
#define __extpack(_ARG) xsc_extension _ARG

#define __xsc_attribs(_ARGS) _ARGS

/** Alternative Spellings Section. **/

/* Alternative Spellings for xsc_forceinline. */
#define xsc_forceline xsc_forceinline
#define xsc_inline xsc_forceinline
#define xsc_alwaysinline xsc_forceinline

/* Alternative Spellings for xsc_constructor && xsc_destructor. */
#define Constructor(_VAL) xsc_constructor(_VAL)
#define Destructor(_VAL) xsc_destructor(_VAL)

/* Other Alternative Spellings... */
#define xsc_nonnull(_V) xsc_nonull(_V)
#define xsc_notnull(_V) xsc_nonull(_V) /* <- the best one. */

#endif /* _XCD_COMPILER_ATTRIBS */
