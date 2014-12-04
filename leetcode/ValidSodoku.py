#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	MaximumDepthOfBinaryTree.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 17:33:41 CST]
# Last-update:	2014-12-02 17:33:41 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2013 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        for row in board:
            s = set()
            for v in row:
                if v in s and v != '.':
                    return False
                s.add(v)
        i = 8
        j = 8
        while i >= 0:
            s = set()
            col = [row[i] for row in board]
            for v in col:
                if v in s and v != '.':
                    return False
                s.add(v)
            i -= 1

        i = 0
        while i < 9:
            j = 0
            while j < 9:
                l = board[i][j:j+3] + board[i+1][j:j+3] + board[i+2][j:j+3]
                s = set()
                for v in l:
                    if v in s and v != '.':
                        return False
                    s.add(v)
                j += 3
            i += 3
        return True


import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        #self._isValidSudoku = Solution().isValidSudoku
        def validate(board):
            self.dispSudoku(board)
            return Solution().isValidSudoku(board)
        self._isValidSudoku = validate

    def dispSudoku(self, board):
        print '_'*13
        for col in board:
            print col.split()
        print '-'*13

    def test_isValidSudoku(self):
        self.assertFalse(self._isValidSudoku(["......5..",".........",".........","93..2.4..","..7...3..",".........","...34....",".....3...",".....52.."]))
        self.assertFalse(self._isValidSudoku(["7...4....","...865...",".1.2.....",".....9...","....5.5..",".........","......2..",".........","........."]))
        self.assertTrue(self._isValidSudoku([".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]))
        self.assertFalse(self._isValidSudoku(["..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."]))

if __name__ == '__main__':
    unittest.main()

