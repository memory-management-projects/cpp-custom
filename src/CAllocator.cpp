#include "includes/CAllocator.h"

cpp_custom::CAllocator::CAllocator() : Allocator(0) {}

void *cpp_custom::CAllocator::Allocate(const std::size_t size,
                                       const std::size_t alignment) {
  return ::operator new(size);
}

void cpp_custom::CAllocator::Deallocate(void *ptr) { ::operator delete(ptr); }

void cpp_custom::CAllocator::Reset() {}
