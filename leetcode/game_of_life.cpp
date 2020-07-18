//
//  game_of_life.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//

#include "leetcode.hpp"

/**
 * @brief game of life
 * @link https://leetcode.com/problems/game-of-life/solution/
 */
class Solution {
    using board = std::vector<std::vector<int>>;
public:
    int value(board& b, size_t i, size_t j) {
        if (i == -1 || j == -1 || i == b.size() || j == b[0].size()) return 0;
        return b[i][j];
    }
    void next(int& x, int n) {
        if (x) {
            if (n < 2 || n > 3) x = 0;
        } else {
            if (n == 3) x = 1;
        }
    }
    void next(board& b, board& o, size_t i, size_t j) {
       auto v = value(b, i-1, j-1) + value(b, i-1, j) + value(b, i-1, j+1) + value(b, i, j+1)
        + value(b, i+1, j+1) + value(b, i+1, j) + value(b, i+1, j-1) + value(b, i, j-1);
        next(o[i][j], v);
    }
    void gameOfLife(board& board) {
        auto o = board;
        if (board.empty() || board.front().empty()) return;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[0].size(); ++j) {
                next(board, o, i, j);
            }
        }
        board = o;
    }
};

TEST(game_of_life, case1) {
    std::vector<std::vector<int>> planet = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    }, expected = {
        {0,0,0},
        {1,0,1},
        {0,1,1},
        {0,1,0}
    };
    Solution sol;
    sol.gameOfLife(planet);
    for (size_t i = 0; i < planet.size(); ++i)
        EXPECT_EQ(planet[i], expected[i]);
}
