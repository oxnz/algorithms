//
//  insert_interval.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& i) {
        if (v.empty()) {
            v.push_back(i);
            return v;
        }
//        auto p0 = std::find(v.begin(), v.end(), [&](const auto& x) {
//            return x.front() > i.front();
//        });
//        auto p1 = std::find(v.begin(), v.end(), [&](const auto& x) {
//            return x.back() > i.back();
//        });
        return {};
    }
};
