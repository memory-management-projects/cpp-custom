#include "includes/LinearAllocator.h"

#include <memory>

cpp_custom::LinearAllocator::LinearAllocator(const std::size_t size)
	: Allocator(size), m_Offset(0)
{
	m_StartAddress = ::operator new(size);
}

cpp_custom::LinearAllocator::~LinearAllocator()
{
	::operator delete(m_StartAddress);
	m_StartAddress = nullptr;
}

void* cpp_custom::LinearAllocator::Allocate(const std::size_t size, const std::size_t alignment)
{
	void* currentAddress = reinterpret_cast<char*>(m_StartAddress) + m_Offset;
	std::size_t space = m_Size - m_Offset;
	std::align(alignment, size, currentAddress, space);

	if ((std::size_t)currentAddress + size > (std::size_t)m_StartAddress + m_Size)
		return nullptr;

	m_Offset = m_Size - space + size;

	return currentAddress;
}

void cpp_custom::LinearAllocator::Deallocate(void* ptr) {}

void cpp_custom::LinearAllocator::Reset()
{
	m_Offset = 0;
}
