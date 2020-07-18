project(mp)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)
find_package(benchmark REQUIRED)
find_package(OpenMP)

CHECK_INCLUDE_FILE("omp.h" HAVE_OMP_H)

add_library(${PROJECT_NAME}
    "thread_pool.cpp"
    "pi.cpp"
    )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set(TEST "${PROJECT_NAME}_unittest")
add_executable(${TEST} pi.cpp)
target_compile_features(${TEST} PRIVATE cxx_std_17)
target_link_libraries(${TEST} ${PROJECT_NAME})
target_link_libraries(${TEST} Threads::Threads)
target_link_libraries(${TEST} GTest::GTest)
target_link_libraries(${TEST} gmock)
target_link_libraries(${TEST} benchmark::benchmark)
target_link_libraries(${TEST} GTest::Main)
gtest_add_tests(TARGET ${TEST} WORKING_DIRECTORY ${PROJECT_DIR})

set(BENCHMARK "${PROJECT_NAME}_benchmark")
add_executable(${BENCHMARK} pi.cpp)
target_compile_features(${BENCHMARK} PRIVATE cxx_std_17)
target_link_libraries(${BENCHMARK} ${PROJECT_NAME})
target_link_libraries(${BENCHMARK} Threads::Threads)
target_link_libraries(${BENCHMARK} GTest::GTest)
target_link_libraries(${BENCHMARK} gmock)
target_link_libraries(${BENCHMARK} benchmark::benchmark)
target_link_libraries(${BENCHMARK} benchmark::benchmark_main)

if (OpenMP_CXX_FOUND)
    target_link_libraries(${TEST} OpenMP::OpenMP_CXX)
    target_link_libraries(${BENCHMARK} OpenMP::OpenMP_CXX)
endif()

