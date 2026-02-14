#ifndef _STDB_TYPEOF_
#define _STDB_TYPEOF_

/**
    Package Name: typeof.h,
    stands for "typeof collection".
    General Purpose Package? yes;
    Child-Package? yes, dependent;
        Parent-Packages: "stdbasic.h", "autoVA.h";
    Experimental Package? no.
**/

#ifndef __STDB_DEFINED
#include <super/stdbasic.h>
#endif

/* currently, this library is under domain of stdbasic.h and autoVA.h, but that may change in the future... */

#ifndef Random
#define Random unsigned char**
#endif

#ifndef __KWPACK__
#define mstring char*
#define lostring char*
#define histring char*
#define hihistring char*
#endif

#if defined(__GNUC__) || defined(__GNUG__) /* && !defined(typeof) */
#define typeof(t) __typeof__(t)
#elif defined(_MSC_VER)
#define typeof(t) __typeof(t)
#elif defined(__clang__)
#define typeof(t) __typeof__(t)
#elif defined(__IBMC__)
#define typeof(t) __typeof__(t)
#elif defined(__SUNPRO_C)
#define typeof(t) typeof(t)
#elif defined(__HP_cc)
#define typeof(t) __typeof__(t)
#elif defined(__TINYC__)
#define typeof(t) typeof(t)
#else /* Compiler not Found. */
#define typeof(t) void*
#define __TYPEOF_UNAVAILABLE 1
#endif
/* typecmp: (sizeof(_T) == sizeof(_t) && sizeof(*((_T) ? &_T : (_t*)0)) == sizeof(_t)) */
/* dtypecmp: (sizeof(_T) == sizeof(_t) && (sizeof(*(0 ? (_T*)0 : (_t*)0)) == sizeof(_t))) */
#define typecmp2(_T, _t) (sizeof(_T) == sizeof(_t) && sizeof(*((_T) ? &_T : (_t*)0)) == sizeof(_t))
#define dtypecmp(_T, _t) (sizeof(_T) == sizeof(_t) && (sizeof(*(0 ? (_T*)0 : (_t*)0)) == sizeof(_t)))

#if (COMPILER_ID == 1 || COMPILER_ID == 2) && !defined(__TYPEOF_UNAVAILABLE)
#define typecmp(_type1, _type2) __builtin_types_compatible_p(typeof(_type1), _type2)
#else
#define typecmp(_T, _t) typecmp2(_T, _t)
#define XDB_USING_TYPECMP2
#endif

#if CONFIG_TYPEOF_MOD3 != 1
#if defined(__MINGW32__)
#define _ctypeof(_T)    __builtin_types_compatible_p(typeof(_T), char) ? 'B' : \
__builtin_types_compatible_p(typeof(_T), short) ? 'C' : \
__builtin_types_compatible_p(typeof(_T), int) ? 'D' : \
__builtin_types_compatible_p(typeof(_T), long) ? 'E' : \
__builtin_types_compatible_p(typeof(_T), long long) ? 'F' : \
__builtin_types_compatible_p(typeof(_T), unsigned char) ? 'G' : \
__builtin_types_compatible_p(typeof(_T), unsigned short) ? 'H' : \
__builtin_types_compatible_p(typeof(_T), unsigned int) ? 'I' : \
__builtin_types_compatible_p(typeof(_T), unsigned long) ? 'J' : \
__builtin_types_compatible_p(typeof(_T), unsigned long long) ? 'K' : \
__builtin_types_compatible_p(typeof(_T), char*) ? 'L' : \
__builtin_types_compatible_p(typeof(_T), short*) ? 'M' : \
__builtin_types_compatible_p(typeof(_T), int*) ? 'N' : \
__builtin_types_compatible_p(typeof(_T), long*) ? 'O' : \
__builtin_types_compatible_p(typeof(_T), long long*) ? 'P' : \
__builtin_types_compatible_p(typeof(_T), void*) ? 'Q' : \
__builtin_types_compatible_p(typeof(_T), float) ? 'R' : \
__builtin_types_compatible_p(typeof(_T), double) ? 'S' : \
__builtin_types_compatible_p(typeof(_T), long double) ? 'T' : \
__builtin_types_compatible_p(typeof(_T), _Bool) ? 'U' : \
__builtin_types_compatible_p(typeof(_T), Random) ? 'V' : \
__builtin_types_compatible_p(typeof(_T), lostring) ? 'W' : \
__builtin_types_compatible_p(typeof(_T), mstring) ? 'X' : \
__builtin_types_compatible_p(typeof(_T), histring) ? 'Y' : \
__builtin_types_compatible_p(typeof(_T), hihistring) ? 'Z' : 'A' \
///
#endif /* first attempt of creating typeof_c */

#if __STDC_VERSION__ >= 201112L && !defined(_ctypeof)
#define _ctypeof(_T) _Generic((_T), \
default: 'A', /* [DEFAULT/UNKNOWN] */ \
char: 'B', /* [CHAR] */ \
short: 'C', /* [SHORT] */ \
int: 'D', /* [INT] */ \
long: 'E', /* [LONG] */ \
long long: 'F', /* [X-LONG] */ \
unsigned char: 'G', /* [UNSIGNED-CHAR] */ \
unsigned short: 'H', /* [UNSIGNED-SHORT] */ \
unsigned int: 'I', /* [UNSIGNED-INT] */ \
unsigned long: 'J', /* [UNSIGNED-LONG] */ \
unsigned long long: 'K', /*[SIZE-T/UX-LONG] */ \
char*: 'L', /* [STRING-LITERAL/CHAR-PTR] */ \
short*: 'M', /* [SHORT-PTR] */ \
int*: 'N', /*[INT-PTR]*/ \
long*: 'O', /*[LONG-PTR]*/ \
long long*: 'P', /*[X-LONG-PTR]*/ \
void*: 'Q', /* [VAR/VOID-PTR] */ \
float: 'R', /* [FLOAT] */ \
double: 'S', /* [DOUBLE] */ \
long double: 'T', /* [LONG-DOUBLE] */ \
_Bool: 'U', /* [BOOLEAN] */ \
Random: 'V', /* [RANDOM] */ \
lostring: 'W', /* [LOW-STRING] */ \
mstring: 'X', /* [STRING] */ \
histring: 'Y', /* [HIGH-STRING] */ \
hihistring: 'Z' /* [ULTRA-HIGH-STRING] */ \
)
#endif /* second attempt of creating typeof_c */

#endif /* XSCCONF_USE_TYPEOF_3 != 1 */

#if XSCCONF_USE_TYPEOF_3 != 0 || !defined(_ctypeof)

#define STDB_TYPEOF_MODE3 1
#define XDB_USING_TYPEOFIII
//if i could only blend the two models together...
//what if type-of was available...?

#define __t_char ,
#define __t_short ,
#define __t_int ,
#define __t_long ,
#define __t_float ,
#define __t_double ,
#define __t_void ,
#define __t__Bool ,
#define __t_bool ,
#define __t_unsigned ,
#define __t_size_t ,
#define __t_uint8_t ,
#define __t_uint16_t ,
#define __t_uint32_t ,
#define __t_uint64_t ,
#define __t_int8_t ,
#define __t_int16_t,
#define __t_int32_t ,
#define __t_int64_t ,
#define __t_mstring ,
#define __t_lostring ,
#define __t_histring ,
#define __t_hihistring ,
#define __t_uchar ,
#define __t_ushort ,
#define __t_uint ,
#define __t_ulong ,
#define __t_uxlong ,
#define __t_xlong ,
#define __t_ubyte ,
#define __t_sbyte ,
#define __t_hex ,
#define __t_dword ,
#define __t_qword ,
#define __t_hex ,
#define __t_bin ,
#define __t_var ,
#define __t_ldouble ,

#ifdef _WINDOWS_
#define __t_DWORD ,
#endif
#ifndef __RPCNDR_H_VERSION__
#define __t_byte ,
#endif
#define __t_expand(...) __VA_ARGS__
#define __t_concat(_X) concat(__t_, _X)
#define __t_check(_X) __t_expand(__t_concat(_X) 1, 0)
#define __deref_t_imp(_, _X, ...) _X
#define __deref_t(...) __t_expand(__deref_t_imp(__VA_ARGS__, 0, ))
#define __t_is_type(_X) __deref_t(__t_check(_X))
#define __t_select(__res, _T, _is_x, _dt) concat(__THANDLE_, __res)(_T, _is_x, _dt)
#define __THANDLE_0(_T, _is_x, _dt) concat(__THANDLE_0_, _is_x)(_T, _dt)
#define __THANDLE_1(_T, _is_x, _dt) concat(__THANDLE_1_, _is_x)(_T, _dt)

#ifndef XSC_TOF3_MODEL
#define XSC_TOF3_MODEL 0

#ifdef typeof
#undef XSC_TOF3_MODEL
#define XSC_TOF3_MODEL 4
#endif
#endif

#if XSC_TOF3_MODEL == 0
/** USE BUILT-IN RECURSIVE MODEL. **/
/* p = pointer, f = float, i = int/short/long, ps = pointer-size, ll = long-long */
#define __THANDLE_0_u(_T, _NLL) ((*(int*)&_T = (((__len=_T)*0)-1) )*0) || ((_T <= 0)) &~ !(( (*(int*)&_T) = __len))*1
#define __THANDLE_1_u(_T, _NLL) !(((_T)-1) > 0)
#define __THANDLE_0_b(_T, _NLL) ((*(int*)&_T = (((__len=_T)*0)+2) )*0) || ((_T == 1)) &~ !(( (*(int*)&_T) = __len))*1
#define __THANDLE_1_b(_T, _NLL) (((_T)+2) < 2)
#define __THANDLE_0_f(_T, _ftype) __THANDLE_0_t(_T, _ftype)
#define __THANDLE_1_f(_T, _ftype) (((_T)+1.1) > 1) && sizeof(_T) == sizeof(_ftype)
/****/
#define __THANDLE_0_t(_T, _type) typecmp2(_T, _type)
#define __THANDLE_1_t(_T, _type) dtypecmp(_T, _type)

#define ctypeof_get(__type, _is_x, _dt) __t_select(__t_is_type(__type), __type, _is_x, _dt)
#define _ctypeof(_T)    sizeof(_T) == sizeof(lostring) ? 'W' : \
sizeof(_T) == sizeof(mstring) ? 'X' : \
sizeof(_T) == sizeof(histring) ? 'Y' : \
sizeof(_T) == sizeof(hihistring) ? 'Z' : \
ctypeof_get(_T, f, float) ? 'R' : \
ctypeof_get(_T, f, double) ? 'S' : \
ctypeof_get(_T, f, long double) ? 'T' : \
ctypeof_get(_T, t, unsigned short) ? 'H' : \
ctypeof_get(_T, t, unsigned int) ? 'I' : \
ctypeof_get(_T, t, unsigned long) ? 'J' : \
ctypeof_get(_T, t, unsigned long long) ? 'K' : \
ctypeof_get(_T, t, char) ? ctypeof_get(_T, u, 0) ? 'B' : ctypeof_get(_T, b, 0) ? 'U' : 'G' : \
ctypeof_get(_T, t, short) ? 'C' : \
ctypeof_get(_T, t, int) ? 'D' : \
ctypeof_get(_T, t, long) ? 'E' : \
ctypeof_get(_T, t, long long) ? 'F' : \
ctypeof_get(_T, t, char*) ? 'L' : \
ctypeof_get(_T, t, short*) ? 'M' : \
ctypeof_get(_T, t, int*) ? 'N' : \
ctypeof_get(_T, t, long*) ? 'O' : \
ctypeof_get(_T, t, long long*) ? 'P' : \
ctypeof_get(_T, t, void*) ? 'Q' : 'A'
#elif XSC_TOF3_MODEL == 1
/**USE BUILT-IN FLAT COMPARATIVE MODEL.**/
/**Description: (most portable yet worst model in developers opinion).**/
/*it sacrifices the ability to truly determine the type for the ability to accept both d-types and variables.*/

#define _ctypeof(_T) sizeof(_T) == sizeof(lostring) ? 'W' :  \
sizeof(_T) == sizeof(mstring) ? 'X' : \
sizeof(_T) == sizeof(histring) ? 'Y' : \
sizeof(_T) == sizeof(hihistring) ? 'Z' : \
sizeof(_T) == sizeof(float) && ( ((_T)+0 - ((int)(_T)+0)) > 0) ? 'R' : \
sizeof(_T) == sizeof(double) && ( ((_T)+0 - ((int)(_T)+0)) > 0) ? 'S' : \
sizeof(_T) == sizeof(long double) && ( ((_T)+0 - ((int)(_T)+0)) > 0) || sizeof(_T) == sizeof(long double) ? 'T' : \
sizeof(_T) == sizeof(char) ? (_T)+0 > 0x7F |~ !((_T)+0 - (_T)-1) > ((_T)+0 - (_T)-1) ? 'G' : ((_T)+2 == 1) ? 'U' : 'B' : \
sizeof(_T) == sizeof(short) ? (_T)+0 > 0x7FFF |~ !((_T)+0 - (_T)-1) > ((_T)+0 - (_T)-1) ? 'H' : 'C' : \
sizeof(_T) == sizeof(int) ? (_T)+0 > 0x7FFFFFFF |~ !((_T)+0 - (_T)-1) > ((_T)+0 - (_T)-1) ? 'I' : 'D' : \
sizeof(_T) == sizeof(long) ? (_T)+0 > 0x7FFFFFFF |~ !((_T)+0 - (_T)-1) > ((_T)+0 - (_T)-1) ? 'J' : 'E' : \
sizeof(_T) == sizeof(long long) ? (_T)+0 > 0x7FFFFFFFFFFFFFFF |~ !((_T)+0 - (_T)-1) > ((_T)+0 - (_T)-1) ? 'K' : \
((_T)+0 + 1) == (sizeof(short)) + ((int)(_T)+0) ? 'M' : \
((_T)+0 + 1) == (sizeof(int)) + ((int)(_T)+0) ? 'N' : \
((_T)+0 + 1) == (sizeof(long)) + ((int)(_T)+0) ? 'O' : \
((_T)+0 + 1) == (sizeof(long long)) + ((int)(_T)+0) ? 'P' : 'F' : 'A'
#elif XSC_TOF3_MODEL == 2
/**USE BUILT-IN AMBIGUOUS MODEL.**/
/**Description: (different from the other models, this one accepts more inputs but it has more difficulty in type identification).**/
#define typecmp3(_T, _t) sizeof(_T) == sizeof(_t)
#define _ctypeof(_T) \
typecmp3(_T, lostring) ? 'W' : \
typecmp3(_T, mstring) ? 'X' : \
typecmp3(_T, histring) ? 'Y' : \
typecmp3(_T, hihistring) ? 'Z' : \
typecmp3(_T, short*) && ((_T)+0 + 1) == (sizeof(short)) + ((int)(_T)+0) ? 'M' : \
typecmp3(_T, int*) && ((_T)+0 + 1) == (sizeof(int)) + ((int)(_T)+0) ? 'N' : \
typecmp3(_T, long*) && ((_T)+0 + 1) == (sizeof(long)) + ((int)(_T)+0) ? 'O' : \
typecmp3(_T, long long*) && ((_T)+0 + 1) == (sizeof(long long)) + ((int)(_T)+0) ? 'P' : \
typecmp3(_T, char) ? 'B' : \
typecmp3(_T, short) ? 'C' : \
typecmp3(_T, int) ? 'D' : \
typecmp3(_T, long) ? 'E' : \
typecmp3(_T, long long) ? 'F' : \
typecmp3(_T, unsigned char) ? 'G' : \
typecmp3(_T, unsigned short) ? 'H' : \
typecmp3(_T, unsigned int) ? 'I' :\
typecmp3(_T, unsigned long) ? 'J' : \
typecmp3(_T, unsigned long long) ? 'K' : \
typecmp3(_T, void*) ? 'Q' : \
typecmp3(_T, char*) ? 'L' : \
typecmp3(_T, float) ? 'R' :\
typecmp3(_T, double) ? 'S' :\
typecmp3(_T, long double) ? 'T' : 'A'
#elif XSC_TOF3_MODEL == 3
/**USE BUILT-IN ORIGINAL RECURSIVE MODEL.**/

#define __THANDLE_0_u(_T, _NLL) (((_T = ((__len = _T)*0) -1 ) <= 0 || (_T = __len) < 0))
#define __THANDLE_1_u(_T, _NLL) !(((_T)-1) > 0)
#define __THANDLE_0_p(_T, _NLL) (sizeof(_T) == sizeof(char*) && sizeof(*((_T) ? &_T : (char*)0)) == sizeof(char))
#define __THANDLE_1_p(_T, _NLL) 1
#define __THANDLE_0_b(_T, _NLL) (((_T = ((__len = _T)*0) +2 ) <= 1 || (_T = __len) < 0))
#define __THANDLE_1_b(_T, _NLL) !(((bool)+2) < 2)
#define __THANDLE_0_ps(_T, _dtype) (((int)(_T +1) - (int)_T) == sizeof(_dtype))
#define __THANDLE_1_ps(_T, _dtype) 1
#define __THANDLE_0_ll(_T, _NLL) (sizeof(_T) == sizeof(long long) && sizeof(*((_T) ? &_T : (long long*)0)) == sizeof(long long))
#define __THANDLE_1_ll(_T, _NLL) !(((_T)+0xFFFFFFFFFFFFFFFF) < 0xFFFFFFFFFFFFFFFF)
#define __THANDLE_0_f(_T, _ftype) ((sizeof(_T) == sizeof(_ftype) && sizeof(*((_T) ? &_T : (_ftype*)0)) == sizeof(_ftype)) || (sizeof(_T) == sizeof(void*) && sizeof(*((_T) ? &_T : (void*)0)) == sizeof(void)))
#define __THANDLE_1_f(_T, _ftype) (((_T)+1.111f) != 1)
#define __t_select(__res, _T, _is_x, _dt) concat(__THANDLE_, __res)(_T, _is_x, _dt)
#define ctypeof_get(__type, _is_x, _dt) __t_select(__t_is_type(__type), __type, _is_x, _dt)

#define _ctypeof(_T) sizeof(_T) == sizeof(lostring) ? 'W' : \
sizeof(_T) == sizeof(mstring) ? 'X' : \
sizeof(_T) == sizeof(histring) ? 'Y' : \
sizeof(_T) == sizeof(hihistring) ? 'Z' : \
sizeof(_T) == sizeof(float) && ctypeof_get(_T, f, float) ? 'R' : \
sizeof(_T) == sizeof(double) && ctypeof_get(_T, f, double) ? 'S' : \
sizeof(_T) == sizeof(long double) ? 'T' : \
sizeof(_T) == sizeof(bool) && ctypeof_get(_T, b, 0) ? 'U' : \
sizeof(_T) == sizeof(char) ? ctypeof_get(_T, u, 0) ? 'B' : 'G' : \
sizeof(_T) == sizeof(short) ? ctypeof_get(_T, u, 0) ? 'C' : 'H' : \
sizeof(_T) == sizeof(int) ? ctypeof_get(_T, u, 0) ? 'D' : 'I' : \
sizeof(_T) == sizeof(long) ? ctypeof_get(_T, u, 0) ? 'E' : 'J' : \
ctypeof_get(_T, ll, 0) ? ctypeof_get(_T, u, 0) ? 'F' : 'K' : \
ctypeof_get(_T, ps, char) ? 'L' : \
ctypeof_get(_T, ps, short) ? 'M' : \
ctypeof_get(_T, ps, int) ? 'N' : \
ctypeof_get(_T, ps, long) ? 'O' : \
ctypeof_get(_T, ps, long long) ? 'P' : 'A'
#elif XSC_TOF3_MODEL == 4
/**USE BUILT-IN COMPARATIVE MODEL WITH TYPEOF. **/
#define typecmp4(_T, _t) (sizeof(_T) == sizeof(_t) && (sizeof(*(0 ? (typeof(_T)*)0 : (typeof(_t)*)0)) == sizeof(_t)))
/* note: fix array issue. */
#define _ctypeof(_T) \
typecmp4(_T, lostring) ? 'W' : \
typecmp4(_T, mstring) ? 'X' : \
typecmp4(_T, histring) ? 'Y' : \
typecmp4(_T, hihistring) ? 'Z' : \
typecmp4(_T, short*) ? 'M' : \
typecmp4(_T, int*) ? 'N' : \
typecmp4(_T, long*) ? 'O' : \
typecmp4(_T, long long*) ? 'P' : \
typecmp4(_T, char) ? !(((typeof(_T))-1) > 0) ? 'B' : (((typeof(_T))+2) < 2) ? 'U' : 'G' : \
typecmp4(_T, short) ? 'C' : \
typecmp4(_T, int) ? 'D' : \
typecmp4(_T, long) ? 'E' : \
typecmp4(_T, long long) ? 'F' : \
typecmp4(_T, unsigned short) ? 'H' : \
typecmp4(_T, unsigned int) ? 'I' :\
typecmp4(_T, unsigned long) ? 'J' : \
typecmp4(_T, unsigned long long) ? 'K' : \
typecmp4(_T, void*) ? 'Q' : \
typecmp4(_T, char*) ? 'L' : \
typecmp4(_T, float) ? 'R' :\
typecmp4(_T, double) ? 'S' :\
typecmp4(_T, long double) ? 'T' : 'A'

#endif
#endif /* last attempt of creating typeof_c */

#if __STDC_VERSION__ >= 201112L

#define _KWP_AUTO_FMT(T)            \
_Generic(                    \
(T),                          \
default:            "%p[N/A]", \
char:               "%c",       \
short:              "%hd",       \
int:                "%i",         \
long:               "%ld",         \
long long:          "%lld",         \
unsigned char:      "%u",            \
unsigned short:     "%hu",            \
unsigned int:       "%u",              \
unsigned long:      "%lu",              \
unsigned long long: "%llu",              \
float:              "%f",                 \
double:             "%lf",                 \
long double:        "%Lf",                  \
_Bool:              "%d",                    \
char*:              "%s",                     \
short*:             "%p",                      \
int*:               "%p",                       \
long*:              "%p",                        \
long long*:         "%p",                         \
lostring:           "%s",                          \
mstring:             "%s",                           \
histring:           "%s",                            \
hihistring:         "%s",                             \
)

#endif /* first attempt of creating typeof_f */

#if !defined(_KWP_AUTO_FMT) && (COMPILER_ID == 1 || COMPILER_ID == 2)

#define _KWP_AUTO_FMT(T) __builtin_types_compatible_p(typeof(T), char) ? "%c" : \
__builtin_types_compatible_p(typeof(T), short) ? "%hd" : \
__builtin_types_compatible_p(typeof(T), int) ? "%i" : \
__builtin_types_compatible_p(typeof(T), long) ? "%ld" : \
__builtin_types_compatible_p(typeof(T), long long) ? "%lld" : \
__builtin_types_compatible_p(typeof(T), unsigned char) ? "%c" : \
__builtin_types_compatible_p(typeof(T), unsigned short) ? "%hu" : \
__builtin_types_compatible_p(typeof(T), unsigned int) ? "%u" : \
__builtin_types_compatible_p(typeof(T), unsigned long) ? "%lu" : \
__builtin_types_compatible_p(typeof(T), unsigned long long) ? "%llu" : \
__builtin_types_compatible_p(typeof(T), float) ? "%f" : /* DOESN'T WORK */ \
__builtin_types_compatible_p(typeof(T), double) ? "%lf" : \
__builtin_types_compatible_p(typeof(T), long double) ? "%Lf" : \
__builtin_types_compatible_p(typeof(T), _Bool) ? "%d" : \
__builtin_types_compatible_p(typeof(T), char*) ? "%s" : \
__builtin_types_compatible_p(typeof(T), short*) ? "%p" : \
__builtin_types_compatible_p(typeof(T), int*) ? "%p" : \
__builtin_types_compatible_p(typeof(T), long*) ? "%p" : \
__builtin_types_compatible_p(typeof(T), long long*) ? "%p" : \
__builtin_types_compatible_p(typeof(T), lostring) ? "%s" : \
__builtin_types_compatible_p(typeof(T), mstring) ? "%s" : \
__builtin_types_compatible_p(typeof(T), histring) ? "%s" : \
__builtin_types_compatible_p(typeof(T), hihistring) ? "%s" : "%p"

#endif /* second attempt of creating typeof_f */

#ifndef _KWP_AUTO_FMT
#define _KWP_AUTO_FMT(T) \
_ctypeof(T) == 'A' ? "%p[N/A]" : \
_ctypeof(T) == 'B' ? "%c" : \
_ctypeof(T) == 'C' ? "%hd" : \
_ctypeof(T) == 'D' ? "%i" : \
_ctypeof(T) == 'E' ? "%ld" : \
_ctypeof(T) == 'F' ? "%lld" : \
_ctypeof(T) == 'G' ? "%c" : \
_ctypeof(T) == 'H' ? "%hu" : \
_ctypeof(T) == 'I' ? "%u" : \
_ctypeof(T) == 'J' ? "%lu" : \
_ctypeof(T) == 'K' ? "%llu" : \
_ctypeof(T) == 'L' ? "%s" : \
_ctypeof(T) == 'M' ? "%p" : \
_ctypeof(T) == 'N' ? "%p" : \
_ctypeof(T) == 'O' ? "%p" : \
_ctypeof(T) == 'P' ? "%p" : \
_ctypeof(T) == 'Q' ? "%p" : \
_ctypeof(T) == 'R' ? "%f" : \
_ctypeof(T) == 'S' ? "%lf" : \
_ctypeof(T) == 'T' ? "%Lf" : \
_ctypeof(T) == 'U' ? "%d" : \
_ctypeof(T) == 'W' ? "%s" : \
_ctypeof(T) == 'X' ? "%s" : \
_ctypeof(T) == 'Y' ? "%s" : \
_ctypeof(T) == 'Z' ? "%s" : "%p"
#endif /* last attempt of creating typeof_f */

#define typeof_c(T) _ctypeof(T) /* //typeof - compare. */
#define typeof_i(T) typeof_c(T) - 'A' /* //typeof - integer. */
#define typeof_f(T) _KWP_AUTO_FMT(T) /* //typeof - format. */

#if 0

/* all the possible data type combos. */
/* some of these still need to be added. */

var A = ?;
char B = 0;
short C = 0;
int D = 0;
long E = 0L;
long long F = 0LL;

size_t G = 0LL;

float H = 0.0f;
double I = 0.0;
long double J = 0.0;

char* K = "";
short* L = 0;
int* M = 0;
long* N = 0L;
void* O = 0;

unsigned char P = 0;
unsigned short Q = 0;
unsigned int R = 0;
unsigned long S = 0L;
unsigned long long T = 0LL;

Random U;
bool V = false;
lostring W = "";
mstring X = "";
histring Y = "";
hihistring Z = "";

/* Missing:
-ubyte;
-sbyte;
-byte;
-long long int;
-long long int*;
-unsigned char*;
-unsigned short*;
-unsigned int*;
-unsigned long*;
-unsigned long long*;
-unsigned long long int*;
-size_t;
*/

#endif /* 0 */

#endif /* _STDB_TYPEOF_ */
