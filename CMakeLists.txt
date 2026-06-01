cmake_minimum_required(VERSION 3.5)

project(cpp-custom LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/CAllocator.cpp
    src/LinearAllocator.cpp
    src/StackAllocator.cpp
    src/PoolAllocator.cpp
    src/FreeListAllocator.cpp
    src/FreeTreeAllocator.cpp
    src/BuddyAllocator.cpp
    src/LinkedList.cpp
    src/RBTree.cpp
)

add_library(cpp_custom STATIC ${SOURCES})
target_include_directories(cpp_custom PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_features(cpp_custom PUBLIC cxx_std_11)
