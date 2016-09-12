#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	ImplementQueueUsingStacks.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-05-13 18:34:53 CST
# Last-update:	2016-05-13 18:34:53 CST
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

class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.inbox = list()
        self.outbox = list()

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.inbox.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.outbox) == 0:
            while len(self.inbox) > 0:
                self.outbox.append(self.inbox.pop())
        return self.outbox.pop()

    def peek(self):
        """
        :rtype: int
        """
        v = self.pop()
        self.outbox.append(v)
        return v

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.inbox) + len(self.outbox) == 0

if __name__ == '__main__':
    q = Queue()
    q.push(1)
    q.push(2)
    q.push(3)
    q.pop()
    q.pop()
    q.push(4)
    q.pop()
