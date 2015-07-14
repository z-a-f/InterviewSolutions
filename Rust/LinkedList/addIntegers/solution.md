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

We'll add current digits (which are also first digits at this point) 5 and 2 from both lists and will add `7(= 5 + 2)` to the tail of result linked list. There is no carry in this case, so carry remains 0.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[7]->[NULL]
carry = 0
```

We'll add current digits 1 and 9 from both and will add 0 from result `10 (= (0 + 1 + 9) % 10)` to the tail of result linked list. Carry becomes `1 (= (0 + 1 + 9)/10)` in this case.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[7]->[0]->[NULL]
carry = 1
```

At this step we'll add carry and current digits 8 and 3 from both lists and will add 2 from result `12 (= 1 + 8 + 3)` to the tail of result linked list. Carry becomes 1 in this case.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[7]->[0]->[2]->[NULL]
carry = 1
```

Both lists have exhausted now, but carry is still greater than 0, so we'll add the carry to the tail of the result.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]
(reslt)->[7]->[0]->[2]->[1]->[NULL]
carry = 0
```

There is no carry anymore, so all the iterations are complete.

## Additional Thoughts
In some cases interviewer might ask that digits in the linked list are stored from left to right i.e. in same order as they appear in the number itself. You have two options in this case:

* Reverse the linked list first, and apply the above algorithm.
* If the data structure is __doubly__ linked list, you can simply run above program from tail to head and keep addign resulting digit at head of result linked list.



