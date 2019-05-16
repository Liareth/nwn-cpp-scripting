#pragma once

#include <stdio.h>

namespace example
{

#define ASSERT(condition) \
    do \
    { \
        if (!(condition)) ::example::assert_fail((#condition), __FILE__, __LINE__, nullptr); \
    } while (0)

#define ASSERT_MSG(condition, format, ...) \
    do \
    { \
        if (!(condition)) ::example::assert_fail((#condition), __FILE__, __LINE__, (format), ##__VA_ARGS__); \
    } while (0)

#define ASSERT_FAIL() \
    ::example::assert_fail(nullptr, __FILE__, __LINE__, nullptr)

#define ASSERT_FAIL_MSG(format, ...) \
    ::example::assert_fail(nullptr, __FILE__, __LINE__, (format), ##__VA_ARGS__)

    void assert_fail(const char* condition, const char* file, int line, const char* message);

    template <typename ... Args>
    void assert_fail(const char* condition, const char* file, int line, const char* format, Args ... args)
    {
        char buffer[1024];
        sprintf(buffer, format, args ...);
        assert_fail(condition, file, line, buffer);
    }

}
