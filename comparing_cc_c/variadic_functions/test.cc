
#ifdef __cplusplus
#if (LANG != CPP)
#error "Expecting compilation for C++"
#endif
#include <cstdlib>
#else
#if (LANG != C)
#error "Expecting compilation for C++"
#endif
#include <stdarg.h>
#include <stdlib.h>
#endif

#ifdef USE_RAND
#define VARIADIC_LOOPS 1000000
#else
#define VARIADIC_LOOPS 100000000
#endif

#include "test.h"

#ifdef USE_INPUT
VOLATILE int value_;
#else
#define value_ 2
#endif

#ifdef USE_RAND
#define RAW_DATA rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand()
#else
#define RAW_DATA 1,value_,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,value_,20
#endif

#ifdef __cplusplus
#define DATA RAW_DATA
#else
#define DATA RAW_DATA,-1  // stop condition for C loop
#endif

#ifdef __cplusplus
template <typename T, typename ... Ts>
int64_t add(T head, Ts ... rest) {
    if constexpr (sizeof...(rest) == 0)
        return head;
    else
        return static_cast<int64_t>(head) + add(rest ...);
}
#else 
static int64_t add(int first, ...) {
    int64_t ret = first;
    va_list args;
    va_start(args, first);
    for (int i=va_arg(args,int); i >= 0; i=va_arg(args,int)) {
        ret += i;
    }
    return ret;
}
#endif

int64_t test_variadic() {
    int64_t t = 0;
    for (int i=0; i < VARIADIC_LOOPS; i++) {
        t += add(DATA);
    }
    return t;
}

