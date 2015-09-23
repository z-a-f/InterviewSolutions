import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def merge(first, second):
    if (first == None): return second
    if (second == None): return first

    # new_head = Node()
    if (first.value() <= second.value()):
        new_head = first
        first = first.next()
    else:
        new_head = second
        second = second.next()

    current = new_head
    while (first != None) and (second != None):
        temp = None
        if (first.value() <= second.value()):
            temp = first
            first = first.next()
        else:
            temp = second
            second = second.next()
        current.setNext(temp)
        current = temp

    if (first != None):
        current.setNext(first)
    elif (second != None):
        current.setNext(second)

    return new_head

            
if __name__ == '__main__':
    list1 = LinkedList()
    list2 = LinkedList()

    list1.addFront(19)
    list1.addFront(15)
    list1.addFront(8)
    list1.addFront(4)

    list2.addFront(16)
    list2.addFront(10)
    list2.addFront(9)
    list2.addFront(7)

    print "Original 1:", list1
    print "Original 2:", list2

    merged = LinkedList()
    merged.setHead(merge(list1.head(), list2.head()))

    print "Merged", merged
    print "Original 1:", list1
    print "Original 2:", list2
