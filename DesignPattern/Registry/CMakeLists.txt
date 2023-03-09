cmake_minimum_required(VERSION 3.22)
project(Registry)

set(CMAKE_CXX_STANDARD 17)
add_executable(main main.cpp registry.h registry.cpp)