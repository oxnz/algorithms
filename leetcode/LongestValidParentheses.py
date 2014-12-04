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
    def longestValidParentheses(self, s):
        stack = []
        if not s:
            return 0
        for p in s:
            if p == '(':
                stack.append('(')
            elif len(stack):
                top = stack.pop()
                if top == '(':
                    stack.append(2)
                elif top == ')':
                    stack.append(')')
                    stack.append(')')
                else:
                    t = top
                    while len(stack) and stack[-1] != '(' and stack[-1] != ')':
                        top = stack.pop()
                        t += top
                    if len(stack):
                        top = stack.pop()
                        if top == ')':
                            stack.append(')')
                            stack.append(t)
                            stack.append(')')
                        elif top == '(':
                            stack.append(t+2)
                    else:
                        stack.append(t)
                        stack.append(')')
        c = True
        m = 0
        t = 0
        for i in stack:
            if i == '(' or i == ')':
                m = max(m, t)
                c = False
            else:
                if c:
                    t += i
                else:
                    c = True
                    t = i
        m = max(m, t)
        return m

import unittest

class TestRegexpMatch(unittest.TestCase):
    def setUp(self):
        self._longestValidParentheses = Solution().longestValidParentheses

    def test_longestValidParentheses(self):
        for s, v in [
            ['(', 0],
            ['((', 0],
            [')(', 0],
            [')', 0],
            [')((', 0],
            ['()', 2],
            ['()(', 2],
            ['(()', 2],
            ['(()()', 4],
            ['()(()', 2],
            ['())', 2],
            ['(()())', 6],
            [')()())()()(', 4],
            ['(()))())(', 4],
            ['()()))))()()(', 4],
            [')(())))(())())', 6],
            [')(()())())(((()))(()()()(()(()(())))(())()((()()(((()())()))(()()())())(())(()(()()()()))(((()())))(((()))))()()())))(()))))())(((()', 106],
        ]:
            try:
                self.assertEqual(v, self._longestValidParentheses(s))
            except AssertionError as e:
                print 'failed for: ', s, e

if __name__ == '__main__':
    unittest.main()

