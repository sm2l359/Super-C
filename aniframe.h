#ifndef _ANIFRAME_H
#define _ANIFRAME_H

#line 5 "[aniframe.h]"

#include <super/stdbasic.h>

#ifndef _CYCLES_DT_H
#include <super/cycles.h>
#warning the use of the package 'cycles.h' is necessary and therefore, 'aniframe.h' has automatically included it.
#endif

/**
    Package Name: aniframe.h / "anif",
    stands for "Animation Functional Frame Library".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? kinda.
**/

/* Animation experiment functions library */

#if XSCCONF_HEADER_XTD >= ENABLED
typedef void aniframe;
#else
#define aniframe void
#endif


/* "1 Frame per Second." */

/* _t = _Time. */
aniframe anifunc(int _Frames, void(*_Sleeper)(), const unsigned int _t, ...) {
    va_list VA;
    va_start(VA, _t);

    void(*_func)() = NULL;
    for(int I = 0; I < _Frames; ++I) {
        _Sleeper(_t);
        _func = va_arg(VA, void*); /* 0/1 == FPS || FPM || FPU */
        _func();
    }

    va_end(VA);
}

aniframe mkaniframe(int _Frames, void(*_Sleeper)(), ...) {

}


aniframe mktypeText(char * _Strg, int _Delay, unsigned char _TypingFreq) {
    size_t _WritingLen = strlen(_Strg);

    srand(time(NULL));

    int _TypingDelayChance = 0;
    int _TypingDelay = 1;

    const int _Freq = (255 - _TypingFreq);

    for(int I = 0; I < _WritingLen; ++I) {

        if (kbhit()) {

            if(getch() == 0x0D) {

                printf(_Strg + I);
                return;
            }
        }

        _TypingDelayChance = rand() % 255 + 1;
        if(_TypingDelayChance > _Freq) {

            _TypingDelay = (rand() % 3) + 1;

            csleep(_Delay / _TypingDelay);

        }

        putchar(_Strg[I]);

    }

}

#include <super/sub/stdcrt.h>

#endif /* _ANIFRAME_H */
