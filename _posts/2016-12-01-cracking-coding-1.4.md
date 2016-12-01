---
layout: post
title: "%20fy the string"
categories: [Cracking the Coding Interview]
description:
tags: [algorithm, data structure, python, interview, solution]
comments: true
share: true
---
Given a string[^1], replace all spaces with `%20`. Assume that the string has sufficient space at the end to hold additional characters. Also, the "true" length of the string is given. Make sure the space occupied is constant.

### Example

{% raw %}
Input: "Mr John Smith    ", 13

Output: "Mr%20John%20Smith"
{% endraw %}

### Solution
_Complexity: $$T = O(n), S = O(1)$$_

Because the question says that we have some buffer in the end of the string, and we are given the "true" length of the string, we can start from the end, and move every character from the "true" end to the string end. If we encounter a space, we place a `%20` instead

{% highlight python %}
def percent_twentyfy(st, n):
  idx = len(st) - 1 # The end of the string
  jdx = n-1 # The "true" end of the string
  while idx >= 0 and jdx >= 0:
    if st[jdx] == ord(' '):
      st[idx] = '0'
      st[idx-1] = '2'
      st[idx-2] = '%'
      idx -= 3
    else:
      st[idx] = st[jdx]
      idx -= 1
    jdx -= 1
{% endhighlight %}

[^1]: If you do it in Python: because strings in python are not mutable, assume that the input is a `bytearray`
