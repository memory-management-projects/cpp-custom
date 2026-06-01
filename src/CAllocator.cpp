#include "CAllocator.h"

namespace cpp_custom {

CAllocator::CAllocator() : Allocator(0) {}

void *CAllocator::Allocate(const std::size_t size, const std::size_t alignment) {
    (void)alignment;
    return ::operator new(size);
}

void CAllocator::Deallocate(void *ptr) {
    ::operator delete(ptr);
}

void CAllocator::Reset() {}

} // namespace cpp_custom
