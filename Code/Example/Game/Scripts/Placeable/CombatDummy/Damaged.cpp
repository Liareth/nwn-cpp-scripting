#pragma once

#include "Game/Systems/Scripting.hpp"
#include "NWN/Scripts/NWScript.hpp"
#include <stdio.h>

namespace example
{

using namespace nwn;
using namespace nwn::vm;

static void main()
{
    OID damager = GetLastDamager();
    int damage = GetTotalDamageDealt();

    char buf[512];
    sprintf(buf, "Took %d damage from %s!", damage, GetName(damager).m_sString);
    SpeakString(buf);
}

REGISTER_SCRIPT("ex_plc_dmg_dum", &main);

}