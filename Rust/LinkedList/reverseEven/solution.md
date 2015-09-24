## Solution explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

One of the solutions would be to copy the values of the elements or re-allocate memory for the nodes.
However, this is inefficient. Instead we create two linked lists, one with odd elements and another with
even elements. While extracting the elements into the even linked list we push them at the end,
such that when merging with the odd linked list, we get the reverse of the original linked list.

```
(input)->[7]->[14]->[21]->[28]->[9]->(NULL)

(odd)->[7]->[21]->[9]->(NULL)
(even)->[28]->[14]->(NULL)
```
