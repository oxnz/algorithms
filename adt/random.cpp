/*
 * Filename:	random_string_generator.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2018-12-25 17:54:35 CST
 * Last-update:	2018-12-25 17:54:35 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2018 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include "random.hpp"
#include "adt.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(random_string_generator, random_string_generator) {
	size_t n = 1<<3;
    vector<string> v;
	v.reserve(n);
	generate_n(back_inserter(v), n, r::random_string_generator<mt19937_64>("abcdefghijklmnopqrstuvwxyz", 2, 30));
	EXPECT_EQ(v.size(), n);
	for (const auto& s : v) {
		EXPECT_TRUE(s.length() >= 2);
		EXPECT_TRUE(s.length() <= 30);
	}
}

TEST(random_number_generator, random_number_generator) {
	size_t n = 1<<10;
	vector<int> v;
	v.reserve(n);
	generate_n(back_inserter(v), n, r::random_number_generator<int>(0, 100));
	EXPECT_EQ(v.size(), n);
	for (auto i : v) {
		EXPECT_TRUE(i >= 0);
		EXPECT_TRUE(i <= 100);
	}
}

template <typename BidirectionalIterator>
bool next_perm(BidirectionalIterator first, BidirectionalIterator last) {
	if (first == last || first+1 == last) return false;
	using T = typename std::iterator_traits<BidirectionalIterator>::value_type;
	auto it = last-1;
	auto cmp = std::less<T>();
	while (it != first && !cmp(*(it-1), *(it)))
		--it;
	if (it == first) { reverse(first, last); return false; }
	--it;
	auto rit = last-1;
	while (rit != it && !cmp(*it, *rit))
		--rit;
	std::iter_swap(it, rit);
	std::reverse(it+1, last);
	return true;
}

TEST(permutation, permutation) {
	string s("1224");
	vector<string> v;
	do {
		v.push_back(s);
	} while (next_perm(s.begin(), s.end()));
	ASSERT_EQ(12, v.size());
	EXPECT_EQ(s, v.front());
	EXPECT_EQ("1242", v[1]);
	EXPECT_EQ("4221", v.back());
}

