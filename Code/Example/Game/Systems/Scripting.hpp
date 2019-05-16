#pragma once

#include "NWN/Structs.hpp"
#include "subhook.h"

namespace example
{

struct ScriptingSystem
{
public:
    ScriptingSystem();
    ~ScriptingSystem();

private:
    static subhook::Hook s_hk_runscript;
};

// Every script should have this in its .cpp file.
// - entry_point is void main().
// - call vm::set_ret_val() for StartingConditional scripts.

#define REGISTER_SCRIPT(script, entry_point) \
    static ::example::impl::ScopedScriptDecl s_autoscriptdecl(script, entry_point)

using ScriptEntryPoint = void(*)();

void register_script(const char* script, ScriptEntryPoint entry_point);
ScriptEntryPoint get_script(const char* script);
bool run_cpp_script(const char* script, nwn::OID oid, bool oid_valid);

namespace impl
{
    struct ScopedScriptDecl
    {
        ScopedScriptDecl(const char* script, ScriptEntryPoint entry_point)
        {
            register_script(script, entry_point);
        }
    };
}

}
