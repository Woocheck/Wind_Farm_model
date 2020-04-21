cmake_minimum_required(VERSION 3.8)
project(basic_test)

# Setup testing
enable_testing()

file( GLOB ALL_SOURCES test_files/*.cpp )
set( ALL_FILES main_test.cpp ${ALL_SOURCES})
set( EXEC main_test )

#target_link_libraries( gtest gtest_main )

add_definitions(-std=c++17 -Wall -pedantic -O1 -llapack -lblas -lgtest -lgtest_main)
add_executable( ${EXEC} ${ALL_FILES})

