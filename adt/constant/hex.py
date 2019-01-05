#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	hex.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-11 14:53:46 CST
# Last-update:	2016-08-11 14:53:46 CST
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

import os
import sys

def charHex(ch):
    return hex(ord(ch))[1:]

try:
    string = sys.argv[1]
    hexStr = ''.join(map(charHex, string))
    print hexStr
    #cmd = "echo -n '"+string+"' | xxd -ps | sed 's/[[:xdigit:]]\{2\}/\\\\x&/g'"
    #print 'cmd = [{}]'.format(cmd)
    #os.system(cmd)
except IndexError:
    print("informe a string")
