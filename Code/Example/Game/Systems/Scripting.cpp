#include "Game/Systems/Scripting.hpp"
#include "NWN/Scripts/NWScriptVM.hpp"

#include <unordered_map>
#include <string>

namespace example
{

subhook::Hook ScriptingSystem::s_hk_runscript;

ScriptingSystem::ScriptingSystem()
{
    s_hk_runscript.Install(
        nwn::CVirtualMachine__RunScript, (decltype(nwn::CVirtualMachine__RunScript))
        [](TCPARAM(nwn::CVirtualMachine* this_, nwn::CExoString* psFileName, nwn::OID oid, int bOidValid))
        {
            if (!psFileName->m_sString || !run_cpp_script(psFileName->m_sString, oid, !!bOidValid))
            {
                return ((decltype(nwn::CVirtualMachine__RunScript))s_hk_runscript.GetTrampoline())
                    (TCCALL(this_, psFileName, oid, bOidValid));
            }

            return 1;
        });
}

ScriptingSystem::~ScriptingSystem()
{
    s_hk_runscript.Remove();
}

std::unordered_map<std::string, ScriptEntryPoint>& get_script_map()
{
    static std::unordered_map<std::string, ScriptEntryPoint> map;
    return map;
}

void register_script(const char* script, ScriptEntryPoint entry_point)
{
    get_script_map()[script] = entry_point;
}

ScriptEntryPoint get_script(const char* script)
{
    auto entry = get_script_map().find(script);
    if (entry != std::end(get_script_map()))
    {
        return entry->second;
    }
    return nullptr;
}

bool run_cpp_script(const char* script, nwn::OID oid, bool oid_valid)
{
    ScriptEntryPoint ep = get_script(script);
    if (ep)
    {
        nwn::vm::prep_vm(oid, oid_valid);
        ep();
        nwn::vm::clean_vm();
    }
    return false;
}


}