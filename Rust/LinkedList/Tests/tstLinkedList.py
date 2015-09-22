import sys                      # Need that to set path
sys.path.insert(0, '../../Library/Python')     # Need that to import LL

from LinkedList import *    # Linked List defined here


if __name__ == '__main__':

    print "\n1) Testing Node..."
    n = Node('abc', None)
    n.setNext(Node(3, None))
    print "New node n:", n
    print "Next of the n:", n.next()

    print "\n2)Testing LinkedList..."
    list = LinkedList()
    print "Initial list is:\n", list
    print "Front of empty list:\n", list.front()

    list.addFront(28)
    list.addFront(21)
    list.addFront(14)
    list.addFront(7)
    print "After populating the list:\n", list

    print "\n3) Testing iterative reverse..."
    list.reverse()
    print "After reverse:\n", list

    print "\n4) Testing recursive reverse..."
    list.reverseRecursive()
    print "After reverse:\n", list


    list.deleteKey(0)
    print "\n5)After removing non-existent element:\n", list

    list.deleteKey(list.head().next().value())
    print "6)After removing existent element:\n", list

    list.deleteKey(list.head().value())
    print "7)After removing headelement:\n", list

    A = Int(123)
    B = Int(897)

    print "Integer A:\n", A
    print "Integer B:\n", B
    print "Integer A + B:\n", A + B
    # print "Integer A + B:", sum(A, B)

    print "Create list for arbitrary pointers:\n"
    listArb = LinkedList()
    listArb.addFront(21)
    listArb.addFront(14)
    listArb.addFront(7)
    listArb.head().setArb(listArb.head().next().next())
    listArb.head().next().next().setArb(listArb.head())
    print listArb

    listArbCopy = LinkedList()
    listArbCopy = listArb.deepCopy()

    listArbCopy.head().next().next().setValue(123)
    listArb.head().setValue(321)

    print "Copy:", listArbCopy
    print "Original:", listArb

    # Check the sorting:
    listNew = LinkedList()
    listNew.addFront(11)
    listNew.addFront(82)
    listNew.addFront(23)
    listNew.addFront(29)

    print
    print listNew
    listNew.sort()
    print listNew
    print

    print "Test the intersection point:"
    list1 = LinkedList()
    list2 = LinkedList()
    list3 = LinkedList()
    
    list1.addFront(27)
    list1.addFront(12)
    list1.addFront(23)
    list1.addFront(29)
    
    list2.addFront(4)
    list2.addFront(13)
    
    list2.head().next().setNext(list1.head().next().next())
    
    list3.addFront(27)
    list3.addFront(12)
    list3.addFront(23)
    list3.addFront(29)
    
    print list1
    print list2
    print list3
    
    # intsct = Node()
    intsct = list1.intersects(list2)
    print intsct
    
    intsct = list1.intersects(list3)
    print intsct
    
