add_executable(
    unit_tests
    example_add.cpp
    example_subtract.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    wind_farm_model
    )

add_test(
  NAME
    unit
  COMMAND
    #${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
    /home/woocheck/Workspace_model/Wind_Farm_model/build/bin
  )
