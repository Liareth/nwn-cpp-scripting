#pragma once

#include "NWN/Addresses.hpp"
#include "NWN/Structs.hpp"
#include "subhook.h"

namespace example
{

struct CombatSystem
{
public:
    CombatSystem();
    ~CombatSystem();

    static uint32_t TCCONV CNWSCreature__AIActionAttackObject(TCPARAM(nwn::CNWSCreature*, nwn::CNWSObjectActionNode*));

    static void TCCONV patch_write_attacks(TCPARAM(void* this_, uint8_t, int));

private:
    static subhook::Hook s_hk_aiaction_attack_object;
};

}
