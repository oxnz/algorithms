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
    def isNumber(self, s):
        s = s.strip().lower()
        if ' ' in s:
            return False
        l = len(s)
        if not l:
            return False
        if s[0] == '-' or s[0] == '+':
            s = s[1:]
        if len(s) == 0:
            return False
        HEX = 0
        DEC = 1
        OCT = 2
        valid = False
        if s.startswith('0x'):
            t = HEX
            s = s[2:]
        elif s.startswith('0'):
            t = OCT
            s = s[1:]
        else:
            t = DEC
        if len(s) == 0:
            return False
        sets = [set('.0123456789abcdef'), set('.0123456789e'), set('.01234567e')]
        if len(set(s) | sets[t]) != len(sets[t]):
            return False
        if s.count('e') > 1:
            return False
        if s.count('.') > 1:
            return False
        return True

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
            ['3', True],
        ]:
            try:
                self.assertEqual(v, self._isNumber(s))
            except AssertionError as e:
                print 'failed for: ', s, e
            except Exception as e:
                print 'exec fail:', s, e

if __name__ == '__main__':
    unittest.main()

