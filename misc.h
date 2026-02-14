#ifndef __XSC_MISC1__
#define __XSC_MISC1__

#include <super/stdbasic.h>

/*
//in msm.h or misc.h will go all the features that are global platform compatible (C-Standard)

//that means:
//this header uses no compiler attributes, no platform exclusive features, only pure C-89
//standard or forward version features.
*/

/**
///Inside the C-Standards, this is the maximum you can get to a clear system that is
///Compatible with every single platform inside the standard.
**/

/** (R) - Special Purpose File.
*
*    - This Is a special Header File designed for specific utility purposes.
*      mostly being compatibility, ..., and developing useful functions
*      available for everyone.
*
*    > This file (misc.h) is a file intended to be fully compliant with the C-standard use little to no non-C features.
*      this file tends to GUARANTEE that it will run in any kind of Compiler/Version of C.
*
*    > All the contents you'll 'C' here are coded in C89 to enhance compatibility, performance, and
*      inheritance. some lines of code may look awkward due to some features that C89 doesn't port.
*
*    > Although this header is intended to be C-compliant, it still uses some macros and values which
*      port stuff that are not C related, however, these are nearly secured, overworked, and hardcoded
*      with the help of the preprocessor to guarantee compatibility either way, and the content linked
*      to it it's not C-incompatible at all, these are mostly workarounds to gather console information.
*
*   -FILE-NAME- : MISC.H
**/

/**
    Package Name: misc.h / "msm",
    stands for "miscellaneous".
    General Purpose Package? no;
    Child-Package? no;
    Experimental Package? no.
    Description: Cross-Compatible package.
**/

void pclear(int _Sz) { /* (stands for provisional clear) */

    if(_Sz == NULL) _Sz = __STDB_DEFCONSL_WIDTH;
    char* _shit;
    _shit = (char*)calloc(_Sz, sizeof(char));
    memset(_shit, VK_SPACE, _Sz);
    printf("\r%s\r", _shit);
    free(_shit);

}

/*
//[C][R]
//personal note: 1KB is entirely spent from this function, so attention on that one..
//yeah, varidic functions can be size expensive.
//thinking about removing / adapting this one.
*/

/* XSC "format" functions use '#' if there's no need to specify
    a "type" for the function.
*/

void concatf(String _SRC, ...)
{
    va_list _VA;
    va_start(_VA, _SRC);
    size_t _len;
    _len = strlen(_SRC);
    char* _STR;
    _STR = (char*)calloc(_len, sizeof(char));
    int I;
    int J;
    J = 0;
    for(I = 0; I < _len; ++I, ++J) {

        if(_SRC[I] == '#') {
            char* _vst;
            _vst = va_arg(_VA, char*);
            size_t _vst_l;
            _vst_l = strlen(_vst);

            strcat(_STR, _vst);
            J += _vst_l -1;
            _STR = (char*)realloc(_STR, _len + _vst_l +1);
            continue;
        }
        _STR[J] = _SRC[I];
    }
    strcpy(_SRC, _STR);
    free(_STR);
    va_end(_VA);
}

void tscan(void (* _runthread[2])(char), char _ext) /* thread scan */
{
    char C;
    C = 0;
    if(!_ext) _ext = 0x0D;
    for(;;) {
        _runthread[0](C);
        C = __STDB_GETCH;
        if(_ext == C) break;
        _runthread[1](C);
    }

}

/** ///// PASSWORD SECTION ///// **/

char* CharSet(const char * _CharSet);
void PassSet(const char * _ListSet[], unsigned short _Len);
void PassKill(const char * _PassCode);

#ifdef _TIME_H_ /* Process Speed Result */
time_t _misc_spd;
    #define __PSPD_RESULT printf("~%g Seconds taken.\n", (double)(clock() - _misc_spd) * 0.001)
#else
    #define __PSPD_RESULT (0)
#endif

char* __misc_CharList = "abcdefghijklmnopqrstuvwxyz1234567890";

char* __misc_PasswordList[] = {
                                "password",
                                "1234",
                                "pass123",
                                "password123",
                                "password1234",
                                "password12345",
                                };

char* CharSet(const char * _CharSet) {
    __misc_CharList = (char*)_CharSet;
}

void PassSet(const char * _ListSet[], unsigned short _Len) {
    int I;
    for(I = 0; I < _Len; ++I) {
        if(I > arrelm(__misc_PasswordList)) return;
        __misc_PasswordList[I] = _ListSet[I];
    }

}

void PassKill(const char * _PassCode) {

    if(_PassCode == NULL) {
        _PassCode = (char*)"example12345";
    }

    char* _CrackedCode;
    _CrackedCode = (char*)calloc(strlen(_PassCode), sizeof(char));

    size_t charset_len;
    charset_len = strlen(__misc_CharList);
    unsigned int _att;
    _att = 0;

    _misc_spd = clock();

    int _ListLen;
    _ListLen = arrelm(__misc_PasswordList);
    for(int I = 0; I < _ListLen; ++I) {
        if (!strcmp(__misc_PasswordList[I], _PassCode)) {
            printf("Password Debunked As: '%s' w/ the Password debunking algolrithm.\n", __misc_PasswordList[I]);
            return;
        }
    }

    _CrackedCode[0] = __misc_CharList[0];

    while(1) {

        ++_att;

        if (!strcmp(_CrackedCode, _PassCode)) {
            printf("Password Debunked As: '%s'\n", _CrackedCode);
            __PSPD_RESULT;
            printf("Done In: %i Attempts.\n", _att);
            return;
        }

        int I;
        I = strlen(_CrackedCode) - 1;

        while (I >= 0) {

            int _POS;
            _POS = strchr(__misc_CharList, _CrackedCode[I]) - __misc_CharList;

            if (_POS + 1 < charset_len) {
                _CrackedCode[I] = __misc_CharList[_POS + 1];
                break;
            }

            _CrackedCode[I] = __misc_CharList[0];
            --I;
        }

        if (I < 0) {
            memmove(_CrackedCode + 1, _CrackedCode, strlen(_CrackedCode) + 1);
            _CrackedCode[0] = __misc_CharList[0];
        }
    }
    free(_CrackedCode);

}

#endif /* __XSC_MISC1__ */
