#ifndef HARNESS__TESTS_H
#define HARNESS__TESTS_H

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef int (*TestFunction)(void);

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf(ANSI_COLOR_RED "Test Failed: %s\n" ANSI_COLOR_RESET, message); \
            return 1; \
        } \
    } while (0)


#endif // HARNESS__TESTS_H

