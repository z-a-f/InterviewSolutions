## Solution 2 explanation
* Time: _O(n)_
* Memory: _O(n)_
* File: solution.(cpp|java|py)

_Note_: Recursive method uses __stack__, meaning the the OS might run out of memory if a huge SLL is given.

In order to reverse the SLL, we call the method (recursively), up until there is only a single element in the SLL. Once reached we return 
