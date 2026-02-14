#ifndef __PLATFORM_STANDARD
#define __PLATFORM_STANDARD __extpak(xsc_section(".platspec"))
#line 4 "[pltstd.h]"

#define __PLATFORM_STAND __PLATFORM_STANDARD /* insert some extra platform attribute here later */

#include <super/stdbasic.h>

/** (R) - This File Is Partially Safe For Use.
*
*    -This File Is Not Completely Compatible With The C Language Nor
*     The Library(C):
*
*    > this Header contains features that are not completely compatible
*      with the Standard C Library, and are exclusive to your platform.
*
*    > As a Result, the content of this File Cannot be fully used to it's
*      maximum capacity and may even cause flaws, errors and bugs to the main source.
*                             _
*    > You Have Been Warned! /!\
*
*   -FILE-NAME- : PLTSTD.H
**/

/**
    Package Name: pltstd.h / "platstd",
    stands for "platform-standard".
    General Purpose Package? no;
    Child-Package? no;
    Experimental Package? no.
    Description: Library features exclusive to your platform only.
**/

#if defined(XSC_WINDOWS)

                    mswin();
    __PLATOFORM_STAND putnl(const char* _Str);
                      regdl(char* _Key);
                      regwt(const char* _Key, const char* _Val, const char* _Mode);

#elif defined(XSC_LINUX)

#elif defined(XSC_MAC)

#endif

#ifdef XSC_WINDOWS
    __PLATFORM_STANDARD DWORD mswin() { /* Gets the Windows OS, ex: XP, 7, 8, 10, 11... */
        /* [INV] returns the windows Version OS */
    }

    DWORD putnl(const char* _Str) {
        DWORD _len = (DWORD)strlen(_Str);
        HANDLE _hstd = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD _writr = NULL;
        WriteFile(_hstd, _Str, _len, &_writr, NULL);
        return _writr;
    }

    __PLATFORM_STANDARD DWORD regdl(char* _Key) {

    }

    __PLATFORM_STANDARD DWORD regwt(char* _Key, const char* _Val, const char* _Mode) { /* works exactly the same as FILE* */
        /* modes:
            w
            r
            wb
            rb
        */
    }
#endif

/* [ALT] stdclp.h, libclt.h, libclt.h, libclp.h */
#include <super/sub/stdcrt.h>
#endif /* __PLATFORM_STANDARD */
