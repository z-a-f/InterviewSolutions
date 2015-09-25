# Rotate a Linked List
[solution](solution.md)

Given the head node of a singly linked list and an integer `n`, rotate the linked list
by `n` to the right

## Example
```
n = 2 (or n = 7)
(input)->[1]->[2]->[3]->[4]->[5]->(NULL)
(output)->[4]->[5]->[1]->[2]->[3]->(NULL)
```

```
n = -2
(input)->[1]->[2]->[3]->[4]->[5]->(NULL)
(output)->[3]->[4]->[5]->[1]->[2]->(NULL)
```


1. Use linear scan to find n<sup>th</sup> node

