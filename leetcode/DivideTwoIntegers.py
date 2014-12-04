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
    def divide(self, dividend, divisor):
        if dividend < 0 and divisor < 0:
            dividend = - dividend
            divisor = - divisor
        elif dividend < 0:
            return - self.devide(- dividend, divisor)
        elif divisor < 0:
            return - self.devide(dividend, - divisor)
        if dividend < divisor:
            return 0
        elif dividend == divisor:
            return 1
        a = str(dividend).split()
        b = str(divisor).split()
        i = len(a) - 1
        result = ''
        c = False
        while i >= 0:
            for edx in reversed(b):
                eax = int(a[i])
                edx = int(edx) - c
                if eax < edx:
                    c = True
                    eax += 10
                c, r = [d[a[i]+x]]
                result = r + result
                i -= 1
            while c:
                r = a[i] - 1
            i -= 1

import unittest

class TestRegexpMatch(unittest.TestCase):
    def setUp(self):
        self._isNumber = Solution().isNumber

    def test_isNumber(self):
        for s, v in [
            ['0', True],
            [' 0.1', True],
            ['abc', False],
            ['1 a', False],
            ['2e10', True],
            ['0x', False],
            ['0x2', True],
            ['02', True],
            ['09', False],
            ['3.', True],
            ['..', False],
        ]:
            try:
                self.assertEqual(v, self._isNumber(s))
            except AssertionError as e:
                print 'failed for: ', s, e

if __name__ == '__main__':
    unittest.main()

