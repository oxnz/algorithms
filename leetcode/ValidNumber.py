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
        if s[-1] == '.':
            if l == 1:
                return False
            s = s[:-1]
        if s[0] in '+-':
            s = s[1:]
        if s[0] == '.':
            s = s[1:]
        if s.startswith('0x'): # hex
            if l == 2:
                return False
            return len(set(s[2:]) | set('abcdef0123456789')) == 16
        if s[-1] == 'e':
            return False
        if s.count('e') > 1:
            return False
        if s.count('.') > 1:
            return False
        if s.startswith('0'):
            if l == 1:
                return True
            return len(set(s[1:]) | set('.01234567')) == 9
        if '.' in s:
            return len(set(s) | set('.0123456789')) == 11
        if s[0] == 'e':
            return False
        s = s.replace('e', '')
        return len(set(s) | set('0123456789')) == 10

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

