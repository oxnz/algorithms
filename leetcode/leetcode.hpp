//
//  leetcode.hpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/15.
//

#ifndef leetcode_hpp
#define leetcode_hpp

#include <cstdio>
#include <cstring>

#include <set>
#include <bit>
#include <stack>
#include <vector>
#include <random>
#include <string>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>

#include <gtest/gtest.h>

template <typename T>
inline T anybit(T x) {
    if (!x) return x;
    for (int i = 0; i < sizeof(T)*8; ++i)
        if (x&(1<<i)) return 1<<i;
    return x;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    if (is.peek() == '[') is.get();
    T tmp;
    while (is >> tmp) {
        v.push_back(tmp);
        if (!is.eof() && is.peek() == ',') is.get();
    }
    if (!is.eof() && is.peek() == ']') is.get();
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    if (v.empty()) return os << "[]";
    if (v.size() == 1) return os << "[" << v[0] << "]";
    auto it = v.begin();
    os << "[" << *it++;
    while (it != v.end()) os << "," << *it++;
    return os << "]";
}

#endif /* leetcode_hpp */
