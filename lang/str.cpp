//
//  str.cpp
//  Interview
//
//  Created by 云心逸 on 2018/12/31.
//  Copyright © 2018 Errpro,Inc. All rights reserved.
//

#include "str.hpp"

#include <vector>

#include <gtest/gtest.h>

using namespace std;

TEST(str, str) {
	str s1("hello"), s2("world"), s0(""), s;
	str s3 = "hello";
	EXPECT_EQ(5, s1.size()) << "invalid size";
	EXPECT_EQ(0, s.size()) << "invalid size";
	EXPECT_EQ(s0.size(), s.size()) << "invalid size";
	EXPECT_EQ(s1, s3) << "ne";
	EXPECT_EQ(s1[0], 'h') << "ne";
	s3[0] = 'w';
	str s4 = s1, s5 = s1 + s2;
	s4 += s2;
	EXPECT_NE(s1, s3) << "eq";
	EXPECT_EQ(s4, s5) << "operator+";
	EXPECT_TRUE(s1.compare("hello") == 0) << "compare";
	EXPECT_TRUE(s1.compare("Hello") != 0) << "compare";
	EXPECT_TRUE(s1.compare("Hello", str::case_insensitive) == 0) << "compare";
	vector<str> v = {s1, s2, s3, s4, s5};
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), less<str>());
	sort(v.begin(), v.end(), [](const str& lhs, const str& rhs){ return lhs.compare(rhs, str::case_insensitive) < 0; });
	EXPECT_TRUE(s1.contains("llo")) << "contains";
	EXPECT_FALSE(s1.contains("Hell")) << "contains";
	EXPECT_TRUE(s1.contains("Hell", str::case_insensitive)) << "contains";
	s1 = s1;
	EXPECT_EQ(s1, "hello") << "self assignment";
	swap(s1, s2);
	EXPECT_EQ(s1, "world") << "swap";
	str s6 = std::move(s1);
	EXPECT_TRUE(s1.empty()) << "move";
}
