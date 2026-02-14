#ifndef _XSC_SCMATH

# if !defined(XSC_WIN) && !defined(MATH_LINKED) /* In Case Windows Is Not Being Used. */
# error ___________________________________________________
# error | Remember To Link the math Library with '-lm' in |
# error | Order To Work, when Finished, create a define   |
# error | called 'MATH_LINKED' and place it before this   |
# error | library or remove this section of the header.   |
# error ---------------------------------------------------
# endif

#define _XSC_SCMATH

/**
    Package Name: scmath.h / scmath,
    stands for "super-C math library".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

#include <super/stdbasic.h>

#ifndef _MATH_EXTENDED_DEFS_AND_CONSTANTS
#define _MATH_EXTENDED_DEFS_AND_CONSTANTS /* extended macros that are mostly not included in math.h */
#define M_PLANCK            6.62607015
#define M_2LOG10            3.32192809489
#define M_NAPIER            2.71828182845904523536
#define M_PI                3.14159265358979323846
#define M_E                 2.71828182845904523536 /* same as napier */
#define M_PYTHAGORAS        1.41421356237309504880
#define M_THEODORUS         1.73205080756887729352
#define M_ALPHA             0.00729927007299270072 /* (1 / 137) */
#define M_MYSTERY_CONSTANT  M_ALPHA
#define M_SQRT5             2.23606797749978969640
#define M_EULER_MASCHERONI  0.57721566490153286060
#define M_GOLDEN_RATIO      1.61803398874989484820
#define M_MILLS             1.30637788386308069046
#define M_OMEGA             0.56714329040978387299
#define M_FEIGENBAUM        4.66920160910299067185
#define M_APPERY            1.20205690315959428539
#define M_FIBONACCI         3.35988566624317755317
#define M_IMAGINARY_UNIT    sqrt(-1) /* placeholder macro. */
#endif

#if XSCCONF_CUSTOM_ATTRIBUTES >= ENABLED && XSCCONF_CUSTOM_SCMATH_ATTRIBUTES >= ENABLED
/* use it only when there's no horizontal space left. */
  #define __SCM_FASTCALL __attribs(xsc_noinline xsc_fastcall)

  #define __SCM_INLINE xsc_inline /* stuff that start with __X, are almost always compiler related. */
  #define __SCM_NOINLINE xsc_noinline
  #define __SCM_HOT xsc_hot
  #define __SCM_COLD xsc_cold
#else
  #define __SCM_FASTCALL

  #define __SCM_INLINE
  #define __SCM_NOINLINE
  #define __SCM_HOT
  #define __SCM_COLD
#endif

#if XSCCONF_CUSTOM_SECTIONS >= ENABLED
  #define __SCMATH __extpack(xscs_scmath)
#else
  #define __SCMATH
#endif


#if XSCCONF_EXCLUSIVE_HDR >= ENABLED
  typedef void scmath_void;
  typedef uint8_t scmath_bool;
  typedef int16_t scmath_int;
  typedef uint16_t scmath_uint;
  typedef int64_t scmath_llong;
  typedef uint64_t scmath_ullong;
  typedef double scmath_double;
#else
  #define scmath_void void
  #define scmath_bool uint8_t
  #define scmath_int int32_t
  #define scmath_uint uint32_t
  #define scmath_llong int64_t
  #define scmath_ullong uint64_t
  #define scmath_double double
#endif

/* i seriously wanted to make the scmath function name without the header specifier at the beginning. */
/* problem is that if i use there's gonna be function that are going to collide with the C standard library.
/* prep. -> func. -> struct */
/* so i decided that only the ones that already exist in scmath.h are gonna get the specifier. */

/*
//indirect definition area, where the stuff is going to be pre-implemented here.
//there's nothing much to say about it just that
//so that all the parameter stuff won't cause any flaws in the future;
//and the alternative versions of functions can be properly implemented.

//Order: data type > parameter count > code length (all of which are smallest to biggest)
    (if any) compiler keyword > data type > ...
    __SCMATH __SCM_FASTCALL scm_int scmath_unite(unsigned int _Array[], size_t _Size);

*/
    __SCMATH __SCM_NOINLINE scmath_ullong fact(double _Fact);
    __SCMATH __SCM_INLINE scmath_void cswap(int * a, int * b);
    __SCMATH              scmath_llong scmath_pow10(unsigned char _Exp);
    __SCMATH              scmath_int scmath_smartrand(size_t _Val_);
    __SCMATH              scmath_int ncount(int _Val);
    __SCMATH              scmath_void scmath_unite(unsigned int _Array[], unsigned int _Digit);
    __SCMATH              scmath_void scmath_sep(unsigned int _Array[], unsigned int _Digit);
    __SCMATH __SCM_INLINE scmath_void bsort(int * Array); /* Sorting Algorithm Section... */


/* non-original scmath features */
    float fisqrt(float _N); /* fast inverse square root */

/*
//direct implementation area. / declaration-implementation area. / inline functions area.
//Organize Order: data_type > parameter count > code length (all of which are smallest to biggest)
//if there's two or more compiler keywords: 'compiler keyword > data_type (...)'
*/
#if XSC_LMODE <= DISABLED
    __SCMATH __SCM_INLINE scmath_bool scmath_isFloating(double _Val){ return !(_Val - (int) _Val) == 0.0; }
    __SCMATH __SCM_INLINE scmath_int scmath_sign(size_t _Number) { return -_Number; }
    __SCMATH __SCM_INLINE scmath_int scmath_round(double _Val_) { return (int)(((int)(_Val_ + 1) - _Val_) * 10) >= 5 ? (int)_Val_ : (int)(_Val_ + 1); }
    __SCMATH              scmath_int scmath_decrease(int _Number, int _Chars){ return (_Chars > -1) ? _Number / scmath_pow10(_Chars) : _Number % (int)scmath_pow10(-_Chars); }
    __SCMATH              scmath_int scmath_selectdigit(int _Number, int _Pos) { return scmath_decrease(_Number, _Pos * (-1)) / scmath_pow10(_Pos -1); }
    __SCMATH __SCM_INLINE scmath_int __qsort__(void * _a, void * _b) { return (*(int*) _a - *(int*) _b); } /* sorting section.. */
#endif

/*
//Other Algorithms Go Here Later...
*/

/*
    rules for parameters:
    1 ->
    modification - _Number_ / comparison - _Val_
    if the function includes a section that has a syntax that contradicts the '_'
    ex: "-_Par", it should be done "-Par_" instead of "_Par".
    2 ->
    Doesn't use return - One Line = fastcall (Max. 2 Lines)
    Uses return - One Line = inline
    Uses return - > One Line = fastcall
    3 ->
    rules for the implementation areas:
    if it the function uses return and is one line only it goes into the direct section.
    if it doesn't uses return and/or has more than one line, it goes directly to the indirect section.
*/

/*
//indirect implementation area. / implementation area.

//there's no need to be signed, since all the work it demands
//to get the negative factorial is just flipping the bit.
*/

    /* when working with number/math related parameters,
    always use these names:
        _Base, _Exp, _Number, _Digit, _Size, _Count
        etc...

    */

    scmath_ullong fact(double _Base) {
        return (!!_Base) ? _Base * fact(_Base - 1) : 1;
    }


    /* Note: when working with data in Assembly
        always remember to either use eax for
        it's speed abilities or rax for size
        compatibility, use only ax, ah and al
        for size matching purposes but even
            then it's more recommended to
             use eax, all of the time.
    */
    #if XSCCONF_SHARED >= ENABLED
        scmath_void cswap(int * a, int * b) {
            #if COMPILER_ID == ID_GCC
            __asm__ volatile(
                "xchg %0, %1"
                : "+r"(*a), "+r"(*b)
            );
            #else
            *a ^= *b ^= *a ^= *b;
            #endif
        }
    #else
        scmath_void cswap(int * a, int * b) {
            __sh_len_ = *a;
            *a = *b;
            *b = __sh_len_;
        }
    #endif

        #define XCLLM_MODEL_FASTPOW10 1
    #if XCLLM_MODEL_FASTPOW10 <= DISABLED /* version that (SUPPOSEDLY) was more optimized than the rest. */
        scmath_llong scmath_fastpow10(unsigned char _Val) {
            if(_Val > 10 && _Val < 17) {
                uint64_t _table[4] = {100000000000LL,
                                        1000000000000LL,
                                         10000000000000LL,
                                          100000000000000LL
                                        };

                if(_Val > 14) { /* this was most likely ignored somehow, or i didn't compiled the thing.. */
                    if(_Val == 15) _table[3] *= 10;
                    if(_Val == 16) _table[3] *= 100;
                    return _table[3];
                }
                return _table[_Val - 11];

            }
            return exp2((double)_Val * M_2LOG10);
        }
    #else /* Model 2: logarithmic approximation */
        scmath_llong scmath_pow10(unsigned char _Exp) {
            if(_Exp > 10 && _Exp < 17) {
                uint64_t _table[4] = {100000000000LL,
                                        1000000000000LL,
                                         10000000000000LL,
                                          100000000000000LL
                                        };
                if(_Exp == 15) return _table[3] * 10;
                if(_Exp == 16) return _table[3] * 100;
                return _table[_Exp - 11];

            }
            return exp2((double)_Exp * M_2LOG10);
        }
    #endif

    scmath_int scmath_cut(size_t _Val_, unsigned int _Beg, unsigned int _End) {
        /* replace with fast_exp10() later */
        /* optimize this function later */

        size_t _exp = scmath_pow10(_Beg);
        _Val_ = _Val_ / _exp;
        _exp = scmath_pow10(_End);
        _Beg = (_Val_ / _exp) * _exp;
        return _Val_ - _Beg;
    }

    scmath_int scmath_smartrand(size_t _Val_) {
        return _Val_;
    }

    scmath_int ncount(int _Val) { /* unfinished */
        double _Ctr = _Val;
        uint _Res = 0;
        _Ctr = _Val * 0.0001; /* x / 10000 */
        if (_Ctr < 0) {
            _Res = 5;
            _Val *= 0;
        } else {
            _Res = 6;
        }

        return _Val;
    }

    scmath_void scmath_unite(unsigned int _Array[], unsigned int _Digit) { /* [ALT] _Digits, _Digitws [NIP] */
        uint32_t _Unite = 0;
        uint32_t _Pow = 0;

        for(int I = 0; I < _Digit; ++I) {
            _Unite = _Unite + _Array[I];
            _Unite *= 10;
        }

        _Unite *= 0.1f;

        return _Unite;
    }

    scmath_void scmath_sep(unsigned int _Array[], unsigned int _Digit) {
        uint32_t _Pow = 1;
        uint32_t _N = 0;

        while(_Digit > _Pow) {
            _Pow *= 10;
            ++_N;
        }

        for(int I = 0; I < _N; ++I) {
            _Pow = _Pow * 0.1f;
            _Array[I] = _Digit / _Pow;
            _Digit = _Digit - (_Array[I] * _Pow);

        }

    }

    scmath_int bsort(int * _Array) {

    }

float fisqrt(float _N)
{
    const float _3h = 1.5f;
    float Z, Y;
    long I;
      Y = _N;
      Z = _N * 0.5f;

      I = *(long*) &Y;
      I = 0x5f3759df - (I >> 1);
      Y = *(float*) &I;

      Y = Y * (_3h - (Z * Y * Y));
      Y = Y * (_3h - (Z * Y * Y));
    return Y;
}

#if 0
typedef struct XSCMATH {
    double pi;
    double sqrt2;
    double sqrt1_2;
    double e;
    int pi_accurancy; //to be removed...
    uint rseed;
    ushort sortSize;
    //scRandom (*random)(Random);
    #if XSC_LMODE == 1
    void (*swap)(),
         (*sort)(),
         (*remove)(),
         (*arrset)(),
         (*unsort)(),
         (*sep)();
    double (*fdecrease)(),
           (*sin)(),
           (*cos)(),
           (*pow)(),
           (*root)(),
           (*pigen)();
    int (*count)(),
        (*decrease)(),
        (*selectDigit)(),
        (*selectDigits)(),
        (*alt)(),
        (*round)(),
        (*unite)(),
        (*factorial)();
    #endif
    /* SCM_INI Init; */
}
#endif

#ifdef _NON_SCMATH /* alternative spellings for the common math operations. */
#   define root(b, e) _scmath_root_(b, e)
#   define fact(N) _scmath_fact_(N)
#endif

#include <super/sub/stdcrt.h>

#endif /* _XSC_SCMATH */
