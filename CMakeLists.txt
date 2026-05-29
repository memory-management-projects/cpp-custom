cmake_minimum_required(VERSION 3.5)

project(cpp-custom LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES )

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_compile_features(main PRIVATE cxx_std_11)
