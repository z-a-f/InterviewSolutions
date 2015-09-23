## Solution explanation
* Time: _O(n)_
* Memory: _O(n)_ - to store hashset
* File: solution.(cpp|java|py)

A simple solution wowuld be to use a hashset (requires memory linearly proportional to the number of elements in the linked list)

* Add the value of the first element to the hashset
* Starting from the second element in the linked list:
  * If the value is in the hashset, remove the node
  * Else add the value to the hashset and go to the next node

```
     (current)
         v
(head)->[4]->[7]->[4]->[9]->[4]->[9]->(NULL)
HASHSET: []
```

```
          (current)
              v
(head)->[4]->[7]->[4]->[9]->[4]->[9]->(NULL)
HASHSET: [4]
```

```
               (current)
                   v
(head)->[4]->[7]->[4]->[9]->[4]->[9]->(NULL)
HASHSET: [4, 7]
```

```
               (current)
                   v
(head)->[4]->[7]->[9]->[4]->[9]->(NULL)
HASHSET: [4]
```

etc.
