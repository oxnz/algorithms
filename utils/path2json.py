#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	test.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2015-12-17 10:26:44 CST
# Last-update:	2015-12-17 10:26:44 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2015 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

m = {
        'title:subtitle': 12,
        'body:div': 23,
        'art:dc': 34,
        'title:href': 45,
        'title:hello:world': 222,
        }

nodes = {}
for k in m:
    paths = k.split(':')
    node = nodes.get(paths[0])
    if node == None:
        node = {}
        nodes[paths[0]] = node
    for path in paths[1:-1]:
        n = node.get(path)
        if n == None:
            n = {}
            node[path] = n
        node = n
    node[paths[-1]] = m[k]

import json

print json.dumps(nodes)
