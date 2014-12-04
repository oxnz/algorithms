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

class Token(object):
    START = object()
    CHAR = object()
    DOT = object()
    STAR = object()
    END = object()
    def __init__(self, typ = CHAR, char = None):
        self._type = typ
        self._char = char

    @property
    def type(self):
        return self._type

    @property
    def char(self):
        return self._char

    def __repr__(self):
        if self._type == Token.CHAR:
            s = 'CHAR({})'.format(self._char)
        elif self._type == Token.DOT:
            s = 'DOT'
        elif self._type == Token.STAR:
            s = 'STAR'
        elif self._type == Token.START:
            s = 'START'
        elif self._type == Token.END:
            s = 'END'
        else:
            raise Exception('Invalid token type: {}'.format(self._type))
        return 'Token: ' + s

class State(object):
    __count = -1
    def __init__(self, token, out = None):
        self._token = token
        if not out:
            out = set()
        self.out = out
        State.__count += 1
        self._id = State.__count

    @property
    def id(self):
        return self._id

    def match(self, c):
        if self._token.type == Token.CHAR:
            return c == self._token.char
        elif self._token.type == Token.DOT:
            return True
        elif self._token.type == Token.START:
            return False
        elif self._token.type == Token.STAR:
            return False

    def __repr__(self):
        return 'State instance({}): {} -> {}'.format(hex(self._id), self._token, [hex(s.id) for s in self.out])

    @classmethod
    def count(cls):
        return self.__count

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        if len(p) == 0:
            return s == p
        self._match = State(Token(Token.END))
        cset = self.parse(p)
        if not s:
            return self._match in cset
        for c in s:
            nset = set()
            for s in cset:
                if s.match(c):
                    nset |= set(s.out)
            if len(nset) == 0:
                return False
            cset = nset
        if self._match in cset:
            return True
        return False

    def lex(self, p):
        l = len(p)
        if not l:
            raise Exception('Empty regexp')
        if p[0] == '*':
            raise Exception('Invalid regexp')
        i = 0
        star = 0 # adjacent star
        while i < l:
            c = p[i]
            if c == '*':
                if star:
                    # skip multi star klenee closure
                    pass
                else:
                    yield Token(Token.STAR)
                star += 1
            else:
                star = 0
                if c == '.':
                    yield Token(Token.DOT)
                else:
                    yield Token(Token.CHAR, c)
            i += 1

    def parse(self, p):
        tokens = [token for token in self.lex(p)]
        l = len(tokens)
        start = State(Token(Token.START))
        pset = set([start]) # set need patch out
        i = 0
        while i < l:
            state = State(tokens[i])
            for s in pset:
                s.out.add(state)
            npset = set([state]) # next patch set
            if i + 1 < l and tokens[i+1].type == Token.STAR:
                i += 1
                state.out.add(state)
                npset |= pset
            pset = npset
            i += 1
        for tok in pset:
            tok.out.add(self._match)
        return start.out

import unittest

class TestRegexpMatch(unittest.TestCase):
    def setUp(self):
        self._isMatch = Solution().isMatch

    def test_isMatch(self):
        for s, p, v in [
            ['aa', 'a', False],
            ['aa', 'aa', True],
            ['aaa', 'aa', False],
            ['aa', 'a*', True],
            ['aa', '.*', True],
            ['ab', '.*', True],
            ['aab', 'c*a*b', True],
            ['a', 'a*a*', True],
            ['aaa', 'a*a*a*a*', True],
            ['aaaaaaaaaaaaaab', 'a*a*a*a*a*a*a*b', True],
            ['aaaaaaaaaaaaab', 'a*a*a*a*a*a*a*a*a*a*a*a*b', True],
            ['ab', '.*c', False],
            ['', '.*', True],
        ]:
            self.assertEqual(v, self._isMatch(s, p))

if __name__ == '__main__':
    unittest.main()

