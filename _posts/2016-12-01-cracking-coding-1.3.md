---
layout: post
title: "String Permuations"
categories: [Interview Preparation]
description:
tags: [algorithm, data structure, python, interview, solution]
comments: true
share: true
---
Given two strings, write a method to decide if one is a permutation of the other.

### Solution
_Complexity: $$T = O(n), S = O(n)$$_

Assuming that the length are the same, we can count all the characters in one string, and see if the numbers match in the other string. For fast access we can use a hash table or an array to store the counts.

{% highlight python %}
def is_permutation(str1, str2):
  hash = dict()
  for char in str1:
    hash[char] = hash.get(char, 0) + 1
  for char in str2:
    if hash.get(char, 0) == 0:
      return False
    hash[char] -= 1
  return True
{% endhighlight %}
