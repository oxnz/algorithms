cmake_minimum_required(VERSION 2.8)
project(spatial)
set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME}
	"rect.cpp"
	)
target_link_libraries(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
