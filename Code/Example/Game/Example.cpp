#include "Game/Example.hpp"
#include "Platform/ASLR.hpp"
#include "NWN/Addresses.hpp"

namespace example
{

Example* g_game;

subhook::Hook s_hk_createserver;
subhook::Hook s_hk_destroyserver;

// Called once from the injection point.
void init()
{
    example::compute_base_addr();
    nwn::init_addresses();
    nwn::init_globals();

    s_hk_createserver.Install(nwn::CAppManager__CreateServer, (decltype(nwn::CAppManager__CreateServer))
        [](TCPARAM(nwn::CAppManager*)) { s_hk_createserver.Remove(); g_game = new Example(); });

    s_hk_destroyserver.Install(nwn::CAppManager__DestroyServer, (decltype(nwn::CAppManager__DestroyServer))
        [](TCPARAM(nwn::CAppManager*)) { s_hk_destroyserver.Remove(); delete g_game; });
}

Example::Example()
{
    nwn::CAppManager__CreateServer(TCCALL(*nwn::g_pAppManager));

    m_combat = new CombatSystem();
    m_scripting = new ScriptingSystem();
}

Example::~Example()
{
    delete m_scripting;
    delete m_combat;

    nwn::CAppManager__DestroyServer(TCCALL(*nwn::g_pAppManager));
}

}
