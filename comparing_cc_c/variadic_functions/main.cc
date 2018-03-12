
#ifdef __cplusplus
#include <sys/time.h>
#include <cstdio>
#include <cstdint>
#else
#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>
#endif

#include "util.h"
#include "test.h"

int main(int argc, char *argv[])
{
    long long int t = 0;
    struct timeval start, end;

#ifdef USE_INPUT
    printf("Enter an integer ");
    int res = scanf("%d", &value_);
    if (res != 1) {
        printf("Failed to parse input\n");
        return -1;
    }
#endif

    gettimeofday(&start, NULL);

    t = test_variadic();

    gettimeofday(&end, NULL);

    long long int s1, s2, s;

    s1 = start.tv_sec * 1000LL + start.tv_usec / 1000LL;
    s2 = end.tv_sec * 1000LL + end.tv_usec / 1000LL;
    s = s2 - s1;

    printf(MAKE_STR(LANG) " returned %lld in %lld ms\n", t, s);
}

