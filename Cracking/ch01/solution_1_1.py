#!/usr/bin/env python

import unittest

def solution(st):
  hash = {}
  for c in st:
    if hash.get(c, None) is not None:
      return False
    hash[c] = True
  return True

def solution_alt1(st):
  # O(n^2)
  for idx in xrange(len(st)):
    for jdx in xrange(idx+1, len(st)):
      if st[idx] == st[jdx]:
        return False
  return True

def solution_alt2(st):
  # O(nlogn), destructive
  st = sorted(st)
  for idx in xrange(1, len(st)):
    if st[idx] == st[idx-1]:
      return False
  return True


class TestAllUniqueSolution(unittest.TestCase):
  def test_long_false(self):
    self.assertFalse(solution('abcdefa'))
  def test_long_true(self):
    self.assertTrue(solution('abcdefg'))
  def test_empty(self):
    self.assertTrue(solution(''))
  def test_short_false(self):
    self.assertFalse(solution('aa'))
  def test_short_true(self):
    self.assertTrue(solution('a'))
    self.assertTrue(solution('abc'))

class TestAllUniqueSolutionAlt1(unittest.TestCase):
  def test_long_false(self):
    self.assertFalse(solution_alt1('abcdefa'))
  def test_long_true(self):
    self.assertTrue(solution_alt1('abcdefg'))
  def test_empty(self):
    self.assertTrue(solution_alt1(''))
  def test_short_false(self):
    self.assertFalse(solution_alt1('aa'))
  def test_short_true(self):
    self.assertTrue(solution_alt1('a'))
    self.assertTrue(solution_alt1('abc'))

class TestAllUniqueSolutionAlt2(unittest.TestCase):
  def test_long_false(self):
    self.assertFalse(solution_alt2('abcdefa'))
  def test_long_true(self):
    self.assertTrue(solution_alt2('abcdefg'))
  def test_empty(self):
    self.assertTrue(solution_alt2(''))
  def test_short_false(self):
    self.assertFalse(solution_alt2('aa'))
  def test_short_true(self):
    self.assertTrue(solution_alt2('a'))
    self.assertTrue(solution_alt2('abc'))

if __name__ == '__main__':
  unittest.main()
