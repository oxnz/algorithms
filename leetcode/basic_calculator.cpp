//
//  basic_calculator.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//

#include <cassert>
#include <gtest/gtest.h>
#include "leetcode.hpp"

class Solution {
    struct token {
        enum { MUL, DIV, ADD, SUB, LPAR, RPAR, VAL } type;
        int val;
    };
public:
    int calculate(std::string s) {
        std::stack<token> ebp;
        bool reduction = false;
        int v = 0;
        for (auto p = s.begin(); p != s.end(); ++p) {
            switch (*p) {
                case ' ': break;
                case '(': ebp.push({token::LPAR, 0}); break;
                case '+': ebp.push({token::ADD, 0}); break;
                case '-': ebp.push({token::SUB, 0}); break;
                case ')': {
                    v = ebp.top().val;
                    ebp.pop();
                    if (ebp.top().type != token::LPAR) throw std::runtime_error("left par expected");
                    else ebp.pop();
                    reduction = true;
                    break;
                }
                default:
                    if (!std::isdigit(*p)) throw std::runtime_error("invalid char");
                    size_t n = 1;
                    while (p+n != s.end() && std::isdigit(*(p+n))) ++n;
                    v = std::stoi(std::string(p, p+n));
                    p += n-1;
                    reduction = true;
                    break;
            }
            if (reduction) {
                if (!ebp.empty()) {
                    switch (ebp.top().type) {
                        case token::LPAR: ebp.push({token::VAL, v}); break;
                        case token::ADD: ebp.pop(); ebp.top().val += v; break;
                        case token::SUB: ebp.pop(); ebp.top().val -= v; break;
                        default: throw std::runtime_error("unexpected token");
                    }
                } else ebp.push({token::VAL, v});
                reduction = false;
            }
        }
        if (ebp.size() != 1 || ebp.top().type != token::VAL) throw std::runtime_error("unexpected stack");
        return ebp.top().val;
    }
};

TEST(basic_calc, add) {
    Solution sol;
    EXPECT_EQ(sol.calculate("1+1"), 2);
}

TEST(basic_calc, sub) {
    Solution sol;
    EXPECT_EQ(sol.calculate(" 2-1 + 2 "), 3);
}

TEST(basic_calc, paren) {
    auto s = "(1+(4+5+2)-3)+(6+8)";
    Solution sol;
    EXPECT_EQ(sol.calculate(s), 23);
}
