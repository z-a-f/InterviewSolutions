# Deep copy of linked list with arbitraty pointer

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
