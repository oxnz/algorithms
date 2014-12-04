#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	Permutations.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 14:05:19 CST]
# Last-update:	2014-12-02 14:05:19 CST
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
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        num = sorted(num)
        return self.next(num)

    def next(self, num):
        l = len(num)
        if l == 1:
            return [num]
        elif l == 2:
            a, b = num
            return [[a, b], [b, a]]
        ss = []
        while l > 0:
            l -= 1
            for s in self.next(num[1:]):
                ss.append([num[0]] + s)
            num = num[1:] + [num[0]]
        return ss

import unittest

class TestPermutations(unittest.TestCase):
    def setUp(self):
        self._permute = Solution().permute

    def test_permute(self):
        self.assertEqual([[1]], self._permute([1]))
        #self.assertEqual([[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]], self._permute([1,2,3]))
        #self.assertEqual([[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]], self._permute([2,3,1]))
        print self._permute([1, 2, 3, 4])

if __name__ == '__main__':
    unittest.main()

