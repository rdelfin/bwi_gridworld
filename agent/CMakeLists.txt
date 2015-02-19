project(agent)

cmake_minimum_required(VERSION 2.8.1)
cmake_policy(SET CMP0015 NEW)

set (GRID_LOCATION ../grid)


include_directories(${GRID_LOCATION}/include include)

add_library(agent SHARED src/RandomAgent.cpp)
 
 
