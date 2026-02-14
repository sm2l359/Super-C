#ifndef __RODATA_H__
#define __RODATA_H__

#ifdef __STDB_DEFINED
#include <super/stdbasic.h>
#endif


#if __INLINE_COMMENT__
//operations with string literals & RAM memory.

/**
    Package Name: rodata.h,
    stands for "rom-data".
    General Purpose Package? not quite;
    Child-Package? no;
    Experimental Package? no.
**/

    //<rodata.h> Standard Functions:
    //rommod() //modify the string literal.
    //romset() //set characters with string literal.
    //romcat() //concatenate string literal
    //romcpy() //copy string into string literal.
    //romasn() //rom assign,
    //rom = "reassignable"; //"modify" rodata.

    /* [NOTE] romasn -> rom assign. */
#endif
    /* allocation related tokens */
    #define alloc(_Data) calloc(_Data, 1)
    #define salloc(_Strg) malloc(_Strg * sizeof(char))
    #define scalloc(_Strg) calloc(_Strg, sizeof(char))
    #define allocate(_Data) malloc(_Data * sizeof *_Data) /* full name: Auto-Allocate */
    #define callocate(_Data) calloc(_Data, sizeof *_Data)
    /* allocation related functions */

xsc_notnull(1) xsc_forceinline
    void* strinit(char ** _Mem) {
        return (*_Mem = strdup(*_Mem));
    }

xsc_notnull(1)
    char* romasn(char * _Lit, char * _Repl) {
        /* this function is an alternative to malloc */
        /* that uses annoymous arrays (C99) to set */
        /* the string. */
    }

xsc_notnull(1)
    char* rommod(char * _Lit, size_t _Pos, char _Repl) {
        char* _Bkp = *_Lit;
        *_Lit += _Pos;
        //*_Lit = (char*)((char[]){_Lit});
        //char* _STR = (char*)((char[]){(char*)_Bkp, _Repl, (int*)_Lit});
        //*_Lit = (char*)((int*){(int*)_Bkp, _Repl, (int*)_Lit});
        *_Lit = (int[]){'a', 'b', 'c', '\0'};
        //*_Lit = _Bkp;
    }

xsc_notnull(1)
    char* romcat(char * _Lit, char * _Cat) {

        char* abc[2];
        _Lit = _Cat;

    }

xsc_notnull(1)
    char* romcpy(char * _Lit, char * _Repl) {
        //create another string
        //transfer the content to this string/
        //reassign.
        *_Lit = (char*)_Repl;
    }

#include <super/sub/stdcrt.h>

#endif /* __RODATA_H__ */
