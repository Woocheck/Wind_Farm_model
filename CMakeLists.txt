
cmake_minimum_required(VERSION 3.8)
project(WindFarmModel)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(googletest)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

file(GLOB ALL_GRID grid/*.cpp)
file(GLOB ALL_FILE file/*.cpp)
file(GLOB ALL_ALGORITHMS algorithms/*.cpp)
set(ALL_SOURCES main.cpp ${ALL_GRID} ${ALL_FILE} ${ALL_ALGORITHMS})
set(EXEC main)


include_directories( file grid algorithms )
add_definitions(-std=c++17 -Wall -pedantic -O1 -llapack -lblas)
add_executable( ${EXEC} ${ALL_SOURCES})

target_link_libraries(${EXEC} ${ARMADILLO_LIBRARIES})
