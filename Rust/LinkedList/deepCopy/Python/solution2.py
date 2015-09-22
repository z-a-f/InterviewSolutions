import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def deep_copy_arbitrary_pointer(head):
    if head == None:
        return None

    current = head

    # inserting new nodes within the existing linkedlist
    while current != None:
        new_node = Node(current.value())

        new_node.setNext(current.next())
        current.setNext(new_node)
        current = new_node.next()

    # setting correct arbitrary pointers
    current = head
    while current != None:
        if current.arb() != None:
            current.next().setArb(current.arb().next())

        current = current.next().next()

    # separating lists
    current = head
    new_head = head.next()
    copied_current = new_head

    while current != None:
        copied_current = current.next()
        current.setNext(copied_current.next())

        if copied_current.next() != None:
            copied_current.setNext(copied_current.next().next())

        current = current.next()

    return new_head

if __name__ == '__main__':
    listArb = LinkedList()
    listArb.addFront(21)
    listArb.addFront(14)
    listArb.addFront(7)

    listArb.head().setArb(listArb.head().next().next())
    listArb.head().next().next().setArb(listArb.head());

    print "List with arbitrary pointers:\n", listArb

    listArbCopy = LinkedList()
    listArbCopy.setHead(deep_copy_arbitrary_pointer(listArb.head()));
    listArbCopy.head().next().setValue(123);
    listArb.head().setValue(321);

    print "Updated List with arbitrary pointers:\n", listArb
    print "Copied List with arbitrary pointers:\n", listArbCopy
