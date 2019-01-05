#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	TopK.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-07-05 18:39:58 CST
# Last-update:	2016-07-05 18:39:58 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2016 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m = {}
        for n in nums:
            if m.has_key(n):
                m[n] += 1
            else:
                m[n] = 1
        l = [[v, k_] for k_, v in m.items()]
        l.sort()
        l = reversed(l)
        result = []
        for n, v in l:
            k = k - 1
            if k < 0:
                break
            result.append(v)
        return result

print Solution().topKFrequent([1,1,1,2,2,3], 1)
print Solution().topKFrequent([1,1,1,2,2,3], 3)
