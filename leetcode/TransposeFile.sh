#!/usr/bin/env sh
# 
# ===============================================================
#
# Filename:	TransposeFile.sh
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-05-13 13:42:57 CST
# Last-update:	2016-05-13 13:42:57 CST
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

NF="$(awk '{print NF; exit}' file.txt)"
i=0
while [ $i -lt $NF ]; do
	i=$((i+1))
	cut -d' ' -f "$i" file.txt | tr '\n' ' ' | sed -e 's/ $/\n/'
done
