## Solution explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

Rotating by one node is very simple, i.e.: just find the last node, and move it to the head of the
linked list. One way of solving the original problem is to rotate by one node at a time, `n` times.
Getting to the last node of linked list requires a linear scan, so such an algorithm requires
_O(mn)_, whenere `m` is the length of a linekd list, and `n` is the number of single rotations
required. In the wors casr the asymptotic time will be _O(n<sup>2</sup>)_. A better solutions is

* Find the length of the linked list
* If `n` is negative or `n` is larger than lengthof linked list, adjust this for number of rotations
needed at tail of linked list. Adjusted number is always a positive integer smaller than `n`.
* If adjusted number of rotations is 0, return (no rotations needed)
* Find n<sup>th</sup> node from last node of linked list. As we already have length of linked list,
it is simpler - just get to the node `x` located at `len-n`. Next pointer of node previous to this node
should be updated to the last node of the linked list.
* Start from `x` and move to the last node of linked list. Update next pointer of last node to the head node
* Make `x` the new head of the list.


Find the length:
```
n = 2 (or n = 7)
len = 5
(input)->[1]->[2]->[3]->[4]->[5]->(NULL)
```

Find the node that stands before the n<sup>th</sup>, adn set the `newHead` pointer:
```
n = 2 (or n = 7)
len = 5
                (temp)  (newHead)
                    v    v
(input)->[1]->[2]->[3]->[4]->[5]->(NULL)
```

Disconnect the `temp` and `newHead`:
```
n = 2 (or n = 7)
len = 5
                (temp)  (newHead)
                    v    v
(input)->[1]->[2]->[3]  [4]->[5]->(NULL)
```

Travel strting from the `newHead` until `NULL`. After that connect the last node to the original `head`
```
n = 2 (or n = 7)
len = 5
                        (newHead)
                         v
->[1]->[2]->[3]->(NULL) [4]->[5]---->|
^------------------------------------
```




