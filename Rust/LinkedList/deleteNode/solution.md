## Solution explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|python)

First, we have to find the key in the linked list. We'll keep two pointers: `current` and `previous` as we iterate through the linked list. If key is found in the linked list, `current` pointer would be pointing to the node containing the key to be deleted, while `previous` would point to the node before it (or HEAD). To delete the node with the key, we make sure the `previous.next` points to `current.next`.

__NOTE__ that in C-like languages the memory of the node to be deleted has to be _freed_.

__NOTE__ that if the current node is the `head`, the previous should be pointing at the `NULL`. In this case we just move the `head` node to its `.next` node.

```
key = 55
(head)->[70]->[10]->[55]->[22]->[NULL]
               ↑     ↑
              prev  curr
```
