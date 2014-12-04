#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	RomantoInteger.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 11:25:05 CST]
# Last-update:	2014-12-02 11:25:05 CST
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
    def romanToInt(self, s):
        tbl = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        v = [tbl[c] for c in s]
        i = 0
        l = len(v)
        x = []
        while i < l:
            if i+1 < l and v[i] < v[i+1]:

import unittest

class TestRomantoInteger(unittest.TestCase):
    def setUp(self):
        self._rti = Solution.romanToInt

    def test_romanToInt(self):
        cases = {
            1: 'I',
            2: 'II',
            3: 'III',
            4: 'IV',
            5: 'V',
            6: 'VI',
            7: 'VII',
            8: 'VIII',
            9: 'IX',
            10: 'X',
            11: 'XI',
            13: 'XIII',
            14: 'XIV',
            15: 'XV',
        }
        for v in cases:
            self.assertEqual(v, cases[v])

if __name__ == '__main__':
    unittest.main()

