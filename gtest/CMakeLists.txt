cmake_minimum_required(VERSION 3.8)

set( This ModelTests)

set(Sources
    testNode.cpp)

add_definitions(-std=c++17 -Wall -pedantic -O1 -llapack -lblas -lgtest)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)