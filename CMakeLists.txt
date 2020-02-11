cmake_minimum_required(VERSION 3.10.0)

include(common.cmake)
project(algorithms
    VERSION 0.9.2.0
    DESCRIPTION "algorithms & data structures"
    HOMEPAGE_URL "https://github.com/oxnz/algorithms"
    LANGUAGES C CXX
    )
message(STATUS ${PROJECT_NAME})
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

configure_file(config.h.in config.h @ONLY)
include_directories(
    /usr/local/include
    ${CMAKE_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_BINARY_DIR}
    )
link_directories(/usr/local/lib)

add_subdirectory(lang)
add_subdirectory(adt)
add_subdirectory(exp)
add_subdirectory(mp)
