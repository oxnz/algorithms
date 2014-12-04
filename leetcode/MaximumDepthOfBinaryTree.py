#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	MaximumDepthOfBinaryTree.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 17:33:41 CST]
# Last-update:	2014-12-02 17:33:41 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
# License:
# Copyright (c) 2013 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def maxDepth(self, root):
        if not root:
            return 0
        depth = 0
        curlvl = [root]
        nxtlvl = []
        while len(curlvl):
            for node in curlvl:
                nxtlvl += [n for n in [node.left, node.right] if n]
            depth += 1
            curlvl = nxtlvl
            nxtlvl = []
        return depth

import unittest

class TestMaximumDepthOfBinaryTree(unittest.TestCase):
    def setUp(self):
        self._maxDepth = Solution().maxDepth

    def test_maxDepth(self):
        self.assertEqual(0, self._maxDepth(None))
        node = TreeNode(0)
        self.assertEqual(1, self._maxDepth(node))
        node.left = TreeNode(1)
        node.left.left = TreeNode(2)
        self.assertEqual(3, self._maxDepth(node))

if __name__ == '__main__':
    unittest.main()

