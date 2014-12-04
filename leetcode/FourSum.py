#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	4Sum.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 16:18:56 CST]
# Last-update:	2014-12-02 16:18:56 CST
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
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
        d = {}
        l = len(num)
        i = 0
        while i < l:
            j = i+1
            while j < l:
                s = num[i] + num[j]
                if s in d:
                    d[s] += [(i, j)]
                else:
                    d[s] = [(i, j)]
                j += 1
            i += 1
        i = 0
        v = []
        while i < l:
            j = i + 1
            while j < l:
                s = target - num[i] - num[j]
                if s in d:
                    for a, b in d[s]:
                        if i != a and b != j:
                            t = [i, j, a, b]
                            st = sorted([num[i], num[j], num[a], num[b]])
                            if len(set(t)) == 4 and st not in v:
                                v.append(st)
                j += 1
            i += 1
        return v

import unittest

class Test4Sum(unittest.TestCase):
    def setUp(self):
        self._fourSum = Solution().fourSum

    def test_fourSum(self):
        pass
        print self._fourSum([1, 0, -1, 0, -2, 2], 0)

if __name__ == '__main__':
    unittest.main()

