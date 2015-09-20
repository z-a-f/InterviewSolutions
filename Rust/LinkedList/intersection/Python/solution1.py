import sys                      # Need that to set path
sys.path.insert(0, '../..') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def intersects(head1, head2):
    l1 = None
    l2 = None

    l1len = get_length(head1)
    l2len = get_length(head2)

    d = l1len - l2len

    l1 = head1 if d >= 0 else head2
    l2 = head2 if d >= 0 else head1
    d = d if d >= 0 else -d

    while d > 0:
        l1 = l1.next()
        d -= 1

    while l1 != None:
        if l1 == l2:
            return l1

        l1 = l1.next()
        l2 = l2.next()

    return None

def get_length(head):
    list_length = 0
    while head != None:
        head = head.next()
        list_length += 1
    return list_length

if __name__ == '__main__':
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
    intsct = intersects(list1.head(), list2.head())
    print intsct

    intsct = intersects(list1.head(), list3.head())
    print intsct
