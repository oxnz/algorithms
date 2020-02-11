#include "exp.hpp"

#include <iostream>
#include <typeinfo>
#include <gtest/gtest.h>

TEST(exp, exp) {
    EXPECT_TRUE(true);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << typeid (v).name() << "<" << std::addressof(v) << ">[";
    auto it = v.begin();
    if (it != v.end()) os << *it++;
    for (; it != v.end(); ++it) os << ", " << *it;
    return os << "]";
}

TEST(ostream, vector) {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    std::cout << v << "\n";
}
