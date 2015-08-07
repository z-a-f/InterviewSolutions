## Solution explanation
* Time: _O(n^2)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

__Note__: There is a bug in this solution - if the nodes are already sorted, it doesn't remove them from the original linked list. So, if some part of the initial linked list is sorted (partially sorted), after the insertion sort the original list will still have some elements (not all though).

Concept of Insertion SOrt is very simple. We'll maintain two linked lists:
* Original list (given to us as input)
* Sorted list (initially empty)

Here is how the algorithm works.

While Original list is not empy:

1. Remove an element (say `X`) from the Original list
2. Insert `X` at correct sorted position in the Sorted list.

In order to insert a node in Sorted linked list we may need to scan the whole sorted list depending upon node being inserted. Let's take an example where input linked list is `29->23->82->11`:
```
(orig)->[29]->[23]->[82]->[11]->(NULL)
(sort)->(NULL)
```
Remove the first node:
```
(orig)->[23]->[82]->[11]->(NULL)
(sort)->[29]->(NULL)
```
Now, remove the first node from the `orig` linked list and insert it at the appropriate position.
```
(orig)->[82]->[11]->(NULL)
(sort)->[23]->[29]->(NULL)
```
Repeat the process until the whole list is sorted
```
(orig)->[11]->(NULL)
(sort)->[23]->[29]->[82]->(NULL)

(orig)->(NULL)
(sort)->[11]->[23]->[29]->[82]->(NULL)
```
