## Solution 1 explanation
* Time: _O(n)_
* Memory: _O(n)_
* File: solution1.(cpp|java|py)

As the first step, create a copy of the linked list. Copy the original arbitrary pointer in the new node during copy. While creating the copy, keep a map where key is the address of the copied node. At the end of the first pass, a list copy would have been created but arbitrary pointer would still be pointing to nodes in the original list.

Once the copy has been created, do another pass on the copied linked list and update arbitrary pointers to new address using the map created in the first pass.


