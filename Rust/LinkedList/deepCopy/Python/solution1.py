import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def deep_copy_arbitrary_pointer(head):
    if head == None:
        return None

    current = head
    new_head = None
    new_prev = None
    ht = dict()

    # Create copy of the linked list, recording the corresponding
    # nodes in hashmap without updating arbitrary pointer
    while current != None:
        new_node = Node(current.value())

        # copy the old arbitrary pointer in the new node
        new_node.setArb(current.arb())

        if new_prev != None:
            new_prev.setNext(new_node)
        else:
            new_head = new_node

        ht[current] = new_node

        new_prev = new_node
        current = current.next();

    new_current = new_head

    # updating arbitrary pointer
    while new_current != None:
        if new_current.arb() != None:
            node = ht[new_current.arb()]
            new_current.setArb(node)
        new_current = new_current.next()

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
