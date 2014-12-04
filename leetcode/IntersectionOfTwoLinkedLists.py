#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	IntersectionOfTwoLinkedLists.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 13:20:37 CST]
# Last-update:	2014-12-02 13:20:37 CST
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

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        return 'node(val = {})'.format(self.val)

    def __repr__(self):
        return self.__str__()

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        node = headA
        lA = 0
        lB = 0
        while node:
            eA = node
            node = node.next
            lA += 1
        if not lA:
            return None
        node = headB
        while node:
            eB = node
            node = node.next
            lB += 1
        if not lB:
            return None
        if eA != eB:
            return None

        nA = headA
        nB = headB
        if lA > lB:
            while nA and lA > lB:
                lA -= 1
                nA = nA.next
        elif lA < lB:
            while nB and lA < lB:
                lB -= 1
                nB = nB.next
        while nA:
            if nA == nB:
                return nA
            else:
                nA = nA.next
                nB = nB.next
        return None

import unittest

class TestIntersectionOfTwoLinkedLists(unittest.TestCase):
    def setUp(self):
        self._ins = Solution().getIntersectionNode

    def test_getIntersectionNode(self):
        self.assertEqual(None, self._ins(None, None))
        self.assertEqual(None, self._ins(None, ListNode(1)))
        self.assertEqual(None, self._ins(ListNode(2), ListNode(1)))
        n1 = ListNode(1)
        n2 = ListNode(2)
        n1.next = n2
        self.assertEqual(n2, self._ins(n1, n2))
        n3 = ListNode(3)
        self.assertEqual(None, self._ins(n1, n3))
        n3.next = n2
        self.assertEqual(n2, self._ins(n1, n3))
        n4 = ListNode(4)
        n3.next = n4
        self.assertEqual(None, self._ins(n1, n3))
        n5 = ListNode(5)
        n6 = ListNode(6)
        n1.next = n2
        n2.next = n3
        n3.next = n4
        n4.next = n6
        n5.next = n6
        n6.next = ListNode(7)
        self.assertEqual(n6, self._ins(n1, n5))
        self.assertEqual(n6, self._ins(n5, n1))


    def listDump(self, head):
        node = head
        while node:
            print '{}->'.format(node),
            node = node.next
        print

if __name__ == '__main__':
    unittest.main()

