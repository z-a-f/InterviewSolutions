---
layout: post
title: "All Unique"
categories: [Interview Preparation]
description:
tags: [algorithm, data structure, python, interview, solution]
comments: true
share: true
---

Implement an algorithm to determine if a string has all unique characters. What if you could cannot use additional data structures?

### Clarification questions

1. Do whitespace characters count as valid characters, that is if there are two spaces in the string, will the result be false?
1. Does capitalization (or any capital letters) matter?

### Solution 1
_Complexity: $$T = O(n), S = O(n)$$_

This solution uses a hash table to store all the characters in the string -- if the character already in the table, it returns `false`

__Note:__ This solution is based on the assumption that hash table access is constant!

{% highlight python %}
def all_unique(st):
  hash = dict()
  for el in st:
    if hash.get(el, True):
      # The character is not found
      hash[el] = False
    else:
      return False
  return True
{% endhighlight %}

### Solution 2
_Complexity: $$T = O(n\log{n}), S = O(1)$$_

If space is more important, and we don't care if the original array is modified or not, we can sort the string inplace, and just iterate through it in linear time.

__Note:__ The assumption here is that either the string is mutable, or the input is not a string but array of characters.

{% highlight python %}
def all_unique(st):
  st.sort() # In-place sort
  for idx in range(1, len(st)):
    if st[idx] == st[idx - 1]:
      return False
  return True
{% endhighlight %}

### Solution 3
_Complexity: $$T = O(n^2), S = O(1)$$_

If we are not allowed to modify the original array, and the space is more important, we can just compare every character to every other character.

{% highlight python %}
def all_unique(st):
  for idx in range(len(st)):
    for jdx in range(idx+1, len(st)):
      if st[idx] == st[jdx]:
        return False
  return True
{% endhighlight %}
