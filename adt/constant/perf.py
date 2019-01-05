#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	perf.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-10 17:28:06 CST
# Last-update:	2016-08-10 17:28:06 CST
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

import timeit

s = ['it is a long value string will not keep in memory' for i in xrange(100000)]

def join_test():
    return ''.join(s)

def plus_test():
    r = ''
    for subs in s:
        r += subs
    return r

if __name__ == '__main__':
    n = 100
    print timeit.Timer('join_test()', 'from __main__ import join_test').timeit(n)
    print timeit.Timer('plus_test()', 'from __main__ import plus_test').timeit(n)
