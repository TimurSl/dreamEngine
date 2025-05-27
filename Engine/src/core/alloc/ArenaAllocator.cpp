#include "core/alloc/ArenaAllocator.h"

#include <cstdlib>
#include <cassert>

ArenaAllocator::ArenaAllocator(size_t totalSize)
{
    m_Buffer = static_cast<char*>(malloc(totalSize));
    assert(m_Buffer != nullptr && "ArenaAllocator: malloc failed!");
    m_TotalSize = totalSize;
    m_Offset = 0;
}

ArenaAllocator::~ArenaAllocator()
{
    std::free(m_Buffer);
}

void* ArenaAllocator::Allocate(size_t size, size_t alignment)
{
    size_t current = reinterpret_cast<size_t>(m_Buffer) + m_Offset;
    size_t aligned = (current + alignment - 1) & ~(alignment - 1);
    size_t padding = aligned - current;
    if (m_Offset + padding + size > m_TotalSize)
    {
        assert(false && "ArenaAllocator: out of memory!");
        return nullptr;
    }
    void* ptr = m_Buffer + m_Offset + padding;
    m_Offset += padding + size;
    return ptr;
}

void ArenaAllocator::Reset()
{
    m_Offset = 0;
}
