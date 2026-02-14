#ifndef XCM_AUTOVA_
#define XCM_AUTOVA_

/**
    Header Name: autoVA.h,
    stands for "automatic varidic system".
    General Purpose Header? no;
    Child-Header? no;
    Experimental Package? no.
**/

/* name may be changed to 'auto.h' in the future... */

#ifndef _STDB_TYPEOF_
#include <super/sub/typeof.h>
#endif

#ifndef concat
#define concat(_VAR_I, VAR_II_) (_VAR_I##VAR_II_)
#endif

char va_auto[9] = ""; /** [DO NOT TOUCH THIS. EVER.] **/

#define _VA_C(...) _VA_C_(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _VA_C_(A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, ...) A9
#define _VA_F0()
#define _VA_F1(A0) A0
#define _VA_F2(A0, A1) A0 || A1
#define _VA_F3(A0, A1, A2) _VA_F2(A0, A1) || A2
#define _VA_F4(A0, A1, A2, A3) _VA_F3(A0, A1, A2) || A3
#define _VA_F5(A0, A1, A2, A3, A4) _VA_F4(A0, A1, A2, A3) || A4
#define _VA_F6(A0, A1, A2, A3, A4, A5) _VA_F5(A0, A1, A2, A3, A4) || A5
#define _VA_F7(A0, A1, A2, A3, A4, A5, A6) _VA_F6(A0, A1, A2, A3, A4, A5) || A6
#define _VA_F8(A0, A1, A2, A3, A4, A5, A6, A7) _VA_F7(A0, A1, A2, A3, A4, A5, A6) || A7
#define _VA_F9() _VA_F8() || A8
#define _PV_I0(...) _PV_I9(__VA_ARGS__)
#define _PV_I1(...) _PV_I9(__VA_ARGS__)
#define _PV_I2(A0, A1) P(A0), P(A1)
#define _PV_I3(A0, A1, A2) P(A0), P(A1), P(A2)
#define _PV_I4(A0, A1, A2, A3) P(A0), P(A1), P(A2), P(A3)
#define _PV_I5(A0, A1, A2, A3, A4) P(A0), P(A1), P(A2), P(A3), P(A4)
#define _PV_I6(A0, A1, A2, A3, A4, A5) P(A0), P(A1), P(A2), P(A3), P(A4), P(A5)
#define _PV_I7(A0, A1, A2, A3, A4, A5, A6) P(A0), P(A1), P(A2), P(A3), P(A4), P(A5), P(A6)
#define _PV_I8(A0, A1, A2, A3, A4, A5, A6, A7) P(A0), P(A1), P(A2), P(A3), P(A4), P(A5), P(A6), P(A7)
#define _PV_I9(...) (printf(ERR_5C002), getchar(), exit(0x5C002))
#define P(A) va_auto[strlen(va_auto)] = typeof_c(A)
#define __GET_VA__(...) _PV_N(_VA_C(__VA_ARGS__), __VA_ARGS__)
#define _PV_N(N, ...) concat(_PV_I, N)(__VA_ARGS__)

#include <super/sub/stdcrt.h>

#endif /* XCM_AUTOVA_ */
