#include "NWN/Addresses.hpp"
#include "Platform/ASLR.hpp"

namespace nwn
{

using namespace example;

decltype(g_pVirtualMachine) g_pVirtualMachine;
decltype(g_pAppManager) g_pAppManager;
decltype(g_pTlkTable) g_pTlkTable;

decltype(ExoMalloc) ExoMalloc;
decltype(ExoFree) ExoFree;

decltype(CAppManager__CreateServer) CAppManager__CreateServer;
decltype(CAppManager__DestroyServer) CAppManager__DestroyServer;

decltype(CNWSCreature__AddMoveToPointActionToFront) CNWSCreature__AddMoveToPointActionToFront;
decltype(CNWSCreature__AIActionAttackObject) CNWSCreature__AIActionAttackObject;
decltype(CNWSCreature__GetVisibleListElement) CNWSCreature__GetVisibleListElement;
decltype(CNWSCreature__SetAnimation) CNWSCreature__SetAnimation;
decltype(CNWSCreature__SetLockOrientationToObject) CNWSCreature__SetLockOrientationToObject;

decltype(CNWSObject__AddActionToFront) CNWSObject__AddActionToFront;
decltype(CNWSObject__GetDead) CNWSObject__GetDead;
decltype(CNWSObject__GetIsPCDying) CNWSObject__GetIsPCDying;

decltype(CNWVirtualMachineCommands__DestroyGameDefinedStructure) CNWVirtualMachineCommands__DestroyGameDefinedStructure;
decltype(CNWVirtualMachineCommands__ExecuteCommand) CNWVirtualMachineCommands__ExecuteCommand;

decltype(CServerExoApp__GetGameObject) CServerExoApp__GetGameObject;

decltype(CVirtualMachine__RunScript) CVirtualMachine__RunScript;
decltype(CVirtualMachine__RunScriptSituation) CVirtualMachine__RunScriptSituation;

decltype(CVirtualMachine__StackPopEngineStructure) CVirtualMachine__StackPopEngineStructure;
decltype(CVirtualMachine__StackPopFloat) CVirtualMachine__StackPopFloat;
decltype(CVirtualMachine__StackPopInteger) CVirtualMachine__StackPopInteger;
decltype(CVirtualMachine__StackPopObject) CVirtualMachine__StackPopObject;
decltype(CVirtualMachine__StackPopString) CVirtualMachine__StackPopString;
decltype(CVirtualMachine__StackPopVector) CVirtualMachine__StackPopVector;

decltype(CVirtualMachine__StackPushEngineStructure) CVirtualMachine__StackPushEngineStructure;
decltype(CVirtualMachine__StackPushFloat) CVirtualMachine__StackPushFloat;
decltype(CVirtualMachine__StackPushInteger) CVirtualMachine__StackPushInteger;
decltype(CVirtualMachine__StackPushObject) CVirtualMachine__StackPushObject;
decltype(CVirtualMachine__StackPushString) CVirtualMachine__StackPushString;
decltype(CVirtualMachine__StackPushVector) CVirtualMachine__StackPushVector;

decltype(CVirtualMachineStack__InitializeStack) CVirtualMachineStack__InitializeStack;

void init_addresses()
{
    ExoMalloc = (decltype(ExoMalloc))addr(0x0040FEA0);
    ExoFree = (decltype(ExoFree))addr(0x0040FE90);

    CAppManager__CreateServer = (decltype(CAppManager__CreateServer))addr(0x00401490);
    CAppManager__DestroyServer = (decltype(CAppManager__DestroyServer))addr(0x00401510);

    CNWSCreature__AddMoveToPointActionToFront = (decltype(CNWSCreature__AddMoveToPointActionToFront))addr(0x00528190);
    CNWSCreature__AIActionAttackObject = (decltype(CNWSCreature__AIActionAttackObject))addr(0x00587CB0);
    CNWSCreature__GetVisibleListElement = (decltype(CNWSCreature__GetVisibleListElement))addr(0x005596F0);
    CNWSCreature__SetAnimation = (decltype(CNWSCreature__SetAnimation))addr(0x005417D0);
    CNWSCreature__SetLockOrientationToObject = (decltype(CNWSCreature__SetLockOrientationToObject))addr(0x00541D10);

    CNWSObject__AddActionToFront = (decltype(CNWSObject__AddActionToFront))addr(0x004CC070);
    CNWSObject__GetDead = (decltype(CNWSObject__GetDead))addr(0x004D0DD0);
    CNWSObject__GetIsPCDying = (decltype(CNWSObject__GetIsPCDying))addr(0x004D0FC0);

    CNWVirtualMachineCommands__DestroyGameDefinedStructure = (decltype(CNWVirtualMachineCommands__DestroyGameDefinedStructure))addr(0x005AE180);
    CNWVirtualMachineCommands__ExecuteCommand = (decltype(CNWVirtualMachineCommands__ExecuteCommand))addr(0x005AE270);

    CServerExoApp__GetGameObject = (decltype(CServerExoApp__GetGameObject))addr(0x00487390);

    CVirtualMachine__RunScript = (decltype(CVirtualMachine__RunScript))addr(0x007D9990);
    CVirtualMachine__RunScriptSituation = (decltype(CVirtualMachine__RunScriptSituation))addr(0x007DA0F0);

    CVirtualMachine__StackPopEngineStructure = (decltype(CVirtualMachine__StackPopEngineStructure))addr(0x007DAB10);
    CVirtualMachine__StackPopFloat = (decltype(CVirtualMachine__StackPopFloat))addr(0x007DAB90);
    CVirtualMachine__StackPopInteger = (decltype(CVirtualMachine__StackPopInteger))addr(0x007DABE0);
    CVirtualMachine__StackPopObject = (decltype(CVirtualMachine__StackPopObject))addr(0x007DAC30);
    CVirtualMachine__StackPopString = (decltype(CVirtualMachine__StackPopString))addr(0x007DAC80);
    CVirtualMachine__StackPopVector = (decltype(CVirtualMachine__StackPopVector))addr(0x007DACD0);

    CVirtualMachine__StackPushEngineStructure = (decltype(CVirtualMachine__StackPushEngineStructure))addr(0x007DADB0);
    CVirtualMachine__StackPushFloat = (decltype(CVirtualMachine__StackPushFloat))addr(0x007DAE10);
    CVirtualMachine__StackPushInteger = (decltype(CVirtualMachine__StackPushInteger))addr(0x007DAF20);
    CVirtualMachine__StackPushObject = (decltype(CVirtualMachine__StackPushObject))addr(0x007DB020);
    CVirtualMachine__StackPushString = (decltype(CVirtualMachine__StackPushString))addr(0x007DB120);
    CVirtualMachine__StackPushVector = (decltype(CVirtualMachine__StackPushVector))addr(0x007DB180);

    CVirtualMachineStack__InitializeStack = (decltype(CVirtualMachineStack__InitializeStack))addr(0x007D9200);
}

void init_globals()
{
    g_pVirtualMachine = (decltype(g_pVirtualMachine))addr(0x008FBCF0);
    g_pAppManager = (decltype(g_pAppManager))addr(0x008FBD08);
    g_pTlkTable = (decltype(g_pTlkTable))addr(0x008FBCF8);
}

}
