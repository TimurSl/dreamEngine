#include "core/alloc/MallocAllocator.h"

#include <stdlib.h>

void* MallocAllocator::Allocate(size_t size, size_t alignment) { return std::malloc(size); }

void MallocAllocator::Deallocate(void* ptr) { std::free(ptr); }
