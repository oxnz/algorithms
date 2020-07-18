//
//  edit_distance.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/17.
//

#include "leetcode.hpp"

namespace m {

/**
 * @brief The **Levenshtein distance** allows deletion, insertion and substitution.
 *
 * d{i,j} = {
 *if (a[i] == b[i]) return d{i-1,j-1}
 *else return 1 + min(
 *  d{i-1,j}, // del
 *  d{i, j-1}, // ins
 *  d{i-1,j-1}) // sub
 * }
 */
int edit_distance(const std::string& s1, const std::string& s2) {
    if (s1.empty()) return s2.length();
    if (s2.empty()) return s1.length();
    if (s1[0] == s2[0]) return edit_distance(s1.substr(1), s2.substr(1));
    return 1 + std::min(std::min(edit_distance(s1.substr(1), s2),
                    edit_distance(s2.substr(1), s1)),
                    edit_distance(s1.substr(1), s2.substr(1)));
    return 0;
}

int hamming_distance(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) throw std::invalid_argument("length differ");
    int n = 0;
    for (int i = 0; i < s1.length(); ++i)
        if (s1[i] != s2[i]) ++n;
    return n;
}

}

TEST(edit_distance, zero) {
    EXPECT_EQ(m::edit_distance("", ""), 0);
    EXPECT_EQ(m::edit_distance("a", "a"), 0);
    EXPECT_EQ(m::edit_distance("hello", "hello"), 0);
}

TEST(edit_distance, one) {
    EXPECT_EQ(m::edit_distance("", "a"), 1);
    EXPECT_EQ(m::edit_distance("a", "b"), 1);
    EXPECT_EQ(m::edit_distance("aa", "a"), 1);
    EXPECT_EQ(m::edit_distance("ab", "aa"), 1);
}

TEST(edit_distance, multi) {
    EXPECT_EQ(m::edit_distance("horse", "ros"), 3);
    EXPECT_EQ(m::edit_distance("intention", "execution"), 5);
}

TEST(hamming_distance, hamming_distance) {
    EXPECT_EQ(m::hamming_distance("", ""), 0);
    EXPECT_EQ(m::hamming_distance("a", "a"), 0);
    EXPECT_EQ(m::hamming_distance("a", "b"), 1);
    EXPECT_EQ(m::hamming_distance("aa", "aa"), 0);
    EXPECT_EQ(m::hamming_distance("aa", "ab"), 1);
    EXPECT_EQ(m::hamming_distance("abc", "def"), 3);
}
