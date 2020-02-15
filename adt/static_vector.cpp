#include <gtest/gtest.h>
#include "static_vector.h"

TEST(static_vector, empty) {
    m::static_vector<int, 10> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 10);
}

TEST(static_vector, push) {
    m::static_vector<int, 10> v;
    v.push_back(1);
    EXPECT_EQ(v.size(), 1);
    EXPECT_FALSE(v.empty());
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
}

TEST(static_vector, pop) {
    m::static_vector<int, 10> v;
    v.push_back(1);
    EXPECT_EQ(v.size(), 1);
    v.pop_back();
    EXPECT_TRUE(v.empty());
    v.push_back(1);
    v.push_back(2);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.back(), 2);
    v.pop_back();
    EXPECT_EQ(v.back(), 1);
    v.push_back(3);
    EXPECT_EQ(v.back(), 3);
    v.pop_back();
    EXPECT_EQ(v.back(), 1);
    v.pop_back();
    EXPECT_TRUE(v.empty());
}

TEST(static_vector, iterator) {
    m::static_vector<int, 10> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    int i = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
        EXPECT_EQ(*it, i++);
}

TEST(static_vector, object) {
    struct T {
        T(int& i) : i(i) { ++i; }
        ~T() { --i; }
        int& i;
    };
    int n = 0;
    {
        m::static_vector<T, 10> v;
        for (int i = 0; i < 10; ++i)
            v.emplace_back(std::ref(n));
        EXPECT_EQ(n, 10);
    }
    EXPECT_EQ(n, 0);
}

TEST(static_vector, exceptoin) {
    m::static_vector<int, 0> v;
    EXPECT_THROW({ v.push_back(1); }, std::overflow_error);
    EXPECT_THROW({ v.pop_back(); }, std::underflow_error);
    EXPECT_THROW({ v.at(0); }, std::out_of_range);
}
