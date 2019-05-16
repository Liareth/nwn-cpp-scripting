#include "Platform/ASLR.hpp"
#include "Util/Assert.hpp"

#if WINDOWS
    #include "Windows.h"
#endif

namespace example
{

uintptr_t g_base_addr = 0;

void compute_base_addr()
{
#if WINDOWS
    uintptr_t ida_addr = 0x0040C690;
    
    if (HMODULE handle = LoadLibraryA("nwserver.exe"); handle)
    {
        uintptr_t actual_addr = (uintptr_t)GetProcAddress(handle, "NWNXEntryPoint");
        FreeLibrary(handle);

        if (actual_addr)
        {
            g_base_addr = actual_addr - ida_addr;
        }
    }
    
    ASSERT_MSG(g_base_addr, "Couldn't find base address; assuming 0.");
#else
    #error supportme
#endif
}

uintptr_t addr(uintptr_t addr)
{
    return g_base_addr + addr;
}

}
