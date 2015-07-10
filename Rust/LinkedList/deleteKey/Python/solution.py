import sys                      # Need that to set path
sys.path.insert(0, '../..')     # Need that to import LL

from LinkedList import *    # Linked List defined here

def delete_key(head, key):
    prev = None
    current = head

    while (current != None):
        if (current.value() == key):
            break
        prev = current
        current = current.next()

    # Key not found:
    if current == None:
        return head

    # If node is found:
    if current == head:
        return current.next()

    prev.setNext(current.next())

    return head

if __name__ == '__main__':
    print "Testing Solution deleting key"
    list = LinkedList()
    print "Initial LL:", list

    list.addFront(28)
    list.addFront(21)
    list.addFront(14)
    list.addFront(7)
    print "Populated LL:", list

    list.setHead(delete_key(list.head(), 0))
    print "After removing non-existent element:", list

    list.setHead(delete_key(list.head(), list.head().next().value()))
    print "After removing existent element:", list

    list.setHead(delete_key(list.head(), list.head().value()))
    print "After removing head element:", list
    
