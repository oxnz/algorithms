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

using namespace std;

template<typename T>
class Q {
public:
	void enq(T v) { m_in_stack.push(v); }
	T deq() {
		if (m_out_stack.empty())
			while (!m_in_stack.empty()) {
				m_out_stack.push(m_in_stack.top());
				m_in_stack.pop();
			}
		T v = m_out_stack.top();
		m_out_stack.pop();
		return v;
	}
	bool empty() const { return m_in_stack.empty() && m_out_stack.empty(); }
private:
	std::stack<T> m_in_stack; // in stack
	std::stack<T> m_out_stack; // out stack
};

TEST(queue, queue) {
	Q<int> q;
	EXPECT_TRUE(q.empty()) << "queue not empty";
	q.enq(1);
	EXPECT_FALSE(q.empty()) << "queue empty";
	q.enq(2);
	q.enq(3);
	q.enq(4);
	q.enq(5);
}
