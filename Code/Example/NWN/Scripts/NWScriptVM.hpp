#pragma once

#include "NWN/Addresses.hpp"
#include "NWN/Structs.hpp"

namespace nwn::vm
{

CVirtualMachine* vm();
CNWVirtualMachineCommands* vmc();

void prep_vm(OID oid, bool oidValid);
void clean_vm();
void set_ret_val(int val);

namespace impl
{

struct RefCounted
{
    int* ref_count;
    RefCounted() { ref_count = new int(1); }
    RefCounted(const RefCounted& other) { ref_count = other.ref_count; inc_ref_count(); }
    void inc_ref_count() { ++(*ref_count); }
    bool dec_ref_count() { if (!--(*ref_count)) { delete ref_count; return true; } return false; }
};

}

struct Effect : public impl::RefCounted
{
    CGameEffect* raw;
    Effect(CGameEffect* loc) : raw(loc) { }
    Effect(const Effect& other) : RefCounted(other), raw(other.raw) { }
    Effect& operator=(const Effect& other) = delete;
    ~Effect() { if (dec_ref_count()) CNWVirtualMachineCommands__DestroyGameDefinedStructure(TCCALL(vmc(), 0, raw)); }
};

struct Event : public impl::RefCounted
{
    CScriptEvent* raw;
    Event(CScriptEvent* loc) : raw(loc) { }
    Event(const Event& other) : RefCounted(other), raw(other.raw) { }
    Event& operator=(const Event& other) = delete;
    ~Event() { if (dec_ref_count()) CNWVirtualMachineCommands__DestroyGameDefinedStructure(TCCALL(vmc(), 1, raw)); }
};

struct Loc : public impl::RefCounted
{
    CScriptLocation* raw;
    Loc(CScriptLocation* loc) : raw(loc) { }
    Loc(const Loc& other) : RefCounted(other), raw(other.raw) { }
    Loc& operator=(const Loc& other) = delete;
    ~Loc() { if (dec_ref_count()) CNWVirtualMachineCommands__DestroyGameDefinedStructure(TCCALL(vmc(), 2, raw)); }
};

struct Talent : public impl::RefCounted
{
    CScriptTalent* raw;
    Talent(CScriptTalent* loc) : raw(loc) { }
    Talent(const Talent& other) : RefCounted(other), raw(other.raw) { }
    Talent& operator=(const Talent& other) = delete;
    ~Talent() { if (dec_ref_count()) CNWVirtualMachineCommands__DestroyGameDefinedStructure(TCCALL(vmc(), 3, raw)); }
};

struct ItemProperty : public impl::RefCounted
{
    CGameEffect* raw;
    ItemProperty(CGameEffect* loc) : raw(loc) { }
    ItemProperty(const ItemProperty& other) : RefCounted(other), raw(other.raw) { }
    ItemProperty& operator=(const ItemProperty& other) = delete;
    ~ItemProperty() { if (dec_ref_count()) CNWVirtualMachineCommands__DestroyGameDefinedStructure(TCCALL(vmc(), 4, raw)); }
};

using Action = void(*)();
constexpr OID OBJECT_INVALID = 0x7F000000;
constexpr OID OBJECT_SELF = OBJECT_INVALID - 1; // technically wrong but practically right

namespace impl
{

void push_int(int);
void push_float(float);
void push_string(const CExoString&);
void push_oid(OID);
void push_effect(const Effect&);
void push_event(const Event&); 
void push_loc(const Loc&);
void push_talent(const Talent&);
void push_iprop(const ItemProperty&);
void push_vec(Vec3);

int pop_int();
float pop_float();
CExoString pop_string();
OID pop_oid();
Effect pop_effect();
Event pop_event();
Loc pop_loc();
Talent pop_talent();
ItemProperty pop_iprop();
Vec3 pop_vec();

void call_builtin(int id);

}

}