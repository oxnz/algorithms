/*
 * Filename:	SingleNumberIII.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2015-08-18 19:47:35 CST
 * Last-update:	2015-08-18 19:47:35 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2015 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = std::reduce(nums.begin(), nums.end(), 0, std::bit_xor());
        int pivot = anybit(sum);
        int a = 0, b = 0;
        for (int i : nums)
            if ((i & pivot) == 0) a ^= i; else b ^= i;
        return {a, b};
	}
};

TEST(single_number_iii, solution) {
    std::string input = "[1,2,1,3,2,5]";
    std::string output = "[3,5]";
    std::vector<int> iv;
    std::istringstream iss(input);
    iss >> iv;
    Solution sol;
    auto ov = sol.singleNumber(iv);
    EXPECT_EQ(ov.size(), 2);
    if (ov[0] > ov[1]) std::swap(ov[0], ov[1]);
    EXPECT_EQ(ov[0], 3);
    EXPECT_EQ(ov[1], 5);
}
