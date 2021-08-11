cmake_minimum_required(VERSION 3.19)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(evalfull
        evalfull.cpp
        intstack.h)
add_executable(usestack
        usestack.cpp
        intstack.h)

