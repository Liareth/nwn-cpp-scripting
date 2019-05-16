#pragma once

#include <cstdint>

namespace example
{

extern uintptr_t g_base_addr;

// Must be called once upon startup.
void compute_base_addr();

// Should be called for every address before using it.
uintptr_t addr(uintptr_t addr);

}