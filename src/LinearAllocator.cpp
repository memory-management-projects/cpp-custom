#include "LinearAllocator.h"

#include <memory>

namespace cpp_custom {

LinearAllocator::LinearAllocator(const std::size_t size)
    : Allocator(size), m_Offset(0) {
    m_StartAddress = ::operator new(size);
}

LinearAllocator::~LinearAllocator() {
    ::operator delete(m_StartAddress);
    m_StartAddress = nullptr;
}

void *LinearAllocator::Allocate(const std::size_t size, const std::size_t alignment) {
    void *currentAddress = reinterpret_cast<char *>(m_StartAddress) + m_Offset;
    std::size_t space = m_Size - m_Offset;
    std::align(alignment, size, currentAddress, space);

    if ((std::size_t)currentAddress + size > (std::size_t)m_StartAddress + m_Size)
        return nullptr;

    m_Offset = m_Size - space + size;

    return currentAddress;
}

void LinearAllocator::Deallocate(void *ptr) {
    (void)ptr;
}

void LinearAllocator::Reset() {
    m_Offset = 0;
}

} // namespace cpp_custom
