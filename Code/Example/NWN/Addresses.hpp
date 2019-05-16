#pragma once

#include "NWN/Structs.hpp"
#include "Platform/Hook.hpp"

namespace nwn
{

extern CVirtualMachine** g_pVirtualMachine;
extern CAppManager** g_pAppManager;
extern CTlkTable** g_pTlkTable;

extern void* (*ExoMalloc)(uint32_t size);
extern void (*ExoFree)(void* ptr);

extern void (TCCONV* CAppManager__CreateServer)(TCPARAM(CAppManager* this_));
extern void (TCCONV* CAppManager__DestroyServer)(TCPARAM(CAppManager* this_));

extern int (TCCONV* CNWSCreature__AddMoveToPointActionToFront)(TCPARAM(
    CNWSCreature* this_, uint16_t nGroupId, Vec3 vNewWalkPosition, OID oidNewWalkArea,
    OID oidObjectMovingTo, int bRunToPoint, float fRange, float fTimeout, int bClientMoving,
    int nClientPathNumber, int nMoveToPosition, int nMoveMode, int bStraightLine, int bCheckedActionPoint));
extern uint32_t (TCCONV* CNWSCreature__AIActionAttackObject)(TCPARAM(CNWSCreature* this_, CNWSObjectActionNode* pNode));
extern CNWVisibilityNode* (TCCONV* CNWSCreature__GetVisibleListElement)(TCPARAM(CNWSCreature* this_, OID oidCreature));
extern bool (TCCONV* CNWSCreature__SetAnimation)(TCPARAM(CNWSCreature* this_, int nAnimation));
extern void (TCCONV* CNWSCreature__SetLockOrientationToObject)(TCPARAM(CNWSCreature* this_, OID oidLockOnObj));

extern void (TCCONV* CNWSObject__AddActionToFront)(TCPARAM(
    CNWSObject* this_, uint32_t nActionId, uint16_t nGroupId,
    uint32_t nParamType1, void* pParameter1, uint32_t nParamType2, void* pParameter2,
    uint32_t nParamType3, void* pParameter3, uint32_t nParamType4, void* pParameter4,
    uint32_t nParamType5, void* pParameter5, uint32_t nParamType6, void* pParameter6,
    uint32_t nParamType7, void* pParameter7, uint32_t nParamType8, void* pParameter8,
    uint32_t nParamType9, void* pParameter9, uint32_t nParamType10, void* pParameter10,
    uint32_t nParamType11, void* pParameter11, uint32_t nParamType12, void* pParameter12));
extern bool (TCCONV* CNWSObject__GetDead)(TCPARAM(CNWSObject* this_));
extern bool (TCCONV* CNWSObject__GetIsPCDying)(TCPARAM(CNWSObject* this_));

extern void (TCCONV* CNWVirtualMachineCommands__DestroyGameDefinedStructure)(TCPARAM(CNWVirtualMachineCommands* this_, int nEngineStructure, void* pStructureToDelete));
extern int (TCCONV* CNWVirtualMachineCommands__ExecuteCommand)(TCPARAM(CNWVirtualMachineCommands* this_, int nCommandId, int nParameters));

extern CGameObject* (TCCONV* CServerExoApp__GetGameObject)(TCPARAM(CServerExoApp* this_, OID nObjectID));

extern int (TCCONV* CVirtualMachine__RunScript)(TCPARAM(CVirtualMachine* this_, CExoString* psFileName, OID oid, int bOidValid));
extern int (TCCONV* CVirtualMachine__RunScriptSituation)(TCPARAM(CVirtualMachine* this_, void* pSituation, OID oid, int bOidValid));

extern int (TCCONV* CVirtualMachine__StackPopEngineStructure)(TCPARAM(CVirtualMachine* this_, int nEngineStructure, void** ppEngineStructure));
extern int (TCCONV* CVirtualMachine__StackPopFloat)(TCPARAM(CVirtualMachine* this_, float* fFloat));
extern int (TCCONV* CVirtualMachine__StackPopInteger)(TCPARAM(CVirtualMachine* this_, int* nInteger));
extern int (TCCONV* CVirtualMachine__StackPopObject)(TCPARAM(CVirtualMachine* this_, OID* poidObjectId));
extern int (TCCONV* CVirtualMachine__StackPopString)(TCPARAM(CVirtualMachine* this_, CExoString* sString));
extern int (TCCONV* CVirtualMachine__StackPopVector)(TCPARAM(CVirtualMachine* this_, Vec3* pvVector));

extern int (TCCONV* CVirtualMachine__StackPushEngineStructure)(TCPARAM(CVirtualMachine* this_, int nEngineStructure, void* pEngineStructure));
extern int (TCCONV* CVirtualMachine__StackPushFloat)(TCPARAM(CVirtualMachine* this_, float fFloat));
extern int (TCCONV* CVirtualMachine__StackPushInteger)(TCPARAM(CVirtualMachine* this_, int nInteger));
extern int (TCCONV* CVirtualMachine__StackPushObject)(TCPARAM(CVirtualMachine* this_, OID oidObjectId));
extern int (TCCONV* CVirtualMachine__StackPushString)(TCPARAM(CVirtualMachine* this_, const CExoString& sString));
extern int (TCCONV* CVirtualMachine__StackPushVector)(TCPARAM(CVirtualMachine* this_, Vec3 vVector));

extern void (TCCONV* CVirtualMachineStack__InitializeStack)(TCPARAM(CVirtualMachineStack* this_));

void init_addresses();
void init_globals();

}