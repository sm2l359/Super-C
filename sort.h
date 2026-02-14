#ifndef _XCM_SORT
#define _XCM_SORT

/**
    Library Name: sort.h,
    stands for "sorting algorithm".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
    Description: sorting algorithm package
**/

#define __SORT __xsc_attribs(xsc_extension xsc_section(".SuperC.sort"))

__SORT void xsort(void * _List, ...); /* select sorting algorithm with extra settings */
__SORT void qsort(void * _List); /* quick-sort, (C STANDARD) */
__SORT void bsort(void * _List); /* bogo-sort, (no comparisons, array shuffling only). */
__SORT void rsort(void * _List); /* radix-sort */
__SORT void hsort(void * _List); /* heap-sort */
__SORT void ssort(void * _List); /* shell-sort */
__SORT void csort(void * _List); /* super-C standard sorting algorithm. */

#undef __SORT

#endif /* _XCM_SORT */
