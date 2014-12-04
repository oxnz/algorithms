#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	Subsets.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 10:08:09 CST]
# Last-update:	2014-12-02 10:08:09 CST
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
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        '''bit mask'''
        sets = [[]]
        S = sorted(S)
        l = len(S)
        mask = [False for i in range(l)]
        while True:
            i = 0
            while i < l and mask[i]:
                mask[i] = False
                i += 1
            if i == l:
                return sets
            mask[i] = True
            subset = []
            i = 0
            while i < l:
                if mask[i]:
                    subset.append(S[i])
                i += 1
            sets.append(subset)

    def subsets2(self, S):
        '''original'''
        sets = [[]]
        S = sorted(S)
        for elem in S:
            ss = []
            for s in sets:
                ss.append(s + [elem])
            sets += ss
        return sets


import unittest

class TestSubsets(unittest.TestCase):
    def setUp(self):
        self._subsets = Solution().subsets

    def isIdenticalSubsets(self, s1, s2):
        for l in s1:
            if l not in s2 or sorted(l) != l:
                return False
        for l in s2:
            if l not in s1 or sorted(l) != l:
                return False
        return True

    def test_subsets(self):
        self.assertTrue(self.isIdenticalSubsets([ [] ], self._subsets([])))
        self.assertTrue(self.isIdenticalSubsets([ [], [1] ], self._subsets([1])))
        self.assertTrue(self.isIdenticalSubsets([ [], [1], [2], [1,2] ], self._subsets([1, 2])))
        self.assertTrue(self.isIdenticalSubsets([ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ], self._subsets([1,2,3])))
        self.assertTrue(self.isIdenticalSubsets([ [],[0],[1],[4],[0,1],[0,4],[1,4],[0,1,4] ],
            self._subsets([4,1,0])))

if __name__ == '__main__':
    unittest.main()

