#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	Sqrt.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 12:09:48 CST]
# Last-update:	2014-12-02 12:09:48 CST
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
    def __init__(self):
        self._cache = [0]
        self._len = 1
        self._mid = 0

    def sqrt(self, x):
        m = self._cache[self._len - 1]
        if x > m:
            i = self._len - 1
            l = [i*i for i in range(m+1, x+5)]
            self._cache += l
            self._len += len(l)
            self._mid = self._len / 2
            return self.search(x, i, self._len)
        else:
            return self.search(x, 0, self._len)

    def search(self, x, i, j):
        print 'x = ', x, ' i = ', i, ' cache = ', self._cache, ' j = ', j
        while i < j and self._cache[i] < x:
            i += 1
        if i >= j:
            raise Exception('not found')
        if i < 1:
            return 0
        elif i == 1:
            return 1
        if self._cache[i] == x:
            return i
        return i - 1

import unittest

class TestSqrt(unittest.TestCase):
    def setUp(self):
        self._sqrt = Solution().sqrt

    def test_sqrt(self):
        roots = {
            0: 0,
            1: 1,
            2: 1,
            3: 1,
            4: 2,
            5: 2,
            8: 2,
            9: 3,
            100: 10,
            10000: 100,
            100000000: 10000,
        }
        for n in roots:
            self.assertEqual(roots[n], self._sqrt(n))

if __name__ == '__main__':
    unittest.main()

