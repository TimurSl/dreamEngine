#pragma once
#include <cstddef>

class Allocator
{
public:
    virtual void* Allocate(size_t size, size_t alignment = alignof(std::max_align_t)) = 0;
    virtual void Deallocate(void* ptr) = 0;
    virtual ~Allocator() = default;
};
