# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.6)
project(untitled C)

set(CMAKE_C_STANDARD 99)
add_library(heap STATIC heap.c heap.h)
add_executable(untitled main.c)
TARGET_LINK_LIBRARIES(untitled heap)

add_executable(tests tests.c)
TARGET_LINK_LIBRARIES(tests heap)
