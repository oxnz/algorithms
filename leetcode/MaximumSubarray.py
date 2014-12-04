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
    def maxSubArray(self, A):
        s = A[0]
        t = A[0]
        for n in A[1:]:
            s = max(s + n, n)
            t = max(t, s)
        return t

    def maxSubArray2(self, A):
        m = None
        s = 0
        t = 0
        for n in A:
            s += n
            m = max(m, s)
            if n < 0:
                t = 0
            else:
                t += n
            if s < 0:
                s = t
        return m


import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._maxSubArray = Solution().maxSubArray

    def test_maxSubArray(self):
        self.assertEqual(1, self._maxSubArray([1]))
        self.assertEqual(-1, self._maxSubArray([-1]))
        self.assertEqual(6, self._maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))

if __name__ == '__main__':
    unittest.main()

