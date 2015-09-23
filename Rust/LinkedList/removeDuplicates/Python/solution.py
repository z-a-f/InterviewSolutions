import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def nth_from_last(head, n):
    second = head
    if (second == None or n < 1):
        return None

    first = head
    while first != None and n > 0:
        first = first.next()
        n -= 1

    # Check out-of-bounds
    if n != 0:
        return None

    while first != None:
        first = first.next()
        second = second.next()

    return second

if __name__ == '__main__':
    list = LinkedList()

    # Check on empty lists:
    found = nth_from_last(list.head(), 1)
    if found != None:
        print "Something went wrong"
    else:
        print "Empty lists work"

    list.addFront(9);
    list.addFront(28);
    list.addFront(21);
    list.addFront(14);
    list.addFront(7);

    print list
    
    found = nth_from_last(list.head(), 100)
    if found != None:
        print "Something went wrong"
    else:
        print "BIG n's work!"

    found = nth_from_last(list.head(), 3)
    if found != None:
        print "n=3 value:", found.value()
    else:
        print "Something went wrong!"

    print list
        
        
