#include "Platform/Assembly.hpp"
#include <cstring>
#include <Windows.h>

namespace {

uintptr_t rel_addr(const uintptr_t from, const uintptr_t to, const uintptr_t instSize)
{
    return to + (0xFFFFFFFF - (from + instSize)) + 1;
}

}

namespace example::asm_
{

std::vector<uint8_t> AddRegImmByteInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x83; // ADD r32, imm8
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_register);
    return { opcode, extended, m_value };
}

std::vector<uint8_t> AddRegImmDwordInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x81; // ADD r32, imm32
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    encoded[0] = opcode;
    encoded[1] = extended;
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> CallRelInstruction::bytes(const uintptr_t address) const
{
    const uint8_t opcode = 0xE8; // CALL near relative
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    const uintptr_t relAddress = rel_addr(address, m_address, 5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &relAddress, 4);
    return encoded;
}

std::vector<uint8_t> JmpRelInstruction::bytes(const uintptr_t address) const
{
    const uint8_t opcode = 0xE9; // JMP near relative
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    const uintptr_t relAddress = rel_addr(address, m_address, 5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &relAddress, 4);
    return encoded;
}

std::vector<uint8_t> MovRegRegInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x89; // MOV r32, r32
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_destination) + (static_cast<uint8_t>(m_source) * 8);
    return { opcode, extended };
}

std::vector<uint8_t> MovRegRegMemInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x8B; // MOV r32, r/m32
    const uint8_t extended = (static_cast<uint8_t>(m_destination) * 8) + static_cast<uint8_t>(m_source);
    return { opcode, extended };
}

std::vector<uint8_t> MovRegImmInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0xB8 + static_cast<uint8_t>(m_destination); // MOV r32, imm32
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> NoopInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x90; // NOOP
    return { opcode };
}

std::vector<uint8_t> PushImmInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x68; // PUSH imm32
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> PopRegInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x58 /* PUSH r32 */ + static_cast<uint8_t>(m_register);
    return { opcode };
}

std::vector<uint8_t> PushRegInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x50 /* PUSH r32 */ + static_cast<uint8_t>(m_register);
    return { opcode };
}

std::vector<uint8_t> PushRegMemByteInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0xFF; // PUSH r/m32
    const uint8_t extended = 0x70 + static_cast<uint8_t>(m_register);
    return { opcode, extended, *reinterpret_cast<const uint8_t*>(&m_offset) };
}

std::vector<uint8_t> PushRegMemDwordInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0xFF; // PUSH r/m32
    const uint8_t extended = 0xB0 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_offset, 4);
    return encoded;
}

std::vector<uint8_t> RetInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0xC3; // RET
    return { opcode };
}

std::vector<uint8_t> SubRegImmByteInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x83; // SUB r32, imm8
    const uint8_t extended = 0xE8 + static_cast<uint8_t>(m_register);
    return { opcode, extended, m_value };
}

std::vector<uint8_t> SubRegImmDwordInstruction::bytes(const uintptr_t) const
{
    const uint8_t opcode = 0x81; // SUB r32, imm32
    const uint8_t extended = 0xE8 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_value, 4);
    return encoded;
}

void patch(uintptr_t addr, uintptr_t end_addr, const std::vector<uint8_t>& data)
{
    DWORD old_protect;
    VirtualProtect((void*)addr, end_addr - addr, PAGE_READWRITE, &old_protect);

    memcpy((void*)addr, data.data(), data.size());
    NoopInstruction noop;
    size_t noops = data.size() - (end_addr - addr);
    for (size_t i = 0; i < noops; ++i)
    {
        memcpy((void*)(addr + data.size() + i), noop.bytes().data(), 1);
    }

    VirtualProtect((void*)addr, end_addr - addr, old_protect, &old_protect);
}

}
