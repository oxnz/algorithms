//
//  leetcode.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/15.
//

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& v) {
        if (v.size() < 3) return false;
        auto p = std::adjacent_find(v.begin(), v.end(), [](auto& a, auto& b) {return a >= b;});
        if (p == v.begin() || p == v.end()) return false;
        p = std::adjacent_find(p, v.end(), [](auto& a, auto& b) {return a <= b;});
        return p == v.end();
    }
};
