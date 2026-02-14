#ifndef _XSC_LGATE_H
#define _XSC_LGATE_H
#include <super/stdbasic.h>
#include <stdint.h>

/**
    Library Name: logic.h,
    stands for "logic-gate".
    General Purpose Library? no;
    Child-Library? no;
    Experimental Library? yes.
**/

/* header designed for anyone interested in testing/playing with virtual logic gates. */

#define XSC_LOGICGATE __attribs(xsc_extension xsc_forceline xscs_logic)

#if XSC_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL || C_VERSION < CC99
 typedef uint8_t xsc_bgate; /* basic */
 typedef uint8_t xsc_ugate; /* universal */
 typedef uint8_t xsc_dgate; /* derived */
 typedef uint8_t xsc_gate;
 typedef uint8_t xsc_lgin;
#else
 typedef _Bool xsc_bgate; /* basic */
 typedef _Bool xsc_ugate; /* universal */
 typedef _Bool xsc_dgate; /* derived */
 typedef _Bool xsc_gate;
 typedef _Bool xsc_lgin;
#endif

#if XSC_OPTIMIZE <= XSCOPT_0PTIMIZELEVEL
XSC_LOGICGATE xsc_bgate lg_and(xsc_lgin I, xsc_lgin II) { return I & II; }
XSC_LOGICGATE xsc_bgate lg_or(xsc_lgin I, xsc_lgin II) { return I | II; }
XSC_LOGICGATE xsc_bgate lg_not(xsc_lgin In) { return !In; }
XSC_LOGICGATE xsc_gate lg_lsh(xsc_lgin I, xsc_lgin II) { return I >> II; }
XSC_LOGICGATE xsc_gate lg_rsh(xsc_lgin I, xsc_lgin II) { return I << II; }
XSC_LOGICGATE xsc_ugate lg_nand(xsc_lgin I, xsc_lgin II) { return !(I && II); }
XSC_LOGICGATE xsc_ugate lg_nor(xsc_lgin I, xsc_lgin II) { return !(I | II); }
XSC_LOGICGATE xsc_dgate lg_xor(xsc_lgin I, xsc_lgin II) { return I ^ II; }
XSC_LOGICGATE xsc_dgate lg_xnor(xsc_lgin I, xsc_lgin II) { return !(I ^ II); }
XSC_LOGICGATE xsc_gate lg_inc(xsc_lgin In) { return ++In; }
XSC_LOGICGATE xsc_gate lg_dec(xsc_lgin In) { return --In; }
XSC_LOGICGATE xsc_gate lge_and(xsc_lgin I, xsc_lgin II) { return I && II; } /* lge: extended logic gate. */
XSC_LOGICGATE xsc_gate lge_or(xsc_lgin I, xsc_lgin II) { return I || II; }
XSC_LOGICGATE xsc_gate lg_noteq(xsc_lgin I, xsc_lgin II) { return I != II; }
XSC_LOGICGATE xsc_gate lg_andeq(xsc_lgin I, xsc_lgin II) { return I &= II; }
XSC_LOGICGATE xsc_gate lg_oreq(xsc_lgin I, xsc_lgin II) { return I |= II; }
XSC_LOGICGATE xsc_gate lg_xoreq(xsc_lgin I, xsc_lgin II) { return I ^= II; }
XSC_LOGICGATE xsc_gate lg_lsheq(xsc_lgin I, xsc_lgin II) { return I >>= II; }
XSC_LOGICGATE xsc_gate lg_rsheq(xsc_lgin I, xsc_lgin II) { return I <<= II; }
#else
 #define lg_and(I,  II) I & II
 #define lg_or(I,  II) I | II
 #define lg_not(In) !In
 #define lg_xor(I,  II) I ^ II
 #define lg_lsh(I,  II) I >> II
 #define lg_rsh(I,  II) I << II
 #define lg_nand(I,  II) !(I && II)
 #define lg_xnor(I,  II) !(I ^ II)
 #define lg_nor(I,  II) !(I | II)
 #define lg_inc(In) ++In
 #define lg_dec(In) --In
 #define lge_and(I,  II) I && II
 #define lge_or(I,  II) I || II
 #define lg_andeq(I,  II) I &= II
 #define lg_oreq(I,  II) I |= II
 #define lg_noteq(I,  II) I != II
 #define lg_xoreq(I,  II) I ^= II
 #define lg_lsheq(I,  II) I >>= II
 #define lg_rsheq(I,  II) I <<= II
#endif

#undef XSC_LOGICGATE

#include <super/sub/stdcrt.h>
#endif /* _XSC_LGATE_H */
