# Check if two trees are identical
[solution](solution.md)

Given roots of two binary trees, determine if these trees are identical or not. Identical trees have the same structure and data at each node.

## Example

Two trees are identical if they have the same data and the same physical layout.
For example:

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

If trees have the same data, that doesn't mean they are identical:
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

The trees above although having the same data, have different structure, and thus are not identical

1. Depth first traversal
2. Recursion?

