#ifndef TEST_H_
#define TEST_H_

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

extern int64_t test_variadic();

#ifdef USE_VOLATILE
#define VOLATILE volatile
#else
#define VOLATILE
#endif

#ifdef USE_INPUT
extern VOLATILE int value_;
#endif

#endif  // ifndef TEST_H_
