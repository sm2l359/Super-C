#ifndef _ADVANCED_IO_
#define _ADVANCED_IO_
#define __IO 1

/**
    Library Name: file.io / file.h,
    stands for "file-in-out".
    General Purpose Library? yes;
    Child-Library? shared library; (this ends up as an independent package, even thought 'fadvance.h' uses this as a sub)
    Experimental Library? no.
**/

#include <super/stdbasic.h>
#include <stdio.h>

typedef char FileEditingMode[3];

struct XSC_FILE
{
    FileEditingMode Read, Write,
                    Append, Edit;
};

struct XSC_FILE File = { /* the functions will automatically turn the mode into binary if the file isn't a text. */
       .Read = "r",     .Write = "w",
     .Append = "a",      .Edit = "w+"
};

char fcopy(FILE* _F1, FILE* _F2)
{
    if(_F1 == 0x0) return 1;
    if(_F2 == 0x0) return 1;
    fseek(_F1, 0, SEEK_END);
    long  _SZ  = ftell(_F1);
    fseek(_F1, 0, SEEK_SET);
    char* _R = (char*)malloc(sizeof(char) * _SZ+1);
    fread (_R, _SZ, 1, _F1);
    fwrite(_R, _SZ, 1, _F2);
    free(_R);/* free memo */
    return 0;/* return  0 */
}

char sfput(char* _STR, FILE* _TAR)
{
    fseek(_TAR, 0, SEEK_END);
    long  _SZ  = ftell(_TAR);
    fseek(_TAR, 0, SEEK_SET);
    fread(_STR, _SZ, 1,_TAR);
}

char* fxread(char* _fname, size_t _Size)
{
    FILE* _File = fopen(_fname, "r");
    if(!_File) return ERR_5C004;

    if(!_Size)
    {
        fseek(_File, 0, SEEK_END);
        _Size = ftell(_File);
        rewind(_File);
    }

    char* _Buf = (char*) malloc(sizeof(char) * _Size +1);
    fread(_Buf, sizeof(char), _Size, _File);
    _Buf[_Size] = '\0';

    fclose(_File);
    return _Buf;
}

#define ins_back (amount) chprint(amount, '\b')
#define ins_space(amount) chprint(amount, ' ')
#include <super/s/stdcrt.h> /* libr.h, libcrc.h, libcheck.h... */

#endif /* _ADVANCED_IO_ */
