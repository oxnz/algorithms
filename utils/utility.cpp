//
//  utility.cpp
//  Interview
//
//  Created by 云心逸 on 2018/12/31.
//  Copyright © 2018 Errpro,Inc. All rights reserved.
//

#include "utility.h"

#include <gtest/gtest.h>

using namespace std;

class B {};
class D : B {};
class T {};

TEST(utility, utility) {
	auto a{is_same_type<B, B>()}, b{is_same_type<D, D>()}, c{is_same_type<B, D>()}, d{is_same_type<D, B>()};
	EXPECT_TRUE(a and b);
	EXPECT_FALSE(c or d);
}
