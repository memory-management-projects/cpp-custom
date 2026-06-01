#include <gtest/gtest.h>
#include <includes/LinearAllocator.h>
#include <includes/StackAllocator.h>
#include <includes/PoolAllocator.h>
#include <includes/FreeListAllocator.h>
#include <includes/FreeTreeAllocator.h>
#include <includes/BuddyAllocator.h>

#include <vector>
#include <unordered_map>

#include "Utils.cpp"

constexpr std::size_t mb = 1024 * 1024;

TEST(AllocateTest, LinearAllocatorAllocation)
{
	cpp_custom::LinearAllocator alloc(mb);
	RandomAllocate(&alloc);
}

TEST(AllocateTest, StackAllocatorAllocation)
{
	cpp_custom::StackAllocator alloc(mb);
	RandomAllocateDeallocateLinearly(&alloc);
}

TEST(AllocateTest, PoolAllocatorAllocation)
{
	cpp_custom::PoolAllocator alloc(mb, 512, true);
	FixedAllocateDeallocate(&alloc, 512);
}

TEST(AllocateTest, FreeListAllocatorAllocation)
{
	cpp_custom::FreeListAllocator alloc(mb, A5::FreeListAllocator::SearchMethod::BEST);
	RandomAllocateDeallocate(&alloc);
}

TEST(AllocateTest, FreeTreeAllocatorAllocation)
{
	cpp_custom::FreeTreeAllocator alloc(mb);
	RandomAllocateDeallocate(&alloc);
}

TEST(AllocateTest, BuddyAllocatorAllocation)
{
	cpp_custom::BuddyAllocator alloc(mb);
	RandomAllocateDeallocate(&alloc);
}
