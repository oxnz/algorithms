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
    def nextPermutation(self, num):
        i = len(num) - 1
        if i <= 0:
            return num
        if i == 1:
            return [num[1], num[0]]
        while i > 0 and num[i-1] - num[i] <= 1:
            i -= 1
        if i == 0:
            return sorted(num)
        if i == 1:
            return [num[-1]] + num[:-1]
        num[i], num[i-1] = num[i-1], num[i]
        return num + sorted(num[i+1:])

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._nextPermutation = Solution().nextPermutation

    def test_nextPermutation(self):
        self.assertEqual([], self._nextPermutation([]))
        self.assertEqual([1], self._nextPermutation([1]))
        self.assertEqual([2, 1], self._nextPermutation([1, 2]))
        self.assertEqual([1, 2], self._nextPermutation([2, 1]))
        self.assertEqual([1, 3, 2], self._nextPermutation([1, 2, 3]))
        self.assertEqual([1, 2, 3], self._nextPermutation([3, 2, 1]))
        self.assertEqual([1, 5, 1], self._nextPermutation([1, 1, 5]))
        self.assertEqual([2, 1, 3], self._nextPermutation([1, 3, 2]))
        self.assertEqual([3, 1, 2], self._nextPermutation([2, 3, 1]))

if __name__ == '__main__':
    unittest.main()

