#pragma once
#include <cstdint>

#include "Allocator.h"

// Linear arena allocator (без free для каждого блока, только Reset)
class ArenaAllocator : public Allocator
{
public:
    explicit ArenaAllocator(size_t totalSize);
    ~ArenaAllocator();

    void* Allocate(size_t size, size_t alignment = alignof(std::max_align_t)) override;

    void Deallocate(void* ptr) override
    {
    } // ничего не делает
    void Reset();

private:
    char* m_Buffer;
    size_t m_Offset;
    size_t m_TotalSize;
};
