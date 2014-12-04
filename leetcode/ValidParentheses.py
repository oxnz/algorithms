#!/usr/bin/env python
# letcode: Valid Parentheses

import unittest

class Solution:
    def isValid(self, s):
        stack = []
        mdict = {
            ')' : '(',
            ']' : '[',
            '}' : '{'
        }
        for c in s:
            if c in ('[', '(', '{'):
                stack.append(c)
            elif len(stack) == 0 or mdict[c] != stack.pop():
                return False
        return len(stack) == 0


class TestSolution(unittest.TestCase):
    def setUp(self):
        self._solution = Solution()

    def test_isValid(self):
        self.assertTrue(self._solution.isValid('[]'))
        self.assertTrue(self._solution.isValid('()'))
        self.assertTrue(self._solution.isValid('{}'))
        self.assertTrue(self._solution.isValid('()[]{}'))
        self.assertFalse(self._solution.isValid('(]'))
        self.assertFalse(self._solution.isValid('([)]'))

if __name__ == '__main__':
    unittest.main()
