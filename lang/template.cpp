//
//  template.cpp
//  Interview
//
//  Created by 云心逸 on 2019/1/1.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#include "template.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(fibonacci, fibonacci) {
	EXPECT_EQ(1, fibonacci<0>::value);
	EXPECT_EQ(1, fibonacci<1>::value);
	EXPECT_EQ(2, fibonacci<2>::value);
	EXPECT_EQ(3, fibonacci<3>::value);
	EXPECT_EQ(5, fibonacci<4>::value);
	EXPECT_EQ(5, fib(4));
	EXPECT_EQ(5, fib_it(4));
}

TEST(crtp, crtp) {
	circle c;
	EXPECT_EQ(circle::name(), "circle");
	EXPECT_EQ(c.render(), "circle");
	square s;
	EXPECT_EQ(square::name(), "square");
	EXPECT_EQ(s.render(), "square");
}


template <typename T, std::size_t N>
std::enable_if_t<std::is_integral_v<T> and N < 128>
insertion_sort(std::array<T, N>& arr) {
	for (size_t i = 0; i < N; ++i)
		for (size_t j = i; j > 0 and arr[j] < arr[j-1]; --j)
			std::swap(arr[j], arr[j-1]);
}

