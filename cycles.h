#ifndef _CYCLES_DT_H
#define _CYCLES_DT_H

#line 5 "[cycles.h]"

#ifndef __STDCON__
#warning The use of 'stdcon.h' in this package is necessary for the proper functionality of some functions.
#endif

#include <super/stdbasic.h>

/**
    Header Name: cycles.h,
    stands for "extended cycles set".
    General Purpose Header? yes;
    Child-Header? no;
    Experimental Header? no.
**/

#if defined(XSC_LINUX) || defined(XSC_MAC) || defined(__unix__) || \
    defined(XSC_BSD) || defined(COMPILER_HAS_MINGW)
 #define __XSC_Zz 1
#else
#if XSC_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
int     usleep(int MicroSeconds) { return 1; }
#else
#define usleep(MicroSeconds) (1)
#endif
#endif
#ifndef XSC_WINDOWS
#if XSC_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
xsc_inline void Sleep(int dwMilliseconds) { usleep(dwMilliseconds * 1000); }
#else
#define Sleep(dwMilliseconds) usleep(dwMilliseconds * 1000)
#endif
#endif

/* sleepDebris. */

typedef void SleepType;
typedef int sleepType;
typedef sleepType MICRO_SLEEP;
typedef sleepType JIFFY_SLEEP;
typedef sleepType MILLI_SLEEP;
typedef sleepType CENTI_SLEEP;
typedef sleepType DEDIS_SLEEP;
typedef sleepType SECND_SLEEP;
typedef sleepType MNUTE_SLEEP;
typedef int TimeSpan;


SleepType msleep(MICRO_SLEEP TimeSpan){usleep(TimeSpan);     }
SleepType jsleep(JIFFY_SLEEP TimeSpan){ Sleep(TimeSpan);     }
SleepType MSleep(MILLI_SLEEP TimeSpan){ Sleep(TimeSpan);     }
SleepType csleep(CENTI_SLEEP TimeSpan){ Sleep(TimeSpan* 10); }
SleepType dsleep(DEDIS_SLEEP TimeSpan){ Sleep(TimeSpan*100); }
SleepType ssleep(SECND_SLEEP TimeSpan){ sleep(TimeSpan);     }
SleepType Msleep(MNUTE_SLEEP TimeSpan){ sleep(TimeSpan* 60); }

/*  The Order Goes From Quickest to Slowest.  */
/* the List is NOT working. */
typedef union _sleeptyp {
    SleepType(*msleep)(MICRO_SLEEP); /** 0.000001 Second **/ /** 100 = 1 Sec. **/
    SleepType(*jsleep)(JIFFY_SLEEP); /** 0.001    Second **/ /** 100 = 1 Sec. **/
    SleepType(*MSleep)(MILLI_SLEEP); /** 0.001    Second **/ /** 100 = 1 Sec. **/
    SleepType(*csleep)(CENTI_SLEEP); /** 0.01     Second **/ /** 100 = 1 Sec. **/
    SleepType(*dsleep)(DEDIS_SLEEP); /** 0.1      Second **/ /** 10 = 1 Sec.  **/
    SleepType(*ssleep)(SECND_SLEEP); /** 1        Second **/ /** 1 = 1 Sec.   **/
    SleepType(*Msleep)(MNUTE_SLEEP); /** 1        Minute **/ /** 0.1 = 1 Sec. **/
} SLEEPTYPES;
SLEEPTYPES SleepTypes = {
    .msleep = msleep,
    .jsleep = jsleep,
    .MSleep = MSleep,
    .csleep = csleep,
    .dsleep = dsleep,
    .ssleep = ssleep,
    .Msleep = Msleep
};

enum CycleTypes {
    CYCLE_DEFAULT    = 0,
    CYCLE_MOVEONLY   = 1, /* Deprecated. */
    CYCLE_CONTINUOUS = 1,
    CYCLE_CLEAR      = 2,
    CYCLE_CLEARESET  = 3
} CYCLE_TYPE;

void timed_cycle(void (*_cycle_)(), unsigned short _timer_)
{
#ifdef __STDCON__
    _timer_ = (!_timer_ && !_cycle_) ? 0100 : _timer_;
    _cycle_(_timer_);
    (CYCLE_TYPE == CYCLE_DEFAULT) ? CursorPosition(0,0) : /*0*/
    (CYCLE_TYPE == CYCLE_CONTINUOUS) ? 0LL : /*1*/
    (CYCLE_TYPE == CYCLE_CLEAR) ? xclear() : /*2*/
    (CYCLE_TYPE == CYCLE_CLEARESET) ? (CursorPosition(0,0), xclear()) :
    (CYCLE_TYPE >= 4) ? (printf("error: CYCLE_TYPE is set bigger than 4.\n"), getch(), exit(0x1)) : 0;
#else /* this doesn't seem right... emit a cycle error in case stdcon is not defined? yeah, definitely gonna re-check that later... */
    EMIT_ERROR(5C006, CYCLE_TYPE);
#endif
}

#define changeCycle(TYPE) (CYCLE_TYPE = TYPE)
#define CYCLES_RETURN_SEC 0

///64 6A 76 69 | 3C 33

#endif /* _CYCLES_DT_H */
