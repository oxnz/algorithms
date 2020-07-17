//
//  iter.cpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/20.
//  Copyright © 2019 云心逸. All rights reserved.
//

#include <vector>
#include <gtest/gtest.h>
#include "iter.hpp"

using namespace std;

TEST(enumerate, enumerate) {
    vector<int> v{5, 4, 3, 2, 1};

	auto eum = enumerate(v);
	auto first = eum.begin();
	EXPECT_EQ((*first).first, 0);
	EXPECT_EQ((*first).second, 5);

	auto it = ++first;
	EXPECT_EQ((*it).first, 1);
	EXPECT_EQ((*it).second, 4);
	EXPECT_EQ((*first).first, 1);
	EXPECT_EQ((*first).second, 4);

	it = first++;
	EXPECT_EQ((*it).first, 1);
	EXPECT_EQ((*it).second, 4);
	EXPECT_EQ((*first).first, 2);
	EXPECT_EQ((*first).second, 3);

	for (auto [idx, val] : enumerate(v)) {
        EXPECT_EQ(idx + static_cast<size_t>(val), v.size());
	}
}

TEST(iterator, iterator) {
    vector<int> v {1, 2, 3, 4};
    Iterator it(v.begin(), v.end());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(1, it.next());
    EXPECT_EQ(2, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(3, it.next());
    EXPECT_EQ(4, it.next());
    EXPECT_FALSE(it.hasNext());
}
