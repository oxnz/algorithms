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
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        if not a:
            return b
        if not b:
            return a
        i = len(a)-1
        j = len(b)-1
        if i < j:
            a, b = b, a
            i, j = j, i
        k = ''
        c = False
        while j >= 0:
            vv = a[i] + b[j]
            if c:
                if vv in ('01', '10'):
                    k = '0' + k
                elif vv == '11':
                    k = '1' + k
                else:
                    k = '1' + k
                    c = False
            else:
                if vv in ('01', '10'):
                    k = '1' + k
                elif vv == '11':
                    k = '0' + k
                    c = True
                else:
                    k = '0' + k
            j -= 1
            i -= 1
        while i >= 0:
            if c:
                if a[i] == '1':
                    k = '0' + k
                else:
                    k = '1' + k
                    c = False
            else:
                if a[i] == '1':
                    k = '1' + k
                else:
                    k = '0' + k
            i -= 1
        if c:
            k = '1' + k
        return k

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._addBinary = Solution().addBinary

    def dispSudoku(self, board):
        print '_'*13
        for col in board:
            print col.split()
        print '-'*13

    def test_addBinary(self):
        self.assertEqual('0', self._addBinary('', '0'))
        self.assertEqual('0', self._addBinary('0', ''))
        self.assertEqual('0', self._addBinary('0', '0'))
        self.assertEqual('1', self._addBinary('', '1'))
        self.assertEqual('1', self._addBinary('1', '0'))
        self.assertEqual('10', self._addBinary('1', '1'))
        self.assertEqual('100', self._addBinary('11', '1'))
        self.assertEqual('110110', self._addBinary('100', '110010'))

if __name__ == '__main__':
    unittest.main()

