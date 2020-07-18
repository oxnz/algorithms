/*
 * Filename:	test.cc
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2016-08-25 02:10:55 CST
 * Last-update:	2016-08-25 02:10:55 CST
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
#include <iterator>
#include <vector>
#include <gtest/gtest.h>
#include "algo.h"

TEST(algo, copy) {
    std::vector<int> v;
    std::string s = "1 2 3 4 5 ";
    std::istringstream iss(s);
    m::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(),
            std::back_inserter(v));
    std::ostringstream oss;
    m::copy(v.begin(), v.end(), std::ostream_iterator<int>(oss, " "));
    EXPECT_EQ(oss.str(), s);
}
