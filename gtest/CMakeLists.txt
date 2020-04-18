cmake_minimum_required(VERSION 3.8)

set( This ModelTests)

set(Sources
    nodeTests.cpp)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Wind_Farm_model/grid

)

add_test(
    NAME ${This}
    COMMAND ${This}
)