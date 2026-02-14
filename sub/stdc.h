#ifndef XSC_STDC_ALL
#define XSC_STDC_ALL

/**
    Package Name: stdc.h / stdc,
    stands for "Standard C/C++ Libraries".
    General Purpose Package? yes;
    Child-Package? kinda;
    Experimental Package? no.
**/

#ifndef __cplusplus /* C */
/* C-89 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <float.h>
#include <stddef.h>
#include <limits.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
/* C-90 / NA1 */
#include <wchar.h>
#include <wctype.h>
#include <iso646.h>
/* C-99 */
#if __STDC_VERSION__ >= 199901L
#if 0
    #include <complex.h> /** /// Issues. /// **/
    #include <tgmath.h> /** /// Issues. /// **/
#endif
/** Note: Include "tgmath.h" and "complex.h" manually after the Super-C Library. **/
#include <inttypes.h>
#include <stdint.h>
#include <super/kwpack.h>
#include <stdbool.h>

#include <fenv.h>
#endif
/* C-11 */
#if __STDC_VERSION__ >= 201112L
#include <stdatomic.h>
#include <stdalign.h>
#include <uchar.h>
#endif
#else /* C++ */
#ifndef __cplusplus
#error [C++ superset directories attempting to be included in C]
#endif
#include <cctype> /* [C ported to C++] */
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#endif
/* [Actual C++] */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#if __cplusplus >= 201402L
#include <shared_mutex>
#endif
#if __cplusplus >= 201703L
#include <charconv>
#include <filesystem>
#endif
#endif

#endif /* XSC_STDC_ALL */
