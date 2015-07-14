## Solution explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|python)

We'll start from heads of both linked lists, keep adding current digits and insertto a new node with resulting digit at the tail of result linked list. We'll keep doing this for all digits in both linked lists. If one of the linked list ends sooner, we'll continue with the other linked list. We also need to maintain carry.

Initially result linked list is empty

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[NULL]
```

We'll add current digits (which are also first digits at this point) 5 and 2 from both lists and will add `7( = 5 + 2)` to the tail of result linked list. There is no carry in this case, so carry remains 0.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[7]->[NULL]
carry = 0
```

We'll add current digits 1 and 9 from both and will add 0 from result `10 ( ( = 0 + 1 + 9) % 10)` to the tail of result linked list. Carry becomes `1 ( (0 + 1 + 9)/10`
