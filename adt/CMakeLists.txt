project(adt)
<<<<<<< HEAD

add_library(${PROJECT_NAME} SHARED
    "btree.cpp"
    "forward_list.cpp"
    "rand.cpp"
    "static_vector.cpp"
    "disjoint_set.cpp"
    "sparse_set.cpp"
    "raw.cpp"
    "opt.cpp"
    "algo.cpp"
    "bitvec.cpp"
    "tree.cpp"
    "hash.cpp"
    "heap.cpp"
    "arr.cpp"
    "list.cpp"
    "trie.cpp"
    "queue.cpp"
    "basic.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
=======
set(CMAKE_CXX_STANDARD 17)
link_directories(/usr/local/lib)
include_directories(/usr/local/include)
add_executable(${PROJECT_NAME}
	"alg.cpp"
	"tree.cpp"
	"heap.cpp"
	"arr.cpp"
	"list.cpp"
	"queue.cpp"
	"hash.cpp"
	"random.cpp"
	"cache.cpp"
	"basic.cpp")
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4
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
add_executable(${TEST} "heap.cpp")
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
