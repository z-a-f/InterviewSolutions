## Solution explanation
* Time: _O(m+n)_, where _m_ and _n_ are the lengths of two lists
* Memory: _O(1)_
* File: solution.(cpp|java|py)

Usually first solution that comes to mind is of quadratic complexity: for each node in one of the lists do a linear search in the other list. if any node (address) in the 1st list is found in the second list, that would be the intersection point. __This solution is not efficient though.__

A more efficient sollution would be creating a hashset of one of the linked lists, and compare the hashset to the second list. This will need linear time and memory complexity.

We can save up the memory by using another algorithm. First we need to realize is that after the intersection node the linked lists share all other nodes. This means that if the lists have the same lengths, we can just compare the lists elementwise till we find the common node.

If the lists are not of the same lengths:
1. Find the lengths of both lists
2. Calculate length difference `d`
3. Move a pointer `d` steps forward in the longer linked list
4. Apply the algorithm described above

## Example
Length difference `d` here is 1:
```
(head1)->[29]->[23]->[82]->[12]->[27]->(NULL)
(head2)------->[13]->[4]----^
```

Create two pointers and increment the longer one `d` steps
```
         (l1)
          v
(head1)->[29]->[23]->[82]->[12]->[27]->(NULL)
(head2)------->[13]->[4]----^
                ^
               (l2)
                
               (l1)
                v
(head1)->[29]->[23]->[82]->[12]->[27]->(NULL)
(head2)------->[13]->[4]----^
                ^
               (l2)
```

Now increment both list pointers until they are equal to each other:
```
                           (l1)
                            v
(head1)->[29]->[23]->[82]->[12]->[27]->(NULL)
(head2)------->[13]->[4]----^
                            ^
                           (l2)
```

