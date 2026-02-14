#ifndef __STRINGS_H
#define __STRINGS_H
#include <super/stdbasic.h>

#line 6 "[strings.h]"

/**
    Package Name: strings.h,
    stands for "C Strings".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? mostly-yes.
**/

/* Optimization Choice in case size is really something to worry about. */
#if XSCCONF_NORETURN <= DISABLED
#define __RETURN_T char*
#else
#define __RETURN_T void
#endif

#if XSCCONF_EXCLUSIVE_HDR >= ENABLED
typedef __RETURN_T strings;
#else
#define strings __RETURN_T
#endif

#if XSCCONF_EXCLUSIVE_HDR >= ENABLED
    typedef bool strings_bool;
    typedef char strings_char;
    typedef short strings_short;
    typedef int strings_int;
    typedef size_t strings_size;
#else
#define strings_bool bool
#define strings_char char
#define strings_short short
#define strings_int int
#define strings_size size_t
#endif

/* order ->  function & it's variations -> data type (must match next function set) */
strings strg_adds(String _SRC_, int _POS, const String _STRG); /* [NIP] (const cchar*) */
strings strg_add(String _Src, uint _POS, ubyte _CHAR, ushort _amount);
strings strrem_s(String _STR, String _SUB);
strings strnrem(String _STRG, uint _POS, uint _COUNT);
strings_char strrem(String _STRG, uint _POS);
strings_bool strg_cmpat(const String STR_1, const String STR_2, uint _POS);

/* inline directives. */
xsc_forceline strings strclear(String _TAR) { memset(_TAR, '\0', strlen(_TAR)); } /* use it when working with: mem--- and strn--- family. (any function that works via manual input.) */
xsc_forceline strings strreset(String _TAR) { _TAR[0] = '\0'; } /* safe to use with any function null terminator based. (reads until reaches '\0') */

/* [NOTE] speed results: ~0.0003 */
#ifndef __STRINGS_H_CHP_DEFINED
void chprint(unsigned short _size, unsigned char _CHR)
{
    char* _strset = (char*)calloc(_size, sizeof(char));
    memset(_strset, _CHR, _size);
    printf("%s", _strset);
    free(_strset);
}
#endif

strings strg_adds(String _SRC_, int _POS, const String _STRG)
{
#define __len __sh_len_
#if XSCSET_MODE <= 0 /* 0 and lower... (optim.:std-mode) */
      _shared_t __len = strlen(_STRG);
#define SRC_P_POS _SRC_+_POS
#elif XSCSET_MODE == 1 /* 1 (optim.:size-mode) */
#define SRC_P_POS _SRC_+_POS
#undef __len
#define __len strlen(_STRG)
#elif XSCSET_MODE >= 2 /* 2 and above... (optim.:speed-mode) */
      _shared_t __len = strlen(_STRG);
      const int SRC_P_POS = _SRC_+_POS;
#endif


    memmove(SRC_P_POS + __len, SRC_P_POS, strlen(_SRC_) - _POS +1);
    memcpy(SRC_P_POS, _STRG, __len);

#undef SRC_P_POS
#undef __len

    __stdb_return(_SRC_);
}

strings strg_add(String _Src, uint _POS, ubyte _CHAR, ushort _amount)
{
#if XSCSET_MODE == XSCPROP_SPEED
      const uint SRC_P_POS = _Src + _POS;
#else
#define SRC_P_POS _Src + _POS
#endif
    memmove(SRC_P_POS + _amount, SRC_P_POS, strlen(_Src) - _POS + _amount);
    memset(SRC_P_POS, _CHAR, _amount);
#undef SRC_P_POS
    __stdb_return(_Src);
}

xsc_forceline strings_char strrem(String _STRG, uint _POS)
{
    strcpy(_STRG + _POS, _STRG + _POS +1);
    __xsc_return _STRG[_POS];
}

strings strrem_s(String restrict _STR, String restrict _SUB) /* cannot refer to itself in calling. */
{
    _shared_t __sh_len_ = strlen(_SUB);
    while ((_STR = strstr(_STR, _SUB))) {
        memmove(_STR, _STR + __sh_len_, strlen(_STR + __sh_len_) + 1);
    }
    __stdb_return(_STR);
}

strings strnrem(String _STRG, uint _POS, uint _COUNT)
{
    memmove(&_STRG[_POS], &_STRG[_POS + _COUNT], strlen(_STRG) - _POS - _COUNT + 1);
    __stdb_return(_STRG);
}

xsc_inline
strings_bool strg_cmpat(const String STR_1, const String STR_2, uint _POS)
{
    return !strncmp(STR_1 + _POS, STR_2, strlen(STR_2));
}

strings_int chrcount(String _TXT, sbyte _TAR)
{
    uint16_t _COUNTR = 0;

    while(* _TXT != '\0')
    {
        if(* _TXT == _TAR) ++_COUNTR;
        ++_TXT;
    }

    return (int)_COUNTR;
}

strings_int wrdcount(String _TXT, sbyte _WORD)
{
    uint16_t _COUNTR = 0;

    while(* _TXT != '\0')
    {
        if(* _TXT == _WORD) ++_COUNTR;
        ++_TXT;
    }

    return (int)_COUNTR;
}

/* directives area. */
#define strlcpy(_Str, _Dest) (_Str = (char*)_Dest)
/* (Undefine) Directives area. */
#undef __RETURN_T
#undef strings

#include <super/sub/stdcrt.h>

#endif /* __STRINGS_H */
