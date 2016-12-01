#!/usr/bin/env python

import unittest

def solution(st):
  ## reverse routine
  # Don't use the built-ins
  st = list(st) # Make it mutable
  for idx in xrange(len(st) / 2):
    st[idx], st[len(st) - 1 - idx] = st[len(st) - 1 - idx], st[idx]

  return ''.join(st)

class TestReverseString(unittest.TestCase):
  def test_even(self):
    st = 'abcd'
    self.assertEqual(solution(st), st[::-1])

  def test_odd(self):
    st = 'abc'
    self.assertEqual(solution(st), st[::-1])

  def test_empty(self):
    st = ''
    self.assertEqual(solution(st), st[::-1])

if __name__ == '__main__':
  unittest.main()
