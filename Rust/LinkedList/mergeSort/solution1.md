## Solution explanation
* Time: _O(nlogn)_
* Memory: _O(logn)_
* File: solution.(cpp|java|py)

The merge sort is based on the `Divide and Conquer` approach: in the first step we divide the
problem, and in the second step we merge it back together, while sorting it. This allows for
a recursive approach to the problem. The dividing of the problem is recursively applied until
the size of the problem is `0` or `1` - at this sizes, the problem (list) is sorted.

### Example
Assume we have the following linked list to sort using mergeSort:
```
[29]->[23]->[82]->[11]
```

We split the list into two halves:

```
[29]->[23]  [82]->[11]
```

The sizes of individual lists is neither `0`, nor `1`, so we recursively call merge sort
on both of them:

```
[29]  [23]  [82]  [11]
```

At this level we have all the lists of size `1`, so we start merging them. When merging we put
the smaller valued elements first, so that the resulting lists would be sorted:

```
[23]->[29]  [11]->[82]
```

Repeat the process until all the individual lists are combined:

```
[11]->[23]->[29]->[82]
```

The time it will take to run the whole thing is given as `T(n)=2T(n/2)+n`.



