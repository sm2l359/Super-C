/**
    Package Name: stdcrt.h,
    stands for "standard cleanup routine".
    General Purpose Package? yes;
    Child-Package? yes;
        Parent-Package: *;
    Experimental Package? no.
**/

/* this file will appear at the end of almost every file from the SuperC
   Library to perform cleanup involving the kwpack.h header file. */

/*
   //currently this file is being used only to remove the placeHolder directives with kwpack.
   //however, it can be used for pretty much every single purpose that would require some
   //kind of intervention in the end of every file of the SuperC Library.
*/

#ifdef __KWPACK__ /* undefine placeholder Definitions to prevent Incompatibility with "kwpack.h". */
#undef String
#undef string
#undef lostring
#undef mstring
#undef ustring
#undef histring
#undef hihistring
#undef ubyte
#undef sbyte
#undef uchar
#undef ushort
#undef uint
#undef ulong
#undef xlong long long
#undef uxlong unsigned long long
#endif

#ifndef _STDINT_H
#undef uint8_t
#undef uint16_t
#undef uint32_t
#undef uint64_t
#undef int8_t
#undef int16_t
#undef int32_t
#undef int64_t
#endif

#if (defined(__COMPLETE_DEBUGGING) && !defined(__INCOMPLETE_DEBUGGING)) || (defined(__INCOMPLETE_DEBUGGING) && defined(XSC_DEBUG_BY_DBG)) && \
            !defined(XSC_DEBUG_UNDISPLAYABLE)
#line 51 "[DEBUG-ERROR]"
#if XSCSET_NO_DEBUG_ORDER == 0 || !defined(XSCSET_NO_DEBUG_ORDER)
#error you need to activate debug after the other headers are included
#error otherwise their conditions cannot be displayed. please,
#error include debug after the headers OR do "#define XSCSET_DEBUG 1."
#error with "#define XSCSET_NO_DEBUG_ORDER 1".
#define XSC_DEBUG_UNDISPLAYABLE
#endif /* XSCSET_NO_DEBUG_ORDER */
#endif /* __DEBUGGER__, XSC_DEBUG_UNDISPLAYABLE, XSC_DEBUG_BY_STDB */
