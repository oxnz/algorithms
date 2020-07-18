project(image)

add_library(${PROJECT_NAME} SHARED
    "image.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)

set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER ${PROJECT_DIR})
cmake_print_properties(
    TARGETS ${PROJECT_NAME}
    PROPERTIES POSITION_INDEPENDENT_CODE
)

set(TEST "${PROJECT_NAME}_unittest")
add_executable(${TEST} "image.cpp")
target_compile_features(${TEST} PRIVATE cxx_std_17)
target_link_libraries(${TEST} ${PROJECT_NAME})
target_link_libraries(${TEST} Threads::Threads)
target_link_libraries(${TEST} GTest::GTest)
target_link_libraries(${TEST} gmock)
target_link_libraries(${TEST} GTest::Main)
gtest_discover_tests(${TEST}
    WORKING_DIRECTORY ${PROJECT_DIR}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "PROJECT_DIR"
    )


install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${TEST} DESTINATION bin)
install(FILES "${PROJECT_NAME}.h" DESTINATION include)
