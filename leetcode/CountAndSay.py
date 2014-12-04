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
    def __init__(self):
        self._cache = ['1']
        self._len = 1
    # @return a string
    def countAndSay(self, n):
        while self._len < n:
            self._cache.append(self.say(self._cache[self._len-1]))
            self._len += 1
        return self._cache[n-1]

    def say(self, s):
        l = len(s)
        o = ''
        i = 0
        while i < l:
            cnt = 0
            for c in '0123456789':
                cnt = 0
                while i < l and s[i] == c:
                    cnt += 1
                    i += 1
                if cnt:
                    o += str(cnt) + c
        return o

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._countAndSay = Solution().countAndSay

    def test_countAndSay(self):
        self.assertEqual('1', self._countAndSay(1))
        self.assertEqual('11', self._countAndSay(2))
        self.assertEqual('21', self._countAndSay(3))
        self.assertEqual('1211', self._countAndSay(4))

if __name__ == '__main__':
    unittest.main()

