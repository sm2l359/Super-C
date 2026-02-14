#ifndef _F_ADVANCE_
#define _F_ADVANCE_

/**
    Package Name: fadavance.h / f_advance / advancedf,
    stands for "advanced format system".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? yes.
**/

#include <stdio.h>
#include <super/file.io>
#include <super/version.h>

/* [INV] */
#if 0
#define ConvertTo(_Return, _Input) convf(typeof_f(_Input), _New_Fmt, _Input)
void* convf(char Current_Format[4], char New_Format[4], ...)
{
    va_list V;
    va_start(V, 1);
    const void* _BUF_GEN = va_arg(V, const void*);


    if(!strcmp(Current_Fmt, "%s"))
    {
        return
            (!strcmp(Return_Fmt, "%i")) ? strtol(_BUF_GEN, NULL, 10) :
            (!strcmp(Return_Fmt, "%b")) ? strtol(_BUF_GEN, NULL, 02) :
            (!strcasecmp(Return_Fmt, "%X")) ? strtol(_BUF_GEN, NULL, 16) :
            (!strcmp(Return_Fmt, "%c")) ? *(char*) _BUF_GEN :
                                          strtol(_BUF_GEN, NULL, 10);
            if(!strcmp(Return_Fmt, "%f") || !strcmp(Return_Fmt, "%g"))
            {

            }
    }
    else if(!strcmp(Current_Fmt, "%b"))
    {

    }
    else if(!strcmp(Current_Fmt, "%c"))
    {

    }
    va_end(V);
}
#endif

#endif
