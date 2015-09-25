import sys                      # Need that to set path
sys.path.insert(0, '../../../Library/Python') # Need that to import LL

from LinkedList import *    # Linked LIst defined here

def split_odd_even(head):
    if (head == None):
        return None

    curr = head
    even = head.next()
    tail = even

    while curr != None and curr.next() != None:
        temp = curr.next()

        curr.setNext(temp.next())
        curr = curr.next()

        tail.setNext(temp)
        tail = tail.next()

    if tail != None:
        tail.setNext(None)

    return even

def merge_alternating (head1, head2):
    if head1 == None:
        return head2
    if head2 == None:
        return head1

    head = head1
    while head1.next() != None and head2 != None:
        temp = head2
        head2 = head2.next()

        temp.setNext(head1.next())
        head1.setNext(temp)
        head1 = temp.next()

    if head1.next() == None:
        head1.setNext(head2)

    return head

def reverse_even_nodes(head):
    curr = head
    list_even = None

    while curr != None and curr.next() != None:
        even = curr.next()
        curr.setNext(even.next())

        even.setNext(list_even)
        list_even = even

        curr = curr.next()

    return merge_alternating(head, list_even)
    

if __name__ == '__main__':
    list = LinkedList()
    even = LinkedList()
    
    list.addFront(7)
    list.addFront(6)
    list.addFront(5)
    list.addFront(4)
    list.addFront(3)
    list.addFront(2)
    list.addFront(1)

    print list

    # even.setHead(split_odd_even(list.head()))
    print list
    # even.reverse()
    print even

    # list.setHead(merge_alternating(list.head(), even.head()))
    list.setHead(reverse_even_nodes(list.head()))
    print list
    





    
