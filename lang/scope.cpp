#include <gtest/gtest.h>
#include "scope.h"

TEST(scope, exit) {
    int n = 1234;
    int i = n;
    {
        scope_exit _guard([&]() {++i;});
    }
    EXPECT_EQ(i, n+1);
}

TEST(scope, success) {
    int n = 1234;
    int i = n;
    try {
        scope_success _guard([&]() {++i;});
        throw std::runtime_error("ex");
    } catch (std::exception& ex) {
        // pass
    }
    EXPECT_EQ(i, n);
}

TEST(scope, failure) {
    int n = 1234;
    int i = n;
    try {
        scope_failure _guard([&]() {++i;});
        throw std::runtime_error("ex");
    } catch (std::exception& ex) {
        // pass
    }
    EXPECT_EQ(i, n+1);
}
