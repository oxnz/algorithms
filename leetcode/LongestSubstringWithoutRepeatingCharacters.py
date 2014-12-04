#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	LongestSubstringWithoutRepeatingCharacters.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-12-02 01:20:30 CST]
# Last-update:	2014-12-02 01:20:30 CST
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
    def lengthOfLongestSubstring(self, s):
        if not s:
            return 0
        d = {}
        i = 0
        l = len(s)
        m = 0
        while i < l:
            c = s[i]
            if c in d:
                m = max(m, len(d))
                j = d[c] + 1
                d[c] = i
                d = { k:d[k] for k in d if d[k] >= j }
            else:
                d[c] = i
            i += 1
        return m

import unittest

class TestLongestSubstringWithoutRepeatingCharacters(unittest.TestCase):
    def setUp(self):
        self._maxlen = Solution().lengthOfLongestSubstring

    def testLongestSubstrLen(self):
        self.assertEqual(3, self._maxlen('abcabcbb'))
        self.assertEqual(1, self._maxlen('bbbbb'))
        self.assertEqual(12, self._maxlen('wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco'))
        self.assertEqual(12, self._maxlen('hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac'))


if __name__ == '__main__':
    unittest.main()

