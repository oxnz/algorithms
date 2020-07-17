#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <random>
#include <deque>
#include <list>
#include <forward_list>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

template<typename ForwardIterator>
void echo(ForwardIterator first, ForwardIterator last) {
	std::copy(first, last, std::ostream_iterator<typename iterator_traits<ForwardIterator>::value_type>(std::cout, ", "));
	std::cout << "\n";
}

template<typename Container>
void echo(Container container) {
	echo(container.begin(), container.end());
}

class MinimalistPrinter : public ::testing::EmptyTestEventListener {
	// Called before a test starts.
	virtual void OnTestStart(const ::testing::TestInfo& test_info) {
//		printf("*** Test %s.%s starting.\n",
//			   test_info.test_case_name(), test_info.name());
	}

	// Called after a failed assertion or a SUCCESS().
	virtual void OnTestPartResult(const ::testing::TestPartResult& test_part_result) {
//		printf("%s in %s:%d\n%s\n",
//			   test_part_result.failed() ? "*** Failure" : "Success",
//			   test_part_result.file_name(),
//			   test_part_result.line_number(),
//			   test_part_result.summary());
	}

	// Called after a test ends.
	virtual void OnTestEnd(const ::testing::TestInfo& test_info) {
//		printf("*** Test %s.%s ending.\n",
//			   test_info.test_case_name(), test_info.name());
	}
	};

//int main(int argc, char** argv) {
//	::testing::InitGoogleTest(&argc, argv);
//	// Gets hold of the event listener list.
//	::testing::TestEventListeners& listeners =
//	::testing::UnitTest::GetInstance()->listeners();
//	// Adds a listener to the end.  googletest takes the ownership.
////	listeners.Append(new MinimalistPrinter);
//	return RUN_ALL_TESTS();
//}
