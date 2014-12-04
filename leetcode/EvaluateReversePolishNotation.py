#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	EvaluateReversePolishNotation.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-01 19:41:23 CST]
# Last-update:	2014-12-01 19:41:23 CST
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
    def evalRPN(self, tokens):
        def div(a, b):
            if b == 0:
                raise Exception('divsion by zero')
            elif a >= 0 and b > 0:
                return a/b;
            elif a >= 0 and b < 0:
                return -(a/(-b))
            elif a < 0 and b > 0:
                return -((-a)/b)
            elif a < 0 and b < 0:
                return (-a)/(-b)

        action = {
            '+': lambda a, b: a + b,
            '-': lambda a, b: a - b,
            '*': lambda a, b: a * b,
            '/': lambda a, b: div(a,b),
        }
        stack = []
        for token in tokens:
            f = action.get(token)
            if f == None:
                stack.append(int(token))
                #print 'stack.push({}) => {}'.format(token, stack)
            else:
                b = stack.pop()
                a = stack.pop()
                stack.append(f(a, b))
                #print 'stack.push({} {} {} = {}) => {}'.format(a, token, b, f(a,b), stack)
        return stack[0]

import unittest

class TestEvalRPN(unittest.TestCase):
    def setUp(self):
        self._eval = Solution().evalRPN

    def test_evalRPN(self):
        tbl = {
            '2 1 + 3 *': 9,
            '4 13 5 / +': 6,
            '10 6 9 3 + -11  *  / *  17 +  5  +': 22,
        }
        for k in tbl:
            v = k.split()
            self.assertEqual(self._eval(v), tbl[k])

    def test_wa(self):
        self.assertEqual(self._eval(["-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"]), 165)

if __name__ == '__main__':
    unittest.main()
