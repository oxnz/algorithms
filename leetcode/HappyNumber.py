#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	HappyNumber.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-07-04 22:21:11 CST
# Last-update:	2016-07-04 22:21:11 CST
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
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        m = set()
        s = 0
        n = str(n)
        while s != 1:
            s = 0
            for i in str(n):
                s += int(i)*int(i)
            n = str(s)
            if s in m:
                return False
            else:
                m.add(s)
        return True

print Solution().isHappy(12)
