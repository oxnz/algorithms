project(leetcode)

add_executable(${PROJECT_NAME}
    "reorder_by_index.cpp"
    "edit_distance.cpp"
    "basic_calculator.cpp"
    "basic_calculator_II.cpp"
    "game_of_life.cpp"
    "snapshot_array.cpp"
    "insert_interval.cpp"
    "multiply_strings.cpp"
    "Subsets.cc"
    "SingleNumberIII.cpp"
    "leetcode.cpp"
    "sell_stock_2.cc"
    )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_DIR})

