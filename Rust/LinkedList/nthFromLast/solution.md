## Solution explanation
* Time: _O(m+n)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

We maintain the head and the tail of the merged linked list. Initially the merged linked list is empty, and
both `head` and `tail` point to `NULL`.

```
(head1)->[4]->[8]->[15]->[19]->(NULL)
(head2)->[7]->[9]->[10]->[16]->(NULL)

(merged)->(NULL)<-(tail)

```

At every step we compare the heads of the original linked lists, and we point the tail of the
merged array to the smaller node (by value). At the same time we change the head of the list
with the smaller value to `.next()`

```
(head1)->[8]->[15]->[19]->(NULL)
(head2)->[7]->[9]->[10]->[16]->(NULL)

(merged)->[4]<-(tail)

```

Repeat the process until one of the original lists is not empty

```
(head1)->[8]->[15]->[19]->(NULL)
(head2)->[9]->[10]->[16]->(NULL)

(merged)->[4]->[7]<-(tail)

```

If at some point one of the arrays is empty while the other one is not, we just poiont the tail
of the merged linked list to the head of the non-empty list.

```
(head1)->[19]->(NULL)
(head2)->(NULL)

(merged)->[4]->[7]->[8]->[9]->[10]->[15]->[16]<-(tail)

```

```
(head1)->(NULL)
(head2)->(NULL)

(merged)->[4]->[7]->[8]->[9]->[10]->[15]->[16]->[19]<-(tail)

```

__Note:__ In the actual solution the `head1` and `head2` will point to valid nodes, and thus will represent
linked lists. If you need to make sure that the heads of the original linked lists are pointing to `NULL`,
in the end of the solution manually update them
