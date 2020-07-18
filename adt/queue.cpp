/*
 * Filename:	queue.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-07-12 01:53:58 CST
 * Last-update:	2016-07-12 01:53:58 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2016 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <stack>
#include <gtest/gtest.h>

#include "queue.hpp"

using namespace std;

TEST(queue, Q) {
	queue::Q<int> q;
	EXPECT_TRUE(q.empty()) << "queue not empty";
	q.enq(1);
	EXPECT_FALSE(q.empty()) << "queue empty";
	q.enq(2);
	q.enq(3);
	q.enq(4);
	q.enq(5);
}

TEST(queue, queue) {
	queue::queue<int> q(3);
	EXPECT_TRUE(q.empty());
	EXPECT_EQ(q.capacity(), 3);
	q.enq(1);
	EXPECT_EQ(q.back(), 1);
	EXPECT_EQ(q.front(), 1);
	EXPECT_EQ(q.size(), 1);
	EXPECT_FALSE(q.empty());
	q.enq(2);
	EXPECT_EQ(q.front(), 1);
	EXPECT_EQ(q.back(), 2);
	EXPECT_EQ(q.size(), 2);
	q.enq(3);
	EXPECT_EQ(q.size(), q.capacity());
	EXPECT_EQ(q.size(), 3);
	EXPECT_THROW(q.enq(4), std::runtime_error);
	EXPECT_EQ(1, q.front());
	EXPECT_EQ(3, q.back());
	q.deq();
	EXPECT_EQ(q.size(), 2);
	EXPECT_EQ(2, q.front());
	EXPECT_EQ(3, q.back());
	q.enq(4);
	EXPECT_EQ(2, q.front());
	EXPECT_EQ(3, q.size());
	EXPECT_EQ(4, q.back());
	q.deq();
	EXPECT_EQ(3, q.front());
	EXPECT_EQ(4, q.back());
	EXPECT_EQ(q.size(), 2);
	EXPECT_FALSE(q.empty());
	q.enq(5);
	EXPECT_EQ(5, q.back());
	q.deq();
	q.deq();
	q.deq();
	EXPECT_EQ(q.size(), 0);
	EXPECT_TRUE(q.empty());
	EXPECT_THROW(q.deq(), std::runtime_error);
}
