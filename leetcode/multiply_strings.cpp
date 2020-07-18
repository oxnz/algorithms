//
//  multiply_strings.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//
#include <gtest/gtest.h>
#include "leetcode.hpp"

using namespace std;

/**
 @brief alphabetic arithmetic calc
 * P415 Add Strings
 * P989 Add to Array-Form of Integer
 */
class Solution {
public:
    /** multiply by string representation
    * @param s1 first
    * @param s2 second
    * 1 2 3
    * 4 5 6
     * 123*6 + 123*5*10 + 123*4*100
     */

    std::pair<char, char> adc(char a, char b, char c) {
        auto v = (a - '0') + (b - '0') + (c - '0');
        return {v/10 + '0', (v%10)+'0'};
    }
    
    std::string add(const std::string& s1, const std::string& s2) {
        if (s1.length() < s2.length()) return add(s2, s1);
        std::ostringstream oss;
        char c = '0', r;
        auto p1 = s1.rbegin(), p2 = s2.rbegin();
        while (p2 != s2.rend()) {
            std::tie(c, r) = adc(*p1++, *p2++, c);
            oss << r;
        }
        for (; p1 != s1.rend(); ++p1) {
            std::tie(c, r) = adc(*p1, '0', c);
            oss << r;
        }
        if (c > '0') oss << c;
        auto s = oss.str();
        std::reverse(s.begin(), s.end());
        return s;
    }
    
    vector<int> addToArrayForm(vector<int>& A, int K) {
        std::ostringstream oss;
        for (auto i : A) oss << i;
        auto s = add(oss.str(), std::to_string(K));
        vector<int> v;
        for (auto c : s) v.push_back(c - '0');
        return v;
    }
    
    std::pair<char, char> multiply(char a, char b, char c) {
        auto v = (a - '0') * (b - '0') + (c - '0');
        return {v/10 + '0', (v%10)+'0'};
    }

    string multiply(const string& s, char x) {
        if (x == '0') return "0";
        ostringstream oss;
        char c = '0', r = '0';
        for (auto p = s.rbegin(); p != s.rend(); ++p) {
            std::tie(c, r) = multiply(*p, x, c);
            oss << r;
        }
        if (c > '0') oss << c;
        auto rs = oss.str();
        std::reverse(rs.begin(), rs.end());
        return rs;
    }
    
    string multiply(string s1, string s2) {
        if (s1.length() < s2.length()) std::swap(s1, s2);
        string r;
        for (auto p = s2.begin(); p != s2.end(); ++p)
            r = add(r+'0', multiply(s1, *p));
        return r;
    }
};

TEST(multiply_strings, add) {
    auto s1 = "9999", s2 = "11";
    EXPECT_EQ(Solution().add(s2, s1), "10010");
}

TEST(multiply_strings, multiply_by_char) {
    auto s1 = "9999";
    char x = '9';
    EXPECT_EQ(Solution().multiply(s1, x), "89991");
    EXPECT_EQ(Solution().multiply(s1, '0'), "0");
}

TEST(multiply_strings, multiply_digit) {
    auto s1 = "2", s2 = "3", r = "6";
    EXPECT_EQ(Solution().multiply(s1, s2), r);
}

TEST(multiply_strings, multiply) {
    auto s1 = "123", s2 = "456", r = "56088";
    EXPECT_EQ(Solution().multiply(s1, s2), r);
}

TEST(multiply_strings, multiply_v2) {
    Solution sol;
    for (size_t i = 0; i < 100; ++i)
        for (size_t j = 0; j < 100; ++j)
            EXPECT_EQ(sol.multiply(std::to_string(i), std::to_string(j)), std::to_string(i*j));
}
