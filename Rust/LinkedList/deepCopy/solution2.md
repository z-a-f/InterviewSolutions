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
2. Add arbitrary pointers to the copied nodes. Each original node would be pointing to its copy. With the understanding "if original node points to arbitrary pointer `P`, then the copy of arbiter pointer is located at `P->next`", we do another pass on the linked list and only process the odd nodes (which are nodes from the original linked list). At each original node, we set the arbitrary pointer of its copy to the copy of original node's arbitrary pointer. Therefore, if P is the current node, then set `P->next->arb` (arbitrary pointer of copied node) points to the copy of P's arbitrary pointer(`P->arb->next`). For each original node p: `set p->next->arb = p->arb->next`.
3. Separate the two linked lists: it is done by iterating through the list and setting up next pointers for nodes in both new and old list. We start the iteration from the beginning of the linked list. We know that the first element in the list is the head of old list (original head) and second element in the list is the head of the copied list.
4. After the above steps, every odd node belongs to the original list and every even node belongs to the copied list. Using this, we can form an algorithm where we visit a node and setup the pointers for `P` and `P->next` such that `P` and copy of `P` now point to their true `next` nodes.

Now two lists are separated.
