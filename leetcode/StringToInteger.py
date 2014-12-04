class Solution:
    # @return an integer
    def atoi(self, str):
        d = "0123456789"
        i = 0
        s = str
        l = len(s)
        sign = 1
        v = 0
        while i < l and s[i] == ' ':
            i += 1
        if i == l:
            return 0
        if s[i] == '+':
            i += 1
        elif s[i] == '-':
            i += 1
            sign = -1
        if i == l:
            return 0
        while i < l and s[i] in d:
            v = v * 10 + ord(s[i]) - ord('0')
            i += 1
        v *= sign
        if v > 2147483647:
            return 2147483647
        elif v < -2147483648:
            return -2147483648
        return v

import unittest

class TestAtoi(unittest.TestCase):
    def setUp(self):
        self._atoi = Solution().atoi

    def test_atoi(self):
        for s in [ '', '+', '-', '0', '1', '9', '10', '+1', '-1', '+9', '-9', '+10', '-10',
            '123', '-123', ' -13', '-21321', '+321', '         12']:
            try:
                v = int(s)
            except:
                v = 0
            self.assertEqual(v, self._atoi(s))


if __name__ == '__main__':
    unittest.main()

