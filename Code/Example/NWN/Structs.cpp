#pragma once

#include "NWN/Structs.hpp"
#include "NWN/Addresses.hpp"
#include <string.h>

namespace nwn
{

CExoString::CExoString()
{
    // This isn't efficient, but keeps it simple.
    m_sString = (char*)ExoMalloc(1);
    m_nBufferLength = 0;
    *m_sString = '\0';
}

CExoString::CExoString(const char* str)
{
    m_nBufferLength = strlen(str);
    m_sString = (char*)ExoMalloc(m_nBufferLength + 1);
    memcpy(m_sString, str, m_nBufferLength + 1);
}

CExoString::CExoString(const CExoString& other)
    : CExoString(other.m_sString) // inefficient; recount string
{ }

CExoString& CExoString::operator=(const CExoString& other)
{
    m_nBufferLength = other.m_nBufferLength;
    m_sString = (char*)ExoMalloc(m_nBufferLength + 1);
    memcpy(m_sString, other.m_sString, m_nBufferLength + 1);
    return *this;
}

CExoString::~CExoString()
{
    ExoFree(m_sString);
}

}