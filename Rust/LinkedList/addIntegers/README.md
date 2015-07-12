# Add two integers

Given head of two linked lists where each linked list represents an integer number (each node is a digit), add them and return resulting linked list.

## Example

Integer 815 is stored in linked list as `5->1->8` (inversed).

Integer 392 is stored as `2->9->3`.

Sum of the two integers should be `7->0->2->1`.

```
(head1)->[5]->[1]->[8]->[NULL]
(head2)->[2]->[9]->[3]->[NULL]

(result)->[7]->[0]->[2]->[1]->[NULL]
```

1. Handle carry
