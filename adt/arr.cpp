//
//  arr.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/6.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include "arr.hpp"
#include <gtest/gtest.h>

using namespace std;

template <typename Container>
size_t find_any_peak(Container v, size_t first, size_t last) {
	if (last == first) return first;
	size_t mid = first + ((last-first)>>1);
	if (mid == first) { // 2 elem
		if (v[last] < v[first]) return first;
		else return last;
	}
	if (v[mid] < v[mid-1]) return find_any_peak(v, first, mid-1);
	return find_any_peak(v, mid, last);
}

template <typename Container>
size_t find_any_peak(Container container) {
	if (container.size() == 0) throw invalid_argument("empty container");
	return find_any_peak(container, 0, container.size()-1);
}

TEST(find_any_peak, find_any_peak) {
	vector<int> v1 {7, 6, 5, 4, 3, 4, 3}, v2 { 1, 2, 3, 4, 5}, v3 {5, 4, 3, 2, 1};
	vector<int> v0 {};
	EXPECT_EQ(find_any_peak(v1), 0);
	EXPECT_EQ(find_any_peak(v2), 4);
	EXPECT_EQ(find_any_peak(v3), 0);
	EXPECT_THROW(find_any_peak(v0), invalid_argument);
}

TEST(array, empty) {
    m::array<int> arr(0);
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0);
}

TEST(array, integer) {
    size_t n = 1024;
    m::array<int> arr(n);
    EXPECT_FALSE(arr.empty());
    EXPECT_EQ(arr.size(), n);
}

TEST(array, access) {
    size_t n = 10;
    m::array<int> arr(n);
    for (size_t i = 0; i < n; ++i) {
        arr[i] = i;
        EXPECT_EQ(arr[i], i);
    }
}

TEST(array, iter) {
    size_t n = 10;
    m::array<int> arr(n);
    for (size_t i = 0; i < n; ++i)
        arr[i] = i;
    size_t i = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it)
        EXPECT_EQ(*it, i++);
    EXPECT_EQ(i, n);
    for (auto it = arr.rbegin(); it != arr.rend(); ++it)
        EXPECT_EQ(*it, --i);
    EXPECT_EQ(i, 0);
}
