## Solution 2 explanation
* Time: _O(n)_
* Memory: _O(n)_
* File: solution2.(cpp|java|py)

_Note_: Recursive method uses __stack__, meaning the the OS might run out of memory if a huge SLL is given.

In order to reverse the SLL, we call the method (recursively), up until there is only a single element in the SLL. Once reached the end of the list, we return the last pointer. Once out of the recursively called function we append the current pointer to it, and return. :) Confusing? Check `solution2.cpp`
