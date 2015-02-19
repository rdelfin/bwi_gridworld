project(grid)

cmake_minimum_required(VERSION 2.8.1)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

add_library(grid SHARED src/grid.cpp)
