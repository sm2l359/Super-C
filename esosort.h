#ifndef _XCM_ESOTERIC_SORT
#define _XCM_ESOTERIC_SORT

#include <super/stdbasic.h>

#define __ESO __xsc_attribs(xsc_extension xsc_section(".esoteric"))



__ESO void bogo(void * _List); /* actual bogo sort w/ comparisions. */
__ESO void bogobogo(void * _List); /* the most useless sorting algorithm to ever exist. */
__ESO void bozosort(void * _List); /* interested in a more precise version of bogosort? */
__ESO void stalinsort(void * _List); /* wants to lose some data? try this one. */
__ESO void semiStalinSort(void * _List); /* forgot what this one does since it erased my memory. */
__ESO void miraclesort(void * _List) {} /* praise god for this one to work. */

#undef __ESO

void bogo() {

}


#include <super/sub/stdcrt.h>

#endif
