project(graph)

configure_file(tinyG.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${PROJECT_NAME}
	"digraph.cpp"
	"graph.cpp"
	)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)
target_link_libraries(${PROJECT_NAME} gmock)
target_link_libraries(${PROJECT_NAME} benchmark)
gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${PROJECT_DIR})
