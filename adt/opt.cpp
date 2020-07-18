#include "opt.h"

#include <gtest/gtest.h>

TEST(optional, empty) {
    m::optional<int> opt;
    EXPECT_FALSE(opt);
    EXPECT_TRUE(opt.empty());
}

TEST(optional, not_empty) {
    int v = 0;
    m::optional<int> opt(v);
    EXPECT_FALSE(opt.empty());
    EXPECT_TRUE(opt);
}

TEST(optional, value) {
    int v = 1234;
    m::optional<int> opt(v);
    EXPECT_EQ(opt.value(), v);
}
