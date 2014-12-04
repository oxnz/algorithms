#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	TwoSum.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 00:36:59 CST]
# Last-update:	2014-12-02 00:36:59 CST
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
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        l = len(num)
        i = 1
        d = {}
        while i <= l:
            d[num[i-1]] = i
            i += 1
        i = 1
        while i <= l:
            sub = target - num[i-1]
            if sub in d:
                if i == d[sub]:
                    pass
                elif i <= d[sub]:
                    return i, d[sub]
                else:
                    return d[sub], i
            i += 1
        raise Exception('no result')


import unittest

class TestTwoSum(unittest.TestCase):
    def setUp(self):
        self._sum = Solution().twoSum

    def test_sum(self):
        self.assertEqual((1,2), self._sum([2, 7], 9))
        self.assertEqual((1,2), self._sum([2, 7, 11, 15], 9))
        self.assertEqual((2,3), self._sum([3, 2, 4], 6))
        self.assertEqual((1,4), self._sum([0, 4, 3, 0], 0))

if __name__ == '__main__':
    unittest.main()
