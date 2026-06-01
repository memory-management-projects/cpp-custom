#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "Allocator.h"

namespace cpp_custom {
class StackAllocator : public Allocator {
private:
    using Header = unsigned char;
    std::size_t m_Offset;

public:
    StackAllocator(const std::size_t size);
    ~StackAllocator() override;
    void *Allocate(const std::size_t size, const std::size_t alignment) override;
    void Deallocate(void *ptr) override;
    void Reset() override;
};
} // namespace cpp_custom

#endif // !STACK_ALLOCATOR_H
