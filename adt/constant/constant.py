#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	constant.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-08-10 01:10:30 CST
# Last-update:	2016-08-10 01:10:30 CST
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

class _const:
    class ConstError(TypeError):
        pass
    class ConstCastError(ConstError):
        pass
    def __setattr__(self, name, value):
        if name in self.__dict__:
            raise self.ConstError, "Can't change const.{}".format(name)
        if not name.isupper():
            raise self.ConstCastError, 'const name {} is not all uppercase'.format(name)
        self.__dict__[name] = value

import sys
sys.modules[__name__] = _const()
import const
const.MY_CONSTANT = 1
const.SECOND_CONSTANT = 2
const.THIRD_CONSTANT = 'a'
const.FORTH_CONSTANT = 'b'
