/*
 * Filename:	main.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2020-02-13 00:54:42 CST
 * Last-update:	2020-02-13 00:54:42 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2020 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include "config.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << argv[0] << ":";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << "\n";

    return 0;
}

<<<<<<< HEAD
=======
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
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4
