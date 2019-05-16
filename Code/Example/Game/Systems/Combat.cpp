#include "Game/Systems/Combat.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/Assembly.hpp"
#include "NWN/Constants.hpp"
#include "NWN/Functions.hpp"
#include "Util/Assert.hpp"

namespace example
{

subhook::Hook CombatSystem::s_hk_aiaction_attack_object;

CombatSystem::CombatSystem()
{
    s_hk_aiaction_attack_object.Install(nwn::CNWSCreature__AIActionAttackObject, &CNWSCreature__AIActionAttackObject);

    // This patches the call to WriteBYTE for the attack count.
    asm_::patch(addr(0x004ABCED), addr(0x004ABCF2), asm_::CallRelInstruction((uintptr_t)&patch_write_attacks).bytes(addr(0x004ABCED)));
}

CombatSystem::~CombatSystem()
{
    s_hk_aiaction_attack_object.Remove();
}

using namespace nwn;

// NEXT STEPS:
//
// - We may have to investigate what sets UPDATE_OBJECT_ANIMATION_FLAG.
// - Hook WriteGameObjUpdate_UpdateObject.
// - In the hook, if UPDATE_OBJECT_ANIMATION_FLAG is set on nObjectUpdatesRequired, unset it, then call original.
// - After calling original, if it was set, write our own update:
//   - WriteCHAR('U');
//   - WriteBYTE(creature);
//   - WriteOBJECTIDServer(oid);
//   - WriteDWORD(UPDATE_OBJECT_ANIMATION_FLAG);
//   - Fill in the rest of the update as appropriate
// - This will send the normal update, then our own update which we can fill with the attack animation data as we 
//   please without interacting with the existing combat round structure.
// - From there, we can start creating data in m_pNwnxData and storing auxiliary data there.
// - We can start to fill in our combat system using that information.

uint32_t TCCONV CombatSystem::CNWSCreature__AIActionAttackObject(TCPARAM(nwn::CNWSCreature* this_, nwn::CNWSObjectActionNode* pNode))
{
    //TODO if (GetDead() || GetIsPCDying())
    if (false)
    {
        // If we're dead, this action cannot happen.
    //  SetLockOrientationToObject(INVALID_OBJECT_ID);
    //  SetCombatMode(COMBAT_MODE_NONE, TRUE);
    //  SetAnimation(NWANIMBASE_ANIM_PAUSE);
        return ACTION_FAILED;
    }

    // TODO: Do we need a check for paralysis?

    ASSERT(pNode->m_nParameters == 1);
    OID target_oid = (OID)(pNode->m_pParameter[0]);

    if (target_oid == this_->m_idSelf)
    {
        // We can't attack ourselves. That would just be absurd.
        //    SetAnimation(NWANIMBASE_ANIM_PAUSE);
        return ACTION_FAILED;
    }

    CNWSObject* target_object = as_obj(lookup(target_oid));

    if (!target_object 
        // TODO ||  target_object->m_nObjectType
        )
    {
        // We're trying to attack an invalid object or an object of type we cannot possibly attack.
        return ACTION_FAILED;
    }

    bool need_new_target = false;

    // TODO if:
    // - target dead
    // - target dying
    bool target_dead = false;

    bool can_perceive_target = // TODO is DM
        true;

    // TODO if (GetVisibleListElement(oidAttackTarget))
    {
        can_perceive_target = true;
            // !pVisNode->GetCreatureInvisible() ||
            // pVisNode->GetCreatureHeard() ||
            // pVisNode->GetCreatureSeen()
    }

    need_new_target = target_dead || !can_perceive_target;

    if (need_new_target)
    {
        // TODO: Try to select a new target in weapon range.
        // If we can't find one, just fail the action.
        return ACTION_FAILED;
    }

    float desired_attack_range = 1.0f;
    float max_attack_range = desired_attack_range + 1.0f;

    bool target_same_area = true;
    bool target_in_los = true;

    Vec3 our_position = this_->m_vPosition;
    Vec3 target_position = target_object->m_vPosition;

    // I don't know why we do this, but it happens a lot...
    our_position.z += 1.0f;
    target_position.z += 1.0f;

    bool target_in_range = magnitude(our_position - target_position) <= max_attack_range;

    // TODO: We need an area check here, could be attacking something in another area.
    // TODO: We need an LoS check here.
    if (!target_same_area || !target_in_los || !target_in_range)
    {
        add_action_to_front(this_, CSERVERAIMASTER_AIACTION_ATTACKOBJECT, pNode->m_nGroupActionId,
            CNWSOBJECTACTION_PARAMETER_OBJECT, &target_oid);

        CNWSCreature__AddMoveToPointActionToFront(TCCALL(this_, pNode->m_nGroupActionId, target_position,
            target_object->m_oidArea, target_oid, 1, desired_attack_range,
            0.0f, 0, 0, 0, 0, 0, 0));

        return ACTION_COMPLETE;
    }

    static uint32_t timer = 0;
    static uint32_t last_update = 0;
    static bool waiting = false;
    
    timer += this_->m_nAIUpdateDifference;

    if (timer - last_update > 400)
    {
        last_update = timer;
        CNWSCreature__SetAnimation(TCCALL(this_, waiting ? NWANIMBASE_ANIM_FAKE_ATTACK : NWANIMBASE_ANIM_PAUSE));
        CNWSCreature__SetLockOrientationToObject(TCCALL(this_, target_oid));
        waiting = !waiting;
    }

    return ACTION_IN_PROGRESS;
}

void TCCONV CombatSystem::patch_write_attacks(TCPARAM(void* this_, uint8_t, int))
{

}

}