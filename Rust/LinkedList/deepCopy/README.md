# Deep copy of linked list with arbitraty pointer

[solution1](solution1.md)

[solution2](solution2.md)

Given a linked list where every node has two pointers - First one is the regulat `next` pointer, while another is an arbitrary pointer `arb`. Arbitrary pointer can point to any node in the linked list. Write a code to make a deep copy of the given linked list.

## Example
Linked list with arbitrary pointers:
```
         _____________
         |            v
(HEAD)->[14]->[21]->[NULL]
 ^ L___________^|
 |______________|
```


1. Hash Table
