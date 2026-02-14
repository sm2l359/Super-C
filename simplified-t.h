#ifndef _KWP_SIMPLIFIED_T_H
#define _KWP_SIMPLIFIED_T_H
#include <super/stdbasic.h>

/* child of 'kwpack.h' */

/**
    Header Name: simplified-t.h,
    stands for "simplified-types".
    General Purpose Package? yes;
    Child-Package? yes, independent;
        Parent-Package: "kwpack.h".
    Experimental Package? no.
**/

    _KWP_EXTENSION typedef unsigned char uchar;
    _KWP_EXTENSION typedef unsigned short ushort;
    _KWP_EXTENSION typedef unsigned int uint;
    _KWP_EXTENSION typedef unsigned long ulong;
    _KWP_EXTENSION typedef unsigned long long ullong;
    _KWP_EXTENSION typedef long long llong;
    _KWP_EXTENSION typedef long double ldouble;

    _KWP_EXTENSION typedef signed char schar; /* use these if you feel the need to identify/specify the types as signed. */
    _KWP_EXTENSION typedef signed short sshort;
    _KWP_EXTENSION typedef signed int sint;
    _KWP_EXTENSION typedef signed long slong;
    _KWP_EXTENSION typedef signed long long sllong;

/* Platform Exclusive (Api) */
#if XSC_OS == OsID_WINDOWS
_KWP_EXTENSION typedef CONSOLE_SCREEN_BUFFER_INFO WAP_BUFF_INFO;
#elif XSC_OS == OsID_LINUX
/** _KWP_EXTENSION typedef NCURSES_STUFF LINUX; //change later... **/
#elif XSC_OS == OsID_MAC
/** _KWP_EXTENSION typedef CONSOLE_SCREEN_BUFFER_INFO WAP_BUFF_INFO; //change later... **/
#endif

/* add more stuff in the future... */
/* add more finishing in the future... */

#include <super/sub/stdcrt.h>

#endif /* _KWP_SIMPLIFIED_T_H */
