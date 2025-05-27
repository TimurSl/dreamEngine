#pragma once
#include "Allocator.h"


class MallocAllocator : public Allocator
{
public:
    void* Allocate(size_t size, size_t alignment) override;
    void Deallocate(void* ptr) override;
};
