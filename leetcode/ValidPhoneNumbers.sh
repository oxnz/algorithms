#!/usr/bin/env sh
# 
# ===============================================================
#
# Filename:	ValidPhoneNumbers.sh
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-05-13 13:28:11 CST
# Last-update:	2016-05-13 13:28:11 CST
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

sed -rne '/^((\([0-9]{3}\) )|([0-9]{3}-))[0-9]{3}-[0-9]{4}$/p' file.txt
