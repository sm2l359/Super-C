/**
    Package Name: getos.h,
    stands for "get Operating System".
    General Purpose Package? yes;
    Child-Package? yes;
        Parent-Package: "stdbasic.h";
    Experimental Package? no.
**/

#define osID_WINDOWS 1
#define osID_LINUX 2
#define osID_MAC 3
#define osID_BSD 4
#define osID_OTHER 0

/* first-caps */
#define OsID_WINDOWS 1
#define OsID_LINUX 2
#define OsID_MAC 3
#define OsID_BSD 4
#define OsID_OTHER 0

#define BSD_FREEBSD 1
#define BSD_OPENBSD 2
#define BSD_NETBSD 3
#define BSD_DRAGONFLY 4

#if defined(__unix__) || defined(__unix)
#define UNIX_BASED 1
#endif

#ifndef XSC_OS
#if defined(_WIN32)
#define XSC_OS OsID_WINDOWS
#ifdef _WIN32_WINNT
#define WINDOWS_MINVER _WIN32_WINNT
#else
#define WINDOWS_MINVER 0x0000
#define _WIN32_WINNT 0x0000
#endif

#define WINDOWS_95 1995
#define WINDOWS_98 1998
#define WINDOWS_ME 2000
#define WINDOWS_XP 2001
#define WINDOWS_XP64 2005
#define WINDOWS_VISTA 2007
#define WINDOWS_7 2009
#define WINDOWS_8 2012
#define WINDOWS_8_1 2013
#define WINDOWS_10 2015
#define WINDOWS_11 2021

#if (0) /* doesn't really work... */
#define XSC_OSVER 11
#define XSC_WINDOWS "11"
#define WINDOWS_RELEASE 2021
#define WINDOWS_CODENAME SUNVALLEY
#elif (_WIN32_WINNT >= 0x0A00)
#define XSC_OSVER 10
#define XSC_WINDOWS "10"
#define WINDOWS_RELEASE 2015
#define WINDOWS_CODENAME THRESHOLD
#elif (_WIN32_WINNT >= 0x0603)
#define XSC_OSVER 9 /* 8_1 */
#define XSC_WINDOWS "8.1"
#define WINDOWS_RELEASE 2013
#define WINDOWS_CODENAME BLUE
#elif (_WIN32_WINNT >= 0x0602)
#define XSC_OSVER 8
#define XSC_WINDOWS "8"
#define WINDOWS_RELEASE 2012
#define WINDOWS_CODENAME WINDOWS8
#elif (_WIN32_WINNT >= 0x0601)
#define XSC_OSVER 7
#define XSC_WINDOWS "7"
#define WINDOWS_RELEASE 2009
#define WINDOWS_CODENAME WINDOWS7
#elif (_WIN32_WINNT >= 0x0600)
#define XSC_OSVER 5
#define XSC_WINDOWS "Vista"
#define WINDOWS_RELEASE 2007
#define WINDOWS_CODENAME LONGHORN
#elif (_WIN32_WINNT >= 0x0502)
#define XSC_OSVER 4
#define XSC_WINDOWS "XP-64"
#define WINDOWS_RELEASE 2005
#define WINDOWS_CODENAME EMERALD
#elif (_WIN32_WINNT >= 0x0501)
#define XSC_OSVER 3
#define XSC_WINDOWS "XP"
#define WINDOWS_RELEASE 2001
#define WINDOWS_CODENAME WHISTLER
#elif (_WIN32_WINNT >= 0x0500)
#define XSC_OSVER 2
#define XSC_WINDOWS "2000"
#define WINDOWS_RELEASE 2000
#define WINDOWS_CODENAME MILLENIUM
#else
#define XSC_OSVER 1
#define XSC_WINDOWS "< 2000" /* Equal or Lower Than Windows 98... */
#define WINDOWS_RELEASE 0000
#define WINDOWS_CODENAME UNKNOWN
#endif
#define XSC_WIN 1
#elif defined(__linux__) || defined(__LINUX__)
#define XSC_OS OsID_LINUX /* [ALT] XSC_OSID, XSC_OsID */
#define XSC_LINUX 1
#elif defined(__apple__) || defined(__APPLE__)
#define XSC_OS OsID_MAC
#define XSC_MAC 1
#elif defined(__FreeBSD__)
#define XSC_OS OsID_FREEBSD
#define XSC_BSD 1 /* Free */
#elif defined(__OpenBSD__)
#define XSC_OS OsID_OPENBSD
#define XSC_BSD 2 /* Open */
#elif defined(__NetBSD__)
#define XSC_OS OsID_NETBSD
#define XSC_BSD 3 /* Net */
#elif defined(__DragonFly__)
#define XSC_OS OsID_DRAGONFLY
#define XSC_BSD 4 /* Fly */
#elif defined(UNIX_BASED)
#define XSC_UNIX
#else
#define XSC_OS OsID_OTHER
#define XSC_OTHER 0
#endif
#endif

/* OS-Architeture (32x, 64x), */

#ifdef _STDINT_H
#if UINTPTR_MAX == 0xffffffff
#define XSC_ARCH 32
#elif UINTPTR_MAX == 0xffffffffffffffff
#define XSC_ARCH 64
#else
#define XSC_ARCH 16 /* 16x = Unknown architeture, so it presumes your System is on real mode. */
#endif
#else /* [NOTE][CUT][REM] cut this section out later. */
/* Maybe i Should replace this with a warning? */
#if XSC_OS == OsID_WINDOWS
#if defined(_WIN64)
#define XSC_ARCH 64
#elif defined(_WIN32)
#define XSC_ARCH 32
#else
#define XSC_ARCH 16
#endif
#else /* Linux / Mac */
#if defined(__x86_64__) || defined(__ppc64__) || defined(__aarch64__)
#define XSC_ARCH 64
#elif defined(__i386__) || defined(__ppc__) || defined(__arm__)
#define XSC_ARCH 32
#else
#define XSC_ARCH 16
#endif
#endif
#endif
