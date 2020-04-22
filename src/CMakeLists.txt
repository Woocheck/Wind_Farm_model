add_library(wind_farm_model "")

file(GLOB ALL_GRID grid/*.cpp)
file(GLOB ALL_FILE file/*.cpp)
file(GLOB ALL_ALGORITHMS algorithms/*.cpp)
set(ALL_SOURCES main_wind_farm.cpp ${ALL_GRID} ${ALL_FILE} ${ALL_ALGORITHMS})

file(GLOB ALL_GRID_H grid/*.h)
file(GLOB ALL_FILE_H file/*.h)
file(GLOB ALL_ALGORITHMS_H algorithms/*.h)
set(ALL_SOURCES_H ${ALL_GRID_H} ${ALL_FILE_H} ${ALL_ALGORITHMS_H})

target_sources(
    wind_farm_model 
    PRIVATE
        ${ALL_SOURCES}
    PUBLIC
        ${ALL_SOURCES_H}
    )

target_include_directories(
    wind_farm_model 
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
