#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	SingleNumber.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 01:08:49 CST]
# Last-update:	2014-12-02 01:08:49 CST
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
    def singleNumber(self, A):
        s = None
        for n in A:
            if s:
                s = s ^ n
            else:
                s = n
        return s

import unittest

class TestSingleNumber(unittest.TestCase):
    def setUp(self):
        self._singleNum = Solution().singleNumber

    def test_singleNum(self):
        self.assertEqual(123, self._singleNum([123]))
        self.assertEqual(1, self._singleNum([1, 2, 2, 3, 3]))

if __name__ == '__main__':
    unittest.main()

