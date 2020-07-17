//
//  alg.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/9.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include "adt.hpp"
#include "alg.hpp"

#include <gtest/gtest.h>

TEST(algorithm, nth_element) {
	using iv = std::vector<int>;
	iv v{5, 4, 3, 2, 1};
    nz::nth_element(v.begin(), v.begin(), v.end());
	EXPECT_EQ(v[0], 1);
	nz::nth_element(v.begin(), v.begin()+1, v.end());
	EXPECT_EQ(v[1], 2);
	v = {3,2,1,5,6,4};
	nz::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<>());
	echo(v);
}
