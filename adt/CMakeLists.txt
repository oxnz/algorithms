cmake_minimum_required(VERSION 2.8)
project(adt)
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
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
