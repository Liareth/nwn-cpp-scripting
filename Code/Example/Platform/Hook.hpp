#pragma once

#if WINDOWS
    // fastcall does ecx, edx, then stack
    // thiscall does ecx=this, rest stack
    // on win32 we can emulate thiscall by using fastcall with a dummy second param (which goes into edx)
    // https://docs.microsoft.com/en-us/cpp/cpp/argument-passing-and-naming-conventions?view=vs-2019
    #define TCCONV __fastcall
    #define TCPARAM(this_, ...) this_, int, ##__VA_ARGS__
    #define TCCALL(this_, ...) this_, 0, ##__VA_ARGS__
#else
    #error supportme
#endif