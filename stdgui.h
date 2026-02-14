#ifndef __STDGUI__ /* [ONF] */
#define __STDGUI__
#include <super/stdbasic.h>

/**
    Package Name: stdgui.h,
    stands for "Standard Graphical User Interface".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
    Description: In-Development [INV]
**/

/*
    Bit1 - Visibility.
    Bit2 - SizeState. [Minimized/Maximized]
    Bit3 - NotStandardState. [if 1 means that it's either minimized/maximized]
    Bit4 = MinimizeBtnEnabled.
    Bit5 = MaximizeBtnEnabled.
    Bit6 - IsFocused.
    Bit7 - Resizable.
    Bit8 - IsDialog.
    //IsDialog makes the window hidden in taskBar by default.
    //also the developer IS NOT going to add an "ShowInTaskBar" mode.
    //there's no need to have a showInTaskBar feature at all. reason:
    //theres no reason to even have an option like this for somebody, unless
    //this person actually does have the intention of developing a malicious
    //program using that feature;
    //so i decided to discard it. it's just a no-go.
*/

typedef struct _ggin { /* _ggin = global graphical interface */
    char* Title;
    size_t ApiClass; /* Equivalent to "WINCLASS wc" in "windows.h", stores the Window Class. */
    struct _giSize {uint W; uint H; } Size;
    struct _giPosition {int X; int Y; } Position;
    uint8_t State; /* every bit represents a different window state; 00000001 = Visible 00000000 = Hidden. */
} GUI; /* User Interface Main */

#if XSC_OS == OsID_WINDOWS

typedef struct _apimain { /* API reserved */

    /* Global Values */
    char* _iobffr;
    int _cmnd_listsize;
    int* _list_pos;
    GUI* _interface;

    /* OS-Defined Values */
    WNDCLASS _wc;
    HWND _selectedWHandler;
    HANDLE _outputHandler;
    HINSTANCE _hinst;
    LPPOINT _lp;


} API; /* used for more internalized, reserved stuff from the insider user data. */
/* API is for more internal, reserved values for the OS only. */
/* [ALT] STDGUIAPI, STDAPI, STDWINAPI */
#elif XSC_OS == OsID_LINUX

typedef struct _apimain {

    /* Global Values */
    char* _iobffr;
    int _cmnd_listsize;
    int* _list_pos;
    GUI* _interface;

    /* OS-Defined Values */


} API;

#elif XSC_OS == OsID_MAC

typedef struct _apimain {

    /* Global Values */
    char* _iobffr;
    int _cmnd_listsize;
    int* _list_pos;
    GUI* _interface;

    /* OS-Defined Values */


} API;


#else

typedef struct _applmain { /* API reserved */

    /* Global Values */
    char* _iobffr;
    int _cmnd_listsize;
    int* _list_pos;
    GUI* _interface;

    /* OS-Defined Values */


} _APP;

#define API _APP

#endif

#if __STDC_VERSION__ < CC99
#define __NOT_USING_C99_INL
#endif

#ifdef __NOT_USING_C99_INL
#define _C99_INL xsc_inline
#else
#define _C99_INL inline
#endif

/* __xsc_notnull(1) */
__xsc_attribs(xsc_notnull(1) xsc_hot) int gprintf(API* _Gui, const char * _Commands, ...);

/* temp. just for testing */
API* __stdg; /* = {0,0,0,0,0,0,0,0}; */

#define stdgui __stdg

#if LANG_VERSION < CC99
  GUI Application = {NULL, NULL, NULL, NULL};
#else
  GUI Application = {0};
#endif

    #define __stdg_inline _C99_INL /* [NCS] */
#if COMPILER_ID == ID_UNKNOWN
    #define __stdg_discard
#else
    #define __stdg_discard __stdg_inline xsc_unused
#endif

#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__) /* [NCS] */
#pragma GCC push_options
 #   pragma GCC optimize("03")
 #   pragma GCC debug("off")
#endif

#if COMPILER_ID == ID_MSVC
#pragma optimize( "t", on )
#pragma optimize( "g", on )
#endif

/* [REM] small helper functions go here. */

__stdg_inline __gprintf_get_identf(API* _stdg)
    { return (*(_stdg->_iobffr) == '%') && (*(_stdg->_iobffr + 1) != '%'); }

/* [KILL] */
__stdg_discard __gprintf_platform_orgn(API* _stdg) {

    /* exclusive platform related stuff go here. */

    #if XSC_OS == OsID_WINDOWS /* Windows Section */

    _stdg->_lp = NULL;
    _stdg->_hinst = NULL;
    /* ... */

}

    #elif XSC_OS == OsID_LINUX /* Linux Section */

}

    #elif XSC_OS == OsID_MAC /* Mac Section */

}

    #else

}

    #endif

#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#pragma GCC pop_options /* [NCS] */
#endif

#if COMPILER_ID == ID_MSVC
#pragma optimize( "", on )
#endif

/* TODO: probably will change this to gprintg in 1.5 */
int gprintf(API* _Gui, const char * _Commands, ...) {

    va_list _VA;

    #if LANG_VERSION >= CC99
    if(strncmp(_Commands, "%V", 2) == 0) {
        va_start(_VA, 1);
        va_copy(_VA, va_arg(_VA, va_list));
        va_end(_VA);
    }
    va_start(_VA, _Commands);
    #endif

    int __list_size = 4;
    uint __iopos = 0; /* [OPT], should try to remove this later */
    __stdg = calloc(1, sizeof(API));
    __stdg->_iobffr = strdup(_Commands);/*(char*)malloc(__stdg->_iobffr * sizeof(API));*/
    __stdg->_list_pos = calloc(__list_size, sizeof *__stdg->_list_pos);


    while(*(__stdg->_iobffr) != '\0') {
        if((__gprintf_get_identf(__stdg))) {
            __stdg->_list_pos[__stdg->_cmnd_listsize] = __iopos;
            __stdg->_cmnd_listsize++;

            if(__list_size < __stdg->_cmnd_listsize) {
                __list_size *= 2;
                __stdg->_list_pos = realloc(__stdg->_list_pos, __list_size * sizeof *__stdg->_list_pos);
            }

        }
        __stdg->_iobffr++;
        __iopos++;

    }

    /*__gprintf_platform_orgn(&_Gui)*/

    /* Note: remember to cast to (uintptr_t) */

    printf("work in progress.. %i", __stdg->_list_pos[7]);
}


int printg(const char * _Cmnds, ...) {
    va_list _VA;
    va_start(_VA, _Cmnds);
    gprintf(stdgui, _Cmnds, _VA);
    va_end(_VA);
}


int gclose(API* _CloseGUI) {
    if(_CloseGUI == NULL) {
        free(__stdg);
    } else {
        free(_CloseGUI);
    }
}

#if 0
stdgui GetWinCursorPosition()
{
    #ifdef _WINDOWS_
    GetCursorPos(&_lp);
    WCURX = _lp.x;
    WCURY = _lp.y;
    #endif
}
#endif

#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#pragma GCC pop_options
#endif /* added an extra pop at the end in case of using another pragma. */

#if COMPILER_ID == ID_MSVC
#pragma optimize( "", on )
#endif /* added an extra pop at the end in case of using another pragma. */

#include <super/sub/stdcrt.h>
#endif /* __STDGUI__ */
