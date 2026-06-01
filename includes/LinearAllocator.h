#ifndef LINEAR_ALLOCATOR_H
#define LINEAR_ALLOCATOR_H

#include "Allocator.h"

namespace cpp_custom {
class LinearAllocator : public Allocator {
private:
    std::size_t m_Offset;

public:
    LinearAllocator(const std::size_t size);
    ~LinearAllocator() override;
    void *Allocate(const std::size_t size, const std::size_t alignment) override;
    void Deallocate(void *ptr) override;
    void Reset() override;
};
} // namespace cpp_custom

#endif // !LINEAR_ALLOCATOR_H
