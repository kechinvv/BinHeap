# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.6)
project(untitled C)

set(CMAKE_C_STANDARD 99)
add_library(heap STATIC heap.c heap.h)
set(SOURCE_FILES main.c)
file(GLOB SOURCES *.h *.c)
add_executable(untitled ${SOURCE_FILES} ${SOURCES})
TARGET_LINK_LIBRARIES(untitled heap)


