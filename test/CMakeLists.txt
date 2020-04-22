
file(GLOB ALL_GRID_TESTS grid/*.cpp)
file(GLOB ALL_FILE_TESTS file/*.cpp)
file(GLOB ALL_ALGORITHMS_TESTS algorithms/*.cpp)
set(ALL_SOURCES ${ALL_GRID_TESTS} ${ALL_FILE_TESTS} ${ALL_ALGORITHMS_TESTS})

add_executable(
    unit_tests
    ${ALL_SOURCES}
    )

target_link_libraries(
    unit_tests
    gtest_main
    wind_farm_model
    )

add_test(
  NAME
    Wind_Farm_Model
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
