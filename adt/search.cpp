//
//  search.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/16.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <gtest/gtest.h>
#include "search.hpp"

TEST(union_find, union_find) {
	std::vector<std::pair<uint32_t, uint32_t>> edges {
		{4, 3},
		{3, 8},
		{6, 5},
		{9, 4},
		{2, 1},
		{8, 9},
		{5, 0},
		{7, 2},
		{6, 1},
		{1, 0},
		{6, 7}
	};
	search::union_find<uint32_t> uf(10);
	for (const auto& edge : edges)
		uf.connect(edge);
	EXPECT_EQ(2, uf.count());
}
