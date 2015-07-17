## Solution 2 explanation
* Time: _O(n)_
* Memory: _O(1)_
* File: solution2.(cpp|java|py)

We will create copy of the linked list in three passes
1. Create copy of each node such that the original node's next pointer is pointing to it's copy.
2. Fix the arbitrary pointers in the copied nodes
3. Separate copied linked list from the original linked list

### Example
Given the original linked list with arbitrary pointer:
1. During the first iteration, visit each node and create a copy of the node. Then set the `next` pointer of original node to the copied node and the `next` pointer of the copied node will point to the remaining original list. Once all the nodes are copied, all odd nodes in the linked list are from the original list and all even nodes will become part of the copied list.
2.
