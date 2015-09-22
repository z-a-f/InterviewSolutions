# from pympler.tracker import SummaryTracker
# tracker = SummaryTracker()

import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python')     # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def reverse_recursive (head):
    # Do not check if the size = 0 or 1
    if (head == None or head.next() == None):
        return head

    reversed_list = reverse_recursive(head.next())

    head._next.setNext(head)
    head.setNext(None)
    
    return reversed_list


if __name__ == '__main__':
    print "Testing Solution 2 for reverse"
    list = LinkedList()
    print "Initial LL:", list

    list.addFront(28)
    list.addFront(21)
    list.addFront(14)
    list.addFront(7)
    print "Populated LL:", list

    list.setHead(reverse_recursive(list.head()))
    print "Reversed list:", list
    
    # tracker.print_diff()
