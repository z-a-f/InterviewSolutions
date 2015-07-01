## Solution 1 explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

Given the SLL `(head)->[7]->[14]->[21]->[28]->[NULL]`, if it only contains 0 or 1 nodes, then the current list is the same when reversed, and can be returned as it is. If there are two or more nodes, then iterative solution starts with 2 pointers:
1. A pointer to already reversed SLL (head)
2. A pointer to the remaining SLL (head->next)

We first set the `still_to_do = head->next`, and _only after that_ we set `head->next = NULL`. At every step we take the first element in the `still_to_do` and prepend it to the `head`-list. Loop terminates when `still_to_do = NULL`.

Here how the pointers will look like after each iteration:

1. ```
(head)->[7]->[NULL]
(still_to_do)->[14]->[21]->[28]->[NULL]
```

2. ```
(head)->[14]->[7]->[NULL]
(still_to_do)->[21]->[28]->[NULL]
```

3. ```
(head)->[21]->[14]->[7]->[NULL]
(still_to_do)->[28]->[NULL]
```

4. ```
(head)->[28]->[21]->[14]->[7]->[NULL]
(still_to_do)->[NULL]
```