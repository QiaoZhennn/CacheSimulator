cmake_minimum_required(VERSION 3.8)
project(cachesim)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cacheline.cpp cacheline.h set.cpp set.h cache.cpp cache.h driver.cpp driver.h)
add_executable(cachesim ${SOURCE_FILES})