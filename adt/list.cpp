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

#include <gtest/gtest.h>
#include "list.h"

TEST(list, push_back) {
    m::list<int> v;
    size_t n = 10;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
        EXPECT_EQ(v.back(), i);
    }
    EXPECT_EQ(v.size(), n);
}

TEST(list, push_front) {
    m::list<int> v;
    size_t n = 10;
    for (int i = 0; i < n; ++i) {
        v.push_front(i);
        EXPECT_EQ(v.front(), i);
    }
    EXPECT_EQ(v.size(), n);
}

TEST(list, insert) {
    m::list<int> v;
    size_t n = 10;
    for (int i = 0; i < n; ++i) {
        v.insert(v.end(), i);
        EXPECT_EQ(v.back(), i);
    }
}

TEST(list, erase) {
    m::list<int> v;
    size_t n = 10;
    for (int i = 0; i < n; ++i) v.push_back(i);
    for (int i = 0; i < n; ++i) v.erase(v.begin());
    EXPECT_EQ(v.size(), 0);
}

TEST(list, r_iter) {
    return;
    m::list<int> v;
    size_t n = 10;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
        EXPECT_EQ(*(v.crbegin()), i);
    }
}
