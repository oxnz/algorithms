#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	SimplifyPath.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-01 18:54:04 CST]
# Last-update:	2014-12-01 18:54:04 CST
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

    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        parts = path.split('/')
        length = len(parts)
        pathv = ['']
        needsep = True
        i = 0
        while i < len(parts):
            if parts[i] == '':
                i += 1
            elif parts[i] == '..':
                i += 1
                if len(pathv):
                    pathv.pop()
            elif parts[i] == '.':
                i += 1
            else:
                pathv.append(parts[i])
                i += 1

        path = '/'.join(pathv)
        if path == '':
            return '/'
        elif path[0] != '/':
            path = '/' + path
        return path

import unittest
import os.path

class TestSolution(unittest.TestCase):
    def setUp(self):
        self._simpath = Solution().simplifyPath

    def test_case(self):
        for path in {
            '/': '/',
            '/../': '/',
            '/home//foo': '/home/foo',
            '/../../../': '/',
            '/././../../././': '/',
            '/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///': '/e/f/g',
        }:
            self.assertEqual(os.path.abspath(path), self._simpath(path))

if __name__ == '__main__':
    unittest.main()
