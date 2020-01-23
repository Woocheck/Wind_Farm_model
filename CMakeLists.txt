
cmake_minimum_required(VERSION 3.8)
project(advcpp CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ALL_GRID grid/*.cpp)
file(GLOB ALL_FILE file/*.cpp)
set(ALL_SOURCES main.cpp ${ALL_GRID} ${ALL_FILE})
set(EXEC main)

include_directories( file grid )
add_definitions(-std=c++17 -Wall -pedantic)
add_executable( ${EXEC} ${ALL_SOURCES})