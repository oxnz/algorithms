project(sorting)

find_package(benchmark REQUIRED)

add_executable(${PROJECT_NAME}
	"radix_sort.cpp"
        "heapsort_r.cpp"
        "heapsort.cpp"
        "quicksort.cpp"
        "mergesort.cpp"
        "bubble_sort.cpp"
        "insertion_sort.cpp"
        "selection_sort.cpp"
        "bucket_sort.cpp"
	)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_DIR})

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" PREFIX "Source Files" FILES ${FILE_LIST})

set(BENCHMARK "${PROJECT_NAME}_benchmark")
add_executable(${BENCHMARK}
    "benchmark.cpp"
    "heapsort_r.cpp"
    "heapsort.cpp"
    "quicksort.cpp"
    "mergesort.cpp"
    "bubble_sort.cpp"
    "insertion_sort.cpp"
    "selection_sort.cpp"
    "bucket_sort.cpp"
    )
target_compile_features(${BENCHMARK} PRIVATE cxx_std_17)
target_link_libraries(${BENCHMARK} Threads::Threads)
target_link_libraries(${BENCHMARK} GTest::GTest)
target_link_libraries(${BENCHMARK} gmock)
target_link_libraries(${BENCHMARK} benchmark::benchmark)
target_link_libraries(${BENCHMARK} benchmark::benchmark_main)
