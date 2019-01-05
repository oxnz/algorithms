#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	myPow.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-05 12:19:19 CST
# Last-update:	2016-08-05 12:19:19 CST
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

class Solution(object):
    def myPow(self, x, n):
        print 'x = {}, n = {}'.format(x, n)
        if n < 0:
            return 1/self.myPow(x, -n)
        if n == 0:
            return 1
        if n % 2 == 0:
            x = self.myPow(x, n>>1)
            return x * x
        else:
            return self.myPow(x, n-1) * x

if __name__ == '__main__':
    myPow = Solution().myPow
    print '{}'.format(myPow(0.2, 2147483647))
