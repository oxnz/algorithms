#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	MinStack.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-01 17:25:04 CST]
# Last-update:	2014-12-01 17:25:04 CST
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

class MinStack:
    def __init__(self):
        self._stack = []
        self._stackp = -1
        self._min = None

    # @param x, an integer
    # @return an integer
    def push(self, x):
        self._stack.append(x)
        self._stackp += 1
        if self._stackp == 0:
            self._min = x
        else:
            m = min(self._min, x)
            if self._min != m:
                self._stack.append(str(self._min))
                self._stackp += 1
                self._min = m
        return x

    # @return nothing
    def pop(self):
        if self._stackp < 0:
            raise IndexError('stack empty')
        v = self._stack.pop()
        self._stackp -= 1
        if type(v) == str:
            self._min = int(v)
            self._stack.pop()
            self._stackp -= 1

    # @return an integer
    def top(self):
        if self._stackp < 0:
            raise IndexError('stack empty')
        v = self._stack[self._stackp]
        if type(v) == str:
            return self._stack[self._stackp-1]
        else:
            return v

    # @return an integer
    def getMin(self):
        if self._stackp < 0:
            raise IndexError('stack empty')
        return self._min

    def echo(self):
        print 'min: {}, stack: {}, stackp: {}'.format(self._min, self._stack, self._stackp)

import unittest
import random

class TestMinStack(unittest.TestCase):
    def setUp(self):
        self._stack = MinStack()
        self._seq = []
        self._min = []
        m = 100
        for i in range(100):
            i = random.randint(0, 100)
            self._seq.append(i)
            m = min(m, i)
            self._min.append(m)

    def test_stack(self):
        for i in range(len(self._seq)):
            v = self._seq[i]
            self._stack.push(v)
            self.assertEqual(v, self._stack.top())
            self.assertEqual(self._min[i], self._stack.getMin())

    def test_wa(self):
        self._stack = MinStack()
        self._stack.echo()
        self._stack.push(-10)
        self._stack.echo()
        self._stack.push(14)
        self._stack.echo()
        print self._stack.getMin()
        self._stack.echo()
        print self._stack.getMin()
        self._stack.echo()
        self._stack.push(-20)
        self._stack.echo()
        print self._stack.getMin();
        self._stack.echo()
        print self._stack.getMin();
        print self._stack.top();
        self._stack.echo()
        print self._stack.getMin();
        self._stack.echo()
        self._stack.pop()
        self._stack.echo()
        self._stack.push(10)
        self._stack.echo()
        self._stack.push(-7)
        print self._stack.getMin();
        self._stack.push(-7)
        self._stack.pop()
        print self._stack.top();
        print self._stack.getMin();
        self._stack.pop()


if __name__ == '__main__':
    unittest.main()
