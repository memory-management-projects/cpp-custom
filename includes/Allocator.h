#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

namespace cpp_custom {
class Allocator {
protected:
    std::size_t m_Size;
    void *m_StartAddress;

    Allocator(const std::size_t size) : m_Size(size), m_StartAddress(nullptr) {}

public:
    virtual ~Allocator() = default;
    virtual void *Allocate(const std::size_t size, const std::size_t alignment) = 0;
    virtual void Deallocate(void *ptr) = 0;
    virtual void Reset() = 0;
};
} // namespace cpp_custom

#endif // !ALLOCATOR_H
