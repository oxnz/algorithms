#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	QStack.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-07-06 11:30:37 CST
# Last-update:	2016-07-06 11:30:37 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2016 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self._q = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self._q.insert(0, x)


    def pop(self):
        """
        :rtype: nothing
        """
        for i in range(len(self._q) - 1):
            self.push(self._q.pop())
        return self._q.pop()

    def top(self):
        """
        :rtype: int
        """
        return self._q[0]

    def empty(self):
        """
        :rtype: bool
        """
        return len(self._q) == 0

s = Stack()
s.push(1)
s.push(2)
print s.pop()
s.push(3)
s.push(4)
print s.pop()
print s.pop()
print s.pop()
