#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	BinaryTreePreorderTraversal.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-01 20:36:15 CST]
# Last-update:	2014-12-01 20:36:15 CST
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


class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        stack = [root]
        v = []
        while len(stack):
            node = stack[0]
            stack = stack[1:]
            if node:
                v.append(node.val)
                stack.insert(0, node.left)
                stack.insert(1, node.right)
        return v

    def preloop(self, root):
        v = []
        if root:
            v.append(root.val)
            v += self.preloop(root.left)
            v += self.preloop(root.right)
        return v

    def inloop(self, root):
        v = []
        if root:
            v += self.inloop(root.left)
            v.append(root.val)
            v += self.inloop(root.right)
        return v

    def postloop(self, root):
        v = []
        if root:
            v += self.postloop(root.left)
            v += self.postloop(root.right)
            v.append(root.val)
        return v

    def inorderTraversal(self, root):
        stack = [root]
        v = []
        while len(stack):
            node = stack[0]
            stack = stack[1:]

    def zigzagLevelOrder(self, root):
        if not root:
            return []
        curlvl = [root]
        v = []
        reverse = True
        while len(curlvl):
            v.append([node.val for node in curlvl])
            reverse = not reverse
            nxtlvl = []
            if reverse:
                curlvl = reversed(curlvl)
            for node in curlvl:
                if reverse:
                    nxtlvl += [ n for n in [node.left, node.right] if n ]
                else:
                    nxtlvl = [ n for n in [node.right, node.left] if n ] + nxtlvl
            curlvl = nxtlvl
        return v




import unittest

# Definition for a  binary tree node
class TreeNode:
     def __init__(self, x, l, r):
         self.val = x
         self.left = l
         self.right = r

class TestTraversal(unittest.TestCase):
    def setUp(self):
        solu = Solution()
        self._trav = solu.preorderTraversal
        self._ptrav = solu.preloop
        self._zigzag = solu.zigzagLevelOrder

    def test_123(self):
        tree = TreeNode(1, None, TreeNode(2, TreeNode(3, None, None), None))
        self.assertEqual(self._trav(tree), [1,2,3])
        self.assertEqual([[1],[2],[3]], self._zigzag(tree))
        tree = TreeNode(1, None, None)
        self.assertEqual(self._trav(tree), [1])
        tree = None
        self.assertEqual(self._trav(tree), [])
        tree = TreeNode(1, None, None)
        tree.left = TreeNode(2, TreeNode(4, None, None), TreeNode(5, None, None))
        tree.right = TreeNode(3, TreeNode(6, None, None), TreeNode(7, None, None))
        self.assertEqual(self._trav(tree), self._ptrav(tree))
        self.assertEqual([[1],[3, 2],[4, 5, 6, 7]], self._zigzag(tree))

if __name__ == '__main__':
    unittest.main()
