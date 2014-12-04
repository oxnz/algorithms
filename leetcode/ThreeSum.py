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
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        #d = {}
        num = sorted(num)
        l = len(num)
        i = 0
        v = []
        while i < l:
            j = i+1
            while j < l:
                s = -num[i] - num[j]
                p = num[j+1:]
                if s in p:
                    k = p.index(s)
                    if k > j:
                        t = sorted([i, j, k])
                        if t not in v:
                            v.append(t)
                #if s in d:
                #    d[s] += [[i, j]]
                #else:
                #    d[s] = [[i, j]]
                j += 1
            i += 1
        #i = 0
        #while i < l:
        #    if num[i] in d:
        #        for a, b in d[num[i]]:
        #            if a != i and b != i:
        #                t = sorted([num[i], num[a], num[b]])
        #                if t not in v:
        #                    v.append(t)
        #    i += 1
        return v

import unittest

class Test4Sum(unittest.TestCase):
    def setUp(self):
        self._threeSum = Solution().threeSum

    def test_threeSum(self):
        pass
        print self._threeSum([-1, 0, 1, 2, -1, -4])
        print self._threeSum([-9,-14,-3,2,0,-11,-5,11,5,-5,4,-4,5,-15,14,-8,-11,10,-6,1,-14,-12,-13,-11,9,-7,-2,-13,2,2,-15,1,3,-3,-12,-12,1,-2,6,14,0,-4,-13,-10,-12,8,-2,-8,3,-1,8,4,-6,2,1,10,2,14,4,12,1,4,-2,11,9,-7,6,-13,7,-3,8,14,8,10,12,11,-4,-13,10,14,1,-4,-4,2,5,4,-11,-7,3,8,-10,11,-11,-5,7,13,3,-2,8,-13,2,1,9,-12,-11,6])

if __name__ == '__main__':
    unittest.main()

