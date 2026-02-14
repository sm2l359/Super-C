#ifndef __SCB_STDINT
#define __SCB_STDINT

#ifndef __cplusplus

#ifndef __STDC_VERSION__
#define __STDC_VERSION__ 198912L
#endif

#if __STDC_VERSION__ >= 199901L
#include <stdint.h>
#else
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;
#endif
#endif

#endif /* __SCB_STDINT */
