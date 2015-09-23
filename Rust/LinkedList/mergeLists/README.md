# Merge Two Sorted Linked Lists
[solution](solution.md)

Give the heads of two __sorted__ linked lists, merge the two, such that
the resulting linked list is sorted. Return the head of the new linked list

## Example
```
(head1)->[4]->[8]->[15]->[19]->(NULL)
(head2)->[7]->[9]->[10]->[16]->(NULL)

(merged)->[4]->[7]->[8]->[9]->[10]->[15]->[16]->[19]->(NULL)
```

1. Use two iterators to scan both linked lists
2. Use a pointer to point to the end of the merged sort as it is created
