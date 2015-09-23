## Solution explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution.(cpp|java|py)

Use two pointers, while one of the pointers is _n nodes apart_ from the other.

```
n=3
      (first)
         v
(head)->[7]->[14]->[21]->[28]->[9]->(NULL)
         ^
      (second)
```

Move the `first` pointer by `n` positions
```
n=3
                       (first)
                          v
(head)->[7]->[14]->[21]->[28]->[9]->(NULL)
         ^
      (second)
```

Now move both pointers until the `first` pointer is pointing at `NULL`:
```
n=3
                                  (first)
                                     v
(head)->[7]->[14]->[21]->[28]->[9]->(NULL)
                    ^
                 (second)
```

Now, return the `second` pointer. If the `first` pointer reaches `NULL` before being _n nodes apart_
from the `second`, return `NULL`
