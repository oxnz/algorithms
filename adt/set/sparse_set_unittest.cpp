/*
 * Filename:	sparse-dense_unittest.cc
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2014-11-30 01:53:46 CST]
 * Last-update:	2014-11-30 01:53:46 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <gtest/gtest.h>
#include "sparse_set.h"

using namespace std;

namespace {
	class SparseSetTest : public ::testing::Test {
	protected:
		SparseSetTest() {}
		~SparseSetTest() {}

		static void SetUpTestCase() {
			cout << "case up" << endl;
		}

		static void TearDownTestCase() {
			cout << "case down" << endl;
		}

		void SetUp() {
			cout << "setup" << endl;
		}

		void TearDown() {
			cout << "teardown" << endl;
		}
		SparseSet s;
	};
}

TEST_F(SparseSetTest, init) {
	EXPECT_EQ(100, s.capacity());
	EXPECT_EQ(0, s.count());
	EXPECT_TRUE(s.empty());
}

TEST_F(SparseSetTest, insert) {
	EXPECT_TRUE(s.insert(1));
	EXPECT_EQ(1, s.count());
	EXPECT_FALSE(s.empty());

	EXPECT_FALSE(s.insert(1));
	EXPECT_EQ(1, s.count());
}

TEST_F(SparseSetTest, remove) {
	EXPECT_TRUE(s.insert(3));
	EXPECT_FALSE(s.remove(1));
	EXPECT_TRUE(s.remove(3));
	EXPECT_FALSE(s.remove(3));
	EXPECT_FALSE(s.contain(4));
	EXPECT_TRUE(s.insert(4));
	EXPECT_TRUE(s.contain(4));
}

int foo() {
	int sep[] = {8, 9, 3, 2};
	SparseSet s(10);
	s.inspect();
	for (int n : sep) {
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
		printf("insert %d %s\n", n, s.insert(n) ? "success" : "failure");
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
	}
	s.inspect();
	for (int i = 0; i < 10; ++i) {
		printf("contain %d = %s\n", i, s.contain(i) ? "yes" : "no");
	}
	s.foreach([](int n)->void * { printf("[%d]", n); return 0; });
	putchar('\n');
	s.remove(2);
	s.remove(3);
	for (int i = 0; i < 10; ++i) {
		printf("contain %d = %s\n", i, s.contain(i) ? "yes" : "no");
	}
	s.clear();
	s.inspect();
	s.insert(3);
	s.insert(7);
	s.insert(4);
	s.inspect();
	s.xchg(3, 7);
	printf("after swap(3, 7):\n");
	s.inspect();
	s.xchg(3, 4);
	printf("after swap(3, 4):\n");
	s.inspect();

	return 0;
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
