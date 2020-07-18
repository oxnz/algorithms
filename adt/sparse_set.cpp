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
#include <unordered_set>
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

TEST(sparse_set, for_each) {
    std::unordered_set<int> sep = {8, 9, 3, 2};
    m::sparse_set s(10);
    for (auto i : sep) s.insert(i);
    std::unordered_set<int> vals;
    s.foreach([&vals](int n)->void * { vals.insert(n); return 0; });
    EXPECT_EQ(sep, vals);
}

TEST(sparse_set, io) {
	std::unordered_set<int> sep = {8, 9, 3, 2};
    m::sparse_set s(10);
	for (int n : sep) {
        EXPECT_FALSE(s.contain(n));
        EXPECT_TRUE(s.insert(n));
        EXPECT_TRUE(s.contain(n));
	}
    for (int i = 0; i < 10; ++i) {
        if (sep.count(i)) EXPECT_TRUE(s.contain(i));
        else EXPECT_FALSE(s.contain(i));
    }
}

TEST(sparse_set, op) {
    std::unordered_set<int> sep = {8, 9, 3, 2};
    m::sparse_set s(10);
    for (auto i : sep) s.insert(i);
    s.remove(2);
    EXPECT_FALSE(s.contain(2));
    s.remove(3);
    EXPECT_FALSE(s.contain(3));
	s.clear();
    EXPECT_FALSE(s.contain(8));
    s.insert(3);
    EXPECT_TRUE(s.contain(3));
	s.insert(7);
    EXPECT_TRUE(s.contain(7));
	s.insert(4);
    EXPECT_TRUE(s.contain(4));
}
