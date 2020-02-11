project(adt)

add_executable(${PROJECT_NAME}
        "raw.cpp"
        "opt.cpp"
        "algo.cpp"
        "bitvec.cpp"
	"tree.cpp"
	"heap.cpp"
	"arr.cpp"
	"list.cpp"
	"trie.cpp"
	"queue.cpp"
	"hash.cpp"
	"basic.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_DIR})
