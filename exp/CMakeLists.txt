project(exp)
<<<<<<< HEAD

=======
set(CMAKE_CXX_STANDARD 11)
link_directories(/usr/local/lib)
include_directories(/usr/local/include)
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4
add_executable(${PROJECT_NAME} "exp.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_DIR})
