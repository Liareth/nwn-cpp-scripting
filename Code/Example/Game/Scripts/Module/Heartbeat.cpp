#pragma once

#include "Game/Systems/Scripting.hpp"
#include "NWN/Scripts/NWScript.hpp"

namespace example
{

using namespace nwn;
using namespace nwn::vm;

static void main()
{
    OID player = GetFirstPC();

    if (GetIsObjectValid(player))
    {
        SendMessageToPC(player, "Sup bro? It works!");
        Effect effect = EffectVisualEffect(VFX_FNF_DISPEL_DISJUNCTION);
        Effect effect2 = EffectVisualEffect(VFX_FNF_DISPEL_DISJUNCTION);
        Effect effect3 = EffectLinkEffects(effect, effect2);
        ApplyEffectAtLocation(DURATION_TYPE_INSTANT, effect3, GetLocation(player));
    }
}

REGISTER_SCRIPT("ex_mod_hb", &main);

}