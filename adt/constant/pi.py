#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	pi.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-10 02:25:15 CST
# Last-update:	2016-08-10 02:25:15 CST
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

from __future__ import division
import math
import random

def pi(n):
    cnt = 0
    for i in xrange(n):
        x = random.random()
        y = random.random()
        if x*x + y*y < 1:
            cnt += 1
    return cnt*4/n

if __name__ == '__main__':
    print 'pi = {}'.format(pi(10000000))
