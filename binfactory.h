#ifndef _XSC_BINARY_FUNCTIONS /* Operations with Binary Types. */

/* here will go the warnings, the signs, the setups of the file, etc... */
#ifndef __KWPACK__
#warning Please, include "kwpack.h" in order to use "bFactory.h".
#else

#define _XSC_BINARY_FUNCTIONS
#define _XSC_BINARYFUNCTIONS /* [ALT] */

#include <super/stdbasic.h>

#line 14 "[binfactory]"

/**
    Package Name: binfactory.h / BinFactory.h / binary.h,
    stands for "Binary Factory".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

bin binFactory(sint _Val, _Bool _Arr[], sint _bSize);
inline int GetBit(size_t _Val, unsigned int _BitPos);
inline int SetBit(size_t _Val, unsigned int _BitPos);

/* The Key Purpose of this function is to allow conversion between Binary and integer Arrays. */
bin binFactory(sint _Val, _Bool _Arr[], sint _bSize) {
    if(_bSize > 0) { /* To Integer */
        _Val = 0;
        for (int I = 0; I < _bSize; ++I)
            { _Val = (_Val << 1) | _Arr[I]; }
        return _Val;
    } else { /* To Binary */
        _bSize *= (-1);
        for (int I = _bSize - 1; I >= 0; --I, _Val >>= 1)
            { _Arr[I] = _Val & 1; }
    }
}

inline int GetBit(size_t _Val, unsigned int _BitPos) {
    return (_Val >> _BitPos) & 1;
}

inline int SetBit(size_t _Val, unsigned int _BitPos) {
    return _Val | (1 << _BitPos);
}

#if COMPILER_GCCCLANG == FALSE

uint32_t BinRev(uint32_t _Bin) {
    _Bin = ((_Bin >> 1) & 0x55555555) | ((_Bin & 0x55555555) << 1);
    _Bin = ((_Bin >> 2) & 0x33333333) | ((_Bin & 0x33333333) << 2);
    _Bin = ((_Bin >> 4) & 0x0F0F0F0F) | ((_Bin & 0x0F0F0F0F) << 4);
    _Bin = ((_Bin >> 8) & 0x00FF00FF) | ((_Bin & 0x00FF00FF) << 8);
    _Bin = (_Bin >> 16) | (_Bin << 16);
    return _Bin;
}

uint64_t BinRev64(uint64_t _Bin) {
    _Bin = ((_Bin >> 1)  & 0x5555555555555555ULL) | ((_Bin & 0x5555555555555555ULL) << 1);
    _Bin = ((_Bin >> 2)  & 0x3333333333333333ULL) | ((_Bin & 0x3333333333333333ULL) << 2);
    _Bin = ((_Bin >> 4)  & 0x0F0F0F0F0F0F0F0FULL) | ((_Bin & 0x0F0F0F0F0F0F0F0FULL) << 4);
    _Bin = ((_Bin >> 8)  & 0x00FF00FF00FF00FFULL) | ((_Bin & 0x00FF00FF00FF00FFULL) << 8);
    _Bin = ((_Bin >> 16) & 0x0000FFFF0000FFFFULL) | ((_Bin & 0x0000FFFF0000FFFFULL) << 16);
    _Bin = (_Bin >> 32) | (_Bin << 32);
    return _Bin;
}

int popcount(int32_t _Bin) {
    int _Res = 0;
    for(int I = 0; I < (sizeof(int32_t) * 8); ++I) {
        _Res = _Res + ((_Bin >>= 1) & 1);
    }
    return _Res;
}

int popcount64(int64_t _Bin) {
    int _Res = 0;
    for(int I = 0; I < (sizeof(int64_t) * 8); ++I) {
        _Res = _Res + ((_Bin >>= 1) & 1);
    }
    return _Res;
}

#else

uint32_t BinRev(uint32_t _Bin) {
    uint64_t _Res = __builtin_bitreverse32(_Bin);
    return _Res;
}

uint64_t BinRev64(uint64_t _Bin) {
    uint64_t _Res = __builtin_bitreverse64(_Bin);
    return _Res;
}

int popcount(int32_t _Bin) {
    return __builtin_popcount(_Bin);
}

int popcount64(int64_t _Bin) {
    return __builtin_popcountll(_Bin);
}

#endif

#include <super/sub/stdcrt.h>

#endif /* __KWPACK__ */
#endif /* _XSC_BINARY_FUNCTIONS */

