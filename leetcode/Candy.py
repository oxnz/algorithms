#!/usr/bin/env python
# -*- coding: utf-8 -*-
# ===============================================================
#
# Filename:	Candy.py
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		2016-06-29 10:23:45 CST
# Last-update:	2016-06-29 10:23:45 CST
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

class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        if len(ratings) < 2:
            return len(ratings)
        if len(ratings) < 3:
            if ratings[0] == ratings[1]:
                return 2
            else:
                return 3
        trend = ratings[1] - ratings[0]
        if trend != 0:
            trend /= abs(trend)
        length = 2
        first = ratings[0]
        last = ratings[1]
        if first == last:
            ncandy = 2
        else:
            ncandy = 3
        for v in ratings[2:]:
            ntrend = v - last
            if ntrend != 0:
                ntrend /= abs(ntrend)
            if ntrend == trend:
                if trend == 0:
                    ncandy += 1
                else:
                    ncandy += 1 + length
                length += 1
            elif ntrend > trend:
                if trend == 0:
                    ncandy += 2
                    length = 1
                else:
                    if ntrend == 0:
                        ncandy += 1
                        length = 1
                    else:
                        ncandy += 2
                        length = 1
            else:
                if trend == 0:
                    ncandy += length + 1
                    length = 1
                else:
                    if ntrend == -1:
                        ncandy += 1
                        length = 1
                    else:
                        ncandy += length
                        length = 1
            trend = ntrend
            last = v
        return ncandy

import unittest

class TestRegexpMatch(unittest.TestCase):
    def setUp(self):
        self._candy = Solution().candy

    def test_candy(self):
        for ratings, ncandy in [
            [[], 0],
            [[1], 1],
            [[2], 1],
            [[1, 1], 2],
            [[2, 2], 2],
            [[1, 2], 3],
            [[2, 1], 3],
            [[1, 1, 1], 3],
            [[1, 2, 3], 6],
            [[2, 2, 2], 3],
            [[1, 2, 1], 4],
            [[2, 1, 2], 5],
            [[2, 2, 1], 5],
            [[1, 2, 3, 4], 10],
            [[1, 2, 3, 1], 7],
            [[1, 2, 2, 1], 6],
        ]:
            try:
                nreal = self._candy(ratings)
                nexct = ncandy
                self.assertEqual(nreal, nexct)
            except AssertionError:
                print '[failed] candy({})({}) != {}'.format(ratings, nreal, nexct)

if __name__ == '__main__':
    unittest.main()
