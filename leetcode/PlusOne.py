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
    def plusOne(self, digits):
        l = len(digits)
        if not l:
            return []
        i = l-1
        while i >= 0 and digits[i] == 9:
            digits[i] = 0
            i -= 1
        if i >= 0:
            digits[i] += 1
        else:
            digits = [1] + digits
        return digits

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._plusOne = Solution().plusOne

    def test_plusOne(self):
        self.assertEqual([], self._plusOne([]))
        self.assertEqual([1], self._plusOne([0]))
        self.assertEqual([1, 0], self._plusOne([9]))
        self.assertEqual([1, 0, 0], self._plusOne([9, 9]))

if __name__ == '__main__':
    unittest.main()

