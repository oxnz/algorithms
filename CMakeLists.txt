cmake_minimum_required(VERSION 3.10.0)
project(algorithms)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

link_directories(/usr/local/lib)

add_subdirectory(lang)
add_subdirectory(adt)
add_subdirectory(exp)
add_subdirectory(mp)

include_directories(/usr/local/include
${PROJECT_SOURCE_DIR}/inc
)
