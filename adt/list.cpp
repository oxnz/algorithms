/*
 * Filename:	test.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-05-20 18:18:44 CST]
 * Last-update:	2015-05-20 18:18:44 CST
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
#include "adt.hpp"
#include <gtest/gtest.h>

using namespace list;

int test_reverse() {
    ForwardListNode<int> list(0);
    ForwardListNode<int> nodes[10]{1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; ++i) {
        list::list_insert(list, nodes[i]);
    }

    echo(&list);
    ForwardListNode<int> *p = reverse(&list);
    echo(p);
    echo(reverse_n(p, 3));
    list_erase(list, &nodes[4]);
    list_erase(list, &nodes[6]);
    list_erase(list, &nodes[8]);
    echo(reverse(p));

    return 0;
}

TEST(list, reverse2) {
	using Node = ForwardListNode<int>;
	Node nodes[5] {1, 2, 3, 4, 5};
	int expected[] {2, 1, 4, 3, 5};
	for (int i = 0; i < 4; ++i) {
		nodes[i].next = &nodes[i+1];
	}
	EXPECT_TRUE(nodes[1].next == &nodes[2]);
	EXPECT_TRUE(nodes[4].next == nullptr);
	Node *lst = list::reverse2<int>(&nodes[0]);
	int i = 0;
	for (Node* p = lst; p; p = p->next) {
		EXPECT_EQ(expected[i++], p->value);
	}
	EXPECT_EQ(i, 5);
	lst = nullptr;
	EXPECT_EQ(nullptr, reverse2<int>(lst));
}

TEST(list, sort) {
	using Node = ForwardListNode<int>;
	Node nodes[5]{5,4,3,2,1};
	Node *p = nullptr;
	list::sort(p, std::less<int>());
	EXPECT_EQ(nullptr, p);
	p = &nodes[0];
	EXPECT_EQ(p, list::sort(p, std::less<int>()));
	p->next = &nodes[1];
	p->next->next = &nodes[2];
	p->next->next->next = &nodes[3];
	p->next->next->next->next = &nodes[4];
	auto sorted = list::sort(p, std::less<int>());
	EXPECT_EQ(1, sorted->value);
}
