//
//  disjoint_set.cpp
//  adt
//
//  Created by Max Zhang on 2020/2/12.
//

#include <gtest/gtest.h>
#include "disjoint_set.hpp"

TEST(disjoint_set, empty) {
    size_t n = 10;
    m::disjoint_set s(n);
    EXPECT_EQ(s.size(), n);
}

TEST(disjoint_set, find) {
    m::disjoint_set::index_type n = 10;
    m::disjoint_set s(n);
    for (m::disjoint_set::index_type i = 0; i < n; ++i) {
        EXPECT_EQ(s.find(i), i);
    }
}

TEST(disjoint_set, join) {
    m::disjoint_set::index_type n = 10;
    m::disjoint_set s(n);
    for (m::disjoint_set::index_type i = 0; i < n; ++i) {
        EXPECT_EQ(s.size(), n-i);
        auto idx = s.join(i, (i+1)%n);
        if (i+1 < n) EXPECT_EQ(idx, i+1);
        else EXPECT_EQ(idx, i);
    }
}
