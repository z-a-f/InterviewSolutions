# Delete node with a given key
Given head of a linked list and a key, delete node with this given key from the list

## Example
If node with the key to be deleted is in the middle of the SLL, then next pointer in node previous to the key node should start pointing to the node next to key node.
```
(head)->[70]->[10]->[55]->[22]->[NULL]
(key)->[55]

(head)->[70]->[10]->[22]->[NULL]
```

If node with the key to be deleted is the head node, then head should start pointing to the 2nd node
```
(head)->[70]->[10]->[55]->[22]->[NULL]
(key)->[70]

(head)->->[10]->[55]->[22]->[NULL]
```

1. Keep track of previous pointer
