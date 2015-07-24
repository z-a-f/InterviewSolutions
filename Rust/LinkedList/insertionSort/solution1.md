## Solution explanation
* Time: _O(n^2)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

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
