/*
 * Filename:	trie.c
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-09-03 20:43:57 CST
 * Last-update:	2015-09-03 20:43:57 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2015 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <gtest/gtest.h>
#include "trie.h"

TEST(trie, trie) {
    m::trie<26> t;
}

TEST(trie, insert) {
    m::trie<26> t;
    t.insert("hello");
    t.insert("world");
}

TEST(trie, count) {
    m::trie<26> t;
    EXPECT_EQ(t.count("hello"), 0);
    t.insert("hello");
    EXPECT_EQ(t.count("hello"), 1);
    t.insert("hey");
    EXPECT_EQ(t.count("he"), 2);
    t.insert("hi");
    EXPECT_EQ(t.count("h"), 3);
}

TEST(trie, iter) {
    m::trie<26> t;
    t.insert("hello");
    for (auto it = t.begin(); it != t.end(); ++it)
        std::cout << *it << "\n";
}
