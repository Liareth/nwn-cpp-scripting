#pragma once

#include "NWN/Structs.hpp"

namespace nwn
{

CGameObject* lookup(OID oid);
CNWSObject* as_obj(CGameObject* obj);
CNWSArea* as_area(CGameObject* obj);
CNWSCreature* as_cre(CGameObject* obj);

void add_action_to_front(CNWSObject* this_, uint32_t nActionId, uint16_t nGroupId,
    uint32_t nParamType1 = 0, void* pParameter1 = nullptr, uint32_t nParamType2 = 0, void* pParameter2 = nullptr,
    uint32_t nParamType3 = 0, void* pParameter3 = nullptr, uint32_t nParamType4 = 0, void* pParameter4 = nullptr,
    uint32_t nParamType5 = 0, void* pParameter5 = nullptr, uint32_t nParamType6 = 0, void* pParameter6 = nullptr,
    uint32_t nParamType7 = 0, void* pParameter7 = nullptr, uint32_t nParamType8 = 0, void* pParameter8 = nullptr,
    uint32_t nParamType9 = 0, void* pParameter9 = nullptr, uint32_t nParamType10 = 0, void* pParameter10 = nullptr,
    uint32_t nParamType11 = 0, void* pParameter11 = nullptr, uint32_t nParamType12 = 0, void* pParameter12 = nullptr);

}