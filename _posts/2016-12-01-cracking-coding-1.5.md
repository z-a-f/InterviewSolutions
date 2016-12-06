---
layout: post
title: "String Compression"
categories: [Cracking the Coding Interview]
description:
tags: [algorithm, data structure, python, interview, solution]
comments: true
share: true
---
Implement a method to perform string compression using the counts of repeated characters. If the "compressed" string would not become smaller than the original, return the original string.

Assume that the string has only upper and lower case letters (`a-z`)

### Example

{% raw %}
    Input:  aabcccccaaa
    Output: a2b1c5a3
{% endraw %}

<!-- more -->

### Solution
_Complexity: $$T = O(n), S = O(n)$$_ (to store the output)

```python
def compress(st):
    result = bytearray() # Bytearray is mutable
    if len(st) == 0:
        return result
    count = 1
    current = st[0]
    result.append(current)
    for idx in xrange(1, len(st)):
        if st[idx] == current:
            count += 1
        else:
            result.append(str(count))
            count = 1
            current = st[idx]
            result.append(current)
    result.append(str(count))
    if len(result) > len(st):
        return st
    return result

st = 'aabcccccaaa'
print 'Result:', compress(st)
```
```raw
Result: a2b1c5a3
```
