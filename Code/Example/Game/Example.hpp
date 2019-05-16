#pragma once

#include "Game/Systems/Combat.hpp"
#include "Game/Systems/Scripting.hpp"
#include <subhook.h>

namespace example
{

// Called once from the injection point.
void init();

class Example
{
public:
    // Called by CAppManager__CreateServer only once.
    Example();

    // Called by CAppManager__DestroyServer only once.
    ~Example();

private:
    CombatSystem* m_combat;
    ScriptingSystem* m_scripting;
};

extern Example* g_game;

}
