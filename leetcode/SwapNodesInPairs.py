#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	SwapNodesInPairs.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-05-13 17:37:16 CST
# Last-update:	2016-05-13 17:37:16 CST
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

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return str(self.val)

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head != None and head.next != None:
            ret = head.next
        else:
            ret = head
        prev = None
        p = head
        while p != None and p.next != None:
            pn = p.next
            pnn = p.next.next
            pn.next = p
            if prev:
                prev.next = pn
            prev = p
            prev.next = None
            p = pnn
        if prev != None and p != None:
            prev.next = p

        return ret

    def reverseList(self, head):
        if head == None or head.next == None:
            return head
        while head != None and head.next != None:
            head.next.next = head
            head = head.next


if __name__ == '__main__':
    s = Solution()
    n7 = ListNode(7)
    n6 = ListNode(6)
    n6.next = n7
    n5 = ListNode(5)
    n5.next = n6
    n4 = ListNode(4)
    n4.next = n5
    n3 = ListNode(3)
    n3.next = n4
    n2 = ListNode(2)
    n2.next = n3
    n1 = ListNode(1)
    n1.next = n2
    head = n1
    p = head
    print('before')
    while p != None:
        print(p.val)
        p = p.next
    #head = s.swapPairs(n1)
    head = s.reverseList(n1)
    p = head
    print('after')
    while p != None:
        print(p.val)
        p = p.next
