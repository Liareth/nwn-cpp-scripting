#include "Util/Assert.hpp"

#include <stdlib.h>
#include <string.h>
#include <string>

#if WINDOWS
    #include "Windows.h"
#endif

namespace example
{

std::string get_stack_trace()
{
    char buffer[1024] = { '\0' };
    void* stackTrace[20];

#if WINDOWS
    if (int numCapturedFrames = CaptureStackBackTrace(0, 20, stackTrace, NULL); numCapturedFrames)
    {
        strncat(buffer, "\n  Backtrace:\n", sizeof(buffer) - 1);
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            char backtraceBuffer[32];
            snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    [0x%p]\n", stackTrace[i]);
            strncat(buffer, backtraceBuffer, sizeof(buffer) - 1);
        }
    }
#endif // _WIN32

    return std::string(buffer);
}

void assert_fail(const char* condition, const char* file, int line, const char* message)
{
    char buffer[1024];

    if (condition)
    {
        snprintf(buffer, sizeof(buffer), "ASSERTION FAILURE\n  Summary: (%s) failed at (%s:%d)", condition, file, line);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "ASSERTION FAILURE\n  Summary: Failed at (%s:%d)", file, line);
    }

    if (message)
    {
        strncat(buffer, "\n  Message: ", sizeof(buffer) - 1);
        strncat(buffer, message, sizeof(buffer) - 1);
    }

    strncat(buffer, get_stack_trace().c_str(), sizeof(buffer) - 1);
    fputs(buffer, stderr);
    fflush(stderr);

    bool skipCrash = false;
    bool skipBreak = false;

#if WINDOWS
    int response = MessageBox(GetActiveWindow(), buffer, "ASSERTION FAILURE", MB_ABORTRETRYIGNORE);

    switch (response)
    {
    case IDRETRY: // No crash, but break.
        skipCrash = true;
        break;

    case IDIGNORE: // No crash or break.
        skipCrash = true;
        skipBreak = true;
        break;

    case IDABORT:
    default: // Crash and break
        break;
    }
#endif

    if (!skipBreak)
    {
#if WINDOWS
        __debugbreak();
#else
        raise(SIGTRAP);
#endif
    }

    if (!skipCrash)
    {
        abort();
    }
}

}