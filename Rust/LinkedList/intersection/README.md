# Intersection Point in Two Lists
[solution](solution.md)

Given head nodes of two linked lists which might or might not intersect, find out if they do, and return the intersection node (or null if not intersecting)

## Example

This is the non-intersecting lists:

```
(head1)->[29]->[23]->[82]->[11]->(NULL)
(head2)->[13]->[4]->[18]->[12]->(NULL)
```

This is the example of the intersecting nodes:

```
(head1)->[29]->[23]->[82]->[12]->[27]->(NULL)
(head2)->[13]->[4]----------^
```

1. Find length of both linked lists
