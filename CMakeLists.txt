cmake_minimum_required(VERSION 3.10.0)

include(common.cmake)
include(CMakePrintHelpers)

project(algorithms
    VERSION 0.9.2.0
    DESCRIPTION "algorithms & data structures"
    HOMEPAGE_URL "https://github.com/oxnz/algorithms"
    LANGUAGES C CXX
    )

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
cmake_print_variables(PROJECT_NAME)
cmake_print_variables(CONFIGURATION)

message(STATUS "project: ${PROJECT_NAME}")
message(DEBUG "configuration: ${CONFIGURATION}")
message(DEBUG "")
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

configure_file(config.h.in config.h @ONLY)
configure_file(libalgo.pc.in libalgo.pc @ONLY)
include_directories(
    /usr/local/include
    ${CMAKE_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_BINARY_DIR}
    )
link_directories(/usr/local/lib)

add_subdirectory(sorting)
add_subdirectory(graph)
add_subdirectory(lang)
add_subdirectory(adt)
add_subdirectory(exp)
add_subdirectory(mp)

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
add_definitions(-DALGO -DAUTHOR="Max.Z")
add_compile_options("$<$<CONFIG:DEBUG>:-DDEBUG>")

#export(TARGETS MyLib1 MyLib2 NAMESPACE MyLib:: FILE MyLibTargets.cmake)

add_custom_target(debug)
add_custom_command(TARGET debug PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
    COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
    )

add_custom_target(release)
add_custom_command(TARGET release PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
    COMMENT "Switch CMAKE_BUILD_TYPE to Release"
    )

add_custom_target(run COMMAND algo
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Run with ${CMAKE_BUILD_TYPE} configuration"
    )

# Packaging support
set(CPACK_PACKAGE_VENDOR "Max.Z")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "algorithms and data structus")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_SOURCE_IGNORE_FILES
    /.git
    /dist
    /.*build.*
    /\\\\.DS_Store
)
include(CPack)
