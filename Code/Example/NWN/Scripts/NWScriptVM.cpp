#include "NWN/Scripts/NWScriptVM.hpp"
#include "Util/Assert.hpp"

namespace nwn::vm
{

CVirtualMachine* vm()
{
    return *g_pVirtualMachine;
}

CNWVirtualMachineCommands* vmc()
{
    return (CNWVirtualMachineCommands*)vm()->m_pCmdImplementer;
}

void prep_vm(OID oid, bool oidValid)
{
    if (vm()->m_nRecursionLevel == -1)
    {
        CVirtualMachineStack__InitializeStack(TCCALL(&vm()->m_cRunTimeStack));
        vm()->m_cRunTimeStack.m_pVMachine = vm();
    }

    vm()->m_nReturnValueParameterType = 0;
    vm()->m_pReturnValue = nullptr;

    vm()->m_nRecursionLevel += 1;
    vm()->m_oidObjectRunScript[vm()->m_nRecursionLevel] = oid;
    vm()->m_bValidObjectRunScript[vm()->m_nRecursionLevel] = oidValid;
    vmc()->m_oidObjectRunScript = vm()->m_oidObjectRunScript[vm()->m_nRecursionLevel];
    vmc()->m_bValidObjectRunScript = vm()->m_bValidObjectRunScript[vm()->m_nRecursionLevel];
}

void clean_vm()
{
    vm()->m_nRecursionLevel -= 1;

    if (vm()->m_nRecursionLevel != -1)
    {
        vmc()->m_oidObjectRunScript = vm()->m_oidObjectRunScript[vm()->m_nRecursionLevel];
        vmc()->m_bValidObjectRunScript = vm()->m_bValidObjectRunScript[vm()->m_nRecursionLevel];
    }
}

void set_ret_val(int val)
{
    vm()->m_nReturnValueParameterType = 0x03;
    vm()->m_pReturnValue = (void*)val;
}

static uint32_t s_pushed_count = 0;

void impl::push_int(int value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    if (CVirtualMachine__StackPushInteger(TCCALL(vm(), value)))
    {
        ++s_pushed_count;
    }
}

void impl::push_float(float value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    if (CVirtualMachine__StackPushFloat(TCCALL(vm(), value)))
    {
        ++s_pushed_count;
    }
}

void impl::push_string(const CExoString& value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    if (CVirtualMachine__StackPushString(TCCALL(vm(), value)))
    {
        ++s_pushed_count;
    }
}

void impl::push_oid(OID value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    if (value == OBJECT_SELF)
    {
        value = vm()->m_oidObjectRunScript[vm()->m_nRecursionLevel];
    }

    if (CVirtualMachine__StackPushObject(TCCALL(vm(), value)))
    {
        ++s_pushed_count;
    }
}

template <typename T>
void push_game_struct(int id, T value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    if (CVirtualMachine__StackPushEngineStructure(TCCALL(vm(), id, value)))
    {
        ++s_pushed_count;
    }
}

void impl::push_effect(const Effect& value)
{
    push_game_struct(0, value.raw);
}

void impl::push_event(const Event& value)
{
    push_game_struct(1, value.raw);
}

void impl::push_loc(const Loc& value)
{
    push_game_struct(2, value.raw);
}

void impl::push_talent(const Talent& value)
{
    push_game_struct(3, value.raw);
}

void impl::push_iprop(const ItemProperty& value)
{
    push_game_struct(4, value.raw);
}

void impl::push_vec(Vec3 value)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    if (CVirtualMachine__StackPushVector(TCCALL(vm(), value)))
    {
        ++s_pushed_count;
    }
}

int impl::pop_int()
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    int value;
    if (!CVirtualMachine__StackPopInteger(TCCALL(vm(), &value)))
    {
        return -1;
    }

    return value;
}

float impl::pop_float()
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    float value;
    if (!CVirtualMachine__StackPopFloat(TCCALL(vm(), &value)))
    {
        return 0.0f;
    }

    return value;
}

CExoString impl::pop_string()
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    CExoString value;
    if (!CVirtualMachine__StackPopString(TCCALL(vm(), &value)))
    {
        return "";
    }

    return value;
}

OID impl::pop_oid()
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    OID value;
    if (!CVirtualMachine__StackPopObject(TCCALL(vm(), &value)))
    {
        return OBJECT_INVALID;
    }

    return value;
}

template <typename T>
T pop_game_struct(int id)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    void* value;
    if (!CVirtualMachine__StackPopEngineStructure(TCCALL(vm(), id, &value)))
    {
        return nullptr;
    }

    return (T)value;
}

Effect impl::pop_effect()
{
    return Effect(pop_game_struct<CGameEffect*>(0));
}

Event impl::pop_event()
{
    return Event(pop_game_struct<CScriptEvent*>(1));
}

Loc impl::pop_loc()
{
    return Loc(pop_game_struct<CScriptLocation*>(2));
}

Talent impl::pop_talent()
{
    return Talent(pop_game_struct<CScriptTalent*>(3));
}

ItemProperty impl::pop_iprop()
{
    return ItemProperty(pop_game_struct<CGameEffect*>(4));
}

Vec3 impl::pop_vec()
{
    ASSERT(vm()->m_nRecursionLevel >= 0);

    Vec3 value;
    if (!CVirtualMachine__StackPopVector(TCCALL(vm(), &value)))
    {
        return { 0.0f, 0.0f, 0.0f };
    }

    return value;
}

void impl::call_builtin(int id)
{
    ASSERT(vm()->m_nRecursionLevel >= 0);
    CNWVirtualMachineCommands__ExecuteCommand(TCCALL(vmc(), id, s_pushed_count));
    s_pushed_count = 0;
}

}
