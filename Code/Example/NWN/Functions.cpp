#include "NWN/Addresses.hpp"
#include "NWN/Constants.hpp"
#include "NWN/Functions.hpp"

namespace nwn
{

CGameObject* lookup(OID oid)
{
    return CServerExoApp__GetGameObject(TCCALL((*g_pAppManager)->m_pServerExoApp, oid));
}

CNWSObject* as_obj(CGameObject* obj)
{
    if (obj)
    {
        switch (obj->m_nObjectType)
        {
            case COBJECT_TYPE_AREAOFEFFECTOBJECT:
            case COBJECT_TYPE_CREATURE:
            case COBJECT_TYPE_DOOR:
            case COBJECT_TYPE_ENCOUNTER:
            case COBJECT_TYPE_ITEM:
            case COBJECT_TYPE_PLACEABLE:
            case COBJECT_TYPE_SOUND:
            case COBJECT_TYPE_STORE:
            case COBJECT_TYPE_TRIGGER:
            case COBJECT_TYPE_WAYPOINT:
                return (CNWSObject*)obj;
        }
    }

    return nullptr;
}

CNWSArea* as_area(CGameObject* obj)
{
    return obj && obj->m_nObjectType == COBJECT_TYPE_AREA ? (CNWSArea*)obj : nullptr;
}

CNWSCreature* as_cre(CGameObject* obj)
{
    return obj && obj->m_nObjectType == COBJECT_TYPE_CREATURE ? (CNWSCreature*)obj : nullptr;
}

void add_action_to_front(CNWSObject* this_, uint32_t nActionId, uint16_t nGroupId,
    uint32_t nParamType1, void* pParameter1, uint32_t nParamType2, void* pParameter2,
    uint32_t nParamType3, void* pParameter3, uint32_t nParamType4, void* pParameter4,
    uint32_t nParamType5, void* pParameter5, uint32_t nParamType6, void* pParameter6,
    uint32_t nParamType7, void* pParameter7, uint32_t nParamType8, void* pParameter8,
    uint32_t nParamType9, void* pParameter9, uint32_t nParamType10, void* pParameter10,
    uint32_t nParamType11, void* pParameter11, uint32_t nParamType12, void* pParameter12)
{
    CNWSObject__AddActionToFront(TCCALL(this_, nActionId, nGroupId,
        nParamType1, pParameter1, nParamType2, pParameter2,
        nParamType3, pParameter3, nParamType4, pParameter4,
        nParamType5, pParameter5, nParamType6, pParameter6,
        nParamType7, pParameter7, nParamType8, pParameter8,
        nParamType9, pParameter9, nParamType10, pParameter10,
        nParamType11, pParameter11, nParamType12, pParameter12));
}

}