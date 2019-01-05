#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	iter.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-10 02:34:28 CST
# Last-update:	2016-08-10 02:34:28 CST
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

s = 'hello'
for i, e in zip(range(len(s)), s):
    print 'index: {}, element: {}'.format(i, e)
for i, e in enumerate(s):
    print 'index: {}, element: {}'.format(i, e)
