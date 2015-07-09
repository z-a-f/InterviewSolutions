# Delete node with a give key
Given head of a linked list and a key, delete node with this given key from the list

## Example
If node with the key to be deleted is in the middle of the SLL, then next pointer in node previous to the key node should start pointing to the node next to key node.
```
(head)->[70]->[10]->[55]->[22]->[NULL]
(key)->[55]
```

1. Keep track of previous pointer
