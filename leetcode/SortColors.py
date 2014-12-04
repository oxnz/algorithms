#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	SortColors.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-01 23:36:03 CST]
# Last-update:	2014-12-01 23:36:03 CST
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
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        if not A:
            return
        p0, p2 = 0, len(A) - 1
        i = 0
        while i <= p2:
            while p2 >= p0 and A[p2] == 2:
                p2 -= 1
            while p0 <= p2 and A[p0] == 0:
                p0 += 1
            if A[i] == 2 and i < p2:
                A[i], A[p2] = A[p2], A[i]
                p2 -= 1
            if A[i] == 0 and i > p0:
                A[p0], A[i] = A[i], A[p0]
                p0 += 1
            i += 1

import unittest
import random

class TestSortColors(unittest.TestCase):
    def setUp(self):
        self._sort = Solution().sortColors

    def test_sort(self):
        l = None
        self._sort(l)
        self.assertEqual(None, l)
        l = [random.randint(0,2) for i in xrange(10)]
        sl = sorted(l)
        self._sort(l)
        self.assertEqual(sl, l)
        random.shuffle(l)
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [0]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [1]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [0, 1]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [1, 2]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [2, 1]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)
        l = [2, 0]
        self._sort(l)
        sl = sorted(l)
        self.assertEqual(sl, l)

if __name__ == '__main__':
    unittest.main()
