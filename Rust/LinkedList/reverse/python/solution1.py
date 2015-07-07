
import sys                      # Need that to set path
sys.path.insert(0, '../..') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def reverse_iterative(head):
    # Do not check if the size = 0 or 1
    if (head == None or head.next() == None):
        return head

    list_to_do = head.next()

    reversed_list = head
    reversed_list.setNext(None)

    while (list_to_do != None):
        temp = list_to_do
        list_to_do = list_to_do.next()

        temp.setNext(reversed_list)
        reversed_list = temp

    return reversed_list


if __name__ == '__main__':
    print "Testing Solution 1 for reverse"
    list = LinkedList()
    print "Initial LL:", list

    list.addFront(28)
    list.addFront(21)
    list.addFront(14)
    list.addFront(7)
    print "Populated LL:", list

    list.setHead(reverse_iterative(list.head()))
    print "Reversed list:", list
    
