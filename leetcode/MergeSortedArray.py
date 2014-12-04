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
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        i = m-1
        j = n-1
        k = m + n - 1
        while i >= 0 and j >= 0:
            if A[i] > B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
        while i >= 0:
            A[k] = A[i]
            i -= 1
            k -= 1
        while j >= 0:
            A[k] = B[j]
            j -= 1
            k -= 1

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._merge = Solution().merge

    def test_merge(self):
        a, b = [], []
        self._merge(a, len(a) - a.count(None), b, len(b))
        self.assertEqual([], a)
        a, b = [1], []
        self._merge(a, len(a) - a.count(None), b, len(b))
        self.assertEqual([1], a)
        a, b = [None], [1]
        self._merge(a, 0, b, 1)
        self.assertEqual([1], a)
        a, b = [1, None], [2]
        self._merge(a, len(a) - a.count(None), b, len(b))
        self.assertEqual([1,2], a)
        a, b = [1, 2, 3, None, None, None], [0, 2, 4]
        self._merge(a, len(a) - a.count(None), b, len(b))
        self.assertEqual([0,1,2,2,3,4], a)

if __name__ == '__main__':
    unittest.main()

