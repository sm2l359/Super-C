#ifndef _OPERATOR_PACK
#define _OPERATOR_PACK

#line 5 "[oprpack.h]"

/**
    Package Name: opack.h / oppack.h / oprpack.h,
    stands for "Operator-Pack".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

/* this file includes alternative spellings for operators and some keywords. */


    /*
    //this is an extension pack to <iso646.h> model; since this doesn't include all the type definitions by
    //default.

    //however, this is NOT a superset of it.
    //since it changes some of the syntax
    //of the <iso646> model. instead
    //this extension chooses to focus
    //on type convenience and comfort
    //rather than name accurancy.
    */



    /* oprpack definition rules:

    -most text version of operators
     contain a uppercase version of
     themselves due to some writing
     reasons; convenience, typing
     flexibility, etc.

    ex:
        and -- And
        or -- Or
        xor -- Xor

    -with the exception being
     relational operators;
     these only contains
     alternative types
     related to the
     '_equ' sign
     at the end.

*/

#ifndef __cplusplus /* operators. */
#define and && /* [THE LOGICAL ONES] */
#define And &&
#define or ||
#define Or ||
#define Not !
#define and_equ &= /* [THE RELATIONAL ONES] */
#define and_eq &=
#define or_equ |=
#define or_eq |=
#define xor_equ ^=
#define xor_eq ^=
#define not_equ !=
#define not_eq !=
#define not != /* swapped logic due to convenience. (!= <=-> !) */
#define bnot ! /* [THE BITWISE ONES] */
#define band &
#define bor |
#define xor ^
#define Xor ^
#define compl ~
#endif

#if XSCCONF_OPRPACK_ORIGINAL_NOT >= ENABLED
#undef not
#undef Not
#define not !
#define Not !=
#endif

#if XSCCONF_OPRPACK_ALT_SPELLINGS >= ENABLED
#define equals ==
#define HigherThan >
#define higherthan >
#define LowerThan <
#define lowerthan <
#define higherthan_equ >=
#define higherthan_eq >=
#define lowerthan_equ <=
#define lowerthan_eq <=
#define bLeft <<
#define bRight >>
#define bLeft_equ <<=
#define bRight_equ >>=
#define bleft <<
#define bright >>
#define bleft_equ <<=
#define bright_equ >>=
#define _neg -
#define _pos +
#define inc ++
#define dec --
#define op_add(a, b) a + b /* [Assembly-Like Math] */
#define op_sub(a, b) a - b
#define op_mul(a, b) a * b
#define op_div(a, b) a / b
#define op_rem(a, b) a % b
#define op_eqcmp(a, b) (a == b) /* [Assembly-Like Operations] */
#define op_necmp(a, b) (a != b)
#define op_hecmp(a, b) (a => b)
#define op_hlcmp(a, b) (a >= b)
#define op_hicmp(a, b) (a > b)
#define op_locmp(a, b) (a < b)
#define op_mulcmp(a, b) (a * b)
#define op_divcmp(a, b) (a / b)
#define op_remcmp(a, b) (a % b)
#define op_eq_cmp(a, b) (a == b)
#define op_ne_cmp(a, b) (a != b)
#define op_he_cmp(a, b) (a => b)
#define op_hl_cmp(a, b) (a >= b)
#define op_hi_cmp(a, b) (a > b)
#define op_lo_cmp(a, b) (a < b)
#define op_mul_cmp(a, b) (a * b)
#define op_div_cmp(a, b) (a / b)
#define op_rem_cmp(a, b) (a % b)
#define __DEFINED__OPRTR__PACK__ 0
#define __ALT__OPERATOR__PACK__ 0
#define _OPERATOR_PACK 0
#else /* In Case C++ Is Defined, define the definition directive as 1 Instead. */
#define __DEFINED__OPRTR__PACK__ 1
#define __ALT__OPERATOR__PACK__ 1
#define _OPERATOR_PACK 1
#endif

#if XSCCONF_OPRPACK_ALT_SPELLINGS >= ENABLED /* keywords. */
#define elif else if

/* infinite, but breakable loop with no conditions. */
#define loop for(;;)

/* ARG1 = LOOP, ARG2(Optional) = VAR-NAME, ARG3(Optional) = VAR_TYPE */
#define reach(...) __reach(__VA_ARGS__)

/* recursive algorithm that makes reach work. */
#define _VA_C3(...) _VA_C3_(__VA_ARGS__, 3, 2, 1, 0)
#define _VA_C3_(A0, A1, A2, A3, ...) A3
#define _VA_H0()
#define _VA_H1(A0) A0
#define _VA_H2(A0, A1) _VA_H1() || A1
#define _PV3_I0(...) _PV3_I1(__VA_ARGS__)
#define _PV3_I1(A0, ...) for(int I = 0; A0;)
#define _PV3_I2(A0, A1, ...) for(int A1; A0;)
#define _PV3_I3(A0, A1, A2, ...) for(A2 A1; A0;)
#define _PV3_I4(A0, ...) _PV3_I3(A0, __VA_ARGS__)
#define _PV3_N(N, ...) concat(_PV3_I, N)(__VA_ARGS__)
#define __reach(...) _PV3_N(_VA_C3(__VA_ARGS__), __VA_ARGS__)

/* A.K.A; Bit-Flip, Basically switch between 0 and 1. */
#define bfl ^= 1
#endif

#endif /* _OPERATOR_PACK */
