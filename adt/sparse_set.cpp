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
        SparseSetTest() : s(10) {}
        ~SparseSetTest() {}

		static void SetUpTestCase() {
		}

		static void TearDownTestCase() {
		}

		void SetUp() {
		}

		void TearDown() {
		}
        m::sparse_set s;
	};
}

TEST_F(SparseSetTest, insert) {
	EXPECT_TRUE(s.insert(1));
	EXPECT_EQ(1, s.size());
	EXPECT_FALSE(s.empty());

	EXPECT_FALSE(s.insert(1));
	EXPECT_EQ(1, s.size());
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

TEST(sparse_set, empty) {
    size_t n = 10;
    m::sparse_set s(n);
    EXPECT_EQ(s.capacity(), n);
    EXPECT_EQ(0, s.size());
    EXPECT_TRUE(s.empty());
}

TEST(sparse_set, sparse_set) {
	int sep[] = {8, 9, 3, 2};
    m::sparse_set s(10);
    std::cout << s << "\n";
	for (int n : sep) {
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
		printf("insert %d %s\n", n, s.insert(n) ? "success" : "failure");
		printf("contain %d = %s\n", n, s.contain(n) ? "yes" : "no");
	}
    std::cout << s << "\n";
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
    std::cout << s << "\n";
    s.insert(3);
	s.insert(7);
	s.insert(4);
    std::cout << s << "\n";
//    s.xchg(3, 7);
	printf("after swap(3, 7):\n");
    std::cout << s << "\n";
//    s.xchg(3, 4);
	printf("after swap(3, 4):\n");
    std::cout << s << "\n";
}
