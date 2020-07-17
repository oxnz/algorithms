//
//  sort.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/7.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include "sort.hpp"
#include "../adt/adt.hpp"
#include "../adt/random.hpp"

#include <gtest/gtest.h>

using namespace std;

TEST(sort, correctness) {
	vector<int> v;
	v.reserve(1<<11);
    auto rng = r::random_number_generator<int>(0, 100);
	for (size_t i = 0; i < 10; ++i) {
        generate_n(back_inserter(v), 1<<i, rng);
        shuffle(v.begin(), v.end(), mt19937());
		sort::bubble_sort(v.begin(), v.end());
        EXPECT_TRUE(is_sorted(v.begin(), v.end()));
		shuffle(v.begin(), v.end(), mt19937());
		sort::insertion_sort(v.begin(), v.end());
		EXPECT_TRUE(is_sorted(v.begin(), v.end()));
		shuffle(v.begin(), v.end(), mt19937());
		sort::selection_sort(v.begin(), v.end());
		EXPECT_TRUE(is_sorted(v.begin(), v.end()));
	}
}

TEST(sort, merge) {
	vector<int> v1{1,3,5,7,9}, v2{0,2,6}, v3{4,8}, v;
    using iter = vector<int>::iterator;
    vector<std::pair<iter, iter>> iters;
    iters.emplace_back(v1.begin(), v1.end());
    iters.emplace_back(v2.begin(), v2.end());
	iters.emplace_back(v3.begin(), v3.end());
	sort::merge<int>(iters.begin(), iters.end(), back_inserter(v), [](auto p1, auto p2) {
		return p1 > p2;
	});
	EXPECT_EQ(10, v.size());
    for (unsigned long i = 0; i < 10; ++i)
		EXPECT_EQ(i, v[i]);
}

TEST(sort, topology) {
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 3}, {3, 4}
    };
    auto v = sort::topology_sort(edges);
    EXPECT_EQ(4, v.size());
    EXPECT_EQ(1, v[0]);
    EXPECT_EQ(2, v[1]);
    EXPECT_EQ(3, v[2]);
    EXPECT_EQ(4, v[3]);
}
