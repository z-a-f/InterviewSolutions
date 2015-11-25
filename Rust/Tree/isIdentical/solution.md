## Solution explanation
* Time: _O(n)_
* Memory: _O(h)_, where _h_ is _log(n)_ for balanced tree and _n_ for worst case
* File: [C++](C++/solution.cpp), [Java](Java/solution.java), [Python](Python/python.py)

Let's define a recursive solution. Two binary trees are identical if:

* Data on their root nodes is the same or both nullptr
* Left sub-tree of A is identical to left sub-tree of B
* Right sub-tree of A is identical to right sub-tree of B

### Example for identical trees
Given two identical trees A and B, write the stack entries with the call for `is_identical(A',B')` as well as the stack depth:
```
            A
            |
		  [100]
	     /     \
    [50]		[200]
    /  \        /   \
[25]	[]	[125]	[350]


            B
            |
		  [100]
	     /     \
    [50]		[200]
    /  \        /   \
[25]	[]	[125]	[350]
```

```
1. is_identical(100, 100)
2. is_identical(50, 50)
3. is_identical(25, 25)
3. is_identical(null, null) // Technically this one is not called
2. is_identical(200, 200)
3. is_identical(125, 125)
3. is_identical(350, 350) // Exhausted the tree, stack will now unwind
0.
```

### Example for non-identical trees
Given two non-identical binary trees A and B, write the stack entries with the call for `is_identical(A', B')`, stack depth, and point of false return
```
            A
            |
		  [100]
	     /     \
    [50]		[200]
    /  \        /   \
[25]	[]	[125]	[350]


            B
            |
		  [100]
	     /     \
    [25]		[200]
    /  \        /   \
  []	[50]	[125]	[350]
```

```
1. is_identical(100, 100)
2. is_identical(50, 25)
break
```

